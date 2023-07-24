/****************************************/
/* Author: Mohammed Mashal              */
/* Date: Jan, 25, 2023                  */
/* Version: 1.0                         */
/* Module: IR                           */
/* File: IR_Program.c                   */
/****************************************/

#include "DIO_Interface.h"
#include "IR_Interface.h"

void IR_Initilization(){
	
	//make IR pins as input
	DIO_SetPinDirection( IR_FRONT_PORT, IR_FRONT_PIN, DIO_INPUT);
	DIO_SetPinDirection( IR_BACK_PORT, IR_BACK_PIN, DIO_INPUT);
	
	//enable pull up resistor
	DIO_EnablePullUpRes( IR_FRONT_PORT,IR_FRONT_PIN);
	DIO_EnablePullUpRes( IR_BACK_PORT, IR_BACK_PIN);
}

u8 IR_FrontRead(){
	return DIO_GetPinValue ( IR_FRONT_PORT, IR_FRONT_PIN);
}


u8 IR_BackRead(){
	return DIO_GetPinValue ( IR_BACK_PORT, IR_BACK_PIN);
}