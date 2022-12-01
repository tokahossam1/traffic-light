/*
 * MEXTI_Interface.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Toka
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

/*Function Prototype*/
void INTERRUPT_Set0CallBack(void(*copy_ptr)(void));
void MEXTI0_Init();
void Mexti_TEST_FUN(void);

//void MEXTI_SetSenseControl(u8 Copy_u8Interrupt_ID, u8 Copy_u8Mode)


#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
