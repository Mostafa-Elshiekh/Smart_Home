/*
 * GPIO_Driver.h
 *
 * Created: 8/30/2021 2:54:36 PM
 *  Author:  Mostafa Elshiekh
 */ 


#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

/*============================ Include ===============================*/
#include <avr/io.h>
#include <avr/delay.h>


/*====================== GPIO Configuration ==========================*/
#define  A 0x39
#define  B 0x36
#define  C 0x33
#define  D 0x30
#define  output 1
#define input 0


/*============================ APIs ================================*/
void       Bin_Set(uint8_t  base , uint8_t  bit);
void	      Bin_Rest (uint8_t  base , uint8_t  bit);
void	      toggle_bit (uint8_t  reg , uint8_t  bit);
void       Pin_Direction(uint8_t  base , uint8_t  bin , uint8_t  state );  //base is register bin
void       Port_Direction(uint8_t  base  , uint8_t  state ) ; //base is register bin
uint8_t  Port_Read(uint8_t  base);
uint8_t  Port_Write(uint8_t  base , uint8_t  value);
uint8_t  Bin_Read(uint8_t  base , uint8_t   bin);
uint8_t  Bin_Write(uint8_t  base , uint8_t  bin, uint8_t  value);





#endif /* GPIO_DRIVER_H_ */