//*******************************************************************************************
//* Name: Lidia Van Moen and Lauryn Jeffrey                            
//* Date: 10/06/2017
//*	Class: Embedded Systems Lab
//* Prof: Chase
//* Lab Description: This is my Analog to Digital converter. Most of this wasn't taken directly
//*                  from the professor's Git Hub. So, a lot of it is like, magic to me. But
//*									 basically. I am using the code that he has a established, and I made it so
//*                  that I can read in the voltage that is going to PE3. When you enter my function
//*									 I print the value that is on the port. I had to do a conversion, so that it would
//*									 display voltage and that is in my function below.
//*Hardware Description: TIVA C Series LaunchPad. TMC123G micro
//*******************************************************************************************

#include "HAL_ADC.h"

uint32_t ADC_Values[13];
void SetupADCPins(void);

// set up for 2 ports and accelerometer + 1 extra
void SetupADCPins()
{
	HWREG(GPIO_PORTE_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;		//Need to Unlock PD7
	HWREG(GPIO_PORTE_BASE + GPIO_O_CR) = 0xFF;
  HWREG(GPIO_PORTE_BASE + GPIO_O_LOCK) = 0;
	GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_3|GPIO_PIN_1|GPIO_PIN_2);
	
}

void SetupADC()
{
	
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE))
	{
	}
	
	// Enable the ADC0 module.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

	// Wait for the ADC0 module to be ready.
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
	{
		// wait here for a hot second
	}
	
	ADCReferenceSet(ADC0_BASE, ADC_REF_EXT_3V);
	
	// Enable the first sample sequencer to capture the value of channel 0 when
	// the processor trigger occurs.
	ADCSequenceDisable(ADC0_BASE,0);
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0 );
  ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH1 );	
  ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_CH2 );	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 3, ADC_CTL_CH4 );	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 4, ADC_CTL_CH5 );	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 5, ADC_CTL_CH6 );	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 6, ADC_CTL_CH7 | ADC_CTL_END);	
		
	ADCSequenceEnable(ADC0_BASE, 0);

	SetupADCPins(); //setup the GPIO
		
}

void ADCfunction()
{
	int32_t scratch;
	// Trigger the sample sequence.
	ADCProcessorTrigger(ADC0_BASE, 0);

	while(ADCBusy(ADC0_BASE)){};
	{
		// wait here for a hot second
	}
	
	// Read the value from the ADC.
	// This is going to read in E3, so if you change the offset you can read in different pins 
	scratch = (ADCSequenceDataGet(ADC0_BASE, 0, ADC_Values));
	if (scratch < 13)
	{
		ADC_Values[12]=scratch;
	}
		 
	double conv;
		
		
		conv = ADC_Values[0];
		// I am converting the 4096 value I get so that it read 3.3 Volts when 
		// full power goes to the port
		conv = conv * 0.000805664;
		
		printf("\n The voltage value in port E pin 3 is currently: %.2f \n", conv);

	
}
