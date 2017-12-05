#include "project.h"
#include <stdio.h>
#include <stdint.h>

#ifdef DEBUG

void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

//Function Protoypes
void mainMenu(char ctemp,uint8_t temp,uint32_t ui32Loop);  //Main menu that displays to the UART terminal for a HMI
void SetupHardware(void);  //Function that sets up all of the pins,ports, etc... that are used in the program

//Main Code
int  main(void)
{		
	//Variables
	char ctemp; //Temp char used for UART
	uint8_t temp;	//Temp 8-bit int used for gpio functions
	volatile uint32_t ui32Loop; //32-bit int used for multiple functions 
	
	SetupHardware();

	int hour1 =0;
	int hour2 =1;
	int min1=0;
	int min2=0;

	int alarmhour1;
	int alarmhour2;
	int alarmmin1;
	int alarmmin2;
	
	int pm=0;
	int alarmpm=0;
	int i;
	
		while (1)
			{
				printf("The time is %d %d : %d %d\n\n",hour1,hour2,min1,min2);
	
				// I am calling the functions that will set the seven segment displays to the correct 
				// outputs so it looks like we have a clock. 
				printhours1(hour1);
				printhours2(hour2);
				printmin1(min1);
				printmin2(min2);
	
				CheckStatus(hour1, hour2, min2, min1, alarmhour1, alarmhour2, alarmmin1, alarmmin2,alarmpm);

				// This is the main clock function, so basically, this is the
				// part of the code that is keeping track of the time. 
				min2 = min2+1;
				SysTickWait10msDN(1200);
					
				if (min2>9){
					min2=0;
					min1++;
					}
				if (min1 > 5){
					min1=0;
					hour2++;
					}
				if (hour2 >9){
					hour2=0;
					hour1++;
					}
				if (hour1 == 1 && hour2 == 3){
					min1=0;
					min2=0;
					hour2=1;
					hour1=0;
					
					pm = pm||0;
					if(pm==1){
						pmindicatoron();
					}
					if(pm==0){
						pmindicatoroff();
					}	
					}
				
				if(hour1==alarmhour1 && hour2 == alarmhour2 && min1==alarmmin1 && alarmmin2==min2 && alarmpm == pm)
					{
						AlarmBuzzGo(alarmhour1, alarmhour2, alarmmin1, alarmmin2);
					}
		
		
					
		}
}

void SetupHardware(void)  
{
	UartSetup();	//Sets up Uart communication using RealTerm
	setup_IO();		//Function that unlocks certain pins that are needed.
	SetupSystickDN();	//Sets up the timers and hardware to use systick
	setupPWM();
	
}





