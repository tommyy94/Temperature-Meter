/*******************************************************************************
*
* 1. NAME
*       sensors.h
*
* 2. DESCRIPTION
*       - Used temperature sensor is TMP36
*
*******************************************************************************/
#ifndef SENSOR_H_
#define SENSOR_H_

#ifndef F_CPU
    #define F_CPU 8000000UL
#endif

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>
#include "adc_lib/adc.h"

/*******************************************************************************
*   GLOBAL VARIABLES                                                           *
*****************************************************************************///
#ifndef DECIMAL_SYSTEM
    #define DECIMAL_SYSTEM 10 /* for converting integer to ascii */
#endif

#define MAX_STRING_LENGTH 5
#define SAMPLES 1000
#define READ_DELAY 5 /* 0x26 = 39 timer ticks */

/* sensor pins */
#define SENSOR_1_PIN PINC0


struct sensor {
    char celsius[MAX_STRING_LENGTH];
    char fahrenheit[MAX_STRING_LENGTH];
    char kelvin[MAX_STRING_LENGTH];
};

/*******************************************************************************
*   MACROS                                                                     *
*****************************************************************************///
/* NOTE: result is multiplied by 10 to avoid floating point */
/* using 3.3V reference voltage */
#define CELSIUS_FORMULA(average) (((average) * 330 * 10 / 1024) - 330)
#define FAHRENHEIT_FORMULA(celsius) (((celsius) * 9 / 5) + 320)
#define KELVIN_FORMULA(celsius) ((celsius) * 10 + 27315)


/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

/***************************************************************************//**
@brief Discard first 1000 readings, since they are unreliable.
@param void
@return void
*******************************************************************************/
void sensor_init(void);


/***************************************************************************//**
@brief Read adc values and calculate average.
@param void
@return average ADC value
*******************************************************************************/
int32_t sensor_read(void);


/***************************************************************************//**
@brief Shift digit to right and fill empty spot with a dot.
@param Pointer to first character of the string, current digit position, new
digit position.
@return void
*******************************************************************************/
void shift_digit(char *const digit_pos,
                 uint8_t cur_pos, uint8_t new_pos);


/***************************************************************************//**
@brief Converts readings from ADC to celsius, kelvin and fahrenheit.
@details Also converts temperature values to ASCII, to be sent to the LCD.
@param Pointer to struct sensor, pointer to average
@return void
*******************************************************************************/
void convert_to_temperature(struct sensor *temperature,
                            int32_t *const average);


#endif /* SENSOR_H_ */
