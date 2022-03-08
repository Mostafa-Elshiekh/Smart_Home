/*
 * ADC.c
 *
 * Created: 9/1/2021 3:22:43 AM
 *  Author: Mostafa Elshiekh
 */ 

#include "ADC.h"

void ADC_init(void)
{
	ADCSRA=(1<<ADPS0)|(1<<ADPS1);  //Enable ADC and Select Prescaler (8)
	ADMUX|=(1<<ADLAR);             //8 bit mood (just ADCH) (left adjusted
	ADMUX|=(1<<MUX0);             // Select Channel
	ADMUX=(1<<REFS0)|(1<<REFS1);
	ADCSRA|=(1<<ADEN);

}
unsigned short ADC_u16Read(void)
{
	unsigned short read_val;
	
	 ADCSRA|=(1<<ADSC); //start conversion
	 while((ADCSRA &(1<<ADIF))==0);//wait the conversion stop
	 read_val=ADCL|ADCH;
	 return read_val;
}