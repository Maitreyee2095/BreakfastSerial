/*
 * Hexdump.h
 *
 *  Created on: Nov 9, 2020
 *      Author: maitr
 */

#ifndef HEXDUMP_H_
#define HEXDUMP_H_
#include "Circular_buffer.h"
#include "UART.h"
#include "sysclock.h"
#include "MKL25Z4.h"
#include "core_cm0plus.h"
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
void hexdump( char* address, char* length);

#endif /* HEXDUMP_H_ */
