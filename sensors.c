/******************************************************************************
*
* 1. NAME
*       sensors.c
*
* 2. DESCRIPTION
*       Reads sensor values, converts them to corresponding temperature values.
*
******************************************************************************/

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include "sensors.h"

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///


/*******************************************************************************
*   FUNCTION DEFINITIONS                                                       *
*******************************************************************************/
int32_t sensor_read(void)
{
    int32_t average = 0;

    for(uint16_t i = 0; i < SAMPLES; i++) {
        average += adc_read();
        _delay_us(READ_DELAY);
    }
    return (average / SAMPLES);
}


void sensor_init(void)
{
    for(uint16_t i = 0; i < SAMPLES; i++) {
        adc_read();
        _delay_us(READ_DELAY);
    }
}


void convert_to_temperature(struct sensor *temperature,
                            int32_t *const average)
{
    int32_t celsius, fahrenheit, kelvin;

    celsius = CELSIUS_FORMULA(*average);
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
