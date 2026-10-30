#include "timer0.h"

#define TIMER0_INTERVAL_OVERFLOWS 122

static unsigned char overflow_count = 0;

void timer0_init(void)
{
    OPTION_REG = (OPTION_REG & 0xC0) | 0x03;
    TMR0 = 0;
    overflow_count = 0;
    T0IF_bit = 0;
    T0IE_bit = 1;
}

unsigned char timer0_handle_interrupt(void)
{
    if (!T0IF_bit)
    {
        return 0;
    }

    T0IF_bit = 0;

    if (++overflow_count >= TIMER0_INTERVAL_OVERFLOWS)
    {
        overflow_count = 0;
        return 1;
    }

    return 0;
}
