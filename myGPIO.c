#include <stdio.h>
#include <stdint.h>
#include "myGPIO.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller


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


void pinReadAndWrite(void)
	{

	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);  // Set PB0 Low
	
	}

	