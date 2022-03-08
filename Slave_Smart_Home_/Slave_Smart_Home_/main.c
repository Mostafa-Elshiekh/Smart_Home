/*
 * Slave_Smart_Home_.c
 *
 * Created: 8/31/2021 12:44:44 AM
 * Author : Mostafa Elshiekh
 */ 

#include <avr/io.h>
#include "stdint.h"
#include "GPIO_Driver.h"
#include "SPI_Driver.h"
#include "ADC.h"
#include "avr/interrupt.h"
#define F_CPU 8000000

/*Golbal Var*/
volatile unsigned short Temperatue;
volatile char store;
char Flag_Air=0;
uint8_t read_val=0;
uint8_t SPI_DATA=0;
uint8_t Window_Flag=0;
volatile int flag=0;
static unsigned char SevenSeg[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
volatile uint8_t Gas=0;
unsigned char i,j;


void HW_Init(void)
{
	Port_Direction(C,output);
	Port_Direction(D,output);
	Pin_Direction(A,0,input);
	Pin_Direction(A,1,input);
	Pin_Direction(A,2,output);
	Pin_Direction(A,3,input);
	Pin_Direction(A,4,output);

}


int main (void)
{

   HW_Init();
   SPI_Init();
   ADC_init();
   sei();  //Global Interrupt

	Bin_Set(C,0);
	_delay_ms(500);
	while (1) 

	{
		Temperatue=(ADC_u16Read()*0.25);
		store = SPI_DATA;
	
	       	if( Bin_Read(A,1))
	       	{
		       	Bin_Set(C,1);
		       	_delay_ms(3);
		       	Bin_Rest(C,1);
		       	_delay_ms(3);
	       	}
	       	
	       	if( Bin_Read(A,3))
	       	{
		       	Bin_Set(A,2);
		       	_delay_ms(3);
		       	Bin_Rest(A,2);
		       	_delay_ms(3);
			 }

			   
		if(store==1)
		{
			 Bin_Set(D,2);
			_delay_ms(500);
			SPI_DATA = 0;
		}

		if(store==2)
		{

			Bin_Set(D,3);
			SPI_DATA = 0;
		}

		if(store==3)
		{

			Bin_Set(D,4);
			SPI_DATA = 0;
		}

		if(store==4)
		{

			Bin_Set(D,5);
			SPI_DATA = 0;
		}


       if(store==5 && Window_Flag==0)
       {
           Bin_Set(A,4);
           _delay_ms(1000);
           PORTA &=~(1<<4);
           PORTA &=~(1<<4);
           Window_Flag =1;
       }
       
		if(store==5)
		{
			Bin_Set(D,6);
			_delay_ms(50);
			PORTC = 0b0111 | ((Temperatue%10)<<4); 
			_delay_ms(100);
			PORTC = 0b1011 |  ((Temperatue/10)<<4);
			_delay_ms(100);
			SPI_DATA = 0;
			Flag_Air=1;
		}
		
		if(Flag_Air==1)
		{
			_delay_ms(50);
			PORTC = 0b1011 |  ((Temperatue%10)<<4);
			_delay_ms(100);
			PORTC = 0b0111 | ((Temperatue/10)<<4);
			_delay_ms(100);
		}
       
	}
}

//ISR
ISR (SPI_STC_vect)
{
	SPI_DATA = SPDR;
}