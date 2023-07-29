/*
 * E2PROM.h
 *
 * Created: 10/14/2021 1:30:49 PM
 *  Author: MSI
 */ 


#ifndef E2PROM_H_
#define E2PROM_H_
void EEPROM_write(unsigned short address,unsigned char data);
unsigned char EEPROM_read(unsigned short address);



#endif /* E2PROM_H_ */