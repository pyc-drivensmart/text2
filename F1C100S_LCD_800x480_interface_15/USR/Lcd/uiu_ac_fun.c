#include "includes.h"

//page5
//read me:copy the new item to 'ui_func.c'
extern ACSystem now_AC_status;   //现在状态
P6_HVAC_CTRL_STATUS page6_ac_ctrl;//空调参数结构体
///HVAC_CTRL_STATUS  Hvac_ctrl_status[MAX_HVAC_NUM];//3
extern void ui_ac_init_b(void)   ;
extern void ui_ac_init_r(void)   ;


extern void send_FlC200_Hvac_cmd(u8 ch,P6_HVAC_CTRL_STATUS* P6_Hvac_ctrl_status_p);//

//AIRXCEL
//5-40C
//41-104F
//void temp_add_F(u8* val_set_p)
//{
//   if(*val_set_p>=98) *val_set_p=99;
//	 else if(*val_set_p<33) *val_set_p=33;
//	 else (*val_set_p)++;
//}
//void temp_add_C(u8* val_set_p)
//{
//   if(*val_set_p>=36) *val_set_p=37;
//	 else if(*val_set_p<1) *val_set_p=1;
//	 else (*val_set_p)++;
//}

//void temp_min_F(u8* val_set_p)
//{
//   if(*val_set_p>99) *val_set_p=99;
//	 else if(*val_set_p<=34) *val_set_p=33;
//	 else (*val_set_p)--;
//}
//void temp_min_C(u8* val_set_p)
//{
//   if(*val_set_p>37) *val_set_p=37;
//	 else if(*val_set_p<=2) *val_set_p=1;
//	 else (*val_set_p)--;
//}

void temp_add_F(u8* val_set_p)
{
   if(*val_set_p>=90) *val_set_p=90;
	 else if(*val_set_p<50) *val_set_p=50;
	 else (*val_set_p)++;
}
//void temp_add_C(u8* val_set_p)
//{
//   if(*val_set_p>=50) *val_set_p=90;
//	 else if(*val_set_p<1) *val_set_p=1;
//	 else (*val_set_p)++;
//}
void temp_add_C(u8* val_set_p)
{
   if(*val_set_p>=32) *val_set_p=32;
	 else if(*val_set_p<10) *val_set_p=10;
	 else (*val_set_p)++;
}
void temp_min_F(u8* val_set_p)
{
   if(*val_set_p>90) *val_set_p=90;
	 else if(*val_set_p<=50) *val_set_p=50;
	 else (*val_set_p)--;
}
//void temp_min_C(u8* val_set_p)//
//{
//   if(*val_set_p>90) *val_set_p=90;
//	 else if(*val_set_p<=50) *val_set_p=50;
//	 else (*val_set_p)--;
//}


void temp_min_C(u8* val_set_p)//10~32
{
   if(*val_set_p>32) *val_set_p=32;
	 else if(*val_set_p<=10) *val_set_p=10;
	 else (*val_set_p)--;
}




extern lcd_dis_item_t AC_item[13+8];//图片缓存区？？

void set_ac_FAN_mode_icon(u8 sn)//互斥处理图片
{
	  u8 i;
    for(i=0;i<3;i++)//选项数
		{
		  if((i+AC_FAN_MODE_SN)!=sn)//超出索引（互斥图片开始索引）
			{
			  AC_item[i+AC_FAN_MODE_SN].now_status = STATUS_IDLE;
				AC_item[i+AC_FAN_MODE_SN].key_type = KEY_TYPE_NORMAL;
			}
			else
			{
			   AC_item[i+AC_FAN_MODE_SN].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 
			
			}
		}
}


void set_ac_mode_icon(u8 sn)//互斥处理图片
{
	  u8 i;
    for(i=0;i<2;i++)//选项数
		{
		  if((i+AC_MODE_SN)!=sn)//超出索引（互斥图片开始索引）
			{
			  AC_item[i+AC_MODE_SN].now_status = STATUS_IDLE;//未选中
				AC_item[i+AC_MODE_SN].key_type = KEY_TYPE_NORMAL;//未选中,可以按下
			}
			else
			{
			   AC_item[i+AC_MODE_SN].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 
			
			}
		}
}



void func_page5_1(void* p,u8 sn)
{

}


void func_page5_add(void* p,u8 sn)//温度加
{

        	u8 SN =sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    
    P6_HVAC_CTRL_STATUS *P6_Hvac_ctrl_status_p = &page6_ac_ctrl;//空调结构体指针
	u8 *val_set_p; //设置温度

//	if(p1->item[SN].now_status==STATUS_TOUCH)//
//	{     
//	sysprintf("func_page5_add-----------------------------\r\n");
//    if(now_AC_status.SetTemp<99)now_AC_status.SetTemp++;

//	}
    //	if(p1->item[SN].now_status==STATUS_SELECT)
      if(p1->item[SN].now_status==STATUS_TOUCH)//
	{ 
		switch(P6_Hvac_ctrl_status_p->sw_mode)
		{   				
				 
			case MODE_COOL:
			//case MODE_DRY:
			  if(Is_uint_Fahrenheit())//
				{
					val_set_p =  &P6_Hvac_ctrl_status_p->Cool_set_temp_f;
					temp_add_F(val_set_p);
                    sysprintf("MODE_COOL_ADD_F----------------------------\r\n");

				}
				else
				{
					val_set_p =  &P6_Hvac_ctrl_status_p->Cool_set_temp;
					temp_add_C(val_set_p);
					sysprintf("MODE_COOL_ADD_C----------------------------\r\n");

				}
                sysprintf("send_FlC200_Hvac_cmd：");
				send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
				break;
				
			case MODE_HEAT_PUMP:
               	  if(Is_uint_Fahrenheit())//F
				{
					val_set_p =  &P6_Hvac_ctrl_status_p->Furnace_set_temp_f;
					temp_add_F(val_set_p);
					 sysprintf("MODE_HEAT_FURNACE_ADD_F----------------------------\r\n");

				}
				else
				{
					val_set_p =  &P6_Hvac_ctrl_status_p->Furnace_set_temp;
					temp_add_C(val_set_p);
                    sysprintf("MODE_HEAT_FURNACE_ADD_C----------------------------\r\n");

				}
                sysprintf("send_FlC200_Hvac_cmd：");
				send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);

				break; 
          
			default:
         send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
				break;
		
//            
            
		}
	}

}



void func_page5_bk2(void* p,u8 sn)
{
}



void func_page5_bk2_b(void* p,u8 sn)
{
}



void func_page5_bk2_r(void* p,u8 sn)
{
}



void func_page5_COOL_up(void* p,u8 sn)
{
}



void func_page5_cut(void* p,u8 sn)//温度减
{

    
    u8 SN =sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    
    P6_HVAC_CTRL_STATUS *P6_Hvac_ctrl_status_p = &page6_ac_ctrl;//空调结构体指针
	u8 *val_set_p; //设置温度

//	if(p1->item[SN].now_status==STATUS_TOUCH)//
//	{     
//	sysprintf("func_page5_add-----------------------------\r\n");
//    if(now_AC_status.SetTemp<99)now_AC_status.SetTemp++;

//	}
    
    //	if(p1->item[SN].now_status==STATUS_SELECT)
	      if(p1->item[SN].now_status==STATUS_TOUCH)//

    { 
		switch(P6_Hvac_ctrl_status_p->sw_mode)
		{   				
				 
			case MODE_COOL:
			//case MODE_DRY:
			  if(Is_uint_Fahrenheit())//
				{
                    sysprintf("MODE_COOL_CUT_F----------------------------\r\n");
					val_set_p =  &P6_Hvac_ctrl_status_p->Cool_set_temp_f;
					temp_min_F(val_set_p);
				}
				else
				{                    
                    sysprintf("MODE_COOL_ADD_C----------------------------\r\n");
					val_set_p =  &P6_Hvac_ctrl_status_p->Cool_set_temp;
					temp_min_C(val_set_p);
				}
				sysprintf("send_FlC200_Hvac_cmd：");
                send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
				break;
				
            case MODE_HEAT_PUMP:
			   if(Is_uint_Fahrenheit())//F
				{
                    sysprintf("MODE_HEAT_FURNACE_CUT_F----------------------------\r\n");
					val_set_p =  &P6_Hvac_ctrl_status_p->Furnace_set_temp_f;
					temp_min_F(val_set_p);
				}
				else
				{
                    sysprintf("MODE_HEAT_FURNACE_CUT_C----------------------------\r\n");
					val_set_p =  &P6_Hvac_ctrl_status_p->Furnace_set_temp;
					temp_min_C(val_set_p);
				}
				sysprintf("send_FlC200_Hvac_cmd：");
                send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
				break;
//			case MODE_HEAT_FURNACE://加热
//                if(Is_uint_Fahrenheit())//F
//				{
//                    sysprintf("MODE_HEAT_FURNACE_CUT_F----------------------------\r\n");
//					val_set_p =  &P6_Hvac_ctrl_status_p->Furnace_set_temp_f;
//					temp_min_F(val_set_p);
//				}
//				else
//				{
//                    sysprintf("MODE_HEAT_FURNACE_CUT_C----------------------------\r\n");
//					val_set_p =  &P6_Hvac_ctrl_status_p->Furnace_set_temp;
//					temp_min_C(val_set_p);
//				}
//				sysprintf("send_FlC200_Hvac_cmd：");
//                send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
                
			default:
                         sysprintf("send_FlC200_Hvac_cmd：");
                send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
				break;
		}
	}
}





void func_page5_COOL_b_d(void* p,u8 sn)//模式：制冷
{                
    P6_HVAC_CTRL_STATUS *P6_Hvac_ctrl_status_p = &page6_ac_ctrl;//空调结构体指针

	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
		now_AC_status.mode=1;
        
        page6_ac_ctrl.sw_mode=MODE_COOL;//模式：制冷
		sysprintf("send_FlC200_Hvac_cmd：");
        send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);

        ui_ac_init_b();//模式转化
        
        sysprintf("now_AC_status.mode=%d-----------------------------\r\n",now_AC_status.mode);

	}
    //else if(p1->item[SN].now_status==STATUS_SELECT)
	//{  
                //ui_ac_init_b();//模式转化
    //}
}


u8 p5_HEATnum;
void func_page5_HEAT_r_d(void* p,u8 sn)//模式：制热
{                
            P6_HVAC_CTRL_STATUS *P6_Hvac_ctrl_status_p = &page6_ac_ctrl;//空调结构体指针

                u8 SN = sn;//图标在当前页面列表的序号
          lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
            if(p1->item[SN].now_status==STATUS_SELECT)
            {  
                page6_ac_ctrl.sw_mode=MODE_HEAT_PUMP;//模式：制热
                now_AC_status.mode=2;
				sysprintf("send_FlC200_Hvac_cmd：");
                send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
                        ui_ac_init_r();//模式转化
        sysprintf("now_AC_status.mode=%d-----------------------------\r\n",now_AC_status.mode);
            }
  // else if(p1->item[SN].now_status==STATUS_SELECT)
	//{  
  //             ui_ac_init_b();//模式转化
  // }

}



void func_page5_HEAT_up(void* p,u8 sn)
{

}





u8 p5_keynum;

u8 old_p5_mode;
void func_page5_key_d(void* p,u8 sn)//开关
{                
    u8 SN = sn;//图标在当前页面列表的序号
    lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    P6_HVAC_CTRL_STATUS *P6_Hvac_ctrl_status_p = &page6_ac_ctrl;//空调结构体指针
        if(p1->item[SN].now_status==STATUS_SELECT)//按ON恢复关闭前状态（排查关机）
        {
            now_AC_status.isPowerOn=1;
            
            if(page6_ac_ctrl.sw_mode!=MODE_OFF)old_p5_mode=page6_ac_ctrl.sw_mode;
            page6_ac_ctrl.sw_mode=old_p5_mode;//恢复
            page6_ac_ctrl.fan_speed|=0x20;//开启风速

//            sysprintf("send_FlC200_Hvac_cmd：");
            send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
//            sysprintf("ON-----------------------------\r\n");
        }
        else if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
        {
                    now_AC_status.isPowerOn=0;

            if(page6_ac_ctrl.sw_mode!=MODE_OFF)old_p5_mode=page6_ac_ctrl.sw_mode;
            page6_ac_ctrl.sw_mode=MODE_OFF;
            page6_ac_ctrl.fan_speed&=0x0F;//清除风速
//            sysprintf("send_FlC200_Hvac_cmd：");
            send_FlC200_Hvac_cmd(1,P6_Hvac_ctrl_status_p);
//            sysprintf("OFF-----------------------------\r\n");

        }
        
//        

}



void func_page5_key_up(void* p,u8 sn)
{

}


void func_page5_LOW_b_d(void* p,u8 sn)
{
    
    	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  
		now_AC_status.Fan=1;
        set_ac_FAN_mode_icon(sn);
        
        page6_ac_ctrl.fan_speed &=0x00;
		page6_ac_ctrl.fan_speed |=0x23 ;
		sysprintf("send_FlC200_Hvac_cmd：");
        send_FlC200_Hvac_cmd(1,&page6_ac_ctrl);
	}
        sysprintf("now_AC_status.Fan=%d-----------------------------\r\n",now_AC_status.Fan);

    
    
}

void func_page5_LOW_up(void* p,u8 sn)
{

}


void func_page5_MED_b_d(void* p,u8 sn)
{

        	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  
//		now_AC_status.Fan=2;
        set_ac_FAN_mode_icon(sn);
        
        page6_ac_ctrl.fan_speed &=0x00;
		page6_ac_ctrl.fan_speed |=0x22 ;
//		sysprintf("send_FlC200_Hvac_cmd：");
send_FlC200_Hvac_cmd(1,&page6_ac_ctrl);

        
	}
//    sysprintf("now_AC_status.Fan=%d-----------------------------\r\n",now_AC_status.Fan);

}





void func_page5_HIGH_b_d(void* p,u8 sn)
{

            	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  
		now_AC_status.Fan=3;
        set_ac_FAN_mode_icon(sn);
        
        page6_ac_ctrl.fan_speed &=0x00;
		page6_ac_ctrl.fan_speed |=0x21 ;
//		sysprintf("send_FlC200_Hvac_cmd：");
        send_FlC200_Hvac_cmd(1,&page6_ac_ctrl);

	}

//        sysprintf("now_AC_status.Fan=%d-----------------------------\r\n",now_AC_status.Fan);
    
    
    

}

void func_page5_LOW_r_d(void* p,u8 sn)
{
	sysprintf("func_page5_LOW_r_d----------------------------\r\n");
    
            	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  
		now_AC_status.Fan=4;
        set_ac_FAN_mode_icon(sn);
        
        page6_ac_ctrl.fan_speed_heat &=0x00;
		page6_ac_ctrl.fan_speed_heat |=0x23 ;
		sysprintf("send_FlC200_Hvac_cmd：");
        send_FlC200_Hvac_cmd(1,&page6_ac_ctrl);

	}
        sysprintf("now_AC_status.Fan=%d-----------------------------\r\n",now_AC_status.Fan);

    
}

void func_page5_MED_r_d(void* p,u8 sn)
{
	sysprintf("func_page5_MED_r_d----------------------------\r\n");
    
            	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  
		now_AC_status.Fan=5;
   set_ac_FAN_mode_icon(sn);
        
                page6_ac_ctrl.fan_speed_heat &=0x00;
		page6_ac_ctrl.fan_speed_heat |=0x22 ;
		sysprintf("send_FlC200_Hvac_cmd：");
send_FlC200_Hvac_cmd(1,&page6_ac_ctrl);

	}
        sysprintf("now_AC_status.Fan=%d-----------------------------\r\n",now_AC_status.Fan);

}
void func_page5_HIGH_r_d(void* p,u8 sn)
{
	sysprintf("func_page5_HIGH_r_d----------------------------\r\n");
    
            	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH)
	{  
		now_AC_status.Fan=6;
   set_ac_FAN_mode_icon(sn);
        
                page6_ac_ctrl.fan_speed_heat &=0x00;
		page6_ac_ctrl.fan_speed_heat |=0x21 ;
		sysprintf("send_FlC200_Hvac_cmd：");
send_FlC200_Hvac_cmd(1,&page6_ac_ctrl);

	}
        sysprintf("now_AC_status.Fan=%d-----------------------------\r\n",now_AC_status.Fan);

    
    
    
}



void func_page5_HIGH_up(void* p,u8 sn)
{
}

void func_page5_MED_up(void* p,u8 sn)
{

}



void func_page5_text1(void* p,u8 sn)
{

}



void func_page5_text2(void* p,u8 sn)
{

}

void func_paeg5_el_up(void* p,u8 sn)
{

}


