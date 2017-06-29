/******************************************************************************
*                                                                             *
*   This file is part of TemperatureMeter.	                              *
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
*       main.c
*
* 2. DESCRIPTION
*       Main file
*
******************************************************************************/

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include "main.h"

/******************************************************************************
*   MAIN PROGRAM                                                              *
******************************************************************************/
int main(void)
{
    struct sensor temperature;
    struct sensor *const ptr_temperature = &temperature;
    int8_t *const ptr_celsius = &temperature.celsius;
    int8_t *const ptr_fahrenheit = &temperature.fahrenheit;
    
    adc_init();
    lcd_init();

    while(1)
    {
        sensor_read(ptr_temperature);
        
        lcd_send_string(0, 0, "Celsius");
        lcd_send_int(DIGIT_POSITION, 0, ptr_celsius);
        lcd_send_string(0, 1, "Fahrenheit");
        lcd_send_int(DIGIT_POSITION, 1, ptr_fahrenheit);
        
        _delay_ms(DELAY);
    }
    return 0;
}
