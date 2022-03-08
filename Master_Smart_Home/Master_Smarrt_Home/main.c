/*
 * Master_Smart_Home.c
 *
 * Created: 8/30/2021 2:20:41 PM
 * Author : Mostafa Elshiekh
 */ 



#include "avr/io.h"
#include "LCD_Driver.h"
#include "Keypad_Driver.h"
#include "GPIO_Driver.h"
#include "ADC.h"
#define  F_CPU  8000000



int main(void)
{

	HW_Init();
	lcd_init();
	SPI_Init();
    Welcome_User();
    Hello_User();
   
   
    while (1) 
    {
		 	   //Log in page && determine the user
                LogIn();
				Wrong_Choice();
	            AdminMode();
		        Check_Pass_Admin();
		        Admin_Choice();
			    GuestMode();
			    Check_pass_Guset();
			    Guset_Choice();	
			    Hello_User();
    
    }
}

