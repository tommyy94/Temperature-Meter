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
    wdt_reset();
    /* start timed sequence */
    WDTCSR = (1 << WDCE) | (1 << WDE);
    /* Set prescaler (timeout) value = 128K cycles (1.0s) */
    WDTCSR = (1 << WDP2) | (1 << WDP1);
    //WDTCSR = (1 << WDIE) | (1 << WDP2) | (1 << WDP1);
    
    DDRB &= ~(1 << SYS_RESET_PIN);
    PORTB |= (1 << SYS_RESET_PIN);
    
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (PCINT4);
    
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
    if(wdt_counter < 1) {
        wdt_reset();
    } else {
        /* immediate reset */
        wdt_counter = 0;
        WDTCSR = (1 << WDCE) | (1 << WDE);	/* Enable the WD Change Bit */
        WDTCSR = (1 << WDE) | (1 << WDP2) | (1 << WDP1);
    }
}


ISR(PCINT0_vect)
{
    if(!(PINB & (1 << SYS_RESET_PIN))) { /* if PINB4 is pressed */
        MCUSR = 0;
        wdt_disable();
        system_reset();
    } else {
        wdt_reset();
    }
}
