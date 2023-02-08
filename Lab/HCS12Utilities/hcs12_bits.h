/* flash and EEPROM memory commands */
#define     Program      0x20           //program a flash or eeprom word
#define     EraseVerify  0x05           //Erase and verify flash and EEPROM, BLANK bit will be set
#define     SectorErase  0x40           //Erase a sector of flash or EEPROM
#define     BulkErase    0x41           //Bulk erase the flash memory or EEPROM
#define     SectorModify 0x60           //Erase a sector (4 bytes), program a word (2 bytes)
/* definitions of bits */
#define     BIT7         0x80
#define     BIT6         0x40
#define     BIT5         0x20
#define     BIT4         0x10
#define     BIT3         0x08
#define     BIT2         0x04
#define     BIT1         0x02
#define     BIT0         0x01
#define     NOACCE       0x80
#define     PIPOE        0x20
#define     NECLK        0x10
#define     LSTRE        0x08
#define     RDWE         0x04
#define     MODC         0x80
#define     MODB         0x40
#define     MODA         0x20
#define     IVIS         0x08
#define     EMK          0x02
#define     EME          0x01
#define     PUPKE        0x80
#define     PUPEE        0x10
#define     PUPBE        0x02
#define     PUPAE        0x01
#define     RDPK         0x80
#define     RDPE         0x10
#define     RDPB         0x02
#define     RDPA         0x01
#define     ESTR         0x01
#define     EXSTR1       0x08
#define     EXSTR0       0x04
#define     ROMHM        0x02
#define     ROMON        0x01
#define     WRINT        0x10
#define     INTE         0x80
#define     INTC         0x40
#define     INTA         0x20
#define     INT8         0x10
#define     INT6         0x08
#define     INT4         0x04
#define     INT2         0x02
#define     INT0         0x01
#define     IRQE         0x80
#define     IRQEN        0x40
#define     BKEN         0x80
#define     BKFULL       0x40
#define     BKBDM        0x20
#define     BKTAG        0x10
#define     BK0RWE       0x08
#define     BK0RW        0x04
#define     BK1RWE       0x02
#define     BK1RW        0x01
#define     RTIF         0x80
#define     PROF         0x40
#define     LOCKIF       0x10
#define     LOCK         0x08
#define     TRACK        0x04
#define     SCMIF        0x02
#define     SCM          0x01
#define     RTIE         0x80
#define     LOCKIE       0x10
#define     SCMIE        0x02
#define     PLLSEL       0x80
#define     PSTP         0x40
#define     SYSWAI       0x20
#define     ROAWAI       0x10
#define     PLLWAI       0x08
#define     CWAI         0x04
#define     RTIWAI       0x02
#define     COPWAI       0x01
#define     CME          0x80
#define     PLLON        0x40
#define     AUTO         0x20
#define     ACQ          0x10
#define     PRE          0x04
#define     PCE          0x02
#define     SCME         0x01
#define     WCOP         0x80
#define     RSBCK        0x40
#define     RTIBYP       0x80
#define     COPBYP       0x40
#define     PLLBYP       0x10
#define     FCM          0x02
#define     TEN          0x80
#define     TSWAI        0x40
#define     TSFRZ        0x20
#define     TFFCA        0x10
#define     TOI          0x80           ; TCNT overflow interrupt enable
#define     TOF          0x80           ; TCNT overflow flag
#define     C7I          0x80
#define     C6I          0x40
#define     C5I          0x20
#define     C4I          0x10
#define     C3I          0x08
#define     C2I          0x04
#define     C1I          0x02
#define     C0I          0x01
#define     C7F          0x80
#define     C6F          0x40
#define     C5F          0x20
#define     C4F          0x10
#define     C3F          0x08
#define     C2F          0x04
#define     C1F          0x02
#define     C0F          0x01
#define     IC7          0x80
#define     IC6          0x40
#define     IC5          0x20
#define     IC4          0x10
#define     IC3          0x08
#define     IC2          0x04
#define     IC1          0x02
#define     IC0          0x01
#define     IOS7         0x80
#define     IOS6         0x40
#define     IOS5         0x20
#define     IOS4         0x10
#define     IOS3         0x08
#define     IOS2         0x04
#define     IOS1         0x02
#define     IOS0         0x01
#define     OC7          0x80
#define     NOVW7        0x80
#define     NOVW6        0x40
#define     NOVW5        0x20
#define     NOVW4        0x10
#define     NOVW3        0x08
#define     NOVW2        0x04
#define     NOVW1        0x02
#define     NOVW0        0x01
#define     OC6          0x40
#define     OC5          0x20
#define     OC4          0x10
#define     OC3          0x08
#define     OC2          0x04
#define     OC1          0x02
#define     OC0          0x01
#define     TCRE         0x08
#define     PAEN         0x40
#define     PAMOD        0x20
#define     PEDGE        0x10
#define     CLK1         0x08
#define     CLK0         0x04
#define     PAOVI        0x02
#define     PAI          0x01
#define     PAOVF        0x02
#define     PAIF         0x01
#define     MCZI         0x80
#define     MODMC        0x40
#define     RDMCL        0x20
#define     ICLAT        0x10
#define     FLMC         0x08
#define     MCEN         0x04
#define     MCPR1        0x02
#define     MCPR0        0x01
#define     MCZF         0x80
#define     POLF3        0x08
#define     POLF2        0x04
#define     POLF1        0x02
#define     POLF0        0x01
#define     PAEN3        0x08
#define     PAEN2        0x04
#define     PAEN1        0x02
#define     PAEN0        0x01
#define     TFMOD        0x08
#define     PACMX        0x04
#define     BUFEN        0x02
#define     LATQ         0x01
#define     TCBYP        0x02
#define     PBEN         0x40
#define     PBOVI        0x02
#define     PBOVF        0x02
#define     ADPU         0x80
#define     AFFC         0x40
#define     AWAI         0x20
#define     ETRIGLE      0x10
#define     ETRIGP       0x08
#define     ETRIG        0x04
#define     ASCIE        0x02
#define     ASCIF        0x01
#define     SCF          0x80
#define     ETORF        0x20
#define     FIFOR        0x10
#define     CON67        0x80
#define     CON45        0x40
#define     CON23        0x20
#define     CON01        0x10
#define     PSWAI        0x08
#define     PFRZ         0x04
#define     PWMIF        0x80
#define     PWMIE        0x40
#define     PWMRSTRT     0x20
#define     PWMLVL       0x10
#define     PWM7IN       0x04
#define     PWM7INL      0x02
#define     PWM7ENA      0x01
#define     PWME7		0x80
#define     PWME6		0x40
#define     PWME5		0x20
#define     PWME4		0x10
#define     PWME3		0x08
#define     PWME2		0x04
#define     PWME1		0x02
#define     PWME0		0x01
#define     PCLK7		0x80
#define     PCLK6		0x40
#define     PCLK5		0x20
#define     PCLK4		0x10
#define     PCLK3		0x08
#define     PCLK2		0x04
#define     PCLK1		0x02
#define     PCLK0		0x01
#define     PPOL7		0x80
#define     PPOL6		0x40
#define     PPOL5		0x20
#define     PPOL4		0x10
#define     PPOL3		0x08
#define     PPOL2		0x04
#define     PPOL1		0x02
#define     PPOL0		0x01
#define     CAE7		0x80
#define     CAE6		0x40
#define     CAE5		0x20
#define     CAE4		0x10
#define     CAE3		0x08
#define     CAE2		0x04
#define     CAE1		0x02
#define     CAE0		0x01

#define     TIEN         0x80   /* changed to TIEN to avoid duplication with the register TIE */
#define     TCIE         0x40
#define     RIE          0x20
#define     ILIE         0x10
#define     TE           0x08
#define     RE           0x04
#define     RWU          0x02
#define     SBK          0x01
#define     TDRE         0x80
#define     TC           0x40
#define     RDRF         0x20
#define     IDLE         0x10
#define     OR           0x08
#define     NF           0x04
#define     FE           0x02
#define     PF           0x01
#define     BRK13        0x04
#define     TXDIR        0x02
#define     RAF          0x01
#define     R8           0x80
#define     T8           0x40
#define     SPIF         0x80
#define     SPTEF        0x20
#define     MODF         0x10
#define     IBEN         0x80
#define     IBIE         0x40
#define     MSSL         0x20
#define     TXRX         0x10
#define     TXAK         0x08
#define     RSTA         0x04
#define     IBSWAI       0x01
#define     TCF          0x80
#define     IAAS         0x40
#define     IBB          0x20
#define     IBAL         0x10
#define     SRW          0x04
#define     IBIF         0x02
#define     RXAK         0x01
#define     IMSG         0x80
#define     CLKS         0x40
#define     IE           0x02
#define     WCM          0x01
#define     BDLCE        0x10
#define     BIDLE        0x01           /* idle bit of BDLC */
#define     CANE         0x80
#define     WUPIF        0x80
#define     CSCIF        0x40
#define     RSTAT1       0x20
#define     RSTAT0       0x10
#define     TSTAT1       0x08
#define     TSTAT0       0x04
#define     OVRIF        0x02
#define     RXF          0x01
#define     WUPIE        0x80
#define     CSCIE        0x40
#define     INITRQ       0x01
#define     INITAK       0x01
#define     RSTATE1      0x20
#define     RSTATE0      0x10
#define     TSTATE1      0x08
#define     TSTATE0      0x04
#define     OVRIE        0x02
#define     RXFIE        0x01
#define     TXE2         0x04
#define     TXE1         0x02
#define     TXE0         0x01
#define     TXEIE2       0x04
#define     TXEIE1       0x02
#define     TXEIE0       0x01
#define     TX2          0x04
#define     TX1          0x02
#define     TX0          0x01
#define     FDIVLD       0x80           /* clock divider loaded bit */
#define     EDIVLD       0x80           /*       "       */
#define     PRDIV8       0x40           /* enable divide by 8 bit */
#define     KEYEN        0x80           /* enable backdoor key to security */
#define     WRALL        0x10           /* write to all register banks */
#define     CBEIE        0x80           /* command buffer empty interrupt enable */
#define     CCIE         0x40           /* command completion interrupt enable */
#define     KEYACC       0x20           /* enable security key writing */
#define     FPOPEN       0x80           /* opens the flash for programming and erasure */
#define     EPOPEN       0x80           /* opens the EEPROM for programming and erasure */
#define     EPDIS        0x08           /* EEPROM protection address range disable */
#define     FPHDIS       0x20           /* flash protection higher address range disable */
#define     FPLDIS       0x04           /* flash protection lower address range disable */
#define     CBEIF        0x80           /* command buffer empty interrupt flag */
#define     CCIF         0x40           /* command complete interrupt flag */
#define     PVIOL        0x20           /* protection violation interrupt flag */
#define     ACCERR       0x10           /* access error flag */
#define     BLANK        0x04           /* array has been verified as erased */


#define TIOS_IOS0_MASK                  1
#define TIOS_IOS1_MASK                  2
#define TIOS_IOS2_MASK                  4
#define TIOS_IOS3_MASK                  8
#define TIOS_IOS4_MASK                  16
#define TIOS_IOS5_MASK                  32
#define TIOS_IOS6_MASK                  64
#define TIOS_IOS7_MASK                  128

/* end of bit definitions for 9s12DP256b */
