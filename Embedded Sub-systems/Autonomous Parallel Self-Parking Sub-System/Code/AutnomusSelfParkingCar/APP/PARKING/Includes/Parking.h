/*
 * Parking.h
 *
 * Created: 6/16/2023 9:46:52 AM
 *  Author: Mashal
 */ 


#ifndef PARKING_H_
#define PARKING_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_Types.h"
#include "Buzzer_Interface.h"
#include "SERVO_MOTOR_Interface.h"
#include "DC_MOTOR_Interface.h"
#include "LCD_Interface.h"


void AutoPark(void);

//void Beep(u8 num_of_beeps,u8 time_between_beeps);


#endif /* PARKING_H_ */