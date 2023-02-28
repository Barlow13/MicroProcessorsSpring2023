//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Petty
// Micro Lab 4 Part 1
// 02/28/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"

void SetClk8(void);
int main(void)
{
    int loop_counts;
    SetClk8();   // set E clock frequency to 24 MHz
    DDRT = 0xFF; // configure PORT T for output

    while (1) // Repeats Loop Forever
    {
        loop_counts = 100;
        while (loop_counts > 0) // 100 Hz
        {
            PTT = 0x20;
            delayby1ms(10);
            PTT = 0x00;
            delayby1ms(10);
            loop_counts--;
        }
        delayby100ms(10);
        loop_counts = 250;
        while (loop_counts > 0) // 250 Hz
        {
            PTT = 0x20;
            delayby1ms(4);
            PTT = 0x00;
            delayby1ms(4);
            loop_counts--;
        }
        delayby100ms(10);
        loop_counts = 500;
        while (loop_counts > 0) // 500 Hz
        {
            PTT = 0x20;
            delayby1ms(2);
            PTT = 0x00;
            delayby1ms(2);
            loop_counts--;
        }
        delayby100ms(10);
        loop_counts = 1000;
        while (loop_counts > 0) // 1000 Hz
        {
            PTT = 0x20;
            delayby1ms(1);
            PTT = 0x00;
            delayby1ms(1);
            loop_counts--;
        }
        delayby100ms(10);
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