/*
 * Command_process.c
 *
 *  Created on: Nov 9, 2020
 *      Author: maitreyee Rao
 *   some code from this file was used from the lexical analysis code that Howdy gave in lecture 11
 */

#include "Command_logger.h"
#include "Command_process.h"
#include "Hexdump.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define SPACE 0x20
#define ENTER 0x0D
#define MAX_BUF 50
//commands that are considered valid
//can add a new command to this string
const char *command_strings[] = {
		"author",
		"dump",
		"Help",
};

/*********************************************************************************************************
 * void process_command(char*input): performs a lexical analysis on string thats entered
 * splits the string using ' ' (space) as token
 * when a ' ' is detected it appends the string and stores it in array argv[]
 * argc returns the number of elements of the array argv[]
 *
 * depending on argc it passed the output argv[] to different command handlers
 *
 * @param
 * input    String to be parsed
 *
 * @returns null
 **********************************************************************************************************/
void process_command(char *input) //code from howdy's lecture 11
{
	char *p = input;
	char *end;
	char *argv[MAX_BUF];
	int argc = 0;
	// find end of string
	for (end = input; *end != '\0'; end++)
		;

	// Tokenize input in place
	bool in_token = false;
	memset(argv, 0, sizeof(argv));
	for (p = input; p <end-1; p++) {

		if(in_token)  // if token is true
		{
			if((*p== ' ')||(*p=='\t')) //if space is found
			{
				*p='\0'; //append the string
				in_token=false;//change token to false
			}
			else
			{
				argv[argc]=p; //else add the character to array

			}
		}
		else //if token is false
		{
			if((*p== ' ')||(*p=='\t')) //if space is found
			{
				*p='\0'; //append string
			}
			else
			{

				argv[argc]= p; //add character to argv array
				argc++;//increment argc
				in_token=true; //change token

			}
		}


	}
	argv[argc] = NULL;//append string
	if (argc == 0)   // no command
		return;



	// TODO: Dispatch argc/argv to handler
	switch(argc)
	{
	case 1: //if just 1 argument present pass for command 1 handler //if adding commands can have command handler of their own n passit here;
		command1(argv[0]);
		break;
	case 3:
		command2(argv[0],argv[1],argv[2]);
	default:
		printf("Enter Valid Command\n\r");
	}

}
/*********************************************************************************************************
void command2(char* cmd,char* address, char* length)
processes commands with argc 1 i.e 1 strings it checks if the first string matches command and processes further
@param
cmd        command
p

@returns void

 **************************************************************************************************************/

void command1(char *cmd)
{

	if((strncasecmp(cmd,command_strings[0],sizeof(command_strings[0]))==0)) //check if the argument and defined commands match
	{
		printf("%s :Maitreyee Rao\n\r",cmd); //process  command
	}
	else if((strncasecmp(cmd,command_strings[2],sizeof(command_strings[2]))==0))
	{
		printf("Help\n\r");
		printf("Enter command to perform one of the following functions press enter:\r\n");
		printf("'Author' or 'author' : Name of the Author \r\n");
		printf("'dump <address> <total length>(valid length:0 to 640)' : Performs a hexdump for the address and length provided\r\n");
		printf("'DUMP <address> <total length>' : HEX DUMP for specified locations\r\n");
		printf("'Help' or 'help' : Get the help menu\r\n");

	}
	else if(*cmd == ENTER)
	{
		;
	}
	else
	{
		printf("Please Enter a valid command\n\r"); //if it doesnt match to any command throw an error
	}

}

/*********************************************************************************************************
void command2(char* cmd,char* address, char* length)
processes commands with argc 3 i.e 3 strings it checks if the first string matches command and passes further for function

@param
cmd        command
address    second string address for hex dump
length      third string length for hexdump

@returns void

 **********************************************************************************************************/
void command2(char* cmd, char* address, char* length)
{

	if((strncasecmp(command_strings[1],cmd,sizeof(command_strings[1]))==0)) //check if command is right
	{

		hexdump(address, length); //call hexdump function

	}
	else
	{

		printf("Please Enter a valid command\n\r"); //throw error
	}
}
