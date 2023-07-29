/*
 * THE_SAFE.c
 *
 * Created: 10/28/2021 1:41:35 PM
 *  Author: MSI
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "E2PROM.h"
#include "LCD.h"
#include "KEY_PAD.h"
#define EEPROM_STATUS_ADDRESS 0x20
#define EEPROM_PASS_LOCATION1 0x21
#define EEPROM_PASS_LOCATION2 0x22
#define EEPROM_PASS_LOCATION3 0x23
#define EEPROM_PASS_LOCATION4 0x24
#define TRIES 2
unsigned char arr[4];
int main(void)
{
	LCD_init();
	key_pad_init();
	unsigned char value;
	unsigned char tries=TRIES;
	unsigned char flag=0,i;
   
	if (EEPROM_read(EEPROM_STATUS_ADDRESS)==0xff)
	{
		LCD_send_string("SET PASS:");
		for(i=0;i<4;i++)
		{
			do 
			{
				value=key_pad_check_press();
			} while (value==NOTPRESSED);
			EEPROM_write(EEPROM_PASS_LOCATION1+i,value);
			LCD_send_char(value);
			
			LCD_move_cursor(1,10+i);
			LCD_send_char('*');
			_delay_ms(500);
			value=NOTPRESSED;
			
		}
		EEPROM_write(EEPROM_STATUS_ADDRESS,0x00);
		
	}
	else
	{
		while(flag==0)
		{
			arr[0],arr[1],arr[2],arr[3]=NOTPRESSED;
			LCD_clear();
			LCD_send_string("check Pass:");
			for (i=0;i<4;i++)
			{
				do 
				{
					arr[i]=key_pad_check_press();
				} while (arr[i]==NOTPRESSED);
				LCD_send_char(arr[i]);
				LCD_move_cursor(1,12+i);
				LCD_send_char('*');
				_delay_ms(500);
			}
			
			if (arr[0]==EEPROM_read(EEPROM_PASS_LOCATION1)&&arr[1]==EEPROM_read(EEPROM_PASS_LOCATION2)&&arr[2]==EEPROM_read(EEPROM_PASS_LOCATION3)&&arr[3]==EEPROM_read(EEPROM_PASS_LOCATION4))
			{
				LCD_clear();
				LCD_send_string("right password");
				LCD_move_cursor(2,1);
				LCD_send_string("safe opened");
				flag=1;
				
			}
			else
			{
				tries-=1;
				if(tries>0)
				{
					
					LCD_clear();
					LCD_send_string("wrong password");
					_delay_ms(1000);
					LCD_move_cursor(2,1);
					LCD_send_string("tries left:");
					LCD_send_char(tries+48);
					_delay_ms(1000);
					
					
				}
				else if (tries==0)
				{
						LCD_clear();
						LCD_send_string("wrong password");
						LCD_move_cursor(2,1);
						LCD_send_string("safe closed");
						flag=1;
				}
			}
		}
	}
}