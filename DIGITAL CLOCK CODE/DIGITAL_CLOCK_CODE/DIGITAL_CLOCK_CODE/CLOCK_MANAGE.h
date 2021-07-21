/*
 * CLOCK_MANAGE.h
 *
 * Created: 10/4/2020 1:53:10 PM
 *  Author: ideapad510
 */ 


#ifndef CLOCK_MANAGE_H_
#define CLOCK_MANAGE_H_
#include "microconfigrations.h"

void INCREMENT_SEC();
void APPLY_CLOCK();

void ADJUST_CLOCK(unsigned char HOUR_MIN_SEC,unsigned char NEW_NUM);
void MIN_INCREMENT();
void SEC_INCREMENT();
void HOUR_INCREMENT();
#endif /* CLOCK_MANAGE_H_ */