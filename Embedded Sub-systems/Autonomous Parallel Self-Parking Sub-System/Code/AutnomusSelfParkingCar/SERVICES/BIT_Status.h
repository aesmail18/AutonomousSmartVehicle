/******************************************/
/*          Author: Ahmed Esmail          */
/*          Date: Des, 16, 2022           */
/*          Version: 1.0                  */
/*          Module: Service               */
/*          File: BIT_Status.h            */
/********************* ********************/


#ifndef BIT_STATUS_H_
#define BIT_STATUS_H_

#define SET_BIT(Register, BitNo)        Register = (Register | (1 << BitNo))
#define GET_BIT(Register, BitNo)        ((Register >> BitNo) & 1)						
#define CLEAR_BIT(Register, BitNo)      Register = (Register & ~(1 << BitNo))
#define TOGGLE_BIT(Register, BitNo)     Register = (Register ^ (1 << BitNo))

#endif 

