#include "includes.h"




bool f_ui_disply_dialog_lights_ch = FALSE;
u8 now_dialog_lights_ch_select_ch = 0;//当前要更改的图标序号
u8 now_dialog_lights_ch_select_num = 1;//从1开始 当前选择的通道


  extern void func_lights_setup_ch_char0_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char1_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char2_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char3_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char4_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char5_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char6_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char7_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char8_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char9_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char10_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char11_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char12_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char13_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char14_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char15_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char16_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char17_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char18_d(void* p,u8 sn);
	extern void func_lights_setup_ch_char19_d(void* p,u8 sn);
	
	
	

	
lcd_dis_item_t t_lights_setup_ch_char0_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char0,Y_lights_setup_ch_d_char0,X_lights_setup_ch_d_char0+X_INTER_SPACE,Y_lights_setup_ch_d_char0+Y_INTER_SPACE,0,&func_lights_setup_ch_char0_d};
lcd_dis_item_t t_lights_setup_ch_char1_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char1,Y_lights_setup_ch_d_char1,X_lights_setup_ch_d_char1+X_INTER_SPACE,Y_lights_setup_ch_d_char1+Y_INTER_SPACE,0,&func_lights_setup_ch_char1_d};
lcd_dis_item_t t_lights_setup_ch_char2_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char2,Y_lights_setup_ch_d_char2,X_lights_setup_ch_d_char2+X_INTER_SPACE,Y_lights_setup_ch_d_char2+Y_INTER_SPACE,0,&func_lights_setup_ch_char2_d};
lcd_dis_item_t t_lights_setup_ch_char3_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char3,Y_lights_setup_ch_d_char3,X_lights_setup_ch_d_char3+X_INTER_SPACE,Y_lights_setup_ch_d_char3+Y_INTER_SPACE,0,&func_lights_setup_ch_char3_d};
lcd_dis_item_t t_lights_setup_ch_char4_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char4,Y_lights_setup_ch_d_char4,X_lights_setup_ch_d_char4+X_INTER_SPACE,Y_lights_setup_ch_d_char4+Y_INTER_SPACE,0,&func_lights_setup_ch_char4_d};
lcd_dis_item_t t_lights_setup_ch_char5_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char5,Y_lights_setup_ch_d_char5,X_lights_setup_ch_d_char5+X_INTER_SPACE,Y_lights_setup_ch_d_char5+Y_INTER_SPACE,0,&func_lights_setup_ch_char5_d};
lcd_dis_item_t t_lights_setup_ch_char6_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char6,Y_lights_setup_ch_d_char6,X_lights_setup_ch_d_char6+X_INTER_SPACE,Y_lights_setup_ch_d_char6+Y_INTER_SPACE,0,&func_lights_setup_ch_char6_d};
lcd_dis_item_t t_lights_setup_ch_char7_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char7,Y_lights_setup_ch_d_char7,X_lights_setup_ch_d_char7+X_INTER_SPACE,Y_lights_setup_ch_d_char7+Y_INTER_SPACE,0,&func_lights_setup_ch_char7_d};
lcd_dis_item_t t_lights_setup_ch_char8_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char8,Y_lights_setup_ch_d_char8,X_lights_setup_ch_d_char8+X_INTER_SPACE,Y_lights_setup_ch_d_char8+Y_INTER_SPACE,0,&func_lights_setup_ch_char8_d};
lcd_dis_item_t t_lights_setup_ch_char9_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char9,Y_lights_setup_ch_d_char9,X_lights_setup_ch_d_char9+X_INTER_SPACE,Y_lights_setup_ch_d_char9+Y_INTER_SPACE,0,&func_lights_setup_ch_char9_d};
lcd_dis_item_t t_lights_setup_ch_char10_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char10,Y_lights_setup_ch_d_char10,X_lights_setup_ch_d_char10+X_INTER_SPACE,Y_lights_setup_ch_d_char10+Y_INTER_SPACE,0,&func_lights_setup_ch_char10_d};
lcd_dis_item_t t_lights_setup_ch_char11_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char11,Y_lights_setup_ch_d_char11,X_lights_setup_ch_d_char11+X_INTER_SPACE,Y_lights_setup_ch_d_char11+Y_INTER_SPACE,0,&func_lights_setup_ch_char11_d};
lcd_dis_item_t t_lights_setup_ch_char12_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char12,Y_lights_setup_ch_d_char12,X_lights_setup_ch_d_char12+X_INTER_SPACE,Y_lights_setup_ch_d_char12+Y_INTER_SPACE,0,&func_lights_setup_ch_char12_d};
lcd_dis_item_t t_lights_setup_ch_char13_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char13,Y_lights_setup_ch_d_char13,X_lights_setup_ch_d_char13+X_INTER_SPACE,Y_lights_setup_ch_d_char13+Y_INTER_SPACE,0,&func_lights_setup_ch_char13_d};
lcd_dis_item_t t_lights_setup_ch_char14_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char14,Y_lights_setup_ch_d_char14,X_lights_setup_ch_d_char14+X_INTER_SPACE,Y_lights_setup_ch_d_char14+Y_INTER_SPACE,0,&func_lights_setup_ch_char14_d};
lcd_dis_item_t t_lights_setup_ch_char15_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char15,Y_lights_setup_ch_d_char15,X_lights_setup_ch_d_char15+X_INTER_SPACE,Y_lights_setup_ch_d_char15+Y_INTER_SPACE,0,&func_lights_setup_ch_char15_d};
lcd_dis_item_t t_lights_setup_ch_char16_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char16,Y_lights_setup_ch_d_char16,X_lights_setup_ch_d_char16+X_INTER_SPACE,Y_lights_setup_ch_d_char16+Y_INTER_SPACE,0,&func_lights_setup_ch_char16_d};
lcd_dis_item_t t_lights_setup_ch_char17_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char17,Y_lights_setup_ch_d_char17,X_lights_setup_ch_d_char17+X_INTER_SPACE,Y_lights_setup_ch_d_char17+Y_INTER_SPACE,0,&func_lights_setup_ch_char17_d};
lcd_dis_item_t t_lights_setup_ch_char18_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char18,Y_lights_setup_ch_d_char18,X_lights_setup_ch_d_char18+X_INTER_SPACE,Y_lights_setup_ch_d_char18+Y_INTER_SPACE,0,&func_lights_setup_ch_char18_d};
lcd_dis_item_t t_lights_setup_ch_char19_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_lights_setup_ch_d_char19,Y_lights_setup_ch_d_char19,X_lights_setup_ch_d_char19+X_INTER_SPACE,Y_lights_setup_ch_d_char19+Y_INTER_SPACE,0,&func_lights_setup_ch_char19_d};

extern const unsigned char dialog_close_d[];
extern const unsigned char dialog_close_u[];
extern const unsigned char dialog_save_d[];
extern const unsigned char dialog_save_u[];
	
extern void func_dialog_close_lights_ch_d(void* p,u8 sn);
extern void func_dialog_close_lights_ch_u(void* p,u8 sn);
extern void func_dialog_save_lights_ch_d(void* p,u8 sn);
extern void func_dialog_save_lights_ch_u(void* p,u8 sn);
	
lcd_dis_item_t t_dialog_close_lights_ch_d={(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,0,0,5123,5123,5123,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_d,Y_dialog_close_d,X_dialog_close_d+230,Y_dialog_close_d+71,0,&func_dialog_close_lights_ch_d};
lcd_dis_item_t t_dialog_close_lights_ch_u={(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,0,0,4611,4611,4611,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_u,Y_dialog_close_u,X_dialog_close_u+230,Y_dialog_close_u+71,0,&func_dialog_close_lights_ch_u};
lcd_dis_item_t t_dialog_save_lights_ch_d={(unsigned char*)dialog_save_d,(unsigned char*)dialog_save_d,(unsigned char*)dialog_save_d,0,0,5014,5014,5014,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_save_d,Y_dialog_save_d,X_dialog_save_d+230,Y_dialog_save_d+71,0,&func_dialog_save_lights_ch_d};
lcd_dis_item_t t_dialog_save_lights_ch_u={(unsigned char*)dialog_save_u,(unsigned char*)dialog_save_u,(unsigned char*)dialog_save_u,0,0,4571,4571,4571,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_save_u,Y_dialog_save_u,X_dialog_save_u+230,Y_dialog_save_u+71,0,&func_dialog_save_lights_ch_u};



	//keyboard
lcd_dis_item_t *p_dialog_lights_ch_item_d[DIALOG_LIGHTS_CH_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_close_lights_ch_d,
&t_dialog_p_d,
&t_dialog_save_lights_ch_d,
	
&t_lights_setup_ch_char0_d,
&t_lights_setup_ch_char1_d,
&t_lights_setup_ch_char2_d,
&t_lights_setup_ch_char3_d,
&t_lights_setup_ch_char4_d,
&t_lights_setup_ch_char5_d,
&t_lights_setup_ch_char6_d,
&t_lights_setup_ch_char7_d,
&t_lights_setup_ch_char8_d,
&t_lights_setup_ch_char9_d,
&t_lights_setup_ch_char10_d,
&t_lights_setup_ch_char11_d,
&t_lights_setup_ch_char12_d,
&t_lights_setup_ch_char13_d,
&t_lights_setup_ch_char14_d,
&t_lights_setup_ch_char15_d,
&t_lights_setup_ch_char16_d,
&t_lights_setup_ch_char17_d,
&t_lights_setup_ch_char18_d,
&t_lights_setup_ch_char19_d,
};

//
lcd_dis_item_t *p_dialog_lights_ch_item_u[DIALOG_LIGHTS_CH_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_close_lights_ch_u,
&t_dialog_p_u,
&t_dialog_save_lights_ch_u,
	
&t_lights_setup_ch_char0_d,
&t_lights_setup_ch_char1_d,
&t_lights_setup_ch_char2_d,
&t_lights_setup_ch_char3_d,
&t_lights_setup_ch_char4_d,
&t_lights_setup_ch_char5_d,
&t_lights_setup_ch_char6_d,
&t_lights_setup_ch_char7_d,
&t_lights_setup_ch_char8_d,
&t_lights_setup_ch_char9_d,
&t_lights_setup_ch_char10_d,
&t_lights_setup_ch_char11_d,
&t_lights_setup_ch_char12_d,
&t_lights_setup_ch_char13_d,
&t_lights_setup_ch_char14_d,
&t_lights_setup_ch_char15_d,
&t_lights_setup_ch_char16_d,
&t_lights_setup_ch_char17_d,
&t_lights_setup_ch_char18_d,
&t_lights_setup_ch_char19_d,
};

lcd_dis_item_t dialog_lights_ch_item[DIALOG_LIGHTS_CH_ICO_NUM];










u16 lights_setup_ch_X[DIALOG_LIGHTS_CH_MAX]=
{
  X_lights_setup_ch_d_char0,
	X_lights_setup_ch_d_char1,
	X_lights_setup_ch_d_char2,
	X_lights_setup_ch_d_char3,
	X_lights_setup_ch_d_char4,
	X_lights_setup_ch_d_char5,
	X_lights_setup_ch_d_char6,
	X_lights_setup_ch_d_char7,
	X_lights_setup_ch_d_char8,
	X_lights_setup_ch_d_char9,
	X_lights_setup_ch_d_char10,
	X_lights_setup_ch_d_char11,
	X_lights_setup_ch_d_char12,
	X_lights_setup_ch_d_char13,
	X_lights_setup_ch_d_char14,
	X_lights_setup_ch_d_char15,
	X_lights_setup_ch_d_char16,
	X_lights_setup_ch_d_char17,
	X_lights_setup_ch_d_char18,
	X_lights_setup_ch_d_char19,

};

u16 lights_setup_ch_Y[DIALOG_LIGHTS_CH_MAX]=
{
  Y_lights_setup_ch_d_char0,
	Y_lights_setup_ch_d_char1,
	Y_lights_setup_ch_d_char2,
	Y_lights_setup_ch_d_char3,
	Y_lights_setup_ch_d_char4,
	Y_lights_setup_ch_d_char5,
	Y_lights_setup_ch_d_char6,
	Y_lights_setup_ch_d_char7,
	Y_lights_setup_ch_d_char8,
	Y_lights_setup_ch_d_char9,
	Y_lights_setup_ch_d_char10,
	Y_lights_setup_ch_d_char11,
	Y_lights_setup_ch_d_char12,
	Y_lights_setup_ch_d_char13,
	Y_lights_setup_ch_d_char14,
	Y_lights_setup_ch_d_char15,
	Y_lights_setup_ch_d_char16,
	Y_lights_setup_ch_d_char17,
	Y_lights_setup_ch_d_char18,
	Y_lights_setup_ch_d_char19,

};




void disply_lights_ch_name(bool upgrade)
{
	u8 i,j;
//	u8 ch=0;
	u8 offset = 0;
	//static SWITCH_NAME_LIST old_switch_name_list_return[SWITCH_NAME_CH_NUM];
	char display_buf[32];
	
	for(i=0;i<8;i++)
	{
		
		 
	  
		 /*if(now_dialog_lights_ch_select_ch<=3)
		 {
			 offset = 0;
			 if(i>=4) break;
		 }
		 else if(now_dialog_lights_ch_select_ch>=4)
		 {
			 offset = 4;
		   if(i==0)
				 i=4;
		 }*/
			 
//		 ch = lights_display_lights_ch[i];//找到对应的开关号
		//ch = lights_display_lights_ch[i];
		//if((upgrade)||(memcmp(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST))))
	  {
	     // memcpy(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST));
			//if(upgrade==FALSE)
			Virtual_LCD_Draw_Rectangle_ARGB32(lights_setup_ch_X[i-offset],lights_setup_ch_Y[i-offset],X_INTER_SPACE,Y_INTER_SPACE,Virtual_LCDbuff2,ARGB_clear);
      //sysprintf("\r\nnow_status:,%d,%d",p_home_lights_item_d[i]->now_status,t_home_load_d_ico.last_status);
			sprintf(display_buf,"CH%d",i+1);
			if((i+1)==now_dialog_lights_ch_select_num)
			{
			  Virtual_LCD_Draw_String_ARGB_24_4bit_bold(lights_setup_ch_X[i-offset]+0,lights_setup_ch_Y[i-offset]+10,display_buf,ARGB_myorange,0,1,1);
			}
			else //if(switch_ch_list_return[i] == 0)
			{
				 
				for(j=0;j<SWITCH_NAME_CH_NUM;j++)
				{
				   if(switch_ch_list_return[j]==(i+1))
						 break;
				}
				if(j==SWITCH_NAME_CH_NUM)
				{	
			     Virtual_LCD_Draw_String_ARGB_24_4bit_bold(lights_setup_ch_X[i-offset]+0,lights_setup_ch_Y[i-offset]+10,display_buf,ARGB_white,0,1,1);
				}
				else
				Virtual_LCD_Draw_String_ARGB_24_4bit_bold(lights_setup_ch_X[i-offset]+0,lights_setup_ch_Y[i-offset]+10,display_buf,0xFF838697,0,1,1);
			}
			
			if(upgrade==FALSE)
			{
			   Virtual_LCD_Upgrate_formx1y1(lights_setup_ch_X[i-offset],lights_setup_ch_Y[i-offset],130,90);
			  // Virtual_LCD_Upgrate();
			}
			
			
	
	 }
		

 }
}
	



BOOL page_dialog_lights_ch_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
	return FALSE;
}



void ui_out_dialog_lights_ch(void)
{
    //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
	  
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
}

void ui_disply_dialog_lights_ch(void)
{
	lcd_dis_page_t *p;
	u8 i,ch;
	p = &page_home.page_dialog_lights_ch;	
 //sysprintf("\r\n eeeeeeeeeeeeeee");
  //Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff3,ARGB_clear);
	//Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val,p->item[0].y_val,p->item[0].x_end_val-p->item[0].x_val,p->item[0].y_end_val-p->item[0].y_val,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_dialog_lights_ch = TRUE;
	//dialog_lights_ch_item[7].now_status = STATUS_SELECT;//选中第一个图标	 
	ch = lights_display_lights_ch[now_dialog_lights_ch_select_ch];//找到对应的开关号
	now_dialog_lights_ch_select_num = switch_ch_list_return[ch];
	
	Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+330,p->item[0].y_val+30,"Channel",ARGB_myorange,0,1,1);

	
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_lights_ch_deel_with_i(p,&i))
							 break;
			
		  //sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }
	 //char_input_len =0;
	 //disply_char_input_val(TRUE);
	 disply_lights_ch_name(TRUE);
   Virtual_LCD_Upgrate();

}


///////////////////////初始化////////////////////////////////////////


void ui_dialog_lights_ch_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_dialog_lights_ch;
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=DIALOG_LIGHTS_CH_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


   t_dialog_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_dialog_close_lights_ch_d.key_type = KEY_TYPE_ONCE;
	 t_dialog_save_lights_ch_d.key_type = KEY_TYPE_ONCE;
   //t_lights_none_c.key_type = KEY_TYPE_TOUCH_NONE;
	 
	 
   p->item = dialog_lights_ch_item;
   for(i=0;i<DIALOG_LIGHTS_CH_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_dialog_lights_ch_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_dialog_lights_ch_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_dialog_lights_ch_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 f_ui_disply_dialog_lights_ch = FALSE;
 }


