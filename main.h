/*******************************************************************************
*
* 1. NAME
*       main.h
*
* 2. DESCRIPTION
*       - ATmega328P
*
*******************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

#ifndef F_CPU
    #define F_CPU 8000000UL
#endif

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "adc_lib/adc.h"
#include "sensors.h"
#include "lcd_lib/lcd.h"
#include "watchdog.h"
#include "power_management.h"


/*******************************************************************************
*   GLOBAL VARIABLES                                                           *
*******************************************************************************/
#define DELAY 0x4D /* 10ms delay */
/**
 * 7812.5 ticks / (1000ms / target_delay) = target_delay_in_ticks
 *                                        => convert to hexadecimal - 1,
 *                                           because 0x00 is one count
 */



#define DEGREE_SIGN "\xB2"

//#define BOOT_DEBUG
#ifdef BOOT_DEBUG
    volatile uint8_t mcusr_mirror __attribute__((section(".noinit")));
#endif

/* positions for sending string to LCD */
#define FIRST_ROW 0
#define SECOND_ROW 1
#define THIRD_ROW 2
#define FOURTH_ROW 3

#define FIRST_COLUMN 0
#define SECOND_COLUMN 1
#define THIRD_COLUMN 2
#define FOURTH_COLUMN 3
#define FIFTH_COLUMN 4
#define SIXTH_COLUMN 5
#define SEVENTH_COLUMN 6
#define EIGHT_COLUMN 7
#define NINTH_COLUMN 8
#define TENTH_COLUMN 9
#define TENTH_COLUMN 9
#define ELEVENTH_COLUMN 10
#define TWELFTH_COLUMN 11
#define THIRTEENTH_COLUMN 12
#define FOURTEENTH_COLUMN 13
#define FIFTEENTH_COLUMN 14
#define SIXTEENTH_COLUMN 15


/*******************************************************************************
*   MACROS                                                                     *
*****************************************************************************///

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///


/***************************************************************************//**
@brief Saves MCUSR status to mirror and clears MCUSR.
@details Disables the watchdog timer.
@param void
@return void
*******************************************************************************/
#ifdef BOOT_DEBUG
    void get_mcusr(void)
    __attribute__((naked))
    __attribute__((section(".init3")));
#endif


#endif /* MAIN_H_ */
