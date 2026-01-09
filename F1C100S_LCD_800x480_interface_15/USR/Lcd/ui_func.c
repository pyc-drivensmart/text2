#include "includes.h"




//read me:copy the new item to 'ui_func.c'





void func_background_1(void* p,u8 sn)
{

}



void func_background_2(void* p,u8 sn)
{

}





void func_text_ELEVATOR(void* p,u8 sn)
{

}





//add





void func_Bluetooth_up_2(void* p,u8 sn)
{

}



void func_page1_slider_100(void* p,u8 sn)
{

}




void func_page3_slider_100(void* p,u8 sn)
{

}



void func_page6_no_select2(void* p,u8 sn)
{

}

void func_page6_no_select2_2(void* p,u8 sn)
{

}
void func_page6_no_select2_3(void* p,u8 sn)
{

}void func_page6_no_select2_4(void* p,u8 sn)
{

}


void func_bk13(void* p,u8 sn)
{

}



extern void func_Setup_coulumn_enter(void* p,u8 sn);

void func_page6_select2(void* p,u8 sn)
{
    func_Setup_coulumn_enter(p,sn);

}
void func_page6_select2_2(void* p,u8 sn)
{
    func_Setup_coulumn_enter(p,sn);

}

void func_page6_select2_3(void* p,u8 sn)
{
    func_Setup_coulumn_enter(p,sn);

}
void func_page6_select2_4(void* p,u8 sn)
{
    func_Setup_coulumn_enter(p,sn);

}





void func_page6_s_back_d(void* p,u8 sn)
{
    func_Setup_save_and_back_new_down(p,sn);

}



void func_page6_s_back_up(void* p,u8 sn)
{
    func_Setup_save_and_back_new_down(p,sn);

}



void func_page6_upgrade_icon_3(void* p,u8 sn)
{

}



////////new_5_cun////////////////////////////////////////////////////////////
void func_bg_5_cun_new(void* p,u8 sn)
{
	
}


void func_bgbg_test(void* p,u8 sn)
{

}


void func_bottom_alarm_down_5_new(void* p,u8 sn)
{
		sysprintf("func_bottom_alarm_down_5_new----------------------------\r\n");

}



void func_bottom_alarm_up_5_new(void* p,u8 sn)
{

}



void func_bottom_home_down_5_new(void* p,u8 sn)
{
		sysprintf("func_bottom_home_down_5_new----------------------------\r\n");

}



void func_bottom_home_up_5_new(void* p,u8 sn)
{

}



void func_bottom_power_down_5_new(void* p,u8 sn)
{
		sysprintf("func_bottom_power_down_5_new----------------------------\r\n");

}



void func_bottom_power_up_5_new(void* p,u8 sn)
{

}



void func_bottom_setup_down_5_new(void* p,u8 sn)
{
			sysprintf("func_bottom_setup_down_5_new----------------------------\r\n");

}



void func_bottom_setup_up_5_new(void* p,u8 sn)
{

}

void func_top_bluetooth_connect_new(void* p,u8 sn)
{

}



void func_top_bluetooth_disconnect_new(void* p,u8 sn)
{

}



void func_top_turn_off_screen_icon_new(void* p,u8 sn)
{
	u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		send_FlC200_swtich_cmd(0x28,1);//
		f_disply_debug_val = FALSE;
		send_FlC200_base_set_cmd(0x82,0,0);
	}
}



void func_top_warning_icon_new(void* p,u8 sn)
{

}

void func_top_warning_icon_yellow_new(void* p,u8 sn)
{

}
///////////////////////////////////////////////////////////////
void func_bg_5_chun(void* p,u8 sn)
{

}



void func_bottom_Appliances_down_5(void* p,u8 sn)
{

}



void func_bottom_Appliances_up_5(void* p,u8 sn)
{

}



void func_bottom_home_down_5(void* p,u8 sn)
{

}



void func_bottom_home_up_5(void* p,u8 sn)
{

}



void func_bottom_lights_down_5(void* p,u8 sn)
{

}



void func_bottom_lights_up_5(void* p,u8 sn)
{

}



void func_bottom_power_down_5(void* p,u8 sn)
{

}



void func_bottom_power_up_5(void* p,u8 sn)
{

}



void func_bottom_setup_down_5(void* p,u8 sn)
{

}



void func_bottom_setup_up_5(void* p,u8 sn)
{

}



void func_bottom_tanks_down_5(void* p,u8 sn)
{

}



void func_bottom_tanks_up_5(void* p,u8 sn)
{

}





///////////////////////////////////////////////



///////////////////////复用按键补充/////////////////////////////




void func_power_batt_bg(void* p,u8 sn)
{

}

void func_power_bc_icon(void* p,u8 sn)
{

}



void func_power_cc_icon(void* p,u8 sn)
{

}



void func_power_charger_bg(void* p,u8 sn)
{

}



void func_power_sc_icon(void* p,u8 sn)
{

}


void func_light_bg(void* p,u8 sn)
{

}



void func_bgbg(void* p,u8 sn)
{

}


void func_bg(void* p,u8 sn)
{

}

void func_menu_home_d(void* p,u8 sn)
{

}



void func_menu_home_u(void* p,u8 sn)
{

}



void func_menu_lights_d(void* p,u8 sn)
{

}



void func_menu_lights_u(void* p,u8 sn)
{

}



void func_menu_loads_d(void* p,u8 sn)
{

}



void func_menu_loads_u(void* p,u8 sn)
{

}



void func_menu_power_d(void* p,u8 sn)
{

}



void func_menu_power_u(void* p,u8 sn)
{

}



void func_menu_system_d(void* p,u8 sn)
{

}



void func_menu_system_u(void* p,u8 sn)
{

}



void func_menu_tanks_d(void* p,u8 sn)
{

}



void func_menu_tanks_u(void* p,u8 sn)
{

}


void func_top_bluetooth_d(void* p,u8 sn)
{

}

void func_top_bluetooth_t(void* p,u8 sn)
{

}

void func_top_bluetooth_u(void* p,u8 sn)
{

}

void func_top_power_d(void* p,u8 sn)
{

}
void func_top_power(void* p,u8 sn)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		send_FlC200_swtich_cmd(0x28,1);//
		f_disply_debug_val = FALSE;
		send_FlC200_base_set_cmd(0x82,0,0);
		
	}
}


void func_top_power_u(void* p,u8 sn)
{

}



void func_top_wifi_1(void* p,u8 sn)
{

}



void func_top_wifi_2(void* p,u8 sn)
{

}



void func_top_wifi_3(void* p,u8 sn)
{

}



void func_top_wifi_e(void* p,u8 sn)
{

}



void func_top_wifi_f(void* p,u8 sn)
{

}



void func_top_fault_gray(void* p,u8 sn)
{

}



void func_top_fault_red(void* p,u8 sn)
{

}



void func_top_fault_yellow(void* p,u8 sn)
{

}

void func_top_fault(void* p,u8 sn)
{
	u8 i;
    u8 SN = sn;  // 保存子项索引（当前操作的子项编号）
    lcd_dis_page_t *p2;  // 用于指向顶部页面的指针
    lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;  // 将void*转换为页面结构体指针，便于操作当前页面
    
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		//sysprintf("\r\n666666666ttt6666556666");
		f_fault_flash = FALSE;
		if(waining_code_list_num)
		{
			p2 = &page_home.page_top_side[LEFT_SIDE_PAGE_HOME];// 指向顶部页面（可能是一个导航栏或标签页页面）
			p2->now_item = TOP_SIDE_PAGE_HOME_ALARM;	// 设置顶部页面当前选中项为“故障报警页”（TOP_SIDE_PAGE_HOME_ALARM是枚举值）
			for(i=0;i<p2->item_num;i++)// 先将顶部页面所有子项状态设为“空闲”（STATUS_IDLE）
			{
				p2->item[i].now_status = STATUS_IDLE;
			}
			p2->item[TOP_SIDE_PAGE_HOME_ALARM].now_status = STATUS_SELECT;// 单独将“故障报警页”子项设为“选中状态”（高亮显示）
			f_force_to_target_top_page = TRUE;// 强制切换到目标顶部页面（触发页面刷新显示）
		}
	}
}




void func_key_locked1(void* p,u8 sn)
{

}
void func_key_locked2(void* p,u8 sn)
{

}

void func_icon_warning(void* p,u8 sn)
{

}










/////////////////////////////////////////////old/////////////////////////////////////////////////////

void func_info(void* p,u8 sn)
{

}







void func_menu_carinfo_d(void* p,u8 sn)
{

}



void func_menu_carinfo_u(void* p,u8 sn)
{

}



void func_menu_carset_d(void* p,u8 sn)
{

}



void func_menu_carset_u(void* p,u8 sn)
{

}



void func_menu_climate_d(void* p,u8 sn)
{

}



void func_menu_climate_u(void* p,u8 sn)
{

}



void func_menu_parking_d(void* p,u8 sn)
{

}



void func_menu_parking_u(void* p,u8 sn)
{

}



void func_menu_systemset_d(void* p,u8 sn)
{

}



void func_menu_systemset_u(void* p,u8 sn)
{

}



void func_radar(void* p,u8 sn)
{

}






void func_setting(void* p,u8 sn)
{

}

/////////////////////////////////////////////////

void func_topbtn_climate_d(void* p,u8 sn)
{

}



void func_topbtn_climate_u(void* p,u8 sn)
{

}



void func_topbtn_seat_d(void* p,u8 sn)
{

}



void func_topbtn_seat_u(void* p,u8 sn)
{

}



void func_topbtn_setup_d(void* p,u8 sn)
{

}



void func_topbtn_setup_u(void* p,u8 sn)
{

}
//////////////////////////////////////////////


void func_topbtn_ic_d(void* p,u8 sn)
{

}



void func_topbtn_ic_u(void* p,u8 sn)
{

}



void func_topbtn_vi_d(void* p,u8 sn)
{

}



void func_topbtn_vi_u(void* p,u8 sn)
{

}

void func_page0(void* p,u8 sn)
{

}



void func_page1(void* p,u8 sn)
{

}



void func_page2(void* p,u8 sn)
{

}



void func_page3(void* p,u8 sn)
{

}



void func_page4(void* p,u8 sn)
{

}



void func_page5(void* p,u8 sn)
{

}


//new

//read me:copy the new item to 'ui_func.c'





void func_Bluetooth_d(void* p,u8 sn)
{

}



void func_Bluetooth_up(void* p,u8 sn)
{

}



void func_new_AC_d(void* p,u8 sn)
{

}



void func_new_AC_up(void* p,u8 sn)
{

}



void func_new_Elevator_d(void* p,u8 sn)
{

}



void func_new_Elevator_up(void* p,u8 sn)
{

}



void func_new_Halo_d(void* p,u8 sn)
{

}



void func_new_Halo_up(void* p,u8 sn)
{

}



void func_new_Light_d(void* p,u8 sn)
{

}



void func_new_Light_up(void* p,u8 sn)
{

}



void func_new_Setup_d(void* p,u8 sn)
{

}



void func_new_Setup_up(void* p,u8 sn)
{

}



void func_off_d(void* p,u8 sn)
{
   u8 SN = sn;//图标在当前页面列表的序号s
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
        if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
        {
        
		send_FlC200_swtich_cmd(0x28,1);//
		f_disply_debug_val = FALSE;
		send_FlC200_base_set_cmd(0x82,0,0);
		                    sysprintf("func_off_up----------------------------\r\n");

        }
        
        
}



void func_off_up(void* p,u8 sn)
{
//   u8 SN = sn;//图标在当前页面列表的序号
//  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
//    sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
//        if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
//        {
//        
//		send_FlC200_swtich_cmd(0x28,1);//
//		f_disply_debug_val = FALSE;
//		send_FlC200_base_set_cmd(0x82,0,0);
//		                    sysprintf("func_off_up----------------------------\r\n");

//        } 
        
        u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		send_FlC200_swtich_cmd(0x28,1);//
		f_disply_debug_val = FALSE;
		send_FlC200_base_set_cmd(0x82,0,0);
	}
}



void func_warn_no(void* p,u8 sn)
{
 
        u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    
    sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
    sysprintf("func_warn_no----------------------------\r\n");
//       p1->item[SN].now_status=STATUS_IDLE;
//    ui_column_alarm_init_5();
        
	}
}



void func_warn_r(void* p,u8 sn)
{
        u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
    sysprintf("func_warn_r----------------------------\r\n");

	}
}



void func_warn_y(void* p,u8 sn)
{
        u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
    sysprintf("func_warn_y----------------------------\r\n");

	}
}

//read me:copy the new item to 'ui_func.c'





void func_background(void* p,u8 sn)
{

}







void func_new_AC_d_5(void* p,u8 sn)
{

}



void func_new_AC_up_5(void* p,u8 sn)
{

}


extern lcd_dis_item_t home_5_chun_item2[2];

void func_new_Elevator_d_5(void* p,u8 sn)
{
   if(f_ignore_handbreak==1)//无手刹检测
        {
            home_5_chun_item2[0].key_type = KEY_TYPE_TOUCH_KEEP;//持续按下
            home_5_chun_item2[1].key_type = KEY_TYPE_TOUCH_KEEP;    
        }
        else//检测手刹
        {
             if(f_handbreak)///有手刹
            {
            home_5_chun_item2[0].key_type = KEY_TYPE_TOUCH_KEEP;//持续按下
            home_5_chun_item2[1].key_type = KEY_TYPE_TOUCH_KEEP;    
            }
             else //无手刹
            {
            home_5_chun_item2[0].now_status=STATUS_IDLE;
            home_5_chun_item2[1].now_status=STATUS_IDLE;
            home_5_chun_item2[1].key_type = KEY_TYPE_TOUCH_NONE;//不
            home_5_chun_item2[0].key_type = KEY_TYPE_TOUCH_NONE;
            }
        }

}



void func_new_Elevator_up_5(void* p,u8 sn)
{

}


extern RGBSystem now_RGB_status;   //现在状态
extern void DrawColorSelectorByRGB(u8 R, u8 G, u8 B);

void func_new_Halo_d_5(void* p,u8 sn)
{
    u8 SN = sn;//图标在当前页面列表的序号
    lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;

    sysprintf("func_new_Halo_d_5----------------------------\r\n");
        sysprintf("item[SN].now_status=%d----------------------------\r\n",p1->item[SN].now_status);
    
//    u8 SN = sn;//图标在当前页面列表的序号
//    lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
        
        if(now_RGB_status.RGB_select==0)//现在选中的RGB
      DrawColorSelectorByRGB(now_RGB_status.RGB[0].r,now_RGB_status.RGB[0].g,now_RGB_status.RGB[0].b);//反馈绘制小圆
        else if(now_RGB_status.RGB_select==1)//现在选中的RGB
      DrawColorSelectorByRGB(now_RGB_status.RGB[1].r,now_RGB_status.RGB[1].g,now_RGB_status.RGB[1].b);//反馈绘制小圆



    }
}


void func_new_Halo_up_5(void* p,u8 sn)
{
    sysprintf("func_new_Halo_d_5----------------------------\r\n");

}



void func_new_heater_d_5(void* p,u8 sn)
{

}



void func_new_heater_up_5(void* p,u8 sn)
{

}



void func_new_Light_d_5(void* p,u8 sn)
{
  // Light_Status_synchronization_SW(TRUE);//同步开关状态
       lcd_dis_page_t * p3 = &page_home.page_top_side[page_home.page_left_side.now_item];	
    p3->last_item = LEFT_SIDE_PAGE_UPDATA;

}



void func_new_Light_up_5(void* p,u8 sn)
{

}



void func_new_Setup_d__5(void* p,u8 sn)
{

}



void func_new_Setup_up_5(void* p,u8 sn)
{

}










void func_page1_slider_25(void* p,u8 sn)
{

}
//page6
//read me:copy the new item to 'ui_func.c'





void func_page6_down_d(void* p,u8 sn)
{
func_Setup_page_next_down_new(p,sn);
}



void func_page6_down_up(void* p,u8 sn)
{

}



void func_page6_in(void* p,u8 sn)
{

}



void func_page6_in_2(void* p,u8 sn)
{

}


extern void func_Setup_coulumn_set_left(void* p,u8 sn);

extern SetupSystem now_Setup_status;   //现在状态

void func_page6_left_d(void* p,u8 sn)
{    
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
   
    sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
        if(p1->item[SN].now_status==STATUS_SELECT)//按ON
        {
            if(now_Setup_status.icon>=1)now_Setup_status.icon--;

        }
        else if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
        {
            if(now_Setup_status.icon>=1)now_Setup_status.icon--;

        }
	//func_Setup_coulumn_set_left(p,sn);

}
void func_page6_left_d_2(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);

}void func_page6_left_d_3(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);

}void func_page6_left_d_4(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);

}

void func_page6_left_up(void* p,u8 sn)
{
}
 void func_page6_left_up_2(void* p,u8 sn)
{

}void func_page6_left_up_3(void* p,u8 sn)
{

}void func_page6_left_up_4(void* p,u8 sn)
{

}









u8 setup_page_display_num22 = 4;//页面选项数

void func_Setup_coulumn_touch2(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
		sysprintf("func_Setup_coulumn_touch2----------------\r\n");

	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		setup_p = &setup_page_sta.now_p[setup_page_sta.now_page_num*setup_page_display_num22+sn-0];

		if(*setup_p->f!=empty_fun)
		{
			(*setup_p->f)(setup_p,SN,TO_DEAL);	
		}
		p1->item[SN].now_status=STATUS_IDLE;
	}
}


void func_Setup_coulumn_enter2(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		//setup_p = &setup_page_sta.now_p[setup_page_sta.now_page_num*4+sn];
        		setup_p = &setup_page_sta.now_p[setup_page_sta.now_page_num*setup_page_display_num22+sn-0];

//		if((setup_p->setup_menu_touch_type!=TOUCH_TYPE_NORMAL)&&(setup_p->setup_menu_touch_type!=TOUCH_TYPE_KEYBOARD))
//		{
//			if((setup_page_sta.now_p != System_Reset_5)&&(setup_page_sta.now_p !=Restore_Default_Settings_5)\
//				&&(setup_page_sta.now_p != Battery_info_select)&&(setup_page_sta.now_p != Inverter_info_select)\
//					&&(setup_page_sta.now_p != Mppt_info_select)&&(setup_page_sta.now_p != DcDc_info_select))
//			{
//                
				last_show_page_num[last_show_page_level] = setup_page_sta.now_page_num;
				last_show_page_level++;
				setup_page_sta.now_page_num = 0;
				setup_page_sta.now_p = setup_p->son_p;
        
//				if(setup_page_sta.now_p == Data_Time)
//				{
//					memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
//				}
                
                
				//Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(0,392,800,88,ARGB_clear);
//				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=8;//更新
				//page_home.page_top_side[page_home.page_left_side.now_item].item[3].last_status= STATUS_IDLE;
				f_display_set_info = TRUE;
                
//                
//			}
//		}
		if(*setup_p->f!=empty_fun)//页面功能函数
			(*setup_p->f)(setup_p,SN,TO_DEAL);	
     //(*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_ITEM_1_OFFSET,TO_DOWN);	
    p1->item[SN].now_status=STATUS_IDLE;
	}
}




void func_page6_no_select(void* p,u8 sn)
{
	sysprintf("iniiiiiiiiiiiiiiiiiiiiiiiiiiiiii------------func_page6_no_select_1----\r\n");
    //func_Setup_coulumn_enter2(p,sn);
    func_Setup_coulumn_enter(p,sn);

}

void func_page6_no_select_2(void* p,u8 sn)
{
	sysprintf("iniiiiiiiiiiiiiiiiiiiiiiiiiiiiii------------func_page6_no_select_2----\r\n");
 //   func_Setup_coulumn_enter2(p,sn);
        func_Setup_coulumn_enter(p,sn);

}
void func_page6_no_select_3(void* p,u8 sn)
{
	sysprintf("iniiiiiiiiiiiiiiiiiiiiiiiiiiiiii------------func_page6_no_select_3----\r\n");
   // func_Setup_coulumn_enter2(p,sn);
        func_Setup_coulumn_enter(p,sn);

}
void func_page6_no_select_4(void* p,u8 sn)
{
	sysprintf("iniiiiiiiiiiiiiiiiiiiiiiiiiiiiii------------func_page6_no_select_4 ----\r\n");
  ///  func_Setup_coulumn_enter2(p,sn);
        func_Setup_coulumn_enter(p,sn);


}

extern void func_Setup_save_and_back_new_down(void* p,u8 sn);
void func_page6_no_select_back(void* p,u8 sn)
{
	sysprintf("iniiiiiiiiiiiiiiiiiiiiiiiiiiiiii------------func_page6_no_select_back----\r\n");
    //func_Setup_coulumn_enter2(p,sn);
    func_Setup_save_and_back_new_down(p,sn);
}


void func_page6_select_2(void* p,u8 sn)
{

}
void func_page6_select_3(void* p,u8 sn)
{

}
void func_page6_select_4(void* p,u8 sn)
{

}


extern  void func_Setup_coulumn_set_right(void* p,u8 sn);


void func_page6_right_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
   
    sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
        if(p1->item[SN].now_status==STATUS_SELECT)//按ON
        {
    if(now_Setup_status.icon<2)now_Setup_status.icon++;

        }
        else if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
        {
    if(now_Setup_status.icon<2)now_Setup_status.icon++;

        }
	//func_Setup_coulumn_set_right(p,sn);

}
void func_page6_right_d_2(void* p,u8 sn)
{
	func_Setup_coulumn_set_right(p,sn);

}void func_page6_right_d_3(void* p,u8 sn)
{
	func_Setup_coulumn_set_right(p,sn);

}void func_page6_right_d_4(void* p,u8 sn)
{
	func_Setup_coulumn_set_right(p,sn);

}


void func_page6_right_up(void* p,u8 sn)
{

}
void func_page6_right_up_2(void* p,u8 sn)
{

}void func_page6_right_up_3(void* p,u8 sn)
{

}void func_page6_right_up_4(void* p,u8 sn)
{

}




void func_page6_select(void* p,u8 sn)
{

}



void func_page6_temp_icon(void* p,u8 sn)
{

}



void func_page6_time_icon(void* p,u8 sn)
{

}



void func_page6_upgrade_icon(void* p,u8 sn)
{

}



void func_page6_upgrade_icon_2(void* p,u8 sn)
{

}


//extern void func_Setup_save_and_back_new_down(void* p,u8 sn);
//extern void func_Setup_page_next_down_new(void* p,u8 sn);


extern void func_Setup_page_pre_down_new(void* p,u8 sn);
extern void func_Setup_page_next_down_new(void* p,u8 sn);

void func_page6_up_d(void* p,u8 sn)
{
func_Setup_page_pre_down_new(p,sn);
}



void func_page6_up_up(void* p,u8 sn)
{

}



void func_page6_Ver_icon(void* p,u8 sn)
{

}
//page6
//read me:copy the new item to 'ui_func.c'




void func_page4_el_up(void* p,u8 sn)
{

}



void func_page6_temp_ico_2(void* p,u8 sn)
{

}



