/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Apr, 12, 2023           */
/*          Version: 1.0                  */
/*          Module: Elements              */
/*          File: Elements.c              */
/********************* ********************/


#include "Cool_Heat_Elements.h"

void heat_init(void){
	SET_BIT(HEAT_PORT_DIR,HEAT_PIN);
}

void cool_init(void){
	SET_BIT(COOL_PORT_DIR,COOL_PIN);
}

void heat_start(void){
	SET_BIT(HEAT_PORT,HEAT_PIN);
}

void cool_start(void){
	SET_BIT(COOL_PORT,COOL_PIN);
}


void heat_stop(void){
	CLEAR_BIT(HEAT_PORT,HEAT_PIN);
}

void cool_stop(void){
	CLEAR_BIT(COOL_PORT,COOL_PIN);
}