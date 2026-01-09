#include "includes.h"
//BOE2.1(480x480)_initial_code-0526.-Customer-FW.INI(1)(1)




#define GT911_RST_1()  GPIO_SET(GPIOA,GPIO_Pin_3) /* RST = 1 */
#define GT911_RST_0()  GPIO_RESET(GPIOA,GPIO_Pin_3) /* RST = 0 */
#define GT911_INT_1()  GPIO_SET(GPIOA,GPIO_Pin_1)/* INT = 1 */
#define GT911_INT_0()  GPIO_RESET(GPIOA,GPIO_Pin_1)/* INT = 0 */
#define GT911_INT_in() GPIO_READ(GPIOA,GPIO_Pin_1)   /* INT_IN */






extern void Write(unsigned char  cmd,unsigned char  dat);
extern void ResetDelayTime(u32 *time);//??????
extern void SetDelayTime(u32 *time,u32 t);//??????
extern u8 CntDelayTime(u32 *time,u32 t);//??????
u8 Command = 0,Parameter=1;
void Lcd_480_Init(void)
{
	static u32 IdelTime = 0;
	static u8 start_flag = 1;
//HW_Reset();   			//VBP>=11, VFP>=7
	
	
//Delay(120);	
if(start_flag==1)
{
  ResetDelayTime(&IdelTime); 
	start_flag =2;
	
	GT911_RST_0();
}
else if(start_flag==2)
{
   if(CntDelayTime(&IdelTime,100))
	{
		start_flag =3;
		
		

	Write(Command  , 0xFF);
	Write(Parameter , 0x77);
	Write(Parameter , 0x01);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x10);
	
	Write(Command  , 0xC0);
	Write(Parameter , 0x3B);	
	Write(Parameter , 0x00);
	
	Write(Command  , 0xC1);
	Write(Parameter , 0x0B);	//VBP
	Write(Parameter , 0x02);
	
	Write(Command  , 0xC2);
	Write(Parameter , 0x00);
	Write(Parameter , 0x02);
	
	Write(Command  , 0xCC);
	Write(Parameter , 0x10);
	
	Write(Command  , 0xCD);
	Write(Parameter , 0x08);
	
	Write(Command  , 0xB0); 	//Positive Voltage Gamma Control  
	Write(Parameter , 0x00); 
	Write(Parameter , 0x1D);
	Write(Parameter , 0x29);
	Write(Parameter , 0x12);
	Write(Parameter , 0x17);
	Write(Parameter , 0x0B);
	Write(Parameter , 0x18);
	Write(Parameter , 0x09);
	Write(Parameter , 0x08);
	Write(Parameter , 0x2A);
	Write(Parameter , 0x06);
	Write(Parameter , 0x14);
	Write(Parameter , 0x11);
	Write(Parameter , 0x19);
	Write(Parameter , 0x1C);
	Write(Parameter , 0x18);
	
	Write(Command  , 0xB1); 	//Negative Voltage Gamma Control  
	Write(Parameter , 0x00); 
	Write(Parameter , 0x1D);
	Write(Parameter , 0x29);
	Write(Parameter , 0x12);
	Write(Parameter , 0x16);
	Write(Parameter , 0x0A);
	Write(Parameter , 0x18);
	Write(Parameter , 0x08);
	Write(Parameter , 0x09);
	Write(Parameter , 0x2A);
	Write(Parameter , 0x07);
	Write(Parameter , 0x13);
	Write(Parameter , 0x12);
	Write(Parameter , 0x19);
	Write(Parameter , 0x1D);
	Write(Parameter , 0x18);
	
	Write(Command  , 0xFF);
	Write(Parameter , 0x77);
	Write(Parameter , 0x01);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x11);
	
	Write(Command  , 0xB0);   
	Write(Parameter , 0x5D);
	
	Write(Command  , 0xB1); 	//VCOM amplitude setting  
	Write(Parameter , 0x43); 
		
	Write(Command  , 0xB2); 	//VGH Voltage setting  
	Write(Parameter , 0x81);	//12V
	
	Write(Command  , 0xB3);
	Write(Parameter , 0x80);
	
	Write(Command  , 0xB5); 	//VGL Voltage setting  
	Write(Parameter , 0x43);	//-8.3V
	
	Write(Command  , 0xB7);
	Write(Parameter , 0x85);
	
	Write(Command  , 0xB8);
	Write(Parameter , 0x20);
	
	Write(Command  , 0xC1);
	Write(Parameter , 0x78);
	
	Write(Command  , 0xC2);
	Write(Parameter , 0x78);
	
	Write(Command  , 0xD0);
	Write(Parameter , 0x88);
	
	Write(Command  , 0xE0);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x02);
	
	Write(Command  , 0xE1);
	Write(Parameter , 0x03);	
	Write(Parameter , 0xA0);
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);
	Write(Parameter , 0x04);	
	Write(Parameter , 0xA0);
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);
	Write(Parameter , 0x20);
	Write(Parameter , 0x20);
	
	Write(Command  , 0xE2);
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	  
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);
	
	Write(Command  , 0xE3);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x11);
	Write(Parameter , 0x00);
	
	Write(Command  , 0xE4);
	Write(Parameter , 0x22);
	Write(Parameter , 0x00);
	
	Write(Command  , 0xE5);		
	Write(Parameter , 0x05);	
	Write(Parameter , 0xEC);	
	Write(Parameter , 0xA0);
	Write(Parameter , 0xA0);
	Write(Parameter , 0x07);	
	Write(Parameter , 0xEE);	
	Write(Parameter , 0xA0);
	Write(Parameter , 0xA0);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	
	Write(Command  , 0xE6);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x11);
	Write(Parameter , 0x00);
	
	Write(Command  , 0xE7);
	Write(Parameter , 0x22);
	Write(Parameter , 0x00);
	
	Write(Command  , 0xE8);		
	Write(Parameter , 0x06);	
	Write(Parameter , 0xED);	
	Write(Parameter , 0xA0);
	Write(Parameter , 0xA0);
	Write(Parameter , 0x08);	
	Write(Parameter , 0xEF);	
	Write(Parameter , 0xA0); 
	Write(Parameter , 0xA0);
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);	
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	
	Write(Command  , 0xEB);
	Write(Parameter , 0x00); 	
	Write(Parameter , 0x00);
	Write(Parameter , 0x40);
	Write(Parameter , 0x40);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);  
	
	Write(Command  , 0xED);  
	Write(Parameter , 0xFF); 
	Write(Parameter , 0xFF);  
	Write(Parameter , 0xFF); 	
	Write(Parameter , 0xBA); 		
	Write(Parameter , 0x0A); 	
	Write(Parameter , 0xBF); 	
	Write(Parameter , 0x45); 	
	Write(Parameter , 0xFF); 
	Write(Parameter , 0xFF);  
	Write(Parameter , 0x54); 	
	Write(Parameter , 0xFB); 	
	Write(Parameter , 0xA0); 	
	Write(Parameter , 0xAB); 	
	Write(Parameter , 0xFF); 
	Write(Parameter , 0xFF); 
	Write(Parameter , 0xFF); 
	
	Write(Command  , 0xEF);
	Write(Parameter , 0x10); 
	Write(Parameter , 0x0D); 
	Write(Parameter , 0x04); 
	Write(Parameter , 0x08); 
	Write(Parameter , 0x3F); 
	Write(Parameter , 0x1F);
	
	Write(Command  , 0xFF);
	Write(Parameter , 0x77);
	Write(Parameter , 0x01);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x13);
	
	Write(Command  , 0xEF);
	Write(Parameter , 0x08);
	
	Write(Command  , 0xFF);
	Write(Parameter , 0x77);
	Write(Parameter , 0x01);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	Write(Parameter , 0x00);
	
	Write(Command  , 0x11);
	
	GT911_RST_1();
		ResetDelayTime(&IdelTime); 
			
		}
	}
	//Delay(120);	
	else if(start_flag==3)
	{
		if(CntDelayTime(&IdelTime,100))
		{
			start_flag =4;
	GT911_RST_0();
	
	
	
	Write(Command  , 0x29);
	
	Write(Command  , 0x36);
	Write(Parameter , 0x00);
	
	Write(Command  , 0x3A);
	Write(Parameter , 0x60);
			GT911_RST_1();
		}
	}
	
	else if(start_flag==4)
	{
	
			start_flag =5;
	}
}
