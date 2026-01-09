#include "includes.h"


void func_tank_balck_val_5(void* p,u8 sn)
{
	//u8 SN = 0;//图标在当前页面列表的序号
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//lcd_dis_page_t *p2 ;
	//
	//p2 =&page_home.page_left_side;
	//if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	//{ 
	//	p1->item[SN].now_status = STATUS_IDLE;
	//	p2->last_item = LEFT_SIDE_PAGE_UPDATA;
	//	
	//	page_deepth_val[TOP_SIDE_PAGE_HOME_TANK] = 1; //子页面1
	//	page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK] = 3;  //
	//}
}
void func_tank_fresh_val_5(void* p,u8 sn)
{
	//u8 SN = 1;//图标在当前页面列表的序号
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//lcd_dis_page_t *p2 ;
	//
	//p2 =&page_home.page_left_side;
	//if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	//{ 
	//	p1->item[SN].now_status = STATUS_IDLE;
	//	p2->last_item = LEFT_SIDE_PAGE_UPDATA;
	//	
	//	page_deepth_val[TOP_SIDE_PAGE_HOME_TANK] = 1; //子页面1
	//	page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK] = 1;  //
	//}
}

void func_tank_gray_val_5(void* p,u8 sn)
{
	//u8 SN = 2;//图标在当前页面列表的序号
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//lcd_dis_page_t *p2 ;
	//
	//p2 =&page_home.page_left_side;
	//if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	//{ 
	//	p1->item[SN].now_status = STATUS_IDLE;
	//	p2->last_item = LEFT_SIDE_PAGE_UPDATA;
	//	
	//	page_deepth_val[TOP_SIDE_PAGE_HOME_TANK] = 1; //子页面1
	//	page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK] = 2;  //
	//}
}

void func_tank_lpg_val_5(void* p,u8 sn)
{
	//u8 SN = 3;//图标在当前页面列表的序号
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//lcd_dis_page_t *p2 ;
	//
	//p2 =&page_home.page_left_side;
	//if(p1->item[SN].now_status==STATUS_TOUCH_LONG_PRESS)
	//{ 
	//	p1->item[SN].now_status = STATUS_IDLE;
	//	p2->last_item = LEFT_SIDE_PAGE_UPDATA;
	//	
	//	
	//	page_deepth_val[TOP_SIDE_PAGE_HOME_TANK] = 1; //子页面深度1
	//	page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK] = 4;  //
	//}
}
void func_tank_black_bg_5(void* p,u8 sn)
{

}




void func_tank_fresh_bg_5(void* p,u8 sn)
{

}






void func_tank_gray_bg_5(void* p,u8 sn)
{

}







void func_tank_lpg_bg_5(void* p,u8 sn)
{

}




void func_tank_water_heater_down_5(void* p,u8 sn)
{

}



void func_tank_water_heater_up_5(void* p,u8 sn)
{

}



void func_tank_water_pump_down_5(void* p,u8 sn)
{

}



void func_tank_water_pump_up_5(void* p,u8 sn)
{

}


void func_tank_black_wave_5(void* p,u8 sn)
{

}



void func_tank_fresh_wave_5(void* p,u8 sn)
{

}



void func_tank_gray_wave_5(void* p,u8 sn)
{

}



void func_tank_lpg_wave_5(void* p,u8 sn)
{

}

void func_tank_column_1_5(void* p,u8 sn)
{

}
void func_tank_column_2_5(void* p,u8 sn)
{

}
void func_tank_column_3_5(void* p,u8 sn)
{

}
void func_tank_column_4_5(void* p,u8 sn)
{

}
void func_tank_column_5_5(void* p,u8 sn)
{

}
void func_tank_column_6_5(void* p,u8 sn)
{

}
void func_tank_column_7_5(void* p,u8 sn)
{

}
void func_tank_solumn_return_1_5(void* p,u8 sn)
{
	//u8 SN = 8;//图标在当前页面列表的序号
  //lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//lcd_dis_page_t *p2 ;
	//
	//p2 =&page_home.page_left_side;
	//if(p1->item[SN].now_status==STATUS_SELECT)
	//{ 
	//	//p1->item[SN].now_status = STATUS_IDLE;
	//	p2->last_item = LEFT_SIDE_PAGE_UPDATA;
	//	
	//	page_deepth_val[TOP_SIDE_PAGE_HOME_TANK] = 0 ;
	//	page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK] = 0;  //
	//}
}
extern TANK_SET_STATUS* Tank_set_return_status[TANK_DIS_NUM];
void func_tank_column_right_add_1_5(void* p,u8 sn)
{
	//u8 SN = 6;
	//lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//if(p1->item[SN].now_status==STATUS_SELECT)
	//{ 
	//	Tank_set_return_status[page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1]->Tank_type++;
	//	if(Tank_set_return_status[page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1]->Tank_type>=4)
	//		Tank_set_return_status[page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1]->Tank_type = 4;
	//	sysprintf("\r\n Tank_set_return_status[%d]->tank_type = %d \r\n",(page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1),Tank_set_return_status[page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1]->Tank_type);
	//}
}
void func_tank_solumn_left_sub_1_5(void* p,u8 sn)
{
	//u8 SN = 7;
	//lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	//if(p1->item[SN].now_status==STATUS_SELECT)
	//{ 
	//	Tank_set_return_status[page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1]->Tank_type--;
	//	if(Tank_set_return_status[page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1]->Tank_type<1)
	//		Tank_set_return_status[page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1]->Tank_type = 1;
	//	sysprintf("\r\n Tank_set_return_status[%d]->tank_type = %d \r\n",(page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1),Tank_set_return_status[page_sub_page_serial_num[0][TOP_SIDE_PAGE_HOME_TANK]-1]->Tank_type);
	//
	//}
}


