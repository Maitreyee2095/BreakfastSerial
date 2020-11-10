/*
 * Hexdump.c
 *
 *  Created on: Nov 9, 2020
 *      Author: maitreyee rao
 *      parts of code were sourced from Howdy's code for assignment 1
 */

#include "Command_logger.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#define MAX_LEN 640
#define STRIDE 16

/*********************************************************************************************************
static char int_to_hexchar(int x)
converts given integer to its hex value
@param
x       integer value to be converted

@returns
char      hex value of same

**************************************************************************************************************/
static char int_to_hexchar(int x)   //convert integers to char //this code was sourced from howdy's code for assignment 1
{
	if (x >=0 && x < 10)
		return '0' + x;
	else if
	(x >= 10 && x < 16)
		return 'A' + x - 10;
	else
		return '-';
}
/*********************************************************************************************************
void hexdump( char* address, char* length);
Hexdumps for provided start address and length
length can be hex or decimal and handles both
length has to be in range of 0 640
@param
address        start address
length         length for hex dump

@returns void

**************************************************************************************************************/

void hexdump( char* address, char* length)
{

	int add;//integer to store address
	int len;//integer to store length
	uint8_t* start_address; //address in uint8_t

	sscanf(address,"%x",&add); //use scanf to convert string to hex address
	if(((*(length+1))=='x')||((*(length+1)) =='X')) //check if length is in format'0x00' which is if user entered hex length
	{
	  sscanf(length,"%x",&len); //scan hex length

	}
	else
	{
		sscanf(length,"%d",&len);//scan decimal length

	}


	start_address = (uint8_t*)atoi(address); //store address
	if(len<=MAX_LEN) //check if length is within limits
	{


		for(int i =1;i<=len; i++)
		{
			int j =1;
			//this code was inspired from Howdy's code for hex dump
			//convert and print address in format xxxx_xxxx
			putchar(int_to_hexchar((((uint32_t)add & 0xF0000000)>>28)));
			putchar(int_to_hexchar((((uint32_t)add & 0x0F000000)>>24)));
			putchar(int_to_hexchar((((uint32_t)add & 0x00F00000)>>20)));
			putchar(int_to_hexchar((((uint32_t)add & 0x000F0000)>>16)));
			putchar('_');
			putchar(int_to_hexchar((((uint32_t)add & 0x0000F000)>>12)));
			putchar(int_to_hexchar((((uint32_t)add & 0x00000F00)>>8)));
			putchar(int_to_hexchar((((uint32_t)add & 0x000000F0)>>4)));
			putchar(int_to_hexchar((((uint32_t)add & 0x0000000F))));
			putchar(' ');
			if(i==(int)len) //check if i= length last byte to print
			{
				printf("%02x ",*(start_address)); //print last byte
				break;

			}
			while (j % STRIDE != 0)
			{

				printf("%02x ",*(start_address)); //print byte at address
				start_address++; //increment address
				add++; //increment add
				j++;//increment counter

			}
			len-=16; //decrement length
			start_address++; //increment for last address 16
			add++;
			printf("\r\n");
		}
		printf("\r\n");
	}
	else
	{

		printf("Please Enter a valid length\n\r");
	}

}



