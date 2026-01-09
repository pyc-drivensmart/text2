#include "includes.h"




	// &t_tanks_b_tanks_d,	

	//home面按键列表 按下
lcd_dis_item_t *p_tanks_item_d[TANKS_ICO_NUM]=
{
 
	//&t_tanks_black_bg,
  //&t_tanks_fresh_bg,
  //&t_tanks_grey_bg,
  //&t_tanks_LPG_bg,
  &t_tanks_wpON_d,
	&t_tanks_heat_ON,
};

//界面按键列表 弹起
lcd_dis_item_t *p_tanks_item_u[TANKS_ICO_NUM]=
{
	//&t_tanks_black_bg,
  //&t_tanks_fresh_bg,
  //&t_tanks_grey_bg,
  //&t_tanks_LPG_bg,
  &t_tanks_wpOFF_u,//&t_tanks_wpON_d
	&t_tanks_heat_OFF,




};

lcd_dis_item_t tanks_item[TANKS_ICO_NUM];
u8 ICO_tanks_wp =0;//定义t_tanks_wpOFF_d图标的位置 





void set_tanks_item_key_type(void)
{

	if(f_override_key==FALSE)
	{
		if((switch_ch_list_return[6]==0)||(switch_ch_list_return[6]>24))
		{
			tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_TOUCH_NONE;
			t_tanks_wpON_d.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
			home_item[11].key_type = KEY_TYPE_TOUCH_NONE;
			t_home_wpON_d.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
		}
		else
		{
			 tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_NORMAL;
			 t_tanks_wpON_d.key_type = KEY_TYPE_NORMAL;//防止初始化前收到了这个指令
			 home_item[11].key_type = KEY_TYPE_NORMAL;
			 t_home_wpON_d.key_type = KEY_TYPE_NORMAL;//防止初始化前收到了这个指令
		}
		if((switch_ch_list_return[7]==0)||(switch_ch_list_return[7]>24))
		{
			tanks_item[ICO_tanks_wp+1].key_type = KEY_TYPE_TOUCH_NONE;
			t_tanks_heat_ON.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
		}
		else
		{
			 tanks_item[ICO_tanks_wp+1].key_type = KEY_TYPE_NORMAL;
			 t_tanks_heat_ON.key_type = KEY_TYPE_NORMAL;//防止初始化前收到了这个指令
		}
	}
	else
	{
	  if((switch_ch_list_return[6]==0)||(switch_ch_list_return[6]>24))
		{
			tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_TOUCH_NONE;
			t_tanks_wpON_d.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
			home_item[11].key_type = KEY_TYPE_TOUCH_NONE;
			t_home_wpON_d.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
		}
		else
		{
			 tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_TOUCH_NONE;
			 t_tanks_wpON_d.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
			 home_item[11].key_type = KEY_TYPE_TOUCH_NONE;
			 t_home_wpON_d.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
		}
		if((switch_ch_list_return[7]==0)||(switch_ch_list_return[7]>24))
		{
			tanks_item[ICO_tanks_wp+1].key_type = KEY_TYPE_TOUCH_NONE;
			t_tanks_heat_ON.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
		}
		else
		{
			 tanks_item[ICO_tanks_wp+1].key_type = KEY_TYPE_TOUCH_NONE;
			 t_tanks_heat_ON.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
		}
	
	}
			
}






TANK_SET_STATUS* Tank_set_return_status[TANK_DIS_NUM]={&Tank1_set_return_status,&Tank2_set_return_status,&Tank3_set_return_status,&Tank4_set_return_status};
void disply_big_tanks_status(u8 type,bool upgrage)
{
  static u8 old_val_fresh[TANK_DIS_NUM]={0,0,0,0};
	static u8 old_Tank_type[TANK_DIS_NUM]={0xFF,0xFF,0xFF,0xFF};
	static u8 old_Tank_sensor_type[TANK_DIS_NUM]={0,0,0,0};
	static u16 old_Tank_val_max[TANK_DIS_NUM]={0,0,0,0};
	lcd_dis_item_t *p,*p2,*p3,*p_xy,*p_xy2,*p_xy3;
	u8 offet = 0;
	u8 val_temp =0;
	u8 X_tanks_black_offset = 0;//ico have offset
	u8 i,same_tank_type_cnt = 0,same_tank_type_cnt_all=0;
	char display_buf[16];
	char *dipPtype;
  TANK_SET_STATUS* p_Tank_set_return_status;
	//return;
	switch(type) 
	{
	  case TANK1:
			//取坐标位置
      p_xy = &t_tanks_fresh_bg;
		  p_xy2 = &t_tanks_fresh_100;
		  p_xy3 = &t_tanks_fresh_wave;
			p_Tank_set_return_status = Tank_set_return_status[type];
		  val_temp = 50;//val_status.val_tank1;		
      break;
		case TANK2:
			p_xy=&t_tanks_grey_bg;
		  p_xy2 = &t_tanks_grey_100;
	  	p_xy3 = &t_tanks_grey_wave;
		  p_Tank_set_return_status= Tank_set_return_status[type];
		  val_temp = 80;//val_status.val_tank2;
		  //dipPtype = "Grey";
			break;
		case TANK3:
			p_xy=&t_tanks_black_bg;
		  p_xy2 = &t_tanks_black_100;
		  p_xy3 = &t_tanks_black_wave;
		  p_Tank_set_return_status= Tank_set_return_status[type];
		  val_temp = 100;//val_status.val_tank3;
		  //dipPtype = "Black";
			break;
		case TANK4:
			p_xy=&t_tanks_LPG_bg;
		  p_xy2 = &t_tanks_LPG_100;
		  p_xy3 = &t_tanks_LPG_wave;
		  p_Tank_set_return_status= Tank_set_return_status[type];
		  val_temp = 20;//val_status.val_tank4;
		  //dipPtype = "LPG";
			break;
		default:
			return;
			//break;
				
	}
	

		for(i=0;i<TANK_DIS_NUM;i++)
		{
			 if(p_Tank_set_return_status->Tank_type == Tank_set_return_status[i]->Tank_type)
			 {
				 if(i<type)
			   same_tank_type_cnt++;	
				 
				 same_tank_type_cnt_all++;	
			 }
		}


			
			 
	
	
	if((val_temp!=old_val_fresh[type])||(p_Tank_set_return_status->Tank_type!=old_Tank_type[type])||(p_Tank_set_return_status->Tank_sensor_type!=old_Tank_sensor_type[type])||(p_Tank_set_return_status->val_max!=old_Tank_val_max[type])||(upgrage))
	{
     old_val_fresh[type] = val_temp;
		 /*if(old_Tank_type[type] != p_Tank_set_return_status->Tank_type)
		 {
			 for(i=0;i<TANK_DIS_NUM;i++)
			 {
			   old_Tank_type[i]=0xFF;
			 }
		 }*/
		 old_Tank_type[type] = p_Tank_set_return_status->Tank_type;
		 old_Tank_sensor_type[type] = p_Tank_set_return_status->Tank_sensor_type;
		 old_Tank_val_max[type] = p_Tank_set_return_status->val_max;
		
		
		  if(p_Tank_set_return_status->Tank_type==1)
			{
			  p= &t_tanks_fresh_bg;
		    p2 = &t_tanks_fresh_100;
		    p3 = &t_tanks_fresh_wave;
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
			  p= &t_tanks_grey_bg;
		    p2 = &t_tanks_grey_100;
		    p3 = &t_tanks_grey_wave;
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
			  p= &t_tanks_black_bg;
		    p2 = &t_tanks_black_100;
		    p3 = &t_tanks_black_wave;
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
			  p= &t_tanks_LPG_bg;
		    p2 = &t_tanks_LPG_100;
		    p3 = &t_tanks_LPG_wave;
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
			  p= &t_tanks_black_bg;
		    p2 = &t_tanks_black_100;
		    p3 = &t_tanks_black_wave;
				X_tanks_black_offset = 1;
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
		  
		
		
		//sysprintf("\r\nnow_status788777");
		
		 
     
	   png_dis_xy(p_xy->x_val,p_xy->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		 Virtual_LCD_Draw_Rectangle_ARGB32(p_xy->x_val,p_xy->y_val,p_xy->x_end_val-p_xy->x_val,p_xy->y_end_val-p_xy->y_val,Virtual_LCDbuff2,ARGB_clear);
		
			
		//if (val_temp==0xFF)	
		//{}
		//else
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
					
					
						
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p_xy->x_val+80,p_xy->y_val+190,dipPtype,ARGB_white,0,1,1);
		if((base_return_status.uint&0x03)==0x01)
		{
			sprintf(display_buf,"(%dGal)",p_Tank_set_return_status->val_max);
		}
		else
		{
		  sprintf(display_buf,"(%dL)",p_Tank_set_return_status->val_max);				
		}
		
		Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p_xy->x_val+80,p_xy->y_val+220,display_buf,0xFFAAAAAA,0,1,1);
		
		//Virtual_LCD_Draw_Rectangle_ARGB32(p_xy->x_val,p_xy->y_val+107,24*6,48,Virtual_LCDbuff2,ARGB_clear);
		if((p_Tank_set_return_status->Tank_type==0)||((val_temp&0x80)==0x80))//tank1_set_status.Tank_sensor_type
		{
		
		    sprintf(display_buf,"--");
				Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+80,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);
		}
		else
		{				
			if(p_Tank_set_return_status->Tank_sensor_type==1)
			{
				if((val_temp&0x7F)>=75)
				{
				  sprintf(display_buf,"Full");
          Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+80,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);					
				}
				else if((val_temp&0x7F)>=50)
				{
				  sprintf(display_buf,"2/3");	
					Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(p_xy->x_val+80,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);
				}
				else if((val_temp&0x7F)>=25)
				{
				  sprintf(display_buf,"1/3");	
					Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(p_xy->x_val+80,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);
				}
				else 
				{
			    sprintf(display_buf,"Empty");
				  Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+80,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);		
				}
				
			}
      else		
			{
				sprintf(display_buf,"%d%%",(val_temp&0x7F));
				Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(p_xy->x_val+80,p_xy->y_val+107,display_buf,ARGB_white,0,1,1);	
			}				
				
  	}
		if(upgrage==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p_xy->x_val,p_xy->y_val,p_xy->x_end_val-p_xy->x_val,p_xy->y_end_val-p_xy->y_val);
	}  
}

#if 0
void disply_big_tanks_status(u8 type,bool upgrage)
{
  static u8 old_val_fresh[4]={0,0,0,0};
	  lcd_dis_item_t *p,*p2,*p3;
	u8 offet = 0;
	u8 val_temp =0;
	char display_buf[16];
	char *dipPtype;

	switch(type) 
	{
	  case TK_FRESH:
			p= &t_tanks_fresh_bg;
		  p2 = &t_tanks_fresh_100;
		  p3 = &t_tanks_fresh_wave;
		  val_temp = val_status.val_fresh;
		  dipPtype = "Fresh";
			break;
		case TK_GREY:
			p=&t_tanks_grey_bg;
		  p2 = &t_tanks_grey_100;
	  	p3 = &t_tanks_grey_wave;
		  val_temp = val_status.val_grey;
		  dipPtype = "Grey";
			break;
		case TK_BLACK:
			p=&t_tanks_black_bg;
		  p2 = &t_tanks_black_100;
		  p3 = &t_tanks_black_wave;
		  val_temp = val_status.val_black;
		  dipPtype = "Black";
			break;
		case TK_LPG:
			p=&t_tanks_LPG_bg;
		  p2 = &t_tanks_LPG_100;
		  p3 = &t_tanks_LPG_wave;
		  val_temp = val_status.val_LPG;
		  dipPtype = "LPG";
			break;
		default:
			return;
			//break;
				
	}
	
	if((val_temp!=old_val_fresh[type])||(upgrage))
	{
     old_val_fresh[type] = val_temp;
		
     
	   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		
		
		if(val_temp>=95)
		{
			png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		}
		else if(val_temp<=5)
		{
			//do nothing
		}
		else
		{
		offet = 200-val_temp*200/100;
		
	  //png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		png_dis_xy_form_x1y1_to_x2y2(p2->x_val,p2->y_val+offet,\
                                	p2->pic_item,p2->size_of_pic_item,\
		                              0,offet,\
	                                p2->x_end_val-p2->x_val,p2->y_end_val-p2->y_val,\
																	0,0,\
																	Virtual_LCDbuff1);
		
		//p=&t_home_fresh_wave;
	   png_dis_xy(p3->x_val,p3->y_val+offet,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);
		}
		 
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->x_val+48,p->y_val+190,dipPtype,ARGB_white,0,1,1);
		
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val+107,24*6,48,Virtual_LCDbuff2,ARGB_clear);
		if(val_temp>=100)
		{
			sprintf(display_buf,"100");
			display_buf[3] = '%';
			display_buf[4] = ' ';
			display_buf[5] = ' ';
			display_buf[6] = '\0';
			Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val+30,p->y_val+107,display_buf,ARGB_white,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"%02d",val_temp);
		  display_buf[2] = '%';
			display_buf[3] = ' ';
			display_buf[4] = ' ';
			display_buf[5] = '\0';
			Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val+35,p->y_val+107,display_buf,ARGB_white,0,1,1);
		
		}
		if(upgrage==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}  

}


#endif



#define X_tank_ch_name_offset 280
#define Y_tank_ch_name_offset 5
void disply_tanks_tank_ch_name(bool upgrade)
{
	//u8 i;
	u8 ch1=6,ch2=7;
	u32 display_color;
	char display_buf[32];
	static u8 old_switch_ch_list_return[SWITCH_NAME_CH_NUM];
	lcd_dis_item_t *p,*p1,*p2;
		if((upgrade)||(old_switch_ch_list_return[ch1]!=switch_ch_list_return[ch1])||(old_switch_ch_list_return[ch2]!=switch_ch_list_return[ch2]))
	  {
	    old_switch_ch_list_return[ch1]=switch_ch_list_return[ch1];
			old_switch_ch_list_return[ch2]=switch_ch_list_return[ch2];
	
	    p1 = &t_tanks_wpON_d;
	    p2 = &t_tanks_heat_ON;
			
			if(upgrade==FALSE)
			{
			  Virtual_LCD_Draw_Rectangle_ARGB32(p1->x_val+X_tank_ch_name_offset,p1->y_val+Y_tank_ch_name_offset,50,32,Virtual_LCDbuff2,ARGB_clear);
				Virtual_LCD_Draw_Rectangle_ARGB32(p2->x_val+X_tank_ch_name_offset,p2->y_val+Y_tank_ch_name_offset,50,32,Virtual_LCDbuff2,ARGB_clear);
      }
			
			
		  display_color = 0xFF838697;
			if(f_override_key)
			{
				p=&t_key_locked2;
				png_dis_xy(p1->x_val+X_tank_ch_name_offset+35,p1->y_val+Y_tank_ch_name_offset,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff2);
			  
				//sprintf(display_buf,"locked");
			  //Virtual_LCD_Draw_String_ARGB_16_4bit(p1->x_val+X_tank_ch_name_offset,p1->y_val+Y_tank_ch_name_offset,display_buf,display_color,0,1,1);
		
			}
			else if((switch_ch_list_return[ch1]==0)||(switch_ch_list_return[ch1]>switch_ch_select_num_max))
			{
			sprintf(display_buf,"null");
				Virtual_LCD_Draw_String_ARGB_16_4bit(p1->x_val+X_tank_ch_name_offset+18,p1->y_val+Y_tank_ch_name_offset,display_buf,display_color,0,1,1);
		
			}
			else
			{
				sprintf(display_buf,"ch%d",switch_ch_list_return[ch1]);
				if(tanks_item[ICO_tanks_wp].now_status==STATUS_SELECT)
					display_color = 0xFF82c2ff;
				Virtual_LCD_Draw_String_ARGB_16_4bit(p1->x_val+X_tank_ch_name_offset+18,p1->y_val+Y_tank_ch_name_offset,display_buf,display_color,0,1,1);
		
			}
			
		
			
			display_color = 0xFF838697;
			if(f_override_key)
			{
				//lcd_dis_item_t *p;
				p=&t_key_locked2;
				png_dis_xy(p2->x_val+X_tank_ch_name_offset+35,p2->y_val+Y_tank_ch_name_offset,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff2);
			  
				//sprintf(display_buf,"locked");
				//      Virtual_LCD_Draw_String_ARGB_16_4bit(p2->x_val+X_tank_ch_name_offset,p2->y_val+Y_tank_ch_name_offset,display_buf,display_color,0,1,1);

			}
			else if((switch_ch_list_return[ch2]==0)||(switch_ch_list_return[ch2]>switch_ch_select_num_max))
			{
			sprintf(display_buf,"null");
			      Virtual_LCD_Draw_String_ARGB_16_4bit(p2->x_val+X_tank_ch_name_offset+18,p2->y_val+Y_tank_ch_name_offset,display_buf,display_color,0,1,1);
			}
			else
			{
				sprintf(display_buf,"ch%d",switch_ch_list_return[ch2]);
				if(tanks_item[ICO_tanks_wp+1].now_status==STATUS_SELECT)
					display_color = 0xFF82c2ff;
				      Virtual_LCD_Draw_String_ARGB_16_4bit(p2->x_val+X_tank_ch_name_offset+18,p2->y_val+Y_tank_ch_name_offset,display_buf,display_color,0,1,1);

			}
			
		
			if(upgrade==FALSE)
			{
			   Virtual_LCD_Upgrate_formx1y1(p1->x_val+X_tank_ch_name_offset,p1->y_val+Y_tank_ch_name_offset,50,32);
				 Virtual_LCD_Upgrate_formx1y1(p2->x_val+X_tank_ch_name_offset,p1->y_val+Y_tank_ch_name_offset,50,32);
			}
	    
	}

}



BOOL page_tanks_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
  /*if(page_home.page_left_side.now_item == LEFT_SIDE_PAGE_AC)
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
						}*/
						 return FALSE;

}
///////////////////////初始化////////////////////////////////////////


void ui_tanks_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_TANKS][TOP_SIDE_PAGE_TANKS_TANKS];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=TANKS_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only



   t_tanks_black_bg.key_type = KEY_TYPE_TOUCH_NONE;
   t_tanks_fresh_bg.key_type = KEY_TYPE_TOUCH_NONE;
   t_tanks_grey_bg.key_type = KEY_TYPE_TOUCH_NONE;
   t_tanks_LPG_bg.key_type = KEY_TYPE_TOUCH_NONE;
   //t_tanks_wpON_d
   
	 
   p->item = tanks_item;
   for(i=0;i<TANKS_ICO_NUM;i++)
	 {
	  memcpy(&(p->item[i]),p_tanks_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_tanks_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_tanks_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 //p->item[ICO_tanks_wp].pic_item_touch =t_tanks_wpON_d.pic_item_touch;//
   //p->item[ICO_tanks_wp].size_of_pic_item_touch = t_tanks_wpON_d.size_of_pic_item_touch ;
	 //p->item[ICO_tanks_wp].key_type = KEY_TYPE_TOUCH_NONE;
 }


