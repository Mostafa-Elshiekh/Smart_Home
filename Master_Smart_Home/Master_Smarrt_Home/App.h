/*
 * App.h
 *
 * Created: 9/2/2021 10:31:57 PM
 *  Author: Mostafa Elshiekh
 */ 


#ifndef APP_H_
#define APP_H_


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

       /*APIs*/
void Welcome_User(void);
void Hello_User(void);
void HW_Init(void);
void LogIn(void);
void Wrong_Choice(void);
void AdminMode(void);
void Check_Pass_Admin(void);
void Admin_Choice(void);
void Check_pass_Guset(void);
void GuestMode(void);
void Guset_Choice(void);


#endif /* APP_H_ */