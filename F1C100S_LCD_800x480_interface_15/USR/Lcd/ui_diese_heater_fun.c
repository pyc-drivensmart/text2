
//page4

#include "includes.h"

//read me:copy the new item to 'ui_func.c'



extern DiseHeaterSystem now_DiseHeater_status;   //现在状态


void func_page4_V(void* p,u8 sn)
{

}


void func_page4_6_0(void* p,u8 sn)
{

}



void func_page4_6_1(void* p,u8 sn)
{

}



void func_page4_6_2(void* p,u8 sn)
{

}



void func_page4_6_3(void* p,u8 sn)
{

}



void func_page4_6_4(void* p,u8 sn)
{

}



void func_page4_6_5(void* p,u8 sn)
{

}



void func_page4_6_6(void* p,u8 sn)
{

}



extern DiseHeaterSystem now_DiseHeater_status;   //现在状态

void func_page4_add_d(void* p,u8 sn)
{
    
        	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
   
    sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
        if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
        {
        if(now_DiseHeater_status.isPowerOn==1){
            if(now_DiseHeater_status.icon_num<=5)
              send_FlC200_set_cmd_new(0xA2,0x0001,0x01);//+

            sysprintf("func_page4_add----------------------------\r\n");
          //  if(now_DiseHeater_status.icon_num<6)now_DiseHeater_status.icon_num++;
            
    	sysprintf("now_DiseHeater_status.icon_num=%d----------------------------\r\n",now_DiseHeater_status.icon_num);
        }
        }
        
        

}



void func_page4_cut_d(void* p,u8 sn)
{

        	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
   
    sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
        if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
        {
                    if(now_DiseHeater_status.isPowerOn==1){
            if(now_DiseHeater_status.icon_num>=2)
        send_FlC200_set_cmd_new(0xA2,0x0002,0x01);//-
            sysprintf("func_page4_cut----------------------------\r\n");
            }
          //  if(now_DiseHeater_status.icon_num>0)now_DiseHeater_status.icon_num--;
    	sysprintf("now_DiseHeater_status.icon_num=%d----------------------------\r\n",now_DiseHeater_status.icon_num);

        }
        
        
        
        
        
}


void func_page4_add(void* p,u8 sn)
{
    

        


}



void func_page4_bk1(void* p,u8 sn)
{

}



void func_page4_bk2(void* p,u8 sn)
{

}



void func_page4_bk3(void* p,u8 sn)//持续泵油
{

  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	u8 SN =sn;//图标在当前页面列表的序号
	if(p1->item[SN].now_status==STATUS_TOUCH)//
	{     
           send_FlC200_set_cmd_new(0xA1,0x0001,0x01);// ：ON
           sysprintf("func_page4_bk3_________ON\r\n");

	}
    else
    {
           send_FlC200_set_cmd_new(0xA1,0x0000,0x01);// ：OFF
           sysprintf("func_page4_bk3_________OFF\r\n");
    }
}


void func_page4_bk3_up(void* p,u8 sn)//持续泵油
{



}


void func_page4_cut(void* p,u8 sn)//
{
    

}



void func_page4_Ellipse_g(void* p,u8 sn)
{

}


void func_page4_key_up_2(void* p,u8 sn)
{

}



void func_page4_key_up(void* p,u8 sn)
{

}

void func_page4_key_d(void* p,u8 sn)//开关//柴暖加热器设置
{
    
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
   
  ////  sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
    
//    now_DiseHeater_status.heatDissipation=1;
    
            if(p1->item[SN].now_status==STATUS_SELECT)//按ON
        {
//            if(now_DiseHeater_status.heatDissipation==0)
//             {
            now_DiseHeater_status.isPowerOn=1;//ON                    
            send_FlC200_set_cmd_new(0xA0,0x0001,0x01);
          ////  sysprintf("ooooooooooooooooooooooooooooN\r\n");
//            }
//           else//散热不开
//           {
//            now_DiseHeater_status.isPowerOn=0;//OFF            
//           send_FlC200_set_cmd_new(0xA0,0x0000,0x01);

//           }               
            
            
        }
        else if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
        {
            now_DiseHeater_status.isPowerOn=0;//OFF            
           send_FlC200_set_cmd_new(0xA0,0x0000,0x01);

         ///   sysprintf("oFFFFFFFFFFFFFFFFFFFFFFFFFFF\r\n");
        }

}

void func_page4_Ellipse(void* p,u8 sn)
{

}



void func_page4_Ellipse_r(void* p,u8 sn)
{

}


void func_text_Alarm(void* p,u8 sn)
{

}



void func_text_Diesel_heater(void* p,u8 sn)
{

}



void func_Vector_1(void* p,u8 sn)
{

}



void func_page4_alarm_r(void* p,u8 sn)
{

}



void func_page4_alarm_t(void* p,u8 sn)
{

}



void func_page4_alarm_y(void* p,u8 sn)
{

}



void func_Vector_2(void* p,u8 sn)
{

}



void func_Vector_3(void* p,u8 sn)
{

}



