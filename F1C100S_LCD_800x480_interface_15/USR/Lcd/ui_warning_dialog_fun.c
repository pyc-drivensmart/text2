#include "includes.h"

extern u8 warning_dialog_list_item;
void fun_Alarm_bk_close_d(void* p,u8 sn)
{    	     u8 SN = sn;//图标在当前页面列表的序    号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
   
            if(p1->item[SN].now_status==STATUS_SELECT)//按ON
        {
            
    sysprintf("fun_Alarm_bk_close_d\r\n");

 sysprintf("item[SN].last_item=%dr\n",page_home.page_top_side[0].last_item);
      sysprintf("page_home.page_top_side[0].now_item=%dr\n",page_home.page_top_side[0].now_item);
    
    
  ///  page_home.page_top_side[0].now_item=page_home.page_top_side[0].last_item;
    page_home.page_top_side[0].now_item=warning_dialog_list_item;
        }
}

