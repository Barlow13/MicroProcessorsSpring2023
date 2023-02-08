#include "c:\cwHCS12\include\hcs12.h"
/*************************************************************************************/
/* The following function outputs a character to the SPI0 interface.                 */
/*************************************************************************************/
void putcspi0 (char cx)
{    char temp;
     while(!(SPI0SR & SPTEF)); /* wait until write is permissible */
     SPI0DR = cx;              /* output the byte to the SPI */
     while(!(SPI0SR & SPIF));  /* wait until write operation is complete */
     temp = SPI0DR;            /* clear SPIF flag */
}
/************************************************************************************/
/* The following function outputs a string to the SPI0 interface.                   */
/************************************************************************************/
void putsspi0(char *ptr)
{
     while(*ptr) {   /* continue until all characters have been output */
          putcspi0(*ptr);
          ptr++;
     }
}
/************************************************************************************/
/* The following function reads a character from the SPI0 interface.                */
/************************************************************************************/
char getcspi0(void)
{
     while(!(SPI0SR & SPTEF)); /* wait until write is permissible */
     SPI0DR = 0x00; /* trigger 8 SCK pulses to shift in data */
     while(!(SPI0SR & SPIF));  /* wait until a byte has been shifted in */
     return SPI0DR; /* return the character and clear SPIF flag */
}
/************************************************************************************/
/* The following function reads a string of count bytes from the SPI interface.     */
/************************************************************************************/
void getsspi0(char *ptr, char count)
{
     while(count) {  /* continue while byte count is nonzero */
           *ptr++ = getcspi0(); /* get a byte and save it in buffer */
           count--;
     }
     *ptr = 0;     /* terminate the string with a NULL */
}
