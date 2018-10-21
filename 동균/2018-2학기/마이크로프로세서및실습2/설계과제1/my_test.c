#include <avr/io.h>
#include <stdio.h>
#include "my_atmega128.h"
#include "my_LCD.h"

unsigned char keyScan(void);
void LED_ON(unsigned char i);
void LED_OFF(unsigned char i);

int main(void)
{
    DDRA  = 0xFF;
    PORTA = 0x00;
    
    DDRC  = 0xFF;  
    PORTC = 0x00;

    char msg_1[16];
    char msg_2[16];

    LCD_initialize();

    unsigned char Switch_N;

    unsigned char Flipflop = 0;
    unsigned char i;

	while(1)
	{
        Switch_N = keyScan();

        // LCD Print message
            sprintf(msg_1, "You've pressed  ");

        if (Switch_N)
            sprintf(msg_2, "S%02d!          ", Switch_N);
        else
            sprintf(msg_2, "Nothing!        ");
        
        LCD_string(0x80, msg_1);
        LCD_string(0xC0, msg_2);


        // Switch Actions

        // Wave upward
		if (Switch_N == 9) // S9 : 5
		{
			for (i = 7; i >= 2; i--) {
                LED_ON(i);
                Delay_ms(100);
                LED_OFF(i);
            }

            Flipflop = ~0;
		}
        // Wave downward
        if (Switch_N == 13) // S13 : 8
        {
			for (i = 2; i <= 7; i++) {
                LED_ON(i);
                Delay_ms(100);
                LED_OFF(i);
            }

            Flipflop = ~0;
        }
        // LED Turn on 2~7
        for (i = 3; i <= 8; i++)
        {
            if (Switch_N == i)
            {
                LED_ON(i - 1);
                Delay_ms(100);
                LED_OFF(i - 1);
            }
        }
        // Print Dongjoo
        if (Switch_N == 10)
        {
            sprintf(msg_1, "Hepheir @ Gmail ");
            sprintf(msg_2, "2018212236      ");
        
            LCD_string(0x80, msg_1);
            LCD_string(0xC0, msg_2);

			for (i = 2; i <= 7; i++)
                LED_ON(i);
            Delay_ms(100);
			for (i = 2; i <= 7; i++)
                LED_OFF(i);
            Delay_ms(100);

            Flipflop = ~0;
        }
        // Curtain Close
        if (Switch_N == 11)
        {
			for (i = 0; i <= 2; i++) {
                LED_ON(2 + i);
                LED_ON(7 - i);
                Delay_ms(100);
            }

            Flipflop = 0;
        }
        // Curtain Open
        if (Switch_N == 12)
        {
			for (i = 3; i >= 1; i--) {
                LED_OFF(2 + (i - 1));
                LED_OFF(7 - (i - 1));
                Delay_ms(100);
            }

            Flipflop = ~0;
        }
        // Print Dolyok
        if (Switch_N == 14)
        {
            sprintf(msg_1, "DOL YOK is kawai");
            sprintf(msg_2, "Yee~~~ Bob-O!   ");
        
            LCD_string(0x80, msg_1);
            LCD_string(0xC0, msg_2);

			for (i = 2; i <= 7; i++)
                LED_ON(i);
            Delay_ms(250);
			for (i = 2; i <= 7; i++)
                LED_OFF(i);
            Delay_ms(250);

            Flipflop = ~0;
        }
        // Hold all
        if (Switch_N == 15)
        {
			for (i = 2; i <= 7; i++)
                LED_ON(i);
            Delay_ms(100);
			for (i = 2; i <= 7; i++)
                LED_OFF(i);

            Flipflop = ~0;
        }
        // Flip flop
        if (Switch_N == 16) {
            if (Flipflop) {
                for (i = 2; i <= 7; i++)
                    LED_ON(i);
            } else {
                for (i = 2; i <= 7; i++)
                    LED_OFF(i);
            }
            Delay_ms(500);

            Flipflop = ~Flipflop;
        }
        // Climb up & down
        if (Switch_N == 17)
        {
			for (i = 7; i >= 2; i--) {
                LED_ON(i);
                Delay_ms(100);
            }
			for (i = 2; i <= 7; i++) {
                LED_OFF(i);
                Delay_ms(100);
            }

            Flipflop = ~0;
        }
        // Zigzag
        if (Switch_N == 18)
        {
			for (i = 2; i <= 7; i+=2) {
                LED_ON(i);
                LED_OFF(i + 1);
            }
            Delay_ms(250);
			for (i = 2; i <= 7; i+=2) {
                LED_OFF(i);
                LED_ON(i + 1);
            }
            Delay_ms(250);

            for (i = 2; i <= 7; i++)
                LED_OFF(i);

            Flipflop = ~0;
        }
	}
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
        Delay_us(5);
        
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

void LED_ON(unsigned char i) {
	PORTC |= (1 << i);
}

void LED_OFF(unsigned char i) {
	PORTC &= ~(1 << i);
}