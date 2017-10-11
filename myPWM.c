//*****************************************************************************************************
//* Name: Lidia Van Moen and Lauryn Jeffrey                            
//* Date: 10/06/2017
//*	Class: Embedded Systems Lab
//* Prof: Chase
//* Lab Description: This is my PWM portion of code. This basically turns all the LED pins of F
//*                  so that they are now PWM outputs. And then I fade the lights up and down. So that
//*									 it is all white. Then for my funciton I put it in a loop for 250 counts so 
//*                  that the user can verify that this function works. Then I exit this loop.
//*									 And then I have to set up my IO so that my other functions will work 
//*									 Because if I don't they won't (I found this out the hard way)
//*Hardware Description: TIVA C Series LaunchPad. TMC123G micro
//******************************************************************************************************


#include <stdio.h>
#include <stdint.h>
#include "myPWM.h"
#include "driverlib/pin_map.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "myGPIO.h"

void delayMS(int ms) {
    SysCtlDelay( (SysCtlClockGet()/(3*1000))*ms ) ;
}


void PulseWidthModulation(){
	
	  //Set the clock
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    //Configure PWM Clock to match system
    SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

    // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);  //The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins

    //Configure PF1,PF2,PF3 Pins as PWM
    GPIOPinConfigure(GPIO_PF1_M1PWM5);
    GPIOPinConfigure(GPIO_PF2_M1PWM6);
    GPIOPinConfigure(GPIO_PF3_M1PWM7);
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

    //Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 
    PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //Set the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, 320);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 320);

    //Set PWM duty-50% (Period /2)
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,100);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,100);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,100);

    // Enable the PWM generator
    PWMGenEnable(PWM1_BASE, PWM_GEN_2);
    PWMGenEnable(PWM1_BASE, PWM_GEN_3);

    // Turn on the Output pins
    PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, true);

    //Fade
		int fadeUp = 1;
    int increment = 10;
    int pwmNow = 100;
    
		for(int x = 0; x<300; x++)
    {
        delayMS(20);
        if (fadeUp) {
            pwmNow += increment;
            if (pwmNow >= 320) 
							{ 
							fadeUp = 0; 
							}
        }
        else {
            pwmNow -= increment;
            if (pwmNow <= 10) 
							{ 
								fadeUp = 1; 
							}
        }
				
				// This will turn my LEDs on, which will create the pulsing visual
        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,pwmNow);
        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,pwmNow);
        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,pwmNow);
    }
		
		setup_IO();		   														    // This makes it so I can go back to how my GPIO were set up after exiing this function
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0); // I want to turn off the LEDS off when I leave this function
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
}
