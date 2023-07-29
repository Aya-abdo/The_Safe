/*
 * KEY_PAD.h
 *
 * Created: 10/28/2021 11:28:35 AM
 *  Author: MSI
 */ 


#ifndef KEY_PAD_H_
#define KEY_PAD_H_
#define NOTPRESSED 0xff
#define KEYPADPORT 'D'
#include "DIO.h"
void key_pad_init(void);
unsigned char key_pad_check_press(void);





#endif /* KEY_PAD_H_ */