#include "includes.h"

void func_Alarm_info_column_0_d(void* p,u8 sn)//顶栏清除
    
{
    
	u8 SN = 0;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
                sysprintf("func_Alarm_info_column_0_d  clear?? STATUS_SELECT\r\n");
		if(now_page_alarm_deep==0)
		{
			if(now_page_alarm == 0x0000)
			{
		    waining_code_list_num = 0;
				power_waining_code_list_num = 0;
				last_waining_code_list_num = 0;
			  send_FlC200_base_set_cmd(0x80,0xFF,0);
			}
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
     sysprintf("func_Alarm_info_column_0_d  STATUS_IDLE\r\n");

		if(now_page_alarm_deep==0)
		{
			if(now_page_alarm == 0x0000)
			{
			  ui_column_alarm_display_info(TRUE);
			}
		}
	}
}

void func_Alarm_info_column_0(void* p,u8 sn)
{
	
}



void func_Alarm_info_column_1(void* p,u8 sn)
{

}



void func_Alarm_info_column_2(void* p,u8 sn)
{

}



void func_Alarm_info_column_3(void* p,u8 sn)
{

}


void func_Alarm_info_column_4(void* p,u8 sn)
{

}

void func_Alarm_info_column_5(void* p,u8 sn)
{

}



void func_Alarm_normal_flag_logo_5(void* p,u8 sn)
{

}

void func_Alarm_page_pre_down_5(void* p,u8 sn)//向上翻页
{
    
    
	u8 temp = 0 ;
	u8 SN = sn;//图标在当前页面列表的序号
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(now_page_alarm_deep==0)
		{
			temp = ((waining_code_list_num+1)/5);
			if((waining_code_list_num+1)%5)
			{
			}
			else
			{
				if(temp)
					temp-=1;
			}
			if(now_page_alarm < temp*0x1000)
			{
				now_page_alarm_deep = 0;
				now_page_alarm += 0x1000;
				ui_column_alarm_display_info(TRUE);
			}
		}
	}
}




void func_Alarm_page_next_up_5(void* p,u8 sn)
{

}


void func_Alarm_page_next_down_5(void* p,u8 sn)//向下翻页
{
	u8 SN = sn;//图标在当前页面列表的序号
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
      sysprintf("func_Alarm_page_pre_down_5  up?? STATUS_SELECT\r\n");

		if(now_page_alarm_deep==0)
		{
			if(now_page_alarm >= 0x1000)
			{
				now_page_alarm_deep = 0;
				now_page_alarm-= 0x1000;
				ui_column_alarm_display_info(TRUE);
			}
			else
			{
				now_page_alarm_deep = 0;
				now_page_alarm = 0x0000;
				ui_column_alarm_display_info(TRUE);
			}
		}
	}
}



void func_Alarm_page_pre_up_5(void* p,u8 sn)
{

}



void func_Alarm_warning_flag_logo_5(void* p,u8 sn)
{

}
void func_Alarm_warning_flag_logo_5_1(void* p,u8 sn)
{

}
void func_Alarm_warning_flag_logo_5_2(void* p,u8 sn)
{

}
void func_Alarm_warning_flag_logo_5_3(void* p,u8 sn)
{

}
void func_Alarm_warning_flag_logo_5_4(void* p,u8 sn)
{

}
void func_Alarm_warning_flag_logo_5_5(void* p,u8 sn)
{

}
void func_Alarm_error_flag_logo_5(void* p,u8 sn)
{

}
void func_Alarm_error_flag_logo_5_1(void* p,u8 sn)
{                                
                                 
}                                
void func_Alarm_error_flag_logo_5_2(void* p,u8 sn)
{                                
                                 
}                                
void func_Alarm_error_flag_logo_5_3(void* p,u8 sn)
{

}
void func_Alarm_error_flag_logo_5_4(void* p,u8 sn)
{

}
void func_Alarm_error_flag_logo_5_5(void* p,u8 sn)
{

}
