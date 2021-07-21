/*
 * DIGITAL_7_SEG.c
 *
 * Created: 10/4/2020 1:44:51 PM
 *  Author: ideapad510
 */ 
#include "DIGITAL_7_SEG.h"

void DIG_INTILIZE()
{
	*PORT7SEG_DDR_ADDRESS=0B01111111;
	*PORT7SEGUNITS_DDR_ADDRESS=0B00111111;
}

void DIGITS_DISABLE()
{
	*PORT7SEG_OUT_ADDRESS&=0B10000000;
	*PORT7SEGUNITS_OUT_ADDRESS&=0B11000000;
}

void APPLY_DIGIT(DIGIT_DT DIG,unsigned char NUM,unsigned char states)
{
	*PORT7SEGUNITS_OUT_ADDRESS&=0B11000000;
	if (states)
	{
		switch (NUM)
		{
					case 0 :*PORT7SEG_OUT_ADDRESS=_0;
					break;
					case 1 :*PORT7SEG_OUT_ADDRESS=_1;
					break;
					case 2 :*PORT7SEG_OUT_ADDRESS=_2;
					break;
					case 3 :*PORT7SEG_OUT_ADDRESS=_3;
					break;
					case 4 :*PORT7SEG_OUT_ADDRESS=_4;
					break;
					case 5 :*PORT7SEG_OUT_ADDRESS=_5;
					break;
					case 6 :*PORT7SEG_OUT_ADDRESS=_6;
					break;
					case 7 :*PORT7SEG_OUT_ADDRESS=_7;
					break;
					case 8 :*PORT7SEG_OUT_ADDRESS=_8;
					break;
					case 9 :*PORT7SEG_OUT_ADDRESS=_9;
					break;
		}
	}
	else
	{
		*PORT7SEG_OUT_ADDRESS=_blank;
	}
	setbit(*PORT7SEGUNITS_OUT_ADDRESS,DIG);
	
	
	
}

void DIG_START_SHOW_SEGMENTS()
{
	TCCR2_ACCESS=T2_NORMAL|T2_TIMER_128;
	TIMSK_ACCESS|=ENABLE_TIMER2_INT<<6;
}

void DIG_STOP_SHOW_SEGMENTS()
{
	TCCR2_ACCESS=00;
	TIMSK_ACCESS&=0x3f;
	 DIGITS_DISABLE();
}