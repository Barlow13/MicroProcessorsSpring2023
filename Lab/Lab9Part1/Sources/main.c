//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Petty
// Micro Lab 9 Part 1
// 04/11/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\LCD.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\lcd_util.h"

void SetClk8(void);
char KeyPad(void);
int StrtoInt(char string);
void IntToChar(int number);
int fourDigitConverter(char a, char b, char c, char d);
char pressed;

void main(void)
{
    char FirstDigit = 0, SecondDigit = 0, ThirdDigit = 0, FourthDigit = 0,
         Loop = 0, FirstDigit2 = 0, SecondDigit2 = 0, ThirdDigit2 = 0, FourthDigit2 = 0;
    int Input1 = 0, Input2 = 0, ans = 0;
    SetClk8();
    delayby1ms(1);
    openLCD();
    delayby10ms(10);
    DDRA |= 0x0F;
    PTA = 0;

    while (1)
    {
        Loop = 0;
        while (Loop == 0)
        {

            cmd2LCD(0x01);
            delayby10ms(10);
            putsLCD("Enter an integer:");
            delayby10ms(10);
            cmd2LCD(0xC0);
            delayby10ms(10);
            FirstDigit = KeyPad();
            delayby10ms(15);
            putcLCD(FirstDigit + 0x30);
            delayby10ms(15);
            SecondDigit = KeyPad();
            delayby10ms(15);
            putcLCD(SecondDigit + 0x30);
            delayby10ms(15);
            ThirdDigit = KeyPad();
            delayby10ms(15);
            putcLCD(ThirdDigit + 0x30);
            delayby10ms(15);
            FourthDigit = KeyPad();
            delayby10ms(15);
            putcLCD(FourthDigit + 0x30);
            delayby10ms(15);
            while (Loop != 1)
            {
                if (KeyPad() == 0x14)
                {
                    delayby10ms(15);
                    Loop = 1;
                    break;
                }
                if ((KeyPad() != 0x14) && (KeyPad() != 0))
                {
                    cmd2LCD(0x01);
                    delayby10ms(15);
                    putsLCD("D not pressed");
                    delayby10ms(15);
                    cmd2LCD(0xC0);
                    putsLCD("Press D to cont");
                    delayby10ms(15);
                    break;
                }
            }
        }
        while (Loop == 1)
        {
            cmd2LCD(0x01);
            delayby10ms(15);
            putsLCD("Enter a 2nd int:");
            delayby10ms(15);
            cmd2LCD(0xC0);
            delayby10ms(15);
            FirstDigit2 = KeyPad();
            delayby10ms(15);
            putcLCD(FirstDigit2 + 0x30);
            delayby10ms(15);
            SecondDigit2 = KeyPad();
            delayby10ms(15);
            putcLCD(SecondDigit2 + 0x30);
            delayby10ms(15);
            ThirdDigit2 = KeyPad();
            delayby10ms(15);
            putcLCD(ThirdDigit2 + 0x30);
            delayby10ms(15);
            FourthDigit2 = KeyPad();
            delayby10ms(15);
            putcLCD(FourthDigit2 + 0x30);
            delayby10ms(15);
            while (Loop != 2)
            {
                if (KeyPad() == 0x14)
                {
                    delayby10ms(15);
                    Loop = 2;
                    break;
                }
                if ((KeyPad() != 0x14) && (KeyPad() != 0))
                {
                    cmd2LCD(0x01);
                    delayby10ms(15);
                    putsLCD("D not pressed");
                    delayby10ms(15);
                    cmd2LCD(0xC0);
                    putsLCD("Press D to cont");
                    delayby10ms(15);
                    break;
                }
            }
        }
        Input1 = fourDigitConverter(FirstDigit, SecondDigit, ThirdDigit, FourthDigit);
        Input2 = fourDigitConverter(FirstDigit2, SecondDigit2, ThirdDigit2, FourthDigit2);
        ans = Input1 + Input2;
        cmd2LCD(0x01);
        delayby10ms(15);
        putsLCD("The sum of ");
        putcLCD(FirstDigit + 0x30);
        putcLCD(SecondDigit + 0x30);
        putcLCD(ThirdDigit + 0x30);
        putcLCD(FourthDigit + 0x30);
        cmd2LCD(0xC0);
        putsLCD("and ");
        putcLCD(FirstDigit2 + 0x30);
        putcLCD(SecondDigit2 + 0x30);
        putcLCD(ThirdDigit2 + 0x30);
        putcLCD(FourthDigit2 + 0x30);
        putsLCD(" is ");
        IntToChar(ans);
        delayby1ms(2000);
    }
}

void SetClk8(void)
{
    SYNR = 0x02;
    REFDV = 0;
    PLLCTL = 0x60;
    while (!(CRGFLG & LOCK))
        ;
    CLKSEL |= PLLSEL;
}

char KeyPad(void)
{
    unsigned char PTA_Array[4] = {0x08, 0x04, 0x02, 0x01};
    int index = 0, Continue = 0;

    while (Continue == 0)
    {
        if (index == 4)
        {
            index = 0;
        }

        PTA = PTA_Array[index];
        switch (PTA)
        {
        default:
            index++;
            Continue = 0;
            break;
        case 0x11: // button 0
            Continue = 1;
            return 1;
            break;
        case 0x12: // button 1
            Continue = 1;
            return 2;
            break;
        case 0x14: // button 2
            Continue = 1;
            return 3;
            break;
        case 0x18: // button 3
            Continue = 1;
            return 0x11;
            break;
        case 0x21: // button 4
            Continue = 1;
            return 4;
            break;
        case 0x22: // button 5
            Continue = 1;
            return 5;
            break;
        case 0x24: // button 6
            Continue = 1;
            return 6;
            break;
        case 0x28: // button 7
            Continue = 1;
            return 0x12;
            break;
        case 0x41: // button 8
            Continue = 1;
            return 7;
            break;
        case 0x42: // button 9
            Continue = 1;
            return 8;
            break;
        case 0x44: // button 10
            Continue = 1;
            return 9;
            break;
        case 0x48: // button 11
            Continue = 1;
            return 0x13;
            break;
        case 0x81: // button 12
            Continue = 1;
            return -6;
            break;
        case 0x82: // button 13
            Continue = 1;
            return 0;
            break;
        case 0x84: // button 14
            Continue = 1;
            return -13;
            break;
        case 0x88: // button 15
            Continue = 1;
            return 0x14;
            break;
        }
    }
}

int StrtoInt(char string)
{
    switch (string)
    {
    default:
        return 0;
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    }
}

void IntToChar(int number)
{
    int i;
    unsigned char digit[4];
    unsigned char numArray[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    digit[0] = numArray[number / 1000];
    digit[1] = numArray[(number % 1000) / 100];
    digit[2] = numArray[((number % 1000) % 100) / 10];
    digit[3] = numArray[((number % 1000) % 100) % 10];
    for (i = 0; i < 4; i++)
    {
        delayby1ms(1);
        putcLCD(digit[i]);
    }
}

int fourDigitConverter(char a, char b, char c, char d)
{
    int x, y, z, k;
    x = StrtoInt(a);
    y = StrtoInt(b);
    z = StrtoInt(c);
    k = StrtoInt(d);

    return ((x * 1000) + (y * 100) + (z * 10) + k);
}
