/*
 * main.c
 *
 *  Created on: Oct 12, 2024
 *      Author: leno
 */


#include"buzzer.h"
#include"common_macros.h"
#include <avr/io.h>
#include"lcd.h"
#include"led.h"
#include"ultrasonic.h"
#include"std_types.h"


int main(){
	uint16 d=0;
	SREG |= (1<<7);
	ultrasonic_init();
	LCD_init();
	Buzzer_init();
	LEDS_init();
    LCD_moveCursor(0,0);
	 LCD_displayString("Distance=     cm");

while(1){
	 d=Ultrasonic_readDisatance();
	 if(d>20 ){
	     LCD_moveCursor(0,10);
	     LCD_intgerToString(d);
		 LCD_displayCharacter(' ');
	     LED_off(FIRST_LED);
	     LED_off(SECOND_LED);
	     LED_off(THIRD_LED);
	     Buzzer_off();
	     LCD_moveCursor(1,5);
		 LCD_displayString("    ");
	 }
	 else if(d>=16 && d<=20){
	     LCD_moveCursor(0,10);
	     LCD_intgerToString(d);
	  	 LCD_displayCharacter(' ');
	     LED_on(FIRST_LED);
	     LED_off(SECOND_LED);
	     LED_off(THIRD_LED);
	     Buzzer_off();
	     LCD_moveCursor(1,5);
		 LCD_displayString("    ");
	 }
	 else if(d>=11 && d<=15){
	     LCD_moveCursor(0,10);
	     LCD_intgerToString(d);
		 LCD_displayCharacter(' ');
	     LED_on(FIRST_LED);
	     LED_on(SECOND_LED);
	     LED_off(THIRD_LED);
	     Buzzer_off();
	     LCD_moveCursor(1,5);
		 LCD_displayString("    ");
	 }
	 else if(d>=6 && d<=10){
	     LCD_moveCursor(0,10);
	     LCD_intgerToString(d);
	  	LCD_displayCharacter(' ');
	     LED_on(FIRST_LED);
	     LED_on(SECOND_LED);
	     LED_on(THIRD_LED);
	     Buzzer_off();
	     LCD_moveCursor(1,5);
		 LCD_displayString("    ");
	 }
	 else if(d<=5){
	     LCD_moveCursor(0,10);
	     LCD_intgerToString(d);
	  	LCD_displayCharacter(' ');
	     LED_on(FIRST_LED);
	     LED_on(SECOND_LED);
	     LED_on(THIRD_LED);
	     Buzzer_on();
	     LCD_moveCursor(1,5);
		 LCD_displayString("STOP");
	 }
}
}

