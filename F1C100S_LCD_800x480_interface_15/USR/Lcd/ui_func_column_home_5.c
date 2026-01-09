#include "includes.h"


//new

//

void func_home_batt_bg_black_5(void* p,u8 sn)
{

}



void func_home_batt_bg_white_5(void* p,u8 sn)
{

}



void func_home_batt_info_column_5(void* p,u8 sn)
{

}



void func_home_batt_soc_5(void* p,u8 sn)
{

}



void func_home_bg_ac_down_5(void* p,u8 sn)
{

}



void func_home_bg_ac_up_5(void* p,u8 sn)
{

}



void func_home_bg_dc_down_5(void* p,u8 sn)
{

}



void func_home_bg_dc_up_5(void* p,u8 sn)
{

}



void func_home_bg_sc_down_5(void* p,u8 sn)
{

}



void func_home_bg_sc_up_5(void* p,u8 sn)
{

}



void func_home_bt_in_mode_down_5(void* p,u8 sn)
{

}



void func_home_bt_in_mode_up_5(void* p,u8 sn)
{

}



void func_home_bt_out_mode_down_5(void* p,u8 sn)
{

}



void func_home_bt_out_mode_up_5(void* p,u8 sn)
{

}



void func_home_bt_pet_mode_down_5(void* p,u8 sn)
{

}



void func_home_bt_pet_mode_up_5(void* p,u8 sn)
{

}



void func_home_bt_sleep_mode_down_5(void* p,u8 sn)
{

}



void func_home_bt_sleep_mode_up_5(void* p,u8 sn)
{

}



void func_home_logo_ac_5(void* p,u8 sn)
{

}

void func_home_logo_dc_5(void* p,u8 sn)
{

}
void func_home_logo_sc_5(void* p,u8 sn)
{

}
//////new_5_cun/////////////////////////////////////////////////////////////////


//
/**
 * 首页触摸事件处理函数（回调函数）
 * 功能：响应首页子项（如按钮、图标）的触摸选中操作，根据子项配置执行进入子菜单或调用自定义功能
 * @param p：传入的页面结构体指针（需转换为lcd_dis_page_t类型操作当前页面）
 * @param sn：触摸选中的子项索引（当前页面中的序号）
 */
void func_home_touch_handle(void* p,u8 sn)
{
	u8 SN = sn;  // 保存触摸子项的索引（当前页面中的序号，提升代码可读性）
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;  // 将void*转换为页面结构体指针，用于访问当前页面属性
	setup_item_info_t *home_p;  // 指向子项配置信息的指针（存储触摸类型、子菜单、关联函数等）
	
	// 判断当前触摸的子项是否处于"选中状态"（仅处理有效触摸事件，如确认按下）
	if(p1->item[SN].now_status == STATUS_SELECT)
	{
		// 根据子项索引获取对应的配置信息（now_p是当前页面的子项配置数组）
		home_p = &home_page_sta.now_p[SN];
		
		// 若子项的触摸类型为"进入子菜单"（TOUCH_TYPE_ENTER），执行页面跳转逻辑
		if(home_p->setup_menu_touch_type == TOUCH_TYPE_ENTER)
		{
			// 保存当前页面编号到页面栈（用于后续返回上一级页面）
			power_last_show_page_num[power_last_show_page_level] = home_page_sta.now_page_num;
			power_last_show_page_level++;  // 页面栈层级+1（进入下一级菜单）
			
			// 初始化子菜单页面：页码设为0（子菜单首页），配置指针切换到子菜单的配置数组
			home_page_sta.now_page_num = 0;
			home_page_sta.now_p = home_p->son_p;  // son_p指向当前子项关联的子菜单配置
			
			// 更新顶部导航栏状态：左侧首页的顶部页面"上一个选中项"设为TOP_SIDE_ICO_NUM_5
			// （推测是子菜单对应的顶部图标索引，用于同步导航状态）
			page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item = TOP_SIDE_ICO_NUM_5;
			
			// 设置首页信息刷新标志，通知UI模块重新绘制页面（加载子菜单界面）
			f_display_home_mes_info = TRUE;
			
			// 根据新的首页状态，更新子项的按键交互类型（适配子菜单的触摸逻辑）
			set_home_display_item_key_type(&home_page_sta, home_5_chun_item);
		}
		
		// 若当前子项关联了自定义函数（且不是空函数），则调用该函数执行具体功能
		// home_p->f是函数指针，empty_fun是空函数标记（表示无自定义逻辑）
		if(*home_p->f != empty_fun)
			(*home_p->f)(home_p, SN, TO_DEAL);  // 传入参数：配置指针、子项索引、处理类型（TO_DEAL表示执行处理）
		
		// 触摸事件处理完成后，将子项状态重置为"空闲"（STATUS_IDLE）
		// 避免重复响应同一触摸操作，确保下次触摸可正常触发
		p1->item[SN].now_status = STATUS_IDLE;
	}
}







/**
 * 首页栏目进入处理函数（触摸事件回调）
 * 功能：响应首页特定栏目的触摸选中事件，根据配置进入子菜单或执行关联功能
 * @param p：传入的页面结构体指针（需转换为lcd_dis_page_t类型操作当前页面）
 * @param sn：触摸选中的子项索引（当前页面中的序号）
 */
void func_home_coulumn_enter(void* p,u8 sn)
{
	u8 SN = sn;  // 保存触摸子项的索引（当前页面中的序号，提升代码可读性）
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;  // 将void*转换为页面结构体指针，用于访问当前页面属性
	setup_item_info_t *home_p;  // 指向子项配置信息的指针（存储触摸类型、子菜单、关联函数等）
	
	// 判断当前触摸的子项是否处于"选中状态"（仅处理有效选中事件）
	if(p1->item[SN].now_status == STATUS_SELECT)
	{
		// 根据当前页面编号和子项索引，计算并获取对应的子项配置信息
		// 公式说明：home_page_sta.now_page_num*6 表示当前页面前面所有页的子项总数（假设每页6个）
		// SN-6 表示当前子项在全局列表中的偏移（推测当前页面是从第6个开始的子项）
		home_p = &home_page_sta.now_p[home_page_sta.now_page_num * 6 + SN - 6];
		
		// 判断子项的触摸类型：若不是"普通触摸"（TOUCH_TYPE_NORMAL）和"键盘输入"（TOUCH_TYPE_KEYBOARD）
		// 则认为是"进入子菜单"类型，执行页面跳转逻辑
		if((home_p->setup_menu_touch_type != TOUCH_TYPE_NORMAL) && 
		   (home_p->setup_menu_touch_type != TOUCH_TYPE_KEYBOARD))
		{
			// 保存当前页面编号到页面栈，用于后续返回上一级页面
			power_last_show_page_num[power_last_show_page_level] = home_page_sta.now_page_num;
			power_last_show_page_level++;  // 页面栈层级+1（进入下一级）
			
			// 初始化子菜单页面：页码设为0（子菜单首页），配置指针切换到子菜单的配置数组
			home_page_sta.now_page_num = 0;
			home_page_sta.now_p = home_p->son_p;  // son_p指向当前子项关联的子菜单配置
			
			// 更新顶部导航栏状态：左侧首页的顶部页面"上一个选中项"设为TOP_SIDE_ICO_NUM_5
			// （推测是子菜单对应的顶部图标索引，用于同步导航状态）
			page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item = TOP_SIDE_ICO_NUM_5;
			
			// 设置首页信息刷新标志，通知UI模块重新绘制页面（加载子菜单界面）
			f_display_home_mes_info = TRUE;
		}
		// 若当前子项关联了自定义函数（且不是空函数），则调用该函数执行具体功能
		// home_p->f是函数指针，empty_fun是空函数标记（表示无自定义逻辑）
		if(*home_p->f != empty_fun)
			(*home_p->f)(home_p, SN, TO_DEAL);  // 传入参数：配置指针、子项索引、处理类型（TO_DEAL表示执行处理）
		
    // 触摸事件处理完成后，将子项状态重置为"空闲"（STATUS_IDLE）
    // 避免重复响应同一触摸操作，确保下次触摸可正常触发
		p1->item[SN].now_status = STATUS_IDLE;
	}
}

void func_home_batt_bg_black_5_new(void* p,u8 sn)
{
	func_home_touch_handle(p,sn);
}



void func_home_batt_bg_blue_5_new(void* p,u8 sn)
{

}



void func_home_batt_charging_logo(void* p,u8 sn)
{

}



void func_home_batt_info_column_5_new(void* p,u8 sn)
{

}



void func_home_batt_soc_val_5_new(void* p,u8 sn)
{

}



void func_home_bg_ac_down_5_new(void* p,u8 sn)
{
	func_home_touch_handle(p,sn);
}



void func_home_bg_ac_up_5_new(void* p,u8 sn)
{

}



void func_home_bg_dc_down_5_new(void* p,u8 sn)
{
	func_home_touch_handle(p,sn);
}



void func_home_bg_dc_up_5_new(void* p,u8 sn)
{

}



void func_home_bg_sc_down_5_new(void* p,u8 sn)
{
	func_home_touch_handle(p,sn);
}



void func_home_bg_sc_up_5_new(void* p,u8 sn)
{

}



void func_home_page_back(void* p,u8 sn)
{
}

void func_home_page_back_down(void* p,u8 sn)
{
	u8 SN = sn;
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *home_p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		home_p = &home_page_sta.now_p[0];
		if(home_p->father_p != empty_father_p)
		{
			if(power_last_show_page_level>0)
				power_last_show_page_level--;
			home_page_sta.now_page_num = power_last_show_page_num[power_last_show_page_level];
			home_page_sta.now_p = home_p->father_p;
			page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新 
			f_display_home_mes_info = TRUE;
			//set_home_display_item_key_type(&home_page_sta);
		}
		if(*home_p->f!=empty_fun)
			(*home_p->f)(home_p,SN,TO_DEAL);	
		p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_home_page_enter_down_1(void* p,u8 sn)
{
	func_home_coulumn_enter(p,sn);
}
void func_home_page_enter_down_2(void* p,u8 sn)
{
	func_home_coulumn_enter(p,sn);
}
void func_home_page_enter_down_3(void* p,u8 sn)
{
	func_home_coulumn_enter(p,sn);
}
void func_home_page_enter_down_4(void* p,u8 sn)
{
	func_home_coulumn_enter(p,sn);
}
void func_home_page_enter_down_5(void* p,u8 sn)
{
	func_home_coulumn_enter(p,sn);
}
void func_home_page_enter_down_6(void* p,u8 sn)
{
	func_home_coulumn_enter(p,sn);
}


void func_home_page_enter_up_1(void* p,u8 sn)
{                             
                              
}                             
void func_home_page_enter_up_2(void* p,u8 sn)
{                             
                              
}                             
void func_home_page_enter_up_3(void* p,u8 sn)
{                             
                              
}                             
void func_home_page_enter_up_4(void* p,u8 sn)
{                             
                              
}                             
void func_home_page_enter_up_5(void* p,u8 sn)
{

}
void func_home_page_enter_up_6(void* p,u8 sn)
{

}

void func_home_page_info_1(void* p,u8 sn)
{                         
                          
}                         
void func_home_page_info_2(void* p,u8 sn)
{                         
                          
}                         
void func_home_page_info_3(void* p,u8 sn)
{                         
                          
}                         
void func_home_page_info_4(void* p,u8 sn)
{                         
                          
}                         
void func_home_page_info_5(void* p,u8 sn)
{

}
void func_home_page_info_6(void* p,u8 sn)
{

}

void func_home_page_next_down_new(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_HOME)
		{
			if((home_page_sta.now_page_num+1)*6<home_page_sta.max_page_num)
			{
				home_page_sta.now_page_num+=1;
				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
				f_display_home_mes_info = TRUE;
			}
		}
	}
}

void func_home_page_next_up_new(void* p,u8 sn)
{
	
}

void func_home_page_pre_down_new(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_HOME)
		{
			//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			{
				if(home_page_sta.now_page_num)
				{
					home_page_sta.now_page_num--;
					page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
					f_display_home_mes_info = TRUE;
				}
			}
		}
	}
}

void func_home_page_pre_up_new(void* p,u8 sn)
{

}

