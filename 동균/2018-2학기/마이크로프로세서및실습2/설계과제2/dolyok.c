#include <avr/io.h>
#include <stdio.h>
#include "my_atmega128.h"
#include "my_LCD.h"

double Volt_Scan(void);
unsigned char keyScan(void);


int main(void)
{
     // LED Init

    DDRC  = 0xFF;  
    PORTC = 0x00;

    // LCD Init

    DDRA  = 0xFF;
    PORTA = 0x00;


    int ADC_start;
    unsigned int ADCVAL;
    ADC_start = 0;
    char msg_1[16];
    char msg_2[16];
	 
    LCD_initialize();



    unsigned char Switch_N;
	double Volt_val;
   
    while(1) 
    {
        Switch_N = keyScan();

        if (Switch_N == 3)  //키 매트릭스의 S3 (좌측 상단)키가 눌리면
            ADC_start = 1;

        if (Switch_N == 7)  //키 매트릭스의 S7 키가 눌리면
        {  
            ADCSRA = ADCSRA & ~(1<<7); // AD converter 비활성화
            ADC_start = 0;
            PORTC = 0x00;		       // LED OFF 
        }

        if(ADC_start>0)
        {
            Volt_val = Volt_Scan();

            // LCD Print message
            sprintf(msg_1, " |V1 - V2|      ");
            sprintf(msg_2, "value : %2.2f!  ", Volt_val);

            LCD_string(0x80, msg_1);
            LCD_string(0xC0, msg_2);

            if(Volt_val > 2.0)      // 입력전압이 2.0 volt 이상이면 (정확하게는 (AREF/2) * 0.8 이상이면) 
                PORTC = 0xFF;
            else
                PORTC = 0x00;
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

double Volt_Scan(void){
    double volt_1;
    double volt_2;
    double volt_dif;
    
    {
        ADMUX = 0x00;

        ADCSRA = 0xF7;  
        Delay_ms(10);	

        while((ADCSRA&0x10)==0);  // AD conversion이 완료 되기까지 대기 (폴링 방식)
                
        ADCSRA |= 0x10;   // AD conversion이 완료를 나타내는 비트를 clear

        volt_1 = ADC / 1024.0F * 5;
        
        ADCSRA &= ~(1<<7); // AD converter 비활성화
    }
    {
        ADMUX = 0x01;

        ADCSRA = 0xF7;  
        Delay_ms(10);	

        while((ADCSRA&0x10)==0);  // AD conversion이 완료 되기까지 대기 (폴링 방식)
                
        ADCSRA |= 0x10;   // AD conversion이 완료를 나타내는 비트를 clear

        volt_2 = ADC / 1024.0F * 5;
        
        ADCSRA &= ~(1<<7); // AD converter 비활성화
    }

    volt_dif = volt_1 - volt_2;

    return volt_dif;
} 

