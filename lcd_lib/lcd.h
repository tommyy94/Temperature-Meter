/******************************************************************************
*
* 1. NAME
*       lcd.h
*
* 2. DESCRIPTION
*
*
******************************************************************************/
#ifndef LCD_H_
#define LCD_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

/******************************************************************************
*   GLOBAL VARIABLES                                                          *
******************************************************************************/
/* Control flags */

/* Global constants */
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

#define DECIMAL_SYSTEM 10

#define CLEAR_DISPLAY 0x01
#define SET_4_BIT 0x28
#define SET_8_BIT 0x38
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define DISPLAY_ON_CURSOR_ON 0x0E
#define DISPLAY_ON_CURSOR_BLINK 0x0F

#define FIRST_LINE_ADDRESS 0x80
#define SECOND_LINE_ADDRESS 0xC0
#define THIRD_LINE_ADDRESS 0x94
#define FOURTH_LINE_ADDRESS 0xD4

#ifndef NOP
#define NOP asm volatile("nop")
#endif

/* Global variables */

/* Global structures */

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/
void lcd_send_character(char const character);
void lcd_send_string(uint8_t const x, uint8_t const y,
                     char const *string);
void lcd_send_int(uint8_t const x, uint8_t const y,
                  int32_t *const int_to_display);
void lcd_init(void);

#endif /* LCD_H_ */
