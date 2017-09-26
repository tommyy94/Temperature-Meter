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
#include "main.h"
#include "adc_lib/adc.h"

/******************************************************************************
*   GLOBAL VARIABLES                                                          *
******************************************************************************/
/* Control flags */

/* Global constants */
#define DECIMAL_SYSTEM 10
#define MAX_STRING_LENGTH 5
#define SAMPLES 1000

#define CELSIUS_FORMULA(average) (((average) * 5000 / 1024) - 500)
#define FAHRENHEIT_FORMULA(celsius) (((celsius) * 9 / 5) + 320)

#define DIGIT_CURRENT_POS 2
#define DIGIT_NEW_POS 3

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
void sensor_read(struct sensor *temperature,
                 uint8_t const analog_channel);
void shift_digit(char *const digit);

#endif /* SENSOR_H_ */
