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
*		sensors.h
*
* 2. DESCRIPTION
*		Sensor header
*
***************************************************************************/

#ifndef SENSORS_H_
#define SENSORS_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/***************************************************************************
*   HEADER FILES
***************************************************************************/
#include <util/delay.h>
#include <stdint.h>
#include "adc_lib/adc.h"

/***************************************************************************
*   GLOBAL VARIABLES
***************************************************************************/
/* Control flags */
#define TEMP_SENSOR 1

/* Global constants */
#define SAMPLES 10
//#ifdef TEMP_SENSOR
//sensor_read(Temp, TEMP_SENSOR)*5/10
//#define TEMP_FORMULA sensor_read(Temp, TEMP_SENSOR)/2
//#endif

/* Global variables */

/* Global structures */
struct Sensors{
	uint16_t celsius;
	uint16_t fahrenheit;
	uint16_t value;
};

/****************************************************************************
*   FUNCTION PROTOTYPES
****************************************************************************/
uint16_t sensor_read(struct Sensors, uint8_t sensor_type);

#endif /* SENSORS_H_ */
