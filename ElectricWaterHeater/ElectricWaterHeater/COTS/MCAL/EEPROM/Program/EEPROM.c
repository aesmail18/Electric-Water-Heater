/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 25, 2022           */
/*          Version: 1.0                  */
/*          Module: EEPROM                */
/*          File: EEPROM.c                */
/********************* ********************/
#include "EEPROM.h"

u8 EEPROM_read(const unsigned short addr){
	// Setup Address Register
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	// Start Reading
	SET_BIT(EECR,EERE);
	
	// Return Data
	return EEDR;
}

void EEPROM_write(const unsigned short addr, unsigned char data){
	u8 INT_EN=0;
		
	// Setup Address Register
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	// Put Data in Data Register
	EEDR = data;
	
	// Disable Interrupts to work fine
	if(((SREG&(1<<7))>>7)==1){
		INT_EN = 1;
		CLEAR_BIT(SREG,7);
	}
	
	// Start Writing
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	
	// Back
	if (INT_EN==1)
	{
		SET_BIT(SREG,7);
	}
	
}