#include "includes.h"





bool f_ui_disply_dialog_code = FALSE;
bool f_ui_init_finsh = FALSE;
bool f_ui_need_disply_dialog_code = FALSE;
//u8 now_dialog_code_select_ch = 0;//μ±?°òa?ü??μ?í?±êDòo?
//u8 now_dialog_code_select_num = 1;//′ó1?aê? μ±?°????μ?í¨μà


extern const unsigned char dialog_close_d[];
extern const unsigned char dialog_close_u[];

	
extern void func_dialog_close_code_d(void* p,u8 sn);
extern void func_dialog_close_code_u(void* p,u8 sn);

	
lcd_dis_item_t t_dialog_close_code_d={(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,0,0,5123,5123,5123,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_d+125,Y_dialog_close_d,X_dialog_close_d+125+230,Y_dialog_close_d+71,0,&func_dialog_close_code_d};
lcd_dis_item_t t_dialog_close_code_u={(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,0,0,4611,4611,4611,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_u+125,Y_dialog_close_u,X_dialog_close_u+125+230,Y_dialog_close_u+71,0,&func_dialog_close_code_u};


	//keyboard
lcd_dis_item_t *p_dialog_code_item_d[DIALOG_CODE_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_close_code_d,

};

//
lcd_dis_item_t *p_dialog_code_item_u[DIALOG_CODE_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_close_code_u,
};

lcd_dis_item_t dialog_code_item[DIALOG_CODE_ICO_NUM];








BOOL page_dialog_code_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
	return FALSE;
}


bool f_last_ui_disply_keyboard = FALSE;
void ui_out_dialog_code(void)
{
    //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
		//page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//??μ?ê??￠D?ò3??
	if(f_last_ui_disply_keyboard)
	{
	  Virtual_LCD_Draw_Rectangle_ARGB32(0,280,200,320,Virtual_LCDbuff1,ARGB_clear);
	  Virtual_LCD_Draw_Rectangle_ARGB32(0,280,200,320,Virtual_LCDbuff2,ARGB_clear);
		f_last_ui_disply_keyboard = FALSE;
	}
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
	  send_FlC200_base_set_cmd(0x89,0x10,0);
}

void ui_disply_dialog_code(void)
{
	lcd_dis_page_t *p;
	u8 i;//,ch;
	u8 num ;
	num = waining_code_list_num;
	char display_buf[64];
	
	if(f_ui_disply_keyboard)
	{
	  f_ui_disply_keyboard = FALSE;
		f_ui_out_keyboard = FALSE;
		f_last_ui_disply_keyboard = TRUE;
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
	       f_ui_disply_dialog_msg=FALSE;
	       out_from_long_touch_status();
	      // f_system_accessories_External_Key_Type = FALSE;
	      // f_system_Date_Time_set = FALSE;
				 //f_ui_disply_dialog_info=FALSE;
	
	
	p = &page_home.page_dialog_code;	
 //sysprintf("\r\n eeeeeeeeeeeeeee");
  //Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff3,ARGB_clear);
	//Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val,p->item[0].y_val,p->item[0].x_end_val-p->item[0].x_val,p->item[0].y_end_val-p->item[0].y_val,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_dialog_code = TRUE;

	
	Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+345,p->item[0].y_val+30,"Alarm",0xFF82c2ff,0,1,1);


          sprintf(display_buf,"%d/%d  %02d-%02d-%02d %02d:%02d:%02d  ",\
	        num,\
	        waining_code_list_num,\
					waining_code_list[num].time_happen.year,\
					waining_code_list[num].time_happen.mon,\
					waining_code_list[num].time_happen.day,\
					waining_code_list[num].time_happen.hour,\
					waining_code_list[num].time_happen.min,\
					waining_code_list[num].time_happen.sec);
					Virtual_LCD_Draw_String_ARGB_16_4bit(p->item[0].x_val+300,p->item[0].y_val+240,display_buf,ARGB_gray,0,1,1);
	
					
					for(i=0;i<waining_code_list[num].txt_len;i++)
					{
					   sprintf(&display_buf[i],"%c",waining_code_list[num].txt[i]);
					
					}
	        Virtual_LCD_Draw_String_ARGB_32_4bit_bold(p->item[0].x_val+400-waining_code_list[num].txt_len*8,p->item[0].y_val+200,display_buf,ARGB_yellow,0,1,1);
	
					if((waining_code_list[num].err_code_type==2)||(waining_code_list[num].err_code_type==3))//=1：警告  =2：故障/错误  =3：保护  =4：没连接 
	         send_FlC200_base_set_cmd(0x89,0x11,0);
	
					
					
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_code_deel_with_i(p,&i))
							 break;
			
		  //sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }
	 //char_input_len =0;
	 //disply_char_input_val(TRUE);
	 //disply_code_name(TRUE);
   Virtual_LCD_Upgrate();

}


///////////////////////3?ê??ˉ////////////////////////////////////////


void ui_dialog_code_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_dialog_code;
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=DIALOG_CODE_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


   t_dialog_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_dialog_close_code_d.key_type = KEY_TYPE_ONCE;

	 
	 
   p->item = dialog_code_item;
   for(i=0;i<DIALOG_CODE_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_dialog_code_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_dialog_code_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_dialog_code_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 f_ui_disply_dialog_code = FALSE;
 }


