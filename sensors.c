/******************************************************************************
*
* 1. NAME
*       sensor.c
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

/******************************************************************************
*   FUNCTION: sensor_read                                                     *
***************************************************************************//**
@brief Read adc values and compute corresponding temperature values.
@param Pointer to struct sensor
******************************************************************************/
void sensor_read(struct sensor *temperature)
{
    int32_t celsius, fahrenheit;
    const char decimal_mark[] = ".";
    
    celsius = ((adc_read(PINC0) * 5000) / 1024) - 500;
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
