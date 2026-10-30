# PIC Timer0 Example

Minimal Timer0 driver and interrupt example for the **Microchip PIC16F628A**, written in C for **mikroC PRO for PIC**.

## Configuration

| Parameter | Value |
| --- | --- |
| Microcontroller | PIC16F628A |
| Original compiler | mikroC PRO for PIC v7.2.0 |
| System clock | 4 MHz |
| Peripheral | Timer0 (8-bit) |
| Timer clock | Internal instruction clock (FOSC/4) |
| Prescaler | 1:16 |
| Example output | RB0 |

The example toggles an LED connected to RB0 approximately every **500 ms**. The full on/off cycle takes approximately **1 second**.

## Timer0 interface

- `timer0_init()` configures Timer0 with the internal instruction clock and a 1:16 prescaler, clears its pending flag and enables the Timer0 interrupt. Global interrupts are enabled by the application.
- `timer0_handle_interrupt()` is called from the application's `void interrupt()` function. It clears the Timer0 flag and returns `1` every 122 overflows, or `0` otherwise.

Only one application interrupt routine should be defined. Additional interrupt sources can be handled in that same routine.

## Timing

At a 4 MHz oscillator frequency, the instruction clock runs at 1 MHz. Timer0 overflows every 4.096 ms:

```text
256 counts × 16 / 1,000,000 = 4.096 ms
122 overflows × 4.096 ms = 499.712 ms
```

Timer0 runs continuously, without software reloads. The resulting interval is approximately 499.7 ms, assuming an accurate 4 MHz oscillator. This is an educational example, not a precision timebase.

## Build

1. Create a project in **mikroC PRO for PIC** targeting `PIC16F628A`.
2. Set the project clock to **4 MHz** and configure oscillator settings to match the physical circuit.
3. Add `src/timer0.c` and `examples/main.c` to the project, keeping `src/timer0.h` in place.
4. Build the project and program its generated HEX file into the device.

Connect an LED to RB0 through an appropriate current-limiting resistor.

## References

- [PIC16F627A/628A/648A datasheet (DS40044G)](https://ww1.microchip.com/downloads/en/DeviceDoc/40044G.pdf)
