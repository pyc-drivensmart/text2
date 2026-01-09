#include "includes.h"

//read me:copy the new item to 'ui_func.c'



void func_tanks_setup_btn(void* p,u8 sn)
{
		u8 SN = sn;//图标在当前页面列表的序号
			lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
			setup_item_info_t *setup_p;
			if(p1->item[SN].now_status==STATUS_SELECT)
			{  

			

				 setup_p = &tanks_setup_page.now_p[tanks_setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_ITEM_1_OFFSET];
				if((setup_p->setup_menu_touch_type!=TOUCH_TYPE_NORMAL)&&(setup_p->setup_menu_touch_type!=TOUCH_TYPE_KEYBOARD))
				{
				 last_now_page_num = tanks_setup_page.now_page_num;
				 tanks_setup_page.now_page_num = 0;
				 tanks_setup_page.now_p = setup_p->son_p;
				 page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].last_item=TOP_SIDE_PAGE_TANKS_MUN;//更新
				 f_display_tanks_setup_info = TRUE;
				}
				if(*setup_p->f!=empty_fun)
						(*setup_p->f)(setup_p,SN,TO_DEAL);	
				 //(*setup_p->f)(setup_p,sn-system_setup_LEFT_1_OFFSET+system_setup_ITEM_1_OFFSET,TO_DOWN);	
				
        p1->item[SN].now_status=STATUS_IDLE;
				p1->item[SN].now_status=STATUS_IDLE;
		 }


}



void func_tanks_setup_btn1_d(void* p,u8 sn)
{
	 func_tanks_setup_btn(p,sn);

}



void func_tanks_setup_btn1_u(void* p,u8 sn)
{

}



void func_tanks_setup_btn2_d(void* p,u8 sn)
{
	func_tanks_setup_btn(p,sn);
}



void func_tanks_setup_btn2_u(void* p,u8 sn)
{

}



void func_tanks_setup_btn3_d(void* p,u8 sn)
{
	
	 func_tanks_setup_btn(p,sn);
}



void func_tanks_setup_btn3_u(void* p,u8 sn)
{

}



void func_tanks_setup_btn4_d(void* p,u8 sn)
{
  func_tanks_setup_btn(p,sn);
}



void func_tanks_setup_btn4_u(void* p,u8 sn)
{

}



void func_tanks_setup_b_tanks_setup_d(void* p,u8 sn)
{

}



void func_tanks_setup_b_tanks_setup_u(void* p,u8 sn)
{

}



void func_tanks_setup_headline(void* p,u8 sn)
{

}



void func_tanks_setup_nextpage_d(void* p,u8 sn)
{
  u8 SN = 5;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_TANKS)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].now_item==TOP_SIDE_PAGE_TANKS_SETUP)
		{
		    if((tanks_setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<tanks_setup_page.max_page_num)
				{
					tanks_setup_page.now_page_num+=1;
					page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].last_item=TOP_SIDE_PAGE_TANKS_MUN;//更新
					f_display_tanks_setup_info = TRUE;
				}
				
		
		}
	}
	

}



void func_tanks_setup_nextpage_o(void* p,u8 sn)
{

}



void func_tanks_setup_nextpage_u(void* p,u8 sn)
{

}



void func_tanks_setup_prepage_d(void* p,u8 sn)
{
  u8 SN = 6;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_TANKS)
		if(page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].now_item==TOP_SIDE_PAGE_TANKS_SETUP)
		{
		    //if((tanks_setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<tanks_setup_page.max_page_num)
				{
					if(tanks_setup_page.now_page_num)
					{
						tanks_setup_page.now_page_num--;
						page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].last_item=TOP_SIDE_PAGE_TANKS_MUN;//更新
					f_display_tanks_setup_info = TRUE;
					}
				}
				
		
		}
	}
	

}



void func_tanks_setup_prepage_o(void* p,u8 sn)
{

}



void func_tanks_setup_prepage_u(void* p,u8 sn)
{

}

//read me:copy the new item to 'ui_func.c'







void func_tanks_setup_b_alarm_d(void* p,u8 sn)
{

}



void func_tanks_setup_b_alarm_u(void* p,u8 sn)
{

}

void func_tanks_setup_down_d(void* p,u8 sn)
{

}

void func_tanks_setup_down_u(void* p,u8 sn)
{

}



void func_tanks_setup_up_d(void* p,u8 sn)
{

}

void func_tanks_setup_up_u(void* p,u8 sn)
{

}


void func_tanks_setup_left(void* p,u8 sn)
{
	 u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 setup_p = &tanks_setup_page.now_p[tanks_setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_LEFT_1_OFFSET];
     (*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_ITEM_1_OFFSET,TO_DOWN);	
	}
}
void func_tanks_setup_right(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 setup_p = &tanks_setup_page.now_p[tanks_setup_page.now_page_num*PAGE_DISPLAY_ITEM_NUM+sn-SYSTEM_RIGHT_1_OFFSET];
     (*setup_p->f)(setup_p,sn-SYSTEM_LEFT_1_OFFSET+SYSTEM_RIGHT_1_OFFSET,TO_UP);	
	}
}


void func_tanks_setup_left_d(void* p,u8 sn)
{

	func_tanks_setup_left(p,sn);
}

void func_tanks_setup_left_u(void* p,u8 sn)
{

}

void func_tanks_setup_right_d(void* p,u8 sn)
{
   func_tanks_setup_right(p,sn);
}

void func_tanks_setup_right_u(void* p,u8 sn)
{

	
}

void func_tanks_setup_left2_d(void* p,u8 sn)
{
	func_tanks_setup_left(p,sn);
}

void func_tanks_setup_left2_u(void* p,u8 sn)
{

}

void func_tanks_setup_right2_d(void* p,u8 sn)
{
 func_tanks_setup_right(p,sn);
}

void func_tanks_setup_right2_u(void* p,u8 sn)
{

	
}

void func_tanks_setup_left3_d(void* p,u8 sn)
{
	func_tanks_setup_left(p,sn);
}

void func_tanks_setup_left3_u(void* p,u8 sn)
{

}

void func_tanks_setup_right3_d(void* p,u8 sn)
{
 func_tanks_setup_right(p,sn);
}

void func_tanks_setup_right3_u(void* p,u8 sn)
{

	
}

void func_tanks_setup_left4_d(void* p,u8 sn)
{
	 func_tanks_setup_left(p,sn);
}

void func_tanks_setup_left4_u(void* p,u8 sn)
{

}

void func_tanks_setup_right4_d(void* p,u8 sn)
{
  func_tanks_setup_right(p,sn);
}

void func_tanks_setup_b_back_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	setup_item_info_t *setup_p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		setup_p = &tanks_setup_page.now_p[0];
		if(page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].now_item==TOP_SIDE_PAGE_TANKS_SETUP)
		{
		    //if((tanks_setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<tanks_setup_page.max_page_num)
			  if(setup_p->father_p!=empty_father_p)	
				{
					//tanks_setup_page.now_page_num = 0;
					//f_tanks_setup_External_Key_Type = FALSE;
					tanks_setup_page.now_page_num=last_now_page_num;
		      tanks_setup_page.now_p = setup_p->father_p;
		      page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].last_item=TOP_SIDE_PAGE_TANKS_MUN;//更新
		      f_display_tanks_setup_info = TRUE;
				}
				
		
		}
	}

}
void func_tanks_setup_b_back_u(void* p,u8 sn)
{

	
}

void func_tanks_setup_b_btn2(void* p,u8 sn)
{

	
}

void func_tanks_setup_b_btn3(void* p,u8 sn)
{

	
}
void func_tanks_setup_right4_u(void* p,u8 sn)
{

	
}





