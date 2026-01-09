#include "includes.h"

extern const unsigned char system_b_back_u[];

	
	
	//面按键列表 按下
lcd_dis_item_t *p_system_diagnostics_item_d[SYSTEM_DIAGNOSTICS_ICO_NUM]=
{
 
	&t_diagnostics_clear_d,
	&t_diagnostics_start_d,	
	&t_system_b_back_d,
	&t_diagnostics_network_bg,
	&t_diagnostics_output_bg,
  &t_diagnostics_sensor_bg,

};

//界面按键列表 弹起
lcd_dis_item_t *p_system_diagnostics_item_u[SYSTEM_DIAGNOSTICS_ICO_NUM]=
{
	&t_diagnostics_clear_u,
	&t_diagnostics_start_u,	
	&t_system_b_back_u,
	&t_diagnostics_network_bg,
	&t_diagnostics_output_bg,
  &t_diagnostics_sensor_bg,

};

lcd_dis_item_t system_diagnostics_item[SYSTEM_DIAGNOSTICS_ICO_NUM];





#define X_info_offset 25
#define Y_info_offset 36
#define Y_info_next_offset 24//42

#define X_retract_offset 32//退格


bool f_diagnostics_on =FALSE;



#define Y_next_offset_diagn_network 20
#define Y_next_offset_diagn 24
#define X_offset_diagn 5
#define Y_offset_diagn 15
	
	char display_buf0[]="Undiagnosed";
	char display_buf1[]="Checking";
	char display_buf2[]="Normal";
	char display_buf3[]="No Connect";	
	
	char display_buf4[]="fault";

	
char*display_p[4]=
{
display_buf3,display_buf1,display_buf2,display_buf4
};
u32 display_color[4]=
{
   ARGB_mygray,ARGB_white,ARGB_green,ARGB_yellow
};

char network_buf0[]="12 Channel Central Control Unit";
char network_buf1[]="RV Central Control Display";
char network_buf2[]="Communication Conversion Box";
char network_buf3[]="Inverter Charger";
char network_buf4[]="Solar Charger";
char network_buf5[]="DC -DC Charger";
char network_buf6[]="DC Battery Charger with MPPT";

char*display_network_p[7]=
{
  network_buf0,
	network_buf1,
	network_buf2,
	network_buf3,
	network_buf4,
	network_buf5,
	network_buf6,
};



char channel_buf0[]="Channel 1       10A";
char channel_buf1[]="Channel 2       10A";
char channel_buf2[]="Channel 3       10A";
char channel_buf3[]="Channel 4       10A";
char channel_buf4[]="Channel 5       10A";
char channel_buf5[]="Channel 6       10A";
char channel_buf6[]="Channel 7       10A";
char channel_buf7[]="Channel 8       10A";
char channel_buf8[]="Channel 9       30A";
char channel_buf9[]="Channel 10      30A";
char channel_buf10[]="Channel 11      30A";
char channel_buf11[]="Channel 12      30A";

char*display_channel_p[12]=
{
  channel_buf0,
	channel_buf1,
	channel_buf2,
	channel_buf3,
	channel_buf4,
	channel_buf5,
	channel_buf6,
	channel_buf7,
	channel_buf8,
	channel_buf9,
	channel_buf10,
	channel_buf11,
};

char sensor_buf0[]="Tank 1";
char sensor_buf1[]="Tank 2";
char sensor_buf2[]="Tank 3";
char sensor_buf3[]="Tank 4";
char sensor_buf4[]="Temperature 1";
char sensor_buf5[]="Temperature 2";


char*display_sensor_p[6]=
{
  sensor_buf0,
	sensor_buf1,
	sensor_buf2,
	sensor_buf3,
	sensor_buf4,
	sensor_buf5,
};


void display_diagnostics_info(bool upgrade)
{
	char display_buf[64];
	static ALL_DIAGNOST old_all_diagnostics;
	lcd_dis_item_t *p,*p2;
	u8 addr=0;
	u8 i;
	


	if((memcmp(&old_all_diagnostics,&all_diagnostics,sizeof(ALL_DIAGNOST)))||upgrade)
  {
     memcpy(&old_all_diagnostics,&all_diagnostics,sizeof(ALL_DIAGNOST));
 
     Virtual_LCD_Draw_Rectangle_ARGB32(MAIN_AREA_X,MAIN_AREA_Y,MAIN_AREA_X_END-MAIN_AREA_X,MAIN_AREA_Y_END-MAIN_AREA_Y,Virtual_LCDbuff2,ARGB_clear);
		 Virtual_LCD_Draw_String_ARGB_24_4bit(290,90,"Network",ARGB_mydarkcyan,0,1,1);
		 Virtual_LCD_Draw_String_ARGB_24_4bit(600,90,"Output",ARGB_mydarkcyan,0,1,1);
		 Virtual_LCD_Draw_String_ARGB_24_4bit(830,90,"Sensor",ARGB_mydarkcyan,0,1,1);
		
		
		 p=&t_diagnostics_start_d;		
		 Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+30,466,"Start Diagnosis",ARGB_white,0,1,1);
		 p=&t_diagnostics_clear_d;		
		 Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+30,466,"Clear Report",ARGB_white,0,1,1);
		
		
		
		 p=&t_diagnostics_idle;	
		 png_dis_xy(143,466-10,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff2);

		 p=&t_diagnostics_gray;	
		 png_dis_xy(143,466+13,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff2);

		 p=&t_diagnostics_green;	
		 png_dis_xy(360,466-10,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff2);

		 p=&t_diagnostics_red;	
		 png_dis_xy(360,466+13,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff2);
					

   Virtual_LCD_Draw_String_ARGB_16_4bit(163,466-8,"No Connect/Output",ARGB_lightGray,0,1,1);
	 Virtual_LCD_Draw_String_ARGB_16_4bit(380,466-8,"Normal/Load",ARGB_lightGray,0,1,1);
	 Virtual_LCD_Draw_String_ARGB_16_4bit(163,466+15,"Connect/Output Normal",ARGB_lightGray,0,1,1);
	 Virtual_LCD_Draw_String_ARGB_16_4bit(380,466+15,"fault",ARGB_lightGray,0,1,1);
		
		 p=&t_diagnostics_network_bg;
		
		addr=1;
		for(i=0;i<7;i++)   
		{
		  Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_offset_diagn,Y_offset_diagn+p->y_val+Y_next_offset_diagn_network*addr*2,display_network_p[i],(ARGB_white),0,1,1);
		  if(all_diagnostics.network_check_status[i]<=3)
		    Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_offset_diagn+50,Y_offset_diagn+p->y_val+Y_next_offset_diagn_network*(addr*2+1)-2,display_p[all_diagnostics.network_check_status[i]],display_color[all_diagnostics.network_check_status[i]],0,1,1);
	    else if(all_diagnostics.network_check_status[i]==0xFF)
		    Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_offset_diagn+50,Y_offset_diagn+p->y_val+Y_next_offset_diagn_network*(addr*2+1)-2,display_buf1,(ARGB_white),0,1,1);
	    
			addr++;
		}
		p=&t_diagnostics_output_bg;
		addr=2;
		for(i=0;i<12;i++)   
		{
		  Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_offset_diagn,Y_offset_diagn+p->y_val+Y_next_offset_diagn*addr,display_channel_p[i],(ARGB_white),0,1,1);
		  
			if((all_diagnostics.output_check_status[i]<4)||(all_diagnostics.output_check_status[i]==0xFF))
			{
				if(all_diagnostics.output_check_status[i]==0)
				{
					 p2=&t_diagnostics_idle;	
					

				}
				else if(all_diagnostics.output_check_status[i]==1)
				{
					 p2=&t_diagnostics_gray;	
					

				}
				else if(all_diagnostics.output_check_status[i]==2)
				{
					 p2=&t_diagnostics_green;	

				}
				else if(all_diagnostics.output_check_status[i]==3)
				{
					 p2=&t_diagnostics_red;	

				}
				if(all_diagnostics.output_check_status[i]==0xFF)
					Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_offset_diagn+140,Y_offset_diagn+p->y_val+Y_next_offset_diagn*addr,display_buf1,(ARGB_white),0,1,1);
					else
				png_dis_xy(p->x_val+X_offset_diagn+175,Y_offset_diagn+p->y_val+Y_next_offset_diagn*addr,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff2);
			}
			addr++;
		}
		p=&t_diagnostics_sensor_bg;
		addr=2;
		for(i=0;i<6;i++)   
		{
		  Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_offset_diagn,Y_offset_diagn+p->y_val+Y_next_offset_diagn*addr,display_sensor_p[i],(ARGB_white),0,1,1);
		  
			if((all_diagnostics.sensor_check_status[i]<4)||(all_diagnostics.sensor_check_status[i]==0xFF))
			{
				
				if(all_diagnostics.sensor_check_status[i]==0)
				{
					 p2=&t_diagnostics_idle;	
					

				}
				else if(all_diagnostics.sensor_check_status[i]==1)
				{
					 p2=&t_diagnostics_gray;	

				}
				else if(all_diagnostics.sensor_check_status[i]==2)
				{
					 p2=&t_diagnostics_green;	

				}
				else if(all_diagnostics.sensor_check_status[i]==3)
				{
					 p2=&t_diagnostics_red;	

				}
				if((all_diagnostics.sensor_check_status[i]==1)||(all_diagnostics.sensor_check_status[i]==0xFF))
					Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+X_offset_diagn+140,Y_offset_diagn+p->y_val+Y_next_offset_diagn*addr,display_buf1,(ARGB_white),0,1,1);
					else
				png_dis_xy(p->x_val+X_offset_diagn+175,Y_offset_diagn+p->y_val+Y_next_offset_diagn*addr,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff2);
			}
			addr++;
		}
		
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate();
	}
}




void diagnostics_pro(void)
{
	 static bool last_f_diagnostics_on = FALSE;
	 static u8 step = 0xFF;
	 static u32 IdelTime = 0;
   if(last_f_diagnostics_on!=f_diagnostics_on)
	 {		 
	    last_f_diagnostics_on = f_diagnostics_on;
		  if(f_diagnostics_on==TRUE)
			{
			  step = 0;
				ResetDelayTime(&IdelTime); 
				f_diagnostics_on = FALSE;
			}
	 
	 
	 }
	 if(CntDelayTime(&IdelTime,TIME_ONE_MS*600))
	{
		ResetDelayTime(&IdelTime);
	   switch(step)
	   {
			 case 0:
				 //all_diagnostics.network_check_status[0] = 2;
				 all_diagnostics.network_check_status[0] = 0xFF;
			   step++;
			  break;
				case 1:
				 all_diagnostics.network_check_status[0] = all_diagnostics_return.network_check_status[0];
				 all_diagnostics.network_check_status[1] = 0xFF;
			   step++;
			  break;
        case 2:
				 all_diagnostics.network_check_status[1] = all_diagnostics_return.network_check_status[1];
				 all_diagnostics.network_check_status[2] = 0xFF;
			   step++;
			  break;	
        case 3:
				 all_diagnostics.network_check_status[2] = all_diagnostics_return.network_check_status[2];
				 all_diagnostics.network_check_status[3] = 0xFF;
			   step++;
			  break;	
				case 4:
				 all_diagnostics.network_check_status[3] = all_diagnostics_return.network_check_status[3];
				 all_diagnostics.network_check_status[4] = 0xFF;
			   step++;
			  break;	
				case 5:
				 all_diagnostics.network_check_status[4] = all_diagnostics_return.network_check_status[4];
				 all_diagnostics.network_check_status[5] = 0xFF;
			   step++;
			  break;	
				case 6:
				 all_diagnostics.network_check_status[5] = all_diagnostics_return.network_check_status[5];
				 all_diagnostics.network_check_status[6] = 0xFF;
			   step++;
			  break;	
				
				case 7:
				 all_diagnostics.network_check_status[6] = all_diagnostics_return.network_check_status[6];
				 all_diagnostics.output_check_status[0] = 0xFF;
			   step++;
			  break;	
				case 8:
				 all_diagnostics.output_check_status[0] = all_diagnostics_return.output_check_status[0];
				 all_diagnostics.output_check_status[1] = 0xFF;
			   step++;
			  break;
				case 9:
				 all_diagnostics.output_check_status[1] = all_diagnostics_return.output_check_status[1];
				 all_diagnostics.output_check_status[2] = 0xFF;
			   step++;
			  break;		
        case 10:
				 all_diagnostics.output_check_status[2] = all_diagnostics_return.output_check_status[2];
				 all_diagnostics.output_check_status[3] = 0xFF;
			   step++;
			  break;
        case 11:
				 all_diagnostics.output_check_status[3] = all_diagnostics_return.output_check_status[3];
				 all_diagnostics.output_check_status[4] = 0xFF;
			   step++;
			  break;
        case 12:
				 all_diagnostics.output_check_status[4] = all_diagnostics_return.output_check_status[4];
				 all_diagnostics.output_check_status[5] = 0xFF;
			   step++;
			  break;
        case 13:
				 all_diagnostics.output_check_status[5] = all_diagnostics_return.output_check_status[5];
				 all_diagnostics.output_check_status[6] = 0xFF;
			   step++;
			  break;
case 14:
				 all_diagnostics.output_check_status[6] = all_diagnostics_return.output_check_status[6];
				 all_diagnostics.output_check_status[7] = 0xFF;
			   step++;
			  break;
case 15:
				 all_diagnostics.output_check_status[7] = all_diagnostics_return.output_check_status[7];
				 all_diagnostics.output_check_status[8] = 0xFF;
			   step++;
			  break;
case 16:
				 all_diagnostics.output_check_status[8] = all_diagnostics_return.output_check_status[8];
				 all_diagnostics.output_check_status[9] = 0xFF;
			   step++;
			  break;
case 17:
				 all_diagnostics.output_check_status[9] = all_diagnostics_return.output_check_status[9];
				 all_diagnostics.output_check_status[10] = 0xFF;
			   step++;
			  break;
case 18:
				 all_diagnostics.output_check_status[10] = all_diagnostics_return.output_check_status[10];
				 all_diagnostics.output_check_status[11] = 0xFF;
			   step++;
			  break;
case 19:
				 all_diagnostics.output_check_status[11] = all_diagnostics_return.output_check_status[11];
				 all_diagnostics.sensor_check_status[0] = 0xFF;
			   step++;
			  break;
case 20:
				 all_diagnostics.sensor_check_status[0] = all_diagnostics_return.sensor_check_status[0];
				 all_diagnostics.sensor_check_status[1] = 0xFF;
			   step++;
			  break;
case 21:
				 all_diagnostics.sensor_check_status[1] = all_diagnostics_return.sensor_check_status[1];
				 all_diagnostics.sensor_check_status[2] = 0xFF;
			   step++;
			  break;
case 22:
				 all_diagnostics.sensor_check_status[2] = all_diagnostics_return.sensor_check_status[2];
				 all_diagnostics.sensor_check_status[3] = 0xFF;
			   step++;
			  break;
case 23:
				 all_diagnostics.sensor_check_status[3] = all_diagnostics_return.sensor_check_status[3];
				 all_diagnostics.sensor_check_status[4] = 0xFF;
			   step++;
			  break;
case 24:
				 all_diagnostics.sensor_check_status[4] = all_diagnostics_return.sensor_check_status[4];
				 all_diagnostics.sensor_check_status[5] = 0xFF;
			   step++;
			  break;
case 25:
				 all_diagnostics.sensor_check_status[5] = all_diagnostics_return.sensor_check_status[5];
				 //all_diagnostics.sensor_check_status[6] = 0xFF;
			   step=0xFF;
			  break;


	 
	   }
 }
		 


}





BOOL page_system_diagnostics_deel_with_i(lcd_dis_page_t *p2,u8* i)
{

	return FALSE;

}
///////////////////////初始化////////////////////////////////////////


void ui_system_diagnostics_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_SYSTEM][TOP_SIDE_PAGE_SYSTEM_DIAGNOSTICS];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=SYSTEM_DIAGNOSTICS_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only



   t_diagnostics_network_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_diagnostics_output_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 t_diagnostics_sensor_bg.key_type = KEY_TYPE_TOUCH_NONE;
	
	 t_diagnostics_clear_d.key_type = KEY_TYPE_ONCE;
	 t_diagnostics_start_d.key_type = KEY_TYPE_ONCE;

   p->item = system_diagnostics_item;
   for(i=0;i<SYSTEM_DIAGNOSTICS_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_system_diagnostics_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_system_diagnostics_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_system_diagnostics_item_u[i]->size_of_pic_item ;
	 
	 }
 }


