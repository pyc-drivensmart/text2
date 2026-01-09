#include "includes.h"
//read me:copy the new item to 'ui_func.c'
//read me:copy the new item to 'ui_func.c'
//read me:copy the new item to 'ui_func.c'





void func_loads_AC_sel_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 3;
	}
}



void func_loads_AC_sel_u(void* p,u8 sn)
{

}



void func_loads_fridge_sel_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 1;
	}
}



void func_loads_fridge_sel_u(void* p,u8 sn)
{

}



void func_loads_KV_sel_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 2;
	}
}



void func_loads_KV_sel_u(void* p,u8 sn)
{

}



void func_loads_load_sel_c(void* p,u8 sn)
{
 /* u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 0;
	}*/
}



void func_loads_load_sel_u(void* p,u8 sn)
{

}



void func_loads_MW_sel_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 4;
	}
}



void func_loads_MW_sel_u(void* p,u8 sn)
{

}



void func_loads_TV_sel_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 5;
	}
}



void func_loads_TV_sel_u(void* p,u8 sn)
{

}



void func_loads_ventilator_sel_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 0;
	}
}



void func_loads_ventilator_sel_u(void* p,u8 sn)
{

}



void func_loads_WM_sel_c(void* p,u8 sn)
{
u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 6;
	}
}



void func_loads_WM_sel_u(void* p,u8 sn)
{

}



void func_loads_wp_sel_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_loads_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_loads_icon_select_ch = 7;
	}
}



void func_loads_wp_sel_u(void* p,u8 sn)
{

}



void func_loads_dialog_close_d(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_loads();
		f_ui_disply_dialog_loads = FALSE;
		f_ui_disply_dialog_loads_ch = FALSE;
	}
	

}



void func_loads_dialog_close_u(void* p,u8 sn)
{

}



char loads_name_default[8][20]=
{
  {"Ventilator"},
  {"Fridge"},
  {"Kitchen Vent."},	
  {"Air Conditioner"},	
	{"Microwave"},
	{"TV"},
	{"Washing Michine"},
	{"Load"},
};
extern lcd_dis_item_t loads_item[LOADS_ICO_NUM];
void func_loads_dialog_save_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
		u8 ch,i;
	char *char_p;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_loads();
		
		loads_load_d_ico_select_p[loads_load_d_ico_select_ch] = now_dialog_loads_icon_select_ch;
		//home_loads_d_ico_select_p[loads_load_d_ico_select_ch] = now_dialog_loads_select_ch;
		
		//sysprintf("\r\n loads_load_d_ico_select_p:%d,%d",loads_load_d_ico_select_ch,now_dialog_loads_select_ch);
    get_loads_item_now_status();
		get_home_loads_item_now_status();
		//sysprintf("\r\n++++++++++++++%d %d",now_dialog_loads_icon_select_ch,loads_display_loads_ch[loads_load_d_ico_select_ch]);	
    switch_name_list_return[loads_display_loads_ch[loads_load_d_ico_select_ch]].icon_select = now_dialog_loads_icon_select_ch;
		//switch_name_list[loads_display_loads_ch[loads_load_d_ico_select_ch]].icon_select = now_dialog_loads_icon_select_ch;
		if(now_dialog_loads_icon_select_ch<7)
			char_p=&loads_name_default[now_dialog_loads_icon_select_ch][0];
		else
			char_p=&loads_name_default[7][0];
		for(i=0;1;i++)
		{
		   switch_name_list_return[loads_display_loads_ch[loads_load_d_ico_select_ch]].txt[i]=char_p[i];
			if(char_p[i]==0)
			{
				switch_name_list_return[loads_display_loads_ch[loads_load_d_ico_select_ch]].txt_len = i+1;
				break;
			}
		}		
		memcpy(&switch_name_list[loads_display_loads_ch[loads_load_d_ico_select_ch]],&switch_name_list_return[loads_display_loads_ch[loads_load_d_ico_select_ch]],sizeof(SWITCH_NAME_LIST));

		
		ui_loads_init();
		//loads_item[LOADS_ICO_NUM-1].last_status = STATUS_SELECT;
		//loads_item[LOADS_ICO_NUM-1].now_status = STATUS_SELECT;
		loads_item[30].last_status = STATUS_SELECT;//setup
		loads_item[30].now_status = STATUS_SELECT;
		//set_loads_item_key_type(KEY_TYPE_LONG_PRESS);
		//	sysprintf("\r\n------------  %d",f_loads_b_setup_d);
		Upgrade_load_item();
		set_loads_item_now_status(); 
		set_home_loads_item_now_status();
		f_ui_disply_dialog_loads = FALSE;
		
		//f_loads_b_setup_d = TRUE;
		
		send_FlC200_swtich_name_cmd(loads_display_loads_ch[loads_load_d_ico_select_ch]);
		
	//	sysprintf("\r\n------------  %d",f_loads_b_setup_d);
	  for(i=0;i<SWITCH_NAME_CH_NUM;i++)
		{
		   if(switch_ch_list_return[i]==now_dialog_loads_ch_select_num)
			 {
				 switch_ch_list_return[i] = 0;
				 break;
			 }
				 
		}
		ch = loads_display_loads_ch[now_dialog_loads_ch_select_ch];//?òμ???ó|μ??a1?o?
		switch_ch_list_return[ch] = now_dialog_loads_ch_select_num;

		
		//sysprintf("\r\n loads_load_d_ico_select_p:%d,%d",loads_load_d_ico_select_ch,now_dialog_loads_select_ch);

		set_loads_item_key_type(KEY_TYPE_LONG_PRESS);
		f_ui_disply_dialog_loads_ch = FALSE;
		
		
		send_FlC200_set_cmd(0x80,ch*256+now_dialog_loads_ch_select_num);
		
	}
}



void func_loads_dialog_save_u(void* p,u8 sn)
{

}
