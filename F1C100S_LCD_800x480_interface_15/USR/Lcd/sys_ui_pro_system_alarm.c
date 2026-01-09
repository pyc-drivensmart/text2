#include "includes.h"



extern void func_system_alarm_btn1_d(void* p,u8 sn);
extern void func_system_alarm_btn1_u(void* p,u8 sn);
extern void func_system_alarm_btn2_d(void* p,u8 sn);
extern void func_system_alarm_btn2_u(void* p,u8 sn);
extern void func_system_alarm_btn3_u(void* p,u8 sn);
extern void func_system_alarm_btn3_d(void* p,u8 sn);
extern void func_system_alarm_btn4_d(void* p,u8 sn);
extern void func_system_alarm_btn4_u(void* p,u8 sn);
extern void func_system_alarm_b_system_alarm_d(void* p,u8 sn);
extern void func_system_alarm_b_system_alarm_u(void* p,u8 sn);
extern void func_system_alarm_headline(void* p,u8 sn);
extern void func_system_alarm_nextpage_d(void* p,u8 sn);
extern void func_system_alarm_nextpage_o(void* p,u8 sn);
extern void func_system_alarm_nextpage_u(void* p,u8 sn);
extern void func_system_alarm_prepage_d(void* p,u8 sn);
extern void func_system_alarm_prepage_o(void* p,u8 sn);
extern void func_system_alarm_prepage_u(void* p,u8 sn);
extern void func_system_b_alarm_d(void* p,u8 sn);
extern void func_system_b_alarm_u(void* p,u8 sn);






extern const unsigned char system_btn1_d[];
extern const unsigned char system_btn2_d[];
extern const unsigned char system_btn3_d[];
extern const unsigned char system_btn4_d[];
extern const unsigned char system_btn1_u[];
extern const unsigned char system_btn2_u[];
extern const unsigned char system_btn3_u[];
extern const unsigned char system_btn4_u[];

extern const unsigned char system_headline[];
extern const unsigned char system_nextpage_d[];
extern const unsigned char system_nextpage_u[];
extern const unsigned char system_nextpage_o[];
extern const unsigned char system_prepage_d[];
extern const unsigned char system_prepage_o[];
extern const unsigned char system_prepage_u[];


lcd_dis_item_t t_system_alarm_btn1_d={(unsigned char*)system_btn1_d,(unsigned char*)system_btn1_d,(unsigned char*)system_btn1_d,0,0,3496,3496,3496,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_btn1_d,Y_system_alarm_btn1_d,X_system_alarm_btn1_d+732,Y_system_alarm_btn1_d+85,0,&func_system_alarm_btn1_d};
lcd_dis_item_t t_system_alarm_btn1_u={(unsigned char*)system_btn1_u,(unsigned char*)system_btn1_u,(unsigned char*)system_btn1_u,0,0,3070,3070,3070,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_btn1_u,Y_system_alarm_btn1_u,X_system_alarm_btn1_u+732,Y_system_alarm_btn1_u+85,0,&func_system_alarm_btn1_u};
lcd_dis_item_t t_system_alarm_btn2_d={(unsigned char*)system_btn2_d,(unsigned char*)system_btn2_d,(unsigned char*)system_btn2_d,0,0,3690,3690,3690,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_btn2_d,Y_system_alarm_btn2_d,X_system_alarm_btn2_d+732,Y_system_alarm_btn2_d+85,0,&func_system_alarm_btn2_d};
lcd_dis_item_t t_system_alarm_btn2_u={(unsigned char*)system_btn2_u,(unsigned char*)system_btn2_u,(unsigned char*)system_btn2_u,0,0,3325,3325,3325,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_btn2_u,Y_system_alarm_btn2_u,X_system_alarm_btn2_u+732,Y_system_alarm_btn2_u+85,0,&func_system_alarm_btn2_u};
lcd_dis_item_t t_system_alarm_btn3_d={(unsigned char*)system_btn3_d,(unsigned char*)system_btn3_d,(unsigned char*)system_btn3_d,0,0,4427,4427,4427,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_btn3_d,Y_system_alarm_btn3_d,X_system_alarm_btn3_d+732,Y_system_alarm_btn3_d+85,0,&func_system_alarm_btn3_d};
lcd_dis_item_t t_system_alarm_btn3_u={(unsigned char*)system_btn3_u,(unsigned char*)system_btn3_u,(unsigned char*)system_btn3_u,0,0,4101,4101,4101,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_btn3_u,Y_system_alarm_btn3_u,X_system_alarm_btn3_u+732,Y_system_alarm_btn3_u+85,0,&func_system_alarm_btn3_u};
lcd_dis_item_t t_system_alarm_btn4_d={(unsigned char*)system_btn4_d,(unsigned char*)system_btn4_d,(unsigned char*)system_btn4_d,0,0,5049,5049,5049,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_btn4_d,Y_system_alarm_btn4_d,X_system_alarm_btn4_d+732,Y_system_alarm_btn4_d+85,0,&func_system_alarm_btn4_d};
lcd_dis_item_t t_system_alarm_btn4_u={(unsigned char*)system_btn4_u,(unsigned char*)system_btn4_u,(unsigned char*)system_btn4_u,0,0,4641,4641,4641,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_btn4_u,Y_system_alarm_btn4_u,X_system_alarm_btn4_u+732,Y_system_alarm_btn4_u+85,0,&func_system_alarm_btn4_u};
lcd_dis_item_t t_system_alarm_headline={(unsigned char*)system_headline,(unsigned char*)system_headline,(unsigned char*)system_headline,0,0,1038,1038,1038,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_headline,Y_system_alarm_headline,X_system_alarm_headline+861,Y_system_alarm_headline+3,0,&func_system_alarm_headline};
lcd_dis_item_t t_system_alarm_nextpage_d={(unsigned char*)system_nextpage_d,(unsigned char*)system_nextpage_d,(unsigned char*)system_nextpage_d,0,0,3882,3882,3882,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_nextpage_d,Y_system_alarm_nextpage_d,X_system_alarm_nextpage_d+120,Y_system_alarm_nextpage_d+85,0,&func_system_alarm_nextpage_d};
lcd_dis_item_t t_system_alarm_nextpage_o={(unsigned char*)system_nextpage_o,(unsigned char*)system_nextpage_o,(unsigned char*)system_nextpage_o,0,0,3413,3413,3413,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_nextpage_o,Y_system_alarm_nextpage_o,X_system_alarm_nextpage_o+120,Y_system_alarm_nextpage_o+85,0,&func_system_alarm_nextpage_o};
lcd_dis_item_t t_system_alarm_nextpage_u={(unsigned char*)system_nextpage_u,(unsigned char*)system_nextpage_u,(unsigned char*)system_nextpage_u,0,0,3567,3567,3567,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_nextpage_u,Y_system_alarm_nextpage_u,X_system_alarm_nextpage_u+120,Y_system_alarm_nextpage_u+85,0,&func_system_alarm_nextpage_u};
lcd_dis_item_t t_system_alarm_prepage_d={(unsigned char*)system_prepage_d,(unsigned char*)system_prepage_d,(unsigned char*)system_prepage_d,0,0,3474,3474,3474,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_prepage_d,Y_system_alarm_prepage_d,X_system_alarm_prepage_d+120,Y_system_alarm_prepage_d+85,0,&func_system_alarm_prepage_d};
lcd_dis_item_t t_system_alarm_prepage_o={(unsigned char*)system_prepage_o,(unsigned char*)system_prepage_o,(unsigned char*)system_prepage_o,0,0,2990,2990,2990,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_prepage_o,Y_system_alarm_prepage_o,X_system_alarm_prepage_o+120,Y_system_alarm_prepage_o+85,0,&func_system_alarm_prepage_o};
lcd_dis_item_t t_system_alarm_prepage_u={(unsigned char*)system_prepage_u,(unsigned char*)system_prepage_u,(unsigned char*)system_prepage_u,0,0,3110,3110,3110,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_system_alarm_prepage_u,Y_system_alarm_prepage_u,X_system_alarm_prepage_u+120,Y_system_alarm_prepage_u+85,0,&func_system_alarm_prepage_u};



	//面按键列表 按下
lcd_dis_item_t *p_system_alarm_item_d[SYSTEM_ALARM_ICO_NUM]=
{
 
	&t_system_alarm_headline,
  &t_system_alarm_btn1_d,
  &t_system_alarm_btn2_d,
  &t_system_alarm_btn3_d,
  &t_system_alarm_btn4_d,
  &t_system_alarm_nextpage_d,
  &t_system_alarm_prepage_d,
	&t_system_b_back_d,

};

//界面按键列表 弹起
lcd_dis_item_t *p_system_alarm_item_u[SYSTEM_ALARM_ICO_NUM]=
{
	&t_system_alarm_headline,
  &t_system_alarm_btn1_u,
  &t_system_alarm_btn2_u,
  &t_system_alarm_btn3_u,
  &t_system_alarm_btn4_u,
  &t_system_alarm_nextpage_u,//5
  &t_system_alarm_prepage_u,
	&t_system_b_back_u,
	





};

lcd_dis_item_t system_alarm_item[SYSTEM_ALARM_ICO_NUM];





u16 now_page_alarm = 0x0000;//从高到低 --1级--2级--3级--4级
u8 now_page_alarm_deep = 0x00;//当前处于哪一层

void reset_page_alarm(void)
{
  now_page_alarm = 0;
}

void alarm_info_printf(u8 num,lcd_dis_item_t* p,WARNING_CODE_LIST* p_list,u8 list_num)
{
	u8 item_num=0;
	char display_buf[64];
	lcd_dis_item_t *p_y,*p_r;
	item_num = num%4;
	switch(item_num)
	{
		case 0:
			p_r=&t_set_err_r_1;
		  p_y=&t_set_err_y_1;
			break;
	  case 1:
			p_r=&t_set_err_r_2;
		  p_y=&t_set_err_y_2;
			break;
	
		case 2:
			p_r=&t_set_err_r_3;
		  p_y=&t_set_err_y_3;
			break;
	
		case 3:
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




void display_set_alarm_info(void)
{
	//char display_buf[64];
	//lcd_dis_item_t *p;
	u16 i;//,addr;
	u8 temp;
	lcd_dis_item_t* p;
	
	p=system_alarm_item;
	sysprintf("\r\n page:%04X,%X",now_page_alarm,now_page_alarm_deep);
	if(now_page_alarm_deep==0)//第一层
	{
		
		
		for(i=0;TRUE;i++)
		{
			 if((i*0x1000)==now_page_alarm)
			 {
				 if(now_page_alarm==0x0000)
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
         Virtual_LCD_Draw_Rectangle_ARGB32(p[1].x_val,p[1].y_val,p[1].x_end_val-p[1].x_val,p[1].y_end_val-p[1].y_val,Virtual_LCDbuff2,ARGB_clear);
				 Virtual_LCD_Draw_Rectangle_ARGB32(p[2].x_val,p[2].y_val,p[2].x_end_val-p[2].x_val,p[2].y_end_val-p[2].y_val,Virtual_LCDbuff2,ARGB_clear);
				 Virtual_LCD_Draw_Rectangle_ARGB32(p[3].x_val,p[3].y_val,p[3].x_end_val-p[3].x_val,p[3].y_end_val-p[3].y_val,Virtual_LCDbuff2,ARGB_clear);
				 Virtual_LCD_Draw_Rectangle_ARGB32(p[4].x_val,p[4].y_val,p[4].x_end_val-p[4].x_val,p[4].y_end_val-p[4].y_val,Virtual_LCDbuff2,ARGB_clear);

				 if(i==0)
				 {
					p[1].key_type = KEY_TYPE_TOUCH_NONE;
					Virtual_LCD_Draw_Rectangle_ARGB32(142,90,700,24,Virtual_LCDbuff2,ARGB_clear);
					Virtual_LCD_Draw_String_ARGB_24_4bit(142,90,"Alarm Info",(0xFF78baf7),0,1,1);
				
				
				
					
					//Virtual_LCD_Draw_Rectangle_ARGB32(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
					if(waining_code_list_num>=1)
					{					
						//alarm_info_printf(display_buf,1,p[1]);		
					 //Virtual_LCD_Draw_String_ARGB_24_4bit(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
						 Virtual_LCD_Draw_String_ARGB_24_4bit(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,"                                  Clear All",(0xFFe2e2e4),0,1,1);
							p[1].key_type = KEY_TYPE_ONCE;
					}
					else
					{
						Virtual_LCD_Draw_String_ARGB_24_4bit(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,"No Fault Or Warning Information",(0xFFe2e2e4),0,1,1);
					  p[5].key_type = KEY_TYPE_TOUCH_NONE;
						 p[6].key_type = KEY_TYPE_TOUCH_NONE;
						p[5].now_status = STATUS_IDLE;
						 p[5].last_status = STATUS_IDLE;
						p[6].now_status = STATUS_IDLE;
						 p[6].last_status = STATUS_IDLE;
					}
				}
			 else
			 {
				  p[6].key_type = KEY_TYPE_ONCE;
			    p[1].key_type = KEY_TYPE_TOUCH_NONE;
				 //	Virtual_LCD_Draw_Rectangle_ARGB32(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
          temp = i*4;
				  if(waining_code_list_num>=temp)
					{					
						alarm_info_printf(temp,&p[1],waining_code_list,waining_code_list_num);		
					 // Virtual_LCD_Draw_String_ARGB_24_4bit(p[1].x_val+X_system_system_offset,p[1].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
            if(waining_code_list_num==temp)
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
				
			  temp = 1+i*4;
				if(waining_code_list_num>=temp)
				{					
					alarm_info_printf(temp,&p[2],waining_code_list,waining_code_list_num);			
          //Virtual_LCD_Draw_String_ARGB_24_4bit(p[2].x_val+X_system_system_offset,p[2].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);					
			    if(waining_code_list_num==temp)
					{
						 p[5].key_type = KEY_TYPE_TOUCH_NONE;
						p[5].now_status = STATUS_IDLE;
						 p[5].last_status = STATUS_IDLE;
						break;
					 }
				}

				//3
				temp = 2+i*4;
				//Virtual_LCD_Draw_Rectangle_ARGB32(p[3].x_val+X_system_system_offset,p[3].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
			  if(waining_code_list_num>=temp)
				{					
					alarm_info_printf(temp,&p[3],waining_code_list,waining_code_list_num);		
           //Virtual_LCD_Draw_String_ARGB_24_4bit(p[3].x_val+X_system_system_offset,p[3].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);					
			     if(waining_code_list_num==temp)
						{
						 p[5].key_type = KEY_TYPE_TOUCH_NONE;
							p[5].now_status = STATUS_IDLE;
						 p[5].last_status = STATUS_IDLE;
						break;
					 }
				}
				
				
        //4
				temp = 3+i*4;
				//Virtual_LCD_Draw_Rectangle_ARGB32(p[4].x_val+X_system_system_offset,p[4].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
				if(waining_code_list_num>=temp)
				{					
					alarm_info_printf(temp,&p[4],waining_code_list,waining_code_list_num);			
					//Virtual_LCD_Draw_String_ARGB_24_4bit(p[4].x_val+X_system_system_offset,p[4].y_val+Y_system_system_offset,display_buf,(0xFFe2e2e4),0,1,1);
          if(waining_code_list_num==temp)
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










BOOL page_system_alarm_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
  /*if(page_home.page_left_side.now_item == LEFT_SIDE_PAGE_AC)
						 {
						  if(p2->now_item == TOP_SIDE_PAGE_AC_CLIMATE)
						{
						  if(ac_ui_step==AC_PAGE_NOR)
							{
							   if(*i==19)return TRUE;
							
							}
							else if(ac_ui_step==AC_PAGE_REAR)
							{
								 if(*i==0)*i=8;
							   //if(*i==26)return TRUE;
							}
						}
						}*/
						 return FALSE;

}
///////////////////////初始化////////////////////////////////////////


void ui_system_alarm_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_SYSTEM][TOP_SIDE_PAGE_SYSTEM_ALARM];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=SYSTEM_ALARM_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only



   t_system_alarm_headline.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_alarm_btn1_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_alarm_btn2_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_alarm_btn3_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_alarm_btn4_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_system_alarm_nextpage_d.key_type = KEY_TYPE_ONCE;
   t_system_alarm_prepage_d.key_type= KEY_TYPE_ONCE;
	 t_system_b_back_d.key_type = KEY_TYPE_TOUCH_NONE;


   p->item = system_alarm_item;
   for(i=0;i<SYSTEM_ALARM_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_system_alarm_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_system_alarm_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_system_alarm_item_u[i]->size_of_pic_item ;
		
	 
	 }
 }


