/*
 * Searching.c
 *
 * Created: 6/16/2023 10:48:37 AM
 *  Author: Mashal
 */ 

#include "Searching.h"

void Searching(void)
{
	//print "parking" on lcd
	LCD_WriteString("Searching...");
	
	//motor forward
	DC_MOTOR_RunClkWise();
	
	
	//looping for searching for distance >= car_length *1.5  or Ir sense an obstacle
	
	
	
	//if distance >= car_length *1.5 then call AutoParking
	
	
	//Ir sense an obstacle then dc motor stops
	
	
}