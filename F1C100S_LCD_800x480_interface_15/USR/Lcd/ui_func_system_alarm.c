#include "includes.h"



void func_system_alarm_btn1_d(void* p,u8 sn)
{
	u8 SN = 1;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(now_page_alarm_deep==0)
		{
			if(now_page_alarm == 0x0000)
			{
		    waining_code_list_num = 0;
				power_waining_code_list_num = 0;
				//sysprintf("\r\n000000000000000000000000000");
				last_waining_code_list_num = 0;
			  send_FlC200_base_set_cmd(0x80,0xFF,0);
			 // display_set_alarm_info();
			}
			
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
		if(now_page_alarm_deep==0)
		{
			if(now_page_alarm == 0x0000)
			{
		   /// waining_code_list_num = 0;
			 // send_FlC200_base_set_cmd(0x80,0xFF,0);
			  display_set_alarm_info();
			}
			
		}
	}

}



void func_system_alarm_btn1_u(void* p,u8 sn)
{

}



void func_system_alarm_btn2_d(void* p,u8 sn)
{

}



void func_system_alarm_btn2_u(void* p,u8 sn)
{

}



void func_system_alarm_btn3_d(void* p,u8 sn)
{
}



void func_system_alarm_btn3_u(void* p,u8 sn)
{

}



void func_system_alarm_btn4_d(void* p,u8 sn)
{

}



void func_system_alarm_btn4_u(void* p,u8 sn)
{

}



void func_system_alarm_b_system_alarm_d(void* p,u8 sn)
{

}



void func_system_alarm_b_system_alarm_u(void* p,u8 sn)
{

}



void func_system_alarm_headline(void* p,u8 sn)
{

}



void func_system_alarm_nextpage_d(void* p,u8 sn)
{
	u8 temp = 0 ;
  u8 SN = 5;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(now_page_alarm_deep==0)
		{
			
			 temp = ((waining_code_list_num+1)/4);
			 if((waining_code_list_num+1)%4)
			 {
				// temp +=1;
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
			 display_set_alarm_info();
			 }
		}
	}
}



void func_system_alarm_nextpage_o(void* p,u8 sn)
{

}



void func_system_alarm_nextpage_u(void* p,u8 sn)
{

}



void func_system_alarm_prepage_d(void* p,u8 sn)
{
  u8 SN = 6;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(now_page_alarm_deep==0)
		{
			
			  if(now_page_alarm >= 0x1000)
				{
			    now_page_alarm_deep = 0;
			    now_page_alarm-= 0x1000;
			    display_set_alarm_info();
				}
				else
				{
				  now_page_alarm_deep = 0;
			    now_page_alarm = 0x0000;
			    display_set_alarm_info();
				}

		}
	}
}



void func_system_alarm_prepage_o(void* p,u8 sn)
{

}



void func_system_alarm_prepage_u(void* p,u8 sn)
{

}

//read me:copy the new item to 'ui_func.c'




void func_set_err_r_1(void* p,u8 sn)
{

}
void func_set_err_r_2(void* p,u8 sn)
{

}
void func_set_err_r_3(void* p,u8 sn)
{

}
void func_set_err_r_4(void* p,u8 sn)
{

}
void func_set_err_y_1(void* p,u8 sn)
{

}
void func_set_err_y_2(void* p,u8 sn)
{

}
void func_set_err_y_3(void* p,u8 sn)
{

}
void func_set_err_y_4(void* p,u8 sn)
{

}



