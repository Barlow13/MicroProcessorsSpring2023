//----------------------------------------------------------------------------------
// Brady Barlow
// Micro Lab 9 Part 2
// 04/11/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\LCD.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\lcd_util.h"

void SetClk8(void);
void main(void)
{
    DDRB = 0x0F;
    DDRP = 0x03;
    PTB = 0x00;
    PTP = 0x03;
    

    while (1)
    {
        int i;

        // CW Full-Step
        for (i = 0; i < 25; ++i)
        {
            PTB = 0x09;
            delayby1ms(50);

            PTB = 0x0C;
            delayby1ms(50);

            PTB = 0x06;
            delayby1ms(50);

            PTB = 0x03;
            delayby1ms(50);
        }

        // CCW Full-Step
        for (i = 0; i < 25; ++i)
        {
            PTB = 0x03;
            delayby1ms(50);

            PTB = 0x06;
            delayby1ms(50);

            PTB = 0x0c;
            delayby1ms(50);

            PTB = 0x09;
            delayby1ms(50);
        }

        // CW Half-Step
        for (i = 0; i < 13; ++i)
        {
            PTB = 0x08;
            delayby1ms(48);

            PTB = 0x0C;
            delayby1ms(48);

            PTB = 0x04;
            delayby1ms(48);

            PTB = 0x06;
            delayby1ms(48);

            PTB = 0x02;
            delayby1ms(48);

            PTB = 0x03;
            delayby1ms(48);

            PTB = 0x01;
            delayby1ms(48);

            PTB = 0x09;
            delayby1ms(48);
        }

        // CCW Half-Step
        for (i = 0; i < 13; ++i)
        {
            PTB = 0x09;
            delayby1ms(48);

            PTB = 0x01;
            delayby1ms(48);

            PTB = 0x03;
            delayby1ms(48);

            PTB = 0x02;
            delayby1ms(48);

            PTB = 0x06;
            delayby1ms(48);

            PTB = 0x04;
            delayby1ms(48);

            PTB = 0x0C;
            delayby1ms(48);

            PTB = 0x08;
            delayby1ms(48);
        }
    }
}
// This function enables PLL and use an 8-MHz crystal oscillator to
// generate 24-MHz E clock.
//
void SetClk8(void)
{
    SYNR = 0x02;   // set SYSCLK to 24 MHz from a 4-MHz oscillator
    REFDV = 0;     // "
    PLLCTL = 0x60; // turn on PLL, set automatic
    while (!(CRGFLG & LOCK))
        ;
    CLKSEL |= PLLSEL; // clock derived from PLL
}
