#include "includes.h"



extern void func_power_alarm_btn1_d(void* p,u8 sn);
extern void func_power_alarm_btn1_u(void* p,u8 sn);
extern void func_power_alarm_btn2_d(void* p,u8 sn);
extern void func_power_alarm_btn2_u(void* p,u8 sn);
extern void func_power_alarm_btn3_u(void* p,u8 sn);
extern void func_power_alarm_btn3_d(void* p,u8 sn);
extern void func_power_alarm_btn4_d(void* p,u8 sn);
extern void func_power_alarm_btn4_u(void* p,u8 sn);
extern void func_power_alarm_b_power_alarm_d(void* p,u8 sn);
extern void func_power_alarm_b_power_alarm_u(void* p,u8 sn);
extern void func_power_alarm_headline(void* p,u8 sn);
extern void func_power_alarm_nextpage_d(void* p,u8 sn);
extern void func_power_alarm_nextpage_o(void* p,u8 sn);
extern void func_power_alarm_nextpage_u(void* p,u8 sn);
extern void func_power_alarm_prepage_d(void* p,u8 sn);
extern void func_power_alarm_prepage_o(void* p,u8 sn);
extern void func_power_alarm_prepage_u(void* p,u8 sn);
extern void func_system_b_alarm_d(void* p,u8 sn);
extern void func_system_b_alarm_u(void* p,u8 sn);


lcd_dis_item_t power_alarm_item[SYSTEM_ALARM_ICO_NUM];




void*p_func_power_alarm_item_d[SYSTEM_SYSTEM_ICO_NUM]=
{	
	&func_power_alarm_headline,
  &func_power_alarm_btn1_d,
  &func_power_alarm_btn2_d,
  &func_power_alarm_btn3_d,
  &func_power_alarm_btn4_d,
  &func_power_alarm_nextpage_d,
  &func_power_alarm_prepage_d,
	&func_system_b_alarm_d,
};

u16 now_page_power_alarm = 0x0000;//从高到低 --1级--2级--3级--4级
u8 now_page_power_alarm_deep = 0x00;//当前处于哪一层

void reset_page_power_alarm(void)
{
  now_page_power_alarm = 0;
}

void power_alarm_info_printf(u8 num,lcd_dis_item_t* p,WARNING_CODE_LIST* p_list,u8 list_num)
{
	u8 item_num=0;
	char display_buf[64];
	lcd_dis_item_t *p_y,*p_r;
	item_num = num%4;
	//sysprintf("\r\n power_alarm_info_printf:%04X,%X",num,list_num);
	switch(item_num)
	{
		case 1:
			p_r=&t_set_err_r_1;
		  p_y=&t_set_err_y_1;
			break;
	  case 2:
			p_r=&t_set_err_r_2;
		  p_y=&t_set_err_y_2;
			break;
	
		case 3:
			p_r=&t_set_err_r_3;
		  p_y=&t_set_err_y_3;
			break;
	
		case 0:
			p_r=&t_set_err_r_4;
		  p_y=&t_set_err_y_4;
			break;
	  default :
			return;
			//break;
		
	}
	if((p_list[num].err_code_type==2)||(p_list[num].err_code_type==3))//=1：警告  =2：故障/错误  =3：保护  =4：没连接 
		 png_dis_xy(p_r->x_val,p_r->y_val,p_r->pic_item,p_r->size_of_pic_item,Virtual_LCDbuff2);
	else
	   png_dis_xy(p_y->x_val,p_y->y_val,p_y->pic_item,p_y->size_of_pic_item,Virtual_LCDbuff2); 

	sprintf(display_buf,"%d/%d %02d-%02d-%02d %02d:%02d:%02d  ",num,list_num,\
					p_list[num].time_happen.year,\
					p_list[num].time_happen.mon,\
					p_list[num].time_happen.day,\
					p_list[num].time_happen.hour,\
					p_list[num].time_happen.min,\
					p_list[num].time_happen.sec);
	
	Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_system_system_offset+50,p->y_val+Y_system_system_offset-10,display_buf,(ARGB_gray),0,1,1);
  Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+X_system_system_offset+50,p->y_val+Y_system_system_offset+10,&p_list[num].txt[0],(0xFFe2e2e4),0,1,1);

				
}		 


void display_power_alarm_info(void)
{
//	char display_buf[64];
	//lcd_dis_item_t *p;
	u16 i;//,addr;
	u8 temp;
	lcd_dis_item_t* p;
	
	p=power_alarm_item;
	sysprintf("\r\n page:%04X,%X",now_page_power_alarm,now_page_power_alarm_deep);
	if(now_page_power_alarm_deep==0)//第一层
	{
		
		
		// power_waining_code_list updata
		power_waining_code_list_num = 0;
		for(i=0;i<waining_code_list_num;i++)
		{
			//sysprintf("\r\n ----------------%d,%X,%c",i,waining_code_list[i].err_code_from,waining_code_list[i].txt[0]);
		//	sysprintf("\r\n ------+1--------%d,%X,%c",i,waining_code_list[i+1].err_code_from,waining_code_list[i+1].txt[0]);
		   if(waining_code_list[i+1].err_code_from&0x80)
			 {
				     power_waining_code_list_num++;
			       memcpy(&power_waining_code_list[power_waining_code_list_num],&waining_code_list[i+1],sizeof(WARNING_CODE_LIST));
              
			  //sysprintf("\r\n ----------------%d,%X,%c",power_waining_code_list_num,power_waining_code_list[power_waining_code_list_num].err_code_from,power_waining_code_list[power_waining_code_list_num].txt[0]);
				 
			 }
		
		}
		
		for(i=0;TRUE;i++)
		{
			 if((i*0x1000)==now_page_power_alarm)
			 {
				 //sysprintf("\r\n p[1].x_val,p[1].y_val:%d,%d",p[1].x_val,p[1].y_val);
				 if(now_page_power_alarm==0x0000)
			   {
			     p[6].key_type = KEY_TYPE_TOUCH_NONE;
					 p[6].now_status = STATUS_IDLE;
					 p[6].last_status = STATUS_IDLE;
				 }
			   else	
				 {					 
				  p[6].key_type = KEY_TYPE_ONCE;
					 p[6].now_status = STATUS_IDLE;
					 p[6].last_status = STATUS_IDLE;
				 }
				 p[5].key_type = KEY_TYPE_ONCE;
				 p[1].key_type = KEY_TYPE_TOUCH_NONE;
         Virtual_LCD_Draw_Rectangle_ARGB32(p[1].x_val,p[1].y_val,p[1].x_end_val-p[1].x_val,p[1].y_end_val-p[1].y_val,Virtual_LCDbuff2,ARGB_clear);
				 Virtual_LCD_Draw_Rectangle_ARGB32(p[2].x_val,p[2].y_val,p[2].x_end_val-p[2].x_val,p[2].y_end_val-p[2].y_val,Virtual_LCDbuff2,ARGB_clear);
				 Virtual_LCD_Draw_Rectangle_ARGB32(p[3].x_val,p[3].y_val,p[3].x_end_val-p[3].x_val,p[3].y_end_val-p[3].y_val,Virtual_LCDbuff2,ARGB_clear);
				 Virtual_LCD_Draw_Rectangle_ARGB32(p[4].x_val,p[4].y_val,p[4].x_end_val-p[4].x_val,p[4].y_end_val-p[4].y_val,Virtual_LCDbuff2,ARGB_clear);

				 if(i==0)
				 {
					p[1].key_type = KEY_TYPE_TOUCH_NONE;
					Virtual_LCD_Draw_Rectangle_ARGB32(142,90,700,24,Virtual_LCDbuff2,ARGB_clear);
					Virtual_LCD_Draw_String_ARGB_24_4bit(142,90,"Power Alarm Info",(0xFF78baf7),0,1,1);
				
				
				
					
					//Virtual_LCD_Draw_Rectangle_ARGB32(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
					if(power_waining_code_list_num==0)
					{					
						Virtual_LCD_Draw_String_ARGB_24_4bit(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,"No Fault Or Warning Information",(0xFFe2e2e4),0,1,1);
					  p[5].key_type = KEY_TYPE_TOUCH_NONE;
						p[6].key_type = KEY_TYPE_TOUCH_NONE;
						break;
					}
			
					 else
					 {
						 //	Virtual_LCD_Draw_Rectangle_ARGB32(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
							temp = 1+i*4;
							if(power_waining_code_list_num>=temp)
							{					
								power_alarm_info_printf(temp,&p[1],&power_waining_code_list[0],power_waining_code_list_num);				
								//Virtual_LCD_Draw_String_ARGB_24_4bit(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
								//sysprintf("\r\n --------------1 %d,%d",power_waining_code_list_num,temp);
								if(power_waining_code_list_num==temp)
								{
								 p[5].key_type = KEY_TYPE_TOUCH_NONE;
								 p[5].now_status = STATUS_IDLE;
						         p[5].last_status = STATUS_IDLE;
								break;
							 }
							}
					 
					 }
		   
				 }
          else
					 {
						 //	Virtual_LCD_Draw_Rectangle_ARGB32(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
							temp = 1+i*4;
							if(power_waining_code_list_num>=temp)
							{					
								power_alarm_info_printf(temp,&p[1],&power_waining_code_list[0],power_waining_code_list_num);				
								//Virtual_LCD_Draw_String_ARGB_24_4bit(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
								//sysprintf("\r\n --------------1 %d,%d",power_waining_code_list_num,temp);
								if(power_waining_code_list_num==temp)
								{
								 p[5].key_type = KEY_TYPE_TOUCH_NONE;
							p[5].now_status = STATUS_IDLE;
						 p[5].last_status = STATUS_IDLE;
								break;
							 }
							}
					 
					 }


        
				
				//2
				//Virtual_LCD_Draw_Rectangle_ARGB32(p[2].x_val+X_system_system_offset,p[2].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
				
			  temp = 2+i*4;//2
				if(power_waining_code_list_num>=temp)
				{					
					power_alarm_info_printf(temp,&p[2],&power_waining_code_list[0],power_waining_code_list_num);	
          //Virtual_LCD_Draw_String_ARGB_24_4bit(p[2].x_val+X_system_system_offset,p[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);					
			    //sysprintf("\r\n --------------2 %d,%d",power_waining_code_list_num,temp);
					if(power_waining_code_list_num==temp)
					{
						 p[5].key_type = KEY_TYPE_TOUCH_NONE;
						p[5].now_status = STATUS_IDLE;
						 p[5].last_status = STATUS_IDLE;
						break;
					 }
				}

				//3
				temp = 3+i*4;//3
				//Virtual_LCD_Draw_Rectangle_ARGB32(p[3].x_val+X_system_system_offset,p[3].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
			  if(power_waining_code_list_num>=temp)
				{					
					power_alarm_info_printf(temp,&p[3],&power_waining_code_list[0],power_waining_code_list_num);		
           //Virtual_LCD_Draw_String_ARGB_24_4bit(p[3].x_val+X_system_system_offset,p[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);					
			     //sysprintf("\r\n --------------3 %d,%d",power_waining_code_list_num,temp);
					if(power_waining_code_list_num==temp)
					 {
						 p[5].key_type = KEY_TYPE_TOUCH_NONE;
							p[5].now_status = STATUS_IDLE;
						 p[5].last_status = STATUS_IDLE;
						break;
					 }
				}

				
        //4
				temp = 4+i*4;//4
				//Virtual_LCD_Draw_Rectangle_ARGB32(p[4].x_val+X_system_system_offset,p[4].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
				if(power_waining_code_list_num>=temp)
				{					
					power_alarm_info_printf(temp,&p[4],&power_waining_code_list[0],power_waining_code_list_num);	
					//Virtual_LCD_Draw_String_ARGB_24_4bit(p[4].x_val+X_system_system_offset,p[4].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
          //sysprintf("\r\n --------------4 %d,%d",power_waining_code_list_num,temp);
					if(power_waining_code_list_num==temp)
					{
						 p[5].key_type = KEY_TYPE_TOUCH_NONE;
						 p[5].now_status = STATUS_IDLE;
						 p[5].last_status = STATUS_IDLE;
						break;
					 }
					 
			  }

		   break;
			}
		     
		}
		

  }
	


}










BOOL page_power_alarm_deel_with_i(lcd_dis_page_t *p2,u8* i)
{

   return FALSE;

}
///////////////////////初始化////////////////////////////////////////


extern lcd_dis_item_t *p_system_alarm_item_d[SYSTEM_ALARM_ICO_NUM];
extern lcd_dis_item_t *p_system_alarm_item_u[SYSTEM_ALARM_ICO_NUM];


//
void ui_power_alarm_init(void)//
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_POWER][TOP_SIDE_PAGE_POWER_ALARM];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=SYSTEM_ALARM_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only

	
	//alarm界面ui_system_alarm_init()这个要先初始化，其他设置system_alarm_item个为基准
   t_system_b_back_d.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
   p->item = power_alarm_item;
   for(i=0;i<SYSTEM_ALARM_ICO_NUM;i++)
	 {
	    memcpy(&(p->item[i]),p_system_alarm_item_d[i],sizeof(lcd_dis_item_t));
	    p->item[i].pic_item =p_system_alarm_item_u[i]->pic_item;//
   	  p->item[i].size_of_pic_item = p_system_alarm_item_u[i]->size_of_pic_item ;
		  p->item[i].f = p_func_power_alarm_item_d[i];
	 
	 }
 }


