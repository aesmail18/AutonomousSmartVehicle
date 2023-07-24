/*
 * Parking.c
 *
 * Created: 6/16/2023 9:47:03 AM
 *  Author: Mashal
 */ 


#include "Parking.h"


void AutoPark(void)
{
	//print "parking" on lcd
	LCD_Clear();
	LCD_WriteString("Parking...");
	//Beep(2,150);
	
	
	//servo right
	SERVO_MOTOR_TurnRight();
	//Beep(2,150);
	
	
	//motor backward
	DC_MOTOR_RunAntiClkWise();
	//Beep(2,150);
	
	
	//loop for try and error
	_delay_ms(10000);

	//Beep(2,150);
	
	
	//servo left
	DC_MOTOR_Stop();
	SERVO_MOTOR_Vertical();
	_delay_ms(1000);
 	SERVO_MOTOR_TurnLeft();
	 _delay_ms(1000);
	 DC_MOTOR_RunAntiClkWise();
// 	//Beep(2,150);
// 	
// 	
// 	//loop for try and error
 	_delay_ms(3500);
// 	//Beep(2,150);
	
	
	DC_MOTOR_Stop();
	SERVO_MOTOR_Vertical();
	_delay_ms(1000);
	SERVO_MOTOR_TurnRight();
	DC_MOTOR_RunClkWise();
	_delay_ms(3000);
	
	
	DC_MOTOR_Stop();
	SERVO_MOTOR_Vertical();
	_delay_ms(1000);
	SERVO_MOTOR_TurnLeft();
	DC_MOTOR_RunAntiClkWise();
	_delay_ms(3800);
	
	
	DC_MOTOR_Stop();
	SERVO_MOTOR_Vertical();
	_delay_ms(1000);
	SERVO_MOTOR_TurnRight();
	DC_MOTOR_RunClkWise();
	_delay_ms(1500);
	
	DC_MOTOR_Stop();
	SERVO_MOTOR_Vertical();
	_delay_ms(1000);
	DC_MOTOR_RunClkWise();
	_delay_ms(500);
	
	//motor stop
	DC_MOTOR_Stop();


}




//void Beep(u8 num_of_beeps,u8 time_between_beeps)
//{
	//while (num_of_beeps>=0)
	//{
		//BUZZER_TurnOn();
		//_delay_ms(time_between_beeps);
		//BUZZER_TurnOff();
		//num_of_beeps--;
	//}
//}