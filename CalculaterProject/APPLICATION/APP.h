/*
 * APP.h
 *
 * Created: 10/21/2022 7:40:45 PM
 *  Author: Mohamed Nagy
 */ 

#ifndef _APP_H
#define _APP_H

void appStart();
void calculatorMode();
void blinkingLedMode();

#include "../MCAL/DIO/DIO.h"
#include "../ECUL/LED/LED.h"
#include "../MCAL/TIMER_0/TIMER_0.h"
#include "../MCAL/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.h"
#include "../ECUL/LCD/LCD.h"
#include "../ECUL/KEYPAD/KEYPAD.h"
#include "../SERVICES/UART_SERVICES/UART_SERVICES.h"

#endif