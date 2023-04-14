/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Apr, 12, 2023           */
/*          Version: 1.0                  */
/*          Module: LED                   */
/*          File: LED.h                   */
/********************* ********************/


#ifndef LED_H_
#define LED_H_


#include <avr/io.h>
#include "STD_Types.h"
#include "BIT_Status.h"

#define LED_PORT_DIR      DDRB
#define LED_PORT          PORTB
#define LED_PIN           0

void led_init(void);
void led_on(void);
void led_off(void);


#endif /* LED_H_ */