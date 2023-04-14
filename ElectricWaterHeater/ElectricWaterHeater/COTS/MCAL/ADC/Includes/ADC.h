/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 16, 2022           */
/*          Version: 1.0                  */
/*          Module: ADC                   */
/*          File: ADC.h                   */
/********************* ********************/

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include "STD_Types.h"
#include "BIT_Status.h"

void ADC_init(void);
u16 ADC_read(void);


#endif /* ADC_H_ */