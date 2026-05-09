/*
 * led.h
 *
 *  Created on: Oct 7, 2024
 *      Author: leno
 */

#ifndef LED_H_
#define LED_H_
#include "std_types.h"

#define PORT_LEDS    PORTC_ID
#define PIN_LED     PIN0_ID
#define CON        POSTIVE_LOGIC
#define POSTIVE_LOGIC    0
#define NEGATIVE_LOGIC    1
typedef enum
{
	FIRST_LED,SECOND_LED,THIRD_LED
}LED_ID;

void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);

#endif /* LED_H_ */
