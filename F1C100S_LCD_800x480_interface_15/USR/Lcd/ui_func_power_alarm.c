#include "includes.h"



void func_power_alarm_btn1_d(void* p,u8 sn)
{
	u8 SN = 1;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(now_page_power_alarm_deep==0)
		{
			if(now_page_power_alarm == 0x0000)
			{
		    power_waining_code_list_num = 0;
			  send_FlC200_base_set_cmd(0x80,0xFF,0);
			}
			
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
		if(now_page_power_alarm_deep==0)
		{
			if(now_page_power_alarm == 0x0000)
			{
			  display_power_alarm_info();
			}
			
		}
	}

}



void func_power_alarm_btn1_u(void* p,u8 sn)
{

}



void func_power_alarm_btn2_d(void* p,u8 sn)
{

}



void func_power_alarm_btn2_u(void* p,u8 sn)
{

}



void func_power_alarm_btn3_d(void* p,u8 sn)
{
}



void func_power_alarm_btn3_u(void* p,u8 sn)
{

}



void func_power_alarm_btn4_d(void* p,u8 sn)
{

}



void func_power_alarm_btn4_u(void* p,u8 sn)
{

}



void func_power_alarm_b_power_alarm_d(void* p,u8 sn)
{

}



void func_power_alarm_b_power_alarm_u(void* p,u8 sn)
{

}



void func_power_alarm_headline(void* p,u8 sn)
{

}



void func_power_alarm_nextpage_d(void* p,u8 sn)
{
	u8 temp = 0 ;
  u8 SN = 5;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(now_page_power_alarm_deep==0)
		{
			
			 temp = ((power_waining_code_list_num+1)/4);
			 if((waining_code_list_num+1)%4)
			 {
				// temp +=1;
			 }
			 else
			 {
			    if(temp)
						temp-=1;
			 }
			 if(now_page_power_alarm < temp*0x1000)
			 {
		   now_page_power_alarm_deep = 0;
			 now_page_power_alarm += 0x1000;
			 display_power_alarm_info();
			 }
		}
	}
}



void func_power_alarm_nextpage_o(void* p,u8 sn)
{

}



void func_power_alarm_nextpage_u(void* p,u8 sn)
{

}



void func_power_alarm_prepage_d(void* p,u8 sn)
{
  u8 SN = 6;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(now_page_power_alarm_deep==0)
		{
			
			  if(now_page_power_alarm >= 0x1000)
				{
			    now_page_power_alarm_deep = 0;
			    now_page_power_alarm-= 0x1000;
			    display_power_alarm_info();
				}
				else
				{
				  now_page_power_alarm_deep = 0;
			    now_page_power_alarm = 0x0000;
			    display_power_alarm_info();
				}

		}
	}
}



void func_power_alarm_prepage_o(void* p,u8 sn)
{

}



void func_power_alarm_prepage_u(void* p,u8 sn)
{

}







