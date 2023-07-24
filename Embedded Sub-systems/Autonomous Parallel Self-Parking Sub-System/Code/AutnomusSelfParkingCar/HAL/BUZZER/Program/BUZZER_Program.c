/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Mar, 20, 2023           */
/*          Version: 1.0                  */
/*          Module: Buzzer                */
/*          File: Buzzer_Program.c        */
/********************* ********************/

#include "BUZZER_Interface.h"

void BUZZER_Initilization(void){
	DIO_SetPinDirection(BUZZER_PORT,BUZZER_PIN,DIO_OUTPUT);
}

void BUZZER_TurnOn(void){
	DIO_SetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_HIGH);
}

void BUZZER_TurnOff(void){
	DIO_SetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_LOW);
}