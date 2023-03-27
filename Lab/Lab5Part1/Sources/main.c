// Brady Barlow and Rebecca Petty
// MicoProcessor Lab 5 Part 1
// 03/07/2023
// -------------------------------------------------------------------

#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\vectors12.h"
void SetClk8(void);
unsigned char SegPat[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
int count;
void main(void)
{
    count = 0;
    SetClk8();    // set E clock frequency to 24 MHz
    DDRB = 0xFF;  // configure Port B for output
    DDRP = 0xFF;  // configure Port P for output
    INTCR = 0xC0; // enable interrupt on falling edge
    asm("cli");
    while (1)
    {
        PTB = SegPat[count]; // output segment pattern
        PTP = 0xF7;          // output digit select value
    }
}
interrupt void IRQISR(void)
{
    if (count != 9)
        count++;
    else
        count = 0;
}
// -------------------------------------------------------------------
// This function enables PLL and use an 8-MHz crystal oscillator to
// generate 24-MHz E clock.
// -------------------------------------------------------------------
void SetClk8(void)
{
    SYNR = 0x02;   // set SYSCLK to 24 MHz from a 4-MHz oscillator
    REFDV = 0;     // "
    PLLCTL = 0x60; // turn on PLL, set automatic
    while (!(CRGFLG & LOCK))
        ;
    CLKSEL |= PLLSEL; // clock derived from PLL
}
