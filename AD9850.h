#ifndef _AD9850_H
#define _AD9850_H
#include "stm32f10x.h"  //改成自己32的hal库头文件
typedef unsigned char u8;


#define AD9850_CONTROL_PORT  GPIOA
#define AD9850_FQUD   GPIO_Pin_3  //改成自己连接的引脚
#define AD9850_WCLK   GPIO_Pin_4  //改成自己连接的引脚
#define AD9850_DATA   GPIO_Pin_8  //改成自己连接的引脚  和D7相连
#define AD9850_RST    GPIO_Pin_5  //改成自己连接的引脚

#define AD9850_WCLK_H	GPIO_WriteBit(AD9850_CONTROL_PORT, AD9850_WCLK, 1)
#define AD9850_WCLK_L	GPIO_WriteBit(AD9850_CONTROL_PORT, AD9850_WCLK, 0)
#define AD9850_FQUD_H	GPIO_WriteBit(AD9850_CONTROL_PORT, AD9850_FQUD, 1)
#define AD9850_FQUD_L	GPIO_WriteBit(AD9850_CONTROL_PORT, AD9850_FQUD, 0)
#define AD9850_DATA_H	GPIO_WriteBit(AD9850_CONTROL_PORT, AD9850_DATA, 1)
#define AD9850_DATA_L	GPIO_WriteBit(AD9850_CONTROL_PORT, AD9850_DATA, 0)
#define AD9850_RESET_H	GPIO_WriteBit(AD9850_CONTROL_PORT, AD9850_RST, 1)
#define AD9850_RESET_L	GPIO_WriteBit(AD9850_CONTROL_PORT, AD9850_RST, 0)


void AD9850_Delay(unsigned int z); 
void AD9850_Write(unsigned char w0,double frequence);
void AD9850_Init(void);

#endif
