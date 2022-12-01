/*
 * MTIMER_Program.c
 *
 *  Created on: Nov 9, 2022
 *      Author: Toka
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"MTIMER_Config.h"
#include"MTIMER_Private.h"
#include"../MDIO/MDIO_Interface.h"
/**
 * Init:
 * 1-SetMode of Timer
 * 2-Set OC0 Mode
 * 3-Set Interrupt State
 * 4-Set Prescalar
 */

void MTIMER0_Init()
{
	//SetMode of Timer
#if TIMER0_MODE==TIMER_NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//Set Normal Mode interrupt
	#if TIMER0_NORMAL_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_DISABLED
		CLR_BIT(TIMSK,0);
	#elif TIMER0_NORMAL_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_ENABLED
		SET_BIT(TIMSK,0);
	#endif

#elif TIMER0_MODE==TIMER_CTC_MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//Set CTC Mode interrupt
	#if TIMER0_CTC_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_DISABLED
		CLR_BIT(TIMSK,1);
	#elif TIMER0_CTC_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_ENABLED
		SET_BIT(TIMSK,1);
	#endif

#else
#error "Wrong Mode chosen"
#endif


//Set OC0 Mode
#if TIMER0_OC0_MODE==OC0_PIN_DISCONNECTED
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
#elif TIMER0_OC0_MODE==OC0_PIN_TOGGLE
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
#elif TIMER0_OC0_MODE==OC0_PIN_CLEARED
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIMER0_OC0_MODE==OC0_PIN_SET
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif

//SET PRESCALAR
#if TIMER0_CLOCK_SOURCE==NO_CLOCK
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==SYSTEM_CLOCK
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==EXTERNAL_CLOCK_FALLING_EDGE
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==EXTERNAL_CLOCK_RISING_EDGE
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#endif

}

void MTIMER0_SetPreload(u8 Copy_u8Preload)
{
	TCCR0=Copy_u8Preload;

}

void MTIMER0_SetCTC(u8 Copy_u8OCR)
{
	OCR0=Copy_u8OCR;
}

void delay_1sec()
{
u8 counter;
MTIMER0_Init();
while(counter<61)
{
while((TIFR &(1<<0))==0);
SET_BIT(TIFR,0);
counter++;
}
counter=0;
TCCR0=0;
}

void timer_test(void)
{
	MTIMER0_Init();
			MGIE_Enable();

			/*Set Direction pins*/
			MDIO_SetPinDirection(PIN0,MDIO_PORTA,PIN_OUTPUT);

}

void(*TIMER0_CallBack)(void); //pointer to function
void TIMER0_Set0CallBack(void(*copy_ptr)(void))
{
	TIMER0_CallBack=copy_ptr;
}

//call back function
void __vector_11(void)__attribute((signal));
void __vector_11(void)
{
TIMER0_CallBack();
}
