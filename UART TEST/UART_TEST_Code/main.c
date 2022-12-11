/*
 * UART_DRIVER.c
 *
 * Created: 12/11/2022 3:48:41 PM
 * Author : Omarm
 */ 

#include <avr/io.h>
#define F_CPU 1000000U
#include "UART_Interface.h"
int main(void)
{
	UART_Init();
	char v = 'a';
    /* Replace with your application code */
    while (1) 
    {
		UART_SendByte(v);
		v = UART_ReceiveByte();
    }
}

