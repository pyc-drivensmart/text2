#include "includes.h"


#define AC_PAGE_ITEM_NUM  14
// 保持原变量名和类型不变
lcd_dis_item_t  p_ac_FAN_LOW;
lcd_dis_item_t  p_ac_FAN_MED;
lcd_dis_item_t  p_ac_FAN_HIGH;

// 用指针间接赋值实现 Fan_up
void Fan_up(void)
{
    lcd_dis_item_t *p_low = &p_ac_FAN_LOW;   // 指针指向 p_ac_FAN_LOW
    lcd_dis_item_t *p_med = &p_ac_FAN_MED;   // 指针指向 p_ac_FAN_MED
    lcd_dis_item_t *p_high = &p_ac_FAN_HIGH; // 指针指向 p_ac_FAN_HIGH

    *p_low = t_page5_LOW_up;    // 间接赋值：等价于 p_ac_FAN_LOW = t_page5_LOW_up
    *p_med = t_page5_MED_up;    // 间接赋值：等价于 p_ac_FAN_MED = t_page5_MED_up
    *p_high = t_page5_HIGH_up;  // 间接赋值：等价于 p_ac_FAN_HIGH = t_page5_HIGH_up
}

// 用指针间接赋值实现 Fan_b
void Fan_b(void)
{
    lcd_dis_item_t *p_low = &p_ac_FAN_LOW;
    lcd_dis_item_t *p_med = &p_ac_FAN_MED;
    lcd_dis_item_t *p_high = &p_ac_FAN_HIGH;

    *p_low = t_page5_LOW_b_d;   // 间接赋值
    *p_med = t_page5_MED_b_d;
    *p_high = t_page5_HIGH_b_d;
}

// 用指针间接赋值实现 Fan_r
void Fan_r(void)
{
    lcd_dis_item_t *p_low = &p_ac_FAN_LOW;
    lcd_dis_item_t *p_med = &p_ac_FAN_MED;
    lcd_dis_item_t *p_high = &p_ac_FAN_HIGH;

    *p_low = t_page5_LOW_r_d;   // 间接赋值
    *p_med = t_page5_MED_r_d;
    *p_high = t_page5_HIGH_r_d;
}



    
    
lcd_dis_item_t *p_home_item_ac_up[AC_PAGE_ITEM_NUM]={
	
  &t_page5_1           ,//圆背景0
  &t_page5_bk2         ,
       &t_page5_key_up      ,//开关2
 
    &t_page5_add         ,//3
  &t_page5_cut  ,       

  &t_page5_COOL_up     ,//模式5
      &t_page5_HEAT_up     ,

  &t_page5_LOW_up      ,//FAN MODE 7
  &t_page5_MED_up      ,
  &t_page5_HIGH_up     ,
    
  &t_page5_text1       ,
  &t_page5_text2       ,
    
    &t_page5_bk2,
&t_page4_V            ,
};

lcd_dis_item_t *p_home_item_ac_d[AC_PAGE_ITEM_NUM]={
	
  &t_page5_1           ,
  &t_page5_bk2         ,
      &t_page5_key_d       ,
      &t_page5_add         ,
      &t_page5_cut         ,
  &t_page5_COOL_b_d    ,
      &t_page5_HEAT_r_d    ,
     &p_ac_FAN_LOW     ,//随着mode变化
     &p_ac_FAN_MED       ,
     &p_ac_FAN_HIGH      ,
  &t_page5_text1       ,
  &t_page5_text2       ,
        &t_page5_bk2,//  
   &t_page4_V            ,


};						 
lcd_dis_item_t AC_item[AC_PAGE_ITEM_NUM];//图片缓存区？？

ACSystem now_AC_status;   //现在状态

#define set_F_x 142
#define set_F_y 183
#define set_F_o_x 150+4
#define set_F_o_y 180


#define set_x_o 169-8-2  //设置温度符号
#define set_all_x_o 10 



extern u8 old_p5_mode;//关闭前保存的模式
extern P6_HVAC_CTRL_STATUS page6_ac_ctrl;//空调参数结构体

void display_ac_str(u8 state)
{
    char display_buf[32];
    lcd_dis_item_t *p2;
    switch(state)
    {  
        case 0:
        {
            p2 = &t_page5_1;
            /* ---------- 清空显示区域 ---------- */
            Virtual_LCD_Draw_Rectangle_ARGB32(
                p2->x_val,
                p2->y_val,
                p2->x_end_val - p2->x_val,
                p2->y_end_val - p2->y_val,
                Virtual_LCDbuff2,
                ARGB_clear
            );

            /* ---------- 当前温度显示 ---------- */
            if (Is_uint_Fahrenheit())   // 显示 F
            {
                if (page6_ac_ctrl.Now_temp_f < 2000)
                {
                    sprintf(display_buf, "%d F", (page6_ac_ctrl.Now_temp_f + 5) / 10);  // 四舍五入
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x, 168+10+5,display_buf, ARGB_darkGray, 0, 1, 1);
                    Virtual_LCD_Draw_String_o(set_F_o_x, set_F_o_y,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,ARGB_darkGray, 0, 1, 1);
                }
                else    // 异常值
                {
                    sprintf(display_buf, "--");
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x+10, 168+10+5,display_buf, ARGB_darkGray, 0, 1, 1);
                }
            }
            else    // 显示 C
            {
                if (page6_ac_ctrl.Now_temp < 2000)
                {
                    sprintf(display_buf, "%d C", (page6_ac_ctrl.Now_temp + 5) / 10); // 四舍五入
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x, 168+10+5,display_buf, ARGB_darkGray, 0, 1, 1);
                    Virtual_LCD_Draw_String_o(set_F_o_x, set_F_o_y,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,ARGB_darkGray, 0, 1, 1);
                }
                else
                {
                    sprintf(display_buf, "--");
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x+10, 168+10+5,display_buf, ARGB_darkGray, 0, 1, 1);
                }
            }

            /* ---------- Set To ---------- */
            sprintf(display_buf, "Set To");
            Virtual_LCD_Draw_String_ARGB_16_4bit(120 + set_all_x_o, 214+5,display_buf, ARGB_darkGray, 0, 1, 1);

            /* ---------- 设定温度显示 ---------- */
            if (Is_uint_Fahrenheit())
            {
                if(old_p5_mode == MODE_COOL)
                    sprintf(display_buf, "%d  F", page6_ac_ctrl.Cool_set_temp_f);
                else if(old_p5_mode == MODE_HEAT_PUMP)
                    sprintf(display_buf, "%d  F", page6_ac_ctrl.Furnace_set_temp_f);
            }
            else
            {
                if(old_p5_mode == MODE_COOL)
                    sprintf(display_buf, "%d  C", page6_ac_ctrl.Cool_set_temp);
                else if(old_p5_mode == MODE_HEAT_PUMP)
                    sprintf(display_buf, "%d  C", page6_ac_ctrl.Furnace_set_temp);
            }

            /* 白色显示 Set Temp */
            Virtual_LCD_Draw_String_ARGB_16_4bit(166 + 8 + set_all_x_o, 214+5,
                                                 display_buf, ARGB_darkGray, 0, 1, 1);

            Virtual_LCD_Draw_String_o(set_x_o + set_all_x_o, 212+5,
                                      display_buf,
                                      (lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,
                                      ARGB_darkGray, 0, 1, 1);
        }break;
        case 1:
        {
            p2 = &t_page5_bk2_b;
            png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);

            p2 = &t_page5_1;
            Virtual_LCD_Draw_Rectangle_ARGB32(p2->x_val,p2->y_val,
                                              p2->x_end_val-p2->x_val,
                                              p2->y_end_val-p2->y_val,
                                              Virtual_LCDbuff2,ARGB_clear);

            /* ----------- 当前温度显示（含异常值） ----------- */
            if(Is_uint_Fahrenheit())
            {
                if(page6_ac_ctrl.Now_temp_f < 2000)
                {
                    sprintf(display_buf, "%d F", (page6_ac_ctrl.Now_temp_f + 5) / 10);
                                /* 蓝色高亮显示 */
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x,168+10+5,display_buf,(0xFF3193F9),0,1,1);
                    Virtual_LCD_Draw_String_o(set_F_o_x,set_F_o_y,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(0xFF3193F9),0,1,1);
                }
                else
                {
                    sprintf(display_buf, "--");
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x+10,168+10+5,display_buf,(0xFF3193F9),0,1,1);

                }
            }
            else
            {
                if(page6_ac_ctrl.Now_temp < 2000)
                {
                    sprintf(display_buf, "%d C", (page6_ac_ctrl.Now_temp + 5) / 10);
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x,168+10+5,display_buf,(0xFF3193F9),0,1,1);
                    Virtual_LCD_Draw_String_o(set_F_o_x,set_F_o_y,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(0xFF3193F9),0,1,1);                }
                else
                {
                    sprintf(display_buf, "--");
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x+10,168+10+5,display_buf,(0xFF3193F9),0,1,1);
                }
            }

            /* ----------- Set To ----------- */
            sprintf(display_buf, "Set To");
            Virtual_LCD_Draw_String_ARGB_16_4bit(120+set_all_x_o,214+5,
                display_buf,(ARGB_darkGray),0,1,1);

            /* ----------- 设定温度 ----------- */
            if(Is_uint_Fahrenheit())
                sprintf(display_buf,"%d  F",page6_ac_ctrl.Cool_set_temp_f);
            else
                sprintf(display_buf,"%d  C",page6_ac_ctrl.Cool_set_temp);

            Virtual_LCD_Draw_String_ARGB_16_4bit(166+8+set_all_x_o,214+5,
                display_buf,(ARGB_white),0,1,1);
            Virtual_LCD_Draw_String_o(set_x_o+set_all_x_o,212+5,
                display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,
                (ARGB_white),0,1,1);
        }break;


        case 2:
        {
            p2 = &t_page5_bk2_r;
            png_dis_xy(p2->x_val,p2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);

            p2 = &t_page5_1;
            Virtual_LCD_Draw_Rectangle_ARGB32(p2->x_val,p2->y_val,
                                              p2->x_end_val-p2->x_val,
                                              p2->y_end_val-p2->y_val,
                                              Virtual_LCDbuff2,ARGB_clear);

            /* ----------- 当前温度显示（含异常值） ----------- */
            if(Is_uint_Fahrenheit())
            {
                if(page6_ac_ctrl.Now_temp_f < 2000)
                {
                    sprintf(display_buf, "%d F", (page6_ac_ctrl.Now_temp_f + 5) / 10);
                            /* 红色高亮显示 */
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x,168+10+5,display_buf,(0xFFFC532E),0,1,1);
                    Virtual_LCD_Draw_String_o(set_F_o_x,set_F_o_y,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(0xFFFC532E),0,1,1);
                }
                else
                {
                    sprintf(display_buf, "--");
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x+10,168+10+5,display_buf,(0xFFFC532E),0,1,1);

                
                }
            }
            else
            {
                if(page6_ac_ctrl.Now_temp < 2000)
                {
                    sprintf(display_buf, "%d C", (page6_ac_ctrl.Now_temp + 5) / 10);
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x,168+10+5,display_buf,(0xFFFC532E),0,1,1);
                    Virtual_LCD_Draw_String_o(set_F_o_x,set_F_o_y,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(0xFFFC532E),0,1,1);
                    
                }
                else
                {
                    sprintf(display_buf, "--");
                    Virtual_LCD_Draw_String_ARGB_32_4bit_bold(set_F_x+10,168+10+5,display_buf,(0xFFFC532E),0,1,1);
                }
            }

            /* ----------- Set To ----------- */
            sprintf(display_buf, "Set To");
            Virtual_LCD_Draw_String_ARGB_16_4bit(120+set_all_x_o,214+5,
                display_buf,(ARGB_darkGray),0,1,1);

            /* ----------- 设定温度 ----------- */
            if(Is_uint_Fahrenheit())
                sprintf(display_buf,"%d  F",page6_ac_ctrl.Furnace_set_temp_f);
            else
                sprintf(display_buf,"%d  C",page6_ac_ctrl.Furnace_set_temp);

            Virtual_LCD_Draw_String_ARGB_16_4bit(166+8+set_all_x_o,214+5,
                display_buf,(ARGB_white),0,1,1);
            Virtual_LCD_Draw_String_o(set_x_o+set_all_x_o,212+5,
                display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,
                (ARGB_white),0,1,1);
        }break;


    
    }

}






void ui_ac_init(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][4]; //父页面4
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_background_2.pic_item;//poit to backgroud pic 
	p->size_of_pic_back=t_background_2.size_of_pic_item;// backgroud pic size
    
    
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=AC_PAGE_ITEM_NUM;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only

    

	t_page5_1.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
    t_page5_text1.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_text2.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
    
	t_page5_bk2.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_bk2_b.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_bk2_r.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;


    t_page5_cut.key_type = KEY_TYPE_TOUCH_KEEP;
	t_page5_add.key_type = KEY_TYPE_TOUCH_KEEP;//需要持续按住才有效的按键

    now_AC_status.nowTemp=25;//默认值
    now_AC_status.SetTemp=23;
    

Fan_up();
//Fan_r();
//Fan_b();
         display_ac_str(0);

	p->item = AC_item;
	for(i=0;i<AC_PAGE_ITEM_NUM;i++)
	{
		memcpy(&(p->item[i]),p_home_item_ac_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_ac_up[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_ac_up[i]->size_of_pic_item ;
	}
old_p5_mode=MODE_COOL;
}


void ui_ac_init_b(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][4]; //父页面4
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_background_2.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_2.size_of_pic_item;// backgroud pic size
    
    
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=AC_PAGE_ITEM_NUM;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only

    

	t_page5_1.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
    t_page5_text1.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_text2.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
    
	t_page5_bk2.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_bk2_b.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_bk2_r.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;


    t_page5_cut.key_type = KEY_TYPE_TOUCH_KEEP;
	t_page5_add.key_type = KEY_TYPE_TOUCH_KEEP;//需要持续按住才有效的按键

    Fan_b();
      display_ac_str(1);


	p->item = AC_item;
	for(i=0;i<AC_PAGE_ITEM_NUM;i++)
	{
		memcpy(&(p->item[i]),p_home_item_ac_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_ac_up[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_ac_up[i]->size_of_pic_item ;
	}
    
    
   AC_item[AC_MODE_SN].now_status = STATUS_SELECT;//COOL b选中
   AC_item[AC_MODE_SN].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 

   AC_item[AC_MODE_SN+1].now_status = STATUS_IDLE;//Heart r未选中
	AC_item[AC_MODE_SN+1].key_type = KEY_TYPE_NORMAL;//未选中,可以按下
   
   
   AC_item[AC_KEY_SN].now_status = STATUS_SELECT;//电源选中
	AC_item[AC_KEY_SN].key_type = KEY_TYPE_NORMAL;//,可以按下

                
   lcd_dis_page_t * p3 = &page_home.page_top_side[page_home.page_left_side.now_item];	
    p3->last_item = LEFT_SIDE_PAGE_UPDATA;
}



void ui_ac_init_r(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][4]; //父页面4
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_background_2.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_2.size_of_pic_item;// backgroud pic size
    
    
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=AC_PAGE_ITEM_NUM;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only

    

	t_page5_1.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
    t_page5_text1.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_text2.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
    
	t_page5_bk2.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_bk2_b.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
	t_page5_bk2_r.key_type = KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 ;
    

    t_page5_cut.key_type = KEY_TYPE_TOUCH_KEEP;
	t_page5_add.key_type = KEY_TYPE_TOUCH_KEEP;//需要持续按住才有效的按键

    
//Fan_up();
Fan_r();
    display_ac_str(2);

	p->item = AC_item;
	for(i=0;i<AC_PAGE_ITEM_NUM;i++)
	{
		memcpy(&(p->item[i]),p_home_item_ac_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_ac_up[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_ac_up[i]->size_of_pic_item ;
	}
    
    
			  AC_item[AC_MODE_SN].now_status=STATUS_IDLE;//b未选中
			   AC_item[AC_MODE_SN].key_type =KEY_TYPE_NORMAL;//未选中,可以按下

			  AC_item[AC_MODE_SN+1].now_status =  STATUS_SELECT;//r选中
				AC_item[AC_MODE_SN+1].key_type =  KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 

        			  AC_item[AC_KEY_SN].now_status = STATUS_SELECT;//电源选中
				AC_item[AC_KEY_SN].key_type = KEY_TYPE_NORMAL;//,可以按下

   lcd_dis_page_t * p3 = &page_home.page_top_side[page_home.page_left_side.now_item];	
    p3->last_item = LEFT_SIDE_PAGE_UPDATA;

}



#define  HVAC_NUM 1 //空调数量

void FlC200_hc_comm_Hvac_pro(u8* para)//获取同步输
{	   
	P6_HVAC_CTRL_STATUS* list_p;
	page6_ac_ctrl.sw_mode = para[1];//mode

    if(page6_ac_ctrl.sw_mode==MODE_COOL)
    {
    page6_ac_ctrl.fan_speed = para[2];//fan
    }
    if(page6_ac_ctrl.sw_mode==MODE_HEAT_PUMP)
    {
    page6_ac_ctrl.fan_speed_heat = para[2];//fan
    }    

//        if(Is_uint_Fahrenheit()==1)//F
//		{
			page6_ac_ctrl.Furnace_set_temp_f= para[3];
			page6_ac_ctrl.Cool_set_temp_f= para[4];
			page6_ac_ctrl.Auto_set_temp_f= para[5];
			page6_ac_ctrl.Now_temp_f = para[6]*256+para[7];
//		}
//		else  if(Is_uint_Fahrenheit()==0)///c
//		{
			page6_ac_ctrl.Furnace_set_temp= para[3];
			page6_ac_ctrl.Cool_set_temp = para[4];
			page6_ac_ctrl.Auto_set_temp = para[5];
			page6_ac_ctrl.Now_temp = para[6]*256+para[7];
//		}		
 
}


    


void AC_Status_synchronization_SW()//同步选项状态
{
    switch(page6_ac_ctrl.sw_mode)//同步模式
    {
            case MODE_OFF:
                AC_item[AC_ISPOWER_SN].now_status=STATUS_IDLE;
                AC_item[AC_MODE_SN].now_status=STATUS_IDLE;
				AC_item[AC_MODE_SN].key_type = KEY_TYPE_NORMAL;//未选中,可以按下
				AC_item[AC_MODE_SN+1].key_type = KEY_TYPE_NORMAL;//未选中,可以按下
                AC_item[AC_MODE_SN+1].now_status=STATUS_IDLE;
                for(int i=0;i<3;i++)
                {
                  AC_item[AC_FAN_MODE_SN+i].now_status=STATUS_IDLE;
                  AC_item[AC_FAN_MODE_SN+i].key_type = KEY_TYPE_TOUCH_NONE;//
                }
            break;
    		case MODE_COOL:
                for(int i=0;i<3;i++)
                {
                  AC_item[AC_FAN_MODE_SN+i].key_type = KEY_TYPE_NORMAL;//
                }
                AC_item[AC_MODE_SN].now_status=STATUS_SELECT;
                AC_item[AC_MODE_SN+1].now_status=STATUS_IDLE;
            break;
			case MODE_HEAT_PUMP:
                for(int i=0;i<3;i++)
                {
                  AC_item[AC_FAN_MODE_SN+i].key_type = KEY_TYPE_NORMAL;//
                }
                AC_item[AC_MODE_SN].now_status=STATUS_IDLE;
                AC_item[AC_MODE_SN+1].now_status=STATUS_SELECT;
            break;
			default:
				break;

    }
    
        if(page6_ac_ctrl.sw_mode==MODE_COOL)//制冷
        switch (page6_ac_ctrl.fan_speed & 0xF0)   // 解析高4位 FAN模式
        {
            case 0x00: // FAN OFF
                // 关闭所有风速选项
                AC_item[AC_FAN_MODE_SN].now_status     = STATUS_IDLE;   // LOW
                AC_item[AC_FAN_MODE_SN+1].now_status   = STATUS_IDLE;   // MID
                AC_item[AC_FAN_MODE_SN+2].now_status   = STATUS_IDLE;   // HIGH
                break;
            case 0x20: // FAN ON
                switch (page6_ac_ctrl.fan_speed & 0x0F) // 解析低4位风速档位
                {
                    case 0x01: // HIGH
                        AC_item[AC_FAN_MODE_SN].now_status     = STATUS_IDLE;
                        AC_item[AC_FAN_MODE_SN+1].now_status   = STATUS_IDLE;
                        AC_item[AC_FAN_MODE_SN+2].now_status   = STATUS_SELECT;
                    	
                        AC_item[AC_FAN_MODE_SN+2].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 

                        break;

                    case 0x02: // MID
                        AC_item[AC_FAN_MODE_SN].now_status     = STATUS_IDLE;
                        AC_item[AC_FAN_MODE_SN+1].now_status   = STATUS_SELECT;
                        AC_item[AC_FAN_MODE_SN+2].now_status   = STATUS_IDLE;
                    
                        AC_item[AC_FAN_MODE_SN+1].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 

                        break;

                    case 0x03: // LOW
                        AC_item[AC_FAN_MODE_SN].now_status     = STATUS_SELECT;
                        AC_item[AC_FAN_MODE_SN+1].now_status   = STATUS_IDLE;
                        AC_item[AC_FAN_MODE_SN+2].now_status   = STATUS_IDLE;
                        AC_item[AC_FAN_MODE_SN].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 

                        break;

                    default:
                        // 无效风速，不处理
                        break;
                }
        }

    
                
         if(page6_ac_ctrl.sw_mode==MODE_HEAT_PUMP)//制热
         switch (page6_ac_ctrl.fan_speed_heat & 0xF0)   // 解析高4位 FAN模式
         {
             case 0x00: // FAN OFF
                 // 关闭所有风速选项
                 AC_item[AC_FAN_MODE_SN].now_status     = STATUS_IDLE;   // LOW
                 AC_item[AC_FAN_MODE_SN+1].now_status   = STATUS_IDLE;   // MID
                 AC_item[AC_FAN_MODE_SN+2].now_status   = STATUS_IDLE;   // HIGH
                 break;


             case 0x20: // FAN ON
                 switch (page6_ac_ctrl.fan_speed_heat & 0x0F) // 解析低4位风速档位
                 {
                     case 0x01: // HIGH
                         AC_item[AC_FAN_MODE_SN].now_status     = STATUS_IDLE;
                         AC_item[AC_FAN_MODE_SN+1].now_status   = STATUS_IDLE;
                         AC_item[AC_FAN_MODE_SN+2].now_status   = STATUS_SELECT;
                        AC_item[AC_FAN_MODE_SN+2].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 

                         break;

                     case 0x02: // MID
                         AC_item[AC_FAN_MODE_SN].now_status     = STATUS_IDLE;
                         AC_item[AC_FAN_MODE_SN+1].now_status   = STATUS_SELECT;
                         AC_item[AC_FAN_MODE_SN+2].now_status   = STATUS_IDLE;
                        AC_item[AC_FAN_MODE_SN+1].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 
                         break;

                     case 0x03: // LOW
                         AC_item[AC_FAN_MODE_SN].now_status     = STATUS_SELECT;
                         AC_item[AC_FAN_MODE_SN+1].now_status   = STATUS_IDLE;
                         AC_item[AC_FAN_MODE_SN+2].now_status   = STATUS_IDLE;
                         AC_item[AC_FAN_MODE_SN].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 
                  
                         break;
             }
                 
         }
//ui_ac_init_b();//模式转化
}



void disply_AC_val(bool upgrade)
{
    
	char display_buf[32];
	lcd_dis_item_t *p;
    	
   
    static P6_HVAC_CTRL_STATUS old_page6_ac_ctrl;   
       
	if((memcmp(&page6_ac_ctrl,&old_page6_ac_ctrl,sizeof(P6_HVAC_CTRL_STATUS)))||upgrade)//判断是否状态更新
	{
        memcpy(&old_page6_ac_ctrl,&page6_ac_ctrl,sizeof(P6_HVAC_CTRL_STATUS));//更新状态
        AC_Status_synchronization_SW();//同步选项状态
        switch(page6_ac_ctrl.sw_mode)//page6_ac_ctrl.sw_mode
        {
            case MODE_OFF:{//no
                p = &t_page5_bk2;  
                
                png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);     
                display_ac_str(0);
            }break;
            case MODE_COOL:{//cool
                    
                p = &t_page5_bk2_b;
                png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);           
                display_ac_str(1);
            }break;
            
            case MODE_HEAT_PUMP://制暖
            {                                                 
                p = &t_page5_bk2_r;
                png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);             
                display_ac_str(2);
            }break;
                sysprintf("page6_ac_ctrl.sw_mode=%d-----------------------------\r\n",page6_ac_ctrl.sw_mode);
        }
        	if(upgrade==FALSE)
             {
                 p=&t_page5_1;
                 Virtual_LCD_Upgrate_formx1y1(p->x_val+5,168,p->x_end_val-p->x_val,80);
             }
    }
}

#define debuge_data_AC 0

void FlC200_hc_comm_AC_SW(u8* para) //打印同步数据 para[0]: ID, para[1]: LEN, para[2]: DATA 0
{
    FlC200_hc_comm_Hvac_pro(&para[2]);//获取同步输数据

    if(debuge_data_AC)
    {
        sysprintf("IN AC------------------------------------------ \r\n");

        u8 id  = para[0];   // 数据包ID
        u8 len = para[1];   // 数据长度
        int i;

        sysprintf("ID = 0x%02X, LEN = %d\r\n", id, len);
        sysprintf("para[0] DataType = %02X\r\n", para[0]);
        sysprintf("para[1] LEN      = %02X\r\n", para[1]);
        sysprintf("para[2] D0(hvac)       = %02X\r\n", para[2]);
        sysprintf("para[3] D1(mode)       = %02X\r\n", para[3]);
        sysprintf("para[4] D2(fan)       = %02X\r\n", para[4]);
        sysprintf("para[5] D3(h tem)       = %02X\r\n", para[5]);
        sysprintf("para[6] D4(c tem)       = %02X\r\n", para[6]);
        sysprintf("para[7] D5(auto t)       = %02X\r\n", para[7]);
        sysprintf("para[8] D6(t1)       = %02X\r\n", para[8]);
        sysprintf("para[9] D7(t2)       = %02X\r\n", para[9]);
        
        sysprintf("Is_uint_Fahrenheit=%d= %02X\r\n", Is_uint_Fahrenheit());
             


        // 打印数据区内容
        sysprintf("DATA: ");
        for (i = 0; i < len; i++)
        {
            sysprintf("%02X ", para[2 + i]);
        }
        sysprintf("\r\n--------------------------------------------------\r\n");

        // 基础校验：长度是否合理（防止死循环或越界）
        if (len == 0)
        {
            sysprintf("Warning: LEN = 0 (no data)\r\n");
            return;
        }
        if (len > 100)
        {
            sysprintf("Warning: LEN too large (%d), truncated to 100\r\n", len);
            len = 100;
        }
                 
     //   if(Is_uint_Fahrenheit()==1)//F
        sysprintf("FFFFFFFFFFFFFFFFFFFFFFF - Furnace_set_temp_f:%d, Cool_set_temp_f:%d, Auto_set_temp_f:%d, Now_temp_f:%d\r\n",
                  page6_ac_ctrl.Furnace_set_temp_f,
                  page6_ac_ctrl.Cool_set_temp_f,
                  page6_ac_ctrl.Auto_set_temp_f,
                  page6_ac_ctrl.Now_temp_f);
         		
    //    else if(Is_uint_Fahrenheit()==0)//c
		
                   // 打印摄氏度解析后的数据
        sysprintf("CCCCCCCCCCCCCCCCCCCCC  - Furnace_set_temp:%d, Cool_set_temp:%d, Auto_set_temp:%d, Now_temp:%d\r\n",
                  page6_ac_ctrl.Furnace_set_temp,
                  page6_ac_ctrl.Cool_set_temp,
                  page6_ac_ctrl.Auto_set_temp,
                  page6_ac_ctrl.Now_temp);
	         
                  
                  
        
        sysprintf("--------------------------------------------------\r\n");
    }
}
