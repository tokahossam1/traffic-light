/*
 * main.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Toka
 */
#define F_CPU 16000000
#include <util/delay.h>
#include"APPLICATION/APP.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include"MCAL/MEXTI/MEXTI_Interface.h"
//fun for testing exti
/*
void fun(void){

	MDIO_TogglePin(PIN0,MDIO_PORTA);
}
 */
//fun for testing timer driver
/*
void APP_Overflow()
{
	u8 static OverflowCounter=0;

	if(OverflowCounter==100)
	{
		MDIO_TogglePin(PIN0,MDIO_PORTA);
		OverflowCounter=0;
	}
	OverflowCounter++;

}
*/

int main()
{


	APP_Start();



	//for testing drivers
	//to test dio driver uncomment this
	//MDIO_TEST_FUN();

	//to test EXTI AND GIE uncomment this
	/*
	Mexti_TEST_FUN();
	INTERRUPT_Set0CallBack(fun);
	 */

	//to test TIMER driver uncomment this
	/* timer_test();
		TIMER0_Set0CallBack(APP_Overflow);
	 */
	while(1){}
	return 0;
}


