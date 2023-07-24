/* Author: Mohammed Mashal */
/* Date: Feb, 1, 2023 */
/* Version: 1.0 */
/* Module: Door sensor */
/* File: DOOR_Program.c */
/****************************************/

#include "DOOR_Interface.h"


void DOOR_Initilization(void)
{
	DIO_SetPinDirection( DOOR_PORT, DOOR_PIN, DIO_INPUT);
	DIO_SetPinDirection(DIO_PORT_B,DIO_PIN_0,DIO_OUTPUT);
	DIO_SetPinValue(DIO_PORT_B,DIO_PIN_0,DIO_HIGH);
}

u8 DOOR_Read(void)
{
	// return 0 if switch closed otherwise return 1
	return DIO_GetPinValue ( DOOR_PORT, DOOR_PIN);
}