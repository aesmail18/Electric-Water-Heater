/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Apr, 13, 2023           */
/*          Version: 1.0                  */
/*          Module: App                   */
/*          File: App.h                   */
/********************* ********************/

#ifndef SYS_H_
#define SYS_H_


// Description
/*
The system is using a modified cooperative scheduler. it has
only one task (ON_TASK) which executes the functionality of
the normally working WATER HEATER. the ON_TASK is also checking
if buttons are pressed so it can switch to the SETTING_MODE, 
which is another function (state) to allow the user to change
the set point - or the desired temperature.
*/

// when Reading the ADC, the value is halved due to some issues
// to the Temperature sensor in Proteus LM35. So, please, configure
// it depending on your sensor.

// Including All Peripherals
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Sys_Config.h"
#include "STD_Types.h"
#include "BIT_Status.h"
#include "ADC.h"
#include "Buttons.h"
#include "Cool_Heat_Elements.h"
#include "LED.h"
#include "SSD_disp.h"
#include "Timer.h"
#include "EEPROM.h"

#define OFF 0
#define ON 1
#define SETTING 2

/**************************************** 
*               Functions               *
****************************************/

void sys_init(void);
void ON_state(void);
void OFF_state(void);
void SET_state(void);

void change_temp(void);
void add_new_temp(u16 * arr , u16 new_val);
u16 calc_avg_temp(u16 * arr);
void temp_arr_init(void);
void go_to_sleep(void);

/****************************************
*               Variables               *
****************************************/

// will add as needed

u8 Curr_state;

u16 temp_arr[NUM_OF_TEMP_MEASURES];
u16 desired_temp;
u16 actual_temp;
u16 avg_temp;

u8 temp_measure_f;
u8 temp_measure_counter;
u8 setting_counter;

u16 toggle_f;
u16 arr_counter;

#endif /* SYS_H_ */