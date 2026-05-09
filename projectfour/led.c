/*
 * led.c
 *
 *  Created on: Oct 7, 2024
 *      Author: leno
 */


#include "led.h"
#include "gpio.h"

void LEDS_init(void){
	GPIO_setupPinDirection(PORT_LEDS,PIN_LED ,PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_LEDS,PIN_LED +1,PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_LEDS,PIN_LED +2,PIN_OUTPUT);
#if(CON == POSTIVE_LOGIC)
	GPIO_writePin(PORT_LEDS, PIN_LED , LOGIC_LOW);
	GPIO_writePin(PORT_LEDS, PIN_LED +1, LOGIC_LOW);
	GPIO_writePin(PORT_LEDS, PIN_LED +2, LOGIC_LOW);
#elif(CON == NEGATIVE_LOGIC)
	GPIO_writePin(PORT_LEDS, PIN_LED  ,   LOGIC_HIGH);
	GPIO_writePin(PORT_LEDS, PIN_LED +1, LOGIC_HIGH);
	GPIO_writePin(PORT_LEDS, PIN_LED +2, LOGIC_HIGH);
#endif
}
void LED_on(LED_ID id){
#if(CON == POSTIVE_LOGIC)
	GPIO_writePin(PORT_LEDS, id, LOGIC_HIGH);
#elif(CON ==NEGATIVE_LOGIC)
	GPIO_writePin(PORT_LEDS, id, LOGIC_LOW);
#endif
}
void LED_off(LED_ID id){
#if(CON ==  POSTIVE_LOGIC)
	GPIO_writePin(PORT_LEDS, id, LOGIC_LOW);
#elif(CON == NEGATIVE_LOGIC)
	GPIO_writePin(PORT_LEDS, id, LOGIC_HIGH);
#endif
}
