//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Petty
// Micro Lab 10
// 04/018/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\LCD.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\lcd_util.h"
void SetClk8(void);
void main(void)
{
    unsigned long corrected_period, edge1, edge2, period, frequency;
    SetClk8();
    delayby1ms(1);
    openLCD();
    delayby10ms(10);
    while (1)
    {

        DDRB = 0xFF; // configure port B for output
        DDRP = 0xFF; // configure port P for output
        DDRH = 0x00;
        DDRA |= 0x0F;
        PTA = 0;

        TSCR1 = 0x90;  // enable timer and fast flag clear
        TSCR2 = 0x01;  // set prescaler to 32, no timer overflow interrupt
        TIOS &= ~IOS7; // select input-capture 0
        TCTL3 = 0xC0;  // prepare to capture the rising edge
        TFLG1 = C7F;   // clear C0F flag
        while (!(TFLG1 & C7F))
            ;        // wait for the arrival of the rising edge
        edge1 = TC7; // save the first edge
        while (!(TFLG1 & C7F))
            ; // wait for the arrival of the falling edge
        edge2 = TC7;
        period = edge2 - edge1;
        corrected_period = (period * 4) / 24;
        frequency = (1000000 / corrected_period);

        if ((PTH & 0x01) == 0x00)
        {
            cmd2LCD(0x01);
            delayby10ms(5);
            putsLCD("Width is ");
            delayby10ms(5);
            putcLCD((corrected_period / 1000) + 0x30);
            delayby10ms(5);
            putcLCD((corrected_period % 1000 / 100) + 0x30);
            delayby10ms(5);
            putcLCD((corrected_period % 1000 / 100 % 100 / 10) + 0x30);
            delayby10ms(5);
            putcLCD((corrected_period % 1000 / 100 % 100 / 10 % 10) + 0x30);
            delayby10ms(5);
            cmd2LCD(0xC0);
            putsLCD("Freq is ");
            putcLCD((frequency / 1000) + 0x30);
            delayby10ms(5);
            putcLCD((frequency % 1000 / 100) + 0x30);
            delayby10ms(5);
            putcLCD((frequency % 1000 / 100 % 100 / 10) + 0x30);
            delayby10ms(5);
            putcLCD((frequency % 1000 / 100 % 100 / 10 % 10) + 0x30);
            delayby10ms(5);
        }
        delayby10ms(1);
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