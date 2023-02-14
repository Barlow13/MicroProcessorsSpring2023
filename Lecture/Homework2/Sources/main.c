/* --------------------------------------------------------------------------------------------- */  
/*  E4.19 Write an instruction sequence to configure Port A and Port B for input and output,
    respectively; read the value of Port A and output the value to Port B.

*/

DDRA = 0x00;
DDRB = 0xFF;
PTA = PTB;
 
/* --------------------------------------------------------------------------------------------- */  

/*  E4.20 Give an instruction to configure the pins 7, 5, 1, and 0 of Port B for output and the
    remaining pins for input.
*/ 

// Port B has pins 0-7 so a binary representation of the configuring port 7,5,1, and 0 would be 
// starting with pin 7 as MSB [10100011] which is 163 in decimal but you must use hexadecimal so
// 163 in hexadecimal is 0xA3

DDRB = 0xA3;

/* --------------------------------------------------------------------------------------------- */  

/*  E5.1 Assume that ax = 83 and bx = 11. What is the value of ax/bx?
*/

ax = 83;
bx = 11;
ans = ax/bx // ans is 7


/* --------------------------------------------------------------------------------------------- */

/*  E5.2 Assume that ax = 97 and bx = ax % 23. What is the value of bx?
*/

ax = 97;
bx = ax % 23       
ans = bx // ans is 5

/* --------------------------------------------------------------------------------------------- */

/*  E5.3 Assume that ax = 0x39 and bx = ax ^ 0x79. What is the value of bx?
*/
ax = 0x39;
bx = ax ^ 0x79;
ans = bx // ans is 121 - 57 = 64 = 0x40

/* --------------------------------------------------------------------------------------------- */

/*  E5.5 Assume that ax = 0x6B and bx = ax & 0xDE. What is the value of bx?
*/

ax = 0x6B;
bx = ax & 0xDE;
ans = bx; // ans is 0x4A or 74 decimal

/* --------------------------------------------------------------------------------------------- */

/*  E5.7 Write a C program to find the median and mode of an array of integers. When the array has
    an even number of elements, the median is defined as the average of the middle two elements.
    Otherwise, it is defined as the middle element of the array. The mode is the element that occurs
    most frequently. You need to sort the array in order to find the median
*/
  
#include <stdio.h>
#include <math.h>
#define n 8

int median, mode, count, i, j, k;
int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void ArraySort(int array[], int array_size);

int main(void)
{
    printf("Orignal Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    ArraySort(array, n);
    if ((n % 2) == 0)
        median = (array[n / 2 - 1] + array[n / 2]) / 2;
    else
        median = array[n / 2];
    count = 1;
    mode = array[0];
    for (i = 0; i < n; i++)
    {
        k = 1;
        for (j = i + 1; j < n; j++)
        {
            if (array[j] == array[i])
                k++;
        }
        if (k > count)
        {
            mode = array[i];
            count = k;
        }
    }
    printf("\n");
    printf("New Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Meadian: %d", median);
    printf("\n");
    printf("Mode: %d", mode);
    printf("\n");

    return 0;
}
void ArraySort(int array[], int array_size)
{
    int i, j, k;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                k = array[j + 1];
                array[j + 1] = array[j];
                array[j] = k;
            }
        }
    }
}

/* --------------------------------------------------------------------------------------------- */