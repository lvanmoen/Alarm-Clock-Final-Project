//#include <stdio.h>
//#include <stdint.h>
//#include "myGPIO.h"
//#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller


//void printhours1(int ctemp1)
//{
//	switch(ctemp1){
//		
//	case '1':
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0x0);  // Set PB0 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0x0);  // Set PB1 Low
//		break;
//		
//	default:
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0xF);  // Set PB0 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0xF);  // Set PB1 Low
//		break;
//	
//	
//	}
//}

//void printhours2(int ctemp2)
//{
//	switch(ctemp2){
//		
//	case '1':
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
//		break;
//	
//	case '2':
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0x0);  // Set PE4 Low
//		break;

//	case '3':
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
//		break;
//	
//	case '4':
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
//		break;
//	
//	case '5':
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
//		break;

//	case '6':
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0x0);  // Set PE4 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
//		break;

//	case '7':
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
//		break;

//	case '8':
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0x0);  // Set PE4 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
//		break;	
//	
//	case '9':
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0x0);  // Set PA3 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0x0);  // Set PA4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0x0);  // Set PA5 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0x0);  // Set PE1 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0x0);  // Set PE2 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0x0);  // Set PE5 Low
//		break;
//		
//	}
//}

//void printmin1(int ctemp3)
//{
//	switch(ctempt3){
//	
//	case '0':
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0x0);  // Set PC4 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0x0);  // Set PC5 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0x0);  // Set PE3 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0x0);  // Set PD7 Low

//		break;	
//	
//	case '1':
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
//		break;
//	
//	case '2':
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0x0);  // Set PC4 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0x0);  // Set PC5 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0x0);  // Set PE3 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0x0);  // Set PD6 Low
//		break;

//	case '3':
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0x0);  // Set PC5 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0x0);  // Set PE3 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0x0);  // Set PD6 Low
//		break;
//	
//	case '4':
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x0);  // Set PC7 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0x0);  // Set PD6 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0x0);  // Set PD7 Low
//		break;
//	
//	case '5':
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0x0);  // Set PC5 Low
//		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x0);  // Set PC6 Low
//		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0x0);  // Set PE3 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0x0);  // Set PD6 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0x0);  // Set PD7 Low
//		break;


//}

//}


//void printmin2(int ctemp4)
//{
//	switch(ctemp4){
//	
//	case '0':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);  // Set PD0 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
//		break;	

//	case '1':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
//		break;
//	
//	case '2':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);  // Set PD0 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
//		break;

//	case '3':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
//		break;
//	
//	case '4':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
//		break;
//	
//	case '5':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
//		break;

//	case '6':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);  // Set PD0 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
//		break;

//	case '7':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
//		break;

//	case '8':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x0);  // Set PD0 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
//		break;	
//	
//	case '9':
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x0);  // Set PD1 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0x0);  // Set PD2 Low
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0x0);  // Set PD3 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0x0);  // Set PB4 Low
//		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0x0);  // Set PA2 Low
//		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0x0);  // Set PB5 Low
//		break;

//}
//	}
