// Code from Example 7-2 used in this tutorial
#include <mc9s12dg256.h> /* derivative information */
void main(void) {
 unsigned char mynum[]= "012345ABCD"; //data is stored in RAM
 unsigned char z;
 DDRB = 0xFF; //make Port B an output
 for(z=0;z<10;z++)
 PORTB = mynum[z];
 while(1); //stay here forever
}