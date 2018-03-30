<<<<<<< HEAD
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
#define SENSOR_1_PIN PINC1


struct sensor {
    char celsius[MAX_STRING_LENGTH];
    char fahrenheit[MAX_STRING_LENGTH];
    char kelvin[MAX_STRING_LENGTH];
};

/*******************************************************************************
*   MACROS                                                                     *
*****************************************************************************///
/* NOTE: result is multiplied by 10 to avoid floating point */
#define CELSIUS_FORMULA(average) (((average) * 500 * 10 / 1024) - 500)
#define FAHRENHEIT_FORMULA(celsius) (((celsius) * 9 / 5) + 320)
#define KELVIN_FORMULA(celsius) ((celsius) * 10 + 27315)

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

/***************************************************************************//**
@brief Discard first 1000 readings, since they are unreliable.
@param Analog channel to use
@return void
*******************************************************************************/
void sensor_init(uint8_t const analog_channel);


/***************************************************************************//**
@brief Read adc values and compute corresponding temperature values.
@param Pointer to struct sensor, analog channel
@return void
*******************************************************************************/
void sensor_read(struct sensor *temperature,
                 uint8_t const analog_channel);


/***************************************************************************//**
@brief Shift digit to right and fill empty spot with a dot.
@param Pointer to first character of the string, current digit position, new
digit position.
@return void
*******************************************************************************/
void shift_digit(char *const digit_pos,
                 uint8_t cur_pos, uint8_t new_pos);


#endif /* SENSOR_H_ */
=======
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
@param Analog channel to use
@return void
*******************************************************************************/
void sensor_init(void);


/***************************************************************************//**
@brief Read adc values and compute corresponding temperature values.
@param Pointer to struct sensor, analog channel
@return void
*******************************************************************************/
void sensor_read(struct sensor *temperature);


/***************************************************************************//**
@brief Shift digit to right and fill empty spot with a dot.
@param Pointer to first character of the string, current digit position, new
digit position.
@return void
*******************************************************************************/
void shift_digit(char *const digit_pos,
                 uint8_t cur_pos, uint8_t new_pos);


#endif /* SENSOR_H_ */
>>>>>>> Cleaned up everything
