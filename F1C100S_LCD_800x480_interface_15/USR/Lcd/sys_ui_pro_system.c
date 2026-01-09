#include "includes.h"



extern void func_set_left2_d(void* p,u8 sn);
extern void func_set_left2_u(void* p,u8 sn);
extern void func_set_right2_d(void* p,u8 sn);
extern void func_set_right2_u(void* p,u8 sn);
/*extern void func_set_left3_d(void* p,u8 sn);
extern void func_set_left3_u(void* p,u8 sn);
extern void func_set_right3_d(void* p,u8 sn);
extern void func_set_right3_u(void* p,u8 sn);*/
/*extern void func_set_left4_d(void* p,u8 sn);
extern void func_set_left4_u(void* p,u8 sn);
extern void func_set_right4_d(void* p,u8 sn);
extern void func_set_right4_u(void* p,u8 sn);*/
extern const unsigned char set_left_d[];
extern const unsigned char set_left_u[];
extern const unsigned char set_right_d[];
extern const unsigned char set_right_u[];

lcd_dis_item_t t_set_left2_d={(unsigned char*)set_left_d,(unsigned char*)set_left_d,(unsigned char*)set_left_d,0,0,1929,1929,1929,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left2_d,Y_set_left2_d,X_set_left2_d+48,Y_set_left2_d+52,0,&func_set_left2_d};
lcd_dis_item_t t_set_left2_u={(unsigned char*)set_left_u,(unsigned char*)set_left_u,(unsigned char*)set_left_u,0,0,1609,1609,1609,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left2_u,Y_set_left2_u,X_set_left2_u+48,Y_set_left2_u+52,0,&func_set_left2_u};
lcd_dis_item_t t_set_right2_d={(unsigned char*)set_right_d,(unsigned char*)set_right_d,(unsigned char*)set_right_d,0,0,1802,1802,1802,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right2_d,Y_set_right2_d,X_set_right2_d+48,Y_set_right2_d+52,0,&func_set_right2_d};
lcd_dis_item_t t_set_right2_u={(unsigned char*)set_right_u,(unsigned char*)set_right_u,(unsigned char*)set_right_u,0,0,1595,1595,1595,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right2_u,Y_set_right2_u,X_set_right2_u+48,Y_set_right2_u+52,0,&func_set_right2_u};
/*
lcd_dis_item_t t_set_left3_d={(unsigned char*)set_left_d,(unsigned char*)set_left_d,(unsigned char*)set_left_d,0,0,1929,1929,1929,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left3_d,Y_set_left3_d,X_set_left3_d+48,Y_set_left3_d+52,0,&func_set_left3_d};
lcd_dis_item_t t_set_left3_u={(unsigned char*)set_left_u,(unsigned char*)set_left_u,(unsigned char*)set_left_u,0,0,1609,1609,1609,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left3_u,Y_set_left3_u,X_set_left3_u+48,Y_set_left3_u+52,0,&func_set_left3_u};
lcd_dis_item_t t_set_right3_d={(unsigned char*)set_right_d,(unsigned char*)set_right_d,(unsigned char*)set_right_d,0,0,1802,1802,1802,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right3_d,Y_set_right3_d,X_set_right3_d+48,Y_set_right3_d+52,0,&func_set_right3_d};
lcd_dis_item_t t_set_right3_u={(unsigned char*)set_right_u,(unsigned char*)set_right_u,(unsigned char*)set_right_u,0,0,1595,1595,1595,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right3_u,Y_set_right3_u,X_set_right3_u+48,Y_set_right3_u+52,0,&func_set_right3_u};
*/
/*lcd_dis_item_t t_set_left4_d={(unsigned char*)set_left_d,(unsigned char*)set_left_d,(unsigned char*)set_left_d,0,0,1929,1929,1929,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left4_d,Y_set_left4_d,X_set_left4_d+48,Y_set_left4_d+52,0,&func_set_left4_d};
lcd_dis_item_t t_set_left4_u={(unsigned char*)set_left_u,(unsigned char*)set_left_u,(unsigned char*)set_left_u,0,0,1609,1609,1609,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_left4_u,Y_set_left4_u,X_set_left4_u+48,Y_set_left4_u+52,0,&func_set_left4_u};
lcd_dis_item_t t_set_right4_d={(unsigned char*)set_right_d,(unsigned char*)set_right_d,(unsigned char*)set_right_d,0,0,1802,1802,1802,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right4_d,Y_set_right4_d,X_set_right4_d+48,Y_set_right4_d+52,0,&func_set_right4_d};
lcd_dis_item_t t_set_right4_u={(unsigned char*)set_right_u,(unsigned char*)set_right_u,(unsigned char*)set_right_u,0,0,1595,1595,1595,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_set_right4_u,Y_set_right4_u,X_set_right4_u+48,Y_set_right4_u+52,0,&func_set_right4_u};
*/

// 面按键列表 按下
lcd_dis_item_t *p_system_item_d[SYSTEM_SYSTEM_ICO_NUM]=
{
 
	&t_system_headline,
  &t_system_btn1_d,
  &t_system_btn2_d,
  &t_system_btn3_d,
  &t_system_btn4_d,
  &t_system_nextpage_d,//5
  &t_system_prepage_d,
	&t_set_left1_d,
	&t_set_left2_d,
	&t_set_left3_d,
	&t_set_left4_d,//10
	&t_set_right_d,
	&t_set_right2_d,
	&t_set_right3_d,
	&t_set_right4_d,
	&t_system_b_back_d,
};

//界面按键列表 弹起
lcd_dis_item_t *p_system_item_u[SYSTEM_SYSTEM_ICO_NUM]=
{
	&t_system_headline,
  &t_system_btn1_u,
  &t_system_btn2_u,
  &t_system_btn3_u,
  &t_system_btn4_u,
  &t_system_nextpage_u,//5
  &t_system_prepage_u,
	
	&t_set_left1_u,
	&t_set_left2_u,
	&t_set_left3_u,
	&t_set_left4_u,
  &t_set_right_u,
	&t_set_right2_u,
	&t_set_right3_u,
	&t_set_right4_u,
	&t_system_b_back_u,



};

lcd_dis_item_t system_item[SYSTEM_SYSTEM_ICO_NUM];

///////////////////////////////////////////////////



bool f_system_Date_Time_set = FALSE;
bool f_system_accessories_External_Key_Type = FALSE;
#define offset_x 20
u16 External_key_type_x_mid[4] = {130,130+160,130+320,130+480};
extern lcd_dis_item_t system_accessories_item[SYSTEM_ACC_ICO_NUM];
extern setup_item_info_t Battery_settings[];
extern setup_item_info_t accessory_settings[];
u8 last_now_page_num = 0;//定位上一层进来的位置，目前只有两层，使用1个变量即可
bool f_display_set_info = FALSE;
//system 

setup_item_info_t Date_Time[]=
{
   {"Save And Back",TOUCH_TYPE_NORMAL,system_settings,empty_son_p,func_Date_Time_Save_And_Back},
	 {"",TOUCH_TYPE_SPECIAL,system_settings,empty_son_p,empty_fun},
	 {"",TOUCH_TYPE_SPECIAL,system_settings,empty_son_p,func_system_Date_Time},
	 //{"",TOUCH_TYPE_SPECIAL,system_settings,empty_son_p,func_system_Date_Time},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t Upgrade[]=
{
   {"Start",TOUCH_TYPE_NORMAL,system_settings,empty_son_p,func_system_Upgrade},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};


setup_item_info_t Restore_Default_Settings[]=
{
   {"YES",TOUCH_TYPE_NORMAL,system_settings,empty_son_p,func_system_Restore_Default_Settings},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t System_Reset[]=
{
   {"YES",TOUCH_TYPE_NORMAL,system_settings,empty_son_p,func_system_System_Reset},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t system_settings[]=
{
   {"Date&Time",TOUCH_TYPE_ENTER,empty_father_p,Date_Time,empty_fun},
	 {"Language",TOUCH_TYPE_NONE,empty_father_p,empty_son_p,func_system_Language},
	 {"Temperature uint",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,&func_system_Temperature_uint},//
	 {"Volume Uint",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_system_Volume_uint},
	 {"Brightness",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_system_Brightness},
	 {"Sleep Time",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_system_Sleep_Time},
	 {"Touch Tone",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_system_Touch_Tone},
	 {"Alarm Tone",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_system_Warning_Tone},
	 {"Light Up Screen When Alarm Occurs",TOUCH_TYPE_LEFT_RIGHT,empty_father_p,empty_son_p,func_system_Light_Up_The_Screen},
	 //{"Upgrade",TOUCH_TYPE_ENTER,empty_father_p,Upgrade,empty_fun},
	 {"Restore Default Settings",TOUCH_TYPE_ENTER,empty_father_p,Restore_Default_Settings,empty_fun},
	 {"System Reset",TOUCH_TYPE_ENTER,empty_father_p,System_Reset,empty_fun},
	 {"Code Enter",TOUCH_TYPE_KEYBOARD,empty_father_p,empty_son_p,func_Code_Enter},
	 {"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};





setup_page_t setup_page;



///////////////////////////////////////////////////////////////////////////
u16 now_page = 0x0000;//从高到低每4位 --1级(第几页page)--1级(进入1级的第几项)--2级(第几页page)--2级(进入2级的第几项)
u8 now_page_deep = 0x00;//当前处于哪一层


u8 Is_Leap_Year(u16 year)
{			  
	if(year%4==0) //?D???4??3y
	{ 
		if(year%100==0) 
		{ 
			if(year%400==0)return 1;//?1??00??2,?1騛??400??3y 	   
			else return 0;   
		}else return 1;   
	}else return 0;	
}



void dispay_hour(void)
{
	char display_buf[32];
  Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+80,system_item[3].y_val+Y_system_system_offset,64,24,Virtual_LCDbuff2,ARGB_clear);

				if(time_status.format&0x80)
				{
					if(time_status.hour==0)
						sprintf(display_buf,"12am");
					else if(time_status.hour<12)				
			    sprintf(display_buf,"%02dam",time_status.hour);
					else if(time_status.hour==12)		
						sprintf(display_buf,"12pm");
					else
						sprintf(display_buf,"%02dpm",time_status.hour-12);
				}
				else
					sprintf(display_buf,"  %02d",time_status.hour);
				
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+80,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					
}				







void time_touch_pro(u16 x_val,u16 y_val)
{
	 char display_buf[32];
	 u8 i;
	 static u32 IdelTime_1S = 0;
	 static u8 up_flag= 0;
	 lcd_dis_item_t *p,*p1;
	 if(IdelTime_1S==0)
		ResetDelayTime(&IdelTime_1S); 
	 if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
	 {
		 
	if(((x_val==0x0000)||(x_val==0xFFFF))&&((y_val==0x0000)||(y_val==0xFFFF)))
	{
	  up_flag = 1;
	}
	else if((up_flag == 1)||(CntDelayTime(&IdelTime_1S,TIME_ONE_MS*300)))
	{
		  
      up_flag = 0;
			if(f_sleep_now)
				return;
		  ResetDelayTime(&IdelTime_1S); 
		  //sysprintf("\r\n************88 cnt:%d,%d",now_page_deep,now_page);
		 if((now_in_dialog_or_keyboard_window()==FALSE)&&(f_system_accessories_External_Key_Type)&&(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_ACC))//((now_page_deep==1)&&(now_page==0x3000))//External_key_type
		 {
			  External_key_type=External_key_type_return;
			  p = &system_accessories_item[1];
			  if((y_val>=p->y_val)&&(y_val<=p->y_end_val))//Y
				{
					 for(i=0;i<4;i++)
				  {
						 if((x_val>=(p->x_val+External_key_type_x_mid[i]-offset_x))&&(x_val<=(p->x_val+External_key_type_x_mid[i]+offset_x)))
					  {
							  send_FlC200_base_set_cmd(0x89,0x02,0);
							  if(((External_key_type<<(i*2))&0xC0000000)==0)
									External_key_type|=(0x40000000>>(i*2));
								else
									External_key_type&=(~(0xC0000000>>(i*2)));
								
								External_key_type_return = External_key_type;
								Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val+External_key_type_x_mid[i]-44,p->y_val+Y_system_system_offset,96,24,Virtual_LCDbuff2,ARGB_clear);
								if(((External_key_type_return<<(i*2))&0xC0000000)==0x40000000)
									Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+X_system_system_offset+62+160*i,p->y_val+Y_system_system_offset," Lock ",(ARGB_mydarkcyan),0,1,1);
								else
									Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+X_system_system_offset+62+160*i,p->y_val+Y_system_system_offset,"Touch",(ARGB_mydarkcyan),0,1,1);
								Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
								send_FlC200_set_cmd(0x81,(u16)(External_key_type>>16));
								send_FlC200_set_cmd(0x82,(u16)(External_key_type));
								break;
					  }
					}
		   }
				p = &system_accessories_item[2];
			  if((y_val>=p->y_val)&&(y_val<=p->y_end_val))//Y
				{
					 for(i=0;i<4;i++)
				  {
						 if((x_val>=(p->x_val+External_key_type_x_mid[i]-offset_x))&&(x_val<=(p->x_val+External_key_type_x_mid[i]+offset_x)))
					  {
							  send_FlC200_base_set_cmd(0x89,0x02,0);
							  if(((External_key_type<<(i*2+8))&0xC0000000)==0)
									External_key_type|=(0x40000000>>(i*2+8));
								else
									External_key_type&=(~(0xC0000000>>(i*2+8)));
								
								External_key_type_return = External_key_type;
								Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val+External_key_type_x_mid[i]-44,p->y_val+Y_system_system_offset,96,24,Virtual_LCDbuff2,ARGB_clear);
								if(((External_key_type_return<<(i*2+8))&0xC0000000)==0x40000000)
									Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+X_system_system_offset+62+160*i,p->y_val+Y_system_system_offset," Lock ",(ARGB_mydarkcyan),0,1,1);
								else
									Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+X_system_system_offset+62+160*i,p->y_val+Y_system_system_offset,"Touch",(ARGB_mydarkcyan),0,1,1);
								Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
								send_FlC200_set_cmd(0x81,(u16)(External_key_type>>16));
								send_FlC200_set_cmd(0x82,(u16)(External_key_type));
								break;
					  }
					}
		   }
				p = &system_accessories_item[3];
			  if((y_val>=p->y_val)&&(y_val<=p->y_end_val))//Y
				{
					 for(i=0;i<4;i++)
				  {
						 if((x_val>=(p->x_val+External_key_type_x_mid[i]-offset_x))&&(x_val<=(p->x_val+External_key_type_x_mid[i]+offset_x)))
					  {
							  send_FlC200_base_set_cmd(0x89,0x02,0);
							  if(((External_key_type<<(i*2+16))&0xC0000000)==0)
									External_key_type|=(0x40000000>>(i*2+16));
								else
									External_key_type&=(~(0xC0000000>>(i*2+16)));
								
								External_key_type_return = External_key_type;
								Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val+External_key_type_x_mid[i]-44,p->y_val+Y_system_system_offset,96,24,Virtual_LCDbuff2,ARGB_clear);
								if(((External_key_type_return<<(i*2+16))&0xC0000000)==0x40000000)
									Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+X_system_system_offset+62+160*i,p->y_val+Y_system_system_offset," Lock ",(ARGB_mydarkcyan),0,1,1);
								else
									Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+X_system_system_offset+62+160*i,p->y_val+Y_system_system_offset,"Touch",(ARGB_mydarkcyan),0,1,1);
								Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
								send_FlC200_set_cmd(0x81,(u16)(External_key_type>>16));
								send_FlC200_set_cmd(0x82,(u16)(External_key_type));
								break;
					  }
					}
		   }
			 
		 }
		 /*else if((now_page_deep==0)&&(now_page==0x1000))//sleep time
		 {
		    p = &system_item[2];
			  if((y_val>=p->y_val)&&(y_val<=p->y_end_val))//Y
				{
				   if((x_val>=(653-offset_x))&&(x_val<=(653+offset_x)))
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
						 if(base_return_status.sleep_time)
					    base_return_status.sleep_time--;
								
				    Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset,system_item[2].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
						Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset,system_item[2].y_val+Y_system_system_offset,"Sleep Time",(0xFFe2e2e4),0,1,1);
						
						 
						Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+500-30,system_item[2].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);
		
			      Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+500+73,system_item[2].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
						if(base_return_status.sleep_time==0)
						Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+500+15,system_item[2].y_val+Y_system_system_offset,"Off",(ARGB_mydarkcyan),0,1,1);
						else if(base_return_status.sleep_time<=60)
						{
							sprintf(display_buf,"%02d Min",base_return_status.sleep_time);
						  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+500,system_item[2].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
				     }
						send_FlC200_base_set_cmd(0x10,base_return_status.sleep_time,0);
						
						Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
					 }
					 else if((x_val>=(766-offset_x))&&(x_val<=(766+offset_x)))
					 {
						  send_FlC200_base_set_cmd(0x89,0x02,0);
					    base_return_status.sleep_time++;
						  if(base_return_status.sleep_time>60)
								base_return_status.sleep_time = 60;
								
					    Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset,system_item[2].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
						Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset,system_item[2].y_val+Y_system_system_offset,"Sleep Time",(0xFFe2e2e4),0,1,1);
						
							
            Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+500-30,system_item[2].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);
		
			      Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+500+73,system_item[2].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
						if(base_return_status.sleep_time==0)
						Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+500+15,system_item[2].y_val+Y_system_system_offset,"Off",(ARGB_mydarkcyan),0,1,1);
						else if(base_return_status.sleep_time<=60)
						{
							sprintf(display_buf,"%02d Min",base_return_status.sleep_time);
						  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+500,system_item[2].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
				     }
						send_FlC200_base_set_cmd(0x10,base_return_status.sleep_time,0);
						
            Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);						
					 }
				 }
		 
		 }*/
	   else  if((now_in_dialog_or_keyboard_window()==FALSE)&&(f_ui_disply_dialog_msg==FALSE)&&(f_system_Date_Time_set)&&(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_SYSTEM))//((now_page_deep==1)&&(now_page==0x0000))//time
	   {
			  p = &system_item[2];
			  p1 = &system_item[3];
			  if((y_val>=p->y_val)&&(y_val<=p->y_end_val))//Y  mon day year
				{
				   if((x_val>=(235-offset_x))&&(x_val<=(235+offset_x)))//mon
					 {
						  send_FlC200_base_set_cmd(0x89,0x02,0);//sysprintf("\r\n************89");
					    time_status.mon--;
						 if(time_status.mon==0) 
							 time_status.mon = 12;
					
				     Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset+90,system_item[2].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);

			     sprintf(display_buf,"%02d",time_status.mon);
			      Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+90,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					 }
					 else if((x_val>=(318-offset_x))&&(x_val<=(318+offset_x)))//mon
					 {
						  send_FlC200_base_set_cmd(0x89,0x02,0);
					    if(time_status.mon++) 
								if(time_status.mon>12)
									time_status.mon = 1;
												 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset+90,system_item[2].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);

			  sprintf(display_buf,"%02d",time_status.mon);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+90,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					 }
					 else if((x_val>=(454-10-offset_x))&&(x_val<=(454-10+offset_x)))//day
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
						  time_status.day--;
						  if(time_status.day==0) 
							{
								switch(time_status.mon)
								{
									case 1:
										case 3:
											case 5:
												case 7:
													case 8:
														case 10:
															case 12:
										time_status.day = 31;
															break;
										case 2:
                      if(Is_Leap_Year(2000+time_status.year))
												time_status.day = 29;
											else
											time_status.day = 28;
											break;
										default:
											time_status.day = 30;
										break;
																
										
								}
									
							  
							}
							 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset+200+90-10,system_item[2].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);
							sprintf(display_buf,"%02d",time_status.day);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+200+90-10,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  
					 
					 }
					 else if((x_val>=(529-10-offset_x))&&(x_val<=(529-10+offset_x)))//day
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
					    time_status.day++;
						  switch(time_status.mon)
								{
									case 1:
										case 3:
											case 5:
												case 7:
													case 8:
														case 10:
															 case 12:
										if(time_status.day > 31)
											time_status.day = 1;
											
															break;
										case 2:
                      if(Is_Leap_Year(2000+time_status.year))
											{
												if(time_status.day > 29)
											    time_status.day = 1;
											}
											else
											{
											  if(time_status.day > 28)
											    time_status.day = 1;
											}
											break;
										default:
											if(time_status.day > 30)
											time_status.day = 1;
										break;
																
										
								}
									
							 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset+200+90-10,system_item[2].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);
							sprintf(display_buf,"%02d",time_status.day);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+200+90-10,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			   
							
					 }
					 else if((x_val>=(663-20-offset_x))&&(x_val<=(663-20+offset_x)))//year
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
					   
						 if(time_status.year) 
							  time_status.year--;
						
						 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset+400+90+8-20,system_item[2].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);
						  sprintf(display_buf,"%02d",time_status.year);
			      Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+400+90+8-20,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			 
					 }
					 else if((x_val>=(738-20-offset_x))&&(x_val<=(738-20+offset_x)))//year
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
					    if(time_status.year++) 
								if(time_status.year>99)
									time_status.year = 1;
														 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset+400+90+8-20,system_item[2].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);
						  sprintf(display_buf,"%02d",time_status.year);
			      Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+400+90+8-20,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			 
					 }
				 Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
				}
				
				/////////////////////////////////////////////
				else if((y_val>=p1->y_val)&&(y_val<=p1->y_end_val))//Y    hour min sec
				{
				   if((x_val>=(235-offset_x+8))&&(x_val<=(235+offset_x+8)))//hour
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
					    
						 if(time_status.hour==0) 
							 time_status.hour = 23;
						 else
							 time_status.hour--;
					
				     /*Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+90+8,system_item[3].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);

			     sprintf(display_buf,"%02d",time_status.hour);
			      Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+90+8,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					*/
						 dispay_hour();

						 }
					 else if((x_val>=(318-offset_x+8))&&(x_val<=(318+offset_x+8)))//hour
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
					    if(time_status.hour++) 
								if(time_status.hour>23)
									time_status.hour = 0;
								
								/*
												 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+90+8,system_item[3].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);

			  sprintf(display_buf,"%02d",time_status.hour);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+90+8,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					 */
								dispay_hour();
					 
					 }
					 else if((x_val>=(454-20-offset_x+8))&&(x_val<=(454-20+offset_x+8)))//min
					 {
						  send_FlC200_base_set_cmd(0x89,0x02,0);
						  if(time_status.min==0) 
							{								
							  time_status.min=59;
							}
							else
							time_status.min--;
							
							 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+200+90+8-10,system_item[3].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);
							sprintf(display_buf,"%02d",time_status.min);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+200+90+8-10,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  
							
					 
					 }
					 else if((x_val>=(529-20-offset_x+8))&&(x_val<=(529-20+offset_x+8)))//min
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
					    time_status.min++;
					if(time_status.min > 59)
											time_status.min = 0;
									
							 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+200+90+8-10,system_item[3].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);
							sprintf(display_buf,"%02d",time_status.min);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+200+90+8-10,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			   
							
					 }
					 else if((x_val>=(663-30-offset_x+8))&&(x_val<=(663-30+offset_x+8)))//sec
					 {
					   send_FlC200_base_set_cmd(0x89,0x02,0);
						 if(time_status.sec==0) 
							{								
							  time_status.sec=59;
							}
							else
							time_status.sec--;
						
						 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+400-20+90,system_item[3].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);
						  sprintf(display_buf,"%02d",time_status.sec);
			      Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+400-20+90,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			 
					 }
					 else if((x_val>=(738-30-offset_x))&&(x_val<=(738-30+offset_x)))//sec
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
					    time_status.sec++;
					if(time_status.sec > 59)
											time_status.sec = 0;
														 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+400+90-20,system_item[3].y_val+Y_system_system_offset,30,24,Virtual_LCDbuff2,ARGB_clear);
						  sprintf(display_buf,"%02d",time_status.sec);
			      Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+400+90-20,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			 
					 }
					 
					 else if((x_val>=(793-30-offset_x+8))&&(x_val<=(793-30+offset_x+8)))//24h
					 {
					   send_FlC200_base_set_cmd(0x89,0x02,0);
						 if(time_status.format&0x80)
							 time_status.format&=0x7F;
						 else
							 time_status.format|=0x80;
						
						 Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+530+90-20,system_item[3].y_val+Y_system_system_offset,40,24,Virtual_LCDbuff2,ARGB_clear);
						 if(time_status.format&0x80)
				sprintf(display_buf,"12h");
				else
				sprintf(display_buf,"24h");					
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+530+90-20,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);			
			 
				 /*Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+90,system_item[3].y_val+Y_system_system_offset,40,24,Virtual_LCDbuff2,ARGB_clear);

				if(time_status.format&0x80)
				{
					if(time_status.hour==0)
						sprintf(display_buf,"12am");
					else if(time_status.hour<12)				
			    sprintf(display_buf,"%02dam",time_status.hour);
					else if(time_status.hour==12)		
						sprintf(display_buf,"12pm");
					else
						sprintf(display_buf,"%02dpm",time_status.hour-12);
				}
				else
					sprintf(display_buf,"%02d",time_status.hour);
				
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+90+8,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					*/
					dispay_hour();
				
				
				
				
				
					 }
					 else if((x_val>=(873-30-offset_x))&&(x_val<=(873-30+offset_x)))//
					 {
						 send_FlC200_base_set_cmd(0x89,0x02,0);
					   if(time_status.format&0x80)
							 time_status.format&=0x7F;
						 else
							 time_status.format|=0x80;
					
			  Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+530+90-20,system_item[3].y_val+Y_system_system_offset,40,24,Virtual_LCDbuff2,ARGB_clear);
				if(time_status.format&0x80)
				sprintf(display_buf,"12h");
				else
				sprintf(display_buf,"24h");					
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+530+90-20,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);			
			 
				
				
				/* Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset+90,system_item[3].y_val+Y_system_system_offset,40,24,Virtual_LCDbuff2,ARGB_clear);

				if(time_status.format&0x80)
				{
					if(time_status.hour==0)
						sprintf(display_buf,"12am");
					else if(time_status.hour<12)				
			    sprintf(display_buf,"%02dam",time_status.hour);
					else if(time_status.hour==12)		
						sprintf(display_buf,"12pm");
					else
						sprintf(display_buf,"%02dpm",time_status.hour-12);
				}
				else
					sprintf(display_buf,"%02d",time_status.hour);
				
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+90+8,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
					
				*/
				dispay_hour();
				
					 }
					 
					 
					 
				
					 
				 Virtual_LCD_Upgrate_formx1y1(p1->x_val,p1->y_val,p1->x_end_val-p1->x_val,p1->y_end_val-p1->y_val);
				}
				
			 
		 }

	 }
 }

}




				 



void func_Date_Time_Save_And_Back(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  //char display_buf[32];
	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{
			
    }
		else if(deal_type==TO_UP)
		{
		
		}
		else if(deal_type==TO_DOWN)
		{
		
		}
		else if(deal_type==TO_DEAL)
		{
		  memcpy(&time_return_status,&time_status,sizeof(TIME_STATUS));
				  send_FlC200_time_set_cmd();
			setup_p = &setup_page.now_p[0];
			if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_SYSTEM)
			{
					//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
					if(setup_p->father_p!=empty_father_p)	
					{
						//setup_page.now_page_num = 0;
						f_system_Date_Time_set = FALSE;
						setup_page.now_page_num=last_now_page_num;
						setup_page.now_p = setup_p->father_p;
						page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
						f_display_set_info = TRUE;
					}
			}
		}
}


void func_system_Date_Time(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	  if(deal_type==TO_INIT)
		{
	      f_system_Date_Time_set = TRUE;
        //system_item[1].key_type = KEY_TYPE_ONCE;//1			  
			  system_item[2].key_type = KEY_TYPE_TOUCH_NONE;//2
			  system_item[3].key_type = KEY_TYPE_TOUCH_NONE;//3
			  //system_item[4].key_type = KEY_TYPE_ONCE;//4
			  system_item[5].key_type = KEY_TYPE_TOUCH_NONE;//nextpage
			  system_item[6].key_type = KEY_TYPE_TOUCH_NONE;//prepage

			
			
			  memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
			
				Virtual_LCD_Draw_Rectangle_ARGB32(142,90,700,24,Virtual_LCDbuff2,ARGB_clear);
	      Virtual_LCD_Draw_String_ARGB_24_4bit(142,90,"System Settings -> Date&Time",(0xFF78baf7),0,1,1);
				//Virtual_LCD_Draw_Rectangle_ARGB32(system_item[1].x_val+X_system_system_offset,system_item[1].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
				//Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[1].x_val+X_system_system_offset,system_item[1].y_val+Y_system_system_offset,"<-Back",(0xFFe2e2e4),0,1,1);
			
				Virtual_LCD_Draw_Rectangle_ARGB32(system_item[2].x_val+X_system_system_offset,system_item[2].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
				//Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset,system_item[2].y_val+Y_system_system_offset,"Data",(0xFFe2e2e4),0,1,1);
			  
			
			
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+0,system_item[2].y_val+Y_system_system_offset,"Mon",(0xFFe2e2e4),0,1,1);			
				Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+60,system_item[2].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);
			  //sprintf(display_buf,"%04d",time_return_status.year+2000);
			  sprintf(display_buf,"%02d",time_status.mon);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+90,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+130,system_item[2].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
			
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+200-10,system_item[2].y_val+Y_system_system_offset,"Day",(0xFFe2e2e4),0,1,1);			
				Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+200+60-10,system_item[2].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);
			  //sprintf(display_buf,"%04d",time_return_status.year+2000);
			  sprintf(display_buf,"%02d",time_status.day);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+200+90-10,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+200+130-10,system_item[2].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
			
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+400-20,system_item[2].y_val+Y_system_system_offset,"Year",(0xFFe2e2e4),0,1,1);			
				Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+400+60+8-20,system_item[2].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);
			  //sprintf(display_buf,"%04d",time_return_status.year+2000);
			  sprintf(display_buf,"%02d",time_status.year);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[2].x_val+X_system_system_offset+400+90+8-20,system_item[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[2].x_val+X_system_system_offset+400+130+8-20,system_item[2].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
			
			
			
				Virtual_LCD_Draw_Rectangle_ARGB32(system_item[3].x_val+X_system_system_offset,system_item[3].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
				Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+0,system_item[3].y_val+Y_system_system_offset,"Hour",(0xFFe2e2e4),0,1,1);			
				Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[3].x_val+X_system_system_offset+60,system_item[3].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);
			  dispay_hour();
			  //sprintf(display_buf,"%02d",time_status.hour);
			  //Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+80,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[3].x_val+X_system_system_offset+130+16,system_item[3].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
			
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+200+8-10,system_item[3].y_val+Y_system_system_offset,"min",(0xFFe2e2e4),0,1,1);			
				Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[3].x_val+X_system_system_offset+200+60+8-10,system_item[3].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);
			  //sprintf(display_buf,"%04d",time_return_status.year+2000);
			  sprintf(display_buf,"%02d",time_status.min);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+200+90+8-10,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[3].x_val+X_system_system_offset+200+130+8-10,system_item[3].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
			
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+400+8-20,system_item[3].y_val+Y_system_system_offset,"sec",(0xFFe2e2e4),0,1,1);			
				Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[3].x_val+X_system_system_offset+400+60-20,system_item[3].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);
			  //sprintf(display_buf,"%04d",5+2000);
			  sprintf(display_buf,"%02d",time_status.sec);
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+400+90-20,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[3].x_val+X_system_system_offset+400+130-20,system_item[3].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
	
				Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[3].x_val+X_system_system_offset+530+60-20,system_item[3].y_val+Y_system_system_offset,"<",(ARGB_mydarkcyan),0,1,1);			  
				if(time_status.format&0x80)
				sprintf(display_buf,"12h");
				else
				sprintf(display_buf,"24h");					
			  Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+530+90-20,system_item[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);				
			  Virtual_LCD_Draw_String_ARGB_32_4bit_bold(system_item[3].x_val+X_system_system_offset+530+135-20,system_item[3].y_val+Y_system_system_offset,">",(ARGB_mydarkcyan),0,1,1);
			
			
			
				//Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset,system_item[3].y_val+Y_system_system_offset,"Time",(0xFFe2e2e4),0,1,1);
				//Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[3].x_val+X_system_system_offset+500,system_item[3].y_val+Y_system_system_offset,"C     F",(ARGB_mydarkcyan),0,1,1);
			
			//	Virtual_LCD_Draw_Rectangle_ARGB32(system_item[4].x_val+X_system_system_offset,system_item[4].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
			//	Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[4].x_val+X_system_system_offset+600,system_item[4].y_val+Y_system_system_offset,"Save->",(0xFFe2e2e4),0,1,1);
				//Virtual_LCD_Draw_String_ARGB_24_4bit(system_item[4].x_val+X_system_system_offset+500,system_item[4].y_val+Y_system_system_offset,"L    GAL",(ARGB_mydarkcyan),0,1,1);
    }
		else if(deal_type==TO_UP)
		{
			
		}
		else if(deal_type==TO_DOWN)
		{
			
		}
}
void func_system_Language(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	 // sysprintf("\r\n---- deal_type:%d sn %d,",deal_type,sn);
    if(deal_type==TO_INIT)
		{
		  if(base_return_status.language==0)
				sprintf(display_buf,"English");
				//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"English",(ARGB_mydarkcyan),0,1,1);
			else if(base_return_status.language==1)
				sprintf(display_buf,"Chinese");
				//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"Chinese",(ARGB_mydarkcyan),0,1,1);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
		}
		else if(deal_type==TO_UP)
		{
		
		}
		else if(deal_type==TO_DOWN)
		{
		
		}

}


void func_system_Temperature_uint(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
   // sysprintf("\r\n---- deal_type:%d sn %d,",deal_type,sn);
    if(deal_type==TO_INIT)
		{
			if((base_return_status.uint&0x0C)==0x00)
				sprintf(display_buf,"C");
			  //Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"C",(ARGB_mydarkcyan),0,1,1);
			else if((base_return_status.uint&0x0C)==0x04)
				sprintf(display_buf,"F");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
			Virtual_LCD_Draw_String_o(get_str_align_center_x_val(system_item[sn].x_val+X_set_mid_offset,"C",glyph_dsc_24_4bit),system_item[sn].y_val+Y_system_system_offset,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(ARGB_mydarkcyan),0,1,1);
				
		}
		else if(deal_type==TO_UP)
		{  
			if((base_return_status.uint&0x0C)==0x00)
			{ // F
		     base_status.uint&=0xF3;
         base_return_status.uint&=0xF3;
				 base_status.uint|=0x04;
         base_return_status.uint|=0x04;
				 send_FlC200_base_set_cmd(0x01,1,0);
			}
			else
			{
			  //C
			   now_page = 0x0000;
				 base_status.uint&=0xF3;
         base_return_status.uint&=0xF3;
				// base_status.uint|=0x04;
        // base_return_status.uint|=0x04;
				 send_FlC200_base_set_cmd(0x01,0,0);
			}
			  f_display_set_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
		   if((base_return_status.uint&0x0C)==0x00)
			{ // F
		     base_status.uint&=0xF3;
         base_return_status.uint&=0xF3;
				 base_status.uint|=0x04;
         base_return_status.uint|=0x04;
				 send_FlC200_base_set_cmd(0x01,1,0);
			}
			else
			{
			  //C
			   now_page = 0x0000;
				 base_status.uint&=0xF3;
         base_return_status.uint&=0xF3;
				// base_status.uint|=0x04;
        // base_return_status.uint|=0x04;
				 send_FlC200_base_set_cmd(0x01,0,0);
			}
			  f_display_set_info = TRUE;
		}

}
void func_system_Volume_uint(void* p,u8 sn,DEAl_TYPE deal_type)
{
	 char display_buf[32];
   if(deal_type==TO_INIT)
		{
			if((base_return_status.uint&0x03)==0x00)
				sprintf(display_buf,"L");
			  //Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"L",(ARGB_mydarkcyan),0,1,1);
			else if((base_return_status.uint&0x03)==0x01)
				sprintf(display_buf,"GAL");
			  Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
		}
		else if(deal_type==TO_UP)
		{  
			
			
			if((base_return_status.uint&0x03)==0x00)
			{ //gal
			   now_page = 0x0000;
				 base_status.uint&=0xFC;
         base_return_status.uint&=0xFC;
				 base_status.uint|=0x01;
         base_return_status.uint|=0x01;
				 send_FlC200_base_set_cmd(0x02,1,0);
			}
			else
			{
			  //L
			   now_page = 0x0000;
				 base_status.uint&=0xFC;
         base_return_status.uint&=0xFC;
				// base_status.uint|=0x01;
         //base_return_status.uint|=0x01;
				 send_FlC200_base_set_cmd(0x02,0,0);
			}
			  f_display_set_info = TRUE;
		}
		else if(deal_type==TO_DOWN)
		{
		  if((base_return_status.uint&0x03)==0x00)
			{ //gal
			   now_page = 0x0000;
				 base_status.uint&=0xFC;
         base_return_status.uint&=0xFC;
				 base_status.uint|=0x01;
         base_return_status.uint|=0x01;
				 send_FlC200_base_set_cmd(0x02,1,0);
			}
			else
			{
			  //L
			   now_page = 0x0000;
				 base_status.uint&=0xFC;
         base_return_status.uint&=0xFC;
				// base_status.uint|=0x01;
         //base_return_status.uint|=0x01;
				 send_FlC200_base_set_cmd(0x02,0,0);
			}
			  f_display_set_info = TRUE;
		}

}
void func_system_Brightness(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
    if(deal_type==TO_INIT)
		{

			if(base_return_status.light<=50)
				sprintf(display_buf,"Low");
				// Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"Low",(ARGB_mydarkcyan),0,1,1);
			else if(base_return_status.light<=200)
				sprintf(display_buf,"Mid");
				// Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"Mid",(ARGB_mydarkcyan),0,1,1);
		  else //if(base_return_status.light<=200)
				sprintf(display_buf,"Hi");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
			
		}
		else if(deal_type==TO_UP)
		{  
			if(base_return_status.light<=50)
			{
				 base_status.light = 160;//mid
         base_return_status.light = 160;
			   send_FlC200_base_set_cmd(0x08,base_status.light,0);
				 f_display_set_info = TRUE;
			}
			else if(base_return_status.light<=200)
			{
				 base_status.light = 255;//hi
         base_return_status.light = 255;
				 send_FlC200_base_set_cmd(0x08,base_status.light,0);
				 f_display_set_info = TRUE;
			}
			else
			{
			
			}
		}
		else if(deal_type==TO_DOWN)
		{
		  if(base_return_status.light<=50)
			{
				 // base_status.light = 255;
        //base_return_status.light = 255;
				 //send_FlC200_base_set_cmd(0x08,base_status.light,0);
				// f_display_set_info = TRUE;
			}
			else if(base_return_status.light<=200)
			{
				
				 base_status.light = 50;
         base_return_status.light = 50;
			   send_FlC200_base_set_cmd(0x08,base_status.light,0);
				 f_display_set_info = TRUE;
			}
			else
			{
		   	 base_status.light = 160;
         base_return_status.light = 160;
			   send_FlC200_base_set_cmd(0x08,base_status.light,0);
				 f_display_set_info = TRUE;
			}
		}

}
void func_system_Sleep_Time(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
  if(deal_type==TO_INIT)
	{
		if(base_return_status.sleep_time==0)
			sprintf(display_buf,"Off");
		else if(base_return_status.sleep_time<=60)
			sprintf(display_buf,"%02d Min",base_return_status.sleep_time);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
		
	}
	else if(deal_type==TO_UP)
	{  
		 base_return_status.sleep_time++;
		 if(base_return_status.sleep_time>60)
				base_return_status.sleep_time = 60;
		 send_FlC200_base_set_cmd(0x10,base_return_status.sleep_time,0);
		 f_display_set_info = TRUE;

	}
	else if(deal_type==TO_DOWN)
	{
	  if(base_return_status.sleep_time)
				    base_return_status.sleep_time--;
		send_FlC200_base_set_cmd(0x10,base_return_status.sleep_time,0);
		f_display_set_info = TRUE;
	}
}
void func_system_Touch_Tone(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
    if(deal_type==TO_INIT)
		{
			if((base_return_status.touch_tone&0x01)==0x00)
				sprintf(display_buf,"Off");
			else  
				sprintf(display_buf,"On");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
			
		}
		else if(deal_type==TO_UP)
		{  
			if((base_return_status.touch_tone&0x01)==0x00)
				base_return_status.touch_tone |= 0x01;
			else  
			 base_return_status.touch_tone &= 0xFE;
			send_FlC200_base_set_cmd(0x11,(base_return_status.touch_tone&0x01),0);
			f_display_set_info = TRUE;

		}
		else if(deal_type==TO_DOWN)
		{
		  if((base_return_status.touch_tone&0x01)==0x00)
				base_return_status.touch_tone |= 0x01;
			else  
			 base_return_status.touch_tone &= 0xFE;
			send_FlC200_base_set_cmd(0x11,(base_return_status.touch_tone&0x01),0);
			f_display_set_info = TRUE;
		}
}

void func_system_Warning_Tone(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
    if(deal_type==TO_INIT)
		{

			if((base_return_status.touch_tone&0x02)==0x00)
				sprintf(display_buf,"Off");
			else  
				sprintf(display_buf,"On");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
			
		}
		else if(deal_type==TO_UP)
		{  
			if((base_return_status.touch_tone&0x02)==0x00)
			{
				base_return_status.touch_tone |= 0x02;
				send_FlC200_base_set_cmd(0x11,0x11,0);
			}
			else  
			{
			 base_return_status.touch_tone &= 0xFD;
			 send_FlC200_base_set_cmd(0x11,0x10,0);
			}
			
			f_display_set_info = TRUE;

		}
		else if(deal_type==TO_DOWN)
		{
		  if((base_return_status.touch_tone&0x02)==0x00)
			{
				base_return_status.touch_tone |= 0x02;
				send_FlC200_base_set_cmd(0x11,0x11,0);
			}
			else  
			{
			 base_return_status.touch_tone &= 0xFD;
			 send_FlC200_base_set_cmd(0x11,0x10,0);
			}
			f_display_set_info = TRUE;
		}

}

void func_system_Light_Up_The_Screen(void* p,u8 sn,DEAl_TYPE deal_type)
{
	  char display_buf[32];
    if(deal_type==TO_INIT)
		{

			if((base_return_status.touch_tone&0x04)==0x00)
				sprintf(display_buf,"Off");
			else  
				sprintf(display_buf,"On");
			Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
			
		}
		else if(deal_type==TO_UP)
		{  
			if((base_return_status.touch_tone&0x04)==0x00)
			{
				base_return_status.touch_tone |= 0x04;
				send_FlC200_base_set_cmd(0x11,0x21,0);
			}
			else  
			{
			 base_return_status.touch_tone &= 0xFB;
			 send_FlC200_base_set_cmd(0x11,0x20,0);
			}
			
			f_display_set_info = TRUE;

		}
		else if(deal_type==TO_DOWN)
		{
		  if((base_return_status.touch_tone&0x04)==0x00)
			{
				base_return_status.touch_tone |= 0x04;
				send_FlC200_base_set_cmd(0x11,0x21,0);
			}
			else  
			{
			 base_return_status.touch_tone &= 0xFB;
			 send_FlC200_base_set_cmd(0x11,0x20,0);
			}
			f_display_set_info = TRUE;
		}

}



void func_system_Upgrade(void* p,u8 sn,DEAl_TYPE deal_type)
{
//do nothing
	
//	char display_buf[32];
//	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{
			
    }
		else if(deal_type==TO_UP)
		{
		
		}
		else if(deal_type==TO_DOWN)
		{
		
		}
		else if(deal_type==TO_DEAL)
		{
		   send_FlC200_base_set_cmd(0x88,0x01,0);
			
		}

}
void func_system_Restore_Default_Settings(void* p,u8 sn,DEAl_TYPE deal_type)
{
//do nothing
//		char display_buf[32];
	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{
			
    }
		else if(deal_type==TO_UP)
		{
		
		}
		else if(deal_type==TO_DOWN)
		{
		
		}
		else if(deal_type==TO_DEAL)
		{
		   //send_FlC200_base_set_cmd(0x88,0x01,0);
			send_FlC200_base_set_cmd(0x81,0xFF,0);
			setup_p = &setup_page.now_p[0];
			if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item==TOP_SIDE_PAGE_SYSTEM_SYSTEM)
			{
					//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
					if(setup_p->father_p!=empty_father_p)	
					{
						//setup_page.now_page_num = 0;
						f_system_Date_Time_set = FALSE;
						setup_page.now_page_num=last_now_page_num;
						setup_page.now_p = setup_p->father_p;
						page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].last_item=TOP_SIDE_PAGE_SYSTEM_MUN;//更新
						f_display_set_info = TRUE;
					}
					
			
			}
		}

}
void func_system_System_Reset(void* p,u8 sn,DEAl_TYPE deal_type)
{
//do nothing
//		char display_buf[32];
//	  setup_item_info_t *setup_p;
	  if(deal_type==TO_INIT)
		{
			
    }
		else if(deal_type==TO_UP)
		{
		
		}
		else if(deal_type==TO_DOWN)
		{
		
		}
		else if(deal_type==TO_DEAL)
		{
		   //send_FlC200_base_set_cmd(0x88,0x01,0);
			send_FlC200_base_set_cmd(0x81,0xFE,0);
		}

}


void func_Code_Enter(void* p,u8 sn,DEAl_TYPE deal_type)	
{
    char display_buf[32];
	  if(deal_type==TO_INIT)
		{
			// sprintf(display_buf,"%d%%",main_battery_set_return_status.V_SOC_warning_L);
			 //Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(power_setup_item[sn].x_val+X_set_mid_offset,power_setup_item[sn].y_val+Y_system_system_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
    }
		else if(deal_type==TO_UP)
		{
			  
		}
		else if(deal_type==TO_DOWN)
		{
			 
		}
		else if(deal_type==TO_DEAL)
		{
        keyboard_ui_step=KEYBOARD_PAGE_NOR;
			  f_ui_new_input_code_enter = TRUE;
		     //ui_disply_keyboard();
				// f_ui_new_input_bat_capacity = TRUE;
			  // Set_val_input_target_p(&main_battery_set_return_status.V_SOC_warning_L,&main_battery_set_return_status.V_SOC_warning_L);
			  // power_now_set_send_id=0x03;
			  //char_input_target_type = 2;
				 f_need_ui_disply_keyboard = TRUE;
		}
}




void display_setup_page(bool upgrage_dispaly,bool upgrage,setup_page_t *setup_page_p,lcd_dis_item_t *setup_item_p,char* display_buf)
{
    setup_item_info_t *setup_p; 
	  //setup_page_t *father_setup_page_p;
	  u8 i;
	  //u16 x_addr_offset = 0;
	 
	 
	if(setup_page_p->now_p==empty_son_p)
	{
	   setup_page_p->max_page_num = 0;
		 return;
	}
	else
	{
		for(i=0;1;i++)
		{
			if(setup_page_p->now_p[i].setup_menu_touch_type == END_OF_THE_LIST)
			{
				 setup_page_p->max_page_num = i;
				 break;
			}
	 }
 } 
 
   //PAGE_DISPLAY_ITEM_NUM
 	 if(setup_page_p->now_page_num==0)
		 setup_item_p[6].key_type = KEY_TYPE_TOUCH_NONE;//prepage  
	 else
		 setup_item_p[6].key_type = KEY_TYPE_ONCE;//prepage
	 
	 if((setup_page_p->now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page_p->max_page_num)
		 setup_item_p[5].key_type = KEY_TYPE_ONCE;//prepage
	 else
		 setup_item_p[5].key_type = KEY_TYPE_TOUCH_NONE;//prepage
	 
	 
	 if(setup_page_p->now_p[0].father_p!=empty_father_p)	  //back
	 {
	    setup_item_p[SYSTEM_BACK_OFFSET].key_type = KEY_TYPE_ONCE;// 
	 }
	 else 
	 {
		  if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
	    setup_item_p[SYSTEM_BACK_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;// 
			else
			{
				setup_item_p[SYSTEM_BACK_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
				setup_item_p[SYSTEM_BACK_OFFSET].last_status = STATUS_IDLE;
	      setup_item_p[SYSTEM_BACK_OFFSET].now_status = STATUS_IDLE;
				
			}
	 }
	 
	 if(upgrage)
  {
	      Virtual_LCD_Draw_Rectangle_ARGB32(142,90,700,24,Virtual_LCDbuff2,ARGB_clear);
	      Virtual_LCD_Draw_String_ARGB_24_4bit(142,90,display_buf,(0xFF78baf7),0,1,1);
		    /*if(setup_page_p->now_p->father_p!=empty_father_p)
				{
					x_addr_offset = 0;
					i = 0;
					while(display_buf[i]!='\0')
					{						
						  x_addr_offset+=(glyph_dsc_24_4bit_bold[display_buf[i]-0x20].adv_w);
							i++;
					}
					Virtual_LCD_Draw_String_ARGB_24_4bit(142+x_addr_offset,90," -> ",(0xFF78baf7),0,1,1);
					x_addr_offset += 30;
					father_setup_page_p->now_p = setup_page_p->now_p->father_p;
				  Virtual_LCD_Draw_String_ARGB_24_4bit(142+x_addr_offset,90,father_setup_page_p->now_p->display_str,(0xFF78baf7),0,1,1);
				
				}*/
  }
	 
	 
   for(i=0;i<PAGE_DISPLAY_ITEM_NUM;i++)
   {
		 
		 setup_p = &setup_page_p->now_p[setup_page_p->now_page_num*PAGE_DISPLAY_ITEM_NUM+i];
		 if((setup_page_p->now_page_num*PAGE_DISPLAY_ITEM_NUM+i)<setup_page_p->max_page_num)
		 {
			 
			 if(upgrage)
	     {
			   Virtual_LCD_Draw_Rectangle_ARGB32(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
		     if(setup_p->setup_menu_touch_type==TOUCH_TYPE_NONE_DIS_DIM)
				 Virtual_LCD_Draw_String_ARGB_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+Y_system_system_offset,setup_page_p->now_p[setup_page_p->now_page_num*PAGE_DISPLAY_ITEM_NUM+i].display_str,(ARGB_gray),0,1,1);
				 else
				 Virtual_LCD_Draw_String_ARGB_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+Y_system_system_offset,setup_page_p->now_p[setup_page_p->now_page_num*PAGE_DISPLAY_ITEM_NUM+i].display_str,(0xFFe2e2e4),0,1,1);
	     }
			 
			  
			 switch(setup_p->setup_menu_touch_type)
			{
				 case TOUCH_TYPE_NORMAL://正常  
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item 
				   setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
					 break;
				  case TOUCH_TYPE_ENTER://正常  点一下进入下一级
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item 
				   setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
					 break;
				 case TOUCH_TYPE_LEFT_RIGHT://显示左右选择按键 可以左右选择
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
				   setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_ONCE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_ONCE;//right				   
					 break;
				 case TOUCH_TYPE_UP_DOWN://显示上下选择按键 可以上下选择
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
				   setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
					 break;
				 case TOUCH_TYPE_SLIDE://显示滑动按键 可以滑动选择
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
				   setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
					 break;
				 case TOUCH_TYPE_KEYBOARD://进入键盘显示，输入值
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item   
           setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right				 
					 break;
				 case TOUCH_TYPE_NONE://显示没有触摸
				 case TOUCH_TYPE_NONE_DIS_DIM:
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
				   setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
					 break;
				 case TOUCH_TYPE_SPECIAL://特殊情况处理 在程序外处理
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item 
				   setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
					 break;
				 case END_OF_THE_LIST://结束
					 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
				   setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				   setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
					 break;
			}
			
			if(upgrage)
			{
			  if(*setup_p->f!=empty_fun)
			    (*setup_p->f)(setup_p,i+SYSTEM_ITEM_1_OFFSET,TO_INIT);	
				
				//sysprintf("\r\n======================%d",i);
		  }
			else
			{
			   if(*setup_p->f!=empty_fun)
			    (*setup_p->f)(setup_p,i+SYSTEM_ITEM_1_OFFSET,TO_DO_NOTHING);	
			}
				
		
		
   }
	else
	 {
		 setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
		 setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
		 setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
		 if(upgrage)
		 Virtual_LCD_Draw_Rectangle_ARGB32(setup_item_p[1+i].x_val+X_system_system_offset,setup_item_p[1+i].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);

    }
  }
	if(upgrage_dispaly)
		 Virtual_LCD_Upgrate();	


}

void display_set_info(bool upgrage)
{
//	char display_buf[32];
	//u8 i;
	setup_page_t *setup_page_p;
	lcd_dis_item_t *setup_item_p;
	static u8 last_now_item = TOP_SIDE_PAGE_SYSTEM_MUN;

	
	setup_page_p = &setup_page;
	setup_item_p = system_item;
	if(last_now_item!=page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item)
	{
	   last_now_item=page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item;
		// if(page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item)
		 setup_page_p->now_p = system_settings;
		 //accessories_page.now_p = accessory_settings;
     setup_page_p->now_page_deep = MENU_DEEP_1TH;
		 last_now_page_num = 0;
     setup_page_p->now_page_num = 0;
     //accessories_page.now_page_num = 0;
		
	}
  f_display_set_info = FALSE;
	sysprintf("\r\n setup_page.now_page_num:%d MAX:%d",setup_page.now_page_num,setup_page.max_page_num);
	display_setup_page(0,upgrage,setup_page_p,setup_item_p,"System Settings");

}










BOOL page_system_deel_with_i(lcd_dis_page_t *p2,u8* i)
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


void ui_system_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_SYSTEM][TOP_SIDE_PAGE_SYSTEM_SYSTEM];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=SYSTEM_SYSTEM_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only



   t_system_headline.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_btn1_d.key_type = KEY_TYPE_ONCE;
   t_system_btn2_d.key_type = KEY_TYPE_ONCE;
   t_system_btn3_d.key_type = KEY_TYPE_ONCE;
   t_system_btn4_d.key_type = KEY_TYPE_ONCE;
   t_system_nextpage_d.key_type = KEY_TYPE_ONCE;
   t_system_prepage_d.key_type= KEY_TYPE_ONCE;
	 
	 t_set_left_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_left2_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_left3_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_left4_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_right_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_right2_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_right3_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_set_right4_d.key_type= KEY_TYPE_TOUCH_AND_DISPLAY_NONE;


   p->item = system_item;
   for(i=0;i<SYSTEM_SYSTEM_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_system_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_system_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_system_item_u[i]->size_of_pic_item ;
	 
	 }
	 //int setting_list
	   display_set_info(FALSE);
 }


