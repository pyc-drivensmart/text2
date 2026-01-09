#include "includes.h"




bool f_ui_disply_dialog_loads = FALSE;
u8 now_dialog_loads_icon_select_ch = 0;


extern lcd_dis_item_t t_loads_setup_ch_char0_d;
extern lcd_dis_item_t t_loads_setup_ch_char1_d;
extern lcd_dis_item_t t_loads_setup_ch_char2_d;
extern lcd_dis_item_t t_loads_setup_ch_char3_d;
extern lcd_dis_item_t t_loads_setup_ch_char4_d;
extern lcd_dis_item_t t_loads_setup_ch_char5_d;
extern lcd_dis_item_t t_loads_setup_ch_char6_d;
extern lcd_dis_item_t t_loads_setup_ch_char7_d;
extern lcd_dis_item_t t_loads_setup_ch_char8_d;
extern lcd_dis_item_t t_loads_setup_ch_char9_d;
extern lcd_dis_item_t t_loads_setup_ch_char10_d;
extern lcd_dis_item_t t_loads_setup_ch_char11_d;
extern lcd_dis_item_t t_loads_setup_ch_char12_d;
extern lcd_dis_item_t t_loads_setup_ch_char13_d;
extern lcd_dis_item_t t_loads_setup_ch_char14_d;
extern lcd_dis_item_t t_loads_setup_ch_char15_d;
extern lcd_dis_item_t t_loads_setup_ch_char16_d;
extern lcd_dis_item_t t_loads_setup_ch_char17_d;
extern lcd_dis_item_t t_loads_setup_ch_char18_d;
extern lcd_dis_item_t t_loads_setup_ch_char19_d;




extern void func_loads_dialog_close_d(void* p,u8 sn);
extern void func_loads_dialog_close_u(void* p,u8 sn);
extern void func_loads_dialog_save_d(void* p,u8 sn);
extern void func_loads_dialog_save_u(void* p,u8 sn);


extern const unsigned char dialog_close_d[];
extern const unsigned char dialog_close_u[];
extern const unsigned char dialog_save_d[];
extern const unsigned char dialog_save_u[];
lcd_dis_item_t t_loads_dialog_close_d={(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,0,0,5123,5123,5123,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_d,Y_dialog_close_d,X_dialog_close_d+230,Y_dialog_close_d+71,0,&func_loads_dialog_close_d};
lcd_dis_item_t t_loads_dialog_close_u={(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,0,0,4611,4611,4611,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_u,Y_dialog_close_u,X_dialog_close_u+230,Y_dialog_close_u+71,0,&func_loads_dialog_close_u};
lcd_dis_item_t t_loads_dialog_save_d={(unsigned char*)dialog_save_d,(unsigned char*)dialog_save_d,(unsigned char*)dialog_save_d,0,0,5014,5014,5014,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_save_d,Y_dialog_save_d,X_dialog_save_d+230,Y_dialog_save_d+71,0,&func_loads_dialog_save_d};
lcd_dis_item_t t_loads_dialog_save_u={(unsigned char*)dialog_save_u,(unsigned char*)dialog_save_u,(unsigned char*)dialog_save_u,0,0,4571,4571,4571,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_save_u,Y_dialog_save_u,X_dialog_save_u+230,Y_dialog_save_u+71,0,&func_loads_dialog_save_u};










	//keyboard
lcd_dis_item_t *p_dialog_loads_item_d[DIALOG_LOADS_ICO_NUM]=
{
&t_dialog_bg,
&t_loads_dialog_close_d,
&t_dialog_p_d,
&t_loads_dialog_save_d, 
	
&t_loads_ventilator_sel_c,	
&t_loads_fridge_sel_c,	
&t_loads_KV_sel_c,	
&t_loads_AC_sel_c,


//&t_loads_load_sel_c,
&t_loads_MW_sel_c,
&t_loads_TV_sel_c,

&t_loads_WM_sel_c,
&t_lights_none_u,//t_loads_wp_sel_c,
	
&t_loads_setup_ch_char0_d,
&t_loads_setup_ch_char1_d,
&t_loads_setup_ch_char2_d,
&t_loads_setup_ch_char3_d,
&t_loads_setup_ch_char4_d,
&t_loads_setup_ch_char5_d,
&t_loads_setup_ch_char6_d,
&t_loads_setup_ch_char7_d,
&t_loads_setup_ch_char8_d,
&t_loads_setup_ch_char9_d,
&t_loads_setup_ch_char10_d,
&t_loads_setup_ch_char11_d,
&t_loads_setup_ch_char12_d,
&t_loads_setup_ch_char13_d,
&t_loads_setup_ch_char14_d,
&t_loads_setup_ch_char15_d,
&t_loads_setup_ch_char16_d,
&t_loads_setup_ch_char17_d,
&t_loads_setup_ch_char18_d,
&t_loads_setup_ch_char19_d,
};

//
lcd_dis_item_t *p_dialog_loads_item_u[DIALOG_LOADS_ICO_NUM]=
{
&t_dialog_bg,
&t_loads_dialog_close_u,
&t_dialog_p_u,
&t_loads_dialog_save_u,
	
&t_loads_ventilator_sel_u,	
&t_loads_fridge_sel_u,	
&t_loads_KV_sel_u,
	
&t_loads_AC_sel_u,


//&t_loads_load_sel_u,
&t_loads_MW_sel_u,
&t_loads_TV_sel_u,

&t_loads_WM_sel_u,
&t_lights_none_u,//t_loads_wp_sel_u,
&t_loads_setup_ch_char0_d,
&t_loads_setup_ch_char1_d,
&t_loads_setup_ch_char2_d,
&t_loads_setup_ch_char3_d,
&t_loads_setup_ch_char4_d,
&t_loads_setup_ch_char5_d,
&t_loads_setup_ch_char6_d,
&t_loads_setup_ch_char7_d,
&t_loads_setup_ch_char8_d,
&t_loads_setup_ch_char9_d,
&t_loads_setup_ch_char10_d,
&t_loads_setup_ch_char11_d,
&t_loads_setup_ch_char12_d,
&t_loads_setup_ch_char13_d,
&t_loads_setup_ch_char14_d,
&t_loads_setup_ch_char15_d,
&t_loads_setup_ch_char16_d,
&t_loads_setup_ch_char17_d,
&t_loads_setup_ch_char18_d,
&t_loads_setup_ch_char19_d,
};

lcd_dis_item_t dialog_loads_item[DIALOG_LOADS_ICO_NUM];






BOOL page_dialog_loads_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
  /*if(f_ui_disply_keyboard)
	{

			if(keyboard_ui_step==KEYBOARD_PAGE_NOR)
			{
					if(*i==32)return TRUE;
							
			}
			else if(keyboard_ui_step==KEYBOARD_PAGE_CAPS)
			{
					if(*i==6)*i=32;
					if(*i==58)return TRUE;
			}
			else if(keyboard_ui_step==KEYBOARD_PAGE_NUM)
			{
					if(*i==22)*i=58;
					//if(*i==58)return TRUE;
			}
	}
	else
		return TRUE;
*/
	return FALSE;

}



void ui_out_dialog_loads(void)
{
	u8 i;
    //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
	 // set_loads_item_key_type(KEY_TYPE_LONG_PRESS);
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
		for(i=0;i<8;i++)
	  dialog_loads_item[4+i].now_status = STATUS_IDLE;
}

bool f_need_ui_disply_dialog_loads = FALSE;
void ui_disply_dialog_loads(void)
{
	lcd_dis_page_t *p;
	u8 i,ch;
	f_need_ui_disply_dialog_loads = FALSE;
	p = &page_home.page_dialog_loads;	
 //sysprintf("\r\n eeeeeeeeeeeeeee");
  //Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff3,ARGB_clear);
	//Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val,p->item[0].y_val,p->item[0].x_end_val-p->item[0].x_val,p->item[0].y_end_val-p->item[0].y_val,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_dialog_loads = TRUE;
	
	
	now_dialog_loads_icon_select_ch = switch_name_list_return[loads_display_loads_ch[loads_load_d_ico_select_ch]].icon_select;
	dialog_loads_item[now_dialog_loads_icon_select_ch+4].now_status = STATUS_SELECT;//选中第一个图标	 
	
	
	//Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+20,p->item[0].y_val+70,"Icon:",0xFF82c2ff,0,1,1);
	
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_loads_deel_with_i(p,&i))
							 break;
			
		  //sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }
	 //char_input_len =0;
	 //disply_char_input_val(TRUE);
	 
	  f_ui_disply_dialog_loads_ch = TRUE;
	//dialog_loads_ch_item[7].now_status = STATUS_SELECT;//???Dμúò???í?±ê	 
	ch = loads_display_loads_ch[now_dialog_loads_ch_select_ch];//?òμ???ó|μ??a1?o?
	now_dialog_loads_ch_select_num = switch_ch_list_return[ch];
	
	// Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+20,p->item[0].y_val+Y_INTER_OFFET+10," Ch :",0xFF82c2ff,0,1,1);

	
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_loads_ch_deel_with_i(p,&i))
							 break;
			
		  //sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }
	 //char_input_len =0;
	 //disply_char_input_val(TRUE);
	 disply_loads_ch_name(TRUE);
	 
   Virtual_LCD_Upgrate();

}


///////////////////////初始化////////////////////////////////////////


void ui_dialog_loads_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_dialog_loads;
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=DIALOG_LOADS_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


   t_dialog_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_loads_dialog_close_d.key_type = KEY_TYPE_ONCE;
	 t_loads_dialog_save_d.key_type = KEY_TYPE_ONCE;
   //t_lights_none_c.key_type = KEY_TYPE_TOUCH_NONE;
	 t_lights_none_u.key_type = KEY_TYPE_TOUCH_NONE;
	 
   p->item = dialog_loads_item;
   for(i=0;i<DIALOG_LOADS_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_dialog_loads_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_dialog_loads_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_dialog_loads_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 f_ui_disply_dialog_loads = FALSE;
	 f_ui_disply_dialog_loads_ch = FALSE;
 }


