/*
 * IIC.h
 *
 *  Created on: 2014-7-15
 *      Author: dean
 */
#include <msp430.h>
#ifndef IIC_H_
#define IIC_H_

#define SDA_H    P3OUT|=0x01
#define SDA_L    P3OUT&=~0x01
#define SCK_H    P3OUT|=0x02
#define SCK_L    P3OUT&=~0x02
void ioinit();
void delayiic(unsigned int z);
void start();
void stop();
void waitack();
void senddata(unsigned char data);
#endif /* IIC_H_ */
