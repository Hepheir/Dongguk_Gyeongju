#include <stdbool.h>
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
   					// PORTA.0 (O) : LCD DATA0
     					// PORTA.1 (O) : LCD DATA1
     					// PORTA.2 (O) : LCD DATA2
     					// PORTA.3 (O) : LCD DATA3
     					// PORTA.4 (O) : LCD DATA4
     					// PORTA.5 (O) : LCD DATA5
     					// PORTA.6 (O) : LCD DATA6
     					// PORTA.7 (O) : LCD DATA7 
    
     DDRC  = 0xFF;  
     PORTC = 0x00;            
     					// PORTC.0 (O) : LCD_E
     					// PORTC.1 (O) : LCD_RS
     					// PORTC.2 (O)~ PORTC.7 (O) : LED
	            		// PORTC를 모두 출력으로 설정

    // KEY_SCAN0이 PE4에 연결되어 있음 (출력)
    // KEY_DATA0이 PD4에 연결되어 있음 (입력)
    // KEY_DATA1이 PD5에 연결되어 있음 (입력)

    char message[16];
    LCD_initialize();

    unsigned char LED_N = 0x00;
    unsigned char Switch_N = 0x00;

	while(1)
	{
        Switch_N = keyScan();

        sprintf(message, "Switch #%02X", Switch_N);

        LCD_string(0x80, "You've pressed");
        LCD_string(0xC0, message);

		if ((Switch_N & ~0x0E) == 0) 
		{
			for (LED_N = 2; LED_N <= 7; LED_N++) {
                LED_ON(LED_N);
                Delay_ms(100);
                LED_OFF(LED_N);
            }
		}
        else if ((Switch_N & ~0x0D) == 0)
        {
			for (LED_N = 7; LED_N >= 2; LED_N--) {
                LED_ON(LED_N);
                Delay_ms(100);
                LED_OFF(LED_N);
            }
        }
        else if (Switch_N == 0xFF)
        {
            LED_ON(7);
            Delay_ms(100);
            LED_OFF(7);
        }
	}
}

unsigned char keyScan(void) {
    unsigned char keyBuf = 0xFF;

    // SAVE ORIGINAL STATE
    unsigned char ddre  = DDRE;
    unsigned char porte = PORTE;

    // DDR*  : 핀의 사용용도를 정의하는 레지스터 (0 = 입력으로 사용, 1 = 출력으로 사용)
    // PORT* : 핀을 출력용으로 사용할 때 출력값을 쓰는 레지스터 (0 = 출력안함, 1 = 출력함)
    // PIN*  : 핀을 입력용으로 사용할 때 입력값을 받는 레지스터

                                           // SCAN DATA(OUT)
                                           // 4321 4321
    DDRE  |= 0xF0;
    PORTE |= 0xF0;                         // 1111

    PORTE &= ~0x10;                        // 1110
    Delay_us(5);
    if ((PIND & 0x10) == 0) keyBuf = 0x00; //      ___0
    if ((PIND & 0x20) == 0) keyBuf = 0x01; //      __0_
    if ((PIND & 0x40) == 0) keyBuf = 0x02; //      _0__
    if ((PIND & 0x80) == 0) keyBuf = 0x03; //      0___
    PORTE |= 0x10;                         // 1111

    PORTE &= ~0x20;                        // 1101
    Delay_us(5);
    if ((PIND & 0x10) == 0) keyBuf = 0x04; //      ___0
    if ((PIND & 0x20) == 0) keyBuf = 0x05; //      __0_
    if ((PIND & 0x40) == 0) keyBuf = 0x06; //      _0__
    if ((PIND & 0x80) == 0) keyBuf = 0x07; //      0___
    PORTE |= 0x20;                         // 1111

    PORTE &= ~0x40;                        // 1011
    Delay_us(5);
    if ((PIND & 0x10) == 0) keyBuf = 0x08; //      ___0
    if ((PIND & 0x20) == 0) keyBuf = 0x09; //      __0_
    if ((PIND & 0x40) == 0) keyBuf = 0x0A; //      _0__
    if ((PIND & 0x80) == 0) keyBuf = 0x0B; //      0___
    PORTE |= 0x40;                         // 1111

    PORTE &= ~0x80;                        // 0111
    Delay_us(5);
    if ((PIND & 0x10) == 0) keyBuf = 0x0C; //      ___0
    if ((PIND & 0x20) == 0) keyBuf = 0x0D; //      __0_
    if ((PIND & 0x40) == 0) keyBuf = 0x0E; //      _0__
    if ((PIND & 0x80) == 0) keyBuf = 0x0F; //      0___
    PORTE |= 0x80;                         // 1111

    // ROLL BACK
    DDRE  = ddre;
    PORTE = porte;

    return keyBuf;
}

void LED_ON(unsigned char i) {
	PORTC = PORTC | 1 << i;
}

void LED_OFF(unsigned char i) {
	PORTC = PORTC & ~(1 << i);
}
