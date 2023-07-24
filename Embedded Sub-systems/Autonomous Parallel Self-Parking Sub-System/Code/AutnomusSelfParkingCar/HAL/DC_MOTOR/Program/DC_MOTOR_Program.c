/****************************************/
/* Author: Mohammed Mashal              */
/* Date: Nov, 20, 2022                  */
/* Version: 1.0                         */
/* Module: DC Motor                     */
/* File: DC_MOTOR_Program.c             */
/****************************************/



#include "DC_MOTOR_Interface.h"
#include "DIO_Interface.h"


void DC_MOTOR_Initilization()
{
	DIO_SetPinDirection( DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_OUTPUT);
	DIO_SetPinDirection( DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_OUTPUT);
}

void DC_MOTOR_RunClkWise()
{
	DIO_SetPinValue( DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_LOW);
	DIO_SetPinValue( DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_HIGH);
}

void DC_MOTOR_RunAntiClkWise()
{
	DIO_SetPinValue( DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_HIGH);
	DIO_SetPinValue( DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_LOW);
}

void DC_MOTOR_Stop()
{
	DIO_SetPinValue( DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_LOW);
	DIO_SetPinValue( DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_LOW);
}