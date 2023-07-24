/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Mar, 20, 2023           */
/*          Version: 1.0                  */
/*          Module: LED                   */
/*          File: Buzzer_Interface.h      */
/********************* ********************/

#include "STD_Types.h"
#include "BIT_Status.h"
#include "DIO_Interface.h"
#include "BUZZER_Private.h"
#include "BUZZER_Configuration.h"

#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#define BUZZER_PORT    DIO_PORT_C
#define BUZZER_PIN     DIO_PIN_1

void BUZZER_Initilization(void);
void BUZZER_TurnOn(void);
void BUZZER_TurnOff(void);




#endif /* BUZZER_INTERFACE_H_ */