#include "sys_gpio.h"
#include "sys_uart.h"
#include "sys_delay.h"
#include "sys_IO_I2C.h"

#define uchar unsigned char 
#define uint  unsigned int 
 
#define sda_in GPIO_READ(GPIOA,GPIO_Pin_2) 
#define sda_1  GPIO_SET(GPIOA,GPIO_Pin_2) 
#define sda_0  GPIO_RESET(GPIOA,GPIO_Pin_2) 

#define scl_1  GPIO_SET(GPIOA,GPIO_Pin_0) 
#define scl_0  GPIO_RESET(GPIOA,GPIO_Pin_0) 

#define GT911  1

#if GT911//GT911-手册写明标准400KHZ-这里使用500KHZ
	#define delay()         delay_us(1)//时钟延时=1000000/1*2= CLK=500KHZ
	#define delay_1()       delay_us(1)//写完延时
#else
/******************24C系列时钟一定要注意-写完延时5ms不能少*****************************/
//24C系列支持400KHZ时钟-这里使用500KHZ
#define delay()         delay_us(1)//时钟延时=1000000/1*2= CLK=500KHZ
#define delay_1()       delay_ms(5)//24Cxx写完延时-标准5ms-不能少
/************************************************************************************/
#endif

#define set_sda_out()   GPIO_Congif(GPIOA,GPIO_Pin_2,GPIO_Mode_OUT,GPIO_PuPd_UP)
#define set_sda_in()    GPIO_Congif(GPIOA,GPIO_Pin_2,GPIO_Mode_IN,GPIO_PuPd_UP)


/*start---------------------------
*/
int start(void)
{
 //------------------4.3-480x272 GT911 需要加入几个时钟 7寸不需要 ？？
 /*scl_1;
 delay();	
 scl_0;	
 delay();		
 scl_1;		
 delay();
 scl_0;	
 delay();	*/
 scl_1;
 //-----------------------
	
	set_sda_in();	
	delay();

	if(!sda_in)
	{
		sysprintf("err:bus busy!");
		//return -1;	//SDA线为低电平则总线忙,退出
	}
	set_sda_out();
	sda_0;
	delay();

	sda_0;
	delay();

	return 0;
}
/*stop---------------------------
*/
void stop(void)
{
	
 delay(); 
 //scl_0;	
 sda_0;
 scl_1;		
 delay();
 sda_1;
 delay(); 
 //scl_0;	
// delay();
	
}
/*ack---------------------------
*/ 
void ack(void)
{
 volatile int i=0;
 set_sda_in();//GT911-改变输入要放前面，不然有问题
 sda_1;
 delay();
 scl_1;	
 delay();
 do{
	if(sda_in==0)break;
	i++;
 }while(i<50000);
 if(i>=50000)sysprintf("ack timeout!\r\n"); 
 set_sda_out();
 scl_0;
}

/*noack---------------------------
*/
void noack(void)
{
	 //
 sda_0;
	delay();
 scl_1;
 delay();
 scl_0;
}
void noack1(void)
{
	 delay();
 //sda_0;
 scl_1;
 delay();
 scl_0;
}


void Write(uchar cmd,uchar dat)
{
 uchar i;
	
	scl_0;
	 
  if(cmd)sda_1;
  else sda_0;
	delay(); 
	scl_1; 		 
  delay();

	
 scl_0;
 for(i=0;i<8;i++)
 {
	//--------------- 	 
  if(dat&0x80)sda_1;
  else sda_0;
	delay(); 
  dat=dat<<1;
	//---------------  
	scl_1; 		 
  delay();
	scl_0;
	delay(); 	 
 }

}

/*iic_write_byte--------------------------
*/
void iic_write_byte(uchar dat)
{
 uchar i;
 scl_0;
 for(i=0;i<8;i++)
 {
	//--------------- 	 
  if(dat&0x80)sda_1;
  else sda_0;
	delay(); 
  dat=dat<<1;
	//---------------  
	scl_1; 		 
  delay();
	scl_0;
	delay(); 	 
 }

}
/*iic_read_byte--------------------------
*/
uchar iic_read_byte(void)
{
 uchar i;
 uchar dat;
 scl_0;
 set_sda_in();

 for(i=0;i<8;i++)
 { 
  scl_1;	 
	delay(); 
	//--------------- 	 
  dat=dat<<1;
  if(sda_in)dat++;
	//--------------- 
  scl_0;
	delay();
 }
 set_sda_out();
 sda_1;
 return dat;  
}
/*set_slave_addr-------------------------
*/
u8 IO_slave_addr=0;
void IO_set_slave_addr(u8 addr)
{
	IO_slave_addr=addr;
}
/*write_byte-------------------------
addr 地址
addr_len 地址长度
buf 缓存
buf_len 缓存长充
*/
void IO_write_byte(u16 addr,u8 addr_len,u8* buf,u16 buf_len)
{
int i=0;

 start();
 //写器件地址
 iic_write_byte(IO_slave_addr<<1);
 ack();
 //写内存地址
 if(addr_len==1)
 {
	 iic_write_byte(addr&0xff);
	 ack();	  
 }
 else if(addr_len==2)
 {
	 iic_write_byte(addr>>8);
	 ack();
	 iic_write_byte(addr&0xff);
	 ack();	 
 } 
 //写数据
 for(i=0;i<buf_len;i++)
 {
	 iic_write_byte(buf[i]);
	 ack();
 }
 stop(); 
 //返回
 delay_1();//必要延时
}
/*read_byte-------------------------
addr 地址
addr_len 地址长度
buf 缓存
buf_len 缓存长充
*/ 
void IO_read_byte(u16 addr,u8 addr_len,u8* buf,u16 buf_len)
{
 int i=0;
 start();
 //写器件地址	
 iic_write_byte(IO_slave_addr<<1);
 ack();
 //写内存地址
 if(addr_len==1)
 {
	 iic_write_byte(addr&0xff);
	 ack();	  
 }
 else if(addr_len==2)
 {
	 iic_write_byte(addr>>8);
	 ack();
	 iic_write_byte(addr&0xff);
	 ack();
 } 
  stop();	
 //读数据
 start();
 iic_write_byte((IO_slave_addr<<1)|0x01);
 ack();
 //sysprintf("buf_len%d\r\n",buf_len);
 for(i=0;i<buf_len;i++)
 {
	 buf[i]=iic_read_byte();
	 if(i!=(buf_len-1))noack();
	 else noack1();
 }

 stop();	
}
/*I2C_Init-------------------------
*/ 
void IO_I2C_Init(void)
{
	//GPIOA 没有上下拉 
	GPIO_Congif(GPIOA,GPIO_Pin_0,GPIO_Mode_OUT,GPIO_PuPd_UP);
	GPIO_Congif(GPIOA,GPIO_Pin_2,GPIO_Mode_OUT,GPIO_PuPd_UP);
	IO_set_slave_addr(0xa0>>1);	
	sda_1;
  scl_1;
	
}
/*I2C_Demo_读写24Cxx-------------------------
*/ 
void IO_AT24C256_Demo(void)
{
u8 buf_in[3]={44,25,58};
u8 buf_out[3]={0};
int i;	
	
	sysprintf("I2C_Demo...\r\n");
	IO_I2C_Init();
  sysprintf("write...\r\n");
	IO_write_byte(0,2,buf_in,3);

	sysprintf("read...\r\n");
  IO_read_byte(0,2,buf_out,3);


  for(i=0;i<3;i++)sysprintf("read%d:%d\r\n",i,buf_out[i]);
	
	while(1)
	{
	
	}
}

