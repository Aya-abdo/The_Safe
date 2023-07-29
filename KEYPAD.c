/*
 * KEYPAD.c
 *
 * Created: 10/28/2021 11:28:50 AM
 *  Author: MSI
 */ 
#include "KEY_PAD.h"
void key_pad_init()
{
	DIO_SET_PORT_DIR(KEYPADPORT,0x0f);
	DIO_connect_pull_up(KEYPADPORT,4,1);
	DIO_connect_pull_up(KEYPADPORT,5,1);
	DIO_connect_pull_up(KEYPADPORT,6,1);
	DIO_connect_pull_up(KEYPADPORT,7,1);
}
unsigned char key_pad_check_press()
{
	unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	unsigned char value=NOTPRESSED;
	unsigned char row,column;
	for(row=0;row<4;row++)
	{
		DIO_WRITE(KEYPADPORT,0,1);
		DIO_WRITE(KEYPADPORT,1,1);
		DIO_WRITE(KEYPADPORT,2,1);
		DIO_WRITE(KEYPADPORT,3,1);
		DIO_WRITE(KEYPADPORT,row,0);
		for (column=0;column<4;column++)
		{
			if (DIO_READ(KEYPADPORT,column+4)==0)
			{
				value=arr[row][column];
				break;
			}
		if (value!=0xff)
		{
			break;
		}
		}
	}
	return value;
}