/*
 * LCD.h
 *
 * Created: 10/21/2021 9:21:11 AM
 *  Author: MSI
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "LCD_config.h"
#define PD 'A'
#define PW 'B'
#define DISPLAY_CURS_ON_OFF 0x0e
#define RETUEN_HOME 0x02
#define ENTRY_MODE 0x06
#define CLEAR_CMD 0x01
#define EN 0
#define RW 1
#define RS 2
#define ROW1 0x80
#define ROW2 0xc0

#if defined EIGHT_BIT_MODE
#define EIGHT_MODE 0x38
#elif defined FOUR_BIT_MODE
#define FOUR_MODE 0x28
#endif


void LCD_init();
void LCD_send_char(unsigned char data);
void LCD_send_cmd(unsigned char command);
void LCD_clear();
void LCD_move_cursor(unsigned char row,unsigned char column);
void ENABLE();
void LCD_send_string(char *data);




#endif /* LCD_H_ */