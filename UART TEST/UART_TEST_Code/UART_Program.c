/*
 * UART_Program.c
 *
 * Created: 12/11/2022 3:53:26 PM
 *  Author: Omarm
 */ 

/*
 * BAUD = 9600
 * Stop bits = 1 Stop bit
 * Parity bits = Disabled
 * Data bits = 7 bits
 * Async
*/
#include <avr/io.h>
#include "UART_Interface.h"

void UART_Init(void)
{
	/*According to datasheet UBRR must be set to 12 to have a baudrate of 9600*/
	UBRRH = 0;
	UBRRL = 12;
	
	/*This line enables double speed mode*/
	UCSRA = (1<<U2X);
	
	/*This line selects the data frame width to be 7 data bits*/
	UCSRC = (1<<URSEL) | (1<<UCSZ1);
	
	/*This line enables UART send and receive pins*/
	UCSRB = (1<<RXEN) | (1<<TXEN);
}
void UART_SendByte(unsigned char Byte)
{
	/*This line polls UDRE flag to check if Tx register can be written*/
	while ((UCSRA & (1<<UDRE)) == 0) { /*Do nothing*/}
	
	/*Assign data to UDR to be sent over UART*/
	UDR = Byte;
}
unsigned char UART_ReceiveByte(void)
{
	/*This line polls RXC flag to check if Rx register can be read*/
	while ((UCSRA & (1<<RXC)) == 0) { /*Do nothing*/}
	return UDR;
}
