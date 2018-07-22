#include <msp430f5529.h> 
#include <song.h>
#include <player.h>

const unsigned int light[10]={1000,2000,1000,1200,2000,1000,3000,2200,600,100};
/**
 * main.c
 */

volatile int songFlag;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	initClock();
	initTB();
	initTA();
	initIO();
	initADC12();
    PaperIO_Int();
    INIT_SSD1673();
    Init_buff();
	DIS_IMG(2);
	volatile int i=0;
	for(i=0;i<10;i++){
	    TA0CCR4 = light[i];
		sound(welcome[i][0],welcome[i][1],welcome[i][2],welcome[i][3]);
	}
	volatile unsigned int value = 0;
	volatile unsigned int noise = 0;
	while(1){
		ADC12CTL0 |= ADC12SC;
		value = ADC12MEM0;
		noise = ADC12MEM1;
		noise = mwFilter(value);
		if(value < 20){
			TA0CCR4 = 0;
		}
		else{
			TA0CCR4 = value;
		}
		__disable_interrupt();
		if(!(P1IN&BIT2)){
			while(!(P1IN&BIT2));
			TA0CCR4 = 0;
			songFlag = 0;
			P8OUT |= BIT1;
			DIS_IMG(5);
			__enable_interrupt();
			for(i=0;i<75;i++){
				sound(bridalChorus[i][0],bridalChorus[i][1],bridalChorus[i][2],bridalChorus[i][3]);
				if(!(P1IN&BIT2)){
					while(!(P1IN&BIT2));
					break;
				}
			}
			DIS_IMG(2);
			P8OUT &= ~BIT1;
		}
		if(!(P1IN&BIT3)){
			while(!(P1IN&BIT3));
			TA0CCR4 = 0;
			songFlag = 1;
			P3OUT |= BIT7;
			DIS_IMG(3);
			__enable_interrupt();
			for(i=0;i<221;i++){
				sound(loveStory[i][0],loveStory[i][1],loveStory[i][2],loveStory[i][3]);
				if(!(P1IN&BIT3)){
					while(!(P1IN&BIT3));
					P3OUT &= ~BIT7;
					break;
				}
			}
			DIS_IMG(2);
			P3OUT &= ~BIT7;
		}
	}
	return 0;
}

#pragma vector = PORT2_VECTOR
__interrupt void pause(void){
	TB0CCR0 = 0;
	TB0CCR6 = 0;
	if(songFlag == 0){
		DIS_IMG(6);
	}
	else if(songFlag == 1){
		DIS_IMG(4);
	}
	while(1){
		if(!(P2IN&BIT3)){
			while(!(P2IN&BIT3));
			break;
		}
	}
	P2IFG &= 0x00;
	if(songFlag == 0){
		DIS_IMG(5);
	}
	else if(songFlag == 1){
		DIS_IMG(3);
	}
}







