#include "includes.h"



extern void func_system_accessories_btn1_d(void* p,u8 sn);
extern void func_system_accessories_btn1_u(void* p,u8 sn);
extern void func_system_accessories_btn2_d(void* p,u8 sn);
extern void func_system_accessories_btn2_u(void* p,u8 sn);
extern void func_system_accessories_btn3_u(void* p,u8 sn);
extern void func_system_accessories_btn3_d(void* p,u8 sn);
extern void func_system_accessories_btn4_d(void* p,u8 sn);
extern void func_system_accessories_btn4_u(void* p,u8 sn);
extern void func_system_accessories_b_system_accessories_d(void* p,u8 sn);
extern void func_system_accessories_b_system_accessories_u(void* p,u8 sn);
extern void func_system_accessories_headline(void* p,u8 sn);
extern void func_system_accessories_nextpage_d(void* p,u8 sn);
extern void func_system_accessories_nextpage_o(void* p,u8 sn);
extern void func_system_accessories_nextpage_u(void* p,u8 sn);
extern void func_system_accessories_prepage_d(void* p,u8 sn);
extern void func_system_accessories_prepage_o(void* p,u8 sn);
extern void func_system_accessories_prepage_u(void* p,u8 sn);
extern void func_system_b_accessories_d(void* p,u8 sn);
extern void func_system_b_accessories_u(void* p,u8 sn);






extern const unsigned char system_btn1_d[];
extern const unsigned char system_btn2_d[];
extern const unsigned char system_btn3_d[];
extern const unsigned char system_btn4_d[];
extern const unsigned char system_btn1_u[];
extern const unsigned char system_btn2_u[];
extern const unsigned char system_btn3_u[];
extern const unsigned char system_btn4_u[];
extern const unsigned char system_b_back_d[];
extern const unsigned char system_b_back_u[];

extern const unsigned char system_headline[];
extern const unsigned char system_nextpage_d[];
extern const unsigned char system_nextpage_u[];
extern const unsigned char system_nextpage_o[];
extern const unsigned char system_prepage_d[];
extern const unsigned char system_prepage_o[];
extern const unsigned char system_prepage_u[];
extern void func_system_accessories_b_back_d(void* p,u8 sn);
extern void func_system_accessories_b_back_u(void* p,u8 sn);


lcd_dis_item_t t_system_accessories_btn1_d={(unsigned char*)system_btn1_d,(unsigned char*)system_btn1_d,(unsigned char*)system_btn1_d,0,0,3496,3496,3496,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_btn1_d,Y_system_accessories_btn1_d,X_system_accessories_btn1_d+732,Y_system_accessories_btn1_d+85,0,&func_system_accessories_btn1_d};
lcd_dis_item_t t_system_accessories_btn1_u={(unsigned char*)system_btn1_u,(unsigned char*)system_btn1_u,(unsigned char*)system_btn1_u,0,0,3070,3070,3070,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_btn1_u,Y_system_accessories_btn1_u,X_system_accessories_btn1_u+732,Y_system_accessories_btn1_u+85,0,&func_system_accessories_btn1_u};
lcd_dis_item_t t_system_accessories_btn2_d={(unsigned char*)system_btn2_d,(unsigned char*)system_btn2_d,(unsigned char*)system_btn2_d,0,0,3690,3690,3690,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_btn2_d,Y_system_accessories_btn2_d,X_system_accessories_btn2_d+732,Y_system_accessories_btn2_d+85,0,&func_system_accessories_btn2_d};
lcd_dis_item_t t_system_accessories_btn2_u={(unsigned char*)system_btn2_u,(unsigned char*)system_btn2_u,(unsigned char*)system_btn2_u,0,0,3325,3325,3325,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_btn2_u,Y_system_accessories_btn2_u,X_system_accessories_btn2_u+732,Y_system_accessories_btn2_u+85,0,&func_system_accessories_btn2_u};
lcd_dis_item_t t_system_accessories_btn3_d={(unsigned char*)system_btn3_d,(unsigned char*)system_btn3_d,(unsigned char*)system_btn3_d,0,0,4427,4427,4427,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_btn3_d,Y_system_accessories_btn3_d,X_system_accessories_btn3_d+732,Y_system_accessories_btn3_d+85,0,&func_system_accessories_btn3_d};
lcd_dis_item_t t_system_accessories_btn3_u={(unsigned char*)system_btn3_u,(unsigned char*)system_btn3_u,(unsigned char*)system_btn3_u,0,0,4101,4101,4101,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_btn3_u,Y_system_accessories_btn3_u,X_system_accessories_btn3_u+732,Y_system_accessories_btn3_u+85,0,&func_system_accessories_btn3_u};
lcd_dis_item_t t_system_accessories_btn4_d={(unsigned char*)system_btn4_d,(unsigned char*)system_btn4_d,(unsigned char*)system_btn4_d,0,0,5049,5049,5049,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_btn4_d,Y_system_accessories_btn4_d,X_system_accessories_btn4_d+732,Y_system_accessories_btn4_d+85,0,&func_system_accessories_btn4_d};
lcd_dis_item_t t_system_accessories_btn4_u={(unsigned char*)system_btn4_u,(unsigned char*)system_btn4_u,(unsigned char*)system_btn4_u,0,0,4641,4641,4641,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_btn4_u,Y_system_accessories_btn4_u,X_system_accessories_btn4_u+732,Y_system_accessories_btn4_u+85,0,&func_system_accessories_btn4_u};
lcd_dis_item_t t_system_accessories_headline={(unsigned char*)system_headline,(unsigned char*)system_headline,(unsigned char*)system_headline,0,0,1038,1038,1038,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_headline,Y_system_accessories_headline,X_system_accessories_headline+861,Y_system_accessories_headline+3,0,&func_system_accessories_headline};
lcd_dis_item_t t_system_accessories_nextpage_d={(unsigned char*)system_nextpage_d,(unsigned char*)system_nextpage_d,(unsigned char*)system_nextpage_d,0,0,3882,3882,3882,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_nextpage_d,Y_system_accessories_nextpage_d,X_system_accessories_nextpage_d+120,Y_system_accessories_nextpage_d+85,0,&func_system_accessories_nextpage_d};
lcd_dis_item_t t_system_accessories_nextpage_o={(unsigned char*)system_nextpage_o,(unsigned char*)system_nextpage_o,(unsigned char*)system_nextpage_o,0,0,3413,3413,3413,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_nextpage_o,Y_system_accessories_nextpage_o,X_system_accessories_nextpage_o+120,Y_system_accessories_nextpage_o+85,0,&func_system_accessories_nextpage_o};
lcd_dis_item_t t_system_accessories_nextpage_u={(unsigned char*)system_nextpage_u,(unsigned char*)system_nextpage_u,(unsigned char*)system_nextpage_u,0,0,3567,3567,3567,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_nextpage_u,Y_system_accessories_nextpage_u,X_system_accessories_nextpage_u+120,Y_system_accessories_nextpage_u+85,0,&func_system_accessories_nextpage_u};
lcd_dis_item_t t_system_accessories_prepage_d={(unsigned char*)system_prepage_d,(unsigned char*)system_prepage_d,(unsigned char*)system_prepage_d,0,0,3474,3474,3474,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_prepage_d,Y_system_accessories_prepage_d,X_system_accessories_prepage_d+120,Y_system_accessories_prepage_d+85,0,&func_system_accessories_prepage_d};
lcd_dis_item_t t_system_accessories_prepage_o={(unsigned char*)system_prepage_o,(unsigned char*)system_prepage_o,(unsigned char*)system_prepage_o,0,0,2990,2990,2990,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_prepage_o,Y_system_accessories_prepage_o,X_system_accessories_prepage_o+120,Y_system_accessories_prepage_o+85,0,&func_system_accessories_prepage_o};
lcd_dis_item_t t_system_accessories_prepage_u={(unsigned char*)system_prepage_u,(unsigned char*)system_prepage_u,(unsigned char*)system_prepage_u,0,0,3110,3110,3110,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_accessories_prepage_u,Y_system_accessories_prepage_u,X_system_accessories_prepage_u+120,Y_system_accessories_prepage_u+85,0,&func_system_accessories_prepage_u};

lcd_dis_item_t t_system_accessories_b_back_d={(unsigned char*)system_b_back_d,(unsigned char*)system_b_back_d,(unsigned char*)system_b_back_d,0,0,3958,3958,3958,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_b_back_d,Y_system_b_back_d,X_system_b_back_d+126,Y_system_b_back_d+71,0,&func_system_accessories_b_back_d};
lcd_dis_item_t t_system_accessories_b_back_u={(unsigned char*)system_b_back_u,(unsigned char*)system_b_back_u,(unsigned char*)system_b_back_u,0,0,3856,3856,3856,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_b_back_u,Y_system_b_back_u,X_system_b_back_u+126,Y_system_b_back_u+71,0,&func_system_accessories_b_back_u};

	
	
extern void func_set_accessories_left_d(void* p,u8 sn);
extern void func_set_accessories_left_u(void* p,u8 sn);
extern void func_set_accessories_right_d(void* p,u8 sn);
extern void func_set_accessories_right_u(void* p,u8 sn);
extern void func_set_accessories_left2_d(void* p,u8 sn);
extern void func_set_accessories_left2_u(void* p,u8 sn);
extern void func_set_accessories_right2_d(void* p,u8 sn);
extern void func_set_accessories_right2_u(void* p,u8 sn);
extern void func_set_accessories_left3_d(void* p,u8 sn);
extern void func_set_accessories_left3_u(void* p,u8 sn);
extern void func_set_accessories_right3_d(void* p,u8 sn);
extern void func_set_accessories_right3_u(void* p,u8 sn);
extern void func_set_accessories_left4_d(void* p,u8 sn);
extern void func_set_accessories_left4_u(void* p,u8 sn);
extern void func_set_accessories_right4_d(void* p,u8 sn);
extern void func_set_accessories_right4_u(void* p,u8 sn);
extern const unsigned char set_left_d[];
extern const unsigned char set_left_u[];
extern const unsigned char set_right_d[];
extern const unsigned char set_right_u[];


lcd_dis_item_t t_set_accessories_left_d={(unsigned char*)set_left_d,(unsigned char*)set_left_d,(unsigned char*)set_left_d,0,0,1929,1929,1929,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left_d,Y_set_left_d,X_set_left_d+48,Y_set_left_d+52,0,&func_set_accessories_left_d};
lcd_dis_item_t t_set_accessories_left_u={(unsigned char*)set_left_u,(unsigned char*)set_left_u,(unsigned char*)set_left_u,0,0,1609,1609,1609,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left_u,Y_set_left_u,X_set_left_u+48,Y_set_left_u+52,0,&func_set_accessories_left_u};
lcd_dis_item_t t_set_accessories_right_d={(unsigned char*)set_right_d,(unsigned char*)set_right_d,(unsigned char*)set_right_d,0,0,1802,1802,1802,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right_d,Y_set_right_d,X_set_right_d+48,Y_set_right_d+52,0,&func_set_accessories_right_d};
lcd_dis_item_t t_set_accessories_right_u={(unsigned char*)set_right_u,(unsigned char*)set_right_u,(unsigned char*)set_right_u,0,0,1595,1595,1595,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right_u,Y_set_right_u,X_set_right_u+48,Y_set_right_u+52,0,&func_set_accessories_right_u};


lcd_dis_item_t t_set_accessories_left2_d={(unsigned char*)set_left_d,(unsigned char*)set_left_d,(unsigned char*)set_left_d,0,0,1929,1929,1929,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left2_d,Y_set_left2_d,X_set_left2_d+48,Y_set_left2_d+52,0,&func_set_accessories_left2_d};
lcd_dis_item_t t_set_accessories_left2_u={(unsigned char*)set_left_u,(unsigned char*)set_left_u,(unsigned char*)set_left_u,0,0,1609,1609,1609,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left2_u,Y_set_left2_u,X_set_left2_u+48,Y_set_left2_u+52,0,&func_set_accessories_left2_u};
lcd_dis_item_t t_set_accessories_right2_d={(unsigned char*)set_right_d,(unsigned char*)set_right_d,(unsigned char*)set_right_d,0,0,1802,1802,1802,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right2_d,Y_set_right2_d,X_set_right2_d+48,Y_set_right2_d+52,0,&func_set_accessories_right2_d};
lcd_dis_item_t t_set_accessories_right2_u={(unsigned char*)set_right_u,(unsigned char*)set_right_u,(unsigned char*)set_right_u,0,0,1595,1595,1595,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right2_u,Y_set_right2_u,X_set_right2_u+48,Y_set_right2_u+52,0,&func_set_accessories_right2_u};

lcd_dis_item_t t_set_accessories_left3_d={(unsigned char*)set_left_d,(unsigned char*)set_left_d,(unsigned char*)set_left_d,0,0,1929,1929,1929,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left3_d,Y_set_left3_d,X_set_left3_d+48,Y_set_left3_d+52,0,&func_set_accessories_left3_d};
lcd_dis_item_t t_set_accessories_left3_u={(unsigned char*)set_left_u,(unsigned char*)set_left_u,(unsigned char*)set_left_u,0,0,1609,1609,1609,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left3_u,Y_set_left3_u,X_set_left3_u+48,Y_set_left3_u+52,0,&func_set_accessories_left3_u};
lcd_dis_item_t t_set_accessories_right3_d={(unsigned char*)set_right_d,(unsigned char*)set_right_d,(unsigned char*)set_right_d,0,0,1802,1802,1802,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right3_d,Y_set_right3_d,X_set_right3_d+48,Y_set_right3_d+52,0,&func_set_accessories_right3_d};
lcd_dis_item_t t_set_accessories_right3_u={(unsigned char*)set_right_u,(unsigned char*)set_right_u,(unsigned char*)set_right_u,0,0,1595,1595,1595,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right3_u,Y_set_right3_u,X_set_right3_u+48,Y_set_right3_u+52,0,&func_set_accessories_right3_u};

lcd_dis_item_t t_set_accessories_left4_d={(unsigned char*)set_left_d,(unsigned char*)set_left_d,(unsigned char*)set_left_d,0,0,1929,1929,1929,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left4_d,Y_set_left4_d,X_set_left4_d+48,Y_set_left4_d+52,0,&func_set_accessories_left4_d};
lcd_dis_item_t t_set_accessories_left4_u={(unsigned char*)set_left_u,(unsigned char*)set_left_u,(unsigned char*)set_left_u,0,0,1609,1609,1609,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left4_u,Y_set_left4_u,X_set_left4_u+48,Y_set_left4_u+52,0,&func_set_accessories_left4_u};
lcd_dis_item_t t_set_accessories_right4_d={(unsigned char*)set_right_d,(unsigned char*)set_right_d,(unsigned char*)set_right_d,0,0,1802,1802,1802,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right4_d,Y_set_right4_d,X_set_right4_d+48,Y_set_right4_d+52,0,&func_set_accessories_right4_d};
lcd_dis_item_t t_set_accessories_right4_u={(unsigned char*)set_right_u,(unsigned char*)set_right_u,(unsigned char*)set_right_u,0,0,1595,1595,1595,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right4_u,Y_set_right4_u,X_set_right4_u+48,Y_set_right4_u+52,0,&func_set_accessories_right4_u};

	
	
	/*

	//面按键列表 按下
lcd_dis_item_t *p_system_accessories_item_d[SYSTEM_ACC_ICO_NUM]=
{
 
	&t_system_accessories_headline,
  &t_system_accessories_btn1_d,
  &t_system_accessories_btn2_d,
  &t_system_accessories_btn3_d,
  &t_system_accessories_btn4_d,
  &t_system_accessories_nextpage_d,
  &t_system_accessories_prepage_d,
	&t_set_accessories_left_d,
	&t_set_accessories_left2_d,
	&t_set_accessories_left3_d,
	&t_set_accessories_left4_d,//10
	&t_set_accessories_right_d,
	&t_set_accessories_right2_d,
	&t_set_accessories_right3_d,
	&t_set_accessories_right4_d,
	&t_system_accessories_b_back_d,

};

//界面按键列表 弹起
lcd_dis_item_t *p_system_accessories_item_u[SYSTEM_ACC_ICO_NUM]=
{
	&t_system_accessories_headline,
  &t_system_accessories_btn1_u,
  &t_system_accessories_btn2_u,
  &t_system_accessories_btn3_u,
  &t_system_accessories_btn4_u,
  &t_system_accessories_nextpage_u,//5
  &t_system_accessories_prepage_u,
	&t_set_accessories_left_u,
	&t_set_accessories_left2_u,
	&t_set_accessories_left3_u,
	&t_set_accessories_left4_u,
  &t_set_accessories_right_u,
	&t_set_accessories_right2_u,
	&t_set_accessories_right3_u,
	&t_set_accessories_right4_u,
	&t_system_accessories_b_back_u,
	





};
*/

void*p_system_accessories_item_d[SYSTEM_SYSTEM_ICO_NUM]=
{	
	/*
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
	&func_power_setup_b_back_d,	*/
	
  &func_system_accessories_headline,
  &func_system_accessories_btn1_d,
  &func_system_accessories_btn2_d,
  &func_system_accessories_btn3_d,
  &func_system_accessories_btn4_d,
  &func_system_accessories_nextpage_d,
  &func_system_accessories_prepage_d,
  &func_set_accessories_left_d,
  &func_set_accessories_left2_d,
  &func_set_accessories_left3_d,
  &func_set_accessories_left4_d,//10
  &func_set_accessories_right_d,
  &func_set_accessories_right2_d,
  &func_set_accessories_right3_d,
  &func_set_accessories_right4_d,
  &func_system_accessories_b_back_d,
};
lcd_dis_item_t system_accessories_item[SYSTEM_ACC_ICO_NUM];



bool f_display_set_accessories_info_upgrage = FALSE;//强制更新页面
bool f_display_set_accessories_info = FALSE;
u16 now_page_accessories = 0x0000;//从高到低 --1级--2级--3级--4级
u8 now_page_accessories_deep = 0x00;//当前处于哪一层




extern setup_item_info_t Battery_settings[];
extern setup_item_info_t accessory_settings[];
extern setup_item_info_t system_settings[];
//u8 last_now_page_num = 0;//定位上一层进来的位置，目前只有两层，使用1个变量即可

//accessory
setup_item_info_t Battery_settings[]=
{
   {"Battery Capacity",TOUCH_TYPE_KEYBOARD,accessory_settings,empty_son_p,func_Battery_Capacity},
	 {"Percentage of Battery Capacity",TOUCH_TYPE_KEYBOARD,accessory_settings,empty_son_p,func_Percentage_of_Battery_Capacity},	
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t External_Key_Type[]=
{
   {"",TOUCH_TYPE_SPECIAL,accessory_settings,empty_son_p,empty_fun},
	 {"",TOUCH_TYPE_SPECIAL,accessory_settings,empty_son_p,empty_fun},
	 {"",TOUCH_TYPE_SPECIAL,accessory_settings,empty_son_p,func_External_Key_Type},
	 //{"",TOUCH_TYPE_SPECIAL,accessory_settings,empty_son_p,func_External_Key_Type},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t accessory_settings[]=
{
   {"Battery Settings",TOUCH_TYPE_ENTER,empty_father_p,Battery_settings,empty_fun},
	 {"Temperature Sensor Type",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_Temperature_Sensor_Type},
	 {"External Key Type",TOUCH_TYPE_ENTER,empty_father_p,External_Key_Type,empty_fun},//
	 {"Park Brake Detection",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_Ignore_Handbreak},//
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
	 //{"Tanks Sensor Type",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_Tanks_Sensor_Type},
setup_page_t accessories_page;



void func_Ignore_Handbreak(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
//	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{
			if(f_ignore_handbreak)
			  sprintf(display_buf,"OFF");
			else
				 sprintf(display_buf,"ON");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_accessories_item[sn].x_val+X_set_mid_offset,system_accessories_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);

    }
		else if(deal_type==TO_UP)
		{
			 f_ignore_handbreak=!f_ignore_handbreak;

				 send_FlC200_set_cmd(0x83,f_ignore_handbreak);
		  f_display_set_accessories_info = TRUE;
			if(f_ignore_handbreak)
			{
			    f_ui_need_disply_dialog_msg= TRUE;
			    v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_MOTOR_WARNING;
			}
		}
		else if(deal_type==TO_DOWN)
		{
			 f_ignore_handbreak=!f_ignore_handbreak;

				 send_FlC200_set_cmd(0x83,f_ignore_handbreak);
		  f_display_set_accessories_info = TRUE;
			if(f_ignore_handbreak)
			{
			    f_ui_need_disply_dialog_msg= TRUE;
			    v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_MOTOR_WARNING;
			}
		}
		else if(deal_type==TO_DEAL)
		{

		}

}



void func_Temperature_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
//	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{
			if((parts_set_return_status.temp_sensor_type==1)||(parts_set_return_status.temp_sensor_type==2))
			  sprintf(display_buf,"Type%d",parts_set_return_status.temp_sensor_type);
			else
				 sprintf(display_buf,"Unkown");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_accessories_item[sn].x_val+X_set_mid_offset,system_accessories_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);

    }
		else if(deal_type==TO_UP)
		{
			  if(parts_set_return_status.temp_sensor_type == 1)
				{
			    parts_set_return_status.temp_sensor_type = 2;
				 parts_set_status.temp_sensor_type = 2;
				}
				else
				{
			
			   parts_set_return_status.temp_sensor_type = 1;
				 parts_set_status.temp_sensor_type =1;
				}

				 send_FlC200_set_cmd(0x48,parts_set_status.temp_sensor_type);
		  f_display_set_accessories_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
			 if(parts_set_return_status.temp_sensor_type == 1)
				{
			    parts_set_return_status.temp_sensor_type = 2;
				 parts_set_status.temp_sensor_type = 2;
				}
				else
				{
			
			   parts_set_return_status.temp_sensor_type = 1;
				 parts_set_status.temp_sensor_type =1;
				}
				send_FlC200_set_cmd(0x48,parts_set_status.temp_sensor_type);
		  f_display_set_accessories_info = TRUE;
		}
		else if(deal_type==TO_DEAL)
		{

		}
}
/*
void func_Tanks_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
//	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{			
			if(Control_Unit_product_id!=NEW_CONTROL_UNIT_PRODUCT_ID)
				sprintf(display_buf,"KIB(K101)");
			else if(parts_set_return_status.tanks_sensor_type==1)
				sprintf(display_buf,"KIB(K101)");
			else if(parts_set_return_status.tanks_sensor_type==2)
        sprintf(display_buf,"US");//(240-30)
			else if(parts_set_return_status.tanks_sensor_type==3)
        sprintf(display_buf,"European");  	//(0-180)		
			else
				 sprintf(display_buf,"Unkown");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_accessories_item[sn].x_val+X_set_mid_offset,system_accessories_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);

    }
		else if(deal_type==TO_UP)
		{
			  if(parts_set_return_status.tanks_sensor_type <3)
				{
			    parts_set_return_status.tanks_sensor_type ++;				 
				}
				else 
				{			
			   parts_set_return_status.tanks_sensor_type = 1;
				}
         parts_set_status.tanks_sensor_type = parts_set_return_status.tanks_sensor_type;
				 send_FlC200_set_cmd(0x47,parts_set_status.tanks_sensor_type);
		  f_display_set_accessories_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
			 if(parts_set_return_status.tanks_sensor_type > 1)
				{
			    parts_set_return_status.tanks_sensor_type--;
				}
				else
				{			
			   parts_set_return_status.tanks_sensor_type = 3;
				}
				parts_set_status.tanks_sensor_type = parts_set_return_status.tanks_sensor_type;
				send_FlC200_set_cmd(0x47,parts_set_status.tanks_sensor_type);
		  f_display_set_accessories_info = TRUE;
		}
		else if(deal_type==TO_DEAL)
		{

		}
}*/
void func_External_Key_Type(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	u8 i;
	  if(deal_type==TO_INIT)
		{
	      f_system_accessories_External_Key_Type = TRUE;
			
        system_accessories_item[1].key_type = KEY_TYPE_TOUCH_NONE;//1		KEY_TYPE_TOUCH_NONE	  
			  system_accessories_item[2].key_type = KEY_TYPE_TOUCH_NONE;//2
			  system_accessories_item[3].key_type = KEY_TYPE_TOUCH_NONE;//3
			  system_accessories_item[4].key_type = KEY_TYPE_TOUCH_NONE;//4
			  system_accessories_item[5].key_type = KEY_TYPE_TOUCH_NONE;//nextpage
			  system_accessories_item[6].key_type = KEY_TYPE_TOUCH_NONE;//prepage
				Virtual_LCD_Draw_Rectangle_ARGB32(142,90,700,24,Virtual_LCDbuff2,ARGB_clear);
	      Virtual_LCD_Draw_String_ARGB_24_4bit(142,90,"Accessories Settings -> External Key Type",(0xFF78baf7),0,1,1);
			
				Virtual_LCD_Draw_Rectangle_ARGB32(system_accessories_item[1].x_val+X_system_system_offset,system_accessories_item[1].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
				//Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[1].x_val+X_system_system_offset,system_accessories_item[1].y_val+Y_system_system_offset,"<-Back",(0xFFe2e2e4),0,1,1);

			for(i=0;i<4;i++)
				{
					sprintf(display_buf,"CH%d:",i+1);
					Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[1].x_val+X_system_system_offset+160*i,system_accessories_item[1].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					if(((External_key_type_return<<(i*2))&0xC0000000)==0x40000000)
					  Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[1].x_val+X_system_system_offset+62+160*i,system_accessories_item[1].y_val+Y_system_system_offset," Lock ",(ARGB_mydarkcyan),0,1,1);
					else
					  Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[1].x_val+X_system_system_offset+62+160*i,system_accessories_item[1].y_val+Y_system_system_offset,"Touch",(ARGB_mydarkcyan),0,1,1);
				
				}
			
				Virtual_LCD_Draw_Rectangle_ARGB32(system_accessories_item[2].x_val+X_system_system_offset,system_accessories_item[2].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[2].x_val+X_system_system_offset,system_accessories_item[2].y_val+Y_system_system_offset,"CH1:",(0xFFe2e2e4),0,1,1);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[2].x_val+X_system_system_offset+160,system_accessories_item[2].y_val+Y_system_system_offset,"CH2:",(0xFFe2e2e4),0,1,1);
			 // Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[2].x_val+X_system_system_offset+320,system_accessories_item[2].y_val+Y_system_system_offset,"CH3:",(0xFFe2e2e4),0,1,1);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[2].x_val+X_system_system_offset+480,system_accessories_item[2].y_val+Y_system_system_offset,"CH4:",(0xFFe2e2e4),0,1,1);
			  
        for(i=0;i<4;i++)
				{
					sprintf(display_buf,"CH%d:",i+5);
					Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[2].x_val+X_system_system_offset+160*i,system_accessories_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					if(((External_key_type_return<<((i*2+8)))&0xC0000000)==0x40000000)
					  Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[2].x_val+X_system_system_offset+62+160*i,system_accessories_item[2].y_val+Y_system_system_offset," Lock ",(ARGB_mydarkcyan),0,1,1);
					else
					  Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[2].x_val+X_system_system_offset+62+160*i,system_accessories_item[2].y_val+Y_system_system_offset,"Touch",(ARGB_mydarkcyan),0,1,1);
				
				}
				Virtual_LCD_Draw_Rectangle_ARGB32(system_accessories_item[3].x_val+X_system_system_offset,system_accessories_item[3].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[3].x_val+X_system_system_offset,system_accessories_item[3].y_val+Y_system_system_offset,"CH5:",(0xFFe2e2e4),0,1,1);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[3].x_val+X_system_system_offset+160,system_accessories_item[3].y_val+Y_system_system_offset,"CH6:",(0xFFe2e2e4),0,1,1);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[3].x_val+X_system_system_offset+320,system_accessories_item[3].y_val+Y_system_system_offset,"CH7:",(0xFFe2e2e4),0,1,1);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[3].x_val+X_system_system_offset+480,system_accessories_item[3].y_val+Y_system_system_offset,"CH8:",(0xFFe2e2e4),0,1,1);
        for(i=0;i<4;i++)
				{
					sprintf(display_buf,"CH%d:",i+9);
					Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[3].x_val+X_system_system_offset+160*i,system_accessories_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					if(((External_key_type_return<<((i*2+16)))&0xC0000000)==0x40000000)
					  Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[3].x_val+X_system_system_offset+62+160*i,system_accessories_item[3].y_val+Y_system_system_offset," Lock ",(ARGB_mydarkcyan),0,1,1);
					else
					  Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[3].x_val+X_system_system_offset+62+160*i,system_accessories_item[3].y_val+Y_system_system_offset,"Touch",(ARGB_mydarkcyan),0,1,1);
				
				} 
		    Virtual_LCD_Draw_Rectangle_ARGB32(system_accessories_item[4].x_val+X_system_system_offset,system_accessories_item[4].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
		  	//sprintf(display_buf,"BLE Connest Code: %04X",code_connect);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[4].x_val+X_system_system_offset,system_accessories_item[4].y_val+Y_system_system_offset,"CH9:",(0xFFe2e2e4),0,1,1);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[4].x_val+X_system_system_offset+160,system_accessories_item[4].y_val+Y_system_system_offset,"CH10:",(0xFFe2e2e4),0,1,1);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[4].x_val+X_system_system_offset+320,system_accessories_item[4].y_val+Y_system_system_offset,"CH11:",(0xFFe2e2e4),0,1,1);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_accessories_item[4].x_val+X_system_system_offset+480,system_accessories_item[4].y_val+Y_system_system_offset,"CH12:",(0xFFe2e2e4),0,1,1);
         
		}
		else if(deal_type==TO_UP)
		{
		
		}
		else if(deal_type==TO_DOWN)
		{
		
		}
}





void func_Battery_Capacity(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
//	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{
			sprintf(display_buf,"%dAH",parts_set_return_status.Capacity/10);
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_accessories_item[sn].x_val+X_set_mid_offset,system_accessories_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
      // sysprintf("\r\n======================%d",parts_set_return_status.Capacity);
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
				 f_ui_new_input_bat_capacity = TRUE;
			   f_ui_new_input_bat_percenage = FALSE;
				 f_need_ui_disply_keyboard = TRUE;
			
		}
}
void func_Percentage_of_Battery_Capacity(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
//	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{
			sprintf(display_buf,"%d%%",parts_set_return_status.Percentage);
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_accessories_item[sn].x_val+X_set_mid_offset,system_accessories_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);

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
				 f_need_ui_disply_keyboard = TRUE;
				 f_ui_new_input_bat_percenage = TRUE;
		    	f_ui_new_input_bat_capacity = FALSE;
		}
}




void check_parts_set_status(bool upgrage)
{
	static PARTS_SET_STATUS old_parts_set_status;
	static u32 old_External_key_type_return;
  if((memcmp(&old_parts_set_status,&parts_set_return_status,sizeof(PARTS_SET_STATUS)))||(old_External_key_type_return!=External_key_type_return))
  {
    memcpy(&old_parts_set_status,&parts_set_return_status,sizeof(PARTS_SET_STATUS));
		old_External_key_type_return =External_key_type_return;
		f_display_set_accessories_info = TRUE;
		if(upgrage)
			f_display_set_accessories_info_upgrage = TRUE;
	}
}

void display_set_accessories_info(bool upgrage)
{
//	char display_buf[32];
//	u8 i;
	//lcd_dis_item_t *p;
	
	setup_page_t *setup_page_p;
	lcd_dis_item_t *setup_item_p;
	static u8 last_now_item = TOP_SIDE_PAGE_SYSTEM_MUN;
	setup_page_p = &accessories_page;
	setup_item_p = system_accessories_item;

	 check_parts_set_status(FALSE);
	 f_display_set_accessories_info = FALSE;
	
	
	if(last_now_item!=page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item)
	{
	   last_now_item=page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item;
		 setup_page_p->now_p = accessory_settings;
     setup_page_p->now_page_deep = MENU_DEEP_1TH;
		 last_now_page_num = 0;
     setup_page_p->now_page_num = 0;		
	}
  sysprintf("\r\n setup_page_p->now_page_num:%d MAX:%d",setup_page_p->now_page_num,setup_page_p->max_page_num);	 
	 
	 display_setup_page(f_display_set_accessories_info_upgrage,upgrage,setup_page_p,setup_item_p,"Accessories Settings");
	 f_display_set_accessories_info_upgrage = FALSE;
	 


}










BOOL page_system_accessories_deel_with_i(lcd_dis_page_t *p2,u8* i)
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

extern lcd_dis_item_t *p_system_item_d[SYSTEM_SYSTEM_ICO_NUM];//借用system_item界面
extern lcd_dis_item_t *p_system_item_u[SYSTEM_SYSTEM_ICO_NUM];
void ui_system_accessories_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_SYSTEM][TOP_SIDE_PAGE_SYSTEM_ACC];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=SYSTEM_ACC_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


/*
   t_system_accessories_headline.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_accessories_btn1_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_accessories_btn2_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_accessories_btn3_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_accessories_btn4_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_accessories_nextpage_d.key_type = KEY_TYPE_ONCE;
   t_system_accessories_prepage_d.key_type= KEY_TYPE_ONCE;
	 t_system_b_back_d.key_type = KEY_TYPE_TOUCH_NONE;
	 t_set_accessories_left_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_accessories_left2_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_accessories_left3_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_accessories_left4_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_accessories_right_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_accessories_right2_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_accessories_right3_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_accessories_right4_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
*/
/*
   if(Control_Unit_product_id!=NEW_CONTROL_UNIT_PRODUCT_ID)
		 accessory_settings[2].setup_menu_touch_type = TOUCH_TYPE_NONE;
	 else
		 accessory_settings[2].setup_menu_touch_type = TOUCH_TYPE_LEFT_RIGHT;
*/
   /*p->item = system_accessories_item;
   for(i=0;i<SYSTEM_ACC_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_system_accessories_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_system_accessories_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_system_accessories_item_u[i]->size_of_pic_item ;
	 
	 }*/
	 
	 
	 //设置界面ui_system_init()这个要先初始化，其他设置界面以system_item这个为基准
   p->item = system_accessories_item;
   for(i=0;i<SYSTEM_SYSTEM_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_system_item_d[i],sizeof(lcd_dis_item_t));
	   p->item[i].pic_item =p_system_item_u[i]->pic_item;//
   	 p->item[i].size_of_pic_item = p_system_item_u[i]->size_of_pic_item ;
		 p->item[i].f = p_system_accessories_item_d[i];
	 
	 }
	 //int setting_list
	 display_set_accessories_info(FALSE);
 }


