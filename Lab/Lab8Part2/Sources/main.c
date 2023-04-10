//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Petty
// Micro Lab 8 Part 2
// 04/04/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\LCD.h"

unsigned char LCD_Setup[7] = {0x33, 0x32, 0x28, 0x06, 0x0E, 0x01, 0x80};
unsigned char LCD_Output[29] = {
    'M', 'i', 'c', 'r', 'o', 'p', 'r', 'o', 'c', 'e', 's', 's', 'o', 'r', 's', 0xC0,
    'L', 'a', 'b', ' ', '0', '4', '/', '4', '/', '2', '0', '2', '3'};
int index;

void SetClk8(void);
void main(void)
{
    SetClk8();
    DDRK = 0xFF;
    // Setup LCD Loop
    for (index = 0; index < 7; index++)
    {
        LCDControl(LCD_Setup[index]);
        delayby1ms(1);
    }

    for (index = 0; index < 29; index++)
    {
        if (index == 15)
        {
            LCDControl(LCD_Output[index]);
        }
        else
        {

            LCDData(LCD_Output[index]);
            delayby1ms(1);
        }
    }

    while (1)
        ;
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
