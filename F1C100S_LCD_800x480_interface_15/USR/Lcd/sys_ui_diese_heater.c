#include "includes.h"

#define PAGE_DH_NUM  12


#define DH_CUT_ADD_SN  4

lcd_dis_item_t *p_home_item_DH_u[PAGE_DH_NUM]={
            &t_page4_6_0            ,

&t_page4_bk1               ,
&t_page4_bk2           ,
&t_page4_bk3_up           ,
    
&t_page4_cut            ,//4
&t_page4_add           ,

&t_page4_Ellipse	      ,
&t_page4_key_up         ,
&t_text_Alarm          ,
&t_text_Diesel_heater       ,
//&t_text_rgb            ,
&t_Vector_1            ,
&t_Vector_2            ,
    


};

lcd_dis_item_t *p_home_item_DH_d[PAGE_DH_NUM]={
&t_page4_6_0           ,
&t_page4_bk1           ,
&t_page4_bk2           ,
&t_page4_bk3           ,
    
&t_page4_cut_d            ,
&t_page4_add_d           ,

&t_page4_Ellipse	      ,
&t_page4_key_d         ,//7
&t_text_Alarm          ,
&t_text_Diesel_heater       ,
//&t_text_rgb            ,
&t_Vector_1            ,
&t_Vector_2            ,


};						 
lcd_dis_item_t DH_item[PAGE_DH_NUM];//图片缓存区？？

void ui_Dise_Heater_init(void)   
{
	lcd_dis_page_t *p;
	u8 i;
   
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][3]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_background_2.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_2.size_of_pic_item;// backgroud pic size
    
    
    
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END; 
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=PAGE_DH_NUM;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only

    t_page4_bk1        .key_type=KEY_TYPE_TOUCH_NONE;
    t_page4_bk2        .key_type=KEY_TYPE_TOUCH_NONE;
    t_page4_Ellipse_g        .key_type=KEY_TYPE_TOUCH_NONE;
    t_text_Alarm        .key_type=KEY_TYPE_TOUCH_NONE;
    t_text_Diesel_heater        .key_type=KEY_TYPE_TOUCH_NONE;
    t_Vector_1        .key_type=KEY_TYPE_TOUCH_NONE;
    t_Vector_2        .key_type=KEY_TYPE_TOUCH_NONE;
        t_page4_6_0        .key_type=KEY_TYPE_TOUCH_NONE;
        t_page4_6_1        .key_type=KEY_TYPE_TOUCH_NONE;
        t_page4_6_2        .key_type=KEY_TYPE_TOUCH_NONE;
        t_page4_6_3        .key_type=KEY_TYPE_TOUCH_NONE;
        t_page4_6_4        .key_type=KEY_TYPE_TOUCH_NONE;
        t_page4_6_5        .key_type=KEY_TYPE_TOUCH_NONE;
        t_page4_6_6        .key_type=KEY_TYPE_TOUCH_NONE;
        
        t_page4_cut_d        .key_type=KEY_TYPE_ONCE;
        t_page4_add_d        .key_type=KEY_TYPE_ONCE;

        
        t_page4_bk3        .key_type=KEY_TYPE_TOUCH_KEEP;

	p->item = DH_item;
	for(i=0;i<PAGE_DH_NUM;i++)
	{
		memcpy(&(p->item[i]),p_home_item_DH_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_DH_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_DH_u[i]->size_of_pic_item ;
	}
    

}



DiseHeaterSystem now_DiseHeater_status;   //现在状态

void key_state_DH(lcd_dis_item_t *p)//开关
{
      if(now_DiseHeater_status.isPowerOn==0)
      {
                        p = &t_page4_6_0;
                     png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                 p = &t_page4_key_up;
         png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
          
          if(now_DiseHeater_status.heatDissipation==1)//散热
          {
            p = &t_page4_Ellipse_r;//r球
            png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
              DH_item[7].key_type=KEY_TYPE_TOUCH_NONE;//散热状态开关不给触控
          }else{
            p = &t_page4_Ellipse;//灰球
            png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
              
              DH_item[7].key_type=KEY_TYPE_NORMAL;//恢复开关不给触控
          }
          
          

      }else  if(now_DiseHeater_status.isPowerOn==1)
      {

                 p = &t_page4_key_d;
         png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
           DH_item[DH_CUT_ADD_SN].key_type=KEY_TYPE_ONCE;//加减档
            DH_item[DH_CUT_ADD_SN+1].key_type=KEY_TYPE_ONCE;

          
          if(now_DiseHeater_status.heatDissipation==1)//散热
          {
                   p = &t_page4_Ellipse_r;//r球
         png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
          }else
         p = &t_page4_Ellipse_g;//绿球
         png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

          
      }
}
    
#define alarm_add_x 40
void disply_DiseHeater_pic(bool upgrade)
{
    
	static DiseHeaterSystem old_DiseHeater_status;   
	char display_buf[32];
	lcd_dis_item_t *p;
  	lcd_dis_item_t *p4;


            //now_DiseHeater_status.warn.flameExtinguished=1;             // 火焰熄灭警告
//            now_DiseHeater_status.warn.breaklineFault=1;             // 断路故障警告

//            now_DiseHeater_status.warn.motorFault=1;             // 电机故障
//            now_DiseHeater_status.warn.overHeating=1;           // 超温
//            now_DiseHeater_status.warn.oilPumpFaul=1;           // 油泵故障
//            now_DiseHeater_status.warn.ignitionPlugOut=1;       // 点火插头断开
//            now_DiseHeater_status.warn.overVoltage=1;           // 超压（y）
//            now_DiseHeater_status.warn.underVoltage=1;          // 欠压  （y）
    
//            // 先初始化所有故障状态为 0（避免残留旧状态）
//        now_DiseHeater_status.warn.ignitionPlugOut = 0;
//        now_DiseHeater_status.warn.motorFault      = 0;
//        now_DiseHeater_status.warn.oilPumpFaul    = 0;  // 原变量名 oilPumpFaul 修正为 oilPumpFault（拼写错误）
//        now_DiseHeater_status.warn.overHeating     = 0;
//        now_DiseHeater_status.warn.overVoltage     = 0;
//        now_DiseHeater_status.warn.underVoltage    = 0;
//        now_DiseHeater_status.warn.breaklineFault    = 0;
//        now_DiseHeater_status.warn.flameExtinguished    = 0;

//now_DiseHeater_status.heatDissipation=1;

    
	if((memcmp(&now_DiseHeater_status,&old_DiseHeater_status,sizeof(DiseHeaterSystem)))||upgrade)//判断是否状态更新
	{
    memcpy(&old_DiseHeater_status,&now_DiseHeater_status,sizeof(DiseHeaterSystem));//更新状态
        
         // 每次刷新先清除全部报警区域
      p4=&t_page4_bk2;
      png_dis_xy(p4->x_val,p4->y_val,p4->pic_item,p4->size_of_pic_item,Virtual_LCDbuff1);//
      p4=&t_text_Alarm;
      png_dis_xy(p4->x_val,p4->y_val,p4->pic_item,p4->size_of_pic_item,Virtual_LCDbuff1);//


            Virtual_LCD_Draw_Rectangle_ARGB32(553,151-20,247+alarm_add_x,40*6,Virtual_LCDbuff2,ARGB_clear);

            u8 warn_index = 0;
            int base_x = 553 + alarm_add_x;
            int base_y = 148;

              if(now_DiseHeater_status.heatDissipation==1){//散热
                      snprintf(display_buf, sizeof(display_buf), "Cooling Down");//
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x-30+12, base_y +15+40*2, display_buf, ARGB_white, 0, 1, 1);

              }
        
       //// 
        
        
            if(now_DiseHeater_status.warn.flameExtinguished){
                snprintf(display_buf, sizeof(display_buf), "The flame is ");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y +15, display_buf, ARGB_white, 0, 1, 1);
                snprintf(display_buf, sizeof(display_buf), "extinguished ");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*1, display_buf, ARGB_white, 0, 1, 1);

//                // 下划线
                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*1 + 35,
                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

//                // 红色图标
//                png_dis_xy(t_page4_alarm_r.x_val, base_y + 40*warn_index + 5,
//                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);

                  // 红色图标
                png_dis_xy(t_page4_alarm_r.x_val, base_y + 20 + 5,
                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);
              
                
              //  Virtual_LCD_Draw_Rectangle_ARGB32(t_page4_alarm_r.x_val, base_y + 40*warn_index + 5,t_page4_alarm_r.x_end_val-t_page4_alarm_r.x_val,t_page4_alarm_r.y_end_val-t_page4_alarm_r.y_val,Virtual_LCDbuff1,ARGB_clear);
              //  warn_index+=2;
            }        

            if(now_DiseHeater_status.warn.breaklineFault){
                snprintf(display_buf, sizeof(display_buf), "Break line fault");//Break line fault
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index, display_buf, ARGB_white, 0, 1, 1);

//                // 下划线
                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*warn_index + 35,
                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

                // 红色图标
                png_dis_xy(t_page4_alarm_r.x_val, base_y + 40*warn_index + 5,
                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);

                
                
                
                
              //  warn_index+=2;
            }

            
        
            if(now_DiseHeater_status.warn.motorFault){
                snprintf(display_buf, sizeof(display_buf), "Motor Fault");
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index, display_buf, ARGB_white, 0, 1, 1);

//                // 下划线
                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*warn_index + 35,
                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

                // 红色图标
                png_dis_xy(t_page4_alarm_r.x_val, base_y + 40*warn_index + 5,
                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);

               // warn_index+=2;
            }

            
            
            if(now_DiseHeater_status.warn.overHeating){
//                snprintf(display_buf, sizeof(display_buf), "The machine is ");//The machine is overheating.
//                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index, display_buf, ARGB_white, 0, 1, 1);
//                snprintf(display_buf, sizeof(display_buf), "overheating ");//The flame is extinguished.
//                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index+1, display_buf, ARGB_white, 0, 1, 1);

                snprintf(display_buf, sizeof(display_buf), "The machine is ");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y +15, display_buf, ARGB_white, 0, 1, 1);
                snprintf(display_buf, sizeof(display_buf), "overheating ");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*1, display_buf, ARGB_white, 0, 1, 1);

//                // 下划线
                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*1 + 35,
                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

                  // 红色图标
                png_dis_xy(t_page4_alarm_r.x_val, base_y + 20 + 5,
                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);

//                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*warn_index + 35,
//                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

//                // 红色图标
//                png_dis_xy(t_page4_alarm_r.x_val, base_y + 40*warn_index + 5,
//                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);

            }

            if(now_DiseHeater_status.warn.oilPumpFaul){
                snprintf(display_buf, sizeof(display_buf), "Oil Pump Fault");//Oil pump fault
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index, display_buf, ARGB_white, 0, 1, 1);

//                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*warn_index + 35,
//                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

                // 红色图标
                png_dis_xy(t_page4_alarm_r.x_val, base_y + 40*warn_index + 5,
                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);
//                // 下划线
                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*warn_index + 35,
                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

            }

            if(now_DiseHeater_status.warn.ignitionPlugOut){
//                snprintf(display_buf, sizeof(display_buf), "The ignition plug ");//The ignition plug isout of order.
//                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index, display_buf, ARGB_white, 0, 1, 1);
//                snprintf(display_buf, sizeof(display_buf), "isout of order ");//The flame is extinguished.
//                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index+1, display_buf, ARGB_white, 0, 1, 1);

                snprintf(display_buf, sizeof(display_buf), "The ignition plug");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y +15, display_buf, ARGB_white, 0, 1, 1);
                snprintf(display_buf, sizeof(display_buf), "isout of order ");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*1, display_buf, ARGB_white, 0, 1, 1);

//                // 下划线
                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*1 + 35,
                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

                  // 红色图标
                png_dis_xy(t_page4_alarm_r.x_val, base_y + 20 + 5,
                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);

            }

            if(now_DiseHeater_status.warn.overVoltage){
//                snprintf(display_buf, sizeof(display_buf), "Overvoltage of");//Overvoltage of power supply
//                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index, display_buf, ARGB_white, 0, 1, 1);
//                snprintf(display_buf, sizeof(display_buf), "power supply ");//The flame is extinguished.
//                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index+1, display_buf, ARGB_white, 0, 1, 1);

                snprintf(display_buf, sizeof(display_buf), "Overvoltage of");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y +15, display_buf, ARGB_white, 0, 1, 1);
                snprintf(display_buf, sizeof(display_buf), "power supply ");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*1, display_buf, ARGB_white, 0, 1, 1);

//                // 下划线
                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*1 + 35,
                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

                  // 红色图标
                png_dis_xy(t_page4_alarm_r.x_val, base_y + 20 + 5,
                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);

                
                
            }

            if(now_DiseHeater_status.warn.underVoltage){
//                snprintf(display_buf, sizeof(display_buf), "Under-voltage ");//Under-voltage Of power supply
//                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index, display_buf, ARGB_white, 0, 1, 1);
//                snprintf(display_buf, sizeof(display_buf), "Of power supply");//The flame is extinguished.
//                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*warn_index+1, display_buf, ARGB_white, 0, 1, 1);


                snprintf(display_buf, sizeof(display_buf), "Under-voltage");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y +15, display_buf, ARGB_white, 0, 1, 1);
                snprintf(display_buf, sizeof(display_buf), "Of power supply");//The flame is extinguished.
                Virtual_LCD_Draw_String_ARGB_24_4bit(base_x, base_y + 40*1, display_buf, ARGB_white, 0, 1, 1);

//                // 下划线
                png_dis_xy(t_page4_alarm_t.x_val, base_y + 40*1 + 35,
                           t_page4_alarm_t.pic_item, t_page4_alarm_t.size_of_pic_item, Virtual_LCDbuff1);

                  // 红色图标
                png_dis_xy(t_page4_alarm_r.x_val, base_y + 20 + 5,
                           t_page4_alarm_r.pic_item, t_page4_alarm_r.size_of_pic_item, Virtual_LCDbuff1);

                
                
                
            }

            
            
            
                
    
        if(now_DiseHeater_status.manualOilPump==1)//泵油
        {
        t_page4_bk3.now_status=STATUS_SELECT;
        }else t_page4_bk3.now_status=STATUS_IDLE;
        
        
        switch(now_DiseHeater_status.icon_num)//显示档位
        {                              
            lcd_dis_item_t *p;//,*p2;
            case 0:
            {
                    key_state_DH(p);
                    p = &t_page4_6_0;
                     png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
            }break;
        
            case 1:
            {
                                    key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_1;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;
            case 2:
            {
                
                    key_state_DH(p);

                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

                                 p = &t_page4_6_2;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;
            case 3:
            {                                           
                key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_3;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;
            case 4:
            {
                                    key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_4;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;
            case 5:
            {
                                    key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_5;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;
            case 6:
            {
                                    key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_6;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;
            
            
            case 7: //6
            {
                                    key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_6;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;            
            
            case 8:
            {
                                    key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_6;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;

            case 9:
            {
                                    key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_6;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;           
            case 10:
            {
                                    key_state_DH(p);
                                     p = &t_page4_6_0;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
                                 p = &t_page4_6_6;
                       png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);

            }break;            
            
        }
            
                p=&t_page4_bk1;//清除的区域
        		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
                key_state_DH(p);

        
        if(now_DiseHeater_status.isPowerOn) sprintf(display_buf, "ON");
        else sprintf(display_buf, "OFF");
            // 显示到 LCD 指定位置
            Virtual_LCD_Draw_String_ARGB_16_4bit(40, 136, display_buf, (ARGB_darkGray), 0, 1, 1);

        		if(upgrade==FALSE){
                    Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
                    p = &t_page4_bk2;
                    Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
                    }   
    }
}



#define debuge_data_diese_heater 0//影响同步先打开
void FlC200_hc_comm_diese_heater_SW(u8* para) //获取同步数据 ,同步互动条
{
    	char display_buf[32];

    if(debuge_data_diese_heater)//打印接收
    {
        sysprintf("IN diese_heater Page data------------------------------------------- \r\n");
        u8 id  = para[0];   // 数据包ID
        u8 len = para[1];   // 数据长度
        int i;
        sysprintf("ID = 0x%02X, LEN = %d\r\n", id, len);
        sysprintf("para[0] DataType = %02X\r\n", para[0]);
        sysprintf("para[1] LEN      = %02X\r\n", para[1]);
        sysprintf("para[2] D0       = %02X\r\n", para[2]);
        sysprintf("para[3] D1 woerk mode      = %02X\r\n", para[3]);
        sysprintf("para[4] D2 Heats       = %02X\r\n", para[4]);
        sysprintf("para[5] D3 warning      = %02X\r\n", para[5]);
        // 打印数据区内容
        sysprintf("DATA: ");
        for (i = 0; i < len; i++)
        {
            sysprintf("%02X ", para[2 + i]);
        }
        sysprintf(" isPowerOn= %d\r\n", (para[3] >> 7) & 0x01);
        sysprintf(" heatDissipation= %d\r\n", (para[3] >> 6) & 0x01);
        sysprintf(" manualOilPump= %d\r\n", (para[3] >> 5) & 0x01);
       sysprintf(" icon_num= %02X\r\n", para[4]);
       sysprintf(" warn= %02X\r\n", para[5]);

        u8 warnByte =para[5];
        
                
        
        // 先初始化所有故障状态为 0（避免残留旧状态）
        now_DiseHeater_status.warn.ignitionPlugOut = 0;
        now_DiseHeater_status.warn.motorFault      = 0;
        now_DiseHeater_status.warn.oilPumpFaul    = 0;  // 原变量名 oilPumpFaul 修正为 oilPumpFault（拼写错误）
        now_DiseHeater_status.warn.overHeating     = 0;
        now_DiseHeater_status.warn.overVoltage     = 0;
        now_DiseHeater_status.warn.underVoltage    = 0;
        now_DiseHeater_status.warn.breaklineFault    = 0;
        now_DiseHeater_status.warn.flameExtinguished    = 0;

        
        
        // Bit0:火焰熄灭警告
        if (warnByte & (1 << 0))
        {
            sysprintf(" [WARN] Motor Fault (火焰熄灭警告)\r\n");
            now_DiseHeater_status.warn.flameExtinguished = 1;  // 置位：表示发生故障
        }        
        // Bit1断路故障警告
        if (warnByte & (1 << 1))
        {
            sysprintf(" [WARN] Motor Fault (断路故障警告)\r\n");
            now_DiseHeater_status.warn.breaklineFault = 1;  // 置位：表示发生故障
        }   
        // Bit2：电机故障
        if (warnByte & (1 << 2))
        {
            sysprintf(" [WARN] Motor Fault (电机故障)\r\n");
            now_DiseHeater_status.warn.motorFault = 1;  // 置位：表示发生故障
        }
        // 不满足时保持初始化的 0（无需额外 else，初始化已处理）
        // Bit3：超温警告
        if (warnByte & (1 << 3))
        {
            sysprintf(" [WARN] Over Heating (超温警告)\r\n");
            now_DiseHeater_status.warn.overHeating = 1;
        }
        // Bit4：油泵故障
        if (warnByte & (1 << 4))
        {
            sysprintf(" [WARN] Oil Pump Fault (油泵故障)\r\n");
            now_DiseHeater_status.warn.oilPumpFaul = 1;  // 修正变量名拼写错误
        }
        // Bit5：点火插头断开
        if (warnByte & (1 << 5))
        {
            sysprintf(" [WARN] Ignition Plug Out (点火插头断开)\r\n");
            now_DiseHeater_status.warn.ignitionPlugOut = 1;
        }
        // Bit6：超压警告
        if (warnByte & (1 << 6))
        {
            sysprintf(" [WARN] Over Voltage (超压警告)\r\n");
            now_DiseHeater_status.warn.overVoltage = 1;
        }
        // Bit7：欠压警告
        if (warnByte & (1 << 7))
        {
            sysprintf(" [WARN] Under Voltage (欠压警告)\r\n");
            now_DiseHeater_status.warn.underVoltage = 1;
        }
       sysprintf("\r\n--------------------------------------------------\r\n");
        sysprintf("--------------------------------------------------\r\n");

    }
    
    
    
     //获取反馈同步数据    

    // 获取反馈同步数据（Diesel Heater）
    now_DiseHeater_status.isPowerOn       = (para[3] & (1 << 7)) ? TRUE : FALSE;  // Bit7 isPowerOn
    now_DiseHeater_status.heatDissipation = (para[3] & (1 << 6)) ? TRUE : FALSE;  // Bit6 散热
    now_DiseHeater_status.manualOilPump   = (para[3] & (1 << 5)) ? TRUE : FALSE;  // Bit6 泵油
        
        
        
//    // 加热档位（0~10）
    now_DiseHeater_status.icon_num=para[4];

        
        
//    // 警告信息（warn 结构体逐位解析）
    u8 warnByte = para[5];
    now_DiseHeater_status.warn.flameExtinguished= (warnByte & (1 << 0)) ? TRUE : FALSE; // 火焰熄灭警告
    now_DiseHeater_status.warn.breaklineFault   = (warnByte & (1 << 1)) ? TRUE : FALSE; // 断路故障警告
        
    now_DiseHeater_status.warn.motorFault      = (warnByte & (1 << 2)) ? TRUE : FALSE; // 电机故障
    now_DiseHeater_status.warn.overHeating     = (warnByte & (1 << 3)) ? TRUE : FALSE; // 超温
    now_DiseHeater_status.warn.oilPumpFaul     = (warnByte & (1 << 4)) ? TRUE : FALSE; // 油泵故障
    now_DiseHeater_status.warn.ignitionPlugOut = (warnByte & (1 << 5)) ? TRUE : FALSE; // 点火插头断开
    now_DiseHeater_status.warn.overVoltage     = (warnByte & (1 << 6)) ? TRUE : FALSE; // 超压
    now_DiseHeater_status.warn.underVoltage    = (warnByte & (1 << 7)) ? TRUE : FALSE; // 欠压

}




