#include "includes.h"

    
//¾¯¸æµ¯´°ÆôÓÃ
bool warm_dialog_enable_flag =0;

#define warning_dialog_item_num 2
lcd_dis_item_t *p_warning_dialog_item_u[warning_dialog_item_num]={
        &t_Alarm_bk,    //
        &t_Alarm_bk_close,

};

lcd_dis_item_t *p_warning_dialog_item_d[warning_dialog_item_num]={
        &t_Alarm_bk,    //
        &t_Alarm_bk_close_d,

};						 
lcd_dis_item_t p_warning_dialog_item[2];


void ui_warning_dialog_init(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][7]; //¸¸Ò³Ãæ
	p->fat_page = NULL; //¸¸Ò³Ãæ¸¸Ò³ÃæÎª¿Õ£»
	
	p->pic_back_g = t_background_2.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_2.size_of_pic_item;// backgroud pic size
    
    
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=warning_dialog_item_num;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
    
	t_Alarm_bk.key_type=KEY_TYPE_TOUCH_NONE;
    t_Alarm_bk_close_d.key_type=KEY_TYPE_ONCE;
//	
	p->item = p_warning_dialog_item;
	for(i=0;i<warning_dialog_item_num;i++)
	{ 
		memcpy(&(p->item[i]),p_warning_dialog_item_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_warning_dialog_item_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_warning_dialog_item_u[i]->size_of_pic_item ;
	}

}
#define warm_dialog_t_x 210
extern u8 waining_code_list_num;
extern u8 warning_dialog_list_item;
void disply_dialogr_process(bool upgrade)
{
    
	static DiseHeaterSystem old_DiseHeater_status;   
	char display_buf[64];
	lcd_dis_item_t *p;
  	lcd_dis_item_t *p4;
	lcd_dis_item_t *p1;


        p1=&t_Alarm_bk;
    



  if(v_ui_disply_dialog_msg_type == DIALOG_MSG_TYPE_OVERRIDE_KEY)
	{
//		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+320,p->item[0].y_val+50,"Info",0xFF82c2ff,0,1,1);
//                   snprintf(display_buf, sizeof(display_buf), "Info");//
        
       Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(((p1->x_end_val+p1->x_val)>>1),p1->y_val+25,"Info",ARGB_white,0,1,1);


   if(f_override_key)
	 {
      sprintf(display_buf,"Local Override Activated");
	 }
	 else
	 {
		 sprintf(display_buf,"Local Override Deactivated");
	 }
      Virtual_LCD_Draw_String_ARGB_24_4bit(250, 200, display_buf, ARGB_white, 0, 1, 1);


	
	} 
	else if(v_ui_disply_dialog_msg_type == DIALOG_MSG_TYPE_MOTOR_WARNING)
	{

       Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(((p1->x_end_val+p1->x_val)>>1),p1->y_val+25,"CAUTION",ARGB_white,0,1,1);

        
        		                   snprintf(display_buf, sizeof(display_buf), "Ensure the RV is securely parked and the parking ");//
		      Virtual_LCD_Draw_String_ARGB_16_4bit(warm_dialog_t_x, 200+30*0-30*2, display_buf, ARGB_white, 0, 1, 1);
        		                   snprintf(display_buf, sizeof(display_buf), "brake is engaged before using the slide-out or");//
		      Virtual_LCD_Draw_String_ARGB_16_4bit(warm_dialog_t_x, 200+30*1-30*2, display_buf, ARGB_white, 0, 1, 1);        
                
                		                   snprintf(display_buf, sizeof(display_buf), "Ensure there are no obstacles or people around when");//
		      Virtual_LCD_Draw_String_ARGB_16_4bit(warm_dialog_t_x, 200+30*2-30*2, display_buf, ARGB_white, 0, 1, 1);
        		                   snprintf(display_buf, sizeof(display_buf), "operating the slide-out or awning");//
		      Virtual_LCD_Draw_String_ARGB_16_4bit(warm_dialog_t_x, 200+30*3-30*2, display_buf, ARGB_white, 0, 1, 1);        
               
                  		                   snprintf(display_buf, sizeof(display_buf), "Avoid using the awning in strong winds to prevent");//
		      Virtual_LCD_Draw_String_ARGB_16_4bit(warm_dialog_t_x, 200+30*4-30*2, display_buf, ARGB_white, 0, 1, 1);
        		                   snprintf(display_buf, sizeof(display_buf), "damage or accidents");//
		      Virtual_LCD_Draw_String_ARGB_16_4bit(warm_dialog_t_x, 200+30*5-30*2, display_buf, ARGB_white, 0, 1, 1);              
        
       
		                  		                   snprintf(display_buf, sizeof(display_buf), "Do not place too many items in the slide-out space to");//
		      Virtual_LCD_Draw_String_ARGB_16_4bit(warm_dialog_t_x, 200+30*6-30*2, display_buf, ARGB_white, 0, 1, 1);
        		                   snprintf(display_buf, sizeof(display_buf), "avoid overloading and affecting its operation");//
		      Virtual_LCD_Draw_String_ARGB_16_4bit(warm_dialog_t_x, 200+30*7-30*2, display_buf, ARGB_white, 0, 1, 1);              
        
		
			
	}
	
	
	else if(v_ui_disply_dialog_msg_type == DIALOG_MSG_TYPE_HANDBREAK_WARNING)
	{
        Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(((p1->x_end_val+p1->x_val)>>1),p1->y_val+25,"CAUTION",ARGB_white,0,1,1);

        Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(((p1->x_end_val+p1->x_val)>>1),200,"Park Brake Is Not Engaged",ARGB_white,0,1,1);
        Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(((p1->x_end_val+p1->x_val)>>1),230,"Please Check!",ARGB_white,0,1,1);


			
	}



}

