#include <avr/io.h>
#include "my_atmega128.h"



volatile char rx_data, tx_data;

SIGNAL(SIG_UART0_RECV)
{
   cli(); // global interupt enable
   rx_data = UDR0;
   UCSR0A &= 0x7F; // clear RXC flag (UCSR0A의 최상위 비트 수신완료 비트) -> 근데 이거 오류임. READ ONLY인데 WRITE를 하려해서 있으나 마나인 부분
   sei(); // global interupt disable
}

int main(void)
{
   cli();
   seg();
}

/*
ISR(인터럽트 이름) // SIGNAL() 도 가능하나 되도록 ISR 사용.
{
   // 처리할 일
}

TIMER OVERFLOW : 9비트가 있다면 0...1...2...3...1023...->
1024 = 10비트 : 최상위 비트가 오버플로우로 인해 누락되고 1023 -> 1024 대신 1023 -> 0으로 감
이게 타이머에서 발생 할 때 : Timer Overflow.

*/