/***************************************************************************
*
*   This file is part of WeatherStation.
*
*   WeatherStation is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   WeatherStation is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with LCD_library. If not, see <http://www.gnu.org/licenses/>.
*
*	Copyright (C) 2017 by tommyy94
*
***************************************************************************/

/***************************************************************************
*
* 1. NAME
*		main.h
*
* 2. DESCRIPTION
*		Main header
*
***************************************************************************/

#ifndef MAIN_H_
#define MAIN_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/***************************************************************************
*   HEADER FILES
***************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <string.h>
#include "sensors.h"
#include "adc_lib/adc.h"
#include "lcd_lib/lcd.h"

/***************************************************************************
*   GLOBAL VARIABLES
***************************************************************************/
/* Control flags */
#ifndef DEBUG
#define DEBUG
#endif

/* Global constants */
#define SAMPLES 10
#define DELAY 100

/* Global variables */

/* Global structures */

/****************************************************************************
*   FUNCTION PROTOTYPES
****************************************************************************/

#endif /* MAIN_H_ */
