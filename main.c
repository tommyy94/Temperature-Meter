/******************************************************************************
*
* 1. NAME
*       main.c
*
* 2. DESCRIPTION
*       Main file
*
******************************************************************************/

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include "main.h"

/******************************************************************************
*   MAIN PROGRAM                                                              *
******************************************************************************/
int main(void)
{
    struct sensor temperature;
    struct sensor *const ptr_temperature = &temperature;
    char *const ptr_celsius = temperature.celsius;
    char *const ptr_fahrenheit = temperature.fahrenheit;
    
    adc_init();
    lcd_init();
    
    lcd_send_string(0, 0, "Celsius");
    lcd_send_string(0, 1, "Fahrenheit");

    while(1) {
        sensor_read(ptr_temperature);
        lcd_send_string(DIGIT_POSITION, 0, ptr_celsius);
        lcd_send_string(DIGIT_POSITION, 1, ptr_fahrenheit);
        _delay_ms(DELAY);
    }
    return 0;
}
