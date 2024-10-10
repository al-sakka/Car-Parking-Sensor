/******************************************************************************
*
* Module: KEYPAD
*
* File Name: keypad.c
*
* Description: Source file for the Keypad driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include "led.h"
#include "../../MCAL/GPIO/gpio.h"
#include <util/delay.h>
#include "../../Utils/common_macros.h"
#include "../Buzzer/buzzer.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

/*
 * Initializes all Leds (red, green, blue) pins direction.
 * and Turn off all the Leds
 */
void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GRN_PORT_ID, LED_GRN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLU_PORT_ID, LED_BLU_PIN_ID, PIN_OUTPUT);

	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_OFF);
	GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, LED_OFF);
	GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, LED_OFF);
}

/*
 * Turns on the specified LED.
 */
void LED_on(LED_ID id)
{
	switch(id)
	{
		case LED_RED:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_ON);
			break;
		case LED_GRN:
			GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, LED_ON);
			break;
		case LED_BLU:
			GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, LED_ON);
			break;
	}
}

/*
 * Turns off the specified LED.
 */
void LED_off(LED_ID id)
{
	switch(id)
	{
		case LED_RED:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_OFF);
			break;
		case LED_GRN:
			GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, LED_OFF);
			break;
		case LED_BLU:
			GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, LED_OFF);
			break;
	}
}

/*
 * Flash LEDs in STOP mode
 */
static void LED_flash(void)
{
	LED_on(LED_RED);
	LED_on(LED_GRN);
	LED_on(LED_BLU);
	Buzzer_on();
	_delay_ms(FLASHING_TIME);

	LED_off(LED_RED);
	LED_off(LED_GRN);
	LED_off(LED_BLU);
	Buzzer_off();
	_delay_ms(FLASHING_TIME);
}

/*
 * Distance <= 5 cm: All LEDs are flashing (Red, Green, Blue), Buzzer sounds, LCD shows "Stop."
 * 6  cm <= Distance <= 10 cm: All LEDs ON (Red, Green, Blue), No buzzer.
 * 11 cm <= Distance <= 15 cm: Red and Green LEDs ON, Blue LED OFF.
 * 16 cm <= Distance <= 20 cm: Only Red LED ON, others OFF.
 * Distance > 20 cm: All LEDs OFF, Buzzer OFF.
 */
void LED_config(uint16 a_distance)
{
	if (a_distance <= 5)
	{
		LED_flash();
	}
	else if ((a_distance >= 6) && (a_distance <= 10))
	{
		LED_on(LED_RED);
		LED_on(LED_GRN);
		LED_on(LED_BLU);
	}
	else if ((a_distance >= 11) && (a_distance <= 15))
	{
		LED_on(LED_RED);
		LED_on(LED_GRN);
		LED_off(LED_BLU);
	}
	else if	((a_distance >= 16) && (a_distance <= 20))
	{
		LED_on(LED_RED);
		LED_off(LED_GRN);
		LED_off(LED_BLU);
	}
	else	/* Distance > 20 cm */
	{
		LED_off(LED_RED);
		LED_off(LED_GRN);
		LED_off(LED_BLU);
	}
}
