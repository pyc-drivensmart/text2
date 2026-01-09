#include "includes.h"



bool f_ui_disply_keyboard = FALSE;
bool f_ui_out_keyboard = FALSE;

bool f_ui_new_input_code = FALSE;
bool f_ui_new_input_bat_capacity = FALSE;
bool f_ui_new_input_bat_percenage = FALSE;
bool f_ui_new_input_code_enter = FALSE;


	//keyboard
lcd_dis_item_t *p_keyboard_item_d[KEYBOARD_ICO_NUM]=
{
&t_keyboard_bg,//0
&t_keyboard_delete_d,//1
&t_keyboard_enter_d,//2
&t_keyboard_lock_d,//3
&t_keyboard_num_d,//4
&t_keyboard_space_d,//5



&t_keyboard_b_d,
&t_keyboard_c_d,
&t_keyboard_d_d,
&t_keyboard_f_d,
&t_keyboard_g_d,
&t_keyboard_h_d,
&t_keyboard_j_d,
&t_keyboard_k_d,
&t_keyboard_l_d,

&t_keyboard_n_d,
&t_keyboard_s_d,
&t_keyboard_v_d,
&t_keyboard_x_d,
&t_keyboard_z_d,
&t_keyboard_a_d,//20
&t_keyboard_m_d,

&t_keyboard_e_d,
&t_keyboard_i_d,
&t_keyboard_o_d,
&t_keyboard_p_d,//25
&t_keyboard_q_d,
&t_keyboard_r_d,
&t_keyboard_t_d,
&t_keyboard_u_d,
&t_keyboard_y_d,//30
&t_keyboard_w_d,



&t_keyboard_a1_d,//32
&t_keyboard_b1_d,
&t_keyboard_c1_d,
&t_keyboard_d1_d,//35
&t_keyboard_f1_d,
&t_keyboard_g1_d,
&t_keyboard_h1_d,
&t_keyboard_j1_d,
&t_keyboard_k1_d,//40
&t_keyboard_l1_d,
&t_keyboard_m1_d,
&t_keyboard_n1_d,
&t_keyboard_s1_d,
&t_keyboard_v1_d,//45
&t_keyboard_x1_d,
&t_keyboard_z1_d,


&t_keyboard_e1_d,
&t_keyboard_i1_d,
&t_keyboard_o1_d,//50
&t_keyboard_p1_d,
&t_keyboard_q1_d,
&t_keyboard_r1_d,
&t_keyboard_t1_d,
&t_keyboard_u1_d,//55
&t_keyboard_y1_d,
&t_keyboard_w1_d,



&t_keyboard_0_d,//58
&t_keyboard_1_d,
&t_keyboard_2_d,///60
&t_keyboard_3_d,
&t_keyboard_4_d,
&t_keyboard_5_d,
&t_keyboard_6_d,
&t_keyboard_7_d,//65
&t_keyboard_8_d,
&t_keyboard_9_d,//67
&t_keyboard_symbol1_d,//68
&t_keyboard_symbol2_d,//69
};

//
lcd_dis_item_t *p_keyboard_item_u[KEYBOARD_ICO_NUM]=
{
&t_keyboard_bg,//0
&t_keyboard_delete_u,//1
&t_keyboard_enter_u,//2
&t_keyboard_lock_u,//3
&t_keyboard_num_u,//4
&t_keyboard_space_u,//5



&t_keyboard_b_u,
&t_keyboard_c_u,
&t_keyboard_d_u,
&t_keyboard_f_u,
&t_keyboard_g_u,
&t_keyboard_h_u,
&t_keyboard_j_u,
&t_keyboard_k_u,
&t_keyboard_l_u,

&t_keyboard_n_u,
&t_keyboard_s_u,
&t_keyboard_v_u,
&t_keyboard_x_u,
&t_keyboard_z_u,

&t_keyboard_a_u,//20
&t_keyboard_m_u,

&t_keyboard_e_u,
&t_keyboard_i_u,
&t_keyboard_o_u,
&t_keyboard_p_u,//25
&t_keyboard_q_u,
&t_keyboard_r_u,
&t_keyboard_t_u,
&t_keyboard_u_u,
&t_keyboard_y_u,//30
&t_keyboard_w_u,



&t_keyboard_a1_u,//32
&t_keyboard_b1_u,
&t_keyboard_c1_u,
&t_keyboard_d1_u,//35
&t_keyboard_f1_u,
&t_keyboard_g1_u,
&t_keyboard_h1_u,
&t_keyboard_j1_u,
&t_keyboard_k1_u,//40
&t_keyboard_l1_u,
&t_keyboard_m1_u,
&t_keyboard_n1_u,
&t_keyboard_s1_u,
&t_keyboard_v1_u,//45
&t_keyboard_x1_u,
&t_keyboard_z1_u,


&t_keyboard_e1_u,
&t_keyboard_i1_u,
&t_keyboard_o1_u,//50
&t_keyboard_p1_u,
&t_keyboard_q1_u,
&t_keyboard_r1_u,
&t_keyboard_t1_u,
&t_keyboard_u1_u,//55
&t_keyboard_y1_u,
&t_keyboard_w1_u,



&t_keyboard_0_u,//58
&t_keyboard_1_u,
&t_keyboard_2_u,///60
&t_keyboard_3_u,
&t_keyboard_4_u,
&t_keyboard_5_u,
&t_keyboard_6_u,
&t_keyboard_7_u,//65
&t_keyboard_8_u,
&t_keyboard_9_u,//67
&t_keyboard_symbol1_u,//68
&t_keyboard_symbol2_u,//69



};

lcd_dis_item_t keyboard_item[KEYBOARD_ICO_NUM];




KEYBOARD_PAGE keyboard_ui_step = KEYBOARD_PAGE_NOR;






BOOL page_keyboard_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
  if(f_ui_disply_keyboard)
	{

			if(keyboard_ui_step==KEYBOARD_PAGE_NOR)
			{
					if(*i==32)return TRUE;
							
			}
			else if(keyboard_ui_step==KEYBOARD_PAGE_CAPS)
			{
					if(*i==6)*i=32;
					if(*i==58)return TRUE;
			}
			else if(keyboard_ui_step==KEYBOARD_PAGE_NUM)
			{
					if(*i==20)*i=58;
					//if(*i==58)return TRUE;
			}

	}
	else
		return TRUE;

	return FALSE;

}
u16 *val_input_target_p;//输入目标数组
u16 *val_input_target_p2;//输入目标数组
SWITCH_NAME_LIST *char_input_target_p;//输入目标数组
SWITCH_NAME_LIST *char_input_target_p2;//输入目标数组
u8 char_input_target_type =0;
u8 keyboard_val_limit_type = 0;
char char_input_buf[22];
u8 char_input_len = 0;
u8 val_limit_type = 0;//0不限制，1:(max100)
void disply_char_input_val(bool upgrade)
{
	// if(upgrade)
   //Virtual_LCD_Draw_String_ARGB_16_4bit(X_home_POWsc_d+10,Y_home_POWsc_d+55,"        --W/--A",ARGB_mygreen,0,1,1);
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
		
		Virtual_LCD_Draw_Rectangle_ARGB32(400,320,600,64,Virtual_LCDbuff2,ARGB_clear);
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
		
					
		
		Virtual_LCD_Draw_String_ARGB_24_4bit(512-12*(last_char_input_len/2)-(last_char_input_len%2)*6,320,char_input_buf,ARGB_white,0,1,1);
		
		
		if(keyboard_val_limit_type==1)	
		{
			sprintf(display_buf,"(Max100)");
			Virtual_LCD_Draw_String_ARGB_24_4bit(800,320,display_buf,ARGB_white,0,1,1);
		
		}
		else if(keyboard_val_limit_type==2)	
		{
			sprintf(display_buf,"(Max999)");
			Virtual_LCD_Draw_String_ARGB_24_4bit(800,320,display_buf,ARGB_white,0,1,1);
		
		}
		else if(keyboard_val_limit_type==3)	
		{
			sprintf(display_buf,"(Max5000)");
			Virtual_LCD_Draw_String_ARGB_24_4bit(800,320,display_buf,ARGB_white,0,1,1);
		
		}
		else if(keyboard_val_limit_type==4)	
		{
			sprintf(display_buf,"(Max50)");
			Virtual_LCD_Draw_String_ARGB_24_4bit(800,320,display_buf,ARGB_white,0,1,1);
		
		}
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(400,320,600,64);
	}
}

void Set_char_input_target_p(SWITCH_NAME_LIST *p,SWITCH_NAME_LIST *p2)
{
	char_input_target_p = p;
	char_input_target_p2 = p2;
}


void Write_char_input_target(char *p,u8 len)
{
	u8 i;
	u8 code[]="95279527";
	
	for(i=0;i<8;i++)
	{
	  if(code[i] != p[i])
		{
			break;
		}
		else if(i==7)
		{
			 if(len==8)
			 {
		     f_disply_debug_val = TRUE;
				 send_FlC200_base_set_cmd(0x82,1,0);
			   return;
			 }
				 
				 
		
		}
		
	}
	
	for(i=0;i<len;i++)
	{
	  char_input_target_p->txt[i] = p[i];
		char_input_target_p2->txt[i] = p[i];
	}//return;
	//sysprintf("\r\nrrrrrrrrrrrrrrrrrrrrr%d",len);
	char_input_target_p->txt[i] = '\0';
	char_input_target_p2->txt[i] = '\0';
	char_input_target_p->txt_len = len+1;
	char_input_target_p2->txt_len = len+1;	

	//sysprintf("\r\nrrrrrrrrrrrrrrrrrrrrr%d",char_input_target_p->txt_len);
	//sysprintf("\r\nrrrrrrrrrrrrrrrrrrrrr%d",char_input_target_p2->txt_len);
	
	send_FlC200_swtich_name_cmd(char_input_target_type);
}


void Set_val_input_target_p(u16 *p,u16 *p2)
{
	val_input_target_p = p;
	val_input_target_p2 = p2;
}
bool limit_val_input_target(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	bool f_get_minus = FALSE;
	
	val_temp = 0;
	for(i=0;i<len;i++)
	{
		if(((char_input_target_type==12)||(char_input_target_type==13)))
		{
			if(p[i]=='-')
			{
			  f_get_minus = TRUE;
				val_temp = 0;
			}
			else
			{
			   val_temp*=10;
	       val_temp += p[i]-0x30;
			}
		}
		else
		{
			if(p[i]=='-')
			{
			  return TRUE;
			}
			if(p[i]!='.')
			{
				val_temp*=10;
				val_temp += p[i]-0x30;
			}
		}

	}//return;
	//sysprintf("\r\nrrrrrrrrrrrrrrrrrrrrr%d",len);
	if(((char_input_target_type==12)||(char_input_target_type==13)))
	{
		
		  if((base_return_status.uint&0x0C)==0x04)//F
			{
			   
				if(f_get_minus==FALSE)
				{
						val_temp +=80;
					 if((val_temp)>255)
						 val_temp = 255;
					 
					 *val_input_target_p  = val_temp;
					 *val_input_target_p2  = val_temp;
				}
				else
				{
				
					 
					 if((val_temp)>80)
						 val_temp = 80;
					 
					 val_temp = 80-val_temp;
					 *val_input_target_p  = val_temp;
					 *val_input_target_p2  = val_temp;
				
				}
			}
			else
			{
				if(f_get_minus==FALSE)
				{
						val_temp +=80;
					 if((val_temp)>255)
						 val_temp = 255;
					 
					 *val_input_target_p  = val_temp;
					 *val_input_target_p2  = val_temp;
				}
				else
				{
				
					 
					 if((val_temp)>80)
						 val_temp = 80;
					 
					 val_temp = 80-val_temp;
					 *val_input_target_p  = val_temp;
					 *val_input_target_p2  = val_temp;
				
				}
		}
		 
	}
	else
  {
     if(val_temp>999)
		 {
			return TRUE;
		 }
	}

  return FALSE;
}
void Write_val_input_target(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	bool f_get_minus = FALSE;
	
	val_temp = 0;
	for(i=0;i<len;i++)
	{
		if(((char_input_target_type==12)||(char_input_target_type==13)))
		{
			if(p[i]=='-')
			{
			  f_get_minus = TRUE;
				val_temp = 0;
			}
			else
			{
			   val_temp*=10;
	       val_temp += p[i]-0x30;
			}
		}
		else
		{
			if(p[i]=='-')
			{
			  return;
			}
		  val_temp*=10;
	    val_temp += p[i]-0x30;
		}

	}//return;
	//sysprintf("\r\nrrrrrrrrrrrrrrrrrrrrr%d",len);
	if(((char_input_target_type==12)||(char_input_target_type==13)))
	{
		
		  if((base_return_status.uint&0x0C)==0x04)//F
			{
			   
				if(f_get_minus==FALSE)
				{
						val_temp +=80;
					 if((val_temp)>255)
						 val_temp = 255;
					 
					 *val_input_target_p  = val_temp;
					 *val_input_target_p2  = val_temp;
				}
				else
				{
				
					 
					 if((val_temp)>80)
						 val_temp = 80;
					 
					 val_temp = 80-val_temp;
					 *val_input_target_p  = val_temp;
					 *val_input_target_p2  = val_temp;
				
				}
			}
			else
			{
				if(f_get_minus==FALSE)
				{
						val_temp +=80;
					 if((val_temp)>255)
						 val_temp = 255;
					 
					 *val_input_target_p  = val_temp;
					 *val_input_target_p2  = val_temp;
				}
				else
				{
				
					 
					 if((val_temp)>80)
						 val_temp = 80;
					 
					 val_temp = 80-val_temp;
					 *val_input_target_p  = val_temp;
					 *val_input_target_p2  = val_temp;
				
				}
		}
		 
	}
	else
  {

	   *val_input_target_p  = val_temp;
	   *val_input_target_p2  = val_temp;	
		
	}


	
	//send_FlC200_set_cmd(tanks_set_send_id[char_input_target_type],val_temp);
	send_FlC200_set_cmd(tanks_now_set_send_id,val_temp);
}



bool limit_val_input_target_power(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	static bool f_break_next_time = FALSE;
	
	val_temp = 0;
	f_break_next_time = FALSE;
	for(i=0;i<len;i++)
	{
		if(p[i]=='.')
		{
			/* if((char_input_target_type==2)||(char_input_target_type==5)||(char_input_target_type==8))
			 {
				 break;
			 }
			 else*/
		   f_break_next_time = TRUE;
		}
		else
		{
			if((p[i]=='.')&&f_break_next_time)
			{
			}
			else
			{
		    val_temp*=10;
	      val_temp += p[i]-0x30;
			}
			if(f_break_next_time)
		  {
				 break;
			}
				
		}
	

	}
	if(char_input_target_type==1)//50 limit
		{
		   if(f_break_next_time==FALSE)
		   val_temp*=10;
			 else
			 {
			    if(val_temp==50)
					{
						if(f_break_next_time)
		      return TRUE;
					}
			 
			 }
				 
			 
			 if(val_temp>500)
				 return TRUE;
		}
		else if((char_input_target_type!=2)&&(char_input_target_type!=5)&&(char_input_target_type!=8))//100 limit
		{
		   if(f_break_next_time==FALSE)
		   val_temp*=10;
			 else
			 {
			    if(val_temp==100)
					{
						if(f_break_next_time)
		      return TRUE;
					}
			 
			 }
				 
			 
			 if(val_temp>1000)
				 return TRUE;
		}  
		else//百分比 limit
		{
			 if(f_break_next_time)
		   return TRUE;
			 if(val_temp>100)
				 return TRUE;
		}
		return FALSE;
	
}

void Write_val_input_target_power(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	static bool f_break_next_time = FALSE;
	
	val_temp = 0;
	f_break_next_time = FALSE;
	for(i=0;i<len;i++)   //10.1
	{
		if(p[i]=='.')
		{
			 if((char_input_target_type==2)||(char_input_target_type==5)||(char_input_target_type==8))
			 {
				 break;
			 }
			 else
		   f_break_next_time = TRUE;
		}
		else
		{
			if((p[i]=='.')&&f_break_next_time)
			{
			}
			else
			{
		    val_temp*=10;
	      val_temp += p[i]-0x30;
				if(f_break_next_time)
				{
					break;
				}
			}
		}
	}
	if((char_input_target_type!=2)&&(char_input_target_type!=5)&&(char_input_target_type!=8))
	{
	   if(f_break_next_time==FALSE)
	   val_temp*=10;
	}
	send_FlC200_set_cmd(power_now_set_send_id,val_temp);
}

void Write_code_input_target(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	val_temp = 0;
	for(i=0;i<len;i++)
	{
		val_temp<<=4;;
	  val_temp |= (p[i]-0x30)&0x0F;

	}//return;


	   code_connect = val_temp;


	  send_FlC200_connect_req_cmd();
}


bool limit_bat_capacity_input_target(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	val_temp = 0;
	for(i=0;i<len;i++)
	{
		val_temp*=10;
	      val_temp += p[i]-0x30;

	}//return;

  if(val_temp>5000)
	   return TRUE;
	
	return FALSE;
	   //code_connect = val_temp;
   
   //parts_set_return_status.Capacity = val_temp*10;
	  //send_FlC200_set_cmd(0x40,parts_set_return_status.Capacity);
}
void Write_bat_capacity_input_target(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	val_temp = 0;
	for(i=0;i<len;i++)
	{
		val_temp*=10;
		val_temp += p[i]-0x30;
	}
	sysprintf("\r\n  val_temp = %d \r\n",val_temp);
	parts_set_return_status.Capacity = val_temp*10;
	send_FlC200_set_cmd(0x40,parts_set_return_status.Capacity);
}

bool limit_bat_percenage_input_target(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	val_temp = 0;
	for(i=0;i<len;i++)
	{
		val_temp*=10;
	      val_temp += p[i]-0x30;

	}//return;

  if(val_temp>100)
	   return TRUE;
	
	return FALSE;
	   //code_connect = val_temp;
   
   //parts_set_return_status.Capacity = val_temp*10;
	  //send_FlC200_set_cmd(0x40,parts_set_return_status.Capacity);
}
void Write_bat_percenage_input_target(char *p,u8 len)
{
	u8 i;
	u16 val_temp;
	val_temp = 0;
	for(i=0;i<len;i++)
	{
		val_temp*=10;
		val_temp += p[i]-0x30;
	}
  if(val_temp>100)
		val_temp = 100;
	parts_set_return_status.Percentage = val_temp;
	send_FlC200_set_cmd(0x41,val_temp);
}

void Write_code_enter_target(char *p,u8 len)
{
	u8 i;
	u8 code[]="9527";
	u8 code3[]="6532";
	for(i=0;i<4;i++)
	{
	  if(code[i] != p[i])
		{
			break;
		}
		else if(i==3)
		{
			 if(len==4)
			 {
		     f_disply_debug_val = TRUE;
				 send_FlC200_base_set_cmd(0x82,1,0);
			   return;
			 }
		}
	}
	for(i=0;i<4;i++)
	{
	  if(code3[i] != p[i])
		{
			break;
		}
		else if(i==3)
		{
			 if(len==4)
			 {
				 sysprintf("\r\n !!!!!!!!!1 \r\n");
		     f_ui_need_disply_dialog_test= TRUE;
			   return;
			 }
		}
	}
}
void keyboard_input(u8 asiic)
{
  if((asiic>=0x20)&&(asiic<=0x7E))
	{
		if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_TANKS)
		{
			  if(((asiic>=0x30)&&(asiic<=0x39))||(asiic=='-'))
				{
				   if(char_input_len<(5))
					{
					 char_input_buf[char_input_len] = asiic;
					 char_input_len++;
						if(limit_val_input_target(char_input_buf,char_input_len))
						{
						  char_input_len--;
						}
						else
						{
							keyboard_val_limit_type = 2;
						 disply_char_input_val(FALSE);
						}
					}
				
				}
		
		}
		else if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_POWER)
		{
			  if(((asiic>=0x30)&&(asiic<=0x39))||(asiic=='.'))
				{
				   if((char_input_len<(4)))
					{
					 char_input_buf[char_input_len] = asiic;
					 char_input_len++;
						if(limit_val_input_target_power(char_input_buf,char_input_len))
						{
						  char_input_len--;
						}
						else
						{
							keyboard_val_limit_type = 1;
							if(char_input_target_type==1)
							keyboard_val_limit_type = 4;
							else
							keyboard_val_limit_type = 1;	
						  disply_char_input_val(FALSE);
						}
					}
				
				}
		
		}
		else if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
		{
			  if((asiic>=0x30)&&(asiic<=0x39))
				{
				  if(char_input_len<(4))
					{
					  char_input_buf[char_input_len] = asiic;
					  char_input_len++;
						
						if(f_ui_new_input_bat_capacity)
						{
							if(limit_bat_capacity_input_target(char_input_buf,char_input_len))
							{
								char_input_len--;
							}
							else
							{
								keyboard_val_limit_type = 3;
								disply_char_input_val(FALSE);
							}
					  }
						else if(f_ui_new_input_bat_percenage)
						{
						  if(limit_bat_percenage_input_target(char_input_buf,char_input_len))
							{
								char_input_len--;
							}
							else
							{
								keyboard_val_limit_type = 1;
								disply_char_input_val(FALSE);
							}
						
						}
					 
					}
				
				}
		
		}
		else
		{
			if(char_input_len<(NAME_TXT_MAX_LEN-1))
			{
			 char_input_buf[char_input_len] = asiic;
			 char_input_len++;
				disply_char_input_val(FALSE);
			}
	  }
	
	}
	else if(asiic==0x08)//退格
	{
	  if(char_input_len>0)	
		{			
     char_input_len--;
		disply_char_input_val(FALSE);
		}
	
	}
	else if(asiic==0x0E)//shift out
	{
	 keyboard_ui_step=KEYBOARD_PAGE_NOR;
	 ui_disply_keyboard(TRUE);
	}
	else if(asiic==0x0F)//shift in
	{
	 keyboard_ui_step=KEYBOARD_PAGE_CAPS;
	 ui_disply_keyboard(TRUE);
	}
	else if(asiic==0x0D)//回车
	{
		//f_ui_out_keyboard = TRUE;
		//if(char_input_buf!=0)
	  
		//sysprintf("\r\nrrrrrrrrrrrrrrrrrrrrr");
		f_ui_disply_keyboard = FALSE;
		f_ui_out_keyboard = FALSE;
		if(char_input_len!=0)//
		{
				//sysprintf("\r\nf_ui_disply_keyboard %d",f_ui_disply_keyboard);
				if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_TANKS)
				{
					 Write_val_input_target(char_input_buf,char_input_len);
				}
				else if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_POWER)
				{
					 Write_val_input_target_power(char_input_buf,char_input_len);
				}
				else if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_SYSTEM)
				{
					 if(f_ui_new_input_code)
					 {
						 f_ui_new_input_code = FALSE;
						 Write_code_input_target(char_input_buf,char_input_len);
					 }
					 else  if(f_ui_new_input_bat_capacity)
					 {
						 f_ui_new_input_bat_capacity = FALSE;
						 Write_bat_capacity_input_target(char_input_buf,char_input_len);
					 }
					 else  if(f_ui_new_input_bat_percenage)
					 {
						 f_ui_new_input_bat_percenage = FALSE;
						 Write_bat_percenage_input_target(char_input_buf,char_input_len);
					 }
					 else  if(f_ui_new_input_code_enter)
					 {
						 f_ui_new_input_code_enter = FALSE;
						 Write_code_enter_target(char_input_buf,char_input_len);
					 }
				}
				else
				{
					 Write_char_input_target(char_input_buf,char_input_len);
				}
	 }
		else			
		{
		   f_ui_new_input_code = FALSE;
       f_ui_new_input_bat_capacity = FALSE;
       f_ui_new_input_bat_percenage = FALSE;
			 f_ui_new_input_code_enter = FALSE;
		
		}
		
		ui_out_keyboard();
	}
	else if(asiic==0xFF)//123
	{
		keyboard_item[3].last_status = STATUS_IDLE;
		keyboard_item[3].now_status = STATUS_IDLE;
	  keyboard_ui_step=KEYBOARD_PAGE_NUM;
	  ui_disply_keyboard(TRUE);
	}
	else if(asiic==0xFE)//ABC
	{
		keyboard_item[3].last_status = STATUS_IDLE;
		keyboard_item[3].now_status = STATUS_IDLE;
	  keyboard_ui_step=KEYBOARD_PAGE_NOR;
		ui_disply_keyboard(TRUE);
	
	}
}

void ui_out_keyboard(void)
{
	lcd_dis_page_t *p;
	u8 i;
	if(f_ui_need_disply_dialog_test!=TRUE)
	{
		lcd_dis_page_t * p2 = &page_home.page_top_side[page_home.page_left_side.now_item];
		page_home.page_top_side[page_home.page_left_side.now_item].item[p2->now_item].last_status = STATUS_UPDATA;
	}
	page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
}

bool f_need_ui_disply_keyboard = FALSE;
void ui_disply_keyboard(bool keep_input)
{
	lcd_dis_page_t *p;
	u8 i;
	f_need_ui_disply_keyboard = FALSE;
	f_system_accessories_External_Key_Type = FALSE;
	f_system_Date_Time_set = FALSE;
	p = &page_home.page_keyboard;	
 //sysprintf("\r\n eeeeeeeeeeeeeee");
  //Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff3,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_keyboard = TRUE;
	
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_keyboard_deel_with_i(p,&i))
							 break;
			
		  //sysprintf("\r\n i:%d",i);
			if(p->item[i].now_status==STATUS_SELECT)	
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			else
			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }
	 if(keep_input==0)
	 char_input_len =0;
	 keyboard_val_limit_type = 0;
	 disply_char_input_val(TRUE);
   Virtual_LCD_Upgrate();

}


///////////////////////初始化////////////////////////////////////////


void ui_keyboard_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_keyboard;
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=KEYBOARD_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


/*
   t_load_mainbtn10_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_load_mainbtn11_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_load_mainbtn12_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_load_mainbtn13_d.key_type = KEY_TYPE_TOUCH_NONE;
	 t_load_mainbtn14_d.key_type = KEY_TYPE_TOUCH_NONE;
	 
	 t_load_mainbtn20_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_load_mainbtn21_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_load_mainbtn22_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_load_mainbtn23_d.key_type = KEY_TYPE_TOUCH_NONE;
	 t_load_mainbtn24_d.key_type = KEY_TYPE_TOUCH_NONE;

*/
   t_keyboard_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_keyboard_delete_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_enter_d.key_type = KEY_TYPE_ONCE;
   //t_keyboard_lock_d.key_type = KEY_TYPE_ONCE;//3
   //t_keyboard_num_d.key_type = KEY_TYPE_ONCE;//4
   t_keyboard_space_d.key_type = KEY_TYPE_ONCE;//5


   t_keyboard_a_d.key_type = KEY_TYPE_ONCE;//6
   t_keyboard_b_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_c_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_d_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_f_d.key_type = KEY_TYPE_ONCE;//10
   t_keyboard_g_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_h_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_j_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_k_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_l_d.key_type = KEY_TYPE_ONCE;//15
   t_keyboard_m_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_n_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_s_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_v_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_x_d.key_type = KEY_TYPE_ONCE;//20
   t_keyboard_z_d.key_type = KEY_TYPE_ONCE;


   t_keyboard_e_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_i_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_o_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_p_d.key_type = KEY_TYPE_ONCE;//25
   t_keyboard_q_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_r_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_t_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_u_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_y_d.key_type = KEY_TYPE_ONCE;//30
   t_keyboard_w_d.key_type = KEY_TYPE_ONCE;



   t_keyboard_a1_d.key_type = KEY_TYPE_ONCE;//32
   t_keyboard_b1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_c1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_d1_d.key_type = KEY_TYPE_ONCE;//35
   t_keyboard_f1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_g1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_h1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_j1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_k1_d.key_type = KEY_TYPE_ONCE;//40
   t_keyboard_l1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_m1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_n1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_s1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_v1_d.key_type = KEY_TYPE_ONCE;//45
   t_keyboard_x1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_z1_d.key_type = KEY_TYPE_ONCE;


   t_keyboard_e1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_i1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_o1_d.key_type = KEY_TYPE_ONCE;//50
   t_keyboard_p1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_q1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_r1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_t1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_u1_d.key_type = KEY_TYPE_ONCE;//55
   t_keyboard_y1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_w1_d.key_type = KEY_TYPE_ONCE;



   t_keyboard_0_d.key_type = KEY_TYPE_ONCE;//58
   t_keyboard_1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_2_d.key_type = KEY_TYPE_ONCE;///60
   t_keyboard_3_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_4_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_5_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_6_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_7_d.key_type = KEY_TYPE_ONCE;//65
   t_keyboard_8_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_9_d.key_type = KEY_TYPE_ONCE;//67
	 
	 t_keyboard_symbol1_d.key_type = KEY_TYPE_ONCE;
   t_keyboard_symbol2_d.key_type = KEY_TYPE_ONCE;//67
	 
	 
   p->item = keyboard_item;
   for(i=0;i<KEYBOARD_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_keyboard_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_keyboard_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_keyboard_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 f_ui_disply_keyboard = FALSE;
 }


