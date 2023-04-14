/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Apr, 12, 2023           */
/*          Version: 1.0                  */
/*          Module: LED                   */
/*          File: LED.c                   */
/********************* ********************/


#include "LED.h"

void led_init(void){
	
	// PIN 0 in the port is an output pin
	// the LED pin is initially off
	
	SET_BIT(LED_PORT_DIR,LED_PIN);
	CLEAR_BIT(LED_PORT,LED_PIN);

}

void led_on(void){
	SET_BIT(LED_PORT,LED_PIN);
}

void led_off(void){
	CLEAR_BIT(LED_PORT,LED_PIN);
}
