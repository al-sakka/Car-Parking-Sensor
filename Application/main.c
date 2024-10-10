/******************************************************************************
*
* File Name: main.c
*
* Description: Source file for the main application
*
* Author: Abdallah El-Sakka
*
*******************************************************************************/

#include <avr/interrupt.h>
#include <util/delay.h>
#include "../Utils/std_types.h"
#include "../HAL/Ultrasonic/ultrasonic.h"
#include "../HAL/LED/led.h"
#include "../HAL/LCD/lcd.h"
#include "../HAL/Buzzer/buzzer.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

int main(void)
{
	uint16 sensor_distance = (uint16)(INIT_VALUE_UINT16);

	LCD_init();
	Ultrasonic_init();
	Buzzer_init();
	LEDS_init();
	sei();

	LCD_ShowInfo();

	while(1)
	{
		sensor_distance = Ultrasonic_readDistance();

		LCD_ShowData(sensor_distance);
		LED_config(sensor_distance);

		_delay_ms(50);

	}		/* Super Loop */
}
