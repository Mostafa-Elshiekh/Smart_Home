/*
 * SPI_Driver.h
 *
 * Created: 8/30/2021 2:49:39 PM
 *  Author: Mostafa Elshiekh
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_


/*======================== SPI Configurations ========================*/
// MSTR: Master/Slave Select
#define Master_Mode                         1 
#define Slave_Mode                            0

#define SS                                             4
#define MOSI                                        5
#define MISO                                        6
#define SCK                                           7


/*============================ APIs ================================*/
void SPI_Init(void);
char SPI_Send_Data(char Data);
char SPI_Recieve_Data(void);



#endif /* SPI_DRIVER_H_ */