/*******************************************************************************
*
* 1. NAME
*       watchdog.c
*
* 2. DESCRIPTION
*       When switch is pressed, reset the program.
*
*******************************************************************************/

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include "watchdog.h"

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///


/*******************************************************************************
*   FUNCTION DEFINITIONS                                                       *
*******************************************************************************/
void wdt_init(void)
{
    cli();
    WDTCSR = (1 << WDCE) | (1 << WDE);
    WDTCSR = (1 << WDCE) | (1 << WDIE) | (1 << WDP3) | (1 << WDP0);
    sei();
    wdt_counter = 0;
}


void get_mcusr(void)
{
    MCUSR = 0; /* clear WD reset flag */
    wdt_disable();
}


ISR(WDT_vect)
{
    wdt_counter++;
    if(wdt_counter < 60) {
        wdt_reset(); /* restart timer if under 60s */
    } else {
        /* immediate reset */
        wdt_counter = 0;
        wdt_reset();
        WDTCSR |= (1 << WDCE) | (1 << WDE);	/* Enable the WD Change Bit */
        WDTCSR |= (1 << WDE) | (1 << WDP0);	/* set reset flag WDE & 16ms WDP0 */
    }
}

/*
ISR(PCINT0_vect)
{
    if(!(PINB & (1 << SYS_RESET_PIN))) {

    } else if(PINB & (1 << SYS_RESET_PIN)) {
        wdt_reset();
    } else {
    }
}
*/
