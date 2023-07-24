/****************************************/
/* Author:  Mashal                      */
/* Date: June, 17, 2023                 */
/* Version: 1.0                         */
/* Module: Ultrasonic                   */
/* File: ULTRASONIC_Program.c           */
/****************************************/


#include "ULTRASONIC_Interface.h"
volatile u64 Num_Of_OV=0;

void ULTRASONIC_Initilization(void)
{
	DIO_SetPinDirection( ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_OUTPUT);
	DIO_SetPinDirection( ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, DIO_INPUT);
	Timer0_Initilization(NORMAL,TIMER0_NO_PRESCALER,DISCONNECTED);
	//Timer0_OVF_SetCallBack(CountingOV);
	
}


u16   ULTRASONIC_GetDistance(void)
{
	u16 distance=0;
	u16 Time=0;
	u8 value_from_timerReg=0;
	Num_Of_OV=0;
	
	DIO_SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_HIGH);
	_delay_us(50);
	DIO_SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_LOW);
	
	
	while(DIO_GetPinValue(ULTRASONIC_ECHO_PORT,ULTRASONIC_ECHO_PIN)==0);
	Timer0_OV_InterruptEnable();
	Timer0_Update_CounterReg(0);
	
	
	
	while(DIO_GetPinValue(ULTRASONIC_ECHO_PORT,ULTRASONIC_ECHO_PIN)==1);
	Timer0_OV_InterruptDisable();
	
	value_from_timerReg=Timer0_Read_CounterReg();
	Time = value_from_timerReg + (Num_Of_OV*256);
	distance=(((34600)*Time)/F_CPU)/2;
	
	
	return distance;
}



ISR(TIMER0_OVF_vect)
{
	Num_Of_OV++;
}


// void CountingOV(void)
// {
// 	Num_Of_OV++;
// }