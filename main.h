/******************************************************************************
*
* 1. NAME
*       main.h
*
* 2. DESCRIPTION
*
*
******************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "sensors.h"
#include "lcd_lib/lcd.h"

/******************************************************************************
*   GLOBAL VARIABLES                                                          *
******************************************************************************/
/* Control flags */

/* Global constants */
#define DELAY 10
#define DIGIT_POSITION 12

#define FIRST_ROW 0
#define SECOND_ROW 1
#define THIRD_ROW 2
#define FOURTH_ROW 3

#define FIRST_COLUMN 0
#define SECOND_COLUMN 1
#define THIRD_COLUMN 2
#define FOURTH_COLUMN 3

/* Global variables */

/* Global structures */

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/

#endif /* MAIN_H_ */
