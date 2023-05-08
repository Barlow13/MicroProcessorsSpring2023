//--------------------------------------------------------------------------------------------
//
// Microprocessors Final Project: Interactive Music Keyboard
// Project Due Date: 05/09/2023
// Created by: Brady Barlow
// Acknowledgments: Me, Myself and I coupled in with lots of caffeine.
// 
// NOTE: The frequencys listed in this code were tuned to be within ±1 Hz of the true frequency
//       output of the buzzer. This was acomplished by multiplying a factor
//       of 1.13 to each orignal frequency.
//--------------------------------------------------------------------------------------------

#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\hcs12.h"
#include "C:\Users\brady\Documents\Repos\MicroProcessorsSpring2023\Lab\HCS12Utilities\delay.h"

// Initiliaze Every Function
void SetClk8(void);
void PlayTone(int iteration, int period);
void ClearLCD(void);
void SevenSegment(unsigned char First, unsigned char Second, unsigned char Third
  , unsigned char Fourth);

// Main Loop
int main(void)
{

  // Declaration Of Variables
  int ModeSelection = 0, index = 0, i = 0;

  unsigned char PTA_Array[4] = { 0x08, 0x04, 0x02, 0x01 };

  int NoteScale[12][2] = {
      {294, 340}, // C
      {311, 322}, // C#
      {328, 305}, // D
      {349, 287}, // D#
      {370, 270}, // E
      {391, 256}, // F
      {415, 241}, // F#
      {440, 227}, // G
      {464, 216}, // G#
      {494, 202}, // A
      {523, 191}, // A#
      {554, 181}  // B
  };

  int HappyBirthDay[12][2] = {
      {328 / 2, 305}, // D
      {328 / 2, 305}, // D
      {370 / 2, 270}, // E
      {328 / 2, 305}, // D
      {440 / 2, 227}, // G
      {415 / 2, 241}, // F#
      {328 / 2, 305}, // D
      {328 / 2, 305}, // D
      {370 / 2, 270}, // E
      {328 / 2, 305}, // D
      {494 / 2, 202}, // A
      {440 / 2, 227}, // G

  };

  int StarWars[16][2] = {
      {294, 340},     // C
      {440, 227},     // G
      {391 / 4, 256}, // F
      {370 / 4, 270}, // E
      {328 / 4, 305}, // D
      {294, 340},     // C
      {440 / 2, 227}, // G
      {391 / 4, 256}, // F
      {370 / 4, 270}, // E
      {328 / 4, 305}, // D
      {294, 340},     // C
      {440 / 2, 227}, // G
      {391 / 4, 256}, // F
      {370 / 4, 270}, // E
      {391 / 4, 256}, // F
      {328 / 4, 305}  // D

  };

  int RickRoll[13][2] = {
      {294, 340},     // C
      {328, 305},     // D
      {440 / 2, 227}, // G
      {328, 305},     // D
      {370, 270},     // E
      {440 / 8, 227}, // G
      {391 / 8, 256}, // F
      {370 / 8, 270}, // E
      {294, 340},     // C
      {328, 305},     // D
      {440 * 2, 227}, // G
      {494 / 8, 202}  // A

  };

  // Intial Startup for the program
  SetClk8(); // set E clock frequency to 24 MHz
  DDRT = 0xFF;
  ClearLCD();
  putsLCD("Please choose a");
  cmd2LCD(0xC0);
  putsLCD("keyboard mode.");
  delayby100ms(10);
  while (1) // Repeats Loop Forever
  {
    switch (ModeSelection) // Start of state machine that monitors ModeSelction value
    {
    default:
      DDRB |= 0xFF;
      PTB &= 0x00;
      DDRP |= 0xFF;
      DDRH = 0x00;
      DDRA |= 0x0F;
      PTA &= 0x00;
      ClearLCD();
      putsLCD("Press #1 Piano");
      cmd2LCD(0xC0);
      putsLCD("Press #2 Music");
      ModeSelection = 0;
      while (ModeSelection == 0)
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
        case 0x11: // Keypad button 1
          ModeSelection = 1;
          ClearLCD();
          putsLCD("Entering Mode 1");
          delayby100ms(5);
          break;
        case 0x12: // Keypad button 2
          ModeSelection = 2;
          ClearLCD();
          putsLCD("Entering Mode 2");
          delayby100ms(5);
          break;
          // The following keypad buttons return a wrong input response
        case 0x14:
        case 0x18:
        case 0x21:
        case 0x22:
        case 0x24:
        case 0x28:
        case 0x41:
        case 0x42:
        case 0x44:
        case 0x48:
        case 0x81:
        case 0x82:
        case 0x84:
        case 0x88:
          ClearLCD();
          putsLCD("Wrong Input");
          delayby100ms(5);
          ModeSelection = 3;
          break;
        }
      }
      break;
    case 1: // Mode 1
      ClearLCD();
      putsLCD("Press On keypad");
      cmd2LCD(0xC0);
      putsLCD("to play a note.");
      while (ModeSelection != 0)
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
        case 0x11: // Keypad button 1
          ClearLCD();
          putsLCD("Playing Note:C");
          PlayTone(294 * 2, 340);
          SevenSegment(0x3F, 0x5B, 0x7D, 0x5B); // 0262
          ModeSelection = 0;
          break;
        case 0x12: // Keypad button 2
          ClearLCD();
          putsLCD("Playing Note:E");
          PlayTone(370 * 2, 270);
          SevenSegment(0x3F, 0x4F, 0x4F, 0x3F); // 0330
          ModeSelection = 0;
          break;
        case 0x14: // Keypad button 3
          ClearLCD();
          putsLCD("Playing Note:G#");
          PlayTone(464 * 2, 216);
          SevenSegment(0x3F, 0x66, 0x06, 0x6D); // 0415
          ModeSelection = 0;
          break;
        case 0x21: // Keypad button 4
          ClearLCD();
          putsLCD("Playing Note:C#");
          PlayTone(311 * 2, 322);
          SevenSegment(0x3F, 0x5B, 0x07, 0x07); // 0277
          ModeSelection = 0;
          break;
        case 0x22: // Keypad button 5
          ClearLCD();
          putsLCD("Playing Note:F");
          PlayTone(391 * 2, 256);
          SevenSegment(0x3F, 0x4F, 0x66, 0x67); // 0349
          ModeSelection = 0;
          break;
        case 0x24: // Keypad button 6
          ClearLCD();
          putsLCD("Playing Note:A");
          PlayTone(494 * 2, 202);
          SevenSegment(0x3F, 0x66, 0x66, 0x3F); // 0440
          ModeSelection = 0;
          break;
        case 0x41: // Keypad button 7
          ClearLCD();
          putsLCD("Playing Note:D");
          PlayTone(328 * 2, 305);
          SevenSegment(0x3F, 0x5B, 0x67, 0x66); // 0294
          ModeSelection = 0;
          break;
        case 0x42: // Keypad button 8
          ClearLCD();
          putsLCD("Playing Note:F#");
          PlayTone(415 * 2, 241);
          SevenSegment(0x3F, 0x4F, 0x07, 0x3F); // 0370
          ModeSelection = 0;
          break;
        case 0x44: // Keypad button 9
          ClearLCD();
          putsLCD("Playing Note:A#");
          PlayTone(523 * 2, 191);
          SevenSegment(0x3F, 0x66, 0x7D, 0x7D); // 0466
          ModeSelection = 0;
          break;
        case 0x81: // Keypad button *
          ClearLCD();
          putsLCD("Playing Note:D#");
          PlayTone(349 * 2, 287);
          SevenSegment(0x3F, 0x4F, 0x06, 0x06); // 0311
          ModeSelection = 0;
          break;
        case 0x82: // Keypad button 0
          ClearLCD();
          putsLCD("Playing Note:G");
          PlayTone(440 * 2, 227);
          SevenSegment(0x3F, 0x4F, 0x67, 0x5B); // 0392
          ModeSelection = 0;
          break;
        case 0x84: // Keypad button #
          ClearLCD();
          putsLCD("Playing Note:B");
          PlayTone(554 * 2, 181);
          SevenSegment(0x3F, 0x66, 0x67, 0x66); // 0494
          ModeSelection = 0;
          break;
        case 0x18:
        case 0x28:
        case 0x48:
        case 0x88:
          ClearLCD();
          putsLCD("Wrong Input");
          delayby100ms(5);
          ModeSelection = 0;
          break;
        }
      }
      break;
    case 2:
      index = 0;
      ClearLCD();
      putsLCD("Push a button");
      cmd2LCD(0xC0);
      putsLCD("to play a song.");

      while (index == 0)
      {
        if ((PTH & 0x01) == 0x00) // Push Button 0
        {
          ClearLCD();
          putsLCD("Playing:");
          cmd2LCD(0xC0);
          putsLCD("Musical Scale");
          for (i = 0; i <= 11; i++)
          {

            PlayTone(NoteScale[i][0], NoteScale[i][1]);
          }
          for (i = 10; i >= 0; i--)
          {

            PlayTone(NoteScale[i][0], NoteScale[i][1]);
          }
          SevenSegment(0x54, 0x5C, 0x78, 0x79);
          index = 1;
          ModeSelection = 0;
        }
        else if ((PTH & 0x02) == 0x00) // Push Button 1
        {
          ClearLCD();
          putsLCD("Playing:");
          cmd2LCD(0xC0);
          putsLCD("Happy B-Day");
          for (i = 0; i <= 11; i++)
          {

            PlayTone(HappyBirthDay[i][0], HappyBirthDay[i][1]);
          }
          SevenSegment(0x76, 0x7C, 0x5E, 0x00);
          index = 1;
          ModeSelection = 0;
        }
        else if ((PTH & 0x04) == 0x00) // Push Button 2
        {
          ClearLCD();
          putsLCD("Playing:");
          cmd2LCD(0xC0);
          putsLCD("Star Wars");
          for (i = 0; i <= 15; i++)
          {

            PlayTone(StarWars[i][0], StarWars[i][1]);
          }
          SevenSegment(0x6D, 0x78, 0x77, 0x50);
          index = 1;
          ModeSelection = 0;
        }
        else if ((PTH & 0x08) == 0x00) // Push Button 3
        {
          ClearLCD();
          putsLCD("Playing:");
          cmd2LCD(0xC0);
          putsLCD("Rick Roll");
          for (i = 0; i <= 12; i++)
          {

            PlayTone(RickRoll[i][0], RickRoll[i][1]);
          }
          for (i = 0; i <= 11; i++)
          {

            PlayTone(RickRoll[i][0], RickRoll[i][1]);
          }
          SevenSegment(0x00, 0x38, 0x3F, 0x38);
          index = 1;
          ModeSelection = 0;
        }
        else
        {
          index = 0;
        }
      }
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------
// This function enables PLL and use an 8-MHz crystal oscillator to
// generate 24-MHz E clock.
//--------------------------------------------------------------------------------------------
void SetClk8(void)
{
  SYNR = 0x02;   // set SYSCLK to 24 MHz from a 4-MHz oscillator
  REFDV = 0;     // "
  PLLCTL = 0x60; // turn on PLL, set automatic
  while (!(CRGFLG & LOCK))
    ;
  CLKSEL |= PLLSEL; // clock derived from PLL
}

//--------------------------------------------------------------------------------------------
// This function plays a desired frequency on the buzzer.
// The iteration can be put in as the exact frequency of a 
// note and the period must be entered in a 10us interval it will chirp for 2 seconds
//--------------------------------------------------------------------------------------------
void PlayTone(int iteration, int period_10us)
{

  for (; iteration > 0; iteration--)
  {
    PTT = 0x20;
    delayby10us(period_10us / 2);
    PTT = 0x00;
    delayby10us(period_10us / 2);
  }
}

//--------------------------------------------------------------------------------------------
// This function was used to simplify the code by clearing the LCD screen and getting it
// prepared to display something new.
//--------------------------------------------------------------------------------------------
void ClearLCD(void)
{
  openLCD();
  delayby10ms(10);
  cmd2LCD(0x01);
  delayby10ms(5);
}

//--------------------------------------------------------------------------------------------
// This function controls the seven segemnt display. By giving the proper hex value for 
// each digit it will be displayed for 2 seconds on the display.
//--------------------------------------------------------------------------------------------
void SevenSegment(unsigned char First, unsigned char Second,
  unsigned char Third, unsigned char Fourth)
{
  int loop = 0;
  for (loop = 0; loop < 500; loop++)
  {
    PTB = First;
    PTP = 0xFE;
    delayby1ms(1);
    PTB = Second;
    PTP = 0xFD;
    delayby1ms(1);
    PTB = Third;
    PTP = 0xFB;
    delayby1ms(1);
    PTB = Fourth;
    PTP = 0xF7;
    delayby1ms(1);
  }
}