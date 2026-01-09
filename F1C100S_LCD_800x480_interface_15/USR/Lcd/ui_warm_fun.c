#include "includes.h"

void func_alarm_up_d(void* p,u8 sn)//上一页
{
	u8 SN = 7;//图标在当前页面列表的序号
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
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

void func_alarm_up_up(void* p,u8 sn)
{

}
void func_alarm_down_d(void* p,u8 sn)//下一页
{
	u8 SN = 7;//图标在当前页面列表的序号
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
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
void func_alarm_down_up(void* p,u8 sn)
{

}

