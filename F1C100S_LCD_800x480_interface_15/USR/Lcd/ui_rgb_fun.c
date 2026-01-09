#include "includes.h"

//page3
u8 old_pwm_ctrl_RGB_byte[2]={10};//默认100占空比
u8 pwm_ctrl_RGB_byte[2]={10} ;//默认10占空比,操作RGB亮度


extern RGBSystem now_RGB_status;   //现在状态

void ALL_Init(bool rgb)
{
    // 初始化 RGB[1] 的所有标志位为 0
    now_RGB_status.RGB[rgb].FLASH_Flag  = 0;
    now_RGB_status.RGB[rgb].SMOOT_Flag  = 0;
    now_RGB_status.RGB[rgb].FADE_Flag   = 0;
    now_RGB_status.RGB[rgb].STROBE_Flag = 0;
}

extern lcd_dis_item_t RGB_item[PAGE_RGB_NUM];//图片缓存区

void set_RGB_icon(u8 sn)//互斥处理图片
{
	  u8 i;
    for(i=0;i<2;i++)//选项数
		{
		  if((i+RGB_SEL_SN)!=sn)//超出索引（互斥图片开始索引）
			{
			  RGB_item[i+RGB_SEL_SN].now_status = STATUS_IDLE;
				RGB_item[i+RGB_SEL_SN].key_type = KEY_TYPE_NORMAL;
			}
			else
			{
			   RGB_item[i+RGB_SEL_SN].key_type = KEY_TYPE_TOUCH_NONE;// //不进行触摸 弹起图标当背景显示 
			
			}
		}
}

void func_text_rgb(void* p,u8 sn)
{

}

extern void DrawColorSelectorByRGB(u8 R, u8 G, u8 B);

void func_page3_RGB1_d(void* p,u8 sn)
{
    u8 SN = sn;//图标在当前页面列表的序号
    lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
        set_RGB_icon(sn);
        now_RGB_status.RGB_select=0;//
        disply_pwm_RGB_status(0,TRUE);
             sysprintf("RGB1\n");
       DrawColorSelectorByRGB(now_RGB_status.RGB[0].r,now_RGB_status.RGB[0].g,now_RGB_status.RGB[0].b);//反馈绘制小圆
    }
}


void func_page3_RGB2_d(void* p,u8 sn)
{
    u8 SN = sn;//图标在当前页面列表的序号
    lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
        set_RGB_icon(sn);
        now_RGB_status.RGB_select=1;//现在选中的RGB
        disply_pwm_RGB_status(1,TRUE);
             sysprintf("RGB2\n");
      DrawColorSelectorByRGB(now_RGB_status.RGB[1].r,now_RGB_status.RGB[1].g,now_RGB_status.RGB[1].b);//反馈绘制小圆

    }
}



void func_page3_RGB1_up(void* p,u8 sn)
{

}

void func_page3_RGB2_up(void* p,u8 sn)
{

}

void disply_pwm_RGB_status(u8 type,bool upgrage)//显示滑动条
{
  static u8 old_pwm_ctrl_RGB_byte[2]={0};
  lcd_dis_item_t *p,*p2,*p3,*p4;    
  u16 offet = 0;
  u8 val_temp =0;
  u8 ch;
  char display_buf[16];

  p=&t_page3_slider_0;//0背景
  p2 = &t_page3_slider_100ALL;//满进度
  p3 = &t_Ellipse_w;//滑块2
  p4=&t_page3_slider_0_2;//0背景残影遮罩

  val_temp = pwm_ctrl_RGB_byte[type];
    // 最小值锁定到 5%
    if(val_temp < 5)
        val_temp = 5;
  if((val_temp!=old_pwm_ctrl_RGB_byte[type])||(upgrage))
  {
    old_pwm_ctrl_RGB_byte[type] = val_temp;
                 
    png_dis_xy(p4->x_val,p4->y_val,p4->pic_item,p4->size_of_pic_item,Virtual_LCDbuff1);//残影遮罩（所有分支都执行，包括0值）

    // 统一逻辑：val_temp=0时也走进度条裁剪逻辑，仅offet=0
    if(val_temp <=5)
    {
      offet = 5; // 0值时offet=0，进度条裁剪为0宽度
      // 绘制0进度背景（可选，若裁剪逻辑已能覆盖）
      png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
    }
    else if(val_temp>=98)
    {
      offet = 100*294/100-5;//205滑块长（190）
    }
    else if((val_temp>5)&&(val_temp<=97))
    {
      offet = val_temp*294/100+5;//205滑块长（190）
    }

    // 统一的进度条裁剪绘制逻辑（包括val_temp=0）
    if(val_temp >= 5) // 所有情况都执行，0值时offet=0，进度条无显示
    {
      png_dis_xy_form_x1y1_to_x2y2(
          p2->x_val,                   
          p2->y_val,                   
          p2->pic_item,                
          p2->size_of_pic_item,        
          0,                           
          0,                           
          offet,                        // 0值时offet=0，裁剪为0宽度，无进度条
          p2->y_end_val - p2->y_val,   
          0,                           
          0,                           
          Virtual_LCDbuff1             
      );

      // 统一的滑块绘制逻辑，0值时滑块固定在起始位置
      u16 slider_x = p3->x_val + offet - 16;
      // 滑块坐标保护：避免负数，0值时slider_x = p3->x_val（进度条原点）
      if(slider_x < p3->x_val) slider_x = p3->x_val;
      png_dis_xy(slider_x, p3->y_val, p3->pic_item, p3->size_of_pic_item,Virtual_LCDbuff1);
    }

    if(upgrage==FALSE)
    {
      Virtual_LCD_Upgrate_formx1y1(p4->x_val,p4->y_val,p4->x_end_val-p4->x_val,p4->y_end_val-p4->y_val);
    }
  }
}


void func_Ellipse_w(void* p,u8 sn)
{

}


u8 RGB_PWM;

void func_RGB_scrollbar_bg_all(void* p,u8 sn,u32 X_val_bg,u8 ch)//根据x坐标 ,滑动条回调函数调用，计算占空比
{	
	//u8 SN = sn;//图标在当前页面列表的序号
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    //38：滑块宽度，298:滑动背景宽度
    //ch：通道
   //X_val_bg：空进度坐标x，ch：通道，
//	if(slide_x<(X_val_bg+38))//小于范围
//			pwm_ctrl_RGB_byte[ch] = 10;//pwm duty 10
//  else if(slide_x>(X_val_bg+298-38))//超出范围
//			pwm_ctrl_RGB_byte[ch] = PWM_CTRL_MAX_VAL;//pwm duty 100
//  else
//		pwm_ctrl_RGB_byte[ch] = (slide_x-X_val_bg-38)*PWM_CTRL_MAX_VAL/(298-38*2);//
		    
  	if(slide_x<(X_val_bg+32))//小于范围
			pwm_ctrl_RGB_byte[ch] = 5;//pwm duty 10
  else if(slide_x>(X_val_bg+298-32))//超出范围
			pwm_ctrl_RGB_byte[ch] = PWM_CTRL_MAX_VAL;//pwm duty 100
  else
		pwm_ctrl_RGB_byte[ch] = (slide_x-X_val_bg-32)*PWM_CTRL_MAX_VAL/(298-32*2);//
  
  
  
        if(pwm_ctrl_RGB_byte[ch]<PWM_CTRL_MIN_VAL)//pwm duty 0，，最小亮度
             pwm_ctrl_RGB_byte[ch]= PWM_CTRL_MIN_VAL;
        
   //       sysprintf("PWM_duty%d=%dr\n----------------",ch,pwm_ctrl_RGB_byte[ch]);

            if(now_RGB_status.RGB_select==0)
        {
            ALL_Init(0);//关闭灯效
            send_FlC200_set_cmd_new(0xB4,0x00,0x01);//：控制器1

           send_FlC200_set_cmd_new(0xB1,pwm_ctrl_RGB_byte[ch]*255/100,0x01);//协议发送亮 度
           now_RGB_status.RGB[0].brightness=pwm_ctrl_RGB_byte[ch];//(0~100)
            disply_pwm_RGB_status(0,FALSE);//显示滑动条
           
        }
        else if(now_RGB_status.RGB_select==1)
        {
            ALL_Init(1);
            send_FlC200_set_cmd_new(0xB4,0x00,0x02);//：控制器2

         send_FlC200_set_cmd_new(0xB1,pwm_ctrl_RGB_byte[ch]*255/100,0x02);//协议发送
            now_RGB_status.RGB[1].brightness=pwm_ctrl_RGB_byte[ch];
            disply_pwm_RGB_status(1,FALSE);//显示滑动条


        } 

}


	//func_lights_scrollbar_bg_all(p,sn,X_lights_scrollbar_bg,LIGHT_PWM0);

void func_page3_Ellips(void* p,u8 sn)
{

}






void func_page3_slider_0(void* p,u8 sn)
{

    func_RGB_scrollbar_bg_all(p,sn,X_page3_slider_0,now_RGB_status.RGB_select);
   //func_RGB_scrollbar_bg_all(p,sn,X_page3_slider_0,0);
 
}


void func_page3_slider_0_2(void* p,u8 sn)
{

}


void func_page3_slider_100ALL(void* p,u8 sn)
{

}


bool page3_key;
void func_page3_key_d(void* p,u8 sn)
{
    	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
   
            sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
        if(p1->item[SN].now_status==STATUS_SELECT)//按ON
        {


            
            sysprintf("ooooooooooooooooooooooooooooN\n");
            
            if(now_RGB_status.RGB_select==0)
            {
                now_RGB_status.RGB[0].isPowerOn=1;
               send_FlC200_set_cmd_new(0xB0,0x0001,0x01);//：控制器1
                sysprintf("RGB1__________ON\r\n");
            }
            else if(now_RGB_status.RGB_select==1)
            {
                now_RGB_status.RGB[1].isPowerOn=1;
                sysprintf("RGB2__________ON\r\n");
                send_FlC200_set_cmd_new(0xB0,0x0001,0x02);//：控制器2

            }


        }
        else if(p1->item[SN].now_status==STATUS_IDLE)//取消选择OFF
        {
            sysprintf("oFFFFFFFFFFFFFFFFFFFFFFFFFFF\n");
             
               if(now_RGB_status.RGB_select==0)
               {  
                   sysprintf("RGB1__________OFF\r\n");
                   now_RGB_status.RGB[0].isPowerOn=0;

                   send_FlC200_set_cmd_new(0xB0,0x0000,0x01);//：控制器1
                   
         //        send_FlC200_set_cmd_new(0xB4,0x00,0x01);//：控制器1关闭灯效

               }
               else
               {
                   sysprintf("RGB2__________OFFF\r\n");
                  now_RGB_status.RGB[1].isPowerOn=0;

                  send_FlC200_set_cmd_new(0xB0,0x0000,0x02);//：控制器2
                   
                //  send_FlC200_set_cmd_new(0xB4,0x00,0x02);//：控制器2关闭灯效

               }
        }
     
}


void func_page3_add_up(void* p,u8 sn)//RGB设置亮度
{

	u8 SN =10;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH)//
	{     
        sysprintf("func_page3_add_up-------------------------\r\n");
         
         if(now_RGB_status.RGB_select==0)
         {
            if(now_RGB_status.RGB[0].brightness<100)now_RGB_status.RGB[0].brightness++;
            send_FlC200_set_cmd_new(0xB1,((u16)now_RGB_status.RGB[0].brightness*255/100),0x01);//：控制器1
            sysprintf("RGB1 ADD-------------------------\r\n");
             disply_pwm_RGB_status(0,FALSE);//显示滑动条
        }
        else if(now_RGB_status.RGB_select==1)
        {
            if(now_RGB_status.RGB[1].brightness<100)now_RGB_status.RGB[1].brightness++;
            send_FlC200_set_cmd_new(0xB1,((u16)now_RGB_status.RGB[1].brightness*255/100),0x02);//：控制器2
            sysprintf("RGB2 ADD-------------------------\r\n");
             disply_pwm_RGB_status(1,FALSE);//显示滑动条

         }

     //   disply_pwm_RGB_status(now_RGB_status.RGB_select,FALSE);//显示滑动条

	}
    
    
}

void func_page3_cut_up(void* p,u8 sn)//RGB设置亮度
{
    
	u8 SN =9;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_TOUCH)//
	{     
	sysprintf("func_page3_cut_up-------------------------\r\n");

        if(now_RGB_status.RGB_select==0)
         {
            if(now_RGB_status.RGB[0].brightness>5)now_RGB_status.RGB[0].brightness--;
            send_FlC200_set_cmd_new(0xB1,((u16)now_RGB_status.RGB[0].brightness*255/100),0x01);//：控制器1
	//sysprintf("RGB1 CUT-------------------------\r\n");
             disply_pwm_RGB_status(now_RGB_status.RGB_select,FALSE);//显示滑动条
        }
        else if(now_RGB_status.RGB_select==1)
        {
            if(now_RGB_status.RGB[1].brightness>5)now_RGB_status.RGB[1].brightness--;
            send_FlC200_set_cmd_new(0xB1,((u16)now_RGB_status.RGB[1].brightness*255/100),0x02);//：控制器2
          //  sysprintf("RGB2 CUT-------------------------\r\n");
            disply_pwm_RGB_status(now_RGB_status.RGB_select,FALSE);//显示滑动条
         }

	}
    
    
}


void func_page3_bk_1(void* p,u8 sn)
{

}



void func_page3_bk_2(void* p,u8 sn)
{

}




void func_page3_key_up(void* p,u8 sn)
{

    
}



void func_page3_FADE_up(void* p,u8 sn)
{

}



extern lcd_dis_item_t RGB_item[PAGE_RGB_NUM];//图片缓存区


void set_RGB_mode_icon(u8 sn)//互斥处理图片
{
	  u8 i;
    for(i=0;i<4;i++)//选项数
		{
		  if((i+RGB_MODE_SN)!=sn)//超出索引（互斥图片开始索引）
			{
			  RGB_item[i+RGB_MODE_SN].now_status = STATUS_IDLE;
				RGB_item[i+RGB_MODE_SN].key_type = KEY_TYPE_NORMAL;
			}
			else
			{               
						   RGB_item[i+RGB_MODE_SN].key_type = KEY_TYPE_NORMAL;// //可以反选
			}
		}
}

//RGBSystem now_RGB_status;   //现在状态

void func_page3_FLASH_d(void* p,u8 sn)
{

                    

        	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
        set_RGB_mode_icon(sn);
        if(now_RGB_status.RGB_select==0)
        {
            ALL_Init(0);
                    now_RGB_status.RGB[0].FLASH_Flag=1;
                        sysprintf("RGB1 FLASH_d----------------------------\r\n");
            send_FlC200_set_cmd_new(0xB4,0x01,0x01);//：控制器1
        }
        else if(now_RGB_status.RGB_select==1)
        {        
                        ALL_Init(1);
            now_RGB_status.RGB[1].FLASH_Flag=1;
                        sysprintf("RGB2 FLASH_d----------------------------\r\n");
            send_FlC200_set_cmd_new(0xB4,0x01,0x02);//：控制器2
        }
        sysprintf("FLASH_----------------------------\r\n");

	}
    
    
    if(p1->item[SN].now_status==STATUS_IDLE)
    {  
        
         if(now_RGB_status.RGB_select==0)            // 使用逻辑与（&&）判断所有标志位是否都为 0
        {
            
            now_RGB_status.RGB[0].FLASH_Flag=0;
            
            if (!(now_RGB_status.RGB[0].FADE_Flag||now_RGB_status.RGB[0].FLASH_Flag||now_RGB_status.RGB[0].SMOOT_Flag||now_RGB_status.RGB[0].STROBE_Flag))
            {
                                            sysprintf("RGB1 Mode OFF----------------------------\r\n");
                                            send_FlC200_set_cmd_new(0xB4,0x00,0x01);//：控制器1
            }
        }
        else if(now_RGB_status.RGB_select==1)
        {                    
                now_RGB_status.RGB[1].FLASH_Flag=0;

             if (!(now_RGB_status.RGB[1].FADE_Flag||now_RGB_status.RGB[1].FLASH_Flag||now_RGB_status.RGB[1].SMOOT_Flag||now_RGB_status.RGB[1].STROBE_Flag))
            {
                                            sysprintf("RGB2 Mode OFF----------------------------\r\n");
                                            send_FlC200_set_cmd_new(0xB4,0x00,0x02);//：控制器2
            }

        }       
            
        	sysprintf("STATUS_IDLE----------------------------\r\n");
            }
      
	sysprintf("func_page3_FLASH_d----------------------------\r\n");
}

extern u8 R,G,B;  // 最终 RGB 值

void func_page3_SMOOT_d(void* p,u8 sn)
{                  

     u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
        set_RGB_mode_icon(sn);
        
                   if(now_RGB_status.RGB_select==0)
                {
                                ALL_Init(0);

                    now_RGB_status.RGB[0].SMOOT_Flag=1;
                    sysprintf("RGB1 SMOOT_d----------------------------\r\n");
                send_FlC200_set_cmd_new(0xB4,0x02,0x01);//：控制器1
                }
                else  if(now_RGB_status.RGB_select==1)
                {          
                                ALL_Init(1);

                    now_RGB_status.RGB[1].SMOOT_Flag=1;
                    sysprintf("RGB2 SMOOT_d----------------------------\r\n");
                    send_FlC200_set_cmd_new(0xB4,0x02,0x02);//：控制器2
                }   
	}
        	if(p1->item[SN].now_status==STATUS_IDLE)
            {                      // 使用逻辑与（&&）判断所有标志位是否都为 0
                 if(now_RGB_status.RGB_select==0)            // 使用逻辑与（&&）判断所有标志位是否都为 0
                {
                    now_RGB_status.RGB[0].SMOOT_Flag=0;

                    if (!(now_RGB_status.RGB[0].FADE_Flag||now_RGB_status.RGB[0].FLASH_Flag||now_RGB_status.RGB[0].SMOOT_Flag||now_RGB_status.RGB[0].STROBE_Flag))
                    {
                                                    sysprintf("RGB1 Mode OFF----------------------------\r\n");
                                                    send_FlC200_set_cmd_new(0xB4,0x00,0x01);//：控制器1
                    }
                }
                else if(now_RGB_status.RGB_select==1)
                {                                  
                    now_RGB_status.RGB[1].SMOOT_Flag=0;
                     if (!(now_RGB_status.RGB[1].FADE_Flag||now_RGB_status.RGB[1].FLASH_Flag||now_RGB_status.RGB[1].SMOOT_Flag||now_RGB_status.RGB[1].STROBE_Flag))
                    {
                                                    sysprintf("RGB2 Mode OFF----------------------------\r\n");
                                                    send_FlC200_set_cmd_new(0xB4,0x00,0x02);//：控制器2
                    }

                }                   
                sysprintf("STATUS_IDLE----------------------------\r\n");

            }
        sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);

}

void func_page3_FADE_d(void* p,u8 sn)
{
    u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
        
        if(now_RGB_status.RGB_select==0)
      {
                                          ALL_Init(0);

                    now_RGB_status.RGB[0].FADE_Flag=1;
                sysprintf("RGB1 FADE_----------------------------\r\n");
                send_FlC200_set_cmd_new(0xB4,0x03,0x01);//：控制器1
      }
      else if(now_RGB_status.RGB_select==1)
      {          
                                          ALL_Init(1);

                    now_RGB_status.RGB[1].FADE_Flag=1;
                     sysprintf("RGB2 FADE_----------------------------\r\n");
                    send_FlC200_set_cmd_new(0xB4,0x03,0x02);//：控制器2
      }          
      
      
      
        set_RGB_mode_icon(sn);
	}
    

    
     if(p1->item[SN].now_status==STATUS_IDLE)
	{  
                 if(now_RGB_status.RGB_select==0)         
                {
                                            now_RGB_status.RGB[0].FADE_Flag=0;
                    if (!(now_RGB_status.RGB[0].FADE_Flag||now_RGB_status.RGB[0].FLASH_Flag||now_RGB_status.RGB[0].SMOOT_Flag||now_RGB_status.RGB[0].STROBE_Flag))
                    {
                        sysprintf("RGB1 Mode OFF----------------------------\r\n");
                        send_FlC200_set_cmd_new(0xB4,0x00,0x01);//：控制器1
                    }
                }
                else if(now_RGB_status.RGB_select==1)
                {        
                    now_RGB_status.RGB[1].FADE_Flag=0;
                     if (!(now_RGB_status.RGB[1].FADE_Flag||now_RGB_status.RGB[1].FLASH_Flag||now_RGB_status.RGB[1].SMOOT_Flag||now_RGB_status.RGB[1].STROBE_Flag))
                    {
                        sysprintf("RGB2 Mode OFF----------------------------\r\n");
                        send_FlC200_set_cmd_new(0xB4,0x00,0x02);//：控制器2
                    }

                }       
            
        	sysprintf("STATUS_IDLE----------------------------\r\n");

	}
            sysprintf("item[SN].now_status=%dr\n",p1->item[SN].now_status);
}




void func_page3_STROBE_d(void* p,u8 sn)
{
                	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{  
       if(now_RGB_status.RGB_select==0)
      {
               ALL_Init(0);
            now_RGB_status.RGB[0].STROBE_Flag=1;
                sysprintf("RGB1 STROBE_d----------------------------\r\n");
               send_FlC200_set_cmd_new(0xB4,0x04,0x01);//：控制器1
      }
        else if(now_RGB_status.RGB_select==1)
     {          
            ALL_Init(1);

          now_RGB_status.RGB[1].STROBE_Flag=1;
           sysprintf("RGB2 STROBE_d----------------------------\r\n");
            send_FlC200_set_cmd_new(0xB4,0x04,0x02);//：控制器2
      }      
        set_RGB_mode_icon(sn);
                sysprintf("STROBE_d----------------------------\r\n");
	}    
        	if(p1->item[SN].now_status==STATUS_IDLE)
            {                     
                          if(now_RGB_status.RGB_select==0)            // 使用逻辑与（&&）判断所有标志位是否都为 0
                        {

                            now_RGB_status.RGB[0].STROBE_Flag=0;
                            if (!(now_RGB_status.RGB[0].FADE_Flag||now_RGB_status.RGB[0].FLASH_Flag||now_RGB_status.RGB[0].SMOOT_Flag||now_RGB_status.RGB[0].STROBE_Flag))
                            {
//                              sysprintf("RGB1 Mode OFF----------------------------\r\n");
                              send_FlC200_set_cmd_new(0xB4,0x00,0x01);//：控制器1
                            }
                        }
                        else if(now_RGB_status.RGB_select==1)
                        {        
                              now_RGB_status.RGB[1].STROBE_Flag=0;
                             if (!(now_RGB_status.RGB[1].FADE_Flag||now_RGB_status.RGB[1].FLASH_Flag||now_RGB_status.RGB[1].SMOOT_Flag||now_RGB_status.RGB[1].STROBE_Flag))
                            {
                              send_FlC200_set_cmd_new(0xB4,0x00,0x02);//：控制器2
                            }
                        }       
                    sysprintf("STATUS_IDLE----------------------------\r\n");

            }
            
    
}


void func_page3_FLASH_up(void* p,u8 sn)
{

}



void func_page3_RGB(void* p,u8 sn)
{

}



void func_page3_slider(void* p,u8 sn)
{

}






void func_page3_SMOOT_up(void* p,u8 sn)
{

}






void func_page3_STROBE_up(void* p,u8 sn)
{

}