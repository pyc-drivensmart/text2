#include "includes.h"

	//面按键列表 按下
lcd_dis_item_t *p_power_system_item_d[POWER_SYSTEM_ICO_NUM]=
{ 
	&t_system_headline,
};

//界面按键列表 弹起
lcd_dis_item_t *p_power_system_item_u[POWER_SYSTEM_ICO_NUM]=
{
	&t_system_headline,

};

lcd_dis_item_t power_system_item[POWER_SYSTEM_ICO_NUM];





#define X_info_offset 25
#define Y_info_offset 36
#define Y_info_next_offset 24//42

#define X_retract_offset 32//退格


void display_power_system(bool upgrade)
{
	char display_buf[64];
	
	
	if(upgrade)
	{		


		Virtual_LCD_Draw_String_ARGB_24_4bit(MAIN_AREA_X+X_info_offset,90,"Power System",(0xFF78baf7),0,1,1);
		
		  //
		sprintf(display_buf,"Battery Info:");
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*2,display_buf,(ARGB_mydarkcyan),0,1,1);
	  Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*3,Extra_device_battery_ver,(0xFFe2e2e4),0,1,1);
		
			 
    sprintf(display_buf,"Inverter Info:");
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*4,display_buf,(ARGB_mydarkcyan),0,1,1);
    Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*5,Extra_device_inverter_ver,(0xFFe2e2e4),0,1,1);		

		
		sprintf(display_buf,"Mppt Info:");	
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*6,display_buf,(ARGB_mydarkcyan),0,1,1);
		
		
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*7,Extra_device_mppt_ver,(0xFFe2e2e4),0,1,1);

    sprintf(display_buf,"DC-DC Info:");	
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*8,display_buf,(ARGB_mydarkcyan),0,1,1);
		
		
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*9,Extra_device_Dc_Dc_ver,(0xFFe2e2e4),0,1,1);

}
}










BOOL page_power_system_deel_with_i(lcd_dis_page_t *p2,u8* i)
{

	return FALSE;

}
///////////////////////初始化////////////////////////////////////////


void ui_power_system_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_POWER][TOP_SIDE_PAGE_POWER_SYSTEM];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=POWER_SYSTEM_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only



   t_system_headline.key_type = KEY_TYPE_TOUCH_NONE;


   p->item = power_system_item;
   for(i=0;i<POWER_SYSTEM_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_power_system_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_power_system_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_power_system_item_u[i]->size_of_pic_item ;
	 
	 }
 }


