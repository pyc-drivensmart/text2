#include "includes.h"

/* read me
2022-11-18
How to add new ui picture to project:
1. Copy the new pic to "..\USR\ui_data"
2. Run"deel_all_png_file_to_c.exe"(at"ui_data"folder)
3. Copy the new definition of coordinates( such as"#define X_xxxxxxxxx""#define Y_xxxxxxxxxxx"in "ui_list_xy.h") to file"sys_ui_xxxxxxxx.h",and set them val.
4. Copy the new func (such as"void func_xxxxxxxxx(void* p,u8 sn)" in "ui_func_data.c" )to file"ui_func_xxxxxx".
   Hard to find the new definition or new func in step 3 and 4? 
	 You can put all the new item pic to the another folder and do"deel_all_png_file_to_c.exe",
	 Is the item data is all new?

5 Refer to"sys_ui_pro_xxxxx.c" set the page and init,if necessary fill the"void func_xxxxxxxxx(void* p,u8 sn)" .


PS:
	//home page contain 3 main area:left,top,main diaplay
	//-------------------------|
	//|   |      top(3)        |
	//| l |--------------------|
	//| e |                    |
	//| f |                    |
	//| t |      main(n item)  |
	//|(5)|                    |
	//-------------------------|



*/




lcd_dis_page_t page_air;
lcd_dis_home_t page_home;




u8 dis_page_item = 0;//0 init  step1-n
bool f_force_to_target_top_page = FALSE;





#define X_left_side 0
#define Y_left_side 0
//lcd_dis_item_t t_left_side={(unsigned char*)left_side,(unsigned char*)left_side,(unsigned char*)left_side,25021,25021,25021,STATUS_IDLE,STATUS_IDLE,X_left_side,Y_left_side,X_left_side+140,Y_left_side+600};

extern void func_tanks_b_setup_d(void* p,u8 sn);
extern void func_tanks_b_setup_u(void* p,u8 sn);
extern const unsigned char power_b_setup_d[4773UL + 1];
extern const unsigned char power_b_setup_u[4497UL + 1];
extern const unsigned char power_b_btn2[];
lcd_dis_item_t t_tanks_b_setup_d={(unsigned char*)power_b_setup_d,(unsigned char*)power_b_setup_d,(unsigned char*)power_b_setup_d,0,0,4774,4774,4774,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_power_b_setup_d,Y_power_b_setup_d,X_power_b_setup_d+126,Y_power_b_setup_d+71,0,&func_tanks_b_setup_d};
lcd_dis_item_t t_tanks_b_setup_u={(unsigned char*)power_b_setup_u,(unsigned char*)power_b_setup_u,(unsigned char*)power_b_setup_u,0,0,4498,4498,4498,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_power_b_setup_u,Y_power_b_setup_u,X_power_b_setup_u+126,Y_power_b_setup_u+71,0,&func_tanks_b_setup_u};

lcd_dis_item_t t_power_b_setup2_d={(unsigned char*)power_b_setup_d,(unsigned char*)power_b_setup_d,(unsigned char*)power_b_setup_d,0,0,4774,4774,4774,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_power_b_setup_d,Y_power_b_setup_d,X_power_b_setup_d+126,Y_power_b_setup_d+71,0,&func_tanks_b_setup_d};
lcd_dis_item_t t_power_b_setup2_u={(unsigned char*)power_b_setup_u,(unsigned char*)power_b_setup_u,(unsigned char*)power_b_setup_u,0,0,4498,4498,4498,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_power_b_setup_u,Y_power_b_setup_u,X_power_b_setup_u+126,Y_power_b_setup_u+71,0,&func_tanks_b_setup_u};

lcd_dis_item_t t_loads_b_btn3={(unsigned char*)power_b_btn2,(unsigned char*)power_b_btn2,(unsigned char*)power_b_btn2,0,0,1723,1723,1723,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,388,514,388+124,514+71,0,&func_power_b_btn2};
	
	

extern void func_system_b_alarm_d(void* p,u8 sn);
extern void func_system_b_alarm_u(void* p,u8 sn);
//extern const unsigned char power_b_alarm_d[3578UL + 1];
//extern const unsigned char power_b_alarm_u[3345UL + 1];
//lcd_dis_item_t t_system_b_alarm_d={(unsigned char*)power_b_alarm_d,(unsigned char*)power_b_alarm_d,(unsigned char*)power_b_alarm_d,0,0,3579,3579,3579,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_b_alarm_d,Y_system_b_alarm_d,X_system_b_alarm_d+124,Y_system_b_alarm_d+71,0,&func_system_b_alarm_d};
//lcd_dis_item_t t_system_b_alarm_u={(unsigned char*)power_b_alarm_u,(unsigned char*)power_b_alarm_u,(unsigned char*)power_b_alarm_u,0,0,3346,3346,3346,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_b_alarm_u,Y_system_b_alarm_u,X_system_b_alarm_u+124,Y_system_b_alarm_u+71,0,&func_system_b_alarm_u};
	
extern void func_top_fault(void* p,u8 sn);
lcd_dis_item_t t_top_fault={0,0,0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_top_warning_icon_new-10,Y_top_warning_icon_new,X_top_warning_icon_new+50,Y_top_warning_icon_new+60,0,&func_top_fault};
extern void func_top_power(void* p,u8 sn);
lcd_dis_item_t t_top_power={0,0,0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_top_power_d-10,Y_top_power_d,X_top_power_d+50,Y_top_power_d+60,0,&func_top_power};

	
//界面info 按下
lcd_dis_item_t *p_info_d[INFO_ICO_NUM]=
{
&t_top_fault,  //0
&t_top_power,
};

//界面left 弹起
lcd_dis_item_t *p_info_u[LEFT_SIDE_ICO_NUM]=
{
&t_top_fault,  //0
&t_top_power,
};



//界面left 按下
lcd_dis_item_t *p_left_side_d[LEFT_SIDE_ICO_NUM]=
{
&t_menu_home_d,  //0
&t_menu_power_d, //1
&t_menu_lights_d,//2
&t_menu_loads_d, //3
//&t_menu_tanks_d, //4	
&t_menu_system_d,//5
};

//界面left 弹起
lcd_dis_item_t *p_left_side_u[LEFT_SIDE_ICO_NUM]=
{
&t_menu_home_u,  //0
&t_menu_power_u, //1
&t_menu_lights_u,//2
&t_menu_loads_u, //3
//&t_menu_tanks_u, //4	
&t_menu_system_u,//5
};





	//power界面top 按下
lcd_dis_item_t *p_power_top_side_d[TOP_SIDE_ICO_NUM]=
{
	&t_power_b_power_d,
	&t_power_b_system_d,	
	&t_power_b_alarm_d,
	&t_power_b_chart_d,  
	&t_power_b_btn5,
	&t_power_b_btn6,	
	&t_power_b_setup2_d,


};

//power界面top 弹起
lcd_dis_item_t *p_power_top_side_u[TOP_SIDE_ICO_NUM]=
{
	&t_power_b_power_u,
	&t_power_b_system_u,
	&t_power_b_alarm_u,// &t_power_b_alarm_u,
	&t_power_b_chart_u,	  
	&t_power_b_btn5,
	&t_power_b_btn6,	
	&t_power_b_setup2_u,
};


	//LIGHTS界面top 按下
lcd_dis_item_t *p_lights_top_side_d[TOP_SIDE_ICO_NUM]=
{
  &t_lights_b_lights_d,
	&t_power_b_btn5,
	&t_power_b_btn6,
	&t_power_b_btn2,
	&t_power_b_btn3,
	&t_power_b_btn4,
	&t_power_b_btn4,	//&t_lights_b_setup_d,//让这个地方空白，要不然触摸过不去


};

//LIGHT界面top 弹起
lcd_dis_item_t *p_lights_top_side_u[TOP_SIDE_ICO_NUM]=
{
  &t_lights_b_lights_u,
	&t_power_b_btn5,
	&t_power_b_btn6,
	&t_power_b_btn2,
	&t_power_b_btn3,
	&t_power_b_btn4,
	&t_power_b_btn4,	//&t_lights_b_setup_u,//让这个地方空白，要不然触摸过不去
};


	//loadS界面top 按下
lcd_dis_item_t *p_loads_top_side_d[TOP_SIDE_ICO_NUM]=
{
  &t_loads_b_loads_d,
	&t_loads_b_Motors_d,
	&t_power_b_btn5,
	&t_power_b_btn6,
	&t_loads_b_btn3,
	&t_power_b_btn4,
	&t_power_b_btn4,	//&t_loads_b_setup_d,//让这个地方空白，要不然触摸过不去


};

//loads界面top 弹起
lcd_dis_item_t *p_loads_top_side_u[TOP_SIDE_ICO_NUM]=
{
  &t_loads_b_loads_u,
	&t_loads_b_Motors_u,
	&t_power_b_btn5,
	&t_power_b_btn6,
	&t_loads_b_btn3,
	&t_power_b_btn4,
	&t_power_b_btn4,	//&t_loads_b_setup_u,//让这个地方空白，要不然触摸过不去
};

	//TANKS界面top 按下
lcd_dis_item_t *p_tanks_top_side_d[TOP_SIDE_ICO_NUM]=
{
  &t_tanks_b_tanks_d,
	&t_power_b_btn5,
	&t_power_b_btn6,
	&t_power_b_btn2,
	&t_power_b_btn3,
	&t_power_b_btn4,
	&t_tanks_b_setup_d,


};

//TANKS界面top 弹起
lcd_dis_item_t *p_tanks_top_side_u[TOP_SIDE_ICO_NUM]=
{
  &t_tanks_b_tanks_u,// &t_power_b_alarm_u,
	&t_power_b_btn5,
	&t_power_b_btn6,
	&t_power_b_btn2,
	&t_power_b_btn3,
	&t_power_b_btn4,
	&t_tanks_b_setup_u,
};






	//SYSTEM界面top 按下
lcd_dis_item_t *p_system_top_side_d[TOP_SIDE_ICO_NUM]=
{
  &t_system_b_system_d,
	&t_system_b_info_d,	
	&t_system_b_alarm_d,
	&t_system_b_acc_d,
	&t_power_b_btn5,
	&t_power_b_btn6,	
	

	&t_power_b_btn6,	//&t_loads_b_setup_d,//让这个地方空白，要不然触摸过不去
  

};

//SYSTEM界面top 弹起
lcd_dis_item_t *p_system_top_side_u[TOP_SIDE_ICO_NUM]=
{
  &t_system_b_system_u,// 
	&t_system_b_info_u,	
	&t_system_b_alarm_u,
	&t_system_b_acc_u,
	&t_power_b_btn5,
	&t_power_b_btn6,	
	&t_power_b_btn6,	//&t_loads_b_setup_d,//让这个地方空白，要不然触摸过不去
	
};

//////////////////////////////////////////////////////////////////////////////
#define HOME_TEST_TOP_ITEM_NUM 7
lcd_dis_item_t *p_home_top_item_5_test_u[HOME_TEST_TOP_ITEM_NUM]={//底栏选项
//	&t_bottom_home_up_5_new,
//	&t_bottom_power_up_5_new,
//	&t_bottom_alarm_up_5_new,
//	&t_bottom_setup_up_5_new,
    &t_new_Light_up_5     ,
    &t_new_Elevator_up_5  ,
    &t_new_Halo_up_5      ,
    &t_new_heater_up_5,

    &t_new_AC_up_5        ,
    &t_new_Setup_up_5     ,
    
    &t_warn_no,
};
lcd_dis_item_t *p_home_top_item_5_test_d[HOME_TEST_TOP_ITEM_NUM]={
//	&t_bottom_home_down_5_new,
//	&t_bottom_power_down_5_new,
//	&t_bottom_alarm_down_5_new,
//	&t_bottom_setup_down_5_new,
    
    &t_new_Light_d_5     ,
    &t_new_Elevator_d_5  ,
    &t_new_Halo_d_5      ,
    &t_new_heater_d_5,

    &t_new_AC_d_5        ,
    &t_new_Setup_d__5     ,
    

    &t_warn_no,
};



lcd_dis_item_t test_home_top_item[HOME_TEST_TOP_ITEM_NUM];
///////////////////////////////////////////////////////////////////////////


lcd_dis_item_t info_item[INFO_ICO_NUM];
lcd_dis_item_t left_side_item[LEFT_SIDE_ICO_NUM];
lcd_dis_item_t power_top_side_item[TOP_SIDE_ICO_NUM];
lcd_dis_item_t lights_top_side_item[TOP_SIDE_ICO_NUM];
lcd_dis_item_t loads_top_side_item[TOP_SIDE_ICO_NUM];
lcd_dis_item_t tanks_top_side_item[TOP_SIDE_ICO_NUM];
lcd_dis_item_t system_top_side_item[TOP_SIDE_ICO_NUM];
lcd_dis_item_t carinfo_top_side_item[TOP_SIDE_ICO_NUM];

u16 slide_x = 0;
u16 slide_y = 0;

u8 const table_week[12]={0,3,3,6,1,4,6,2,5,0,3,5};                                                                                                                                               
u8 RTC_Get_Week(u16 year,u8 month,u8 day)
{    
       u16 temp2;
       u8 yearH,yearL;
      
       yearH=year/100;     yearL=year%100;
       if (yearH>19)yearL+=100;
       temp2=yearL+yearL/4;
       temp2=temp2%7;
       temp2=temp2+day+table_week[month-1];
       if (yearL%4==0&&month<3)temp2--;
       return(temp2%7);
}

void disply_system_top_side_name(bool upgrage)
{
//	 char display_buf[32];
	 lcd_dis_item_t *p;//,*p2;
	if(upgrage)
	{
		p=&system_top_side_item[1];
	  Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
    if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item == TOP_SIDE_PAGE_SYSTEM_ACC)
		Virtual_LCD_Draw_String_ARGB_align_center_16_4bit((p->x_val+p->x_end_val)/2,p->y_val+30,"Accessories",0xFF78baf7,0,1,1);
		else
		Virtual_LCD_Draw_String_ARGB_align_center_16_4bit((p->x_val+p->x_end_val)/2,p->y_val+30,"Accessories",0xFFe2e2e4,0,1,1);
		
		p=&system_top_side_item[2];
	  Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
    if(page_home.page_top_side[LEFT_SIDE_PAGE_SYSTEM].now_item == TOP_SIDE_PAGE_SYSTEM_INFO)
		Virtual_LCD_Draw_String_ARGB_align_center_16_4bit((p->x_val+p->x_end_val)/2,p->y_val+30,"Info",0xFF78baf7,0,1,1);
		else
		Virtual_LCD_Draw_String_ARGB_align_center_16_4bit((p->x_val+p->x_end_val)/2,p->y_val+30,"Info",0xFFe2e2e4,0,1,1);
	}
	 

}
//Virtual_LCD_Draw_String_ARGB48(150+50,100+15,"My love 22.5",(ARGB_white),0,1,1);
//			 Virtual_LCD_Draw_String_ARGB_32_4bit(150+50,100+100,"Climate 552",(ARGB_white),0,1,1);
void disply_top_info(bool upgrage)
{
	 //u16 i,x;
	 char display_buf[16];
	 u16 temp;
   static TEMP_STATUS old_temp_status;
	 static u8 old_base_return_status_uint = 0;
	 if((memcmp(&temp_status,&old_temp_status,sizeof(TEMP_STATUS)))||(old_base_return_status_uint != base_return_status.uint)||upgrage)
   {
     memcpy(&old_temp_status,&temp_status,sizeof(TEMP_STATUS));
		 old_base_return_status_uint = base_return_status.uint;
		 
		 
		 Virtual_LCD_Draw_Rectangle_ARGB32(434,7,12*16,24,Virtual_LCDbuff2,ARGB_clear);
		 if((base_return_status.uint&0x0C)==0x04)//F
		 {
			 
			   if(temp_status.Temp_in==0xFFFF)
				 {
					 sprintf(display_buf,"-- F  ");
				 }
				 else if(temp_status.Temp_in>0x8000)
				 {
					 temp = temp_status.Temp_in&0x7FFF;
					// temp = temp*18+320;
					 sprintf(display_buf,"-%d F  ",temp/10);
				 }
				 else
				 {
					 temp = temp_status.Temp_in;
					 sprintf(display_buf," %d F   ",temp/10);
				 }
				 
				 
				 Virtual_LCD_Draw_String_ARGB_24_4bit(529,7,display_buf,(ARGB_white),0,1,1);				 
				 Virtual_LCD_Draw_String_o(529,7,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(ARGB_white),0,1,1);

				 
				 if(temp_status.Temp_out==0xFFFF)
				 {
					 sprintf(display_buf,"-- F  ");
				 }
				 else if(temp_status.Temp_out>0x8000)
				 {
					 temp = temp_status.Temp_out&0x7FFF;
					 sprintf(display_buf,"-%d F   ",temp/10);
				 }
				 else
				 {
					 temp = temp_status.Temp_out;
					 sprintf(display_buf," %d F   ",temp/10);
				 }
				 Virtual_LCD_Draw_String_ARGB_24_4bit(434,7,display_buf,(ARGB_white),0,1,1);				 
		    Virtual_LCD_Draw_String_o(434,7,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(ARGB_white),0,1,1);

		 }
		 else//c
		 {
			 
			 if(temp_status.Temp_in==0xFFFF)
				 {
					 sprintf(display_buf,"-- C  ");
				 }
		 else if(temp_status.Temp_in>0x8000)
		 {
			 temp = temp_status.Temp_in&0x7FFF;
			// temp = temp*18+320;
			 sprintf(display_buf,"-%d C  ",temp/10);
		 }
		 else
		 {
			 temp = temp_status.Temp_in;
			 sprintf(display_buf," %d C   ",temp/10);
		 }
		 Virtual_LCD_Draw_String_ARGB_24_4bit(529,7,display_buf,(ARGB_white),0,1,1);
		 Virtual_LCD_Draw_String_o(529,7,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(ARGB_white),0,1,1);
		 
		 if(temp_status.Temp_out==0xFFFF)
		 {
					 sprintf(display_buf,"-- C  ");
		 }
		 else if(temp_status.Temp_out>0x8000)
		 {
			 temp = temp_status.Temp_out&0x7FFF;
			 sprintf(display_buf,"-%d C   ",temp/10);
		 }
		 else
		 {
			 temp = temp_status.Temp_out;
			 sprintf(display_buf," %d C   ",temp/10);
		 }
	 			 
		 Virtual_LCD_Draw_String_ARGB_24_4bit(434,7,display_buf,(ARGB_white),0,1,1);
		 Virtual_LCD_Draw_String_o(434,7,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(ARGB_white),0,1,1);
	 }
		 
	 

		 Virtual_LCD_Draw_String_ARGB_16_4bit(434,31,"Outdoor",(ARGB_gray),0,1,1);
		  Virtual_LCD_Draw_String_ARGB_16_4bit(529,31,"Indoor",(ARGB_gray),0,1,1);
		 
		 if(upgrage==FALSE)
		Virtual_LCD_Upgrate_formx1y1(434,0,12*16,128);

	 }
}



void disply_time_info(bool upgrage)
{
	static u32 IdelTime_500MS;
	static bool flash_dis = FALSE;
	char display_buf[16];
	static TIME_STATUS old_time_return_status;
	u16 x_temp;
	
	if((memcmp(&time_return_status,&old_time_return_status,sizeof(TIME_STATUS)))||upgrage||CntDelayTime(&IdelTime_500MS,TIME_ONE_MS*1000))
	{
		memcpy(&old_time_return_status,&time_return_status,sizeof(TIME_STATUS));
		if(CntDelayTime(&IdelTime_500MS,TIME_ONE_MS*1000))
		{
			ResetDelayTime(&IdelTime_500MS); 
			if(flash_dis) 
				flash_dis = FALSE;
			else
				flash_dis = TRUE;
		}
    // 1. 清除时间显示区域旧内容（覆盖时间绘制位置）
	Virtual_LCD_Draw_Rectangle_ARGB32(0,0,127+20,35+20,Virtual_LCDbuff2,ARGB_clear);//解决时间重叠
        
		if(time_return_status.format&0x80)//12h
		{
			if(time_return_status.hour==0)
				sprintf(display_buf,"12:%02dAM",time_return_status.min);
		 	else if(time_return_status.hour<12)				
			  sprintf(display_buf,"%02d:%02dAM",time_return_status.hour,time_return_status.min);
		 	else if(time_return_status.hour==12)		
				sprintf(display_buf,"%02d:%02dAM",time_return_status.hour,time_return_status.min);
			else
				sprintf(display_buf,"%02d:%02dPM",time_return_status.hour-12,time_return_status.min);
		}
		else			    
			sprintf(display_buf,"%02d:%02d",time_return_status.hour,time_return_status.min);//24h
         Virtual_LCD_Draw_Rectangle_ARGB32(0,0,160,57+7,Virtual_LCDbuff2,ARGB_clear);//解决时间重叠
        Virtual_LCD_Draw_String_ARGB_32_4bit_bold(23,29,display_buf,(ARGB_white),0,1,1);//display time

        
           // 2. 清除日期显示区域旧内容（新增）
        Virtual_LCD_Draw_Rectangle_ARGB32(160-12, 29, 150+40, 16+10, Virtual_LCDbuff2, ARGB_clear);//xywh
            // 先定义月份名称表 
            const char *month_str[] = {
                "", "January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"
            };

            // 从结构体中取出年月日
            uint8_t day  = time_return_status.day;
            uint8_t mon  = time_return_status.mon;
            uint16_t year = time_return_status.year + 2000;

            // 判断 day 对应的英文序数后缀（st, nd, rd, th）
            const char *suffix;
            if (day % 10 == 1 && day != 11)
                suffix = "st";
            else if (day % 10 == 2 && day != 12)
                suffix = "nd";
            else if (day % 10 == 3 && day != 13)
                suffix = "rd";
            else
                suffix = "th";

            // 组合完整日期字符串 → "July 5th 2025"
//            sprintf(display_buf, "%s %d%s %d", month_str[mon], day, suffix, year);
            
              sprintf(display_buf, "%s %d %d", month_str[mon], day, year);
          
            

            // 显示到 LCD 指定位置
        //    Virtual_LCD_Draw_String_ARGB_16_4bit(163, 29, display_buf, (ARGB_darkGray), 0, 1, 1);
            Virtual_LCD_Draw_String_ARGB_24_4bit(163, 29, display_buf, (ARGB_darkGray), 0, 1, 1);

                        
            
		 
//		if(upgrage==FALSE)
//			Virtual_LCD_Upgrate_formx1y1(30,10,430,30);
            // 3. 调整刷新范围，包含时间和日期
        if(upgrage==FALSE)
         // Virtual_LCD_Upgrate_formx1y1(0, 0, 300, 40);
       //   Virtual_LCD_Upgrate_formx1y1(0, 0, 300, 60);
          Virtual_LCD_Upgrate_formx1y1(0, 0, 440, 60);

//            Virtual_LCD_Upgrate_formx1y1(20, 10, 300, 40);
        
	 }
    
     
     
     
     
     
}



void disply_start_battery_info(bool upgrage)
{
	 char display_buf[16];
	 u16 temp;
   static u16 old_main_battery_status_V;
	 if((main_battery_status.V != old_main_battery_status_V)||upgrage)
   {
     old_main_battery_status_V = main_battery_status.V;
		 
		   Virtual_LCD_Draw_Rectangle_ARGB32(637,7,12*8,24,Virtual_LCDbuff2,ARGB_clear);
			 temp = main_battery_status.V;
		   if(temp>600)
			  sprintf(display_buf,"    -- V  ");
			 else
				sprintf(display_buf," %d.%1dV  ",temp/10,temp%10); 
		
		 Virtual_LCD_Draw_String_ARGB_24_4bit(637,7,display_buf,(ARGB_white),0,1,1);

		 Virtual_LCD_Draw_String_ARGB_16_4bit(637,31,"Start Battery",(ARGB_gray),0,1,1);

		 if(upgrage==FALSE)
		Virtual_LCD_Upgrate_formx1y1(637,0,12*8,128);

	 }
}


#define X_printf_form  140 
#define Y_printf_form  60
#define X_printf_to  1024
#define Y_printf_to  516
#define Row_pitch 20
#define Char_pitch 16

#define MAX_LINE_LEN 22
#define MAX_CHAR_LEN 100
char DisplayBuf[MAX_LINE_LEN][MAX_CHAR_LEN];
u8 DisplayBuf_R_p = 0;
u8 DisplayBuf_W_p = 0;
bool DisplayBuf_full = FALSE;


void fill_DisplayBuf(char* buf)
{
	u8 i=0;
		u16 x = 0;;
	 
	while(buf[i]!='\0')
	{
		DisplayBuf[DisplayBuf_W_p][i]=buf[i];
		//sysprintf("*%X ",buf[i]);
		if((buf[i]>=' ')&&(buf[i]<='~'))
		x+=(glyph_dsc_16_4bit_bold[buf[i]-0x20].adv_w);
		else
			x+=(glyph_dsc_16_4bit_bold[0].adv_w);
		if(x>(X_printf_to-(X_printf_form)))
		{
			//sysprintf("6666666666666666666666666666");
				break;
		
		}
    if(i>=(MAX_CHAR_LEN-2))
		{	
			//sysprintf("666666666677666");
			break;
		}

		
		//buf++;
		i++;
		
	}
	DisplayBuf[DisplayBuf_W_p][i]=0;
	//sysprintf("\r\n -i:%d,DisplayBuf_W_p %d,%X,%X,%X",i,DisplayBuf_W_p,DisplayBuf[DisplayBuf_W_p][0],DisplayBuf[DisplayBuf_W_p][1],DisplayBuf[DisplayBuf_W_p][2]);
	
	DisplayBuf_W_p++;
	if(DisplayBuf_W_p>=MAX_LINE_LEN)
	{
		DisplayBuf_full = TRUE;
		DisplayBuf_W_p =0;
	}
	
	
}

void page_printf_DisplayBuf(bool Upgrape)
{
  static u8 last_DisplayBuf_W_p = 0;
	static bool f_last_disply_debug_val = FALSE;
	u8 Temp_DisplayBuf_R_p = 0;
	u8 i;

	
	if(f_last_disply_debug_val != f_disply_debug_val)
	{
				if(f_last_disply_debug_val==FALSE)
				{
						DisplayBuf_R_p = 0;
						DisplayBuf_W_p = 0;
					  last_DisplayBuf_W_p = 0;
						DisplayBuf_full = FALSE;
					 //clear;
						Virtual_LCD_Draw_Rectangle_ARGB32(X_printf_form,Y_printf_form,X_printf_to-X_printf_form,Y_printf_to-Y_printf_form,Virtual_LCDbuff2,ARGB_clear);
						
				}
				else
				{
				   //clear;
						Virtual_LCD_Draw_Rectangle_ARGB32(X_printf_form,Y_printf_form,X_printf_to-X_printf_form,Y_printf_to-Y_printf_form,Virtual_LCDbuff2,ARGB_clear);
						Virtual_LCD_Upgrate();
				}
				f_last_disply_debug_val = f_disply_debug_val;
	}
	
	if(f_disply_debug_val)
	 {
		  
			if(last_DisplayBuf_W_p!=DisplayBuf_W_p)
			{
				 last_DisplayBuf_W_p=DisplayBuf_W_p;
				 if(DisplayBuf_full)
				 {
					 //clear;
						Virtual_LCD_Draw_Rectangle_ARGB32(X_printf_form,Y_printf_form,X_printf_to-X_printf_form,Y_printf_to-Y_printf_form,Virtual_LCDbuff2,ARGB_clear);
						
					 if(DisplayBuf_W_p)
						 Temp_DisplayBuf_R_p = DisplayBuf_W_p-1;//??
					 else
						 Temp_DisplayBuf_R_p = MAX_LINE_LEN-1;//??
					 
					 for(i=0;i<MAX_LINE_LEN;i++)
					 {
						 Temp_DisplayBuf_R_p++;
						 if(Temp_DisplayBuf_R_p>=MAX_LINE_LEN)
							 Temp_DisplayBuf_R_p = 0;
						 Virtual_LCD_Draw_String_ARGB_16_4bit(X_printf_form,Y_printf_form+i*Row_pitch,&(DisplayBuf[Temp_DisplayBuf_R_p][0]),ARGB_white,0,1,1);
						 //sysprintf("\r\n ---DisplayBuf_W_p %d,%X,%X,%X",DisplayBuf_W_p,DisplayBuf[Temp_DisplayBuf_R_p][0],DisplayBuf[Temp_DisplayBuf_R_p][1],DisplayBuf[Temp_DisplayBuf_R_p][2]);
					 }
				 
				 
				 }
				 else
				 {
					 //clear;
						Virtual_LCD_Draw_Rectangle_ARGB32(X_printf_form,Y_printf_form,X_printf_to-X_printf_form,Y_printf_to-Y_printf_form,Virtual_LCDbuff2,ARGB_clear);
						
					 for(i=0;i<(DisplayBuf_W_p+1);i++)
					 {
						 Virtual_LCD_Draw_String_ARGB_16_4bit(X_printf_form,Y_printf_form+i*Row_pitch,&(DisplayBuf[i][0]),ARGB_white,0,1,1);			 
						//sysprintf("\r\n --DisplayBuf_W_p %d,%X,%X,%X",DisplayBuf_W_p,DisplayBuf[i][0],DisplayBuf[Temp_DisplayBuf_R_p][1],DisplayBuf[Temp_DisplayBuf_R_p][2]);
					 }
				 
				 
				 }
				 
					Virtual_LCD_Upgrate();
			
			}
}

}






void page_printf_info(char c,bool Upgrape)
{
	 static bool f_last_disply_debug_val = FALSE;
	 static u16 x=X_printf_form,y=Y_printf_form;
	 static bool f_need_upgrade = FALSE;
	 static u32 IdelTime = 0;
   if(f_disply_debug_val)
	 {
		  if(f_last_disply_debug_val==FALSE)
			{
			  //clear;
				Virtual_LCD_Draw_Rectangle_ARGB32(X_printf_form,Y_printf_form,X_printf_to-X_printf_form,Y_printf_to-Y_printf_form,Virtual_LCDbuff2,ARGB_clear);
        f_need_upgrade=TRUE;
				ResetDelayTime(&IdelTime); 
			}
		  f_last_disply_debug_val = f_disply_debug_val;
			if(Upgrape==FALSE)
			{
				if(c=='\n')
				{
						 y+=Row_pitch;
						 x=X_printf_form;
						 if(y>(Y_printf_to-Row_pitch))
						 {
							 y= Y_printf_form;
							 //clear;
						 Virtual_LCD_Draw_Rectangle_ARGB32(X_printf_form,Y_printf_form,X_printf_to-X_printf_form,Y_printf_to-Y_printf_form,Virtual_LCDbuff2,ARGB_clear);
				
						 }
						 
				}
				else if(c=='\r')
				{
						 x=X_printf_form;
				
				}
				else if((c>=' ')&&(c<='~'))
				{
					 Virtual_LCD_Draw_ASCII_ARGB_16_4bit(x,y,c,ARGB_white,0,1,1);
					 x+=(glyph_dsc_16_4bit_bold[c-0x20].adv_w);
					 if(x>(X_printf_to-(Char_pitch)))
					 {
						 y+=Row_pitch;
						 x=X_printf_form;
						 if(y>(Y_printf_to-Row_pitch))
						 {
							 y= Y_printf_form; 
							 //clear;
						 Virtual_LCD_Draw_Rectangle_ARGB32(X_printf_form,Y_printf_form,X_printf_to-X_printf_form,Y_printf_to-Y_printf_form,Virtual_LCDbuff2,ARGB_clear);
					
							 
						 }
						 }
					 f_need_upgrade=TRUE;
				}
				else
				{
					Virtual_LCD_Draw_ASCII_ARGB_16_4bit(x,y,' ',ARGB_white,0,1,1);
					 x+=(glyph_dsc_16_4bit_bold[c-0x20].adv_w);
					 if(x>(X_printf_to-(Char_pitch)))
					 {
						 y+=Row_pitch;
						 x=X_printf_form;
						 if(y>(Y_printf_to-Row_pitch))
						 {
							 y= Y_printf_form; 
							 //clear;
						 Virtual_LCD_Draw_Rectangle_ARGB32(X_printf_form,Y_printf_form,X_printf_to-X_printf_form,Y_printf_to-Y_printf_form,Virtual_LCDbuff2,ARGB_clear);
					
						 }
						 }
					 f_need_upgrade=TRUE;
				
				}
		  }
			
			else
			{
			  if(f_need_upgrade)
				{
					if(CntDelayTime(&IdelTime,TIME_ONE_MS*500))
		     {
				    Virtual_LCD_Upgrate();
				
				    f_need_upgrade = FALSE;
					 ResetDelayTime(&IdelTime); 
				 }
			
			}
			
	 }	 

}
}





extern bool change_light_val;
extern bool warm_dialog_enable_flag;


//初始化页面结构
void page_init(void)
{
	 lcd_dis_page_t *p;
	 u8 i;
	
	//////////////////////////左边5个大项图标初始化////////////////////////////////
	p = &page_home.page_left_side;
    p->pic_back_g = t_background_1.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_1.size_of_pic_item;// backgroud pic size


//    	p->pic_back_g = t_bk13.pic_item;//poit to backgroud pic
//	p->size_of_pic_back=t_bk13.size_of_pic_item;// backgroud pic size

    
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=120;
	p->y_end_val=480;
	p->item_num=LEFT_SIDE_ICO_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only 	
	
	t_menu_home_d.now_status = STATUS_SELECT;
	t_menu_home_d.last_status = STATUS_SELECT;
	p->item = left_side_item;
	
	p->item = left_side_item;
	for(i=0;i<LEFT_SIDE_ICO_NUM;i++)
	{
	  memcpy(&(p->item[i]),p_left_side_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_left_side_u[i]->pic_item;//
  	p->item[i].size_of_pic_item = p_left_side_u[i]->size_of_pic_item ;
		
	} 
	/////////////////////////////home底部图标初始化/////////////////////////////
	p = &page_home.page_top_side[LEFT_SIDE_PAGE_HOME];
    


	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=420;
	p->x_end_val=800;
	p->y_end_val=480;
	p->item_num=HOME_TEST_TOP_ITEM_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only 
  
    t_new_Light_d_5.now_status = STATUS_SELECT;//默认选中
	t_new_Light_d_5.last_status = STATUS_SELECT;
	
	t_new_Light_d_5.key_type  = KEY_TYPE_NORMAL;
	t_new_Elevator_d_5.key_type = KEY_TYPE_NORMAL;
	t_new_Halo_d_5.key_type = KEY_TYPE_NORMAL;
	t_new_AC_d_5.key_type = KEY_TYPE_NORMAL;
	t_new_Setup_d__5.key_type = KEY_TYPE_NORMAL;
	t_new_heater_d_5.key_type = KEY_TYPE_NORMAL;
    

    
	p->item = test_home_top_item;
	for(i=0;i<HOME_TEST_TOP_ITEM_NUM;i++)//下栏选项
	{
	  memcpy(&(p->item[i]),p_home_top_item_5_test_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_home_top_item_5_test_u[i]->pic_item;//
  	p->item[i].size_of_pic_item = p_home_top_item_5_test_u[i]->size_of_pic_item ;
	}
    
    
    

//////////////////////////功能区设置/////////////////////////////////////////////////	 
    ui_light_init();//0
change_light_val=1;
    ui_elevator_init();//1
	 //ui_home_init();
//	 ui_column_home_init_5();
//	 ui_column_power_init_5();
//	 ui_column_alarm_init_5();
//	 //ui_column_power_white_init_5();
//	 //ui_column_tank_init_5();
    
    
    	 ui_top_info_init_t();//初始化顶栏

     ui_RGB_init();//2
    ui_Dise_Heater_init();
    ui_ac_init();
        ui_column_alarm_init_5();//警告页
    	 ui_column_setup_init_5();//设置页
    
    
    if(warm_dialog_enable_flag)ui_warning_dialog_init();//警告弹窗
	 
}




u16 name[]=
{
  0x732E,//?
	0x7ED9,//?
	0x7231,//?
	0x4E3D,//?
	0x4E1D,//?
};	

extern RGBSystem now_RGB_status;   //现在状态


u8 power_page_max = 0;
u8 power_page_min = 0;
u8 power_page = 0x00;
void disply_4_chun_screen_status(bool upgrade)
{
	char display_buf[32];
	//lcd_dis_item_t *p;
	
	if(upgrade)
	{
		//Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(120,5,480-120,480-5,ARGB_clear);
		Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(430,130,"P",ARGB_black,0,1,1);
		Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(430,180,"A",ARGB_black,0,1,1);
		Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(430,230,"G",ARGB_black,0,1,1);
		Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(430,280,"E",ARGB_black,0,1,1);
		sprintf(display_buf,"%d",power_page);
		Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(430,330,display_buf,ARGB_black,0,1,1);

		if(power_page == 0x00)
		{
			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(142,50,"DC State",ARGB_blue,0,1,1);
			Virtual_LCD_Draw_String_ARGB_16_4bit(140,82, "Vol   :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_16_4bit(140,98, "Cur   :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_16_4bit(140,114,"Pow :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(142,150,"AC Load",ARGB_blue,0,1,1);
			Virtual_LCD_Draw_String_ARGB_16_4bit(140,182, "Vol   :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_16_4bit(140,198, "Cur   :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_16_4bit(140,214, "Pow :",ARGB_black,0,1,1);
			
			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(152,325,"Battery",ARGB_blue,0,1,1);
			Virtual_LCD_Draw_String_ARGB_16_4bit(175,353, "100%",ARGB_green,0,1,1);   //剥离
			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(290,325,"0 W",ARGB_cyan,0,1,1); //剥离
			Virtual_LCD_Draw_String_ARGB_16_4bit(275,350, "0 V",ARGB_green,0,1,1);    //剥离
			Virtual_LCD_Draw_String_ARGB_16_4bit(325,350, "0 A",ARGB_green,0,1,1);    //剥离
			Virtual_LCD_Draw_String_ARGB_16_4bit(303,375, "- -",ARGB_green,0,1,1);    //剥离
			Virtual_LCD_Draw_String_ARGB_16_4bit(255,400, "Time to Empty",ARGB_blue,0,1,1);
			Virtual_LCD_Draw_String_ARGB_16_4bit(285,425, "0h 0m ",ARGB_green,0,1,1); //剥离
		}
		else if(power_page == 0x01)
		{
			Virtual_LCD_Draw_String_ARGB_32_4bit_bold(230,50,"CC State",ARGB_blue,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(240,92, "vol :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(240,116,"cur :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(240,140,"pow:",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_32_4bit_bold(230,180,"SC State",ARGB_blue,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(253,222, "vol :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(253,246, "cur :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(253,270, "pow:",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_32_4bit_bold(230,320,"BC State",ARGB_blue,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(250,352, "vol :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(250,376, "cur :",ARGB_black,0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(250,400, "pow:",ARGB_black,0,1,1);
		}
	}
}

//extern GT911_T g_GT911;

extern void ui_column_setup_set_info2(bool upgrage);
u16 counter2;

bool RGB_touch_Flag;//RGB界面打印RGB坐标标志位

void page_dis_all_val(u8 now_dis_page_item,bool upgrade)//显示所有界面数据
{                

	char display_buf[32];

	//u8 i;
	  lcd_dis_page_t * p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
		if(page_home.page_left_side.now_item==LEFT_SIDE_PAGE_HOME)//主侧栏
		{
			if(p2->now_item==0)//liight、、、page_home.page_top_side[page_home.page_left_side.now_item
			{
                RGB_touch_Flag=0;
        
                for(u8 i=0;i<6;i++)
               	disply_page1_light_pwm_status(i,upgrade);//显示滑动条
                Light_Status_synchronization_SW(upgrade);//同步开关状态
               disply_ligght_val2(upgrade);//打印字符
          //  RGB_touch_Flag=0;
                
               			   Elevator_Status_synchronization_SW();//同步开关状态
 
			}
			else if(p2->now_item==1)//调平
			{
                RGB_touch_Flag=0;
               sprintf(display_buf, "Elevator");
                Virtual_LCD_Draw_String_ARGB_32_4bit_bold(358,93,display_buf,(ARGB_white),0,1,1);//display time
			   Elevator_Status_synchronization_SW();//同步开关状态

            
            
            }
			else if(p2->now_item==2)////RGB
			{
                disply_RGB_val(upgrade);
                if(now_RGB_status.RGB_select==0)
                    disply_pwm_RGB_status(0,upgrade);//显示滑动条
                else 
                    disply_pwm_RGB_status(1,upgrade);//显示滑动条
             //   RGB_touch_Flag=1;//色盘触控开启
                
                			   Elevator_Status_synchronization_SW();//同步开关状态

			}

			else if(p2->now_item==3)//柴暖
			{
           //     RGB_touch_Flag=0;
                disply_DiseHeater_pic(upgrade);
			   Elevator_Status_synchronization_SW();//同步开关状态

			}

 			else if(p2->now_item==4)//AC
			{             
                disply_AC_val(upgrade);
              //  RGB_touch_Flag=0;    
                			   Elevator_Status_synchronization_SW();//同步开关状态

			}   


            else if(p2->now_item==TOP_SIDE_PAGE_HOME_SETUP2)//SET UP
			{            
                			   Elevator_Status_synchronization_SW();//同步开关状态

            ///       RGB_touch_Flag=0;
                   disply_Setup_val(upgrade);//C,F,K
                if(now_dis_page_item==TEST_PAGE_MAIN_ITEM_DISALL)
				{
					if(now_in_dialog_or_keyboard_window())
						return;
					if(f_display_set_info)
					{
						ui_column_setup_set_info(TRUE);
						ui_column_setup_power_system_info_str(TRUE);
						if(f_need_ui_disply_keyboard)
						{ 
							ui_disply_auxilary_keyboard(FALSE);
						}
					}
				}
				else
				{
					reset_page_alarm();
					ui_column_home_info_set(FALSE);
					ui_column_setup_set_info(upgrade);
					ui_column_power_info_set(FALSE);
					ui_column_setup_power_system_info_str(upgrade);
				}
				if(f_ui_disply_dialog_info_5)
				{
					ui_column_setup_system_upgrade_info_str(FALSE);
				}

            }  
            
            
            
             else if(p2->now_item==6)//warm
			{            
             //    RGB_touch_Flag=0;
                ui_column_alarm_display_info(upgrade);

            }  
            
             else if(p2->now_item==7)//warm
			{            
                disply_dialogr_process(upgrade);
            }                  
 
		}   
            
                      
                      

   
        
		{
            
			disply_time_info(upgrade);
			
            
            disply_top_signal_info(upgrade);//警告

		//	disply_top_info(upgrade);
		//	disply_start_battery_info(upgrade);
		}

}




extern lcd_dis_item_t AC_item[];//图片缓存区？？

BOOL f_ilde_status_go_pass = FALSE;
void page_dis_test_pro(void)
{
	lcd_dis_page_t *p,*p2;
	//lcd_dis_item_t * p3;
	u8 i,go_upgrate_from_x1y1=0;
	static u32 IdelTime_1S = 0;
	unsigned int* Virtual_LCDbuff;
	if(IdelTime_1S==0)
	ResetDelayTime(&IdelTime_1S); 
	    


    
    
	switch(dis_page_item)
	{
		case PAGE_INIT:
		{
			if(!CntDelayTime(&IdelTime_1S,TIME_ONE_MS*1200))
				 break;
			//清除全部 Virtual_LCDbuff0需要写入背景 不需要清除  //Virtual_LCDbuff0要写入背景，不能清
		  Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff1,ARGB_clear); //将两个显示层清空
		  Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff2,ARGB_clear); //将两个显示层清空
			page_init();//再次初始化
#if 1 

            p = &page_home.page_left_side;	
            p->pic_back_g = t_background_1.pic_item;//poit to backgroud pic
            p->size_of_pic_back=t_background_1.size_of_pic_item;// backgroud pic size
            
        sysprintf("page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item=%dr\n",page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item);


      // Virtual_LCDbuff0写入背景 
		  png_dis_xy(0,0,p->pic_back_g,p->size_of_pic_back,Virtual_LCDbuff0);
            
            

  

			//写入顶边图标
			p = &page_home.page_top_side[page_home.page_left_side.now_item];		
			for(i=0;i<p->item_num;i++)
		  {
		    png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff0);
		    if(p->item[i].now_status==STATUS_SELECT)	
			      png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
		
			}		
#endif
			Virtual_LCD_Upgrate();
			
		  dis_page_item++;//进入下一个处理步骤
			
			break;
		} 
		case TEST_PAGE_INFO://顶层
		{
            
            

			p = &page_home.page_info;
			for(i=0;i<p->item_num;i++)
			{
				if((p->item[i].last_status != p->item[i].now_status))
				{
					// go_upgrate_from_x1y1 = 1;//这里不更新UI
					if(p->item[i].now_status==STATUS_IDLE)
					{
						(*p->item[i].f)(p,i);//调用处理图标处理函数
						p->item[i].last_status = p->item[i].now_status;
						png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);
						
					}
					else if(p->item[i].now_status==STATUS_TOUCH)
					{
						(*p->item[i].f)(p,i);//调用处理图标处理函数
						p->item[i].last_status = p->item[i].now_status;
						png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_touch,p->item[i].size_of_pic_item_touch,Virtual_LCDbuff1);
					
					}
					else if(p->item[i].now_status==STATUS_SELECT)
					{
						(*p->item[i].f)(p,i);//调用处理图标处理函数
						if((p->item[i].key_type ==KEY_TYPE_ONCE)||(p->item[i].key_type ==KEY_TYPE_TOUCH_KEEP))
								p->item[i].now_status=STATUS_IDLE;		
						p->item[i].last_status = p->item[i].now_status;
						png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
					}
				}
			}
			if(go_upgrate_from_x1y1)
			{
				Virtual_LCD_Upgrate_formx1y1(0,0,800,50);	 
				go_upgrate_from_x1y1 = 0;
				f_need_LCD_Upgrate = FALSE;//这里不需要全屏更新
			}
			dis_page_item++;
		break;
		}
		case TEST_PAGE_LEFT_SIDE:  //左侧
		{
			//    sysprintf("23333333333333333,,,,,,page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item=%dr\n",page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item);

			dis_page_item++;
			break;
			p = &page_home.page_left_side;
			for(i=0;i<p->item_num;i++)
			{
				if((p->item[i].last_status != p->item[i].now_status))  //状态更新
				{
					go_upgrate_from_x1y1 = 1;
			   	//p->item[i].last_status = p->item[i].now_status;
					if(p->item[i].now_status==STATUS_IDLE)
					{
						 p->item[i].last_status = p->item[i].now_status;
						
						Virtual_LCD_Draw_Rectangle_ARGB32(p->item[i].x_val,\
						p->item[i].y_val,\
						p->item[i].x_end_val-p->item[i].x_val+1,\
						p->item[i].y_end_val-p->item[i].y_val+1,\
						Virtual_LCDbuff1,\
							ARGB_clear);
					}
					else if(p->item[i].now_status==STATUS_TOUCH)   //轻触
					{
						p->item[i].last_status = p->item[i].now_status;
						png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_touch,p->item[i].size_of_pic_item_touch,Virtual_LCDbuff1);
					  p->now_item = i;
					}
					else if(p->item[i].now_status==STATUS_SELECT)  //选择
					{
						p->item[i].last_status = p->item[i].now_status;
						png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
					}
				}
			}
			if(go_upgrate_from_x1y1)
			{
			  Virtual_LCD_Upgrate_formx1y1(0,0,800,400);	 //这里不能越界  越界堵死了 操！
				go_upgrate_from_x1y1 = 0;
				f_need_LCD_Upgrate = FALSE;//这里不需要全屏更新
			}
			dis_page_item++;
			break;
		}
		case TEST_PAGE_LEFT_SIDE_UPDATA:  //左测更新
		{
            		//	    sysprintf("4444444444444444,,,,,,page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item=%dr\n",page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item);

			if(now_in_dialog_or_keyboard_window())
			{
				dis_page_item++;  
				break;
			}
			p = &page_home.page_left_side;
			if(p->last_item==p->now_item)
			{
				dis_page_item++;
				break;
			}
			
			if(p->last_item == LEFT_SIDE_PAGE_UPDATA)
				Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(0,0,800,480,ARGB_clear);
			else
				Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(0,0,800,400,ARGB_clear);
			p->last_item=p->now_item;
			
			//更新主区域图标
			p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
			if(page_deepth_val[p2->now_item] == 0)//判断父子页面深度
				p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
			else if(page_deepth_val[p2->now_item] == 1)//判断父子页面深度   1层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			else if(page_deepth_val[p2->now_item] == 2)//判断父子页面深度   2层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1]->sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			 
      
			for(i=0;i<p->item_num;i++)
			{
				if(page_home_deel_with_i(p2,&i))
					break;
				if(page_power_deel_with_i(p2,&i))
					break;
				// if(page_ac_seet_deel_with_i(p2,&i))
				//	 break;
					
			  //sysprintf("\r\nnow_status:,%d,%d",i,p->item[i].now_status);
				
				if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE)&&(p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
				{
					if(p->item[i].now_status==STATUS_SELECT)	
						png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
					else
						png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
				}
			}
			page_dis_all_val(dis_page_item,TRUE);
			Virtual_LCD_Upgrate();	
			dis_page_item++;
			break;
		}
		case TEST_PAGE_TOP_SIDE://下栏
		{
            			    

			#if 1
			p = &page_home.page_top_side[page_home.page_left_side.now_item];
       
			for(i=0;i<p->item_num;i++)
			{
				if((p->item[i].last_status != p->item[i].now_status))
				{
					go_upgrate_from_x1y1 = 1;
			 		(*p->item[i].f)(p,i);	
			 		if(p->item[i].now_status==STATUS_IDLE)
			 		{
			 			p->item[i].last_status = p->item[i].now_status;								
			 			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);
			 		}
			 		else if(p->item[i].now_status==STATUS_TOUCH)
			 		{
						p->item[i].last_status = p->item[i].now_status;
			 			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_touch,p->item[i].size_of_pic_item_touch,Virtual_LCDbuff1);
			 			p->now_item = i;
			 		}
			 		else if(p->item[i].now_status==STATUS_SELECT)
			 		{
			 			p->item[i].last_status = p->item[i].now_status;
			 			png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
                        
                        sysprintf("55555555555555,,,,,,page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item=%dr\n",page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item);
                        
                        
			 		}
			 	}
			}
			if(go_upgrate_from_x1y1)
			{
			  Virtual_LCD_Upgrate_formx1y1(0,400,800,80);	
			  go_upgrate_from_x1y1 = 0;
			  f_need_LCD_Upgrate = FALSE;//这里不需要全屏更新
			}
		  #endif
		 	dis_page_item++;      
		 break;
		 }		 
		 //////////////////////////////////////////////////////////////////		 
		case TEST_PAGE_TOP_SIDE_UPDATA://下栏更新
		{
#if 1
            
            	///		    sysprintf("666666666666,,,,,,page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item=%dr\n",page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item);

			 p = &page_home.page_top_side[page_home.page_left_side.now_item];
			 if(p->last_item==p->now_item)
			 {
				 dis_page_item++;
				 break;
			 }
			  
			 p->last_item=p->now_item;
		  p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
			if(page_deepth_val[p2->now_item] == 0)//判断父子页面深度
				p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
			else if(page_deepth_val[p2->now_item] == 1)//判断父子页面深度   1层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			else if(page_deepth_val[p2->now_item] == 2)//判断父子页面深度   2层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1]->sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			 
       Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(0,0,800,400,ARGB_clear);
			 
			 //Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(
			 //				            	p->x_val,p->y_val,\
			 //					            p->x_end_val-p->x_val,p->y_end_val-p->y_val,\
			 //						ARGB_clear);
			 
			 for(i=0;i<p->item_num;i++)
			 {
				 //if(page_home_deel_with_i(p2,&i))
					 //				 break;
				 //sysprintf("\r\nPAGE_TOP_SIDE_UPDATA %d -",i);
				 if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE)&&(p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
				 {
					 if(p->item[i].now_status==STATUS_SELECT)	
					 png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
					 else
					 png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);
				 }
			 }
			 // sysprintf("\r\nPAGE_TOP_SIDE_UPDATA    d%,d%",p->now_item,p2->now_item);
	 
			 page_dis_all_val(dis_page_item,TRUE);

		   Virtual_LCD_Upgrate();
#endif
			 dis_page_item++;

			 break;
		}
		case TEST_PAGE_MAIN_ITEM_DISALL:  //主区域
		{

            
            		//	    sysprintf("777777777777,,,,,,page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item=%dr\n",page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item);



			if(f_ui_disply_keyboard)
			{
				p = &page_home.page_keyboard;					 
			}
			else if(f_ui_disply_dialog_test)
			{
				p = &page_home.page_dialog_test;
			}
			else
			{
				p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
				if(page_deepth_val[p2->now_item] == 0)//判断父子页面深度
					p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
				else if(page_deepth_val[p2->now_item] == 1)//判断父子页面深度   1层子页面
					p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
				else if(page_deepth_val[p2->now_item] == 2)//判断父子页面深度   2层子页面
					p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1]->sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			}
			Virtual_LCDbuff = Virtual_LCDbuff1;
			
			for(i=0;i<p->item_num;i++)
			{
				//sysprintf("\r\n item_num = %d",p->item_num);
				
				if(f_ui_disply_keyboard)
				{
					if(page_keyboard_deel_with_i(p,&i))
						break;
				}
				else if(f_ui_disply_dialog_test)
				{
				
				}
                    // 状态变化检测条件：满足以下任一条件时执行状态更新
                    // 1. 状态发生变化 AND 不是从某些特定状态切换到触摸状态的特殊情况
                    // 2. 当前状态是长按状态（长按状态需要立即处理）
                    if(((p->item[i].last_status != p->item[i].now_status) && \
                        (!(((p->item[i].last_status == STATUS_UPDATA) || \
                            (p->item[i].last_status == STATUS_TOUCH_ON_IDLE) || \
                            (p->item[i].last_status == STATUS_TOUCH_ON_SELECT) || \
                            (p->item[i].last_status == STATUS_TOUCH_ON_SELECT2) || \
                            (p->item[i].last_status == STATUS_TOUCH_ON_SELECT3)) && \
                            (p->item[i].now_status == STATUS_TOUCH)))) \
                        || (p->item[i].now_status == STATUS_TOUCH_LONG_PRESS))
                    {
                          

                        // 如果当前状态变为空闲状态
                  if(p->item[i].now_status == STATUS_IDLE)//显示正常状态图片
                        {
                            // 显示逻辑：如果不是触摸隐藏或长按隐藏类型，则显示正常状态图片
                            if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE) && 
                               (p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE)) 
                            {
                                // 显示图标的正常状态图片（非触摸、非选中状态）
                                png_dis_xy(p->item[i].x_val, p->item[i].y_val, 
                                          p->item[i].pic_item, p->item[i].size_of_pic_item, 
                                          Virtual_LCDbuff);	
                            }
                            
                            // 调用该图标的处理函数（执行空闲状态下的业务逻辑）
                            (*p->item[i].f)(p,i);
                            
                            // 更新上一次状态为当前状态
                            p->item[i].last_status = p->item[i].now_status;
                            
                            // 如果系统处于键盘显示模式，立即刷新该区域的屏幕
                            if((f_ui_disply_keyboard))
                                Virtual_LCD_Upgrate_formx1y1(p->item[i].x_val, p->item[i].y_val,
                                                            p->item[i].x_end_val - p->item[i].x_val,
                                                            p->item[i].y_end_val - p->item[i].y_val);
                            //sysprintf("\r\n 0000000000000000");
                        }
                                        
                    
                  else if(p->item[i].now_status == STATUS_TOUCH) // 如果当前状态为触摸按下状态
                        {
                            // 根据上一次的状态来记录触摸发生在什么基础状态上
                            if(p->item[i].last_status == STATUS_IDLE) // 如果之前是空闲状态
                            {
                                //sysprintf("222222222222222222\r\n");
                                p->item[i].last_status = STATUS_TOUCH_ON_IDLE; // 记录：在空闲状态上触摸
                                (*p->item[i].f)(p,i); // 调用该图标的处理函数（执行触摸响应逻辑）
                            }
                            else if(p->item[i].last_status == STATUS_SELECT) // 如果之前是选中状态
                                p->item[i].last_status = STATUS_TOUCH_ON_SELECT; // 记录：在选中状态上触摸
                            else if(p->item[i].last_status == STATUS_SELECT2) // 如果之前是第二选中状态
                                p->item[i].last_status = STATUS_TOUCH_ON_SELECT2; // 记录：在第二选中状态上触摸  
                            else if(p->item[i].last_status == STATUS_SELECT3) // 如果之前是第三选中状态
                                p->item[i].last_status = STATUS_TOUCH_ON_SELECT3; // 记录：在第三选中状态上触摸
                            
                            // 显示触摸效果：如果不是在SELECT2或SELECT3状态上触摸，且不是长按隐藏类型，则显示触摸态图片
                            if((!(p->item[i].last_status == STATUS_TOUCH_ON_SELECT2) || 
                                (p->item[i].last_status == STATUS_TOUCH_ON_SELECT3)) && 
                                (p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
                            {
                                // 在触摸位置显示触摸状态图片（如高亮、按下效果等）
                                png_dis_xy(p->item[i].x_val, p->item[i].y_val, 
                                          p->item[i].pic_item_touch, p->item[i].size_of_pic_item_touch, 
                                          Virtual_LCDbuff);
                            }
                            
                            //sysprintf("\r\n i1:%d",i);
                            
                            // 如果系统处于键盘显示模式，立即刷新该区域的屏幕
                            if((f_ui_disply_keyboard))
                                Virtual_LCD_Upgrate_formx1y1(p->item[i].x_val, p->item[i].y_val,
                                                            p->item[i].x_end_val - p->item[i].x_val,
                                                            p->item[i].y_end_val - p->item[i].y_val);
                        }
                    
                    
                        // 处理长按状态
                        else if(p->item[i].now_status == STATUS_TOUCH_LONG_PRESS)
                        {
                            // 执行长按对应的处理函数
                            (*p->item[i].f)(p,i);	
                            // 更新状态记录
                            p->item[i].last_status = p->item[i].now_status;
                        }
                        // 处理选中状态
                        else if(p->item[i].now_status == STATUS_SELECT)
                        {						
                            //sysprintf("\r\n i2:%d",i);
                            
                            // 如果上一次状态不是更新状态，说明是新的选中操作
                            if(p->item[i].last_status != STATUS_UPDATA)
                            {
                                // 执行选中状态的处理函数
                                (*p->item[i].f)(p,i);								
                                // 更新状态记录
                                p->item[i].last_status = p->item[i].now_status;
                                
                                // 如果是单次触发或触摸保持类型的按键，立即返回到空闲状态
                                if((p->item[i].key_type == KEY_TYPE_ONCE) || 
                                   (p->item[i].key_type == KEY_TYPE_TOUCH_KEEP))
                                    p->item[i].now_status = STATUS_IDLE;										 
                            }
                            else
                            {
                                // 如果是从更新状态来的，只更新状态记录，不执行处理函数
                                p->item[i].last_status = p->item[i].now_status;				
                            }
                            
                            // 显示处理：如果不是触摸隐藏或长按隐藏类型，则更新显示
                            if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE) && 
                               (p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
                            {
                                // 重新判断当前状态（因为处理函数可能改变了状态）
                                if(p->item[i].now_status == STATUS_SELECT)
                                {
                                    // 显示选中状态的图片
                                    png_dis_xy(p->item[i].x_val, p->item[i].y_val,
                                              p->item[i].pic_item_select, p->item[i].size_of_pic_item_select,
                                              Virtual_LCDbuff);
                                }
                                else if(p->item[i].now_status == STATUS_IDLE)
                                {
                                    // 显示空闲状态的图片
                                    png_dis_xy(p->item[i].x_val, p->item[i].y_val,
                                              p->item[i].pic_item, p->item[i].size_of_pic_item,
                                              Virtual_LCDbuff);
                                }
                            }
                            
                            // 如果系统处于键盘显示模式，立即刷新该区域的屏幕
                            if((f_ui_disply_keyboard))
                                Virtual_LCD_Upgrate_formx1y1(p->item[i].x_val, p->item[i].y_val,
                                                            p->item[i].x_end_val - p->item[i].x_val,
                                                            p->item[i].y_end_val - p->item[i].y_val);
                        }
                                           
                    
                   
                                              
                        // 处理第二选中状态
                        else if(p->item[i].now_status == STATUS_SELECT2)
                        {
                            // 更新状态记录：将当前状态保存为上一次状态
                            p->item[i].last_status = p->item[i].now_status;
                            
                            // 执行第二选中状态对应的处理函数
                            (*p->item[i].f)(p,i);	
                            
                            // 显示第二选中状态的专用图标
                            png_dis_xy(p->item[i].x_val, p->item[i].y_val,
                                      p->item[i].pic_item_select2, p->item[i].size_of_pic_item_select2,
                                      Virtual_LCDbuff);
                        }

                        // 处理第三选中状态  
                        else if(p->item[i].now_status == STATUS_SELECT3)
                        {
                            // 更新状态记录：将当前状态保存为上一次状态
                            p->item[i].last_status = p->item[i].now_status;
                            
                            // 执行第三选中状态对应的处理函数
                            (*p->item[i].f)(p,i);	
                            
                            // 显示第三选中状态的专用图标
                            png_dis_xy(p->item[i].x_val, p->item[i].y_val,
                                      p->item[i].pic_item_select3, p->item[i].size_of_pic_item_select3,
                                      Virtual_LCDbuff);
                        }
                                            
                    
                    
					if((!f_ui_disply_keyboard))
						Virtual_LCD_Upgrate();
				}
			}
			//if(page_home.page_left_side.last_item != LEFT_SIDE_PAGE_UPDATA)
			//{			
				page_dis_all_val(dis_page_item,FALSE);//显示所有界面数据
			//}
			if((f_ui_need_disply_dialog_code==FALSE)&&(f_ui_need_disply_dialog_msg==FALSE)&&(f_ui_need_disply_dialog_test==FALSE))
				disply_input_val(FALSE);
			else if(f_ui_need_disply_dialog_test)
			{
				if(f_ui_disply_dialog_code==FALSE)
					ui_disply_dialog_test();
				f_ui_need_disply_dialog_test = FALSE;
			}
			dis_page_item=TEST_PAGE_LEFT_SIDE;
			break;
		}
	}
}
void page_dis_pro(void)
{
	lcd_dis_page_t *p,*p2;
	//lcd_dis_item_t * p3;
	u8 i,go_upgrate_from_x1y1=0;
	static u32 IdelTime_1S = 0;
	unsigned int* Virtual_LCDbuff;
	if(IdelTime_1S==0)
	ResetDelayTime(&IdelTime_1S); 
	
	
	//return;
   switch(dis_page_item)
	 {
		 //////////////////////////////////////////////////////////////////
		 case PAGE_INIT:
		 {	 
			 
			if(!CntDelayTime(&IdelTime_1S,TIME_ONE_MS*1200))
				break;
      //清除全部 Virtual_LCDbuff0需要写入背景 不需要清除  //Virtual_LCDbuff0要写入背景，不能清
		  Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff1,ARGB_clear); //将两个显示层清空
		  Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff2,ARGB_clear); //将两个显示层清空
      
			page_init();//再次初始化
			 
			#if 1
			p = &page_home.page_left_side;		
			// Virtual_LCDbuff0写入背景 
			png_dis_xy(0,0,p->pic_back_g,p->size_of_pic_back,Virtual_LCDbuff0);
			
			//写入左边图标
			for(i=0;i<p->item_num;i++)
			{
					png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff0);
					if(p->item[i].now_status==STATUS_SELECT)	
							png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
			}
		 

		
			//写入主要页面图标	
			p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
			p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
		
	   for(i=0;i<p->item_num;i++)
			{		   
       if(page_home_deel_with_i(p2,&i))
							 break;
//			 if(page_lights_deel_with_i(p2,&i))
//							 break;
//			 if(page_loads_deel_with_i(p2,&i))
//							 break;			 
			 if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE)&&(p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
			 {
			 if(p->item[i].now_status==STATUS_SELECT)	
			      png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
	     else
			 png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);		
		   }			 
			}
			
			

			
			#endif
			
			
			//p3 = &t_page0;//page0;
			//   png_dis_xy(p3->x_val,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);
			
		 //所有界面准备好后 更新界面到显示区
		   Virtual_LCD_Upgrate();
			
			 dis_page_item++;//进入下一个处理步骤
			 break;
		}	
		 //////////////////////////////////////////////////////////////////	
		 case PAGE_INFO://顶层
		 { 
			 p = &page_home.page_info;
			   for(i=0;i<p->item_num;i++)
				 {
				    if((p->item[i].last_status != p->item[i].now_status))
						{
							// go_upgrate_from_x1y1 = 1;//这里不更新UI
							if(p->item[i].now_status==STATUS_IDLE)
							{
								(*p->item[i].f)(p,i);//调用处理图标处理函数
								 p->item[i].last_status = p->item[i].now_status;
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);
							  
							}
							else if(p->item[i].now_status==STATUS_TOUCH)
							{
								(*p->item[i].f)(p,i);//调用处理图标处理函数
								 p->item[i].last_status = p->item[i].now_status;
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_touch,p->item[i].size_of_pic_item_touch,Virtual_LCDbuff1);
							 
							}
							else if(p->item[i].now_status==STATUS_SELECT)
							{
								(*p->item[i].f)(p,i);//调用处理图标处理函数
								if((p->item[i].key_type ==KEY_TYPE_ONCE)||(p->item[i].key_type ==KEY_TYPE_TOUCH_KEEP))
										 p->item[i].now_status=STATUS_IDLE;		
								 p->item[i].last_status = p->item[i].now_status;
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
							}
						
						}
				 
			}
       if(go_upgrate_from_x1y1)
			{
			 Virtual_LCD_Upgrate_formx1y1(0,0,1024,50);	 
				go_upgrate_from_x1y1 = 0;
				f_need_LCD_Upgrate = FALSE;//这里不需要全屏更新
			}
			 dis_page_item++;
		 break;
		}
		 //////////////////////////////////////////////////////////////////	
		 case PAGE_LEFT_SIDE://左侧
		 { 
			 p = &page_home.page_left_side;
			   for(i=0;i<p->item_num;i++)
				 {
				    if((p->item[i].last_status != p->item[i].now_status))
						{
							go_upgrate_from_x1y1 = 1;
					   	//p->item[i].last_status = p->item[i].now_status;
							if(p->item[i].now_status==STATUS_IDLE)
							{
								 p->item[i].last_status = p->item[i].now_status;
								
								Virtual_LCD_Draw_Rectangle_ARGB32(p->item[i].x_val,\
								p->item[i].y_val,\
								p->item[i].x_end_val-p->item[i].x_val+1,\
								p->item[i].y_end_val-p->item[i].y_val+1,\
								Virtual_LCDbuff1,\
									ARGB_clear);
							}
							else if(p->item[i].now_status==STATUS_TOUCH)
							{
								 p->item[i].last_status = p->item[i].now_status;
								
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_touch,p->item[i].size_of_pic_item_touch,Virtual_LCDbuff1);
							  p->now_item = i;
							}
							else if(p->item[i].now_status==STATUS_SELECT)
							{
								 p->item[i].last_status = p->item[i].now_status;
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
							}
						
						}
				 
				 }
			 //Virtual_LCD_Upgrate();
			if(go_upgrate_from_x1y1)
			{
			 Virtual_LCD_Upgrate_formx1y1(0,0,140,600);	 
				go_upgrate_from_x1y1 = 0;
				f_need_LCD_Upgrate = FALSE;//这里不需要全屏更新
			}
			 dis_page_item++;
		 break;
		}		 
		 //////////////////////////////////////////////////////////////////		 
		 case PAGE_LEFT_SIDE_UPDATA://左侧更新
		 {	 
			 
			 if(now_in_dialog_or_keyboard_window())
			 {
				 dis_page_item++;   
				 break;
			 }
		   p = &page_home.page_left_side;
			 if(p->last_item==p->now_item)
			 {
				 dis_page_item++;
				 break;
			 }
			 
				
			   //更新状态列表
			   p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
			   sysprintf("\r\n@@@@@@@@@@@PAGE_LIFT_SIDE_UPDATA    %d,%d",p->now_item,p2->now_item);
			  if(p->last_item!=LEFT_SIDE_PAGE_UPDATA)
				{
					
					// sysprintf("\r\n$$$$$$$$$$$$$$$$LEFT_SIDE_PAGE_UPDATA %d",p->now_item);
					
				 if(f_force_to_target_top_page)
				 {
				    f_force_to_target_top_page = FALSE;
					 /*for(i=0;i<p2->item_num;i++)
					 {
							 p2->item[i].now_status = STATUS_IDLE;
					 }
					 p2->item[0].now_status = STATUS_SELECT;*/
				 }
				 else
				 {
			      p2->now_item = 0;//每次切换进入第一个TOP项
				 
					 for(i=0;i<p2->item_num;i++)
					 {
							 p2->item[i].now_status = STATUS_IDLE;
					 }
					 p2->item[0].now_status = STATUS_SELECT;
				 }
				 
				 //退出通道编辑
				 drop_out_lights_setup();
				 drop_out_loads_setup();
				}
				 p->last_item=p->now_item;
	       p2 = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
			 
			 
			// p3 = &page_home.page_top_side[page_home.page_left_side.now_item];
			   //if((p->now_item==LEFT_SIDE_PAGE_HOME))
					{
									Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(
							            	120,56,\
								            1024-120,600-56,\
									ARGB_clear);
			   }
				
				  //更新顶部图标
          if((p->now_item!=LEFT_SIDE_PAGE_HOME))
				 {
					 p = &page_home.page_top_side[page_home.page_left_side.now_item];					 
					 for(i=0;i<p->item_num;i++)
				   {						 
						png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);
						if(p->item[i].now_status==STATUS_SELECT)	
			      png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
	 
					 }
				  }					 

					//更新具体图标 
					p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
					p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	


					 for(i=0;i<p->item_num;i++)
					 {
						 if(page_home_deel_with_i(p2,&i))
							 break;
						 if(page_power_deel_with_i(p2,&i))
							 break;
						// if(page_ac_seet_deel_with_i(p2,&i))
						//	 break;
             
						//sysprintf("\r\nnow_status:,%d,%d",i,p->item[i].now_status);
						 if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE)&&(p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
						 {
              if(p->item[i].now_status==STATUS_SELECT)	
			        png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
	            else
						  png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
					  }
					 }
					  page_dis_all_val(dis_page_item,TRUE);
									

			 Virtual_LCD_Upgrate();	
		 
		 	 dis_page_item++;   
			 break;
		 } 
		 //////////////////////////////////////////////////////////////////	 
		 case PAGE_TOP_SIDE://下栏
		 {
			 #if 1
			 if((p->now_item==LEFT_SIDE_PAGE_HOME))
			 {
			   dis_page_item++;      
		     break;
			 }
			 
			   p = &page_home.page_top_side[page_home.page_left_side.now_item];

		     for(i=0;i<p->item_num;i++)
				 {
					  if((p->item[i].last_status != p->item[i].now_status))
						{
							sysprintf("???????????????????????????????????????????????????????");
							go_upgrate_from_x1y1 = 1;
							(*p->item[i].f)(p,i);	
							if(p->item[i].now_status==STATUS_IDLE)
							{
								p->item[i].last_status = p->item[i].now_status;								
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);
								
							}
							else if(p->item[i].now_status==STATUS_TOUCH)
							{
								 p->item[i].last_status = p->item[i].now_status;
								
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_touch,p->item[i].size_of_pic_item_touch,Virtual_LCDbuff1);
								
								p->now_item = i;
	 				
							}
							else if(p->item[i].now_status==STATUS_SELECT)
							{
								 p->item[i].last_status = p->item[i].now_status;

								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
							}
						
						}
				 
				 }
				 
			 if(go_upgrate_from_x1y1)
			 {
			   Virtual_LCD_Upgrate_formx1y1(141,514,1024,600);	
				 go_upgrate_from_x1y1 = 0;
				 f_need_LCD_Upgrate = FALSE;//这里不需要全屏更新
			 }
		 #endif
		 	 dis_page_item++;      
		 break;
		 }		 
		 //////////////////////////////////////////////////////////////////		 
		 case PAGE_TOP_SIDE_UPDATA://下栏更新
		 {
			 //dis_page_item++;
		 #if 1
			 if((p->now_item==LEFT_SIDE_PAGE_HOME))
			 {
			   dis_page_item++;      
		     break;
			 }
			  p = &page_home.page_top_side[page_home.page_left_side.now_item];
			 if(p->last_item==p->now_item)
			 {
				 dis_page_item++;
				 break;
			 }
			  
				p->last_item=p->now_item;
		  p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
	    p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
			sysprintf("\r\n@@@@@@@@@@@PAGE_TOP_SIDE_UPDATA    %d,%d",p->now_item,p2->now_item);
			 

			Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(
							            	p->x_val,p->y_val,\
								            p->x_end_val-p->x_val,p->y_end_val-p->y_val,\
									ARGB_clear);

		for(i=0;i<p->item_num;i++)
		{
			//if(page_home_deel_with_i(p2,&i))
				//				 break;
					//sysprintf("\r\nPAGE_TOP_SIDE_UPDATA %d -",i);
				if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE)&&(p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
				{
				if(p->item[i].now_status==STATUS_SELECT)	
				png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
				else
				png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);
			}//sysprintf("\r\nPAGE_TOP_SIDE_UPDATA %d --",i);
				
		}
	  // sysprintf("\r\nPAGE_TOP_SIDE_UPDATA    d%,d%",p->now_item,p2->now_item);
	 
					page_dis_all_val(dis_page_item,TRUE);

		   Virtual_LCD_Upgrate();
			#endif
			 dis_page_item++;

			 break;
		}
		 //////////////////////////////////////////////////////////////////	
		 case PAGE_MAIN_ITEM:
			 dis_page_item++;   
		 break;
		////////////////////////////////////////////////////////////////// 
		 case PAGE_MAIN_ITEM_DISALL:
		 {
		     if(f_ui_disply_dialog_code)
				 {
					 p = &page_home.page_dialog_code;
				 }
				 else if(f_ui_disply_dialog_msg)
				 {
					 p = &page_home.page_dialog_msg;
				 }
				 else if(f_ui_disply_dialog_test)
				 {
					 p = &page_home.page_dialog_test;
				 }
				 else if(f_ui_disply_keyboard)
				 {
					 p = &page_home.page_keyboard;					 
				 }
				 else if(f_ui_disply_dialog_lights)
				 {
					 p = &page_home.page_dialog_lights;
				 }
				 else if(f_ui_disply_dialog_loads)
				 {
					 p = &page_home.page_dialog_loads;
				 }
				 else if(f_ui_disply_dialog_motors)
				 {
					 p = &page_home.page_dialog_motors;
				 }
				 else if(f_ui_disply_dialog_lights_ch)
				 {
					 p = &page_home.page_dialog_lights_ch;
				 }
				 else if(f_ui_disply_dialog_loads_ch)
				 {
					 p = &page_home.page_dialog_loads_ch;
				 }
				 else if(f_ui_disply_dialog_info)
				 {
					 p = &page_home.page_dialog_info;
				 }
				 else
				 {
					 p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
					 p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
				 }
				 Virtual_LCDbuff = Virtual_LCDbuff1;
				 
			   //p = &page_home.page_main_item[page_home.page_left_side.now_item][0];		
		     //sysprintf("\r\n now_item %d", p2->now_item);
			   for(i=0;i<p->item_num;i++)
				 {
					 if(f_ui_disply_dialog_code)
					 {
					 
					 }
					 else if(f_ui_disply_dialog_msg)
					 {
					 
					 }
					 else if(f_ui_disply_keyboard)
					 {
						 if(page_keyboard_deel_with_i(p,&i))
							 break;
					 }
					 else if(f_ui_disply_dialog_lights)
					 {
					 
					 }
					 else if(f_ui_disply_dialog_loads)
					 {
					 
					 }
					 else if(f_ui_disply_dialog_lights_ch)
					 {
					 
					 }
					 else if(f_ui_disply_dialog_loads_ch)
					 {
					 
					 }
					 
					 else if(f_ui_disply_dialog_info)
					 {
					 
					 }
					 else
					 {
           
					 if(page_home_deel_with_i(p2,&i))
							 break;
					// if(page_lights_deel_with_i(p2,&i))
						//	 break;
//			 if(page_loads_deel_with_i(p2,&i))
//							 break;						
				   }
				//	 if(page_ac_seet_deel_with_i(p2,&i))
					//		 break;
				//	 if(page_car_info_deel_with_i(p2,&i))
					//		 break;
					// sysprintf("\r\n 0000000000000000,%d,%d,%d",i,p->item[i].last_status, p->item[i].now_status);// 0000000000000000,4,8,2 STATUS_TOUCH_ON_IDLE,STATUS_TOUCH
						/////////////////////////////////////////////
				    if(((p->item[i].last_status != p->item[i].now_status)&&\
							  (!(((p->item[i].last_status == STATUS_UPDATA)||\
						      (p->item[i].last_status == STATUS_TOUCH_ON_IDLE)||\
						      (p->item[i].last_status == STATUS_TOUCH_ON_SELECT)||\
						      (p->item[i].last_status == STATUS_TOUCH_ON_SELECT2)||\
						      (p->item[i].last_status == STATUS_TOUCH_ON_SELECT3))&&\
						      (p->item[i].now_status==STATUS_TOUCH))))\
						||(p->item[i].now_status==STATUS_TOUCH_LONG_PRESS))
						{
							if(p->item[i].now_status==STATUS_IDLE)
							{
								 if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE)&&(p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
			          //{
								 png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff);	
									//if(p->item[i].key_type!=KEY_TYPE_TOUCH_NONE)
								 (*p->item[i].f)(p,i);//调用处理图标处理函数
								  p->item[i].last_status = p->item[i].now_status;
								if((f_ui_disply_keyboard))
									Virtual_LCD_Upgrate_formx1y1(p->item[i].x_val,p->item[i].y_val,p->item[i].x_end_val-p->item[i].x_val,p->item[i].y_end_val - p->item[i].y_val);
						//	sysprintf("\r\n 0000000000000000");
							
							
							}
							else if(p->item[i].now_status==STATUS_TOUCH)
							{
								 if(p->item[i].last_status == STATUS_IDLE)
								 {
									 p->item[i].last_status = STATUS_TOUCH_ON_IDLE;
									 (*p->item[i].f)(p,i);//调用处理图标处理函数
								 }
								 else if(p->item[i].last_status == STATUS_SELECT)
									 p->item[i].last_status = STATUS_TOUCH_ON_SELECT;
								 else if(p->item[i].last_status == STATUS_SELECT2)
									 p->item[i].last_status = STATUS_TOUCH_ON_SELECT2;
								 else if(p->item[i].last_status == STATUS_SELECT3)
									 p->item[i].last_status = STATUS_TOUCH_ON_SELECT3;
								 if(!(p->item[i].last_status == STATUS_TOUCH_ON_SELECT2)||(p->item[i].last_status == STATUS_TOUCH_ON_SELECT3))
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_touch,p->item[i].size_of_pic_item_touch,Virtual_LCDbuff);
	 				      //sysprintf("\r\n i1:%d",i);
								 if((f_ui_disply_keyboard))
									 Virtual_LCD_Upgrate_formx1y1(p->item[i].x_val,p->item[i].y_val,p->item[i].x_end_val-p->item[i].x_val,p->item[i].y_end_val - p->item[i].y_val);
							}
							else if(p->item[i].now_status==STATUS_TOUCH_LONG_PRESS)
							{
							   
									
									(*p->item[i].f)(p,i);	
								p->item[i].last_status = p->item[i].now_status;
								//sysprintf("\r\n i55:%d",i);
							
							}
							else if(p->item[i].now_status==STATUS_SELECT)
							{						
								//sysprintf("\r\n i2:%d",i);
								if(p->item[i].last_status != STATUS_UPDATA)
								{
									
									
									(*p->item[i].f)(p,i);								
                  p->item[i].last_status = p->item[i].now_status;
									 if((p->item[i].key_type ==KEY_TYPE_ONCE)||(p->item[i].key_type ==KEY_TYPE_TOUCH_KEEP))
										 p->item[i].now_status=STATUS_IDLE;										 

							  }
								else
									p->item[i].last_status = p->item[i].now_status;				
								if((p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE)&&(p->item[i].key_type != KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))
			          {
								if(p->item[i].now_status==STATUS_SELECT)//再判断一次，在这里可能会补改变(*p->item[i].f)(p,i);	
								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff);
	 				      else if(p->item[i].now_status==STATUS_IDLE)
									png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff);
						  	}
								if((f_ui_disply_keyboard))
									 Virtual_LCD_Upgrate_formx1y1(p->item[i].x_val,p->item[i].y_val,p->item[i].x_end_val-p->item[i].x_val,p->item[i].y_end_val - p->item[i].y_val);
									    
							}
							else if(p->item[i].now_status==STATUS_SELECT2)
							{
								p->item[i].last_status = p->item[i].now_status;
								
								(*p->item[i].f)(p,i);	

								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select2,p->item[i].size_of_pic_item_select2,Virtual_LCDbuff);
	 				
							}
						  else if(p->item[i].now_status==STATUS_SELECT3)
							{
								p->item[i].last_status = p->item[i].now_status;
								
								(*p->item[i].f)(p,i);	

								png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select3,p->item[i].size_of_pic_item_select3,Virtual_LCDbuff);
	 				
							
					  	}
							if((!f_ui_disply_keyboard))
							Virtual_LCD_Upgrate();
						}
				 
				 }
			   
				 
				 if(page_home.page_left_side.last_item != LEFT_SIDE_PAGE_UPDATA)
				 {			
				 
				 	page_dis_all_val(dis_page_item,FALSE);
				 }
					
						
					
				 sysprintf("\r\n  !!!!!!!wo  jin lai la !!!!!!!!!!!!!!!!! \r\n");
			   if((f_ui_need_disply_dialog_code==FALSE)&&(f_ui_need_disply_dialog_msg==FALSE)&&(f_ui_need_disply_dialog_test==FALSE))
						disply_input_val(FALSE);
			   //page_printf_info(' ',TRUE);			 
				 
			   page_printf_DisplayBuf(TRUE);					
				 
				 if(f_ui_need_disply_dialog_code)
				 {
					 ui_disply_dialog_code();
					 f_ui_need_disply_dialog_code = FALSE;
				 }
				 else if(f_ui_need_disply_dialog_msg)
				 {
					 if(f_ui_disply_dialog_code==FALSE)
						ui_disply_dialog_msg();
					 f_ui_need_disply_dialog_msg = FALSE;
				 }
			   else if(f_ui_disply_dialog_info)
				 {
					 disply_info(FALSE);
				 }
				 else if(f_ui_need_disply_dialog_test)
				 {
					 if(f_ui_disply_dialog_code==FALSE)
						 //ui_disply_dialog_test();
					 f_ui_need_disply_dialog_test = FALSE;
				 }
				 else if(f_ui_disply_dialog_info_5)
				 {
					 ui_column_setup_system_upgrade_info_str(FALSE);
				 }
				 if((!f_ui_disply_keyboard))
					 dis_page_item = 1;
					
				}		
		 break;

	 }
}

//触摸处理入口

u8 touch_keep_press_ch =0xFF;
u8 long_press_ch =0xFF;
u8 slide_press_ch =0xFF;
u32 long_press_time =0;
u32 touch_keep_press_time =0;
void out_from_long_touch_status(void)//中断长按状态
{
  touch_keep_press_ch =0xFF; 
  long_press_ch =0xFF;
  slide_press_ch =0xFF;
}


u16 X_touch_now = 0;
u16 Y_touch_now = 0;
void page_touch_pro(u16 x,u16 y)
{
	u8 i,j;
	static BOOL f_touch_up = TRUE;
	lcd_dis_page_t *p,*p2;
	
	
	//if((g_GT911.X1!=0x0000)&&(g_GT911.X1!=0xFFFF)&&(g_GT911.Y1!=0x0000)&&(g_GT911.Y1!=0xFFFF))
	//{
	 time_touch_pro(x,y);   //这个函数是处理System->DATA&TIME的，因为里面的时间设置要实时更新
	 X_touch_now = x;
	 Y_touch_now = y;
	 if(((x==0x0000)||(x==0xFFFF))&&((y==0x0000)||(y==0xFFFF)))  //根据坐标值判断按键弹起
	 {
	   if(f_touch_up)
			 return;
	   f_touch_up = TRUE;
		 f_sleep_now = FALSE;
		// send_FlC200_test_cmd(0);//休眠计算
		 send_FlC200_base_set_cmd(0x89,0x00,0);
		 long_press_ch = 0xFF;
		 slide_press_ch = 0xFF;
	 //}
		
	//if((x==0)&&(y==0))//弹起
	//{
		 
		 
		 /////////////////////////
	  p = &page_home.page_left_side;
		for(i=0;i<LEFT_SIDE_ICO_NUM;i++)
		{
			if(p->item[i].now_status ==STATUS_TOUCH)  //
			{
				 for(j=0;j<LEFT_SIDE_ICO_NUM;j++)
				    p->item[j].now_status =STATUS_IDLE;//需要取消当前选中的页
				 p->item[i].now_status =STATUS_SELECT;
				 //sysprintf("left now_status:%d,%d\r\n",i,p->item[i].now_status);
			}
		}
		p = &page_home.page_info;
		for(i=0;i<INFO_ICO_NUM;i++)
		{
			if(p->item[i].now_status ==STATUS_TOUCH)
			{
				 for(j=0;j<INFO_ICO_NUM;j++)
				    p->item[j].now_status =STATUS_IDLE;//需要取消当前选中的页
				 p->item[i].now_status =STATUS_SELECT;
				 //sysprintf("left now_status:%d,%d\r\n",i,p->item[i].now_status);
			}
		}
			
		 ///////////////////////////
		 p = &page_home.page_top_side[page_home.page_left_side.now_item];
		 for(i=0;i<TOP_SIDE_ICO_NUM;i++)
		 {
		 	if(p->item[i].now_status ==STATUS_TOUCH)
		 	{
		 		 for(j=0;j<TOP_SIDE_ICO_NUM;j++)
		 		    p->item[j].now_status =STATUS_IDLE;//需要取消当前选中的页
		 		 p->item[i].now_status =STATUS_SELECT;
		 		//sysprintf("top now_status:%d,%d\r\n",i,p->item[i].now_status);
		 	}
		 }
		 /////////////////////////
		 if(f_ui_disply_dialog_code)
		 {
				p = &page_home.page_dialog_code;
		 }
		 else if(f_ui_disply_dialog_msg)
		 {
				p = &page_home.page_dialog_msg;
		 }
		 else if(f_ui_disply_dialog_test)
		 {
				p = &page_home.page_dialog_test;
		 }
		 else  if(f_ui_disply_keyboard)
		 {
			 if(f_ui_out_keyboard)
			 {
			 	 f_ui_disply_keyboard = FALSE;
			 	 f_ui_out_keyboard = FALSE;
			 	 ui_out_keyboard();
			 		
			 }
				p = &page_home.page_keyboard;
		 }
		 else if(f_ui_disply_dialog_lights)
		 {
				p = &page_home.page_dialog_lights;
		 }
		 else if(f_ui_disply_dialog_loads)
		 {
				p = &page_home.page_dialog_loads;
		 }
		 else if(f_ui_disply_dialog_motors)
		 {
				p = &page_home.page_dialog_motors;
		 }
		 else if(f_ui_disply_dialog_lights_ch)
		 {
				p = &page_home.page_dialog_lights_ch;
		 }
		 else if(f_ui_disply_dialog_loads_ch)
		 {
				p = &page_home.page_dialog_loads_ch;
		 }
		 else if(f_ui_disply_dialog_info)
		 {
				p = &page_home.page_dialog_info;
		 }
		 else
		 {
			 p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
			if(page_deepth_val[p2->now_item] == 0)//判断父子页面深度
				p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
			else if(page_deepth_val[p2->now_item] == 1)//判断父子页面深度   1层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			else if(page_deepth_val[p2->now_item] == 2)//判断父子页面深度   2层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1]->sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			 
		 }
		 //p = &page_home.page_main_item[LEFT_SIDE_PAGE_AC][TOP_SIDE_PAGE_AC_CLIMATE];
		 for(i=0;i<p->item_num;i++)
		 {	
				if(p->item[i].now_status ==STATUS_TOUCH)
				{
					//for(j=0;j<TOP_SIDE_ICO_NUM;j++)
					//   p->item[j].now_status =STATUS_IDLE;//需要取消当前选中的页
					if(p->item[i].last_status == STATUS_TOUCH_ON_IDLE)
						p->item[i].now_status =STATUS_SELECT;
					else if((p->item[i].last_status == STATUS_TOUCH_ON_SELECT)&&(p->item[i].pic_item_select_num>=2))
						p->item[i].now_status =STATUS_SELECT2;
					else if((p->item[i].last_status == STATUS_TOUCH_ON_SELECT2)&&(p->item[i].pic_item_select_num>=3))
						p->item[i].now_status =STATUS_SELECT3;
					else 
						p->item[i].now_status =STATUS_IDLE;
					
				}
		 }
		
	//	time_touch_pro(x,y);
		
	  return;
	}
	 else
	 {
     if(!f_touch_up)
		 {
		    //处理长按
			 //sysprintf("\r\nslide_press_ch%d",slide_press_ch);
			 if((long_press_ch!=0xFF)||(slide_press_ch!=0xFF)||(touch_keep_press_ch!=0xFF))//have press
			 {
				 
				 //页面按键
			  p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
			if(page_deepth_val[p2->now_item] == 0)//判断父子页面深度
				p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
			else if(page_deepth_val[p2->now_item] == 1)//判断父子页面深度   1层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			else if(page_deepth_val[p2->now_item] == 2)//判断父子页面深度   2层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1]->sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			 
		   	//p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
	      //p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
			 //p = &page_home.page_main_item[LEFT_SIDE_PAGE_AC][TOP_SIDE_PAGE_AC_CLIMATE];
			  for(i=0;i<p->item_num;i++)
			 {
					if(page_home_deel_with_i(p2,&i))
								 break;
					if(page_lights_deel_with_i(p2,&i))
								 break;
					if(page_loads_deel_with_i(p2,&i))
								break;		
						// if(page_ac_seet_deel_with_i(p2,&i))
						//		 break;
						// if(page_car_info_deel_with_i(p2,&i))
					//			 break;
						 
					 if((x>=p->item[i].x_val)&&(x<=p->item[i].x_end_val)&&(y>=p->item[i].y_val)&&(y<=p->item[i].y_end_val))
					 {
						if(i==long_press_ch)
						{
							//sysprintf("\r\n i2:%d,%d,%d",i,p->item[i].last_status,p->item[i].now_status);
							if(((p->item[i].key_type == KEY_TYPE_LONG_PRESS)||(p->item[i].key_type ==KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))&&((p->item[i].now_status ==STATUS_TOUCH)))		
							{					
								
								if(CntDelayTime(&long_press_time,TIME_ONE_MS*1200))
								{
									p->item[i].now_status = STATUS_TOUCH_LONG_PRESS;
									//sysprintf("\r\n i4:%d,%d,%d",i,p->item[i].last_status,p->item[i].now_status);
								}
							}
						}
						else if(i==slide_press_ch)
						{
							//sysprintf("\r\n8888888888888888888888888555");
							if(p->item[i].key_type == KEY_TYPE_SLIDE)		
							{					
								slide_x = x;
								slide_y = y;
							(*p->item[i].f)(p,i);
							}
						}
						else if(i==touch_keep_press_ch)
						{
							//sysprintf("\r\n8888888888888888888888888555");
							if(p->item[i].key_type == KEY_TYPE_TOUCH_KEEP)		
							{					
								//slide_x = x;
								//slide_y = y;
								if(CntDelayTime(&touch_keep_press_time,TIME_ONE_MS*500))
								{
									ResetDelayTime(&touch_keep_press_time); 
							     (*p->item[i].f)(p,i);
									 
								}
							}
						}
						else if((p->item[i].key_type != KEY_TYPE_TOUCH_NONE)&&(p->item[i].key_type != KEY_TYPE_TOUCH_NONE_2)&&(p->item[i].key_type != KEY_TYPE_TOUCH_AND_DISPLAY_NONE))		
						{				
							long_press_ch = 0xFF;
							//slide_press_ch = 0xFF;
						}
					
						
					 }
				}	
			 
			    
 
			 
			 }
			 
		 return;
		 }
		 if(f_touch_up)
		 {
	     f_touch_up = FALSE;
			 //send_FlC200_test_cmd(0);//休眠计算
			 send_FlC200_base_set_cmd(0x89,0x01,0);
			 
		 }
		 if(f_sleep_now)
		 {
			 return;
		 }
		 
		 
		 
		 //键盘
		 if(now_in_dialog_or_keyboard_window())
		 {
			 
			  if(f_ui_disply_dialog_code) 
					p = &page_home.page_dialog_code;
				else if(f_ui_disply_dialog_msg) 
					p = &page_home.page_dialog_msg;
				else if(f_ui_disply_dialog_test) 
					p = &page_home.page_dialog_test;
			  else if(f_ui_disply_keyboard)
				{
					
					p = &page_home.page_keyboard;
					if((x>0)&&(x<800)&&(y>0)&&(y<220))
					{
						//no keyboard area
						f_ui_out_keyboard = TRUE;
					}
			  }
				else if(f_ui_disply_dialog_lights) p = &page_home.page_dialog_lights;
				else if(f_ui_disply_dialog_loads)  p = &page_home.page_dialog_loads;
				else if(f_ui_disply_dialog_motors)  p = &page_home.page_dialog_motors;
				else if(f_ui_disply_dialog_lights_ch) p = &page_home.page_dialog_lights_ch;
				else if(f_ui_disply_dialog_loads_ch) p = &page_home.page_dialog_loads_ch;
				
				else if(f_ui_disply_dialog_info) p = &page_home.page_dialog_info;
				
			  for(i=0;i<p->item_num;i++)
			 {
				 if(f_ui_disply_dialog_code)
				 {
				    if(page_dialog_code_deel_with_i(p,&i))
							 break;
			   }
				 else if(f_ui_disply_dialog_msg)
				 {
				    if(page_dialog_msg_deel_with_i(p,&i))
							 break;
			   }
				 else if(f_ui_disply_keyboard)
				 {
				    if(page_keyboard_deel_with_i(p,&i))
							 break;
			   }
				 else if(f_ui_disply_dialog_lights)
				 {
				    if(page_dialog_lights_deel_with_i(p,&i))
							 break;
			   }
				 else if(f_ui_disply_dialog_loads)
				 {
				    if(page_dialog_loads_deel_with_i(p,&i))
							 break;
			   }
				 else if(f_ui_disply_dialog_motors)
				 {
				    if(page_dialog_motors_deel_with_i(p,&i))
							 break;
			   }
				 else if(f_ui_disply_dialog_lights_ch)
				 {
				    if(page_dialog_lights_ch_deel_with_i(p,&i))
							 break;
			   }
				 else if(f_ui_disply_dialog_loads_ch)
				 {
				    if(page_dialog_loads_ch_deel_with_i(p,&i))
							 break;
			   }				 
				 else if(f_ui_disply_dialog_info)
				 {
				    if(page_dialog_info_deel_with_i(p,&i))
							 break;
			   }
				 
				//sysprintf("\r\n i1:%d",i);
					// if(page_ac_seet_deel_with_i(p2,&i))
					//		 break;
					// if(page_car_info_deel_with_i(p2,&i))
				//			 break;
					 
				 if((x>=p->item[i].x_val)&&(x<=p->item[i].x_end_val)&&(y>=p->item[i].y_val)&&(y<=p->item[i].y_end_val))
				{
					if(p->item[i].key_type == KEY_TYPE_NORMAL)
					{
						 //p->item[j].now_status
						 p->item[i].now_status =STATUS_TOUCH;
						 send_FlC200_base_set_cmd(0x89,0x02,0);
						//sysprintf("\r\n i:%d",i);
						return;
					}
					else if((p->item[i].key_type == KEY_TYPE_TOUCH_NONE)||(p->item[i].key_type == KEY_TYPE_TOUCH_AND_DISPLAY_NONE))
					{
					 // p->item[i].now_status =STATUS_IDLE;
						//return;//给排在后面兄弟一点机会
					}
					else if(p->item[i].key_type == KEY_TYPE_TOUCH_NONE_2)
					{
					  p->item[i].now_status =STATUS_SELECT;
						//return;//给排在后面兄弟一点机会
					}
					else if(p->item[i].key_type == KEY_TYPE_N_SEL_1)
					{
					  if(p->item[i].now_status !=STATUS_SELECT)
						{
					    p->item[i].now_status =STATUS_TOUCH;
							send_FlC200_base_set_cmd(0x89,0x02,0);
						}
						return;
					}					
                    
                    else if(p->item[i].key_type == KEY_TYPE_N_SEL)
					{
					  if(p->item[i].now_status !=STATUS_SELECT)
						{
					    p->item[i].now_status =STATUS_TOUCH;
						}
						return;
					}					
                    
                    
                    
					else
					{
					   if(p->item[i].now_status !=STATUS_SELECT)
						 {
					    p->item[i].now_status =STATUS_TOUCH;
							 send_FlC200_base_set_cmd(0x89,0x02,0);
						 }
					}
				}
			}
		} 
		 else
		 {
		  //左侧按键
			p = &page_home.page_left_side;
			for(i=0;i<LEFT_SIDE_ICO_NUM;i++)
			{
				 if((x>=p->item[i].x_val)&&(x<=p->item[i].x_end_val)&&(y>=p->item[i].y_val)&&(y<=p->item[i].y_end_val))
				{
					if(p->item[i].now_status !=STATUS_SELECT)
					{
						 p->item[i].now_status =STATUS_TOUCH;

				 
						send_FlC200_base_set_cmd(0x89,0x02,0);
						//sysprintf("left now_status:%d,%d\r\n",i,p->item[i].now_status);
						return;
					}
					
				}
			}
			//info按键
			p = &page_home.page_info;
			for(i=0;i<INFO_ICO_NUM;i++)
			{
				 if((x>=p->item[i].x_val)&&(x<=p->item[i].x_end_val)&&(y>=p->item[i].y_val)&&(y<=p->item[i].y_end_val))
				{
					if(p->item[i].now_status !=STATUS_SELECT)
					{
						 p->item[i].now_status =STATUS_TOUCH;
						 send_FlC200_base_set_cmd(0x89,0x02,0);
						//sysprintf("left now_status:%d,%d\r\n",i,p->item[i].now_status);
						return;
					}
					
				}
			}
			
			
			//顶部按键
			p = &page_home.page_top_side[page_home.page_left_side.now_item];
			for(i=0;i<HOME_TEST_TOP_ITEM_NUM;i++)
			{
				 if((x>=p->item[i].x_val)&&(x<=p->item[i].x_end_val)&&(y>=p->item[i].y_val)&&(y<=p->item[i].y_end_val))
				 {
					//sysprintf("top type:%d,%d\r\n",i,p->item[i].key_type);
					if((p->item[i].key_type == KEY_TYPE_TOUCH_NONE)||(p->item[i].key_type == KEY_TYPE_TOUCH_AND_DISPLAY_NONE))
					{
					  //p->item[i].now_status =STATUS_IDLE;
						
						return;
					}
					else if(p->item[i].key_type == KEY_TYPE_TOUCH_NONE_2)
					{
					  p->item[i].now_status =STATUS_SELECT;
						//return;//给排在后面兄弟一点机会
						return;
					}
					else if(p->item[i].now_status !=STATUS_SELECT)
					{
						 p->item[i].now_status =STATUS_TOUCH;
						 send_FlC200_base_set_cmd(0x89,0x02,0);
						//sysprintf("top now_status:%d,%d\r\n",i,p->item[i].now_status);
						return;
					}
					
					
				}
			}
			
			//页面按键
			p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	
			if(page_deepth_val[p2->now_item] == 0)//判断父子页面深度
				p = &page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item];	
			else if(page_deepth_val[p2->now_item] == 1)//判断父子页面深度   1层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			else if(page_deepth_val[p2->now_item] == 2)//判断父子页面深度   2层子页面
				p = page_home.page_main_item[page_home.page_left_side.now_item][p2->now_item].sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1]->sub_page[page_sub_page_serial_num[page_deepth_val[p2->now_item]-1][p2->now_item]-1];
			 
			//p = &page_home.page_main_item[LEFT_SIDE_PAGE_AC][TOP_SIDE_PAGE_AC_CLIMATE];
			for(i=0;i<p->item_num;i++)
			{
				if(page_home_deel_with_i(p2,&i))
							 break;
				if(page_lights_deel_with_i(p2,&i))
							 break;
				if(page_loads_deel_with_i(p2,&i))
               break;		
				if(page_power_special_handle(p2,i,x,y))
							 continue;
					// if(page_ac_seet_deel_with_i(p2,&i))
					//		 break;
					// if(page_car_info_deel_with_i(p2,&i))
				  //		 break;
				if((x>=p->item[i].x_val)&&(x<=p->item[i].x_end_val)&&(y>=p->item[i].y_val)&&(y<=p->item[i].y_end_val))//图片内点击
				{
					if(p->item[i].key_type == KEY_TYPE_NORMAL)//默认按键状态
					{
						 //p->item[j].now_status
						 p->item[i].now_status =STATUS_TOUCH;//赋值图片现在状态
						send_FlC200_base_set_cmd(0x89,0x02,0);
						return;
					}
					else if(p->item[i].key_type == KEY_TYPE_SLIDE)  //可以划动按键状态
					{
						 //p->item[j].now_status
						 //p->item[i].now_status =STATUS_TOUCH;
						
						 slide_x = x;slide_y = y;//获取滑动坐标
						(*p->item[i].f)(p,i);//处理滑动坐标
						 slide_press_ch = i;
						return;
					}
					else if((p->item[i].key_type == KEY_TYPE_TOUCH_NONE)||(p->item[i].key_type == KEY_TYPE_TOUCH_AND_DISPLAY_NONE))//不进行触摸 弹起图标当背景显示 ， //不进行触摸 也不显示
					{
						
					 // p->item[i].now_status =STATUS_IDLE;
						//return;//给排在后面兄弟一点机会
					}
					else if(p->item[i].key_type == KEY_TYPE_TOUCH_NONE_2) //不进行触摸 选择图标当背景显示 
					{
					  p->item[i].now_status =STATUS_SELECT;
						//return;//给排在后面兄弟一点机会
					}
					else if(p->item[i].key_type == KEY_TYPE_N_SEL_1) //多个选择一个，当选中时只能通过选中其他选项取消
					{
						
					  if(p->item[i].now_status !=STATUS_SELECT)
						{
							
					    p->item[i].now_status =STATUS_TOUCH;
							send_FlC200_base_set_cmd(0x89,0x02,0);
						}
						return;
					}
                  	else if(p->item[i].key_type == KEY_TYPE_N_SEL) //多个选择一个，当选中时只能通过选中其他选项取消
					{
						
					  if(p->item[i].now_status !=STATUS_SELECT)
						{
							
					    p->item[i].now_status =STATUS_TOUCH;
						}
						return;
					}  
                    
                    
          else if((p->item[i].key_type == KEY_TYPE_LONG_PRESS)||(p->item[i].key_type == KEY_TYPE_LONG_PRESS_AND_DISPLAY_NONE))//有长按功能//有长按功能 但不显示（什么鬼）
					{
						//if((p->item[i].now_status !=STATUS_SELECT_LONG_PRESS))
					    p->item[i].now_status = STATUS_TOUCH;//触控状态
						send_FlC200_base_set_cmd(0x89,0x02,0);
						sysprintf("\r\n i1:%d,%d,%d",i,p->item[i].last_status,p->item[i].now_status);
				    ResetDelayTime(&long_press_time); 
						long_press_ch = i;
						return;
					}	
					else if(p->item[i].key_type == KEY_TYPE_TOUCH_KEEP)//需要持续按住才有效的按键
					{
						//if((p->item[i].now_status !=STATUS_SELECT_LONG_PRESS))
					   p->item[i].now_status = STATUS_TOUCH;
						send_FlC200_base_set_cmd(0x89,0x02,0);
						sysprintf("\r\n KEY_TYPE_TOUCH_KEEP i1:%d,%d,%d",i,p->item[i].last_status,p->item[i].now_status);
				    ResetDelayTime(&touch_keep_press_time); 
						touch_keep_press_ch = i;
						return;
					}
					else
					{
					   if(p->item[i].now_status !=STATUS_SELECT)
						 {
					     p->item[i].now_status =STATUS_TOUCH;
							 send_FlC200_base_set_cmd(0x89,0x02,0);
						 }
					}
				}
			}
		}
			//time_touch_pro(x,y);
}
	

}
