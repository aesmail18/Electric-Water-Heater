/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Apr, 12, 2023           */
/*          Version: 1.0                  */
/*          Module: SSD                   */
/*          File: SSD.h                   */
/********************* ********************/

#ifndef SSD_H_
#define SSD_H_


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_Status.h"

	
// SSD Display Macros
#define DISP1                    1
#define DISP2                    2

#define SSD_ENABLE_PORT_DIR      DDRB
#define SSD_ENABLE_PORT          PORTB
#define SSD1_ENABLE_PIN          6 
#define SSD2_ENABLE_PIN          7
#define SSD_DATA                 PORTD
#define SSD_PORT_DIR             DDRD

// SSD Control Functions
void SSD_init(void);
void SSD_send(u16 N);
void SSD_enable(u8 disp);
void SSD_disable(void);
void SSD_turn_off(void);
void SSD_write(u16 N);


#endif /* SSD_H_ */