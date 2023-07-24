/****************************************/
/* Author: Mohammed Mashal              */
/* Date: Jan, 25, 2023                  */
/* Version: 1.0                         */
/* Module: IR sensor                    */
/* File: IR_Interface.h                 */
/****************************************/


#include "STD_Types.h"
#include "BIT_Status.h"
#include "IR_Configuration.h"
#include "IR_Private.h"


#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

//Front IR
#define IR_FRONT_PORT       DIO_PORT_D

#define IR_FRONT_PIN        DIO_PIN_4

//Back IR
#define IR_BACK_PORT        DIO_PORT_D
						   
#define IR_BACK_PIN         DIO_PIN_6


/****************************************************************
 name           : 	IR_Initilization                        
 description    : 	initialize input pin for IR sensor 		                                         
 parameter      :   None		     
 options        :   Set from config file  
 return         : 	none                             
****************************************************************/
void IR_Initilization(void);


/****************************************************************
 name           : 	IR_FrontRead                        
 description    : 	read value from Front IR sensor		                                         
 parameter      :   None		     
 return         : 	1 if there is an obstacle  ,  0 if there is nothing                             
****************************************************************/
u8 IR_FrontRead(void);


/****************************************************************
 name           : 	IR_BackRead                        
 description    : 	read value from Back IR sensor		                                         
 parameter      :   None		     
 return         : 	1 if there is an obstacle  ,  0 if there is nothing                             
****************************************************************/
u8 IR_BackRead(void);

#endif