/*
 * MEXTI_Program.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Toka
 */


/*
 * Set Sense Control
 * Enable PIE
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../MDIO/MDIO_Interface.h"
#include"../MGIE/MGIE.Interface.h"
#include"MEXTI_Config.h"
#include"MEXTI_Interface.h"
#include"MEXTI_Private.h"

void MEXTI0_Init()
{
#if MEXTI_SENSE_CONTROL_STATE==MEXTI_LOW_LEVEL

	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif MEXTI_SENSE_CONTROL_STATE==MEXTI_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);

#elif MEXTI_SENSE_CONTROL_STATE==MEXTI_RISING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);

#elif MEXTI_SENSE_CONTROL_STATE==MEXTI_FALLING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#endif

	/*Enable Interrupt on INT0 ==> PIE of Interrupt zero*/
	SET_BIT(GICR,6);
}

void Mexti_TEST_FUN(void)
{
	//Set Port A Output
	MDIO_SetPortDirection(MDIO_PORTA,PORT_OUTPUT);
	MDIO_SetPinValue(PIN0,MDIO_PORTA,PIN_HIGH);
	MDIO_SetPinDirection(PIN2,MDIO_PORTD, PIN_INPUT);
	MDIO_SetPinValue(PIN2,MDIO_PORTD,PIN_HIGH);

	MEXTI0_Init();
	MGIE_Enable();


}



void(*INTERRUPT_CallBack)(void); //pointer to function
void INTERRUPT_Set0CallBack(void(*copy_ptr)(void))
{
	INTERRUPT_CallBack=copy_ptr;
}


//call back function
void __vector_1(void)__attribute((signal));
void __vector_1(void)
{
	INTERRUPT_CallBack();
}

