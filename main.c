/*******************************************************************************
* @file
* @author   tommyy94
* @version  0.6
*
* @section  DESCRIPTION
*   test
* 
*******************************************************************************/

/*******************************************************************************
*
* 1. NAME
*       main.c
*
* 2. DESCRIPTION
*       Main file
*
*******************************************************************************/

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include "main.h"

/*******************************************************************************
*   MAIN PROGRAM                                                               *
*******************************************************************************/
void main(void)
{
    struct sensor temperature;
    struct sensor *const ptr_temperature = &temperature;
    char *const ptr_celsius = temperature.celsius;
    char *const ptr_fahrenheit = temperature.fahrenheit;

    //get_mcusr();
    adc_init();
    sensor_init(SENSOR_1_PIN);
    lcd_init();
    //wdt_init();

    lcd_send_string(FIRST_COLUMN, FIRST_ROW, "Celsius");
    lcd_send_string(FIRST_COLUMN, SECOND_ROW, "Fahrenheit");

    while(1) {
        sensor_read(ptr_temperature, SENSOR_1_PIN);
        shift_digit(ptr_celsius);
        shift_digit(ptr_fahrenheit);
        lcd_send_string(DIGIT_POSITION, FIRST_ROW, ptr_celsius);
        lcd_send_string(DIGIT_POSITION, SECOND_ROW, ptr_fahrenheit);
        _delay_ms(DELAY);
        //wdt_reset(); /* restart timer if under 60s */
    }
}
