#include "c:\cwHCS12\include\hcs12.h"
unsigned long int FindSqr (unsigned long int xval) 
{
    unsigned long int mask,temp,sar;
    unsigned int ix;
    mask = 0x8000; //Initialize mask for making bit value gussing
    sar  = 0;
    for (ix = 0; ix < 16; ix++){
        temp = sar | mask;
        if((temp * temp) <= xval)
            sar = temp;
        mask >>= 1;        
    }
    if ((xval - (sar * sar)) > ((sar+1)*(sar+1) - xval))
        sar += 1;    
    return sar;
}