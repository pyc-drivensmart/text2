#include "includes.h"

 extern   LightSystem light_now_sta;//现在状态


//read me:copy the new item to 'ui_func.c'


// 通用的灯光控制处理函数
void func_page1_light_common(void* p, u8 sn, u8 channel)
{
    u8 SN = sn; // 图标在当前页面列表的序号
    lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    
    sysprintf("item[SN].now_status=%d\r\n", p1->item[SN].now_status); // 修复笔误：%dr→%d，统一换行符\r\n
    
    if (p1->item[SN].now_status == STATUS_SELECT) // 选中状态 → 开灯
    {
        // 按通道映射发送开灯指令（0x01=ON）
        if (channel < 4)
        {
            send_FlC200_swtich_cmd(channel, 0x01); // 1-4灯：通道号=channel（直接使用）
        }
        else if (channel == 4)
        {
            send_FlC200_swtich_cmd(0x09, 0x01); // 5灯：固定通道0x09
        }
        else if (channel == 5)
        {
            send_FlC200_swtich_cmd(0x0a, 0x01); // 6灯：固定通道0x0a
        }
        
        light_now_sta.lights[channel].isPowerOn = 1; // 更新本地状态为“开”
        sysprintf("ON (Input Channel %d)-----------------------------\r\n", channel);
    }
    else if (p1->item[SN].now_status == STATUS_IDLE) // 空闲状态 → 关灯
    {
        // 按通道映射发送关灯指令（0x00=OFF）
        if (channel < 4)
        {
            send_FlC200_swtich_cmd(channel, 0x00); // 1-4灯：通道号=channel（直接使用）
        }
        else if (channel == 4)
        {
            send_FlC200_swtich_cmd(0x09, 0x00); // 5灯：固定通道0x09（修复原注释错误）
        }
        else if (channel == 5)
        {
            send_FlC200_swtich_cmd(0x0a, 0x00); // 6灯：固定通道0x0a（修复原注释错误）
        }
        
        light_now_sta.lights[channel].isPowerOn = 0; // 更新本地状态为“关”
        sysprintf("OFF (Input Channel %d)-----------------------------\r\n", channel);
    }
}



void func_page11_light_off(void* p,u8 sn)
{

}



void func_page11_light_off2(void* p,u8 sn)
{

}



void func_page11_light_off3(void* p,u8 sn)
{

}



void func_page11_light_off4(void* p,u8 sn)
{

}



void func_page11_light_off5(void* p,u8 sn)
{

}



void func_page11_light_off6(void* p,u8 sn)
{

}



void func_page11_light_on(void* p,u8 sn)
{
    func_page1_light_common(p, sn, 0); // 通道

}



void func_page11_light_on2(void* p,u8 sn)
{
    func_page1_light_common(p, sn, 1); // 通道

}



void func_page11_light_on3(void* p,u8 sn)
{
    func_page1_light_common(p, sn, 2); // 通道

}



void func_page11_light_on4(void* p,u8 sn)
{
    func_page1_light_common(p, sn, 3); // 通道

}



void func_page11_light_on5(void* p,u8 sn)
{
    func_page1_light_common(p, sn, 4); // 通道

}



void func_page11_light_on6(void* p,u8 sn)
{
    func_page1_light_common(p, sn, 5); // 通道

}



void func_page1_light_bk_bk(void* p,u8 sn)
{

}



void func_page1_light_bk_bk2(void* p,u8 sn)
{

}



void func_page1_light_bk_bk3(void* p,u8 sn)
{

}



void func_page1_light_bk_bk4(void* p,u8 sn)
{

}



void func_page1_light_bk_bk5(void* p,u8 sn)
{

}



void func_page1_light_bk_bk6(void* p,u8 sn)
{

}



void func_page1_light_bk(void* p,u8 sn)
{

}

void func_page1_light_bk2(void* p,u8 sn)
{

}
void func_page1_light_bk3(void* p,u8 sn)
{

}
void func_page1_light_bk4(void* p,u8 sn)
{

}
void func_page1_light_bk5(void* p,u8 sn)
{

}void func_page1_light_bk6(void* p,u8 sn)
{

}
//void func_page1_light_off(void* p,u8 sn)
//{        	
//    

//}
//void func_page1_light_off2(void* p,u8 sn)
//{
//    
//}
//void func_page1_light_off3(void* p,u8 sn)
//{
//}
//void func_page1_light_off4(void* p,u8 sn)
//{
//	
//}
//void func_page1_light_off5(void* p,u8 sn)
//{

//}
//void func_page1_light_off6(void* p,u8 sn)
//{

//}


// 保留原函数接口，作为通用函数的包装
void func_page1_light_on(void* p, u8 sn)
{
//    func_page1_light_common(p, sn, 0); // 通道0
}
void func_page1_light_off(void* p, u8 sn)
{
    // 可根据需要实现，或调用通用函数
}
void func_page1_light_off2(void* p, u8 sn)
{
    // 可根据需要实现，或调用通用函数
}

void func_page1_light_on2(void* p, u8 sn)
{
 //   func_page1_light_common(p, sn, 1); // 通道1
}

void func_page1_light_off3(void* p, u8 sn)
{
    // 可根据需要实现，或调用通用函数
}

void func_page1_light_on3(void* p, u8 sn)
{
  //  func_page1_light_common(p, sn, 2); // 通道2
}

void func_page1_light_off4(void* p, u8 sn)
{
    // 可根据需要实现，或调用通用函数
}

void func_page1_light_off5(void* p, u8 sn)
{
    // 可根据需要实现，或调用通用函数
}

void func_page1_light_off6(void* p, u8 sn)
{
    // 可根据需要实现，或调用通用函数
}

void func_page1_light_on4(void* p, u8 sn)
{
 //   func_page1_light_common(p, sn, 3); // 通道3
}
void func_page1_light_on5(void* p, u8 sn)
{
///    func_page1_light_common(p, sn, 4); // 通道
}

void func_page1_light_on6(void* p, u8 sn)
{
  ///  func_page1_light_common(p, sn, 5); // 通道
}
void func_page1_slider75(void* p,u8 sn)
{

}



void func_page1_slider_0(void* p,u8 sn)
{

}

void func_page1_slider_0_1(void* p,u8 sn)
{

}

void func_page1_slider_0_2(void* p,u8 sn)
{

}

void func_page1_slider_0_3(void* p,u8 sn)
{

}

void func_page1_slider_0_4(void* p,u8 sn)
{

}

void func_page1_slider_0_5(void* p,u8 sn)
{

}

void func_page1_slider_0_6(void* p,u8 sn)
{

}

//page1


//read me:copy the new item to 'ui_func.c'

u8 pwm_p1_light_ctrl_byte[P1_Light_PWM_CTRL_CH]={5};//(0~100)


u8 p1_lights_display_lights_ch[P1_Light_PWM_CTRL_CH] = {0,1,0x02,0x03,9,0x0A};

void disply_page1_light_pwm_status(u8 type,bool upgrage)//显示,type:通道
{
  static u8 old_pwm_p1_light_ctrl_byte[P1_Light_PWM_CTRL_CH]={5,5,5,5,5,5};//默认亮度
	  lcd_dis_item_t *p,*p2,*p3,*p4;
	u8 offet = 5;
	u8 val_temp =5;
	u8 ch;
	char display_buf[16];

	switch(type) //选择通道
	{
	  case Page1_LIGHT_PWM0:
			p=&t_page1_light_slider_0_1;//0背景
		  p2 = &t_page1_light_slider_100_1;//满进度
		  p3 = &t_page1_Ellipse_1;//滑块2
          p4 = &t_page1_light_bk_bk;
		  val_temp = pwm_p1_light_ctrl_byte[type];//获取百分比
			break;
		
		case Page1_LIGHT_PWM1:
			p=&t_page1_light_slider_0_2;//0背景
		  p2 = &t_page1_light_slider_100_2;//满进度
		  p3 = &t_page1_Ellipse_2;//滑块2
                  p4 = &t_page1_light_bk_bk2;

		  val_temp = pwm_p1_light_ctrl_byte[type];
			break;
		
		case Page1_LIGHT_PWM2:
			p=&t_page1_light_slider_0_3;//0背景
		  p2 = &t_page1_light_slider_100_3;//满进度
		  p3 = &t_page1_Ellipse_3;//滑块2
                  p4 = &t_page1_light_bk_bk3;

		  val_temp = pwm_p1_light_ctrl_byte[type];
			break;
		case Page1_LIGHT_PWM3:
			p=&t_page1_light_slider_0_4;//0背景
		  p2 = &t_page1_light_slider_100_4;//满进度
		  p3 = &t_page1_Ellipse_4;//滑块2
                  p4 = &t_page1_light_bk_bk4;

		  val_temp = pwm_p1_light_ctrl_byte[type];
			break;
		case Page1_LIGHT_PWM4:
			p=&t_page1_light_slider_0_5;//0背景
		  p2 = &t_page1_light_slider_100_5;//满进度
		  p3 = &t_page1_Ellipse_5;//滑块2
                  p4 = &t_page1_light_bk_bk5;

		  val_temp = pwm_p1_light_ctrl_byte[type];
			break;
		case Page1_LIGHT_PWM5:
			p=&t_page1_light_slider_0_6;//0背景
		  p2 = &t_page1_light_slider_100_6;//满进度
		  p3 = &t_page1_Ellipse_6;//滑块2
                  p4 = &t_page1_light_bk_bk6;

		  val_temp = pwm_p1_light_ctrl_byte[type];
			break;

		default:
			return;
			//break;
				
	}
	
	if((val_temp!=old_pwm_p1_light_ctrl_byte[type])||(upgrage))
	{
     old_pwm_p1_light_ctrl_byte[type] = val_temp;
		
		ch = p1_lights_display_lights_ch[type];
            png_dis_xy(p4->x_val,p4->y_val,p4->pic_item,p4->size_of_pic_item,Virtual_LCDbuff1);//残影遮罩
        	 png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);//显0进度

        if(val_temp==0)
        {
				 png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);//显0进度
                   png_dis_xy(p3->x_val,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);//滑块0
        }
        
                if((val_temp>0)&&(val_temp<=100))
				{		
                    
                offet = val_temp*190/100+5;//205滑块长（190）
//					
                    // 调用PNG图片裁剪显示函数，实现横向从x_val到offet的完整显示，纵向默认从顶部开始显示
                    png_dis_xy_form_x1y1_to_x2y2(
                        p2->x_val,                   // 1. 图片在LCD上的起始X坐标（显示区域左上角X）
                        p2->y_val,                   // 2. 图片在LCD上的起始Y坐标（显示区域左上角Y）
                        p2->pic_item,                // 3. 指向PNG图片原始数据的缓冲区（二进制数据）
                        p2->size_of_pic_item,        // 4. PNG图片原始数据的大小（字节数）
                        0,                           // 5. 图片横向裁剪起始X坐标（从原图最左侧开始，不裁切X）
                        0,                           // 6. 图片纵向裁剪起始Y坐标（从原图最顶部开始，不裁切Y）
                        offet,                       // 7. 图片横向裁剪结束X坐标（到offet位置，即横向显示x_val到offet的完整内容）
                        p2->y_end_val - p2->y_val,   // 8. 图片纵向裁剪结束Y坐标（计算方式：显示区域的总高度 = 结束Y - 起始Y）
                        0,                           // 9. X方向偏移量（0表示无偏移，显示位置与x_val一致）
                        0,                           // 10. Y方向偏移量（0表示无偏移，显示位置与y_val一致）
                        Virtual_LCDbuff1             // 11. 显示图层缓冲区（指定绘制到Virtual_LCDbuff1图层）
                    );	// 功能说明：横向从x_val到offet的区域会显示图片的完整横向内容（100%显示，不裁切），纵向从顶部开始显示到指定高度//			offet到x_val显示0%
                    
				 png_dis_xy(p3->x_val+offet-10,p3->y_val,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);//滑块，滑块22（10）
				}
			
				if(upgrage==FALSE)
				{
                Virtual_LCD_Upgrate_formx1y1(p->x_val,(p->y_val)-20,p->x_end_val-p->x_val,(p->y_end_val-p->y_val)+20);//增加y轴3刷新+-5
				//Virtual_LCD_Upgrate_formx1y1(p4->x_val,p4->y_val,p4->x_end_val-p4->x_val,p4->y_end_val-p4->y_val);

				v_clear_lights_pwm_val[type] = 300;//3S
				}
			}
                
                
                
	

}







void func_page1_lights_scrollbar_bg_all(void* p,u8 sn,u32 X_val_bg,u8 ch)//根据x坐标 ,ch：通道，滑动条(空)回调函数调用
{	
	//u8 SN = sn;//图标在当前页面列表的序号
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
    //22：滑块宽度，162:滑动背景宽度205
    //ch：通道
       //X_val_bg：空进度坐标x，ch：通道，

	if(slide_x<(X_val_bg+22))//小于范围
			pwm_p1_light_ctrl_byte[ch] = 5;//pwm duty 1
  else if(slide_x>(X_val_bg+205-22))//超出范围
			pwm_p1_light_ctrl_byte[ch] = P1_Light_PWM_CTRL_MAX_VAL;//pwm duty 100
  else
		pwm_p1_light_ctrl_byte[ch] = (slide_x-X_val_bg-22)*P1_Light_PWM_CTRL_MAX_VAL/(205-44);
		
	if(pwm_p1_light_ctrl_byte[ch]<P1_PWM_CTRL_MIN_VAL)//pwm duty 5，，最小亮度
		 pwm_p1_light_ctrl_byte[ch]= P1_PWM_CTRL_MIN_VAL;//获取坐标百分比
    
    
	//  sysprintf("Light_PWM_duty %d=%d\r\n----------------",ch,pwm_p1_light_ctrl_byte[ch]);
    
    
        for(int i=0;i<6;i++)
          light_now_sta.lights[i].brightness=pwm_p1_light_ctrl_byte[i];
        send_FlC200_swtich_cmd(0x30+ch,pwm_p1_light_ctrl_byte[ch]);//协议发送

	disply_page1_light_pwm_status(ch,FALSE);//显示滑动条
}


#define Page1_LIGHT_PWM0 0 
#define Page1_LIGHT_PWM1 1
#define Page1_LIGHT_PWM2 2
#define Page1_LIGHT_PWM3 3
#define Page1_LIGHT_PWM4 4
#define Page1_LIGHT_PWM5 5


void func_page1_light_slider_0_1(void* p,u8 sn)
{
//func_RGB_scrollbar_bg_all(p,sn,X_page3_slider_0,0);
	func_page1_lights_scrollbar_bg_all(p,sn,X_page1_light_slider_0_1,Page1_LIGHT_PWM0);//x坐标，灯序号

}



void func_page1_light_slider_0_2(void* p,u8 sn)
{
	func_page1_lights_scrollbar_bg_all(p,sn,X_page1_light_slider_0_2,Page1_LIGHT_PWM1);//x坐标，灯序号

}



void func_page1_light_slider_0_3(void* p,u8 sn)
{
	func_page1_lights_scrollbar_bg_all(p,sn,X_page1_light_slider_0_3,Page1_LIGHT_PWM2);//x坐标，灯序号

}



void func_page1_light_slider_0_4(void* p,u8 sn)
{
	func_page1_lights_scrollbar_bg_all(p,sn,X_page1_light_slider_0_4,Page1_LIGHT_PWM3);//x坐标，灯序号

}



void func_page1_light_slider_0_5(void* p,u8 sn)
{
	func_page1_lights_scrollbar_bg_all(p,sn,X_page1_light_slider_0_5,Page1_LIGHT_PWM4);//x坐标，灯序号

}



void func_page1_light_slider_0_6(void* p,u8 sn)
{
	func_page1_lights_scrollbar_bg_all(p,sn,X_page1_light_slider_0_6,Page1_LIGHT_PWM5);//x坐标，灯序号
}



void func_page1_light_slider_0_b(void* p,u8 sn)
{

}



void func_page1_light_slider_100_1(void* p,u8 sn)
{

}



void func_page1_light_slider_100_2(void* p,u8 sn)
{

}



void func_page1_light_slider_100_3(void* p,u8 sn)
{

}



void func_page1_light_slider_100_4(void* p,u8 sn)
{

}



void func_page1_light_slider_100_5(void* p,u8 sn)
{

}



void func_page1_light_slider_100_6(void* p,u8 sn)
{

}



void func_page1_light_slider_100_b(void* p,u8 sn)
{

}



void func_page1_Ellipse_1(void* p,u8 sn)
{

}



void func_page1_Ellipse_2(void* p,u8 sn)
{

}



void func_page1_Ellipse_3(void* p,u8 sn)
{

}



void func_page1_Ellipse_4(void* p,u8 sn)
{

}



void func_page1_Ellipse_5(void* p,u8 sn)
{

}



void func_page1_Ellipse_6(void* p,u8 sn)
{

}



void func_page1_Ellipse_b(void* p,u8 sn)
{

}


