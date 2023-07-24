#include "Timer_Interface.h"



/////////////////////////////*******Timer0**********//////////////////////////////////

//static void (*Timer0_OVF_Fptr) (void) = NULLPTR;


void Timer0_Initilization(Timer_mode timer_mode,Timer0_prescaler_type scaler_type,OC_MODE oc_mode)
{
	Timer0_Update_TimerMode(timer_mode);
	Timer0_Update_OC_Mode(oc_mode);
	Timer0_Update_Prescaler_Type(scaler_type);
}

void Timer0_Update_CounterReg(u8 value)
{
	TCNT0=value;
}

void Timer0_Update_CompareReg(u8 value)
{
	OCR0=value;
}

void Timer0_Update_TimerMode(Timer_mode timer_mode)
{
	switch(timer_mode)
	{
		case NORMAL:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case PHASE_CORRECT:
		SET_BIT  (TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case CTC:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT  (TCCR0,WGM01);
		break;
		case FAST_PWM:
		SET_BIT  (TCCR0,WGM00);
		SET_BIT  (TCCR0,WGM01);
		break;
		default:
		break;
	}
}

void Timer0_Update_OC_Mode(OC_MODE oc_mode)
{
	switch(oc_mode)
	{
		case DISCONNECTED:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case TOGGLE:
		DIO_SetPinDirection(DIO_PORT_B,DIO_PIN_3,DIO_OUTPUT);
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case CLEAR:
		DIO_SetPinDirection(DIO_PORT_B,DIO_PIN_3,DIO_OUTPUT);
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case SET:
		DIO_SetPinDirection(DIO_PORT_B,DIO_PIN_3,DIO_OUTPUT);
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		default:
		break;
	}
}

void Timer0_Update_Prescaler_Type(Timer0_prescaler_type scaler_type)
{
	switch(scaler_type)
	{
		case TIMER0_STOP:
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case TIMER0_NO_PRESCALER:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case TIMER0_PRESCALER_8:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case TIMER0_PRESCALER_64:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		case TIMER0_PRESCALER_256:
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		case TIMER0_PRESCALER_1024:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		case TIMER0_EXTERNAL_FALLING:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		case TIMER0_EXTERNAL_RISING:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		default:
		break;
	}
}


u8   Timer0_Read_CounterReg(void)
{
	u8 value =TCNT0;
	return value;
}


void Timer0_OV_InterruptEnable()
{
	SET_BIT(TIMSK,TOIE0);
}

void Timer0_OV_InterruptDisable()
{
	CLEAR_BIT(TIMSK,TOIE0);
}

void Timer0_OC_InterruptEnable()
{
	SET_BIT(TIMSK,OCIE0);
}

void Timer0_OC_InterruptDisable()
{
	CLEAR_BIT(TIMSK,OCIE0);
}

// void Timer0_OVF_SetCallBack(void(*LocalPtr)(void))
// {
// 	Timer0_OVF_Fptr=LocalPtr;
// }
// 
// ISR(TIMER0_OVF_vect)
// {
// 	if (Timer0_OVF_Fptr != NULLPTR)
// 	{
// 		Timer0_OVF_Fptr();
// 	}
// }


//****************************************Timer2************************************************************//

void Timer2_Initilization(Timer_mode timer_mode,Timer2_prescaler_type scaler_type,OC_MODE oc_mode,Timer2_asynchronous_mode as_mode)
{
	Timer2_Update_Timer_Mode(timer_mode);
	Timer2_Update_OC_Mode(oc_mode);
	Timer2_Update_Prescaler_Type(scaler_type);
}

void Timer2_Update_CounterReg(u8 value)
{
	TCNT2=value;
}

void Timer2_Update_CompareReg(u8 value)
{
	OCR2=value;
}

void Timer2_Update_AS_mode(Timer2_asynchronous_mode as_mode)
{
	switch(as_mode)
	{
		case IO_CLOCK:
		CLEAR_BIT(ASSR,3);
		break;
		case CRYSTAL_OSCILLATOR:
		SET_BIT(ASSR,3);
		break;
		default:
		break;
	}
	
}

void Timer2_Update_Timer_Mode(Timer_mode timer_mode)
{
	switch(timer_mode)
	{
		case NORMAL:
		CLEAR_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		break;
		case PHASE_CORRECT:
		SET_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		break;
		case CTC:
		CLEAR_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
		case FAST_PWM:
		SET_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
		default:
		break;
	}
}

void Timer2_Update_OC_Mode(OC_MODE oc_mode)
{
	switch(oc_mode)
	{
		case DISCONNECTED:
		CLEAR_BIT(TCCR2,COM20);
		CLEAR_BIT(TCCR2,COM21);
		break;
		case TOGGLE:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_7,DIO_OUTPUT);
		SET_BIT(TCCR2,COM20);
		CLEAR_BIT(TCCR2,COM21);
		break;
		case CLEAR:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_7,DIO_OUTPUT);
		CLEAR_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
		break;
		case SET:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_7,DIO_OUTPUT);
		SET_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
		break;
		default:
		break;
	}
}

void Timer2_Update_Prescaler_Type(Timer2_prescaler_type scaler_type)
{
	switch(scaler_type)
	{
		case TIMER2_STOP:
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
		case TIMER2_NO_PRESCALER:
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
		case TIMER2_PRESCALER_8:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
		case TIMER2_PRESCALER_32:
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
		case TIMER2_PRESCALER_64:
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
		case TIMER2_PRESCALER_128:
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
		case TIMER2_PRESCALER_256:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
		case TIMER2_PRESCALER_1024:
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
		default:
		break;
	}
}

void Timer2_OV_InterruptEnable()
{
	SET_BIT(TIMSK,TOIE2);
}

void Timer2_OV_InterruptDisable()
{
	CLEAR_BIT(TIMSK,TOIE2);
}

void Timer2_OC_InterruptEnable()
{
	SET_BIT(TIMSK,OCIE2);
}

void Timer2_OC_InterruptDisable()
{
	CLEAR_BIT(TIMSK,OCIE2);
}



//****************************************Timer1************************************************************//


void Timer1_Initilization(Timer1_mode timer_mode,Timer1_prescaler_type scaler_type,OC_MODE oca_mode,OC_MODE ocb_mode)
{
	Timer1_Update_Timer_Mode(timer_mode);
	Timer1_Update_OCA_Mode(oca_mode);
	Timer1_Update_OCB_Mode(ocb_mode);
	Timer1_Update_Prescaler_Type(scaler_type);
}


void Timer1_Update_Timer_Mode(Timer1_mode timer_mode)
{
	switch(timer_mode)
	{
		case TIMER1_NORMAL:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_PHASE_CORRECT_8BIT:
		SET_BIT  (TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_PHASE_CORRECT_9BIT:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT  (TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_PHASE_CORRECT_10BIT:
		SET_BIT  (TCCR1A,WGM10);
		SET_BIT  (TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_OCR1A:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT  (TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_PWM_8BIT:
		SET_BIT  (TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT  (TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_PWM_9BIT:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT  (TCCR1A,WGM11);
		SET_BIT  (TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_PWM_10BIT:
		SET_BIT  (TCCR1A,WGM10);
		SET_BIT  (TCCR1A,WGM11);
		SET_BIT  (TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_PHASE_CORRECT_ICR1_TOP_UPDATE_BOTTOM:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT  (TCCR1B,WGM13);
		break;
		case TIMER1_PHASE_CORRECT_OCR1A_TOP_UPDATE_BOTTOM:
		SET_BIT  (TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT  (TCCR1B,WGM13);
		break;
		case TIMER1_PHASE_CORRECT_ICR1_TOP_UPDATE_TOP:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT  (TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT  (TCCR1B,WGM13);
		break;
		case TIMER1_PHASE_CORRECT_OCR1A_TOP_UPDATE_TOP:
		SET_BIT  (TCCR1A,WGM10);
		SET_BIT  (TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT  (TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR1:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT  (TCCR1B,WGM12);
		SET_BIT  (TCCR1B,WGM13);
		break;
		case TIMER1_PWM_ICR1:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT  (TCCR1A,WGM11);
		SET_BIT  (TCCR1B,WGM12);
		SET_BIT  (TCCR1B,WGM13);
		break;
		case TIMER1_PWM_OCR1A:
		SET_BIT  (TCCR1A,WGM10);
		SET_BIT  (TCCR1A,WGM11);
		SET_BIT  (TCCR1B,WGM12);
		SET_BIT  (TCCR1B,WGM13);
		break;
		default:
		break;
	}
}


void Timer1_Update_CounterReg(u16 value)
{
	TCNT1=value;
}


void Timer1_Update_CompareReg_A(u16 value)
{
	OCR1A=value;
}


void Timer1_Update_CompareReg_B(u16 value)
{
	OCR1B=value;
}


void Timer1_Update_Prescaler_Type(Timer1_prescaler_type scaler_type)
{
	switch(scaler_type)
	{
		case TIMER1_STOP:
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_NO_PRESCALER:
		SET_BIT  (TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_PRESCALER_8:
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT  (TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_PRESCALER_64:
		SET_BIT  (TCCR1B,CS10);
		SET_BIT  (TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_PRESCALER_256:
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT  (TCCR1B,CS12);
		break;
		case TIMER1_PRESCALER_1024:
		SET_BIT  (TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT  (TCCR1B,CS12);
		break;
		case TIMER1_EXTERNAL_FALLING:
		SET_BIT  (TCCR1B,CS10);
		SET_BIT  (TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_EXTERNAL_RISING:
		SET_BIT  (TCCR1B,CS10);
		SET_BIT  (TCCR1B,CS11);
		SET_BIT  (TCCR1B,CS12);
		break;
		default:
		break;
	}
}


void Timer1_Update_OCA_Mode(OC_MODE oca_mode)
{
	switch(oca_mode)
	{
		case DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case TOGGLE:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_5,DIO_OUTPUT);
		SET_BIT  (TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case CLEAR:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_5,DIO_OUTPUT);
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT  (TCCR1A,COM1A1);
		break;
		case SET:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_5,DIO_OUTPUT);
		SET_BIT  (TCCR1A,COM1A0);
		SET_BIT  (TCCR1A,COM1A1);
		break;
		default:
		break;
	}
}


void Timer1_Update_OCB_Mode(OC_MODE ocb_mode)
{
	switch(ocb_mode)
	{
		case DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case TOGGLE:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_4,DIO_OUTPUT);
		SET_BIT  (TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case CLEAR:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_4,DIO_OUTPUT);
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT  (TCCR1A,COM1B1);
		break;
		case SET:
		DIO_SetPinDirection(DIO_PORT_D,DIO_PIN_4,DIO_OUTPUT);
		SET_BIT  (TCCR1A,COM1B0);
		SET_BIT  (TCCR1A,COM1B1);
		break;
		default:
		break;
	}
}


void Timer1_Update_OCR1A(u16 value)
{
	OCR1A=value;
}


void Timer1_Update_OCR1B(u16 value)
{
	OCR1B=value;
}


void Timer1_OV_InterruptEnable()
{
	SET_BIT(TIMSK,TOIE1);
}


void Timer1_OV_InterruptDisable()
{
	CLEAR_BIT(TIMSK,TOIE1);
}


void Timer1_OCA_InterruptEnable()
{
	SET_BIT(TIMSK,OCIE1A);
}


void Timer1_OCA_InterruptDisable()
{
	CLEAR_BIT(TIMSK,OCIE1A);
}


void Timer1_OCB_InterruptEnable()
{
	SET_BIT(TIMSK,OCIE1B);
}


void Timer1_OCB_InterruptDisable()
{
	CLEAR_BIT(TIMSK,OCIE1B);
}


void Timer1_IC_InterruptEnable()
{
	SET_BIT(TIMSK,TICIE1);
}


void Timer1_IC_InterruptDisable()
{
	CLEAR_BIT(TIMSK,TICIE1);
}

void Timer1_IC_EdgeSelect(ICU_Edge_type edge)
{
	switch(edge)
	{
		case RISING:
		SET_BIT  (TCCR1B,ICES1);
		break;
		case FALLING:
		CLEAR_BIT(TCCR1B,ICES1);
		break;
		default:
		break;
	}
}

void Timer1_Update_ICR1(u16 value)
{
	ICR1 = value;
}

void Timer1_IC_NoiseCancler_Enable()
{
	SET_BIT(TCCR1B,ICNC1);
}
void Timer1_IC_NoiseCancler_Disable()
{
	CLEAR_BIT(TCCR1B,ICNC1);
}