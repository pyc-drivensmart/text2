#include "sys_I2C.h"
#include "sys_IO_I2C.h"
#include "sys_types.h"
#include "sys_uart.h"
#include "sys_interrupt.h"
#include "sys_delay.h"
#include "sys_gpio.h"
#include "sys_io.h"


enum {
	I2C_STAT_BUS_ERROR	= 0x00,
	I2C_STAT_TX_START	= 0x08,
	I2C_STAT_TX_RSTART	= 0x10,
	I2C_STAT_TX_AW_ACK	= 0x18,
	I2C_STAT_TX_AW_NAK	= 0x20,
	I2C_STAT_TXD_ACK	= 0x28,
	I2C_STAT_TXD_NAK	= 0x30,
	I2C_STAT_LOST_ARB	= 0x38,
	I2C_STAT_TX_AR_ACK	= 0x40,
	I2C_STAT_TX_AR_NAK	= 0x48,
	I2C_STAT_RXD_ACK	= 0x50,
	I2C_STAT_RXD_NAK	= 0x58,
	I2C_STAT_IDLE		= 0xf8,
};

/*寄存器地址*/
#define F1C100S_TWI0_BASE  (0x01C27000)
#define F1C100S_TWI1_BASE  (0x01C27400)
#define F1C100S_TWI2_BASE  (0x01C27800)

#define TWI_ADDR_REG(TWIx)   (F1C100S_TWI0_BASE+(TWIx*0x400)+0x00)  //TWI Slave Address
#define TWI_XADDR_REG(TWIx)  (F1C100S_TWI0_BASE+(TWIx*0x400)+0x04)  //TWI Extended Slave Address Register
#define TWI_DATA_REG(TWIx)   (F1C100S_TWI0_BASE+(TWIx*0x400)+0x08)  //TWI Data Byte Register
#define TWI_CNTR_REG(TWIx)   (F1C100S_TWI0_BASE+(TWIx*0x400)+0x0C)  //TWI Control Register
#define TWI_STAT_REG(TWIx)   (F1C100S_TWI0_BASE+(TWIx*0x400)+0x10)  //TWI Status Register
#define TWI_CCR_REG(TWIx)    (F1C100S_TWI0_BASE+(TWIx*0x400)+0x14)  //TWI Clock Control Register
#define TWI_SRST_REG(TWIx)   (F1C100S_TWI0_BASE+(TWIx*0x400)+0x18)  //TWI Software Reset Register
#define TWI_EFR_REG(TWIx)    (F1C100S_TWI0_BASE+(TWIx*0x400)+0x1C)  //TWI Enhance Feature Register
#define TWI_LCR_REG(TWIx)    (F1C100S_TWI0_BASE+(TWIx*0x400)+0x20)  //TWI Line Control Register


#define TIMEOUT 50000 //超时计数



/*I2C io初始化
*/
void I2C_io_init(int TWIx)
{
	if(TWIx==0)
	{
		GPIO_Congif(GPIOE,GPIO_Pin_11,GPIO_Mode_011,GPIO_PuPd_UP);
		GPIO_Congif(GPIOE,GPIO_Pin_12,GPIO_Mode_011,GPIO_PuPd_UP);
	}else if(TWIx==1){}
	 else if(TWIx==2){}
}
/*clear_irq_flag
*/
void twi_clear_irq_flag(int TWIx)
{
	unsigned int temp;
	unsigned int reg_val = read32(TWI_CNTR_REG(TWIx));
	/* start and stop bit should be 0 */
	reg_val |= 1<<3;
	reg_val &= ~(1<<4 | 1<<5);
	write32(TWI_CNTR_REG(TWIx),reg_val);
	/* read two more times to make sure that interrupt flag does really be cleared */
	{

		temp = read32(TWI_CNTR_REG(TWIx));
		temp |= read32(TWI_CNTR_REG(TWIx));
	}
}

/*I2C设置速率
rate_hz<=400000
*/
void f1c100s_i2c_set_rate(int TWIx, u64_t rate)
{
	u64_t pclk = 102000000;//APB clock input
	s64_t freq, delta, best = 0x7fffffffffffffffLL;
	int tm = 15, tn = 7;
	int m, n;

	for(n = 0; n <= 7; n++)
	{
		for(m = 0; m <= 15; m++)
		{
			freq = pclk / (10 * (m + 1) * (1 << n));
			delta = rate - freq;
			if(delta >= 0 && delta < best)
			{
				tm = m;
				tn = n;
				best = delta;
			}
			if(best == 0)
				break;
		}
	}
	sysprintf("CLK_M= %d...\r\n",tm);
	sysprintf("CLK_n= %d...\r\n",tn);
	
	write32(TWI_CCR_REG(TWIx), ((tm & 0xf) << 3) | ((tn & 0x7) << 0));
}

/*I2C等待状态
*/
int f1c100s_i2c_wait_status(int TWIx)
{
	volatile int timeout=0;
	do {
		if((read32(TWI_CNTR_REG(TWIx)) & (1 << 3)))return read32(TWI_STAT_REG(TWIx));
		timeout++;
	} while(timeout<TIMEOUT);
	if(timeout>=TIMEOUT)sysprintf("i2c_wait timeout!\r\n");
	return I2C_STAT_BUS_ERROR;
}
/*等待总线空闲
*/ 
int Wait_Idle(int TWIx)
{
  volatile int timeout=0;
	do {
		if(read32(TWI_STAT_REG(TWIx))==I2C_STAT_IDLE)return 0;
		timeout++;
	} while(timeout<TIMEOUT);
	if(timeout>=TIMEOUT)sysprintf("I2C Wait_Idle timeout!\r\n");
	return I2C_STAT_BUS_ERROR;
}
/*I2C开始
*/
int f1c100s_i2c_start(int TWIx)
{
	//u32_t val;
  volatile int timeout=0;
	S_BIT(TWI_CNTR_REG(TWIx),5);
  C_BIT(TWI_CNTR_REG(TWIx),3);
	do
	{
		if(!(read32(TWI_CNTR_REG(TWIx)) & (1 << 5)))break;
		timeout++;
	} while(timeout<TIMEOUT);
	if(timeout>=TIMEOUT)sysprintf("i2c_start timeout!\r\n");
	return f1c100s_i2c_wait_status(TWIx);
}

/*I2C停止
*/
int f1c100s_i2c_stop(int TWIx)
{
	//u32_t val;
  volatile int timeout=0;
	S_BIT(TWI_CNTR_REG(TWIx),4);
  C_BIT(TWI_CNTR_REG(TWIx),3);
	do {
		if(!(read32(TWI_CNTR_REG(TWIx)) & (1 << 4)))break;
		timeout++;
	} while(timeout<TIMEOUT);
	if(timeout>=TIMEOUT)sysprintf("i2c_stop timeout!\r\n");
	return read32(TWI_STAT_REG(TWIx));
}
/*I2C发送数据
*/
int f1c100s_i2c_send_data(int TWIx, u8 dat)
{
	write32(TWI_DATA_REG(TWIx), dat);
	C_BIT(TWI_CNTR_REG(TWIx),3);
	
	return f1c100s_i2c_wait_status(TWIx);
}
/*I2C读
*/
int f1c100s_i2c_read(int TWIx, u8 addr,u8 *buff,int len)
{
	u8 * p = buff;

	if(f1c100s_i2c_send_data(TWIx, (addr << 1 | 1)) != I2C_STAT_TX_AR_ACK)
	 {
		 sysprintf("err:f1c100s_i2c_read-0\r\n");	 
		 return -1;
	 }
	S_BIT(TWI_CNTR_REG(TWIx),2);
	while(len > 0)
	{
		if(len == 1)
		{
			C_BIT(TWI_CNTR_REG(TWIx),2);
			C_BIT(TWI_CNTR_REG(TWIx),3);
			if(f1c100s_i2c_wait_status(TWIx) != I2C_STAT_RXD_NAK)
			 {
				 sysprintf("err:f1c100s_i2c_read-1\r\n");	 
				 return -1;
			 }	
		}
		else
		{
			C_BIT(TWI_CNTR_REG(TWIx),3);
			if(f1c100s_i2c_wait_status(TWIx) != I2C_STAT_RXD_ACK)
			 {
				 sysprintf("err:f1c100s_i2c_read-2\r\n");	 
				 return -1;
			 }
		}
		*p++ = read32(TWI_DATA_REG(TWIx));
		len--;
	}
	return 0;
}
/*I2C写数据+地址
*/
static int f1c100s_i2c_write(int TWIx, u8 addr,u8 *buff,int len)
{
	u8 * p = buff;
	if(f1c100s_i2c_send_data(TWIx,(addr << 1)) != I2C_STAT_TX_AW_ACK)return -1;
	while(len > 0)
	{
		 if(f1c100s_i2c_send_data(TWIx, *p++)!= I2C_STAT_TXD_ACK)
		 {
			 sysprintf("err:f1c100s_i2c_write()\r\n");	 
			 return -1;
		 }
		 len--;
	}
	return 0;
}
/*I2C写数据+无地址
*/
static int f1c100s_i2c_data_write(int TWIx,u8 *buff,int len)
{
	u8 * p = buff;
	while(len > 0)
	{
		 if(f1c100s_i2c_send_data(TWIx, *p++)!= I2C_STAT_TXD_ACK)	 
		 {
			 sysprintf("err:f1c100s_i2c_data_write()\r\n");	 
			 return -1;
		 }
		 len--;
	}
	return 0;
}
/*设置从机地址
*/
u8 slave_addr;
void set_slave_addr(u8 addr)
{
	slave_addr=addr;
}
/*I2C时钟化
*/
void I2C_clock_init(int TWIx)
{
#define CCU_Base_Address    (u32_t)0x01C20000	
#define BUS_CLK_GATING_REG2 (CCU_Base_Address+0x068)	
#define BUS_SOFT_RST_REG2   (CCU_Base_Address+0x2D0)
	write32(BUS_CLK_GATING_REG2,read32(BUS_CLK_GATING_REG2)|(1)<<(16+TWIx));
	write32(BUS_SOFT_RST_REG2,read32(BUS_SOFT_RST_REG2)|((1)<<(16+TWIx)));
	delay_ms(1);
}
/*IO测试-SDA-SCL 输出高低电平
*/
void IO_Test(int TWIx)
{
	S_BIT(TWI_LCR_REG(TWIx),0);
	S_BIT(TWI_LCR_REG(TWIx),2);
	while(1)	
	{
		S_BIT(TWI_LCR_REG(TWIx),1);
		S_BIT(TWI_LCR_REG(TWIx),3);
		delay_us(1000);
		C_BIT(TWI_LCR_REG(TWIx),1);
		C_BIT(TWI_LCR_REG(TWIx),3);
		delay_us(1000);	
	}
}
/*I2C初始化
*/
void I2C_Init(int TWIx)
{  		
  //int i=0;
	sysprintf("TWI%d_Init...\r\n",TWIx);
  I2C_io_init(TWIx);
	I2C_clock_init(TWIx);
	S_BIT(TWI_CNTR_REG(TWIx), 6);//使能总线
	S_BIT(TWI_SRST_REG(TWIx), 0);//复位总线	
	f1c100s_i2c_set_rate(TWIx,  Rate100K);//设置速率
	set_slave_addr(0xA0>>1);//设置从机地址
}


//-------------------------------------------------------------------------------------------------------------
//------------------------------------24C256测试---------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
#define EEPROM_ADDR_TYPE  2  //2=2位内存地址 1=1位内存地址 


/*24c256 read_byte-------------------------
add  读地址
buuf 缓存地址
len  读长度
*/ 
u8 read_byte(int TWIx,u16 addr,u8 addr_len,u8* buff,u16 len)
{
u8 addr_buff[2];
	if(addr_len==2)
	{
		addr_buff[0]=addr>>8;
		addr_buff[1]=addr&0xff;
	}else if(addr_len==1)
	{
		addr_buff[0]=addr&0xff;		
		addr_buff[1]=0;
	}
	if(Wait_Idle(TWIx)==0)
	{
		//写地址
		f1c100s_i2c_start(TWIx);
		f1c100s_i2c_write(TWIx,slave_addr,addr_buff,EEPROM_ADDR_TYPE);
		//读数据
		f1c100s_i2c_start(TWIx);
		f1c100s_i2c_read(TWIx,slave_addr,buff,len);
		f1c100s_i2c_stop(TWIx);
		return 0;
	}else sysprintf("BUS ERR!\r\n");
	return 1; 
}
/*24c256 write_byte-------------------------
*/ 
int write_byte(int TWIx,u16 addr,u8 addr_len,u8* buff,u16 len)
{
u8 addr_buff[2];
	if(addr_len==2)
	{
		addr_buff[0]=addr>>8;
		addr_buff[1]=addr&0xff;
	}else if(addr_len==1)
	{
		addr_buff[0]=addr&0xff;		
		addr_buff[1]=0;
	}

	if(Wait_Idle(TWIx)==0)
	{
		//写地址
		f1c100s_i2c_start(TWIx);
		f1c100s_i2c_write(TWIx,slave_addr,addr_buff,EEPROM_ADDR_TYPE);
		//写数据
    f1c100s_i2c_data_write(TWIx,buff,len);
		f1c100s_i2c_stop(TWIx);
		return 0;
	}else sysprintf("BUS ERR!\r\n");
	return -1;
}

/*I2C测试
*/
void AT24C256_Demo(void)
{
	int i,TWI=TWI0;
  u8 buff_in[10]={73,75,78,3,4,5,6,7,8,9};
  u8 buff_out[10]={0};
	
	sysprintf("I2C_Demo...\r\n");
	I2C_Init(TWI);
	
  //EEPROM写入
  sysprintf("write...\r\n");	
	write_byte(TWI,0,2,buff_in,3);
	//延时,等EEPROM完成
	delay_ms(10);
  //EEPROM读出
	sysprintf("read...\r\n");	
	read_byte(TWI,0,2,buff_out,3);
	for(i=0;i<3;i++)sysprintf("read%d:%d\r\n",i,buff_out[i]);	
	
	while(1);
}

