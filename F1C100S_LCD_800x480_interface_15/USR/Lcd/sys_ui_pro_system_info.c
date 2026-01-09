#include "includes.h"

extern const unsigned char system_b_back_u[];
extern void func_system_info_ble_code(void* p,u8 sn);
lcd_dis_item_t t_system_info_ble_code={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_ONCE,STATUS_IDLE,STATUS_IDLE,X_system_info_ble_code,Y_system_info_ble_code,X_system_info_ble_code+110,Y_system_info_ble_code+50,0,&func_system_info_ble_code};

	//面按键列表 按下
lcd_dis_item_t *p_system_info_item_d[SYSTEM_INFO_ICO_NUM]=
{
 
	&t_system_headline,
	&t_system_b_back_d,
	&t_system_info_code_d,
	//&t_system_info_ble_code,
	//&t_system_info_control_upgrade_d,
	&t_system_info_screen_upgrade_d,

};

//界面按键列表 弹起
lcd_dis_item_t *p_system_info_item_u[SYSTEM_INFO_ICO_NUM]=
{
	&t_system_headline,
	&t_system_b_back_u,
	&t_system_info_code_u,
	//&t_system_info_ble_code,
	//&t_system_info_control_upgrade_u,
	&t_system_info_screen_upgrade_u,
	





};

lcd_dis_item_t system_info_item[SYSTEM_INFO_ICO_NUM];





#define X_info_offset 25
#define Y_info_offset 36
#define Y_info_next_offset 24//42

#define X_retract_offset 32//退格


void display_set_info_info(bool upgrade)
{
	char display_buf[64];
	
	
	if(upgrade)
	{		

			 Virtual_LCD_Draw_String_ARGB_24_4bit(MAIN_AREA_X+X_info_offset,90,"Info",(0xFF78baf7),0,1,1);
		
		  //
		  sprintf(display_buf,"BLE module:");
		  Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*2,display_buf,(ARGB_mydarkcyan),0,1,1);
		
	   	sprintf(display_buf,"BLE Name: LINKSWELLiRV-%c%c%c%c%c%c%c%c%c%c%c%c",BT_MAC_STR[0],BT_MAC_STR[1],BT_MAC_STR[2],BT_MAC_STR[3],BT_MAC_STR[4],BT_MAC_STR[5],BT_MAC_STR[6],BT_MAC_STR[7],BT_MAC_STR[8],BT_MAC_STR[9],BT_MAC_STR[10],BT_MAC_STR[11]);
			Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*3,display_buf,(0xFFe2e2e4),0,1,1);
		
	    sprintf(display_buf,"BLE Connect Code: ");
		  Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*4,display_buf,(0xFFe2e2e4),0,1,1);
		  sprintf(display_buf," %04X ",code_connect);
			Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset+160,MAIN_AREA_Y+Y_info_offset+2+Y_info_next_offset*4,display_buf,(ARGB_mydarkcyan),0,1,1);

			 
    sprintf(display_buf,"RV Central Control Screen:");
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*5,display_buf,(ARGB_mydarkcyan),0,1,1);
    Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*6,VERSION_STR,(0xFFe2e2e4),0,1,1);		
    Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*7,MCU_VERSION_STR,(0xFFe2e2e4),0,1,1);
		
		sprintf(display_buf,"12 Channel Central Control Unit:");	
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*8,display_buf,(ARGB_mydarkcyan),0,1,1);
		
		
		Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*9,CONTROL_MCU_VERSION_STR,(0xFFe2e2e4),0,1,1);
     Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*10,CONTROL_SECOND_MCU_VERSION_STR,(0xFFe2e2e4),0,1,1);

  	
	 if(External_key_MCU_VERSION_STR[18]!='\0')
	 {
		       sprintf(display_buf,"Button Expansion Box:");
		       Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*11,display_buf,(ARGB_mydarkcyan),0,1,1);
			     Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*12,External_key_MCU_VERSION_STR,(0xFFe2e2e4),0,1,1);
	 }
	else if(External_protocol_MCU_VERSION_STR[23]!='\0')
	{
		       sprintf(display_buf,"Communication Conversion Box:");
				       Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*11,display_buf,(ARGB_mydarkcyan),0,1,1);

			     Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*12,External_protocol_MCU_VERSION_STR,(0xFFe2e2e4),0,1,1);
	}		

				if((External_protocol_MCU_VERSION_STR[23]!='\0')&&(External_key_MCU_VERSION_STR[18]!='\0'))
				{
					sprintf(display_buf,"Communication Conversion Box:");
				Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*13,display_buf,(ARGB_mydarkcyan),0,1,1);

			  Virtual_LCD_Draw_String_ARGB_16_4bit(MAIN_AREA_X+X_info_offset+X_retract_offset,MAIN_AREA_Y+Y_info_offset+Y_info_next_offset*14,External_protocol_MCU_VERSION_STR,(0xFFe2e2e4),0,1,1);
				}
	}
}










BOOL page_system_info_deel_with_i(lcd_dis_page_t *p2,u8* i)
{

	return FALSE;

}
///////////////////////初始化////////////////////////////////////////


void ui_system_info_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_SYSTEM][TOP_SIDE_PAGE_SYSTEM_INFO];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=SYSTEM_INFO_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only



   t_system_headline.key_type = KEY_TYPE_TOUCH_NONE;
	 t_system_b_back_d.key_type = KEY_TYPE_TOUCH_NONE;
	 t_system_info_screen_upgrade_d.key_type = KEY_TYPE_ONCE;
	 t_system_info_control_upgrade_d.key_type = KEY_TYPE_ONCE;
   t_system_info_code_d.key_type = KEY_TYPE_ONCE;

   p->item = system_info_item;
   for(i=0;i<SYSTEM_INFO_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_system_info_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_system_info_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_system_info_item_u[i]->size_of_pic_item ;
	 
	 }
 }


