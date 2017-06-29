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
*       adc.c
*
* 2. DESCRIPTION
*
*
******************************************************************************/

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include "adc.h"

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/

/******************************************************************************
*   FUNCTION: adc_init                                                        *
***************************************************************************//**
@brief Sets ADC register values.
@details Sets reference voltage and input clock to the ADC.
******************************************************************************/
void adc_init(void)
{
    ADMUX |= (1 << REFS0);
    /*
     * Using AVcc (REFS0)
     * 10-bit conversion
     */

    ADCSRA |= (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0);
    /*
     * Input clock to the ADC:
     * 16MHz/8 = 125kHz
     */
    return;
}

/******************************************************************************
*   FUNCTION: adc_read                                                        *
***************************************************************************//**
@brief Starts ADC, waits until it's done, then turns pin ADSC LOW.
@details Conversion is done in single conversion mode; each conversion has to
be called. 
@param Analog input pin
@return 10-bit ADC value
******************************************************************************/
uint8_t adc_read(const uint8_t analog_channel)
{
    ADMUX |= analog_channel;
    ADCSRA |= (1 << ADSC); /* starts ADC conversion */
    while(ADCSRA & (1 << ADSC))
    {
        ; /* wait until conversion is done */
    }
    return ADC;
}
