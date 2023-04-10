//Part below is in file lcd.h
#define LCD_DATA PORTK
#define LCD_CTRL PORTK
#define RS 0x01
#define EN 0x02
void LCDControl(unsigned char);
void LCDData(unsigned char);