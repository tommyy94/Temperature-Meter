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
*		adc.c
*
* 2. DESCRIPTION
*		Converts analog to digital.
*
***************************************************************************/

/***************************************************************************
*   HEADER FILES
***************************************************************************/
#include "adc.h"

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME: adc_init
; DESCRIPTION: Sets register values
;	Input: Analog input pin
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void adc_init(uint8_t analog_channel)
{
	ADMUX |= (1 << REFS0) | (1 << ADLAR) | analog_channel;
	ADCSRA |= (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0);
} /* end of adc_init */

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME: adc_read
; DESCRIPTION: Converts analog to digital
;	Input: -
;	Output: Converted analog value in digital form
;	Used global variables: -
; REMARKS when using this function:
;**************************************************************************/
uint16_t adc_read(void)
{
	ADCSRA |= (1 << ADSC); //start ADC conversion
	while(ADCSRA & (1 << ADSC)){}
	return ADCH;
} /* end of adc_read */
