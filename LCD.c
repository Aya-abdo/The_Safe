/*
 * LCD.c
 *
 * Created: 10/21/2021 9:20:49 AM
 *  Author: MSI
 */ 
#include "LCD.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_init()
{
  _delay_ms(200);
  #if defined EIGHT_BIT_MODE
  DIO_SET_PORT_DIR(PD,0xff);
  DIO_SET_DIR(PW,EN,1);
  DIO_SET_DIR(PW,RS,1);
  DIO_SET_DIR(PW,RW,1);
  DIO_WRITE(PW,RW,0);
  LCD_send_cmd(EIGHT_MODE);
  _delay_ms(1);
  LCD_send_cmd(DISPLAY_CURS_ON_OFF);
  _delay_ms(1);
  LCD_send_cmd(CLEAR_CMD);
  _delay_ms(10);
  LCD_send_cmd(ENTRY_MODE);
  _delay_ms(1);
  #elif defined FOUR_BIT_MODE
  DIO_SET_DIR(PD,4,1);	
  DIO_SET_DIR(PD,5,1);
  DIO_SET_DIR(PD,6,1);
  DIO_SET_DIR(PD,7,1);
  DIO_SET_DIR(PW,EN,1);
  DIO_SET_DIR(PW,RS,1);
  DIO_SET_DIR(PW,RW,1);
  DIO_WRITE(PW,RW,0);
  LCD_send_cmd(RETUEN_HOME);
  _delay_ms(10);
  LCD_send_cmd(FOUR_MODE);
  _delay_ms(1);
  LCD_send_cmd(DISPLAY_CURS_ON_OFF);
    _delay_ms(1);
  LCD_send_cmd(CLEAR_CMD);
  _delay_ms(10);
  LCD_send_cmd(ENTRY_MODE);
  _delay_ms(1);
	#endif
  
    
}
void LCD_send_char(unsigned char data)
{
	#if defined EIGHT_BIT_MODE
	DIO_PORT_WRITE(PD,data);
	DIO_WRITE(PW,RS,1);
	ENABLE();
	_delay_ms(1);
	#elif defined FOUR_BIT_MODE
	write_high_nibble(PD,data);
	DIO_WRITE(PW,RS,1);
	ENABLE();
	write_high_nibble(PD,data<<4);
	
	ENABLE();
	_delay_ms(1);
	
	
   #endif
}
void LCD_send_cmd(unsigned char command)
{
	#if defined EIGHT_BIT_MODE
	DIO_PORT_WRITE(PD,command);
	DIO_WRITE(PW,RS,0);
	ENABLE();
	_delay_ms(1);
	#elif defined FOUR_BIT_MODE
	write_high_nibble(PD,command);
	DIO_WRITE(PW,RS,0);
	ENABLE();
	write_high_nibble(PD,command<<4);
	
	ENABLE();
	_delay_ms(1);
	 #endif
}
void LCD_clear()
{
	LCD_send_cmd(CLEAR_CMD);
	_delay_ms(10);
}
void LCD_move_cursor(unsigned char row,unsigned char column)
{
	unsigned char cmd;
	if(row<1||row>2||column>16||column<1)
    {
		cmd=ROW1;
	}
	else if(row==1)
	{
		cmd=ROW1+column-1;
	}
	else if(row==2)
	{
		cmd=ROW2+column-1;
	}
	LCD_send_cmd(cmd);
	_delay_ms(1);
}
void ENABLE()
{
	DIO_WRITE(PW,EN,1);
	_delay_ms(2);
	DIO_WRITE(PW,EN,0);
	_delay_ms(2);
}
void LCD_send_string(char *data)
{
	while((*data) != '\0')
	{
		LCD_send_char(*data);
		data++;
	}
}