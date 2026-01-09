#include "includes.h"


void func_indicatorlamp_d(void* p,u8 sn)
{

}



void func_indicatorlamp_u(void* p,u8 sn)
{

}



void func_power_ac_bg(void* p,u8 sn)
{

}



void func_power_battery_bg(void* p,u8 sn)
{

}



void func_power_battery_ico(void* p,u8 sn)
{

}



void func_power_bc_bg(void* p,u8 sn)
{

}



void func_power_b_alarm_d(void* p,u8 sn)
{

}



void func_power_b_alarm_u(void* p,u8 sn)
{

}
void func_power_b_btn2(void* p,u8 sn)
{

}
void func_power_b_btn3(void* p,u8 sn)
{

}

void func_power_b_btn4(void* p,u8 sn)
{

}
void func_power_b_btn5(void* p,u8 sn)
{

}



void func_power_b_btn6(void* p,u8 sn)
{

}



void func_power_b_chart_d(void* p,u8 sn)
{

}



void func_power_b_chart_u(void* p,u8 sn)
{

}



void func_power_b_power_d(void* p,u8 sn)
{
	/*u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
	  page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].key_type = KEY_TYPE_NORMAL;
	  page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].last_status = STATUS_IDLE;
	  page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].now_status = STATUS_IDLE;
	}*/
}



void func_power_b_power_u(void* p,u8 sn)
{

}



void func_power_b_setup_d(void* p,u8 sn)
{
	/*u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
	  page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	  page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].last_status = STATUS_IDLE;
	  page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].now_status = STATUS_IDLE;
	}*/
}



void func_power_b_setup_u(void* p,u8 sn)
{

}



void func_power_b_system_d(void* p,u8 sn)
{

}



void func_power_b_system_u(void* p,u8 sn)
{

}



void func_power_cc_bg(void* p,u8 sn)
{

}



void func_power_inverterOFF_d(void* p,u8 sn)
{

}



void func_power_inverterOFF_u(void* p,u8 sn)
{

}



void func_power_inverterON_d(void* p,u8 sn)
{
	u8 SN = 5;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     

		
		if(Is_rego_ver())
		{
		  if(parts_set_return_status.Inverter_Mode==0)
				parts_set_return_status.Inverter_Mode = 3;
			else
				parts_set_return_status.Inverter_Mode = 0;
				
		}
		else
		parts_set_return_status.Inverter_Mode++;
		
		if(parts_set_return_status.Inverter_Mode>=4)
			parts_set_return_status.Inverter_Mode = 0;

		
		parts_set_status.Inverter_Mode=parts_set_return_status.Inverter_Mode;
		send_FlC200_set_cmd(0x49,parts_set_status.Inverter_Mode);
		
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
    // send_FlC200_swtich_cmd(0x24,0);//
		// disply_light_name(TRUE);
	}
}



void func_power_inverterON_u(void* p,u8 sn)
{

}



void func_power_sc_bg(void* p,u8 sn)
{

}





void func_power_battery_changer_0(void* p,u8 sn)
{

}



void func_power_battery_changer_1(void* p,u8 sn)
{

}



void func_power_battery_changer_2(void* p,u8 sn)
{

}



void func_power_battery_changer_3(void* p,u8 sn)
{

}



void func_power_battery_changer_4(void* p,u8 sn)
{

}



void func_power_battery_changer_5(void* p,u8 sn)
{

}

void func_power_battery_0(void* p,u8 sn)
{

}



void func_power_battery_1(void* p,u8 sn)
{

}



void func_power_battery_2(void* p,u8 sn)
{

}



void func_power_battery_3(void* p,u8 sn)
{

}



void func_power_battery_4(void* p,u8 sn)
{

}



void func_power_battery_5(void* p,u8 sn)
{

}

