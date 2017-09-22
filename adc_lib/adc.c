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
int32_t adc_read(const uint8_t analog_channel)
{
    ADMUX |= analog_channel;
    ADCSRA |= (1 << ADSC); /* starts ADC conversion */
    while(ADCSRA & (1 << ADSC)) {
        ; /* wait until conversion is done */
    }
    return ADC;
}
