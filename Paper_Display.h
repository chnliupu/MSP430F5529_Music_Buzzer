#include <msp430.h>

#define nRST_H	P1OUT|=BIT4
#define nRST_L	P1OUT&=~BIT4
#define nCS_H	P3OUT|=BIT2
#define nCS_L	P3OUT&=~BIT2
#define SDA_H	P3OUT|=BIT3
#define SDA_L	P3OUT&=~BIT3
#define SCLK_H   P2OUT|=BIT7
#define SCLK_L   P2OUT&=~BIT7
#define nDC_H 	P3OUT|=BIT4
#define nDC_L 	P3OUT&=~BIT4
#define nBUSY	P2IN & BIT2

extern volatile unsigned char DisBuffer[250*16];

void SPI4W_WRITECOM(unsigned char INIT_COM);
void SPI4W_WRITEDATA(unsigned char INIT_DATA);
void SPI4W_WRITE(unsigned char INIT_COM,unsigned char INIT_DATA);
void MYRESET(void);
void WRITE_LUT(void);
void INIT_SSD1673(void);
void DIS_IMG(unsigned char num);
void FIRST_PICTURE(void);
void IMAGE_WRITE(unsigned char patt_num);
void DELAY_100nS(unsigned int delaytime);
void DELAY_mS(unsigned int delaytime);
void DELAY_S(unsigned int delaytime);
void DELAY_M(unsigned int delaytime);
void RING(void);
void READBUSY(void);
void closebump(void);
void DisplayString(const char* str, unsigned int sx, unsigned int sy);
void enterdeepsleep(void);
void Init_buff(void);
void SET_EYEONE(void);
void PaperIO_Int(void);
void display(unsigned char *str, //字符串
             unsigned int xsize,  //x方向位置
			 unsigned int ysize,  //y方向位置
			 unsigned int font,   //字体 0,1,2
			 unsigned int size,   //字号 0,1
			 unsigned int reverse,//反显 0 正常显示， 1 反显
			 unsigned int fresh   //立即刷新
			 );
