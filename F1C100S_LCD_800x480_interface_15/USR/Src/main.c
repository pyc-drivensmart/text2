
#include "includes.h"




u32 SysTime=0;  
void ResetDelayTime(u32 *time)//重置目标时间
{       
	*time = SysTime;
}

void SetDelayTime(u32 *time,u32 t)//设置目标时间
{
        *time = SysTime + t;
}

u8 CntDelayTime(u32 *time,u32 t)//计算目标时间
{
	u32 nowTime;
        u32 inTime=*time;
	ResetDelayTime(&nowTime);   
        //nowTime = OSTimeGet();
       // printf("\r\nnowTime:%d,time:%d,t:%d",nowTime,inTime,t);   
	if((nowTime-inTime)>t) return 1;
        else return 0;
}


unsigned short *BT1;//
__align(4) unsigned int LCDbuff1[XSIZE_PHYS*YSIZE_PHYS]; 
__align(4) unsigned int LCDbuff2[XSIZE_PHYS*YSIZE_PHYS];  
__align(4) unsigned int Virtual_LCDbuff0[XSIZE_PHYS*YSIZE_PHYS];  //模拟显示层  0优先级最低 数字越大优先级越大
__align(4) unsigned int Virtual_LCDbuff1[XSIZE_PHYS*YSIZE_PHYS];  //
__align(4) unsigned int Virtual_LCDbuff2[XSIZE_PHYS*YSIZE_PHYS];  //字幕层Virtual_LCD_Upgrate_formx1y1 

__align(4) unsigned int Virtual_LCDbuff3[XSIZE_PHYS*YSIZE_PHYS];  //背景层  弹出层 键盘层


/*---------------------------------------------------
AHB 时钟为204MHZ(LCD)
APB 时钟为102MHZ(UART)
---- main
---- main
接入LCD分辩率为480x272

图片转换方法：
1.使用PS打开图片,存储为16位的RGB565的BMP格式。如果转换不正确，可以下载我的PS软件试一下，
	绿色软件不用安装，下载地址【链接：https://pan.baidu.com/s/1-iOIZ0Dac4R-hD7UxD1nhA 提取码：ln07】。
2.然后使用【...\F1C100S_keil开发文件\开发与调试软件\Bin2C.exe】转换成C文件，加入到工程就可以了。
3.图片数据需要4位对齐,不然一些图片会显示不正常，  __align(4)。
----------------------------------------------------*/

#define CPU_FREQ_MHZ 720//CPU频率  720
#define cpu_frequency_mhz(x) (u32)(1000*1000*(x/24*24))//CPU频率


void Touch_GT911_pro(void)
{
	static BOOL f_int_h = FALSE; 
  static u32 IdelTime = 0;
	if(IdelTime == 0)ResetDelayTime(&IdelTime); 
	
	if(GT911_INT_in())  //读输入电平
		f_int_h = TRUE; //高电平给标志位
	if(CntDelayTime(&IdelTime,TIME_ONE_MS*50))  //延时 50MS，这种延时像是任务调度那种延时，不是卡死在这里延时
  {
     if((GT911_INT_in()==0)&&f_int_h)//低电平查询
		 {
			  f_int_h = FALSE;
			  GT911_OnePiontScan();
			  ResetDelayTime(&IdelTime); 
		 }
		 else
		 {
			 if(touch_up == FALSE)
			 {
				  GT911_OnePiontScan();
				  ResetDelayTime(&IdelTime); 
			 }
		 }
	 }
}
void set_spi_io_in_float(void)
{
     GPIO_Congif(GPIOC,GPIO_Pin_0,GPIO_Mode_IN,GPIO_PuPd_NOPULL);
	 GPIO_Congif(GPIOC,GPIO_Pin_1,GPIO_Mode_IN,GPIO_PuPd_NOPULL);
	 GPIO_Congif(GPIOC,GPIO_Pin_2,GPIO_Mode_IN,GPIO_PuPd_NOPULL);
	 GPIO_Congif(GPIOC,GPIO_Pin_3,GPIO_Mode_IN,GPIO_PuPd_NOPULL);
}


u8 mcnt = 0;
extern u8 cntt1;
extern u8 cntt2;
//char print_buf[100];
//u8 k = 0;
int main(void)
{ 
	static u32 IdelTime_1S = 0;
	static u32 IdelTime_20MS = 0;
	//static u32 Heartbeat_cnt = 0;
  Sys_Clock_Init(cpu_frequency_mhz(CPU_FREQ_MHZ));
	sys_mmu_init();	
	set_spi_io_in_float();
	//Sys_Uart0_Init(cpu_frequency_mhz(CPU_FREQ_MHZ),115200);
	Sys_Uart_Init(UART2,CPU_FREQ_MHZ*1000000,921600,1);
	Sys_Uart_Init(UART0,CPU_FREQ_MHZ*1000000,115200,1);
	sysprintf("\r\n\r\n\r\n");
	sysprintf("Sys_Start...\r\n");	
	sysprintf("Build:%s %s   *\r\n",__DATE__,__TIME__);	
	sysprintf(VERSION_STR);	
	sysprintf("CPU_FREQ_MHZ %d MHZ.\r\n",CPU_FREQ_MHZ);	
	sysprintf("Dram Init Size %d Mb.\r\n",32);	
			

	Sys_Timer1_Init();
	
	
	//这里10寸显示屏不用初始化LCD，直接读了。
	BT1=(unsigned short *)LCDbuff1;
	Sys_LCD_Init(XSIZE_PHYS,YSIZE_PHYS,(unsigned int *)LCDbuff1,(unsigned int *)LCDbuff2);
	

	GT911_Init();   //触摸屏初始化
	ResetDelayTime(&IdelTime_1S);	 	
	ResetDelayTime(&IdelTime_20MS); 	
    page_init();
	
	while(1)
	{   
	#if 1
	  SysTime =   sys_count_timer0;

		F1C200_rx_pro();		
		 if(CntDelayTime(&IdelTime_1S,TIME_ONE_MS*1000))
		 {
				ResetDelayTime(&IdelTime_1S); 		
                mcnt++;
				if(mcnt>6)mcnt = 0;
				f_FlC200_send_Heartbeat = TRUE;
		 }
     	
            Touch_GT911_pro();
            page_dis_test_pro();//更新背景等
		 
		 #endif
		 if(CntDelayTime(&IdelTime_20MS,TIME_ONE_MS*10))
		 {
			ResetDelayTime(&IdelTime_20MS); 	
		    FlC200_hc_ready_time_send_proc();
			clear_lights_pwm_val();		
            check_ui_out_dialog_msg();
			if(f_ui_disply_dialog_test)
			 disply_tset_touch(FALSE);
		 }
	 }
	
}









