#include "includes.h"
//read me:copy the new item to 'ui_func.c'
//read me:copy the new item to 'ui_func.c'





void func_dialog_bg(void* p,u8 sn)
{

}



void func_dialog_close_d(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_lights();
		f_ui_disply_dialog_lights = FALSE;
		f_ui_disply_dialog_lights_ch = FALSE;
	}
	

}



void func_dialog_close_u(void* p,u8 sn)
{

}



void func_dialog_p_d(void* p,u8 sn)
{

}



void func_dialog_p_u(void* p,u8 sn)
{

}


extern lcd_dis_item_t lights_item[LIGHTS_ICO_NUM];
char lights_name_default[8][20]=
{
  {"Pendant"},
  {"Rear Side"},
  {"Interior"},	
  {"Awning"},	
	{"Right Side"},
	{"Underbody"},
	{"Rear Work"},
	{"Light"},
};
void func_dialog_save_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 ch,i;
	char *char_p;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_lights();
		
		lights_light_d_ico_select_p[lights_light_d_ico_select_ch] = now_dialog_lights_icon_select_ch;
		//home_lights_d_ico_select_p[lights_light_d_ico_select_ch] = now_dialog_lights_select_ch;
		
		//sysprintf("\r\n lights_light_d_ico_select_p:%d,%d",lights_light_d_ico_select_ch,now_dialog_lights_select_ch);
    get_lights_item_now_status();
		get_home_lights_item_now_status();

    switch_name_list_return[lights_display_lights_ch[lights_light_d_ico_select_ch]].icon_select = now_dialog_lights_icon_select_ch;
		//switch_name_list[lights_display_lights_ch[lights_light_d_ico_select_ch]].icon_select = now_dialog_lights_icon_select_ch;
		
		
		if(now_dialog_lights_icon_select_ch<7)
			char_p=&lights_name_default[now_dialog_lights_icon_select_ch][0];
		else
			char_p=&lights_name_default[7][0];
		for(i=0;1;i++)
		{
		   switch_name_list_return[lights_display_lights_ch[lights_light_d_ico_select_ch]].txt[i]=char_p[i];
			if(char_p[i]==0)
			{
				switch_name_list_return[lights_display_lights_ch[lights_light_d_ico_select_ch]].txt_len = i+1;
				break;
			}
		}		
		memcpy(&switch_name_list[lights_display_lights_ch[lights_light_d_ico_select_ch]],&switch_name_list_return[lights_display_lights_ch[lights_light_d_ico_select_ch]],sizeof(SWITCH_NAME_LIST));

		
		ui_lights_init();
		//lights_item[LIGHTS_ICO_NUM-1].last_status = STATUS_SELECT;
		//lights_item[LIGHTS_ICO_NUM-1].now_status = STATUS_SELECT;
		lights_item[34].last_status = STATUS_SELECT;//setup
		lights_item[34].now_status = STATUS_SELECT;
		//set_lights_item_key_type(KEY_TYPE_LONG_PRESS);
		Upgrade_home_item();
		set_lights_item_now_status(); 
		set_home_lights_item_now_status();
		f_ui_disply_dialog_lights = FALSE;
		
		
		send_FlC200_swtich_name_cmd(lights_display_lights_ch[lights_light_d_ico_select_ch]);
		
		//sysprintf("\r\n------------%d %d",now_dialog_lights_icon_select_ch,lights_display_lights_ch[lights_light_d_ico_select_ch]);
		
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



void func_dialog_save_u(void* p,u8 sn)
{

}


extern lcd_dis_item_t dialog_lights_item[DIALOG_LIGHTS_ICO_NUM];
void func_lights_awning_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_lights_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_lights_icon_select_ch = 3;
	}
}



void func_lights_awning_d(void* p,u8 sn)
{

}



void func_lights_awning_u(void* p,u8 sn)
{

}



void func_lights_interior_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_lights_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_lights_icon_select_ch = 2;
	}
}



void func_lights_interior_d(void* p,u8 sn)
{

}



void func_lights_interior_u(void* p,u8 sn)
{

}



void func_lights_none_c(void* p,u8 sn)
{

}



void func_lights_none_d(void* p,u8 sn)
{

}



void func_lights_none_u(void* p,u8 sn)
{

}



void func_lights_pendant_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_lights_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_lights_icon_select_ch = 0;
	}
}



void func_lights_pendant_d(void* p,u8 sn)
{

}



void func_lights_pendant_u(void* p,u8 sn)
{

}



void func_lights_rearside_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_lights_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_lights_icon_select_ch = 1;
	}
}



void func_lights_rearside_d(void* p,u8 sn)
{

}



void func_lights_rearside_u(void* p,u8 sn)
{

}



void func_lights_rearwork_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_lights_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_lights_icon_select_ch = 6;
	}
}



void func_lights_rearwork_d(void* p,u8 sn)
{

}



void func_lights_rearwork_u(void* p,u8 sn)
{

}



void func_lights_rightside_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_lights_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_lights_icon_select_ch = 4;
	}
}



void func_lights_rightside_d(void* p,u8 sn)
{

}



void func_lights_rightside_u(void* p,u8 sn)
{

}



void func_lights_underbody_c(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
	u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<8;i++)
		{
			if((4+i)!=SN)
		  dialog_lights_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_lights_icon_select_ch = 5;
	}
}



void func_lights_underbody_d(void* p,u8 sn)
{

}



void func_lights_underbody_u(void* p,u8 sn)
{

}


