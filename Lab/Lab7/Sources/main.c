//----------------------------------------------------------------------------------
// Brady Barlow
// Micro PreLab 7
// 03/27/2023
//----------------------------------------------------------------------------------
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"

void main(void)
{
    int LeftSegment = 10, RightSegment = 10, i = 0, index = 0;
    unsigned char SegPat[11] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00};
    unsigned char PTA_Array[4] = {0x08, 0x04, 0x02, 0x01};
    DDRB |= 0xFF; // configure PB pins for output
    PTB &= 0x00;  // Port B pins set to low
    DDRP |= 0xFF; // Configure Port P for output.
    DDRA |= 0x0F; // Port A pins configured upper for input, and lower for output.
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
        case 0x11: // button 0, display 0
            LeftSegment = 10;
            RightSegment = 0;
            break;
        case 0x12: // button 1, display 1
            LeftSegment = 10;
            RightSegment = 1;
            break;
        case 0x14: // button 2, display 2
            LeftSegment = 10;
            RightSegment = 2;
            break;
        case 0x18: // button 3, display 3
            LeftSegment = 10;
            RightSegment = 3;
            break;
        case 0x21: // button 4, display 4
            LeftSegment = 10;
            RightSegment = 4;
            break;
        case 0x22: // button 5, display 5
            LeftSegment = 10;
            RightSegment = 5;
            break;
        case 0x24: // button 6, display 6
            LeftSegment = 10;
            RightSegment = 6;
            break;
        case 0x28: // button 7, display 7
            LeftSegment = 10;
            RightSegment = 7;
            break;
        case 0x41: // button 8, display 8
            LeftSegment = 10;
            RightSegment = 8;
            break;
        case 0x42: // button 9, display 9
            LeftSegment = 10;
            RightSegment = 9;
            break;
        case 0x44: // button 10, display 10
            LeftSegment = 1;
            RightSegment = 0;
            break;
        case 0x48: // button 11, display 11
            LeftSegment = 1;
            RightSegment = 1;
            break;
        case 0x81: // button 12, display 12
            LeftSegment = 1;
            RightSegment = 2;
            break;
        case 0x82: // button 13, display 13
            LeftSegment = 1;
            RightSegment = 3;
            break;
        case 0x84: // button 14, display 14
            LeftSegment = 1;
            RightSegment = 4;
            break;
        case 0x88: // button 15, display 15
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
