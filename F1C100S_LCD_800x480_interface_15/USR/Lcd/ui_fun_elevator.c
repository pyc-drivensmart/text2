
#include "includes.h"
uint16_t counter;
extern u8 warning_dialog_list_item;
void func_page2_Down_d(void* p,u8 sn)
{
    char display_buf[32];
    u8 SN =1;//图标在当前页面列表的序号
    lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
//        sysprintf(" f_handbreak=%d\r\n",f_handbreak);
//        sysprintf(" f_ignore_handbreak=%d\r\n",f_ignore_handbreak);

       if(f_ignore_handbreak)//不检测
       {
           if(p1->item[SN].now_status==STATUS_TOUCH)//
            {     
//                      counter++;
//                    sysprintf("\r\n Count:%d\r\n",counter);
                   send_FlC200_swtich_cmd(0x1B,0x01);//：开
                   sysprintf("func_page2_UP_d_______ON\r\n");
            }
            else if(p1->item[SN].now_status==STATUS_IDLE)//
            {
             send_FlC200_swtich_cmd(0x1B,0x00);//：关
                   sysprintf("func_page2_UP_d_______OFF\r\n");
            }       
        }
       else
       {
                   
            if(f_handbreak)
            {
                    if(p1->item[SN].now_status==STATUS_TOUCH)//
                {     
//                          counter++;
//                        sysprintf("\r\n Count:%d\r\n",counter);
                       send_FlC200_swtich_cmd(0x1B,0x01);//：开
                       sysprintf("func_page2_UP_d_______ON\r\n");
                }
                else if(p1->item[SN].now_status==STATUS_IDLE)//
                {
                 send_FlC200_swtich_cmd(0x1B,0x00);//：关
                       sysprintf("func_page2_UP_d_______OFF\r\n");
                }
            } 
            else//跳转弹窗
            {
//                page_home.page_top_side[0].now_item=7;
//                warning_dialog_list_item=1;
            }

            
       }
}



void func_page2_Down_up(void* p,u8 sn)
{

}

    
extern LightSystem light_now_sta;//现在状态


void func_page2_Up_d(void* p,u8 sn)
{
    	char display_buf[32];
	u8 SN =0;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
//        sysprintf(" f_handbreak=%d\r\n",f_handbreak);
//        sysprintf(" f_ignore_handbreak=%d\r\n",f_ignore_handbreak);
           if(f_ignore_handbreak)//手刹不检测
           {
                 if(p1->item[SN].now_status==STATUS_TOUCH)//
                {     
//                          counter--;
//                            sysprintf("\r\n Count:%d\r\n",counter);
                       send_FlC200_swtich_cmd(0x1A,0x01);//：开
                       sysprintf("func_page2_Down_d_________ON\r\n");
                            sysprintf("f_fault_on=%d----------------------------\r\n",f_fault_on);
                }
                else if(p1->item[SN].now_status==STATUS_IDLE)//
                {
                    send_FlC200_swtich_cmd(0x1A,0x00);//：关
                       sysprintf("func_page2_Down_d_______OFF\r\n");
                }

            }
           
            else//检测
            {
               if(f_handbreak)
                   {
                        if(p1->item[SN].now_status==STATUS_TOUCH)//
                        {     
//                                  counter--;
//                                    sysprintf("\r\n Count:%d\r\n",counter);
                               send_FlC200_swtich_cmd(0x1A,0x01);//：开
                               sysprintf("func_page2_Down_d_________ON\r\n");
                                    sysprintf("f_fault_on=%d----------------------------\r\n",f_fault_on);
                        }
                        else if(p1->item[SN].now_status==STATUS_IDLE)//
                        {
                            send_FlC200_swtich_cmd(0x1A,0x00);//：关
                               sysprintf("func_page2_Down_d_______OFF\r\n");
                        }
                   }
                else//跳转弹窗
                {
//                    page_home.page_top_side[0].now_item=7;
//                    warning_dialog_list_item=1;
                }
            }
}



void func_page2_Up_up(void* p,u8 sn)
{

}





