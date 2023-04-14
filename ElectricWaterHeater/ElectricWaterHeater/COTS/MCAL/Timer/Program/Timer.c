/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 16, 2022           */
/*          Version: 2.0                  */
/*          Module: Timer                 */
/*          File: Timer.c                 */
/********************* ********************/


#include "Timer.h"


/*
timer1_init() : to initialize timer(1) to measure time between tasks every 1ms.
*/

void timer1_init(){
	
	// we are working with AVR ATmega32 chip with a frequency of 1 MHz
	// It triggers an interrupt every One millisecond
	
	
	// Select CTC Mode
	SET_BIT(TCCR1B,WGM12);
	
	
	// Load Value in OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	/*
	// Load Value in OCR1B
	OCR1BH = 0b00000011;
	OCR1BL = 0b11010001;
	*/
	// Select Clock Prescaler (F_CPU / 1024)
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	
	// Enable Global Interrupt bit
	sei();

}

void timer0_init(){
	
	// choose mode
	SET_BIT(TCCR0,WGM01);
	
	// Load Value in OCR0
	OCR0 = 250;
	
	// Choose Prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// Enable Timer INT
	sei();
	SET_BIT(TIMSK,OCIE0);
	
}

void timer1_INT_disable(){
	
	// Disable Interrupts when Comparing with values A and B
	CLEAR_BIT(TIMSK,OCIE1A);
	
}


void timer1_INT_enable(){
	
	// Enable Interrupts when Comparing with values A and B
	SET_BIT(TIMSK,OCIE1A);
	
}