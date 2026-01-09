#include "includes.h"

//////////new_5_cun//////////////////////////////////////////////////////////////////////////////
void func_power_coulumn_enter(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *power_p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		power_p = &power_page_sta.now_p[power_page_sta.now_page_num*6+SN-16];
		if((power_p->setup_menu_touch_type!=TOUCH_TYPE_NORMAL)&&(power_p->setup_menu_touch_type!=TOUCH_TYPE_KEYBOARD))
		{
			power_last_show_page_num[power_last_show_page_level] = power_page_sta.now_page_num;
			power_last_show_page_level++;
			power_page_sta.now_page_num = 0;
			power_page_sta.now_p = power_p->son_p;
			page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
			f_display_power_mes_info = TRUE;
		}
		if(*power_p->f!=empty_fun)
			(*power_p->f)(power_p,SN,TO_DEAL);	
    p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_power_touch_handle(void* p,u8 sn)
{
	u8 SN=sn;
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *power_p;
	
	if(p1->item[SN].now_status == STATUS_SELECT)
	{
		power_p = &power_page_sta.now_p[SN];
		if(power_p->setup_menu_touch_type == TOUCH_TYPE_ENTER)
		{
			power_last_show_page_num[power_last_show_page_level] = power_page_sta.now_page_num;
			power_last_show_page_level++;
			power_page_sta.now_page_num = 0;
			power_page_sta.now_p = power_p->son_p;
			page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
			f_display_power_mes_info = TRUE;
			set_power_display_item_key_type(&power_page_sta);
		}
		if(*power_p->f!=empty_fun)
			(*power_p->f)(power_p,SN,TO_DEAL);
		p1->item[SN].now_status=STATUS_IDLE;
	}
}

void func_AC_charger_line_off_new(void* p,u8 sn)
{

}



void func_AC_charger_line_on_new(void* p,u8 sn)
{

}



void func_AC_input_bg_off_5_new(void* p,u8 sn)
{
	
}



void func_AC_input_bg_on_5_new(void* p,u8 sn)
{
	func_power_touch_handle(p,sn);
}



void func_AC_Loads_bg_off_5_new(void* p,u8 sn)
{

}



void func_AC_Loads_bg_on_5_new(void* p,u8 sn)
{
	
}



void func_AC_loads_line_off_new(void* p,u8 sn)
{

}



void func_AC_loads_line_on_new(void* p,u8 sn)
{

}



void func_Battery_bg_off_5_new(void* p,u8 sn)
{

}



void func_Battery_bg_on_5_new(void* p,u8 sn)
{
	func_power_touch_handle(p,sn);
}



void func_Battery_icon_val_0_new(void* p,u8 sn)
{

}



void func_Battery_icon_val_100_new(void* p,u8 sn)
{

}



void func_Battery_icon_val_25_new(void* p,u8 sn)
{

}



void func_Battery_icon_val_50_new(void* p,u8 sn)
{

}



void func_Battery_icon_val_75_new(void* p,u8 sn)
{

}



void func_Batt_to_inverter_line_off_new(void* p,u8 sn)
{

}



void func_Batt_to_inverter_line_on_new(void* p,u8 sn)
{

}



void func_DC_charger_bg_off_5_new(void* p,u8 sn)
{

}



void func_DC_charger_bg_on_5_new(void* p,u8 sn)
{
	func_power_touch_handle(p,sn);
}



void func_DC_charger_line_off_new(void* p,u8 sn)
{

}



void func_DC_charger_line_on_new(void* p,u8 sn)
{

}



void func_DC_Loads_bg_off_5_new(void* p,u8 sn)
{

}



void func_DC_Loads_bg_on_5_new(void* p,u8 sn)
{

}



void func_DC_loads_line_off_new(void* p,u8 sn)
{

}



void func_DC_loads_line_on_new(void* p,u8 sn)
{

}



void func_Inverter_bg_off_5_new(void* p,u8 sn)
{

}



void func_Inverter_bg_on_5_new(void* p,u8 sn)
{
	func_power_touch_handle(p,sn);
}



void func_inverter_icon_down_5_new(void* p,u8 sn)
{
	u8 SN = 6;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(Is_rego_ver())
		{
		  if(parts_set_return_status.Inverter_Mode==0)
			{
				parts_set_return_status.Inverter_Mode = 3;
			}
			else
			{
				parts_set_return_status.Inverter_Mode = 0;
			}
		}
		else
		{
			//sysprintf("\r\nExtra_device_inverter_ver[0]==%dr\nExtra_device_inverter_ver[1]==%d \r\n Extra_device_inverter_ver[2]==%d \r\n Extra_device_inverter_ver[3]=%d \r\n",Extra_device_inverter_ver[0],Extra_device_inverter_ver[1],Extra_device_inverter_ver[2],Extra_device_inverter_ver[3]);
			parts_set_return_status.Inverter_Mode++;
		}
		
		if(parts_set_return_status.Inverter_Mode>=4)
		{
			parts_set_return_status.Inverter_Mode = 0;
		}
		parts_set_status.Inverter_Mode=parts_set_return_status.Inverter_Mode;
		send_FlC200_set_cmd(0x49,parts_set_status.Inverter_Mode);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
    // send_FlC200_swtich_cmd(0x24,0);//
		// disply_light_name(TRUE);
	}
}



void func_inverter_icon_up_5_new(void* p,u8 sn)
{

}



void func_Inverter_to_batt_line_off_new(void* p,u8 sn)
{

}



void func_Inverter_to_batt_line_on_new(void* p,u8 sn)
{

}



void func_Solar_charger_bg_off_5_new(void* p,u8 sn)
{

}



void func_Solar_charger_bg_on_5_new(void* p,u8 sn)
{
	func_power_touch_handle(p,sn);
}



void func_Solar_charger_line_off_new(void* p,u8 sn)
{

}



void func_Solar_charger_line_on_new(void* p,u8 sn)
{

}


void func_Power_page_back(void* p,u8 sn)
{
}



void func_Power_page_back_down(void* p,u8 sn)
{
	u8 SN = sn;
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *power_p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		power_p = &power_page_sta.now_p[0];
		if(power_p->father_p != empty_father_p)
		{
			if(power_last_show_page_level>0)
				power_last_show_page_level--;
			power_page_sta.now_page_num = power_last_show_page_num[power_last_show_page_level];
			power_page_sta.now_p = power_p->father_p;
			page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
			f_display_power_mes_info = TRUE;
			set_power_display_item_key_type(&power_page_sta);
		}
		if(*power_p->f!=empty_fun)
			(*power_p->f)(power_p,SN,TO_DEAL);	
		p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_Power_page_enter_down_1(void* p,u8 sn)
{
	func_power_coulumn_enter(p,sn);
}
void func_Power_page_enter_down_2(void* p,u8 sn)
{
	func_power_coulumn_enter(p,sn);
}
void func_Power_page_enter_down_3(void* p,u8 sn)
{
	func_power_coulumn_enter(p,sn);
}
void func_Power_page_enter_down_4(void* p,u8 sn)
{
	func_power_coulumn_enter(p,sn);
}
void func_Power_page_enter_down_5(void* p,u8 sn)
{
	func_power_coulumn_enter(p,sn);
}
void func_Power_page_enter_down_6(void* p,u8 sn)
{
	func_power_coulumn_enter(p,sn);
}


void func_Power_page_enter_up_1(void* p,u8 sn)
{                             
                              
}                             
void func_Power_page_enter_up_2(void* p,u8 sn)
{                             
                              
}                             
void func_Power_page_enter_up_3(void* p,u8 sn)
{                             
                              
}                             
void func_Power_page_enter_up_4(void* p,u8 sn)
{                             
                              
}                             
void func_Power_page_enter_up_5(void* p,u8 sn)
{

}
void func_Power_page_enter_up_6(void* p,u8 sn)
{

}

void func_Power_page_info_1(void* p,u8 sn)
{                         
                          
}                         
void func_Power_page_info_2(void* p,u8 sn)
{                         
                          
}                         
void func_Power_page_info_3(void* p,u8 sn)
{                         
                          
}                         
void func_Power_page_info_4(void* p,u8 sn)
{                         
                          
}                         
void func_Power_page_info_5(void* p,u8 sn)
{

}
void func_Power_page_info_6(void* p,u8 sn)
{

}

void func_Power_page_next_down_new(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_POWER)
		{
			if((power_page_sta.now_page_num+1)*6<power_page_sta.max_page_num)
			{
				power_page_sta.now_page_num+=1;
				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
				f_display_power_mes_info = TRUE;
			}
		}
	}
}

void func_Power_page_next_up_new(void* p,u8 sn)
{
	
}

void func_Power_page_pre_down_new(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_POWER)
		{
			//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			{
				if(power_page_sta.now_page_num)
				{
					power_page_sta.now_page_num--;
					page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
					f_display_power_mes_info = TRUE;
				}
			}
		}
	}
}

void func_Power_page_pre_up_new(void* p,u8 sn)
{

}



////////////////////old/////////////////////////////////////////////////////////////
void func_AC_input_bg_off_5(void* p,u8 sn)
{

}



void func_AC_input_bg_on_5(void* p,u8 sn)
{

}



void func_AC_input_logo_5(void* p,u8 sn)
{
	u8 SN = 1;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 1;  //
	}
}



void func_AC_Loads_bg_OFF_5(void* p,u8 sn)
{

}



void func_AC_Loads_bg_ON_5(void* p,u8 sn)
{

}



void func_AC_loads_logo_5(void* p,u8 sn)
{
	u8 SN = 3;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 1;  //
	}
}



void func_Battery_bg_off_5(void* p,u8 sn)
{

}



void func_Battery_bg_on_5(void* p,u8 sn)
{

}



void func_Battery_logo_5(void* p,u8 sn)
{	
	u8 SN = 5;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 3;  //
	}
}



void func_DC_charger_bg_off_5(void* p,u8 sn)
{

}



void func_DC_charger_bg_on_5(void* p,u8 sn)
{

}



void func_DC_charger_logo_5(void* p,u8 sn)
{
	u8 SN = 7;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 4;  //
	}
}



void func_DC_Loads_bg_off_5(void* p,u8 sn)
{

}



void func_DC_Loads_bg_on_5(void* p,u8 sn)
{

}



void func_DC_loads_logo_5(void* p,u8 sn)
{
	u8 SN = 9;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 3;  //
	}
}



void func_Inverter_bg_off_5(void* p,u8 sn)
{

}



void func_inverter_bg_on_5(void* p,u8 sn)
{
	
}


void func_inverter_icon_down_5(void* p,u8 sn)
{
	u8 SN = 11;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		inverter_ctrl_mode++;
		battery_soc_state+=25;
		if(battery_soc_state>100)
			battery_soc_state=0;
		//page_home.page_left_side.now_item = LEFT_SIDE_PAGE_UPDATA;
		//sysprintf("\r\ninverter_ctrl_mode = %d",inverter_ctrl_mode);
		if(inverter_ctrl_mode>=4)
			inverter_ctrl_mode = 0;
	}
}



void func_inverter_icon_on_5(void* p,u8 sn)
{

}



void func_inverter_logo_5(void* p,u8 sn)
{
	u8 SN = 12;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 1;  //
	}
}



void func_Solar_charger_bg_off_5(void* p,u8 sn)
{

}



void func_Solar_charger_bg_on_5(void* p,u8 sn)
{

}



void func_Solar_charger_logo_5(void* p,u8 sn)
{
	u8 SN = 14;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 2;  //
	}
}


void func_AC_charger_line_off(void* p,u8 sn)
{

}



void func_AC_charger_line_on(void* p,u8 sn)
{

}



void func_AC_loads_line_off(void* p,u8 sn)
{

}



void func_AC_loads_line_on(void* p,u8 sn)
{

}



void func_Battery_loads_line_off(void* p,u8 sn)
{

}



void func_Battery_loads_line_on(void* p,u8 sn)
{

}



void func_DC_loads_line_off(void* p,u8 sn)
{

}



void func_DC_loads_line_on(void* p,u8 sn)
{

}


void func_Inverter_charger_line_off(void* p,u8 sn)
{

}



void func_Inverter_charger_line_on(void* p,u8 sn)
{

}



void func_Solar_charger_line_off(void* p,u8 sn)
{

}



void func_Solar_charger_line_on(void* p,u8 sn)
{

}

void func_Home_Battery_icon_0(void* p,u8 sn)
{

}



void func_Home_Battery_icon_100(void* p,u8 sn)
{

}



void func_Home_Battery_icon_25(void* p,u8 sn)
{

}



void func_Home_Battery_icon_50(void* p,u8 sn)
{

}



void func_Home_Battery_icon_75(void* p,u8 sn)
{

}

void func_DC_charger_line_off(void* p,u8 sn)
{

}



void func_DC_charger_line_on(void* p,u8 sn)
{

}



void func_Home_black_info_column_1(void* p,u8 sn)
{

}



void func_Home_black_info_column_2(void* p,u8 sn)
{

}



void func_Home_black_info_column_3(void* p,u8 sn)
{

}



void func_Home_black_info_column_4(void* p,u8 sn)
{

}



void func_Home_black_info_column_5(void* p,u8 sn)
{

}



void func_Home_black_info_column_6(void* p,u8 sn)
{

}



void func_Home_black_info_column_7(void* p,u8 sn)
{

}



void func_Home_black_info_column_8(void* p,u8 sn)
{

}

void func_Home_inverter_sub_next_page(void* p,u8 sn)
{

}



void func_Home_inverter_sub_pre_page(void* p,u8 sn)
{
	u8 SN = 7;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		//p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 0 ;
		
	}
}

////////////////////////////white///////////////////////////////
void func_AC_input_bg_white_off_5(void* p,u8 sn)
{

}



void func_AC_input_bg_white_on_5(void* p,u8 sn)
{

}



void func_AC_Loads_bg_white_OFF_5(void* p,u8 sn)
{

}



void func_AC_Loads_bg_white_ON_5(void* p,u8 sn)
{

}



void func_Battery_bg_white_off_5(void* p,u8 sn)
{

}



void func_Battery_bg_white_on_5(void* p,u8 sn)
{

}



void func_bg_white_5_chun(void* p,u8 sn)
{

}



void func_DC_charger_bg_white_off_5(void* p,u8 sn)
{

}



void func_DC_charger_bg_white_on_5(void* p,u8 sn)
{

}



void func_DC_Loads_bg_white_off_5(void* p,u8 sn)
{

}



void func_DC_Loads_bg_white_on_5(void* p,u8 sn)
{

}



void func_Inverter_bg_white_off_5(void* p,u8 sn)
{

}



void func_Inverter_bg_white_on_5(void* p,u8 sn)
{

}



void func_Solar_charger_bg_white_off_5(void* p,u8 sn)
{

}



void func_Solar_charger_bg_white_on_5(void* p,u8 sn)
{

}

void func_AC_input_white_logo_5(void* p,u8 sn)
{
	u8 SN = 1;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 1;  //
	}
}



void func_AC_loads_white_logo_5(void* p,u8 sn)
{
	u8 SN = 3;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 1;  //
	}
}



void func_Battery_white_logo_5(void* p,u8 sn)
{
	u8 SN = 5;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 3;  //
	}
}



void func_DC_charger_white_logo_5(void* p,u8 sn)
{
	u8 SN = 7;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 4;  //
	}
}



void func_DC_loads_white_logo_5(void* p,u8 sn)
{
	u8 SN = 9;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 3;  //
	}
}



void func_inverter_white_logo_5(void* p,u8 sn)
{
	u8 SN = 12;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 1;  //
	}
}



void func_Solar_charger_white_logo_5(void* p,u8 sn)
{
	u8 SN = 14;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{ 
		p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 1; //子页面1
		page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_POWER] = 2;  //
	}
}

void func_Home_white_info_column_1(void* p,u8 sn)
{

}



void func_Home_white_info_column_2(void* p,u8 sn)
{

}



void func_Home_white_info_column_3(void* p,u8 sn)
{

}



void func_Home_white_info_column_4(void* p,u8 sn)
{

}



void func_Home_white_info_column_5(void* p,u8 sn)
{

}



void func_Home_white_info_column_6(void* p,u8 sn)
{

}



void func_Home_white_info_column_7(void* p,u8 sn)
{

}



void func_Home_white_info_column_8(void* p,u8 sn)
{

}



void func_Home_white_sub_next_page(void* p,u8 sn)
{

}



void func_Home_white_sub_pre_page(void* p,u8 sn)
{
	u8 SN = 7;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t *p2 ;
	
	p2 =&page_home.page_left_side;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 	
		//p1->item[SN].now_status = STATUS_IDLE;
		p2->last_item = LEFT_SIDE_PAGE_UPDATA;
		
		if(page_deepth_val[TOP_SIDE_PAGE_HOME_POWER]>0)
			page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] -= 1 ;
		else
			page_deepth_val[TOP_SIDE_PAGE_HOME_POWER] = 0;
	}
}



