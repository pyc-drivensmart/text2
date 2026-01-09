#include "includes.h"


extern void func_top_fault(void* p,u8 sn);
extern lcd_dis_item_t t_top_fault;

#define HOME_5_CHUN_ITME_NUM 20
#define HOME_5_CHUN_INTELLIGENT_ITEM_NUM 4
#define TOP_5_CUN_ITEM_NUM 2
lcd_dis_item_t *p_top_item_5_cun_u[TOP_5_CUN_ITEM_NUM]={
//	&t_top_fault,
//	&t_top_turn_off_screen_icon_new,
    &t_warn_no,//灰色警告
    &t_off_up,
};
lcd_dis_item_t *p_top_item_5_cun_d[TOP_5_CUN_ITEM_NUM]={
    
//	&t_top_fault//灰色警告
//	&t_top_turn_off_screen_icon_new,//息屏
    
        &t_warn_no,
    &t_off_up,

};
lcd_dis_item_t *p_home_item_5_chun_u[HOME_5_CHUN_ITME_NUM]={
	&t_home_batt_bg_blue_5_new,
	&t_home_batt_bg_black_5_new,
	&t_home_batt_info_column_5_new,
	//&t_home_batt_soc_5,
	&t_home_bg_ac_up_5_new,
	&t_home_bg_dc_up_5_new,
	&t_home_bg_sc_up_5_new,
	
	&t_home_page_back,
	&t_home_page_enter_up_2,
	&t_home_page_enter_up_3,
	&t_home_page_enter_up_4,
	&t_home_page_enter_up_5,
	&t_home_page_enter_up_6,
	&t_home_page_back,
	&t_home_page_info_2,
	&t_home_page_info_3,
	&t_home_page_info_4,
	&t_home_page_info_5,
	&t_home_page_info_6,
	&t_home_page_next_up_new,
	&t_home_page_pre_up_new,
};
lcd_dis_item_t *p_home_item_5_chun_d[HOME_5_CHUN_ITME_NUM]={
	&t_home_batt_bg_blue_5_new,
	&t_home_batt_bg_black_5_new,
	&t_home_batt_info_column_5_new,
	//&t_home_batt_soc_5,
	&t_home_bg_ac_down_5_new,
	&t_home_bg_dc_down_5_new,
	&t_home_bg_sc_down_5_new,
	
	&t_home_page_back_down,
	&t_home_page_enter_down_2,
	&t_home_page_enter_down_3,
	&t_home_page_enter_down_4,
	&t_home_page_enter_down_5,
	&t_home_page_enter_down_6,
	&t_home_page_back_down,
	&t_home_page_info_2,
	&t_home_page_info_3,
	&t_home_page_info_4,
	&t_home_page_info_5,
	&t_home_page_info_6,
	&t_home_page_next_down_new,
	&t_home_page_pre_down_new,
};						 

setup_item_info_t home_batt_alarm[]=
{
	{"Battery_Info->Alarm",TOUCH_TYPE_SAVE_AND_BACK,home_batt_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_batt_history_info[]=
{
	{"Battery_Info->Histroy",TOUCH_TYPE_SAVE_AND_BACK,home_batt_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_batt_device_info[]=
{
	{"Battery_Info->Device",TOUCH_TYPE_SAVE_AND_BACK,home_batt_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_batt_page_info[]=
{
	{"Battery_Info",TOUCH_TYPE_SAVE_AND_BACK,home_main_page,empty_son_p,empty_fun},
	{"Battery",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"State of charge",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Consumed AmpHours",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Timer",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Alarm",TOUCH_TYPE_ENTER,home_main_page,home_batt_alarm,empty_fun},
	{"Battery_Info",TOUCH_TYPE_SAVE_AND_BACK,home_main_page,empty_son_p,empty_fun},
	{"History",TOUCH_TYPE_ENTER,home_main_page,home_batt_history_info,empty_fun},
	{"Device",TOUCH_TYPE_ENTER,home_main_page,home_batt_device_info,empty_fun},
	//{"Device",TOUCH_TYPE_BACKGROUND,power_main_page,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t home_inv_advance[]=
{
	{"Inverter_Info->Advanced",TOUCH_TYPE_SAVE_AND_BACK,home_inv_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_inv_alarm_status[]=
{
	{"Inverter_Info->Alarm_status",TOUCH_TYPE_SAVE_AND_BACK,home_inv_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_inv_alarm_setup[]=
{
	{"Inverter_Info->Alarm_setup",TOUCH_TYPE_SAVE_AND_BACK,home_inv_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_inv_device[]=
{
	{"Inverter_Info->Device",TOUCH_TYPE_SAVE_AND_BACK,home_inv_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_inv_page_info[]=
{
	{"Inverter_Info",TOUCH_TYPE_SAVE_AND_BACK,home_main_page,empty_son_p,empty_fun},
	{"Grid current limit",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"DC Voltage",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"DC Current",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"State of charge",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Active AC Input",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Inverter_Info",TOUCH_TYPE_SAVE_AND_BACK,home_main_page,empty_son_p,empty_fun},
	{"Advanced",TOUCH_TYPE_ENTER,home_main_page,home_inv_advance,empty_fun},
	{"Alarm status",TOUCH_TYPE_ENTER,home_main_page,home_inv_alarm_status,empty_fun},
	{"Alarm setup",TOUCH_TYPE_ENTER,home_main_page,home_inv_alarm_setup,empty_fun},
	{"Device",TOUCH_TYPE_ENTER,home_main_page,home_inv_device,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t home_solar_history[]=
{
	{"Solar_Info->History",TOUCH_TYPE_SAVE_AND_BACK,home_solar_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_solar_network[]=
{
	{"Solar_Info->Network",TOUCH_TYPE_SAVE_AND_BACK,home_solar_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_solar_device[]=
{
	{"Solar_Info->Device",TOUCH_TYPE_SAVE_AND_BACK,home_solar_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_solar_page_info[]=
{
	{"Solar_Info",TOUCH_TYPE_SAVE_AND_BACK,home_main_page,empty_son_p,empty_fun},
	{"Pv info",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Pv state",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Yield Today",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Battery",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Load",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Solar_Info",TOUCH_TYPE_SAVE_AND_BACK,home_main_page,empty_son_p,empty_fun},
	{"Alarm & Errors",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"History",TOUCH_TYPE_ENTER,home_main_page,home_solar_history,empty_fun},
	{"Networked operation",TOUCH_TYPE_ENTER,home_main_page,home_solar_network,empty_fun},
	{"Device",TOUCH_TYPE_ENTER,home_main_page,home_solar_device,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t home_dcdc_overall_history[]=
{
	{"DcDc_info->Overall_history",TOUCH_TYPE_SAVE_AND_BACK,home_dcdc_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_dcdc_cycle_history[]=
{
	{"DcDc_info->Cycle_history",TOUCH_TYPE_SAVE_AND_BACK,home_dcdc_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_dcdc_device[]=
{
	{"DcDc_info->Device",TOUCH_TYPE_SAVE_AND_BACK,home_dcdc_page_info,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_dcdc_page_info[]=
{
	{"DcDc_info",TOUCH_TYPE_SAVE_AND_BACK,home_main_page,empty_son_p,empty_fun},
	{"Input",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Output",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"State",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Network status",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"Error",TOUCH_TYPE_NONE,home_main_page,empty_son_p,empty_fun},
	{"DcDc_info",TOUCH_TYPE_SAVE_AND_BACK,home_main_page,empty_son_p,empty_fun},
	{"Overall history",TOUCH_TYPE_ENTER,home_main_page,home_dcdc_overall_history,empty_fun},
	{"Charge cycle history",TOUCH_TYPE_ENTER,home_main_page,home_dcdc_cycle_history,empty_fun},
	{"Device",TOUCH_TYPE_ENTER,home_main_page,home_dcdc_device,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t home_main_page[]=
{
	{"",TOUCH_TYPE_NONE,empty_father_p,empty_son_p,empty_fun},
	{"",TOUCH_TYPE_ENTER,empty_father_p,home_batt_page_info,empty_fun},
	{"",TOUCH_TYPE_NONE,empty_father_p,empty_son_p,empty_fun},
	{"",TOUCH_TYPE_ENTER,empty_father_p,home_inv_page_info,empty_fun},
	{"",TOUCH_TYPE_ENTER,empty_father_p,home_dcdc_page_info,empty_fun},
	{"",TOUCH_TYPE_ENTER,empty_father_p,home_solar_page_info,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};






bool f_display_home_mes_info;
setup_page_t home_page_sta;
lcd_dis_item_t top_5_cun_item[TOP_5_CUN_ITEM_NUM];
lcd_dis_item_t home_5_chun_item[HOME_5_CHUN_ITME_NUM];
void ui_column_home_init_5(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][TOP_SIDE_PAGE_HOME_HOME]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_bg_5_cun_new.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_bg_5_cun_new.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
	p->item_num=HOME_5_CHUN_ITME_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only

	t_home_batt_bg_blue_5_new.key_type = KEY_TYPE_TOUCH_NONE;
	//t_home_batt_bg_black_5_new.key_type = KEY_TYPE_ONCE;
	t_home_batt_info_column_5_new.key_type = KEY_TYPE_TOUCH_NONE;
	//t_home_bg_ac_down_5_new.key_type = KEY_TYPE_ONCE;
	//t_home_bg_dc_down_5_new.key_type = KEY_TYPE_ONCE;
	//t_home_bg_sc_down_5_new.key_type = KEY_TYPE_ONCE;
	
	p->item = home_5_chun_item;
	for(i=0;i<HOME_5_CHUN_ITME_NUM;i++)
	{
		memcpy(&(p->item[i]),p_home_item_5_chun_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_5_chun_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_5_chun_u[i]->size_of_pic_item ;
	}
	for(i=0;i<14;i++)
	{
		home_5_chun_item[6+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	}
	//p->sub_page_count = 0x04; //定义好子页面数目
	//p->sub_page = (lcd_dis_page_t **)malloc(p->sub_page_count * sizeof(lcd_dis_page_t *));  //开辟子页面数组内存
	//for (u8 i=0;i<p->sub_page_count; i++) 
	//{
	//	p->sub_page[i] = (lcd_dis_page_t *)malloc(sizeof(lcd_dis_page_t));  //开辟每个子页面内存
	//	if(p->sub_page[i] != NULL) 
	//	{
	//		p->sub_page[i]->fat_page = p;
  //  }
	//}
	
}


void set_home_display_item_key_type(setup_page_t *home_info_page_p,lcd_dis_item_t *home_info_item_p)
{
	u8 i = 0;
	if(home_info_page_p->now_p == home_main_page)
	{
		for(i=0;i<20;i++)
		{
			if(i>=6)
				home_info_item_p[i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			else
				home_info_item_p[i].key_type = KEY_TYPE_TOUCH_NONE;
		}
		//home_info_item_p[1].key_type = KEY_TYPE_ONCE;
		//home_info_item_p[3].key_type = KEY_TYPE_ONCE;
		//home_info_item_p[4].key_type = KEY_TYPE_ONCE;
		//home_info_item_p[5].key_type = KEY_TYPE_ONCE;
	}
	else 
	{
		for(i=0;i<6;i++)
		{
			home_info_item_p[i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
		}
	}
}
void display_column_home_info_page(bool upgrage_dispaly,bool upgrade,setup_page_t *home_info_page_p,lcd_dis_item_t *home_info_item_p,char* display_buf)
{
	setup_item_info_t *home_p;
	u8 home_page_display_item_num = 0;
	u8 i =0;
	
	if(home_info_page_p->now_p==empty_son_p)
	{
		home_info_page_p->max_page_num = 0;
		return;
	}
	
	else if(home_info_page_p->now_p==home_main_page)
	{
		home_info_page_p->max_page_num = 6;
		home_page_display_item_num = 6;
	}
	else
	{
		home_page_display_item_num = 6;
		for(i=0;1;i++)
		{
			if(home_info_page_p->now_p[i].setup_menu_touch_type == END_OF_THE_LIST)
			{
				 home_info_page_p->max_page_num = i;
				 break;
			}
		}
	}
	
	if(home_info_page_p->now_p == home_main_page)
	{
		if(upgrade)
		{
			set_home_display_item_key_type(home_info_page_p,home_info_item_p);
		}
	}
	else
	{
		sysprintf("\r\n jin lai le  \r\n");
		set_home_display_item_key_type(home_info_page_p,home_info_item_p);
		if(home_info_page_p->now_page_num==0)
			home_info_item_p[19].key_type = KEY_TYPE_TOUCH_NONE;//prepage  
		else
			home_info_item_p[19].key_type = KEY_TYPE_ONCE;//prepage
		
		if((home_info_page_p->now_page_num+1)*home_page_display_item_num<home_info_page_p->max_page_num)
			home_info_item_p[18].key_type = KEY_TYPE_ONCE;//prepage
		else
			home_info_item_p[18].key_type = KEY_TYPE_TOUCH_NONE;//prepage
		if(upgrade)
		{
			Virtual_LCD_Draw_Rectangle_ARGB32(25,50,690,400,Virtual_LCDbuff2,ARGB_clear);
			//Virtual_LCD_Draw_String_ARGB_24_4bit(297,80,display_buf,(0xFF78baf7),0,1,1);
		}
		for(i=0;i<home_page_display_item_num;i++)
		{
			home_p = &home_info_page_p->now_p[home_info_page_p->now_page_num*home_page_display_item_num+i];
			if((home_info_page_p->now_page_num*home_page_display_item_num+i)<(home_info_page_p->max_page_num))
			{
				if(upgrade)
				{
					if(home_p->setup_menu_touch_type==TOUCH_TYPE_NONE_DIS_DIM)
					{
						if(i==0)
							Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(home_info_item_p[HOME_ITEM_1_OFFSET+i].x_val+330,home_info_item_p[HOME_ITEM_1_OFFSET+i].y_val+Y_HOME_INFO_offset,home_info_page_p->now_p[home_info_page_p->now_page_num*home_page_display_item_num+i].display_str,(ARGB_gray),0,1,1);
						else
							Virtual_LCD_Draw_String_ARGB_24_4bit(home_info_item_p[HOME_ITEM_1_OFFSET+i].x_val+X_HOME_INFO_offset,home_info_item_p[HOME_ITEM_1_OFFSET+i].y_val+Y_HOME_INFO_offset,home_info_page_p->now_p[home_info_page_p->now_page_num*home_page_display_item_num+i].display_str,(ARGB_gray),0,1,1);
					}
					else
					{
						if(i==0)
							Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(home_info_item_p[HOME_ITEM_1_OFFSET+i].x_val+330,home_info_item_p[HOME_ITEM_1_OFFSET+i].y_val+Y_HOME_INFO_offset,home_info_page_p->now_p[home_info_page_p->now_page_num*home_page_display_item_num+i].display_str,(0xFFe2e2e4),0,1,1);
						else
							Virtual_LCD_Draw_String_ARGB_24_4bit(home_info_item_p[HOME_ITEM_1_OFFSET+i].x_val+X_HOME_INFO_offset,home_info_item_p[HOME_ITEM_1_OFFSET+i].y_val+Y_HOME_INFO_offset,home_info_page_p->now_p[home_info_page_p->now_page_num*home_page_display_item_num+i].display_str,(0xFFe2e2e4),0,1,1);
					}
				}
				switch(home_p->setup_menu_touch_type)
				{
					case TOUCH_TYPE_NORMAL://正常  
					break;
					case TOUCH_TYPE_ENTER://正常  点一下进入下一级
						home_info_item_p[HOME_OFFSET_ENTER_BTN+i].key_type = KEY_TYPE_ONCE;
						home_info_item_p[HOME_OFFSET_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
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
						home_info_item_p[HOME_OFFSET_ENTER_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
						home_info_item_p[HOME_OFFSET_BTN+i].key_type = KEY_TYPE_TOUCH_NONE;
					break;
					case TOUCH_TYPE_SPECIAL://特殊情况处理 在程序外处理
					break;
					case END_OF_THE_LIST://结束
						home_info_item_p[HOME_OFFSET_ENTER_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
						home_info_item_p[HOME_OFFSET_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					break;
					case TOUCH_TYPE_UPGRADE:
					break;
					case TOUCH_TYPE_BACKGROUND:
						//test_power_item[28].key_type = KEY_TYPE_TOUCH_NONE;
					break;
					case TOUCH_TYPE_SAVE_AND_BACK:
						home_info_item_p[6].key_type = KEY_TYPE_ONCE;// 
					break;
				}
				if(upgrade)
				{
					if(*home_p->f!=empty_fun)
						(*home_p->f)(home_p,i+SYSTEM_ITEM_1_OFFSET,TO_INIT);	
					//sysprintf("\r\n======================%d",i);
				}
				else
				{
					if(*home_p->f!=empty_fun)
						(*home_p->f)(home_p,i+SYSTEM_ITEM_1_OFFSET,TO_DO_NOTHING);	
				}
			}
			else
			{
				home_info_item_p[HOME_OFFSET_ENTER_BTN+i].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
				home_info_item_p[HOME_OFFSET_BTN+i].key_type = KEY_TYPE_TOUCH_NONE;
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
void ui_column_home_info_set(bool upgrade)
{
	setup_page_t *home_info_page_p;
	lcd_dis_item_t *home_info_item_p;
	static u8 last_now_item = TOP_SIDE_ICO_NUM_5;
	
	home_info_page_p = &home_page_sta;
	home_info_item_p = home_5_chun_item;
	
	if(last_now_item!=page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item)
	{
		last_now_item=page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item;
		
		home_info_page_p->now_p = home_main_page;
		home_info_page_p->now_page_deep = 0;
		home_info_page_p->now_page_num = 0;
		power_last_show_page_level = 0;
		power_last_show_page_num[0] = 0;
		power_last_show_page_num[1] = 0;
		set_home_display_item_key_type(home_info_page_p,home_info_item_p);
	}
	f_display_home_mes_info = FALSE;
	display_column_home_info_page(FALSE,upgrade,home_info_page_p,home_info_item_p,"");
}
void ui_top_info_init_t(void)
{
	lcd_dis_page_t *p;
	u8 i = 0;
	p = &page_home.page_info;

	p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=800;
	p->y_end_val=45;
	p->item_num=TOP_5_CUN_ITEM_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only 	
	
	
	t_off_up.key_type = KEY_TYPE_ONCE;
	
	p->item = top_5_cun_item;
	for(i=0;i<TOP_5_CUN_ITEM_NUM;i++)
	{
	  memcpy(&(p->item[i]),p_top_item_5_cun_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_top_item_5_cun_u[i]->pic_item;//
  	p->item[i].size_of_pic_item = p_top_item_5_cun_u[i]->size_of_pic_item ;
	}
}
void disply_column_home_battery_val(bool upgrade)
{
	static BATTERY_STATUS old_assi1_battery_status;  
//	u8 val_temp = 0;
	lcd_dis_item_t *p;//,*p2;
//  u16 offset;
	u32 dis_color = ARGB_white;
	char display_buf[16];
	u16 temp_I;
	//char *dipPtype;

	if((memcmp(&assi1_battery_status,&old_assi1_battery_status,sizeof(BATTERY_STATUS)))||upgrade)
  {
		memcpy(&old_assi1_battery_status,&assi1_battery_status,sizeof(BATTERY_STATUS));
		Virtual_LCD_Draw_Rectangle_ARGB32(90,45,300,365,Virtual_LCDbuff1,ARGB_clear);
		Virtual_LCD_Draw_Rectangle_ARGB32(90,45,350,365,Virtual_LCDbuff2,ARGB_clear);
		
		p = &t_home_batt_bg_blue_5_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		p = &t_home_batt_bg_black_5_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		p = &t_home_batt_info_column_5_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		Virtual_LCD_Draw_String_ARGB_24_4bit(63,285,"Battery",ARGB_myblue,0,1,1);
		if(assi1_battery_status.V!=0)//&&(assi1_battery_status.I!=0))
		{
			if(assi1_battery_status.I&0x8000)
			{
				temp_I =  assi1_battery_status.I&0x7FFF;
				sprintf(display_buf,"%d.%d V / -%d.%d A / -%d W",assi1_battery_status.V/10,assi1_battery_status.V%10,temp_I/10,temp_I%10,(assi1_battery_status.V*temp_I)/100);
			}
			else
			{
				temp_I =  assi1_battery_status.I;
				sprintf(display_buf,"%d.%d V / %d.%d A / %d W",assi1_battery_status.V/10,assi1_battery_status.V%10,temp_I/10,temp_I%10,(assi1_battery_status.V*temp_I)/100);
				p = &t_home_batt_charging_logo;
				png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
			}
			Virtual_LCD_Draw_String_ARGB_24_4bit(150,286,display_buf,ARGB_white,0,1,1);
		}
		else
		{
			sprintf(display_buf,"--   /   --   /   -- ");
			Virtual_LCD_Draw_String_ARGB_24_4bit(220,286,display_buf,ARGB_white,0,1,1);
		}
		
		
		if(assi1_battery_status.f_time_changer)
		{
			sprintf(display_buf,"Charging");	
			dis_color = ARGB_myblue;			
			Virtual_LCD_Draw_String_ARGB_24_4bit(63,335,display_buf,dis_color,0,1,1);
			if(assi1_battery_status.time==0xFFFF)
			{
		    sprintf(display_buf,"--d --h");	 
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
					sprintf(display_buf,"--d --h");	 
					dis_color = ARGB_white;
				}
			}	
		  else if(assi1_battery_status.time>=1440)
			{
				sprintf(display_buf,"%dd  %dh",assi1_battery_status.time/1440,(assi1_battery_status.time%1440)/60);
				dis_color = ARGB_white;
			}
			else if(assi1_battery_status.time==0)
			{
			  sprintf(display_buf,"fully charged");
				dis_color = ARGB_white;
			}
			else
			{
				sprintf(display_buf,"%dh  %dm",(assi1_battery_status.time%1440)/60,(assi1_battery_status.time%1440)%60);
				dis_color = ARGB_white;
			}
			if((assi1_battery_status.time==0xFFFE)&&(type_sel.Battery_SmartShun_Type==1))
				Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,350,335,display_buf,dis_color,0,1,1);
			else
				Virtual_LCD_Draw_String_ARGB_align_right_4bit(24,350,335,display_buf,dis_color,0,1,1);
		}
		else
		{
			sprintf(display_buf,"Discharging");	
			dis_color = ARGB_myblue;			
			Virtual_LCD_Draw_String_ARGB_24_4bit(63,335,display_buf,dis_color,0,1,1);
			if(assi1_battery_status.time==0xFFFF)
			{
				sprintf(display_buf,"--d --h");	
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
					sprintf(display_buf,"--d --h");	
					dis_color = ARGB_white;		
				}
			}	
		  else if(assi1_battery_status.time>=1440)
			{
				sprintf(display_buf,"%dd  %dh",assi1_battery_status.time/1440,(assi1_battery_status.time%1440)/60);
				dis_color = ARGB_white;
			}
			else
			{
				sprintf(display_buf,"%dh  %dm",(assi1_battery_status.time%1440)/60,(assi1_battery_status.time%1440)%60);
				dis_color = ARGB_white;
			}
			if((assi1_battery_status.time==0xFFFE)&&(type_sel.Battery_SmartShun_Type==1))
				Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,350,335,display_buf,dis_color,0,1,1);
			else
				Virtual_LCD_Draw_String_ARGB_align_right_4bit(24,350,335,display_buf,dis_color,0,1,1);
		}
		
		p=&t_home_batt_soc_val_5_new;
		png_dis_xy_to_circle(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,237,156,95,assi1_battery_status.Q,Virtual_LCDbuff1);
		if(assi1_battery_status.Q>=100)
		{
			sprintf(display_buf,"100");
			Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(236,130,display_buf,ARGB_white,0,1,1);
		}
		else if(assi1_battery_status.Q<100 && assi1_battery_status.Q >=10)
		{
			sprintf(display_buf,"%2d%d",assi1_battery_status.Q/10,assi1_battery_status.Q%10);
			Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(230,130,display_buf,ARGB_white,0,1,1);
		}
		else
		{
			sprintf(display_buf,"%2d",assi1_battery_status.Q);
			Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(230,130,display_buf,ARGB_white,0,1,1);
		}
		Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(238,185,"%",ARGB_white,0,1,1);
		
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(90,45,350,365);
	}		
}					

void disply_column_home_bootster_charger_val(bool upgrade)
{
	static CHARGER_STATUS old_Booster_Charger;    
	char display_buf[32];
	lcd_dis_item_t *p;
	
	if((memcmp(&Booster_Charger,&old_Booster_Charger,sizeof(CHARGER_STATUS)))||upgrade)
	{
		memcpy(&old_Booster_Charger,&Booster_Charger,sizeof(CHARGER_STATUS));
		if(Booster_Charger.I_in)
			p=&t_home_bg_dc_down_5_new;
		else
			p=&t_home_bg_dc_up_5_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		if((Booster_Charger.I_in&0x8000))
		{
			sprintf(display_buf,"%dW / -%d.%dA",Booster_Charger.Power&0x7FFF,(Booster_Charger.I_in&0x7FFF)/10,(Booster_Charger.I_in&0x7FFF)%10);
		}
		else if((Booster_Charger.I_in!=0))
		{
			sprintf(display_buf,"%dW / %d.%dA",Booster_Charger.Power&0x7FFF,Booster_Charger.I_in/10,Booster_Charger.I_in%10);
		}
		else 
			sprintf(display_buf,"-- / --");
		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(603,329,display_buf,ARGB_myblue,0,1,1);
		  
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
}
void disply_column_home_solar_charger_val(bool upgrade)
{
	static CHARGER_STATUS old_solar_status;    
	char display_buf[32];
	lcd_dis_item_t *p;
	
	if((memcmp(&solar_status,&old_solar_status,sizeof(SOLAR_STATUS)))||upgrade)
	{
		memcpy(&old_solar_status,&solar_status,sizeof(SOLAR_STATUS));
		if(solar_status.I_in)
			p=&t_home_bg_sc_down_5_new;
		else
			p=&t_home_bg_sc_up_5_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		if((solar_status.I_in&0x8000))
		{
			sprintf(display_buf,"%dW / -%d.%dA",solar_status.Power&0x7FFF,(solar_status.I_in&0x7FFF)/10,(solar_status.I_in&0x7FFF)%10);
		}
		else if((solar_status.I_in!=0))
		{
			sprintf(display_buf,"%dW / %d.%dA",solar_status.Power&0x7FFF,solar_status.I_in/10,solar_status.I_in%10);
		}
		else 
			sprintf(display_buf,"-- / --");
		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(603,211,display_buf,ARGB_myblue,0,1,1);
		
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
}
void disply_column_home_combi_charger_val(bool upgrade)
{
	static CHARGER_STATUS old_Inverter_status;    
	char display_buf[32];
	lcd_dis_item_t *p;
		
	if((memcmp(&Inverter_status,&old_Inverter_status,sizeof(INVERTER_STATUS)))||upgrade)
	{	
		memcpy(&old_Inverter_status,&Inverter_status,sizeof(INVERTER_STATUS));
		if(Inverter_status.I_220)
			p=&t_home_bg_ac_down_5_new;
		else
			p=&t_home_bg_ac_up_5_new;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		if((Inverter_status.I_220&0x8000))
		{
			sprintf(display_buf,"%dW / -%d.%dA",Inverter_status.P_220&0x7FFF,(Inverter_status.I_220&0x7FFF)/10,(Inverter_status.I_220&0x7FFF)%10);
		}
		else if((Inverter_status.I_220!=0))
		{
			sprintf(display_buf,"%dW / %d.%dA",Inverter_status.P_220&0x7FFF,Inverter_status.I_220/10,Inverter_status.I_220%10);
		}
		else 
			sprintf(display_buf,"-- / --");
		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(603,97,display_buf,ARGB_myblue,0,1,1);
		
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
}
extern bool warm_dialog_enable_flag;
u8 warning_dialog_list_item;//保存进入警告弹窗时的页面索引
u8 old_waining_code_list_num=0;
// 显示顶部状态栏信息（蓝牙、警报、关机图标）
// upgrage = TRUE 时强制刷新整个顶部栏
void disply_top_signal_info(bool upgrage)
{
    // 旧状态记录，用于判断是否需要刷新显示（避免频繁重绘）
	static u8 old_f_fault_on = FALSE;            // 上次警报等级
	static bool old_f_ble_connect_on = FALSE;    // 上次蓝牙连接状态
	static bool f_fault_flash_on = FALSE;        // 顶部警告闪烁开关
    static bool old_f_fault_flash_on = FALSE;    // 上次闪烁状态
	static u8 old_power_status = 0;              // 上次关机图标状态

	// 计时用，用于 500ms 触发闪烁
	static u32 IdelTime = 0;

	lcd_dis_item_t *p;
	u8 i;

	/* ===================================================
	   1) 判断当前是否存在警报 & 确定警报等级
	       0 = 无警报（灰色）
	       1 = 黄警报（低等级）
	       2 = 红警报（高等级）
	   =================================================== */

	if (waining_code_list_num)  // 有警报
	{

        if(warm_dialog_enable_flag)//使能弹窗
        if(old_waining_code_list_num!=waining_code_list_num)//仅在警报数量变化时弹窗
        {
           if(page_home.page_top_side[0].now_item!=7)warning_dialog_list_item=page_home.page_top_side[0].now_item;
           page_home.page_top_side[0].now_item=7;//弹窗页面
            old_waining_code_list_num=waining_code_list_num;
        }
        
        
		f_fault_on = 1;  // 默认先认为是低等级（黄）

		// 检查是否存在高等级错误（02/03）
		for (i = 0; i < waining_code_list_num; i++)
		{ 
			if ((waining_code_list[i+1].err_code_type == 0x02) ||
			    (waining_code_list[i+1].err_code_type == 0x03))
			{
				f_fault_on = 2;  // 高等级（红）
				break;
			}
		}
	}
	else
	{
		f_fault_on = 0;  // 无报警（灰色）
        old_waining_code_list_num=0;
 	}

	/* ===================================================
	   2) 控制警告闪烁（每 500ms 翻转一次）
	   =================================================== */

	// 初始化延时计时器
	if (IdelTime == 0)
		ResetDelayTime(&IdelTime);

	// 每 500ms 触发一次
	if (CntDelayTime(&IdelTime, TIME_ONE_MS * 500))
	{
		ResetDelayTime(&IdelTime);

		// 外部开关 f_fault_flash 为 true 时才允许闪烁
		if (f_fault_flash)
			f_fault_flash_on = !f_fault_flash_on; // 取反（闪烁）
		else
			f_fault_flash_on = FALSE;             // 不闪烁
	}

	/* ===================================================
	   3) 判断是否需要刷新显示
	     - 强制刷新
	     - 蓝牙状态变化
	     - 警报等级变化
	     - 警报闪烁状态变化
	     - 电源图标状态变化
	   =================================================== */

	if (upgrage ||
	    (old_f_ble_connect_on != f_ble_connect_on) ||
	    (old_power_status != top_5_cun_item[1].now_status) ||
	    (old_f_fault_on != f_fault_on) ||
	    (old_f_fault_flash_on != f_fault_flash_on))
	{
		// 更新旧状态
		old_power_status = top_5_cun_item[1].now_status;
		old_f_ble_connect_on = f_ble_connect_on;
		old_f_fault_on = f_fault_on;
		old_f_fault_flash_on = f_fault_flash_on;

		/* ===================================================
		   4) 显示蓝牙图标
		   =================================================== */
        
//		if (f_ble_connect_on)
//			p = &t_Bluetooth_d;      // 已连接图标
//		else
//			p = &t_Bluetooth_up_2;   // 未连接图标

//		png_dis_xy(p->x_val, p->y_val, p->pic_item, p->size_of_pic_item, Virtual_LCDbuff1);


		/* ===================================================
		   5) 显示警报图标（红 / 黄 / 灰）
		   =================================================== */

		if (f_fault_on == 2)
			p = &t_warn_r;     // 红色警告（高等级）
		else if (f_fault_on == 1)
			p = &t_warn_y;     // 黄色警告（低等级）
		else
		{
			p = &t_warn_no;    // 无警告（灰色）
			// 直接显示灰色警告图标
			png_dis_xy(p->x_val, p->y_val, p->pic_item, p->size_of_pic_item, Virtual_LCDbuff1);
		}

		/* ===================================================
		   6) 警告图标闪烁控制
		       f_fault_flash_on = true 则清除区域实现闪烁
		       false 则正常显示图标
		   =================================================== */

		if (f_fault_flash_on)
		{
			// 清空警报图标区域，实现“闪烁效果”
			Virtual_LCD_Draw_Rectangle_ARGB32(
			    p->x_val, p->y_val,
			    p->x_end_val - p->x_val,
			    p->y_end_val - p->y_val,
			    Virtual_LCDbuff1,
			    ARGB_clear
			);
		}
		else if ((f_fault_on == 2) || (f_fault_on == 1))
		{
			// 仅在有警告时绘制（红/黄）
			png_dis_xy(p->x_val, p->y_val, p->pic_item, p->size_of_pic_item, Virtual_LCDbuff1);
		}


		/* ===================================================
		   7) 显示关机图标
		   =================================================== */

		if (top_5_cun_item[1].now_status == STATUS_IDLE)
			p = &t_off_up;   // 默认显示
		else
			p = &t_off_up;   //（你原代码两个都一样）

		png_dis_xy(p->x_val, p->y_val, p->pic_item, p->size_of_pic_item, Virtual_LCDbuff1);


		/* ===================================================
		   8) 局部刷新屏幕（仅刷新顶部区域）
		   =================================================== */

		if (upgrage == FALSE)
			Virtual_LCD_Upgrate_formx1y1(590-10, 0, 200+10, 90);
	}
}
