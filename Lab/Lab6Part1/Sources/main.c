//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Petty
// Micro Lab 6 Part 1
// 03/21/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
void SetClk8(void);
char hiOrlo;
void main(void)
{
    SetClk8();
    hiOrlo = 0;
    DDRT |= 0x20;   // configure PT5 pin for output
    PTT |= 0x20;    // pull PT5 pin to high
    RTICTL = 0x40;  // set RTI timeout interval to about 1 ms
    CRGINT |= RTIE; // enable RTI interrupt
    asm("cli");
    while (1)
        ;
}
// RTI interrupt service routine
interrupt void rtiISR(void)
{
    CRGFLG = 0x80; // clear RTIF flag
    if (hiOrlo)
    {
        hiOrlo = 0;
        PTT |= 0x20; // pull pin high
    }
    else
    {
        hiOrlo = 1;
        PTT &= 0xDF; // pull pin low
    }
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