#include "includes.h"


void func_load_motobtn0_u(void* p,u8 sn)
{

}

void func_load_motobtn1_u(void* p,u8 sn)
{

}

void func_loads_b_Motors_d(void* p,u8 sn)
{
		u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
if(p1->item[SN].now_status==STATUS_SELECT)
 {
				  f_ui_need_disply_dialog_msg= TRUE;
			    v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_MOTOR_WARNING;
    }

}
void func_loads_b_Motors_f(void* p,u8 sn)
{

}

void func_loads_b_Motors_u(void* p,u8 sn)
{

}

void func_load_motoctl_btn_deel(void* p,u8 sn,u8 send_cmd)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	
	//sysprintf("\r\n 0000000000000:%d",p1->item[SN].now_status);
  if(p1->item[SN].now_status==STATUS_TOUCH)
	{   

		  send_FlC200_swtich_cmd(send_cmd,1);//
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{ 
	   send_FlC200_swtich_cmd(send_cmd,0);//
	}
}
		



void func_load_motoctl_btn_d(void* p,u8 sn)
{
  u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	 //func_load_motoctl_btn_deel(p,sn,0x1A);
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  
		 if((f_handbreak==0)&&(f_ignore_handbreak==0))
		 {
			 f_ui_need_disply_dialog_msg= TRUE;
			    v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_HANDBREAK_WARNING;
			 p1->item[SN].now_status=STATUS_IDLE;
			 p1->item[SN].last_status=STATUS_IDLE;
		 }
		 else
		 {
      send_FlC200_swtich_cmd(0x1B,0);
		  send_FlC200_swtich_cmd(0x1A,1);
		 }

	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{ 
		 send_FlC200_swtich_cmd(0x1B,0);
	   send_FlC200_swtich_cmd(0x1A,0);
	}
}

void func_load_motoctl_btn_down_d(void* p,u8 sn)
{
  u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//func_load_motoctl_btn_deel(p,sn,0x1B);
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  if((f_handbreak==0)&&(f_ignore_handbreak==0))
		 {
			 f_ui_need_disply_dialog_msg= TRUE;
			    v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_HANDBREAK_WARNING;
			 p1->item[SN].now_status=STATUS_IDLE;
			 p1->item[SN].last_status=STATUS_IDLE;
		 }
		 else
		 {
      send_FlC200_swtich_cmd(0x1A,0);
		  send_FlC200_swtich_cmd(0x1B,1);
		 }

	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{ 
		 send_FlC200_swtich_cmd(0x1A,0);
	   send_FlC200_swtich_cmd(0x1B,0);
	}
}



//
void func_load_motoctl_btn1_d(void* p,u8 sn)
{
  u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//func_load_motoctl_btn_deel(p,sn,0x1C);
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  if((f_handbreak==0)&&(f_ignore_handbreak==0))
		 {
			 f_ui_need_disply_dialog_msg= TRUE;
			    v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_HANDBREAK_WARNING;
			 p1->item[SN].now_status=STATUS_IDLE;
			 p1->item[SN].last_status=STATUS_IDLE;
		 }
		 else
		 {
      send_FlC200_swtich_cmd(0x1D,0);
		  send_FlC200_swtich_cmd(0x1C,1);
		 }

	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{ 
		 send_FlC200_swtich_cmd(0x1D,0);
	   send_FlC200_swtich_cmd(0x1C,0);
	}
}

void func_load_motoctl_btn1_down_d(void* p,u8 sn)
{
  u8 SN = sn;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//func_load_motoctl_btn_deel(p,sn,0x1D);
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  
		if((f_handbreak==0)&&(f_ignore_handbreak==0))
		 {
			   f_ui_need_disply_dialog_msg= TRUE;
			    v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_HANDBREAK_WARNING;
			 p1->item[SN].now_status=STATUS_IDLE;
			 p1->item[SN].last_status=STATUS_IDLE;
		 }
		 else
		 {
      send_FlC200_swtich_cmd(0x1C,0);
		  send_FlC200_swtich_cmd(0x1D,1);
		 }

	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{ 
		 send_FlC200_swtich_cmd(0x1C,0);
	   send_FlC200_swtich_cmd(0x1D,0);
	}
}






void func_load_motoctl_btn_u(void* p,u8 sn)
{

}

void func_load_motoctl_btn_down_u(void* p,u8 sn)
{

}

void func_load_motoctl_btn1_u(void* p,u8 sn)
{

}

void func_load_motoctl_btn1_down_u(void* p,u8 sn)
{

}



void func_Motors_Awning_ico_u(void* p,u8 sn)
{

}

void func_Motors_Curtain_ico_u(void* p,u8 sn)
{

}

void func_Motors_Expansion_ico_u(void* p,u8 sn)
{

}















extern lcd_dis_item_t *p_loads_motors_item_d[];
void func_load_motobtn_touch_d(void* p,u8 sn,u8 sel_ch)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	

	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
			loads_motor_u_ico_select_ch = sel_ch;
		  now_dialog_motors_ch_select_ch = sel_ch;
			f_need_ui_disply_dialog_motors = TRUE;
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
	   /*if(p_loads_loads_item_d[sel_ch]->now_status ==STATUS_SELECT)
		 {
			 p_loads_loads_item_d[sel_ch]->now_status =STATUS_IDLE;				 
		  }
			else if(p_loads_loads_item_d[sel_ch]->now_status ==STATUS_IDLE)
		 {
			 if(p_loads_loads_item_d[sel_ch]->key_type !=KEY_TYPE_TOUCH_AND_DISPLAY_NONE)
				 p_loads_loads_item_d[sel_ch]->now_status =STATUS_SELECT;
		 }*/
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
	 /* if(p_loads_loads_item_d[sel_ch]->now_status ==STATUS_SELECT)
		{
			 p_loads_loads_item_d[sel_ch]->now_status =STATUS_IDLE;

		}
		else if(p_loads_loads_item_d[sel_ch]->now_status ==STATUS_IDLE)
		{
			if(p_loads_loads_item_d[sel_ch]->key_type !=KEY_TYPE_TOUCH_AND_DISPLAY_NONE)
			p_loads_loads_item_d[sel_ch]->now_status =STATUS_SELECT;
		}*/
	}
	
}

	

void func_load_motobtn_touch0_d(void* p,u8 sn)
{
	func_load_motobtn_touch_d(p,sn,0);
}

void func_load_motobtn_touch1_d(void* p,u8 sn)
{
	func_load_motobtn_touch_d(p,sn,1);
}

void func_loads_motors_u_ico0(void* p,u8 sn)
{

}
void func_loads_motors_u_ico1(void* p,u8 sn)
{
 
}

