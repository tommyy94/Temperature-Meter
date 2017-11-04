/*******************************************************************************
*
* 1. NAME
*       main.h
*
* 2. DESCRIPTION
*
*
*******************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "adc_lib/adc.h"
#include "sensors.h"
#include "lcd_lib/lcd.h"
#include "watchdog.h"

/*******************************************************************************
*   GLOBAL VARIABLES                                                           *
*******************************************************************************/
#define DELAY 10 /* main loop delay */
#define DIGIT_POSITION 12 /* digit position on LCD */

/* positions for sending string to LCD */
#define FIRST_ROW 0
#define SECOND_ROW 1
#define THIRD_ROW 2
#define FOURTH_ROW 3

#define FIRST_COLUMN 0
#define SECOND_COLUMN 1
#define THIRD_COLUMN 2
#define FOURTH_COLUMN 3

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

#endif /* MAIN_H_ */
