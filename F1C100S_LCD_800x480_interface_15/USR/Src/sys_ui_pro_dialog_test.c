#include "includes.h"



u32 v_ui_need_out_dialog_test_cnt = 0;
bool f_ui_disply_dialog_test = FALSE;
bool f_ui_need_disply_dialog_test = FALSE;

	
u8 dialog_testout_cnt[5] = {0,0,0,0,0};

void dialog_testout_cnt_pro(u8 ch)
{
	u8 i;
	return;
	dialog_testout_cnt[ch]++;
	if(dialog_testout_cnt[ch]==5)
	{
		for(i=0;i<5;i++)
		{
			dialog_testout_cnt[i]=0;
		}
		ui_out_dialog_test();
	}
	for(i=0;i<5;i++)
	{
		if(i!=ch)
	  dialog_testout_cnt[i]=0;
	}
}


void func_test_touch1_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t* p2;
	u8 j;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		p2 = &page_home.page_top_side[0];
		//p2->now_item =0;
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff1,ARGB_black);
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff0,ARGB_black);
		f_need_LCD_Upgrate = TRUE;
		Virtual_LCD_Upgrate();
		dialog_testout_cnt_pro(0);
	}
}	
void func_test_touch2_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t* p2;
	u8 j;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		p2 = &page_home.page_top_side[0];
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff1,ARGB_white);
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff0,ARGB_white);
		f_need_LCD_Upgrate = TRUE;
		Virtual_LCD_Upgrate();
		dialog_testout_cnt_pro(1);
	}
}	
void func_test_touch3_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t* p2;
	u8 j;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		p2 = &page_home.page_top_side[0];
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff1,ARGB_red);
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff0,ARGB_red);
		f_need_LCD_Upgrate = TRUE;
		Virtual_LCD_Upgrate();
		dialog_testout_cnt_pro(2);
	}
}	
void func_test_touch4_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t* p2;
	u8 j;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		p2 = &page_home.page_top_side[0];
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff1,ARGB_green);
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff0,ARGB_green);
		f_need_LCD_Upgrate = TRUE;
		Virtual_LCD_Upgrate();
		dialog_testout_cnt_pro(3);
	}
}	
void func_test_touch5_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	lcd_dis_page_t* p2;
	u8 j;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
		p2 = &page_home.page_top_side[0];
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff1,ARGB_blue);
		Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff0,ARGB_blue);
		f_need_LCD_Upgrate = TRUE;
		Virtual_LCD_Upgrate();
		dialog_testout_cnt_pro(4);
	}
}
lcd_dis_item_t t_test_touch1_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_test_touch1_d,Y_test_touch1_d,X_test_touch1_d+test_touch_offset,Y_test_touch1_d+test_touch_offset,0,&func_test_touch1_d};	
lcd_dis_item_t t_test_touch2_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_test_touch2_d,Y_test_touch2_d,X_test_touch2_d+test_touch_offset,Y_test_touch2_d+test_touch_offset,0,&func_test_touch2_d};	
lcd_dis_item_t t_test_touch3_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_test_touch3_d,Y_test_touch3_d,X_test_touch3_d+test_touch_offset,Y_test_touch3_d+test_touch_offset,0,&func_test_touch3_d};	
lcd_dis_item_t t_test_touch4_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_test_touch4_d,Y_test_touch4_d,X_test_touch4_d+test_touch_offset,Y_test_touch4_d+test_touch_offset,0,&func_test_touch4_d};	
lcd_dis_item_t t_test_touch5_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_test_touch5_d,Y_test_touch5_d,X_test_touch5_d+test_touch_offset,Y_test_touch5_d+test_touch_offset,0,&func_test_touch5_d};	

lcd_dis_item_t *p_test_item_d[TEST_ITEM_NUM]=
{
	&t_test_touch1_d,
	&t_test_touch2_d,
	&t_test_touch3_d,
	&t_test_touch4_d,
	&t_test_touch5_d,
};
lcd_dis_item_t *p_test_item_u[TEST_ITEM_NUM]=
{
	&t_test_touch1_d,
	&t_test_touch2_d,
	&t_test_touch3_d,
	&t_test_touch4_d,
	&t_test_touch5_d,
};	

lcd_dis_item_t test_item_arr[TEST_ITEM_NUM];

BOOL page_dialog_test_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
	return FALSE;
}


bool f_last_ui_disply_keyboard_test = FALSE;
void ui_out_dialog_test(void)
{
    //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
		//page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//??μ?ê??￠D?ò3??
	if(f_last_ui_disply_keyboard_test)
	{
	  Virtual_LCD_Draw_Rectangle_ARGB32(0,0,800,480,Virtual_LCDbuff1,ARGB_clear);
	  Virtual_LCD_Draw_Rectangle_ARGB32(0,0,800,480,Virtual_LCDbuff2,ARGB_clear);
		f_last_ui_disply_keyboard_test = FALSE;
	}
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
	f_ui_disply_dialog_test = FALSE;
	//reset_dis_page_item();
}
/*void set_v_ui_need_out_dialog_test_cnt(void)
{
  v_ui_need_out_dialog_test_cnt = 500;

}
void rest_v_ui_need_out_dialog_test_cnt(void)
{
  v_ui_need_out_dialog_test_cnt = 0;

}
void check_ui_out_dialog_test(void)
{
  if(v_ui_need_out_dialog_test_cnt)
	{
		v_ui_need_out_dialog_test_cnt--;
		if(v_ui_need_out_dialog_test_cnt ==0)
			ui_out_dialog_test();
	}
}*/
void disply_tset_touch(bool upgrade)
{
  static u16 cnt = 0; 
	static bool dis_flag = FALSE;
	lcd_dis_item_t *p;


	if((upgrade))
	{
	  p = &t_test_touch1_d;
		Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_black,0,1,1);		
		
		p = &t_test_touch2_d;
		Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_white,0,1,1);
		
		p = &t_test_touch3_d;
		Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_red,0,1,1);
	
		p = &t_test_touch4_d;
		Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_green,0,1,1);
		
		p = &t_test_touch5_d;
		Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_blue,0,1,1);
		
		Virtual_LCD_Upgrate();
	}
	else
	{
		cnt++;
		if(cnt>=100)
		{
			dis_flag = !dis_flag;
			cnt = 0;
			//sysprintf("88888888888888888888888 %d",dis_flag);
			if(dis_flag)
			{
				p = &t_test_touch1_d;
				Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_black,0,1,1);		
				
				p = &t_test_touch2_d;
				Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_white,0,1,1);
				
				p = &t_test_touch3_d;
				Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_red,0,1,1);
				
				p = &t_test_touch4_d;
				Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_green,0,1,1);
				
				p = &t_test_touch5_d;
				Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val,p->y_val,"O",ARGB_blue,0,1,1);
			}
			else
			{
				Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff2,ARGB_clear);
			}
			f_need_LCD_Upgrate = TRUE;
			Virtual_LCD_Upgrate();
		}
	}
}
void ui_disply_dialog_test(void)
{
	lcd_dis_page_t *p;
	//lcd_dis_item_t *p1;
	u8 i;//,ch;


	//char display_buf[64];
	
	if(f_ui_disply_keyboard)
	{
	  f_ui_disply_keyboard = FALSE;
		f_ui_out_keyboard = FALSE;
	}
	
	f_ui_disply_dialog_lights=FALSE;
	f_ui_disply_dialog_loads=FALSE;
	f_ui_disply_dialog_lights_ch=FALSE;
	f_ui_disply_dialog_loads_ch=FALSE;
	f_ui_disply_dialog_motors=FALSE;
	out_from_long_touch_status();
	//f_system_accessories_External_Key_Type = FALSE;
	//f_system_Date_Time_set = FALSE;
	//f_ui_disply_dialog_info=FALSE;
	
	
	p = &page_home.page_dialog_test;	
	Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val,p->item[0].y_val,p->item[0].x_end_val-p->item[0].x_val,p->item[0].y_end_val-p->item[0].y_val,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_dialog_test = TRUE;
	
	Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff1,ARGB_black);
	Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff0,ARGB_black);
	Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff2,ARGB_clear);
	disply_tset_touch(TRUE);
	
	//for(i=0;i<p->item_num;i++)
	//{
	//	if(p->item[i].now_status==STATUS_SELECT)	
	//		png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
	//	else
	//		png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	//}
	
	
	//disply_tset_touch(TRUE);
	
	
	Virtual_LCD_Upgrate();
}

void ui_dialog_test_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_dialog_test;
	
	p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=800;
	p->y_end_val=480;
	p->item_num=TEST_ITEM_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	
	p->item = test_item_arr;
	for(i=0;i<TEST_ITEM_NUM;i++)
	{
		memcpy(&(p->item[i]),p_test_item_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_test_item_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_test_item_u[i]->size_of_pic_item ;
	}
	
	f_ui_disply_dialog_test = FALSE;
 }

