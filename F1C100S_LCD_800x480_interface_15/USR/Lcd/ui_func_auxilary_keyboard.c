#include "includes.h"

void func_keyboard_5cun_0_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('0');
	}
}



void func_keyboard_5cun_0_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_1_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('1');
	}
}



void func_keyboard_5cun_1_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_2_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('2');
	}
}



void func_keyboard_5cun_2_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_3_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('3');
	}
}



void func_keyboard_5cun_3_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_4_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('4');
	}
}



void func_keyboard_5cun_4_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_5_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('5');
	}
}



void func_keyboard_5cun_5_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_6_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('6');
	}
}



void func_keyboard_5cun_6_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_7_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('7');
	}
}



void func_keyboard_5cun_7_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_8_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('8');
	}
}



void func_keyboard_5cun_8_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_9_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('9');
	}
}



void func_keyboard_5cun_9_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_bg(void* p,u8 sn)
{

}



void func_keyboard_5cun_close_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val(0x1b);
	}
}



void func_keyboard_5cun_close_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_delete_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val(0x8);
	}
}



void func_keyboard_5cun_delete_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_dot_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val('.');
	}
}



void func_keyboard_5cun_dot_u(void* p,u8 sn)
{

}



void func_keyboard_5cun_enter_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input_val(0x0D);
	}
}



void func_keyboard_5cun_enter_u(void* p,u8 sn)
{

}

