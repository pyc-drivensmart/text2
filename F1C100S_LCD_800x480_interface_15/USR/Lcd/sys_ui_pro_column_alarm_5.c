#include "includes.h"

#define ALARM_PAGE_ITEM_NUM  8
//&t_Alarm_normal_flag_logo_5    , //无警告标志
lcd_dis_item_t *p_alarm_item_5_up[ALARM_PAGE_ITEM_NUM]=
{
	&t_Alarm_info_column_0         ,
	&t_Alarm_info_column_1         ,
	&t_Alarm_info_column_2         ,
	&t_Alarm_info_column_3         ,
	&t_Alarm_info_column_4         ,
	&t_Alarm_info_column_5         ,//实则放不下不显示，做占位

       &t_page_alarm_down_up  ,
    &t_page_alarm_up_up    ,
    
    
    
    
    
};
lcd_dis_item_t *p_alarm_item_5_down[ALARM_PAGE_ITEM_NUM]=
{
	&t_Alarm_info_column_0_d			 ,
	&t_Alarm_info_column_1         ,
	&t_Alarm_info_column_2         ,
	&t_Alarm_info_column_3         ,
	&t_Alarm_info_column_4         ,
	&t_Alarm_info_column_5         ,
//   	&t_Alarm_page_next_down_5  ,//向上翻页（按下）6
//	&t_Alarm_page_pre_down_5       ,//向下翻页（按下）7
       &t_page_alarm_down_d   ,    //向下翻页（按下）7
 
        &t_page_alarm_up_d     ,//向上翻页（按下）6
};

lcd_dis_item_t Alarm_page_item[ALARM_PAGE_ITEM_NUM];

void ui_column_alarm_init_5(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][6]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_bg_5_cun_new.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_bg_5_cun_new.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
	p->item_num=ALARM_PAGE_ITEM_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	p->sub_page_count = 0x00; //定义好子页面数目
	p->sub_page = NULL;//
	p->fat_page = NULL;
	
	t_Alarm_info_column_0.key_type = KEY_TYPE_TOUCH_NONE;//选框背景
	t_Alarm_info_column_1.key_type = KEY_TYPE_TOUCH_NONE;
	t_Alarm_info_column_2.key_type = KEY_TYPE_TOUCH_NONE;
	t_Alarm_info_column_3.key_type = KEY_TYPE_TOUCH_NONE;
	t_Alarm_info_column_4.key_type = KEY_TYPE_TOUCH_NONE;
	t_Alarm_info_column_5.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//放不下不显示
    
	t_Alarm_warning_flag_logo_5.key_type   = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_warning_flag_logo_5_1.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_warning_flag_logo_5_2.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_warning_flag_logo_5_3.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_warning_flag_logo_5_4.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_warning_flag_logo_5_5.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
    
	t_Alarm_error_flag_logo_5.key_type   = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_error_flag_logo_5_1.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_error_flag_logo_5_2.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_error_flag_logo_5_3.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_error_flag_logo_5_4.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	t_Alarm_error_flag_logo_5_5.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
    
	t_Alarm_normal_flag_logo_5.key_type = KEY_TYPE_TOUCH_NONE;  //无警告标志
	t_Alarm_page_next_down_5.key_type   = KEY_TYPE_ONCE;//翻页按键单次点击
	t_Alarm_page_pre_down_5.key_type    = KEY_TYPE_ONCE;
	
	
	p->item = Alarm_page_item;
	for(i=0;i<ALARM_PAGE_ITEM_NUM;i++)
	{
		memcpy(&(p->item[i]),p_alarm_item_5_down[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_alarm_item_5_up[i]->pic_item;//
		p->item[i].size_of_pic_item = p_alarm_item_5_up[i]->size_of_pic_item ;
	}
}


void ui_column_alarm_info_printf(u8 num,lcd_dis_item_t* p,WARNING_CODE_LIST* p_list,u8 list_num)
{
	u8 item_num=0;
	char display_buf[64];
	lcd_dis_item_t *p_y,*p_r;
	item_num = num%5;//项数(带顶项)
	switch(item_num)//页数
	{
		case 0:
			p_r=&t_Alarm_error_flag_logo_5;//红色错误图标
		  p_y=&t_Alarm_warning_flag_logo_5;//黄色警告
			break;
	  case 1:
			p_r=&t_Alarm_error_flag_logo_5_1;
		  p_y=&t_Alarm_warning_flag_logo_5_1;
			break;
	
		case 2:
			p_r=&t_Alarm_error_flag_logo_5_2;
		  p_y=&t_Alarm_warning_flag_logo_5_2;
			break;
	
		case 3:
			p_r=&t_Alarm_error_flag_logo_5_3;
		  p_y=&t_Alarm_warning_flag_logo_5_3;
			break;
		case 4:
			p_r=&t_Alarm_error_flag_logo_5_4;
			p_y=&t_Alarm_warning_flag_logo_5_4;
			break;

	  default :
			return;
			//break;
	}
    //判断警报类型显示相图标
	if((p_list[num].err_code_type==2)||(p_list[num].err_code_type==3))//=1：警告  =2：故障/错误  =3：保护  =4：没连接 
		 png_dis_xy(p_r->x_val,p_r->y_val,p_r->pic_item,p_r->size_of_pic_item,Virtual_LCDbuff2);
	else
	   png_dis_xy(p_y->x_val,p_y->y_val,p_y->pic_item,p_y->size_of_pic_item,Virtual_LCDbuff2); 
	//警报时间
	sprintf(display_buf,"%d/%d %02d-%02d-%02d %02d:%02d:%02d  ",num,list_num,\
					p_list[num].time_happen.year,\
					p_list[num].time_happen.mon,\
					p_list[num].time_happen.day,\
					p_list[num].time_happen.hour,\
					p_list[num].time_happen.min,\
					p_list[num].time_happen.sec);
	
	Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_system_system_offset,p->y_val+Y_system_system_offset-10,display_buf,(ARGB_gray),0,1,1);
  Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+X_system_system_offset,p->y_val+Y_system_system_offset+10,&p_list[num].txt[0],(0xFFe2e2e4),0,1,1);		
}
void ui_column_alarm_display_info(bool upgrade)
{
	u16 i;//,addr;
	u8 temp;
	lcd_dis_item_t* p;
	lcd_dis_item_t* p2;
	
	if(upgrade)
	{
		p=Alarm_page_item;
		sysprintf("\r\n page:%04X,%X",now_page_alarm,now_page_alarm_deep);
		if(now_page_alarm_deep==0)//第一层
		{
			for(i=0;TRUE;i++)
			{
				if((i*0x1000)==now_page_alarm)
				{
					if(now_page_alarm==0x0000)
					{
						p[7].key_type = KEY_TYPE_TOUCH_NONE;//下翻禁止
						p[7].now_status = STATUS_IDLE;
						p[7].last_status = STATUS_IDLE;
					}
					else	
					{
						p[7].key_type = KEY_TYPE_ONCE;//下翻启用
						p[7].now_status = STATUS_IDLE;
						p[7].last_status = STATUS_IDLE;
					}
					p[6].key_type = KEY_TYPE_ONCE;//可以上翻
					Virtual_LCD_Draw_Rectangle_ARGB32(p[0].x_val,p[0].y_val,p[0].x_end_val-p[0].x_val,p[0].y_end_val-p[0].y_val,Virtual_LCDbuff2,ARGB_clear);
					Virtual_LCD_Draw_Rectangle_ARGB32(p[1].x_val,p[1].y_val,p[1].x_end_val-p[1].x_val,p[1].y_end_val-p[1].y_val,Virtual_LCDbuff2,ARGB_clear);
					Virtual_LCD_Draw_Rectangle_ARGB32(p[2].x_val,p[2].y_val,p[2].x_end_val-p[2].x_val,p[2].y_end_val-p[2].y_val,Virtual_LCDbuff2,ARGB_clear);
					Virtual_LCD_Draw_Rectangle_ARGB32(p[3].x_val,p[3].y_val,p[3].x_end_val-p[3].x_val,p[3].y_end_val-p[3].y_val,Virtual_LCDbuff2,ARGB_clear);
					Virtual_LCD_Draw_Rectangle_ARGB32(p[4].x_val,p[4].y_val,p[4].x_end_val-p[4].x_val,p[3].y_end_val-p[3].y_val,Virtual_LCDbuff2,ARGB_clear);
				//	Virtual_LCD_Draw_Rectangle_ARGB32(p[5].x_val,p[5].y_val,p[5].x_end_val-p[5].x_val,p[3].y_end_val-p[3].y_val,Virtual_LCDbuff2,ARGB_clear);
				
					if(i==0)//页数1
					{
						p[0].key_type = KEY_TYPE_TOUCH_NONE;
						Virtual_LCD_Draw_Rectangle_ARGB32(28,56,660,76,Virtual_LCDbuff2,ARGB_clear);
						if(waining_code_list_num>=1)
						{
							Virtual_LCD_Draw_String_ARGB_24_4bit(p[0].x_val+X_system_system_offset,p[0].y_val+Y_system_system_offset,"                                  Clear All",(0xFFe2e2e4),0,1,1);
							p[0].key_type = KEY_TYPE_ONCE;
						}
						else//无警告
						{
							Virtual_LCD_Draw_String_ARGB_24_4bit(p[0].x_val+X_system_system_offset,p[0].y_val+Y_system_system_offset,"No Fault Or Warning Information",(0xFFe2e2e4),0,1,1);
							p2 = &t_Alarm_normal_flag_logo_5;//无警告标志
							png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff2); 
							p[6].key_type = KEY_TYPE_TOUCH_NONE;//上，下翻禁止
							p[7].key_type = KEY_TYPE_TOUCH_NONE;
							p[6].now_status = STATUS_IDLE;
							p[6].last_status = STATUS_IDLE;
							p[7].now_status = STATUS_IDLE;
							p[7].last_status = STATUS_IDLE;
						}
					}
					else//页>1,可以翻页
					{
						p[7].key_type = KEY_TYPE_ONCE;
						p[0].key_type = KEY_TYPE_TOUCH_NONE;
					///	temp = i*6;///
                        temp = i*5;///

						if(waining_code_list_num>=temp)
						{
							ui_column_alarm_info_printf(temp,&p[0],waining_code_list,waining_code_list_num);		
							if(waining_code_list_num==temp)
							{
								p[6].key_type = KEY_TYPE_TOUCH_NONE;//上翻禁止
								p[6].now_status = STATUS_IDLE;
								p[6].last_status = STATUS_IDLE;
								break;
							}
						}
					}
					//2					
					temp = 1+i*5;
					if(waining_code_list_num>=temp)
					{
						ui_column_alarm_info_printf(temp,&p[1],waining_code_list,waining_code_list_num);			
						if(waining_code_list_num==temp)
						{
							p[6].key_type = KEY_TYPE_TOUCH_NONE;//上翻禁止
							p[6].now_status = STATUS_IDLE;
							p[6].last_status = STATUS_IDLE;
							break;
						}
					}
					//3
					temp = 2+i*5;
					if(waining_code_list_num>=temp)
					{					
						ui_column_alarm_info_printf(temp,&p[2],waining_code_list,waining_code_list_num);		
						if(waining_code_list_num==temp)
						{
							p[6].key_type = KEY_TYPE_TOUCH_NONE;//上翻禁止
							p[6].now_status = STATUS_IDLE;
							p[6].last_status = STATUS_IDLE;
							break;
						}
					}
					//4
					temp = 3+i*5;
					if(waining_code_list_num>=temp)
					{					
						ui_column_alarm_info_printf(temp,&p[3],waining_code_list,waining_code_list_num);			
						if(waining_code_list_num==temp)
						{
							p[6].key_type = KEY_TYPE_TOUCH_NONE;//上翻禁止
							p[6].now_status = STATUS_IDLE;
							p[6].last_status = STATUS_IDLE;
							break;
						}
					}
					//5
					temp = 4+i*5;
					if(waining_code_list_num>=temp)
					{					
						ui_column_alarm_info_printf(temp,&p[4],waining_code_list,waining_code_list_num);			
						if(waining_code_list_num==temp)
						{
							p[6].key_type = KEY_TYPE_TOUCH_NONE;//上翻禁止
							p[6].now_status = STATUS_IDLE;
							p[6].last_status = STATUS_IDLE;
							break;
						}
					}
										

										
					break;
				}
			}
		}
	}
}








