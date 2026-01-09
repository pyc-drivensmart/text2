#include "includes.h"




bool f_ui_disply_dialog_lights = FALSE;
u8 now_dialog_lights_icon_select_ch = 0;

extern lcd_dis_item_t t_lights_setup_ch_char0_d;
extern lcd_dis_item_t t_lights_setup_ch_char1_d;
extern lcd_dis_item_t t_lights_setup_ch_char2_d;
extern lcd_dis_item_t t_lights_setup_ch_char3_d;
extern lcd_dis_item_t t_lights_setup_ch_char4_d;
extern lcd_dis_item_t t_lights_setup_ch_char5_d;
extern lcd_dis_item_t t_lights_setup_ch_char6_d;
extern lcd_dis_item_t t_lights_setup_ch_char7_d;
extern lcd_dis_item_t t_lights_setup_ch_char8_d;
extern lcd_dis_item_t t_lights_setup_ch_char9_d;
extern lcd_dis_item_t t_lights_setup_ch_char10_d;
extern lcd_dis_item_t t_lights_setup_ch_char11_d;
extern lcd_dis_item_t t_lights_setup_ch_char12_d;
extern lcd_dis_item_t t_lights_setup_ch_char13_d;
extern lcd_dis_item_t t_lights_setup_ch_char14_d;
extern lcd_dis_item_t t_lights_setup_ch_char15_d;
extern lcd_dis_item_t t_lights_setup_ch_char16_d;
extern lcd_dis_item_t t_lights_setup_ch_char17_d;
extern lcd_dis_item_t t_lights_setup_ch_char18_d;
extern lcd_dis_item_t t_lights_setup_ch_char19_d;


	//keyboard
lcd_dis_item_t *p_dialog_lights_item_d[DIALOG_LIGHTS_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_close_d,
&t_dialog_p_d,
&t_dialog_save_d,
	
&t_lights_pendant_c,	
&t_lights_rearside_c,	
&t_lights_interior_c,	
&t_lights_awning_c,
&t_lights_rightside_c,	
&t_lights_underbody_c,


&t_lights_rearwork_c,


&t_lights_none_c,
	
	
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
lcd_dis_item_t *p_dialog_lights_item_u[DIALOG_LIGHTS_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_close_u,
&t_dialog_p_u,
&t_dialog_save_u,
	
	
&t_lights_pendant_u,	
&t_lights_rearside_u,	
&t_lights_interior_u,	
&t_lights_awning_u,
&t_lights_rightside_u,	
&t_lights_underbody_u,


&t_lights_rearwork_u,


&t_lights_none_u,
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

lcd_dis_item_t dialog_lights_item[DIALOG_LIGHTS_ICO_NUM];






BOOL page_dialog_lights_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
/*
if(now_dialog_lights_ch_select_ch<=3) 
{
   if(*i==16)
		 return TRUE;
}*/
return FALSE;

}



void ui_out_dialog_lights(void)
{
	u8 i;
    //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
	   //set_lights_item_key_type(KEY_TYPE_LONG_PRESS);
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
	for(i=0;i<8;i++)
	  dialog_lights_item[4+i].now_status = STATUS_IDLE;

}
bool f_need_ui_disply_dialog_lights = FALSE;
void ui_disply_dialog_lights(void)
{
	lcd_dis_page_t *p;
	u8 i,ch;
	f_need_ui_disply_dialog_lights = FALSE;
	p = &page_home.page_dialog_lights;	
 //sysprintf("\r\n eeeeeeeeeeeeeee");
  //Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff3,ARGB_clear);
	//Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val,p->item[0].y_val,p->item[0].x_end_val-p->item[0].x_val,p->item[0].y_end_val-p->item[0].y_val,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_dialog_lights = TRUE;
	//dialog_lights_item[7].now_status = STATUS_SELECT;//选中第一个图标	 
	//now_dialog_lights_icon_select_ch = 0;
	now_dialog_lights_icon_select_ch = switch_name_list_return[lights_display_lights_ch[lights_light_d_ico_select_ch]].icon_select;
	dialog_lights_item[now_dialog_lights_icon_select_ch+4].now_status = STATUS_SELECT;//选中第一个图标	 
	
	//Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+20,p->item[0].y_val+70,"Icon:",ARGB_myorange,0,1,1);
	
	
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_lights_deel_with_i(p,&i))
							 break;
			
		  //sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }
	 //char_input_len =0;
	 //disply_char_input_val(TRUE);
	 
	 ///////////////////////////////////////////////
	 f_ui_disply_dialog_lights_ch = TRUE;
	//dialog_lights_ch_item[7].now_status = STATUS_SELECT;//选中第一个图标	 
	ch = lights_display_lights_ch[now_dialog_lights_ch_select_ch];//找到对应的开关号
	now_dialog_lights_ch_select_num = switch_ch_list_return[ch];
	
	// Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+20,p->item[0].y_val+Y_INTER_OFFET+10," Ch :",ARGB_myorange,0,1,1);

	
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


void ui_dialog_lights_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_dialog_lights;
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=DIALOG_LIGHTS_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


   t_dialog_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_dialog_close_d.key_type = KEY_TYPE_ONCE;
	 t_dialog_save_d.key_type = KEY_TYPE_ONCE;
   t_lights_none_c.key_type = KEY_TYPE_TOUCH_NONE;
	 
	 
   p->item = dialog_lights_item;
   for(i=0;i<DIALOG_LIGHTS_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_dialog_lights_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_dialog_lights_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_dialog_lights_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 f_ui_disply_dialog_lights = FALSE;
	 f_ui_disply_dialog_lights_ch = FALSE;
 }


