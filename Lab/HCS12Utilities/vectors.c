extern void near rtiISR(void);
#pragma CODE_SEG __NEAR_SEG NON_BANKED
#pragma CODE_SEG DEFAULT // Change code section to DEFAULT.
typedef void (*near tIsrFunc)(void);
const tIsrFunc _vect[] @0xFFF0 = {
rtiISR
};