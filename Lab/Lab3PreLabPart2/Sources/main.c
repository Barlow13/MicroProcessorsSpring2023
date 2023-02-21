// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// Brady Barlow and Rebecca Petty
// Micro Lab 3 Part 2
// 02/21/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"

void SetClk8(void);
unsigned char SegPat[14] = {0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x3F, 0x06, 0x5B, 0x4F, 0x66};
unsigned char digit[4] = {0xFE, 0xFD, 0xFB, 0xF7};
int i, j, k;

void main(void)
{

    SetClk8();
    DDRB = 0xFF;
    DDRP = 0xFF;

    // First Pattern
    PTB = SegPat[0];
    PTP = digit[0];
    delayby1ms(500);

    // Second Pattern
    for (i = 0; i <= 250; i++)
    {
        for (j = 0; j < 2; j++)
        {
            PTB = SegPat[j];
            PTP = digit[1 - j];
            delayby1ms(1);
        }
    }

    // Third Pattern
    for (i = 0; i <= 167; i++)
    {
        for (j = 0; j < 3; j++)
        {
            PTB = SegPat[j];
            PTP = digit[2 - j];
            delayby1ms(1);
        }
    }

    // Loop Pattern 4-10
    while (1)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 125; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    PTB = SegPat[i + k];
                    PTP = digit[3 - k];
                    delayby1ms(1);
                }
            }
        }
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