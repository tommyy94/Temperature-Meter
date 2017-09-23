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
    uint8_t i;
    *average = 0;
    
    for(i = 0; i < SAMPLES; i++) {
        *average += adc_read(analog_channel);
        _delay_ms(10);
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
    uint8_t i;
    
    for(i = 0; i < SAMPLES; i++) {
        adc_read(analog_channel);
        _delay_ms(10);
    }
}

/******************************************************************************
*   FUNCTION: sensor_read                                                     *
***************************************************************************//**
@brief Read adc values and compute corresponding temperature values.
@param Pointer to struct sensor
******************************************************************************/
void sensor_read(struct sensor *temperature)
{
    char const decimal_mark[] = ".";
    int32_t celsius, fahrenheit, average;
    int32_t *const ptr_average = &average;
    
    calculate_average(PINC0, ptr_average);
    
    celsius = ((*ptr_average * 5000) / 1024) - 500;
    itoa(celsius, temperature->celsius, DECIMAL_SYSTEM);
    /* move last digit to right by one and place decimal mark in empty place */
    *(temperature->celsius+3) = *(temperature->celsius+2);
    *(temperature->celsius+2) = *decimal_mark;
    
    fahrenheit = (celsius * 9 / 5) + 320;
    itoa(fahrenheit, temperature->fahrenheit, DECIMAL_SYSTEM);
    /* again shifting a digit and placing a decimal mark */
    *(temperature->fahrenheit+3) = *(temperature->fahrenheit+2);
    *(temperature->fahrenheit+2) = *decimal_mark;
}
