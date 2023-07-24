/****************************************/
/*      Author: Ahmed Esmail            */
/*      Date: Feb, 1, 2023              */
/*      Version: 2.0                    */
/*      Module: ALCOHOL sensor          */
/*      File: ALCOHOL_Interface.h       */
/****************************************/

#include "STD_Types.h"
#include "BIT_Status.h"
#include "DIO_Interface.h"
#include "ALCOHOL_Private.h"
#include "ALCOHOL_Configuration.h"

#define  F_CPU 8000000UL
#include <util/delay.h>


#ifndef ALCOHOL_INTERFACE_H_
#define ALCOHOL_INTERFACE_H_

#define ALCOHOL_PORT    DIO_PORT_D
		
#define ALCOHOL_PIN     DIO_PIN_2

void ALCOHOL_Initilization(void);

u8   ALCOHOL_Read(void);

#endif /* ALCOHOL_INTERFACE_H_ */