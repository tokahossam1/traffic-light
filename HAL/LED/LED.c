/*
 * LED.c
 *
 *  Created on: Nov 10, 2022
 *      Author: Toka
 */


#include"../../LIB/STD_TYPES.h"
#include"LED.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MGIE/MGIE.Interface.h"
#include"../../MCAL/MTIMER/MTIMER_Interface.h"
#include"../../MCAL/MTIMER/MTIMER_Private.h"
#include<util/delay.h>



void LED_INIT(u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber)
{
	MDIO_SetPinDirection(Copy_u8PinNumber,Copy_u8PortNumber, PIN_OUTPUT);
}


void LED_ON(u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber)
{
	MDIO_SetPinValue(Copy_u8PinNumber,Copy_u8PortNumber, PIN_HIGH);
}

void LED_OFF(u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber)
{
	MDIO_SetPinValue(Copy_u8PinNumber,Copy_u8PortNumber, PIN_LOW);
}

void LED_NormalDelay(void)
{
	MTIMER0_Init();
	MGIE_Enable();

}

void YELLOW_LEDBlink(void)
{

	MDIO_TogglePin(PIN2,MDIO_PORTA);
	MDIO_TogglePin(PIN2,MDIO_PORTB);
	delay_1sec();

}

void Yellow_cars_led(void)
{
	MDIO_TogglePin(PIN2,MDIO_PORTA);
	delay_1sec();
}
