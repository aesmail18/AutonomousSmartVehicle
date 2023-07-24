/****************************************/
/* Author: Mohammed Mashal              */
/* Date: Nov, 20, 2022                  */
/* Version: 1.0                         */
/* Module: DC Motor                     */
/* File: DC_MOTOR_Interface.h           */
/****************************************/

#include "STD_Types.h"
#include "BIT_Status.h"
#include "DC_MOTOR_Configuration.h"
#include "DC_MOTOR_Private.h"

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

#define DC_MOTOR_PORT       DIO_PORT_A 

#define DC_MOTOR_PIN1       DIO_PIN_3 

#define DC_MOTOR_PIN2       DIO_PIN_4 


/****************************************************************
 name           : 	DC_MOTOR_Init                        
 description    : 	initialize output pins for dc motor  		                                         
 parameter      :   None		     
 options        :   Set from config file  
 return         : 	none                             
****************************************************************/
void DC_MOTOR_Initilization();


/****************************************************************
 name           : 	DC_MOTOR_RunClkWise                        
 description    : 	make dc motor run on clock wise direction		                                         
 parameter      :   None		       
 return         : 	none                             
****************************************************************/
void DC_MOTOR_RunClkWise();


/****************************************************************
 name           : 	DC_MOTOR_RunAntiClkWise                       
 description    : 	make dc motor run on anti clock wise direction	 		                                         
 parameter      :   None		      
 return         : 	none                             
****************************************************************/
void DC_MOTOR_RunAntiClkWise();


/****************************************************************
 name           : 	DC_MOTOR_Stop                        
 description    : 	stop dc motor  		                                         
 parameter      :   None		      
 return         : 	none                             
****************************************************************/
void DC_MOTOR_Stop(); 


#endif