/*******************************************************************************
*
* 1. NAME
*      power_management.c
*
* 2. DESCRIPTION
*
*
*******************************************************************************/

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include "power_management.h"

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///


/*******************************************************************************
*   FUNCTION DEFINITIONS                                                       *
*******************************************************************************/
void sleep_ms(uint8_t duration_as_hex)
{
    /**
     * timer_ticks = CPU frequency / timer prescaler
     *             = 8 MHz / 1024 clk
     *             = 7812.5 timer ticks (=> 1000 ms)
     *
     * converting to milliseconds:
     * duration_as_hex = timer_ticks * <time to sleep in milliseconds>
     * NOTE: 0x00 is one count!
     */
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);

    /* set 8-bit timer registers */
    TCCR2B |= (1 << WGM22) | (1 << CS22) | (1 << CS21) | (1 << CS20);
    OCR2A |= duration_as_hex;

    TIMSK2 |= (1 << OCIE2A);

    sei();
    sleep_mode();
}


ISR(TIMER2_COMPA_vect)
{
    ;
}
