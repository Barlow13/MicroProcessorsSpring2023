// Brady Barlow and Rebecca Petty
// MicoProcessor Lab 5 Part 2
// 03/07/2023
// ---------------------------------------------------------------------------------

#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\vectors12.h"

void SetClk8(void);
int cnt, i;
unsigned char SegPat[19] = {
    0x3F,    0x06,    0x5B,    0x4F,
    0x66,    0x6D,    0x7D,    0x07,
    0x7F,    0x67,    0x7F,    0x07,
    0x7D,    0x6D,    0x66,    0x4F,
    0x5B,    0x06,    0x3F,};
// ---------------------------------------------------------------------------------
void main(void)
{
    cnt = 0;
    i = 0;
    SetClk8();
    DDRB = 0xFF;
    DDRP = 0xFF;
    INTCR = 0xC0;
    asm("cli");

    while (1)
    {
        // For loop for the sequence pattern
        for (i = 0; i < 10; i++)
        {

            PTB = SegPat[i + cnt];
            PTP = 0xF7;
            delayby100ms(10);
        }
    }
}
// ---------------------------------------------------------------------------------
// watches for the push button interupt and will switch sequence pattern when pushed
interrupt void IRQISR(void)
{
    if (cnt == 0)
    {
        cnt = 9;
        i = -1;
    }
    else
    {
        cnt = 0;
        i = -1;
    }
}
// ---------------------------------------------------------------------------------
void SetClk8(void)
{
    SYNR = 0x02;
    REFDV = 0;
    PLLCTL = 0x60;
    while (!(CRGFLG & LOCK))
        ;
    CLKSEL |= PLLSEL;
}
