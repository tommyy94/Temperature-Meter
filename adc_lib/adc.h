/******************************************************************************
*
* 1. NAME
*       adc.h
*
* 2. DESCRIPTION
*
*
******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include <avr/io.h>
#include <stdint.h>

/******************************************************************************
*   GLOBAL VARIABLES                                                          *
******************************************************************************/
/* Control flags */

/* Global constants */

/* Global variables */

/* Global structures */

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/
void adc_init(void);
int32_t adc_read(const uint8_t analog_channel);

#endif /* ADC_H_ */
