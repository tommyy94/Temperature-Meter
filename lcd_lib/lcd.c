/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include "lcd.h"

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

/***************************************************************************//**
@brief Set EN HIGH for required time, then set EN LOW to execute instructions.
@details Instruction is executed when EN is set LOW.
@param void
@return void
*******************************************************************************/
static void lcd_execute_instruction(void);


/***************************************************************************//**
@brief Determine if the last given instruction is finished.
@details Set data lines to read mode, use command and read mode.
Execute instruction, then set data lines to write mode.
@param void
@return void
*******************************************************************************/
static void lcd_wait_if_busy(void);


/***************************************************************************//**
@brief Sends a character when LCD is available.
@param Character to send
@return void
*******************************************************************************/
static void lcd_send_character(char const character);


/***************************************************************************//**
@brief Moves LCD cursor to given position.
@details Cursor is moved relative to first line.
@param X & Y -coordinates
@return void
*******************************************************************************/
static void lcd_goto(uint8_t const x, uint8_t const y);


/*******************************************************************************
*   FUNCTION DEFINITIONS                                                       *
*******************************************************************************/
static void lcd_execute_instruction(void)
{
    CONTROL_LINES |= 1 << EN;
    NOP;
    NOP;
    CONTROL_LINES &= ~(1 << EN); /* execute instruction here */
}


static void lcd_wait_if_busy(void)
{
    DATA_DIRECTION &= ~0xFF; /* read data lines */
    CONTROL_LINES &= ~(1 << RS); /* command mode */
    CONTROL_LINES |= 1 << RW; /* read mode */
    while(DATA_LINES & MSB) { /* LCD is busy if MSB is set */
        lcd_execute_instruction();
    }
    DATA_DIRECTION |= 0xFF; /* write to data lines */
    _delay_us(LCD_DELAY_US_LONG);
}


void lcd_send_command(uint8_t const command)
{
    lcd_wait_if_busy();
    DATA_LINES |= command;
    CONTROL_LINES &= ~((1 << RW) | (1 << RS)); /* write mode, command mode */
    lcd_execute_instruction();
    DATA_LINES &= ~0xFF; /* clear data lines */
}


static void lcd_goto(uint8_t const x, uint8_t const y)
{
    static uint8_t const first_column_position[ROWS] = {
        FIRST_ROW_POSITION,
        SECOND_ROW_POSITION,
        THIRD_ROW_POSITION,
        FOURTH_ROW_POSITION
    };

    lcd_send_command(FIRST_LINE_ADDRESS + x + first_column_position[y]);
    _delay_us(LCD_DELAY_US_LONG);
}


static void lcd_send_character(char const character)
{
    lcd_wait_if_busy();
    DATA_LINES |= character; /* character sent through 4/8-bit data lines */
    CONTROL_LINES &= ~(1 << RW); /* write mode */
    CONTROL_LINES |= 1 << RS; /* text mode */
    lcd_execute_instruction();
    DATA_LINES &= ~0xFF; /* clear data lines */
    _delay_us(LCD_DELAY_US_SHORT);
}


void lcd_send_string(uint8_t const x, uint8_t const y,
                     char const *string)
{
    lcd_goto(x, y);
    while(*string != '\0') {
        lcd_send_character(*string++);
    }
}


void lcd_init(void)
{
    CONTROL_DIRECTION |= 1 << EN | 1 << RW | 1 << RS; /* set control lines  */
    _delay_us(LCD_DELAY_US_AFTER_VDD);
    lcd_send_command(SET_8_BIT); /* using 8 data lines */
    _delay_us(LCD_DELAY_US_SHORT);
    lcd_send_command(DISPLAY_ON_CURSOR_OFF);
    _delay_us(LCD_DELAY_US_SHORT);
    lcd_send_command(CLEAR_DISPLAY);
    _delay_us(LCD_DELAY_US_LONG);
}
