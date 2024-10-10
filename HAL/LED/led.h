/******************************************************************************
*
* Module: LED
*
* File Name: led.h
*
* Description: Header file for the LED driver
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "../../Utils/std_types.h"

/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/

#define LED_RED_PORT_ID		(PORTC_ID)
#define LED_RED_PIN_ID		(PIN0_ID)

#define LED_GRN_PORT_ID		(PORTC_ID)
#define LED_GRN_PIN_ID		(PIN1_ID)

#define LED_BLU_PORT_ID		(PORTC_ID)
#define LED_BLU_PIN_ID		(PIN2_ID)

#define LED_ON				(LOGIC_HIGH)
#define LED_OFF				(LOGIC_LOW)

typedef enum
{
	LED_RED,	/* 0 */
	LED_GRN,	/* 1 */
	LED_BLU,	/* 2 */
	LED_NUM		/* # of LEDs */
} LED_ID;

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*
 * Initializes all Leds (red, green, blue) pins direction.
 * and Turn off all the Leds
 */
void LEDS_init(void);

/*
 * Turns on the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Turns off the specified LED.
 */
void LED_off(LED_ID id);

/*
 * Configure LEDs based on the LDR readings:
 * Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
 * Intensity 16–50%: Red and Green LEDs turn ON.
 * Intensity 51–70%: Only the Red LED turns ON.
 * Intensity > 70%: All LEDs are turned OFF.
 */
void LED_config(uint16 a_ldr);

#endif /* LED_H_ */
