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
@brief Sends a hexadecimal command to LCD.
@details Given command is set to port.
Sets write and command mode, executes instruction and clears used port.
@param Hexadecimal command to send
@return void
*******************************************************************************/
static void lcd_send_command(uint8_t const command);


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
    CONTROL_LINES &= ~(1 << EN); /* execute instruction */
}


static void lcd_wait_if_busy(void)
{
    DATA_DIRECTION &= ~0xFF;
    CONTROL_LINES &= ~(1 << RS); /* command mode */
    CONTROL_LINES |= 1 << RW; /* read mode */
    while (DATA_LINES >= FIRST_LINE_ADDRESS) {
        lcd_execute_instruction();
    }
    DATA_DIRECTION |= 0xFF;
}


static void lcd_send_command(uint8_t const command)
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
}


void lcd_send_character(char const character)
{
    lcd_wait_if_busy();
    DATA_LINES |= character; /* character sent through 4/8-bit data lines */
    CONTROL_LINES &= ~(1 << RW); /* write mode */
    CONTROL_LINES |= 1 << RS; /* text mode */
    lcd_execute_instruction();
    DATA_LINES &= ~0xFF; /* clear data lines */
}


void lcd_send_string(uint8_t const x, uint8_t const y,
                     char const *string)
{
    lcd_goto(x, y);
    while(*string != '\0') {
        lcd_send_character(*string++);
    }
}


void lcd_send_int(uint8_t const x, uint8_t const y,
                  int32_t *const int_to_display)
{
    char string_to_display[COLUMNS];

    itoa(*int_to_display, string_to_display, DECIMAL_SYSTEM);
    lcd_send_string(x, y, string_to_display);
}


void lcd_init(void)
{
    CONTROL_DIRECTION |= 1 << EN | 1 << RW | 1 << RS; /* set control lines  */
    _delay_ms(LCD_DELAY_AFTER_VDD);
    lcd_send_command(CLEAR_DISPLAY);
    _delay_ms(LCD_DELAY_MS);
    lcd_send_command(SET_8_BIT); /* using 8 data lines */
    _delay_us(LCD_DELAY_US);
    lcd_send_command(DISPLAY_ON_CURSOR_OFF);
    _delay_us(LCD_DELAY_US);
}
