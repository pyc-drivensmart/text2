#include "includes.h"

void func_system_accessories_btn(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  

	

		 setup_p = &accessories_page.now_p[setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_ITEM_1_OFFSET];
		if((setup_p->setup_menu_touch_type!=TOUCH_TYPE_NORMAL)&&(setup_p->setup_menu_touch_type!=TOUCH_TYPE_KEYBOARD))
		{
		 last_now_page_num = accessories_page.now_page_num;
		 accessories_page.now_page_num = 0;
		 accessories_page.now_p = setup_p->son_p;
		 page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
		 f_display_set_accessories_info = TRUE;
		}
		if(*setup_p->f!=empty_fun)
			  (*setup_p->f)(setup_p,SN,TO_DEAL);	
     //(*setup_p->f)(setup_p,sn-system_accessories_LEFT_1_OFFSET+system_accessories_ITEM_1_OFFSET,TO_DOWN);	
    p1->item[SN].now_status=STATUS_IDLE;
		p1->item[SN].now_status=STATUS_IDLE;
 }


}

void func_system_accessories_btn1_d(void* p,u8 sn)
{
	func_system_accessories_btn(p,sn);


}



void func_system_accessories_btn1_u(void* p,u8 sn)
{

}



void func_system_accessories_btn2_d(void* p,u8 sn)
{
	func_system_accessories_btn(p,sn);
}



void func_system_accessories_btn2_u(void* p,u8 sn)
{

}



void func_system_accessories_btn3_d(void* p,u8 sn)
{
	func_system_accessories_btn(p,sn);

}



void func_system_accessories_btn3_u(void* p,u8 sn)
{

}



void func_system_accessories_btn4_d(void* p,u8 sn)
{
  func_system_accessories_btn(p,sn);
}



void func_system_accessories_btn4_u(void* p,u8 sn)
{

}



void func_system_accessories_b_system_accessories_d(void* p,u8 sn)
{

}



void func_system_accessories_b_system_accessories_u(void* p,u8 sn)
{

}



void func_system_accessories_headline(void* p,u8 sn)
{

}



void func_system_accessories_nextpage_d(void* p,u8 sn)
{
  u8 SN = 5;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_ACC)
		{
		    if((accessories_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
				{
					accessories_page.now_page_num+=1;
					page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
					f_display_set_accessories_info = TRUE;
				}
				
		
		}
	}
	

}



void func_system_accessories_nextpage_o(void* p,u8 sn)
{

}



void func_system_accessories_nextpage_u(void* p,u8 sn)
{

}



void func_system_accessories_prepage_d(void* p,u8 sn)
{
  u8 SN = 6;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_ACC)
		{
		    //if((accessories_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
				{
					if(accessories_page.now_page_num)
					{
						accessories_page.now_page_num--;
						page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
					f_display_set_accessories_info = TRUE;
					}
				}
				
		
		}
	}
	

}



void func_system_accessories_prepage_o(void* p,u8 sn)
{

}



void func_system_accessories_prepage_u(void* p,u8 sn)
{

}

//read me:copy the new item to 'ui_func.c'







void func_system_accessories_b_alarm_d(void* p,u8 sn)
{

}



void func_system_accessories_b_alarm_u(void* p,u8 sn)
{

}




void func_set_accessories_down_d(void* p,u8 sn)
{

}

void func_set_accessories_down_u(void* p,u8 sn)
{

}



void func_set_accessories_up_d(void* p,u8 sn)
{

}

void func_set_accessories_up_u(void* p,u8 sn)
{

}

void func_set_accessories_left(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 setup_p = &accessories_page.now_p[setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_LEFT_1_OFFSET];
     (*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_ITEM_1_OFFSET,TO_DOWN);	
	}
}

void func_set_accessories_right(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 setup_p = &accessories_page.now_p[setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_RIGHT_1_OFFSET];
     (*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_RIGHT_1_OFFSET,TO_UP);	
	}
}

void func_set_accessories_left_d(void* p,u8 sn)
{
	 func_set_accessories_left(p,sn);
}

void func_set_accessories_left_u(void* p,u8 sn)
{

}

void func_set_accessories_right_d(void* p,u8 sn)
{
  func_set_accessories_right(p,sn);
}

void func_set_accessories_right_u(void* p,u8 sn)
{

	
}

void func_set_accessories_left2_d(void* p,u8 sn)
{
	 func_set_accessories_left(p,sn);
}

void func_set_accessories_left2_u(void* p,u8 sn)
{

}

void func_set_accessories_right2_d(void* p,u8 sn)
{
  func_set_accessories_right(p,sn);
}

void func_set_accessories_right2_u(void* p,u8 sn)
{

	
}

void func_set_accessories_left3_d(void* p,u8 sn)
{
	func_set_accessories_left(p,sn);
}

void func_set_accessories_left3_u(void* p,u8 sn)
{

}

void func_set_accessories_right3_d(void* p,u8 sn)
{
  func_set_accessories_right(p,sn);
}

void func_set_accessories_right3_u(void* p,u8 sn)
{

	
}

void func_set_accessories_left4_d(void* p,u8 sn)
{
	func_set_accessories_left(p,sn);
}

void func_set_accessories_left4_u(void* p,u8 sn)
{

}

void func_set_accessories_right4_d(void* p,u8 sn)
{
  func_set_accessories_right(p,sn);
}

void func_system_accessories_b_back_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		setup_p = &accessories_page.now_p[0];
		if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_ACC)
		{
		    //if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			  if(setup_p->father_p!=empty_father_p)	
				{
					//setup_page.now_page_num = 0;
					f_system_accessories_External_Key_Type = FALSE;
					accessories_page.now_page_num=last_now_page_num;
		      accessories_page.now_p = setup_p->father_p;
		      page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
		      f_display_set_accessories_info = TRUE;
				}
				
		
		}
	}

}
void func_system_accessories_b_back_u(void* p,u8 sn)
{

	
}

void func_system_accessories_b_btn2(void* p,u8 sn)
{

	
}

void func_system_accessories_b_btn3(void* p,u8 sn)
{

	
}
void func_set_accessories_right4_u(void* p,u8 sn)
{

	
}


