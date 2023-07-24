/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 17, 2022           */
/*          Version: 1.0                  */
/*          Module: LCD                   */
/*          File: LCD_Interface.h         */
/********************* ********************/

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_Types.h"
#include "BIT_Status.h"
#include "DIO_Interface.h"
#include "LCD_Configuration.h"
#include "LCD_Private.h"

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

//Interfacing with the microcontroller
#define LCD_PORT_RS  DIO_PORT_A

#define LCD_PORT_E   DIO_PORT_A

#define LCD_PIN_RS   DIO_PIN_2

#define LCD_PIN_E    DIO_PIN_5


#define LCD_PORT_D0
#define LCD_PORT_D1
#define LCD_PORT_D2
#define LCD_PORT_D3
#define LCD_PORT_D4  DIO_PORT_B
#define LCD_PORT_D5  DIO_PORT_B
#define LCD_PORT_D6  DIO_PORT_B
#define LCD_PORT_D7  DIO_PORT_B

#define LCD_PIN_D0
#define LCD_PIN_D1
#define LCD_PIN_D2
#define LCD_PIN_D3
#define LCD_PIN_D4   DIO_PIN_4
#define LCD_PIN_D5   DIO_PIN_5
#define LCD_PIN_D6   DIO_PIN_6
#define LCD_PIN_D7   DIO_PIN_7


void LCD_Initialization (void);
void LCD_Clear(void);
void LCD_SendInstruction (u8 Instruction);
void LCD_WriteCharacter (u8 Character);
void LCD_WriteString (char* ptr);
void LCD_WriteNumber (u8 Number);
void LCD_SetCursor(u8 row ,u8 column);


#endif 
