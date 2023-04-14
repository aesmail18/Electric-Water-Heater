/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 16, 2022           */
/*          Version: 1.0                  */
/*          Module: ADC                   */
/*          File: ADC.c                   */
/********************* ********************/

#include "ADC.h"

void ADC_init(){
	
	// Choosing reference voltage option.
	// the AVCC pin with a capacitor at the AREF pin.
	SET_BIT(ADMUX,REFS0);
	
	// Choosing Channel One (Single Ended In.) at A0 pin.
	CLEAR_BIT(ADMUX,MUX0);
	CLEAR_BIT(ADMUX,MUX1);
	CLEAR_BIT(ADMUX,MUX2);
	CLEAR_BIT(ADMUX,MUX3);
	CLEAR_BIT(ADMUX,MUX4);
	
	// Choosing the Data to be Right Adjusted in the Data Reg.
	CLEAR_BIT(ADMUX,ADLAR);
	
	// Choosing Prescaler for the ADC clock.
	// the following is choosing (2) as a Prescaler.
	SET_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
	
	// Enable the ADC
	SET_BIT(ADCSRA,ADEN);
	
}

u16 ADC_read(){
	
	u16 data;
	
	// Start Conversion
	SET_BIT(ADCSRA,ADSC);
	
	// Wait for flag to be set.
	// Indication of finished conversion
	while(is_bit_clr(ADCSRA,ADIF));
	
	// Read Data from the ADC Data Register
	// Read the Low register first!
	data = ADCL;
	data |= (ADCH<<8);
	
	// Clear Flag (As we are not using the interrupt)
	// It won't be cleared automatically!
	SET_BIT(ADCSRA,ADIF);
	
	return data;	
}