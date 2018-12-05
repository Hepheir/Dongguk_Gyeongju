#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>
#include "my_atmega128.h"
#include "my_LCD.h"

#define DATA_LENGTH 10

char rx_data;
char tx_data[DATA_LENGTH];

unsigned short vR;

int loop = 0;
int sends = 0;

void serialSend(char text[], unsigned char length);
unsigned short resistorScan(unsigned char i);

ISR(USART0_RX_vect)
{
    cli();
    rx_data = UDR0;
    UCSR0A &= 0x7f;
    sei();
}

ISR(TIMER0_OVF_vect)
{
    // TIMER 0 : 8bit

    if (loop < 100)
        loop++;
    else {
        loop = 0;
        // 현재 전압값을 표시한 문자열을 생성하고 tx_data에 저장
        sprintf(tx_data, "%5d [V]\n", vR);
        // 문자열을 PC로 전송
        serialSend(tx_data, DATA_LENGTH);
    }

    // 144 클럭을 카운트 하기위해 TCNT0을 112로 지정.
    TCNT0 = 112; // 256 - 144 = 112.
}

void init()
{
    DDRA = 0xFF; // Port A set Output
    DDRB = 0xFF; // Port B set Output
    DDRC = 0xFF; // Port C set Output 

    PORTA = 0x00;
    PORTC = 0x00;

    LCD_initialize();

    // 포트 초기화    
    DDRE = 0xFE;    // RXD0/PE<0> = 입력, TXD0/PE<1> = 출력

    // RS232 초기화
    UBRR0L = 103;        // 16MHz에서 9600 bps : 103
    UCSR0B = 0x18;    // RXEN = 1, TXEN = 1
    UCSR0B |= 0x80;    // RXC interrupt 허용

    // TIMER 준비
    TCCR0 = 0b00000111; // normal 모드, 분주비 1024, OC0차단
    TCNT0 = 112;
    
    TIMSK = 0b00000001; // TOIE0 = 1 (TIMER/COUNTER 0 Enable)
    SREG = 0x80; // sei();
}

int main(void)
{
    init();
    
    char msg_1[16];
    char msg_2[16];

    rx_data = '*';

	while (1)
	{
        vR = resistorScan(0); // VR0 Scan

        // Print on LCD
        // "                "
        sprintf(msg_1, "S: %3d, Tmr0: %2d", sends, loop);
        sprintf(msg_2, "Last: %c, V: %4d", rx_data, vR);
        
        LCD_string(0x80, msg_1);
        LCD_string(0xC0, msg_2);

        Delay_ms(5);
	}

    return 0;
}

void serialSend(char text[], unsigned char length)
{
    unsigned char i;
    for (i = 0; i < length; i++)
    {
        // UDE가 비었으면 송신 가능
        while( (UCSR0A & (1<<UDRE0)) == 0);
        // 데이터를 보낸다.
        UDR0 = text[i];
    }
    sends++;
}

unsigned short resistorScan(unsigned char i) {
    if (i == 0) {
        ADMUX = 0x00; // VR0
    }
    else if (i == 1) {
        ADMUX = 0x01; // VR1
    }
    else
        return 0x0000;

    // AD converter 활성화, 변환동작 시작, Free running mode
    // ,인터럽트 사용안함, ADC 클럭을 128분주	
    ADCSRA = 0xF7;

    // AD conversion이 완료 되기까지 대기 (폴링 방식)
    while((ADCSRA & 0x10) == 0);

    // AD conversion이 완료를 나타내는 비트를 clear
    ADCSRA |= 0x10;
    
    return ADC;
}
