/*
 * DIGITAL_7_SEG.h
 *
 * Created: 10/4/2020 1:44:59 PM
 *  Author: ideapad510
 */ 


#ifndef DIGITAL_7_SEG_H_
#define DIGITAL_7_SEG_H_
#include "microconfigrations.h"
#include "TIMER2.h"
#define PORT7SEG_DDR_ADDRESS PORTD_DDRA_ADDRESS
#define PORT7SEG_OUTMOD_ADDRESS PORTD_OUTMOD_ADDRESS
#define PORT7SEG_OUT_ADDRESS PORTD_OUT_ADDRESS

#define PORT7SEGUNITS_DDR_ADDRESS PORTC_DDRA_ADDRESS
#define PORT7SEGUNITS_OUTMOD_ADDRESS PORTC_OUTMOD_ADDRESS
#define PORT7SEGUNITS_OUT_ADDRESS PORTC_OUT_ADDRESS
#define PIN_H1 5
#define PIN_H0 4
#define PIN_M1 3
#define PIN_M0 2
#define PIN_S1 1 
#define PIN_S0 0


typedef enum{
				H1=PIN_H1,
				H0=PIN_H0,
				M1=PIN_M1,
				M0=PIN_M0,
				S1=PIN_S1,
				S0=PIN_S0,
				}DIGIT_DT;


#define _0 0b00111111
#define _1 0b00000110
#define _2 0b01011011
#define _3 0b01001111
#define _4 0b01100110
#define _5 0b01101101
#define _6 0b01111101
#define _7 0b00000111
#define _8 0b01111111
#define _9 0b01101111
#define _blank 0b00000000







void DIG_START_SHOW_SEGMENTS();
void DIG_STOP_SHOW_SEGMENTS();

void DIG_INTILIZE();
void APPLY_DIGIT(DIGIT_DT DIG,unsigned char NUM,unsigned char states);
void DIGITS_DISABLE();



#endif /* DIGITAL_7_SEG_H_ */