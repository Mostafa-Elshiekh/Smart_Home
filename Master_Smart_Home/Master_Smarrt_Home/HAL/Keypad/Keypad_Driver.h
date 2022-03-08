/*
 * Keypad_Driver.h
 *
 * Created: 8/30/2021 2:33:29 PM
 *  Author: Mostafa Elshiekh
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

/*============================ Include ===============================*/
#include "avr/io.h"


/*====================== Keypad Configuration =======================*/
#define PORT                             PORTA
#define READ_DATA_REG       PINA


/*============================ APIs ================================*/
char keypad(void);


#endif /* KEYPAD_DRIVER_H_ */