/*
 * Keypad_Driver.c
 *
 * Created: 8/30/2021 2:33:04 PM
 *  Author: Mostafa Elshiekh
 */ 

#include "avr/delay.h"
#include "Keypad_Driver.h"
 

char keypad(void)
{
			PORT=0x01 ;                                           //PORT |=(1<<READ_DATA_REG0) , PORT&=~(1<<READ_DATA_REG1), PORT&=~(1<<READ_DATA_REG1), PORT&=~(1<<READ_DATA_REG1);
			_delay_ms(1);
			if((READ_DATA_REG & 0b00010000 )) return '7';
			if((READ_DATA_REG & 0b00100000 ))  return '8';
			if((READ_DATA_REG & 0b01000000 )) return '9';
			if((READ_DATA_REG & 0b10000000 ))  return '/';
	
			PORT=0x02 ;                                        //PORT &=~(1<<READ_DATA_REG0) , PORT|=(1<<READ_DATA_REG1), PORT&=~(1<<READ_DATA_REG1), PORT&=~(1<<READ_DATA_REG1);
			_delay_ms(1);
			if((READ_DATA_REG & 0b00010000 )) return '4';
			if((READ_DATA_REG & 0b00100000)) return '5';
			if((READ_DATA_REG & 0b01000000 )) return '6';
			if((READ_DATA_REG & 0b10000000 )) return '*';
	
			PORT=0x04 ;                                      //PORT |=(1<<READ_DATA_REG0) , PORT&=~(1<<READ_DATA_REG1), PORT|=(1<<READ_DATA_REG1), PORT&=~(1<<READ_DATA_REG1);
			_delay_ms(1);
			if((READ_DATA_REG & 0b00010000 )) return '1';
			if((READ_DATA_REG & 0b00100000 )) return '2';
			if((READ_DATA_REG & 0b01000000 )) return '3';
			if((READ_DATA_REG & 0b10000000 )) return '-';
	
			PORT=0x08 ;                                    //PORT &=~(1<<READ_DATA_REG0) , PORT&=~(1<<READ_DATA_REG1), PORT&=~(1<<READ_DATA_REG1), PORT|=(1<<READ_DATA_REG1);
			_delay_ms(1);
			if((READ_DATA_REG & 0b00010000 )) return 'C';
			if((READ_DATA_REG & 0b00100000 )) return '0';
			if((READ_DATA_REG & 0b01000000 )) return '=';
			if((READ_DATA_REG & 0b10000000 )) return '+';
	
			return 'N';
}
