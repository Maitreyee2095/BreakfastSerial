In this Assignment we initialized UART for Freedom KL25z
The required settings for UART were:

Baud rate:3840
Parity bits:0
Stop bits:2
Total data bits :8
 

Following Commands were Implemented, All commands being case sensitive
1)	Author: Name of Author
2)	Dump <start address> <Length> : to hex dump data for provided address and length
3)	Help: Help Menu that provides user info with commands available
If a user enters invalid command it is specified to the user to enter a valid command.
At the start of the program User is also presented with list of command available.
To add a new command the user will have to add the command to the string array
And add the command handler function of its own, instructions for the same are provided in comments 
of the code.
Along with the required functionality, I also implemented backspace functionality, the way professor 
Howdy taught in the lecture.

 
 The code is implemented using Circular buffers.
The code initializes two buffers at the start of uart initialization.
One buffer is used for Rx and the other is used for Tx.
At the start of the main function both buffers are tested.
Printf and Scanf inbuilt functions are tied to UART.
Care is taken than while printing no bits are lost, speed of enqueue in buffer is synchronized with speed 
of dequeuing the buffer.
