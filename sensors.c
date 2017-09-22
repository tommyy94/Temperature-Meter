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
static int32_t calculate_average(const uint8_t analog_channel);

/******************************************************************************
*   FUNCTION: sensor_init                                                     *
***************************************************************************//**
@brief
@param
******************************************************************************/
void sensor_init(const uint8_t analog_channel)
{
    uint8_t i;
    
    for(i = 0; i < SAMPLES; i++) {
        adc_read(analog_channel);
        _delay_ms(10);
    }
}

/******************************************************************************
*   FUNCTION: calculate_average                                               *
***************************************************************************//**
@brief
@param
******************************************************************************/
static int32_t calculate_average(const uint8_t analog_channel)
{
    int32_t average = 0;
    uint8_t i;
    /* uint8_t *ptr_average = &average; */
    /*
     * @TODO: return pointer to "average"
     */
    
    for(i = 0; i < SAMPLES; i++) {
        average += adc_read(analog_channel);
        _delay_ms(10);
    }
    average /= SAMPLES;
    return average;
}

/******************************************************************************
*   FUNCTION: sensor_read                                                     *
***************************************************************************//**
@brief Read adc values and compute corresponding temperature values.
@param Pointer to struct sensor
******************************************************************************/
void sensor_read(struct sensor *temperature)
{
    const char decimal_mark[] = ".";
    int32_t celsius, fahrenheit;
    
    celsius = ((calculate_average(PINC0) * 5000) / 1024) - 500;
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
