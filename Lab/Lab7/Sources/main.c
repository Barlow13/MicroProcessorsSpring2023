//----------------------------------------------------------------------------------
// Brady Barlow and Rebecca Petty
// Micro Lab 7
// 03/28/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"

void main(void)
{
    int LeftSegment = 10, RightSegment = 10, i = 0, index = 0;
    unsigned char SegPat[11] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00};
    unsigned char PTA_Array[4] = {0x08, 0x04, 0x02, 0x01};
    DDRB |= 0xFF;
    PTB &= 0x00; 
    DDRP |= 0xFF; 
    DDRA |= 0x0F; 
    PTA &= 0x00;

    while (1)
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
            break;
        case 0x11: // button 0
            LeftSegment = 10;
            RightSegment = 0;
            break;
        case 0x12: // button 1
            LeftSegment = 10;
            RightSegment = 1;
            break;
        case 0x14: // button 2
            LeftSegment = 10;
            RightSegment = 2;
            break;
        case 0x18: // button 3
            LeftSegment = 10;
            RightSegment = 3;
            break;
        case 0x21: // button 4
            LeftSegment = 10;
            RightSegment = 4;
            break;
        case 0x22: // button 5
            LeftSegment = 10;
            RightSegment = 5;
            break;
        case 0x24: // button 6
            LeftSegment = 10;
            RightSegment = 6;
            break;
        case 0x28: // button 7
            LeftSegment = 10;
            RightSegment = 7;
            break;
        case 0x41: // button 8
            LeftSegment = 10;
            RightSegment = 8;
            break;
        case 0x42: // button 9
            LeftSegment = 10;
            RightSegment = 9;
            break;
        case 0x44: // button 10
            LeftSegment = 1;
            RightSegment = 0;
            break;
        case 0x48: // button 11
            LeftSegment = 1;
            RightSegment = 1;
            break;
        case 0x81: // button 12
            LeftSegment = 1;
            RightSegment = 2;
            break;
        case 0x82: // button 13
            LeftSegment = 1;
            RightSegment = 3;
            break;
        case 0x84: // button 14
            LeftSegment = 1;
            RightSegment = 4;
            break;
        case 0x88: // button 15
            LeftSegment = 1;
            RightSegment = 5;
            break;
        }
        for (i = 0; i < 5; i++)
        {
            PTP = 0xF7;
            PTB = SegPat[RightSegment];
            delayby1ms(1);
            PTP = 0xFB;
            PTB = SegPat[LeftSegment];
            delayby1ms(1);
        }
    }
}
