/*
 * CAPACITIVE_TOUCH.h
 *
 * Created: 10/3/2020 12:48:16 PM
 *  Author: ideapad510
 */ 


#ifndef CAPACITIVE_TOUCH_H_
#define CAPACITIVE_TOUCH_H_
#include "microconfigrations.h"

#define NUMBER_OF_SENSORS 4
typedef struct{
				volatile uint8 * PORT_OUT_ADDRESS_OUT;
				uint8 PINOUT;
				volatile uint8 * PORT_IN_ADDRESS_IN;
				volatile uint8 * PORT_DDR_ADDRESS_IN;
				volatile uint8 * PORT_OUT_ADDRESS_IN;
				uint8 PININ;
				unsigned long THRESH;
				unsigned char STATES;
				}CAPACITIVE_TOUCH_BUTTON_DATATYPE;
typedef CAPACITIVE_TOUCH_BUTTON_DATATYPE* CAPACITIVE_BUTTON_POINTER;

#define CHECK_TOUCH_BUTTON(X) (X->STATES)
				
CAPACITIVE_BUTTON_POINTER NEW_CAPACITIVE_BUTTON(volatile uint8 * NEWPORT_DDR_ADDRESS_OUT,
												volatile uint8 * NEWPORT_OUT_ADDRESS_OUT,
												volatile uint8 * NEWPORT_OUTMOD_ADDRESS_OUT,
												uint8 NEWPINOUT,
												volatile uint8 * NEWPORT_DDR_ADDRESS_IN,
												volatile uint8 * NEWPORT_IN_ADDRESS_IN,
												volatile uint8 * NEWPORT_OUT_ADDRESS_IN, 
												volatile uint8 * NEWPORT_INMOD_ADDRESS_IN,
												uint8 NEWPININ,
												unsigned long NEWTHRESH);
uint8 CHECK_ALL_CAPACITIVES();
uint8 READ_CAPACITIVE(CAPACITIVE_BUTTON_POINTER CAP);

#endif /* CAPACITIVE_TOUCH_H_ */