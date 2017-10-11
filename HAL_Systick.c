//*******************************************************************************************
//* Name: Lidia Van Moen and Lauryn Jeffrey                            
//* Date: 10/06/2017
//*	Class: Embedded Systems Lab
//* Prof: Chase
//* Lab Description: This is my Systick timer. It's pretty messy. Most of this I got off of 
//*                  Git Hub. But basically I am trying to set up the Systick clock so that 
//*									 I have a delay that I can call, that will delay for a specific amount of
//*                  time. My function at the end just calls my systick delay and shows it
//*									 works by keeping an LED on for a specified amount of time. 
//*Hardware Description: TIVA C Series LaunchPad. TMC123G micro
//*******************************************************************************************

#include "HAL_Systick.h"
#include "myGPIO.h"

void SetupSystick()
{
	SysTickPeriodSet(NVIC_ST_RELOAD_M);
	SysTickEnable();
}


// Time delay using busy wait.
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTick(unsigned long delay)
{
	NVIC_ST_RELOAD_R = delay-1;  // This is how many counts I have to wait
  NVIC_ST_CURRENT_R = 0;       // Something about any value is written to CURRENT clears
  
	while((NVIC_ST_CTRL_R&0x00010000)==0)
	{
	}
}

// This is my function to show that my systick is working
void SysTickWait(unsigned long delay)
{
	printf("We are going to turn on an LED for approximately 2 seconds\n\n");
	
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF); // This is me turning on my led to show you that my timer works
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);
  
  for(unsigned long i=0; i<delay; i++)
	{
    SysTick(800000);  // I am calling my Systick function so that I can delay
  }
	
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0); // This is me turning off my led to show you that my timer works
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);
}


