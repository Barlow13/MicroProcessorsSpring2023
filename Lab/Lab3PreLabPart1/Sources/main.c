// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// Brady Barlow and Rebecca Petty
// Micro Lab 3 Part 1
// 02/21/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"

void SetClk8(void);
unsigned char digit[4] = {0xFE, 0xFD, 0xFB, 0xF7};
unsigned char SegPat[4];
int ArrayIndex = 0;
int SumArray[14];
int SumAnswer = 0;
int i = 2;
int j = 0;
unsigned char hexConverter(int value);
void Pattern(int num, unsigned char arr[]);

void main(void)
{
    for (i; i < 200; i += 3)
    { // pattern array start index
        if (i % 5 == 0)
        {

            SumArray[ArrayIndex + 1] = i;
            ArrayIndex += 1;
        }
    }
    for (j; j < 14; j++)
    {
        SumAnswer += SumArray[j];
    }
    SumArray[13] = SumAnswer;

    Pattern(SumAnswer, SegPat);

    SetClk8();   // set E clock frequency to 24 MHz
    DDRB = 0xFF; // configure Port B for output
    DDRP = 0xFF; // configure Port P for output
    while (1)
    {
        for (i = 0; i < 4; i++)
        {
            PTB = SegPat[i];
            PTP = digit[i];
            delayby1ms(1);
        }
    }
}

// -------------------------------------------------------------------

unsigned char hexConverter(int value)
{
    unsigned int i;
    unsigned char temp;
    unsigned char hexValue[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    for (i = 0; i < 10; i++)
    {
        if (i == value)
        {
            temp = hexValue[i];
            break;
        }
    }
    return temp;
}

void Pattern(int num, unsigned char arr[])
{
    int a, b, c, d;
    unsigned char ones, tens, hundreds, thousands;
    a = num / 1000;
    thousands = hexConverter(a);
    arr[0] = thousands;
    b = (num / 100) % 10;
    hundreds = hexConverter(b);
    arr[1] = hundreds;
    c = (num / 10) % 10;
    tens = hexConverter(c);
    arr[2] = tens;
    d = num % 10;
    ones = hexConverter(d);
    arr[3] = ones;
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
