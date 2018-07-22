/*
 * IIC.c
 *
 *  Created on: 2014-7-15
 *      Author: dean
 */
#include "IIC.h"

void delayiic(unsigned int z)
{
	unsigned int x,y;
	for(x=z;x>0;x--)
		for(y=100;y>0;y--)
			P8OUT&=~0x04;
}
void start()
{
	SCK_H;
	//delay(10);
	SDA_H;
	//delay(10);
	SDA_L;
}
void stop()
{
	SCK_H;
	SDA_L;
	//delay(10);
	SDA_H;
}
void waitack()
{
	 //P3DIR &=~ 0x01;
	 SCK_H;
	 //delay(5);
	 SCK_L;
//	 while(P3IN&0x01==0x01);
	 //delay(5);
	// P3DIR |= 0x01;
}
void senddata(unsigned char data)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SCK_L;
		//delay(5);
		if((data&0x80)==0x80)
		{
			SDA_H;
		}
		else
		{
			SDA_L;
		}
		data<<=1;
		//delay(5);
		SCK_H;
		//delay(5);
	}
	SCK_L;
}

