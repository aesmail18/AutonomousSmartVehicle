/*
 * AutnomusSelfParkingCar.c
 *
 * Created: 2023-07-09 6:35:41 PM
 * Author : Mashal
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include "DC_MOTOR_Interface.h"
#include "BUZZER_Interface.h"
#include "ALCOHOL_Interface.h"
#include "LED_Interface.h"
#include "IR_Interface.h"
#include "DOOR_Interface.h"
#include "LCD_Interface.h"
#include "SERVO_MOTOR_Interface.h"
#include "ULTRASONIC_Interface.h"
#include <avr/interrupt.h>
#include "Parking.h"
#include "UnParking.h"

int main(void)
{
	//sei();
    DC_MOTOR_Initilization();
	//BUZZER_Initilization();
	//ALCOHOL_Initilization();
	//LED_Initilization();
	//IR_Initilization();
	//DOOR_Initilization();
	//LCD_Initialization();
	SERVO_MOTOR_Initilization();
	//ULTRASONIC_Initilization();
	//LCD_WriteString("Distance is");
	_delay_ms(5000);
	//AutoPark();
	UnParking();
	
	
    while (1) 
    {
// 		DC_MOTOR_RunClkWise();
// 		while(IR_FrontRead()==1);
// 		DC_MOTOR_Stop();
// 		BUZZER_TurnOn();
// 		_delay_ms(2000);
// 		BUZZER_TurnOff();
// 		DC_MOTOR_RunAntiClkWise();
// 		while(IR_BackRead()==1);
// 		DC_MOTOR_Stop();
// 		BUZZER_TurnOn();
// 		_delay_ms(2000);
// 		BUZZER_TurnOff();
// 		SERVO_MOTOR_TurnRight();
// 		_delay_ms(2000);
// 		SERVO_MOTOR_Vertical();
// 		_delay_ms(2000);
// 		SERVO_MOTOR_TurnLeft();
// 		_delay_ms(2000);
// 		LCD_SetCursor(2,1);
//  		u16 Distance = ULTRASONIC_GetDistance();
// 		LCD_WriteNumber(Distance/100);
// 		LCD_WriteNumber((Distance/10)%10);
// 		LCD_WriteNumber(Distance%10);
// 		_delay_ms(500);
    }
}

