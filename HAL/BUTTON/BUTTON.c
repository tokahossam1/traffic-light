/*
 * BUTTON.c
 *
 *  Created on: Nov 9, 2022
 *      Author: Toka
 */

#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MGIE/MGIE.Interface.h"
#include"../../MCAL/MEXTI/MEXTI_Interface.h"
#include"../../LIB/STD_TYPES.h"
#include"BUTTON.h"
EN_Button_state Button_init(void)
{

		MDIO_SetPinDirection(PIN2,MDIO_PORTD, PIN_INPUT);
		MDIO_SetPinValue(PIN2,MDIO_PORTD,PIN_HIGH);
		if(1)
		{
			return ok;
		}else return error;

}

EN_Button_state Button_State(void)
{
	u8 PIN_READING=0;
	MDIO_ReadPin(PIN2,MDIO_PORTD,&PIN_READING);
	if(PIN_READING==1)
	{
		return Button_Pressed;
	}else{
		return Not_pressed;
	}
}

void Button_Interrupt(void)
{

	MEXTI0_Init();
	MGIE_Enable();
}
