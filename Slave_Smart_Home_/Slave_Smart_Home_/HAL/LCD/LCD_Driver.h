/*
 * LCD_Driver.h
 *
 * Created: 8/30/2021 2:24:06 PM
 *  Author: Mostafa Elsiekh 
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "avr/io.h"
#include "avr/delay.h"


#define A  0x39
#define B  0x36
#define C  0x33
#define D  0x30

/*====================== LCD CONFIGUARTION ======================*/
#define data C
#define commmand D
#define RS 0
#define E  1
#define mode 4


/*========================= APIs LCD ==============================*/
void lcd_init();
void lcd_command(char cmd) ;//send commends to LCD
void lcd_out(unsigned char value) ; // send data to LCD as (char)
void lcd_print(char *str);// print string
void lcd_go_to(unsigned char x,unsigned char y); // determine position
void lcd_int(int value); // print integer value
void lcd_num(int n);



#endif /* LCD_DRIVER_H_ */