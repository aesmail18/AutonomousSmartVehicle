/*
 * UnParking.c
 *
 * Created: 6/16/2023 10:29:29 AM
 *  Author: Mashal
 */ 

#include "UnParking.h"


void UnParking(void)
{
	
	//print "un parking" on lcd
	//LCD_Clear();
	//LCD_WriteString("Un Parking...");
	
	
	//Motor backward
	SERVO_MOTOR_Vertical();
	DC_MOTOR_RunAntiClkWise();
	
	
	//loop for try and error
	_delay_ms(2150);
	
	//motor stops
 	DC_MOTOR_Stop();
	_delay_ms(1000);
	
	//servo left
	SERVO_MOTOR_TurnLeft();
	
	
	//motor forward
	DC_MOTOR_RunClkWise();
	
	
	//loop for try and error
	_delay_ms(3800);
	DC_MOTOR_Stop();
	SERVO_MOTOR_Vertical();
	_delay_ms(1000);
	
	
	//servo right
	SERVO_MOTOR_TurnRight();
	DC_MOTOR_RunAntiClkWise();
	
	//loop for try and error
	_delay_ms(3350);
	DC_MOTOR_Stop();
	SERVO_MOTOR_Vertical();
	_delay_ms(1000);
	
	
	SERVO_MOTOR_TurnLeft();
	DC_MOTOR_RunClkWise();
	_delay_ms(6000);
	
	SERVO_MOTOR_Vertical();
	DC_MOTOR_Stop();
	_delay_ms(1000);
	
	SERVO_MOTOR_TurnRight();
	DC_MOTOR_RunClkWise();
	_delay_ms(9000);
	
	SERVO_MOTOR_Vertical();
	DC_MOTOR_Stop();
	_delay_ms(1000);
	
	DC_MOTOR_RunClkWise();
	_delay_ms(500);
	
	DC_MOTOR_Stop();
	
}