/******************************************************************************
*
* 1. NAME
*       sensors.c
*
* 2. DESCRIPTION
*       Reads sensor values and calculates them.
*
******************************************************************************/

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include "sensors.h"

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/
static void calculate_average(uint8_t const analog_channel,
                              int32_t *const average);

/******************************************************************************
*   FUNCTION: calculate_average                                               *
***************************************************************************//**
@brief Calculates average temperature and saves it to given memory address.
@param Analog channel to use, pointer to average temperature
******************************************************************************/
static void calculate_average(uint8_t const analog_channel,
                              int32_t *const average)
{
    uint16_t i;
    *average = 0;

    for(i = 0; i < SAMPLES; i++) {
        *average += adc_read(analog_channel);
        _delay_us(DELAY);
    }
    *average /= SAMPLES;
}

/******************************************************************************
*   FUNCTION: sensor_init                                                     *
***************************************************************************//**
@brief Discard first 100 readings, since they are unreliable.
@param Analog channel to use
******************************************************************************/
void sensor_init(uint8_t const analog_channel)
{
    uint16_t i;

    for(i = 0; i < SAMPLES; i++) {
        adc_read(analog_channel);
        _delay_us(DELAY);
    }
}

/******************************************************************************
*   FUNCTION: sensor_read                                                     *
***************************************************************************//**
@brief Read adc values and compute corresponding temperature values.
@param Pointer to struct sensor
******************************************************************************/
void sensor_read(struct sensor *temperature,
                 uint8_t const analog_channel)
{
    int32_t celsius, fahrenheit, average;
    int32_t *const ptr_average = &average;

    calculate_average(analog_channel, ptr_average);

    celsius = CELSIUS_FORMULA(*ptr_average);
    fahrenheit = FAHRENHEIT_FORMULA(celsius);
    itoa(celsius, temperature->celsius, DECIMAL_SYSTEM);
    itoa(fahrenheit, temperature->fahrenheit, DECIMAL_SYSTEM);
}

/******************************************************************************
*   FUNCTION: shift_digit                                                     *
***************************************************************************//**
@brief Shift digit to right.
@param Pointer to first character of the string.
******************************************************************************/
void shift_digit(char *const digit)
{
    char const decimal_mark[] = ".";

    *(digit + DIGIT_NEW_POS) = *(digit + DIGIT_CURRENT_POS);
    *(digit + DIGIT_CURRENT_POS) = *decimal_mark;
}
