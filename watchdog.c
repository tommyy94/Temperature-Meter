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
void reset_system(void)
{
    MCUSR &= ~(1 << WDRF); /* clear WD reset flag */
    wdt_disable();
}


void wdt_init(void)
{
    cli();
    /* start timed sequence */
    WDTCSR = (1 << WDCE) | (1 << WDE);
    /* Set prescaler (timeout) value = 64K cycles (0.5s) */
    WDTCSR = (1 << WDE) | (1 << WDP2) | (1 << WDP0);
    
    sei();
    
    DDRB &= ~(1 << SYS_RESET_PIN);
    PORTB |= (1 << SYS_RESET_PIN);
    
    /* switch interrupts */
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (PCINT4);
    
    while(!(PINB & (1 << SYS_RESET_PIN))) { /* if switch is pressed */
        ; /* don't enable interrupts until switch is not pressed */
    }
}


ISR(PCINT0_vect)
{
    if(!(PINB & (1 << SYS_RESET_PIN))) { /* if switch is pressed */
        reset_system();
    }
}
