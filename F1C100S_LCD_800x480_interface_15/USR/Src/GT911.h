#ifndef __GT911_H__
#define __GT911_H__
#include "sys_gpio.h"

//IIC方式【硬件spi&软件spi】
#define IO_IIC 1 //1=IO_IIC 0= IIC

//定以外分辩率
//#define TP43_480x272
#define TP43_800x480


/* 定义GT911复位与中断引脚连接的GPIO端口 */
#define GT911_RST_1()  GPIO_SET(GPIOA,GPIO_Pin_3) /* RST = 1 */
#define GT911_RST_0()  GPIO_RESET(GPIOA,GPIO_Pin_3) /* RST = 0 */
#define GT911_INT_1()  GPIO_SET(GPIOA,GPIO_Pin_1)/* INT = 1 */
#define GT911_INT_0()  GPIO_RESET(GPIOA,GPIO_Pin_1)/* INT = 0 */
#define GT911_INT_in() GPIO_READ(GPIOA,GPIO_Pin_1)   /* INT_IN */

#define SET_GT911_INT_out()   GPIO_Congif(GPIOA,GPIO_Pin_1,GPIO_Mode_OUT,GPIO_PuPd_NOPULL)
#define SET_GT911_INT_in()    GPIO_Congif(GPIOA,GPIO_Pin_1,GPIO_Mode_IN,GPIO_PuPd_UP)

typedef struct
{
unsigned char Enable;
unsigned char i2c_addr;
unsigned char TouchpointFlag;
unsigned char Touchkey1trackid;
unsigned short X1;
unsigned short Y1;
unsigned short S1;
unsigned char  Touchkey2trackid;
unsigned short X2;
unsigned short Y2;
unsigned short S2;
unsigned char  Touchkey3trackid;
unsigned short X3;
unsigned short Y3;
unsigned short S3;
unsigned char  Touchkey4trackid;
unsigned short X4;
unsigned short Y4;
unsigned short S4;
unsigned char  Touchkey5trackid;
unsigned short X5;
unsigned short Y5;
unsigned short S5;
}GT911_T;

extern GT911_T g_GT911;

int GT911_Init(void);
int GT911_OnePiontScan(void);
void GT911_Test(void);


int GT911_WriteReg(unsigned short _usRegAddr, unsigned char  *_pRegBuf, unsigned char  _ucLen);
int GT911_ReadReg(unsigned short _usRegAddr, unsigned char  *_pRegBuf, unsigned char  _ucLen);
unsigned char  GT911_ReadStatue(void);

extern BOOL touch_up;

#endif
