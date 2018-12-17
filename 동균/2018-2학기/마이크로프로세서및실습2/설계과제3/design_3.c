#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "my_atmega128.h"
#include "my_LCD.h"


// Constants

#define DATA_LENGTH 12 // 송신할 문자열의 길이
#define PERIOD_MS 1000 // 송신 주기

#define CMD_START "<ADC_START>"
#define CMD_END "#"

#define BUFFER_LENGTH 16 // 버퍼에 저장할 수신한 문자들의 최대 갯수


// Global Variables

char rx_data; // 수신한 문자
char tx_data[DATA_LENGTH]; // 송신할 문자열

unsigned short vR; // 가변 저항의 저항 값 (ADC)

int loop = 0;   // 타이머 루프
int sends = 0;  // 지금까지 송신한 횟수

bool enableSerialCom = false; // 시리얼 통신 활성/비활성

char Buffer[BUFFER_LENGTH+1] = { '\0' }; // 수신한 문자와 수신할 문자들을 저장하는 버퍼


// Functions

void writeChBuffer(char c); // 수신한 문자를 버퍼에 저장하는 함수
void serialSend(char text[], unsigned char length); // 문자열을 Serial통신으로 PC에 송신하는 함수

unsigned short resistorScan(unsigned char i); // 가변저항의 ADC값을 반환하는 함수
  double ADC_to_voltage(unsigned short _ADC); // ADC 값을 [V] 단위로 바꿔주는 함수
unsigned char keyScan(void); // (유틸) Key Matrix에서 현재 눌려있는 키의 번호를 반환하는 함수

void LED_ON(unsigned char i);
void LED_OFF(unsigned char i);


// Serial 통신 수신 Interrupt

ISR(USART0_RX_vect)
{
    cli();
    rx_data = UDR0; // 수신 받은 데이터를 임시 변수에 저장
    writeChBuffer(rx_data); // 수신 받은 문자를 버퍼에 저장
    UCSR0A &= 0x7f; // clear RXC flag
    sei();
}


// Timer/Counter 0 Overflow Interrupt

ISR(TIMER0_OVF_vect)
{
    // TIMER 0 : 8bit
    if (loop < PERIOD_MS/10)
        loop++;
    else {
        loop = 0;
        // 시리얼 통신이 활성화 되어있으면 ㄱㄱ
        if (enableSerialCom) {
            // 현재 전압값을 표시한 문자열을 생성하고 tx_data에 저장
            sprintf(tx_data, "\n%.2lf [V]", ADC_to_voltage(vR));
            // 문자열을 PC로 전송
            serialSend(tx_data, DATA_LENGTH);
        }
    }

    // 154 클럭을 카운트 하기위해 TCNT0을 102로 지정.
    TCNT0 = 102; // 256 - 154
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
    TCNT0 = 102;
    
    TIMSK = 0b00000001; // TOIE0 = 1 (TIMER/COUNTER Inturrupt Masking 해제. (0 = Enable) )
    SREG = 0x80; // sei();
}

int main(void)
{
    init();
    
    char msg_1[16];
    char msg_2[16];

    rx_data = '_';

    // 버퍼의 마지막 문자는 항상 NULL 문자 (문자열로서 사용하기 편하게)
    for (unsigned char i = 0; i < BUFFER_LENGTH; i++) Buffer[i] = '_'; // 언더바(_)로 초기화
    Buffer[BUFFER_LENGTH] = '\0';

    // 유틸리티
    unsigned char keyNum = 0; // 현재 눌린 키의 번호
    unsigned char scrNum = 0; // 현재 표시중인 화면 번호 (어떤 번호의 키를 눌러야 나오는 화면인지)
    unsigned char lastScrNum = 0; // 이전에 표시했던 화면 번호.

   while (1)
   {
    // 가변 저항의 ADC 값 구하기
        vR = resistorScan(1); // VR1 Scan

    // LCD 출력 (유틸리티)
        keyNum = keyScan();

        // 일반 모드는 한번 버튼이 눌렸다 놓여도 상태 유지.
        // 눌린 키의 값이 변할 때만 감지 하도록 keyNum != scrNum 의 조건을 넣어줌.
        if (keyNum != 0 && keyNum != scrNum) {
            lastScrNum = scrNum;
            scrNum = keyNum;
        }
        // Debug 모드는 버튼이 눌려있는 동안만 유지.
        else if (keyNum == 0 && scrNum >= 17)
            scrNum = lastScrNum;

        switch (scrNum) {
            case 3: // Buffer의 내용 출력
                sprintf(msg_1, "1. Buffer Text  ");
                sprintf(msg_2, "%s", Buffer);
                break;
            case 4: // Timer 관련 레지스터, 변수 상태
                sprintf(msg_1, "2. Timer/Cntr 0 ");
                sprintf(msg_2, "TCNT0:%2X/loop:%2d", TCNT0, loop);
                break;
            case 5: // Serial 통신 송신 관련 상태 (송신 횟수, 송신 활성화(1)/비활성화(0) 여부)
                sprintf(msg_1, "3. Serial Status");
                sprintf(msg_2, "Send:%04d/Stat:%d", sends, enableSerialCom);
                break;
            case 6: // 가변 저항의 값
                sprintf(msg_1, "4. Var. Resistor");
                sprintf(msg_2, "ADC:%4d/V:%4.3lf", vR, ADC_to_voltage(vR));
                break;
            
            // 이 아래는 디버그용 기능들. 명령어 입력 없이도 Serial 통신 활성화/비활성화 를 강제 할 수 있음.
            case 17: // DEBUG #1 : Force Enable serial communication.
                sprintf(msg_1, "Debug #1. Serial");
                sprintf(msg_2, "Force Enabled   ");
                enableSerialCom = true;
                break;
            case 18: // DEBUG #2 : Force Disable serial communication.
                sprintf(msg_1, "Debug #2. Serial");
                sprintf(msg_2, "Force Disabled  ");
                enableSerialCom = false;
                break;
        
            // 기본 화면
            default:
                sprintf(msg_1, "Serial Enabled:%d", enableSerialCom);
                sprintf(msg_2, "Voltage: %.2lf[V]", ADC_to_voltage(vR));
                break;
        }

        LCD_string(0x80, msg_1);
        LCD_string(0xC0, msg_2);

    // 명령어 인지

        // Buffer 문자열의 마지막 11개 문자가 "<ADC_START>" 이면, 송신 활성화
        if (!strcmp(CMD_START, &Buffer[BUFFER_LENGTH-strlen(CMD_START)]))
        {
            // 디버그 모드의 Serial 통신 Force Enable/Disable 의 원할한 작동을 위해
            // 명령어가 입력 되면 (명령어 입력감지가 중복 되지 않게) Buffer에 문자를 하나 넣어줌.
            // 그렇지 않으면, 명령어 감지가 연속으로 이루어져, Force disable 이 동작하지 않게 됨.
            writeChBuffer('*');
            enableSerialCom = true;
        }
        
        // Buffer 문자열의 마지막 문자가 "#" 이면, 송신 비활성화
        if (!strcmp(CMD_END, &Buffer[BUFFER_LENGTH-strlen(CMD_END)]))
        {
            // 디버그 모드의 Serial 통신 Force Enable/Disable 의 원할한 작동을 위해
            // 명령어가 입력 되면 (명령어 입력감지가 중복 되지 않게) Buffer에 문자를 하나 넣어줌.
            writeChBuffer('*');
            enableSerialCom = false;
        }

    // LED Control
        // Serial 통신의 활성/비활성 여부를 알기 쉽게 2번 LED에 표시
        (enableSerialCom) ? LED_ON(2) : LED_OFF(2);
   }

    return 0;
}

void serialSend(char text[], unsigned char length)
{
    LED_ON(7); // (유틸) - 송신이 되고 있는지 7번 LED를 통해 표시

    unsigned char i;
    for (i = 0; i < length; i++)
    {
        // UDE가 비었으면 송신 가능
        while( (UCSR0A & (1<<UDRE0)) == 0);
        // 데이터를 보낸다.
        UDR0 = text[i];
    }
    sends++; // 지금까지 송신한 횟수 +1
    
    LED_OFF(7); // (유틸) - 송신이 끝났는지 7번 LED를 통해 표시
}

void writeChBuffer(char c)
{
    // Buffer 배열을 -1만큼 shift하고, 마지막 원소로 c를 push함.
    unsigned i;
    for (i = 0; i < BUFFER_LENGTH-1; i++)
        Buffer[i] = Buffer[i+1]; // -1 방향으로 shift.
    Buffer[BUFFER_LENGTH-1] = c; // 마지막 원소로 c를 push.

    // Buffer는 BUFFER_LENGTH + 1 의 크기로 선언 되었고, 
    // Buffer[BUFFER_LENGTH] 에는 항상 Null 문자가 있음.
}

unsigned char keyScan(void) {
    unsigned char keyNum = 0;

    // SAVE ORIGINAL STATE
    unsigned char ddre  = DDRE;
    unsigned char porte = PORTE;

    // DDR*  : 핀의 사용용도를 정의하는 레지스터 (0 = 입력으로 사용, 1 = 출력으로 사용)
    // PORT* : 핀을 출력용으로 사용할 때 출력값을 쓰는 레지스터 (0 = 출력안함, 1 = 출력함)
    // PIN*  : 핀을 입력용으로 사용할 때 입력값을 받는 레지스터

    // 0x00의 16진수에서 1의 자리수는 여기서 다루지 않을 비트 값이고,
    // 16의 자리수(앞자리수 0x*0의 *부분)는 key_scan/key_data 각각 사용하는 4개의 핀들이다.

    DDRE  |= 0xF0; // key_scan 에 사용될 4핀을 모두 출력으로 설정
    PORTE &= 0x0F; // key_scan 에 사용되는 4 핀이 출력하고 있는 값을 0으로 설정

    unsigned char i, j;
    for (i = 0; i < 4; i++) {
        PORTE |= (0x10 << i); // (1) key_scan 의 i번째 핀만 출력값을 1로 설정, 나머지는 출력 안함.
        
        for (j = 0; j < 4; j++)
        {
            if (PIND & (0x10 << j)) // (2) key_data 의 j번째 핀에 1이 입력되는지를 확인
            {
                // (3) key_data 특정 핀에 입력이 확인되면, (1) 단계에서 출력한 key_scan 핀 번호와
                //     입력이 감지된 key_data 핀 번호의 조합을 통해 스위치 번호를 찾아낼 수 있음.
                keyNum = 3 + (4 * i) + j; // 스위치는 S3부터 시작하므로 3을 더하고 시작함.
            }
        }

        PORTE &= ~(0x10 << i); // (4) key_scan 의 i번째 핀만 출력값을 다시 0으로 되돌림.
    }

    // ROLL BACK
    DDRE  = ddre;
    PORTE = porte;

    return keyNum;
}

unsigned short resistorScan(unsigned char i) {
    if (i == 1) {
        ADMUX = 0x00; // VR1
    }
    else if (i == 2) {
        ADMUX = 0x01; // VR2
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

    double ADC_to_voltage(unsigned short _ADC) {
        // 5V 에서의 ADC값이 십진수로 1023, 이진수로 11 1111 1111이므로
        return (_ADC / (double) 0x3FF) * 5;
    }


void LED_ON(unsigned char i) {
   PORTC |= (1 << i);
}

void LED_OFF(unsigned char i) {
   PORTC &= ~(1 << i);
}