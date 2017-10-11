//*******************************************************************************************
//* Name: Lidia Van Moen and Lauryn Jeffrey                            
//* Date: 10/06/2017
//*	Class: Embedded Systems Lab
//* Prof: Chase
//* Lab Description: This is my UART section. This allows users to input a value and then see
//*                  some results on the launchpad. My system is pretty simple. So what I did
//*									 Is I saved the users input and then entered a switch statement. This
//*                  specific functions allows the users to change the color of the LED on the 
//*									 board. And if they enter the wrong value it exits the function. Or if they
//*									 want to exit the UART testing they can. Pretty simple.
//*Hardware Description: TIVA C Series LaunchPad. TMC123G micro
//*******************************************************************************************

#include <stdio.h>
#include <stdint.h>
#include "myUART.h"

void UARTfunction(char ctemp)
{
	int i = 1; // This is for my while loop
	
	while(i==1){
		printf("What LED would you like to turn on?\nPress 1 to turn on a Blue LED \nPress 2 to"); 
		printf(" turn on a Purple LED\nPress 3 to turn on a Green LED\nPress 4 to Exit UART\n\n");
		ctemp = getc(stdin);
		printf("%c\n",ctemp);
		
	switch (ctemp)
			{
			case '1':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn on blue LED	
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off LED			
				break;			
			case '2':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);  // Turn on red LED	
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off LED			
				break;			
			case '3':
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);  // Turn on green LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off LED
				break;		
			case '4':
				i=0; // This is so that I can exit my loop once I am done
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off LED
			break;
			default:				
				printf("Wrong Value. Try Again.\n\n");
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off LED
				break;		
		}
	}
}