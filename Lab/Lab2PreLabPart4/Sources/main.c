// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// Brady Barlow
// PreLab 2 Part 4
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h" 

void SetClk8(void);
unsigned char SegPat[16] = {0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67,0x06, 0x5B, 0x4F, 0x66};
unsigned char digit[6] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF};
void main(void)
{
    int i, j, k;
    SetClk8();   // set E clock frequency to 24 MHz
    DDRB = 0xFF; // configure Port B for output
    DDRP = 0xFF; // configure Port P for output
    while (1)
    {
        for (i = 0; i < 10; i++)
        { // pattern array start index
            for (j = 0; j < 100; j++)
            { // repeat loop for each pattern sequence
                for (k = 0; k < 4; k++)
                {                        // select the display # to be lighted
                    PTB = SegPat[i + k]; // output segment pattern
                    PTP = digit[k];      // output digit select value
                    delayby1ms(1);       // display one digit for 1 ms
                }
            }
        }
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