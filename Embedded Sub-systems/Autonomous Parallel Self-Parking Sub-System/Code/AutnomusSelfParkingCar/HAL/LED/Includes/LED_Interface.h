/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Mar, 20, 2023           */
/*          Version: 1.0                  */
/*          Module: LED                   */
/*          File: LED_Interface.h         */
/********************* ********************/

#include "STD_Types.h"
#include "BIT_Status.h"
#include "DIO_Interface.h"
#include "LED_Private.h"
#include "LED_Configuration.h"

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_PORT    DIO_PORT_C
#define LED_PIN     DIO_PIN_0

void LED_Initilization(void);
void LED_TurnOn(void);
void LED_TurnOff(void);


#endif /* LED_INTERFACE_H_ */