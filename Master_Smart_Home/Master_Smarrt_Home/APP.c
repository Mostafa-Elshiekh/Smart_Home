/*
 * APP.c
 *
 * Created: 9/1/2021 10:28:42 PM
 *  Author: Mostafa Elshiekh
 */ 


#include "avr/io.h"
#include "LCD_Driver.h"
#include "Keypad_Driver.h"
#include "GPIO_Driver.h"
#include "ADC.h"

/*Global Var*/
int Admin_Pass = 1111;
int Guest_Pass = 2222;
char Flag=0;
int pass[4];
char i=0;
int Temp=0;
int Choise_Num=0;
char store=0;
int password=0;
char Admin_Mode=0;
char Guest_Mode=0;
char Red_Key=0;
char Check_Temp=0;


void Welcome_User(void)
{
	lcd_go_to(2,5);
	lcd_print("Welcome in");
	lcd_go_to(3,5);
	lcd_print("smart home :)");
	lcd_command(0x0c);
	_delay_ms(600);
}


void Hello_User(void)
{
	lcd_command(0x01);
	lcd_go_to(1,1);
	lcd_print("Are you Admin/Guest?");
	
	lcd_go_to(2,1);
	lcd_print("Admin press: 1");
	lcd_go_to(3,1);
	lcd_print("Guest press: 2");
	lcd_go_to(4,1);
	lcd_print("Enter Your Choice: ");
	while(keypad()=='N');
	lcd_command(0x0c);
}


void HW_Init(void)
{
	Port_Direction(C,output);
	Port_Direction(D,output);
	Pin_Direction(A,0,output);
	Pin_Direction(A,1,output);
	Pin_Direction(A,2,output);
	Pin_Direction(A,3,output);
	Pin_Direction(A,4,input);
	Pin_Direction(A,5,input);
	Pin_Direction(A,6,input);
	Pin_Direction(A,7,input);
	Pin_Direction(B,0,output);
	Pin_Direction(B,1,output);
}


void LogIn(void)
{
	if((keypad()!='N') )
	{
		
		Red_Key = keypad();
		Temp = Red_Key;
		lcd_go_to(4,19);
		lcd_out(Red_Key);
		_delay_ms(200);
		
			if(Red_Key !='1' )
			{
				if(Red_Key!='2')
				{
					Check_Temp=1;
				}
			}
	}
}
void Wrong_Choice(void)
{
	while( Check_Temp )
	{
		lcd_command(0x01);
		lcd_go_to(1,5);
		lcd_print("Wrong Choice :(");
		lcd_go_to(2,5);
		lcd_print("Try Again ");
		_delay_ms(1000);
		Hello_User();
		_delay_ms(1000);
		while(keypad()=='N');
		Temp = keypad();
		if(Temp =='1' || Temp =='2' )
		{
			Check_Temp=0;
		}
		
		lcd_go_to(4,19);
		lcd_out(Temp);
		_delay_ms(200);
	}
}



void AdminMode(void)
{
	if( Temp == '1' )   //Admin Mode
	{
		lcd_command(0x01);
		lcd_go_to(1,1);
		lcd_print("Please Enter ");
		lcd_go_to(2,1);
		lcd_print("The Admin pass: ");
		_delay_ms(100);
		lcd_go_to(2,16);
		Guest_Mode =1;
		for(i=0;i<4;i++)
		{
			while(keypad()=='N');
			Temp = (keypad()-48);
			lcd_out(Temp+48);
			pass[i]=Temp;
			_delay_ms(200);
		}
	}
	password =((pass[3]*1000)+(pass[2]*100)+(pass[1]*10)+(pass[0]*1));
	_delay_ms(100);
	
}



void Check_Pass_Admin(void)
{
	if(password == 1111 && Admin_Mode==0) //This is Admin
	{
		lcd_command(0x01);
		Bin_Set(C,4);
		lcd_go_to(1,1);
		lcd_print("Control By Press Num");
		lcd_go_to(2,1);
		lcd_print("Room1: 1");
		lcd_go_to(2,12);
		lcd_print("Room2: 2");
		lcd_go_to(3,1);
		lcd_print("Room3: 3");
		lcd_go_to(3,12);
		lcd_print("TV: 4");
		lcd_go_to(4,1);
		lcd_print("Air Conditioner:5");
	}
}


void Admin_Choice(void)
{
	while(keypad()=='N');
	Choise_Num = keypad()-48;
	
	//Room 1
	if(Choise_Num == 1)
	{
		SPI_Send_Data(Choise_Num);
		lcd_go_to(4,19);
		lcd_int(Choise_Num);
		_delay_ms(20);
	}
	
	//Room 2
	if(Choise_Num == 2)
	{
		SPI_Send_Data(Choise_Num);
		lcd_go_to(4,19);
		lcd_int(SPI_Send_Data(Choise_Num));
		_delay_ms(20);
	}
	
	//Room 3
	if(Choise_Num == 3)
	{
		SPI_Send_Data(Choise_Num);
		lcd_go_to(4,19);
		lcd_int(SPI_Send_Data(Choise_Num));
		_delay_ms(20);
	}
	
	//TV
	if(Choise_Num == 4)
	{
		SPI_Send_Data(Choise_Num);
		lcd_go_to(4,19);
		lcd_int(SPI_Send_Data(Choise_Num));
		_delay_ms(20);
	}
	
	//Air Conditioner
	if(Choise_Num == 5)
	{
		SPI_Send_Data(Choise_Num);
		lcd_go_to(4,19);
		lcd_int(SPI_Send_Data(Choise_Num));
		_delay_ms(20);
	}
	
}


void Check_pass_Guset(void)
{
	if( password == 2222) //Guist Mode
	{
		lcd_command(0x01);
		lcd_command(0x01);
		Bin_Set(C,5);
		lcd_go_to(1,1);
		lcd_print("Control By Press Num");
		lcd_go_to(2,1);
		lcd_print("TV: 4");
		lcd_go_to(3,1);
		lcd_print("Air Conditioner:5");
	}
	while(keypad()=='N');
	Choise_Num = keypad()-48;
}


void GuestMode(void)
{
	if( Temp == '2' )   //Admin Mode
	{
		lcd_command(0x01);
		lcd_go_to(1,1);
		lcd_print("Please Enter ");
		lcd_go_to(2,1);
		lcd_print("The Guest pass: ");
		_delay_ms(100);
		lcd_go_to(2,16);
		Admin_Mode =1;
		for(i=0;i<4;i++)
		{
			while(keypad()=='N');
			Temp = (keypad()-48);
			lcd_out(Temp+48);
			pass[i]=Temp;
			_delay_ms(200);
		}
	}
	password =((pass[3]*1000)+(pass[2]*100)+(pass[1]*10)+(pass[0]*1));
	_delay_ms(100);
}




void Guset_Choice(void)
{
	
	//TV
	if(Choise_Num == 4)
	{
		SPI_Send_Data(Choise_Num);
		lcd_go_to(3,19);
		lcd_int(SPI_Send_Data(Choise_Num));
		_delay_ms(100);
	}
	
	//Air Conditioner
	if(Choise_Num == 5)
	{
		SPI_Send_Data(Choise_Num);
		lcd_go_to(3,19);
		lcd_int(SPI_Send_Data(Choise_Num));
		_delay_ms(100);
	}
	
}

