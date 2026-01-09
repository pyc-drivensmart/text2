#include "includes.h"

void func_setup_column_1_5(void* p,u8 sn)
{

}


void func_setup_column_2_5(void* p,u8 sn)
{

}


void func_setup_column_3_5(void* p,u8 sn)
{

}


void func_setup_column_4_5(void* p,u8 sn)
{

}


void func_setup_column_5_5(void* p,u8 sn)
{

}


void func_setup_column_6_5(void* p,u8 sn)
{

}


void func_setup_column_7_5(void* p,u8 sn)
{

}



void func_setup_column_right_add_1_5(void* p,u8 sn)
{

}



void func_setup_solumn_left_sub_1_5(void* p,u8 sn)
{

}

//////////////new_5_cun////////////////////////////////////////////////////
void func_Setup_coulumn_enter(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		setup_p = &setup_page_sta.now_p[setup_page_sta.now_page_num*setup_page_display_num+sn-SYSTEM_ITEM_1_OFFSET];
		if((setup_p->setup_menu_touch_type!=TOUCH_TYPE_NORMAL)&&(setup_p->setup_menu_touch_type!=TOUCH_TYPE_KEYBOARD))
		{
			if((setup_page_sta.now_p != System_Reset_5)&&(setup_page_sta.now_p !=Restore_Default_Settings_5)\
				&&(setup_page_sta.now_p != Battery_info_select)&&(setup_page_sta.now_p != Inverter_info_select)\
					&&(setup_page_sta.now_p != Mppt_info_select)&&(setup_page_sta.now_p != DcDc_info_select))
			{
				last_show_page_num[last_show_page_level] = setup_page_sta.now_page_num;
				last_show_page_level++;
				setup_page_sta.now_page_num = 0;
				setup_page_sta.now_p = setup_p->son_p;
				if(setup_page_sta.now_p == Data_Time)
				{
					memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
				}
				//Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(0,392,800,88,ARGB_clear);
				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
				//page_home.page_top_side[page_home.page_left_side.now_item].item[3].last_status= STATUS_IDLE;
				f_display_set_info = TRUE;
			}
		}
		if(*setup_p->f!=empty_fun)//页面功能函数
			(*setup_p->f)(setup_p,SN,TO_DEAL);	
     //(*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_ITEM_1_OFFSET,TO_DOWN);	
    p1->item[SN].now_status=STATUS_IDLE;
	}
}

void func_Setup_coulumn_touch(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		setup_p = &setup_page_sta.now_p[setup_page_sta.now_page_num*setup_page_display_num+sn-SETUP_OFFSET_BTN];
		if((setup_page_sta.now_p == Batt_settings)||(setup_page_sta.now_p == Inv_settings)||(setup_page_sta.now_p == Power_setting))
		{
			//setup_p = &setup_page_sta.now_p[setup_page_sta.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_ITEM_1_OFFSET];
			//(*setup_p->f)(setup_p,sn-6+SYSTEM_ITEM_1_OFFSET,TO_DEAL);	
			keyboard_ui_step=KEYBOARD_PAGE_NUM;
			f_display_set_info = TRUE;
			f_need_ui_disply_keyboard = TRUE;

		}
		if(*setup_p->f!=empty_fun)
		{
			(*setup_p->f)(setup_p,SN,TO_DEAL);	
		}
		p1->item[SN].now_status=STATUS_IDLE;
	}
}


void func_Setup_info_coulumn_new(void* p,u8 sn)
{

}

void func_Setup_info_coulumn_new_1(void* p,u8 sn)
{

}

void func_Setup_info_coulumn_new_2(void* p,u8 sn)
{

}

void func_Setup_info_coulumn_new_3(void* p,u8 sn)
{
	
}
void func_Setup_info_coulumn_new_4(void* p,u8 sn)
{
	
}
void func_Setup_info_coulumn_new_5(void* p,u8 sn)
{
	
}
void func_Setup_info_coulumn_new_6(void* p,u8 sn)
{
	
}
void func_Setup_info_coulumn_d_new(void* p,u8 sn)
{
	func_Setup_coulumn_touch(p,sn);
}
void func_Setup_info_coulumn_d_new_1(void* p,u8 sn)
{
	func_Setup_coulumn_touch(p,sn);
}
void func_Setup_info_coulumn_d_new_2(void* p,u8 sn)
{
	func_Setup_coulumn_touch(p,sn);
}
void func_Setup_info_coulumn_d_new_3(void* p,u8 sn)
{
	func_Setup_coulumn_touch(p,sn);
}
void func_Setup_info_coulumn_d_new_4(void* p,u8 sn)
{
	func_Setup_coulumn_touch(p,sn);
}
void func_Setup_info_coulumn_d_new_5(void* p,u8 sn)
{
	func_Setup_coulumn_touch(p,sn);
}
void func_Setup_info_coulumn_d_new_6(void* p,u8 sn)
{
	func_Setup_coulumn_touch(p,sn);
}
void func_Setup_coulumn_set_left(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		f_display_set_info = TRUE;
		setup_p = &setup_page_sta.now_p[setup_page_sta.now_page_num*setup_page_display_num+sn-SETUP_OFFSET_LEFT];
		(*setup_p->f)(setup_p,sn-SETUP_OFFSET_LEFT+SYSTEM_ITEM_1_OFFSET,TO_DOWN);	
	}
}
void func_Setup_coulumn_set_right(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		f_display_set_info = TRUE;
		setup_p = &setup_page_sta.now_p[setup_page_sta.now_page_num*setup_page_display_num+sn-SETUP_OFFSET_RIGHT];
		(*setup_p->f)(setup_p,sn-SETUP_OFFSET_LEFT+SETUP_OFFSET_RIGHT,TO_UP);	
	}
}


void func_Setup_left_icon_down_new(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);
}
void func_Setup_left_icon_down_new_1(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);
}
void func_Setup_left_icon_down_new_2(void* p,u8 sn)
{	
	func_Setup_coulumn_set_left(p,sn);
}
void func_Setup_left_icon_down_new_3(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);
}
void func_Setup_left_icon_down_new_4(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);
}
void func_Setup_left_icon_down_new_5(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);
}
void func_Setup_left_icon_down_new_6(void* p,u8 sn)
{
	func_Setup_coulumn_set_left(p,sn);
}
void func_Setup_left_icon_up_new(void* p,u8 sn)
{

}
void func_Setup_left_icon_up_new_1(void* p,u8 sn)
{                               
                                
}                               
void func_Setup_left_icon_up_new_2(void* p,u8 sn)
{                               
                                
}                               
void func_Setup_left_icon_up_new_3(void* p,u8 sn)
{                               
                                
}  
void func_Setup_left_icon_up_new_4(void* p,u8 sn)
{                               
                                
}  
void func_Setup_left_icon_up_new_5(void* p,u8 sn)
{                               
                                
}  
void func_Setup_left_icon_up_new_6(void* p,u8 sn)
{                               
                                
}  
void func_Setup_right_icon_down_new(void* p,u8 sn)
{
	func_Setup_coulumn_set_right(p,sn);
}

void func_Setup_right_icon_down_new_1(void* p,u8 sn)
{                                  
	func_Setup_coulumn_set_right(p,sn);
}                                  
                                   
void func_Setup_right_icon_down_new_2(void* p,u8 sn)
{                                  
	func_Setup_coulumn_set_right(p,sn);
}   
void func_Setup_right_icon_down_new_3(void* p,u8 sn)
{                                  
	func_Setup_coulumn_set_right(p,sn);
}
void func_Setup_right_icon_down_new_4(void* p,u8 sn)
{                                  
	func_Setup_coulumn_set_right(p,sn);
}
void func_Setup_right_icon_down_new_5(void* p,u8 sn)
{                                  
	func_Setup_coulumn_set_right(p,sn);
}
void func_Setup_right_icon_down_new_6(void* p,u8 sn)
{                                  
	func_Setup_coulumn_set_right(p,sn);
}
void func_Setup_right_icon_up_new(void* p,u8 sn)
{

}

void func_Setup_right_icon_up_new_1(void* p,u8 sn)
{                                
                                 
}                                
                                 
void func_Setup_right_icon_up_new_2(void* p,u8 sn)
{                                
                                 
} 
void func_Setup_right_icon_up_new_3(void* p,u8 sn)
{                                
                                 
} 
void func_Setup_right_icon_up_new_4(void* p,u8 sn)
{                                
                                 
} 
void func_Setup_right_icon_up_new_5(void* p,u8 sn)
{                                
                                 
} 
void func_Setup_right_icon_up_new_6(void* p,u8 sn)
{                                
                                 
} 
void func_Setup_info_column_enter_down_new(void* p,u8 sn)
{
	func_Setup_coulumn_enter(p,sn);
}
void func_Setup_info_column_enter_down_new_1(void* p,u8 sn)
{
	func_Setup_coulumn_enter(p,sn);
}
void func_Setup_info_column_enter_down_new_2(void* p,u8 sn)
{
	func_Setup_coulumn_enter(p,sn);	
}
void func_Setup_info_column_enter_down_new_3(void* p,u8 sn)
{
	func_Setup_coulumn_enter(p,sn);
}
void func_Setup_info_column_enter_down_new_4(void* p,u8 sn)
{
	func_Setup_coulumn_enter(p,sn);
}
void func_Setup_info_column_enter_down_new_5(void* p,u8 sn)
{
	func_Setup_coulumn_enter(p,sn);
}
void func_Setup_info_column_enter_down_new_6(void* p,u8 sn)
{
	func_Setup_coulumn_enter(p,sn);
}

void func_Setup_info_column_enter_up_new(void* p,u8 sn)
{

}
void func_Setup_info_column_enter_up_new_1(void* p,u8 sn)
{                                       
                                        
}                                       
void func_Setup_info_column_enter_up_new_2(void* p,u8 sn)
{                                       
                                        
}                                       
void func_Setup_info_column_enter_up_new_3(void* p,u8 sn)
{

}
void func_Setup_info_column_enter_up_new_4(void* p,u8 sn)
{

}
void func_Setup_info_column_enter_up_new_5(void* p,u8 sn)
{

}
void func_Setup_info_column_enter_up_new_6(void* p,u8 sn)
{

}
void func_Setup_save_and_back_new(void* p,u8 sn)
{
}

void func_Setup_save_and_back_new_down(void* p,u8 sn)//返回
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;//
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		setup_p = &setup_page_sta.now_p[0];//页面指针
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_SETUP2)//判断当前作用页面
		{
			if(setup_p->father_p!=empty_father_p)	
			{
				if(last_show_page_level>0)
					last_show_page_level--;
				setup_page_sta.now_page_num = last_show_page_num[last_show_page_level] ;
				f_system_Date_Time_set = FALSE;
				//setup_page_sta.now_page_num=last_now_page_num;
				if(setup_page_sta.now_p == Data_Time)//退出时间设置页，时间设置立即生效
				{
					memcpy(&time_return_status,&time_status,sizeof(TIME_STATUS));// 将当前编辑的 time_status 保存回 time_return_status
				  send_FlC200_time_set_cmd();// 向 FLC200 主控发送时间更新命令
				}
				setup_page_sta.now_p = setup_p->father_p;
		    page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
		    f_display_set_info = TRUE;       // 触发显示刷新
			}
		}
		p1->item[SN].now_status=STATUS_IDLE;
	}
    
    
    
//    //刷下栏
//    lcd_dis_item_t *p3;//,*p2;
//   p3 = &t_new_Light_up_5;
//     png_dis_xy(p3->x_val,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);    
//   p3 = &t_new_Elevator_up_5;
//     png_dis_xy(p3->x_val,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);    
//   p3 = &t_new_Halo_up_5;
//     png_dis_xy(p3->x_val,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);    
//   p3 = &t_new_heater_up_5;
//     png_dis_xy(p3->x_val,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);    
//   p3 = &t_new_AC_up_5;
//     png_dis_xy(p3->x_val,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);    
//    //刷当前下栏
//     p3 = &t_new_Setup_d__5;
//   png_dis_xy(p3->x_val,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);    

    
    
}
void func_Setup_page_next_down_new(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_SETUP2)
		{
			if((setup_page_sta.now_page_num+1)*setup_page_display_num<setup_page_sta.max_page_num)
			{
				//Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(0,392,800,88,ARGB_clear);
				//page_home.page_top_side[page_home.page_left_side.now_item].item[3].last_status= STATUS_IDLE;
				setup_page_sta.now_page_num+=1;
				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
				f_display_set_info = TRUE;
			}
		}
	}
}



void func_Setup_page_next_up_new(void* p,u8 sn)
{

}



void func_Setup_page_pre_down_new(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_SETUP2)
		{
			//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			{
				if(setup_page_sta.now_page_num)
				{
					//Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(0,392,800,88,ARGB_clear);
					//page_home.page_top_side[page_home.page_left_side.now_item].item[3].last_status= STATUS_IDLE;
					setup_page_sta.now_page_num--;
					page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
					f_display_set_info = TRUE;
				}
			}
		}
	}
}



void func_Setup_page_pre_up_new(void* p,u8 sn)
{

}

void func_Setup_info_column_upgrade_button(void* p,u8 sn)
{

}



void func_Setup_info_column_upgrade_page(void* p,u8 sn)
{

}

void func_Setup_info_column_upgrade_button_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		send_FlC200_base_set_cmd(0x88,0x01,0);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		func_set_upgrade_open_key_type(KEY_TYPE_TOUCH_NONE);
		func_set_upgrade_close_key_type(KEY_TYPE_ONCE);
	  //set_dialog_info_start_key_type(KEY_TYPE_TOUCH_NONE);
    //set_dialog_info_close_key_type(KEY_TYPE_ONCE);
	}
}



void func_Setup_info_column_upgrade_close(void* p,u8 sn)
{	
    u8 SN = sn;//图标在当前页面列表的序号
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;

      sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
      sysprintf("func_Setup_info_column_upgrade_close\r\n");
               
}

void func_Alarm_bk(void* p,u8 sn)
{

}


void fun_Alarm_bk_close(void* p,u8 sn)
{
    


}






void func_Setup_info_column_upgrade_close_d(void* p,u8 sn)
{
	u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_info();
		send_FlC200_base_set_cmd(0x88,0xFF,0);
		f_ui_disply_dialog_info_5 = FALSE;
	}
}

