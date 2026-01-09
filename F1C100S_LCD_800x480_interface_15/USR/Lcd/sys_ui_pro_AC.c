#include "includes.h"


AC_PAGE ac_ui_step = AC_PAGE_NOR;
AC_PAGE last_ac_ui_step = AC_PAGE_NOR;

u16 tempt_l =225;//22.5
u16 tempt_r =225;
u16 tempt_b =225;
u8 fan = 0;
u8 fan_b = 0;




///////////////////////复用按键补充/////////////////////////////
extern void func_climatebtn_right_down_d(void* p);
extern void func_climatebtn_right_down_u(void* p);
extern void  func_climatebtn_right_up_d(void* p);
extern void  func_climatebtn_right_up_u(void* p);



//复用按键补充
extern  const unsigned char climatebtn_down_d[2972UL + 1];
extern  const unsigned char climatebtn_down_u[2972UL + 1];
extern  const unsigned char climatebtn_up_d[2972UL + 1];
extern  const unsigned char climatebtn_up_u[2972UL + 1];
lcd_dis_item_t t_climatebtn_right_down_d={(unsigned char*)climatebtn_down_d,(unsigned char*)climatebtn_down_d,(unsigned char*)climatebtn_down_d,0,0,2973,2973,2973,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_climatebtn_right_down_d,Y_climatebtn_right_down_d,X_climatebtn_right_down_d+132,Y_climatebtn_right_down_d+82,0,&func_climatebtn_right_down_d};
lcd_dis_item_t t_climatebtn_right_down_u={(unsigned char*)climatebtn_down_u,(unsigned char*)climatebtn_down_u,(unsigned char*)climatebtn_down_u,0,0,2631,2631,2631,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_climatebtn_right_down_u,Y_climatebtn_right_down_u,X_climatebtn_right_down_u+132,Y_climatebtn_right_down_u+82,0,&func_climatebtn_right_down_u};
lcd_dis_item_t t_climatebtn_right_up_d={(unsigned char*)climatebtn_up_d,(unsigned char*)climatebtn_up_d,(unsigned char*)climatebtn_up_d,0,0,3266,3266,3266,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_climatebtn_right_up_d,Y_climatebtn_right_up_d,X_climatebtn_right_up_d+132,Y_climatebtn_right_up_d+82,0,&func_climatebtn_right_up_d};
lcd_dis_item_t t_climatebtn_right_up_u={(unsigned char*)climatebtn_up_u,(unsigned char*)climatebtn_up_u,(unsigned char*)climatebtn_up_u,0,0,2755,2755,2755,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_climatebtn_right_up_u,Y_climatebtn_right_up_u,X_climatebtn_right_up_u+132,Y_climatebtn_right_up_u+82,0,&func_climatebtn_right_up_u};

	//空调界面按键列表 按下
lcd_dis_item_t *p_climate_item_d[AC_ICO_NUM]=
{
&t_bottombtn_ac_d,//0
&t_bottombtn_auto_d,//1
&t_bottombtn_frontwindow_d,//2
&t_bottombtn_innerloop_d,//3
&t_bottombtn_maxac_d,//4
&t_bottombtn_outerloop_d,//5
&t_bottombtn_sync_d,//6
	
&t_bottombtn_rearwindow_d,//7	
&t_climatebtn_body_d,//8
&t_climatebtn_down_d,//9
&t_climatebtn_feet_d,//10
&t_climatebtn_head_d,//11
&t_climatebtn_off_d,//12
&t_climatebtn_rearclimate_d,//13
&t_climatebtn_up_d,//14
&t_climate_fan_big_d,//15
&t_climate_fan_small_d,//16
	
&t_climatebtn_right_up_d,	//17
&t_climatebtn_right_down_d,//18

//////////////////////////////////////
/*
&t_rearctrl_lock_d,//19
&t_rearctrl_minusB_d,//20
&t_rearctrl_minus_d,//21
&t_rearctrl_plusR_d,//22
&t_rearctrl_plus_d,//23
&t_rearctrl_power_d,//24
&t_rearctrl_windowbg1,//25
&t_rearctrl_windowbg2,//26
	*/
};

//空调界面按键列表 弹起
lcd_dis_item_t *p_climate_item_u[AC_ICO_NUM]=
{
&t_bottombtn_ac_u,
&t_bottombtn_auto_u,
&t_bottombtn_frontwindow_u,
&t_bottombtn_innerloop_u,
&t_bottombtn_maxac_u,
&t_bottombtn_outerloop_u,
&t_bottombtn_sync_u,	
&t_bottombtn_rearwindow_u,
&t_climatebtn_body_u,
&t_climatebtn_down_u,
&t_climatebtn_feet_u,
&t_climatebtn_head_u,
&t_climatebtn_off_u,
&t_climatebtn_rearclimate_u,
&t_climatebtn_up_u,
&t_climate_fan_big,
&t_climate_fan_small,
//&t_climate_scrollbar_box,
//&t_climate_scrollbar_slider,
//&t_climate_scrollbar_value,	
	
&t_climatebtn_right_up_u,	
&t_climatebtn_right_down_u,	

//////////////////////////////////
/*
&t_rearctrl_lock_u,//19
&t_rearctrl_minusB_u,//20
&t_rearctrl_minus_u,//21
&t_rearctrl_plusR_u,//22
&t_rearctrl_plus_u,//23
&t_rearctrl_power_u,//24
&t_rearctrl_windowbg1,//25
&t_rearctrl_windowbg2,//26*/
};

lcd_dis_item_t climate_ac_item[AC_ICO_NUM];




void tempt_display(void)
{
   //static 
	u16 last_tempt_l =0xFFFF;
   //static 
	u16 last_tempt_r =0xFFFF;
	u16 last_tempt_b =0xFFFF;
	  u16 x_val=0,y_val = 0;
	 u8 data = 0;
	if(last_tempt_l!=tempt_l)
	{
	   last_tempt_l=tempt_l;
		 x_val = X_climatebtn_left_val;
		 if(last_tempt_l>=310)
			 Virtual_LCD_Draw_String_ARGB64(x_val,Y_climatebtn_left_val," HI ",(ARGB_white),0,1,1);
		 else if(last_tempt_l<=150)
	     Virtual_LCD_Draw_String_ARGB64(x_val,Y_climatebtn_left_val," LO ",(ARGB_white),0,1,1);
		 else
		 {
			  data = tempt_l/100;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_left_val,data+'0',(ARGB_white),0,1,1);
			  data = (tempt_l%100)/10;
			  x_val+=32;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_left_val,data+'0',(ARGB_white),0,1,1);
			  x_val+=32;
			  Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_left_val,'.',(ARGB_white),0,1,1);
			  data = tempt_l%10;
			  x_val+=16;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_left_val,data+'0',(ARGB_white),0,1,1);
        
		 }
	}
	
	if(last_tempt_r!=tempt_r)
	{
	  last_tempt_r=tempt_r;
		x_val = X_climatebtn_right_val;
		if(last_tempt_r>=310)
			 Virtual_LCD_Draw_String_ARGB64(x_val,Y_climatebtn_right_val," HI ",(ARGB_white),0,1,1);
		 else if(last_tempt_r<=150)
	     Virtual_LCD_Draw_String_ARGB64(x_val,Y_climatebtn_right_val," LO ",(ARGB_white),0,1,1);
		 else
		 {
			  data = tempt_r/100;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_right_val,data+'0',(ARGB_white),0,1,1);
			  data = (tempt_r%100)/10;
			  x_val+=32;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_right_val,data+'0',(ARGB_white),0,1,1);
			  x_val+=32;
			  Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_right_val,'.',(ARGB_white),0,1,1);
			  data = tempt_r%10;
			  x_val+=16;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_right_val,data+'0',(ARGB_white),0,1,1);

		 }
	
	}
  if(ac_ui_step!=AC_PAGE_REAR)
	return;
	if(last_tempt_b!=tempt_b)
	{
	  last_tempt_b=tempt_b;
		x_val = X_climatebtn_rear_val;
		if(last_tempt_b>=310)
			 Virtual_LCD_Draw_String_ARGB64(x_val,Y_climatebtn_rear_val," HI ",(ARGB_white),0,1,1);
		 else if(last_tempt_b<=150)
	     Virtual_LCD_Draw_String_ARGB64(x_val,Y_climatebtn_rear_val," LO ",(ARGB_white),0,1,1);
		 else
		 {
			  data = tempt_b/100;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_rear_val,data+'0',(ARGB_white),0,1,1);
			  data = (tempt_b%100)/10;
			  x_val+=32;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_rear_val,data+'0',(ARGB_white),0,1,1);
			  x_val+=32;
			  Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_rear_val,'.',(ARGB_white),0,1,1);
			  data = tempt_b%10;
			  x_val+=16;
		    Virtual_LCD_Draw_ASCII_ARGB64(x_val,Y_climatebtn_rear_val,data+'0',(ARGB_white),0,1,1);

		 }
	
	}

}



void fan_display(void)
{
	  lcd_dis_item_t *p;
	  u8 last_fan =0xFF;//0-7
	  u8 last_fan_b =0xFF;//0-7
	  if(last_fan!=fan)
		{
		   last_fan=fan;
		   switch(fan)
			 {
			    case 0:
						 p=&t_climate_fan_0;
					   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
					break;
					case 1:
						 p=&t_climate_fan_1;
					   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
					break;
					case 2:
						 p=&t_climate_fan_2;
					   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
					break;
					case 3:
						 p=&t_climate_fan_3;
					   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
					break;
					case 4:
						 p=&t_climate_fan_4;
					   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
					break;
					case 5:
						 p=&t_climate_fan_5;
					   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
					break;
					case 6:
						 p=&t_climate_fan_6;
					   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
					break;
					case 7:
						 p=&t_climate_fan_7;
					   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
					break;
			 }

		
		}
		if(ac_ui_step!=AC_PAGE_REAR)
	  return;
		if(last_fan_b!=fan_b)
		{
		   last_fan_b=fan_b;
			 if(fan_b>7)fan_b = 7;
			 Virtual_LCD_Draw_ASCII_ARGB64(X_climate_fan_rear,Y_climate_fan_rear,fan_b+'0',(0xFF0fbbf6),0,1,1);
		}
}


BOOL page_ac_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
  if(page_home.page_left_side.now_item == LEFT_SIDE_PAGE_AC)
						 {
						  if(p2->now_item == TOP_SIDE_PAGE_AC_CLIMATE)
						{
						  if(ac_ui_step==AC_PAGE_NOR)
							{
							   if(*i==19)return TRUE;
							
							}
							else if(ac_ui_step==AC_PAGE_REAR)
							{
								 if(*i==0)*i=8;
							   //if(*i==26)return TRUE;
							}
						}
						}
						 return FALSE;

}
///////////////////////初始化////////////////////////////////////////


void ui_AC_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_AC][TOP_SIDE_PAGE_AC_CLIMATE];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=140;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=81;
	 p->x_end_val=1024;
	 p->y_end_val=600;
	 p->item_num=AC_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only



   t_climatebtn_up_d.key_type = KEY_TYPE_ONCE;
	 t_climatebtn_down_d.key_type = KEY_TYPE_ONCE;
	 t_climate_fan_small_d.key_type = KEY_TYPE_ONCE;
	 t_climate_fan_big_d.key_type = KEY_TYPE_ONCE;
	 t_climatebtn_right_down_d.key_type = KEY_TYPE_ONCE;
	 t_climatebtn_right_up_d.key_type = KEY_TYPE_ONCE;
	 /*
	 t_rearctrl_minusB_d.key_type = KEY_TYPE_ONCE;
	 t_rearctrl_minus_d.key_type = KEY_TYPE_ONCE;
	 t_rearctrl_plusR_d.key_type = KEY_TYPE_ONCE;\
	 t_rearctrl_plus_d.key_type = KEY_TYPE_ONCE;
*/
   p->item = climate_ac_item;
   for(i=0;i<AC_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_climate_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_climate_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_climate_item_u[i]->size_of_pic_item ;
	 
	 }
 }
