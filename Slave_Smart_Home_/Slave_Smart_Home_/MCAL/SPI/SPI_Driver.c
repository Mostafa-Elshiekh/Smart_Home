/*
 * SPI_Driver.c
 *
 * Created: 8/30/2021 2:49:10 PM
 *  Author: Mostafa Elshiekh
 */ 


#include "avr/io.h"
#include "SPI_Driver.h"
#include "LCD_Driver.h"


	

void SPI_Init(void)
{
	
			if(Master_Mode == 1)
			{
				DDRB &=~((1<<SS) | (1<<MOSI)|(1<<SCK));
				DDRB &=~(1<<MISO);
				
				 SPCR |=(1<<4);  //Bit 4 – MSTR: Master Select
				
		        // DORD: Data Order
				SPCR |=(1<<5); //DORD bit is written to one To LSB
				
				//Clock Polarity 
				SPCR &=~(1<<3);//Rising
				
				//Clock Phase
				SPCR &=~(1<<0); //Sample
			    SPCR |=(1<<6);//Bit 6 – SPE: SPI Enable
				
				//Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0
				SPCR &=~((1<<0) | (1<<1));  //fosc/4
				SPSR &=~(1<<0);
				
				//Bit 6 – SPE: SPI Enable
				SPCR |=(1<<6);
			}
			
			if(Slave_Mode == 1)
			{
		    
			/*DDRB &=~((1<<SS) | (1<<MOSI)|(1<<SCK));
			DDRB |=(1<<MISO);
			
			SPCR &=~(1<<4);  //Bit 4 – MSTR: Slave Select
			
			
			
			//Clock Polarity
			SPCR &=~(1<<3);//Rising
			
			//Clock Phase
			SPCR &=~(1<<0); //Sample

			
			//Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0
			SPCR &=~((1<<0) | (1<<1));  //fosc/4
			
			//Bit 6 – SPE: SPI Enable
			SPCR |=(1<<6);*/
			 /*Make this pins as input in slave*/
			 DDRB &= ~( (1<<SS) | (1<<MOSI) | (1<<SCK) );
			 
			 /* SPE bit is written to one, the SPI is enabled*/
			 SPCR = ( (1<<SPE)  | (1<<SPR0) );
			 SPCR |=(1<<SPIE); //interrupt Enable
			 /*Slave SPI mode when written to zero*/
			 SPCR &=~(1<<MSTR);
			
	
		
			}
	
}


void SPI_Send_Data(char Data)
{
	
	SPDR = Data;
	while( (SPSR>>7) !=1 );  //When a serial transfer is complete, the SPIF Flag is set
	
}


char SPI_Recieve_Data(void)
{
	
	/*	while( (SPSR>>7) !=1 ); //When a serial transfer is complete, the SPIF Flag is set
		return SPDR;*/
	while( ! ( SPSR &(1<<SPIF))  ); //while Receive not complete -->wait
	return SPDR;
	
}


