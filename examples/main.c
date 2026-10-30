#include "../src/timer0.h"

void main()
{
    TRISB.F0 = 0;
    RB0_bit = 0;

    timer0_init();
    GIE_bit = 1;

    while (1)
    {
    }
}

void interrupt()
{
    if (timer0_handle_interrupt())
    {
        RB0_bit = !RB0_bit;
    }
}
