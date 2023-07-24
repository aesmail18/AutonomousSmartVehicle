/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 16, 2022           */
/*          Version: 2.0                  */
/*          Module: DIO                   */
/*          File: DIO_Private.h           */
/********************* ********************/


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

//DIO Registers Addresses
#define DDR_A          (*((volatile u8*) 0x3A))		//Data Direction Register
#define DDR_B          (*((volatile u8*) 0x37))
#define DDR_C          (*((volatile u8*) 0x34))
#define DDR_D          (*((volatile u8*) 0x31))

#define PORT_A         (*((volatile u8*) 0x3B))		
#define PORT_B         (*((volatile u8*) 0x38))
#define PORT_C         (*((volatile u8*) 0x35))
#define PORT_D         (*((volatile u8*) 0x32))

#define PIN_A          (*((volatile u8*) 0x39))
#define PIN_B          (*((volatile u8*) 0x36))
#define PIN_C          (*((volatile u8*) 0x33))
#define PIN_D          (*((volatile u8*) 0x30))

#define SFIO_R         (*((volatile u8*) 0x50))  // pull up resistor

//Data on a pin direction
#define DIO_INPUT          0
#define DIO_OUTPUT         1

//Data value on a pin
#define DIO_LOW            0
#define DIO_HIGH           1

#endif 
