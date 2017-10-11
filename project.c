//*******************************************************************************************
//* Name: Lidia Van Moen and Lauryn Jeffrey                            
//* Date: 10/06/2017
//*	Class: Embedded Systems Lab
//* Prof: Chase
//* Lab Description: This is my midterm project. I was supposed to get GPIO, Systick Timer,
//*                  UART, ADC, NVIC and PWM to work. So I did. 
//*									 You can find the specifics on the ".c" files of each type. 
//*                  This main file was designed to set up my hardware, make my User input 
//*									 work and to make flipping through my code simple, so that anyone can see 
//*									 how successful my project was. 
//*Hardware Description: TIVA C Series LaunchPad. TMC123G micro
//*******************************************************************************************

#include "project.h"
#include <stdio.h>
#include <stdint.h>

#ifdef DEBUG

void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

void SetupHardware()
{
	UartSetup();				// Setting up UART so I can use it
	setup_IO();		      // Function that unlocks certain pins that are needed.
	SetupSystick();			// Setting up the Systick
	SetupADC();					// Setting up ADC so I can use it
}

int  main(void)
3 {		
		uint8_t temp; 								//Tempt char used for UART
		char ctemp; 									// Temp 8-bit int used for gpio functions
    volatile uint32_t ui32Loop;		// 32-bit int used for multiple func. 
   
    SetupHardware();							//Calling the function to set up all the things.
	 
		int i = 1;										// I intialize this i so that I can infinitely loop through this code until I don't wanna
	 
		while (i==1){
			printf("What feature would you like to test?\n Enter a 1 to test UART \n Enter a 2 to test Systick \n");
			printf(" Enter a 3 to check GPIO \n Enter a 4 to check ADC \n Enter a 5 to Check NVIC \n Enter a 6 to Check PWM");
			ctemp = getc(stdin);			//	This will store the user's input so that I can use it in my case statement.
			printf("%c\n", ctemp);  
	
		// This is a fancy switch statement so that you can check each part of my code
		// Individually without having to go through each section every time you wanna check
		// Something out!
		switch (ctemp)
			{
			case '1':
					printf("\n You entered %c, We are testing UART\n\n", ctemp);
				  UARTfunction(ctemp);
				break;			
			case '2':
					printf("\n You entered %c, We are testing Systick\n\n", ctemp);
					SysTickWait(50);
				break;	
			case '3':
					printf("\n You entered %c, We are testing GPIO\n\n", ctemp);
					GPIOfunction(ui32Loop,ctemp);
				break;	
			case '4':
					printf("\n You entered %c, We are testing ADC\n\n", ctemp);
				  ADCfunction();
				break;	
			case '5':
					printf("\n You entered %c, We are testing NVIC\n", ctemp);
					printf("I got N O T H I N G, except maybe I might use NVIC in my Systick .....\n\n");
				break;	
			case '6':
					printf("\n You entered %c, We are testing PWM\n\n", ctemp);
					PulseWidthModulation(ctemp);
					break;	
			default:
					printf("\n The value you entered wasn't an option. Try again.\n\n");
					break;
			
				}
			}
}
