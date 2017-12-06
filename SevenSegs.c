#include <stdio.h>
#include <stdint.h>
#include "myGPIO.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller
#include "SevenSegs.h"


void printhours1(int ctemp1)
{
	switch(ctemp1){
		
	case '1':
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0x0);  // Set PB0 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0x0);  // Set PB1 Low
		break;
		
	default:
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0xF);  // Set PB0 High
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0xF);  // Set PB1 High
		break;
	
	
	}
}

void printhours2(int ctemp2)
{
	switch(ctemp2){
		case '0':
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0x0);  // Set PE4 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
		
		//set it high
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0xf);  // Set PE1 Low
		break;	
		
	case '1':
		// Turning them on
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
	
		// Turning the others off
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0xF);  // Set PA3 High
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0xF);  // Set PA4 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0xF);  // Set PE1 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0xF);  // Set PE4 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0xF);  // Set PE5 High
		break;
	
	case '2':
		// Turning them on
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0x0);  // Set PE4 Low
	
		// Turning them off
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0xF);  // Set PA3 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0xF);  // Set PE2 High

		break;

	case '3':
		// Turning them on
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0xf);  // Set PA3 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0xf);  // Set PE4 High
		break;
	
	case '4':
		//Turning them on
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0xf);  // Set PA4 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0xf);  // Set PE4 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0xf);  // Set PE5 High
		break;
	
	case '5':
		//Turning them on
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0xf);  // Set PA5 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0xf);  // Set PE4 High	
		break;

	case '6':
		//Turning them On
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0x0);  // Set PE4 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
	
		//Turning them Off
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0xf);  // Set PA3 High
	
		break;

	case '7':
		//Turning them ON
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0xf);  // Set PA3 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0xf);  // Set PE1 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0xf);  // Set PE4 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0xf);  // Set PE5 High
		break;

	case '8':
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0x0);  // Set PE4 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
		break;	
	
	case '9':
		//Turning them On
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0xf);  // Set PE4 High
		break;
		
	}
}

void printmin1(int ctemp3)
{
	switch(ctemp3){
	
	case '0':
		//Turning them on
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0x0);  // Set PC4 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0x0);  // Set PC5 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0x0);  // Set PE3 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0x0);  // Set PD7 Low
	
	 //Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0xf);  // Set PD6 High
		break;	
	
	case '1':
		//Turning them on
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0xf);  // Set PC4 High
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0xf);  // Set PC5 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0xf);  // Set PE3 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0xf);  // Set PD7 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0xf);  // Set PD6 High
		break;
	
	case '2':
		//Turning them on
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0x0);  // Set PC4 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0x0);  // Set PC5 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0x0);  // Set PE3 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0x0);  // Set PD6 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0xf);  // Set PC6 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0xf);  // Set PD7 High

		break;

	case '3':
		//Turning them on
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0x0);  // Set PC5 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0x0);  // Set PE3 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0x0);  // Set PD6 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0xf);  // Set PC4 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0xf);  // Set PD7 High
	
		break;
	
	case '4':
		//Turning them on
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0x0);  // Set PD6 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0x0);  // Set PD7 Low
	
		//Turning them Off
	  GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0xf);  // Set PC4 High
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0xf);  // Set PC5 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0xf);  // Set PE3 High

		break;
	
	case '5':
		//Turning them on 
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0x0);  // Set PC5 Low
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0x0);  // Set PE3 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0x0);  // Set PD6 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0x0);  // Set PD7 Low
	
		//Turning them off
	  GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0xf);  // Set PC4 High
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0xf);  // Set PC7 High
	
		break;


}

}


void printmin2(int ctemp4)
{
	switch(ctemp4){
	
	case '0':
		//Turning them on
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);  // Set PD0 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0xf);  // Set PD2 Low
	
		break;	

	case '1':
		//Turning them on
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0xf);  // Set PD0 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0xf);  // Set PD1 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0xf);  // Set PD2 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0xf);  // Set PB4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0xf);  // Set PA2 Low
	
		break;
	
	case '2':
		//Turning them on 
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);  // Set PD0 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0xf);  // Set PD2 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0xf);  // Set PB5 Low
	
		break;

	case '3':
		//Turning them on 
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0xf);  // Set PD0 High
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0xf);  // Set PB5 High
		break;
	
	case '4':
		//Turning them on 
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0xf);  // Set PD0 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0xf);  // Set PD1 High
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0xf);  // Set PA2 High

	
		break;
	
	case '5':
		//Turning them on 
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0xf);  // Set PD0 High
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0xf);  // Set PB4 High
	
		break;

	case '6':
		//Turning them on
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);  // Set PD0 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0xf);  // Set PB4 High
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0xf);  // Set PB5 High
	
		break;

	case '7':
		//Turning them on
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0xf);  // Set PD0 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0xf);  // Set PD1 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0xf);  // Set PD2 High
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0xf);  // Set PB5 High
	
		break;

	case '8':
		//Turning them on
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);  // Set PD0 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
	
	
		break;	
	
	case '9':
		//Turning them on
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
	
		//Turning them off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0xf);  // Set PD0 High
	
		break;

}
	}
