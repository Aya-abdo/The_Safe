/*
 * DIO.c
 *
 * Created: 9/27/2021 6:16:05 PM
 *  Author: MSI
 */ 
#include <avr/io.h>

#include "STD_macros.h"
void DIO_SET_DIR(unsigned char port,unsigned char bit,unsigned char val )
{
	switch(port){
		case 'A':
		case 'a':
		if(val==1){
		SET_BIT(DDRA,bit);
		}
		else{
			CLR_BIT(DDRA,bit);
		}
		break;
		case 'B':
		case 'b':
		if(val==1){
			SET_BIT(DDRB,bit);
		}
		else{
			CLR_BIT(DDRB,bit);
		}
		break;
		case 'C':
		case 'c':
		if(val==1){
			SET_BIT(DDRC,bit);
		}
		else{
			CLR_BIT(DDRC,bit);
		}
		break;
		case 'D':
		case 'd':
		if(val==1){
			SET_BIT(DDRD,bit);
		}
		else{
			CLR_BIT(DDRD,bit);
		}
		break;
		default:
		break;
				
		
	}
}
void DIO_WRITE(unsigned char port,unsigned char bit,unsigned val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(val==1){
			SET_BIT(PORTA,bit);
		}
		else{
			CLR_BIT(PORTA,bit);
		}
		break;
		case 'B':
		case 'b':
		if(val==1){
			SET_BIT(PORTB,bit);
			}
		else{
			CLR_BIT(PORTB,bit);
			}
			break;
			case 'C':
			case 'c':
			if(val==1){
				SET_BIT(PORTC,bit);
			}
			else{
				CLR_BIT(PORTC,bit);
			}
			break;
			case 'D':
			case 'd':
			if(val==1){
				SET_BIT(PORTD,bit);
			}
			else{
				CLR_BIT(PORTD,bit);
			}
			break;
			default:
			break;
	}
}
void DIO_TOG(unsigned char port,unsigned char bit)
{
	switch(port)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,bit);
		break;
		case 'B':
		case 'b':
		TOG_BIT(PORTB,bit);
		break;
		case 'C':
		case 'c':
		TOG_BIT(PORTC,bit);
		break;
		case 'D':
		case 'd':
		TOG_BIT(PORTD,bit);
		break;
		default:
		break;
		
	}
}
unsigned char DIO_READ(unsigned char port,unsigned char bit)
{
	unsigned char value;
	switch(port)
	{
		case 'A':
		case 'a':
		value=READ_BIT(PINA,bit);
		break;
		case 'B':
		case 'b':
		value=READ_BIT(PINB,bit);
		break;
		case 'C':
		case 'c':
		value=READ_BIT(PINC,bit);
		break;
		case 'D':
		case 'd':
		value=READ_BIT(PIND,bit);
		break;
		default:
		break;
		
		
		
		
		
		
	}
	return value;
}
void DIO_SET_PORT_DIR(unsigned char port,unsigned char val )
{
		switch(port){
			case 'A':
			case 'a':
			DDRA=val;
			break;
			case 'B':
			case 'b':
			DDRB=val;
			break;
			case 'C':
			case 'c':
			DDRC=val;
		
			break;
			case 'D':
			case 'd':
		    DDRD=val;
			break;
			default:
			break;
			
			
		}
}
void DIO_PORT_WRITE(unsigned char port,unsigned val)
{
		switch(port){
			case 'A':
			case 'a':
			PORTA=val;
			break;
			case 'B':
			case 'b':
			PORTB=val;
			break;
			case 'C':
			case 'c':
			PORTC=val;
			
			break;
			case 'D':
			case 'd':
			PORTD=val;
			break;
			default:
			break;
			
			
		}
	

}
void DIO_PORT_TOG(unsigned char port)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA=~PORTA;
		break;
		case 'B':
		case 'b':
		PORTB=~PORTB;
		break;	
		case 'C':
		case 'c':
		PORTC=~PORTC;
		break;
		case 'D':
		case 'd':
		PORTD=~PORTD;
		break;
		default:
		break;
		
	}
}
unsigned char DIO_PORT_READ(unsigned char port)
{
		unsigned char value;
		switch(port)
		{
			case 'A':
			case 'a':
			value=PINA;
			break;
			case 'B':
			case 'b':
	        value=PINB;
			break;
			case 'C':
			case 'c':
			value=PINC;
			break;
			case 'D':
			case 'd':
			value=PIND;
			break;
			default:
			break;
			
			
			
			
			
			
		}
		return value;
}
void DIO_connect_pull_up(unsigned char port,unsigned char pin,unsigned char connection)
{
	if(connection==1)
	{
		DIO_WRITE(port,pin,1);
	}
	else
	{
		DIO_WRITE(port,pin,0);
		
	}
}
void write_low_nibble(unsigned char port,unsigned char number)
{
	unsigned char i;
	for (i=0;i<=3;i++)
	{
		DIO_WRITE(port,i,READ_BIT(number,i));
	}
	
}
void write_high_nibble(unsigned char port,unsigned char number)
{
	unsigned char i;
	for (i=4;i<=7;i++)
	{
		DIO_WRITE(port,i,READ_BIT(number,i));
	}
	
}