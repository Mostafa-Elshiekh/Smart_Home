/*
 * ADC.h
 *
 * Created: 9/1/2021 3:23:02 AM
 *  Author: Mostafa Elshiekh
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "avr/io.h"
#include "avr/delay.h"
void ADC_init(void);
unsigned short ADC_u16Read(void);


#endif /* ADC_H_ */