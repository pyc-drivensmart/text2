#include "includes.h"







///////////////////////复用按键补充/////////////////////////////
		
extern void  func_home_loadlights2_bg(void* p,u8 sn);	
extern void func_home_light_d_ico0(void* p,u8 sn);
extern void func_home_light_d_ico1(void* p,u8 sn);
extern void func_home_light_d_ico2(void* p,u8 sn);
extern void func_home_light_d_ico3(void* p,u8 sn);
extern void func_home_light_d_ico4(void* p,u8 sn);
extern void func_home_light_d_ico5(void* p,u8 sn);
extern void func_home_light_u_ico0(void* p,u8 sn);
extern void func_home_light_u_ico1(void* p,u8 sn);
extern void func_home_light_u_ico2(void* p,u8 sn);
extern void func_home_light_u_ico3(void* p,u8 sn);
extern void func_home_light_u_ico4(void* p,u8 sn);
extern void func_home_light_u_ico5(void* p,u8 sn);
extern void func_home_ventilator_ico1(void* p,u8 sn);
extern void func_home_ventilator_ico2(void* p,u8 sn);
extern void func_home_ventilator_ico3(void* p,u8 sn);

extern const unsigned char home_loadlights_bg[3950UL + 1];	
extern const unsigned char home_light_d_ico[3459UL + 1];
extern const unsigned char home_light_u_ico[2075UL + 1];
extern const unsigned char home_ventilator_ico[3383UL + 1];

lcd_dis_item_t t_home_loadlights2_bg={(unsigned char*)home_loadlights_bg,(unsigned char*)home_loadlights_bg,(unsigned char*)home_loadlights_bg,0,0,3951,3951,3951,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_loadlights2_bg,Y_home_loadlights2_bg,X_home_loadlights2_bg+428,Y_home_loadlights2_bg+170,0,&func_home_loadlights2_bg};
lcd_dis_item_t t_home_light_d_ico0={(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,0,0,3460,3460,3460,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_d_ico0,Y_home_light_d_ico0,X_home_light_d_ico0+68,Y_home_light_d_ico0+54,0,&func_home_light_d_ico0};
lcd_dis_item_t t_home_light_d_ico1={(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,0,0,3460,3460,3460,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_d_ico1,Y_home_light_d_ico1,X_home_light_d_ico1+68,Y_home_light_d_ico1+54,0,&func_home_light_d_ico1};
lcd_dis_item_t t_home_light_d_ico2={(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,0,0,3460,3460,3460,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_d_ico2,Y_home_light_d_ico2,X_home_light_d_ico2+68,Y_home_light_d_ico2+54,0,&func_home_light_d_ico2};
lcd_dis_item_t t_home_light_d_ico3={(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,0,0,3460,3460,3460,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_d_ico3,Y_home_light_d_ico3,X_home_light_d_ico3+68,Y_home_light_d_ico3+54,0,&func_home_light_d_ico3};
lcd_dis_item_t t_home_light_d_ico4={(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,0,0,3460,3460,3460,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_d_ico4,Y_home_light_d_ico4,X_home_light_d_ico4+68,Y_home_light_d_ico4+54,0,&func_home_light_d_ico4};
lcd_dis_item_t t_home_light_d_ico5={(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,(unsigned char*)home_light_d_ico,0,0,3460,3460,3460,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_d_ico5,Y_home_light_d_ico5,X_home_light_d_ico5+68,Y_home_light_d_ico5+54,0,&func_home_light_d_ico5};
lcd_dis_item_t t_home_light_u_ico0={(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,0,0,2076,2076,2076,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_u_ico0,Y_home_light_u_ico0,X_home_light_u_ico0+68,Y_home_light_u_ico0+54,0,&func_home_light_u_ico0};
lcd_dis_item_t t_home_light_u_ico1={(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,0,0,2076,2076,2076,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_u_ico1,Y_home_light_u_ico1,X_home_light_u_ico1+68,Y_home_light_u_ico1+54,0,&func_home_light_u_ico1};
lcd_dis_item_t t_home_light_u_ico2={(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,0,0,2076,2076,2076,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_u_ico2,Y_home_light_u_ico2,X_home_light_u_ico2+68,Y_home_light_u_ico2+54,0,&func_home_light_u_ico2};
lcd_dis_item_t t_home_light_u_ico3={(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,0,0,2076,2076,2076,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_u_ico3,Y_home_light_u_ico3,X_home_light_u_ico3+68,Y_home_light_u_ico3+54,0,&func_home_light_u_ico3};
lcd_dis_item_t t_home_light_u_ico4={(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,0,0,2076,2076,2076,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_u_ico4,Y_home_light_u_ico4,X_home_light_u_ico4+68,Y_home_light_u_ico4+54,0,&func_home_light_u_ico4};
lcd_dis_item_t t_home_light_u_ico5={(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,(unsigned char*)home_light_u_ico,0,0,2076,2076,2076,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_light_u_ico5,Y_home_light_u_ico5,X_home_light_u_ico5+68,Y_home_light_u_ico5+54,0,&func_home_light_u_ico5};
lcd_dis_item_t t_home_ventilator_ico1={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_ventilator_ico1,Y_home_ventilator_ico1,X_home_ventilator_ico1+68,Y_home_ventilator_ico1+54,0,&func_home_ventilator_ico1};
lcd_dis_item_t t_home_ventilator_ico2={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_ventilator_ico2,Y_home_ventilator_ico2,X_home_ventilator_ico2+68,Y_home_ventilator_ico2+54,0,&func_home_ventilator_ico2};
lcd_dis_item_t t_home_ventilator_ico3={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_ventilator_ico3,Y_home_ventilator_ico3,X_home_ventilator_ico3+68,Y_home_ventilator_ico3+54,0,&func_home_ventilator_ico3};	
	
	
	
	
	
	
	
	
extern void func_home_load_d_ico0(void* p,u8 sn);
extern void func_home_load_d_ico1(void* p,u8 sn);
extern void func_home_load_d_ico2(void* p,u8 sn);
extern void func_home_load_d_ico3(void* p,u8 sn);
extern void func_home_load_d_ico4(void* p,u8 sn);
extern void func_home_load_d_ico5(void* p,u8 sn);
extern void func_home_load_u_ico0(void* p,u8 sn);
extern void func_home_load_u_ico1(void* p,u8 sn);
extern void func_home_load_u_ico2(void* p,u8 sn);
extern void func_home_load_u_ico3(void* p,u8 sn);
extern void func_home_load_u_ico4(void* p,u8 sn);
extern void func_home_load_u_ico5(void* p,u8 sn);

lcd_dis_item_t t_home_load_d_ico0={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_d_ico0,Y_home_load_d_ico0,X_home_load_d_ico0+68,Y_home_load_d_ico0+54,0,&func_home_load_d_ico0};
lcd_dis_item_t t_home_load_d_ico1={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_d_ico1,Y_home_load_d_ico1,X_home_load_d_ico1+68,Y_home_load_d_ico1+54,0,&func_home_load_d_ico1};
lcd_dis_item_t t_home_load_d_ico2={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_d_ico2,Y_home_load_d_ico2,X_home_load_d_ico2+68,Y_home_load_d_ico2+54,0,&func_home_load_d_ico2};
lcd_dis_item_t t_home_load_d_ico3={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_d_ico3,Y_home_load_d_ico3,X_home_load_d_ico3+68,Y_home_load_d_ico3+54,0,&func_home_load_d_ico3};
lcd_dis_item_t t_home_load_d_ico4={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_d_ico4,Y_home_load_d_ico4,X_home_load_d_ico4+68,Y_home_load_d_ico4+54,0,&func_home_load_d_ico4};
lcd_dis_item_t t_home_load_d_ico5={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_d_ico5,Y_home_load_d_ico5,X_home_load_d_ico5+68,Y_home_load_d_ico5+54,0,&func_home_load_d_ico5};
lcd_dis_item_t t_home_load_u_ico0={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_u_ico0,Y_home_load_u_ico0,X_home_load_u_ico0+68,Y_home_load_u_ico0+54,0,&func_home_load_u_ico0};
lcd_dis_item_t t_home_load_u_ico1={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_u_ico1,Y_home_load_u_ico1,X_home_load_u_ico1+68,Y_home_load_u_ico1+54,0,&func_home_load_u_ico1};
lcd_dis_item_t t_home_load_u_ico2={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_u_ico2,Y_home_load_u_ico2,X_home_load_u_ico2+68,Y_home_load_u_ico2+54,0,&func_home_load_u_ico2};
lcd_dis_item_t t_home_load_u_ico3={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_u_ico3,Y_home_load_u_ico3,X_home_load_u_ico3+68,Y_home_load_u_ico3+54,0,&func_home_load_u_ico3};
lcd_dis_item_t t_home_load_u_ico4={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_u_ico4,Y_home_load_u_ico4,X_home_load_u_ico4+68,Y_home_load_u_ico4+54,0,&func_home_load_u_ico4};
lcd_dis_item_t t_home_load_u_ico5={(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,(unsigned char*)home_ventilator_ico,0,0,3384,3384,3384,0,0,1,KEY_TYPE_NORMAL,STATUS_IDLE,STATUS_IDLE,X_home_load_u_ico5,Y_home_load_u_ico5,X_home_load_u_ico5+68,Y_home_load_u_ico5+54,0,&func_home_load_u_ico5};

		
	//空
extern void func_home_powerS_0(void* p,u8 sn);
lcd_dis_item_t t_home_powerS_0={(unsigned char*)0,(unsigned char*)0,(unsigned char*)0,0,0,0,0,0,0,0,1,KEY_TYPE_TOUCH_AND_DISPLAY_NONE,STATUS_IDLE,STATUS_IDLE,X_home_powerS_d,Y_home_powerS_d,X_home_powerS_d+109,Y_home_powerS_d+71,0,&func_home_powerS_0};

	

	
	
	
	
	//home界面按键列表 按下
lcd_dis_item_t *p_home_item_d[HOME_ICO_NUM]=
{
&t_home_inverter_d,//0
&t_home_lightsbtn_d,//1
&t_home_lightsON_d,//2
&t_home_loadbtn_d,//3
&t_home_loadON_d,//4
&t_home_POWbc_d,//5
&t_home_POWcc_d,//6
&t_home_powerbtn_d,//7
&t_home_powerS_0,//8
&t_home_POWsc_u,//9
&t_home_tankbtn_d,//10
&t_home_wpON_d,//11

&t_home_black_bg,//12
&t_home_fresh_bg,//13
&t_home_grey_bg,//14
&t_home_LPG_bg,//15

&t_home_powerscroll_bg,//16
&t_home_loadlights_bg,//17
&t_home_loads_bg,//18

&t_home_load_d_ico0,
&t_home_load_d_ico1,
&t_home_load_d_ico2,
&t_home_load_d_ico3,
&t_home_load_d_ico4,
&t_home_load_d_ico5,


&t_home_light_d_ico0,//25
&t_home_light_d_ico1,//26
&t_home_light_d_ico2,//27
&t_home_light_d_ico3,//28
&t_home_light_d_ico4,//29
&t_home_light_d_ico5,//30



};

//空调界面按键列表 弹起
lcd_dis_item_t *p_home_item_u[HOME_ICO_NUM]=
{
&t_home_inverter_u,//0
&t_home_lightsbtn_u,//1
&t_home_lightsoff_u,//2
&t_home_loadbtn_u,//3
&t_home_loadoff_u,//4
&t_home_POWbc_u,//5
&t_home_POWcc_u,//6
&t_home_powerbtn_u,//7
&t_home_powerS_0,//8
&t_home_POWsc_d,//9
&t_home_tankbtn_u,//10
&t_home_wpoff_u,//11

&t_home_black_bg,//12
&t_home_fresh_bg,//13
&t_home_grey_bg,//14
&t_home_LPG_bg,//15

&t_home_powerscroll_bg,//16
&t_home_loadlights_bg,//17
&t_home_loads_bg,//18

&t_home_load_u_ico0,
&t_home_load_u_ico1,
&t_home_load_u_ico2,
&t_home_load_u_ico3,
&t_home_load_u_ico4,
&t_home_load_u_ico5,

&t_home_light_u_ico0,//25
&t_home_light_u_ico1,//26
&t_home_light_u_ico2,//27
&t_home_light_u_ico3,//28
&t_home_light_u_ico4,//29
&t_home_light_u_ico5,//30



};

lcd_dis_item_t home_item[HOME_ICO_NUM];

u8 ICO_home_inverter_offset =0;//定义图标的位置 

bool now_in_dialog_or_keyboard_window(void)
{
   if((f_ui_disply_dialog_code)||\
		  (f_ui_disply_dialog_info)||\
	    (f_ui_disply_dialog_msg)||\
			(f_ui_disply_dialog_test)||\
	    (f_ui_disply_keyboard)||\
	    (f_ui_disply_dialog_loads)||\
	    (f_ui_disply_dialog_lights)||\
	    (f_ui_disply_dialog_motors)||\
	    (f_ui_disply_dialog_loads_ch)||\
	    (f_ui_disply_dialog_lights_ch)||\
	    (f_ui_disply_dialog_loads_ch)||\
	    (f_ui_disply_dialog_loads_ch))
		 return TRUE;
	 else
		 return FALSE;
}

void disply_home_Inverter_Mode(bool upgrade)
{
	 static u8 old_Inverter_Mode;    
	 char display_buf[32];
	 lcd_dis_item_t *p;

	  
  if(now_in_dialog_or_keyboard_window())
		return;
  if((old_Inverter_Mode !=parts_set_return_status.Inverter_Mode)||upgrade)
  {
		old_Inverter_Mode = parts_set_return_status.Inverter_Mode;	
		
		
		p=&t_home_inverter_d;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);

		switch(parts_set_return_status.Inverter_Mode)
		{
		  //case 0:
			//	sprintf(display_buf,"        OFF");
			//	break;
		  case 1:
				sprintf(display_buf,"Charger Only");
				break;
			case 2:
				sprintf(display_buf,"Inverter Only");
				break;
			case 3:
				sprintf(display_buf,"ON  ");
				break;			
			case 0:
				sprintf(display_buf,"OFF  ");
				break;
			default:
				sprintf(display_buf,"No Connect");
				break;
		}
		

		if(parts_set_return_status.Inverter_Mode<=3)
		{
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(15+((p->x_end_val+p->x_val)>>1),p->y_val+25,display_buf,ARGB_white,0,1,1);
			 p=&t_home_inverter_u;
		   home_item[ICO_home_inverter_offset].pic_item = p->pic_item;
			 home_item[ICO_home_inverter_offset].size_of_pic_item = p->size_of_pic_item;	
			 home_item[ICO_home_inverter_offset].key_type = KEY_TYPE_ONCE;
			 //home_item[ICO_home_inverter_offset].last_status = STATUS_IDLE;
			 //home_item[ICO_home_inverter_offset].now_status = STATUS_IDLE;
		}
		else
		{ 
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(15+((p->x_end_val+p->x_val)>>1),p->y_val+25,display_buf,ARGB_gray,0,1,1);
		   p=&t_home_inverter_f;
		   home_item[ICO_home_inverter_offset].pic_item = p->pic_item;
			 home_item[ICO_home_inverter_offset].size_of_pic_item = p->size_of_pic_item;	
			 home_item[ICO_home_inverter_offset].key_type = KEY_TYPE_TOUCH_NONE;
		   //home_item[ICO_home_inverter_offset].last_status = STATUS_IDLE;
			 home_item[ICO_home_inverter_offset].now_status = STATUS_IDLE;
		}
		p=&home_item[ICO_home_inverter_offset];
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
			
		
    
	}
}






#define X_home_charger_offset 68

void disply_bootster_charger_val(bool upgrade)
{
	 //if(upgrade)
  // Virtual_LCD_Draw_String_ARGB_16_4bit(X_home_POWbc_d+10,Y_home_POWbc_d+55,"       --W/--A",ARGB_mygray,0,1,1);
		
	static CHARGER_STATUS old_Booster_Charger;    
  char display_buf[32];
	lcd_dis_item_t *p;

  if((memcmp(&Booster_Charger,&old_Booster_Charger,sizeof(CHARGER_STATUS)))||upgrade)
  {
    memcpy(&old_Booster_Charger,&Booster_Charger,sizeof(CHARGER_STATUS));
		if(now_in_dialog_or_keyboard_window())
			 return;
		if(Booster_Charger.I_in)
			p=&t_home_POWbc_d;
		else
			p=&t_home_POWbc_u;
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		Virtual_LCD_Draw_String_ARGB_16_4bit(X_home_POWbc_d+10,Y_home_POWbc_d+28,"DC-DC Charger",ARGB_gray,0,1,1);
		
		
		
		if((Booster_Charger.I_in&0x8000))
		{
			sprintf(display_buf,"%dW/-%d.%dA",Booster_Charger.Power&0x7FFF,(Booster_Charger.I_in&0x7FFF)/10,(Booster_Charger.I_in&0x7FFF)%10);
		}
		else if((Booster_Charger.I_in!=0))
		{
			sprintf(display_buf,"%dW/%d.%dA",Booster_Charger.Power&0x7FFF,Booster_Charger.I_in/10,Booster_Charger.I_in%10);
		}
		else 
			sprintf(display_buf,"--/--");
		  //sprintf(display_buf,"%dW/%d.%dA",Booster_Charger.Power,Booster_Charger.I_in/10,Booster_Charger.I_in%10);
		if(Booster_Charger.I_in)
		{
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(X_home_POWbc_d+X_home_charger_offset,Y_home_POWbc_d+55,display_buf,ARGB_mygreen,0,1,1);
		}
		else
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(X_home_POWbc_d+X_home_charger_offset,Y_home_POWbc_d+55,display_buf,ARGB_mygray,0,1,1);


		
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
}

void disply_solar_charger_val(bool upgrade)
{
	// if(upgrade)
   //Virtual_LCD_Draw_String_ARGB_16_4bit(X_home_POWsc_d+10,Y_home_POWsc_d+55,"        --W/--A",ARGB_mygreen,0,1,1);
   static SOLAR_STATUS old_solar_status;   
	 char display_buf[32];
	 lcd_dis_item_t *p;

  if((memcmp(&solar_status,&old_solar_status,sizeof(SOLAR_STATUS)))||upgrade)
  {
    memcpy(&old_solar_status,&solar_status,sizeof(SOLAR_STATUS));
		if(now_in_dialog_or_keyboard_window())
			 return;
		
		if(solar_status.I_in)
			p=&t_home_POWsc_d;
		else
			p=&t_home_POWsc_u;
		 png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+18,p->y_val+28,"Solar Charger",ARGB_gray,0,1,1);
		
		
		//Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val+30,p->y_val+55,8*14,16,Virtual_LCDbuff2,ARGB_clear);
		
		if((solar_status.I_in!=0))
		sprintf(display_buf,"%dW/%d.%dA",solar_status.Power&0x7FFF,(solar_status.I_in&0x7FFF)/10,(solar_status.I_in&0x7FFF)%10);
		else 
			sprintf(display_buf,"--/--");
		if(solar_status.I_in)
		{
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(X_home_POWsc_d+X_home_charger_offset,Y_home_POWsc_d+55,display_buf,ARGB_mygreen,0,1,1);
		}
		else
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(X_home_POWsc_d+X_home_charger_offset,Y_home_POWsc_d+55,display_buf,ARGB_mygray,0,1,1);


		
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
}

void disply_combiCHG_val(bool upgrade)
{
	 //if(upgrade)
   //Virtual_LCD_Draw_String_ARGB_16_4bit(X_home_POWcc_d+10,Y_home_POWcc_d+55,"        --W/--A",ARGB_mygray,0,1,1);
	
	
	static CHARGER_STATUS old_Combi_CHG;    
	static INVERTER_STATUS old_Inverter_status;  
  char display_buf[32];
	lcd_dis_item_t *p;
	u16 temp_I,temp_pow;

  if((memcmp(&Combi_CHG,&old_Combi_CHG,sizeof(CHARGER_STATUS)))||\
		(old_Inverter_status.mode!=Inverter_status.mode)||\
	(old_Inverter_status.P_o!=Inverter_status.P_o)||\
	(old_Inverter_status.I_o!=Inverter_status.I_o)||upgrade)
  {
    memcpy(&old_Combi_CHG,&Combi_CHG,sizeof(CHARGER_STATUS));
		old_Inverter_status.mode=Inverter_status.mode;
	  old_Inverter_status.P_o=Inverter_status.P_o;
	  old_Inverter_status.I_o=Inverter_status.I_o;
		
		if(now_in_dialog_or_keyboard_window())
			 return;
		
		if(Is_Inverter_mode_Inverting())//inverter
		{
			 temp_I = Inverter_status.I_o;
			 temp_pow =Inverter_status.P_o;
		   //temp_pow = ((Inverter_status.I_o&0x7FFF)*Inverter_status.V_o)/100;
			 //if(temp_pow>0xFFFF)
				//temp_pow = 0xFFFF;
		   
		}
		else
		{
			 temp_I = Combi_CHG.I_in;
		   temp_pow = Combi_CHG.Power;
		}
		
		if(temp_I)
			p=&t_home_POWcc_d;
		else
			p=&t_home_POWcc_u;
		 png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		if(Is_Inverter_mode_Inverting())//inverter
			Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+28,p->y_val+28,"AC Loads",ARGB_gray,0,1,1);
			else
		Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+22,p->y_val+28,"AC Charger",ARGB_gray,0,1,1);
		
		
		if((temp_I!=0))
		  sprintf(display_buf,"%dW/%d.%dA",(temp_pow&0x7FFF),(temp_I&0x7FFF)/10,(temp_I&0x7FFF)%10);
		else 
			sprintf(display_buf,"--/--");
			if(temp_I)
		{
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(X_home_POWcc_d+X_home_charger_offset,Y_home_POWcc_d+55,display_buf,ARGB_mygreen,0,1,1);
		}
		else
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(X_home_POWcc_d+X_home_charger_offset,Y_home_POWcc_d+55,display_buf,ARGB_mygray,0,1,1);

	 
		
		
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}

}




u8 home_display_lights_ch[MAX_DIAPLAY_NUM] = {0,1,0x02,0x03,9,0x0A};
u8 home_display_loads_ch[MAX_DIAPLAY_NUM] = {0x10,0x11,0x12,0x13,0x14,0x15};

u16 home_display_lights_ch_X[MAX_DIAPLAY_NUM] ={X_home_loadlights_bg+18,X_home_loadlights_bg+159,X_home_loadlights_bg+302,X_home_loadlights_bg+18,X_home_loadlights_bg+159,X_home_loadlights_bg+302};
u16 home_display_lights_ch_Y[MAX_DIAPLAY_NUM] ={Y_home_loadlights_bg+60,Y_home_loadlights_bg+60,Y_home_loadlights_bg+60,Y_home_loadlights_bg+140,Y_home_loadlights_bg+140,Y_home_loadlights_bg+140};
u16 home_display_loads_ch_X[MAX_DIAPLAY_NUM] ={X_home_loadlights2_bg+18,X_home_loadlights2_bg+159,X_home_loadlights2_bg+302,X_home_loadlights2_bg+18,X_home_loadlights2_bg+159,X_home_loadlights2_bg+302};
u16 home_display_loads_ch_Y[MAX_DIAPLAY_NUM] ={Y_home_loadlights2_bg+60,Y_home_loadlights2_bg+60,Y_home_loadlights2_bg+60,Y_home_loadlights2_bg+140,Y_home_loadlights2_bg+140,Y_home_loadlights2_bg+140};

#define X_home_loadlights_nane_offset 50

lcd_dis_item_t *p_home_lights_item_d[MAX_DIAPLAY_NUM]=
{
&home_item[25],//25
&home_item[26],//26
&home_item[27],//27
&home_item[28],//28
&home_item[29],//29
&home_item[30],//30
};
lcd_dis_item_t *p_home_loads_item_d[MAX_DIAPLAY_NUM]=
{
&home_item[19],
&home_item[20],
&home_item[21],
&home_item[22],
&home_item[23],
&home_item[24],
};



void set_home_loads_item_key_type(void)
{
	u8 i;
	u8 ch=0;
	
	for(i=0;i<MAX_DIAPLAY_NUM;i++)
	{
   if(f_override_key==FALSE)
	 {
		  ch = home_display_loads_ch[i];
		 //sysprintf("\r\n switch_ch_list_return[ch]:%d",switch_ch_list_return[ch]);
		   if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>24))
			 {
				 
		     p_home_loads_item_d[i]->key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			 }
			 else
			 {
			   p_home_loads_item_d[i]->key_type = KEY_TYPE_NORMAL;
			 }
		}	
    else	 
		{
		
		   ch = home_display_loads_ch[i];
		 //sysprintf("\r\n switch_ch_list_return[ch]:%d",switch_ch_list_return[ch]);
		   if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>24))
			 {
				 
		     p_home_loads_item_d[i]->key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			 }
			 else
			 {
			   p_home_loads_item_d[i]->key_type = KEY_TYPE_TOUCH_NONE;
			 }
		}

	}
}

void set_home_lights_item_key_type(void)
{
	u8 i;
	u8 ch=0;
	
	for(i=0;i<MAX_DIAPLAY_NUM;i++)
	{
    if(f_override_key==FALSE)
	  {
		   ch = home_display_lights_ch[i];
		   if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>24))
			 {
		     p_home_lights_item_d[i]->key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			 }
			 else
			 {
			   p_home_lights_item_d[i]->key_type = KEY_TYPE_NORMAL;
			 }	
		}	
    else	
		{
		  ch = home_display_lights_ch[i];
		   if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>24))
			 {
		     p_home_lights_item_d[i]->key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			 }
			 else
			 {
			   p_home_lights_item_d[i]->key_type = KEY_TYPE_TOUCH_NONE;
			 }	
		}			

	}
}


u16 home_lights_x_val_offset[6] = {117,117+140,117+140+140,117,117+140,117+140+140};//428*170
u16 home_lights_y_val_offset[6] = {10,10,10,95,95,95};
void disply_home_ch_name(bool upgrade)
{
	#if 1
	u8 i;
	u32 display_color;
//	char display_buf[32];
	lcd_dis_item_t *p,*p2,*p3;
	if(upgrade)
	{
		p = &t_home_loadlights_bg;
		p2 = &t_home_loads_bg;
				if(upgrade==FALSE)
				{
					for(i=0;i<6;i++)
					{
					  Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val+home_lights_x_val_offset[i],p->y_val+home_lights_y_val_offset[i],50,32,Virtual_LCDbuff2,ARGB_clear);
					  Virtual_LCD_Draw_Rectangle_ARGB32(p2->x_val+home_lights_x_val_offset[i],p2->y_val+home_lights_y_val_offset[i],50,32,Virtual_LCDbuff2,ARGB_clear);
					}
				}

				display_color = 0xFF838697;
				if(f_override_key)
				{
				//	lcd_dis_item_t *p;
				p3=&t_key_locked1;
				for(i=0;i<6;i++)
        {					
				  png_dis_xy(p->x_val+home_lights_x_val_offset[i],p->y_val+home_lights_y_val_offset[i],p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff2);
			    png_dis_xy(p2->x_val+home_lights_x_val_offset[i],p2->y_val+home_lights_y_val_offset[i],p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff2);
        }
					
				//	sprintf(display_buf,"lock");	
				//	Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+380,p->y_val+10,display_buf,display_color,0,1,1);
				//	Virtual_LCD_Draw_String_ARGB_16_4bit(p2->x_val+380,p2->y_val+10,display_buf,display_color,0,1,1);

				}

				if(upgrade==FALSE)
				{
					for(i=0;i<6;i++)
					{	
						 Virtual_LCD_Upgrate_formx1y1(p->x_val+home_lights_x_val_offset[i],p->y_val+home_lights_y_val_offset[i],50,32);
						 Virtual_LCD_Upgrate_formx1y1(p2->x_val+home_lights_x_val_offset[i],p2->y_val+home_lights_y_val_offset[i],50,32);
					}
					// Virtual_LCD_Upgrate();
				}
		}   
	 #endif

}
void disply_light_name(bool upgrade)
{
	u8 i,j;
	u8 ch=0;
	u8 txt_temp[NAME_TXT_MAX_LEN];
	u16 x_val=0;
	static SWITCH_NAME_LIST old_switch_name_list_return[SWITCH_NAME_CH_NUM];
	//if(upgrade)
	{
	  for(i=0;i<6;i++)
	  {
	    ch = home_display_lights_ch[i];
			if((upgrade)||(memcmp(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST))))
			{
				memcpy(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST));
				
				if(now_in_dialog_or_keyboard_window())
				return;
				if(upgrade==FALSE)
				Virtual_LCD_Draw_Rectangle_ARGB32(home_display_lights_ch_X[i],home_display_lights_ch_Y[i],120,32,Virtual_LCDbuff2,ARGB_clear);
				
				if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>24))
				{
				}
				else
				{
					x_val=0;
					for(j=0;j<NAME_TXT_MAX_LEN;j++)
					{
					
					txt_temp[j]=switch_name_list_return[ch].txt[j];
					if(switch_name_list_return[ch].txt[j]=='\0')
						break;
					x_val+=(glyph_dsc_16_4bit_bold[switch_name_list_return[ch].txt[j]-0x20].adv_w*1);//计算字符宽度
					if(x_val>(140-10))//160
					{
						txt_temp[j]='\0';
						//if(switch_name_list_return[ch].txt[j]=='\0')
						break;
					}
					}
					if(p_home_lights_item_d[i]->now_status==STATUS_SELECT)
					{
					Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(home_display_lights_ch_X[i]+X_home_loadlights_nane_offset,home_display_lights_ch_Y[i],\
						(char*)txt_temp,ARGB_myorange,0,1,1);
					}
					else
					{
						Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(home_display_lights_ch_X[i]+X_home_loadlights_nane_offset,home_display_lights_ch_Y[i],\
						(char*)txt_temp,ARGB_mygray,0,1,1);	
					}
			  }
				
				if(upgrade==FALSE)
				{
					Virtual_LCD_Upgrate_formx1y1(home_display_lights_ch_X[i],home_display_lights_ch_Y[i],120,32);
					// Virtual_LCD_Upgrate();
				}
			}
	  }
	}
}

void disply_load_name(bool upgrade)
{
	u8 i,j;
	u8 ch=0;
	u8 txt_temp[NAME_TXT_MAX_LEN];
	u16 x_val=0;
	static SWITCH_NAME_LIST old_switch_name_list_return[SWITCH_NAME_CH_NUM];
	//if(upgrade)
	{
	  for(i=0;i<6;i++)
	  {
	    ch = home_display_loads_ch[i];
			if((upgrade)||(memcmp(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST))))
			{
					memcpy(&old_switch_name_list_return[ch],&switch_name_list_return[ch],sizeof(SWITCH_NAME_LIST));
				
			 if(now_in_dialog_or_keyboard_window())
			 return;
				if(upgrade==FALSE)
				Virtual_LCD_Draw_Rectangle_ARGB32(home_display_loads_ch_X[i],home_display_loads_ch_Y[i],120,32,Virtual_LCDbuff2,ARGB_clear);
			  if((switch_ch_list_return[ch]==0)||(switch_ch_list_return[ch]>24))
				{
				}
				else
				{
					x_val=0;
						for(j=0;j<NAME_TXT_MAX_LEN;j++)
					 {
						 
						 txt_temp[j]=switch_name_list_return[ch].txt[j];
						 if(switch_name_list_return[ch].txt[j]=='\0')
							 break;
						 x_val+=(glyph_dsc_16_4bit_bold[switch_name_list_return[ch].txt[j]-0x20].adv_w*1);//计算字符宽度
						 if(x_val>(140-10))//160
						 {
							 txt_temp[j]='\0';
							 //if(switch_name_list_return[ch].txt[j]=='\0')
							 break;
						 }
					 }
					//sysprintf("\r\nnow_status:,%d,%d",p_home_lights_item_d[i]->now_status,i);
					if(p_home_loads_item_d[i]->now_status==STATUS_SELECT)
					{
						Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(home_display_loads_ch_X[i]+X_home_loadlights_nane_offset,home_display_loads_ch_Y[i],\
						(char*)txt_temp,0xFF82c2ff,0,1,1);
					}
					else
					{
						Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(home_display_loads_ch_X[i]+X_home_loadlights_nane_offset,home_display_loads_ch_Y[i],\
						(char*)txt_temp,ARGB_mygray,0,1,1);
					}
			  }
				if(upgrade==FALSE)
				{
					 Virtual_LCD_Upgrate_formx1y1(home_display_loads_ch_X[i],home_display_loads_ch_Y[i],120,32);
					// Virtual_LCD_Upgrate();
				}
			}
			
	
	  }
}
	

}


extern TANK_SET_STATUS* Tank_set_return_status[TANK_DIS_NUM];
void disply_tanks_status(u8 type,bool upgrage)
{
  static u8 old_val_fresh[TANK_DIS_NUM]={0,0,0,0};
	static u8 old_Tank_type[TANK_DIS_NUM]={0xFF,0xFF,0xFF,0xFF};
	static u8 old_Tank_sensor_type[TANK_DIS_NUM]={0,0,0,0};
	static u16 old_Tank_val_max[TANK_DIS_NUM]={0,0,0,0};
	lcd_dis_item_t *p,*p2,*p3,*p_xy,*p_xy2,*p_xy3;
	u8 offet = 0;
	u8 val_temp =0;
	u8 i,same_tank_type_cnt = 0,same_tank_type_cnt_all=0;
	char display_buf[16];
	char *dipPtype;
  TANK_SET_STATUS* p_Tank_set_return_status;

	switch(type) 
	{
	  case TANK1:
			//取坐标位置
      p_xy = &t_home_fresh_bg;
		  p_xy2 = &t_home_fresh_100;
		  p_xy3 = &t_home_fresh_wave;
			p_Tank_set_return_status= Tank_set_return_status[type];
		  val_temp = val_status.val_tank1;
      break;
		case TANK2:
			p_xy=&t_home_grey_bg;
		  p_xy2 = &t_home_grey_100;
	  	p_xy3 = &t_home_grey_wave;
		  p_Tank_set_return_status= Tank_set_return_status[type];
		  val_temp = val_status.val_tank2;
		  //dipPtype = "Grey";
			break;
		case TANK3:
			p_xy=&t_home_black_bg;
		  p_xy2 = &t_home_black_100;
		  p_xy3 = &t_home_black_wave;
		  p_Tank_set_return_status= Tank_set_return_status[type];
		  val_temp = val_status.val_tank3;
		  //dipPtype = "Black";
			break;
		case TANK4:
			p_xy=&t_home_LPG_bg;
		  p_xy2 = &t_home_LPG_100;
		  p_xy3 = &t_home_LPG_wave;
		  p_Tank_set_return_status= Tank_set_return_status[type];
		  val_temp = val_status.val_tank4;
		  //dipPtype = "LPG";
			break;
		default:
			return;
			//break;
				
	}
		for(i=0;i<TANK_DIS_NUM;i++)
		{
			 if(p_Tank_set_return_status->Tank_type == Tank_set_return_status[i]->Tank_type)
			 {
				 if(i<type)
			   same_tank_type_cnt++;	
				 
				 same_tank_type_cnt_all++;	
			 }
		}

	if((val_temp!=old_val_fresh[type])||(p_Tank_set_return_status->Tank_type!=old_Tank_type[type])||(p_Tank_set_return_status->Tank_sensor_type!=old_Tank_sensor_type[type])||(p_Tank_set_return_status->val_max!=old_Tank_val_max[type])||(upgrage))
	{
     old_val_fresh[type] = val_temp;
		 /*if(old_Tank_type[type] != p_Tank_set_return_status->Tank_type)
		 {
			 for(i=0;i<TANK_DIS_NUM;i++)
			 {
			   old_Tank_type[i]=0xFF;
			 }
		 }*/
		 old_Tank_type[type] = p_Tank_set_return_status->Tank_type;
		 old_Tank_sensor_type[type] = p_Tank_set_return_status->Tank_sensor_type;
		 old_Tank_val_max[type] = p_Tank_set_return_status->val_max;
		
		
     if(now_in_dialog_or_keyboard_window())
			 return;
		 
		 
		 	if(p_Tank_set_return_status->Tank_type==1)
			{
			  p= &t_home_fresh_bg;
		    p2 = &t_home_fresh_100;
		    p3 = &t_home_fresh_wave;
				if(same_tank_type_cnt_all<=1)
				  dipPtype = "Fresh";
				else if(same_tank_type_cnt==3)
					 dipPtype = "Fresh4";
				else if(same_tank_type_cnt==2)
					 dipPtype = "Fresh3";
				else if(same_tank_type_cnt==1)
					 dipPtype = "Fresh2";
				else if(same_tank_type_cnt==0)
					 dipPtype = "Fresh1";
			}
			else if(p_Tank_set_return_status->Tank_type==2)
			{
			  p= &t_home_grey_bg;
		    p2 = &t_home_grey_100;
		    p3 = &t_home_grey_wave;
					if(same_tank_type_cnt_all<=1)
				  dipPtype = "Grey";
				else if(same_tank_type_cnt==3)
					 dipPtype = "Grey4";
				else if(same_tank_type_cnt==2)
					 dipPtype = "Grey3";
				else if(same_tank_type_cnt==1)
					 dipPtype = "Grey2";
				else if(same_tank_type_cnt==0)
					 dipPtype = "Grey1";
			}	
      else if(p_Tank_set_return_status->Tank_type==3)
			{
			  p= &t_home_black_bg;
		    p2 = &t_home_black_100;
		    p3 = &t_home_black_wave;
				if(same_tank_type_cnt_all<=1)
				  dipPtype = "Waste";
				else if(same_tank_type_cnt==3)
					 dipPtype = "Waste4";
				else if(same_tank_type_cnt==2)
					 dipPtype = "Waste3";
				else if(same_tank_type_cnt==1)
					 dipPtype = "Waste2";
				else if(same_tank_type_cnt==0)
					 dipPtype = "Waste1";
			}	
			else if(p_Tank_set_return_status->Tank_type==4)
			{
			  p= &t_home_LPG_bg;
		    p2 = &t_home_LPG_100;
		    p3 = &t_home_LPG_wave;
				if(same_tank_type_cnt_all<=1)
				  dipPtype = "LPG";
				else if(same_tank_type_cnt==3)
					 dipPtype = "LPG4";
				else if(same_tank_type_cnt==2)
					 dipPtype = "LPG3";
				else if(same_tank_type_cnt==1)
					 dipPtype = "LPG2";
				else if(same_tank_type_cnt==0)
					 dipPtype = "LPG1";
			}	
			else
			{
			  p= &t_home_black_bg;
		    p2 = &t_home_black_100;
		    p3 = &t_home_black_wave;
				
				if(same_tank_type_cnt_all<=1)
				  dipPtype = "Null";
				else if(same_tank_type_cnt==3)
					 dipPtype = "Null4";
				else if(same_tank_type_cnt==2)
					 dipPtype = "Null3";
				else if(same_tank_type_cnt==1)
					 dipPtype = "Null2";
				else if(same_tank_type_cnt==0)
					 dipPtype = "Null1";
			}
			
	   png_dis_xy(p_xy->x_val,p_xy->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		 Virtual_LCD_Draw_Rectangle_ARGB32(p_xy->x_val,p_xy->y_val,p_xy->x_end_val-p_xy->x_val,p_xy->y_end_val-p_xy->y_val,Virtual_LCDbuff2,ARGB_clear);
		
		
		//if (val_temp==0xFF)	
		//{}
		//else 
		if((val_temp&0x7F)>=95)
		{
			png_dis_xy(p_xy2->x_val,p_xy2->y_val,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		}
		else if((val_temp&0x7F)<=5)
		{
			//do nothing
		}
		else
		{
		offet = 140-(val_temp&0x7F)*140/100;
		
	  //png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		png_dis_xy_form_x1y1_to_x2y2(p_xy2->x_val,p_xy2->y_val+offet,\
                                	p2->pic_item,p2->size_of_pic_item,\
		                              0,offet,\
	                                p_xy2->x_end_val-p_xy2->x_val,p_xy2->y_end_val-p_xy2->y_val,\
																	0,0,\
																	Virtual_LCDbuff1);
		
		//p=&t_home_fresh_wave;
	   png_dis_xy(p_xy3->x_val,p_xy3->y_val+offet,p3->pic_item,p3->size_of_pic_item,Virtual_LCDbuff1);
		}
		    
		Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p_xy->x_val+50,p_xy->y_val+116,dipPtype,ARGB_white,0,1,1);
		
		if((base_return_status.uint&0x03)==0x01)
				{

					sprintf(display_buf,"(%dGal)",p_Tank_set_return_status->val_max);
				}
				else
				{
		      sprintf(display_buf,"(%dL)",p_Tank_set_return_status->val_max);				}
		
		Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p_xy->x_val+50,p_xy->y_val+140,display_buf,0xFFAAAAAA,0,1,1);
		
		//Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val+67,16*6,32,Virtual_LCDbuff2,ARGB_clear);
					
			/*		
		if(val_temp>=100)
		{
			sprintf(display_buf,"100");
			display_buf[3] = '%';
			display_buf[4] = ' ';
			display_buf[5] = ' ';
			display_buf[6] = '\0';
			Virtual_LCD_Draw_String_ARGB_32_4bit_bold(p_xy->x_val+15,p_xy->y_val+67,display_buf,ARGB_white,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"%02d",val_temp);
		  display_buf[2] = '%';
			display_buf[3] = ' ';
			display_buf[4] = ' ';
			display_buf[5] = '\0';
			Virtual_LCD_Draw_String_ARGB_32_4bit_bold(p_xy->x_val+25,p_xy->y_val+67,display_buf,ARGB_white,0,1,1);
		
		}*/
		if((p_Tank_set_return_status->Tank_type==0)||((val_temp&0x80)==0x80))//tank1_set_status.Tank_sensor_type
		{
		
		    sprintf(display_buf,"--");
				Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+50,p_xy->y_val+67,display_buf,ARGB_white,0,1,1);
		}
		else
		{				
			if(p_Tank_set_return_status->Tank_sensor_type==1)
			{
				if((val_temp&0x7F)>=75)
				{
				  sprintf(display_buf,"Full");
          Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p_xy->x_val+50,p_xy->y_val+67,display_buf,ARGB_white,0,1,1);					
				}
				else if((val_temp&0x7F)>=50)
				{
				  sprintf(display_buf,"2/3");	
					Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+50,p_xy->y_val+67,display_buf,ARGB_white,0,1,1);
				}
				else if((val_temp&0x7F)>=25)
				{
				  sprintf(display_buf,"1/3");	
					Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+50,p_xy->y_val+67,display_buf,ARGB_white,0,1,1);
				}
				else 
				{
			    sprintf(display_buf,"Empty");
				  Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p_xy->x_val+50,p_xy->y_val+67,display_buf,ARGB_white,0,1,1);		
				}
				
			}
      else		
			{
				sprintf(display_buf,"%d%%",(val_temp&0x7F));
				Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(p_xy->x_val+50,p_xy->y_val+67,display_buf,ARGB_white,0,1,1);	
			}				
				
  	}
		
		
		
		
		if(upgrage==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p_xy->x_val,p_xy->y_val,p_xy->x_end_val-p_xy->x_val,p_xy->y_end_val-p_xy->y_val);
	}  

}


void disply_all_changer_status(bool upgrade)
{
  static BATTERY_STATUS old_assi1_battery_status;  
	u8 val_temp = 0;
	  lcd_dis_item_t *p,*p2;
  u16 offset;
	u32 dis_color = ARGB_white;
	char display_buf[16];
	//char *dipPtype;


	if((memcmp(&assi1_battery_status,&old_assi1_battery_status,sizeof(BATTERY_STATUS)))||upgrade)
  {
    memcpy(&old_assi1_battery_status,&assi1_battery_status,sizeof(BATTERY_STATUS));
		val_temp = assi1_battery_status.Q;
		
		 if(now_in_dialog_or_keyboard_window())
			 return;
		 
		 
		 if(assi1_battery_status.f_time_changer)
		 {
			 /*if(val_temp>50)
			 {
					p=&t_home_powerscroll_ch_bg;
				  p2=&t_home_powerscroll_ch_f;
			 }
			 else if(val_temp>25)
			 {
					p=&t_home_powerscroll_ch_y_bg;
				  p2=&t_home_powerscroll_ch_f_y;
			 }
			 else
			 {
					p=&t_home_powerscroll_ch_r_bg;
				  p2=&t_home_powerscroll_ch_f_r;
			 }
			 */
			 if(val_temp>=90)
			 {					
					p=&t_home_powerscroll_ch_bg;
				  p2=&t_home_powerscroll_ch_f;
			 }
			 else if(val_temp>50)
			 {					
					p=&t_home_powerscroll_ch_75_bg;
				  p2=&t_home_powerscroll_ch_f;//
			 }
			 else if(val_temp>25)
			 {
					p=&t_home_powerscroll_ch_y_bg;
				  p2=&t_home_powerscroll_ch_f_y;
			 }
			 else
			 {
					p=&t_home_powerscroll_ch_r_bg;
				  p2=&t_home_powerscroll_ch_f_r;
			 }
	   }
		else
		{
		 
			 if(val_temp>=90)
			 {					
					p=&t_home_powerscroll_bg;
				  p2=&t_home_powerscroll_f;
			 }
			 else if(val_temp>50)
			 {					
					p=&t_home_powerscroll_75_bg;
				  p2=&t_home_powerscroll_f_75;
			 }
			 else if(val_temp>25)
			 {
					p=&t_home_powerscroll_y_bg;
				  p2=&t_home_powerscroll_f_y;
			 }
			 else
			 {
					p=&t_home_powerscroll_r_bg;
				  p2=&t_home_powerscroll_f_r;
			 }
			
		}
				 
		 Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		
	   png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		
		

		offset = val_temp*416/100;
		 if(offset>416)
			 offset = 416;

		
		png_dis_xy_form_x1y1_to_x2y2(p2->x_val,p2->y_val,\
                                	p2->pic_item,p2->size_of_pic_item,\
		                              0,0,\
	                                offset,p2->y_end_val-p2->y_val,\
																	0,0,\
																	Virtual_LCDbuff1);



		 
		//Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+160,p->y_val+18,"Battery",ARGB_white,0,1,1);
		
		//Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val+160,p->y_val+18,8*15,16+20,Virtual_LCDbuff2,ARGB_clear);
		
		if(assi1_battery_status.I&0x8000)
		sprintf(display_buf,"Battery: -%dW/%d.%dV/-%d.%dA",(assi1_battery_status.V*(assi1_battery_status.I&0x7FFF))/100,(assi1_battery_status.V)/10,(assi1_battery_status.V)%10,(assi1_battery_status.I&0x7FFF)/10,(assi1_battery_status.I&0x7FFF)%10);
		else
		sprintf(display_buf,"Battery: %dW/%d.%dV/%d.%dA",(assi1_battery_status.V*(assi1_battery_status.I&0x7FFF))/100,(assi1_battery_status.V)/10,(assi1_battery_status.V)%10,(assi1_battery_status.I&0x7FFF)/10,(assi1_battery_status.I&0x7FFF)%10);
		Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+140,p->y_val+18,display_buf,ARGB_white,0,1,1);
		
		
		if(assi1_battery_status.f_time_changer)
		{
			if(assi1_battery_status.time==0xFFFF)
			{
			  sprintf(display_buf,"Time to Full: --d --h");	 
				dis_color = ARGB_white;
			}
			else if(assi1_battery_status.time==0xFFFE)
			{
			  sprintf(display_buf,"No Capacity Set");	
				dis_color = ARGB_yellow;
			}	
		  else if(assi1_battery_status.time>=1440)
			{
			  sprintf(display_buf,"Time to Full: %dd %dh",assi1_battery_status.time/1440,(assi1_battery_status.time%1440)/60);
				dis_color = ARGB_white;
			}
		  else if(assi1_battery_status.time==0)
			{
				sprintf(display_buf,"Battery fully charged");
				dis_color = ARGB_white;
			}
		  else
			{
				sprintf(display_buf,"Time to Full: %dh %dm",(assi1_battery_status.time%1440)/60,(assi1_battery_status.time%1440)%60);
				dis_color = ARGB_white;
			}
			
			Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+140,p->y_val+18+20,display_buf,dis_color,0,1,1);
		}
		else
		{
			if(assi1_battery_status.time==0xFFFF)
			{
			  sprintf(display_buf,"Time to Full: --d --h");	
				dis_color = ARGB_white;
			}	
      else if(assi1_battery_status.time==0xFFFE)
			{
			  sprintf(display_buf,"No Capacity Set");	
				dis_color = ARGB_yellow;
			}				
		  else if(assi1_battery_status.time>=1440)
			{
			  sprintf(display_buf,"Time to Empty: %dd %dh",assi1_battery_status.time/1440,(assi1_battery_status.time%1440)/60);
				dis_color = ARGB_white;
			}
		  else
			{
				sprintf(display_buf,"Time to Empty: %dh %dm",(assi1_battery_status.time%1440)/60,(assi1_battery_status.time%1440)%60);
				dis_color = ARGB_white;
			}
			Virtual_LCD_Draw_String_ARGB_16_4bit(p->x_val+140,p->y_val+18+20,display_buf,dis_color,0,1,1);
		}
		
		//Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val+10,24*6,48,Virtual_LCDbuff2,ARGB_clear);
		if(val_temp>=100)
		{
			sprintf(display_buf,"100");
			display_buf[3] = '%';
			display_buf[4] = ' ';
			display_buf[5] = ' ';
			display_buf[6] = '\0';
			Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val+15,p->y_val+15,display_buf,ARGB_white,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"%02d",val_temp);
		  display_buf[2] = '%';
			display_buf[3] = ' ';
			display_buf[4] = ' ';
			display_buf[5] = '\0';
			Virtual_LCD_Draw_String_ARGB_48_4bit_bold(p->x_val+25,p->y_val+15,display_buf,ARGB_white,0,1,1);
		
		}
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}  

}


BOOL page_home_deel_with_i(lcd_dis_page_t *p2,u8* i)
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

lcd_dis_item_t *home_lights_d_ico_select_list[7]=
{
	&t_home_light_d_ico,
	&t_home_rightside_d_ico,
	&t_home_interior_d_ico,
	&t_home_awning_d_ico,
	&t_home_rightside_d_ico,//t_home_rightside_u_ico,
	&t_home_underbody_ico,
	&t_home_rearwork_d_ico,
	
};
lcd_dis_item_t *home_lights_u_ico_select_list[7]=
{
	&t_home_light_u_ico,
	&t_home_rightside_u_ico,
	&t_home_interior_u_ico,
	&t_home_awning_u_ico,
	&t_home_rightside_u_ico,//t_home_rightside_u_ico,
	&t_home_underbody_u_ico,
	&t_home_rearwork_u_ico,
	
};

lcd_dis_item_t *home_lights_d_ico_list[6]=
{
	&t_home_light_d_ico,
	&t_home_light_d_ico,
	&t_home_light_d_ico,
	&t_home_light_d_ico,
	&t_home_light_d_ico,
	&t_home_light_d_ico,
};
lcd_dis_item_t *home_lights_u_ico_list[6]=
{
	&t_home_light_u_ico,
	&t_home_light_u_ico,
	&t_home_light_u_ico,
	&t_home_light_u_ico,
	&t_home_light_u_ico,
	&t_home_light_u_ico,
};

void init_home_lights_ico_para(void)
{
	u8 i;

	
	for(i=0;i<6;i++)
	{
		 lights_light_d_ico_select_p[i] = switch_name_list_return[lights_display_lights_ch[i]].icon_select;
	   home_lights_d_ico_list[i] = home_lights_d_ico_select_list[lights_light_d_ico_select_p[i]];
		 home_lights_u_ico_list[i] = home_lights_u_ico_select_list[lights_light_d_ico_select_p[i]];	
	}
	
   memcpy(&t_home_light_d_ico0,home_lights_d_ico_list[0],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_d_ico1,home_lights_d_ico_list[1],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_d_ico2,home_lights_d_ico_list[2],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_d_ico3,home_lights_d_ico_list[3],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_d_ico4,home_lights_d_ico_list[4],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_d_ico5,home_lights_d_ico_list[5],sizeof(lcd_dis_item_t));


	 memcpy(&t_home_light_u_ico0,home_lights_u_ico_list[0],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_u_ico1,home_lights_u_ico_list[1],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_u_ico2,home_lights_u_ico_list[2],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_u_ico3,home_lights_u_ico_list[3],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_u_ico4,home_lights_u_ico_list[4],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_light_u_ico5,home_lights_u_ico_list[5],sizeof(lcd_dis_item_t));

	 
	 t_home_light_d_ico0.f = &func_home_light_d_ico0;
	 t_home_light_d_ico1.f = &func_home_light_d_ico1;
	 t_home_light_d_ico2.f = &func_home_light_d_ico2;
	 t_home_light_d_ico3.f = &func_home_light_d_ico3;
	 t_home_light_d_ico4.f = &func_home_light_d_ico4;
	 t_home_light_d_ico5.f = &func_home_light_d_ico5;

	

	 t_home_light_u_ico0.f = &func_home_light_u_ico0;
	 t_home_light_u_ico1.f = &func_home_light_u_ico1;
	 t_home_light_u_ico2.f = &func_home_light_u_ico2;
	 t_home_light_u_ico3.f = &func_home_light_u_ico3;
	 t_home_light_u_ico4.f = &func_home_light_u_ico4;
	 t_home_light_u_ico5.f = &func_home_light_u_ico5;

	
	 
	
	 t_home_light_d_ico0.x_end_val = X_home_light_d_ico0+t_home_light_d_ico0.x_end_val-t_home_light_d_ico0.x_val;
	 t_home_light_d_ico0.y_end_val = Y_home_light_d_ico0+t_home_light_d_ico0.y_end_val-t_home_light_d_ico0.y_val;
   t_home_light_d_ico0.x_val     = X_home_light_d_ico0;
	 t_home_light_d_ico0.y_val     = Y_home_light_d_ico0;
	 
	 t_home_light_d_ico1.x_end_val = X_home_light_d_ico1+t_home_light_d_ico1.x_end_val-t_home_light_d_ico1.x_val;
	 t_home_light_d_ico1.y_end_val = Y_home_light_d_ico1+t_home_light_d_ico1.y_end_val-t_home_light_d_ico1.y_val;
   t_home_light_d_ico1.x_val     = X_home_light_d_ico1;
	 t_home_light_d_ico1.y_val     = Y_home_light_d_ico1;
	 
	 t_home_light_d_ico2.x_end_val = X_home_light_d_ico2+t_home_light_d_ico2.x_end_val-t_home_light_d_ico2.x_val;
	 t_home_light_d_ico2.y_end_val = Y_home_light_d_ico2+t_home_light_d_ico2.y_end_val-t_home_light_d_ico2.y_val;
   t_home_light_d_ico2.x_val     = X_home_light_d_ico2;
	 t_home_light_d_ico2.y_val     = Y_home_light_d_ico2;
	 
	 t_home_light_d_ico3.x_end_val = X_home_light_d_ico3+t_home_light_d_ico3.x_end_val-t_home_light_d_ico3.x_val;
	 t_home_light_d_ico3.y_end_val = Y_home_light_d_ico3+t_home_light_d_ico3.y_end_val-t_home_light_d_ico3.y_val;
   t_home_light_d_ico3.x_val     = X_home_light_d_ico3;
	 t_home_light_d_ico3.y_val     = Y_home_light_d_ico3;
	 
	 t_home_light_d_ico4.x_end_val = X_home_light_d_ico4+t_home_light_d_ico4.x_end_val-t_home_light_d_ico4.x_val;
	 t_home_light_d_ico4.y_end_val = Y_home_light_d_ico4+t_home_light_d_ico4.y_end_val-t_home_light_d_ico4.y_val;
   t_home_light_d_ico4.x_val     = X_home_light_d_ico4;
	 t_home_light_d_ico4.y_val     = Y_home_light_d_ico4;
	 
	 t_home_light_d_ico5.x_end_val = X_home_light_d_ico5+t_home_light_d_ico5.x_end_val-t_home_light_d_ico5.x_val;
	 t_home_light_d_ico5.y_end_val = Y_home_light_d_ico5+t_home_light_d_ico5.y_end_val-t_home_light_d_ico5.y_val;
   t_home_light_d_ico5.x_val     = X_home_light_d_ico5;
	 t_home_light_d_ico5.y_val     = Y_home_light_d_ico5;
	 
	 t_home_light_u_ico0.x_end_val = X_home_light_u_ico0+t_home_light_u_ico0.x_end_val-t_home_light_u_ico0.x_val;
	 t_home_light_u_ico0.y_end_val = Y_home_light_u_ico0+t_home_light_u_ico0.y_end_val-t_home_light_u_ico0.y_val;
   t_home_light_u_ico0.x_val     = X_home_light_u_ico0;
	 t_home_light_u_ico0.y_val     = Y_home_light_u_ico0;
	 
	 t_home_light_u_ico1.x_end_val = X_home_light_u_ico1+t_home_light_u_ico1.x_end_val-t_home_light_u_ico1.x_val;
	 t_home_light_u_ico1.y_end_val = Y_home_light_u_ico1+t_home_light_u_ico1.y_end_val-t_home_light_u_ico1.y_val;
   t_home_light_u_ico1.x_val     = X_home_light_u_ico1;
	 t_home_light_u_ico1.y_val     = Y_home_light_u_ico1;
	 
	 t_home_light_u_ico2.x_end_val = X_home_light_u_ico2+t_home_light_u_ico2.x_end_val-t_home_light_u_ico2.x_val;
	 t_home_light_u_ico2.y_end_val = Y_home_light_u_ico2+t_home_light_u_ico2.y_end_val-t_home_light_u_ico2.y_val;
   t_home_light_u_ico2.x_val     = X_home_light_u_ico2;
	 t_home_light_u_ico2.y_val     = Y_home_light_u_ico2;
	 
	 t_home_light_u_ico3.x_end_val = X_home_light_u_ico3+t_home_light_u_ico3.x_end_val-t_home_light_u_ico3.x_val;
	 t_home_light_u_ico3.y_end_val = Y_home_light_u_ico3+t_home_light_u_ico3.y_end_val-t_home_light_u_ico3.y_val;
   t_home_light_u_ico3.x_val     = X_home_light_u_ico3;
	 t_home_light_u_ico3.y_val     = Y_home_light_u_ico3;
	 
	 t_home_light_u_ico4.x_end_val = X_home_light_u_ico4+t_home_light_u_ico4.x_end_val-t_home_light_u_ico4.x_val;
	 t_home_light_u_ico4.y_end_val = Y_home_light_u_ico4+t_home_light_u_ico4.y_end_val-t_home_light_u_ico4.y_val;
   t_home_light_u_ico4.x_val     = X_home_light_u_ico4;
	 t_home_light_u_ico4.y_val     = Y_home_light_u_ico4;
	 
	 t_home_light_u_ico5.x_end_val = X_home_light_u_ico5+t_home_light_u_ico5.x_end_val-t_home_light_u_ico5.x_val;
	 t_home_light_u_ico5.y_end_val = Y_home_light_u_ico5+t_home_light_u_ico5.y_end_val-t_home_light_u_ico5.y_val;
   t_home_light_u_ico5.x_val     = X_home_light_u_ico5;
	 t_home_light_u_ico5.y_val     = Y_home_light_u_ico5;
	 

}

void Upgrade_home_item(void)
{
	 lcd_dis_page_t *p;
	 u8 i;
	 init_home_lights_ico_para();
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][0];
   p->item = home_item;
   for(i=25;i<31;i++)
	 {
	   memcpy(&(p->item[i]),p_home_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_home_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_home_item_u[i]->size_of_pic_item ;
	 
	 }
	 set_home_lights_item_key_type();
 }
//////////////////////////////////////////////////////////////////////////
 lcd_dis_item_t *home_loads_d_ico_select_list[8]=
{

&t_home_ventilator_d,//20	
&t_home_fridge_d,//23	
&t_home_kv_d,
&t_home_ac_d,
&t_home_mw_d,
&t_home_TV_d,
&t_home_wm_d,
&t_home_wp_d,


	
};
lcd_dis_item_t *home_loads_u_ico_select_list[8]=
{
&t_home_ventilator_u,//20	
&t_home_fridge_ico,//23	
&t_home_kv_u,
&t_home_ac_u,
&t_home_mw_u,
&t_home_TV_u,
&t_home_wm_u,
&t_home_wp_u,
};

lcd_dis_item_t *home_loads_d_ico_list[6]=
{
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
};
lcd_dis_item_t *home_loads_u_ico_list[6]=
{
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
	&t_home_ventilator_ico,
};

void init_home_loads_ico_para(void)
{
	u8 i;

	
	for(i=0;i<6;i++)
	{
		 loads_load_d_ico_select_p[i] = switch_name_list_return[loads_display_loads_ch[i]].icon_select;
	   home_loads_d_ico_list[i] = home_loads_d_ico_select_list[loads_load_d_ico_select_p[i]];
		 home_loads_u_ico_list[i] = home_loads_u_ico_select_list[loads_load_d_ico_select_p[i]];	
	}
	
   memcpy(&t_home_load_d_ico0,home_loads_d_ico_list[0],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_d_ico1,home_loads_d_ico_list[1],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_d_ico2,home_loads_d_ico_list[2],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_d_ico3,home_loads_d_ico_list[3],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_d_ico4,home_loads_d_ico_list[4],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_d_ico5,home_loads_d_ico_list[5],sizeof(lcd_dis_item_t));


	 memcpy(&t_home_load_u_ico0,home_loads_u_ico_list[0],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_u_ico1,home_loads_u_ico_list[1],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_u_ico2,home_loads_u_ico_list[2],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_u_ico3,home_loads_u_ico_list[3],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_u_ico4,home_loads_u_ico_list[4],sizeof(lcd_dis_item_t));
	 memcpy(&t_home_load_u_ico5,home_loads_u_ico_list[5],sizeof(lcd_dis_item_t));

	 
	 t_home_load_d_ico0.f = &func_home_load_d_ico0;
	 t_home_load_d_ico1.f = &func_home_load_d_ico1;
	 t_home_load_d_ico2.f = &func_home_load_d_ico2;
	 t_home_load_d_ico3.f = &func_home_load_d_ico3;
	 t_home_load_d_ico4.f = &func_home_load_d_ico4;
	 t_home_load_d_ico5.f = &func_home_load_d_ico5;

	

	 t_home_load_u_ico0.f = &func_home_load_u_ico0;
	 t_home_load_u_ico1.f = &func_home_load_u_ico1;
	 t_home_load_u_ico2.f = &func_home_load_u_ico2;
	 t_home_load_u_ico3.f = &func_home_load_u_ico3;
	 t_home_load_u_ico4.f = &func_home_load_u_ico4;
	 t_home_load_u_ico5.f = &func_home_load_u_ico5;

	
	 
	
	 t_home_load_d_ico0.x_end_val = X_home_load_d_ico0+t_home_load_d_ico0.x_end_val-t_home_load_d_ico0.x_val;
	 t_home_load_d_ico0.y_end_val = Y_home_load_d_ico0+t_home_load_d_ico0.y_end_val-t_home_load_d_ico0.y_val;
   t_home_load_d_ico0.x_val     = X_home_load_d_ico0;
	 t_home_load_d_ico0.y_val     = Y_home_load_d_ico0;
	 
	 t_home_load_d_ico1.x_end_val = X_home_load_d_ico1+t_home_load_d_ico1.x_end_val-t_home_load_d_ico1.x_val;
	 t_home_load_d_ico1.y_end_val = Y_home_load_d_ico1+t_home_load_d_ico1.y_end_val-t_home_load_d_ico1.y_val;
   t_home_load_d_ico1.x_val     = X_home_load_d_ico1;
	 t_home_load_d_ico1.y_val     = Y_home_load_d_ico1;
	 
	 t_home_load_d_ico2.x_end_val = X_home_load_d_ico2+t_home_load_d_ico2.x_end_val-t_home_load_d_ico2.x_val;
	 t_home_load_d_ico2.y_end_val = Y_home_load_d_ico2+t_home_load_d_ico2.y_end_val-t_home_load_d_ico2.y_val;
   t_home_load_d_ico2.x_val     = X_home_load_d_ico2;
	 t_home_load_d_ico2.y_val     = Y_home_load_d_ico2;
	 
	 t_home_load_d_ico3.x_end_val = X_home_load_d_ico3+t_home_load_d_ico3.x_end_val-t_home_load_d_ico3.x_val;
	 t_home_load_d_ico3.y_end_val = Y_home_load_d_ico3+t_home_load_d_ico3.y_end_val-t_home_load_d_ico3.y_val;
   t_home_load_d_ico3.x_val     = X_home_load_d_ico3;
	 t_home_load_d_ico3.y_val     = Y_home_load_d_ico3;
	 
	 t_home_load_d_ico4.x_end_val = X_home_load_d_ico4+t_home_load_d_ico4.x_end_val-t_home_load_d_ico4.x_val;
	 t_home_load_d_ico4.y_end_val = Y_home_load_d_ico4+t_home_load_d_ico4.y_end_val-t_home_load_d_ico4.y_val;
   t_home_load_d_ico4.x_val     = X_home_load_d_ico4;
	 t_home_load_d_ico4.y_val     = Y_home_load_d_ico4;
	 
	 t_home_load_d_ico5.x_end_val = X_home_load_d_ico5+t_home_load_d_ico5.x_end_val-t_home_load_d_ico5.x_val;
	 t_home_load_d_ico5.y_end_val = Y_home_load_d_ico5+t_home_load_d_ico5.y_end_val-t_home_load_d_ico5.y_val;
   t_home_load_d_ico5.x_val     = X_home_load_d_ico5;
	 t_home_load_d_ico5.y_val     = Y_home_load_d_ico5;
	 
	 t_home_load_u_ico0.x_end_val = X_home_load_u_ico0+t_home_load_u_ico0.x_end_val-t_home_load_u_ico0.x_val;
	 t_home_load_u_ico0.y_end_val = Y_home_load_u_ico0+t_home_load_u_ico0.y_end_val-t_home_load_u_ico0.y_val;
   t_home_load_u_ico0.x_val     = X_home_load_u_ico0;
	 t_home_load_u_ico0.y_val     = Y_home_load_u_ico0;
	 
	 t_home_load_u_ico1.x_end_val = X_home_load_u_ico1+t_home_load_u_ico1.x_end_val-t_home_load_u_ico1.x_val;
	 t_home_load_u_ico1.y_end_val = Y_home_load_u_ico1+t_home_load_u_ico1.y_end_val-t_home_load_u_ico1.y_val;
   t_home_load_u_ico1.x_val     = X_home_load_u_ico1;
	 t_home_load_u_ico1.y_val     = Y_home_load_u_ico1;
	 
	 t_home_load_u_ico2.x_end_val = X_home_load_u_ico2+t_home_load_u_ico2.x_end_val-t_home_load_u_ico2.x_val;
	 t_home_load_u_ico2.y_end_val = Y_home_load_u_ico2+t_home_load_u_ico2.y_end_val-t_home_load_u_ico2.y_val;
   t_home_load_u_ico2.x_val     = X_home_load_u_ico2;
	 t_home_load_u_ico2.y_val     = Y_home_load_u_ico2;
	 
	 t_home_load_u_ico3.x_end_val = X_home_load_u_ico3+t_home_load_u_ico3.x_end_val-t_home_load_u_ico3.x_val;
	 t_home_load_u_ico3.y_end_val = Y_home_load_u_ico3+t_home_load_u_ico3.y_end_val-t_home_load_u_ico3.y_val;
   t_home_load_u_ico3.x_val     = X_home_load_u_ico3;
	 t_home_load_u_ico3.y_val     = Y_home_load_u_ico3;
	 
	 t_home_load_u_ico4.x_end_val = X_home_load_u_ico4+t_home_load_u_ico4.x_end_val-t_home_load_u_ico4.x_val;
	 t_home_load_u_ico4.y_end_val = Y_home_load_u_ico4+t_home_load_u_ico4.y_end_val-t_home_load_u_ico4.y_val;
   t_home_load_u_ico4.x_val     = X_home_load_u_ico4;
	 t_home_load_u_ico4.y_val     = Y_home_load_u_ico4;
	 
	 t_home_load_u_ico5.x_end_val = X_home_load_u_ico5+t_home_load_u_ico5.x_end_val-t_home_load_u_ico5.x_val;
	 t_home_load_u_ico5.y_end_val = Y_home_load_u_ico5+t_home_load_u_ico5.y_end_val-t_home_load_u_ico5.y_val;
   t_home_load_u_ico5.x_val     = X_home_load_u_ico5;
	 t_home_load_u_ico5.y_val     = Y_home_load_u_ico5;
	 

}

void Upgrade_load_item(void)
{
	 lcd_dis_page_t *p;
	 u8 i;
	 init_home_loads_ico_para();
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][0];
   p->item = home_item;
   for(i=19;i<25;i++)
	 {
	   memcpy(&(p->item[i]),p_home_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_home_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_home_item_u[i]->size_of_pic_item ;
	 
	 }
	 set_home_loads_item_key_type();
 }

////////////////////////////////////////////////////////////////////
u8 home_lights_item_now_status[6];
void get_home_lights_item_now_status(void)
{
	u8 i;
	for(i=0;i<6;i++)
	{
	  home_lights_item_now_status[i] =  p_home_lights_item_d[i]->now_status;
	}
}
void set_home_lights_item_now_status(void)
{
	u8 i;
	for(i=0;i<6;i++)
	{
	    p_home_lights_item_d[i]->now_status = home_lights_item_now_status[i];
	  	p_home_lights_item_d[i]->last_status = home_lights_item_now_status[i];
	}
}
u8 home_loads_item_now_status[6];
void get_home_loads_item_now_status(void)
{
	u8 i;
	for(i=0;i<6;i++)
	{
	  home_loads_item_now_status[i] =  p_home_loads_item_d[i]->now_status;
	}
}
void set_home_loads_item_now_status(void)
{
	u8 i;
	for(i=0;i<6;i++)
	{
	    p_home_loads_item_d[i]->now_status = home_loads_item_now_status[i];
	  	p_home_loads_item_d[i]->last_status = home_loads_item_now_status[i];
	}
}


void ui_home_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][0];
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=HOME_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only


/*
   t_climatebtn_up_d.key_type = KEY_TYPE_ONCE;
	 t_climatebtn_down_d.key_type = KEY_TYPE_ONCE;
	 t_climate_fan_small_d.key_type = KEY_TYPE_ONCE;
	 t_climate_fan_big_d.key_type = KEY_TYPE_ONCE;
	 t_climatebtn_right_down_d.key_type = KEY_TYPE_ONCE;
	 t_climatebtn_right_up_d.key_type = KEY_TYPE_ONCE;
*/

   t_home_powerS_d.now_status = STATUS_SELECT;
	 t_home_powerS_d.last_status = STATUS_SELECT;
   
   t_home_black_bg.key_type = KEY_TYPE_TOUCH_NONE;
   t_home_fresh_bg.key_type = KEY_TYPE_TOUCH_NONE;
   t_home_grey_bg.key_type = KEY_TYPE_TOUCH_NONE;
   t_home_LPG_bg.key_type = KEY_TYPE_TOUCH_NONE;

   t_home_powerscroll_bg.key_type = KEY_TYPE_TOUCH_NONE;
   t_home_loadlights_bg.key_type = KEY_TYPE_TOUCH_NONE;
   t_home_loads_bg.key_type = KEY_TYPE_TOUCH_NONE;
	 
	 t_home_powerbtn_d.key_type = KEY_TYPE_ONCE;
	 t_home_lightsbtn_d.key_type = KEY_TYPE_ONCE;
	 t_home_loadbtn_d.key_type = KEY_TYPE_ONCE;
	 t_home_tankbtn_d.key_type = KEY_TYPE_ONCE;
	 
	 
   t_home_POWbc_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_home_POWcc_d.key_type = KEY_TYPE_TOUCH_NONE;
   t_home_POWsc_u.key_type = KEY_TYPE_TOUCH_NONE;
	 
	 
	// t_home_powerS_d.key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
	 t_home_inverter_d.key_type = KEY_TYPE_ONCE;
	 //t_home_lightsoff_d.key_type = KEY_TYPE_ONCE;
  // t_home_loadoff_d.key_type = KEY_TYPE_ONCE;
	//t_home_lightsON_d.key_type = KEY_TYPE_TOUCH_NONE;
	 
	 init_home_lights_ico_para();
	 init_home_loads_ico_para();

   p->item = home_item;
   for(i=0;i<HOME_ICO_NUM;i++)
	 {
	   memcpy(&(p->item[i]),p_home_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_home_item_u[i]->pic_item;//
   	p->item[i].size_of_pic_item = p_home_item_u[i]->size_of_pic_item ;
	 
	 }
	 
	  p->item[2].pic_item_touch =t_home_lightsoff_d.pic_item_touch;//
   	p->item[2].size_of_pic_item_touch = t_home_lightsoff_d.size_of_pic_item_touch ;
	 
	 
    p->item[4].pic_item_touch =t_home_loadoff_d.pic_item_touch;//
   	p->item[4].size_of_pic_item_touch = t_home_loadoff_d.size_of_pic_item_touch ;
	 
	  p->item[11].pic_item_touch =t_home_wpoff_d.pic_item_touch;//
   	p->item[11].size_of_pic_item_touch = t_home_wpoff_d.size_of_pic_item_touch ;
	 
	  //loads off  lights off  pumps off
		p->item[2].key_type = KEY_TYPE_TOUCH_NONE;
	 // p->item[2].now_status=STATUS_SELECT;
	 // p->item[2].pic_item_select =t_home_lightsoff_u.pic_item;//
   // p->item[2].size_of_pic_item_select= t_home_lightsoff_u.size_of_pic_item ;
	 
	 // p->item[2].pic_item =t_home_lightsoff_d.pic_item;//
  //  p->item[2].size_of_pic_item= t_home_lightsoff_d.size_of_pic_item ;

    p->item[4].key_type = KEY_TYPE_TOUCH_NONE;
    //p->item[11].key_type = KEY_TYPE_TOUCH_NONE;
	 
	  set_home_loads_item_key_type();
    set_home_lights_item_key_type(); 
   
	 
 }
