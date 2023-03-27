//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Petty
// Micro Lab 6 Part 2
// 03/21/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
void SetClk8(void);
int count, i;
void main(void)
{
    SetClk8();
    DDRJ |= 0xFF;
    DDRP = 0xFF;
    PTJ &= 0xFD;
    DDRB |= 0xFF; 
    PTB |= 0xFF;  
    PTP = 0xFF;

    RTICTL = 0x40; 
    CRGINT |= RTIE; 
    asm("cli");
    while (1);
}
// RTI interrupt service routine
interrupt void rtiISR(void)
{

    unsigned char SegPat[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

    CRGFLG = 0x80; // clear RTIF flag
    count = 0;
    i = 0;
    while (count < 9)
    {

        switch (count)
        {
        case 0:
        case 1:
        case 2:
            PTB |= 0xFF; 
            delayby100ms(4);
            PTB &= 0x00; 
            delayby100ms(4);
            count += 1;
            break;
        case 3:
        case 4:
        case 5:
            for (i = 0; i < 8; i++)
            {
                PTB = SegPat[i];
                delayby100ms(4);
            }
            count += 1;
            break;
        case 6:
        case 7:
        case 8:
            for (i = 7; i > -1; i--)
            {
                PTB = SegPat[i];
                delayby100ms(4);
            }
            count += 1;
            break;

        default:
            count = 0;
            break;
        }
    }
}
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
