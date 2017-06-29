/******************************************************************************
*                                                                             *
*   This file is part of TemperatureMeter.                                    *
*                                                                             *
*   TemperatureMeter is free software: you can redistribute it and/or         *
*   modify it under the terms of the GNU General Public License as            *
*   published by the Free Software Foundation, either version 3 of the        *
*   License, or (at your option) any later version.                           *
*                                                                             *
*   TemperatureMeter is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of            *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
*   GNU General Public License for more details.                              *
*                                                                             *
*   You should have received a copy of the GNU General Public License along   *
*   with TemperatureMeter If not, see <http://www.gnu.org/licenses/>.         *
*                                                                             *
*   Copyright (C) 2017 by tommyy94                                            *
*                                                                             *
******************************************************************************/

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

#define ROWS 2
#define COLUMNS 16

#define CLEAR_DISPLAY 0x01
#define SET_4_BIT 0x28
#define SET_8_BIT 0x38
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define DISPLAY_ON_CURSOR_ON 0x0E
#define DISPLAY_ON_CURSOR_BLINK 0x0F
#define FIRST_LINE 0x80
#define SECOND_LINE 0xC0

#ifndef NOP
#define NOP asm volatile("nop")
#endif

/* Global variables */

/* Global structures */

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/
void lcd_send_character(const char character);
void lcd_send_string(const uint8_t x, const uint8_t y, char *string);
void lcd_send_int(const uint8_t x, const uint8_t y, int8_t *int_to_display);
void lcd_init(void);

#endif /* LCD_H_ */
