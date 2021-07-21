/*
 * CLOCK_MANAGE.c
 *
 * Created: 10/4/2020 1:53:01 PM
 *  Author: ideapad510
 */ 
#include "CLOCK_MANAGE.h"
volatile unsigned char CLOCK[3]={0,0,0};
volatile unsigned char CLOCK_DIGITS[6]={0,0,0,0,0,0};	

void INCREMENT_SEC()
{
	CLOCK[2]++;
	if(CLOCK[2]==60)
	{
		CLOCK[2]=0;
		CLOCK[1]++;
		if(CLOCK[1]==60)
		{
			CLOCK[1]=0;
			CLOCK[0]++;
			if(CLOCK[0]==24)
			{
				CLOCK[0]=0;
			}
		}
	}
	
}

void APPLY_CLOCK()
{
	CLOCK_DIGITS[5]=CLOCK[2]%10;
	CLOCK_DIGITS[4]=CLOCK[2]/10;
	
	CLOCK_DIGITS[3]=CLOCK[1]%10;
	CLOCK_DIGITS[2]=CLOCK[1]/10;
	
	CLOCK_DIGITS[1]=CLOCK[0]%10;
	CLOCK_DIGITS[0]=CLOCK[0]/10;
}

void ADJUST_CLOCK(unsigned char HOUR_MIN_SEC,unsigned char NEW_NUM)
{
	if (HOUR_MIN_SEC==0)
	{
		NEW_NUM%=24;
	}
	else
	{
		NEW_NUM%=60;
	}
	CLOCK[HOUR_MIN_SEC]=NEW_NUM;
}

void MIN_INCREMENT()
{
	ADJUST_CLOCK(1,CLOCK[1]+1);
}
void SEC_INCREMENT()
{
	ADJUST_CLOCK(2,CLOCK[2]+1);
}

void HOUR_INCREMENT()
{
	ADJUST_CLOCK(0,CLOCK[0]+1);
}