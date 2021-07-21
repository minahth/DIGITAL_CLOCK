/*
 * timer0.h
 *
 * Created: 26/10/2018 10:52:34 ص
 *  Author: ideapad510
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "microconfigrations.h"




 /* WGM01 , WGM00 ,BITS USED TO DETERMINED THE MODE OF TIMER0*/


typedef enum { T0_TIMER_OFF=0x00,
	           T0_TIMER_1=0x01,
			   T0_TIMER_8=0x02,
			   T0_TIMER_64=0x03,
			   T0_TIMER_256=0x04,
			   T0_TIMER_1024=0x05,
			   T0_TIMER_T0_SOURCE_FALLING=0x06,
			   T0_TIMER_T0_SOURCE_RISING=0x07,
	
	          }T0_clock;
			  
			  /*OCIE0 , TOIE0 INTIMSK*/
			  typedef enum {INT_DISABLE,
				            OVER_FLOW_INT_ENABLE,
           				    }TIMER0_INT;
			  
			   
			   void TIMER0_ENABLE(T0_clock fre,TIMER0_INT intmode);
			   void TIMER0_DISABLE();
			   void TIMER0_COUNT_RESET();
#endif /* TIMER0_H_ */