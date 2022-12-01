/*
 * LED.h
 *
 *  Created on: Nov 10, 2022
 *      Author: Toka
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_
#include"../../MCAL/MDIO/MDIO_Interface.h"

void LED_INIT(u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber);
void LED_ON(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
void LED_OFF(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
void LED_NormalDelay(void);
void YELLOW_LEDBlink(void);
void Yellow_cars_led(void);
#endif /* HAL_LED_LED_H_ */
