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

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

/***************************************************************************//**
@brief Calculates average temperature and saves it to given memory address.
@param Analog channel to use, pointer to average temperature
@return void
*******************************************************************************/
static void calculate_average(int32_t *const average);


/*******************************************************************************
*   FUNCTION DEFINITIONS                                                       *
*******************************************************************************/
static void calculate_average(int32_t *const average)
{
    uint16_t i;
    *average = 0;

    for(i = 0; i < SAMPLES; i++) {
        *average += adc_read();
        _delay_us(READ_DELAY);
    }
    *average /= SAMPLES;
}


void sensor_init(void)
{
    uint16_t i;

    for(i = 0; i < SAMPLES; i++) {
        adc_read();
        _delay_us(READ_DELAY);
    }
}


void sensor_read(struct sensor *temperature)
{
    int32_t celsius, fahrenheit, kelvin, average;
    int32_t *const ptr_average = &average;

    calculate_average(ptr_average);

    celsius = CELSIUS_FORMULA(*ptr_average);
    fahrenheit = FAHRENHEIT_FORMULA(celsius);
    kelvin = KELVIN_FORMULA(celsius);

    itoa(celsius, temperature->celsius, DECIMAL_SYSTEM);
    itoa(fahrenheit, temperature->fahrenheit, DECIMAL_SYSTEM);
    itoa(kelvin, temperature->kelvin, DECIMAL_SYSTEM);
}


void shift_digit(char *const digit_pos,
                 uint8_t cur_pos, uint8_t new_pos)
{
    char const decimal_mark[] = ".";

    digit_pos[new_pos] = digit_pos[cur_pos];
    digit_pos[cur_pos] = *decimal_mark;
}
