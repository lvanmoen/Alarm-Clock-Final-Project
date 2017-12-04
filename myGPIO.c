#include <stdio.h>
#include <stdint.h>
#include "myGPIO.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller


void setup_IO()
{
	int delay;
	
	// Enable the GPIO port that is used for the on-board LED.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		
		SYSCTL_RCGC2_R |= 0x00011111;     // 1) activate clock for Ports
    delay = SYSCTL_RCGC2_R;           // allow time for clock to start  
		
	//************************************************************************//
		GPIO_PORTA_CR_R = 0x3C;           // allow changes to PA2-5
	    GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog on PA
	    GPIO_PORTA_PCTL_R = 0x00FFFF00;   // 4) GPIO on PA2-5 && UART on P0-1
	    GPIO_PORTA_DIR_R = 0x3c;          // 5) PA2-5 output
	    GPIO_PORTA_AFSEL_R = 0x03;        // 6) disable alt funct on PF7-2 Leave UART
	    GPIO_PORTA_PUR_R = 0x00;          // Pull up not needed for output
	    GPIO_PORTA_DEN_R = 0x3c;          // 7) enable digital I/O on PF4-0
		
		//************************************************************************//
		GPIO_PORTB_CR_R = 0xFB;           // allow changes to PB 0,1,3,4,5,6,7
	    GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog on PB
	    GPIO_PORTB_PCTL_R = 0x00000000;   // 4) GPIO on PB
	    GPIO_PORTB_DIR_R = 0x3B;          // 5) PB 0,1,3,4,5 output  6,7 input
	    GPIO_PORTB_AFSEL_R = 0x00;        // 6) No AF
	    GPIO_PORTB_PUR_R = 0xC0;          // Pull up inputs on PB6,7
	    GPIO_PORTB_DEN_R = 0xFB;          // 7) enable digital I/O on Pb 0,1,4,5
		
		//************************************************************************//
		GPIO_PORTC_CR_R = 0xF0;           // allow changes to PC4,5,6,7
	    GPIO_PORTC_AMSEL_R = 0x00;        // 3) disable analog on PC
	    GPIO_PORTC_PCTL_R = 0xFFFF0000;   // 4) GPIO on PC4,5,6,7
	    GPIO_PORTC_DIR_R = 0xF0;          // 5) PC4,5,6,7 output
	    GPIO_PORTC_AFSEL_R = 0x00;        // 6) No AF
	    GPIO_PORTC_PUR_R = 0x00;          // Pull up not needed for output
	    GPIO_PORTC_DEN_R = 0xF0;          // 7) enable digital I/O on PC4,5,6,7
		
		//************************************************************************//
			GPIO_PORTD_LOCK_R = 0x4C4F434B;    // Unlock D7
			GPIO_PORTD_PCTL_R = 0xCF;         // allow changes to PD0,1,2,3,6,7
	    GPIO_PORTD_AMSEL_R = 0x00;        // 3) disable analog on PC
	    GPIO_PORTD_PCTL_R = 0xFF00FFFF;   // 4) GPIO on PD0,1,2,3,6,7
	    GPIO_PORTD_DIR_R = 0xCF;          // 5) PD0,1,2,3,6,7 output
	    GPIO_PORTD_AFSEL_R = 0x00;        // 6) No AF
	    GPIO_PORTD_PUR_R = 0x00;          // Pull up not needed for output
	    GPIO_PORTD_DEN_R = 0xCF;          // 7) enable digital I/O on PD0,1,2,3,6,7
		
		//************************************************************************//
		GPIO_PORTE_CR_R = 0x3E;           // allow changes to PE1,2,3,4,5
	    GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog on PC
	    GPIO_PORTE_PCTL_R = 0x00FFFFF0;   // 4) GPIO on PE1,2,3,4,5
	    GPIO_PORTE_DIR_R = 0x3E;          // 5) PE1,2,3,4,5 output
	    GPIO_PORTE_AFSEL_R = 0x00;        // 6) No AF
	    GPIO_PORTE_PUR_R = 0x00;          // Pull up not needed for output
	    GPIO_PORTE_DEN_R = 0x3E;          // 7) enable digital I/O on PE1,2,3,4,5
		
		//************************************************************************//
		GPIO_PORTF_LOCK_R = 0x4C4F434B;   // Unlock PF0  
		GPIO_PORTF_CR_R = 0x1F;           // Allow changes to PF4-0       
		GPIO_PORTF_AMSEL_R = 0x00;        // Disable analog function
		GPIO_PORTF_PCTL_R = 0x00000000;   // GPIO clear bit PCTL  
		GPIO_PORTF_DIR_R = 0x0E;          // PF4,PF0 input, PF3,PF2,PF1 output   
		GPIO_PORTF_AFSEL_R = 0x00;        // No alternate function
		GPIO_PORTF_PUR_R = 0x11;          // Pull up not needed for output       
		GPIO_PORTF_DEN_R = 0x1F;          // Enable digital pins PF4-PF0   
	

}


void pinReadAndWrite(void)
	{

	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);  // Set PB0 Low
	
	}

	