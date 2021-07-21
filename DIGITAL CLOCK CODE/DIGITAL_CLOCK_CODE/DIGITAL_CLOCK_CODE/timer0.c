/*
 * timer.c
 *
 * Created: 26/10/2018 10:52:11 ص
 *  Author: ideapad510
 */ 
#include "timer0.h"

 #define round_factor 0.5
 
 #if 1
      volatile static unsigned long long clock_carry=0;
#endif
 /*extern volatile  unsigned long long clock_carry=0;

 ISR(BADISR_vect)
 {
 ;
 
 
 }

 ISR(TIMER0_OVF_vect)
 {
 clock_carry++;
 
 
 }
 TIMER0_ENABLE(TIMER_1024,OVER_FLOW_INT_ENABLE);
 dont change TCNT0_ACCESS or clock_carry */
  void TIMER0_ENABLE(T0_clock fre ,TIMER0_INT intmode)
  {  
	  TCCR0_ACCESS&=0xf8;
	  TIMSK_ACCESS&=0xfC;
	  TCCR0_ACCESS|=fre;
	  TIMSK_ACCESS|=intmode;
	  
	  if (intmode!=INT_DISABLE)
	  {
		
		  setbit(MCU_STATE_REG_ACCESS,7);
		  
	  }
	
 }
	   
	   
	    void TIMER0_DISABLE()
		{
			  TCCR0_ACCESS&=0xf8;
		}

void TIMER0_COUNT_RESET()
{
	clock_carry=0;
	TCNT0_ACCESS=0;
}

		
		





		