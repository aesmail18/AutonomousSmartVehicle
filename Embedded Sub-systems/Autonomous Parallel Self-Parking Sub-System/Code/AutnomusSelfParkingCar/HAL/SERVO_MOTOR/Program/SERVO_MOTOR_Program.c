/****************************************/
/* Author: Mohammed Mashal              */
/* Date: Feb, 1, 2023                   */
/* Version: 1.0                         */
/* Module: Servo Motor                  */
/* File: Servo_Motor_Program.c          */
/****************************************/

#include "SERVO_MOTOR_Interface.h"

static void SERVO_MOTOR_SetAngle(s8 angle);

void SERVO_MOTOR_Initilization(){
	Timer1_Initilization(TIMER1_PWM_ICR1,TIMER1_PRESCALER_8,CLEAR,DISCONNECTED);
	Timer1_Update_ICR1(19999);
}

static void SERVO_MOTOR_SetAngle(s8 angle)
{
	u16 value = 0;
	if (angle>=0 && angle<=90)
	{
		value = 1350 + (11*angle);
		Timer1_Update_OCR1A(value);
	}
	else if (angle<0)
	{
		angle *= -1;
		value = 1350 - (10*angle); 
		Timer1_Update_OCR1A(value);
	}
}

void SERVO_MOTOR_Vertical(){
	SERVO_MOTOR_SetAngle(SERVO_NO_ANGLE);
}
void SERVO_MOTOR_TurnRight()
{
	SERVO_MOTOR_SetAngle(SERVO_RIGHT_ANGLE);
}

void SERVO_MOTOR_TurnLeft()
{
	SERVO_MOTOR_SetAngle(SERVO_LEFT_ANGLE);
}