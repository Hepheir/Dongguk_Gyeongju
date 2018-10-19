#include <avr/io.h>
#include "my_atmega128.h"

int main(void)
{
    DDRC = 0xFF;         // PORTC를 모두 출력으로 설정
    PORTE = 0x00;         // PORTE를 전부 0으로 둔다.

    //DDRE = DDRE | 1 << 5;      // PE5를 츨력으로 설정 (1로 설정)
    //DDRE = DDRE | 1 << 6;      // PE5를 츨력으로 설정 (1로 설정)

    while (1)
    {
        DDRE = DDRE | 1 << 5;      // PE5를 츨력으로 설정 (1로 설정)
        PORTE = PORTE | 1 << 5;    // PE5를 1로 출력
        DDRE = DDRE | 1 << 5;      // PE5를 츨력으로 설정 (1로 설정)   
        if ((PIND & (1 << 6)) > 0) //3열이 눌리면
        {
            for (int i = 2; i < 8; i++)
            {
                PORTC = PORTC | 1 << i;          // LED ON
                Delay_ms(100);
                PORTC = PORTC & ~(1 << i);         // LED OFF 
            }
            PORTC = 0x00;   //PORTC 0으로 초기화
        }
        PORTE = PORTE & ~(1 << 5); // PE5에 0을 출력
        Delay_ms(100);

        DDRE = DDRE | 1 << 6;      // PE6를 츨력으로 설정 (1로 설정)
        PORTE = PORTE | 1 << 6;    // PE6에 1로 출력
        DDRE = DDRE | 1 << 6;      // PE6를 츨력으로 설정 (1로 설정)
        if ((PIND & (1 << 6)) > 0) //3열이 눌리면
        {
            for (int i = 2; i < 8; i++)
            {
                PORTC = PORTC | 1 << (9 - i);          // LED ON
                Delay_ms(100);
                PORTC = PORTC & ~(1 << (9 - i));         // LED OFF 
            }
            PORTC = 0x00;   //PORTC 0으로 초기화
        }
        PORTE = PORTE & ~(1 << 6); // PE6에 0을 출력
        Delay_ms(100);
    }
}