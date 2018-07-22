#include <msp430.h> 
#include <pwmSong.h>
#include <DAC7571.h>
#include <Paper_Display.h>
/**
 * main.c
 */

void initIO(void){
    //Enable I/O P6.5 For ADC12
    P6DIR &= ~BIT5;
    P6SEL |= BIT5;
    //Enable S1 & S2
    P1DIR &= ~BIT2 & ~BIT3;
    P1REN |= BIT2 | BIT3;
    P1OUT |= BIT2 | BIT3;
    //Enable LED
    P1DIR |= BIT5;
    P1SEL |= BIT5;
    P2DIR |= BIT4 | BIT5;
    P2OUT &= ~BIT4;
    P2OUT |= BIT5;
    //Enable Musical LED L3
    P7DIR |= BIT4;
    P7SEL |= BIT4;
    //Enable S3 interrupt
    P2DIR &= ~BIT3;
    P2REN |= BIT3;
    P2OUT |= BIT3;
    P2IE |= BIT3;
    P2IES |= BIT3;
    P2IFG &= 0x00;
    //Enable L1 & L2
    P8DIR |= BIT1;
    P8OUT &= ~BIT1;
    P3DIR |= BIT7;
    P3OUT &= ~BIT7;
    //Enable TB0.6 output
    P3DIR |= BIT6;
    P3SEL |= BIT6;
    //Enable DAC7571
    P3DIR |= BIT0 | BIT1;
    P3OUT |= BIT0 | BIT1;
    P3REN |= BIT0 | BIT1;
}

void initTB(void){
    //TA0 is clocked by SMCLK 1MHz
    //Wave Output to LED P1.1
    TB0CTL |= TBSSEL__SMCLK | MC__UP | TBCLR;
    TB0CCR0 = 0 ;
    TB0CCR6 = 0;
    TB0CCTL6 = OUTMOD_3;
    TB0CCR6 = 0;
    TB0CCTL2 = OUTMOD_3;
}
void initClock(void){
    P5SEL |= BIT4+BIT5;                                         // ѡ�� XT1
            UCSCTL6 &= ~(XT1OFF);                                       // XT1 ����
            UCSCTL6 |= XCAP_3;                                          // Internal load cap
            P5SEL |= BIT2 + BIT3;                                       //XT2���Ź���ѡ��
            UCSCTL6 &= ~XT2OFF;                                         //��XT2
            while (SFRIFG1 & OFIFG)
            {                                                           //�ȴ�XT1��XT2��DCO�ȶ�
                UCSCTL7 &= ~(DCOFFG+XT1LFOFFG+XT2OFFG);
                SFRIFG1 &= ~OFIFG;
            }

            UCSCTL4 = SELA__XT1CLK + SELS__XT2CLK + SELM__XT2CLK;       //����DCO�������ܷ�

            UCSCTL1 = DCORSEL_5;                                        //6000kHz~23.7MHz
            UCSCTL2 = 20000000 / (4000000 / 8);                         //XT2Ƶ�ʽϸߣ���Ƶ����Ϊ��׼�ɻ�ø��ߵľ���
            UCSCTL3 = SELREF__XT2CLK + FLLREFDIV__8;                    //XT2����16��Ƶ����Ϊ��׼
            while (SFRIFG1 & OFIFG)
            {                                                           //�ȴ�XT1��XT2��DCO�ȶ�
                UCSCTL7 &= ~(DCOFFG+XT1LFOFFG+XT2OFFG);
                SFRIFG1 &= ~OFIFG;
            }
            UCSCTL5 = DIVA__1 + DIVS__1 + DIVM__1;                      //�趨����CLK�ķ�Ƶ
            UCSCTL4 = SELA__XT1CLK + SELS__DCOCLK + SELM__DCOCLK;       //�趨����CLK��ʱ��Դ
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	initClock();
	initIO();
    PaperIO_Int();
    INIT_SSD1673();
    Init_buff();
    DIS_IMG(2);
	volatile unsigned i = 50;
	volatile int j = 0;
	while(1){
	    for(i=0;i<23935;i++){
	        DACValue(wave[i]);
	        __delay_cycles(1800);
	    }
	    for(i=0;i<19998;i++){
	                DACValue(wave1[i]);
	                __delay_cycles(1800);
	            }
	}
	return 0;
}
