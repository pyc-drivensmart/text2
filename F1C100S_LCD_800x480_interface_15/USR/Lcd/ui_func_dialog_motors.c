#include "includes.h"


extern lcd_dis_item_t dialog_motors_item[DIALOG_MOTORS_ICO_NUM];
void func_Motors_Awning_sel_u(void* p,u8 sn)
{

}

void func_Motors_Awning_sel_c(void* p,u8 sn)
{
  u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	u8 i;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<3;i++)
		{
			if((4+i)!=SN)
		  dialog_motors_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_motors_icon_select_ch = 0;
	}
}

void func_Motors_Curtain_sel_u(void* p,u8 sn)
{
	
}

void func_Motors_Curtain_sel_c(void* p,u8 sn)
{
  u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
		u8 i;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<3;i++)
		{
			if((4+i)!=SN)
		  dialog_motors_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_motors_icon_select_ch = 1;
	}
}
void func_Motors_Expansion_sel_u(void* p,u8 sn)
{

}

void func_Motors_Expansion_sel_c(void* p,u8 sn)
{
  u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
		u8 i;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		for(i=0;i<3;i++)
		{
			if((4+i)!=SN)
		  dialog_motors_item[4+i].now_status = STATUS_IDLE;
		}
		now_dialog_motors_icon_select_ch = 2;
	}
}






void func_motors_dialog_close_d(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_motors();
		f_ui_disply_dialog_motors = FALSE;
		f_ui_disply_dialog_motors_ch = FALSE;
	}
	

}



void func_motors_dialog_close_u(void* p,u8 sn)
{

}



char motors_name_default[4][20]=
{
  {"Awning"},
  {"Curtain"},
  {"Slide"},	
	{"Awning"},
};
//extern lcd_dis_item_t loads_motors_item[LOADS_MOTORS_ICO_NUM];
void func_motors_dialog_save_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
		u8 ch,i;
	char *char_p;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_motors();
		
		loads_motor_u_ico_select_p[loads_motor_u_ico_select_ch] = now_dialog_motors_icon_select_ch;
		//home_motors_d_ico_select_p[motors_load_d_ico_select_ch] = now_dialog_motors_select_ch;
		
		//sysprintf("\r\n motors_load_d_ico_select_p:%d,%d",motors_load_d_ico_select_ch,now_dialog_motors_select_ch);
   // get_motors_item_now_status();
		//get_home_motors_item_now_status();
		//sysprintf("\r\n++++++++++++++%d %d",now_dialog_motors_icon_select_ch,motors_display_motors_ch[motors_load_d_ico_select_ch]);	
    switch_name_list_return[loads_display_motors_ch[loads_motor_u_ico_select_ch]].icon_select = now_dialog_motors_icon_select_ch;
		
		//switch_name_list[motors_display_motors_ch[motors_load_d_ico_select_ch]].icon_select = now_dialog_motors_icon_select_ch;
		if(now_dialog_motors_icon_select_ch<3)
			char_p=&motors_name_default[now_dialog_motors_icon_select_ch][0];
		else
			char_p=&motors_name_default[3][0];
		for(i=0;1;i++)
		{
		   switch_name_list_return[loads_display_motors_ch[loads_motor_u_ico_select_ch]].txt[i]=char_p[i];
			if(char_p[i]==0)
			{
				switch_name_list_return[loads_display_motors_ch[loads_motor_u_ico_select_ch]].txt_len = i+1;
				break;
			}
		}		
		memcpy(&switch_name_list[loads_display_motors_ch[loads_motor_u_ico_select_ch]],         &switch_name_list_return[loads_display_motors_ch[loads_motor_u_ico_select_ch]],sizeof(SWITCH_NAME_LIST));
		memcpy(&switch_name_list_return[loads_display_motors_ch[loads_motor_u_ico_select_ch]+1],&switch_name_list_return[loads_display_motors_ch[loads_motor_u_ico_select_ch]],sizeof(SWITCH_NAME_LIST));
    memcpy(&switch_name_list[loads_display_motors_ch[loads_motor_u_ico_select_ch]+1],       &switch_name_list_return[loads_display_motors_ch[loads_motor_u_ico_select_ch]],sizeof(SWITCH_NAME_LIST));

		
		ui_loads_motors_init();
		//motors_item[motors_ICO_NUM-1].last_status = STATUS_SELECT;
		//motors_item[motors_ICO_NUM-1].now_status = STATUS_SELECT;
		//loads_motors_item[30].last_status = STATUS_SELECT;//setup
		//loads_motors_item[30].now_status = STATUS_SELECT;
		//set_motors_item_key_type(KEY_TYPE_LONG_PRESS);
		//	sysprintf("\r\n------------  %d",f_motors_b_setup_d);
		//Upgrade_load_item();
		//set_motors_item_now_status(); 
		//set_home_motors_item_now_status();
		f_ui_disply_dialog_motors = FALSE;
		
		//f_motors_b_setup_d = TRUE;
		
		//send_FlC200_swtich_name_cmd(0x1A);
		//send_FlC200_swtich_name_cmd(0x1B);
		//send_FlC200_swtich_name_cmd(0x1C);
		//send_FlC200_swtich_name_cmd(0x1D);
		send_FlC200_swtich_name_cmd(loads_display_motors_ch[loads_motor_u_ico_select_ch]);
		send_FlC200_swtich_name_cmd(loads_display_motors_ch[loads_motor_u_ico_select_ch]+1);
	//	sysprintf("\r\n------------  %d",f_motors_b_setup_d);
	  /*for(i=0;i<SWITCH_NAME_CH_NUM;i++)
		{
		   if(switch_ch_list_return[i]==now_dialog_motors_ch_select_num)
			 {
				 switch_ch_list_return[i] = 0;
				 break;
			 }
				 
		}*/
		ch = loads_display_motors_ch[now_dialog_motors_ch_select_ch];//?òμ???ó|μ??a1?o?
		if(now_dialog_motors_ch_select_num==1)
		{
		  switch_ch_list_return[ch] = 9;
		  switch_ch_list_return[ch+1] = 10;
		}
		else if(now_dialog_motors_ch_select_num==2)
		{
		  switch_ch_list_return[ch] = 10;
		  switch_ch_list_return[ch+1] = 9;
		}
	  else if(now_dialog_motors_ch_select_num==3)
		{
		  switch_ch_list_return[ch] = 11;
		  switch_ch_list_return[ch+1] = 12;
		}
		else if(now_dialog_motors_ch_select_num==4)
		{ 
		  switch_ch_list_return[ch] = 12;
		  switch_ch_list_return[ch+1] = 11;
		}
		

		
		//sysprintf("\r\n motors_load_d_ico_select_p:%d,%d",motors_load_d_ico_select_ch,now_dialog_motors_select_ch);

		set_loads_motors_item_key_type(KEY_TYPE_LONG_PRESS);
		f_ui_disply_dialog_motors_ch = FALSE;
		
		
		send_FlC200_set_cmd(0x80,ch*256+switch_ch_list_return[ch]);
		send_FlC200_set_cmd(0x80,(ch+1)*256+switch_ch_list_return[ch+1]);
		
	}
}



void func_motors_dialog_save_u(void* p,u8 sn)
{

}







//extern lcd_dis_item_t dialog_motors_ch_item[DIALOG_MOTORS_CH_ICO_NUM];

void set_now_dialog_motors_ch_select_num(u8 num)
{
   /*f(now_dialog_motors_ch_select_ch<=3)
		{
			now_dialog_motors_ch_select_num = num;
		}
		else if(now_dialog_motors_ch_select_ch>=4)		
		{
			if((num+4)<=switch_ch_select_num_max)
		  now_dialog_motors_ch_select_num = num+4;
		}*/
    now_dialog_motors_ch_select_num = num;

}

void func_motors_setup_ch_char0_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		set_now_dialog_motors_ch_select_num(1);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char1_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
    set_now_dialog_motors_ch_select_num(2);		
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char2_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
    set_now_dialog_motors_ch_select_num(3);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char3_d(void* p,u8 sn)
{
	  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
    set_now_dialog_motors_ch_select_num(4);
		disply_motors_ch_name(FALSE);
	}

}
void func_motors_setup_ch_char4_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(5);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char5_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(6);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char6_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(7);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char7_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(8);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char8_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(9);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char9_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(10);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char10_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(11);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char11_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(12);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char12_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(13);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char13_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(14);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char14_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(15);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char15_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(16);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char16_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(17);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char17_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(18);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char18_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(19);
		disply_motors_ch_name(FALSE);
	}
}
void func_motors_setup_ch_char19_d(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		set_now_dialog_motors_ch_select_num(20);
		disply_motors_ch_name(FALSE);
	}
}


