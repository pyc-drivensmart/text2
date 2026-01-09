#include "includes.h"

void func_home_loads_bg(void* p,u8 sn)
{

}
void func_home_inverter_d(void* p,u8 sn)
{
	
	u8 SN = 0;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		//send_FlC200_swtich_cmd(0x24,1);//
		
			parts_set_return_status.Inverter_Mode++;
		if(parts_set_return_status.Inverter_Mode>=4)
			parts_set_return_status.Inverter_Mode = 0;
		//parts_set_status.Inverter_Mode
		parts_set_status.Inverter_Mode=parts_set_return_status.Inverter_Mode;
		send_FlC200_set_cmd(0x49,parts_set_status.Inverter_Mode);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     //send_FlC200_swtich_cmd(0x24,0);//
	}

}



void func_home_inverter_u(void* p,u8 sn)
{

}
void func_home_inverter_f(void* p,u8 sn)
{

}


void func_home_lightsbtn_d(void* p,u8 sn)
{
	u8 SN = 1;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		  page_home.page_left_side.item[LEFT_SIDE_PAGE_HOME].now_status=STATUS_IDLE;
			page_home.page_left_side.item[LEFT_SIDE_PAGE_LIGHTS].now_status=STATUS_TOUCH;
 
	}
}



void func_home_lightsbtn_u(void* p,u8 sn)
{

}



void func_home_lightsoff_d(void* p,u8 sn)
{

}

void func_home_lightsON_u(void* p,u8 sn)
{
	u8 SN = 2;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x0F,1);//
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		//if((switch_ctrl_byte[0]&0xF0)||switch_ctrl_byte[1]&0x7E)//所有灯灭时，不执行
      send_FlC200_swtich_cmd(0x0F,0);//

	}
}
void func_home_lightsON_d(void* p,u8 sn)
{
	u8 SN = 2;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x0F,1);//
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
		//if((switch_ctrl_byte[0]&0xF0)||switch_ctrl_byte[1]&0x7E)//所有灯灭时，不执行
      send_FlC200_swtich_cmd(0x0F,0);//

	}
}


void func_home_lightsoff_u(void* p,u8 sn)
{

}






void func_home_loadbtn_d(void* p,u8 sn)
{
	u8 SN = 3;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		  page_home.page_left_side.item[LEFT_SIDE_PAGE_HOME].now_status=STATUS_IDLE;
			page_home.page_left_side.item[LEFT_SIDE_PAGE_LOADS].now_status=STATUS_TOUCH;
 
	}
}



void func_home_loadbtn_u(void* p,u8 sn)
{

}



void func_home_loadlights_bg(void* p,u8 sn)
{

}



void func_home_loadoff_d(void* p,u8 sn)
{

}

void func_home_loadON_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x1F,1);//
		disply_load_name(TRUE);		
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x1F,0);//
		 disply_load_name(TRUE);
		
		/*home_item[19].now_status = STATUS_IDLE;
		home_item[20].now_status = STATUS_IDLE;
		home_item[21].now_status = STATUS_IDLE;
		home_item[22].now_status = STATUS_IDLE;
		home_item[23].now_status = STATUS_IDLE;
		home_item[24].now_status = STATUS_IDLE;*/
		
		
	}
}


void func_home_loadON_u(void* p,u8 sn)
{
	/*u8 SN = 2;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x1F,0);//
		disply_light_name(TRUE);		
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x1F,0);//
		 disply_light_name(TRUE);
	}*/
}



void func_home_loadoff_u(void* p,u8 sn)
{
	//u8 SN = sn;//图标在当前页面列表的序号
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	/*if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x1F,1);//
		disply_load_name(TRUE);		
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x1F,0);//
		 disply_load_name(TRUE);
		

		
	}*/
}



void func_home_POWbc_d(void* p,u8 sn)
{

}



void func_home_POWbc_u(void* p,u8 sn)
{

}



void func_home_POWcc_d(void* p,u8 sn)
{

}



void func_home_POWcc_u(void* p,u8 sn)
{

}



void func_home_powerbtn_d(void* p,u8 sn)
{
	u8 SN = 7;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		  page_home.page_left_side.item[LEFT_SIDE_PAGE_HOME].now_status=STATUS_IDLE;
			page_home.page_left_side.item[LEFT_SIDE_PAGE_POWER].now_status=STATUS_TOUCH;
 
	}



}



void func_home_powerbtn_u(void* p,u8 sn)
{

}



void func_home_powerscroll_bg(void* p,u8 sn)
{

}

void func_home_powerS_0(void* p,u8 sn)
{

}


void func_home_powerS_d(void* p,u8 sn)
{
	u8 SN = 8;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x20,1);//
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x20,0);//
	}
}



void func_home_powerS_u(void* p,u8 sn)
{

}



void func_home_POWsc_d(void* p,u8 sn)
{

}



void func_home_POWsc_u(void* p,u8 sn)
{

}



void func_home_tankbtn_d(void* p,u8 sn)
{
	u8 SN = 10;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		  page_home.page_left_side.item[LEFT_SIDE_PAGE_HOME].now_status=STATUS_IDLE;
			page_home.page_left_side.item[LEFT_SIDE_PAGE_TANKS].now_status=STATUS_TOUCH;
 
	}
}



void func_home_tankbtn_u(void* p,u8 sn)
{

}



void func_home_black_bg(void* p,u8 sn)
{

}



void func_home_fresh_bg(void* p,u8 sn)
{

}



void func_home_grey_bg(void* p,u8 sn)
{

}



void func_home_LPG_bg(void* p,u8 sn)
{

}

void func_home_heating_bg(void* p,u8 sn)
{

}


void func_home_TV_ico(void* p,u8 sn)
{

}

void func_home_kv_ico(void* p,u8 sn)
{
	
}
void func_home_mw_ico(void* p,u8 sn)
{
	
}
void func_home_wm_ico(void* p,u8 sn)
{
	
}

void func_home_ventilator_ico(void* p,u8 sn)
{

}


void func_home_wpoff_d(void* p,u8 sn)
{
	/*u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x2F,1);//
		disply_load_name(TRUE);
    //disply_light_name(TRUE);			
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x2F,0);//
		 disply_load_name(TRUE);	
     //disply_light_name(TRUE);	
	}*/
}
void func_home_wpoff_u(void* p,u8 sn)
{

}



void func_home_wpON_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x06,1);//
		disply_load_name(TRUE);
    //disply_light_name(TRUE);			
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x06,0);//
		 disply_load_name(TRUE);	
     //disply_light_name(TRUE);	
	}
}

void func_home_wpON_u(void* p,u8 sn)
{

}


void func_home_black_100(void* p,u8 sn)
{

}



void func_home_black_wave(void* p,u8 sn)
{

}



void func_home_grey_100(void* p,u8 sn)
{

}



void func_home_grey_wave(void* p,u8 sn)
{

}
void func_home_fresh_100(void* p,u8 sn)
{

}



void func_home_fresh_wave(void* p,u8 sn)
{

}


void func_home_LPG_100(void* p,u8 sn)
{

}



void func_home_LPG_wave(void* p,u8 sn)
{

}

void func_home_heating_100(void* p,u8 sn)
{

}



void func_home_heating_wave(void* p,u8 sn)
{

}
void func_home_wp_ico(void* p,u8 sn)
{


}
///////////////////////////////////////////////////////////////
void  func_home_loadlights2_bg(void* p,u8 sn)
{

}

void func_home_light_d_ico(void* p,u8 sn)
{
	u8 SN = 25;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x00,1);//
		disply_light_name(TRUE);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x00,0);//
		 disply_light_name(TRUE);
	}
}



void func_home_light_u_ico(void* p,u8 sn)
{

}

void func_home_light_d_ico0(void* p,u8 sn)
{
	u8 SN = 25;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x00,1);//
		disply_light_name(TRUE);
		home_item[2].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x00,0);//
		 disply_light_name(TRUE);
	}

}
void func_home_light_u_ico0(void* p,u8 sn)
{

}


void func_home_light_d_ico1(void* p,u8 sn)
{
	u8 SN = 26;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x01,1);//
		disply_light_name(TRUE);
		home_item[2].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x01,0);//
	  	disply_light_name(TRUE);
	}
}



void func_home_light_d_ico2(void* p,u8 sn)
{
	u8 SN = 27;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x02,1);//
		disply_light_name(TRUE);
		home_item[2].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x02,0);//
		 disply_light_name(TRUE);
	}
}



void func_home_light_d_ico3(void* p,u8 sn)
{
	u8 SN = 28;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x03,1);//
		disply_light_name(TRUE);
		home_item[2].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x03,0);//
		disply_light_name(TRUE);
	}
}



void func_home_light_d_ico4(void* p,u8 sn)
{
	u8 SN = 29;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x09,1);//
		disply_light_name(TRUE);
		home_item[2].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x09,0);//
		disply_light_name(TRUE);
	}
}



void func_home_light_d_ico5(void* p,u8 sn)
{
	u8 SN = 30;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x0A,1);//
		disply_light_name(TRUE);
		home_item[2].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x0A,0);//
		 disply_light_name(TRUE);
	}
}



void func_home_light_u_ico1(void* p,u8 sn)
{

}



void func_home_light_u_ico2(void* p,u8 sn)
{

}



void func_home_light_u_ico3(void* p,u8 sn)
{

}



void func_home_light_u_ico4(void* p,u8 sn)
{

}



void func_home_light_u_ico5(void* p,u8 sn)
{

}



void func_home_ventilator_ico1(void* p,u8 sn)
{

}



void func_home_ventilator_ico2(void* p,u8 sn)
{

}



void func_home_ventilator_ico3(void* p,u8 sn)
{

}
void func_home_ac_ico(void* p,u8 sn)
{

}



void func_home_fridge_ico(void* p,u8 sn)
{

}

void func_home_fridge_d (void* p,u8 sn)
{

}
void func_home_powerscroll_f(void* p,u8 sn)
{

}

//read me:copy the new item to 'ui_func.c'





void func_home_awning_d_ico(void* p,u8 sn)
{

}



void func_home_awning_u_ico(void* p,u8 sn)
{

}



void func_home_rearwork_d_ico(void* p,u8 sn)
{

}



void func_home_rearwork_u_ico(void* p,u8 sn)
{

}



void func_home_rightside_d_ico(void* p,u8 sn)
{

}



void func_home_rightside_u_ico(void* p,u8 sn)
{

}



void func_home_underbody_ico(void* p,u8 sn)
{

}



void func_home_underbody_u_ico(void* p,u8 sn)
{

}

void func_home_interior_d_ico(void* p,u8 sn)
{

}



void func_home_interior_u_ico(void* p,u8 sn)
{

}



void func_home_load_d_ico0(void* p,u8 sn)
{
   	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x10,1);//
		disply_load_name(TRUE);
		home_item[4].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x10,0);//
		 disply_load_name(TRUE);
	}
}
void func_home_load_d_ico1(void* p,u8 sn)
{
  	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x11,1);//
		disply_load_name(TRUE);
		home_item[4].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x11,0);//
		 disply_load_name(TRUE);
	}
}
void func_home_load_d_ico2(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x12,1);//
		disply_load_name(TRUE);
		home_item[4].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x12,0);//
		 disply_load_name(TRUE);
	}
}void func_home_load_d_ico3(void* p,u8 sn)
{
		u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x13,1);//
		disply_load_name(TRUE);
		home_item[4].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x13,0);//
		 disply_load_name(TRUE);
	}

}void func_home_load_d_ico4(void* p,u8 sn)
{
		u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x14,1);//
		disply_load_name(TRUE);
		home_item[4].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x14,0);//
		 disply_load_name(TRUE);
	}

}void func_home_load_d_ico5(void* p,u8 sn)
{
		u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		send_FlC200_swtich_cmd(0x15,1);//
		disply_load_name(TRUE);
		home_item[4].now_status = STATUS_SELECT;
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{
     send_FlC200_swtich_cmd(0x15,0);//
		 disply_load_name(TRUE);
	}

}void func_home_load_u_ico0(void* p,u8 sn)
{

}void func_home_load_u_ico1(void* p,u8 sn)
{

}void func_home_load_u_ico2(void* p,u8 sn)
{

}void func_home_load_u_ico3(void* p,u8 sn)
{

}void func_home_load_u_ico4(void* p,u8 sn)
{

}void func_home_load_u_ico5(void* p,u8 sn)
{

}


//read me:copy the new item to 'ui_func.c'





void func_home_ac_d(void* p,u8 sn)
{

}



void func_home_ac_u(void* p,u8 sn)
{

}



void func_home_kv_d(void* p,u8 sn)
{

}



void func_home_kv_u(void* p,u8 sn)
{

}



void func_home_load_d(void* p,u8 sn)
{

}



void func_home_load_u(void* p,u8 sn)
{

}



void func_home_mw_d(void* p,u8 sn)
{

}



void func_home_mw_u(void* p,u8 sn)
{

}



void func_home_TV_d(void* p,u8 sn)
{

}



void func_home_TV_u(void* p,u8 sn)
{

}



void func_home_ventilator_d(void* p,u8 sn)
{

}



void func_home_ventilator_u(void* p,u8 sn)
{

}



void func_home_wm_d(void* p,u8 sn)
{

}



void func_home_wm_u(void* p,u8 sn)
{

}



void func_home_wp_d(void* p,u8 sn)
{

}



void func_home_wp_u(void* p,u8 sn)
{

}



void func_home_powerscroll_ch_bg(void* p,u8 sn)
{

}
void func_home_powerscroll_ch_75_bg(void* p,u8 sn)
{

}


void func_home_powerscroll_ch_f(void* p,u8 sn)
{

}



void func_home_powerscroll_ch_f_r(void* p,u8 sn)
{

}


void func_home_powerscroll_ch_f_y(void* p,u8 sn)
{

}



void func_home_powerscroll_ch_r_bg(void* p,u8 sn)
{

}



void func_home_powerscroll_ch_y_bg(void* p,u8 sn)
{

}



void func_home_powerscroll_f_y(void* p,u8 sn)
{

}



void func_home_powerscroll_f_r(void* p,u8 sn)
{

}
void func_home_powerscroll_f_75(void* p,u8 sn)
{

}


void func_home_powerscroll_f_y_bg(void* p,u8 sn)
{

}
void func_home_powerscroll_75_bg(void* p,u8 sn)
{

}



void func_home_powerscroll_r_bg(void* p,u8 sn)
{

}




void func_home_powerscroll_y_bg(void* p,u8 sn)
{

}

