//----------------------------------------------------------------------------------
// Brady Barlow
// Micro LCD.c
// 03/27/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\lcd.h"

void LCDControl(unsigned char command)
{
    unsigned char x;

    x = (command & 0xF0) >> 2;   // shift high nibble to center of byte for Pk5-Pk2
    LCD_DATA = LCD_DATA & ~0x3C; // clear bits Pk5-Pk2
    LCD_DATA = LCD_DATA | x;     // sends high nibble to PORTK
    delayby1ms(1);
    LCD_CTRL = LCD_CTRL & ~RS; // set RS to command (RS=0)
    delayby1ms(1);
    ;
    LCD_CTRL = LCD_CTRL | EN; // raise enable
    delayby1ms(5);
    LCD_CTRL = LCD_CTRL & ~EN;   // Drop enable to capture command
    delayby1ms(15);              // wait
    x = (command & 0x0F) << 2;   // shift low nibble to center of byte for Pk5-Pk2
    LCD_DATA = LCD_DATA & ~0x3C; // clear bits Pk5-Pk2
    LCD_DATA = LCD_DATA | x;     // send low nibble to PORTK
    LCD_CTRL = LCD_CTRL | EN;    // raise enable
    delayby1ms(5);
    LCD_CTRL = LCD_CTRL & ~EN; // drop enable to capture command
    delayby1ms(15);
}
void LCDData(unsigned char data)
{

    unsigned char x;

    x = (data & 0xF0) >> 2;
    LCD_DATA = LCD_DATA & ~0x3C;
    LCD_DATA = LCD_DATA | x;
    delayby1ms(1);
    LCD_CTRL = LCD_CTRL | RS;
    delayby1ms(1);
    LCD_CTRL = LCD_CTRL | EN;
    delayby1ms(1);
    LCD_CTRL = LCD_CTRL & ~EN;
    delayby1ms(5);

    x = (data & 0x0F) << 2;
    LCD_DATA = LCD_DATA & ~0x3C;
    LCD_DATA = LCD_DATA | x;
    LCD_CTRL = LCD_CTRL | EN;
    delayby1ms(5);
    LCD_CTRL = LCD_CTRL & ~EN;
    delayby1ms(15);
}
