#include "includes.h"
//read me:copy the new item to 'ui_func.c'
//read me:copy the new item to 'ui_func.c'




void func_dialog_start_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
	   send_FlC200_base_set_cmd(0x88,0x01,0);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
	  set_dialog_info_start_key_type(KEY_TYPE_TOUCH_NONE);
    set_dialog_info_close_key_type(KEY_TYPE_ONCE);
	}
}
void func_dialog_start_u(void* p,u8 sn)
{

}

void func_dialog_close_info_d(void* p,u8 sn)
{
	 u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_info();
		send_FlC200_base_set_cmd(0x88,0xFF,0);
		f_ui_disply_dialog_info = FALSE;
	}
	

}



void func_dialog_close_info_u(void* p,u8 sn)
{

}







