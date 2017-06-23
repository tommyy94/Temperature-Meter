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
*		main.c
*
* 2. DESCRIPTION
*		Main source
*
***************************************************************************/

/***************************************************************************
*   HEADER FILES
***************************************************************************/
#include "main.h"

/***************************************************************************
*	MAIN PROGRAM
***************************************************************************/
int main(void)
{
	struct Sensors Temp;

	adc_init(PINC0);
	lcd_init();

	while(1)
	{
		Temp.celsius = sensor_read(Temp, TEMP_SENSOR)/2;
		Temp.fahrenheit = Temp.celsius * (9/5) + 32;

		lcd_send_string(0, 0, "Celsius: ");
		lcd_send_int(strlen("Celsius: "), 0, Temp.celsius, 2);
		lcd_send_string(0, 1, "Fahrenheit: ");
		lcd_send_int(strlen("Fahrenheit: "), 1, Temp.fahrenheit, 2);

		_delay_ms(DELAY);
	}
	return 0;
} /* end of main */
