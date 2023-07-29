/*
 * DIO.h
 *
 * Created: 9/27/2021 3:55:27 PM
 *  Author: MSI
 */ 


#ifndef DIO_H_
#define DIO_H_
void DIO_SET_DIR(unsigned char port,unsigned char bit,unsigned char val );
void DIO_WRITE(unsigned char port,unsigned char bit,unsigned val);
void DIO_TOG(unsigned char port,unsigned char bit);
unsigned char DIO_READ(unsigned char port,unsigned char bit);
void DIO_SET_PORT_DIR(unsigned char port,unsigned char val );
void DIO_PORT_WRITE(unsigned char port,unsigned val);
void DIO_PORT_TOG(unsigned char port);
unsigned char DIO_PORT_READ(unsigned char port);
void DIO_connect_pull_up(unsigned char port,unsigned char pin,unsigned char connection);
void write_low_nibble(unsigned char port,unsigned char number);
void write_high_nibble(unsigned char port,unsigned char number);




#endif /* DIO_H_ */