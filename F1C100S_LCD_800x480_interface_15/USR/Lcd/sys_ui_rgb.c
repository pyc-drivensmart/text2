#include "includes.h"

void DrawColorSelectorByRGB(u8 R, u8 G, u8 B);
lcd_dis_item_t *p_home_item_RGB_u[PAGE_RGB_NUM]={
	&t_page3_bk_1,
	&t_page3_bk_2,
	&t_page3_RGB,
	&t_page3_FLASH_up,//
	&t_page3_SMOOT_up,
    &t_page3_FADE_up,
	&t_page3_STROBE_up,
    &t_page3_slider_0,
    &t_page3_key_up,//
	&t_page3_cut_up,//
	&t_page3_add_up,//
    &t_page3_RGB1_up,//
    &t_page3_RGB2_up,
};

lcd_dis_item_t *p_home_item_RGB_d[PAGE_RGB_NUM]={
	&t_page3_bk_1,
	&t_page3_bk_2,
	&t_page3_RGB,//
    &t_page3_FLASH_d,//
	&t_page3_SMOOT_d,
    &t_page3_FADE_d,
	&t_page3_STROBE_d,
    &t_page3_slider_0,
    &t_page3_key_d,
	&t_page3_cut_up,
	&t_page3_add_up,    
    &t_page3_RGB1_d,
    &t_page3_RGB2_d,
};						 
lcd_dis_item_t RGB_item[PAGE_RGB_NUM];//图片缓存区
RGBSystem now_RGB_status;   //现在状态

void ui_RGB_init(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][2]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_background_1.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_1.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=PAGE_RGB_NUM;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only

    
    t_page3_bk_1        .key_type=KEY_TYPE_TOUCH_NONE;
	t_page3_bk_2        .key_type=KEY_TYPE_TOUCH_NONE;
//	t_page3_RGB         .key_type=KEY_TYPE_TOUCH_NONE;//不进行触摸 弹起图标当背景显示 

    t_page3_cut_up.key_type = KEY_TYPE_TOUCH_KEEP;
	t_page3_add_up.key_type = KEY_TYPE_TOUCH_KEEP;//需要持续按住才有效的按键

	 t_page3_slider_0.key_type = KEY_TYPE_SLIDE;//0背景滑动
                     
	t_page3_RGB         .key_type=KEY_TYPE_TOUCH_NONE;//不进行触摸 弹起图标当背景显示 
    
    
    t_page3_Ellips.key_type=KEY_TYPE_TOUCH_NONE;//不进行触摸 弹起图标当背景显示 


	p->item = RGB_item;
	for(i=0;i<PAGE_RGB_NUM;i++)
	{
		memcpy(&(p->item[i]),p_home_item_RGB_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_RGB_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_RGB_u[i]->size_of_pic_item ;
	}
    
	RGB_item[RGB_SEL_SN].now_status=STATUS_SELECT;//RGB1
         

  //sysprintf("ui_RGB_initui_RGB_init,pwm_ctrl_RGB_byte[%d]\r\n",now_RGB_status.RGB_select);

    
}





void RGB_Status_synchronization_SW(void)//同步开关状态
{
        if(now_RGB_status.RGB_select==0)
        {
            if(now_RGB_status.RGB[0].FLASH_Flag==1)//同步开关
            RGB_item[RGB_MODE_SN].now_status=STATUS_SELECT;
            else if(now_RGB_status.RGB[0].FLASH_Flag==0)
            RGB_item[RGB_MODE_SN].now_status=STATUS_IDLE;
            
            if(now_RGB_status.RGB[0].SMOOT_Flag==1)//同步开关
            RGB_item[RGB_MODE_SN+1].now_status=STATUS_SELECT;
            else if(now_RGB_status.RGB[0].SMOOT_Flag==0)
            RGB_item[RGB_MODE_SN+1].now_status=STATUS_IDLE;      
                        
            if(now_RGB_status.RGB[0].FADE_Flag==1)//同步开关
            RGB_item[RGB_MODE_SN+2].now_status=STATUS_SELECT;
            else if(now_RGB_status.RGB[0].FADE_Flag==0)
            RGB_item[RGB_MODE_SN+2].now_status=STATUS_IDLE;   
            
            if(now_RGB_status.RGB[0].STROBE_Flag==1)//同步开关
            RGB_item[RGB_MODE_SN+3].now_status=STATUS_SELECT;
            else if(now_RGB_status.RGB[0].STROBE_Flag==0)
            RGB_item[RGB_MODE_SN+3].now_status=STATUS_IDLE;
            
        }
        else if(now_RGB_status.RGB_select==1)
        {
            if(now_RGB_status.RGB[1].FLASH_Flag==1)//同步开关
            RGB_item[RGB_MODE_SN].now_status=STATUS_SELECT;
            else if(now_RGB_status.RGB[1].FLASH_Flag==0)
            RGB_item[RGB_MODE_SN].now_status=STATUS_IDLE;
            
            if(now_RGB_status.RGB[1].SMOOT_Flag==1)//同步开关
            RGB_item[RGB_MODE_SN+1].now_status=STATUS_SELECT;
            else if(now_RGB_status.RGB[1].SMOOT_Flag==0)
            RGB_item[RGB_MODE_SN+1].now_status=STATUS_IDLE;      
                        
            if(now_RGB_status.RGB[1].FADE_Flag==1)//同步开关
            RGB_item[RGB_MODE_SN+2].now_status=STATUS_SELECT; 
            else if(now_RGB_status.RGB[1].FADE_Flag==0)
            RGB_item[RGB_MODE_SN+2].now_status=STATUS_IDLE;   
            
            if(now_RGB_status.RGB[1].STROBE_Flag==1)//同步开关
            RGB_item[RGB_MODE_SN+3].now_status=STATUS_SELECT;
            else if(now_RGB_status.RGB[1].STROBE_Flag==0)
            RGB_item[RGB_MODE_SN+3].now_status=STATUS_IDLE;
        }

}


extern u8 pwm_ctrl_RGB_byte[2];//默认10占空比,操作RGB亮度
extern bool RGB_touch_Flag;//RGB界面打印RGB坐标标志位

#define debuge_data_RGB 0
void FlC200_hc_comm_RGB_SW(u8* para) //获取同步数据 para[0]: ID, para[1]: LEN, para[2]: DATA 0
{
    now_RGB_status.RGB[para[2]-1].isPowerOn=(bool)(para[3]&(0x01<<7));//D1 bit7//RGB开关
        pwm_ctrl_RGB_byte[para[2]-1] = (para[4] * 100) / 255; //pwm百分比

        switch(para[8])//获取灯效数据
    { 
        case 0x00:
        {
            now_RGB_status.RGB[para[2]-1].FLASH_Flag  =0;
            now_RGB_status.RGB[para[2]-1].SMOOT_Flag  =0;
            now_RGB_status.RGB[para[2]-1].FADE_Flag  =0;
            now_RGB_status.RGB[para[2]-1].STROBE_Flag=0;
        }break;  
        case 0x01:
        {
            now_RGB_status.RGB[para[2]-1].FLASH_Flag  =1;
            now_RGB_status.RGB[para[2]-1].SMOOT_Flag  =0;
            now_RGB_status.RGB[para[2]-1].FADE_Flag  =0;
            now_RGB_status.RGB[para[2]-1].STROBE_Flag=0;
        }break; 
        
        case 0x02:
        {
            now_RGB_status.RGB[para[2]-1].FLASH_Flag  =0;
            now_RGB_status.RGB[para[2]-1].SMOOT_Flag  =1;
            now_RGB_status.RGB[para[2]-1].FADE_Flag  =0;
            now_RGB_status.RGB[para[2]-1].STROBE_Flag=0;
        }break;        
        case 0x03:
        {
            now_RGB_status.RGB[para[2]-1].FLASH_Flag  =0;
            now_RGB_status.RGB[para[2]-1].SMOOT_Flag  =0;
            now_RGB_status.RGB[para[2]-1].FADE_Flag  =1;
            now_RGB_status.RGB[para[2]-1].STROBE_Flag=0;
        }break;
         case 0x04:
        {
            now_RGB_status.RGB[para[2]-1].FLASH_Flag  =0;
            now_RGB_status.RGB[para[2]-1].SMOOT_Flag  =0;
            now_RGB_status.RGB[para[2]-1].FADE_Flag  =0;
            now_RGB_status.RGB[para[2]-1].STROBE_Flag=1;
        }break; 
    }
    
    now_RGB_status.RGB[para[2]-1].r=para[5];
    now_RGB_status.RGB[para[2]-1].g=para[6];
    now_RGB_status.RGB[para[2]-1].b=para[7];    
	  lcd_dis_page_t * p2 = &page_home.page_top_side[page_home.page_left_side.now_item];	

    // 仅在触摸标志有效时执行
    if(page_home.page_top_side[page_home.page_left_side.now_item].now_item==2)
      {
          if(now_RGB_status.RGB_select==0){if(para[2]==0x01)//0,1
          DrawColorSelectorByRGB(now_RGB_status.RGB[0].r,now_RGB_status.RGB[0].g,now_RGB_status.RGB[0].b);
          }//反馈绘制小圆
          else if(now_RGB_status.RGB_select==1){if(para[2]==0x02)//0,1
          DrawColorSelectorByRGB(now_RGB_status.RGB[1].r,now_RGB_status.RGB[1].g,now_RGB_status.RGB[1].b);}//反馈绘制小圆
      }
    
    if(debuge_data_RGB)
    {
    sysprintf("IN  RGB------------------------------------------ \r\n");

    u8 id  = para[0];   // 数据包ID
    u8 len = para[1];   // 数据长度
    int i;

    sysprintf("ID = 0x%02X, LEN = %d\r\n", id, len);
    sysprintf("para[0] DataType = %02X\r\n", para[0]);
    sysprintf("para[1] LEN      = %02X\r\n", para[1]);
    sysprintf("para[2] D0:RGB   = %02X\r\n", para[2]);
    sysprintf("para[3] D1:      = %02X\r\n", para[3]);
    sysprintf("para[4] D2   pwm= %02X\r\n", para[4]);
    sysprintf("para[5] D3  R     = %02X\r\n", para[5]);
    sysprintf("para[6] D4  G     = %02X\r\n", para[6]);
    sysprintf("para[7] D5  B     = %02X\r\n", para[7]);
    sysprintf("para[8] D6  Mode  = %02X\r\n", para[8]);
    sysprintf("para[9] D7       = %02X\r\n", para[9]);
    sysprintf("para[10] D8       = %02X\r\n", para[10]);
    sysprintf("para[11] D9       = %02X\r\n", para[11]);
    sysprintf("para[12] D10       = %02X\r\n", para[12]);
                 
    sysprintf("para[4] D2 %d  pwm= %d\r\n", para[4]);

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
    
    sysprintf("nowRGB[0].FLASH_Flag= %d\r\n",now_RGB_status.RGB[0].FLASH_Flag );
    // 打印 SMOOT_Flag
    sysprintf("nowRGB[0].SMOOT_Flag= %d\r\n", 
              now_RGB_status.RGB[0].SMOOT_Flag);
    // 打印 FADE_Flag
    sysprintf("nowRGB[0].FADE_Flag= %d\r\n", 
              now_RGB_status.RGB[0].FADE_Flag);
    // 打印 STROBE_Flag
    sysprintf("nowRGB[0].STROBE_Flag= %d\r\n", 
              now_RGB_status.RGB[0].STROBE_Flag);

        sysprintf("nowRGB[0].FLASH_Flag= %d\r\n",
        now_RGB_status.RGB[1].FLASH_Flag );
    // 打印 SMOOT_Flag
    sysprintf("nowRGB[0].SMOOT_Flag= %d\r\n", 
              now_RGB_status.RGB[1].SMOOT_Flag);
    // 打印 FADE_Flag
    sysprintf("nowRGB[0].FADE_Flag= %d\r\n", 
              now_RGB_status.RGB[1].FADE_Flag);
    // 打印 STROBE_Flag
    sysprintf("nowRGB[0].STROBE_Flag= %d\r\n", 
              now_RGB_status.RGB[1].STROBE_Flag);


        // 打印 isPowerOn
        sysprintf("nowRGB[%d].isPowerOn= %d\r\n", 
                  now_RGB_status.RGB_select, 
                  now_RGB_status.RGB[now_RGB_status.RGB_select].isPowerOn);

        // 打印 brightness
        sysprintf("nowRGB[%d].brightness= %d\r\n",  // 这里将 isPowerOn 改为 brightness
                  now_RGB_status.RGB_select, 
                  now_RGB_status.RGB[now_RGB_status.RGB_select].brightness);

    sysprintf("--------------------------------------------------\r\n");
    }
}


//====================================================================
// 函数名称：key_state_RGB
// 功能说明：根据当前 RGB 选择状态（RGB_select），在 LCD 上显示灯编号与开关状态。
// 参数说明：p - LCD 显示控件指针（此处未直接使用，但可为扩展预留）
// 全局变量：now_RGB_status - 当前 RGB 系统状态
//====================================================================
void key_state_RGB(lcd_dis_item_t *p)
{
    char display_buf[32];
    u8 sel = now_RGB_status.RGB_select;
    //=============================
    // 判断并显示灯开关状态
    //=============================
    if (now_RGB_status.RGB[sel].isPowerOn)
    {
       RGB_item[RGB_POWER_SN].now_status=STATUS_SELECT;
    }
    else
    {
       RGB_item[RGB_POWER_SN].now_status=STATUS_IDLE;
    }
}





int valid_center_x;
int valid_center_y;
const int big_center_x = 155;    // 大圆中心X
const int big_center_y = 275;    // 大圆中心Y
const int big_radius = 91;       // 大圆半径
const int small_dia = 32;        // 小圆直径
const int small_radius = small_dia / 2; // 小圆半径

void disply_RGB_val(bool upgrade)
{
    
	static RGBSystem old_RGB_status;   
	char display_buf[32];
	lcd_dis_item_t *p;
    
	if((memcmp(&now_RGB_status,&old_RGB_status,sizeof(RGBSystem)))||upgrade)//判断是否状态更新
	{
    memcpy(&old_RGB_status,&now_RGB_status,sizeof(RGBSystem));//更新状态
        RGB_Status_synchronization_SW();//同步模式状态
        p=&t_page3_bk_1;
		//清空字符
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
        p=&t_page3_bk_2;
		//清空字符
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
        key_state_RGB(p);//显示RGB灯编号，开关
            sprintf(display_buf, "DIMMER");
            // 显示到 LCD 指定位置
            Virtual_LCD_Draw_String_ARGB_16_4bit(322, 229, display_buf, (ARGB_darkGray), 0, 1, 1);
        if(upgrade==FALSE){
         p=&t_page3_bk_1;
         	Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
         p=&t_page3_bk_2;
         	Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);
                }

    }
}






#include <math.h>       // 用于 sqrtf、atan2f、fabsf、fmodf
#include <stdio.h>      // 用于 sysprintf（或 printf）
#include "GT911.h"      // 假设这里定义了 g_GT911 结构体
extern bool RGB_touch_Flag;//RGB界面打印RGB坐标标志位
#ifndef M_PI
#define M_PI 3.1415926535f  // 定义π常量
#endif

u8 R = 0, G = 0, B = 0;  // 最终 RGB 值初始化为 0
extern void ALL_Init(bool rgb);
// 触摸取色函数：根据触摸坐标计算 RGB 值
void HandleColorTouch(void)
{
    char display_buf[32];
    lcd_dis_page_t *p2 = &page_home.page_top_side[page_home.page_left_side.now_item];

    if (page_home.page_top_side[page_home.page_left_side.now_item].now_item == 2)
    {
        if ((g_GT911.X1 >= 64 && g_GT911.X1 <= 246) &&
            (g_GT911.Y1 >= 184 && g_GT911.Y1 <= 366))
        {
            if (now_RGB_status.RGB_select == 0)
            {
            ALL_Init(0);//关闭灯效
            send_FlC200_set_cmd_new(0xB4,0x00,0x01);//：控制器1
            }
            else
            {
            ALL_Init(1);//关闭灯效
            send_FlC200_set_cmd_new(0xB4,0x00,0x02);//：控制器2
            }
            

            // === 1. 坐标转换（不翻转 Y 轴）===
            int x_rel = g_GT911.X1 - 155;     // 中心 X=155
            int y_rel = g_GT911.Y1 - 275;     // 中心 Y=275（关键：改回 +Y 向下）

            // === 2. 判断是否在色盘内 ===
            int distance_sq = x_rel * x_rel + y_rel * y_rel;
            const int radius = 91;
            if (distance_sq <= radius * radius)
            {
                float r = sqrtf((float)distance_sq);

                // === 3. 计算角度（atan2f 现在方向正常）===
                float theta_rad = atan2f((float)y_rel, (float)x_rel);
                float theta_deg = theta_rad * 180.0f / M_PI;
                if (theta_deg < 0) theta_deg += 360.0f;

                // === 4. HSV ===
                float H = theta_deg;
                float S = r / (float)radius;
                float V = 1.0f;

                // === 5. HSV → RGB ===
                float C = V * S;
                float X = C * (1 - fabsf(fmodf(H / 60.0f, 2) - 1));
                float m = V - C;
                float Rf = 0, Gf = 0, Bf = 0;

                if (H < 60)       { Rf = C; Gf = X; Bf = 0; }
                else if (H < 120) { Rf = X; Gf = C; Bf = 0; }
                else if (H < 180) { Rf = 0; Gf = C; Bf = X; }
                else if (H < 240) { Rf = 0; Gf = X; Bf = C; }
                else if (H < 300) { Rf = X; Gf = 0; Bf = C; }
                else              { Rf = C; Gf = 0; Bf = X; }

                R = (int)((Rf + m) * 255);
                G = (int)((Gf + m) * 255);
                B = (int)((Bf + m) * 255);

                // === 小圆位置修正（无 Y 翻转）===
                int touch_rel_x = g_GT911.X1 - big_center_x;
                int touch_rel_y = g_GT911.Y1 - big_center_y; // 关键：不翻转
                float distance = sqrtf((float)(touch_rel_x * touch_rel_x + touch_rel_y * touch_rel_y));
                valid_center_x = g_GT911.X1;
                valid_center_y = g_GT911.Y1;

                if (distance + small_radius > big_radius)
                {
                    float scale = (float)(big_radius - small_radius) / distance;
                    int corrected_rel_x = (int)(touch_rel_x * scale);
                    int corrected_rel_y = (int)(touch_rel_y * scale);
                    // 关键：不翻转回去，直接使用正常坐标
                    valid_center_x = big_center_x + corrected_rel_x;
                    valid_center_y = big_center_y + corrected_rel_y;
                }

                // 绘制色盘和小圆
                lcd_dis_item_t *p;
                p = &t_page3_RGB;
                png_dis_xy(p->x_val, p->y_val, p->pic_item, p->size_of_pic_item, Virtual_LCDbuff1);
                p = &t_page3_Ellips;
                png_dis_xy(valid_center_x - small_radius, valid_center_y - small_radius,
                p->pic_item, p->size_of_pic_item, Virtual_LCDbuff1);
                Virtual_LCD_Upgrate();
            }

            // 保存 RGB
            if (now_RGB_status.RGB_select == 0)
            {
                now_RGB_status.RGB[0].r = R;
                now_RGB_status.RGB[0].g = G;
                now_RGB_status.RGB[0].b = B;
                send_FlC200_set_cmd_new(0xB2, R << 8 | G, 0x01);
                send_FlC200_set_cmd_new(0xB3, B, 0x01);
            }
            else
            {
                now_RGB_status.RGB[1].r = R;
                now_RGB_status.RGB[1].g = G;
                now_RGB_status.RGB[1].b = B;
                send_FlC200_set_cmd_new(0xB2, R << 8 | G, 0x02);
                send_FlC200_set_cmd_new(0xB3, B, 0x02);
            }
        }
    }
}
void DrawColorSelectorByRGB(u8 R, u8 G, u8 B)
{
    if (!touch_up) return;
    float r_f = R / 255.0f;
    float g_f = G / 255.0f;
    float b_f = B / 255.0f;

    float maxv = fmaxf(r_f, fmaxf(g_f, b_f));
    float minv = fminf(r_f, fminf(g_f, b_f));
    float delta = maxv - minv;

    float H = 0, S = 0, V = maxv;
    if (maxv > 0.0001f) S = delta / maxv;
    if (delta < 0.0001f) H = 0;
    else {
        if (maxv == r_f) H = 60.0f * fmodf((g_f - b_f) / delta, 6.0f);
        else if (maxv == g_f) H = 60.0f * (((b_f - r_f) / delta) + 2.0f);
        else H = 60.0f * (((r_f - g_f) / delta) + 4.0f);
        if (H < 0) H += 360.0f;
    }

    const int big_center_x = 155;
    const int big_center_y = 275;
    const int big_radius   = 91;
    const int small_radius = 16;

    float r_xy = S * big_radius;
    float theta = H * M_PI / 180.0f;

    float dx = r_xy * cosf(theta);
    float dy = r_xy * sinf(theta);

    int target_x = big_center_x + (int)(dx);
    int target_y = big_center_y + (int)(dy);   // 不翻转 Y

    float dist = sqrtf(dx*dx + dy*dy);
    if (dist + small_radius > big_radius)
    {
        float scale = (float)(big_radius - small_radius) / dist;
        dx *= scale;
        dy *= scale;

        target_x = big_center_x + (int)(dx);
        target_y = big_center_y + (int)(dy);   //  同样不翻转
    }

    lcd_dis_item_t *p;
    p = &t_page3_RGB;
    png_dis_xy(p->x_val, p->y_val, p->pic_item, p->size_of_pic_item, Virtual_LCDbuff1);
    p = &t_page3_Ellips;
    png_dis_xy(target_x - small_radius, target_y - small_radius,
               p->pic_item, p->size_of_pic_item, Virtual_LCDbuff1);
    Virtual_LCD_Upgrate();
}






