#include "includes.h"

#define KEYBOARD_ICON_NUM 15

lcd_dis_item_t *p_keyboard_item_5cun_d[KEYBOARD_ICON_NUM]=
{
	&t_keyboard_5cun_bg      ,
	&t_keyboard_5cun_0_d     ,
	&t_keyboard_5cun_1_d     ,
	&t_keyboard_5cun_2_d     ,
	&t_keyboard_5cun_3_d     ,
	&t_keyboard_5cun_4_d     ,
	&t_keyboard_5cun_5_d     ,
	&t_keyboard_5cun_6_d     ,
	&t_keyboard_5cun_7_d     ,
	&t_keyboard_5cun_8_d     ,
	&t_keyboard_5cun_9_d     ,
	&t_keyboard_5cun_dot_d   ,
	&t_keyboard_5cun_delete_d,
	&t_keyboard_5cun_close_d ,
	&t_keyboard_5cun_enter_d ,
};

lcd_dis_item_t *p_keyboard_item_5cun_u[KEYBOARD_ICON_NUM]=
{
	&t_keyboard_5cun_bg      ,
	&t_keyboard_5cun_0_u     ,
	&t_keyboard_5cun_1_u     ,
	&t_keyboard_5cun_2_u     ,
	&t_keyboard_5cun_3_u     ,
	&t_keyboard_5cun_4_u     ,
	&t_keyboard_5cun_5_u     ,
	&t_keyboard_5cun_6_u     ,
	&t_keyboard_5cun_7_u     ,
	&t_keyboard_5cun_8_u     ,
	&t_keyboard_5cun_9_u     ,
	&t_keyboard_5cun_dot_u   ,
	&t_keyboard_5cun_delete_u,
	&t_keyboard_5cun_close_u ,
	&t_keyboard_5cun_enter_u ,
};

lcd_dis_item_t keyboard_ui_item[KEYBOARD_ICON_NUM];

bool f_ui_new_input_inv_limit_cur = FALSE;
void Write_inv_limit_cur_input_target(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	bool flag = FALSE;
	val_temp = 0;
	for(i=0;i<len;i++)
	{
		if(p[i]=='.')           //1.6
		{
			flag = TRUE;	
			continue;
		}
		val_temp += p[i]-0x30;  //1  16 
		if(!flag)
			val_temp*=10;						//10 160   
	}
	if(val_temp>500)
		val_temp=500;
	else if(val_temp<55)
		val_temp=55;
	parts_set_return_status.Inverter_Input_Current_Limit = val_temp;
	send_FlC200_set_cmd(0x4A,val_temp);
}
bool limit_val_input_5chun(char *p,u8 len)
{
	u8 i;
	u32 val_temp;
	val_temp = 0;
	static bool get_bot_next_time = TRUE;
	
	get_bot_next_time = TRUE;
	for(i=0;i<len;i++)
	{
		if(char_input_target_type == 1) //逆变器限流
		{
			if((p[i]=='.')&&(get_bot_next_time))
			{
			  get_bot_next_time = FALSE;
			}
			else
			{
				if(p[i]=='.')
				{
					return TRUE;
					//break;
				}
				else
				{
					val_temp*=10;
					val_temp += p[i]-0x30;
					//if(get_bot_next_time == FALSE)
					//	return TRUE;
				}
			}
		}
		else if((char_input_target_type == 2)||(char_input_target_type == 3)) //2 电池总容量 3电池百分比
		{
			if(p[i]=='.')
			{
				get_bot_next_time = FALSE;
			}
			else
			{
				val_temp*=10;
				val_temp += p[i]-0x30;
			}
		}
	}
	if(char_input_target_type == 1) //逆变器限流
	{
		if(get_bot_next_time==FALSE)
			;//val_temp*=10;
		else
		{
			if(val_temp==50)
			{
				if(get_bot_next_time==FALSE)
				{
					sysprintf(" 11 val_temp = %d \r\n",val_temp);
					return TRUE;
				}
			}
		}
		if((val_temp>500)&&(get_bot_next_time==FALSE))
		{
			sysprintf(" 22 val_temp = %d \r\n",val_temp);
			return TRUE;
		}
		else if((val_temp>50)&&(get_bot_next_time==TRUE))
		{
			sysprintf(" 33 val_temp = %d \r\n",val_temp);
			return TRUE;
		}
		
	}
	else if(char_input_target_type == 2) //电池总容量
	{
		if(get_bot_next_time==FALSE)
			return TRUE;
		if(val_temp>1000)
			return TRUE;
	}
	else if(char_input_target_type == 3) //电池百分比
	{
		if(get_bot_next_time==FALSE)
			return TRUE;
		if(val_temp>100)
			return TRUE;
	}
	return FALSE;
}
void disply_input_val(bool upgrade)
{
	static char last_char_input_len = 0;
	static u32 IdelTime = 0;
	static bool f_flash = TRUE;
	char display_buf[32];
	
	if(f_ui_disply_keyboard==FALSE)
		return;
	if(IdelTime == 0) ResetDelayTime(&IdelTime);
	
	if((last_char_input_len!=char_input_len)||upgrade||(CntDelayTime(&IdelTime,TIME_ONE_MS*750)))
	{
		last_char_input_len=char_input_len;
		ResetDelayTime(&IdelTime);
		
		Virtual_LCD_Draw_Rectangle_ARGB32(500,250,200,100,Virtual_LCDbuff2,ARGB_clear);
		if(f_flash)
		{
			char_input_buf[last_char_input_len] = '|';
			f_flash = FALSE;
		}
		else
		{
			char_input_buf[last_char_input_len] = ' ';
			f_flash = TRUE;
		}
		char_input_buf[last_char_input_len+1] = '\0';
		
		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(592,258,char_input_buf,ARGB_white,0,1,1);
		
		if(char_input_target_type==1)	
		{
			sprintf(display_buf,"(Max50)");
			Virtual_LCD_Draw_String_ARGB_24_4bit(545,319,display_buf,ARGB_white,0,1,1);
		}
		else if(char_input_target_type==2)	
		{
			sprintf(display_buf,"(Max1000)");
			Virtual_LCD_Draw_String_ARGB_24_4bit(545,319,display_buf,ARGB_white,0,1,1);
		}
		else if(char_input_target_type==3)	
		{
			sprintf(display_buf,"(Max100)");
			Virtual_LCD_Draw_String_ARGB_24_4bit(545,319,display_buf,ARGB_white,0,1,1);
		}
		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(500,250,200,100);
	}
}
void keyboard_input_val(u8 asiic)
{
  if((asiic>=0x20)&&(asiic<=0x7E))
	{
		if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_HOME)
		{
			if(((asiic>=0x30)&&(asiic<=0x39))||(asiic=='.'))
			{
				if(char_input_len<(7))
				{
					char_input_buf[char_input_len] = asiic;
					char_input_len++;
					if(limit_val_input_5chun(char_input_buf,char_input_len))
					{
						char_input_len--;
					}
					else
					{
						keyboard_val_limit_type = 2;
						disply_input_val(FALSE);
					}
				}
			}
		}
	}
	else if(asiic==0x08)//退格
	{
	  if(char_input_len>0)	
		{			
			char_input_len--;
			disply_input_val(FALSE);
		}
	}
	else if(asiic==0x0E)//shift out
	{
		keyboard_ui_step=KEYBOARD_PAGE_NOR;
		ui_disply_auxilary_keyboard(TRUE);
	}
	else if(asiic==0x0F)//shift in
	{
		keyboard_ui_step=KEYBOARD_PAGE_CAPS;
		ui_disply_auxilary_keyboard(TRUE);
	}
	else if(asiic==0x0D)//回车
	{
		//f_ui_out_keyboard = TRUE;
		//if(char_input_buf!=0)
	  
		//sysprintf("\r\nrrrrrrrrrrrrrrrrrrrrr");
		f_ui_disply_keyboard = FALSE;
		f_ui_out_keyboard = FALSE;
		ui_out_keyboard();
		if(char_input_len!=0)//
		{
			//sysprintf("\r\nf_ui_disply_keyboard %d",f_ui_disply_keyboard);
			if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_HOME)
			{
				if(page_home.page_top_side->now_item == TOP_SIDE_PAGE_HOME_SETUP2)
				{
				//Write_char_input_target(char_input_buf,char_input_len);
					if(f_ui_new_input_bat_capacity)
					{
						f_ui_new_input_bat_capacity = FALSE;
						Write_bat_capacity_input_target(char_input_buf,char_input_len);
					}
					else  if(f_ui_new_input_bat_percenage)
					{
						f_ui_new_input_bat_percenage = FALSE;
						Write_bat_percenage_input_target(char_input_buf,char_input_len);
					}
					else if(f_ui_new_input_inv_limit_cur)
					{
						f_ui_new_input_inv_limit_cur = FALSE;
						Write_inv_limit_cur_input_target(char_input_buf,char_input_len);
					}
					else if(f_ui_new_input_code_enter)
					{
						f_ui_new_input_code_enter = FALSE;
						Write_code_enter_target(char_input_buf,char_input_len);
					}
				}
			}
			//if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_TANKS)
			//{
			//	Write_val_input_target(char_input_buf,char_input_len);
			//}
			//else if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_POWER)
			//{
			//	Write_val_input_target_power(char_input_buf,char_input_len);
			//}
			//else if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
			//{
			//	if(f_ui_new_input_code)
			//	{
			//		f_ui_new_input_code = FALSE;
			//		Write_code_input_target(char_input_buf,char_input_len);
			//	}
			//	else  if(f_ui_new_input_bat_capacity)
			//	{
			//		f_ui_new_input_bat_capacity = FALSE;
			//		Write_bat_capacity_input_target(char_input_buf,char_input_len);
			//	}
			//	else  if(f_ui_new_input_bat_percenage)
			//	{
			//		f_ui_new_input_bat_percenage = FALSE;
			//		Write_bat_percenage_input_target(char_input_buf,char_input_len);
			//	}
			//	else  if(f_ui_new_input_code_enter)
			//	{
			//		f_ui_new_input_code_enter = FALSE;
			//		Write_code_enter_target(char_input_buf,char_input_len);
			//	}
			//}
		}
		else			
		{
		   f_ui_new_input_code = FALSE;
       f_ui_new_input_bat_capacity = FALSE;
       f_ui_new_input_bat_percenage = FALSE;
			 f_ui_new_input_code_enter = FALSE;
		}
	}
	else if(asiic==0x1b)
	{
		f_ui_disply_keyboard = FALSE;
		f_ui_out_keyboard = FALSE;
		ui_out_keyboard();
	}
	//else if(asiic==0xFF)//123  
	//{
	//	keyboard_item[3].last_status = STATUS_IDLE;
	//	keyboard_item[3].now_status = STATUS_IDLE;
	//  keyboard_ui_step=KEYBOARD_PAGE_NUM;
	//  ui_disply_auxilary_keyboard(TRUE);
	//}
	//else if(asiic==0xFE)//ABC
	//{
	//	keyboard_item[3].last_status = STATUS_IDLE;
	//	keyboard_item[3].now_status = STATUS_IDLE;
	//  keyboard_ui_step=KEYBOARD_PAGE_NOR;
	//	ui_disply_auxilary_keyboard(TRUE);
	//}
}
void ui_disply_auxilary_keyboard(bool keep_input)
{
	lcd_dis_page_t *p;
	u8 i;
	
	f_need_ui_disply_keyboard = FALSE;
	p = &page_home.page_keyboard;	
	Virtual_LCD_Draw_Rectangle_ARGB32(0,221,800,259,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(0,221,800,259,Virtual_LCDbuff2,ARGB_clear);
	f_ui_disply_keyboard = TRUE;
	for(i=0;i<p->item_num;i++)
	{
		if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
		else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	}
	if(keep_input==0)
		char_input_len =0;
	disply_input_val(TRUE);
	Virtual_LCD_Upgrate();
}

//////////////////////////////////////////////////
void ui_auxilary_keyboard_init_5(void)
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_keyboard;
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_bg_5_cun_new.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_bg_5_cun_new.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
	p->item_num=KEYBOARD_ICON_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	p->sub_page_count = 0x00; //定义好子页面数目
	p->sub_page = NULL;//
	
	t_keyboard_5cun_bg.key_type = KEY_TYPE_TOUCH_NONE;
	t_keyboard_5cun_0_d.key_type = KEY_TYPE_ONCE;    
	t_keyboard_5cun_1_d.key_type = KEY_TYPE_ONCE;    
	t_keyboard_5cun_2_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_3_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_4_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_5_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_6_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_7_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_8_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_9_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_dot_d.key_type = KEY_TYPE_ONCE;  
	t_keyboard_5cun_delete_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_close_d.key_type = KEY_TYPE_ONCE;
	t_keyboard_5cun_enter_d.key_type = KEY_TYPE_ONCE;
	
	p->item = keyboard_ui_item;
	for(i=0;i<KEYBOARD_ICON_NUM;i++)
	{
		memcpy(&(p->item[i]),p_keyboard_item_5cun_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_keyboard_item_5cun_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_keyboard_item_5cun_u[i]->size_of_pic_item ;
	}
	
	f_ui_disply_keyboard = FALSE;
}

