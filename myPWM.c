//Includes
#include "myPWM.h"

//Function that sets up the PWM
void setupPWM(void)
{
	//Set the clock to 16MHZ
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	
	//Configure PWM Clock to match system
  SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
	
	// Enable the peripherals used by this program.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);  //The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins
	
	//Wait for the PWM1 module to be ready.
	//
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM1))
	{
		
	}
	
	//Configure PF2 Pin as PWM
  GPIOPinConfigure(GPIO_PF2_M1PWM6);
	GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);
	
	//Configure PWM Options
	//PWM_GEN_3 Covers M1PWM6
	PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	
	//Set the Period (expressed in clock ticks)
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 320);
	
	//Set PWM duty-50% (Period/2)
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,100);
	
	// Enable the PWM generator
	PWMGenEnable(PWM1_BASE, PWM_GEN_3);
	
	// Turn on the Output pins
	PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, true);
}

//Simple delay function.
void delayMS(int ms) 
{
    SysCtlDelay((SysCtlClockGet()/(3*1000))*ms);
}

void AlarmBuzzGo(int alarmhours1, int alarmhours2, int alarmmins1, int alarmmins2)
{	
	//Fade
  bool fadeUp = true;
  unsigned long increment = 10; //Long increment
  unsigned long pwmNow = 100;	//new PWM value
	int i = 1; //Int used in while loop
	int SWOFF;  //Int that contains the output of the button SW2
	int SWSNOOZE;  //Int that contains the output of the button SW1
	volatile int flashTime = 10; //Long that controls the speed of the flashing
	
	
  while(i == 1)
  {	
		SWSNOOZE = GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_7);  // Set SWSNOOZE eual to the output of the button hooked up to PB7
		SWOFF = GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_6); 		// Set SWOFF equal to the output of the button hooked up to PB6
		
		
		delayMS(20); //delay
		 
    if (fadeUp) //check if fadeUp is true
		{
			pwmNow += increment; //add the value of increment to pwmNow
      if (pwmNow >= 320) 
			{ 
				fadeUp = false; 
			}
    }
    else 
		{
			pwmNow -= increment; //subtract the value of increment to pwmNow
      if (pwmNow <= flashTime) 
			{ 
				fadeUp = true;
			}
    }        
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,pwmNow);  //Set the pulse width to the new value, pwmNow.      
    }	
		
			 if (SWOFF == 0)
			 {
					i = 0;
				 PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, false); //Disable ports for PWM so ports can be used for other modules.
				 GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); // Re-enable pin 2 on portf for GPIO usage on other modules.
			 }

			 // yes my snooze is only for a minute get over it. 
			 // you are going to be late to work if you keep snoozing the damn alarm
			 if (SWSNOOZE == 0)
			 {
					i = 0;
				 
				alarmmins2=alarmmins2+1;
				 
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
				}
				
				 PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, false); //Disable ports for PWM so ports can be used for other modules.
				 GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); // Re-enable pin 2 on portf for GPIO usage on other modules.
			 }

}
