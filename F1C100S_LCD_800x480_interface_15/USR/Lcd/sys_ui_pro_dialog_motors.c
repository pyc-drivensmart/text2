#include "includes.h"




bool f_ui_disply_dialog_motors = FALSE;
bool f_ui_disply_dialog_motors_ch = FALSE;
u8 now_dialog_motors_icon_select_ch = 0;

u8 now_dialog_motors_ch_select_ch = 0;
u8 now_dialog_motors_ch_select_num = 1;


  extern void func_motors_setup_ch_char0_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char1_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char2_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char3_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char4_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char5_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char6_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char7_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char8_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char9_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char10_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char11_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char12_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char13_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char14_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char15_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char16_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char17_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char18_d(void* p,u8 sn);
	extern void func_motors_setup_ch_char19_d(void* p,u8 sn);
	
	
	

	
lcd_dis_item_t t_motors_setup_ch_char0_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char0,Y_motors_setup_ch_d_char0,X_motors_setup_ch_d_char0+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char0+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char0_d};
lcd_dis_item_t t_motors_setup_ch_char1_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char1,Y_motors_setup_ch_d_char1,X_motors_setup_ch_d_char1+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char1+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char1_d};
lcd_dis_item_t t_motors_setup_ch_char2_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char2,Y_motors_setup_ch_d_char2,X_motors_setup_ch_d_char2+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char2+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char2_d};
lcd_dis_item_t t_motors_setup_ch_char3_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char3,Y_motors_setup_ch_d_char3,X_motors_setup_ch_d_char3+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char3+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char3_d};
lcd_dis_item_t t_motors_setup_ch_char4_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char4,Y_motors_setup_ch_d_char4,X_motors_setup_ch_d_char4+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char4+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char4_d};
lcd_dis_item_t t_motors_setup_ch_char5_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char5,Y_motors_setup_ch_d_char5,X_motors_setup_ch_d_char5+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char5+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char5_d};
lcd_dis_item_t t_motors_setup_ch_char6_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char6,Y_motors_setup_ch_d_char6,X_motors_setup_ch_d_char6+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char6+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char6_d};
lcd_dis_item_t t_motors_setup_ch_char7_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char7,Y_motors_setup_ch_d_char7,X_motors_setup_ch_d_char7+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char7+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char7_d};
lcd_dis_item_t t_motors_setup_ch_char8_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char8,Y_motors_setup_ch_d_char8,X_motors_setup_ch_d_char8+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char8+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char8_d};
lcd_dis_item_t t_motors_setup_ch_char9_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char9,Y_motors_setup_ch_d_char9,X_motors_setup_ch_d_char9+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char9+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char9_d};
lcd_dis_item_t t_motors_setup_ch_char10_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char10,Y_motors_setup_ch_d_char10,X_motors_setup_ch_d_char10+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char10+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char10_d};
lcd_dis_item_t t_motors_setup_ch_char11_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char11,Y_motors_setup_ch_d_char11,X_motors_setup_ch_d_char11+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char11+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char11_d};
lcd_dis_item_t t_motors_setup_ch_char12_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char12,Y_motors_setup_ch_d_char12,X_motors_setup_ch_d_char12+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char12+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char12_d};
lcd_dis_item_t t_motors_setup_ch_char13_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char13,Y_motors_setup_ch_d_char13,X_motors_setup_ch_d_char13+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char13+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char13_d};
lcd_dis_item_t t_motors_setup_ch_char14_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char14,Y_motors_setup_ch_d_char14,X_motors_setup_ch_d_char14+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char14+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char14_d};
lcd_dis_item_t t_motors_setup_ch_char15_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char15,Y_motors_setup_ch_d_char15,X_motors_setup_ch_d_char15+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char15+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char15_d};
lcd_dis_item_t t_motors_setup_ch_char16_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char16,Y_motors_setup_ch_d_char16,X_motors_setup_ch_d_char16+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char16+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char16_d};
lcd_dis_item_t t_motors_setup_ch_char17_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char17,Y_motors_setup_ch_d_char17,X_motors_setup_ch_d_char17+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char17+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char17_d};
lcd_dis_item_t t_motors_setup_ch_char18_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char18,Y_motors_setup_ch_d_char18,X_motors_setup_ch_d_char18+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char18+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char18_d};
lcd_dis_item_t t_motors_setup_ch_char19_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_motors_setup_ch_d_char19,Y_motors_setup_ch_d_char19,X_motors_setup_ch_d_char19+X_MOTORS_INTER_SPACE,Y_motors_setup_ch_d_char19+Y_MOTORS_INTER_SPACE,0,&func_motors_setup_ch_char19_d};




extern void func_motors_dialog_close_d(void* p,u8 sn);
extern void func_motors_dialog_close_u(void* p,u8 sn);
extern void func_motors_dialog_save_d(void* p,u8 sn);
extern void func_motors_dialog_save_u(void* p,u8 sn);


extern const unsigned char dialog_close_d[];
extern const unsigned char dialog_close_u[];
extern const unsigned char dialog_save_d[];
extern const unsigned char dialog_save_u[];
lcd_dis_item_t t_motors_dialog_close_d={(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,0,0,5123,5123,5123,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_d,Y_dialog_close_d,X_dialog_close_d+230,Y_dialog_close_d+71,0,&func_motors_dialog_close_d};
lcd_dis_item_t t_motors_dialog_close_u={(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,0,0,4611,4611,4611,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_u,Y_dialog_close_u,X_dialog_close_u+230,Y_dialog_close_u+71,0,&func_motors_dialog_close_u};
lcd_dis_item_t t_motors_dialog_save_d={(unsigned char*)dialog_save_d,(unsigned char*)dialog_save_d,(unsigned char*)dialog_save_d,0,0,5014,5014,5014,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_save_d,Y_dialog_save_d,X_dialog_save_d+230,Y_dialog_save_d+71,0,&func_motors_dialog_save_d};
lcd_dis_item_t t_motors_dialog_save_u={(unsigned char*)dialog_save_u,(unsigned char*)dialog_save_u,(unsigned char*)dialog_save_u,0,0,4571,4571,4571,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_save_u,Y_dialog_save_u,X_dialog_save_u+230,Y_dialog_save_u+71,0,&func_motors_dialog_save_u};










	//keyboard
lcd_dis_item_t *p_dialog_motors_item_d[DIALOG_MOTORS_ICO_NUM]=
{
&t_dialog_bg,
&t_motors_dialog_close_d,
&t_dialog_p_d,
&t_motors_dialog_save_d, 
	
&t_Motors_Awning_sel_c,	
&t_Motors_Curtain_sel_c,	
&t_Motors_Expansion_sel_c,	

&t_motors_setup_ch_char0_d,
&t_motors_setup_ch_char1_d,
&t_motors_setup_ch_char2_d,
&t_motors_setup_ch_char3_d,
&t_motors_setup_ch_char4_d,
&t_motors_setup_ch_char5_d,
&t_motors_setup_ch_char6_d,
&t_motors_setup_ch_char7_d,
&t_motors_setup_ch_char8_d,
&t_motors_setup_ch_char9_d,
&t_motors_setup_ch_char10_d,
&t_motors_setup_ch_char11_d,
&t_motors_setup_ch_char12_d,
&t_motors_setup_ch_char13_d,
&t_motors_setup_ch_char14_d,
&t_motors_setup_ch_char15_d,
&t_motors_setup_ch_char16_d,
&t_motors_setup_ch_char17_d,
&t_motors_setup_ch_char18_d,
&t_motors_setup_ch_char19_d,
};

//
lcd_dis_item_t *p_dialog_motors_item_u[DIALOG_MOTORS_ICO_NUM]=
{
&t_dialog_bg,
&t_motors_dialog_close_u,
&t_dialog_p_u,
&t_motors_dialog_save_u,
	
&t_Motors_Awning_sel_u,	
&t_Motors_Curtain_sel_u,	
&t_Motors_Expansion_sel_u,	
	
&t_motors_setup_ch_char0_d,	
&t_motors_setup_ch_char1_d,
&t_motors_setup_ch_char2_d,
&t_motors_setup_ch_char3_d,
&t_motors_setup_ch_char4_d,
&t_motors_setup_ch_char5_d,
&t_motors_setup_ch_char6_d,
&t_motors_setup_ch_char7_d,
&t_motors_setup_ch_char8_d,
&t_motors_setup_ch_char9_d,
&t_motors_setup_ch_char10_d,
&t_motors_setup_ch_char11_d,
&t_motors_setup_ch_char12_d,
&t_motors_setup_ch_char13_d,
&t_motors_setup_ch_char14_d,
&t_motors_setup_ch_char15_d,
&t_motors_setup_ch_char16_d,
&t_motors_setup_ch_char17_d,
&t_motors_setup_ch_char18_d,
&t_motors_setup_ch_char19_d,
};

lcd_dis_item_t dialog_motors_item[DIALOG_MOTORS_ICO_NUM];






BOOL page_dialog_motors_deel_with_i(lcd_dis_page_t *p2,u8* i)
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



u16 motors_setup_ch_X[DIALOG_MOTORS_CH_MAX]=
{
  X_motors_setup_ch_d_char0,
	X_motors_setup_ch_d_char1,
	X_motors_setup_ch_d_char2,
	X_motors_setup_ch_d_char3,
	X_motors_setup_ch_d_char4,
	X_motors_setup_ch_d_char5,
	X_motors_setup_ch_d_char6,
	X_motors_setup_ch_d_char7,
	X_motors_setup_ch_d_char8,
	X_motors_setup_ch_d_char9,
	X_motors_setup_ch_d_char10,
	X_motors_setup_ch_d_char11,
	X_motors_setup_ch_d_char12,
	X_motors_setup_ch_d_char13,
	X_motors_setup_ch_d_char14,
	X_motors_setup_ch_d_char15,
	X_motors_setup_ch_d_char16,
	X_motors_setup_ch_d_char17,
	X_motors_setup_ch_d_char18,
	X_motors_setup_ch_d_char19,

};

u16 motors_setup_ch_Y[DIALOG_MOTORS_CH_MAX]=
{
  Y_motors_setup_ch_d_char0,
	Y_motors_setup_ch_d_char1,
	Y_motors_setup_ch_d_char2,
	Y_motors_setup_ch_d_char3,
	Y_motors_setup_ch_d_char4,
	Y_motors_setup_ch_d_char5,
	Y_motors_setup_ch_d_char6,
	Y_motors_setup_ch_d_char7,
	Y_motors_setup_ch_d_char8,
	Y_motors_setup_ch_d_char9,
	Y_motors_setup_ch_d_char10,
	Y_motors_setup_ch_d_char11,
	Y_motors_setup_ch_d_char12,
	Y_motors_setup_ch_d_char13,
	Y_motors_setup_ch_d_char14,
	Y_motors_setup_ch_d_char15,
	Y_motors_setup_ch_d_char16,
	Y_motors_setup_ch_d_char17,
	Y_motors_setup_ch_d_char18,
	Y_motors_setup_ch_d_char19,

};


void disply_motors_ch_name(bool upgrade)
{
	u8 i,j;
//	u8 ch=0;
	u8 offset = 0;
	//static SWITCH_NAME_LIST old_switch_name_list_return[SWITCH_NAME_CH_NUM];
	char display_buf[32];
	
	for(i=0;i<MAX_LOADS_MOTORS_DIAPLAY_NUM*2;i++)
	{
		
		 
	  
		 /*if(now_dialog_motors_ch_select_ch<=3)
		 {
			 offset = 0;
			 if(i>=4) break;
		 }
		 else if(now_dialog_motors_ch_select_ch>=4)
		 {
			 offset = 4;
		   if(i==0)
				 i=4;
		 }*/
			 
		 //ch = motors_display_motors_ch[i];//?òμ???ó|μ??a1?o?
		//ch = motors_display_motors_ch[i];
		//if((upgrade)||(memcmp(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST))))
	  {
	     // memcpy(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST));
			//if(upgrade==FALSE)
			Virtual_LCD_Draw_Rectangle_ARGB32(motors_setup_ch_X[i-offset],motors_setup_ch_Y[i-offset],X_MOTORS_INTER_SPACE,Y_MOTORS_INTER_SPACE,Virtual_LCDbuff2,ARGB_clear);
      //sysprintf("\r\nnow_status:,%d,%d",p_home_motors_item_d[i]->now_status,t_home_load_d_ico.last_status);
			if(i==0)
			sprintf(display_buf,"CH9+CH10");
			else if(i==1)
			sprintf(display_buf,"CH10+CH9");
			else if(i==2)
			sprintf(display_buf,"CH11+CH12");
			else if(i==3)
			sprintf(display_buf,"CH12+CH11");
			
		/*	ch = loads_display_motors_ch[now_dialog_motors_ch_select_ch];
		if(switch_ch_list_return[ch]==9)
			now_dialog_motors_ch_select_num=1;
		else if(switch_ch_list_return[ch]==10)
			now_dialog_motors_ch_select_num=2;
		else if(switch_ch_list_return[ch]==11)
			now_dialog_motors_ch_select_num=3;	
		else if(switch_ch_list_return[ch]==12)
			now_dialog_motors_ch_select_num=4;
		else
			now_dialog_motors_ch_select_num=1;
			*/
			
			if((i+1)==now_dialog_motors_ch_select_num)
			{
			  Virtual_LCD_Draw_String_ARGB_24_4bit_bold(motors_setup_ch_X[i-offset]+0,motors_setup_ch_Y[i-offset]+10,display_buf,0xFF82c2ff,0,1,1);
			}
			else //if(switch_ch_list_return[i] == 0)
			{
				 
				for(j=0;j<SWITCH_NAME_CH_NUM;j++)
				{
				   if(switch_ch_list_return[j]==(i+9))
						 break;
				}
				if(j==SWITCH_NAME_CH_NUM)
				{	
			     Virtual_LCD_Draw_String_ARGB_24_4bit_bold(motors_setup_ch_X[i-offset]+0,motors_setup_ch_Y[i-offset]+10,display_buf,ARGB_white,0,1,1);
				}
				else
				Virtual_LCD_Draw_String_ARGB_24_4bit_bold(motors_setup_ch_X[i-offset]+0,motors_setup_ch_Y[i-offset]+10,display_buf,0xFF838697,0,1,1);
			}
			
			if(upgrade==FALSE)
			{
			   Virtual_LCD_Upgrate_formx1y1(motors_setup_ch_X[i-offset],motors_setup_ch_Y[i-offset],130,90);
			  // Virtual_LCD_Upgrate();
			}
			
			
	
	 }
		

 }
}
	


BOOL page_dialog_motors_ch_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
	return FALSE;
}


void ui_out_dialog_motors(void)
{
	u8 i;
    //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
	 // set_motors_item_key_type(KEY_TYPE_LONG_PRESS);
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
		for(i=0;i<3;i++)
	  dialog_motors_item[4+i].now_status = STATUS_IDLE;
}

bool f_need_ui_disply_dialog_motors = FALSE;
void ui_disply_dialog_motors(void)
{
	lcd_dis_page_t *p;
	u8 i,ch;
	f_need_ui_disply_dialog_motors = FALSE;
	p = &page_home.page_dialog_motors;	
 sysprintf("\r\n eeeeeeeeeeeeeee");
  //Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff3,ARGB_clear);
	//Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val,p->item[0].y_val,p->item[0].x_end_val-p->item[0].x_val,p->item[0].y_end_val-p->item[0].y_val,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_dialog_motors = TRUE;
	
	
	now_dialog_motors_icon_select_ch = switch_name_list_return[loads_display_motors_ch[loads_motor_u_ico_select_ch]].icon_select;
	dialog_motors_item[now_dialog_motors_icon_select_ch+4].now_status = STATUS_SELECT;//选中第一个图标	 
	
	
	//Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+20,p->item[0].y_val+70,"Icon:",0xFF82c2ff,0,1,1);
	
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_motors_deel_with_i(p,&i))
							 break;
			
		 // sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
			//sysprintf("\r\n i:%d",i);
	 }
	 //char_input_len =0;
	 //disply_char_input_val(TRUE);
	// sysprintf("\r\n eeeeeeeeeeeeeem");
	// while(1);
	  f_ui_disply_dialog_motors_ch = TRUE;
	//dialog_motors_ch_item[7].now_status = STATUS_SELECT;//???Dμúò???í?±ê	 
	ch = loads_display_motors_ch[now_dialog_motors_ch_select_ch];//?òμ???ó|μ??a1?o?
	 
	 
		if(switch_ch_list_return[ch]==9)
			now_dialog_motors_ch_select_num=1;
		else if(switch_ch_list_return[ch]==10)
			now_dialog_motors_ch_select_num=2;
		else if(switch_ch_list_return[ch]==11)
			now_dialog_motors_ch_select_num=3;	
		else if(switch_ch_list_return[ch]==12)
			now_dialog_motors_ch_select_num=4;
		else
			now_dialog_motors_ch_select_num=1;
	//now_dialog_motors_ch_select_num = switch_ch_list_return[ch];
	
	// Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+20,p->item[0].y_val+Y_INTER_OFFET+10," Ch :",0xFF82c2ff,0,1,1);

	
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_motors_ch_deel_with_i(p,&i))
							 break;
			
		  //sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }
	 //char_input_len =0;
	 //disply_char_input_val(TRUE);
	 disply_motors_ch_name(TRUE);
	 //sysprintf("\r\n eeeeeeeeeeeeeed");
   Virtual_LCD_Upgrate();

}


///////////////////////初始化////////////////////////////////////////


void ui_dialog_motors_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_dialog_motors;
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=DIALOG_MOTORS_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


   t_dialog_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_motors_dialog_close_d.key_type = KEY_TYPE_ONCE;
	 t_motors_dialog_save_d.key_type = KEY_TYPE_ONCE;
   //t_lights_none_c.key_type = KEY_TYPE_TOUCH_NONE;
	 t_lights_none_u.key_type = KEY_TYPE_TOUCH_NONE;
	 
   p->item = dialog_motors_item;
   for(i=0;i<DIALOG_MOTORS_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_dialog_motors_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_dialog_motors_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_dialog_motors_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 f_ui_disply_dialog_motors = FALSE;
	 f_ui_disply_dialog_motors_ch = FALSE;
 }


