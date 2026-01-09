#include "includes.h"




void func_diagnostics_clear_d(void* p,u8 sn)
{
		u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
     memset(&all_diagnostics,0,sizeof(ALL_DIAGNOST));
	}
}



void func_diagnostics_clear_u(void* p,u8 sn)
{

}



void func_diagnostics_gray(void* p,u8 sn)
{

}



void func_diagnostics_green(void* p,u8 sn)
{

}



void func_diagnostics_network_bg(void* p,u8 sn)
{

}



void func_diagnostics_output_bg(void* p,u8 sn)
{

}



void func_diagnostics_red(void* p,u8 sn)
{

}
void func_diagnostics_yellow(void* p,u8 sn)
{

}
void func_diagnostics_idle(void* p,u8 sn)
{

}

void func_diagnostics_sensor_bg(void* p,u8 sn)
{

}



void func_diagnostics_start_d(void* p,u8 sn)
{
		u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{ 
     memset(&all_diagnostics,0,sizeof(ALL_DIAGNOST));
		 f_diagnostics_on = TRUE;
	}
}



void func_diagnostics_start_u(void* p,u8 sn)
{

}



void func_system_b_diagnostics_d(void* p,u8 sn)
{

}



void func_system_b_diagnostics_u(void* p,u8 sn)
{

}