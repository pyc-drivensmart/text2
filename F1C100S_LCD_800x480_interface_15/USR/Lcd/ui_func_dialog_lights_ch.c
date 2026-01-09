#include "includes.h"
//read me:copy the new item to 'ui_func.c'
//read me:copy the new item to 'ui_func.c'







void func_dialog_close_lights_ch_d(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_lights_ch();
		f_ui_disply_dialog_lights_ch = FALSE;
	}
	

}



void func_dialog_close_lights_ch_u(void* p,u8 sn)
{

}





void func_dialog_save_lights_ch_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	u8 ch;
	u8 i;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_lights_ch();
		
		
		 for(i=0;i<SWITCH_NAME_CH_NUM;i++)
		{
		   if(switch_ch_list_return[i]==now_dialog_lights_ch_select_num)
			 {
				 switch_ch_list_return[i] = 0;
				 break;
			 }
				 
		}
		
		ch = lights_display_lights_ch[now_dialog_lights_ch_select_ch];//找到对应的开关号
		switch_ch_list_return[ch] = now_dialog_lights_ch_select_num;

		

		set_lights_item_key_type(KEY_TYPE_LONG_PRESS);
		f_ui_disply_dialog_lights_ch = FALSE;
				
		send_FlC200_set_cmd(0x80,ch*256+now_dialog_lights_ch_select_num);
		

	}
}



void func_dialog_save_lights_ch_u(void* p,u8 sn)
{

}










extern lcd_dis_item_t dialog_lights_ch_item[DIALOG_LIGHTS_CH_ICO_NUM];


void set_now_dialog_lights_ch_select_num(u8 num)
{
   // if(now_dialog_lights_ch_select_ch<=3)
		{
			now_dialog_lights_ch_select_num = num;
		}
		/*else if(now_dialog_lights_ch_select_ch>=4)		
		{
			if((num+4)<=switch_ch_select_num_max)
		  now_dialog_lights_ch_select_num = num+4;
		}*/


}

void func_lights_setup_ch_char0_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		set_now_dialog_lights_ch_select_num(1);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
    set_now_dialog_lights_ch_select_num(2);		
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char2_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
    set_now_dialog_lights_ch_select_num(3);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char3_d(void* p,u8 sn)
{
	  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
    set_now_dialog_lights_ch_select_num(4);
		disply_lights_ch_name(FALSE);
	}

}
void func_lights_setup_ch_char4_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(5);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char5_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(6);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char6_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(7);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char7_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(8);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char8_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(9);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char9_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(10);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char10_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(11);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char11_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(12);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char12_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(13);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char13_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(14);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char14_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(15);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char15_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(16);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char16_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(17);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char17_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(18);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char18_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(19);
		disply_lights_ch_name(FALSE);
	}
}
void func_lights_setup_ch_char19_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_lights_ch_select_num(20);
		disply_lights_ch_name(FALSE);
	}
}








