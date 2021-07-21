/*
 * DIGITAL_CLOCK_CODE.c
 *
 * Created: 10/4/2020 1:00:35 PM
 *  Author: ideapad510
 */ 

#include "timer0.h"
#include "TIMER1.h"
#include "TIMER2.h"
#include "DIGITAL_7_SEG.h"
#include "CLOCK_MANAGE.h"
#include "CONTROL_BUTTONS.h"
#include <avr/interrupt.h>
#include <avr/io.h>
extern volatile unsigned char TIMER0_COUNTER_FOR_SHOWING;
volatile unsigned char i=0;
extern volatile unsigned char CLOCK[3];
extern volatile unsigned char CLOCK_DIGITS[6];
ISR(TIMER0_OVF_vect)
{
	TIMER0_COUNTER_FOR_SHOWING++;
	if (TIMER0_COUNTER_FOR_SHOWING==255)
	{
		TIMER0_COUNTER_FOR_SHOWING=0;
		TIMER0_DISABLE();
		DIG_STOP_SHOW_SEGMENTS();	
	}
	
}
ISR(TIMER1_COMPA_vect)
{
	INCREMENT_SEC();
	APPLY_CLOCK();
	
}
ISR(TIMER2_OVF_vect)
{
	 APPLY_DIGIT(i,CLOCK_DIGITS[i],1);
	 i++;
	 i%=6;
}

int main(void)
{
	 /*TIMER0_ENABLE(T0_TIMER_1024,OVER_FLOW_INT_ENABLE);*/
	 TIMER1_ENABLE(T1_OCA1_DISCONNECT,T1_OCB1_DISCONNECT,T1_CTC_OCR1A,T1_TIMER_1024,15624,0,DISABLE_TIMER1_INT,DISABLE_TIMER1_INT,ENABLE_TIMER1_INT,DISABLE_TIMER1_INT);
	global_interupt_enable();
	CONTROL_BUTTONS_INTILIZE();
	DIG_INTILIZE();
	/*DIG_START_SHOW_SEGMENTS();*/
    while(1)
    {
		 CONTROL_CAPTURE();
        
    }
}