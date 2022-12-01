/*
 * MGIE_Program.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Toka
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"MGIE_Private.h"
#include"MGIE.Interface.h"

/*Functions Prototypes*/
void MGIE_Enable(void)
{
	SET_BIT(SREG,7);
}

void MGIE_Disable(void)
{
	CLR_BIT(SREG,7);
}
