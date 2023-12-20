/*
 * Button_Config.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Lenovo
 */
#include "TM1638.h"
#include "TM1638_platform.h"

TM1638_Handler_t Handler;

void bar_led_status(void)
{

	TM1638_SetSingleDigit_HEX(&Handler, 6, 2);

}

void UltraSelect(void)
{
	TM1638_SetSingleDigit_HEX(&Handler, 6, 2);


}

void MotorSelect(void)
{

}

void StartMachine(void)
{

}

void ReverseForward(void)
{

}
