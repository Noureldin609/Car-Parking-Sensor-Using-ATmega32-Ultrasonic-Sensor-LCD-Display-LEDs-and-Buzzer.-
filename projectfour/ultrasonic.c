/*
 * ultrasonic.c
 *
 *  Created on: Oct 12, 2024
 *      Author: leno
 */



#include "ultrasonic.h"
#include "gpio.h"
#include <util/delay.h>
	uint8 g_edgeCount = 0;
	uint16 g_timeHigh = 0;
	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING} ;
void ultrasonic_init(void){
	ICU_init(&ICU_Configurations);
	ICU_setCallBack(Ultransonic_edgeProcessing);
	GPIO_setupPinDirection(PORTD_ID,PIN7_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTD_ID,PIN6_ID,PIN_INPUT);
}

void ultrasonic_trigger(void){
	GPIO_writePin(PORTD_ID,PIN7_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTD_ID,PIN7_ID,LOGIC_LOW);
}

uint16 Ultrasonic_readDisatance(void){
	uint16 distance;

	ultrasonic_trigger();


	 if (g_edgeCount ==2){

	g_edgeCount = 0;
 distance = ((float)(g_timeHigh /117.6))+1   ;

} return distance;
}


void Ultransonic_edgeProcessing(void){
	 g_edgeCount ++;
     if(g_edgeCount==1){
    	 ICU_clearTimerValue();
    	 ICU_setEdgeDetectionType(FALLING);
     }
     else if(g_edgeCount==2){
    	 g_timeHigh = ICU_getInputCaptureValue();
    	 ICU_setEdgeDetectionType(RAISING);
     }

}
