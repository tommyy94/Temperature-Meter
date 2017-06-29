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
*       sensor.c
*
* 2. DESCRIPTION
*       Reads sensor values and calculates them.
*
******************************************************************************/

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include "sensor.h"

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/

/******************************************************************************
*   FUNCTION: sensor_read                                                     *
***************************************************************************//**
@brief Read adc values and compute corresponding temperature values.
@param Pointer to struct sensor
******************************************************************************/
void sensor_read(struct sensor *temperature)
{
    temperature->celsius = ((adc_read(PINC0) * 5 / 1024.0) - 0.5) * 100;
    temperature->fahrenheit = temperature->celsius * 9 / 5 + 32;
    /**
     * @todo figure way to add decimal without floating point
     */
    return;
}
