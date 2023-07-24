/*********************************************/
/*          Author: Mashal                   */
/*          Date: June, 17, 2023             */
/*          Version: 1.0                     */
/*          Module: Ultrasonic               */
/*          File: ULTRASONIC_Interface.h     */
/*********************************************/
#include "STD_Types.h"
#include "BIT_Status.h"
#include "ULTRASONIC_Configuration.h"
#include "ULTRASONIC_Private.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_Interface.h"
#include "Timer_Interface.h"
#include <avr/interrupt.h>


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_



#define ULTRASONIC_TRIGGER_PORT     DIO_PORT_A
#define ULTRASONIC_TRIGGER_PIN      DIO_PIN_1

#define ULTRASONIC_ECHO_PORT        DIO_PORT_A
#define ULTRASONIC_ECHO_PIN         DIO_PIN_0

/****************************************************************
 name           : 	ULTRASONIC_Initilization                        
 description    : 	initialize output pin for trigger pin and input pin for echo pin  		                                         
 parameter      :   None		       
 return         : 	none                             
****************************************************************/
void ULTRASONIC_Initilization(void);


 /****************************************************************
 name           : 	ULTRASONIC_GetDistance                        
 description    : 	read value from ultrasonic sensor		                                         
 parameter      :   None		     
 return         : 	distance                            
****************************************************************/
u16   ULTRASONIC_GetDistance(void);


/****************************************************************
 name           : 	Counting Overflow                        
 description    : 	Count how many times the TIMER 0 has been overflowed	                                         
 parameter      :   None		     
 return         : 	None                            
****************************************************************/

//void CountingOV(void);

#endif