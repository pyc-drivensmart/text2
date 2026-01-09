#include "includes.h"




void func_loads_ac_d(void* p,u8 sn)
{

}



void func_loads_ac_u(void* p,u8 sn)
{

}



void func_loads_b_loads_d(void* p,u8 sn)
{

}



void func_loads_b_loads_u(void* p,u8 sn)
{

}



void func_loads_fridge_d(void* p,u8 sn)
{

}



void func_loads_fridge_u(void* p,u8 sn)
{

}



void func_loads_kv_d(void* p,u8 sn)
{

}



void func_loads_kv_u(void* p,u8 sn)
{

}



void func_loads_load_d(void* p,u8 sn)
{

}



void func_loads_load_u(void* p,u8 sn)
{

}



void func_loads_mw_d(void* p,u8 sn)
{

}



void func_loads_mw_u(void* p,u8 sn)
{

}



void func_loads_tv_d(void* p,u8 sn)
{

}



void func_loads_tv_u(void* p,u8 sn)
{

}



void func_loads_ventilator_d(void* p,u8 sn)
{

}



void func_loads_ventilator_u(void* p,u8 sn)
{

}



void func_loads_wm_d(void* p,u8 sn)
{

}



void func_loads_wm_u(void* p,u8 sn)
{

}



void func_loads_wp_d(void* p,u8 sn)
{

}



void func_loads_wp_u(void* p,u8 sn)
{

}


////////////////////////////////////////////////

void func_load_mainbtn10_d(void* p,u8 sn)
{

}



void func_load_mainbtn10_u(void* p,u8 sn)
{

}



void func_load_mainbtn11_d(void* p,u8 sn)
{

}



void func_load_mainbtn11_u(void* p,u8 sn)
{

}



void func_load_mainbtn12_d(void* p,u8 sn)
{

}



void func_load_mainbtn12_u(void* p,u8 sn)
{

}



void func_load_mainbtn13_d(void* p,u8 sn)
{

}



void func_load_mainbtn13_u(void* p,u8 sn)
{

}



void func_load_mainbtn14_d(void* p,u8 sn)
{

}



void func_load_mainbtn14_u(void* p,u8 sn)
{

}



void func_load_mainbtn20_d(void* p,u8 sn)
{

}



void func_load_mainbtn20_u(void* p,u8 sn)
{

}



void func_load_mainbtn21_d(void* p,u8 sn)
{

}



void func_load_mainbtn21_u(void* p,u8 sn)
{

}



void func_load_mainbtn22_d(void* p,u8 sn)
{

}



void func_load_mainbtn22_u(void* p,u8 sn)
{

}



void func_load_mainbtn23_d(void* p,u8 sn)
{

}



void func_load_mainbtn23_u(void* p,u8 sn)
{

}



void func_load_mainbtn24_d(void* p,u8 sn)
{

}



void func_load_mainbtn24_u(void* p,u8 sn)
{

}




extern lcd_dis_item_t *p_loads_loads_item_d[];
void func_load_mainbtn_touch_d(void* p,u8 sn,u8 sel_ch)
{
  u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	

	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(Y_touch_now>(((p1->item[SN].y_end_val-p1->item[SN].y_val)*2)/3+p1->item[SN].y_val))
		{
		 	char_input_target_type = sel_ch+16;
			Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);			
			disply_loads_load_name_bg(sel_ch,TRUE);
			ui_disply_keyboard(FALSE);

		}
		else
		{
			loads_load_d_ico_select_ch = sel_ch;
		  now_dialog_loads_ch_select_ch = sel_ch;
			f_need_ui_disply_dialog_loads = TRUE;
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
	   if(p_loads_loads_item_d[sel_ch]->now_status ==STATUS_SELECT)
		 {
			 p_loads_loads_item_d[sel_ch]->now_status =STATUS_IDLE;				 
		  }
			else if(p_loads_loads_item_d[sel_ch]->now_status ==STATUS_IDLE)
		 {
			 if(p_loads_loads_item_d[sel_ch]->key_type !=KEY_TYPE_TOUCH_AND_DISPLAY_NONE)
				 p_loads_loads_item_d[sel_ch]->now_status =STATUS_SELECT;
		 }
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
	  if(p_loads_loads_item_d[sel_ch]->now_status ==STATUS_SELECT)
		{
			 p_loads_loads_item_d[sel_ch]->now_status =STATUS_IDLE;

		}
		else if(p_loads_loads_item_d[sel_ch]->now_status ==STATUS_IDLE)
		{
			if(p_loads_loads_item_d[sel_ch]->key_type !=KEY_TYPE_TOUCH_AND_DISPLAY_NONE)
			p_loads_loads_item_d[sel_ch]->now_status =STATUS_SELECT;
		}
	}
	
}

void func_load_mainbtn_touch10_d(void* p,u8 sn)
{
  /*u8 SN = sn;//í?±ê?úμ±?°ò3??áD±íμ?Dòo?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].last_status==STATUS_TOUCH_ON_IDLE)
	{
	   	 if(p_loads_loads_item_d[0]->now_status ==STATUS_SELECT)
			 {
			 p_loads_loads_item_d[0]->now_status =STATUS_IDLE;
				 //sysprintf("\r\n************888");
				 
			 }
			 else if(p_loads_loads_item_d[0]->now_status ==STATUS_IDLE)
			 {
				 p_loads_loads_item_d[0]->now_status =STATUS_SELECT;
				// sysprintf("\r\n************889");
			 }
	}*/
	func_load_mainbtn_touch_d(p,sn,0);
}
void func_load_mainbtn_touch11_d(void* p,u8 sn)
{
 func_load_mainbtn_touch_d(p,sn,1);
}
void func_load_mainbtn_touch12_d(void* p,u8 sn)
{
  func_load_mainbtn_touch_d(p,sn,2);
}
void func_load_mainbtn_touch13_d(void* p,u8 sn)
{
  func_load_mainbtn_touch_d(p,sn,3);
}
void func_load_mainbtn_touch14_d(void* p,u8 sn)
{
  func_load_mainbtn_touch_d(p,sn,4);
}

void func_load_mainbtn_touch20_d(void* p,u8 sn)
{
  func_load_mainbtn_touch_d(p,sn,5);
}
void func_load_mainbtn_touch21_d(void* p,u8 sn)
{
  func_load_mainbtn_touch_d(p,sn,6);
}
void func_load_mainbtn_touch22_d(void* p,u8 sn)
{
  func_load_mainbtn_touch_d(p,sn,7);
}
void func_load_mainbtn_touch23_d(void* p,u8 sn)
{
  func_load_mainbtn_touch_d(p,sn,8);
}
void func_load_mainbtn_touch24_d(void* p,u8 sn)
{
  func_load_mainbtn_touch_d(p,sn,9);
}


/////////////////////////////////////////

void func_loads_load_ico0_deel(void* p,u8 sn,u8 sel_ch,u8 send_cmd)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      //now_dialog_loads_ch_select_ch = sel_ch;
     // ui_disply_dialog_loads_ch();	
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
			
			 if(p1->item[SN].last_status==STATUS_TOUCH_ON_IDLE)
			 {
         p1->item[SN].now_status=STATUS_SELECT;
				 send_FlC200_swtich_cmd(send_cmd,1);//
				 disply_loads_load_ch_name(TRUE);
		     disply_loads_load_name(TRUE);
				 disply_loads_current_val(TRUE);
				 
			 }				 
		   else
			 {
         p1->item[SN].now_status=STATUS_IDLE; 
				 send_FlC200_swtich_cmd(send_cmd,0);//
				 disply_loads_load_ch_name(TRUE);
		     disply_loads_load_name(TRUE);
				 disply_loads_current_val(TRUE);
				 
			 }
		}
		
	}
	else 	if(p1->item[SN].now_status==STATUS_SELECT)
	{   
    if(f_loads_b_setup_d)
		{
			
			if(p1->item[SN].last_status!=STATUS_SELECT)
			{
			  loads_load_d_ico_select_ch = sel_ch;
				now_dialog_loads_ch_select_ch = sel_ch;
			  f_need_ui_disply_dialog_loads = TRUE;//ui_disply_dialog_loads();	
				p1->item[SN].now_status=STATUS_IDLE;
			}
			
			
			// p1->item[SN].last_status=STATUS_IDLE;
		}
		else
		{
		  send_FlC200_swtich_cmd(send_cmd,1);//
			disply_loads_load_ch_name(TRUE);
		  disply_loads_load_name(TRUE);
			disply_loads_current_val(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
			if(p1->item[SN].last_status!=STATUS_IDLE)
			{
			  loads_load_d_ico_select_ch = sel_ch;
				now_dialog_loads_ch_select_ch = sel_ch;
			  f_need_ui_disply_dialog_loads = TRUE;//ui_disply_dialog_loads();	
       
			
			 p1->item[SN].now_status=STATUS_SELECT;
			}
			// p1->item[SN].last_status=STATUS_IDLE;
		}
		else
		{
     send_FlC200_swtich_cmd(send_cmd,0);//
			disply_loads_load_ch_name(TRUE);
		 disply_loads_load_name(TRUE);
			disply_loads_current_val(TRUE);
		}
	}
}


void func_loads_load_ico0_d(void* p,u8 sn)
{
	
	func_loads_load_ico0_deel(p,sn,0,0x10);
	/*
	u8 SN = 10;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 0;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(f_loads_b_setup_d)
		{
		loads_load_d_ico_select_ch = 0;	
    f_need_ui_dialog_loads = TRUE;//ui_disply_dialog_loads();
    
		
		p1->item[SN].now_status=STATUS_IDLE;
			
		}
		else
		{
		send_FlC200_swtich_cmd(0x10,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x10,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/
}



void func_loads_load_ico0_u(void* p,u8 sn)
{

}
void func_loads_load_ico1_d(void* p,u8 sn)
{
	func_loads_load_ico0_deel(p,sn,1,0x11);
	/*
	u8 SN = 11;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 1;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
    if(f_loads_b_setup_d)
		{
			loads_load_d_ico_select_ch = 1;
    f_need_ui_dialog_loads = TRUE;//ui_disply_dialog_loads();	
    
		
		p1->item[SN].now_status=STATUS_IDLE;
			
		}
		else
		{		
		send_FlC200_swtich_cmd(0x11,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x11,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/

}

void func_loads_load_ico1_u(void* p,u8 sn)
{

}
void func_loads_load_ico2_d(void* p,u8 sn)
{	
	func_loads_load_ico0_deel(p,sn,2,0x12);
	/*
	u8 SN = 12;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 2;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
    if(f_loads_b_setup_d)
		{
			loads_load_d_ico_select_ch = 2;
      f_need_ui_dialog_loads = TRUE;//ui_disply_dialog_loads();	
    
		
		p1->item[SN].now_status=STATUS_IDLE;
			
		}
		else
		{	
		send_FlC200_swtich_cmd(0x12,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x12,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/

}



void func_loads_load_ico2_u(void* p,u8 sn)
{

}
void func_loads_load_ico3_d(void* p,u8 sn)
{
	func_loads_load_ico0_deel(p,sn,3,0x13);
	/*
	u8 SN = 13;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 3;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{   
    if(f_loads_b_setup_d)
		{
			loads_load_d_ico_select_ch = 3;
    ui_disply_dialog_loads();		
    
		
		p1->item[SN].now_status=STATUS_IDLE;
			
		}
		else
		{			
		send_FlC200_swtich_cmd(0x13,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x13,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/
}



void func_loads_load_ico3_u(void* p,u8 sn)
{

}
void func_loads_load_ico4_d(void* p,u8 sn)
{
	func_loads_load_ico0_deel(p,sn,4,0x14);
	/*
	u8 SN = 14;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 4;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
		
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{    
   if(f_loads_b_setup_d)
		{
			loads_load_d_ico_select_ch = 4;
    ui_disply_dialog_loads();		
    
		
		p1->item[SN].now_status=STATUS_IDLE;
			
		}
		else
		{			
		send_FlC200_swtich_cmd(0x14,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x14,0);//
		 disply_loads_load_name(TRUE);
		}
	}
		*/
}



void func_loads_load_ico4_u(void* p,u8 sn)
{

}
void func_loads_load_ico5_d(void* p,u8 sn)
{
	func_loads_load_ico0_deel(p,sn,5,0x15);
	/*
	u8 SN = 15;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 5;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{   
    if(f_loads_b_setup_d)
		{
      loads_load_d_ico_select_ch = 5;
			ui_disply_dialog_loads();		
      
		
		  p1->item[SN].now_status=STATUS_IDLE;
		}
		else
		{			
		send_FlC200_swtich_cmd(0x15,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x15,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/
}



void func_loads_load_ico5_u(void* p,u8 sn)
{

}
void func_loads_load_ico6_d(void* p,u8 sn)
{
	func_loads_load_ico0_deel(p,sn,6,0x16);
	/*
	u8 SN = 16;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 6;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{    
    if(f_loads_b_setup_d)
		{
			
			loads_load_d_ico_select_ch = 6;
    ui_disply_dialog_loads();		
    
		
		p1->item[SN].now_status=STATUS_IDLE;
			
		}
		else
		{			
		send_FlC200_swtich_cmd(0x16,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x16,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/
}



void func_loads_load_ico6_u(void* p,u8 sn)
{

}
void func_loads_load_ico7_d(void* p,u8 sn)
{
	func_loads_load_ico0_deel(p,sn,7,0x17);
	/*
	u8 SN = 17;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 7;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(f_loads_b_setup_d)
		{
      loads_load_d_ico_select_ch = 7;
			ui_disply_dialog_loads();		
      
		
		  p1->item[SN].now_status=STATUS_IDLE;
		}
		else
		{	
		send_FlC200_swtich_cmd(0x17,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x17,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/
}



void func_loads_load_ico7_u(void* p,u8 sn)
{

}
void func_loads_load_ico8_d(void* p,u8 sn)
{
	func_loads_load_ico0_deel(p,sn,8,0x18);
	/*
	u8 SN = 18;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 8;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(f_loads_b_setup_d)
		{
			loads_load_d_ico_select_ch = 8;
      ui_disply_dialog_loads();		
    
		
		p1->item[SN].now_status=STATUS_IDLE;
			
		}
		else
		{	
		send_FlC200_swtich_cmd(0x18,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x18,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/
}



void func_loads_load_ico8_u(void* p,u8 sn)
{

}

void func_loads_load_ico9_d(void* p,u8 sn)
{
	func_loads_load_ico0_deel(p,sn,9,0x19);
	/*
	u8 SN = 19;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		if(f_loads_b_setup_d)
		{	
      now_dialog_loads_ch_select_ch = 9;
      ui_disply_dialog_loads_ch();	
			p1->item[SN].now_status=STATUS_IDLE;
		}
	}
	else 
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		if(f_loads_b_setup_d)
		{
			loads_load_d_ico_select_ch = 9;
      ui_disply_dialog_loads();		
      
		
		  p1->item[SN].now_status=STATUS_IDLE;
			
		}
		else
		{	
		send_FlC200_swtich_cmd(0x19,1);//
		disply_loads_load_name(TRUE);
		}
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		if(f_loads_b_setup_d)
		{
			
		}
		else
		{
     send_FlC200_swtich_cmd(0x19,0);//
		 disply_loads_load_name(TRUE);
		}
	}*/
}



void func_loads_load_ico9_u(void* p,u8 sn)
{

}



void func_loads_load_ico_char0_d(void* p,u8 sn)
{
	
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 16;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(0,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
			char_input_target_type = 16;
		  Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		  disply_loads_load_name_bg(0,TRUE);
		  ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}

void func_loads_load_ico_char1_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 17;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(1,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
			char_input_target_type = 17;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(1,TRUE);
		ui_disply_keyboard(FALSE);

		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_loads_load_ico_char2_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 18;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(2,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
      char_input_target_type = 18;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(2,TRUE);
		ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_loads_load_ico_char3_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 19;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(3,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
      char_input_target_type = 19;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(3,TRUE);
		ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_loads_load_ico_char4_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 20;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(4,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
        char_input_target_type = 20;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(4,TRUE);
		ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_loads_load_ico_char5_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 21;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(5,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
     char_input_target_type = 21;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(5,TRUE);
		ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_loads_load_ico_char6_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 22;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(6,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
     char_input_target_type = 22;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(6,TRUE);
		ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_loads_load_ico_char7_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 23;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(7,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
      char_input_target_type = 23;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(7,TRUE);
		ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_loads_load_ico_char8_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 24;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(8,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
     char_input_target_type = 24;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(8,TRUE);
		ui_disply_keyboard(FALSE);
		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}
void func_loads_load_ico_char9_d(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//sysprintf("\r\n iiiii:%d",p1->item[SN].now_status);
	/*if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	{     
		char_input_target_type = 25;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(9,TRUE);
		ui_disply_keyboard();
		
		p1->item[SN].now_status=STATUS_IDLE;
	}
	else */if(p1->item[SN].now_status==STATUS_SELECT)
	{
		if(f_loads_b_setup_d)
		{
			char_input_target_type = 25;
		Set_char_input_target_p(&switch_name_list[char_input_target_type],&switch_name_list_return[char_input_target_type]);
		
		disply_loads_load_name_bg(9,TRUE);
		ui_disply_keyboard(FALSE);

		}
     p1->item[SN].now_status=STATUS_IDLE;
	}
}



void func_loads_b_setup_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
	//u8 i;
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
     f_loads_b_setup_d = TRUE;
		 set_loads_item_key_type(KEY_TYPE_LONG_PRESS);
		 //disply_loads_load_ch_name(FALSE);
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
     f_loads_b_setup_d = FALSE;
		 set_loads_item_key_type(KEY_TYPE_NORMAL);
		 set_home_loads_item_key_type();
		// disply_loads_load_ch_name(FALSE);
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;
	}
	

}
void func_loads_b_setup_f(void* p,u8 sn)
{

}



void func_loads_b_setup_u(void* p,u8 sn)
{

}
