/*******************************************************************************
*
* 1. NAME
*       lcd.h
*
* 2. DESCRIPTION
*       Library for JHD 659 M10 LCD display.
*       NOTE: Whole port is used for Control Direction register.
*
*******************************************************************************/
#ifndef LCD_H_
#define LCD_H_

#ifndef F_CPU
    #define F_CPU 8000000UL
#endif

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

/*******************************************************************************
*   GLOBAL VARIABLES                                                           *
*******************************************************************************/
/* ports and pins for LCD */
#define EN PINB0
#define RW PINB3
#define RS PINB2
#define DATA_LINES PORTD
#define CONTROL_LINES PORTB
#define DATA_DIRECTION DDRD
#define CONTROL_DIRECTION DDRB

#define ROWS 4
#define COLUMNS 16
#define FIRST_ROW_POSITION 0
#define SECOND_ROW_POSITION 64
#define THIRD_ROW_POSITION 32
#define FOURTH_ROW_POSITION 128

#ifndef DECIMAL_SYSTEM
    #define DECIMAL_SYSTEM 10 /* for converting integer to ascii */
#endif

#define MSB 0x80 /* most significant bit */

/* LCD commands */
#define CLEAR_DISPLAY 0x01
#define SET_4_BIT 0x28
#define SET_8_BIT 0x38
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define DISPLAY_ON_CURSOR_ON 0x0E
#define DISPLAY_ON_CURSOR_BLINK 0x0F

/* memory addresses for LCD cursor position */
#define FIRST_LINE_ADDRESS 0x80
#define SECOND_LINE_ADDRESS 0xC0
#define THIRD_LINE_ADDRESS 0x94
#define FOURTH_LINE_ADDRESS 0xD4

/* delays; refer to the manual */
#define LCD_DELAY_US_AFTER_VDD 500 /* => 15ms*250kHz/F_CPU=0.46875ms */
#define LCD_DELAY_US_LONG 52 /* => 1.64ms*250kHz/F_CPU=0.05125ms */
#define LCD_DELAY_US_SHORT 15 /* => 40us*250kHz/F_CPU=1.25us; 15us to be safe */


/*******************************************************************************
*   MACROS                                                                     *
*****************************************************************************///
#ifndef NOP
    #define NOP asm volatile("nop") /* no operation for 1 clock cycle */
#endif

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///


/***************************************************************************//**
@brief Sends string to given position in LCD.
@details Moves LCD cursor to given position. Sends string one character at time.
@param X & Y -coordinates, String to send
@return void
*******************************************************************************/
void lcd_send_string(uint8_t const x, uint8_t const y,
                     char const *string);



/***************************************************************************//**
@brief Sends a hexadecimal command to LCD.
@details Given command is set to port.
Sets write and command mode, executes instruction and clears used port.
@param Hexadecimal command to send
@return void
*******************************************************************************/
void lcd_send_command(uint8_t const command);


/***************************************************************************//**
@brief Sets 4/8-bit mode and control lines to desirable port.
@param void
@return void
*******************************************************************************/
void lcd_init(void);


#endif /* LCD_H_ */
