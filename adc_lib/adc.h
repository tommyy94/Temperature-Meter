/***************************************************************************
*
*   This file is part of ADC_library.
*
*   ADC_library is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   ADC_library is distributed in the hope that it will be useful,
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
*		adc.h
*
* 2. DESCRIPTION
*		ADC header
*
***************************************************************************/

#ifndef ADC_H_
#define ADC_H_

/***************************************************************************
*   HEADER FILES
***************************************************************************/
#include <avr/io.h>
#include <stdint.h>

/***************************************************************************
*   GLOBAL VARIABLES
***************************************************************************/
/* Control flags */

/* Global constants */

/* Global variables */

/* Global structures */

/****************************************************************************
*   FUNCTION PROTOTYPES
****************************************************************************/
void adc_init(uint8_t analog_channel);
uint16_t adc_read(void);

#endif /* ADC_H_ */
