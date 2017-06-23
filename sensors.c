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
*		sensors.c
*
* 2. DESCRIPTION
*
*
***************************************************************************/

/***************************************************************************
*   HEADER FILES
***************************************************************************/
#include "sensors.h"

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME: sensor_read
; DESCRIPTION:
;	Input: whole struct, sensors type
;	Output: Current temperature value
;	Used global variables:
; REMARKS when using this function: sensor_type's: TEMP_SENSOR
;**************************************************************************/
uint16_t sensor_read(struct Sensors Object, uint8_t sensor_type)
{
	switch(sensor_type)
	{
		case TEMP_SENSOR:
			Object.value = adc_read();
			break;
	}
	return Object.value;
} /* end of sensor_read */
