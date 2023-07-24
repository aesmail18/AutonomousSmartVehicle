/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Dec, 16, 2022           */
/*          Version: 3.0                  */
/*          Module: DIO                   */
/*          File: DIO_Interface.h         */
/********************* ********************/

#include "STD_Types.h"
#include "BIT_Status.h"
#include "DIO_Private.h"
#include "DIO_Configuration.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_SetPinDirection (u8 DIO_PORT_X, u8 DIO_PIN_X, u8 DIO_Direction);


void DIO_SetPinValue (u8 DIO_PORT_X, u8 DIO_PIN_X, u8 DIO_Value);


u8 DIO_GetPinValue (u8 DIO_PORT_X, u8 DIO_PIN_X);

void DIO_SetHighNibbleValue (u8 DIO_PORT_X, u8 DIO_Value);

void DIO_EnablePullUpRes(u8 DIO_PORT_X,u8 DIO_PIN_X);
#endif 



