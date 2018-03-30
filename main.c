<<<<<<< HEAD
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
    char *const ptr_kelvin = temperature.kelvin;

    /* set clock division factor to 1 */
    CLKPR = (1 << CLKPCE);
    CLKPR &= ~0xFF;

    /* init sequence */
    adc_init();
    sensor_init(SENSOR_1_PIN);
    lcd_init(SET_8_BIT, CLEAR_DISPLAY);
    sleep_ms(DELAY);

    /* initialize lcd screen with text */
    lcd_send_string(SIXTH_COLUMN, FIRST_ROW, DEGREE_SIGN "C");
    lcd_send_string(FOURTEENTH_COLUMN, FIRST_ROW, DEGREE_SIGN "F");
    lcd_send_string(SIXTH_COLUMN, SECOND_ROW, DEGREE_SIGN "K");

    while(1) {
        /* read sensor values and save to struct */
        sensor_read(ptr_temperature, SENSOR_1_PIN);

        /* handle strings */
        shift_digit(ptr_celsius, 2, 3);
        shift_digit(ptr_fahrenheit, 2, 3);
        shift_digit(ptr_kelvin, 3, 4);

        /* print values */
        lcd_send_string(SECOND_COLUMN, FIRST_ROW, ptr_celsius);
        lcd_send_string(TENTH_COLUMN, FIRST_ROW, ptr_fahrenheit);
        lcd_send_string(FIRST_COLUMN, SECOND_ROW, ptr_kelvin);

        sleep_ms(DELAY);
        wdt_reset();
    }
}


#ifdef BOOT_DEBUG
void get_mcusr(void)
{
    mcusr_mirror = MCUSR;
    MCUSR = 0;
    wdt_disable();
}
#endif
=======
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
    char *const ptr_kelvin = temperature.kelvin;

    /* set clock division factor to 1 */
    CLKPR = (1 << CLKPCE);
    CLKPR &= ~0xFF;

    /* init sequence */
    adc_init();
    sensor_init();
    lcd_init();
    sleep_ms(DELAY); /* sleep needed between LCD operations */

    /* initialize lcd screen with text */
    lcd_send_string(SIXTH_COLUMN, FIRST_ROW, DEGREE_SIGN "C");
    lcd_send_string(FOURTEENTH_COLUMN, FIRST_ROW, DEGREE_SIGN "F");
    lcd_send_string(SIXTH_COLUMN, SECOND_ROW, DEGREE_SIGN "K");

    while(1) {
        /* read sensor values and save to struct */
        sensor_read(ptr_temperature);

        /* handle strings with magic numbers */
        shift_digit(ptr_celsius, 2, 3);
        shift_digit(ptr_fahrenheit, 2, 3);
        shift_digit(ptr_kelvin, 3, 4);

        /* print values */
        lcd_send_string(SECOND_COLUMN, FIRST_ROW, ptr_celsius);
        lcd_send_string(TENTH_COLUMN, FIRST_ROW, ptr_fahrenheit);
        lcd_send_string(FIRST_COLUMN, SECOND_ROW, ptr_kelvin);

        sleep_ms(DELAY);
        wdt_reset();
    }
}


#ifdef BOOT_DEBUG
void get_mcusr(void)
{
    mcusr_mirror = MCUSR;
    MCUSR = 0;
    wdt_disable();
}
#endif
>>>>>>> Cleaned up everything
