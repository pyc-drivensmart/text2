#include "includes.h"
//read me:copy the new item to 'ui_func.c'
//read me:copy the new item to 'ui_func.c'





void func_dialog_close_msg_d(void* p,u8 sn)
{
	 u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//static bool f_status = FALSE;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_msg();
		
		f_ui_disply_dialog_msg = FALSE;
		//f_status = TRUE;
	}
	/*else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
		//ui_out_dialog_msg();
		if(f_status)
		f_ui_disply_dialog_msg = FALSE;
	}*/
	

}



void func_dialog_close_msg_u(void* p,u8 sn)
{

}


void func_dialog_empty_d(void* p,u8 sn)
{
	 u8 SN = sn;//¨ª?¡À¨º?¨²¦Ì¡À?¡ã¨°3??¨¢D¡À¨ª¦Ì?D¨°o?
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//static bool f_status = FALSE;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		ui_out_dialog_msg();
		
		f_ui_disply_dialog_msg = FALSE;
		//f_status = TRUE;
	}
	/*else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
		//ui_out_dialog_msg();
		if(f_status)
		f_ui_disply_dialog_msg = FALSE;
	}*/
	
}

void func_dialog_empty_u(void* p,u8 sn)
{

}


