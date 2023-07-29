/*
 * EEPROM.c
 *
 * Created: 10/14/2021 1:29:06 PM
 *  Author: MSI
 */ 


#include <avr/io.h>
#include "E2PROM.h"
#include "LED.h"
int main(void)
{
	LED_init('A',0);
	EEPROM_write(0x0030,0x50);
	if(EEPROM_read(0x0030)==0x50)
	{
		LED_TURN_ON('A',0);
	}
	else
	{
		LED_TURN_OFF('A',0);
	}			
    while(1)
    {
        //TODO:: Please write your application code 
    }
}