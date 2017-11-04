/*******************************************************************************
*
* 1. NAME
*       sensors.h
*
* 2. DESCRIPTION
*
*
*******************************************************************************/
#ifndef SENSOR_H_
#define SENSOR_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>

/*******************************************************************************
*   GLOBAL VARIABLES                                                           *
*****************************************************************************///
#define DECIMAL_SYSTEM 10 /* for itoa */
#define MAX_STRING_LENGTH 5
#define SAMPLES 1000
#define DELAY 10

#define CELSIUS_FORMULA(average) (((average) * 5000 / 1024) - 500)
#define FAHRENHEIT_FORMULA(celsius) (((celsius) * 9 / 5) + 320)

/* for shifting digit */
#define DIGIT_CURRENT_POS 2
#define DIGIT_NEW_POS 3

/* sensor pins */
#define SENSOR_1_PIN PINC1

struct sensor {
    char celsius[MAX_STRING_LENGTH];
    char fahrenheit[MAX_STRING_LENGTH];
};

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

/***************************************************************************//**
@brief Discard first 1000 readings, since they are unreliable.
@param Analog channel to use
@return void
*******************************************************************************/
void sensor_init(uint8_t const analog_channel);


/***************************************************************************//**
@brief Read adc values and compute corresponding temperature values.
@param Pointer to struct sensor
@return void
*******************************************************************************/
void sensor_read(struct sensor *temperature,
                 uint8_t const analog_channel);


/***************************************************************************//**
@brief Shift digit to right.
@param Pointer to first character of the string.
@return void
*******************************************************************************/
void shift_digit(char *const digit);


#endif /* SENSOR_H_ */
