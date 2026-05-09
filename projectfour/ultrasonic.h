/*
 * ultrasonic.h
 *
 *  Created on: Oct 12, 2024
 *      Author: leno
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"
#include"icu.h"


void ultrasonic_init(void);
void ultrasonic_trigger(void);
uint16 Ultrasonic_readDisatance(void);
void Ultransonic_edgeProcessing(void);
#endif /* ULTRASONIC_H_ */
