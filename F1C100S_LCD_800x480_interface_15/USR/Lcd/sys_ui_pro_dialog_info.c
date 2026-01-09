#include "includes.h"





bool f_ui_disply_dialog_info = FALSE;
bool f_ui_disply_dialog_info_5 = FALSE;
bool f_ui_need_disply_dialog_info = FALSE;
//u8 now_dialog_info_select_ch = 0;//¦Ì¡À?¡ã¨°a?¨¹??¦Ì?¨ª?¡À¨ºD¨°o?
//u8 now_dialog_info_select_num = 1;//¡ä¨®1?a¨º? ¦Ì¡À?¡ã????¦Ì?¨ª¡§¦Ì¨¤


extern const unsigned char dialog_close_d[];
extern const unsigned char dialog_close_u[];

	
extern void func_dialog_close_info_d(void* p,u8 sn);
extern void func_dialog_close_info_u(void* p,u8 sn);

	
lcd_dis_item_t t_dialog_close_info_d={(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,(unsigned char*)dialog_close_d,0,0,5123,5123,5123,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_d+250,Y_dialog_close_d,X_dialog_close_d+250+230,Y_dialog_close_d+71,0,&func_dialog_close_info_d};
lcd_dis_item_t t_dialog_close_info_u={(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,(unsigned char*)dialog_close_u,0,0,4611,4611,4611,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_dialog_close_u+250,Y_dialog_close_u,X_dialog_close_u+250+230,Y_dialog_close_u+71,0,&func_dialog_close_info_u};


	//keyboard
lcd_dis_item_t *p_dialog_info_item_d[DIALOG_INFO_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_start_d,	
&t_dialog_close_info_d,

};

//
lcd_dis_item_t *p_dialog_info_item_u[DIALOG_INFO_ICO_NUM]=
{
&t_dialog_bg,
&t_dialog_start_u,
&t_dialog_close_info_u,
};

lcd_dis_item_t dialog_info_item[DIALOG_INFO_ICO_NUM];



void set_dialog_info_start_key_type(KEY_TYPE key_type)
{
   dialog_info_item[1].key_type = key_type;

}
void set_dialog_info_close_key_type(KEY_TYPE key_type)
{
   dialog_info_item[2].key_type = key_type;

}
		
		



BOOL page_dialog_info_deel_with_i(lcd_dis_page_t *p2,u8* i)
{
	return FALSE;
}



void ui_out_dialog_info(void)
{
    //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	  //Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff2,ARGB_clear);
		page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//??¦Ì?¨º??¡éD?¨°3??
}


extern u8 upgrade_info_len1;
extern u8 upgrade_info_len2;
extern u8 upgrade_info_len3;
extern char upgrade_info1[48];
extern char upgrade_info2[48];
extern char upgrade_info3[48];









void disply_info(bool upgrade)
{
	lcd_dis_page_t *p;
//	u8 i;
//	u8 num ;
	//num = waining_info_list_num;
	static u8 old_upgrade_info1[48];
	static u8 old_upgrade_info2[48];
	static u8 old_upgrade_info3[48];
	
//	char display_buf[64];
	p = &page_home.page_dialog_info;	
	
	if((memcmp(&upgrade_info1,&old_upgrade_info1,36)||upgrade))
  {
     memcpy(&old_upgrade_info1,&upgrade_info1,36);
		//sysprintf("\r\n8888888888888888888888888555");
		Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val+30,p->item[0].y_val+150,700,24,Virtual_LCDbuff2,ARGB_clear);
		       // if(upgrade_info_len1>36)
						//upgrade_info_len1 = 36;
					
         // if(upgrade_info_len1!=0)	
					{						
					   upgrade_info1[47]='\0';
	          Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+100,p->item[0].y_val+150,(char*)upgrade_info1,ARGB_yellow,0,1,1);
	        }
					
					if(upgrade==FALSE)
		 Virtual_LCD_Upgrate_formx1y1(p->item[0].x_val+30,p->item[0].y_val+150,700,24);
	}
	
	if((memcmp(&upgrade_info2,&old_upgrade_info2,36)||upgrade))
  {
     memcpy(&old_upgrade_info2,&upgrade_info2,36);
		//sysprintf("\r\n88888888888886688888555");
		
		Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val+30,p->item[0].y_val+200,700,24,Virtual_LCDbuff2,ARGB_clear);
		       // if(upgrade_info_len2>36)
						//upgrade_info_len2 = 36;
					
          //if(upgrade_info_len2!=0)	
					{						
					   upgrade_info2[47]='\0';
	          Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+100,p->item[0].y_val+200,(char*)upgrade_info2,ARGB_yellow,0,1,1);
	        }
					
					if(upgrade==FALSE)
		 Virtual_LCD_Upgrate_formx1y1(p->item[0].x_val+30,p->item[0].y_val+200,700,24);
	}
	
	if((memcmp(&upgrade_info3,&old_upgrade_info3,36)||upgrade))
  {
     memcpy(&old_upgrade_info3,&upgrade_info3,36);
		
		Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val+30,p->item[0].y_val+250,700,24,Virtual_LCDbuff2,ARGB_clear);
//sysprintf("\r\n8888888888888668888844");
					
         // if(upgrade_info_len3>48)
					//	upgrade_info_len3 = 48;
					
          //if(upgrade_info_len3!=0)	
					{						
					   upgrade_info3[47]='\0';
	          Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+100,p->item[0].y_val+250,(char*)upgrade_info3,ARGB_yellow,0,1,1);
	        }
					
					if(upgrade==FALSE)
		 Virtual_LCD_Upgrate_formx1y1(p->item[0].x_val+30,p->item[0].y_val+250,700,24);
	}
}








void ui_disply_dialog_info(void)
{
	lcd_dis_page_t *p;
	u8 i;
//	u8 num ;
	//num = waining_info_list_num;
//	char display_buf[64];
	p = &page_home.page_dialog_info;	
 //sysprintf("\r\n eeeeeeeeeeeeeee");
  //Virtual_LCD_Clear_ARGB32(Virtual_LCDbuff3,ARGB_clear);
	//Virtual_LCD_Draw_Rectangle_ARGB32(0,280,1024,320,Virtual_LCDbuff1,ARGB_clear);
	Virtual_LCD_Draw_Rectangle_ARGB32(p->item[0].x_val,p->item[0].y_val,p->item[0].x_end_val-p->item[0].x_val,p->item[0].y_end_val-p->item[0].y_val,Virtual_LCDbuff2,ARGB_clear);
  f_ui_disply_dialog_info = TRUE;

		
	Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+315,p->item[0].y_val+30,"Upgrade",0xFF82c2ff,0,1,1);
	
					/*
					if(upgrade_info_len1>36)
						upgrade_info_len1 = 36;
					
          if(upgrade_info_len1!=0)	
					{						
					   upgrade_info1[upgrade_info_len1-1]='\0';
	          Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+400-upgrade_info_len1*6,p->item[0].y_val+150,upgrade_info1,ARGB_yellow,0,1,1);
	        }
					
					if(upgrade_info_len2>36)
						upgrade_info_len2 = 36;
					
          if(upgrade_info_len2!=0)	
					{						
					   upgrade_info2[upgrade_info_len2-1]='\0';
	          Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+400-upgrade_info_len2*6,p->item[0].y_val+200,upgrade_info2,ARGB_yellow,0,1,1);
	        }
					
					if(upgrade_info_len3>36)
						upgrade_info_len3 = 36;
					
          if(upgrade_info_len3!=0)	
					{						
					   upgrade_info3[upgrade_info_len3-1]='\0';
	          Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->item[0].x_val+400-upgrade_info_len3*6,p->item[0].y_val+250,upgrade_info3,ARGB_yellow,0,1,1);
	        }
	
	*/
	disply_info(TRUE);
					
					
	 for(i=0;i<p->item_num;i++)
	 {
		 if(page_dialog_info_deel_with_i(p,&i))
							 break;
			
		 //sysprintf("\r\n i:%d",i);
		 if(p->item[i].now_status==STATUS_SELECT)	
		 png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item_select,p->item[i].size_of_pic_item_select,Virtual_LCDbuff1);
		 else
		 png_dis_xy(p->item[i].x_val,p->item[i].y_val,p->item[i].pic_item,p->item[i].size_of_pic_item,Virtual_LCDbuff1);	
	 }
	 //char_input_len =0;
	 //disply_char_input_val(TRUE);
	 //disply_info_name(TRUE);
   Virtual_LCD_Upgrate();
	 
}


///////////////////////3?¨º??¡¥////////////////////////////////////////


void ui_dialog_info_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_dialog_info;
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=DIALOG_INFO_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


   t_dialog_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_dialog_close_info_d.key_type = KEY_TYPE_ONCE;
   t_dialog_start_d.key_type = KEY_TYPE_ONCE;
	 
	 
   p->item = dialog_info_item;
   for(i=0;i<DIALOG_INFO_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_dialog_info_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_dialog_info_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_dialog_info_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	 f_ui_disply_dialog_info = FALSE;
 }


