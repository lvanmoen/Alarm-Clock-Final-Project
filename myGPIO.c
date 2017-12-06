#include <stdio.h>
#include <stdint.h>
#include "myGPIO.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller


void setup_IO()
{
	
			// Enable the GPIO port that is used for the on-board LED.
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
			volatile unsigned long delay;
		
			SYSCTL_RCGC2_R |= 0x3f;    				// 1) activate clock for Ports
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
	
		//I have to do this so that we don't start off with a bunch of random stuff going on our seven segment displays
		//hours1 all off
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0xF);  // Set PB0 High
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0xF);  // Set PB1 High
			
		//hours2 all off
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0xf);  // Set PA3 High
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0xf);  // Set PA4 High
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0xf);  // Set PA5 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0xf);  // Set PE1 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0xf);  // Set PE2 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0xf);  // Set PE4 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0xf);  // Set PE5 High
		
		//min1 all off
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0xf);  // Set PC5 High
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0xf);  // Set PC6 High
		GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0xf);  // Set PE3 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0xf);  // Set PD6 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0xf);  // Set PD7 High
	  GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0xf);  // Set PC4 High
		GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0xf);  // Set PC7 High
		
		//min2 all off
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0xf);  // Set PD0 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0xf);  // Set PD1 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_2, 0xf);  // Set PD2 High
		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0xf);  // Set PD3 High
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0xf);  // Set PB4 High
		GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0xf);  // Set PA2 High
		GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0xf);  // Set PB5 High
			
			
	
}

void pmindicatoroff(void)
{
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);	 // Turn on red LED
}

void pmindicatoron(void)
{
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);	 // Turn on red LED
}

void CheckStatus(int hours1, int hours2, int minutes2, int minutes1, int alarmhours1, int alarmhours2, int alarmmins1, int alarmmins2, int alarmspm)
{
		int SW1;  
		int SW2;  
	
		printf("You can change some stuff by pressing switches 1 and 2\n Press switch 2 to turn");
		printf("on a purple LED \n Press switch 1 to turn on green LED \n Press both to turn off the LEDs and exit GPIO\n\n");	
	
		SW1 = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4); // set x equal to the output of button SW1
		SW2 = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0); // set x equal to the output of button SW2
		 
			if (SW2 == 1){ 	// When my SW2 isn't pressed I don't want anything to happen
				}
			if( SW1==1){		// When my SW1 isn't pressed I don't want anything to happen
				}
		
		//If SW2 is pressed I want it to increase the hours by 1 every time it's pressed. 
		if (SW2 == 0) // If SW2 is pressed a purple light comes on
			{
					hours2 = hours2+1;
      }
				
		//If SW1 is pressed I want the minutes to increase by one
		if (SW1==0) 
				{ 	
				minutes2 = minutes2+1;	
        }
		
				
				
		// If both SW1 and SW2 are pressed I want to enter alarm clock mode
		// A L A R M    
		// M O D E
		if( SW2 == 0 &&  SW1 ==0) 
			{ 
				printf("YOU ARE IN ALARM MODE. PRESS BOTH SW1 AND SW2 TO EXIT");

				int i=1;
				while(i==1)
					{
						printhours1(alarmhours1);
						printhours2(alarmhours2);
						printmin1(alarmmins1);
						printmin2(alarmmins2);
						
							if (alarmmins2>9){
									alarmmins2=0;
									alarmmins1++;
									}
							if (alarmmins1 > 5){
									alarmmins1=0;
									alarmhours2++;
									}
							if (alarmhours2 >9){
									alarmhours2=0;
									alarmhours1++;
									}
							if (alarmhours1 == 1 && alarmhours2 == 3){
									alarmmins1=0;
									alarmmins2=0;
									alarmhours2=1;
									alarmhours1=0;
								
									alarmspm = alarmspm||1;
									if(alarmspm==1){
										pmindicatoron();
									}
									if(alarmspm ==0){
										pmindicatoroff();
									}	
								}
		 
				if (SW2 == 1)
						{ 	// When my SW2 isn't pressed I don't want anything to happen
						}
				if( SW1==1)
						{		// When my SW1 isn't pressed I don't want anything to happen
						}
		
				//If SW2 is pressed I want it to increase the hours by 1 every time it's pressed. 
				if (SW2 == 0) 
						{
						alarmhours2 = hours2+1;
						}
				
				//If SW1 is pressed
				if (SW1==0) 
					{ 
						alarmmins2 = minutes2+1;	
					}

					
				if( SW2 == 0 &&  SW1 ==0) 
					{ 
						printf("You are now exiting Alarm Mode");
						i=0;
					}				
			}
	
}
}

