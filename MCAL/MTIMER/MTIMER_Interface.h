/*
 * MTIMER_Interface.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Toka
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_

/*Function Prototypes*/
void MTIMER0_Init();

void MTIMER0_SetPreload(u8 Copy_u8Preload);

void MTIMER0_SetCTC(u8 Copy_u8OCR);

void delay_1sec();

void timer_test(void);

void TIMER0_Set0CallBack(void(*copy_ptr)(void));

#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
