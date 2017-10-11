//*******************************************************************************************************
//* Name: Lidia Van Moen and Lauryn Jeffrey                            
//* Date: 10/06/2017
//*	Class: Embedded Systems Lab
//* Prof: Chase
//* Lab Description: This is my GPIO section, and in here I set up my inputs and outputs
//*                  I unlocked the switches on the board, and enabled the pull up resistors.
//*									 And then I made it so that when you press SW1 you get an LED to light and then
//*                  When you press the other switch (SW2) you get a different LED to light.
//*									 And to make it friendly if you press both switches you can exit the function's loop.
//*Hardware Description: TIVA C Series LaunchPad. TMC123G micro
//*********************************************************************************************************

#include <stdio.h>
#include <stdint.h>
#include "myGPIO.h"

#include "tm4c123gh6pm.h"	// Header file accesses registers in TMC123 microcontroller
	
void Delay(void);

// This is my function to set up my Inputs and Outputs for my GPIO
void setup_IO()
{
		// Enable the GPIO port that is used for the on-board LED.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		
		// I found this code on the internet, but it basically makes it so that I can
		// Actually use the two switches on my board. So thats pretty dope.
		GPIO_PORTF_LOCK_R = 0x4C4F434B;   // Unlock PF0  
		GPIO_PORTF_CR_R = 0x1F;           // Allow changes to PF4-0       
		GPIO_PORTF_AMSEL_R = 0x00;        // Disable analog function
		GPIO_PORTF_PCTL_R = 0x00000000;   // GPIO clear bit PCTL  
		GPIO_PORTF_DIR_R = 0x0E;          // PF4,PF0 input, PF3,PF2,PF1 output   
		GPIO_PORTF_AFSEL_R = 0x00;        // No alternate function
		GPIO_PORTF_PUR_R = 0x11;          // Enable pullup resistors on PF4,PF0       
		GPIO_PORTF_DEN_R = 0x1F;          // Enable digital pins PF4-PF0        	
}

void GPIOfunction(uint32_t ui32Loop,uint8_t temp)
{
	
		int SW1;  
		int SW2;  
		int i = 1; 	// This is so that I can loop through this and keep checking if my switches are pushed
	
		printf("You can change some stuff by pressing switches 1 and 2\n Press switch 2 to turn");
		printf("on a purple LED \n Press switch 1 to turn on green LED \n Press both to turn off the LEDs and exit GPIO\n\n");	
	
		while (i == 1){
			SW1 = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4); // set x equal to the output of button SW1
		  SW2 = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0); // set x equal to the output of button SW2
		 
		if (SW2 == 1){ 	// When my SW2 isn't pressed I don't want anything to happen
			
		}
		if( SW1==1){		// When my SW1 isn't pressed I don't want anything to happen
			
		}
		if (SW2 == 0) // If SW2 is pressed a purple light comes on
			{
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);	 // Turn off green LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn on blue LED	
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);	 // Turn on red LED
      }
				
		if (SW1==0) // So if SW1 is pressed I want a green LED to come on and stay on
				{ 
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);   // Turn off blue LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);		// Turn off red LED
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);   // Turn on the green LED.
        }
		if( SW2 == 0 &&  SW1 ==0) // If both SW1 and SW2 are pressed I want to exit the loop and go back to the main menu
			{ 
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0); // I want to turn off the LEDS so I will.
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
			i=0;	// this is so that I can exit that infinite loop I created to keep checking the switches.
			}
	}
}
	 