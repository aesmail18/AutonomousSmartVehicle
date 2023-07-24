#include "STD_Types.h"
#include "BIT_Status.h"
#include "DIO_Interface.h"
#include <avr/io.h>
//#include <avr/interrupt.h>

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_



typedef enum
{
   NORMAL=0,
   PHASE_CORRECT,
   CTC,
   FAST_PWM
}Timer_mode;  // for timer 0 and 2

typedef enum
{
	DISCONNECTED=0,
	TOGGLE,
	CLEAR,
	SET
}OC_MODE;

/* ////////////////////Timer0////////////////////////////*/	
typedef enum
{
	TIMER0_STOP=0,
	TIMER0_NO_PRESCALER,
	TIMER0_PRESCALER_8,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024,
	TIMER0_EXTERNAL_FALLING,
	TIMER0_EXTERNAL_RISING
	
}Timer0_prescaler_type;

void Timer0_Initilization(Timer_mode timer_mode,Timer0_prescaler_type scaler_type,OC_MODE oc_mode);
void Timer0_Update_CounterReg(u8 value);
void Timer0_Update_CompareReg(u8 value);
void Timer0_Update_TimerMode(Timer_mode timer_mode);
void Timer0_Update_OC_Mode(OC_MODE oc_mode);
void Timer0_Update_Prescaler_Type(Timer0_prescaler_type scaler_type);
u8   Timer0_Read_CounterReg(void);
void Timer0_OV_InterruptEnable();
void Timer0_OV_InterruptDisable();
void Timer0_OC_InterruptEnable();
void Timer0_OC_InterruptDisable();
/*void Timer0_OVF_SetCallBack(void(*LocalPtr)(void));*/
/*/////////////////////Timer2////////////////////////////*/	
typedef enum
{
	IO_CLOCK=0,
	CRYSTAL_OSCILLATOR
}Timer2_asynchronous_mode;

typedef enum
{
	TIMER2_STOP=0,
	TIMER2_NO_PRESCALER,
	TIMER2_PRESCALER_8,
	TIMER2_PRESCALER_32,
	TIMER2_PRESCALER_64,
	TIMER2_PRESCALER_128,
	TIMER2_PRESCALER_256,
	TIMER2_PRESCALER_1024
}Timer2_prescaler_type;

void Timer2_Initilization(Timer_mode timer_mode,Timer2_prescaler_type scaler_type,OC_MODE oc_mode,Timer2_asynchronous_mode as_mode);
void Timer2_Update_CounterReg(u8 value);
void Timer2_Update_CompareReg(u8 value);
void Timer2_Update_Timer_Mode(Timer_mode timer_mode);
void Timer2_Update_OC_Mode(OC_MODE oc_mode);
void Timer2_Update_AS_mode(Timer2_asynchronous_mode as_mode);
void Timer2_Update_Prescaler_Type(Timer2_prescaler_type scaler_type);
void Timer2_OV_InterruptEnable();
void Timer2_OV_InterruptDisable();
void Timer2_OC_InterruptEnable();
void Timer2_OC_InterruptDisable();

/*/////////////////////Timer1////////////////////////////*/	
typedef enum
{
	TIMER1_NORMAL=0,
	TIMER1_PHASE_CORRECT_8BIT,
	TIMER1_PHASE_CORRECT_9BIT,
	TIMER1_PHASE_CORRECT_10BIT,
	TIMER1_CTC_OCR1A,
	TIMER1_CTC_ICR1,
	TIMER1_PWM_8BIT,
	TIMER1_PWM_9BIT,
	TIMER1_PWM_10BIT,
	TIMER1_PWM_OCR1A,
	TIMER1_PWM_ICR1,
	TIMER1_PHASE_CORRECT_ICR1_TOP_UPDATE_BOTTOM,
	TIMER1_PHASE_CORRECT_OCR1A_TOP_UPDATE_BOTTOM,
	TIMER1_PHASE_CORRECT_ICR1_TOP_UPDATE_TOP,
	TIMER1_PHASE_CORRECT_OCR1A_TOP_UPDATE_TOP
}Timer1_mode;

typedef enum
{
	TIMER1_STOP=0,
	TIMER1_NO_PRESCALER,
	TIMER1_PRESCALER_8,
	TIMER1_PRESCALER_64,
	TIMER1_PRESCALER_256,
	TIMER1_PRESCALER_1024,
	TIMER1_EXTERNAL_FALLING,
	TIMER1_EXTERNAL_RISING
	
}Timer1_prescaler_type;

typedef enum
{
	RISING,
	FALLING
	}ICU_Edge_type;


void Timer1_Initilization(Timer1_mode timer_mode,Timer1_prescaler_type scaler_type,OC_MODE oca_mode,OC_MODE ocb_mode);
void Timer1_Update_Timer_Mode(Timer1_mode timer_mode);
void Timer1_Update_CounterReg(u16 value);
void Timer1_Update_CompareReg_A(u16 value);
void Timer1_Update_CompareReg_B(u16 value);
void Timer1_Update_Prescaler_Type(Timer1_prescaler_type scaler_type);
void Timer1_Update_OCA_Mode(OC_MODE oca_mode);
void Timer1_Update_OCB_Mode(OC_MODE ocb_mode);
void Timer1_Update_OCR1A(u16 value);
void Timer1_Update_OCR1B(u16 value);
void Timer1_OV_InterruptEnable();
void Timer1_OV_InterruptDisable();
void Timer1_OCA_InterruptEnable();
void Timer1_OCA_InterruptDisable();
void Timer1_OCB_InterruptEnable();
void Timer1_OCB_InterruptDisable();
void Timer1_IC_InterruptEnable();
void Timer1_IC_InterruptDisable();
void Timer1_IC_EdgeSelect(ICU_Edge_type edge);
void Timer1_Update_ICR1(u16 value);
void Timer1_IC_NoiseCancler_Enable();
void Timer1_IC_NoiseCancler_Disable();

#endif