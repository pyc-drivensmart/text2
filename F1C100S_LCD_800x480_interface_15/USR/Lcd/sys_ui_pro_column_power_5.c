#include "includes.h"

extern setup_item_info_t power_main_page[];

#define TOTAL_PAGE_NUM 4
#define POWER_TEST_ITEM_NUM 30
#define DETAIL_PAGE_ITEM_NUM 14
u8 page_deepth_val[TOTAL_PAGE_NUM] = {0};	
u8 page_sub_page_serial_num[2][TOTAL_PAGE_NUM] = {0};

lcd_dis_item_t *p_power_item_5_test_u[POWER_TEST_ITEM_NUM]={
	&t_AC_input_bg_off_5_new     ,   //
	&t_AC_Loads_bg_off_5_new     ,
	&t_Battery_bg_off_5_new      ,
	&t_DC_charger_bg_off_5_new   ,
	&t_DC_Loads_bg_off_5_new     ,
	&t_Inverter_bg_off_5_new    ,
	&t_inverter_icon_up_5_new  ,
	&t_Solar_charger_bg_off_5_new,
	&t_AC_charger_line_off_new,
	&t_AC_loads_line_off_new,
	&t_Batt_to_inverter_line_off_new,
	&t_DC_loads_line_off_new,
	&t_Inverter_to_batt_line_off_new,
	&t_Solar_charger_line_off_new,
	&t_DC_charger_line_off_new,
	&t_Battery_icon_val_0_new,
	
	&t_Power_page_back,
	//&t_Power_page_enter_up_1,
	&t_Power_page_enter_up_2,
	&t_Power_page_enter_up_3,
	&t_Power_page_enter_up_4,
	&t_Power_page_enter_up_5,
	&t_Power_page_enter_up_6,
	//&t_Power_page_info_1,
	&t_Power_page_back,
	&t_Power_page_info_2,
	&t_Power_page_info_3,
	&t_Power_page_info_4,
	&t_Power_page_info_5,
	&t_Power_page_info_6,
	
	&t_Power_page_next_up_new,
	&t_Power_page_pre_up_new,
	//&t_bgbg_test,
};

lcd_dis_item_t *p_power_item_5_test_d[POWER_TEST_ITEM_NUM]={
	&t_AC_input_bg_on_5_new     ,   
	&t_AC_Loads_bg_on_5_new     ,
	&t_Battery_bg_on_5_new      ,
	&t_DC_charger_bg_on_5_new   ,
	&t_DC_Loads_bg_on_5_new     ,
	&t_Inverter_bg_on_5_new    ,
	&t_inverter_icon_down_5_new  ,
	&t_Solar_charger_bg_on_5_new,
	&t_AC_charger_line_on_new,
	&t_AC_loads_line_on_new,
	&t_Batt_to_inverter_line_on_new,
	&t_DC_loads_line_on_new,
	&t_Inverter_to_batt_line_on_new,
	&t_Solar_charger_line_on_new,
	&t_DC_charger_line_on_new,
	&t_Battery_icon_val_0_new,
	
	&t_Power_page_back_down,
	//&t_Power_page_enter_down_1,
	&t_Power_page_enter_down_2,
	&t_Power_page_enter_down_3,
	&t_Power_page_enter_down_4,
	&t_Power_page_enter_down_5,
	&t_Power_page_enter_down_6,
	//&t_Power_page_info_1,
	&t_Power_page_back_down,
	&t_Power_page_info_2,
	&t_Power_page_info_3,
	&t_Power_page_info_4,
	&t_Power_page_info_5,
	&t_Power_page_info_6,
	
	&t_Power_page_next_down_new,
	&t_Power_page_pre_down_new,
	//&t_bgbg_test,
};
lcd_dis_item_t *p_detail_page_item_u[DETAIL_PAGE_ITEM_NUM]={
	&t_Power_page_back,
	&t_Power_page_enter_up_2,
	&t_Power_page_enter_up_3,
	&t_Power_page_enter_up_4,
	&t_Power_page_enter_up_5,
	&t_Power_page_enter_up_6,
	&t_Power_page_back,
	&t_Power_page_info_2,
	&t_Power_page_info_3,
	&t_Power_page_info_4,
	&t_Power_page_info_5,
	&t_Power_page_info_6,
	
	&t_Power_page_next_up_new,
	&t_Power_page_pre_up_new,
};
lcd_dis_item_t *p_detail_page_item_d[DETAIL_PAGE_ITEM_NUM]={
	&t_Power_page_back_down,
	&t_Power_page_enter_down_2,
	&t_Power_page_enter_down_3,
	&t_Power_page_enter_down_4,
	&t_Power_page_enter_down_5,
	&t_Power_page_enter_down_6,
	&t_Power_page_back_down,
	&t_Power_page_info_2,
	&t_Power_page_info_3,
	&t_Power_page_info_4,
	&t_Power_page_info_5,
	&t_Power_page_info_6,
	
	&t_Power_page_next_down_new,
	&t_Power_page_pre_down_new,
};

setup_item_info_t batt_alarm[]=
{
	{"Battery_Info->Alarm",TOUCH_TYPE_SAVE_AND_BACK,batt_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t batt_history_info[]=
{
	{"Battery_Info->Histroy",TOUCH_TYPE_SAVE_AND_BACK,batt_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t batt_device_info[]=
{
	{"Battery_Info->Device",TOUCH_TYPE_SAVE_AND_BACK,batt_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t batt_page_info[]=
{
	{"Battery_Info",TOUCH_TYPE_SAVE_AND_BACK,power_main_page,empty_son_p,empty_fun},
	{"Battery",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"State of charge",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Consumed AmpHours",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Timer",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Alarm",TOUCH_TYPE_ENTER,power_main_page,batt_alarm,empty_fun},
	{"Battery_Info",TOUCH_TYPE_SAVE_AND_BACK,power_main_page,empty_son_p,empty_fun},
	{"History",TOUCH_TYPE_ENTER,power_main_page,batt_history_info,empty_fun},
	{"Device",TOUCH_TYPE_ENTER,power_main_page,batt_device_info,empty_fun},
	//{"Device",TOUCH_TYPE_BACKGROUND,power_main_page,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t inv_advance[]=
{
	{"Inverter_Info->Advanced",TOUCH_TYPE_SAVE_AND_BACK,inv_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t inv_alarm_status[]=
{
	{"Inverter_Info->Alarm_status",TOUCH_TYPE_SAVE_AND_BACK,inv_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t inv_alarm_setup[]=
{
	{"Inverter_Info->Alarm_setup",TOUCH_TYPE_SAVE_AND_BACK,inv_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t inv_device[]=
{
	{"Inverter_Info->Device",TOUCH_TYPE_SAVE_AND_BACK,inv_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t inv_page_info[]=
{
	{"Inverter_Info",TOUCH_TYPE_SAVE_AND_BACK,power_main_page,empty_son_p,empty_fun},
	{"Grid current limit",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"DC Voltage",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"DC Current",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"State of charge",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Active AC Input",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Inverter_Info",TOUCH_TYPE_SAVE_AND_BACK,power_main_page,empty_son_p,empty_fun},
	{"Advanced",TOUCH_TYPE_ENTER,power_main_page,inv_advance,empty_fun},
	{"Alarm status",TOUCH_TYPE_ENTER,power_main_page,inv_alarm_status,empty_fun},
	{"Alarm setup",TOUCH_TYPE_ENTER,power_main_page,inv_alarm_setup,empty_fun},
	{"Device",TOUCH_TYPE_ENTER,power_main_page,inv_device,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t solar_history[]=
{
	{"Solar_Info->History",TOUCH_TYPE_SAVE_AND_BACK,solar_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t solar_network[]=
{
	{"Solar_Info->Network",TOUCH_TYPE_SAVE_AND_BACK,solar_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t solar_device[]=
{
	{"Solar_Info->Device",TOUCH_TYPE_SAVE_AND_BACK,solar_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t solar_page_info[]=
{
	{"Solar_Info",TOUCH_TYPE_SAVE_AND_BACK,power_main_page,empty_son_p,empty_fun},
	{"Pv info",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Pv state",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Yield Today",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Battery",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Load",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Solar_Info",TOUCH_TYPE_SAVE_AND_BACK,power_main_page,empty_son_p,empty_fun},
	{"Alarm & Errors",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"History",TOUCH_TYPE_ENTER,power_main_page,solar_history,empty_fun},
	{"Networked operation",TOUCH_TYPE_ENTER,power_main_page,solar_network,empty_fun},
	{"Device",TOUCH_TYPE_ENTER,power_main_page,solar_device,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t dcdc_overall_history[]=
{
	{"DcDc_info->Overall_history",TOUCH_TYPE_SAVE_AND_BACK,dcdc_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t dcdc_cycle_history[]=
{
	{"DcDc_info->Cycle_history",TOUCH_TYPE_SAVE_AND_BACK,dcdc_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t dcdc_device[]=
{
	{"DcDc_info->Device",TOUCH_TYPE_SAVE_AND_BACK,dcdc_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t dcdc_page_info[]=
{
	{"DcDc_info",TOUCH_TYPE_SAVE_AND_BACK,power_main_page,empty_son_p,empty_fun},
	{"Input",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Output",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"State",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Network status",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"Error",TOUCH_TYPE_NONE,power_main_page,empty_son_p,empty_fun},
	{"DcDc_info",TOUCH_TYPE_SAVE_AND_BACK,power_main_page,empty_son_p,empty_fun},
	{"Overall history",TOUCH_TYPE_ENTER,power_main_page,dcdc_overall_history,empty_fun},
	{"Charge cycle history",TOUCH_TYPE_ENTER,power_main_page,dcdc_cycle_history,empty_fun},
	{"Device",TOUCH_TYPE_ENTER,power_main_page,dcdc_device,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t power_main_page[]=
{
	{"",TOUCH_TYPE_ENTER,empty_father_p,inv_page_info,empty_fun},
	{"",TOUCH_TYPE_NONE,empty_father_p,empty_son_p,empty_fun},
	{"",TOUCH_TYPE_ENTER,empty_father_p,batt_page_info,empty_fun},
	{"",TOUCH_TYPE_ENTER,empty_father_p,dcdc_page_info,empty_fun},
	{"",TOUCH_TYPE_NONE,empty_father_p,empty_son_p,empty_fun},
	{"",TOUCH_TYPE_ENTER,empty_father_p,inv_page_info,empty_fun},
	{"",TOUCH_TYPE_NONE,empty_father_p,empty_son_p,empty_fun},
	{"",TOUCH_TYPE_ENTER,empty_father_p,solar_page_info,empty_fun},
	{"",TOUCH_TYPE_NONE,empty_father_p,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};


setup_page_t power_page_sta;
lcd_dis_item_t detail_page_item[DETAIL_PAGE_ITEM_NUM];
lcd_dis_item_t test_power_item[POWER_TEST_ITEM_NUM];
u8 demo_mode=0;
u8 show_mode=0;
u8 inverter_ctrl_mode = 0;
u8 battery_soc_state = 0;
bool f_display_power_mes_info = FALSE;
u8 power_last_show_page_num[3];
u8 power_last_show_page_level = 0;
void set_power_display_item_key_type(setup_page_t *power_info_page_p)
{
	u8 i = 0;
	if(power_info_page_p->now_p == power_main_page)
	{
		for(i=0;i<30;i++)
		{
			if(i>=16)
				test_power_item[i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			else
				test_power_item[i].key_type = KEY_TYPE_TOUCH_NONE;
		}
		//test_power_item[0].key_type = KEY_TYPE_ONCE;
		//test_power_item[2].key_type = KEY_TYPE_ONCE;
		//test_power_item[3].key_type = KEY_TYPE_ONCE;
		//test_power_item[5].key_type = KEY_TYPE_ONCE;
		//test_power_item[7].key_type = KEY_TYPE_ONCE;
		if(parts_set_return_status.Inverter_Mode<=3)
			test_power_item[6].key_type = KEY_TYPE_ONCE;
	}
	else 
	{
		for(i=0;i<16;i++)
		{
			test_power_item[i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
		}
	}
}
void display_column_power_info_page(bool upgrage_dispaly,bool upgrade,setup_page_t *power_info_page_p,lcd_dis_item_t *power_info_item_p,char* display_buf)
{
	setup_item_info_t *power_p;
	u8 power_page_display_item_num = 0;
	u8 i =0;
	
	if(power_info_page_p->now_p==empty_son_p)
	{
		power_info_page_p->max_page_num = 0;
		return;
	}
	
	else if(power_info_page_p->now_p==power_main_page)
	{
		power_info_page_p->max_page_num = 16;
		power_page_display_item_num = 16;
	}
	else
	{
		power_page_display_item_num = 6;
		for(i=0;1;i++)
		{
			if(power_info_page_p->now_p[i].setup_menu_touch_type == END_OF_THE_LIST)
			{
				 power_info_page_p->max_page_num = i;
				 break;
			}
		}
	}
	
	if(power_info_page_p->now_p == power_main_page)
	{
		if(upgrade)
		{
			set_power_display_item_key_type(power_info_page_p);
		}
	}
	else
	{
		if(power_info_page_p->now_page_num==0)
			test_power_item[29].key_type = KEY_TYPE_TOUCH_NONE;//prepage  
		else
			test_power_item[29].key_type = KEY_TYPE_ONCE;//prepage
		
		if((power_info_page_p->now_page_num+1)*power_page_display_item_num<power_info_page_p->max_page_num)
			test_power_item[28].key_type = KEY_TYPE_ONCE;//prepage
		else
			test_power_item[28].key_type = KEY_TYPE_TOUCH_NONE;//prepage
		if(upgrade)
		{
			Virtual_LCD_Draw_Rectangle_ARGB32(25,50,690,400,Virtual_LCDbuff2,ARGB_clear);
			//Virtual_LCD_Draw_String_ARGB_24_4bit(297,80,display_buf,(0xFF78baf7),0,1,1);
		}
		for(i=0;i<power_page_display_item_num;i++)
		{
			power_p = &power_info_page_p->now_p[power_info_page_p->now_page_num*power_page_display_item_num+i];
			if((power_info_page_p->now_page_num*power_page_display_item_num+i)<(power_info_page_p->max_page_num))
			{
				if(upgrade)
				{
					if(power_p->setup_menu_touch_type==TOUCH_TYPE_NONE_DIS_DIM)
					{
						if(i==0)
							Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(test_power_item[POWER_ITEM_1_OFFSET+i].x_val+330,test_power_item[POWER_ITEM_1_OFFSET+i].y_val+Y_POWER_INFO_offset,power_info_page_p->now_p[power_info_page_p->now_page_num*power_page_display_item_num+i].display_str,(ARGB_gray),0,1,1);
						else
							Virtual_LCD_Draw_String_ARGB_24_4bit(test_power_item[POWER_ITEM_1_OFFSET+i].x_val+X_POWER_INFO_offset,test_power_item[POWER_ITEM_1_OFFSET+i].y_val+Y_POWER_INFO_offset,power_info_page_p->now_p[power_info_page_p->now_page_num*power_page_display_item_num+i].display_str,(ARGB_gray),0,1,1);
					}
					else
					{
						if(i==0)
							Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(test_power_item[POWER_ITEM_1_OFFSET+i].x_val+330,test_power_item[POWER_ITEM_1_OFFSET+i].y_val+Y_POWER_INFO_offset,power_info_page_p->now_p[power_info_page_p->now_page_num*power_page_display_item_num+i].display_str,(0xFFe2e2e4),0,1,1);
						else
							Virtual_LCD_Draw_String_ARGB_24_4bit(test_power_item[POWER_ITEM_1_OFFSET+i].x_val+X_POWER_INFO_offset,test_power_item[POWER_ITEM_1_OFFSET+i].y_val+Y_POWER_INFO_offset,power_info_page_p->now_p[power_info_page_p->now_page_num*power_page_display_item_num+i].display_str,(0xFFe2e2e4),0,1,1);
					}
				}
				switch(power_p->setup_menu_touch_type)
				{
					case TOUCH_TYPE_NORMAL://正常  
					break;
					case TOUCH_TYPE_ENTER://正常  点一下进入下一级
						test_power_item[POWER_OFFSET_ENTER_BTN+i].key_type = KEY_TYPE_ONCE;
						test_power_item[POWER_OFFSET_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					break;
					case TOUCH_TYPE_LEFT_RIGHT://显示左右选择按键 可以左右选择			   
					break;
					case TOUCH_TYPE_UP_DOWN://显示上下选择按键 可以上下选择
					break;
					case TOUCH_TYPE_SLIDE://显示滑动按键 可以滑动选择			
					break;				
					case TOUCH_TYPE_KEYBOARD://进入键盘显示，输入值				 
					break;
					case TOUCH_TYPE_NONE://显示没有触摸
					case TOUCH_TYPE_NONE_DIS_DIM:				
						test_power_item[POWER_OFFSET_ENTER_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
						test_power_item[POWER_OFFSET_BTN+i].key_type = KEY_TYPE_TOUCH_NONE;
					break;
					case TOUCH_TYPE_SPECIAL://特殊情况处理 在程序外处理
					break;
					case END_OF_THE_LIST://结束
						test_power_item[POWER_OFFSET_ENTER_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
						test_power_item[POWER_OFFSET_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					break;
					case TOUCH_TYPE_UPGRADE:
					break;
					case TOUCH_TYPE_BACKGROUND:
						//test_power_item[28].key_type = KEY_TYPE_TOUCH_NONE;
					break;
					case TOUCH_TYPE_SAVE_AND_BACK:
						test_power_item[16].key_type = KEY_TYPE_ONCE;// 
					break;
				}
				if(upgrade)
				{
					if(*power_p->f!=empty_fun)
						(*power_p->f)(power_p,i+SYSTEM_ITEM_1_OFFSET,TO_INIT);	
					//sysprintf("\r\n======================%d",i);
				}
				else
				{
					if(*power_p->f!=empty_fun)
						(*power_p->f)(power_p,i+SYSTEM_ITEM_1_OFFSET,TO_DO_NOTHING);	
				}
			}
			else
			{
				test_power_item[POWER_OFFSET_ENTER_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
				test_power_item[POWER_OFFSET_BTN+i].key_type = KEY_TYPE_TOUCH_NONE;
				//if(upgrade)
				//	Virtual_LCD_Draw_Rectangle_ARGB32(test_power_item[1+i].x_val+X_system_system_offset,setup_item_p[1+i].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
			}
		}
	}
	if(upgrage_dispaly)
	{
		//f_need_LCD_Upgrate = TRUE;
		Virtual_LCD_Upgrate();	
	}
}
void ui_column_power_info_set(bool upgrade)
{
	setup_page_t *power_info_page_p;
	lcd_dis_item_t *power_info_item_p;
	static u8 last_now_item = TOP_SIDE_ICO_NUM_5;
	
	power_info_page_p = &power_page_sta;
	power_info_item_p = test_power_item;
	
	if(last_now_item!=page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item)
	{
		last_now_item=page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item;
		
		power_info_page_p->now_p = power_main_page;
		power_info_page_p->now_page_deep = 0;
		power_info_page_p->now_page_num = 0;
		power_last_show_page_level = 0;
		power_last_show_page_num[0] = 0;
		power_last_show_page_num[1] = 0;
		set_power_display_item_key_type(power_info_page_p);
	}
	f_display_power_mes_info = FALSE;
	display_column_power_info_page(FALSE,upgrade,power_info_page_p,power_info_item_p,"");
}
void ui_detail_page_info_init_t(void)
{
	u8 i =0;
	for(i=0;i<POWER_TEST_ITEM_NUM;i++)
	{
		memcpy(&(detail_page_item[i]),p_detail_page_item_d[i],sizeof(lcd_dis_item_t));
		detail_page_item[i].pic_item =p_detail_page_item_u[i]->pic_item;//
		detail_page_item[i].size_of_pic_item = p_detail_page_item_u[i]->size_of_pic_item ;
	}
}
void ui_column_power_init_5(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][TOP_SIDE_PAGE_HOME_POWER]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_bg_5_cun_new.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_bg_5_cun_new.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
	p->item_num=POWER_TEST_ITEM_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	p->sub_page_count = 0x00; //定义好子页面数目
	p->sub_page = NULL;//
	
	p->item = test_power_item;
	for(i=0;i<POWER_TEST_ITEM_NUM;i++)
	{
		memcpy(&(p->item[i]),p_power_item_5_test_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_power_item_5_test_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_power_item_5_test_u[i]->size_of_pic_item ;
	}
	for(i=0;i<14;i++)
	{
		test_power_item[16+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	}
	ui_column_power_info_set(FALSE);
}
bool Is_rego_ver(void)
{
   if(type_sel.Inverter_Type == INVERTER_RV_C)
		 return TRUE;
	 else
		 return FALSE;
}
bool page_power_special_handle(lcd_dis_page_t *p2,u8 i,u16 x,u16 y)
{
	lcd_dis_page_t *p;
	p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
	if(((p2->now_item == TOP_SIDE_PAGE_HOME_POWER)&&(i==5))&&\
		((x>=p->item[6].x_val)&&(x<=p->item[6].x_end_val)&&(y>=p->item[6].y_val)&&(y<=p->item[6].y_end_val)))
	{
		return TRUE;
	}
	return FALSE;
}
void disply_column_power_assi1_battery_val(bool upgrade)
{
	static BATTERY_STATUS old_assi1_battery_status;   
	char display_buf[32];
	lcd_dis_item_t *p,*p2;
	u16 temp_I;
	u32 dis_color = ARGB_white;
//	 u16 x_offset =0;
//  	u8 i;
   
	if((memcmp(&assi1_battery_status,&old_assi1_battery_status,sizeof(BATTERY_STATUS)))||upgrade)//判断是否状态更新
	{
    memcpy(&old_assi1_battery_status,&assi1_battery_status,sizeof(BATTERY_STATUS));//更新状态
		p=&t_Battery_bg_off_5_new;
		//清空字符
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		
		if(assi1_battery_status.I)
			p2=&t_Battery_bg_on_5_new;
		else
			p2=&t_Battery_bg_off_5_new;
		png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		
		//power
		if(assi1_battery_status.I&0x8000)
		{
		  sprintf(display_buf,"-%d W",(assi1_battery_status.V*(assi1_battery_status.I&0x7FFF))/100);
			Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,333,display_buf,ARGB_white,0,1,1);
      //Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y-10,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(assi1_battery_status.I!=0)
		{
		  sprintf(display_buf,"%d W",(assi1_battery_status.V*(assi1_battery_status.I&0x7FFF))/100);
      Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,333,display_buf,ARGB_white,0,1,1);
			//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y-10,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,333,display_buf,ARGB_mygray,0,1,1);
			//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y-10,display_buf,ARGB_mygray,0,1,1);
		}
		//vol
		if(assi1_battery_status.V==0)
		{
			sprintf(display_buf,"--"); 
			Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,288,display_buf,ARGB_mygray,0,1,1);
		}
		else
		{
			sprintf(display_buf,"%d.%d V",assi1_battery_status.V/10,assi1_battery_status.V%10); 
			Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,288,display_buf,ARGB_white,0,1,1);
		}
		
		//cur
		if(assi1_battery_status.I==0)
		{
			sprintf(display_buf,"--"); 
			Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,310,display_buf,ARGB_mygray,0,1,1);
		}
		else
		{
			if((assi1_battery_status.I&0x8000))
			{
				temp_I =  assi1_battery_status.I&0x7FFF;
				sprintf(display_buf,"-%d.%d A",temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,310,display_buf,ARGB_white,0,1,1);
			}
			else// if(assi1_battery_status.I!=0)
			{
				temp_I =  assi1_battery_status.I;
				sprintf(display_buf,"%d.%d A",temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,310,display_buf,ARGB_white,0,1,1);
			}
		}
		
		//temperature
		if((base_return_status.uint&0x0C)==0x04)//F
		{
			if(assi1_battery_status.MAX_temp==0xFF)
			{
				sprintf(display_buf,"--");
			}
			else if(assi1_battery_status.MAX_temp>=80)
				sprintf(display_buf,"%d  F",assi1_battery_status.MAX_temp-80);
			else
				sprintf(display_buf,"-%d  F",80-assi1_battery_status.MAX_temp);
		}
		else
		{
			if(assi1_battery_status.MAX_temp==0xFF)
			{
				sprintf(display_buf,"--");
			}
			else if(assi1_battery_status.MAX_temp>=80)
				sprintf(display_buf,"%d   C",assi1_battery_status.MAX_temp-80);
			else
				sprintf(display_buf,"-%d   C",80-assi1_battery_status.MAX_temp);
		}
		if(assi1_battery_status.MAX_temp==0xFF)
		{
		  Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,260,display_buf,ARGB_white,0,1,1);
			//Virtual_LCD_Draw_String_o(get_str_align_center_x_val(p->x_val+CHANGER_CENTER_OFFSET_X,display_buf,glyph_dsc_16_4bit),p->y_val+80,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_16_4bit,(ARGB_white),0,1,1);
		}
		else
		{
      Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,260,display_buf,ARGB_white,0,1,1);
			Virtual_LCD_Draw_String_o(get_str_align_center_x_val(455,display_buf,glyph_dsc_16_4bit),260,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_16_4bit,(ARGB_white),0,1,1);
		}
		
		if(assi1_battery_status.f_time_changer)
		{
			if(assi1_battery_status.time==0xFFFF)
			{
		    sprintf(display_buf,"Charging:   --d --h");	 
				dis_color = ARGB_white;
			}
			else if(assi1_battery_status.time==0xFFFE)
			{
				if(type_sel.Battery_SmartShun_Type==BATTERY_LINKS2_KL500A)
				{
					sprintf(display_buf,"No Capacity Set");	
					dis_color = ARGB_yellow;
				}
				else
				{
					sprintf(display_buf,"Charging:   --d --h");	 
					dis_color = ARGB_white;
				}
			}	
		  else if(assi1_battery_status.time>=1440)
			{
				sprintf(display_buf,"Charging:   %dd %dh",assi1_battery_status.time/1440,(assi1_battery_status.time%1440)/60);
				dis_color = ARGB_white;
			}
			else if(assi1_battery_status.time==0)
			{
			  sprintf(display_buf,"Battery fully charged");
				dis_color = ARGB_white;
			}
			else
			{
				sprintf(display_buf,"Charging:   %dh %dm",(assi1_battery_status.time%1440)/60,(assi1_battery_status.time%1440)%60);
				dis_color = ARGB_white;
			}
			Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,357,display_buf,dis_color,0,1,1);
			//Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,465,display_buf,dis_color,0,1,1);
		}
		else
		{
		  if(assi1_battery_status.time==0xFFFF)
			{
				sprintf(display_buf,"Discharging:  --d --h");	
				dis_color = ARGB_white;					
			}
			else if(assi1_battery_status.time==0xFFFE)
			{
				if(type_sel.Battery_SmartShun_Type==BATTERY_LINKS2_KL500A)
				{
					sprintf(display_buf,"No Capacity Set");	
					dis_color = ARGB_yellow;
				}
				else
				{
					sprintf(display_buf,"Discharging:  --d --h");	
					dis_color = ARGB_white;		
				}
			}	
		  else if(assi1_battery_status.time>=1440)
			{
				sprintf(display_buf,"Discharging:  %dd %dh",assi1_battery_status.time/1440,(assi1_battery_status.time%1440)/60);
				dis_color = ARGB_white;
			}
			else
			{
				sprintf(display_buf,"Discharging:  %dh %dm",(assi1_battery_status.time%1440)/60,(assi1_battery_status.time%1440)%60);
				dis_color = ARGB_white;
			}
			Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,478,357,display_buf,dis_color,0,1,1);
			//Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,465,display_buf,dis_color,0,1,1);
		}
		//ch = (u8)ch;
		
		
		
		//Virtual_LCD_Draw_Rectangle_ARGB32(281,422,32*6,32,Virtual_LCDbuff2,ARGB_clear);
		if(assi1_battery_status.Q>=100)
		{
			sprintf(display_buf,"100%%");
			/*display_buf[3] = '%';
			display_buf[4] = ' ';
			display_buf[5] = ' ';
			display_buf[6] = '\0';*/
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(365,285,display_buf,(0xFF51FA75),0,1,1);
			//Virtual_LCD_Draw_String_ARGB_32_4bit_bold(281,422,display_buf,ARGB_white,0,1,1);
		}
		else
		{
			sprintf(display_buf,"%2d%%",assi1_battery_status.Q);
			/*display_buf[2] = '%';
			display_buf[3] = ' ';
			display_buf[4] = ' ';
			display_buf[5] = '\0';*/
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(365,285,display_buf,(0xFF51FA75),0,1,1);
			//Virtual_LCD_Draw_String_ARGB_32_4bit_bold(281,422,display_buf,ARGB_white,0,1,1);
		}
		
		p=&t_Battery_icon_val_0_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		if(assi1_battery_status.f_time_changer)
		{
			if(assi1_battery_status.Q<=5)
				p=&t_Battery_icon_val_0_new;
			else if(assi1_battery_status.Q<=25)
				p=&t_Battery_icon_val_25_new;
			else if(assi1_battery_status.Q<=50)
				p=&t_Battery_icon_val_50_new;
			else if(assi1_battery_status.Q<90)
				p=&t_Battery_icon_val_75_new;
			else// if(assi1_battery_status.Q<=95)
				p=&t_Battery_icon_val_100_new;
			//else 
			// p=&t_power_battery_changer_5;
		}
		else
		{
			if(assi1_battery_status.Q<=5)
				p=&t_Battery_icon_val_0_new;
			else if(assi1_battery_status.Q<=25)
				p=&t_Battery_icon_val_25_new;
			else if(assi1_battery_status.Q<=50)
				p=&t_Battery_icon_val_50_new;
			else if(assi1_battery_status.Q<90)
				p=&t_Battery_icon_val_75_new;
			else //if(assi1_battery_status.Q<=95)
				p=&t_Battery_icon_val_100_new;
			//else 
				// p=&t_power_battery_5;
		}
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		if(Is_Inverter_mode_Inverting())
			p=&t_Batt_to_inverter_line_on_new;
		else
			p=&t_Batt_to_inverter_line_off_new;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff1,ARGB_clear);
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
		
		p=&t_Battery_bg_on_5_new;
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
		//Virtual_LCD_Upgrate();
	}
}
void disply_column_power_Inverter_mes(bool upgrade)
{
	static INVERTER_STATUS old_Inverter_status;  
	static u8 old_Inverter_Mode; 
	char display_buf[32];
	lcd_dis_item_t *p;
	u16 temp_I;
	u32 temp_pow;
	
	//if(upgrade == FALSE)
	//{
	//	if((Inverter_status.mode != 0x00)&&(Inverter_status.mode != 0x01)&&(Inverter_status.mode != 0x02)&&(Inverter_status.mode != 0x03))
	//	{
	//		t_inverter_icon_down_5_new.key_type = KEY_TYPE_TOUCH_NONE;
	//		t_inverter_icon_up_5_new.key_type  = KEY_TYPE_TOUCH_NONE;
	//	}
	//	else
	//	{
	//		t_inverter_icon_down_5_new.key_type = KEY_TYPE_ONCE;
	//		t_inverter_icon_up_5_new.key_type  = KEY_TYPE_ONCE;
	//	}
	//}
	if((memcmp(&Inverter_status,&old_Inverter_status,sizeof(INVERTER_STATUS)))||(old_Inverter_Mode !=parts_set_return_status.Inverter_Mode)||upgrade)
  {
		memcpy(&old_Inverter_status,&Inverter_status,sizeof(INVERTER_STATUS));
		old_Inverter_Mode = parts_set_return_status.Inverter_Mode;
		
		if(Is_Inverter_mode_Inverting()||Is_Inverter_mode_AC_IN())
			p=&t_Inverter_bg_on_5_new;
		else
			p=&t_Inverter_bg_off_5_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		switch(Inverter_status.mode)
		{
		  case 0:
				sprintf(display_buf,"Auxiliary");
				break;
		  case 1:
				sprintf(display_buf,"Standby");
				break;
			case 2:
				sprintf(display_buf,"Fault");
				break;
			case 3:
				sprintf(display_buf,"ShutDown");
				break;
			case 4:
				sprintf(display_buf,"Inverting");
				break;
			case 5:
				sprintf(display_buf,"Normal");
				break;
			case 6:
				sprintf(display_buf,"NoBattery");
				break;
			case 7:
				sprintf(display_buf,"Discharge");
				break;
			case 8:
				sprintf(display_buf,"Mains power");
				break;
			case 9:
				sprintf(display_buf,"PowOff");
				break;
			case 0x10:
				sprintf(display_buf,"Bypass");
				break;
			case 0x11:
				sprintf(display_buf,"Inverting");
				break;
			case 0x12:
				sprintf(display_buf,"Charging");
				break;
			case 0x13:
				sprintf(display_buf,"ParallelDischarge");
				break;
			case 0x14:
				sprintf(display_buf,"GridDischarge");
				break;
			case 0x15:
				sprintf(display_buf,"MicroGridDischarge");
				break;
			case 0x20:
				sprintf(display_buf,"Down");
				break;
			case 0x21:
				sprintf(display_buf,"Startup");
				break;
			case 0x22:
				sprintf(display_buf,"Off");
				break;
			case 0x23:
				sprintf(display_buf,"Slave Mode");
				break;
      case 0x24:
				sprintf(display_buf,"Inverting");//Invert Full
				break;
      case 0x25:
				sprintf(display_buf,"Invert Half");
				break;
      case 0x26:
				sprintf(display_buf,"Invert AES");
				break;
      case 0x27:
				sprintf(display_buf,"Power Assist");
				break;
      case 0x28:
				sprintf(display_buf,"Bypass");
				break;
      case 0x29:
				sprintf(display_buf,"Charge");
				break;
			case 0x30:
				sprintf(display_buf,"Initializing");
				break;
			case 0x31:
				sprintf(display_buf,"Bulk");
				break;
			case 0x32:
				sprintf(display_buf,"Absorption");
				break;
			case 0x33:
				sprintf(display_buf,"Float");
				break;
			case 0x34:
				sprintf(display_buf,"Storage");
				break;
			case 0x35:
				sprintf(display_buf,"Repeated Absorption");
				break;
			case 0x36:
				sprintf(display_buf,"Forced Absorption");
				break;
			case 0x37:
				sprintf(display_buf,"Equalise");
				break;
			case 0x38:
				sprintf(display_buf,"Bulk stopped");
				break;
			default:
				sprintf(display_buf,"Unkown");
				break;
		}
    Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(402,87,display_buf,ARGB_mydarkcyan,0,1,1);
	  
		
		p=&t_inverter_icon_up_5_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		switch(parts_set_return_status.Inverter_Mode)
		{
		  //case 0:
			//	sprintf(display_buf,"        OFF");
			//	break;
		  case 1:
				//test_power_item[6].key_type = KEY_TYPE_ONCE;
				sprintf(display_buf,"Charger Only");
				break;
			case 2:
				//test_power_item[6].key_type = KEY_TYPE_ONCE;
				sprintf(display_buf,"Inverter Only");
				break;
			case 3:
				//test_power_item[6].key_type = KEY_TYPE_ONCE;
				if(Is_rego_ver())
					sprintf(display_buf,"Output ON");
				else
					sprintf(display_buf,"ON");
				break;			
			case 0:
				//test_power_item[6].key_type = KEY_TYPE_ONCE;
				if(Is_rego_ver())
					sprintf(display_buf,"Output OFF");
				else
					sprintf(display_buf,"OFF");
				break;
			default:
			{
				sprintf(display_buf,"No Connect");
				//test_power_item[6].key_type = KEY_TYPE_TOUCH_NONE;
			}
			break;
		}
		if(parts_set_return_status.Inverter_Mode<=3)
		{
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(403,124,display_buf,ARGB_white,0,1,1);
			test_power_item[6].key_type = KEY_TYPE_ONCE;
			//power_item[ICO_power_inverter_offset].last_status = STATUS_IDLE;
			//power_item[ICO_power_inverter_offset].now_status = STATUS_IDLE;
		}
		else
		{
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(403,124,display_buf,ARGB_white,0,1,1);
			test_power_item[6].key_type = KEY_TYPE_TOUCH_NONE;
			//power_item[ICO_power_inverter_offset].last_status = STATUS_IDLE;
			test_power_item[6].now_status = STATUS_IDLE;
		}
		
		if((Inverter_status.V_dc==0)&&(Inverter_status.I_dc==0))
	  {
			sprintf(display_buf,"--  --"); 
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(402,174,display_buf,ARGB_mygray,0,1,1);
	  }
	  else
	  {
			if((Inverter_status.I_dc&0x8000))
			{
				temp_I =  Inverter_status.I_dc&0x7FFF;
				sprintf(display_buf,"%d.%dV  -%d.%dA",Inverter_status.V_dc/10,Inverter_status.V_dc%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(402,174,display_buf,ARGB_white,0,1,1);
			}
			else
			{
				temp_I =  Inverter_status.I_dc;
				sprintf(display_buf,"%d.%dV  %d.%dA",Inverter_status.V_dc/10,Inverter_status.V_dc%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(402,174,display_buf,ARGB_white,0,1,1);
			}
		}
		temp_pow = Inverter_status.P_dc;
		if(temp_pow&0x8000)
		{
		  sprintf(display_buf,"-%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(402,155,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(temp_pow!=0)
		{
		  sprintf(display_buf,"%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(402,155,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(402,155,display_buf,ARGB_mygray,0,1,1);
		}
		if((Is_Inverter_mode_AC_IN()))
			p=&t_Inverter_to_batt_line_on_new;
		else
			p=&t_Inverter_to_batt_line_off_new;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff1,ARGB_clear);
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
		
		p=&t_Inverter_bg_on_5_new;
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
}
void disply_column_power_bootster_charger_val_5(bool upgrade)
{
	static CHARGER_STATUS old_Booster_Charger;   
	char display_buf[32];
	lcd_dis_item_t *p,*p2;
	u16 temp_I;

  if((memcmp(&Booster_Charger,&old_Booster_Charger,sizeof(CHARGER_STATUS)))||upgrade) 
  {
		memcpy(&old_Booster_Charger,&Booster_Charger,sizeof(CHARGER_STATUS));
		
		p=&t_DC_charger_bg_off_5_new;//#define X_power_bc_bg  581 #define Y_power_bc_bg  366
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		
		//Virtual_LCD_Draw_String_ARGB_24_4bit(100,317,"Generator",ARGB_white,0,1,1);
			
		if(Booster_Charger.Power&0x8000)
		{
		  sprintf(display_buf,"-%d W",Booster_Charger.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(Booster_Charger.Power)
		{
		  sprintf(display_buf,"%d W",Booster_Charger.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mygray,0,1,1);
		}
	
		if((Booster_Charger.V_in==0)&&(Booster_Charger.I_in==0))
		{
			sprintf(display_buf,"--  --"); 
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_mygray,0,1,1);
		}
		else
		{
			if((Booster_Charger.I_in&0x8000))
			{
				temp_I =  Booster_Charger.I_in&0x7FFF;
				sprintf(display_buf,"%d.%dV  -%d.%dA",Booster_Charger.V_in/10,Booster_Charger.V_in%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_white,0,1,1);
			}
			else// if(assi1_battery_status.I!=0)
			{
				temp_I =  Booster_Charger.I_in;
				sprintf(display_buf,"%d.%dV  %d.%dA",Booster_Charger.V_in/10,Booster_Charger.V_in%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_white,0,1,1);
			}
		}
		if(Booster_Charger.I_in)
			p2=&t_DC_charger_line_on_new;
		else
			p2=&t_DC_charger_line_off_new;
		Virtual_LCD_Draw_Rectangle_ARGB32(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val,Virtual_LCDbuff1,ARGB_clear);
		png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val);
		
		if(Booster_Charger.I_in)
			p2=&t_DC_charger_bg_on_5_new;
		else
			p2=&t_DC_charger_bg_off_5_new;
		png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val);
	}
}
void disply_column_power_solar_charger_val_5(bool upgrade)
{
	static SOLAR_STATUS old_solar_status;   
	char display_buf[32];
	lcd_dis_item_t *p,*p2;
	u16 temp_I;

  if((memcmp(&solar_status,&old_solar_status,sizeof(SOLAR_STATUS)))||upgrade)
  {
    memcpy(&old_solar_status,&solar_status,sizeof(SOLAR_STATUS));
		
		p=&t_Solar_charger_bg_off_5_new;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		
		//Virtual_LCD_Draw_String_ARGB_24_4bit(96,199,"Solar",ARGB_white,0,1,1);
		if(solar_status.Power&0x8000)
		{
		  sprintf(display_buf,"-%d W",solar_status.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mydarkcyan,0,1,1);
			//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(solar_status.Power)
		{
		  sprintf(display_buf,"%d W",solar_status.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mydarkcyan,0,1,1);
			//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mygray,0,1,1);
			//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mygray,0,1,1);
		}
		if((solar_status.V_in==0)&&(solar_status.I_in==0))
		{
			sprintf(display_buf,"--  --"); 
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_mygray,0,1,1);
		}
		else
		{
			if((solar_status.I_in&0x8000))
			{
				temp_I =  solar_status.I_in&0x7FFF;
				sprintf(display_buf,"%d.%dV  -%d.%dA",solar_status.V_in/10,solar_status.V_in%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_white,0,1,1);
			}
			else// if(assi1_battery_status.I!=0)
			{
				temp_I =  solar_status.I_in;
				sprintf(display_buf,"%d.%dV  %d.%dA",solar_status.V_in/10,solar_status.V_in%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_white,0,1,1);
			}
		}
		if(solar_status.I_in)
			p2=&t_Solar_charger_line_on_new;
		else
			p2=&t_Solar_charger_line_off_new;
		Virtual_LCD_Draw_Rectangle_ARGB32(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val,Virtual_LCDbuff1,ARGB_clear);
		png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val);
		
		if(solar_status.I_in)
			p2=&t_Solar_charger_bg_on_5_new;
		else
			p2=&t_Solar_charger_bg_off_5_new;
		png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val);
	}
}
void disply_column_power_combi_chg_5(bool upgrade)
{
	static INVERTER_STATUS old_Inverter_status;   
	char display_buf[32];
	lcd_dis_item_t *p,*p2;
	u16 temp_I;
	
  if((memcmp(&Inverter_status,&old_Inverter_status,sizeof(INVERTER_STATUS)))||upgrade)
  {
    memcpy(&old_Inverter_status,&Inverter_status,sizeof(INVERTER_STATUS));
		
		
		p=&t_AC_input_bg_off_5_new;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		if(Inverter_status.P_220&0x8000)
		{
		  sprintf(display_buf,"-%d W",Inverter_status.P_220&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(Inverter_status.P_220)
		{
		  sprintf(display_buf,"%d W",Inverter_status.P_220&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mygray,0,1,1);
		}
		
		if((Inverter_status.V_220==0)&&(Inverter_status.I_220==0))
		{
			sprintf(display_buf,"--  --"); 
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_mygray,0,1,1);
		}
		else
		{
			if((Inverter_status.I_220&0x8000))
			{
				temp_I =  Inverter_status.I_220&0x7FFF;
				sprintf(display_buf,"%d.%dV  -%d.%dA",Inverter_status.V_220/10,Inverter_status.V_220%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_white,0,1,1);
			}
			else// if(assi1_battery_status.I!=0)
			{
				temp_I =  Inverter_status.I_220;
				sprintf(display_buf,"%d.%dV  %d.%dA",Inverter_status.V_220/10,Inverter_status.V_220%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_white,0,1,1);
			}
		}
		if(Inverter_status.I_220)
			p2=&t_AC_charger_line_on_new;
		else
			p2=&t_AC_charger_line_off_new;
		Virtual_LCD_Draw_Rectangle_ARGB32(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val,Virtual_LCDbuff1,ARGB_clear);
		png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val);
		
		if(Inverter_status.I_220)
			p2=&t_AC_input_bg_on_5_new;
		else
			p2=&t_AC_input_bg_off_5_new;
		png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p2->x_val,p2->y_val,p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val);

	}
}

void disply_column_power_dc_loads_val_5(bool upgrade)
{
//	static u16 old_V,old_I,old_P; 
	char display_buf[32];
	lcd_dis_item_t *p;
	u16 temp_I=0;
	u32 temp_pow;
//	 u16 x_220ffset = 0;
	u16 I_dcload=0;
  static u16 old_Booster_Charger_I_batt=0;
	static u16 old_solar_status_I_batt=0;
	static u16 old_assi1_battery_status_I	=0;
	static u16 old_Inverter_status_I_dc=0;
  static u16 old_assi1_battery_status_V=0;
	
	
	if((old_Booster_Charger_I_batt != Booster_Charger.I_batt)||\
	 (old_solar_status_I_batt != solar_status.I_batt)||\
	 (old_assi1_battery_status_I != assi1_battery_status.I)||\
	 (old_Inverter_status_I_dc != Inverter_status.I_dc)||\
	 (old_assi1_battery_status_V != assi1_battery_status.V)||upgrade)
  {
		
	  old_Booster_Charger_I_batt = Booster_Charger.I_batt;
		old_solar_status_I_batt = solar_status.I_batt;
		old_assi1_battery_status_I = assi1_battery_status.I;
		old_Inverter_status_I_dc = Inverter_status.I_dc;
		old_assi1_battery_status_V = assi1_battery_status.V;
		
		I_dcload = (Booster_Charger.I_batt&0x7FFF) + (solar_status.I_batt&0x7FFF);
		//sysprintf("\r\n Booster_Charger.I_batt = %d\r\n solar_status.I_batt = %d \r\n  Inverter_status.I_dc=%d \r\n  assi1_battery_status.I = %d \r\n",Booster_Charger.I_batt,solar_status.I_batt,Inverter_status.I_dc,assi1_battery_status.I);
		if(Inverter_status.I_dc&0x8000)//-放电
		{
			if(I_dcload>=(Inverter_status.I_dc&0x7FFF))
				I_dcload = I_dcload - (Inverter_status.I_dc&0x7FFF);
			else
				I_dcload = ((Inverter_status.I_dc&0x7FFF) - I_dcload)|0x8000;
		}
		else
			I_dcload = I_dcload+Inverter_status.I_dc;
		
	/*if(Inverter_status.I_dc&0x8000)
		{
			if(I_dcload>=(Inverter_status.I_dc&0x7FFF))
				I_dcload = I_dcload - (Inverter_status.I_dc&0x7FFF);
			else
				I_dcload = ((Inverter_status.I_dc&0x7FFF) - I_dcload)|0x8000;
		}
		else
			I_dcload = I_dcload+Inverter_status.I_dc;*/
		
		if((assi1_battery_status.I&0x8000)&&(I_dcload&0x8000))//放电X2
		{
			if((I_dcload&0x7FFF)>=(assi1_battery_status.I&0x7FFF))
				I_dcload = 0;	
			else
				I_dcload =  (assi1_battery_status.I&0x7FFF);//-(I_dcload&0x7FFF); //符号为正了
		}
		else if(((assi1_battery_status.I&0x8000)==0)&&((I_dcload&0x8000)==0)) //都在充电
		{
			if(I_dcload>=(assi1_battery_status.I))
	     	I_dcload = I_dcload-assi1_battery_status.I ;
			else	
				I_dcload = 0; 
		}
		else if(((assi1_battery_status.I&0x8000))&&((I_dcload&0x8000)==0))//电池放电 其他在充电
		{
			I_dcload = (I_dcload&0x7FFF)+ (assi1_battery_status.I&0x7FFF);
		}	
		else if(((assi1_battery_status.I&0x8000)==0)&&((I_dcload&0x8000)))//电池在充电，其他在放电 不存在
		{
			I_dcload = 0;			  
		}		
		
		if(I_dcload&0x8000)
			I_dcload = 0;
	
		if(I_dcload)
			p=&t_DC_Loads_bg_on_5_new;
		else
			p=&t_DC_Loads_bg_off_5_new;	
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		
		p=&t_DC_Loads_bg_on_5_new;

		if((assi1_battery_status.V==0)&&(I_dcload==0))
		{
			temp_I = 0;
			sprintf(display_buf,"--  --"); 
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_mygray,0,1,1);
		}
		else
		{
			if((I_dcload&0x8000))
			{
				temp_I =  I_dcload&0x7FFF;
				sprintf(display_buf,"%d.%dV  -%d.%dA",assi1_battery_status.V/10,assi1_battery_status.V%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_white,0,1,1);
			}
			else// if(assi1_battery_status.I!=0)
			{
				temp_I =  I_dcload;
				sprintf(display_buf,"%d.%dV  %d.%dA",assi1_battery_status.V/10,assi1_battery_status.V%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR,display_buf,ARGB_white,0,1,1);
			}
		}
		if(I_dcload)
		{
			p=&t_DC_loads_line_on_new;
		}
		else
		{
			p=&t_DC_loads_line_off_new;
		}
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff1,ARGB_clear);
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_end_val,p->y_end_val-p->y_val);
		
		p=&t_DC_Loads_bg_on_5_new;
		temp_pow = assi1_battery_status.V*temp_I/100;
		if(temp_pow>0xFFFF)
			temp_pow = 0xFFFF;
		
		if((I_dcload&0x8000))
			temp_pow|=0x8000;
		
		if(temp_pow&0x8000)
		{
		  sprintf(display_buf,"-%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(temp_pow!=0)
		{
		  sprintf(display_buf,"%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL,display_buf,ARGB_mygray,0,1,1);
		}
		
		//Virtual_LCD_Draw_String_ARGB_16_4bit(236,181,"--W",ARGB_mygray,0,1,1);
				
		p=&t_DC_Loads_bg_on_5_new;
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(492,p->y_val,p->x_end_val-492,p->y_end_val-p->y_val);
	}
}
void disply_column_power_ac_loads_val_5(bool upgrade)
{
	static u16 old_V,old_I,old_P; 
	char display_buf[32];
	lcd_dis_item_t *p;
	u16 temp_I;
	u32 temp_pow;
//	 u16 x_offset = 0;
	
  if((old_V!=Inverter_status.V_o)||(old_I!=Inverter_status.I_o)||(old_P!=Inverter_status.P_o)||upgrade)
  {
		old_V=Inverter_status.V_o;
		old_I=Inverter_status.I_o;
		old_P=Inverter_status.P_o;
		
		if(Inverter_status.I_o)
			p=&t_AC_Loads_bg_on_5_new;
		else
			p=&t_AC_Loads_bg_off_5_new;	
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		
		if(Is_Inverter_mode_AC_IN())
		{			
		  sprintf(display_buf,"(Grid)"); //Virtual_LCD_Draw_String_ARGB_24_4bit_bold(175,215,"(grid)",ARGB_gray,0,1,1);
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL-15,display_buf,ARGB_gray,0,1,1);
		}
		else if((Is_Inverter_mode_Inverting())||(Inverter_status.mode==0x27))//0x27:Power Assist
		{
	    sprintf(display_buf,"(Inverter)"); //Virtual_LCD_Draw_String_ARGB_24_4bit_bold(175,215,"(inverter)",ARGB_gray,0,1,1);			
		  Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL-15,display_buf,ARGB_gray,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"(--)"); //Virtual_LCD_Draw_String_ARGB_24_4bit_bold(175,215,"(inverter)",ARGB_gray,0,1,1);
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL-15,display_buf,ARGB_mygray,0,1,1);
		}
		
		//Virtual_LCD_Draw_String_ARGB_24_4bit_bold(350,90,"Inverter Status",ARGB_gray,0,1,1); 
		
		
		
		p=&t_AC_Loads_bg_on_5_new;
    
		if((Inverter_status.V_o==0)&&(Inverter_status.I_o==0))
		{
	     sprintf(display_buf,"--  --"); 
	     Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR+8,display_buf,ARGB_mygray,0,1,1);
		}
		else
		{
			if((Inverter_status.I_o&0x8000))
			{
				temp_I =  Inverter_status.I_o&0x7FFF;
				sprintf(display_buf,"%d.%dV  -%d.%dA",Inverter_status.V_o/10,Inverter_status.V_o%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR+8,display_buf,ARGB_white,0,1,1);
			}
			else// if(assi1_battery_status.I!=0)
			{
				temp_I =  Inverter_status.I_o;
				sprintf(display_buf,"%d.%dV  %d.%dA",Inverter_status.V_o/10,Inverter_status.V_o%10,temp_I/10,temp_I%10);
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL_VOL_CUR+8,display_buf,ARGB_white,0,1,1);
			}
		}		
		p=&t_AC_Loads_bg_off_5_new;	
		temp_pow = Inverter_status.P_o;
		if(temp_pow&0x8000)
		{			
		  sprintf(display_buf,"-%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL+8,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(temp_pow!=0)
		{			
		  sprintf(display_buf,"%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL+8,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+X_POWER_OFFSET_VAL,p->y_val+Y_POWER_OFFSET_VAL+8,display_buf,ARGB_mygray,0,1,1);
		}

		p=&t_AC_Loads_bg_off_5_new;
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
		
	  if(Inverter_status.I_o)
			p=&t_AC_loads_line_on_new;
		else
			p=&t_AC_loads_line_off_new;
		 Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff1,ARGB_clear);
		 png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
}
