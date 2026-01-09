#include "includes.h"
//read me:copy the new item to 'ui_func.c'
//read me:copy the new item to 'ui_func.c'







void func_dialog_close_loads_ch_d(void* p,u8 sn)
{
	 u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_loads_ch();
		f_ui_disply_dialog_loads_ch = FALSE;
	}
	

}



void func_dialog_close_loads_ch_u(void* p,u8 sn)
{

}





void func_dialog_save_loads_ch_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	u8 ch;
	u8 i;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_loads_ch();
		for(i=0;i<SWITCH_NAME_CH_NUM;i++)
		{
		   if(switch_ch_list_return[i]==now_dialog_loads_ch_select_num)
			 {
				 switch_ch_list_return[i] = 0;
				 break;
			 }
				 
		}
		ch = loads_display_loads_ch[now_dialog_loads_ch_select_ch];//?¨°¦Ì???¨®|¦Ì??a1?o?
		switch_ch_list_return[ch] = now_dialog_loads_ch_select_num;

		
		//sysprintf("\r\n loads_load_d_ico_select_p:%d,%d",loads_load_d_ico_select_ch,now_dialog_loads_select_ch);
  /*  get_loads_item_now_status();
		get_home_loads_item_now_status();
    switch_name_list_return[loads_display_loads_ch[loads_load_d_ico_select_ch]].icon_select = now_dialog_loads_icon_select_ch;
		switch_name_list[loads_display_loads_ch[loads_load_d_ico_select_ch]].icon_select = now_dialog_loads_icon_select_ch;
		
		ui_loads_init();
		Upgrade_home_item();
		set_loads_item_now_status(); 
		set_home_loads_item_now_status();
		*/
		set_loads_item_key_type(KEY_TYPE_LONG_PRESS);
		f_ui_disply_dialog_loads_ch = FALSE;
		
		
		send_FlC200_set_cmd(0x80,ch*256+now_dialog_loads_ch_select_num);
		
		//sysprintf("\r\n------------%X %d",ch*256+now_dialog_loads_ch_select_num,now_dialog_loads_ch_select_num);
		
	}
}



void func_dialog_save_loads_ch_u(void* p,u8 sn)
{

}










extern lcd_dis_item_t dialog_loads_ch_item[DIALOG_LOADS_CH_ICO_NUM];

void set_now_dialog_loads_ch_select_num(u8 num)
{
   /*f(now_dialog_loads_ch_select_ch<=3)
		{
			now_dialog_loads_ch_select_num = num;
		}
		else if(now_dialog_loads_ch_select_ch>=4)		
		{
			if((num+4)<=switch_ch_select_num_max)
		  now_dialog_loads_ch_select_num = num+4;
		}*/
    now_dialog_loads_ch_select_num = num;

}

void func_loads_setup_ch_char0_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		set_now_dialog_loads_ch_select_num(1);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char1_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
    set_now_dialog_loads_ch_select_num(2);		
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char2_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
    set_now_dialog_loads_ch_select_num(3);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char3_d(void* p,u8 sn)
{
	  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
    set_now_dialog_loads_ch_select_num(4);
		disply_loads_ch_name(FALSE);
	}

}
void func_loads_setup_ch_char4_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(5);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char5_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(6);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char6_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(7);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char7_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(8);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char8_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(9);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char9_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(10);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char10_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(11);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char11_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(12);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char12_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(13);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char13_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(14);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char14_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(15);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char15_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(16);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char16_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(17);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char17_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(18);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char18_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(19);
		disply_loads_ch_name(FALSE);
	}
}
void func_loads_setup_ch_char19_d(void* p,u8 sn)
{
  u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_loads_ch_select_num(20);
		disply_loads_ch_name(FALSE);
	}
}








