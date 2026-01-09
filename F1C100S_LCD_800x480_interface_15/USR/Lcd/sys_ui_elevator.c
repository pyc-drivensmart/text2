
#include "includes.h"
#define item_NUM 2
lcd_dis_item_t *p_home_item_5_chun_u2[item_NUM]={
	&t_page2_Up_up,
	&t_page2_Down_up,
};

lcd_dis_item_t *p_home_item_5_chun_d2[item_NUM]={
	&t_page2_Up_d,
	&t_page2_Down_d,

};						 
lcd_dis_item_t home_5_chun_item2[2];


void ui_elevator_init(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][1]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_background_2.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_2.size_of_pic_item;// backgroud pic size
    
    
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=item_NUM;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	
    t_text_ELEVATOR.key_type = KEY_TYPE_TOUCH_NONE;//
    
	t_page2_Up_d.key_type = KEY_TYPE_TOUCH_KEEP;
	t_page2_Down_d.key_type = KEY_TYPE_TOUCH_KEEP;//需要持续按住才有效的按键
    
  
//	
	p->item = home_5_chun_item2;
	for(i=0;i<item_NUM;i++)
	{ 
		memcpy(&(p->item[i]),p_home_item_5_chun_d2[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_5_chun_u2[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_5_chun_u2[i]->size_of_pic_item ;
	}

    


}

bool old_state;bool old_state2;
void Elevator_Status_synchronization_SW()
{
    if((old_state!=f_ignore_handbreak)||(old_state2!=f_handbreak))//手刹检测，手刹
    {
            if(1)sysprintf(" f_ignore_handbreak=%d\r\n",f_ignore_handbreak);
          if(1)sysprintf(" f_handbreak=%d\r\n",f_handbreak);

        old_state=f_ignore_handbreak;
        old_state2=f_handbreak;

        if(f_ignore_handbreak==1)//无手刹检测
        {
            home_5_chun_item2[0].key_type = KEY_TYPE_TOUCH_KEEP;//持续按下
            home_5_chun_item2[1].key_type = KEY_TYPE_TOUCH_KEEP;    
        }
        else//检测手刹
        {
             if(f_handbreak)///有手刹
            {
            home_5_chun_item2[0].key_type = KEY_TYPE_TOUCH_KEEP;//持续按下
            home_5_chun_item2[1].key_type = KEY_TYPE_TOUCH_KEEP;    
            }
             else //无手刹
            {
            home_5_chun_item2[0].now_status=STATUS_IDLE;
            home_5_chun_item2[1].now_status=STATUS_IDLE;
            home_5_chun_item2[1].key_type = KEY_TYPE_TOUCH_NONE;//不
            home_5_chun_item2[0].key_type = KEY_TYPE_TOUCH_NONE;
                

//             home_5_chun_item2[0].key_type = KEY_TYPE_TOUCH_KEEP;//持续按下
//            home_5_chun_item2[1].key_type = KEY_TYPE_TOUCH_KEEP;    
   
            }
        }

    }

}
