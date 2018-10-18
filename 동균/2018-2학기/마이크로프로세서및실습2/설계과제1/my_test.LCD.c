#include<stdio.h>
#include<avr/io.h>
#include "my_atmega128.h"
#include "my_LCD.h"

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
     					
    char result[16];
    double my_value;
    my_value = 2.34;

    LCD_initialize();  
   
   while(1)
   {
     sprintf(result,"voltage: %.2f[v]", my_value);
 
     LCD_string(0x80,result);
     LCD_string(0xC0,"  OK? ^^ ");
   }
}
