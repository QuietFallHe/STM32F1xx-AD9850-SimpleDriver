#include "ad9850.h"
#include "stm32f10x.h" //改为自己32的头文件

void AD9850_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = AD9850_FQUD | AD9850_WCLK | AD9850_DATA | AD9850_RST;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);

	AD9850_WCLK_L;
	AD9850_FQUD_L;

	AD9850_RESET_L;
	AD9850_RESET_H;
	AD9850_Delay(0xffff);		
	AD9850_RESET_L;

	AD9850_WCLK_L;
	AD9850_WCLK_H;
	AD9850_Delay(0xffff);		
	AD9850_WCLK_L;

	AD9850_FQUD_L;
	AD9850_FQUD_H;
	AD9850_Delay(0xffff);		
	AD9850_FQUD_L;
}

void AD9850_Write(u8 w0,double frequence)
{
	unsigned char i;
	long int y;
	double x;
	u8 wdata;
	x=4294967295U/(72);//修改获得合适频率
	frequence=frequence/1000000;
	frequence=frequence*x;
	y=frequence;
	//写w4数据
	wdata=(y>>=0);
	for(i=0;i<8;i++)
	{
		if(wdata&0x01)
			AD9850_DATA_H;
		else
			AD9850_DATA_L;
		AD9850_WCLK_H;
		wdata=wdata>>1;
		AD9850_WCLK_L;
	}
	wdata=(y>>8);
	for(i=0;i<8;i++)
	{
		if(wdata&0x01)
			AD9850_DATA_H;
		else
			AD9850_DATA_L;
		AD9850_WCLK_H;
		wdata=wdata>>1;
		AD9850_WCLK_L;
	}
	wdata=y>>16;
	for(i=0;i<8;i++)
	{
		if(wdata&0x01)
			AD9850_DATA_H;
		else
			AD9850_DATA_L;
		AD9850_WCLK_H;
		wdata=wdata>>1;
		AD9850_WCLK_L;
	}
	wdata=y>>24;
	for(i=0;i<8;i++)
	{
		if(wdata&0x01)
			AD9850_DATA_H;
		else
			AD9850_DATA_L;
		AD9850_WCLK_H;
		wdata=wdata>>1;
		AD9850_WCLK_L;
	}
	wdata=w0;
	for(i=0;i<8;i++)
	{
		if(wdata&0x01)
			AD9850_DATA_H;
		else
			AD9850_DATA_L;
		AD9850_WCLK_H;
		wdata=wdata>>1;
		AD9850_WCLK_L;
	}
	AD9850_FQUD_H;
//	AD9850_Delay(0xffff);		
	AD9850_FQUD_L;

}

void AD9850_Delay(unsigned int z) 
{  
    
	for(;z>0;z--) 
    
	{;} 
}

