#include "includes.h"


extern lcd_dis_item_t t_load_motobtn0_u;
extern void func_load_motobtn1_u(void* p,u8 sn);
extern const unsigned char load_motobtn0_u[];

lcd_dis_item_t t_load_motobtn1_u={(unsigned char*)load_motobtn0_u,(unsigned char*)load_motobtn0_u,(unsigned char*)load_motobtn0_u,0,0,5342,5342,5342,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motobtn1_u,Y_load_motobtn1_u,X_load_motobtn1_u+190,Y_load_motobtn1_u+327,0,&func_load_motobtn1_u};


extern void func_load_motobtn_touch0_d(void* p,u8 sn);
extern void func_load_motobtn_touch1_d(void* p,u8 sn);


lcd_dis_item_t t_load_motobtn_touch0_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motobtn0_u,Y_load_motobtn0_u,X_load_motobtn0_u+190,Y_load_motobtn0_u+327,0,&func_load_motobtn_touch0_d};
lcd_dis_item_t t_load_motobtn_touch1_d={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motobtn1_u,Y_load_motobtn1_u,X_load_motobtn1_u+190,Y_load_motobtn1_u+327,0,&func_load_motobtn_touch1_d};


extern const unsigned char Motors_Awning_ico_u[];
extern void func_loads_motors_u_ico0(void* p,u8 sn);
extern void func_loads_motors_u_ico1(void* p,u8 sn);


lcd_dis_item_t t_loads_motors_u_ico0={(unsigned char*)Motors_Awning_ico_u,(unsigned char*)Motors_Awning_ico_u,(unsigned char*)Motors_Awning_ico_u,0,0,3935,3935,3935,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_Motors_Awning_ico_u,Y_Motors_Awning_ico_u,X_Motors_Awning_ico_u+118,Y_Motors_Awning_ico_u+73,0,&func_loads_motors_u_ico0};
lcd_dis_item_t t_loads_motors_u_ico1={(unsigned char*)Motors_Awning_ico_u,(unsigned char*)Motors_Awning_ico_u,(unsigned char*)Motors_Awning_ico_u,0,0,3935,3935,3935,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_Motors_Awning_ico_u,Y_Motors_Awning_ico_u,X_Motors_Awning_ico_u+118,Y_Motors_Awning_ico_u+73,0,&func_loads_motors_u_ico1};


//icon char touch
//extern void func_loads_motors_ico_char0_d(void* p,u8 sn);
//extern void func_loads_motors_ico_char1_d(void* p,u8 sn);

//lcd_dis_item_t t_loads_load_d_ico_char0={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_LONG_PRESS,STATUS_IDLE,STATUS_IDLE,X_loads_load_d_ico_char0,Y_loads_load_d_ico_char0,X_loads_load_d_ico_char0+128,Y_loads_load_d_ico_char0+32,0,&func_loads_load_ico_char0_d};
//lcd_dis_item_t t_loads_load_d_ico_char1={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_LONG_PRESS,STATUS_IDLE,STATUS_IDLE,X_loads_load_d_ico_char1,Y_loads_load_d_ico_char1,X_loads_load_d_ico_char1+128,Y_loads_load_d_ico_char1+32,0,&func_loads_load_ico_char1_d};

	
extern const unsigned char load_motoctl_btn_d[];
extern const unsigned char load_motoctl_btn_u[];
	
	
extern void func_load_motoctl_btn_down_d(void* p,u8 sn);
extern void func_load_motoctl_btn1_d(void* p,u8 sn);
extern void func_load_motoctl_btn1_down_d(void* p,u8 sn);
extern void func_load_motoctl_btn_u(void* p,u8 sn);
extern void func_load_motoctl_btn_down_u(void* p,u8 sn);
extern void func_load_motoctl_btn1_u(void* p,u8 sn);
extern void func_load_motoctl_btn1_down_u(void* p,u8 sn);

	
lcd_dis_item_t t_load_motoctl_btn_down_d={(unsigned char*)load_motoctl_btn_d,(unsigned char*)load_motoctl_btn_d,(unsigned char*)load_motoctl_btn_d,0,0,2317,2317,2317,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motoctl_btn_down_d,Y_load_motoctl_btn_down_d,X_load_motoctl_btn_down_d+138,Y_load_motoctl_btn_down_d+48,0,&func_load_motoctl_btn_down_d};
lcd_dis_item_t t_load_motoctl_btn_down_u={(unsigned char*)load_motoctl_btn_u,(unsigned char*)load_motoctl_btn_u,(unsigned char*)load_motoctl_btn_u,0,0,1986,1986,1986,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motoctl_btn_down_u,Y_load_motoctl_btn_down_u,X_load_motoctl_btn_down_u+138,Y_load_motoctl_btn_down_u+48,0,&func_load_motoctl_btn_down_u};

lcd_dis_item_t t_load_motoctl_btn1_d={(unsigned char*)load_motoctl_btn_d,(unsigned char*)load_motoctl_btn_d,(unsigned char*)load_motoctl_btn_d,0,0,2317,2317,2317,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motoctl_btn1_d,Y_load_motoctl_btn_d,X_load_motoctl_btn1_d+138,Y_load_motoctl_btn1_d+48,0,&func_load_motoctl_btn1_d};
lcd_dis_item_t t_load_motoctl_btn1_u={(unsigned char*)load_motoctl_btn_u,(unsigned char*)load_motoctl_btn_u,(unsigned char*)load_motoctl_btn_u,0,0,1986,1986,1986,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motoctl_btn1_u,Y_load_motoctl_btn_u,X_load_motoctl_btn1_u+138,Y_load_motoctl_btn1_u+48,0,&func_load_motoctl_btn1_u};

lcd_dis_item_t t_load_motoctl_btn1_down_d={(unsigned char*)load_motoctl_btn_d,(unsigned char*)load_motoctl_btn_d,(unsigned char*)load_motoctl_btn_d,0,0,2317,2317,2317,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motoctl_btn1_down_d,Y_load_motoctl_btn1_down_d,X_load_motoctl_btn1_down_d+138,Y_load_motoctl_btn1_down_d+48,0,&func_load_motoctl_btn1_down_d};
lcd_dis_item_t t_load_motoctl_btn1_down_u={(unsigned char*)load_motoctl_btn_u,(unsigned char*)load_motoctl_btn_u,(unsigned char*)load_motoctl_btn_u,0,0,1986,1986,1986,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_load_motoctl_btn1_down_u,Y_load_motoctl_btn1_down_u,X_load_motoctl_btn1_down_u+138,Y_load_motoctl_btn1_down_u+48,0,&func_load_motoctl_btn1_down_u};
	
	
	
lcd_dis_item_t *p_loads_motors_item_d[LOADS_MOTORS_ICO_NUM]=
{
&t_load_motobtn0_u,	
&t_load_motobtn1_u,	
&t_loads_motors_u_ico0,
&t_loads_motors_u_ico1,
	
&t_load_motoctl_btn_d,	
&t_load_motoctl_btn_down_d,
&t_load_motoctl_btn1_d,
&t_load_motoctl_btn1_down_d,
	
&t_load_motobtn_touch0_d,
&t_load_motobtn_touch1_d,
&t_loads_b_setup_f,
	
};

//????∞'?¸·D±Ì µØ?e
lcd_dis_item_t *p_loads_motors_item_u[LOADS_MOTORS_ICO_NUM]=
{
&t_load_motobtn0_u,	
&t_load_motobtn1_u,		
&t_loads_motors_u_ico0,
&t_loads_motors_u_ico1,
	
&t_load_motoctl_btn_u,	
&t_load_motoctl_btn_down_u,
&t_load_motoctl_btn1_u,
&t_load_motoctl_btn1_down_u,
	
&t_load_motobtn_touch0_d,
&t_load_motobtn_touch1_d,
&t_loads_b_setup_f,

};

lcd_dis_item_t loads_motors_item[LOADS_MOTORS_ICO_NUM];












u8 loads_display_motors_ch[MAX_LOADS_MOTORS_DIAPLAY_NUM] = {0x1A,0x1C};
u8 loads_display_motors_all_ch[MAX_LOADS_MOTORS_DIAPLAY_NUM*2] = {0x1A,0x1B,0x1C,0x1D};
#define X_motors_nane_offset 92
#define Y_motors_nane_offset 160
#define Y_motors_current_offset 129
#define Y_motors_bntname_offset 202
#define Y_motors_bntname_down_offset 264
u16* loads_display_motors_bnt_X[MAX_LOADS_MOTORS_DIAPLAY_NUM*2] =
{
//&t_load_motobtn0_u.x_val,
//&t_load_motobtn1_u.x_val,
	&t_load_motoctl_btn_d.x_val,
	&t_load_motoctl_btn_down_d.x_val,
	&t_load_motoctl_btn1_d.x_val,
	&t_load_motoctl_btn1_down_d.x_val,
};
u16* loads_display_motors_bnt_Y[MAX_LOADS_MOTORS_DIAPLAY_NUM*2] =
{
//&t_load_motobtn0_u.y_val,
//&t_load_motobtn1_u.y_val,
	&t_load_motoctl_btn_d.y_val,
	&t_load_motoctl_btn_down_d.y_val,
	&t_load_motoctl_btn1_d.y_val,
	&t_load_motoctl_btn1_down_d.y_val,
};
u16* loads_display_motors_ch_X[MAX_LOADS_MOTORS_DIAPLAY_NUM] =
{
&t_load_motobtn0_u.x_val,
&t_load_motobtn1_u.x_val,
};
u16* loads_display_motors_ch_Y[MAX_LOADS_MOTORS_DIAPLAY_NUM] =
{
&t_load_motobtn0_u.y_val,
&t_load_motobtn1_u.y_val,

};
lcd_dis_item_t *p_loads_motors_item[MAX_LOADS_MOTORS_DIAPLAY_NUM]=
{
&loads_motors_item[2],
&loads_motors_item[3],

};
u8 loads_motors_item_now_status[MAX_LOADS_MOTORS_DIAPLAY_NUM];
void get_loads_motors_item_now_status(void)
{
	u8 i;
	for(i=0;i<MAX_LOADS_MOTORS_DIAPLAY_NUM;i++)
	{
	  loads_motors_item_now_status[i] =  p_loads_motors_item[i]->now_status;
	}
}
void set_loads_motors_item_now_status(void)
{
	u8 i;
	for(i=0;i<MAX_LOADS_MOTORS_DIAPLAY_NUM;i++)
	{
	    p_loads_motors_item[i]->now_status = loads_motors_item_now_status[i];
		  p_loads_motors_item[i]->last_status = loads_motors_item_now_status[i];
	}
}




void set_loads_motors_item_key_type(KEY_TYPE type)
{
	u8 i;
	u8 ch=0;
	
	for(i=0;i<MAX_LOADS_MOTORS_DIAPLAY_NUM;i++)
	{
      if(f_override_key==FALSE)
		 {
			 
       ch = loads_display_motors_ch[i];
		
		   if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>switch_ch_select_num_max))
			 {
         // p_loads_loads_item_d[i]->key_type = type;
			    loads_motors_item[i+8].key_type = KEY_TYPE_LONG_PRESS;
			    loads_motors_item[i+2].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
				  if(i==0)
					{
			      loads_motors_item[4].key_type = KEY_TYPE_TOUCH_NONE;
				    loads_motors_item[5].key_type = KEY_TYPE_TOUCH_NONE;
						
					}
					if(i==1)
					{
			      loads_motors_item[6].key_type = KEY_TYPE_TOUCH_NONE;
				    loads_motors_item[7].key_type = KEY_TYPE_TOUCH_NONE;
					}
				 //sysprintf("\r\n------------%d %d %d",i,ch,switch_ch_list_return[ch]);	
			 }
			 else
			 {
         // p_loads_loads_item_d[i]->key_type = type;
			    loads_motors_item[i+8].key_type = KEY_TYPE_LONG_PRESS;
			    loads_motors_item[i+2].key_type = KEY_TYPE_TOUCH_NONE;
				  if(i==0)
					{
			      loads_motors_item[4].key_type = KEY_TYPE_TOUCH_KEEP;
				    loads_motors_item[5].key_type = KEY_TYPE_TOUCH_KEEP;
					}
					if(i==1)
					{
						loads_motors_item[6].key_type = KEY_TYPE_TOUCH_KEEP;
				    loads_motors_item[7].key_type = KEY_TYPE_TOUCH_KEEP;
					}
				//	sysprintf("\r\n------------%d %d %d",i,ch,switch_ch_list_return[ch]);	
			 }
		 }
		 else
		 {
		   ch = loads_display_motors_ch[i];
		
		   if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>switch_ch_select_num_max))
			 {
         // p_loads_loads_item_d[i]->key_type = type;
			    loads_motors_item[i+8].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			    loads_motors_item[i+2].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
				  if(i==0)
					{
			      loads_motors_item[4].key_type = KEY_TYPE_TOUCH_NONE;
				    loads_motors_item[5].key_type = KEY_TYPE_TOUCH_NONE;
						
					}
					if(i==1)
					{
			      loads_motors_item[6].key_type = KEY_TYPE_TOUCH_NONE;
				    loads_motors_item[7].key_type = KEY_TYPE_TOUCH_NONE;
					}
				 //sysprintf("\r\n------------%d %d %d",i,ch,switch_ch_list_return[ch]);	
			 }
			 else
			 {
         // p_loads_loads_item_d[i]->key_type = type;
			    loads_motors_item[i+8].key_type = KEY_TYPE_TOUCH_NONE;
			    loads_motors_item[i+2].key_type = KEY_TYPE_TOUCH_NONE;
				  if(i==0)
					{
			      loads_motors_item[4].key_type = KEY_TYPE_TOUCH_NONE;
				    loads_motors_item[5].key_type = KEY_TYPE_TOUCH_NONE;
					}
					if(i==1)
					{
						loads_motors_item[6].key_type = KEY_TYPE_TOUCH_NONE;
				    loads_motors_item[7].key_type = KEY_TYPE_TOUCH_NONE;
					}
				//	sysprintf("\r\n------------%d %d %d",i,ch,switch_ch_list_return[ch]);	
			 }
		 
		 }

		 

	}
	 /*for(i=0;i<LOADS_MOTORS_ICO_NUM;i++)
			 {
			   sysprintf("\r\n------------%d %d",i,loads_motors_item[i].key_type);	
			 
			 }*/
}




void disply_loads_motor_ch_name(bool upgrade)
{
	u8 i;
	u8 ch=0;
	u32 display_color;
	char display_buf[32];
	static u8 old_switch_ch_list_return[SWITCH_NAME_CH_NUM];
	lcd_dis_item_t *p;
	
	for(i=0;i<MAX_LOADS_MOTORS_DIAPLAY_NUM;i++)
	{
		ch = loads_display_motors_ch[i];
		if((upgrade)||(old_switch_ch_list_return[ch]!=switch_ch_list_return[ch]))
	  {
	     old_switch_ch_list_return[ch]=switch_ch_list_return[ch];
			if(upgrade==FALSE)
			Virtual_LCD_Draw_Rectangle_ARGB32(*loads_display_motors_ch_X[i]+120,*loads_display_motors_ch_Y[i]+10,50,100,Virtual_LCDbuff2,ARGB_clear);
      //sysprintf("\r\nnow_status:,%d,%d",p_home_lights_item_d[i]->now_status,t_home_load_d_ico.last_status);
			
		  display_color = 0xFF838697;
			if(f_override_key)
			{
				
				p=&t_key_locked1;
				png_dis_xy(*loads_display_motors_ch_X[i]+150,*loads_display_motors_ch_Y[i]+10,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff2);
			  
			  //sprintf(display_buf,"locked");	
				//Virtual_LCD_Draw_String_ARGB_16_4bit(*loads_display_motors_ch_X[i]+120,*loads_display_motors_ch_Y[i]+10,display_buf,display_color,0,1,1);

			}
			else if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>switch_ch_select_num_max))
			{
			  sprintf(display_buf,"null");
				Virtual_LCD_Draw_String_ARGB_16_4bit(*loads_display_motors_ch_X[i]+138,*loads_display_motors_ch_Y[i]+10,display_buf,display_color,0,1,1);
				
			}
			else
			{
				sprintf(display_buf,"ch%d",switch_ch_list_return[ch]);
				//if(p_loads_motors_item_d[i]->now_status==STATUS_SELECT)
				//	display_color = 0xFF82c2ff;
				Virtual_LCD_Draw_String_ARGB_16_4bit(*loads_display_motors_ch_X[i]+138,*loads_display_motors_ch_Y[i]+10,display_buf,display_color,0,1,1);
				sprintf(display_buf,"ch%d",switch_ch_list_return[ch+1]);
				Virtual_LCD_Draw_String_ARGB_16_4bit(*loads_display_motors_ch_X[i]+138,*loads_display_motors_ch_Y[i]+30,display_buf,display_color,0,1,1);
			}

			  
		
			
			if(upgrade==FALSE)
			{
			   Virtual_LCD_Upgrate_formx1y1(*loads_display_motors_ch_X[i]+120,*loads_display_motors_ch_Y[i]+10,50,100);
			  // Virtual_LCD_Upgrate();
			}
	    
	}
}
}

void disply_loads_motor_name(bool upgrade)
{
	u8 i;
	u8 ch=0;
	static SWITCH_NAME_LIST old_switch_name_list_return[SWITCH_NAME_CH_NUM];

	
	
	for(i=0;i<MAX_LOADS_MOTORS_DIAPLAY_NUM;i++)
	{
		ch = loads_display_motors_ch[i];
		if((upgrade)||(memcmp(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST))))
	  {
	      memcpy(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST));
			if(upgrade==FALSE)
			Virtual_LCD_Draw_Rectangle_ARGB32(*loads_display_motors_ch_X[i],*loads_display_motors_ch_Y[i]+Y_motors_nane_offset,160,100,Virtual_LCDbuff2,ARGB_clear);
			
      //sysprintf("\r\nnow_status:,%d,%d",p_home_loads_item_d[i]->now_status,t_home_load_d_ico.last_status);
			
			/*if(f_loads_b_setup_d)
			{
				if(p_loads_loads_item_d[i]->now_status==STATUS_SELECT)
				{
				 Virtual_LCD_Draw_String_ARGB_16_4bit(*loads_display_loads_ch_X[i]+X_loads_nane_offset+(7-switch_name_list_return[ch].txt_len/2)*8,*loads_display_loads_ch_Y[i]+Y_loads_nane_offset,\
					(char*)switch_name_list_return[ch].txt,0xFF82c2ff,0,1,1);
				}
				else
				{
					Virtual_LCD_Draw_String_ARGB_16_4bit(*loads_display_loads_ch_X[i]+X_loads_nane_offset+(7-switch_name_list_return[ch].txt_len/2)*8,*loads_display_loads_ch_Y[i]+Y_loads_nane_offset,\
					(char*)switch_name_list_return[ch].txt,0xFF838697,0,1,1);	
				}
	  	}
			else*/
			{
			  if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>switch_ch_select_num_max))
				{
				
				}
				else
				{
					
					if(p_loads_motors_item_d[i]->now_status==STATUS_SELECT)
					{
					 Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_nane_offset,\
						(char*)switch_name_list_return[ch].txt,0xFF82c2ff,0,1,1);
					}
					else
					{
						Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_nane_offset,\
						(char*)switch_name_list_return[ch].txt,0xFF838697,0,1,1);	
					}
					
					if(switch_name_list_return[ch].icon_select==0)
					{
					   Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_bntname_offset,\
						"Retract",ARGB_white,0,1,1);	
						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_bntname_down_offset,\
						"Extend",ARGB_white,0,1,1);	
					}
					else if(switch_name_list_return[ch].icon_select==1)
					{
					   Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_bntname_offset,\
						"Close",ARGB_white,0,1,1);	
						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_bntname_down_offset,\
						"Open",ARGB_white,0,1,1);	
					}
					else if(switch_name_list_return[ch].icon_select==2)
					{
					   Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_bntname_offset,\
						"In",ARGB_white,0,1,1);	
						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_bntname_down_offset,\
						"Out",ARGB_white,0,1,1);	
					}
				
				}
			}
			
			
			if(upgrade==FALSE)
			{
			   Virtual_LCD_Upgrate_formx1y1(*loads_display_motors_ch_X[i],*loads_display_motors_ch_Y[i]+Y_motors_nane_offset,160,32);
			  // Virtual_LCD_Upgrate();
			}
	
	  }
  }
	

}
void disply_motors_current_val(bool upgrade)
{
	u8 i;
	u8 ch=0;
	char display_buf[32];
	static u16 old_current_val[SWITCH_NAME_CH_NUM];
	static u8 ch_now_status[MAX_LOADS_MOTORS_DIAPLAY_NUM*2] = {STATUS_IDLE,STATUS_IDLE,STATUS_IDLE,STATUS_IDLE};
	
	if(f_disply_current_val==FALSE)
		return;
	for(i=0;i<MAX_LOADS_MOTORS_DIAPLAY_NUM*2;i++)
	{
		ch = loads_display_motors_all_ch[i];
		if(upgrade||(old_current_val[ch]!=current_val[ch])||(ch_now_status[i]!=loads_motors_item[4+i].now_status))
	  {
			//sysprintf("\r\n999999999999999999999999999999,i%d,%d,%d",i,ch_now_status[i],loads_motors_item[4+i].now_status);	
	      old_current_val[ch]=current_val[ch];
			ch_now_status[i]=loads_motors_item[4+i].now_status;
			if(upgrade==FALSE)
			Virtual_LCD_Draw_Rectangle_ARGB32(*loads_display_motors_ch_X[i/2],*loads_display_motors_ch_Y[i/2]+Y_motors_current_offset,160,16,Virtual_LCDbuff2,ARGB_clear);

			
			
			if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>switch_ch_select_num_max))
			{
			    sprintf(display_buf,"  ");
			}
			else
			{
				if(loads_motors_item[4+i].now_status==STATUS_TOUCH)
				{
				  if(current_val[ch]>=10)
					{
				    sprintf(display_buf,"%d.%dA",(current_val[ch])/10,(current_val[ch])%10);
					}
					else if(current_val[ch]==0)
					{
					  sprintf(display_buf,"--");
					}
					else
					{
					  sprintf(display_buf,"<1A");
					}
				
				 //Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(*loads_display_motors_ch_X[i]+X_motors_nane_offset,*loads_display_motors_ch_Y[i]+Y_motors_current_offset,\
					//display_buf,0xFF838697,0,1,1);//ARGB_myorange
				}
				else
				{
				   //Virtual_LCD_Draw_Rectangle_ARGB32(*loads_display_motors_ch_X[i],*loads_display_motors_ch_Y[i]+Y_motors_current_offset,160,16,Virtual_LCDbuff2,ARGB_clear);
				   sprintf(display_buf,"--");
				}

			  
	  	}
		  Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(*loads_display_motors_ch_X[i/2]+X_motors_nane_offset,*loads_display_motors_ch_Y[i/2]+Y_motors_current_offset,\
					display_buf,0xFF838697,0,1,1);//ARGB_myorange
			
			if(upgrade==FALSE)
			{
			   Virtual_LCD_Upgrate_formx1y1(*loads_display_motors_ch_X[i/2],*loads_display_motors_ch_Y[i/2]+Y_motors_current_offset,160,32);
			  // Virtual_LCD_Upgrate();
			}
	
	}
}
}
#if 0
void drop_out_loads_setup(void)
{
	loads_item[30].now_status = STATUS_IDLE;
}
void disply_loads_load_name_bg(u8 ich,bool upgrade)
{
	u8 i=ich,j,fd=1;
	u8 ch=0;
	u16 h = 0;
	
	if(upgrade)
	{

	    ch = loads_display_loads_ch[i];
		
		   for(j=0;j<NAME_TXT_MAX_LEN;j++)
		   {
		     if(switch_name_list_return[ch].txt[j]=='\0')					 
					 break;
				 
				 h+=(glyph_dsc_16_4bit_bold[switch_name_list_return[ch].txt[j]-0x20].adv_w*fd);//º∆À„◊÷∑˚øÌ∂»
		   }

			// Virtual_LCD_Draw_String_ARGB_16_4bit(*loads_display_loads_ch_X[i]+X_loads_nane_offset+(7-switch_name_list_return[ch].txt_len/2)*8,*loads_display_loads_ch_Y[i]+Y_loads_nane_offset,\
				//switch_name_list_return[ch].txt,0xFF82c2ff,0,1,1);
				Virtual_LCD_Draw_Rectangle_ARGB32(get_str_align_center_x_val(*loads_display_loads_ch_X[i]+X_loads_nane_offset,(char*)&switch_name_list_return[ch].txt,glyph_dsc_16_4bit),*loads_display_loads_ch_Y[i]+Y_loads_nane_offset,\
				h,16,Virtual_LCDbuff1,ARGB_white);


}
	

}













#endif
BOOL page_loads_motors_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
  if(page_home.page_left_side.now_item == LEFT_SIDE_PAGE_LOADS)
	{
			/*//if(p2->now_item == TOP_SIDE_PAGE_AC_CLIMATE)
			{
						  if(f_loads_b_setup_d)
							{
								 //if(*i==0)  *i=10;
							   //else 
								if(*i==31)return TRUE;
							
							}
							else
							{
								 if(*i==10)  *i=30;
							   //if(*i==30)return TRUE;
							}
			}*/
	}

	return FALSE;

}
///////////////////////≥ı ºªØ////////////////////////////////////////


u8 loads_motor_u_ico_select_p[MAX_LOADS_MOTORS_DIAPLAY_NUM] = {0,1};
u8 loads_motor_u_ico_select_ch = 0;


lcd_dis_item_t *loads_motor_u_ico_select_list[3]=
{
	&t_Motors_Awning_ico_u,
  &t_Motors_Curtain_ico_u,
  &t_Motors_Expansion_ico_u,

	
};

lcd_dis_item_t *loads_motor_u_ico_list[MAX_LOADS_MOTORS_DIAPLAY_NUM]=
{
	&t_Motors_Awning_ico_u,
	&t_Motors_Awning_ico_u,
	
};
void init_loads_motors_ico_para(void)
{
u8 i;
 
	 	
	for(i=0;i<MAX_LOADS_MOTORS_DIAPLAY_NUM;i++)
	{
		
		 loads_motor_u_ico_select_p[i] = switch_name_list_return[loads_display_motors_ch[i]].icon_select;
		 loads_motor_u_ico_list[i] = loads_motor_u_ico_select_list[loads_motor_u_ico_select_p[i]];
//	   sysprintf("\r\n------------%d %d",loads_load_d_ico_select_p[i],loads_display_loads_ch[i]);	
	}


	 memcpy(&t_loads_motors_u_ico0,loads_motor_u_ico_list[0],sizeof(lcd_dis_item_t));
	 memcpy(&t_loads_motors_u_ico1,loads_motor_u_ico_list[1],sizeof(lcd_dis_item_t));
	

	 t_loads_motors_u_ico0.f = &func_loads_motors_u_ico0;
	 t_loads_motors_u_ico1.f = &func_loads_motors_u_ico1;

	 
   t_loads_motors_u_ico0.x_val     = t_load_motobtn0_u.x_val    +t_loads_motors_u_ico0.x_val;
	 t_loads_motors_u_ico0.y_val     = t_load_motobtn0_u.y_val    +t_loads_motors_u_ico0.y_val;
	 t_loads_motors_u_ico0.x_end_val = t_load_motobtn0_u.x_val+t_loads_motors_u_ico0.x_end_val;
	 t_loads_motors_u_ico0.y_end_val = t_load_motobtn0_u.y_val+t_loads_motors_u_ico0.y_end_val;
	 
	 t_loads_motors_u_ico1.x_val     = t_load_motobtn1_u.x_val    +t_loads_motors_u_ico1.x_val;
	 t_loads_motors_u_ico1.y_val     = t_load_motobtn1_u.y_val    +t_loads_motors_u_ico1.y_val;
	 t_loads_motors_u_ico1.x_end_val = t_load_motobtn1_u.x_val+t_loads_motors_u_ico1.x_end_val;
	 t_loads_motors_u_ico1.y_end_val = t_load_motobtn1_u.y_val+t_loads_motors_u_ico1.y_end_val;
	
	
	 
	 t_load_motobtn_touch0_d.x_val     = t_loads_motors_u_ico0.x_val;
	 t_load_motobtn_touch0_d.y_val     = t_loads_motors_u_ico0.y_val;
	 t_load_motobtn_touch0_d.x_end_val = t_loads_motors_u_ico0.x_end_val;
	 t_load_motobtn_touch0_d.y_end_val = t_loads_motors_u_ico0.y_end_val;
	 
	 t_load_motobtn_touch1_d.x_val     = t_loads_motors_u_ico1.x_val;
	 t_load_motobtn_touch1_d.y_val     = t_loads_motors_u_ico1.y_val;
	 t_load_motobtn_touch1_d.x_end_val = t_loads_motors_u_ico1.x_end_val;
	 t_load_motobtn_touch1_d.y_end_val = t_loads_motors_u_ico1.y_end_val;
	 
	 t_loads_motors_u_ico0.key_type = KEY_TYPE_LONG_PRESS;
   t_loads_motors_u_ico1.key_type = KEY_TYPE_LONG_PRESS;

}

void ui_loads_motors_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_LOADS][TOP_SIDE_PAGE_LOADS_MOTORS];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=LOADS_MOTORS_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only



   t_load_motobtn0_u.key_type = KEY_TYPE_TOUCH_NONE;
   t_load_motobtn1_u.key_type = KEY_TYPE_TOUCH_NONE;


   init_loads_motors_ico_para();
   p->item = loads_motors_item;
   for(i=0;i<LOADS_MOTORS_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_loads_motors_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_loads_motors_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_loads_motors_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	set_loads_motors_item_key_type(KEY_TYPE_NORMAL);
 }


