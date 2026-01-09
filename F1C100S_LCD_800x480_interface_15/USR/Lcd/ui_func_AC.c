#include "includes.h"

void func_bottombtn_ac_d(void* p)
{

}



void func_bottombtn_ac_u(void* p)
{

}
void func_climatebtn_right_down_d(void* p)
{
	u8 SN = 18;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if((p1->item[SN].now_status==STATUS_SELECT))
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
   tempt_r-=5;
	 if(tempt_r<150) tempt_r=150;
   //p->item[i].now_status=STATUS_IDLE;
   tempt_display();//ÏÔÊ¾¿Õµ÷ÎÂ¶È
	}
}
void func_climatebtn_right_down_u(void* p)
{

}
void func_climatebtn_right_up_d(void* p)
{
	u8 SN = 17;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if((p1->item[SN].now_status==STATUS_SELECT))
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
   tempt_r+=5;
	 if(tempt_r>310) tempt_r=310;									
	 //p->item[i].now_status=STATUS_IDLE;
	 tempt_display();//ÏÔÊ¾¿Õµ÷ÎÂ¶
	}
}
void func_climatebtn_right_up_u(void* p)
{

}
void func_adjust_minus_min_d(void* p)
{
	u8 SN = 9;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
     /*if(seat_ui_step==SEAT_PAGE_ADJUST)
										{
											if(seat_adjust_status_sel==1 )
											{
									      seat_adjust_status_l_now  = 1;
												if(seat_adjust_status_l_val[seat_adjust_status_l_now])
													seat_adjust_status_l_val[seat_adjust_status_l_now]--;
											}
											else if(seat_adjust_status_sel==2 )
											{
											  seat_adjust_status_r_now  = 1;
												if(seat_adjust_status_r_val[seat_adjust_status_r_now])
													seat_adjust_status_r_val[seat_adjust_status_r_now]--;
											}
										  //p->item[i].now_status=STATUS_IDLE;
										}*/
		}
}

void func_bottombtn_auto_d(void* p)
{

}



void func_bottombtn_auto_u(void* p)
{

}



void func_bottombtn_frontwindow_d(void* p)
{

}



void func_bottombtn_frontwindow_u(void* p)
{

}



void func_bottombtn_innerloop_d(void* p)
{

}



void func_bottombtn_innerloop_u(void* p)
{

}







void func_bottombtn_maxac_d(void* p)
{

}



void func_bottombtn_maxac_u(void* p)
{

}

void func_bottombtn_outerloop_d(void* p)
{

}



void func_bottombtn_outerloop_u(void* p)
{

}



void func_bottombtn_rearwindow_d(void* p)
{

}



void func_bottombtn_rearwindow_u(void* p)
{

}



void func_bottombtn_sync_d(void* p)
{

}



void func_bottombtn_sync_u(void* p)
{

}



void func_bottombtn_whlctrl_d(void* p)
{

}



void func_bottombtn_whlctrl_u(void* p)
{

}



void func_climatebtn_body_d(void* p)
{

}



void func_climatebtn_body_u(void* p)
{

}



void func_climatebtn_down_d(void* p)
{
	u8 SN = 9;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
		tempt_l-=5;
		if(tempt_l<150) tempt_l=150;
		//p->item[i].now_status=STATUS_IDLE;										
		tempt_display();//ÏÔÊ¾¿Õµ÷ÎÂ¶È
	}
	
	
}



void func_climatebtn_down_u(void* p)
{

}



void func_climatebtn_feet_d(void* p)
{

}



void func_climatebtn_feet_u(void* p)
{

}



void func_climatebtn_head_d(void* p)
{

}



void func_climatebtn_head_u(void* p)
{

}



void func_climatebtn_off_d(void* p)
{

}



void func_climatebtn_off_u(void* p)
{

}



void func_climatebtn_rearclimate_d(void* p)
{
	u8 SN = 13;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_IDLE)
	{
	    ac_ui_step = AC_PAGE_NOR;
	  	page_home.page_top_side[page_home.page_left_side.now_item].last_item=0xFF;//¸üÐÂ½çÃæ		
	}
	else if(p1->item[SN].now_status==STATUS_SELECT)
	{
      ac_ui_step = AC_PAGE_REAR;
	  	page_home.page_top_side[page_home.page_left_side.now_item].last_item=0xFF;//¸üÐÂ½çÃæ
	}
}



void func_climatebtn_rearclimate_u(void* p)
{

}



void func_climatebtn_up_d(void* p)
{
	u8 SN = 14;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
    tempt_l+=5;
		if(tempt_l>310) tempt_l=310;									
		//p->item[i].now_status=STATUS_IDLE;
		tempt_display();//ÏÔÊ¾¿Õµ÷ÎÂ¶È
	}
}



void func_climatebtn_up_u(void* p)
{

}



void func_climate_fan_0(void* p)
{

}



void func_climate_fan_1(void* p)
{

}



void func_climate_fan_2(void* p)
{

}



void func_climate_fan_3(void* p)
{

}



void func_climate_fan_4(void* p)
{

}



void func_climate_fan_5(void* p)
{

}



void func_climate_fan_6(void* p)
{

}



void func_climate_fan_7(void* p)
{

}



void func_climate_fan_big(void* p)
{

}



void func_climate_fan_big_d(void* p)
{
	u8 SN = 15;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
    fan++;
		if(fan>7) fan=7;	
    //p->item[i].now_status=STATUS_IDLE;											
		fan_display();//
	}
}



void func_climate_fan_small(void* p)
{

}



void func_climate_fan_small_d(void* p)
{
	u8 SN = 16;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
    if(fan)fan--;
    //p->item[i].now_status=STATUS_IDLE;	
	  fan_display();//
	}
	
}



void func_climate_scrollbar_box(void* p)
{

}



void func_climate_scrollbar_slider(void* p)
{

}



void func_climate_scrollbar_value(void* p)
{

}

void func_rearctrl_lock_d(void* p)
{

}



void func_rearctrl_lock_u(void* p)
{

}



void func_rearctrl_minusB_d(void* p)
{
	u8 SN = 20;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if((p1->item[SN].now_status==STATUS_SELECT))
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
   tempt_b-=5;
	 if(tempt_b<150) tempt_b=150;
   //p->item[i].now_status=STATUS_IDLE;
   tempt_display();//ÏÔÊ¾¿Õµ÷ÎÂ¶È
	}
}



void func_rearctrl_minusB_u(void* p)
{

}



void func_rearctrl_minus_d(void* p)
{
	u8 SN = 21;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ	
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
    if(fan_b)fan_b--;
    //p->item[i].now_status=STATUS_IDLE;	
	  fan_display();//
	}
}



void func_rearctrl_minus_u(void* p)
{

}



void func_rearctrl_plusR_d(void* p)
{
	
	
	u8 SN = 22;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
	lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if((p1->item[SN].now_status==STATUS_SELECT))
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
   tempt_b+=5;
	 if(tempt_b>310) tempt_b=310;									
	 //p->item[i].now_status=STATUS_IDLE;
	 tempt_display();//ÏÔÊ¾¿Õµ÷ÎÂ¶
	}
}



void func_rearctrl_plusR_u(void* p)
{

}



void func_rearctrl_plus_d(void* p)
{
	 u8 SN = 23;//Í¼±êÔÚµ±Ç°Ò³ÃæÁÐ±íµÄÐòºÅ
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{
	//if(p1->item[SN].last_status == STATUS_UPDATA) return;
    fan_b++;
		if(fan_b>7) fan_b=7;	
    //p->item[i].now_status=STATUS_IDLE;											
		fan_display();//
	}
}



void func_rearctrl_plus_u(void* p)
{
  
	
	
}



void func_rearctrl_power_d(void* p)
{

}



void func_rearctrl_power_u(void* p)
{

}

void func_rearctrl_windowbg1(void* p)
{

}

void func_rearctrl_windowbg2(void* p)
{

}
