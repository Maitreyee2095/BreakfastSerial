/*
 * main.c - application entry point
 * 
 * Author Howdy Pierce, howdy.pierce@colorado.edu
 */
#include "sysclock.h"
#include "MKL25Z4.h"
#include "core_cm0plus.h"
#include "UART.h"
#include "Command_logger.h"
#include "Circular_buffer.h"
#include "test_cbfifo.h"

int main(void)
{

	sysclock_init();


	// TODO: initialize the UART here
	UART_init(38400);//set baud rate to 38400
	test_cbfifo(); //test circular buffer;




	printf( "\n\rWelcome to BreakfastSerial \n\r");
	printf("\n\rEnter command to perform one of the following functions and press enter:\r\n");
	printf("'Author' : Name of the Author \r\n");
	printf("'Dump <address> <total length>(valid length:0 to 640)' : Performs a hexdump for the address and length provided\r\n");
	printf("'Help' : Get the help menu\r\n");

	while (1) {

		command_input();

	}
	return 0 ;
}
