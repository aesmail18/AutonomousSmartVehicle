/****************************************/
/*      Author: Ahmed Esmail            */
/*      Date: Feb, 1, 2023              */
/*      Version: 2.0                    */
/*      Module: ALCOHOL sensor          */
/*      File: ALCOHOL_Program.c         */
/****************************************/

#include "ALCOHOL_Interface.h"


void ALCOHOL_Initilization(void){
	DIO_SetPinDirection( ALCOHOL_PORT, ALCOHOL_PIN, DIO_INPUT);
	_delay_ms(120000);   // delay for 2 min to get mq3 warm up
}


u8 ALCOHOL_Read(void){
	// It returns 0 if alchol detected otherwise return 1
	return DIO_GetPinValue ( ALCOHOL_PORT, ALCOHOL_PIN);
}