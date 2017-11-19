/*******************************************************************************
*
* 1. NAME
*       main.h
*
* 2. DESCRIPTION
*       - ATmega328P
*
*******************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

#ifndef F_CPU
#define F_CPU 8000000UL
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
#define DEGREE_SIGN "\xB2"

/* positions for sending string to LCD */
#define FIRST_ROW 0
#define SECOND_ROW 1
#define THIRD_ROW 2
#define FOURTH_ROW 3

#define FIRST_COLUMN 0
#define SECOND_COLUMN 1
#define THIRD_COLUMN 2
#define FOURTH_COLUMN 3
#define FIFTH_COLUMN 4
#define SIXTH_COLUMN 5
#define SEVENTH_COLUMN 6
#define EIGHT_COLUMN 7
#define NINTH_COLUMN 8
#define TENTH_COLUMN 9
#define TENTH_COLUMN 9
#define ELEVENTH_COLUMN 10
#define TWELFTH_COLUMN 11
#define THIRTEENTH_COLUMN 12
#define FOURTEENTH_COLUMN 13
#define FIFTEENTH_COLUMN 14
#define SIXTEENTH_COLUMN 15

/*******************************************************************************
*   MACROS                                                                     *
*****************************************************************************///

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

#endif /* MAIN_H_ */
