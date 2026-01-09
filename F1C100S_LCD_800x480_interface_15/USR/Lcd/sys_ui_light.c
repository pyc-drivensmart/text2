#include "includes.h"



#define Light_PAGE_ITEM_NUM  18+6

lcd_dis_item_t *p_home_item_5_chun_u3[Light_PAGE_ITEM_NUM]={
	&t_page1_light_bk        ,
	&t_page1_light_bk2        ,
	&t_page1_light_bk3        ,
	&t_page1_light_bk4        ,
	&t_page1_light_bk5        ,
	&t_page1_light_bk6        ,


    
    &t_page11_light_off    ,
    &t_page11_light_off2  ,
    &t_page11_light_off3  ,
    &t_page11_light_off4  ,
    &t_page11_light_off5  ,
    &t_page11_light_off6  ,
    

        &t_page1_light_slider_0_1,
        &t_page1_light_slider_0_2,
        &t_page1_light_slider_0_3,
        &t_page1_light_slider_0_4,
        &t_page1_light_slider_0_5,
        &t_page1_light_slider_0_6,

        &t_page1_Ellipse_1  ,
        &t_page1_Ellipse_2  ,
        &t_page1_Ellipse_3  ,
        &t_page1_Ellipse_4  ,
        &t_page1_Ellipse_5  ,
        &t_page1_Ellipse_6  ,



};

lcd_dis_item_t *p_home_item_5_chun_d3[Light_PAGE_ITEM_NUM]={
	&t_page1_light_bk        ,
	&t_page1_light_bk2        ,
	&t_page1_light_bk3        ,
	&t_page1_light_bk4        ,
	&t_page1_light_bk5        ,
	&t_page1_light_bk6        ,
    

    
    
    &t_page11_light_on    ,
    &t_page11_light_on2  ,
    &t_page11_light_on3  ,
    &t_page11_light_on4  ,
    &t_page11_light_on5  ,
    &t_page11_light_on6  ,
    
        &t_page1_light_slider_0_1,
        &t_page1_light_slider_0_2,
        &t_page1_light_slider_0_3,
        &t_page1_light_slider_0_4,
        &t_page1_light_slider_0_5,
        &t_page1_light_slider_0_6,
    
        &t_page1_Ellipse_1  ,
        &t_page1_Ellipse_2  ,
        &t_page1_Ellipse_3  ,
        &t_page1_Ellipse_4  ,
        &t_page1_Ellipse_5  ,
        &t_page1_Ellipse_6  ,


};						 
lcd_dis_item_t light_item[Light_PAGE_ITEM_NUM];//图片缓存区？？



bool change_light_val;

LightSystem light_now_sta;//现在状态
void disply_ligght_val2(bool upgrade)//打印字符
{
	static LightSystem old_light_status;   
//	char display_buf[32];
    	char display_buf[50];
	lcd_dis_item_t *p;
    lcd_dis_item_t *p2;

	if((memcmp(&light_now_sta,&old_light_status,sizeof(LightSystem)))||upgrade)//判断是否状态更新
	{
    memcpy(&old_light_status,&light_now_sta,sizeof(LightSystem));//更新状态
        

        
           p=&t_page1_light_bk;
		//清空字符
        p2=&t_page1_light_bk6;
		//清空字符
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p2->x_end_val-p->x_val,p2->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
                    
                    Virtual_LCD_Draw_String_ARGB_24_4bit(118, 114, "Ceiling", (ARGB_white), 0, 1, 1);
//                   if(light_now_sta.lights[0].isPowerOn==0)
//                    Virtual_LCD_Draw_String_ARGB_24_4bit(118, 114+24+10, "off", (ARGB_white), 0, 1, 1);
//                     else if(light_now_sta.lights[0].isPowerOn==1)
//                     {
                    snprintf(display_buf, sizeof(display_buf), "%d%%", light_now_sta.lights[0].brightness);
                    Virtual_LCD_Draw_String_ARGB_24_4bit(118, 114+24+10, display_buf, (ARGB_white), 0, 1, 1);
//                     }

                    Virtual_LCD_Draw_String_ARGB_24_4bit(357, 114, "Floor", (ARGB_white), 0, 1, 1);
//                    if(light_now_sta.lights[1].isPowerOn==0)
//                    Virtual_LCD_Draw_String_ARGB_24_4bit(357, 114+24+10, "off", (ARGB_white), 0, 1, 1);
//                    else if(light_now_sta.lights[1].isPowerOn==1)
//                        {
                    snprintf(display_buf, sizeof(display_buf), "%d%%", light_now_sta.lights[1].brightness);
                    Virtual_LCD_Draw_String_ARGB_24_4bit(357, 114+24+10, display_buf, (ARGB_white), 0, 1, 1);      
//                        }
//                   
                    Virtual_LCD_Draw_String_ARGB_24_4bit(633, 114, "Reading", (ARGB_white), 0, 1, 1);                    
//                     if(light_now_sta.lights[2].isPowerOn==0)
//                    Virtual_LCD_Draw_String_ARGB_24_4bit(633, 114+24+10, "off", (ARGB_white), 0, 1, 1);
//                    else if(light_now_sta.lights[2].isPowerOn==1)
//                    {
                    snprintf(display_buf, sizeof(display_buf), "%d%%", light_now_sta.lights[2].brightness);
                    Virtual_LCD_Draw_String_ARGB_24_4bit(633, 114+24+10, display_buf, (ARGB_white), 0, 1, 1);                     
//                    
//                    }

                    Virtual_LCD_Draw_String_ARGB_24_4bit(118, 272, "Starlight", (ARGB_white), 0, 1, 1);
                    
//                        if(light_now_sta.lights[3].isPowerOn==0)
//                    Virtual_LCD_Draw_String_ARGB_24_4bit(118, 272+24+10, "off", (ARGB_white), 0, 1, 1);
//                    else if(light_now_sta.lights[3].isPowerOn==1){
                    snprintf(display_buf, sizeof(display_buf), "%d%%", light_now_sta.lights[3].brightness);
                    Virtual_LCD_Draw_String_ARGB_24_4bit(118, 272+24+10, display_buf, (ARGB_white), 0, 1, 1);                   
//                    }
                    

                    Virtual_LCD_Draw_String_ARGB_24_4bit(357, 272, "Center Ceiling", (ARGB_white), 0, 1, 1);
//                    if(light_now_sta.lights[4].isPowerOn==0)
//                    Virtual_LCD_Draw_String_ARGB_24_4bit(357, 272+24+10, "off", (ARGB_white), 0, 1, 1);
//                    else if(light_now_sta.lights[4].isPowerOn==1){
                    snprintf(display_buf, sizeof(display_buf), "%d%%", light_now_sta.lights[4].brightness);
                    Virtual_LCD_Draw_String_ARGB_24_4bit(357, 272+24+10, display_buf, (ARGB_white), 0, 1, 1);                   
//                    }
                   
                    Virtual_LCD_Draw_String_ARGB_24_4bit(633, 272, "Accessory", (ARGB_white), 0, 1, 1);                    
//                    if(light_now_sta.lights[5].isPowerOn==0)
//                    Virtual_LCD_Draw_String_ARGB_24_4bit(633, 272+24+10, "off", (ARGB_white), 0, 1, 1);
//                    else if(light_now_sta.lights[5].isPowerOn==1){
                    snprintf(display_buf, sizeof(display_buf), "%d%%", light_now_sta.lights[5].brightness);
                    Virtual_LCD_Draw_String_ARGB_24_4bit(633, 272+24+10, display_buf, (ARGB_white), 0, 1, 1);                   
//                    }

                    
                   
        		
                    if(upgrade==FALSE)
                        {
//                            // 刷新第1组（ceiling）背景区域
//                            p=&t_page1_light_bk;
//                            Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
//                            // 刷新第2组（Floor）背景区域
//                            p=&t_page1_light_bk2;
//                            Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
//                            // 刷新第3组（Reading）背景区域
//                            p=&t_page1_light_bk3;
//                            Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
//                            // 刷新第4组（Starlight）背景区域
//                            p=&t_page1_light_bk4;
//                            Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
//                            // 刷新第5组（Center Ceiling）背景区域
//                            p=&t_page1_light_bk5;
//                            Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
//                            // 刷新第6组（Accessory）背景区域
//                            p=&t_page1_light_bk6;
//                            Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
                            
                            p=&t_page1_light_bk;
                            //清空字符
                            p2=&t_page1_light_bk6;
                            //清空字符
                            Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p2->x_end_val-p->x_val,p2->y_end_val-p->y_val);

                                                
                        }
                    
//                
//			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);

    }
}



extern u8 pwm_p1_light_ctrl_byte[P1_Light_PWM_CTRL_CH];//
#define debuge_data_light 0
void FlC200_hc_comm_light_SW(u8* para) //获取同步数据 ,同步互动条
{   
    lcd_dis_item_t *p;
    if(debuge_data_light)
    {
        sysprintf("IN Light Page data------------------------------------------- \r\n");

        u8 id  = para[0];   // 数据包ID
        u8 len = para[1];   // 数据长度
        int i;

        sysprintf("ID = 0x%02X, LEN = %d\r\n", id, len);
        sysprintf("para[0] DataType = %02X\r\n", para[0]);
        sysprintf("para[1] LEN      = %02X\r\n", para[1]);
        sysprintf("para[2] D0       = %02X\r\n", para[2]);
        sysprintf("para[3] D1       = %02X\r\n", para[3]);
        sysprintf("Light Byte(D0)   = %02X\r\n", para[2]);

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
            
        // （可选）全灯状态位 bit1，可用于同步所有灯状态
        if (para[3] & (0x01 << 0))
        {
            if(debuge_data_light)  sysprintf("All Lights flag = ON (bit1 = 1)\r\n");
        }
        else
        {
            if(debuge_data_light)    sysprintf("All Lights flag = OFF (bit1 = 0)\r\n");
        }
    
    }
    //-------------------------------------------------------------
    // 功能：解析 para[2] 中灯1~灯4 的开关状态
    // 位定义（para[2]）:
    //   bit7 → light1
    //   bit6 → light2
    //   bit5 → light3
    //   bit4 → light4
    // 位为1表示对应灯处于 ON 状态，位为0表示 OFF
    //-------------------------------------------------------------


   
    // light1
    if (para[2] & (0x01 << 7))
    {
        light_now_sta.lights[0].isPowerOn = 1;
         
    if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
    {        
        p = &t_page11_light_on;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
    }
       if(debuge_data_light)   sysprintf("light1 receive status : ON\r\n");
    }
    else
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
        p = &t_page11_light_off;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        
        light_now_sta.lights[0].isPowerOn = 0;
       if(debuge_data_light)   sysprintf("light1 receive status : OFF\r\n");
    }

    // light2
    if (para[2] & (0x01 << 6))
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
        p = &t_page11_light_on2;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[1].isPowerOn = 1;
       if(debuge_data_light)   sysprintf("light2 receive status : ON\r\n");
    }
    else
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_off2;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[1].isPowerOn = 0;
       if(debuge_data_light)   sysprintf("light2 receive status : OFF\r\n");
    }

    // light3
    if (para[2] & (0x01 << 5))
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_on3;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[2].isPowerOn = 1;
        if(debuge_data_light)  sysprintf("light3 receive status : ON\r\n");
    }
    else
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_off3;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[2].isPowerOn = 0;
       if(debuge_data_light)   sysprintf("light3 receive status : OFF\r\n");
    }

    // light4
    if (para[2] & (0x01 << 4))
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_on4;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[3].isPowerOn = 1;
       if(debuge_data_light)   sysprintf("light4 receive status : ON\r\n");
    }
    else
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_off4;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[3].isPowerOn = 0;
        if(debuge_data_light)  sysprintf("light4 receive status : OFF\r\n");
    }

    //-------------------------------------------------------------
    // 功能：解析 para[3] 中灯5~灯6 的开关状态
    // 位定义（para[3]）:
    //   bit3 → light5
    //   bit2 → light6
    //   bit1 → allLight（全灯控制位，可选）
    //-------------------------------------------------------------

    // light5
    if (para[3] & (0x01 << 6))
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_on5;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[4].isPowerOn = 1;
       if(debuge_data_light)   sysprintf("light5 receive status : ON\r\n");
    }
    else
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_off5;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[4].isPowerOn = 0;
        if(debuge_data_light)  sysprintf("light5 receive status : OFF\r\n");
    }

    // light6
    if (para[3] & (0x01 << 5))
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_on6;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[5].isPowerOn = 1;
        if(debuge_data_light)  sysprintf("light6 receive status : ON\r\n");
    }
    else
    {
            if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==0)
            {
                p = &t_page11_light_off6;
        png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);               // Virtual_LCD_Upgrate();	
            }
        light_now_sta.lights[5].isPowerOn = 0;
         if(debuge_data_light) sysprintf("light6 receive status : OFF\r\n");
    }


    //PWM D5~D10=para[7~]
    for(int i=0;i<6;i++)
    {
        pwm_p1_light_ctrl_byte[i]=para[7+i];				//更新滑动条同步状态
       light_now_sta.lights[i].brightness=para[7+i];
       if(debuge_data_light)   sysprintf("light[%d] receive PWM : %d\r\n",i,pwm_ctrl_byte[i]);

    }
    
    sysprintf("--------------------------------------------------\r\n");
}

void Light_Status_synchronization_SW(bool upgrade)//同步状态
{
	static LightSystem old_light_status;   

	if((memcmp(&light_now_sta,&old_light_status,sizeof(LightSystem)))||upgrade)//判断是否状态更新
	{
        memcpy(&old_light_status,&light_now_sta,sizeof(LightSystem));//更新状态    
        for(int i=0;i<6;i++)
        {
            if(light_now_sta.lights[i].isPowerOn==1)//同步开关
            { 
            light_item[Light_Pic_SN+i].now_status=STATUS_SELECT;
            light_item[Light_Pic_SN+i].last_status=STATUS_SELECT;
            }
            else 
            {
            light_item[Light_Pic_SN+i].now_status=STATUS_IDLE;
            light_item[Light_Pic_SN+i].last_status=STATUS_IDLE;
            }
        }

    }

}



void ui_light_init(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][0]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_background_1.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_1.size_of_pic_item;// backgroud pic size


	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=Light_PAGE_ITEM_NUM;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
 
    
    t_page1_light_bk.key_type=KEY_TYPE_TOUCH_NONE;//不进行触摸 弹起图标当背景显示 
    t_page1_light_bk2.key_type=KEY_TYPE_TOUCH_NONE;
    t_page1_light_bk3.key_type=KEY_TYPE_TOUCH_NONE;
    t_page1_light_bk4.key_type=KEY_TYPE_TOUCH_NONE;
    t_page1_light_bk5.key_type=KEY_TYPE_TOUCH_NONE;
    t_page1_light_bk6.key_type=KEY_TYPE_TOUCH_NONE;
        
    
        t_page1_light_slider_0_1.key_type = KEY_TYPE_SLIDE;//0背景滑动
        t_page1_light_slider_0_2.key_type = KEY_TYPE_SLIDE;//0背景滑动
        t_page1_light_slider_0_3.key_type = KEY_TYPE_SLIDE;//0背景滑动
        t_page1_light_slider_0_4.key_type = KEY_TYPE_SLIDE;//0背景滑动
        t_page1_light_slider_0_5.key_type = KEY_TYPE_SLIDE;//0背景滑动
        t_page1_light_slider_0_6.key_type = KEY_TYPE_SLIDE;//0背景滑动
    
    
   	p->item = light_item;
	for(i=0;i<Light_PAGE_ITEM_NUM;i++)
	{
		memcpy(&(p->item[i]),p_home_item_5_chun_d3[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_5_chun_u3[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_5_chun_u3[i]->size_of_pic_item ;
	}
    
}

