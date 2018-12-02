// 전송 받은 알파벳이 소문자면 대문자로, 대문자면 소문자로 변환
// 알파벳이 아닌 경우에는 "?"를 출력

// Baud Rate = 9600
// Flow Control In = None
// Flow Control Out = None
// Data Bits = 8
// Stop Bits = 1
// Parity = None

#include <avr/io.h>
#include <stdio.h>
#include "my_atmega128.h"
#include "my_LCD.h"

int main(void)
{
    // LCD init
    DDRA  = 0xFF;
    PORTA = 0x00;

    char msg_1[16];
    char msg_2[16];

    LCD_initialize();

    // 포트 초기화 (실험키트의 RxD0, TxD0는 각각 E 포트 0번, 1번 핀임)
    DDRE = 0xFE;    // RXD0/PE<0> = 입력, TXD0/PE<1> = 출력

    // USART 초기화
    UBRR0L = 103;        // 16MHz에서 9600 bps (double speed mode 아님)
    UCSR0B = 0x18;    // RXEN = 1, TXEN = 1  (송/수신부 동작 허용)

    char rx_data, tx_data;    // 수신, 송신 데이터를 각각 임시 저장

    while(1)
    {
        while((UCSR0A & 0x80) == 0x00);    // RXC = 1 이면 수신 끝
        
        rx_data = UDR0;        // 받은 데이터를 임시 변수에 저장

        // 알파벳 소문자가 입력 되었을 경우
        if( (rx_data >= 'a') && (rx_data <= 'z') )
        {
            tx_data = rx_data - 'a' + 'A';    // 소문자를 대문자로 변환
        }
        
        // 알파벳 대문자가 입력 되었을 경우
        else if( (rx_data >= 'A') && (rx_data <= 'Z') )
        {
            tx_data = rx_data - 'A' + 'a';    // 대문자를 소문자로 변환
        }

        // 알파벳이 아닌경우 "?" 출력
        else
        {
            tx_data = '?';
        }

        while((UCSR0A & 0x20) == 0x00);    // UDE가 비었으면 송신 가능

        UDR0 = tx_data;    // 데이터를 보낸다.

        // Print on LCD
        sprintf(msg_1, "Input : %d", rx_data);
        sprintf(msg_2, "Output : %d", tx_data);
        
        LCD_string(0x80, msg_1);
        LCD_string(0xC0, msg_2);
    }

    return 0;
}
