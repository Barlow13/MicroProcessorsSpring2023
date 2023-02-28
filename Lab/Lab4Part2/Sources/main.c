//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Petty
// Micro Lab 3 Part 2
// 02/28/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"

void SetClk8(void);
unsigned char SegPat[5] = {0x00, 0x3F, 0x06, 0x5B, 0x4F};
unsigned char digit = 0xF7;

void main(void)
{

    SetClk8();
    DDRB = 0xFF;
    DDRP = 0xFF;
    DDRH = 0x00;

    while (1)
    {

        if ((PTH & 0x01) == 0x00) // Button 0
        {

            PTB = SegPat[1];
            PTP = digit;
            delayby1ms(1);
        }
        else if ((PTH & 0x02) == 0x00) // Button 1
        {

            PTB = SegPat[2];
            PTP = digit;
            delayby1ms(1);
        }
        else if ((PTH & 0x04) == 0x00) // Button 2
        {

            PTB = SegPat[3];
            PTP = digit;
            delayby1ms(1);
        }
        else if ((PTH & 0x08) == 0x00) // Button 3
        {

            PTB = SegPat[4];
            PTP = digit;
            delayby1ms(1);
        }
        else
        {
            // No Button Pushed
            PTB = SegPat[0];
            PTP = digit;
            delayby1ms(1);
        }
        delayby1ms(10); // Delays loop to add debounce to Button
    }
}

//---------------------------------------------------------------------------------------
// This function enables PLL and use an 8-MHz crystal oscillator to generate 24-MHz E Clock

void SetClk8(void)
{
    SYNR = 0x02;
    REFDV = 0;
    PLLCTL = 0x60;
    while (!(CRGFLG & LOCK))
        ;
    CLKSEL |= PLLSEL;
}