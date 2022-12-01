/*
 * APP.c
 *
 *  Created on: Nov 10, 2022
 *      Author: Toka
 */
#define F_CPU 16000000
#include"../LIB/STD_TYPES.h"
#include"../HAL/LED/LED.h"
#include"../HAL/BUTTON/BUTTON.h"

u8 static state=0;
u16 static counter=0;
u8 static flag;
void FUNC0 (void)
{

	++counter;
	if((counter==10)&&(state==0))
	{
		LED_ON(MDIO_PORTA,PIN0);
		LED_OFF(MDIO_PORTA,PIN1);
		LED_OFF(MDIO_PORTA,PIN2);

		LED_OFF(MDIO_PORTB,PIN0);
		LED_ON(MDIO_PORTB,PIN1);
		LED_OFF(MDIO_PORTB,PIN2);
		counter=0;
		flag=0;
		state++;
	}
	else if((counter==300)&&(state==1))
	{
		LED_OFF(MDIO_PORTA,PIN0);
		LED_OFF(MDIO_PORTA,PIN1);

		LED_OFF(MDIO_PORTB,PIN0);
		LED_ON(MDIO_PORTB,PIN1);
	    Yellow_cars_led();
	    Yellow_cars_led();
	    Yellow_cars_led();
	    Yellow_cars_led();
	    Yellow_cars_led();
		counter=0;
		flag=1;
		state++;
	}
	else if((counter==10)&&(state==2))
	{
		counter=0;

		LED_OFF(MDIO_PORTA,PIN0);
		LED_ON(MDIO_PORTA,PIN1);
		LED_OFF(MDIO_PORTA,PIN2);

		LED_ON(MDIO_PORTB,PIN0);
		LED_OFF(MDIO_PORTB,PIN1);
		LED_OFF(MDIO_PORTB,PIN2);
		flag=2;
		state++;
	}
	else if((counter==300)&&(state==3))
	{
		LED_OFF(MDIO_PORTA,PIN0);
		LED_OFF(MDIO_PORTA,PIN1);

		LED_OFF(MDIO_PORTB,PIN0);
		LED_OFF(MDIO_PORTB,PIN1);
		YELLOW_LEDBlink();
		YELLOW_LEDBlink();
		YELLOW_LEDBlink();
		YELLOW_LEDBlink();
		YELLOW_LEDBlink();
		counter=0;
		flag=3;
		state=0;
	}

}

void Pedestrian_Mode(void)
{
	if((flag==0)||(flag==1)||(flag==3))
	{
	counter=299;
		state=3;
		FUNC0();
		counter=9;
		state=2;
		FUNC0();
	}

}


void APP_Start(void)
{
	while(1)
	{
		Button_init();

		LED_NormalDelay();
		Button_Interrupt();

		LED_INIT(MDIO_PORTA ,PIN0);
		LED_INIT(MDIO_PORTA ,PIN1);
		LED_INIT(MDIO_PORTA ,PIN2);
		LED_INIT(MDIO_PORTB ,PIN0);
		LED_INIT(MDIO_PORTB ,PIN1);
		LED_INIT(MDIO_PORTB ,PIN2);


		TIMER0_Set0CallBack(FUNC0);
		INTERRUPT_Set0CallBack(Pedestrian_Mode);
	}
}



