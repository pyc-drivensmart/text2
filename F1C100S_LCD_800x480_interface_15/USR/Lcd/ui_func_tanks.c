#include "includes.h"




void func_tanks_black_100(void* p,u8 sn)
{

}



void func_tanks_black_bg(void* p,u8 sn)
{

}



void func_tanks_black_wave(void* p,u8 sn)
{

}



void func_tanks_b_tanks_d(void* p,u8 sn)
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



void func_tanks_b_tanks_u(void* p,u8 sn)
{

}



void func_tanks_fresh_100(void* p,u8 sn)
{

}



void func_tanks_fresh_bg(void* p,u8 sn)
{

}



void func_tanks_fresh_wave(void* p,u8 sn)
{

}



void func_tanks_grey_100(void* p,u8 sn)
{

}



void func_tanks_grey_bg(void* p,u8 sn)
{

}



void func_tanks_grey_wave(void* p,u8 sn)
{

}



void func_tanks_LPG_100(void* p,u8 sn)
{

}



void func_tanks_LPG_bg(void* p,u8 sn)
{

}



void func_tanks_LPG_wave(void* p,u8 sn)
{

}



void func_tanks_wpOFF_d(void* p,u8 sn)
{
	/*u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x2F,1);//
		//disply_load_name(TRUE);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x2F,0);//
		// disply_load_name(TRUE);
	}*/
}



void func_tanks_wpOFF_u(void* p,u8 sn)
{

}



void func_tanks_wpON_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x06,1);//
		//disply_load_name(TRUE);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x06,0);//
		// disply_load_name(TRUE);
	}
	disply_tanks_tank_ch_name(TRUE);
}



void func_tanks_wpON_u(void* p,u8 sn)
{

}

void func_tanks_heat_ON(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x07,1);//
		//disply_load_name(TRUE);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x07,0);//
		// disply_load_name(TRUE);
	}
	disply_tanks_tank_ch_name(TRUE);
}
	void func_tanks_heat_OFF(void* p,u8 sn)
{

}

extern lcd_dis_item_t tanks_setup_item[];
void func_tanks_b_setup_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
	  //page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	  //page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].last_status = STATUS_IDLE;
	 // page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].now_status = STATUS_IDLE;
		//tanks_setup_item[TANKS_SET_ICO_NUM-1].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 //     tanks_setup_item[TANKS_SET_ICO_NUM-1].last_status = STATUS_IDLE;
	 //     tanks_setup_item[TANKS_SET_ICO_NUM-1].now_status = STATUS_IDLE;
		//sysprintf("\r\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	}
}



void func_tanks_b_setup_u(void* p,u8 sn)
{

}

