/*******************************************************************************
*
* 1. NAME
*       adc.c
*
* 2. DESCRIPTION
*       Converts analog signal to digital.
*
*******************************************************************************/

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include "adc.h"
 
/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///


/*******************************************************************************
*   FUNCTION DEFINITIONS                                                       *
*******************************************************************************/
uint16_t adc_read(uint8_t const analog_channel)
{
    ADMUX |= analog_channel;
    ADCSRA |= (1 << ADSC); /* starts ADC conversion */
    while(ADCSRA & (1 << ADSC)) {
        ; /* wait until conversion is done */
    }
    return ADC;
}
