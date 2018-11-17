#include <avr/io.h>
#include <stdio.h>
#include <stdbool.h>
#include "my_atmega128.h"
#include "my_LCD.h"

unsigned char keyScan(void);
double volt_of_varResistor(unsigned char resistor_Num);
void LED_ON(unsigned char i);
void LED_OFF(unsigned char i);

int main(void)
{
    // LED Init

    DDRC  = 0xFF;  
    PORTC = 0x00;

    // LCD Init

    DDRA  = 0xFF;
    PORTA = 0x00;

    char msg_1[16];
    char msg_2[16];

    LCD_initialize();


    // Dynamic Resistor Init

    unsigned char enabled_Resister = 0x00;
    ADMUX = enabled_Resister;

    // Variables

    unsigned char Switch_N;
    unsigned char VResistor_N = 2;

    bool ADC_active = false;

    double V_R1 = 0;
    double V_R2 = 0;

    unsigned char i;

	while (1)
	{
        Switch_N = keyScan();

        // Switch Actions

		if (Switch_N == 3) // S3 : KEY_F1
            ADC_active = true;
        
        if (Switch_N == 7) // S7 : KEY_F2
        {
            ADC_active = false;
            ADCSRA &= ~(1<<7); // AD converter 비활성화

            for (i = 2; i <= 7; i++)
                LED_OFF(i);

            sprintf(msg_1, "                  ");
            sprintf(msg_2, "                  ");
        }
        
        // Print on LCD
        LCD_string(0x80, msg_1);
        LCD_string(0xC0, msg_2);

        if (!ADC_active) continue;


        // AD Converter Test
        
        /*
        * 매 실행마다 번갈아 가며 가변저항의 값을 확인함.
        * 매우 짧은 시간동안 두 가변저항을 번갈아 확인하므로
        * 동시에 두 가변저항의 값을 확인하는 것 처럼 보임.
        */

        if (VResistor_N == 1)
        { // R1 Selected
            V_R1 = volt_of_varResistor(1);

            Delay_ms(5);
            VResistor_N = 2;
        }
        else if (VResistor_N == 2)
        { // R2 Selected
            V_R2 = volt_of_varResistor(2);
            
            Delay_ms(5);
            VResistor_N = 1;
        }

        // Print on LCD
        sprintf(msg_1, "%.2lf[V], %.2lf[V]", V_R1, V_R2);
        sprintf(msg_2, "V2-V1: %.3lf[V]", (V_R2 - V_R1));

        // LED Control
        if (V_R2 - V_R1 > 2)
            for (i = 2; i <= 7; i++)
                LED_ON(i);

        else
            for (i = 2; i <= 7; i++)
                LED_OFF(i);
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

double volt_of_varResistor(unsigned char resistor_Num) {
    double voltage;

    Delay_ms(5);

    if (resistor_Num == 1)
        ADMUX = 0x00;
    else if (resistor_Num == 2)
        ADMUX = 0x01;
    else
        return 0;

    // AD converter 활성화, 변환동작 시작, Free running mode
    // ,인터럽트 사용안함, ADC 클럭을 128분주	
    ADCSRA = 0xF7;

    Delay_ms(5);

    // Wait until AD conversion ends
    while((ADCSRA & 0x10) == 0);

    ADCSRA |= 0x10;

    // 5V 에서의 ADC값이 십진수로 1023, 이진수로 11 1111 1111 이므로
    voltage = (ADC / (float) 0x3FF) * 5; // voltage에 ADC에 저장된 전압 값을 넣음

    return voltage;
}

void LED_ON(unsigned char LED_Num) {
	PORTC |= (1 << LED_Num);
}

void LED_OFF(unsigned char LED_Num) {
	PORTC &= ~(1 << LED_Num);
}