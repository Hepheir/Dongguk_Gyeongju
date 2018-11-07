#include <avr/io.h>
#include "my_atmega128.h"

int main(void)
{
    DDRC = DDRC | 0xFC;	    // LED (PC2-7) 사용을 위해 출력으로 설정
    DDRF = 0x00;
    DDRE = DDRE | 0xF0;     // KEY_SCAN(PE4-7) 사용을 위해 출력으로 설정 
    DDRD = DDRD & ~(0xF0);  // KEY_DATA(PD4-7) 사용을 위해 입력으로 설정 

    int ADC_start;
    unsigned int ADCVAL;
    ADC_start = 0;

    ADMUX = 0x01; // 가변 저항 2번 선택 (VR2), 기준전압은 AREF 사용

    while(1)
    {
        PORTE = 1<<4;
        if ((PIND & 1<<4) > 0)  //키 매트릭스의 S3 (좌측 상단)키가 눌리면
            ADC_start = 1;

        if ((PIND & 1<<5) > 0)  //키 매트릭스의 S4 키가 눌리면
        {  
            ADCSRA = ADCSRA & ~(1<<7); // AD converter 비활성화
            ADC_start = 0;
            PORTC = 0x00;		       // LED OFF 
        }

        if(ADC_start>0)
        {
            // AD converter 활성화, 변환동작 시작, Free running mode
            // ,인터럽트 사용안함, ADC 클럭을 128분주				

            ADCSRA = 0xF7;  
            Delay_ms(10);	


            while((ADCSRA&0x10)==0);  // AD conversion이 완료 되기까지 대기 (폴링 방식)
            
            ADCSRA = ADCSRA | 0x10;   // AD conversion이 완료를 나타내는 비트를 clear

            ADCVAL = ADC;

            if(ADCVAL > 512)      // 입력전압이 2.5 volt 이상이면 (정확하게는 AREF/2 이상이면) 
                PORTC = 0xFF;
            else
                PORTC = 0x00;
        }
    }
}
