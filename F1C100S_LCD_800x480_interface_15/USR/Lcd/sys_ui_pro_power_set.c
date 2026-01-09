#include "includes.h"

void disply_power_set_name_bg(u8 ich,bool upgrade)
{
}
u8 power_set_send_id[9] = 
{
  0x01,
	0x02,
	0x03,	
	
	0x06,
	0x07,
	0x08,
	
	0x0A,
	0x0B,
	0x0C,

};
u16 *power_display_set_ch[9] = 
{
  &main_battery_set_status.V_warning_L,
	&main_battery_set_status.V_warning_H,
	&main_battery_set_status.V_SOC_warning_L,
	
	&assi1_battery_set_status.V_warning_L,
	&assi1_battery_set_status.V_warning_H,
	&assi1_battery_set_status.V_SOC_warning_L,	
	
	&assi2_battery_set_status.V_warning_L,
	&assi2_battery_set_status.V_warning_H,
	&assi2_battery_set_status.V_SOC_warning_L,	

};
u16 *power_display_set_return_ch[9] = 
{
  &main_battery_set_return_status.V_warning_L,
	&main_battery_set_return_status.V_warning_H,
	&main_battery_set_return_status.V_SOC_warning_L,
	
	&assi1_battery_set_return_status.V_warning_L,
	&assi1_battery_set_return_status.V_warning_H,
	&assi1_battery_set_return_status.V_SOC_warning_L,	
	
	&assi2_battery_set_return_status.V_warning_L,
	&assi2_battery_set_return_status.V_warning_H,
	&assi2_battery_set_return_status.V_SOC_warning_L,	

};


 u8 power_now_set_send_id = 0;
extern void func_power_setup_btn1_d(void* p,u8 sn);
extern void func_power_setup_btn1_u(void* p,u8 sn);
extern void func_power_setup_btn2_d(void* p,u8 sn);
extern void func_power_setup_btn2_u(void* p,u8 sn);
extern void func_power_setup_btn3_u(void* p,u8 sn);
extern void func_power_setup_btn3_d(void* p,u8 sn);
extern void func_power_setup_btn4_d(void* p,u8 sn);
extern void func_power_setup_btn4_u(void* p,u8 sn);
extern void func_power_setup_b_power_setup_d(void* p,u8 sn);
extern void func_power_setup_b_power_setup_u(void* p,u8 sn);
extern void func_power_setup_headline(void* p,u8 sn);
extern void func_power_setup_nextpage_d(void* p,u8 sn);
extern void func_power_setup_nextpage_o(void* p,u8 sn);
extern void func_power_setup_nextpage_u(void* p,u8 sn);
extern void func_power_setup_prepage_d(void* p,u8 sn);
extern void func_power_setup_prepage_o(void* p,u8 sn);
extern void func_power_setup_prepage_u(void* p,u8 sn);
extern void func_tanks_b_setup_d(void* p,u8 sn);
extern void func_tanks_b_setup_u(void* p,u8 sn);



extern void func_power_setup_b_back_d(void* p,u8 sn);
extern void func_power_setup_b_back_u(void* p,u8 sn);

	
extern void func_power_setup_left_d(void* p,u8 sn);
extern void func_power_setup_left_u(void* p,u8 sn);
extern void func_power_setup_right_d(void* p,u8 sn);
extern void func_power_setup_right_u(void* p,u8 sn);
extern void func_power_setup_left2_d(void* p,u8 sn);
extern void func_power_setup_left2_u(void* p,u8 sn);
extern void func_power_setup_right2_d(void* p,u8 sn);
extern void func_power_setup_right2_u(void* p,u8 sn);
extern void func_power_setup_left3_d(void* p,u8 sn);
extern void func_power_setup_left3_u(void* p,u8 sn);
extern void func_power_setup_right3_d(void* p,u8 sn);
extern void func_power_setup_right3_u(void* p,u8 sn);
extern void func_power_setup_left4_d(void* p,u8 sn);
extern void func_power_setup_left4_u(void* p,u8 sn);
extern void func_power_setup_right4_d(void* p,u8 sn);
extern void func_power_setup_right4_u(void* p,u8 sn);

extern setup_item_info_t power_settings[];
bool f_display_power_setup_info = FALSE;
bool f_display_power_setup_info_upgrage = FALSE;

	
void*p_func_power_setup_item_d[SYSTEM_SYSTEM_ICO_NUM]=
{	
	
  &func_power_setup_headline,
  &func_power_setup_btn1_d,
  &func_power_setup_btn2_d,
  &func_power_setup_btn3_d,
  &func_power_setup_btn4_d,
  &func_power_setup_nextpage_d,
  &func_power_setup_prepage_d,
	&func_power_setup_left_d,
	&func_power_setup_left2_d,
	&func_power_setup_left3_d,
	&func_power_setup_left4_d,//10
	&func_power_setup_right_d,
	&func_power_setup_right2_d,
	&func_power_setup_right3_d,
	&func_power_setup_right4_d,
	&func_power_setup_b_back_d,	
};
	
lcd_dis_item_t power_setup_item[SYSTEM_SYSTEM_ICO_NUM];

void func_Start_Battery_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			 sprintf(display_buf,"%d.%dV",main_battery_set_return_status.V_warning_L/10,main_battery_set_return_status.V_warning_L%10);
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
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
			   Set_val_input_target_p(&main_battery_set_return_status.V_warning_L,&main_battery_set_return_status.V_warning_L);
			   power_now_set_send_id=0x01;
			char_input_target_type = 0;
				 f_need_ui_disply_keyboard = TRUE;
		}
}

void func_Start_Battery_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)
{
char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			 sprintf(display_buf,"%d.%dV",main_battery_set_return_status.V_warning_H/10,main_battery_set_return_status.V_warning_H%10);
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
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
			   Set_val_input_target_p(&main_battery_set_return_status.V_warning_H,&main_battery_set_return_status.V_warning_H);
			   power_now_set_send_id=0x02;
			char_input_target_type = 0;
				 f_need_ui_disply_keyboard = TRUE;
		}
}

void func_Start_Battery_Soc_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
    char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			 sprintf(display_buf,"%d%%",main_battery_set_return_status.V_SOC_warning_L);
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
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
			   Set_val_input_target_p(&main_battery_set_return_status.V_SOC_warning_L,&main_battery_set_return_status.V_SOC_warning_L);
			   power_now_set_send_id=0x03;
			char_input_target_type = 2;
				 f_need_ui_disply_keyboard = TRUE;
		}
}

void func_Assi_Battery_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
	  char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			 sprintf(display_buf,"%d.%dV",assi1_battery_set_return_status.V_warning_L/10,assi1_battery_set_return_status.V_warning_L%10);
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
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
			   Set_val_input_target_p(&assi1_battery_set_return_status.V_warning_L,&assi1_battery_set_return_status.V_warning_L);
			   power_now_set_send_id=0x06;
			char_input_target_type = 0;
				 f_need_ui_disply_keyboard = TRUE;
		}
}
	
void func_Assi_Battery_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
    char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			 sprintf(display_buf,"%d.%dV",assi1_battery_set_return_status.V_warning_H/10,assi1_battery_set_return_status.V_warning_H%10);
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
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
			   Set_val_input_target_p(&assi1_battery_set_return_status.V_warning_H,&assi1_battery_set_return_status.V_warning_H);
			   power_now_set_send_id=0x07;
			  char_input_target_type = 0;
				 f_need_ui_disply_keyboard = TRUE;
		}
}
	
void func_Assi_Battery_Soc_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
      char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			 sprintf(display_buf,"%d%%",assi1_battery_set_return_status.V_SOC_warning_L);
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
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
			   Set_val_input_target_p(&assi1_battery_set_return_status.V_SOC_warning_L,&assi1_battery_set_return_status.V_SOC_warning_L);
			   power_now_set_send_id=0x08;
			   char_input_target_type = 2;
				 f_need_ui_disply_keyboard = TRUE;
		}
}
void func_Input_Current_Limit(void* p,u8 sn,DEAl_TYPE deal_type)	
{
      char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			 sprintf(display_buf,"%d.%dA",parts_set_return_status.Inverter_Input_Current_Limit/10,parts_set_return_status.Inverter_Input_Current_Limit%10);
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
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
			   Set_val_input_target_p(&parts_set_return_status.Inverter_Input_Current_Limit,&parts_set_return_status.Inverter_Input_Current_Limit);
			   power_now_set_send_id=0x4A;
			   char_input_target_type = 1;
				 f_need_ui_disply_keyboard = TRUE;
		}
}



void func_inverter_Alarm(void* p,u8 sn,DEAl_TYPE deal_type,u16 *p_alarm_status,u8 bit_offset)	
{
	  char display_buf[32];
	  u8 temp_status = 0;
	  temp_status = (u8)((*p_alarm_status>>bit_offset)&0x0003);
	
	  if(deal_type==TO_INIT)
		{
			switch(temp_status)
			{
				case 0:
					sprintf(display_buf,"Disabled");
					break;
			  case 1:
					sprintf(display_buf,"Alarm Only");
					break;
				case 2:
					sprintf(display_buf,"Alarm&Warn");
					break;
				default:
					sprintf(display_buf,"Unkown");
					break;			
			}

			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
		
    }
		else if(deal_type==TO_UP)
		{
			  temp_status++;
			  if(temp_status>2)
					temp_status = 2;
       
			 *p_alarm_status  &=	~(0x0003<<bit_offset);
			 *p_alarm_status  |=	(temp_status<<bit_offset);	
			 send_FlC200_set_cmd(0x4B,*p_alarm_status );
		   f_display_power_setup_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
			  if(temp_status)
				{
			    temp_status--;
					if(temp_status>2)
					temp_status = 2;
				}
				*p_alarm_status &=	~(0x0003<<bit_offset);
			  *p_alarm_status |=	(temp_status<<bit_offset);	
				send_FlC200_set_cmd(0x4B,*p_alarm_status );
		   f_display_power_setup_info = TRUE;
		}
		else if(deal_type==TO_DEAL)
		{

		}




}


void func_Low_Battery_Voltage_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
	 func_inverter_Alarm(p,sn,deal_type,&parts_set_return_status.Inverter_Alarm_setup1,14);	
}
void func_High_Temperature_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)		
{
	 func_inverter_Alarm(p,sn,deal_type,&parts_set_return_status.Inverter_Alarm_setup1,12);
}
void func_Inverter_Overload_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
	 func_inverter_Alarm(p,sn,deal_type,&parts_set_return_status.Inverter_Alarm_setup1,10);
}
void func_High_DC_Ripple_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
	 func_inverter_Alarm(p,sn,deal_type,&parts_set_return_status.Inverter_Alarm_setup1,8);
}	
void func_High_DC_Voltage_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)		
{
	 func_inverter_Alarm(p,sn,deal_type,&parts_set_return_status.Inverter_Alarm_setup1,6);
}
void func_High_DC_Current_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
	 func_inverter_Alarm(p,sn,deal_type,&parts_set_return_status.Inverter_Alarm_setup1,4);
}
void func_Temperature_Sense_Error_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)		
{
	 func_inverter_Alarm(p,sn,deal_type,&parts_set_return_status.Inverter_Alarm_setup1,2);
}
void func_Voltage_Sense_Error_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
	 func_inverter_Alarm(p,sn,deal_type,&parts_set_return_status.Inverter_Alarm_setup1,0);
}
void func_VE_Bus_Error_Alarm(void* p,u8 sn,DEAl_TYPE deal_type)	
{
	
	char display_buf[32];
	  u8 temp_status = 0;
	  temp_status = (u8)((parts_set_return_status.Inverter_Alarm_setup2>>14)&0x03);
	
	  if(deal_type==TO_INIT)
		{
			switch(temp_status)
			{
				case 0:
					sprintf(display_buf,"Disabled");
					break;
			  case 1:
					sprintf(display_buf,"Enabled");
					break;
				default:
					sprintf(display_buf,"Unkown");
					break;			
			}

			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
		
    }
		else if(deal_type==TO_UP)
		{
			  if(temp_status)
					temp_status = 0;
				else
					temp_status = 1;
       
			 parts_set_return_status.Inverter_Alarm_setup2 &=	~(0x0003<<14);
			 parts_set_return_status.Inverter_Alarm_setup2 |=	(temp_status<<14);	
			 send_FlC200_set_cmd(0x4C,parts_set_return_status.Inverter_Alarm_setup2);
		   f_display_power_setup_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
			  if(temp_status)
					temp_status = 0;
				else
					temp_status = 1;
				parts_set_return_status.Inverter_Alarm_setup2 &=	~(0x0003<<14);
			  parts_set_return_status.Inverter_Alarm_setup2 |=	(temp_status<<14);	
			  send_FlC200_set_cmd(0x4C,parts_set_return_status.Inverter_Alarm_setup2);
				f_display_power_setup_info = TRUE;
		}
		else if(deal_type==TO_DEAL)
		{

		}


}














setup_item_info_t Start_Battery_settings[]=
{
	 {"Low Alarm",TOUCH_TYPE_KEYBOARD,power_settings,empty_son_p,func_Start_Battery_Low_Alarm},	
	 {"High Alarm",TOUCH_TYPE_KEYBOARD,power_settings,empty_son_p,func_Start_Battery_High_Alarm},	
	 //{"Soc Alarm",TOUCH_TYPE_KEYBOARD,power_settings,empty_son_p,func_Start_Battery_Soc_Alarm},	
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t Assi_Battery_settings[]=
{
	 {"Low Alarm",TOUCH_TYPE_KEYBOARD,power_settings,empty_son_p,func_Assi_Battery_Low_Alarm},	
	 {"High Alarm",TOUCH_TYPE_KEYBOARD,power_settings,empty_son_p,func_Assi_Battery_High_Alarm},	
	 {"Soc Alarm",TOUCH_TYPE_KEYBOARD,power_settings,empty_son_p,func_Assi_Battery_Soc_Alarm},	
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t Victron_Multiplusn_Inverter_settings[]=
{
	 {"Input Current Limit",TOUCH_TYPE_KEYBOARD,power_settings,empty_son_p,func_Input_Current_Limit},
	 /*{"Low Battery Voltage Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_Low_Battery_Voltage_Alarm},	
	 {"High Temperature Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_High_Temperature_Alarm},	
	 {"Inverter Overload Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_Inverter_Overload_Alarm},	
	 {"High DC Ripple Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_High_DC_Ripple_Alarm},	
	 {"High DC Voltage Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_High_DC_Voltage_Alarm},	
	 {"High DC Current Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_High_DC_Current_Alarm},	
	 {"Temperature Sense Error Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_Temperature_Sense_Error_Alarm},	
	 {"Voltage Sense Error Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_Voltage_Sense_Error_Alarm},	
	 {"VE.Bus Error Alarm",TOUCH_TYPE_LEFT_RIGHT,power_settings,empty_son_p,func_VE_Bus_Error_Alarm},	
	*/
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t power_settings[]=
{
   {"Start Battery",TOUCH_TYPE_ENTER,empty_father_p,Start_Battery_settings,empty_fun},
	 {"Assi Battery",TOUCH_TYPE_ENTER,empty_father_p,Assi_Battery_settings,empty_fun},
	 {"Victron Multiplus Inverter",TOUCH_TYPE_ENTER,empty_father_p,Victron_Multiplusn_Inverter_settings,empty_fun},
	 //{"Tank4",TOUCH_TYPE_ENTER,empty_father_p,Tank4_settings,empty_fun},//
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_page_t power_setup_page;

void check_power_setup_status(bool upgrage)
{
	static BATTERY_SET_STATUS old_main_battery_set_return_status,old_assi1_battery_set_return_status;
	static u16 old_Inverter_Input_Current_Limit;
  if((memcmp(&old_main_battery_set_return_status,&main_battery_set_return_status,sizeof(BATTERY_SET_STATUS)))||\
		(memcmp(&old_assi1_battery_set_return_status,&assi1_battery_set_return_status,sizeof(BATTERY_SET_STATUS)))||\
		(old_Inverter_Input_Current_Limit!=parts_set_return_status.Inverter_Input_Current_Limit))
  {
    memcpy(&old_main_battery_set_return_status,&main_battery_set_return_status,sizeof(BATTERY_SET_STATUS));
		memcpy(&old_assi1_battery_set_return_status,&assi1_battery_set_return_status,sizeof(BATTERY_SET_STATUS));
		old_Inverter_Input_Current_Limit =parts_set_return_status.Inverter_Input_Current_Limit;
		f_display_power_setup_info = TRUE;
		if(upgrage)
			f_display_power_setup_info_upgrage = TRUE;
	}
}

void display_power_setup_info(bool upgrage)
{

//	u8 i;
	//setup_item_info_t *setup_p;
	setup_page_t *setup_page_p;
	lcd_dis_item_t *setup_item_p;
	static u8 last_now_item = TOP_SIDE_PAGE_POWER_MUN;

	setup_page_p = &power_setup_page;
	setup_item_p = power_setup_item;
	
	check_power_setup_status(FALSE);
	f_display_power_setup_info = FALSE;
	
	
	if(last_now_item!=page_home.page_top_side[LEFT_SIDE_PAGE_POWER].now_item)
	{
	   last_now_item=page_home.page_top_side[LEFT_SIDE_PAGE_POWER].now_item;
		 setup_page_p->now_p = power_settings;
     setup_page_p->now_page_deep = MENU_DEEP_1TH;
		 last_now_page_num = 0;
     setup_page_p->now_page_num = 0;
		
		if(parts_set_return_status.Inverter_Mode<=3)
		{
			 power_settings[2].setup_menu_touch_type = TOUCH_TYPE_ENTER;
		}
		else
		{ 
			 power_settings[2].setup_menu_touch_type = TOUCH_TYPE_NONE_DIS_DIM;
		}
		
	}
  sysprintf("\r\n setup_page_p->now_page_num:%d MAX:%d",setup_page_p->now_page_num,setup_page_p->max_page_num);
	
	display_setup_page(f_display_power_setup_info_upgrage,upgrage,setup_page_p,setup_item_p,"Power Settings");
	f_display_power_setup_info_upgrage = FALSE;

}




BOOL page_power_setup_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
  return FALSE;

}
///////////////////////初始化////////////////////////////////////////


extern lcd_dis_item_t *p_system_item_d[SYSTEM_SYSTEM_ICO_NUM];//借用system_item界面
extern lcd_dis_item_t *p_system_item_u[SYSTEM_SYSTEM_ICO_NUM];
void ui_power_setup_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_POWER][TOP_SIDE_PAGE_POWER_SETUP];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=SYSTEM_SYSTEM_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


	
	 //设置界面ui_system_init()这个要先初始化，其他设置界面以system_item这个为基准
   p->item = power_setup_item;
   for(i=0;i<SYSTEM_SYSTEM_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_system_item_d[i],sizeof(lcd_dis_item_t));
	   p->item[i].pic_item =p_system_item_u[i]->pic_item;//
   	 p->item[i].size_of_pic_item = p_system_item_u[i]->size_of_pic_item ;
		 p->item[i].f = p_func_power_setup_item_d[i];
	 
	 }
	 //int setting_list
	 display_power_setup_info(FALSE);
 }




