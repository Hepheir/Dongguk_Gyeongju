#include <stdbool.h>
#include <avr/io.h>
#include "my_atmega128.h"


unsigned char keyScan(void);
void LED_ON(unsigned char i);
void LED_OFF(unsigned char i);

int main(void)
{
	DDRC = 0xFF;			// PORTC를 모두 출력으로 설정

    // KEY_SCAN0이 PE4에 연결되어 있음 (출력)
    // KEY_DATA0이 PD4에 연결되어 있음 (입력)
    // KEY_DATA1이 PD5에 연결되어 있음 (입력)

    unsigned char LED_num;
	while(1)
	{
		if (keyScan() == 5) 
		{
			for (LED_num = 2; LED_num <= 7; LED_num++) {
                LED_ON(LED_num);
                Delay_ms(500);
                LED_OFF(LED_num);
            }
		}
        else if (keyScan() == 8) {
			for (LED_num = 7; LED_num >= 2; LED_num--) {
                LED_ON(LED_num);
                Delay_ms(500);
                LED_OFF(LED_num);
            }
        }
	}
}
// 4  0000-0001 -> 0001-0000 // 

unsigned char keyScan(void) {
    unsigned char keyBuf = 0xFF;

    DDRE |= 0xF0;
    PORTE |= 0xF0;

    PORTE &= ~0x10;
    Delay_us(5);
    if (PIND & 0x10) keyBuf = 3;
    if (PIND & 0x20) keyBuf = 4;
    if (PIND & 0x40) keyBuf = 5;
    if (PIND & 0x80) keyBuf = 6;
    PORTE |= 0x10;

    PORTE &= ~0x20;
    Delay_us(5);
    if (PIND & 0x10) keyBuf = 7;
    if (PIND & 0x20) keyBuf = 8;
    if (PIND & 0x40) keyBuf = 9;
    if (PIND & 0x80) keyBuf = 10;
    PORTE |= 0x20;

    PORTE &= ~0x40;
    Delay_us(5);
    if (PIND & 0x10) keyBuf = 11;
    if (PIND & 0x20) keyBuf = 12;
    if (PIND & 0x40) keyBuf = 13;
    if (PIND & 0x80) keyBuf = 14;
    PORTE |= 0x40;

    PORTE &= ~0x80;
    Delay_us(5);
    if (PIND & 0x10) keyBuf = 15;
    if (PIND & 0x20) keyBuf = 16;
    if (PIND & 0x40) keyBuf = 17;
    if (PIND & 0x80) keyBuf = 18;
    PORTE |= 0x80;

    return keyBuf;
}

void LED_ON(unsigned char i) {
	PORTC = PORTC | 1 << i;
}

void LED_OFF(unsigned char i) {
	PORTC = PORTC & ~(1 << i);
}
