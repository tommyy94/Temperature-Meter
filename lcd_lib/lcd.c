/***************************************************************************
*
*   This file is part of LCD_library.
*
*   LCD_library is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   LCD_library is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with LCD_library. If not, see <http://www.gnu.org/licenses/>.
*
*	Copyright (C) 2017 by tommyy94
*
***************************************************************************/

/***************************************************************************
*
* 1. NAME
*		lcd.c
*
* 2. DESCRIPTION
*		LCD source
*
***************************************************************************/

/***************************************************************************
*   HEADER FILES
***************************************************************************/
#include "lcd.h"

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void lcd_keep_enabled(void)
{
	PORTB |= 1 << EN;
	asm volatile("nop"); //no operation
	asm volatile("nop"); //enable has to be on for ~500ns
	PORTB &= ~(1 << EN);
}

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void lcd_check_if_busy(void)
{
	DDRD &= ~0xFF; //read mode
	PORTB &= ~(1 << RS); //RS off
	PORTB |= 1 << RW; //RW on
	while (PORTD >= 0x80)
	{
		lcd_keep_enabled();
	}
	DDRD |= 0xFF; //port D as output
}

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void lcd_send_command(unsigned char command)
{
	lcd_check_if_busy();
	PORTD |= command;
	PORTB &= ~((1 << RW) | (1 << RS));
	lcd_keep_enabled();
	PORTD &= ~0xFF;
}

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void lcd_goto_xy(uint8_t x, uint8_t y)
{
	int first_column_position[2] = {0, 64};
	lcd_send_command(FIRST_LINE + x + first_column_position[y]);
}

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void lcd_send_character(unsigned char character)
{
	lcd_check_if_busy();
	PORTD |= character;
	PORTB &= ~(1 << RW);
	PORTB |= 1 << RS;
	lcd_keep_enabled();
	PORTD &= ~0xFF;
}

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void lcd_send_string(uint8_t x, uint8_t y, char *string)
{
	lcd_goto_xy(x, y);
	while(*string > 0)
	{
		lcd_send_character(*string++);
	}
}

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void lcd_send_int(uint8_t x, uint8_t y, int int_to_display, unsigned char number_of_digits)
{
	char string_to_display[number_of_digits];
	itoa(int_to_display, string_to_display, 10);
	lcd_send_string(x, y, string_to_display);
}

/***************************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------------
; NAME:
; DESCRIPTION:
;	Input:
;	Output:
;	Used global variables:
; REMARKS when using this function:
;**************************************************************************/
void lcd_init(void)
{
	DDRB |= 1 << EN | 1 << RW | 1 << RS;
	_delay_ms(15);
	lcd_send_command(CLEAR_DISPLAY);
	_delay_ms(2);
	lcd_send_command(SET_8_BIT);
	_delay_us(40);
	lcd_send_command(DISPLAY_ON_CURSON_OFF);
	_delay_us(40);
}
