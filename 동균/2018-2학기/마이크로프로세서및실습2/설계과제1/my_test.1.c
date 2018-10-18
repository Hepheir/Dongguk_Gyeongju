#include <stdbool.h>
#include <avr/io.h>
#include "my_atmega128.h"


bool isSwitchOn(unsigned char i);
void LED_on(unsigned char i);
void LED_off(unsigned char i);

int main(void)
{
	DDRC = 0xFF;			// PORTC를 모두 출력으로 설정

    // KEY_SCAN0이 PE4에 연결되어 있음 (출력)
    // KEY_DATA0이 PD4에 연결되어 있음 (입력)
    // KEY_DATA1이 PD5에 연결되어 있음 (입력)

    DDRE = DDRE | 0xF0;      // PE4를 츨력으로 설정 (1로 설정) 0000 0001 : 0001 0000
    PORTE = PORTE | 0xF0;    // PE4 핀에서 1을 출력 

	while(1)
	{

		if (isSwitchOn(5)) 
		{
			LED_on(2);
			Delay_ms(1000); 
			LED_off(2);
		}  
    	 
	}
}
// 4  0000-0001 -> 0001-0000 // 

bool isSwitchOn(unsigned char i)
{
	
	if ((PIND & 0xF0) <= 0) return false; // 아무것도 눌리지 않았을 경우 false 반환


	unsigned char _porte = PORTE;
	unsigned char sc;
	unsigned char dt;
	
	bool isFound = false;

	for (sc = 0; sc < 4; sc++)
	{
		PORTE = _porte | 0x10 << sc;

		for (dt = 0; dt < 4; dt++) 
		{
			if ((PIND & (0x10 << dt)) <= 0) continue;

			if (i - 3 == (4 * dt) + sc)
				isFound = true;
		}
	}

	PORTE = _porte;

	return isFound;
}

void LED_on(unsigned char i) {
	PORTC = PORTC | 1 << i;
}

void LED_off(unsigned char i) {
	PORTC = PORTC & ~(1 << i);
}
