#include "includes.h"

#if 0 
#define TANK_5_CHUN_ITME_NUM 6
#define TANK_5_CHUN_SUB_PAGE_ITEM_NUM 9
#define TANK_5_CHUN_SUB_PAGE_NUM 4
lcd_dis_item_t *p_tank_item_5_chun_u[TANK_5_CHUN_ITME_NUM]={
	&t_tank_balck_val_5,
	&t_tank_fresh_val_5,
	&t_tank_gray_val_5 ,
	&t_tank_lpg_val_5  ,
	&t_tank_water_heater_up_5,
	&t_tank_water_pump_up_5,
};
lcd_dis_item_t *p_tank_item_5_chun_d[TANK_5_CHUN_ITME_NUM]={
	&t_tank_balck_val_5,
	&t_tank_fresh_val_5,
	&t_tank_gray_val_5 ,
	&t_tank_lpg_val_5  ,
	&t_tank_water_heater_down_5,
	&t_tank_water_pump_down_5,
};

lcd_dis_item_t *p_tank_sub_page_1_item_5_chun[TANK_5_CHUN_SUB_PAGE_ITEM_NUM]={
	&t_tank_column_1_5,
	&t_tank_column_2_5,
	&t_tank_column_3_5,
	&t_tank_column_4_5,
	&t_tank_column_5_5,
	&t_tank_column_6_5,
	//&t_tank_column_7_5,
	&t_tank_column_right_add_1_5,
	&t_tank_solumn_left_sub_1_5,
	&t_tank_solumn_return_5,
};

lcd_dis_item_t tank_5_chun_item[TANK_5_CHUN_ITME_NUM];
lcd_dis_item_t tank_sub_page_1_item[TANK_5_CHUN_SUB_PAGE_ITEM_NUM];
void ui_column_tanks_black_or_white_sub_page_init_5(u8 show_state_now,u8 demo_mode_now);

void ui_column_tank_sub_page_1_init(void)
{
	lcd_dis_page_t *p;
	//u8 i = 0;
	
	for(u8 j = 0;j<TANK_5_CHUN_SUB_PAGE_NUM;j++)
	{
		p=page_home.page_main_item[LEFT_SIDE_PAGE_HOME][TOP_SIDE_PAGE_HOME_TANK].sub_page[j];
		p->sub_page = NULL;
		p->sub_page_count = 0;
		p->pic_back_g = t_bg_5_chun.pic_item;//poit to backgroud pic
		p->size_of_pic_back=t_bg_5_chun.size_of_pic_item;// backgroud pic size
		p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
		p->y_val=0;
		p->x_end_val=MAIN_AREA_X_END;
		p->y_end_val=MAIN_AREA_Y_END;
		p->item_num=TANK_5_CHUN_SUB_PAGE_ITEM_NUM;// how many item
		p->now_item = 0;// for "page_left_side" and "page_top_side" only 
		p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	}
	t_tank_column_1_5.key_type = KEY_TYPE_TOUCH_NONE;
	t_tank_column_2_5.key_type = KEY_TYPE_TOUCH_NONE;
	t_tank_column_3_5.key_type = KEY_TYPE_TOUCH_NONE;
	t_tank_column_4_5.key_type = KEY_TYPE_TOUCH_NONE;
	t_tank_column_5_5.key_type = KEY_TYPE_TOUCH_NONE;
	t_tank_column_6_5.key_type = KEY_TYPE_TOUCH_NONE;
	
	t_tank_column_right_add_1_5.key_type = KEY_TYPE_ONCE;
	t_tank_solumn_left_sub_1_5.key_type = KEY_TYPE_ONCE;
	t_tank_solumn_return_5.key_type = KEY_TYPE_ONCE;
	
	
	ui_column_tanks_black_or_white_sub_page_init_5(show_mode,demo_mode);
}
void ui_column_tanks_black_or_white_sub_page_init_5(u8 show_state_now,u8 demo_mode_now)
{
	lcd_dis_page_t *p;
	u8 i;
	
	for(u8 j=0;j<4;j++)
	{
		p = page_home.page_main_item[LEFT_SIDE_PAGE_HOME][TOP_SIDE_PAGE_HOME_TANK].sub_page[j];
		
		p->item = tank_sub_page_1_item;
		
		if(show_state_now == 0x00)
		{
			for(i=0;i<TANK_5_CHUN_SUB_PAGE_ITEM_NUM;i++)
			{
				memcpy(&(p->item[i]),p_tank_sub_page_1_item_5_chun[i],sizeof(lcd_dis_item_t));
				p->item[i].pic_item =p_tank_sub_page_1_item_5_chun[i]->pic_item;//
				p->item[i].size_of_pic_item = p_tank_sub_page_1_item_5_chun[i]->size_of_pic_item ;
			}
		}
		else if(show_state_now == 0x01)
		{
			for(i=0;i<TANK_5_CHUN_SUB_PAGE_ITEM_NUM;i++)
			{
				memcpy(&(p->item[i]),p_tank_sub_page_1_item_5_chun[i],sizeof(lcd_dis_item_t));
				p->item[i].pic_item =p_tank_sub_page_1_item_5_chun[i]->pic_item;//
				p->item[i].size_of_pic_item = p_tank_sub_page_1_item_5_chun[i]->size_of_pic_item ;
			}
		}
	}
}

void ui_column_tank_init_5(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][TOP_SIDE_PAGE_HOME_TANK]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_bg_5_chun.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_bg_5_chun.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
	p->item_num=TANK_5_CHUN_ITME_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	
	t_tank_black_bg_5.key_type =KEY_TYPE_TOUCH_NONE;
	t_tank_fresh_bg_5.key_type =KEY_TYPE_TOUCH_NONE;
	t_tank_gray_bg_5.key_type =KEY_TYPE_TOUCH_NONE;
	t_tank_lpg_bg_5.key_type =KEY_TYPE_TOUCH_NONE;
	t_tank_black_wave_5.key_type =KEY_TYPE_TOUCH_NONE;
	t_tank_fresh_wave_5.key_type =KEY_TYPE_TOUCH_NONE;
	t_tank_gray_wave_5.key_type =KEY_TYPE_TOUCH_NONE;
	t_tank_lpg_wave_5.key_type =KEY_TYPE_TOUCH_NONE;
	t_tank_balck_val_5.key_type =KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE;
	t_tank_fresh_val_5.key_type =KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE;
	t_tank_gray_val_5.key_type =KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE;
	t_tank_lpg_val_5.key_type =KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE;
	
	
	
	
	t_tank_water_heater_down_5.key_type = KEY_TYPE_NORMAL;
	t_tank_water_pump_down_5.key_type = KEY_TYPE_NORMAL;

	
	p->item = tank_5_chun_item;
	for(i=0;i<TANK_5_CHUN_ITME_NUM;i++)
	{
		memcpy(&(p->item[i]),p_tank_item_5_chun_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_tank_item_5_chun_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_tank_item_5_chun_u[i]->size_of_pic_item ;
	}
	
	p->sub_page_count = TANK_5_CHUN_SUB_PAGE_NUM; //定义好子页面数目
	p->sub_page = (lcd_dis_page_t **)malloc(p->sub_page_count * sizeof(lcd_dis_page_t *));  //开辟子页面数组内存
	for (u8 i=0;i<p->sub_page_count; i++) 
	{
		p->sub_page[i] = (lcd_dis_page_t *)malloc(sizeof(lcd_dis_page_t));  //开辟每个子页面内存
		if(p->sub_page[i] != NULL) 
		{
			p->sub_page[i]->fat_page = p;
    }
	}
	ui_column_tank_sub_page_1_init();
}
extern TANK_SET_STATUS* Tank_set_return_status[TANK_DIS_NUM];
//TANK_SET_STATUS* Tank_set_return_status[TANK_DIS_NUM]={&Tank1_set_return_status,&Tank2_set_return_status,&Tank3_set_return_status,&Tank4_set_return_status};
void disply_column_tanks_state(u8 tank_type,bool upgrade)
{
	static u8 old_val_fresh[TANK_DIS_NUM]={0,0,0,0};
	static u8 old_Tank_type[TANK_DIS_NUM]={0xFF,0xFF,0xFF,0xFF};
	static u8 old_Tank_sensor_type[TANK_DIS_NUM]={0,0,0,0};
	static u16 old_Tank_val_max[TANK_DIS_NUM]={0,0,0,0};
	lcd_dis_item_t *p,*p2,*p3,*p_xy,*p_xy2,*p_xy3;
	TANK_SET_STATUS* p_Tank_set_return_status;
	u8 i,same_tank_type_cnt = 0,same_tank_type_cnt_all=0;
	u8 X_tanks_black_offset = 0;//ico have offset
	u8 offet = 0;
//	u8 offset = 0;
	u8 val_temp = 0;
	char display_buf[16];
	char *dipPtype;
	
	switch(tank_type)
	{
		case TANK1:
		{
			p_xy  = &t_tank_fresh_bg_5;
			p_xy2 = &t_tank_fresh_val_5;
			p_xy3 = &t_tank_fresh_wave_5;
			val_temp = 40;//val_status.val_tank1;		
			p_Tank_set_return_status = Tank_set_return_status[tank_type];
		}break;
		case TANK2:
		{
			p_xy  = &t_tank_gray_bg_5;
			p_xy2 = &t_tank_gray_val_5;
			p_xy3 = &t_tank_gray_wave_5;
			val_temp = 60;//val_status.val_tank2;		
			p_Tank_set_return_status = Tank_set_return_status[tank_type];
		}break;
		case TANK3:
		{
			p_xy  = &t_tank_black_bg_5;
			p_xy2 = &t_tank_balck_val_5;
			p_xy3 = &t_tank_black_wave_5;
			val_temp = 80;//val_status.val_tank3;					
			p_Tank_set_return_status = Tank_set_return_status[tank_type];
		}break;
		case TANK4:
		{	
			p_xy  = &t_tank_lpg_bg_5;
			p_xy2 = &t_tank_lpg_val_5;
			p_xy3 = &t_tank_lpg_wave_5;
			val_temp = 90;//val_status.val_tank4;		
			p_Tank_set_return_status = Tank_set_return_status[tank_type];
		}break;
	}
	
	for(i=0;i<TANK_DIS_NUM;i++)
	{
		if(p_Tank_set_return_status->Tank_type == Tank_set_return_status[i]->Tank_type)
		{
			if(i<tank_type)
				same_tank_type_cnt++;	
			same_tank_type_cnt_all++;	
		}
	}

	if((val_temp!=old_val_fresh[tank_type])||(p_Tank_set_return_status->Tank_type!=old_Tank_type[tank_type])||(p_Tank_set_return_status->Tank_sensor_type!=old_Tank_sensor_type[tank_type])||(p_Tank_set_return_status->val_max!=old_Tank_val_max[tank_type])||(upgrade))
	{
    old_val_fresh[tank_type] = val_temp;
		old_Tank_type[tank_type] = p_Tank_set_return_status->Tank_type;
	  old_Tank_sensor_type[tank_type] = p_Tank_set_return_status->Tank_sensor_type;
	  old_Tank_val_max[tank_type] = p_Tank_set_return_status->val_max;
	
		if(p_Tank_set_return_status->Tank_type==1)
		{
			p  = &t_tank_fresh_bg_5;
			p2 = &t_tank_fresh_val_5;
		  p3 = &t_tank_fresh_wave_5;
		  if(same_tank_type_cnt_all<=1)
			  dipPtype = "Fresh";
			else if(same_tank_type_cnt==3)
				dipPtype = "Fresh4";
			else if(same_tank_type_cnt==2)
				dipPtype = "Fresh3";
			else if(same_tank_type_cnt==1)
				dipPtype = "Fresh2";
			else if(same_tank_type_cnt==0)
				dipPtype = "Fresh1";
		}
		else if(p_Tank_set_return_status->Tank_type==2)
		{
		  p  = &t_tank_gray_bg_5;
			p2 = &t_tank_gray_val_5;
		  p3 = &t_tank_gray_wave_5;
			//dipPtype = "Grey";
			if(same_tank_type_cnt_all<=1)
			  dipPtype = "Grey";
			else if(same_tank_type_cnt==3)
				 dipPtype = "Grey4";
			else if(same_tank_type_cnt==2)
				 dipPtype = "Grey3";
			else if(same_tank_type_cnt==1)
				 dipPtype = "Grey2";
			else if(same_tank_type_cnt==0)
				 dipPtype = "Grey1";
		}	
    else if(p_Tank_set_return_status->Tank_type==3)
		{
		  p  = &t_tank_black_bg_5;
			p2 = &t_tank_balck_val_5;
		  p3 = &t_tank_black_wave_5;
			X_tanks_black_offset = 1;
			//dipPtype = "Waste";
			if(same_tank_type_cnt_all<=1)
			  dipPtype = "Waste";
			else if(same_tank_type_cnt==3)
				 dipPtype = "Waste4";
			else if(same_tank_type_cnt==2)
				 dipPtype = "Waste3";
			else if(same_tank_type_cnt==1)
				 dipPtype = "Waste2";
			else if(same_tank_type_cnt==0)
				 dipPtype = "Waste1";
		}	
		else if(p_Tank_set_return_status->Tank_type==4)
		{
		  p  = &t_tank_lpg_bg_5;
			p2 = &t_tank_lpg_val_5;
		  p3 = &t_tank_lpg_wave_5;
			//dipPtype = "LPG";
			if(same_tank_type_cnt_all<=1)
			  dipPtype = "LPG";
			else if(same_tank_type_cnt==3)
				 dipPtype = "LPG4";
			else if(same_tank_type_cnt==2)
				 dipPtype = "LPG3";
			else if(same_tank_type_cnt==1)
				 dipPtype = "LPG2";
			else if(same_tank_type_cnt==0)
				 dipPtype = "LPG1";
		}	
		else
		{
		  p  = &t_tank_black_bg_5;
			p2 = &t_tank_balck_val_5;
		  p3 = &t_tank_black_wave_5;
			//X_tanks_black_offset = 1;
			if(same_tank_type_cnt_all<=1)
			  dipPtype = "Null";
			else if(same_tank_type_cnt==3)
				 dipPtype = "Null4";
			else if(same_tank_type_cnt==2)
				 dipPtype = "Null3";
			else if(same_tank_type_cnt==1)
				 dipPtype = "Null2";
			else if(same_tank_type_cnt==0)
				 dipPtype = "Null1";
		}
	
		//显示水箱背景框
		png_dis_xy(p_xy->x_val,p_xy->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		//清空图层2
		Virtual_LCD_Draw_Rectangle_ARGB32(p_xy->x_val,p_xy->y_val,p_xy->x_end_val-p_xy->x_val,p_xy->y_end_val-p_xy->y_val,Virtual_LCDbuff2,ARGB_clear);
			
		if((val_temp&0x7F)>=95)
		{
			png_dis_xy(p_xy2->x_val-X_tanks_black_offset,p_xy2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		}
		else if((val_temp&0x7F)<=5)
		{
			//do nothing
		}
		else
		{
			offet = 200-(val_temp&0x7F)*200/100;
			
			png_dis_xy_form_x1y1_to_x2y2(p_xy2->x_val-X_tanks_black_offset,p_xy2->y_val+offet,\
																		p2->pic_item,p2->size_of_pic_item,\
																		0,offet,\
																		p_xy2->x_end_val-p_xy2->x_val,p_xy2->y_end_val-p_xy2->y_val,\
																		0,0,\
																		Virtual_LCDbuff1);	
			png_dis_xy(p_xy3->x_val-X_tanks_black_offset,p_xy3->y_val+offet,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);
		}
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p_xy->x_val+67,p_xy->y_val+170,dipPtype,ARGB_white,0,1,1);
		if((base_return_status.uint&0x03)==0x01)
		{
			sprintf(display_buf,"(%dGal)",p_Tank_set_return_status->val_max);
		}
		else
		{
		  sprintf(display_buf,"(%dL)",p_Tank_set_return_status->val_max);				
		}
		Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p_xy->x_val+67,p_xy->y_val+200,display_buf,0xFFAAAAAA,0,1,1);
		if((p_Tank_set_return_status->Tank_type==0)||((val_temp&0x80)==0x80))//tank1_set_status.Tank_sensor_type
		{
			sprintf(display_buf,"--");
			Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+67,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);
		}
		else
		{				
			if(p_Tank_set_return_status->Tank_sensor_type==1)
			{
				if((val_temp&0x7F)>=75)
				{
				  sprintf(display_buf,"Full");
		      Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+67,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);					
				}
				else if((val_temp&0x7F)>=50)
				{
				  sprintf(display_buf,"2/3");	
					Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(p_xy->x_val+67,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);
				}
				else if((val_temp&0x7F)>=25)
				{
				  sprintf(display_buf,"1/3");	
					Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(p_xy->x_val+67,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);
				}
				else 
				{
			    sprintf(display_buf,"Empty");
				  Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+67,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);		
				}
			}
		  else		
			{
				sprintf(display_buf,"%d%%",(val_temp&0x7F));
				Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(p_xy->x_val+67,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);	
			}				
		}
		if(upgrade==FALSE)
		{
			Virtual_LCD_Upgrate_formx1y1(p_xy->x_val,p_xy->y_val,p_xy->x_end_val-p_xy->x_val,p_xy->y_end_val-p_xy->y_val);
		}
	}
}

void ui_column_tank_subpage_1_display(bool upgrade)
{
	//lcd_dis_item_t *p;
	TANK_SET_STATUS* p_Tank_set_return_status;
	static u8 old_Tank_type[TANK_DIS_NUM]          ;
	static u8 old_Tank_sensor_type[TANK_DIS_NUM]   ;
	static u16 old_Tank_val_max[TANK_DIS_NUM]      ;
	u8 tank_type = 0;
	char *dipPtype;
	char display_buf[50];
	
	tank_type = page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK] - 1 ;
	p_Tank_set_return_status = Tank_set_return_status[tank_type];
	if(upgrade)
	{
		sprintf(display_buf,"Tank%d Setting",(tank_type+1));
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(335,40, display_buf,ARGB_white,0,1,1);
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(65,43, "Save and Back",ARGB_white,0,1,1);
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(65,84, "Tank Type",ARGB_white,0,1,1);
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(65,133,"Capacity",ARGB_white,0,1,1);
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(65,183,"Low Alarm",ARGB_white,0,1,1);
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(65,233,"High Alarm",ARGB_white,0,1,1);
		
	}
	//sysprintf("\r\n p_Tank_set_return_status->Tank_type = %d  old_Tank_type[tank_type] = %d \r\n",p_Tank_set_return_status->Tank_type,old_Tank_type[tank_type]);
	if((p_Tank_set_return_status->Tank_type!=old_Tank_type[tank_type])||(p_Tank_set_return_status->Tank_sensor_type!=old_Tank_sensor_type[tank_type])||(p_Tank_set_return_status->val_max!=old_Tank_val_max[tank_type])||(upgrade))
	{
		Virtual_LCD_Draw_Rectangle_ARGB32(580,80,90,375,Virtual_LCDbuff2,ARGB_clear);
		old_Tank_type[tank_type] = p_Tank_set_return_status->Tank_type;
	  old_Tank_sensor_type[tank_type] = p_Tank_set_return_status->Tank_sensor_type;
	  old_Tank_val_max[tank_type] = p_Tank_set_return_status->val_max;
		
		if(p_Tank_set_return_status->Tank_type == 0x01)
			dipPtype = "Fresh";
		else if(p_Tank_set_return_status->Tank_type == 0x02)
			dipPtype = "Gray";
		else if(p_Tank_set_return_status->Tank_type == 0x03)
			dipPtype = "Black";
		else if(p_Tank_set_return_status->Tank_type == 0x04)
			dipPtype = "LPG";
		else
			dipPtype = "Null";
		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(625,86,dipPtype,ARGB_blue,0,1,1);
		if((base_return_status.uint&0x03)==0x01)
		{
			sprintf(display_buf,"%dGal",p_Tank_set_return_status->val_max);
		}
		else
		{
		  sprintf(display_buf,"%dL",p_Tank_set_return_status->val_max);				
		}
		Virtual_LCD_Draw_String_ARGB_align_right_4bit(24,648,136,display_buf,ARGB_blue,0,1,1);
		if((base_return_status.uint&0x03)==0x01)
		{
			sprintf(display_buf,"%dGal",p_Tank_set_return_status->val_warning_H_or_Low_Alarm);
		}
		else
		{
		  sprintf(display_buf,"%dL",p_Tank_set_return_status->val_warning_H_or_Low_Alarm);				
		}
		Virtual_LCD_Draw_String_ARGB_align_right_4bit(24,648,186,display_buf,ARGB_blue,0,1,1);
		if((base_return_status.uint&0x03)==0x01)
		{
			sprintf(display_buf,"%dGal",p_Tank_set_return_status->val_alarm_H);
		}
		else
		{
		  sprintf(display_buf,"%dL",p_Tank_set_return_status->val_alarm_H);				
		}
		Virtual_LCD_Draw_String_ARGB_align_right_4bit(24,648,236,display_buf,ARGB_blue,0,1,1);
		if(upgrade==FALSE)
		{
			Virtual_LCD_Upgrate_formx1y1(600,80,650,375);
		}
	}
}

#endif

