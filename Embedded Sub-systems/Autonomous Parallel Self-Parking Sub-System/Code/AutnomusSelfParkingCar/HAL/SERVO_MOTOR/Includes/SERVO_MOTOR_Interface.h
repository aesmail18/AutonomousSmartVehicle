/****************************************/
/* Author: Mohammed Mashal              */
/* Date: Feb, 1, 2023                   */
/* Version: 1.0                         */
/* Module: Servo Motor                  */
/* File: Servo_Motor_Interface.h        */
/****************************************/

#include "STD_Types.h"
#include "BIT_Status.h"
#include "Timer_Interface.h"
#include "SERVO_MOTOR_Private.h"
#include "SERVO_MOTOR_Configuration.h"

#ifndef SERVO_MOTOR_INTERFACE_H_
#define SERVO_MOTOR_INTERFACE_H_

// macros for defining angle constant
#define SERVO_NO_ANGLE      0
#define SERVO_LEFT_ANGLE    -29
#define SERVO_RIGHT_ANGLE   26


void SERVO_MOTOR_Initilization(void);
void SERVO_MOTOR_Vertical(void);		//No angle applied 
void SERVO_MOTOR_TurnRight(void);
void SERVO_MOTOR_TurnLeft(void);


#endif