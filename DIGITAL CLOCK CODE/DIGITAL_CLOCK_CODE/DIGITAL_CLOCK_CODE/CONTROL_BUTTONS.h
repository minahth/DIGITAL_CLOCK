/*
 * CONTROL_BUTTONS.h
 *
 * Created: 10/5/2020 10:13:12 AM
 *  Author: ideapad510
 */ 


#ifndef CONTROL_BUTTONS_H_
#define CONTROL_BUTTONS_H_
#include "microconfigrations.h"
#include "CONNECTIONS.h"


typedef enum{WORKING,
			SETTING
				}APP_STATES_DT;



void CONTROL_BUTTONS_INTILIZE();
unsigned char CONTROL_CAPTURE();





#endif /* CONTROL_BUTTONS_H_ */