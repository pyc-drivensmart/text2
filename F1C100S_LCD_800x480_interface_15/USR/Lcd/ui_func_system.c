#include "includes.h"

void func_system_btn(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  

	

		 setup_p = &setup_page.now_p[setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_ITEM_1_OFFSET];
		if((setup_p->setup_menu_touch_type!=TOUCH_TYPE_NORMAL)&&(setup_p->setup_menu_touch_type!=TOUCH_TYPE_KEYBOARD))
		{
		 last_now_page_num = setup_page.now_page_num;
		 setup_page.now_page_num = 0;
		 setup_page.now_p = setup_p->son_p;
		 page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
		 f_display_set_info = TRUE;
		}
		if(*setup_p->f!=empty_fun)
			  (*setup_p->f)(setup_p,SN,TO_DEAL);	
     //(*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_ITEM_1_OFFSET,TO_DOWN);	
    p1->item[SN].now_status=STATUS_IDLE;
		p1->item[SN].now_status=STATUS_IDLE;
 }
}

void func_system_btn1_d(void* p,u8 sn)
{
	func_system_btn(p,sn);

}



void func_system_btn1_u(void* p,u8 sn)
{

}



void func_system_btn2_d(void* p,u8 sn)
{
	func_system_btn(p,sn);
}



void func_system_btn2_u(void* p,u8 sn)
{

}



void func_system_btn3_d(void* p,u8 sn)
{
	func_system_btn(p,sn);
}



void func_system_btn3_u(void* p,u8 sn)
{

}



void func_system_btn4_d(void* p,u8 sn)
{
  func_system_btn(p,sn);
}



void func_system_btn4_u(void* p,u8 sn)
{

}



void func_system_b_system_d(void* p,u8 sn)
{

}



void func_system_b_system_u(void* p,u8 sn)
{

}



void func_system_headline(void* p,u8 sn)
{

}



void func_system_nextpage_d(void* p,u8 sn)
{
  u8 SN = 5;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_SYSTEM)
		{
			if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
				{
					setup_page.now_page_num+=1;
					page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
					f_display_set_info = TRUE;
				}
		}
	}	
}



void func_system_nextpage_o(void* p,u8 sn)
{

}



void func_system_nextpage_u(void* p,u8 sn)
{

}



void func_system_prepage_d(void* p,u8 sn)
{
  u8 SN = 6;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_SYSTEM)
		{
		    //if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
				{
					if(setup_page.now_page_num)
					{
						setup_page.now_page_num--;
						page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
					f_display_set_info = TRUE;
					}
				}
				
		
		}
	}	

}



void func_system_prepage_o(void* p,u8 sn)
{

}



void func_system_prepage_u(void* p,u8 sn)
{

}

//read me:copy the new item to 'ui_func.c'





void func_test_1_d(void* p,u8 sn)
{
 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		 //p1->item[7].now_status=STATUS_IDLE;
		 p1->item[8].now_status=STATUS_IDLE;
		 p1->item[9].now_status=STATUS_IDLE;
		 p1->item[10].now_status=STATUS_IDLE;
		 p1->item[11].now_status=STATUS_IDLE;
		
		 send_FlC200_test_cmd(1);
	}
}



void func_test_1_u(void* p,u8 sn)
{

}



void func_test_2_d(void* p,u8 sn)
{
 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		 p1->item[7].now_status=STATUS_IDLE;
		 //p1->item[8].now_status=STATUS_IDLE;
		 p1->item[9].now_status=STATUS_IDLE;
		 p1->item[10].now_status=STATUS_IDLE;
		 p1->item[11].now_status=STATUS_IDLE;
		send_FlC200_test_cmd(2);
	}
}



void func_test_2_u(void* p,u8 sn)
{

}



void func_test_3_d(void* p,u8 sn)
{
 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		 p1->item[7].now_status=STATUS_IDLE;
		 p1->item[8].now_status=STATUS_IDLE;
		 //p1->item[9].now_status=STATUS_IDLE;
		 p1->item[10].now_status=STATUS_IDLE;
		 p1->item[11].now_status=STATUS_IDLE;
		send_FlC200_test_cmd(3);
	}
}



void func_test_3_u(void* p,u8 sn)
{

}



void func_test_4_d(void* p,u8 sn)
{
 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		 p1->item[7].now_status=STATUS_IDLE;
		 p1->item[8].now_status=STATUS_IDLE;
		 p1->item[9].now_status=STATUS_IDLE;
		 //p1->item[10].now_status=STATUS_IDLE;
		 p1->item[11].now_status=STATUS_IDLE;
		send_FlC200_test_cmd(4);
	}
}



void func_test_4_u(void* p,u8 sn)
{

}



void func_test_5_d(void* p,u8 sn)
{
 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		 p1->item[7].now_status=STATUS_IDLE;
		 p1->item[8].now_status=STATUS_IDLE;
		 p1->item[9].now_status=STATUS_IDLE;
		 p1->item[10].now_status=STATUS_IDLE;
		 //p1->item[11].now_status=STATUS_IDLE;
		send_FlC200_test_cmd(1);
	}
}



void func_test_5_u(void* p,u8 sn)
{

}



void func_system_b_alarm_d(void* p,u8 sn)
{

}



void func_system_b_alarm_u(void* p,u8 sn)
{

}




void func_set_down_d(void* p,u8 sn)
{

}

void func_set_down_u(void* p,u8 sn)
{

}



void func_set_up_d(void* p,u8 sn)
{

}

void func_set_up_u(void* p,u8 sn)
{

}
void func_set_left(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 setup_p = &setup_page.now_p[setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_LEFT_1_OFFSET];
     (*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_ITEM_1_OFFSET,TO_DOWN);	
	}
}
void func_set_right(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 setup_p = &setup_page.now_p[setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_RIGHT_1_OFFSET];
     (*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_RIGHT_1_OFFSET,TO_UP);	
	}
}
void func_set_left_d(void* p,u8 sn)
{
	func_set_left(p,sn);
}



void func_set_left_u(void* p,u8 sn)
{

}

void func_set_right_d(void* p,u8 sn)
{
  func_set_right(p,sn);
}

void func_set_right_u(void* p,u8 sn)
{

	
}
void func_set_left1_d(void* p,u8 sn)
{
	func_set_left(p,sn);
}

void func_set_left1_u(void* p,u8 sn)
{

}

void func_set_right1_d(void* p,u8 sn)
{
  func_set_right(p,sn);
}

void func_set_right1_u(void* p,u8 sn)
{

	
}
void func_set_left2_d(void* p,u8 sn)
{
	func_set_left(p,sn);
}

void func_set_left2_u(void* p,u8 sn)
{

}

void func_set_right2_d(void* p,u8 sn)
{
  func_set_right(p,sn);
}

void func_set_right2_u(void* p,u8 sn)
{

	
}

void func_set_left3_d(void* p,u8 sn)
{
	func_set_left(p,sn);
}

void func_set_left3_u(void* p,u8 sn)
{

}

void func_set_right3_d(void* p,u8 sn)
{
  func_set_right(p,sn);
}

void func_set_right3_u(void* p,u8 sn)
{

	
}

void func_set_left4_d(void* p,u8 sn)
{
	func_set_left(p,sn);
}

void func_set_left4_u(void* p,u8 sn)
{

}

void func_set_right4_d(void* p,u8 sn)
{
  func_set_right(p,sn);
}

void func_system_b_back_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		setup_p = &setup_page.now_p[0];
		if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_SYSTEM)
		{
		    //if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			  if(setup_p->father_p!=empty_father_p)	
				{
					//setup_page.now_page_num = 0;
					f_system_Date_Time_set = FALSE;
					setup_page.now_page_num=last_now_page_num;
		      setup_page.now_p = setup_p->father_p;
		      page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
		      f_display_set_info = TRUE;
				}
		}
	}

}
void func_system_b_back_u(void* p,u8 sn)
{

	
}

void func_system_b_btn2(void* p,u8 sn)
{

	
}

void func_system_b_btn3(void* p,u8 sn)
{

	
}

void func_system_b_acc_d(void* p,u8 sn)
{

	
}
void func_system_b_acc_u(void* p,u8 sn)
{

	
}
void func_system_b_info_d(void* p,u8 sn)
{

	
}
void func_system_b_info_u(void* p,u8 sn)
{

	
}

void func_set_right4_u(void* p,u8 sn)
{

	
}

