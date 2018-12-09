// TX는 보낼 데이터가 있을때 알아서...
// RX는 인터럽트 발생시...
// 알파벳 진행하다가 알파벳 입력 받으면 거기서 부터 다시 시작...

// Baud Rate = 9600
// Flow Control In = None
// Flow Control Out = None
// Data Bits = 8
// Stop Bits = 1
// Parity = None

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

char rx_data, tx_data;    // 수신, 송신 데이터를 각각 임시 저장

// 데이터 수신시 인터럽트 발생
SIGNAL(SIG_UART0_RECV)
{
    cli();            // 전체 인터럽트 중지
    rx_data = UDR0;    // 수신 받은 데이터를 임시 변수에 저장
    UCSR0A &= 0x7f;    // clear RXC flag
    sei();            // 전체 인터럽트 허용
}

int main(void)
{
    // 포트 초기화    
    DDRE = 0xFE;    // RXD0/PE<0> = 입력, TXD0/PE<1> = 출력

    // RS232 초기화
    UBRR0L = 103;        // 16MHz에서 9600 bps : 103
    UCSR0B = 0x18;    // RXEN = 1, TXEN = 1
    UCSR0B |= 0x80;    // RXC interrupt 허용

    sei();            // 전체 인터럽트 허용

    rx_data = 'a';    // 초기값 설정

    while(1)
    {
        tx_data = rx_data;    // 전송할 데이터 설정

        // 다음 알파벳 생성, z면 a로 다시 시작
        if('A'<= rx_data && rx_data <= 'z')
        {
            rx_data++;
        }
        else
        {
            rx_data = 'a';
        }

        while((UCSR0A & 0x20) == 0x00);    // UDE가 비었으면 송신 가능

        UDR0 = tx_data;    // 데이터를 보낸다.

        _delay_ms(10);
		}

    return 0;
}
