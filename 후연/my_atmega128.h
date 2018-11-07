void Delay_us(unsigned char time_us)		/* time delay for us */
{   register unsigned char i;

     for(i = 0; i < time_us; i++);
     for(i = 0; i < time_us; i++);
     for(i = 0; i < time_us; i++);
     for(i = 0; i < time_us; i++);
}

void Delay_ms(unsigned int time_ms)       	/* time delay for ms */
{    register unsigned int i;
  
   for(i = 0; i < time_ms; i++) {
        Delay_us(250);
        Delay_us(250);
        Delay_us(250);
        Delay_us(250);
     }
}
