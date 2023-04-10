//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Pettty
// Micro Lab 8 Part 1
// 04/04/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\LCD.h"

void SetClk8(void);
void main(void)
{
    SetClk8(); // set E clock frequency to 24 MHz
    DDRK = 0xFF;
    LCDControl(0x33); // reset sequence provided by data sheet
    delayby1ms(1);
    LCDControl(0x32); // reset sequence provided by data sheet
    delayby1ms(1);
    LCDControl(0x28); // Function set to four bit data length
    // 2 line, 5 x 7 dot format
    delayby1ms(1);
    LCDControl(0x06); // entry mode set: incremental display, no shift
    delayby1ms(1);
    LCDControl(0x0E); // Display set: display on, cursor on, blink off
    delayby1ms(1);
    LCDControl(0x01); // Clear display
    delayby1ms(1);
    LCDControl(0x80); // set start position, home position
    delayby1ms(1);
    LCDData('H');
    delayby1ms(1);
    LCDData('E');
    delayby1ms(1);
    LCDData('L');
    delayby1ms(1);
    LCDData('L');
    delayby1ms(1);
    LCDData('O');
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
