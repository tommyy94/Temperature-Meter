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
*       lcd.c
*
* 2. DESCRIPTION
*       - EN (enable) control line informs the LCD, that data is being sent.
*         Set to HIGH, wait required time, then set LOW to execute instruction.
*       - RS (register select), set LOW to treat data as command/special
*         instruction, HIGH treats data as text.
*       - RW (read/write), LOW to write on LCD, HIGH to read LCD.
*
******************************************************************************/

/******************************************************************************
*   HEADER FILES                                                              *
******************************************************************************/
#include "lcd.h"

/******************************************************************************
*   FUNCTION PROTOTYPES                                                       *
******************************************************************************/
static void lcd_execute_instruction(void);
static void lcd_wait_if_busy(void);
static void lcd_send_command(const uint8_t command);
static void lcd_goto(const uint8_t x, const uint8_t y);

/******************************************************************************
*   FUNCTION: lcd_execute_instruction                                         *
***************************************************************************//**
@brief Set EN HIGH for required time, then set EN LOW to execute instructions.
@details Instruction is executed when EN is set LOW.
******************************************************************************/
static void lcd_execute_instruction(void)
{
    CONTROL_LINES |= 1 << EN;
    NOP;
    NOP;
    CONTROL_LINES &= ~(1 << EN); /* execute instruction */
    return;
}

/******************************************************************************
*   FUNCTION: lcd_wait_if_busy                                                *
***************************************************************************//**
@brief Determine if the last given instruction is finished.
@details Set data lines to read mode, use command and read mode. Execute
instruction, then set data lines to write mode.
******************************************************************************/
static void lcd_wait_if_busy(void)
{
    DATA_DIRECTION &= ~0xFF;
    CONTROL_LINES &= ~(1 << RS); /* command mode */
    CONTROL_LINES |= 1 << RW; /* read mode */
    while (DATA_LINES >= 0x80)
    {
        lcd_execute_instruction();
    }
    DATA_DIRECTION |= 0xFF;
    return;
}

/******************************************************************************
*   FUNCTION: lcd_send_command                                                *
***************************************************************************//**
@brief Sends a hexadecimal command to LCD.
@details Given command is set to port. Sets write and command mode, executes
instruction and clears used port.
@param Hexadecimal command to send
******************************************************************************/
static void lcd_send_command(const uint8_t command)
{
    lcd_wait_if_busy();
    DATA_LINES |= command;
    CONTROL_LINES &= ~((1 << RW) | (1 << RS)); /* write mode, command mode */
    lcd_execute_instruction();
    DATA_LINES &= ~0xFF; /* clear data lines */
    return;
}

/******************************************************************************
*   FUNCTION: lcd_goto                                                        *
***************************************************************************//**
@brief Moves LCD cursor to given position.
@details Cursor is moved relative to first line.
@param X & Y -coordinates
******************************************************************************/
static void lcd_goto(const uint8_t x, const uint8_t y)
{
    static const uint8_t first_column_position[ROWS] = {0, 64};
    lcd_send_command(FIRST_LINE + x + first_column_position[y]);
    return;
}

/******************************************************************************
*   FUNCTION: lcd_send_character                                              *
***************************************************************************//**
@brief Sends a character when LCD is available.
@param Character to send
******************************************************************************/
void lcd_send_character(const char character)
{
    lcd_wait_if_busy();
    DATA_LINES |= character; /* character sent through 4/8-bit data lines */
    CONTROL_LINES &= ~(1 << RW); /* write mode */
    CONTROL_LINES |= 1 << RS; /* text mode */
    lcd_execute_instruction();
    DATA_LINES &= ~0xFF; /* clear data lines */
    return;
}

/******************************************************************************
*   FUNCTION: lcd_send_string                                                 *
***************************************************************************//**
@brief Sends string to given position in LCD.
@details Moves LCD cursor to given position. Sends string one character at
time.
@param X & Y -coordinates, String to send
******************************************************************************/
void lcd_send_string(const uint8_t x, const uint8_t y, char *string)
{
    lcd_goto(x, y);
    while(*string > 0)
    {
        lcd_send_character(*string++);
    }
    return;
}

/******************************************************************************
*   FUNCTION: lcd_send_int                                                    *
***************************************************************************//**
@brief Converts given integer to string, then sends to given location.
@details Moves LCD cursor to given position. Converts integer to string, so it
can be sent to the LCD. String is sent one character at time.
time.
@param X & Y -coordinates, Integer to display
******************************************************************************/
void lcd_send_int(const uint8_t x, const uint8_t y, int8_t *int_to_display)
{
    char string_to_display[COLUMNS];
    itoa(*int_to_display, string_to_display, 10);
    lcd_send_string(x, y, string_to_display);
    return;
}

/******************************************************************************
*   FUNCTION: lcd_init                                                        *
***************************************************************************//**
@brief Sets 4/8-bit mode and control lines to desirable port.
@details
******************************************************************************/
void lcd_init(void)
{
    CONTROL_DIRECTION |= 1 << EN | 1 << RW | 1 << RS; /* set control lines  */
    _delay_ms(15);
    lcd_send_command(CLEAR_DISPLAY);
    _delay_ms(2);
    lcd_send_command(SET_8_BIT); /* using 8 data lines */
    _delay_us(40);
    lcd_send_command(DISPLAY_ON_CURSOR_OFF);
    _delay_us(40);
    return;
}
