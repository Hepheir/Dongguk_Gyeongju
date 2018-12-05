// Required Headers
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


#include <stdio.h>
#include <stdbool.h>
#include "my_LCD.h"
#include "hepheir_atmega128.h"

#define TICK 100 // ms

const char START_COMMAND[] = "<ADC_START>"; // 시작명령
const char END_COMMAND[] = "#";             // 정지명령

int _strtCmdStack = 0;      // 시작명령의 입력여부를 판단하기 위한 변수
bool isSendEnabled = false; // 데이터 전송 할지 말지 결정
char rx_data, tx_data;      // 수신, 송신 데이터를 각각 임시 저장

///////////////////////////////////////////////////
//  3. 직렬통신은 interrupt방식을 사용 (???)
///////////////////////////////////////////////////

// Evt: Rx 수신 완료 시
ISR(SIG_UART0_RECV)
{
    cli();            // 전체 인터럽트 중지 
    rx_data = UDR0;   // 수신 받은 데이터를 임시 변수에 저장

    UCSR0A &= 0x7f;   // clear RXC flag
    sei();            // 전체 인터럽트 허용
}

///////////////////////////////////////////////////
//  6. 일정한 시간 간격을 대략 1초를 넘지 않는 범위에서 자유롭게
//     설정하고 delay방식은 기본점수를 부여하고 타이머를 이용한
//     interrupt 방식을 사용하면 가산점 부여
///////////////////////////////////////////////////

    // iom128.h 헤더 파일의 내용
        // ...
        // /* External Interrupt Request 7 */
        // #define INT7_vect			_VECTOR(8)
        // #define SIG_INTERRUPT7			_VECTOR(8)

        // /* Timer/Counter2 Compare Match */
        // #define TIMER2_COMP_vect		_VECTOR(9)
        // #define SIG_OUTPUT_COMPARE2		_VECTOR(9)

        // /* Timer/Counter2 Overflow */
        // #define TIMER2_OVF_vect			_VECTOR(10)
        // #define SIG_OVERFLOW2			_VECTOR(10)

        // /* Timer/Counter1 Capture Event */
        // #define TIMER1_CAPT_vect		_VECTOR(11)
        // #define SIG_INPUT_CAPTURE1		_VECTOR(11)

        // /* Timer/Counter1 Compare Match A */
        // #define TIMER1_COMPA_vect		_VECTOR(12)
        // #define SIG_OUTPUT_COMPARE1A		_VECTOR(12)

        // /* Timer/Counter Compare Match B */
        // #define TIMER1_COMPB_vect		_VECTOR(13)
        // #define SIG_OUTPUT_COMPARE1B		_VECTOR(13)

        // /* Timer/Counter1 Overflow */
        // #define TIMER1_OVF_vect			_VECTOR(14)
        // #define SIG_OVERFLOW1			_VECTOR(14)

int cnt = 0;

// Evt: TIMER 0 의 OVERFLOW 발생
ISR(SIG_OVERFLOW0)
{
    cli(); // 전체 인터럽트 중지
    if (cnt < 250) cnt++;
    else {
        // 오버플로우가 250번 발생해야 Interrupt 0 실행
        EIFR |= 0x01;
    }
    sei(); // 전체 인터럽트 허용
}

// Evt: Interrupt 0으로 점프되면
//      PC로 신호를 보냄
ISR(SIG_INTERRUPT0)
{
    cli(); // 전체 인터럽트 중지
    // UDE가 비었으면 송신 가능
    while( (UCSR0A & (1<<UDRE0)) == 0);
    // 데이터를 보낸다.
    UDR0 = tx_data;
    sei(); // 전체 인터럽트 허용
}

int main(void)
{
    // LCD Init
    DDRA  = 0xFF;
    PORTA = 0x00;
    LCD_initialize();

    // 포트 초기화    
    DDRE = 0xFE;    // RXD0/PE<0> = 입력, TXD0/PE<1> = 출력

    // RS232 초기화
    UBRR0L = 103;   // 16MHz에서 9600 bps : 103
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);  // RXEN = 1, TXEN = 1
    UCSR0B |= 0x80; // RXC interrupt 허용

    sei();          // 전체 인터럽트 허용
    
    unsigned char vR = 0x00; // 가변 저항의 전압 값

    char msg_1[16];
    char msg_2[16];

	while (1)
	{
        TCCR0++; // Timer/Counter Control Register
        // http://www.icbank.com/icbank_data/community/funfun/뻔뻔한_AVR_야간교육_제4일차_20080603.pdf @ p.11

        ///////////////////////////////////////////////////
        //  1. 실험키트에서 가변저항 조절 시 변하는 전압 값을 AD변환 후
        //     직렬 통신을 통하여 PC로 일정한 시간마다 전달.
        //     (단, 실험키트의 문자 LCD에도 전압 값 표시)
        //
        //  2. 가변 저항은 두 개 중 한 개 선택
        ///////////////////////////////////////////////////

        vR = resistorScan(0); // VR0 Scan

        // Print on LCD
        sprintf(msg_1, "EX-7 ADC test   ");
        sprintf(msg_2, "%3d             ", vR);
        
        LCD_string(0x80, msg_1);
        LCD_string(0xC0, msg_2);

        ///////////////////////////////////////////////////
        //  4. PC에서 <ADC_START>를 입력하면 AD 변환 데이터를 PC로
        //     전송하기 시작함
        ///////////////////////////////////////////////////

        // 수신된 rx_data 문자들이 시작명령인 "<ADC_START>"와 일치
        // 하는 지를 알아본다. ("<ADC_START>" 는 11의 길이를 가지는
        // 문자열 임을 이용.)

        if ( rx_data == START_COMMAND[_strtCmdStack] ) {
            // 시작명령의 첫 번째 문자와 일치하는 문자가 수신되면,
            // (시작명령에서) 그 문자에 이어지는 문자가 이어서 수신
            // 되는지를 확인한다.
            _strtCmdStack++;
        } else {
            // 중간에 연속적으로 일치하지 않는 문자가 입력되면, 카운터
            // 를 리셋한다.
            _strtCmdStack = 0;
        }

        // 연속해서 수신된 문자가 시작명령 전체와 일치하면, 동작을 시작.
        if (_strtCmdStack == 11)
        {
            isSendEnabled = true;

            // 리셋
            _strtCmdStack = 0;
        }

        ///////////////////////////////////////////////////
        //  5. PC에서 ‘#’을 누르면 AD 변환 데이터 전송 중단
        ///////////////////////////////////////////////////
        if (rx_data == '#')
        {
            isSendEnabled = false;
        }
	}
}