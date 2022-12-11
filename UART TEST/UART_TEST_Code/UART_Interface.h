/*
 * UART_Interface.h
 *
 * Created: 12/11/2022 3:52:45 PM
 *  Author: Omarm
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#define UART_BAUDRATE 9600
void UART_Init(void);
void UART_SendByte(unsigned char Byte);
unsigned char UART_ReceiveByte(void);



#endif /* UART_INTERFACE_H_ */