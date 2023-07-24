/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Mar, 20, 2023           */
/*          Version: 1.0                  */
/*          Module: LED                   */
/*          File: LED_Program.c           */
/********************* ********************/

#include "LED_Interface.h"

void LED_Initilization(void){
	DIO_SetPinDirection(LED_PORT,LED_PIN,DIO_OUTPUT);
}

void LED_TurnOn(void){
	DIO_SetPinValue(LED_PORT,LED_PIN,DIO_HIGH);
}

void LED_TurnOff(void){
	DIO_SetPinValue(LED_PORT,LED_PIN,DIO_LOW);
}