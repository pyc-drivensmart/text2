#include "includes.h"



void func_system_info_ble_code(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n************8888 %d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		//sysprintf("\r\n************9999 %d",p1->item[SN].now_status);
		    keyboard_ui_step=KEYBOARD_PAGE_NUM;
		     //ui_disply_keyboard();
				 f_ui_new_input_code = TRUE;
				 f_need_ui_disply_keyboard = TRUE;
	}
}
void func_system_info_screen_upgrade_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
	char upgrade_info[]="Please press the Start button to start.";
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	
  if(p1->item[SN].now_status==STATUS_IDLE)
	{ 
	  // send_FlC200_base_set_cmd(0x88,0x01,0);
		memcpy(&upgrade_info1,&upgrade_info,48);
	  upgrade_info2[0] = 0;
	  upgrade_info3[0] = 0;
		upgrade_info_len1 = 1;
		upgrade_info_len2 = 1;
		upgrade_info_len3 = 1;
  	//p1->item[SN].now_status=STATUS_IDLE;
		//p1->item[SN].last_status=STATUS_IDLE;
	  ui_disply_dialog_info();
    set_dialog_info_start_key_type(KEY_TYPE_ONCE);
    set_dialog_info_close_key_type(KEY_TYPE_ONCE);
	}

}
void func_system_info_screen_upgrade_u(void* p,u8 sn)
{
//	u8 SN = sn;//图标在当前页面列表的序号

}
void func_system_info_control_upgrade_d(void* p,u8 sn)
{
	//u8 SN = sn;//图标在当前页面列表的序号

}
void func_system_info_control_upgrade_u(void* p,u8 sn)
{
	//u8 SN = sn;//图标在当前页面列表的序号

}
void func_system_info_code_d(void* p,u8 sn)
{
	//u8 SN = sn;//图标在当前页面列表的序号
		u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n************8888 %d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		//sysprintf("\r\n************9999 %d",p1->item[SN].now_status);
		    keyboard_ui_step=KEYBOARD_PAGE_NUM;
		     //ui_disply_keyboard();
				 f_ui_new_input_code = TRUE;
				 f_need_ui_disply_keyboard = TRUE;
	}

}
void func_system_info_code_u(void* p,u8 sn)
{
	//u8 SN = sn;//图标在当前页面列表的序号

}
