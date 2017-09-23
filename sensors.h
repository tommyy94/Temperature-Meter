/******************************************************************************
*
* 1. NAME
*       sensors.h
*
* 2. DESCRIPTION
*
*
******************************************************************************/
#ifndef SENSOR_H_
#define SENSOR_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>
#include "adc_lib/adc.h"

/******************************************************************************
*   GLOBAL VARIABLES                                                          *
******************************************************************************/
/* Control flags */

/* Global constants */
#define DECIMAL_SYSTEM 10
#define MAX_STRING_LENGTH 5
#define SAMPLES 100

/* Global variables */

/* Global structures */
struct sensor {
    char celsius[MAX_STRING_LENGTH];
    char fahrenheit[MAX_STRING_LENGTH];
};

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/
void sensor_init(uint8_t const analog_channel);
void sensor_read(struct sensor *temperature);

#endif /* SENSOR_H_ */
