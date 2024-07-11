/*
 * PMW.c
 *
 * Created: 09-07-2024 09:55:06
 * Author : SRIDHAR
 */ 

#define F_CPU 1000000UL
#include "avr/io.h"
#include <util/delay.h>

void PWM_init()
{
	/*set fast PWM mode with non-inverted output and clear OC2 on compare match*/
	TCCR1A = (1<<COM1A0) | (1<<WGM11) | (1<<WGM10);
	TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS12) | (1<<CS11) | (1<<CS10);
	DDRD |= (1<<PD5);  /*set OC2 pin as output*/
}

int main ()
{
	
	unsigned char duty;
	
	PWM_init();

	while (1)
	{
		for(duty=0; duty<255; duty++)
		{
			OCR1A=duty;  /*increase the LED light intensity*/
			_delay_ms(10);
		}
		for(duty=255; duty>1; duty--)
		{
			OCR1A=duty;  /*decrease the LED light intensity*/
			_delay_ms(10);
		}
	}
}