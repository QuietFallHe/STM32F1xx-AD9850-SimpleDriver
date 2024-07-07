# STM32F1xx-AD9850-SimpleDriver
基于标准库，从未在网上搜到免费驱动程序，明明买了芯片商家就会送，但是网上跟签了保密协议一样，最后搜到了Hal库版本，自己改成标准库了，可以简单使用，输出正弦波和方波
# 使用方法
将.c文件和.h文件放到合适的地方就好，但是要改一些地方

## 1-- .h中引脚及端口定义
```c
#define AD9850_CONTROL_PORT  GPIOA
#define AD9850_FQUD   GPIO_Pin_3  //改成自己连接的引脚
#define AD9850_WCLK   GPIO_Pin_4  //改成自己连接的引脚
#define AD9850_DATA   GPIO_Pin_8  //改成自己连接的引脚  和D7相连
#define AD9850_RST    GPIO_Pin_5  //改成自己连接的引脚
```
## 2-- .c 39行频率计算
`x=4294967295U/(72);//修改获得合适频率`，在移植的时候，我并不知道如何改他，我的单片机是72Mhz时钟频率，但是改到72设置频率也不是理想值，不知道为啥，因为我菜比

## 3-- main.c
```c
u32 fre=200000; //设定频率
AD9850_Init();
AD9850_Write(0x00,(double)fre);
```
