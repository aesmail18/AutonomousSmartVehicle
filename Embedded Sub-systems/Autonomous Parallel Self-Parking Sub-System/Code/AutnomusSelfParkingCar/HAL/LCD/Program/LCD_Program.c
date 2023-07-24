/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 17, 2022           */
/*          Version: 1.0                  */
/*          Module: LCD                   */
/*          File: LCD_Program.c           */
/********************* ********************/

#include "LCD_Interface.h"

void LCD_Initialization ()
{
	 //RS
	 DIO_SetPinDirection(LCD_PORT_RS, LCD_PIN_RS , DIO_OUTPUT);
	 //Enable
	 DIO_SetPinDirection(LCD_PORT_E, LCD_PIN_E , DIO_OUTPUT);
	 // Data Pins
    #if LCD_Mode == LCD_4_BIT
		DIO_SetPinDirection (LCD_PORT_D4, LCD_PIN_D4, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D5, LCD_PIN_D5, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D6, LCD_PIN_D6, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D7, LCD_PIN_D7, DIO_OUTPUT);
  	
    #elif LCD_Mode == LCD_8_BIT
		DIO_SetPinDirection (LCD_PORT_D0, LCD_PIN_D0, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D1, LCD_PIN_D1, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D2, LCD_PIN_D2, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D3, LCD_PIN_D3, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D4, LCD_PIN_D4, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D5, LCD_PIN_D5, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D6, LCD_PIN_D6, DIO_OUTPUT);
		DIO_SetPinDirection (LCD_PORT_D7, LCD_PIN_D7, DIO_OUTPUT);
  	
    #endif
	
	_delay_ms(35);
	
	//LCD Commands
	#if LCD_Mode == LCD_4_BIT
		//Function Set Instruction
		LCD_SendInstruction(0x02); 
		_delay_ms(2);			   
								   
		LCD_SendInstruction(0x02); 
		_delay_ms(2);			   
								   
		LCD_SendInstruction(0x28); 
		_delay_ms(2);			   
		
		// Display ON cursor ON						   
		LCD_SendInstruction(0x0E);
		_delay_ms(2);			   
		
		// Clear the LCD						   
		LCD_SendInstruction(0x01);
		_delay_ms(2);			   
		
		// Move the Cursor to First line First Position						   
		LCD_SendInstruction(0x80);
		_delay_ms(2);			   
		
	#elif LCD_Mode == LCD_8_BIT
		LCD_SendInstruction(0x38); //2 lines and 5×7 matrix (8-bit mode)
		_delay_ms(1);
		
		LCD_SendInstruction(0x0E); //Display on, cursor off
		_delay_ms(1);
		
		LCD_SendInstruction(0x01); //Clear display screen
		_delay_ms(2);
		
		LCD_SendInstruction(0x80); //Decrement cursor (shift cursor to left)
		_delay_ms(2);
		
	#endif
}

void LCD_Clear()
{
	LCD_SendInstruction(0x01);	  // Clear the LCD and go to First line First Position
	_delay_ms(3);
	LCD_SendInstruction(LineOne);
	_delay_ms(3);		
}

void LCD_SendInstruction (u8 Instruction)
{
	#if LCD_Mode == LCD_4_BIT
		DIO_SetPinValue(LCD_PORT_D4,LCD_PIN_D4,GET_BIT(Instruction,4));
		DIO_SetPinValue(LCD_PORT_D5,LCD_PIN_D5,GET_BIT(Instruction,5));
		DIO_SetPinValue(LCD_PORT_D6,LCD_PIN_D6,GET_BIT(Instruction,6));
		DIO_SetPinValue(LCD_PORT_D7,LCD_PIN_D7,GET_BIT(Instruction,7));
		
		DIO_SetPinValue(LCD_PORT_RS,LCD_PIN_RS,0);
		
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,1);
		_delay_ms(2);
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,0);
		_delay_ms(2);
		
		DIO_SetPinValue(LCD_PORT_D4,LCD_PIN_D4,GET_BIT( (Instruction <<4) ,4));
		DIO_SetPinValue(LCD_PORT_D5,LCD_PIN_D5,GET_BIT( (Instruction <<4) ,5));
		DIO_SetPinValue(LCD_PORT_D6,LCD_PIN_D6,GET_BIT( (Instruction <<4) ,6));
		DIO_SetPinValue(LCD_PORT_D7,LCD_PIN_D7,GET_BIT( (Instruction <<4) ,7));
		
		DIO_SetPinValue(LCD_PORT_RS,LCD_PIN_RS,0);
		
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,1);
		_delay_ms(2);
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,0);
		_delay_ms(2);
	
	#elif LCD_Mode == LCD_8_BIT
		DIO_SetPinValue(LCD_PORT_D0,LCD_PIN_D0,GET_BIT(Instruction,0));
		DIO_SetPinValue(LCD_PORT_D1,LCD_PIN_D1,GET_BIT(Instruction,1));
		DIO_SetPinValue(LCD_PORT_D2,LCD_PIN_D2,GET_BIT(Instruction,2));
		DIO_SetPinValue(LCD_PORT_D3,LCD_PIN_D3,GET_BIT(Instruction,3));
		DIO_SetPinValue(LCD_PORT_D4,LCD_PIN_D4,GET_BIT(Instruction,4));
		DIO_SetPinValue(LCD_PORT_D5,LCD_PIN_D5,GET_BIT(Instruction,5));
		DIO_SetPinValue(LCD_PORT_D6,LCD_PIN_D6,GET_BIT(Instruction,6));
		DIO_SetPinValue(LCD_PORT_D7,LCD_PIN_D7,GET_BIT(Instruction,7));
		
		DIO_SetPinValue(LCD_PORT_RS,LCD_PIN_RS,0);
		
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,1);
		_delay_ms(2);
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,0);
		_delay_ms(2);
	
	#endif
	
	_delay_ms(1);
}

void LCD_WriteCharacter (u8 Character){
	#if LCD_Mode == LCD_8_BIT
		DIO_SetPinValue(LCD_PORT_D0,LCD_PIN_D0,GET_BIT(Character,0));
		DIO_SetPinValue(LCD_PORT_D1,LCD_PIN_D1,GET_BIT(Character,1));
		DIO_SetPinValue(LCD_PORT_D2,LCD_PIN_D2,GET_BIT(Character,2));
		DIO_SetPinValue(LCD_PORT_D3,LCD_PIN_D3,GET_BIT(Character,3));
		DIO_SetPinValue(LCD_PORT_D4,LCD_PIN_D4,GET_BIT(Character,4));
		DIO_SetPinValue(LCD_PORT_D5,LCD_PIN_D5,GET_BIT(Character,5));
		DIO_SetPinValue(LCD_PORT_D6,LCD_PIN_D6,GET_BIT(Character,6));
		DIO_SetPinValue(LCD_PORT_D7,LCD_PIN_D7,GET_BIT(Character,7));
		
		DIO_SetPinValue(LCD_PORT_RS,LCD_PIN_RS,1);
		
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,1);
		_delay_ms(2);
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,0);
		_delay_ms(2);
	
	#elif LCD_Mode == LCD_4_BIT
		DIO_SetPinValue(LCD_PORT_D4,LCD_PIN_D4,GET_BIT(Character,4));
		DIO_SetPinValue(LCD_PORT_D5,LCD_PIN_D5,GET_BIT(Character,5));
		DIO_SetPinValue(LCD_PORT_D6,LCD_PIN_D6,GET_BIT(Character,6));
		DIO_SetPinValue(LCD_PORT_D7,LCD_PIN_D7,GET_BIT(Character,7));
		
		DIO_SetPinValue(LCD_PORT_RS,LCD_PIN_RS,1);
		
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,1);
		_delay_ms(2);
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,0);
		_delay_ms(2);
		
		DIO_SetPinValue(LCD_PORT_D4,LCD_PIN_D4,GET_BIT( (Character <<4) ,4));
		DIO_SetPinValue(LCD_PORT_D5,LCD_PIN_D5,GET_BIT( (Character <<4) ,5));
		DIO_SetPinValue(LCD_PORT_D6,LCD_PIN_D6,GET_BIT( (Character <<4) ,6));
		DIO_SetPinValue(LCD_PORT_D7,LCD_PIN_D7,GET_BIT( (Character <<4) ,7));
		
		DIO_SetPinValue(LCD_PORT_RS,LCD_PIN_RS,1);
		
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,1);
		_delay_ms(2);
		DIO_SetPinValue(LCD_PORT_E,LCD_PIN_E,0);
		_delay_ms(2);

	#endif
	_delay_ms(1);
}

void LCD_WriteString (char* ptr){
	while (*ptr!='\0')
	{
		LCD_WriteCharacter(*ptr);
		ptr++;
	}
}

void LCD_WriteNumber (u8 Number){
	LCD_WriteCharacter(Number + 48);
}


void LCD_SetCursor(u8 row ,u8 column){
	u8 address=0x80;
	row--;
	column--;
	switch(row)
	{
		case 0:
		address=column+0x80;
		break;
		case 1:
		address=column+0xc0;
		break;
		default:
		address=0x80;
		break;
	}
	LCD_SendInstruction(address);
	_delay_ms(1);
}