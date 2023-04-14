/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 25, 2022           */
/*          Version: 1.0                  */
/*          Module: EEPROM                */
/*          File: EEPROM.h                */
/********************* ********************/


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "STD_Types.h"
#include "BIT_Status.h"

void EEPROM_write(const unsigned short addr, unsigned char data);
u8 EEPROM_read(const unsigned short addr);

#endif /* EEPROM_H_ */