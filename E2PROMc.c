/*
 * E2PROMc.c
 *
 * Created: 10/14/2021 1:30:17 PM
 *  Author: MSI
 */ 
#include <avr/io.h>
#include "STD_macros.h"
void EEPROM_write(unsigned short address,unsigned char data)
{
	EEAR=address;
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	
	while(READ_BIT(EECR,EEWE)==1);
	
}
unsigned char EEPROM_read(unsigned short address)
{
	EEAR=address;
	SET_BIT(EECR,EERE);
	return EEDR;
}