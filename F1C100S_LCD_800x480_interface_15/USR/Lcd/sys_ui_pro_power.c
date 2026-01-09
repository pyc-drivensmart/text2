#include "includes.h"


//power面按键列表 按下
lcd_dis_item_t *p_power_item_d[POWER_ICO_NUM]=
{
	&t_power_ac_bg,//0
	&t_power_battery_bg,	//1
	&t_power_bc_bg,//2
	&t_power_cc_bg,//3
	&t_power_sc_bg, //4
	&t_power_inverterON_d,//5//&t_power_inverterOFF_u,	
	&t_power_battery_ico,//6
	//&t_indicatorlamp_d,
};

//界面按键列表 弹起
lcd_dis_item_t *p_power_item_u[POWER_ICO_NUM]=
{
	&t_power_ac_bg,//0
	&t_power_battery_bg,	//1
	&t_power_bc_bg,//2
	&t_power_cc_bg,//3
	&t_power_sc_bg, //4
	&t_power_inverterOFF_u,	//5
	&t_power_battery_ico,//6
};

lcd_dis_item_t power_item[POWER_ICO_NUM];
lcd_dis_item_t power_test_item[POWER_ICO_NUM_TEST];
lcd_dis_item_t power_charger_test_item[POWER_CHARGER_ICO_NUM];
lcd_dis_item_t light_test_item[LIGHT_ICO_NUM_TEST];
u8 ICO_power_inverter_offset = 5;

//unuser
void disply_Inverter_Mode(bool upgrade)
{
  /*
	 static u8 old_Inverter_Mode;   
	 char display_buf[32];
	 lcd_dis_item_t *p;
	  

  if((old_Inverter_Mode !=parts_set_return_status.Inverter_Mode)||upgrade)
  {
    old_Inverter_Mode = parts_set_return_status.Inverter_Mode;		
		
		p=&t_power_inverterON_d;
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
				sprintf(display_buf,"        ON");
				break;			
			default:
				sprintf(display_buf,"        OFF");
				break;
		}
    Virtual_LCD_Draw_String_ARGB_24_4bit(p->x_val+30,p->y_val+20,display_buf,ARGB_white,0,1,1);

		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
*/
return;
}
//inverter
#define INVERTER_VAL_CENTER_OFFSET_X 220
void disply_AC_in_out_val(bool upgrade)
{
	 static INVERTER_STATUS old_Inverter_status;  
	 static u8 old_Inverter_Mode;    
	 char display_buf[32];
	 lcd_dis_item_t *p;
	 u16 temp_I;
	 u32 temp_pow;
//	 u16 x_offset = 0;
	  

  if((memcmp(&Inverter_status,&old_Inverter_status,sizeof(INVERTER_STATUS)))||(old_Inverter_Mode !=parts_set_return_status.Inverter_Mode)||upgrade)
  {
    memcpy(&old_Inverter_status,&Inverter_status,sizeof(INVERTER_STATUS));
		old_Inverter_Mode = parts_set_return_status.Inverter_Mode;	
		
		
		p=&t_power_ac_bg;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(175,90,"DC State",ARGB_gray,0,1,1);

		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(173,215,"AC Loads",ARGB_gray,0,1,1);


		if(Is_Inverter_mode_AC_IN())
		{			
		  sprintf(display_buf,"(Grid)"); //Virtual_LCD_Draw_String_ARGB_24_4bit_bold(175,215,"(grid)",ARGB_gray,0,1,1);
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,235,display_buf,ARGB_gray,0,1,1);
		}
		else if((Is_Inverter_mode_Inverting())||(Inverter_status.mode==0x27))//0x27:Power Assist
		{
	    sprintf(display_buf,"(Inverter)"); //Virtual_LCD_Draw_String_ARGB_24_4bit_bold(175,215,"(inverter)",ARGB_gray,0,1,1);			
		  Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,235,display_buf,ARGB_gray,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"(--)"); //Virtual_LCD_Draw_String_ARGB_24_4bit_bold(175,215,"(inverter)",ARGB_gray,0,1,1);
			Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,235,display_buf,ARGB_mygray,0,1,1);
		}
			
		
		//Virtual_LCD_Draw_String_ARGB_24_4bit_bold(350,90,"Inverter Status",ARGB_gray,0,1,1); 
		
		p=&t_power_inverterON_d;
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
				sprintf(display_buf,"ON");
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
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit((p->x_end_val+p->x_val)>>1,p->y_val+22,display_buf,ARGB_white,0,1,1);
			 power_item[ICO_power_inverter_offset].key_type = KEY_TYPE_ONCE;
			// power_item[ICO_power_inverter_offset].last_status = STATUS_IDLE;
			// power_item[ICO_power_inverter_offset].now_status = STATUS_IDLE;
		}
		else
		{ 
			 Virtual_LCD_Draw_String_ARGB_align_center_24_4bit((p->x_end_val+p->x_val)>>1,p->y_val+22,display_buf,ARGB_gray,0,1,1);
			 power_item[ICO_power_inverter_offset].key_type = KEY_TYPE_TOUCH_NONE;
			 //power_item[ICO_power_inverter_offset].last_status = STATUS_IDLE;
			 power_item[ICO_power_inverter_offset].now_status = STATUS_IDLE;
		}
		
		
		p=&t_power_ac_bg;

	 if((Inverter_status.V_220==0)&&(Inverter_status.I_220==0))
	 {
	 
	     sprintf(display_buf,"--  --"); 
	     Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,176,display_buf,ARGB_mygray,0,1,1);
	 }
	 else
	 {
	   if((Inverter_status.I_220&0x8000))
		{
			temp_I =  Inverter_status.I_220&0x7FFF;
		  sprintf(display_buf,"%d.%dV  -%d.%dA",Inverter_status.V_220/10,Inverter_status.V_220%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,176,display_buf,ARGB_white,0,1,1);
		}
		else// if(assi1_battery_status.I!=0)
		{
			temp_I =  Inverter_status.I_220;
		  sprintf(display_buf,"%d.%dV  %d.%dA",Inverter_status.V_220/10,Inverter_status.V_220%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,176,display_buf,ARGB_white,0,1,1);
		}
	 
	 }		
		
		temp_pow = Inverter_status.P_220;
		if(temp_pow&0x8000)
		{			
		  sprintf(display_buf,"-%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(INVERTER_VAL_CENTER_OFFSET_X,142,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(temp_pow!=0)
		{			
		  sprintf(display_buf,"%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(INVERTER_VAL_CENTER_OFFSET_X,142,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(INVERTER_VAL_CENTER_OFFSET_X,142,display_buf,ARGB_mygray,0,1,1);
		}

		
		if(Inverter_status.I_220)
			p=&t_indicatorlamp_d;
		else
			p=&t_indicatorlamp_u;
		 png_dis_xy(206,117,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		
		
		
		
		switch(Inverter_status.mode)
		{
		  case 0:
				sprintf(display_buf,"Auxiliary");
				break;
		  case 1:
				sprintf(display_buf,"Standby");
				break;
			case 4:
				sprintf(display_buf,"Inverting");
				break;
			case 8:
				sprintf(display_buf,"Mains power");
				break;
			case 9:
				sprintf(display_buf,"PowOff");
				break;
			case 0x10:
				sprintf(display_buf,"Bypass");
				break;
			case 0x11:
				sprintf(display_buf,"Inverting");
				break;
			case 0x12:
				sprintf(display_buf,"Charging");
				break;
			case 0x20:
				sprintf(display_buf,"Down");
				break;
			
			case 0x21:
				sprintf(display_buf,"Startup");
				break;
			case 0x22:
				sprintf(display_buf,"Off");
				break;
			case 0x23:
				sprintf(display_buf,"Slave Mode");
				break;
      case 0x24:
				sprintf(display_buf,"Inverting");//Invert Full
				break;
      case 0x25:
				sprintf(display_buf,"Invert Half");
				break;
      case 0x26:
				sprintf(display_buf,"Invert AES");
				break;
      case 0x27:
				sprintf(display_buf,"Power Assist");
				break;
      case 0x28:
				sprintf(display_buf,"Bypass");
				break;
      case 0x29:
				sprintf(display_buf,"Charge");
				break;
			case 0x30:
				sprintf(display_buf,"Initializing");
				break;
			case 0x31:
				sprintf(display_buf,"Bulk");
				break;
			case 0x32:
				sprintf(display_buf,"Absorption");
				break;
			case 0x33:
				sprintf(display_buf,"Float");
				break;
			case 0x34:
				sprintf(display_buf,"Storage");
				break;
			case 0x35:
				sprintf(display_buf,"Repeated Absorption");
				break;
			case 0x36:
				sprintf(display_buf,"Forced Absorption");
				break;
			case 0x37:
				sprintf(display_buf,"Equalise");
				break;
			case 0x38:
				sprintf(display_buf,"Bulk stopped");
				break;
			default:
				sprintf(display_buf,"Unkown");
				break;
		}
      //Virtual_LCD_Draw_Rectangle_ARGB32(380,120,12*15,24,Virtual_LCDbuff2,ARGB_clear);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(440,115,display_buf,ARGB_mydarkcyan,0,1,1);

		
		
		
		
		
		
		/////////////
		
		
		//Virtual_LCD_Draw_Rectangle_ARGB32(236,277,8*10,277-216+16,Virtual_LCDbuff2,ARGB_clear);

		if((Inverter_status.V_o==0)&&(Inverter_status.I_o==0))
	 {
	 
	     sprintf(display_buf,"--  --"); 
	     Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,311,display_buf,ARGB_mygray,0,1,1);
	 }
	 else
	 {
	   if((Inverter_status.I_o&0x8000))
		{
			temp_I =  Inverter_status.I_o&0x7FFF;
		  sprintf(display_buf,"%d.%dV  -%d.%dA",Inverter_status.V_o/10,Inverter_status.V_o%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,311,display_buf,ARGB_white,0,1,1);
		}
		else// if(assi1_battery_status.I!=0)
		{
			temp_I =  Inverter_status.I_o;
		  sprintf(display_buf,"%d.%dV  %d.%dA",Inverter_status.V_o/10,Inverter_status.V_o%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(INVERTER_VAL_CENTER_OFFSET_X,311,display_buf,ARGB_white,0,1,1);
		}
	 
	 }
		
		temp_pow = Inverter_status.P_o;
		if(temp_pow&0x8000)
		{
			//temp_pow = Inverter_status.V_o*temp_I/100;
			//if(temp_pow>0xFFFF)
			//	temp_pow = 0xFFFF;
		  sprintf(display_buf,"-%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(INVERTER_VAL_CENTER_OFFSET_X,277,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(temp_pow!=0)
		{
		  sprintf(display_buf,"%d W",temp_pow&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(INVERTER_VAL_CENTER_OFFSET_X,277,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(INVERTER_VAL_CENTER_OFFSET_X,277,display_buf,ARGB_mygray,0,1,1);
		}
		
		//Virtual_LCD_Draw_String_ARGB_16_4bit(236,181,"--W",ARGB_mygray,0,1,1);
		
		if(Inverter_status.I_o)
			p=&t_indicatorlamp_d;
		else
			p=&t_indicatorlamp_u;
		 png_dis_xy(206,255,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		
		
		p=&t_power_ac_bg;
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
   
}



#define CHANGER_NAME_MID_OFFSET_X  174
#define CHANGER_NAME_OFFSET_X  140
#define CHANGER_NAME_OFFSET_Y  30

#define CHANGER_ICO_OFFSET_X  158
#define CHANGER_ICO_OFFSET_Y  92

#define CHANGER_W_OFFSET_X 270
#define CHANGER_W_OFFSET_Y 40
#define CHANGER_V_OFFSET_X 270
#define CHANGER_V_OFFSET_Y 60
#define CHANGER_A_OFFSET_X 270
#define CHANGER_A_OFFSET_Y 78
#define CHANGER_CENTER_OFFSET_X 300


//AC changer
void disply_combi_CHG_val(bool upgrade)
{
   static CHARGER_STATUS old_Combi_CHG;   
	 char display_buf[32];
	 lcd_dis_item_t *p,*p2;
	 u16 temp_I;




  if((memcmp(&Combi_CHG,&old_Combi_CHG,sizeof(CHARGER_STATUS)))||upgrade)
  {
    memcpy(&old_Combi_CHG,&Combi_CHG,sizeof(CHARGER_STATUS));
		
		p=&t_power_cc_bg;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
    Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_NAME_MID_OFFSET_X,p->y_val+CHANGER_NAME_OFFSET_Y,"AC",ARGB_gray,0,1,1);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_NAME_MID_OFFSET_X,p->y_val+CHANGER_NAME_OFFSET_Y+25,"Charger",ARGB_gray,0,1,1);
		if(Combi_CHG.Power&0x8000)
		{
		  sprintf(display_buf,"-%d W",Combi_CHG.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(Combi_CHG.Power)
		{
		  sprintf(display_buf,"%d W",Combi_CHG.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mygray,0,1,1);
		}
		
	 if((Combi_CHG.V_in==0)&&(Combi_CHG.I_in==0))
	 {
	 
	     sprintf(display_buf,"--  --"); 
	     Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_mygray,0,1,1);
	 }
	 else
	 {
	   if((Combi_CHG.I_in&0x8000))
		{
			temp_I =  Combi_CHG.I_in&0x7FFF;
		  sprintf(display_buf,"%d.%dV  -%d.%dA",Combi_CHG.V_in/10,Combi_CHG.V_in%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_white,0,1,1);
		}
		else// if(assi1_battery_status.I!=0)
		{
			temp_I =  Combi_CHG.I_in;
		  sprintf(display_buf,"%d.%dV  %d.%dA",Combi_CHG.V_in/10,Combi_CHG.V_in%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_white,0,1,1);
		}
	 
	 }
		
		if(Combi_CHG.I_in)
			p2=&t_indicatorlamp_d;
		else
			p2=&t_indicatorlamp_u;
		 png_dis_xy(p->x_val+CHANGER_ICO_OFFSET_X,p->y_val+CHANGER_ICO_OFFSET_Y,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		

		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
   


   
}

//Solar changer
void disply_solar_val(bool upgrade)
{
	 static SOLAR_STATUS old_solar_status;   
	 char display_buf[32];
	 lcd_dis_item_t *p,*p2;
	 u16 temp_I;

  if((memcmp(&solar_status,&old_solar_status,sizeof(SOLAR_STATUS)))||upgrade)
  {
    memcpy(&old_solar_status,&solar_status,sizeof(SOLAR_STATUS));
		
		p=&t_power_sc_bg;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		
		 
    Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_NAME_MID_OFFSET_X,p->y_val+CHANGER_NAME_OFFSET_Y,"Solar",ARGB_gray,0,1,1);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_NAME_MID_OFFSET_X,p->y_val+CHANGER_NAME_OFFSET_Y+25,"Charger",ARGB_gray,0,1,1);
		
		
		if(solar_status.Power&0x8000)
		{
		  sprintf(display_buf,"-%d W",solar_status.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(solar_status.Power)
		{
		  sprintf(display_buf,"%d W",solar_status.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mygray,0,1,1);
		}
		if((solar_status.V_in==0)&&(solar_status.I_in==0))
	 {
	 
	     sprintf(display_buf,"--  --"); 
	     Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_mygray,0,1,1);
	 }
	 else
	 {
	   if((solar_status.I_in&0x8000))
		{
			temp_I =  solar_status.I_in&0x7FFF;
		  sprintf(display_buf,"%d.%dV  -%d.%dA",solar_status.V_in/10,solar_status.V_in%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_white,0,1,1);
		}
		else// if(assi1_battery_status.I!=0)
		{
			temp_I =  solar_status.I_in;
		  sprintf(display_buf,"%d.%dV  %d.%dA",solar_status.V_in/10,solar_status.V_in%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_white,0,1,1);
		}
	 
	 }
		
		if(solar_status.I_in)
			p2=&t_indicatorlamp_d;
		else
			p2=&t_indicatorlamp_u;
		 png_dis_xy(p->x_val+CHANGER_ICO_OFFSET_X,p->y_val+CHANGER_ICO_OFFSET_Y,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		

		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
   
}

//DC Changer
void disply_booster_val(bool upgrade)
{
	static CHARGER_STATUS old_Booster_Charger;   
	 char display_buf[32];
	 lcd_dis_item_t *p,*p2;
	 u16 temp_I;

  if((memcmp(&Booster_Charger,&old_Booster_Charger,sizeof(CHARGER_STATUS)))||upgrade) 
  {
    memcpy(&old_Booster_Charger,&Booster_Charger,sizeof(CHARGER_STATUS));
		
		p=&t_power_bc_bg;//#define X_power_bc_bg  581 #define Y_power_bc_bg  366
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);
		
		 
    Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_NAME_MID_OFFSET_X,p->y_val+CHANGER_NAME_OFFSET_Y,"DC-DC",ARGB_gray,0,1,1);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_NAME_MID_OFFSET_X,p->y_val+CHANGER_NAME_OFFSET_Y+25,"Charger",ARGB_gray,0,1,1);
		
		
		if(Booster_Charger.Power&0x8000)
		{
		  sprintf(display_buf,"-%d W",Booster_Charger.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(Booster_Charger.Power)
		{
		  sprintf(display_buf,"%d W",Booster_Charger.Power&0x7FFF);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y,display_buf,ARGB_mygray,0,1,1);
		}
	
		if((Booster_Charger.V_in==0)&&(Booster_Charger.I_in==0))
	 {
	 
	     sprintf(display_buf,"--  --"); 
	     Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_mygray,0,1,1);
	 }
	 else
	 {
	   if((Booster_Charger.I_in&0x8000))
		{
			temp_I =  Booster_Charger.I_in&0x7FFF;
		  sprintf(display_buf,"%d.%dV  -%d.%dA",Booster_Charger.V_in/10,Booster_Charger.V_in%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_white,0,1,1);
		}
		else// if(assi1_battery_status.I!=0)
		{
			temp_I =  Booster_Charger.I_in;
		  sprintf(display_buf,"%d.%dV  %d.%dA",Booster_Charger.V_in/10,Booster_Charger.V_in%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_A_OFFSET_Y,display_buf,ARGB_white,0,1,1);
		}
	 
	 }
		
		
		if(Booster_Charger.I_in)
			p2=&t_indicatorlamp_d;
		else
			p2=&t_indicatorlamp_u;
		 png_dis_xy(p->x_val+CHANGER_ICO_OFFSET_X,p->y_val+CHANGER_ICO_OFFSET_Y,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		
		
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
	}
   
}




//BATTERY
void disply_assi1_battery_val(bool upgrade)
{
	 static BATTERY_STATUS old_assi1_battery_status;   
	 char display_buf[32];
	 lcd_dis_item_t *p,*p2;
	 u16 temp_I;
	 u32 dis_color = ARGB_white;
//	 u16 x_offset =0;
//  	u8 i;
   
  if((memcmp(&assi1_battery_status,&old_assi1_battery_status,sizeof(BATTERY_STATUS)))||upgrade)
  {
    memcpy(&old_assi1_battery_status,&assi1_battery_status,sizeof(BATTERY_STATUS));
   //sysprintf("\r\n9999999999999");	
		p=&t_power_battery_bg;
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);

		Virtual_LCD_Draw_String_ARGB_24_4bit_bold(p->x_val+CHANGER_NAME_OFFSET_X,p->y_val+CHANGER_NAME_OFFSET_Y,"Battery",ARGB_gray,0,1,1);
		
		if(assi1_battery_status.I&0x8000)
		{
		  sprintf(display_buf,"-%d W",(assi1_battery_status.V*(assi1_battery_status.I&0x7FFF))/100);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y-10,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else if(assi1_battery_status.I!=0)
		{
		  sprintf(display_buf,"%d W",(assi1_battery_status.V*(assi1_battery_status.I&0x7FFF))/100);
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y-10,display_buf,ARGB_mydarkcyan,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"--");
      Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_W_OFFSET_Y-10,display_buf,ARGB_mygray,0,1,1);
		}
		
   if((assi1_battery_status.V==0)&&(assi1_battery_status.I==0))
	 {
	 
	    sprintf(display_buf,"--  --"); 
	     Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_V_OFFSET_Y,display_buf,ARGB_mygray,0,1,1);
	 }
	 else
	 {
	   if((assi1_battery_status.I&0x8000))
		{
			temp_I =  assi1_battery_status.I&0x7FFF;
		  sprintf(display_buf,"%d.%d V  -%d.%d A",assi1_battery_status.V/10,assi1_battery_status.V%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_V_OFFSET_Y,display_buf,ARGB_white,0,1,1);
		}
		else// if(assi1_battery_status.I!=0)
		{
			temp_I =  assi1_battery_status.I;
		  sprintf(display_buf,"%d.%d V  %d.%d A",assi1_battery_status.V/10,assi1_battery_status.V%10,temp_I/10,temp_I%10);
      Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+CHANGER_V_OFFSET_Y,display_buf,ARGB_white,0,1,1);
		}
	 
	 }
	
		//////
			
		if((base_return_status.uint&0x0C)==0x04)//F
		{
			   if(assi1_battery_status.MAX_temp==0xFF)
				 {
							sprintf(display_buf,"--");
				 }
				 else if(assi1_battery_status.MAX_temp>=80)
				 sprintf(display_buf,"%d  F",assi1_battery_status.MAX_temp-80);
				 else
					 sprintf(display_buf,"-%d  F",80-assi1_battery_status.MAX_temp);
		  }
		  else
		  {
         if(assi1_battery_status.MAX_temp==0xFF)
				 {
							sprintf(display_buf,"--");
				 }
				 else if(assi1_battery_status.MAX_temp>=80)
				 sprintf(display_buf,"%d  C",assi1_battery_status.MAX_temp-80);
				 else
					 sprintf(display_buf,"-%d  C",80-assi1_battery_status.MAX_temp);
			 }
			if(assi1_battery_status.MAX_temp==0xFF)
			{
			  Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+80,display_buf,ARGB_mygray,0,1,1);
				//Virtual_LCD_Draw_String_o(get_str_align_center_x_val(p->x_val+CHANGER_CENTER_OFFSET_X,display_buf,glyph_dsc_16_4bit),p->y_val+80,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_16_4bit,(ARGB_white),0,1,1);
			}
			else
			{
        Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,p->y_val+80,display_buf,ARGB_white,0,1,1);
				Virtual_LCD_Draw_String_o(get_str_align_center_x_val(p->x_val+CHANGER_CENTER_OFFSET_X,display_buf,glyph_dsc_16_4bit),p->y_val+80,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_16_4bit,(ARGB_white),0,1,1);
			}
			
			
		
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
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,465,display_buf,dis_color,0,1,1);
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
				Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(p->x_val+CHANGER_CENTER_OFFSET_X,465,display_buf,dis_color,0,1,1);
			}
			//ch = (u8)ch;
			
			
			
		//Virtual_LCD_Draw_Rectangle_ARGB32(281,422,32*6,32,Virtual_LCDbuff2,ARGB_clear);
		if(assi1_battery_status.Q>=100)
		{
			sprintf(display_buf,"100%%");
			/*display_buf[3] = '%';
			display_buf[4] = ' ';
			display_buf[5] = ' ';
			display_buf[6] = '\0';*/
			Virtual_LCD_Draw_String_ARGB_32_4bit_bold(281,422,display_buf,ARGB_white,0,1,1);
		}
		else
		{
		  sprintf(display_buf,"%2d%%",assi1_battery_status.Q);
		  /*display_buf[2] = '%';
			display_buf[3] = ' ';
			display_buf[4] = ' ';
			display_buf[5] = '\0';*/
			Virtual_LCD_Draw_String_ARGB_32_4bit_bold(281,422,display_buf,ARGB_white,0,1,1);
		
		}
		
		p=&t_power_battery_ico;
		 png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
	  if(assi1_battery_status.f_time_changer)
		{
		  if(assi1_battery_status.Q<=5)
			 p=&t_power_battery_changer_0;
			else if(assi1_battery_status.Q<=25)
			 p=&t_power_battery_changer_1;
			else if(assi1_battery_status.Q<=50)
			 p=&t_power_battery_changer_2;
			else if(assi1_battery_status.Q<90)
			 p=&t_power_battery_changer_3;
			else// if(assi1_battery_status.Q<=95)
			 p=&t_power_battery_changer_4;
			//else 
			// p=&t_power_battery_changer_5;
		}
		else
		{
			if(assi1_battery_status.Q<=5)
			 p=&t_power_battery_0;
			else if(assi1_battery_status.Q<=25)
			 p=&t_power_battery_1;
			else if(assi1_battery_status.Q<=50)
			 p=&t_power_battery_2;
			else if(assi1_battery_status.Q<90)
			 p=&t_power_battery_3;
			else //if(assi1_battery_status.Q<=95)
			 p=&t_power_battery_4;
			//else 
			// p=&t_power_battery_5;
	 }
		png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);
		
		
		if(assi1_battery_status.I)
			p2=&t_indicatorlamp_d;
		else
			p2=&t_indicatorlamp_u;
		 png_dis_xy(298,458,p2->pic_item,p2->size_of_pic_item,Virtual_LCDbuff1);
		
		p=&t_power_battery_bg;
		if(upgrade==FALSE)
		Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
		//Virtual_LCD_Upgrate();
	}
   
}



BOOL page_power_deel_with_i(lcd_dis_page_t *p2,u8* i)
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
void ui_power_init(void)
{
	lcd_dis_page_t *p;
	u8 i;
	// p2 = &page_home.page_top_side[0];	
	 p = &page_home.page_main_item[LEFT_SIDE_PAGE_POWER][TOP_SIDE_PAGE_POWER_POWER]; 
	 
	 p->pic_back_g = t_bg.pic_item;//poit to backgroud pic
	 p->size_of_pic_back=t_bg.size_of_pic_item;// backgroud pic size
	 p->x_val=MAIN_AREA_X;//for whole area   single item see "lcd_dis_item_t" 
	 p->y_val=MAIN_AREA_Y;
	 p->x_end_val=MAIN_AREA_X_END;
	 p->y_end_val=MAIN_AREA_Y_END;
	 p->item_num=POWER_ICO_NUM;// how many item
	 p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	 p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	
  t_power_ac_bg.key_type = KEY_TYPE_TOUCH_NONE;
	t_power_battery_bg.key_type = KEY_TYPE_TOUCH_NONE;
	t_power_bc_bg.key_type = KEY_TYPE_TOUCH_NONE;
	t_power_cc_bg.key_type = KEY_TYPE_TOUCH_NONE;
	t_power_sc_bg.key_type = KEY_TYPE_TOUCH_NONE;
	t_power_battery_ico.key_type = KEY_TYPE_TOUCH_NONE;
	 
	t_power_inverterON_d.key_type = KEY_TYPE_ONCE;
	 
  p->item = power_item;
  for(i=0;i<POWER_ICO_NUM;i++)
	{
	  memcpy(&(p->item[i]),p_power_item_d[i],sizeof(lcd_dis_item_t));
	  p->item[i].pic_item =p_power_item_u[i]->pic_item;//
  	 p->item[i].size_of_pic_item = p_power_item_u[i]->size_of_pic_item ;
	}
}


