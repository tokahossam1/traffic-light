/*
 * BUTTON.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Toka
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_
typedef enum
{
	Button_Pressed,
	Not_pressed,
	ok,
	error

}EN_Button_state;


void Button_Interrupt(void);
EN_Button_state Button_State(void);
EN_Button_state Button_init(void);
#endif /* HAL_BUTTON_BUTTON_H_ */
