/****************************************/
/* Author: Mohammed Mashal */
/* Date: Feb, 1, 2023 */
/* Version: 1.0 */
/* Module: Door sensor */
/* File: DOOR_Interface.h */
/****************************************/


#include "STD_Types.h"
#include "BIT_Status.h"
#include "DIO_Interface.h"
#include "DOOR_Private.h"
#include "DOOR_Configuration.h"

#ifndef DOOR_INTERFACE_H_
#define DOOR_INTERFACE_H_


#define DOOR_PORT    DIO_PORT_D

#define DOOR_PIN     DIO_PIN_7


/****************************************************************
 name           : 	DOOR_Initilization                        
 description    : 	initialize input pin for door sensor  		                                         
 parameter      :   None		     
 return         : 	none                             
****************************************************************/
void DOOR_Initilization(void);


/****************************************************************
 name           : 	DOOR_Read                        
 description    : 	read status of door sensor		                                         
 parameter      :   None		       
 return         : 	unsigned char : 0 if switch is closed otherwise return 1                             
****************************************************************/
u8 DOOR_Read(void);


#endif