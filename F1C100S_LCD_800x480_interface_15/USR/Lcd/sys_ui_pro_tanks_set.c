#include "includes.h"

u8 tanks_now_set_send_id = 0;


extern void func_tanks_setup_btn1_d(void* p,u8 sn);
extern void func_tanks_setup_btn1_u(void* p,u8 sn);
extern void func_tanks_setup_btn2_d(void* p,u8 sn);
extern void func_tanks_setup_btn2_u(void* p,u8 sn);
extern void func_tanks_setup_btn3_u(void* p,u8 sn);
extern void func_tanks_setup_btn3_d(void* p,u8 sn);
extern void func_tanks_setup_btn4_d(void* p,u8 sn);
extern void func_tanks_setup_btn4_u(void* p,u8 sn);
extern void func_tanks_setup_b_tanks_setup_d(void* p,u8 sn);
extern void func_tanks_setup_b_tanks_setup_u(void* p,u8 sn);
extern void func_tanks_setup_headline(void* p,u8 sn);
extern void func_tanks_setup_nextpage_d(void* p,u8 sn);
extern void func_tanks_setup_nextpage_o(void* p,u8 sn);
extern void func_tanks_setup_nextpage_u(void* p,u8 sn);
extern void func_tanks_setup_prepage_d(void* p,u8 sn);
extern void func_tanks_setup_prepage_o(void* p,u8 sn);
extern void func_tanks_setup_prepage_u(void* p,u8 sn);
extern void func_tanks_b_setup_d(void* p,u8 sn);
extern void func_tanks_b_setup_u(void* p,u8 sn);



extern void func_tanks_setup_b_back_d(void* p,u8 sn);
extern void func_tanks_setup_b_back_u(void* p,u8 sn);

	
extern void func_tanks_setup_left_d(void* p,u8 sn);
extern void func_tanks_setup_left_u(void* p,u8 sn);
extern void func_tanks_setup_right_d(void* p,u8 sn);
extern void func_tanks_setup_right_u(void* p,u8 sn);
extern void func_tanks_setup_left2_d(void* p,u8 sn);
extern void func_tanks_setup_left2_u(void* p,u8 sn);
extern void func_tanks_setup_right2_d(void* p,u8 sn);
extern void func_tanks_setup_right2_u(void* p,u8 sn);
extern void func_tanks_setup_left3_d(void* p,u8 sn);
extern void func_tanks_setup_left3_u(void* p,u8 sn);
extern void func_tanks_setup_right3_d(void* p,u8 sn);
extern void func_tanks_setup_right3_u(void* p,u8 sn);
extern void func_tanks_setup_left4_d(void* p,u8 sn);
extern void func_tanks_setup_left4_u(void* p,u8 sn);
extern void func_tanks_setup_right4_d(void* p,u8 sn);
extern void func_tanks_setup_right4_u(void* p,u8 sn);

extern setup_item_info_t tanks_settings[];
bool f_display_tanks_setup_info = FALSE;
bool f_display_tanks_setup_info_upgrage = FALSE;

	
void*p_func_tanks_setup_item_d[TANKS_SET_ICO_NUM]=
{	
	
  &func_tanks_setup_headline,
  &func_tanks_setup_btn1_d,
  &func_tanks_setup_btn2_d,
  &func_tanks_setup_btn3_d,
  &func_tanks_setup_btn4_d,
  &func_tanks_setup_nextpage_d,
  &func_tanks_setup_prepage_d,
	&func_tanks_setup_left_d,
	&func_tanks_setup_left2_d,
	&func_tanks_setup_left3_d,
	&func_tanks_setup_left4_d,//10
	&func_tanks_setup_right_d,
	&func_tanks_setup_right2_d,
	&func_tanks_setup_right3_d,
	&func_tanks_setup_right4_d,
	&func_tanks_setup_b_back_d,	
};
	
lcd_dis_item_t tanks_setup_item[TANKS_SET_ICO_NUM];








setup_item_info_t Tank1_settings[]=
{
   {"Tank Type",TOUCH_TYPE_LEFT_RIGHT,tanks_settings,empty_son_p,func_Tank1_Type},
	 {"Capacity",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank1_Capacity},	
	 {"High Warning",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank1_High_Warning_or_Low_Alarm},	
	 {"High Alarm",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank1_High_Alarm},	
	 {"Sensor Type",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_Tank1_Sensor_Type},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t Tank2_settings[]=
{
   {"Tank Type",TOUCH_TYPE_LEFT_RIGHT,tanks_settings,empty_son_p,func_Tank2_Type},
	 {"Capacity",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank2_Capacity},	
	 {"High Warning",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank2_High_Warning_or_Low_Alarm},	
	 {"High Alarm",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank2_High_Alarm},	
	 {"Sensor Type",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_Tank2_Sensor_Type},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t Tank3_settings[]=
{
   {"Tank Type",TOUCH_TYPE_LEFT_RIGHT,tanks_settings,empty_son_p,func_Tank3_Type},
	 {"Capacity",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank3_Capacity},	
	 {"High Warning",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank3_High_Warning_or_Low_Alarm},	
	 {"High Alarm",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank3_High_Alarm},
   {"Sensor Type",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_Tank3_Sensor_Type},	 
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t Tank4_settings[]=
{
   {"Tank Type",TOUCH_TYPE_LEFT_RIGHT,tanks_settings,empty_son_p,func_Tank4_Type},
	 {"Capacity",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank4_Capacity},	
	 {"High Warning",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank4_High_Warning_or_Low_Alarm},	
	 {"High Alarm",TOUCH_TYPE_KEYBOARD,tanks_settings,empty_son_p,func_Tank4_High_Alarm},	
	 {"Sensor Type",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_Tank4_Sensor_Type},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t Control_Channel_Selection[]=
{
   {"Water Pump Channel",TOUCH_TYPE_LEFT_RIGHT,tanks_settings,empty_son_p,func_Water_Pump_Channel},
	 {"Water Heater Channel",TOUCH_TYPE_LEFT_RIGHT,tanks_settings,empty_son_p,func_Water_Heater_Channel},	
	 {"Save And Back",TOUCH_TYPE_NORMAL,tanks_settings,empty_son_p,func_Save_And_Back},	
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};


setup_item_info_t tanks_settings[]=
{
   {"Tank1",TOUCH_TYPE_ENTER,empty_father_p,Tank1_settings,empty_fun},
	 {"Tank2",TOUCH_TYPE_ENTER,empty_father_p,Tank2_settings,empty_fun},
	 {"Tank3",TOUCH_TYPE_ENTER,empty_father_p,Tank3_settings,empty_fun},//
	 {"Tank4",TOUCH_TYPE_ENTER,empty_father_p,Tank4_settings,empty_fun},//
	 {"Control Channel Selection",TOUCH_TYPE_ENTER,empty_father_p,Control_Channel_Selection,func_get_Channel},//
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_page_t tanks_setup_page;




u8 Water_Pump_Channel_temp = 0;
u8 Water_Heater_Channel_temp = 0;
void func_get_Channel(void* p,u8 sn,DEAl_TYPE deal_type)
{
	if(deal_type==TO_DEAL)
	{		
	  Water_Pump_Channel_temp = switch_ch_list_return[6];
	  Water_Heater_Channel_temp = switch_ch_list_return[7];
	}	
}

void func_Water_Pump_Channel(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];		
	  if(deal_type==TO_INIT)
		{			
			if((Water_Pump_Channel_temp!=0)&&(Water_Pump_Channel_temp<=12))
			{
					sprintf(display_buf,"CH%d",Water_Pump_Channel_temp);
			}
			else
			{
			   sprintf(display_buf,"Null");
				 Water_Pump_Channel_temp = 0;
				
			}
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(tanks_setup_item[sn].x_val+X_set_mid_offset,tanks_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
    }
		else if(deal_type==TO_UP)
		{
			 // if(Water_Pump_Channel_temp==0)
				//	Water_Pump_Channel_temp = 5;
				//else
				{
			    Water_Pump_Channel_temp++;
			    if(Water_Pump_Channel_temp>12)
					  Water_Pump_Channel_temp = 0;
			  }
			 //send_FlC200_set_cmd(set_cmd,Tank_status->Tank_type);
		   f_display_tanks_setup_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
			  if(Water_Pump_Channel_temp)
				{
			    Water_Pump_Channel_temp--;
					if(Water_Pump_Channel_temp>12)
					Water_Pump_Channel_temp = 12;
				}
				else 
			    Water_Pump_Channel_temp = 12;		
			  
				//send_FlC200_set_cmd(set_cmd,Tank_status->Tank_type);
		    f_display_tanks_setup_info = TRUE;
		}
		else if(deal_type==TO_DEAL)
		{

		}
}
void func_Water_Heater_Channel(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];		
	  if(deal_type==TO_INIT)
		{			
			if((Water_Heater_Channel_temp!=0)&&(Water_Heater_Channel_temp<=12))
			{
					sprintf(display_buf,"CH%d",Water_Heater_Channel_temp);
			}
			else
			{
			   sprintf(display_buf,"Null");
				 Water_Heater_Channel_temp = 0;
				
			}
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(tanks_setup_item[sn].x_val+X_set_mid_offset,tanks_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
    }
		else if(deal_type==TO_UP)
		{
			  //if(Water_Heater_Channel_temp==0)
				//	Water_Heater_Channel_temp = 5;
				//else
				{
			    Water_Heater_Channel_temp++;
			    if(Water_Heater_Channel_temp>12)
					  Water_Heater_Channel_temp = 0;
			  }
			 //send_FlC200_set_cmd(set_cmd,Tank_status->Tank_type);
		   f_display_tanks_setup_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
			  if(Water_Heater_Channel_temp)
				{
			    Water_Heater_Channel_temp--;
					if(Water_Heater_Channel_temp>12)
					Water_Heater_Channel_temp = 12;
				}
				else 
			    Water_Heater_Channel_temp = 12;		
			  
				//send_FlC200_set_cmd(set_cmd,Tank_status->Tank_type);
		    f_display_tanks_setup_info = TRUE;
		}
		else if(deal_type==TO_DEAL)
		{

		}

}
void func_Save_And_Back(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  setup_item_info_t *setup_p;//tanks_setup_page;
	  if(deal_type==TO_DEAL)
		{			
			
			 if(Water_Pump_Channel_temp==Water_Heater_Channel_temp)
			 {
			   switch_ch_list_return[6] = 0;
	       switch_ch_list_return[7] = Water_Heater_Channel_temp;
			 }
			 else
			 {
			    switch_ch_list_return[6] = Water_Pump_Channel_temp;
	        switch_ch_list_return[7] = Water_Heater_Channel_temp;
			 }
			 
      
				
		  send_FlC200_set_cmd(0x80,6*256+Water_Pump_Channel_temp);
			send_FlC200_set_cmd(0x80,7*256+Water_Heater_Channel_temp);
			//f_display_tanks_setup_info = TRUE;
			
			setup_p = &tanks_setup_page.now_p[2];
			if(page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].now_item==TOP_SIDE_PAGE_TANKS_SETUP)
			{
					//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
					if(setup_p->father_p!=empty_father_p)	
					{
						//setup_page.now_page_num = 0;
						//f_system_Date_Time_set = FALSE;
						tanks_setup_page.now_page_num=last_now_page_num;
						tanks_setup_page.now_p = setup_p->father_p;
						page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].last_item=TOP_SIDE_PAGE_TANKS_MUN;//更新
						f_display_tanks_setup_info = TRUE;
					}
					
			
			}
		}

}





void func_Tank_Type(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd)
{

	  char display_buf[32];
	 u8 str1[]="High Warning";
	 u8 str2[]="Low Alarm";
	 u8 i,*p_str;
	  setup_item_info_t* p_Tank_settings;
//	  setup_item_info_t *setup_p;
	
	  if(deal_type==TO_INIT)
		{
			switch(Tank_status->Tank_type)
			{
			  case 1:
					sprintf(display_buf,"Fresh");
				  p_str = str2;
					break;
				case 2:
					sprintf(display_buf,"Grey");
				  p_str = str1;
					break;
				case 3:
					sprintf(display_buf,"Waste");
				  p_str = str1;
					break;
				case 4:
					sprintf(display_buf,"LPG");
				  p_str = str2;
					break;
				default:
					sprintf(display_buf,"Null");
				   p_str = str2;
					break;			
			}

			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(tanks_setup_item[sn].x_val+X_set_mid_offset,tanks_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
  
			if(set_cmd==0x10)//tank1
			{				 
				p_Tank_settings = &Tank1_settings[2];			
			}
			else if(set_cmd==0x1C)//tank2
			{				 
				p_Tank_settings = &Tank2_settings[2];			
			}
			else if(set_cmd==0x28)//tank3
			{				 
				p_Tank_settings = &Tank3_settings[2];			
			}
			else if(set_cmd==0x34)//tank4
			{				 
				p_Tank_settings = &Tank4_settings[2];			
			}
			
				for(i=0;1;i++)
				{
						p_Tank_settings->display_str[i]=p_str[i];
						if(p_str[i]==0)
							break;
				}
			
    }
		else if(deal_type==TO_UP)
		{
			  Tank_status->Tank_type++;
			  if(Tank_status->Tank_type>4)
					Tank_status->Tank_type = 4;

			 send_FlC200_set_cmd(set_cmd,Tank_status->Tank_type);
		   f_display_tanks_setup_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
			  if(Tank_status->Tank_type)
				{
			    Tank_status->Tank_type--;
					if(Tank_status->Tank_type>4)
					Tank_status->Tank_type = 4;
				}
				//else 
			  //  Tank1_set_return_status.Tank_type=4;
					
			  
				send_FlC200_set_cmd(set_cmd,Tank_status->Tank_type);
		  f_display_tanks_setup_info = TRUE;
		}
		else if(deal_type==TO_DEAL)
		{

		}


}


void func_Tank1_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
	 func_Tank_Type(p,sn,deal_type,&Tank1_set_return_status,0x10);	
}
void func_Tank2_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_Type(p,sn,deal_type,&Tank2_set_return_status,0x1C);
}
void func_Tank3_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_Type(p,sn,deal_type,&Tank3_set_return_status,0x28);
}
void func_Tank4_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_Type(p,sn,deal_type,&Tank4_set_return_status,0x34);
}
void func_Tank_Capacity(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd)
{
	  char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			if((base_return_status.uint&0x03)==0x01)
				{

					sprintf(display_buf,"%dGal",Tank_status->val_max);
				}
				else
				{
		      sprintf(display_buf,"%dL",Tank_status->val_max);
				}
			
				Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(tanks_setup_item[sn].x_val+X_set_mid_offset,tanks_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
    }
		else if(deal_type==TO_UP)
		{
			  
		}
		else if(deal_type==TO_DOWN)
		{
			 
		}
		else if(deal_type==TO_DEAL)
		{
       keyboard_ui_step=KEYBOARD_PAGE_NUM;
		     //ui_disply_keyboard();
				// f_ui_new_input_bat_capacity = TRUE;
			   Set_val_input_target_p(&Tank_status->val_max,&Tank_status->val_max);
			   tanks_now_set_send_id=set_cmd;
				 f_need_ui_disply_keyboard = TRUE;
		}
}

void func_Tank1_Capacity(void* p,u8 sn,DEAl_TYPE deal_type)
{
	//func_Tank_Capacity(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd)
	func_Tank_Capacity(p,sn,deal_type,&Tank1_set_return_status,0x12);
}
void func_Tank2_Capacity(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_Capacity(p,sn,deal_type,&Tank2_set_return_status,0x1E);
}
void func_Tank3_Capacity(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_Capacity(p,sn,deal_type,&Tank3_set_return_status,0x2A);
}
void func_Tank4_Capacity(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_Capacity(p,sn,deal_type,&Tank4_set_return_status,0x36);
}

void func_Tank_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd)
{
	  char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			if((base_return_status.uint&0x03)==0x01)
				{

					sprintf(display_buf,"%dGal",Tank_status->val_warning_H_or_Low_Alarm);
				}
				else
				{
		      sprintf(display_buf,"%dL",Tank_status->val_warning_H_or_Low_Alarm);
				}
			
				Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(tanks_setup_item[sn].x_val+X_set_mid_offset,tanks_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
    }
		else if(deal_type==TO_UP)
		{
			  
		}
		else if(deal_type==TO_DOWN)
		{
			 
		}
		else if(deal_type==TO_DEAL)
		{
       keyboard_ui_step=KEYBOARD_PAGE_NUM;
		     //ui_disply_keyboard();
				// f_ui_new_input_bat_capacity = TRUE;
			   Set_val_input_target_p(&Tank_status->val_warning_H_or_Low_Alarm,&Tank_status->val_warning_H_or_Low_Alarm);
			   tanks_now_set_send_id=set_cmd;
				 f_need_ui_disply_keyboard = TRUE;
		}
}


void func_Tank1_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_High_Warning_or_Low_Alarm(p,sn,deal_type,&Tank1_set_return_status,0x13);
}
void func_Tank2_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_High_Warning_or_Low_Alarm(p,sn,deal_type,&Tank2_set_return_status,0x1F);
}

void func_Tank3_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_High_Warning_or_Low_Alarm(p,sn,deal_type,&Tank3_set_return_status,0x2B);
}

void func_Tank4_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_High_Warning_or_Low_Alarm(p,sn,deal_type,&Tank4_set_return_status,0x37);
}

void func_Tank_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd)
{
	  char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			  if((base_return_status.uint&0x03)==0x01)
				{

					sprintf(display_buf,"%dGal",Tank_status->val_alarm_H);
				}
				else
				{
		      sprintf(display_buf,"%dL",Tank_status->val_alarm_H);
				}
			
				Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(tanks_setup_item[sn].x_val+X_set_mid_offset,tanks_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
    }
		else if(deal_type==TO_UP)
		{
			  
		}
		else if(deal_type==TO_DOWN)
		{
			 
		}
		else if(deal_type==TO_DEAL)
		{
       keyboard_ui_step=KEYBOARD_PAGE_NUM;
		     //ui_disply_keyboard();
				// f_ui_new_input_bat_capacity = TRUE;
			   Set_val_input_target_p(&Tank_status->val_alarm_H,&Tank_status->val_alarm_H);
			   tanks_now_set_send_id=set_cmd;
				 f_need_ui_disply_keyboard = TRUE;
		}
}

void func_Tank1_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_High_Alarm(p,sn,deal_type,&Tank1_set_return_status,0x14);
}
void func_Tank2_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_High_Alarm(p,sn,deal_type,&Tank2_set_return_status,0x20);
}
void func_Tank3_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_High_Alarm(p,sn,deal_type,&Tank3_set_return_status,0x2C);
}
void func_Tank4_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	func_Tank_High_Alarm(p,sn,deal_type,&Tank4_set_return_status,0x38);
}



void func_Tanks_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd)
{
	  char display_buf[32];
//	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{			
			if(Control_Unit_product_id!=NEW_CONTROL_UNIT_PRODUCT_ID)
				sprintf(display_buf,"KIB(K101)");
			else if(Tank_status->Tank_sensor_type==1)
				sprintf(display_buf,"KIB(K101)");
			else if(Tank_status->Tank_sensor_type==2)
        sprintf(display_buf,"US");//(240-30)
			else if(Tank_status->Tank_sensor_type==3)
        sprintf(display_buf,"European");  	//(0-180)		
			else
				 sprintf(display_buf,"Unkown");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(tanks_setup_item[sn].x_val+X_set_mid_offset,tanks_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);

    }
		else if(deal_type==TO_UP)
		{
			  if(Tank_status->Tank_sensor_type <3)
				{
			    Tank_status->Tank_sensor_type ++;				 
				}
				else 
				{			
			   Tank_status->Tank_sensor_type = 1;
				}
				 send_FlC200_set_cmd(set_cmd,Tank_status->Tank_sensor_type);
		   f_display_tanks_setup_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
			 if(Tank_status->Tank_sensor_type > 1)
				{
			    Tank_status->Tank_sensor_type--;
				}
				else
				{			
			    Tank_status->Tank_sensor_type = 3;
				}
				send_FlC200_set_cmd(set_cmd,Tank_status->Tank_sensor_type);
		  f_display_tanks_setup_info = TRUE;
		}
		else if(deal_type==TO_DEAL)
		{

		}
}

void func_Tank1_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
   func_Tanks_Sensor_Type(p,sn,deal_type,&Tank1_set_return_status,0x11);
}
void func_Tank2_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
   func_Tanks_Sensor_Type(p,sn,deal_type,&Tank2_set_return_status,0x1d);
}
void func_Tank3_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
   func_Tanks_Sensor_Type(p,sn,deal_type,&Tank3_set_return_status,0x29);
}
void func_Tank4_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
   func_Tanks_Sensor_Type(p,sn,deal_type,&Tank4_set_return_status,0x35);
}


void check_tanks_setup_status(bool upgrage)
{
	static TANK_SET_STATUS old_Tank1_set_return_status,old_Tank2_set_return_status,old_Tank3_set_return_status,old_Tank4_set_return_status;
  if((memcmp(&old_Tank1_set_return_status,&Tank1_set_return_status,sizeof(TANK_SET_STATUS)))||\
		(memcmp(&old_Tank2_set_return_status,&Tank2_set_return_status,sizeof(TANK_SET_STATUS)))||\
			(memcmp(&old_Tank3_set_return_status,&Tank3_set_return_status,sizeof(TANK_SET_STATUS)))||\
				(memcmp(&old_Tank4_set_return_status,&Tank4_set_return_status,sizeof(TANK_SET_STATUS))))
  {
    memcpy(&old_Tank1_set_return_status,&Tank1_set_return_status,sizeof(TANK_SET_STATUS));
		memcpy(&old_Tank2_set_return_status,&Tank2_set_return_status,sizeof(TANK_SET_STATUS));
		memcpy(&old_Tank3_set_return_status,&Tank3_set_return_status,sizeof(TANK_SET_STATUS));
		memcpy(&old_Tank4_set_return_status,&Tank4_set_return_status,sizeof(TANK_SET_STATUS));
		f_display_tanks_setup_info = TRUE;
		if(upgrage)
			f_display_tanks_setup_info_upgrage = TRUE;
	}
}
void display_tanks_setup_info(bool upgrage)
{

//	u8 i;
	//setup_item_info_t *setup_p;
	setup_page_t *setup_page_p;
	lcd_dis_item_t *setup_item_p;
	static u8 last_now_item = TOP_SIDE_PAGE_TANKS_MUN;

	setup_page_p = &tanks_setup_page;
	setup_item_p = tanks_setup_item;
	
	check_tanks_setup_status(FALSE);
	f_display_tanks_setup_info = FALSE;
	
	
	if(last_now_item!=page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].now_item)
	{
	   last_now_item=page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].now_item;
		 /*if(last_now_item==TOP_SIDE_PAGE_TANKS_SETUP)
		 {
		   // tanks_setup_item[TANKS_SET_ICO_NUM-1].key_type = KEY_TYPE_ONCE;
	     // tanks_setup_item[TANKS_SET_ICO_NUM-1].last_status = STATUS_IDLE;
	     // tanks_setup_item[TANKS_SET_ICO_NUM-1].now_status = STATUS_IDLE;
		 }
		 else
		 {
		    tanks_setup_item[15].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	      tanks_setup_item[15].last_status = STATUS_IDLE;
	      tanks_setup_item[15].now_status = STATUS_IDLE;
		 }*/
		// if(page_top_side[LEFT_SIDE_PAGE_TANKS].now_item)
		 setup_page_p->now_p = tanks_settings;
     setup_page_p->now_page_deep = MENU_DEEP_1TH;
		 last_now_page_num = 0;
		// setup_page_p->now_page_num = 0;
     setup_page_p->now_page_num = 0;
		
	}
	//page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	//page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].last_status = STATUS_IDLE;
	//page_home.page_top_side[LEFT_SIDE_PAGE_TANKS].item[TOP_SIDE_PAGE_TANKS_SETUP].now_status = STATUS_IDLE;
  sysprintf("\r\n setup_page_p->now_page_num:%d MAX:%d",setup_page_p->now_page_num,setup_page_p->max_page_num);
	
	display_setup_page(f_display_tanks_setup_info_upgrage,upgrage,setup_page_p,setup_item_p,"Tanks Settings");
	f_display_tanks_setup_info_upgrage = FALSE;

}




BOOL page_tanks_setup_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
  return FALSE;

}
///////////////////////初始化////////////////////////////////////////


extern lcd_dis_item_t *p_system_item_d[SYSTEM_SYSTEM_ICO_NUM];//借用system_item界面
extern lcd_dis_item_t *p_system_item_u[SYSTEM_SYSTEM_ICO_NUM];
void ui_tanks_setup_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_TANKS][TOP_SIDE_PAGE_TANKS_SETUP];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=SYSTEM_SYSTEM_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only

	
	
	 if(Control_Unit_product_id!=NEW_CONTROL_UNIT_PRODUCT_ID)
	 {
		 Tank1_settings[4].setup_menu_touch_type = TOUCH_TYPE_NONE;
		 Tank2_settings[4].setup_menu_touch_type = TOUCH_TYPE_NONE;
		 Tank3_settings[4].setup_menu_touch_type = TOUCH_TYPE_NONE;
		 Tank4_settings[4].setup_menu_touch_type = TOUCH_TYPE_NONE;
	 }
	 else
	 {
		 Tank1_settings[4].setup_menu_touch_type = TOUCH_TYPE_LEFT_RIGHT;
		 Tank2_settings[4].setup_menu_touch_type = TOUCH_TYPE_LEFT_RIGHT;
		 Tank3_settings[4].setup_menu_touch_type = TOUCH_TYPE_LEFT_RIGHT;
		 Tank4_settings[4].setup_menu_touch_type = TOUCH_TYPE_LEFT_RIGHT;
	 }

	
	 //设置界面ui_system_init()这个要先初始化，其他设置界面以system_item这个为基准
   p->item = tanks_setup_item;
   for(i=0;i<SYSTEM_SYSTEM_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_system_item_d[i],sizeof(lcd_dis_item_t));
	   p->item[i].pic_item =p_system_item_u[i]->pic_item;//
   	 p->item[i].size_of_pic_item = p_system_item_u[i]->size_of_pic_item ;
		 p->item[i].f = p_func_tanks_setup_item_d[i];
	 
	 }
	 
	  p->item[15].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	  p->item[15].last_status = STATUS_IDLE;
	  p->item[15].now_status = STATUS_IDLE;
	 //int setting_list
	 display_tanks_setup_info(FALSE);
 }


