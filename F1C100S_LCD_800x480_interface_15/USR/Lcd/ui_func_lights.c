#include "includes.h"


void func_lights_b_lights_d(void* p,u8 sn)
{

}



void func_lights_b_lights_u(void* p,u8 sn)
{

}



void func_lights_scrollbar_bg_all(void* p,u8 sn,u32 X_val_bg,u8 ch)//¸ù¾Ýx×ø±ê ,ch£ºÍ¨µÀ£¬»¬¶¯Ìõ(¿Õ)»Øµ÷º¯Êýµ÷ÓÃ
{	
	//u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    //22£º»¬¿é¿í¶È£¬162:»¬¶¯±³¾°¿í¶È
    //ch£ºÍ¨µÀ
       //X_val_bg£º¿Õ½ø¶È×ø±êx£¬ch£ºÍ¨µÀ£¬

	if(slide_x<(X_val_bg+22))//Ð¡ÓÚ·¶Î§
			pwm_ctrl_byte[ch] = 1;//pwm duty 1
  else if(slide_x>(X_val_bg+162-22))//³¬³ö·¶Î§
			pwm_ctrl_byte[ch] = PWM_CTRL_MAX_VAL;//pwm duty 100
  else
		pwm_ctrl_byte[ch] = (slide_x-X_val_bg-22)*PWM_CTRL_MAX_VAL/(162-44);
		
	if(pwm_ctrl_byte[ch]<PWM_CTRL_MIN_VAL)//pwm duty 5£¬£¬×îÐ¡ÁÁ¶È
		 pwm_ctrl_byte[ch]= PWM_CTRL_MIN_VAL;
	send_FlC200_swtich_cmd(0x30+ch,pwm_ctrl_byte[ch]);//Ð­Òé·¢ËÍ
	disply_pwm_status(ch,FALSE);//ÏÔÊ¾»¬¶¯Ìõ
}


void func_RGB_scrollbar_bg_all2(void* p,u8 sn,u32 X_val_bg,u8 ch)//¸ù¾Ýx×ø±ê ,»¬¶¯Ìõ»Øµ÷º¯Êýµ÷ÓÃ£¬¼ÆËãÕ¼¿Õ±È
{	
	//u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    //22£º»¬¿é¿í¶È£¬162:»¬¶¯±³¾°¿í¶È
    //ch£ºÍ¨µÀ
   //X_val_bg£º¿Õ½ø¶È×ø±êx£¬ch£ºÍ¨µÀ£¬
	if(slide_x<(X_val_bg+38))//Ð¡ÓÚ·¶Î§
			pwm_ctrl_byte[ch] = 1;//pwm duty 1
  else if(slide_x>(X_val_bg+298-38))//³¬³ö·¶Î§
			pwm_ctrl_byte[ch] = PWM_CTRL_MAX_VAL;//pwm duty 100
  else
		pwm_ctrl_byte[ch] = (slide_x-X_val_bg-38)*PWM_CTRL_MAX_VAL/(298-38*2);
		
	if(pwm_ctrl_byte[ch]<PWM_CTRL_MIN_VAL)//pwm duty 5£¬£¬×îÐ¡ÁÁ¶È
		 pwm_ctrl_byte[ch]= PWM_CTRL_MIN_VAL;
	send_FlC200_swtich_cmd(0x30+ch,pwm_ctrl_byte[ch]);//Ð­Òé·¢ËÍ
	disply_pwm_status(ch,FALSE);//ÏÔÊ¾»¬¶¯Ìõ
}


void func_lights_scrollbar_bg(void* p,u8 sn)
{	
	//u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
/*
	if(slide_x<(X_lights_scrollbar_bg+22))
			pwm_ctrl_byte[0] = 1;
  else if(slide_x>(X_lights_scrollbar_bg+162-22))
			pwm_ctrl_byte[0] = PWM_CTRL_MAX_VAL;
  else
		pwm_ctrl_byte[0] = (slide_x-X_lights_scrollbar_bg-22)*PWM_CTRL_MAX_VAL/(162-44);
		
	if(pwm_ctrl_byte[0]<PWM_CTRL_MIN_VAL)
		 pwm_ctrl_byte[0]= PWM_CTRL_MIN_VAL;
	send_FlC200_swtich_cmd(0x30,pwm_ctrl_byte[0]);//
	disply_pwm_status(LIGHT_PWM0,FALSE);*/
	
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar_bg,LIGHT_PWM0);
}
void func_lights_scrollbar1_bg(void* p,u8 sn)
{
	//u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	/*if(slide_x<(X_lights_scrollbar1_bg+22))
			pwm_ctrl_byte[1] = 1;
  else if(slide_x>(X_lights_scrollbar1_bg+162-22))
			pwm_ctrl_byte[1] = PWM_CTRL_MAX_VAL;
  else
		pwm_ctrl_byte[1] = (slide_x-X_lights_scrollbar1_bg-22)*PWM_CTRL_MAX_VAL/(162-44);
	
	if(pwm_ctrl_byte[1]<PWM_CTRL_MIN_VAL)
		 pwm_ctrl_byte[1]= PWM_CTRL_MIN_VAL;
		send_FlC200_swtich_cmd(0x31,pwm_ctrl_byte[1]);//
		disply_pwm_status(LIGHT_PWM1,FALSE);*/
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar1_bg,LIGHT_PWM1);

}
void func_lights_scrollbar2_bg(void* p,u8 sn)
{
	//u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	/*if(slide_x<(X_lights_scrollbar2_bg+22))
			pwm_ctrl_byte[2] = 1;
  else if(slide_x>(X_lights_scrollbar2_bg+162-22))
			pwm_ctrl_byte[2] = PWM_CTRL_MAX_VAL;
  else
		pwm_ctrl_byte[2] = (slide_x-X_lights_scrollbar2_bg-22)*PWM_CTRL_MAX_VAL/(162-44);
	
	if(pwm_ctrl_byte[2]<PWM_CTRL_MIN_VAL)
		 pwm_ctrl_byte[2]= PWM_CTRL_MIN_VAL;
		send_FlC200_swtich_cmd(0x32,pwm_ctrl_byte[2]);//
		disply_pwm_status(LIGHT_PWM2,FALSE);
*/
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar2_bg,LIGHT_PWM2);
}
void func_lights_scrollbar3_bg(void* p,u8 sn)
{
	//u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  //  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	/*	if(slide_x<(X_lights_scrollbar3_bg+22))
			pwm_ctrl_byte[3] = 1;
  else if(slide_x>(X_lights_scrollbar3_bg+162-22))
			pwm_ctrl_byte[3] = PWM_CTRL_MAX_VAL;
  else
		pwm_ctrl_byte[3] = (slide_x-X_lights_scrollbar3_bg-22)*PWM_CTRL_MAX_VAL/(162-44);
	
	if(pwm_ctrl_byte[3]<PWM_CTRL_MIN_VAL)
		 pwm_ctrl_byte[3]= PWM_CTRL_MIN_VAL;
		send_FlC200_swtich_cmd(0x33,pwm_ctrl_byte[3]);//
		disply_pwm_status(LIGHT_PWM3,FALSE);*/
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar3_bg,LIGHT_PWM3);

}

void func_lights_scrollbar4_bg(void* p,u8 sn)
{
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar4_bg,LIGHT_PWM4);

}

void func_lights_scrollbar5_bg(void* p,u8 sn)
{
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar5_bg,LIGHT_PWM5);

}

void func_lights_scrollbar6_bg(void* p,u8 sn)
{
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar6_bg,LIGHT_PWM6);
}

void func_lights_scrollbar7_bg(void* p,u8 sn)
{
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar7_bg,LIGHT_PWM7);

}

void func_lights_scrollbar8_bg(void* p,u8 sn)
{
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar8_bg,LIGHT_PWM8);

}

void func_lights_scrollbar9_bg(void* p,u8 sn)
{
	func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar9_bg,LIGHT_PWM9);

}



void func_lights_scrollbar_slider(void* p,u8 sn)
{

}
void func_lights_scrollbar1_slider(void* p,u8 sn)
{

}
void func_lights_scrollbar2_slider(void* p,u8 sn)
{

}
void func_lights_scrollbar3_slider(void* p,u8 sn)
{

}

void func_lights_scrollbar4_slider(void* p,u8 sn)
{

}

void func_lights_scrollbar5_slider(void* p,u8 sn)
{

}

void func_lights_scrollbar6_slider(void* p,u8 sn)
{

}

void func_lights_scrollbar7_slider(void* p,u8 sn)
{

}

void func_lights_scrollbar8_slider(void* p,u8 sn)
{

}

void func_lights_scrollbar9_slider(void* p,u8 sn)
{

}



void func_lights_scrollbar_100(void* p,u8 sn)
{

}

void func_lights_scrollbar1_100(void* p,u8 sn)
{

}
void func_lights_scrollbar2_100(void* p,u8 sn)
{

}
void func_lights_scrollbar3_100(void* p,u8 sn)
{

}

void func_lights_scrollbar4_100(void* p,u8 sn)
{

}
void func_lights_scrollbar5_100(void* p,u8 sn)
{

}
void func_lights_scrollbar6_100(void* p,u8 sn)
{

}
void func_lights_scrollbar7_100(void* p,u8 sn)
{

}
void func_lights_scrollbar8_100(void* p,u8 sn)
{

}
void func_lights_scrollbar9_100(void* p,u8 sn)
{

}





void func_light_awning_ico_d(void* p,u8 sn)
{

}



void func_light_awning_ico_u(void* p,u8 sn)
{

}



void func_light_interior_ico_d(void* p,u8 sn)
{

}



void func_light_interior_ico_u(void* p,u8 sn)
{

}



void func_light_pendant_ico_d(void* p,u8 sn)
{

}



void func_light_pendant_ico_u(void* p,u8 sn)
{

}



void func_light_rearside_d(void* p,u8 sn)
{

}



void func_light_rearside_u(void* p,u8 sn)
{

}



void func_light_rearwork_ico_d(void* p,u8 sn)
{

}



void func_light_rearwork_ico_u(void* p,u8 sn)
{

}



void func_light_underbody_ico_d(void* p,u8 sn)
{

}



void func_light_underbody_ico_u(void* p,u8 sn)
{

}





void func_light_mainbtn0_d(void* p,u8 sn)
{

}



void func_light_mainbtn0_u(void* p,u8 sn)
{

}


extern lcd_dis_item_t *p_lights_lights_item_d[];
void func_light_mainbtn1_d(void* p,u8 sn)
{
 /* u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
	   
	}
	else  if(p1->item[SN].now_status==STATUS_IDLE)
	{
	
	  if(p_lights_lights_item_d[1]->now_status ==STATUS_SELECT)
			 p_lights_lights_item_d[1]->now_status =STATUS_IDLE;
			 else
				 p_lights_lights_item_d[1]->now_status =STATUS_SELECT;
	}*/
}



void func_light_mainbtn1_u(void* p,u8 sn)
{

}



void func_light_mainbtn2_d(void* p,u8 sn)
{

}



void func_light_mainbtn2_u(void* p,u8 sn)
{

}



void func_light_mainbtn3_d(void* p,u8 sn)
{

}



void func_light_mainbtn3_u(void* p,u8 sn)
{

}



void func_light_mainbtn4_d(void* p,u8 sn)
{

}



void func_light_mainbtn4_u(void* p,u8 sn)
{

}


void func_light_mainbtn5_d(void* p,u8 sn)
{

}



void func_light_mainbtn5_u(void* p,u8 sn)
{

}



void func_light_mainbtn6_d(void* p,u8 sn)
{

}



void func_light_mainbtn6_u(void* p,u8 sn)
{

}



void func_light_mainbtn7_d(void* p,u8 sn)
{

}



void func_light_mainbtn7_u(void* p,u8 sn)
{

}



void func_light_mainbtn8_d(void* p,u8 sn)
{

}



void func_light_mainbtn8_u(void* p,u8 sn)
{

}



void func_light_mainbtn9_d(void* p,u8 sn)
{

}



void func_light_mainbtn9_u(void* p,u8 sn)
{

}





void func_light_mainbtn_touch_d(void* p,u8 sn,u8 sel_ch)
{
  u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	

	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		
		  
		if(Y_touch_now>(((p1->item[SN].y_end_val-p1->item[SN].y_val)*2)/3+p1->item[SN].y_val))
		{
			if(sel_ch>=4)
				char_input_target_type = sel_ch+5;
			else
		 	char_input_target_type = sel_ch;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);			
			disply_lights_light_name_bg(sel_ch,TRUE);
			ui_disply_keyboard(FALSE);
		}
		else
		{
			lights_light_d_ico_select_ch = sel_ch;
		  now_dialog_lights_ch_select_ch = sel_ch;
			f_need_ui_disply_dialog_lights = TRUE;
			
		
		}

			if(p1->item[SN].last_status==STATUS_TOUCH_ON_IDLE)
			{
			  p1->item[SN].now_status=STATUS_IDLE;
			}
			else
			{
			 p1->item[SN].now_status=STATUS_SELECT;
			}
		
	}
	else if(p1->item[SN].now_status==STATUS_SELECT)
	{
	   if(p_lights_lights_item_d[sel_ch]->now_status ==STATUS_SELECT)
		 {
			 p_lights_lights_item_d[sel_ch]->now_status =STATUS_IDLE;				 
		  }
			else if(p_lights_lights_item_d[sel_ch]->now_status ==STATUS_IDLE)
		 {
			 if(p_lights_lights_item_d[sel_ch]->key_type !=KEY_TYPE_TOUCH_AND_DISPLAY_NONE)
				 p_lights_lights_item_d[sel_ch]->now_status =STATUS_SELECT;
		 }
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
	  if(p_lights_lights_item_d[sel_ch]->now_status ==STATUS_SELECT)
		{
			 p_lights_lights_item_d[sel_ch]->now_status =STATUS_IDLE;

		}
		else if(p_lights_lights_item_d[sel_ch]->now_status ==STATUS_IDLE)
		{
			if(p_lights_lights_item_d[sel_ch]->key_type !=KEY_TYPE_TOUCH_AND_DISPLAY_NONE)
			p_lights_lights_item_d[sel_ch]->now_status =STATUS_SELECT;
		}
	}
	
}


void func_light_mainbtn_touch10_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,0);
	
}
void func_light_mainbtn_touch11_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,1);
}
void func_light_mainbtn_touch12_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,2);
}
void func_light_mainbtn_touch13_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,3);
}
void func_light_mainbtn_touch14_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,4);
}

void func_light_mainbtn_touch20_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,5);
}
void func_light_mainbtn_touch21_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,6);
}
void func_light_mainbtn_touch22_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,7);
}
void func_light_mainbtn_touch23_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,8);
}
void func_light_mainbtn_touch24_d(void* p,u8 sn)
{
  func_light_mainbtn_touch_d(p,sn,9);
}





////////////////////////////////////////////////////








void func_light_pendant_ico0_deel(void* p,u8 sn,u8 sel_ch,u8 send_cmd)
{
	u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_lights_b_setup_d)
		{	
      //now_dialog_lights_ch_select_ch = sel_ch;
      //ui_disply_dialog_lights_ch();	
			if(p1->item[SN].last_status==STATUS_TOUCH_ON_IDLE)
			{
			  p1->item[SN].now_status=STATUS_IDLE;
			}
			else
			{
			 p1->item[SN].now_status=STATUS_SELECT;
			}
		}
		else
		{		 

      //sysprintf("\r\n last:%d",p1->item[SN].last_status);			
			 if(p1->item[SN].last_status==STATUS_TOUCH_ON_IDLE)
			 {
				 p1->item[SN].now_status=STATUS_SELECT; 
				 send_FlC200_swtich_cmd(send_cmd,1);//
		     disply_lights_light_name(TRUE);
				 disply_lights_light_ch_name(TRUE);
				 disply_lights_current_val(TRUE);
			 }
			 else
			 {
				 p1->item[SN].now_status=STATUS_IDLE; 
				 send_FlC200_swtich_cmd(send_cmd,0);//
		      disply_lights_light_name(TRUE);
				 disply_lights_light_ch_name(TRUE);
				 disply_lights_current_val(TRUE);
			 }
		}
		
	}
	else 	if(p1->item[SN].now_status==STATUS_SELECT)
	{   
    if(f_lights_b_setup_d)
		{
			
			if(p1->item[SN].last_status!=STATUS_SELECT)
			{
			  lights_light_d_ico_select_ch = sel_ch;
				now_dialog_lights_ch_select_ch = sel_ch;
			  f_need_ui_disply_dialog_lights = TRUE;//ui_disply_dialog_lights();	
				p1->item[SN].now_status=STATUS_IDLE;
			}
			
			
			// p1->item[SN].last_status=STATUS_IDLE;
		}
		else
		{
		  send_FlC200_swtich_cmd(send_cmd,1);//
		  disply_lights_light_name(TRUE);
			disply_lights_light_ch_name(TRUE);
			disply_lights_current_val(TRUE);
			//sysprintf("\r\n************88a");
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_lights_b_setup_d)
		{
			
			if(p1->item[SN].last_status!=STATUS_IDLE)
			{
			  lights_light_d_ico_select_ch = sel_ch;
				now_dialog_lights_ch_select_ch = sel_ch;
			  f_need_ui_disply_dialog_lights = TRUE;//ui_disply_dialog_lights();		
       
			
			 p1->item[SN].now_status=STATUS_SELECT;
			}
			// p1->item[SN].last_status=STATUS_IDLE;
		}
		else
		{
     send_FlC200_swtich_cmd(send_cmd,0);//
		 disply_lights_light_ch_name(TRUE);
		 disply_lights_light_name(TRUE);
			disply_lights_current_val(TRUE);
			//sysprintf("\r\n************88b");
		}
	}
}














void func_light_pendant_ico0_d(void* p,u8 sn)
{	
	func_light_pendant_ico0_deel(p,sn,0,0x00);
}



void func_light_pendant_ico0_u(void* p,u8 sn)
{

}
void func_light_pendant_ico1_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,1,0x01);
	
}



void func_light_pendant_ico1_u(void* p,u8 sn)
{

}
void func_light_pendant_ico2_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,2,0x02);
	
}



void func_light_pendant_ico2_u(void* p,u8 sn)
{

}
void func_light_pendant_ico3_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,3,0x03);
	
}



void func_light_pendant_ico3_u(void* p,u8 sn)
{

}
void func_light_pendant_ico4_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,4,0x09);
}



void func_light_pendant_ico4_u(void* p,u8 sn)
{

}
void func_light_pendant_ico5_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,5,0x0A);	
}



void func_light_pendant_ico5_u(void* p,u8 sn)
{

}
void func_light_pendant_ico6_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,6,0x0B);
	
}



void func_light_pendant_ico6_u(void* p,u8 sn)
{

}
void func_light_pendant_ico7_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,7,0x0C);
	
}



void func_light_pendant_ico7_u(void* p,u8 sn)
{

}
void func_light_pendant_ico8_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,8,0x0D);
	
}



void func_light_pendant_ico8_u(void* p,u8 sn)
{

}

void func_light_pendant_ico9_d(void* p,u8 sn)
{
	func_light_pendant_ico0_deel(p,sn,9,0x0E);
	
}



void func_light_pendant_ico9_u(void* p,u8 sn)
{

}



void func_lights_light_ico_char0_d(void* p,u8 sn)
{
	

  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_lights_b_setup_d)
		{
			char_input_target_type = 0;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(0,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}

void func_lights_light_ico_char1_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_lights_b_setup_d)
		{
			char_input_target_type = 1;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(1,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_lights_light_ico_char2_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 if(f_lights_b_setup_d)
		{
			char_input_target_type = 2;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(2,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_lights_light_ico_char3_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 if(f_lights_b_setup_d)
		{
			char_input_target_type = 3;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(3,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_lights_light_ico_char4_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
	   if(f_lights_b_setup_d)
		{
			char_input_target_type = 9;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(4,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_lights_light_ico_char5_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 if(f_lights_b_setup_d)
		{
			char_input_target_type = 10;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(5,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_lights_light_ico_char6_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 if(f_lights_b_setup_d)
		{
			char_input_target_type = 11;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(6,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_lights_light_ico_char7_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 if(f_lights_b_setup_d)
		{
			char_input_target_type = 12;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(7,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_lights_light_ico_char8_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		 if(f_lights_b_setup_d)
		{
			char_input_target_type = 13;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(8,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_lights_light_ico_char9_d(void* p,u8 sn)
{
  	u8 SN = sn;//í?±ê?úµ±?°ò3??áD±íµ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_lights_b_setup_d)
		{
			char_input_target_type = 14;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
			
			disply_lights_light_name_bg(9,TRUE);
			ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}













void func_lights_b_setup_d(void* p,u8 sn)
{
	u8 SN = sn;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	//u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
     f_lights_b_setup_d = TRUE;
		 set_lights_item_key_type(KEY_TYPE_LONG_PRESS);
//		 set_lights_item_bnt_type(KEY_TYPE_TOUCH_NONE);

		 //disply_lights_light_ch_name(FALSE);
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
     f_lights_b_setup_d = FALSE;
		 set_lights_item_key_type(KEY_TYPE_NORMAL);
//	   set_lights_item_bnt_type(KEY_TYPE_ONCE);
		 set_home_lights_item_key_type();
		 //disply_lights_light_ch_name(FALSE);
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;
	}
	

}



void func_lights_b_setup_u(void* p,u8 sn)
{

}
void func_lights_b_setup_f(void* p,u8 sn)
{

}
