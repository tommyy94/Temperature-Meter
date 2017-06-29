/******************************************************************************
*                                                                             *
*   This file is part of TemperatureMeter.                                    *
*                                                                             *
*   TemperatureMeter is free software: you can redistribute it and/or         *
*   modify it under the terms of the GNU General Public License as            *
*   published by the Free Software Foundation, either version 3 of the        *
*   License, or (at your option) any later version.                           *
*                                                                             *
*   TemperatureMeter is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of            *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
*   GNU General Public License for more details.                              *
*                                                                             *
*   You should have received a copy of the GNU General Public License along   *
*   with TemperatureMeter If not, see <http://www.gnu.org/licenses/>.         *
*                                                                             *
*   Copyright (C) 2017 by tommyy94                                            *
*                                                                             *
******************************************************************************/

/******************************************************************************
*
* 1. NAME
*       sensor
*
* 2. DESCRIPTION
*
*
******************************************************************************/
#ifndef SENSOR_H_
#define SENSOR_H_

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include <stdint.h>
#include "adc_lib/adc.h"

/******************************************************************************
*   GLOBAL VARIABLES                                                          *
******************************************************************************/
/* Control flags */

/* Global constants */

/* Global variables */

/* Global structures */
struct sensor
{
    int8_t celsius;
    int8_t fahrenheit;
};

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/
void sensor_read(struct sensor *temperature);

#endif /* SENSOR_H_ */
