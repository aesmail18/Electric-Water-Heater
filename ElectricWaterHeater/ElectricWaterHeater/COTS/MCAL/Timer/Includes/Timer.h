/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 16, 2022           */
/*          Version: 2.0                  */
/*          Module: Timer                 */
/*          File: Timer.h                 */
/********************* ********************/


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_Types.h"
#include "BIT_Status.h"

void timer1_init();
void timer0_init();
void timer1_INT_disable();
void timer1_INT_enable();

#endif /* TIMER_H_ */