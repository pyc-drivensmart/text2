#include "includes.h"





bool f_ui_disply_dialog_msg = FALSE;
bool f_ui_need_disply_dialog_msg = FALSE;
u32 v_ui_need_out_dialog_msg_cnt = 0;
u8 v_ui_disply_dialog_msg_type = 0;
//u8 now_dialog_msg_select_ch = 0;//μ±?°òa?ü??μ?í?±êDòo?
//u8 now_dialog_msg_select_num = 1;//′ó1?aê? μ±?°????μ?í¨μà


extern const unsigned char dialog_close_d[];
extern const unsigned char dialog_close_u[];

	
extern void func_dialog_close_msg_d(void* p,u8 sn);
extern void func_dialog_close_msg_u(void* p,u8 sn);

	
lcd_dis_item_t t_dialog_close_msg_d={(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,0,0,5123,5123,5123,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_d+125,Y_dialog_close_d,X_dialog_close_d+125+230,Y_dialog_close_d+71,0,&func_dialog_close_msg_d};
lcd_dis_item_t t_dialog_close_msg_u={(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,0,0,4611,4611,4611,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_u+125,Y_dialog_close_u,X_dialog_close_u+125+230,Y_dialog_close_u+71,0,&func_dialog_close_msg_u};


	//keyboard
lcd_dis_item_t *p_dialog_msg_item_d[DIALOG_MSG_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_empty_d,

};

//
lcd_dis_item_t *p_dialog_msg_item_u[DIALOG_MSG_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_empty_u,
};

lcd_dis_item_t dialog_msg_item[DIALOG_MSG_ICO_NUM];








BOOL page_dialog_msg_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
	return FALSE;
}


bool f_last_ui_disply_keyboard_msg = FALSE;
void ui_out_dialog_msg(void)
{
    //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
		//page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//??μ?ê??￠D?ò3??
	if(f_last_ui_disply_keyboard_msg)
	{
	  Virtual_LCD_Draw_Rectangle_ARGB32(0,280,200,320,Virtual_LCDbuff1,ARGB_clear);
	  Virtual_LCD_Draw_Rectangle_ARGB32(0,280,200,320,Virtual_LCDbuff2,ARGB_clear);
		f_last_ui_disply_keyboard_msg = FALSE;
	}
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
}
void set_v_ui_need_out_dialog_msg_cnt(void)
{
  v_ui_need_out_dialog_msg_cnt = 500;

}
void rest_v_ui_need_out_dialog_msg_cnt(void)
{
  v_ui_need_out_dialog_msg_cnt = 0;

}
void check_ui_out_dialog_msg(void)
{
  if(v_ui_need_out_dialog_msg_cnt)
	{
		v_ui_need_out_dialog_msg_cnt--;
		if(v_ui_need_out_dialog_msg_cnt ==0)
			ui_out_dialog_msg();
	}

}



void ui_disply_dialog_msg(void)
{
	lcd_dis_page_t *p;
	lcd_dis_item_t *p1;
	u8 i;//,ch;


	char display_buf[64];
	
	if(f_ui_disply_keyboard)
	{
	  f_ui_disply_keyboard = FALSE;
		f_ui_out_keyboard = FALSE;
		f_last_ui_disply_keyboard_msg = TRUE;
				 //ui_out_keyboard();
		//Virtual_LCD_Draw_Rectangle_ARGB32(0,280,200,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,200,320,Virtual_LCDbuff2,ARGB_clear);
		//page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
	}
	
         f_ui_disply_dialog_lights=FALSE;
				 f_ui_disply_dialog_loads=FALSE;
				 f_ui_disply_dialog_lights_ch=FALSE;
				 f_ui_disply_dialog_loads_ch=FALSE;
	       f_ui_disply_dialog_motors=FALSE;
	       out_from_long_touch_status();
	      // f_system_accessories_External_Key_Type = FALSE;
	      // f_system_Date_Time_set = FALSE;
				 //f_ui_disply_dialog_info=FALSE;
	
	
	p = &page_home.page_dialog_msg;	
 //sysprintf("\r\n eeeeeeeeeeeeeee");
  //Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff3,ARGB_clear);
	//Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val,p->item[0].y_val,p->item[0].x_end_val-p->item[0].x_val,p->item[0].y_end_val-p->item[0].y_val,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_dialog_msg = TRUE;

	
	

  if(v_ui_disply_dialog_msg_type == DIALOG_MSG_TYPE_OVERRIDE_KEY)
	{
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+320,p->item[0].y_val+50,"Info",0xFF82c2ff,0,1,1);
   if(f_override_key)
	 {
      sprintf(display_buf,"Local Override Activated");
		  rest_v_ui_need_out_dialog_msg_cnt();
	 }
	 else
	 {
		 sprintf(display_buf,"Local Override Deactivated");
	    set_v_ui_need_out_dialog_msg_cnt();
	 }
  
		    Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p->item[0].x_val+360,p->item[0].y_val+200,display_buf,ARGB_yellow,0,1,1);
   
		p1=&t_dialog_empty_d;
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(((p1->x_end_val+p1->x_val)>>1),p1->y_val+25,"Confirm",ARGB_white,0,1,1);
			
	
	} 
	else if(v_ui_disply_dialog_msg_type == DIALOG_MSG_TYPE_MOTOR_WARNING)
	{
		
		/*CAUTION

1.Ensure the RV is securely parked and the parking brake is engaged before using the slide-out or awning

2.Ensure there are no obstacles or people around when operating the slide-out or awning

3.Avoid using the awning in strong winds to prevent damage or accidents

4.Do not place too many items in the slide-out space to avoid overloading and affecting its operation*/
		
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+320,p->item[0].y_val+25,"CAUTION",0xFF82c2ff,0,1,1);
		
		p1=&t_icon_warning;
    png_dis_xy(p->item[0].x_val+30,p->item[0].y_val+80,p1->pic_item_select,p1->size_of_pic_item_select,Virtual_LCDbuff2);
		
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+65,p->item[0].y_val+70,\
		"Ensure the RV is securely parked and the parking brake",ARGB_yellow,0,1,1);		
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+65,p->item[0].y_val+105,\
		"is engaged before using the slide-out or awning.",ARGB_yellow,0,1,1);
		
		png_dis_xy(p->item[0].x_val+30,p->item[0].y_val+155,p1->pic_item_select,p1->size_of_pic_item_select,Virtual_LCDbuff2);
	  
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+65,p->item[0].y_val+145,\
		"Ensure there are no obstacles or people around when",ARGB_yellow,0,1,1);		
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+65,p->item[0].y_val+180,\
		"operating the slide-out or awning.",ARGB_yellow,0,1,1);
		
		png_dis_xy(p->item[0].x_val+30,p->item[0].y_val+230,p1->pic_item_select,p1->size_of_pic_item_select,Virtual_LCDbuff2);
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+65,p->item[0].y_val+220,\
		"Avoid using the awning in strong winds to prevent",ARGB_yellow,0,1,1);		
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+65,p->item[0].y_val+255,\
		"damage or accidents.",ARGB_yellow,0,1,1);
		
		png_dis_xy(p->item[0].x_val+30,p->item[0].y_val+305,p1->pic_item_select,p1->size_of_pic_item_select,Virtual_LCDbuff2);
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+65,p->item[0].y_val+295,\
		"Do not place too many items in the slide-out space to",ARGB_yellow,0,1,1);		
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+65,p->item[0].y_val+330,\
		"avoid overloading and affecting its operation.",ARGB_yellow,0,1,1);
		
		
		
		p1=&t_dialog_empty_d;
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(((p1->x_end_val+p1->x_val)>>1),p1->y_val+25,"Confirm",ARGB_white,0,1,1);
			
	}
	
	
	else if(v_ui_disply_dialog_msg_type == DIALOG_MSG_TYPE_HANDBREAK_WARNING)
	{
		
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+320,p->item[0].y_val+50,"CAUTION",0xFF82c2ff,0,1,1);

		 sprintf(display_buf,"Park Brake Is Not Engaged, Please Check!");

  
		Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p->item[0].x_val+360,p->item[0].y_val+200,display_buf,ARGB_yellow,0,1,1);
   
		p1=&t_dialog_empty_d;
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(((p1->x_end_val+p1->x_val)>>1),p1->y_val+25,"Confirm",ARGB_white,0,1,1);
			
			
	}
	
					
					
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_msg_deel_with_i(p,&i))
							 break;
			
		  //sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }

   Virtual_LCD_Upgrate();


}


///////////////////////3?ê??ˉ////////////////////////////////////////


void ui_dialog_msg_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_dialog_msg;
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=DIALOG_MSG_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


   t_dialog_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_dialog_close_msg_d.key_type = KEY_TYPE_ONCE;
   t_dialog_empty_d.key_type = KEY_TYPE_ONCE;

	 
	 
   p->item = dialog_msg_item;
   for(i=0;i<DIALOG_MSG_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_dialog_msg_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_dialog_msg_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_dialog_msg_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 f_ui_disply_dialog_msg = FALSE;
 }


