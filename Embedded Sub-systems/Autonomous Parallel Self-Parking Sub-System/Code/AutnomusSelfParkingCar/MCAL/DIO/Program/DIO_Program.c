/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Dec, 16, 2022           */
/*          Version: 2.0                  */
/*          Module: DIO                   */
/*          File: DIO_Program.c           */
/********************* ********************/


#include "DIO_Interface.h"

void DIO_SetPinDirection (u8 DIO_PORT_X, u8 DIO_PIN_X, u8 DIO_Direction)
{
  switch (DIO_PORT_X) 
  {
    case DIO_PORT_A :
     if (DIO_Direction == DIO_OUTPUT)
     {
       SET_BIT (DDR_A, DIO_PIN_X);
     }
     else
     {
       CLEAR_BIT (DDR_A, DIO_PIN_X);
     }
    break;
    case DIO_PORT_B :
     if (DIO_Direction == DIO_OUTPUT)
     {
       SET_BIT (DDR_B, DIO_PIN_X);
     }
     else
     {
       CLEAR_BIT (DDR_B, DIO_PIN_X);
     }
    break;
    case DIO_PORT_C :
     if (DIO_Direction == DIO_OUTPUT)
     {
       SET_BIT (DDR_C, DIO_PIN_X);
     }
     else
     {
       CLEAR_BIT (DDR_C, DIO_PIN_X);
     }
    break;
    case DIO_PORT_D :
     if (DIO_Direction == DIO_OUTPUT)
     {
       SET_BIT (DDR_D, DIO_PIN_X);
     }
     else
     {
       CLEAR_BIT (DDR_D, DIO_PIN_X);
     }
    break;
    default :
     // Error 
    break;
  } 
}


void DIO_SetPinValue (u8 DIO_PORT_X, u8 DIO_PIN_X, u8 DIO_Value)
{
  switch (DIO_PORT_X) 
  {
    case DIO_PORT_A :
     if (DIO_Value == DIO_HIGH)
     {
       SET_BIT (PORT_A, DIO_PIN_X);
     }
     else
     {
       CLEAR_BIT (PORT_A, DIO_PIN_X);
     }
    break;
    case DIO_PORT_B :
     if (DIO_Value == DIO_HIGH)
     {
       SET_BIT (PORT_B, DIO_PIN_X);
     }
     else
     {
       CLEAR_BIT (PORT_B, DIO_PIN_X);
     }
    break;
    case DIO_PORT_C :
     if (DIO_Value == DIO_HIGH)
     {
       SET_BIT (PORT_C, DIO_PIN_X);
     }
     else
     {
       CLEAR_BIT (PORT_C, DIO_PIN_X);
     }
    break;
    case DIO_PORT_D :
     if (DIO_Value == DIO_HIGH)
     {
       SET_BIT (PORT_D, DIO_PIN_X);
     }
     else
     {
       CLEAR_BIT (PORT_D, DIO_PIN_X);
     }
    break;
    default :
     // Error 
    break;
  } 
}


u8 DIO_GetPinValue (u8 DIO_PORT_X, u8 DIO_PIN_X)
{
 u8 PinValue = 0;
 switch (DIO_PORT_X)
 {
   case DIO_PORT_A :
     PinValue = GET_BIT (PIN_A, DIO_PIN_X);
   break;
   case DIO_PORT_B :
     PinValue = GET_BIT (PIN_B, DIO_PIN_X);
   break;
   case DIO_PORT_C :
     PinValue = GET_BIT (PIN_C, DIO_PIN_X);
   break;
   case DIO_PORT_D :
     PinValue = GET_BIT (PIN_D, DIO_PIN_X);
   break;
   default :
     // Error 
   break;
 }
 return PinValue;
}


void DIO_SetHighNibbleValue (u8 DIO_PORT_X, u8 DIO_Value){
	for (u8 i = 4; i < 8 ; i++)
	{
		DIO_SetPinValue(DIO_PORT_X,i,GET_BIT(DIO_Value,i));
	}
}


void DIO_EnablePullUpRes(u8 DIO_PORT_X,u8 DIO_PIN_X)
{
	CLEAR_BIT(SFIO_R,2);
	switch(DIO_PORT_X)
	{
		case DIO_PORT_A:
		SET_BIT(PORT_A,DIO_PIN_X);
		break;
		
		case DIO_PORT_B:
		SET_BIT(PORT_B,DIO_PIN_X);
		break;
		
		case DIO_PORT_C:
		SET_BIT(PORT_C,DIO_PIN_X);
		break;
		
		case DIO_PORT_D:
		SET_BIT(PORT_D,DIO_PIN_X);
		break;
		
		default:
		//error
		break;
	}
}