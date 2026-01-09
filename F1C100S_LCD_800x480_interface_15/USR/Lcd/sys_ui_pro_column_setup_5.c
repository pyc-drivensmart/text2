#include "includes.h"

void func_power_system_setting_victron_multiplus_inv(void* p,u8 sn,DEAl_TYPE deal_type)			;
void func_power_system_setting_batt_capacity(void* p,u8 sn,DEAl_TYPE deal_type)							;
void func_power_ststem_setting_batt_soc(void* p,u8 sn,DEAl_TYPE deal_type)									;
void func_power_system_info_DcDc_Type_0(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_DcDc_Type_1(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_DcDc_Type_2(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Mppt_Type_0(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Mppt_Type_1(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Mppt_Type_2(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Mppt_Type_3(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Mppt_Type_4(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Inverter_Type_0(void* p,u8 sn,DEAl_TYPE deal_type)              ;
void func_power_system_info_Inverter_Type_1(void* p,u8 sn,DEAl_TYPE deal_type)              ;
void func_power_system_info_Inverter_Type_2(void* p,u8 sn,DEAl_TYPE deal_type)              ;
void func_power_system_info_Inverter_Type_3(void* p,u8 sn,DEAl_TYPE deal_type)              ;
void func_power_system_info_Batt_Type_0(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Batt_Type_1(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Batt_Type_2(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Batt_Type_3(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_power_system_info_Batt_Type_4(void* p,u8 sn,DEAl_TYPE deal_type)                  ;
void func_sys_setting_Code_Enter(void* p,u8 sn,DEAl_TYPE deal_type)													;
void func_sys_setting_restore_defualt(void* p,u8 sn,DEAl_TYPE deal_type)                    ;
void func_sys_setting_system_reset(void* p,u8 sn,DEAl_TYPE deal_type)                       ;
void func_sys_setting_year_setting(void* p,u8 sn,DEAl_TYPE deal_type)                       ;
void func_sys_setting_mon_setting(void* p,u8 sn,DEAl_TYPE deal_type)                        ;
void func_sys_setting_day_setting(void* p,u8 sn,DEAl_TYPE deal_type)                        ;
void func_sys_setting_hour_setting(void* p,u8 sn,DEAl_TYPE deal_type)                       ;
void func_sys_setting_min_setting(void* p,u8 sn,DEAl_TYPE deal_type)                        ;
void func_sys_setting_sec_setting(void* p,u8 sn,DEAl_TYPE deal_type)                        ;
void func_sys_setting_language(void* p,u8 sn,DEAl_TYPE deal_type)          			            ;
void func_sys_setting_temperature_uint(void* p,u8 sn,DEAl_TYPE deal_type)                   ;
void func_power_setting_setting_vol_point_back_to_utility_source(void* p,u8 sn,DEAl_TYPE deal_type) ;
void func_sys_setting_brightness(void* p,u8 sn,DEAl_TYPE deal_type)                         ;
void func_sys_setting_sleep_time(void* p,u8 sn,DEAl_TYPE deal_type)                         ;
void func_sys_setting_touch_tone(void* p,u8 sn,DEAl_TYPE deal_type)                         ;
void func_sys_setting_light_up_screen_when_alarm_occurs(void* p,u8 sn,DEAl_TYPE deal_type)  ;
void func_power_setting_output_source_priority(void* p,u8 sn,DEAl_TYPE deal_type)           ;
void func_power_setting_power_saving_mode(void* p,u8 sn,DEAl_TYPE deal_type)                ;
void func_power_setting_charger_source_priority(void* p,u8 sn,DEAl_TYPE deal_type)          ;
void func_power_setting_ac_input_voltage_range(void* p,u8 sn,DEAl_TYPE deal_type)           ;
void func_power_setting_maximum_charging_current(void* p,u8 sn,DEAl_TYPE deal_type)         ;
void func_power_setting_max_utility_charging_current(void* p,u8 sn,DEAl_TYPE deal_type)     ;
void func_power_setting_output_voltage(void* p,u8 sn,DEAl_TYPE deal_type)                   ;
void func_power_setting_output_fre(void* p,u8 sn,DEAl_TYPE deal_type)                       ;
void func_power_setting_alarm_ctrl(void* p,u8 sn,DEAl_TYPE deal_type)                       ;
void func_power_setting_beeps(void* p,u8 sn,DEAl_TYPE deal_type)                            ;
void func_power_setting_battery_type(void* p,u8 sn,DEAl_TYPE deal_type)                     ;
void func_power_setting_bulk_charging_vol(void* p,u8 sn,DEAl_TYPE deal_type)                ;
void func_power_setting_floating_charging_vol(void* p,u8 sn,DEAl_TYPE deal_type)            ;
void func_power_setting_low_dc_cut_off_vol(void* p,u8 sn,DEAl_TYPE deal_type)               ;
void func_power_setting_auto_restart_when_overload_occurs(void* p,u8 sn,DEAl_TYPE deal_type);
void func_power_setting_auto_restart_when_temp_occurs(void* p,u8 sn,DEAl_TYPE deal_type)    ;
void func_power_setting_record_fault_code(void* p,u8 sn,DEAl_TYPE deal_type)                ;
void disply_Setup_val(bool upgrade);//显示温度单位
SetupSystem now_Setup_status;   //现在状态

u8 last_show_page_num[3] = {0};
u8 last_show_page_level = 0;
setup_item_info_t Data_Time[];
ACOPWER_INV acopower_inv={0};
TYPE_SEL type_sel={0};
u8 setup_page_display_num = 4;
#define SETUP_5_CHUN_ITME_NUM 31
lcd_dis_item_t *p_setup_item_main_u[SETUP_5_CHUN_ITME_NUM]={
    
        &t_page6_no_selects                             ,//选项框带进入
      &t_page6_no_selects_2                          ,
      &t_page6_no_selects_3                          ,
      &t_page6_no_selects_4                          ,//（0~3）
//      &t_page6_select2                             ,
//      &t_page6_select_2                          ,
//      &t_page6_select_3                          ,
//      &t_page6_select_4                          ,//（0~3）
//    
//	&t_Setup_info_column_enter_up_new,//选项框带进入
//	&t_Setup_info_column_enter_up_new_1,
//	&t_Setup_info_column_enter_up_new_2,
//	&t_Setup_info_column_enter_up_new_3,
    
    
	&t_Setup_info_column_enter_up_new_4,//占空
	&t_Setup_info_column_enter_up_new_5,
    
    
    &t_page6_up_up                              ,//4
    &t_page6_down_up                            ,
//	&t_Setup_page_pre_up_new,//向上选项
//	&t_Setup_page_next_up_new,//向下选项
    
    
    
      &t_page6_select                             ,//选项框不带进入
      &t_page6_select_2                          ,
      &t_page6_select_3                          ,
      &t_page6_select_4                          ,//（0~3）

//	&t_Setup_info_coulumn_new,//选项框不带进入
//	&t_Setup_info_coulumn_new_1,
//	&t_Setup_info_coulumn_new_2,
//	&t_Setup_info_coulumn_new_3,
	&t_Setup_info_coulumn_new_4,
	&t_Setup_info_coulumn_new_5,
    
    

//        &t_page6_left_up                            ,
// &t_page6_right_up                           ,    
//   &t_page6_left_d                             ,
// &t_page6_right_d                            ,  
// 
 
 
 
 	&t_page6_left_up,//向左返回箭头
	&t_page6_left_up_2,
	&t_page6_left_up_3,
    &t_page6_left_up_4,

//	&t_Setup_left_icon_up_new,//向左返回箭头
//	&t_Setup_left_icon_up_new_1,
//	&t_Setup_left_icon_up_new_2,
//	&t_Setup_left_icon_up_new_3,
    
    
	&t_Setup_left_icon_up_new_4,//占空
	&t_Setup_left_icon_up_new_5,
    
    
    &t_page6_right_up,//向右箭头
	&t_page6_right_up_2,
	&t_page6_right_up_3,
    &t_page6_right_up_4,

//&t_Setup_right_icon_up_new,//向右箭头
//	&t_Setup_right_icon_up_new_1,
//	&t_Setup_right_icon_up_new_2,
//	&t_Setup_right_icon_up_new_3,
//    
	&t_Setup_right_icon_up_new_4,//占空
	&t_Setup_right_icon_up_new_5,

&t_page6_s_back_d,////选项框带返回箭头

//     &t_page6_no_select_back                             ,
//&t_Setup_save_and_back_new,//选项框带返回箭头


	&t_Setup_info_column_upgrade_page,//升级背景
	&t_Setup_info_column_upgrade_button,//升级按键
	&t_Setup_info_column_upgrade_close,//升级退出
    
    
    &t_page6_temp_ico_2,//温度
};
lcd_dis_item_t *p_setup_item_main_d[SETUP_5_CHUN_ITME_NUM]={
    
    
    
        
   &t_page6_select2                          ,//03//选项框带进入（按下）
  &t_page6_select2_2                       ,
  &t_page6_select2_3                          ,
  &t_page6_select2_4                          ,  
    
//   &t_page6_no_select                          ,//03//选项框带进入（按下）
//  &t_page6_no_select2                          ,
//  &t_page6_no_select3                          ,
//  &t_page6_no_select4                          ,  
//	&t_Setup_info_column_enter_down_new,//选项框带进入（按下）
//	&t_Setup_info_column_enter_down_new_1,
//	&t_Setup_info_column_enter_down_new_2,
//	&t_Setup_info_column_enter_down_new_3,
    
	&t_Setup_info_column_enter_down_new_4,
	&t_Setup_info_column_enter_down_new_5,
    
    &t_page6_up_d                              ,//4
    &t_page6_down_d                            ,
//	&t_Setup_page_pre_down_new,//向上选项
//	&t_Setup_page_next_down_new,//向下选项
    
    
   &t_page6_no_select                          ,//03
  &t_page6_no_select2                          ,
  &t_page6_no_select3                          ,
  &t_page6_no_select4                          ,  
//	&t_Setup_info_coulumn_d_new,//选项框不带进入
//	&t_Setup_info_coulumn_d_new_1,
//	&t_Setup_info_coulumn_d_new_2,
//	&t_Setup_info_coulumn_d_new_3,
    
	&t_Setup_info_coulumn_d_new_4,
	&t_Setup_info_coulumn_d_new_5,


 	&t_page6_left_d,//向左返回箭头
	&t_page6_left_d_2,
	&t_page6_left_d_3,
    &t_page6_left_d_4,
    
//&t_Setup_left_icon_down_new,//向左返回箭头
//	&t_Setup_left_icon_down_new_1,
//	&t_Setup_left_icon_down_new_2,
//	&t_Setup_left_icon_down_new_3,
    
	&t_Setup_left_icon_down_new_4,
	&t_Setup_left_icon_down_new_5,


    &t_page6_right_d,//向右箭头
	&t_page6_right_d_2,
	&t_page6_right_d_3,
    &t_page6_right_d_4,
//&t_Setup_right_icon_down_new,//向右箭头
//	&t_Setup_right_icon_down_new_1,
//	&t_Setup_right_icon_down_new_2,
//	&t_Setup_right_icon_down_new_3,	
    
    
	&t_Setup_right_icon_down_new_4,	
	&t_Setup_right_icon_down_new_5,	

&t_page6_s_back_up,////选项框带返回箭头
//   &t_page6_no_select_back                          ,////选项框带返回箭头
//&t_Setup_save_and_back_new_down,//选项框带返回箭头



	&t_Setup_info_column_upgrade_page,//升级背景
	&t_Setup_info_column_upgrade_button_d,//升级按键
	&t_Setup_info_column_upgrade_close_d,//升级退出
    
        &t_page6_temp_ico_2,

};
lcd_dis_item_t setup_5_chun_item[SETUP_5_CHUN_ITME_NUM];

setup_item_info_t Power_system_info[]=
{
	{"",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},
	{"Output source priority",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_output_source_priority},
	{"Setting voltage point ",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_setting_vol_point_back_to_utility_source},
	{"Power saving mode",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_power_saving_mode},
	{"Charger source priority:",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_charger_source_priority},
    	{"",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},

	{"AC input voltage range",TOUCH_TYPE_NONE,setup_setting,empty_son_p,func_power_setting_ac_input_voltage_range},
	{"Maximum charging current",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_maximum_charging_current},
	{"Maximum utility charging current",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_max_utility_charging_current},
	{"Output voltage",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_output_voltage},
    	{"",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},

	{"Output frequency",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_output_fre},
	{"Alarm control",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_alarm_ctrl},
	{"Beeps ",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_beeps},
	{"Battery type",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_battery_type},
    	{"",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},

	{"Bulk charging voltage",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_bulk_charging_vol},
	{"Floating charging voltage",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_floating_charging_vol},
	{"Low DC cut-off voltage",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_low_dc_cut_off_vol},
	{"Auto restart when overload occurs",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_auto_restart_when_overload_occurs},
    	{"",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},

	{"Auto restart when temp occurs",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_auto_restart_when_temp_occurs},
	{"Record Fault code",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_power_setting_record_fault_code},    
	{"Battery equalization",TOUCH_TYPE_ENTER,setup_setting,empty_son_p,empty_fun},
	{"Restore default settings",TOUCH_TYPE_ENTER,setup_setting,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t Power_setting[]= //system setting
{
	{"System Settings",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	{"Data&Time",TOUCH_TYPE_ENTER,setup_setting,Data_Time,empty_fun},
	{"Language",TOUCH_TYPE_NONE,setup_setting,empty_son_p,func_sys_setting_language},
	{"Brightness",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_brightness},
     	{"System Settings",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},

  {"Sleep Time",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_sleep_time},

        
	//{"Tempreature unit",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_temperature_uint},
	{"Touc Tone",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_touch_tone},
	{"Restore Default Settings",TOUCH_TYPE_ENTER,setup_setting,Restore_Default_Settings_5,empty_fun},
        	{"System Settings",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},

 {"System Reset",TOUCH_TYPE_ENTER,setup_setting,System_Reset_5,empty_fun},

	{"Upgrade The Software",TOUCH_TYPE_ENTER,setup_setting,System_Upgrade_page,empty_fun},
           // 	{"System Settings",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},

	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},

    //{"System Settings",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
    
	//{"Light Up Screen When Alarm Occurs",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_light_up_screen_when_alarm_occurs},
	//{"Code Enter",TOUCH_TYPE_NORMAL,setup_setting,empty_son_p,func_sys_setting_Code_Enter},
};


setup_item_info_t System_Upgrade_page[]=
{
	{"System Settings->Upgrade",TOUCH_TYPE_SAVE_AND_BACK,Power_setting,empty_son_p,empty_fun},
	{"Input USB Disk and Press the Start",TOUCH_TYPE_UPGRADE,Power_setting,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t CanBus_Upgrade_page[]=
{
	{"System Settings->CanBus_Upgrade",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	{"Input USB Disk and Press the Start",TOUCH_TYPE_UPGRADE,setup_setting,empty_son_p,empty_fun}, //升级页面
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};



setup_item_info_t System_Reset_5[]=
{
	{"System Settings->Sys_reset",TOUCH_TYPE_SAVE_AND_BACK,Power_setting,empty_son_p,empty_fun},
	{"Yes",TOUCH_TYPE_ENTER,Power_setting,empty_son_p,func_sys_setting_system_reset},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t Restore_Default_Settings_5[]=
{
	{"System Settings->Restore_default",TOUCH_TYPE_SAVE_AND_BACK,Power_setting,empty_son_p,empty_fun},
	{"Yes",TOUCH_TYPE_ENTER,Power_setting,empty_son_p,func_sys_setting_restore_defualt},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t Data_Time[]=//时间设置
{
	{"System Settings->Data_time",TOUCH_TYPE_SAVE_AND_BACK,Power_setting,empty_son_p,empty_fun},
	{"Year_setting",TOUCH_TYPE_LEFT_RIGHT,Power_setting,empty_son_p,func_sys_setting_year_setting},
	{"Mon_setting",TOUCH_TYPE_LEFT_RIGHT,Power_setting,empty_son_p,func_sys_setting_mon_setting},
	{"Day_setting",TOUCH_TYPE_LEFT_RIGHT,Power_setting,empty_son_p,func_sys_setting_day_setting},
    
    {"System Settings->Data_time",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	{"Hour_setting",TOUCH_TYPE_LEFT_RIGHT,Power_setting,empty_son_p,func_sys_setting_hour_setting},
	{"Min_setting",TOUCH_TYPE_LEFT_RIGHT,Power_setting,empty_son_p,func_sys_setting_min_setting},
	{"Sec_setting",TOUCH_TYPE_LEFT_RIGHT,Power_setting,empty_son_p,func_sys_setting_sec_setting},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};



setup_item_info_t Battery_info_select[] = 
{
	{"Power_System_Settings->Batt_select",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
	{"No Connect",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Batt_Type_0},
	{"LINKS2 KL500A 50MV/0.1V 120V 500A",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Batt_Type_1},
	{"Victron SmartShunt IP65 500A/50mV",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Batt_Type_2},  
    
    	{"Power_System_Settings->Batt_select",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
	{"LINKS2 RV-BAT 12-400",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Batt_Type_3},
	{"Battery Type(RV-C)",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Batt_Type_4},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
	
setup_item_info_t Inverter_info_select[] = 
{
	{"Power_System_Settings->Inv_select",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
	{"No Connect",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Inverter_Type_0},
	{"Victron VE.BUS",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Inverter_Type_1},
	{"LINKS2 12V 3000W Inverter Charger",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Inverter_Type_2},
    
    	{"Power_System_Settings->Inv_select",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
	{"Inverter Type(RV-C)",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Inverter_Type_3},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t Mppt_info_select[] = 
{
	{"Power_System_Settings->Mppt_select",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
	{"No Connect",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Mppt_Type_0},
	{"SRNE MA4830N15 12-48V 30A 1600W",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Mppt_Type_1},
	{"Victron SmartSolar Charger 100/50",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Mppt_Type_2},
    
    	{"Power_System_Settings->Mppt_select",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
	{"LINKS2 12V50A DC Charger with MPPT",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Mppt_Type_3},
	{"MPPT Type(RV-C)",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_Mppt_Type_4},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t DcDc_info_select[] = 
{
	{"Power_System_Settings->DCDC_select",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
	{"No Connect",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_DcDc_Type_0},
	{"LINKS2 12V50A DC Charger with MPPT",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_DcDc_Type_1},
	{"DC_Charger Type(RV-C)",TOUCH_TYPE_ENTER,Power_System_Setting,empty_son_p,func_power_system_info_DcDc_Type_2},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t Batt_settings[]=
{
	{"Power_System_Settings->Batt_set",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
  {"Battery Capacity",TOUCH_TYPE_NORMAL,Power_System_Setting,empty_son_p,func_power_system_setting_batt_capacity},
	{"Percentage of Battery Capacity",TOUCH_TYPE_NORMAL,Power_System_Setting,empty_son_p,func_power_ststem_setting_batt_soc},	
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t Inv_settings[]=
{
	{"Power_System_Settings->Inv_set",TOUCH_TYPE_SAVE_AND_BACK,Power_System_Setting,empty_son_p,empty_fun},
	{"Input Current Limit",TOUCH_TYPE_NORMAL,Power_System_Setting,empty_son_p,func_power_system_setting_victron_multiplus_inv},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t System_setting[]= //power_system_info
{ 
	{"Power System info",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	{"",TOUCH_TYPE_BACKGROUND,setup_setting,empty_son_p,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t System_info[]=
{
	{"System info",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
//	{"BLE connect code:",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},
	//{"BLE Name:",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},
	{"MCU Software:",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},
	
    {"UI Sofrware:",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},
	{"System info",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	
    {"Control Unit MCU:",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},
	{"Control Unit SlaveMCU:",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},
    	
	{"External_protocol MCU:",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},
   // {"System info",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
        
    {"",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};
setup_item_info_t Power_System_Setting[]=
{
	{"Power_System_Settings",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	{"Battery info",TOUCH_TYPE_ENTER,setup_setting,Battery_info_select,empty_fun},
	{"Inverter info",TOUCH_TYPE_ENTER,setup_setting,Inverter_info_select,empty_fun},
	{"Mppt info",TOUCH_TYPE_ENTER,setup_setting,Mppt_info_select,empty_fun},
    
    	{"Power_System_Settings",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	{"DcDc info",TOUCH_TYPE_ENTER,setup_setting,DcDc_info_select,empty_fun},
	{"SmartShunt Settings",TOUCH_TYPE_ENTER,setup_setting,Batt_settings,empty_fun},
	{"Victron Multiplus Inverter",TOUCH_TYPE_ENTER,setup_setting,Inv_settings,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};


setup_item_info_t new_Data_Time[]=//时间设置
{
	{"setup_setting",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	{"Year_setting",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_year_setting},
	{"Mon_setting",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_mon_setting},
	{"Day_setting",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_day_setting},
    
    {"setup_setting",TOUCH_TYPE_SAVE_AND_BACK,setup_setting,empty_son_p,empty_fun},
	{"Hour_setting",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_hour_setting},
	{"Min_setting",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_min_setting},
	{"Sec_setting",TOUCH_TYPE_LEFT_RIGHT,setup_setting,empty_son_p,func_sys_setting_sec_setting},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};

setup_item_info_t setup_setting[]=
{
	//{"Power Settings",TOUCH_TYPE_ENTER,empty_father_p,Power_system_info,empty_fun},
       // {"",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},


    
//    {"Power System Settings",TOUCH_TYPE_ENTER,empty_father_p,Power_System_Setting,empty_fun},
//	{"Power System info",TOUCH_TYPE_ENTER,empty_father_p,System_setting,empty_fun},
    
    
	{"System Settings",TOUCH_TYPE_ENTER,empty_father_p,Power_setting,empty_fun},
	{"System info",TOUCH_TYPE_ENTER,empty_father_p,System_info,empty_fun},
    
    
//    //未做完，暂时放次页
//    {"Temperature unit",TOUCH_TYPE_Temperature,empty_father_p,setup_setting,empty_fun},  
//	{"Data&Time",TOUCH_TYPE_ENTER,empty_father_p,new_Data_Time,empty_fun},
//	{"Version Information",TOUCH_TYPE_ENTER,empty_father_p,System_info,empty_fun},
//	{"CanBus UpGrade",TOUCH_TYPE_ENTER_Upgrade,empty_father_p,CanBus_Upgrade_page,empty_fun},    
//    



	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
	//{"",TOUCH_TYPE_ENTER,empty_father_p,empty_son_p,empty_fun},
	//{"",TOUCH_TYPE_ENTER,empty_father_p,empty_son_p,empty_fun},
	//{"",TOUCH_TYPE_ENTER,empty_father_p,empty_son_p,empty_fun}
};










setup_page_t setup_page_sta;

void func_sys_setting_year_setting(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	
	//memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
	if(deal_type==TO_INIT)
	{
		f_system_Date_Time_set = TRUE;
		sprintf(display_buf,"%02d",time_status.year);		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		time_status.year++;
		if(time_status.year>99)
			time_status.year = 1;
	}
	else if(deal_type==TO_DOWN)
	{
		if(time_status.year) 
			time_status.year--;
	}
}
//void func_sys_setting_mon_setting(void* p,u8 sn,DEAl_TYPE deal_type)
//{
//	char display_buf[32];
//	
//	//memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
//	if(deal_type==TO_INIT)
//	{
//		f_system_Date_Time_set = TRUE;
//		sprintf(display_buf,"%02d",time_status.mon);		
//		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
//	}
//	else if(deal_type==TO_UP)
//	{  
//		time_status.mon++;
//		if(time_status.mon>12)
//			time_status.mon = 1;
//	}
//	else if(deal_type==TO_DOWN)
//	{
//	  time_status.mon--;
//		if(time_status.mon==0) 
//			time_status.mon = 12;
//	}
//}


int Get_Max_Day(int year, int mon)
{
    switch (mon)
    {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return Is_Leap_Year(year) ? 29 : 28;
    }
    return 30;
}

void func_sys_setting_mon_setting(void* p,u8 sn,DEAl_TYPE deal_type)
{
    char display_buf[32];

    if(deal_type==TO_INIT)
    {
        f_system_Date_Time_set = TRUE;
        sprintf(display_buf,"%02d",time_status.mon);
        Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(
            setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,
            setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,
            display_buf,(ARGB_mydarkcyan),0,1,1);
    }
    else if(deal_type==TO_UP)
    {
        time_status.mon++;
        if(time_status.mon > 12)
            time_status.mon = 1;

        // ★ 修正天数
        int max = Get_Max_Day(time_status.year, time_status.mon);
        if (time_status.day > max) time_status.day = max;
    }
    else if(deal_type==TO_DOWN)
    {
        time_status.mon--;
        if(time_status.mon == 0)
            time_status.mon = 12;

        // ★ 修正天数
        int max = Get_Max_Day(time_status.year, time_status.mon);
        if (time_status.day > max) time_status.day = max;
    }
}


void func_sys_setting_day_setting(void* p,u8 sn,DEAl_TYPE deal_type)
{
    char display_buf[32];

    if(deal_type==TO_INIT)
    {
        f_system_Date_Time_set = TRUE;
        sprintf(display_buf,"%02d",time_status.day);
        Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(
            setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,
            setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,
            display_buf,(ARGB_mydarkcyan),0,1,1);
    }

    int max;

    if (deal_type == TO_UP)
    {
        time_status.day++;

        max = Get_Max_Day(time_status.year, time_status.mon);
        if (time_status.day > max)
        {
            time_status.day = 1;
            time_status.mon++;

            if (time_status.mon > 12)
                time_status.mon = 1;
        }
    }
    else if (deal_type == TO_DOWN)
    {
        time_status.day--;
        if (time_status.day == 0)
        {
            time_status.mon--;
            if (time_status.mon == 0)
                time_status.mon = 12;

            time_status.day = Get_Max_Day(time_status.year, time_status.mon);
        }
    }
}

//void func_sys_setting_day_setting(void* p,u8 sn,DEAl_TYPE deal_type)
//{
//	char display_buf[32];
//	
//	//memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
//	if(deal_type==TO_INIT)
//	{
//		f_system_Date_Time_set = TRUE;
//		sprintf(display_buf,"%02d",time_status.day);		
//		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
//	}
//    

//                if (deal_type == TO_UP)
//            {
//                time_status.day++;

//                int max = Get_Max_Day(time_status.year, time_status.mon);
//                if (time_status.day > max)
//                {
//                    time_status.day = 1;
//                    time_status.mon++;
//                    if (time_status.mon > 12)
//                    {
//                        time_status.mon = 1;
//                       // time_status.year++; // 如果需要
//                    }
//                }
//            }
//            else if (deal_type == TO_DOWN)
//            {
//                time_status.day--;

//                if (time_status.day == 0)
//                {
//                    time_status.mon--;
//                    if (time_status.mon == 0)
//                    {
//                        time_status.mon = 12;
//                        //time_status.year--; // 如果需要
//                    }

//                    time_status.day = Get_Max_Day(time_status.year, time_status.mon);
//                }
//            }

//}




void func_sys_setting_hour_setting(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	
	//memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
	if(deal_type==TO_INIT)
	{
		f_system_Date_Time_set = TRUE;
		sprintf(display_buf,"%02d",time_status.hour);		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		time_status.hour++;
		if(time_status.hour>23) 
			time_status.hour = 0;
	}
	else if(deal_type==TO_DOWN)
	{
		if(time_status.hour==0) 
			time_status.hour = 23;
		else
			time_status.hour--;
	}
}
void func_sys_setting_min_setting(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	
	//memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
	if(deal_type==TO_INIT)
	{
		f_system_Date_Time_set = TRUE;
		sprintf(display_buf,"%02d",time_status.min);		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		time_status.min++;
		if(time_status.min > 59)
			time_status.min = 0;
	}
	else if(deal_type==TO_DOWN)
	{
	  if(time_status.min==0) 
		{								
			time_status.min=59;
		}
		else
			time_status.min--;
	}
}
void func_sys_setting_sec_setting(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	
	//memcpy(&time_status,&time_return_status,sizeof(TIME_STATUS));
	if(deal_type==TO_INIT)
	{
		f_system_Date_Time_set = TRUE;
		sprintf(display_buf,"%02d",time_status.sec);		
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		time_status.sec++;
		if(time_status.sec > 59)
			time_status.sec = 0;
	}
	else if(deal_type==TO_DOWN)
	{
		if(time_status.sec==0) 
		{								
			time_status.sec=59;
		}
		else
			time_status.sec--;
	}
}
void func_sys_setting_language(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	 // sysprintf("\r\n---- deal_type:%d sn %d,",deal_type,sn);
	if(deal_type==TO_INIT)
	{
		if(base_return_status.language==0)
			sprintf(display_buf,"English");
			//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"English",(ARGB_mydarkcyan),0,1,1);
		else if(base_return_status.language==1)
			sprintf(display_buf,"Chinese");
			//Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"Chinese",(ARGB_mydarkcyan),0,1,1);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{
		
	}
	else if(deal_type==TO_DOWN)
	{
		
	}
}
void func_sys_setting_temperature_uint(void* p,u8 sn,DEAl_TYPE deal_type)//设置温度单位
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if((base_return_status.uint&0x0C)==0x00)
			sprintf(display_buf,"C");
		else if((base_return_status.uint&0x0C)==0x04)
			sprintf(display_buf,"F");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
		Virtual_LCD_Draw_String_o(get_str_align_center_x_val(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,"C",glyph_dsc_24_4bit),setup_5_chun_item[sn].y_val+30,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{
		if((base_return_status.uint&0x0C)==0x00)
		{ // F
			base_status.uint&=0xF3;
			base_return_status.uint&=0xF3;
			base_status.uint|=0x04;
      base_return_status.uint|=0x04;
			send_FlC200_base_set_cmd(0x01,1,0);
		}
		else
		{
		  //C
		  now_page = 0x0000;
			base_status.uint&=0xF3;
      base_return_status.uint&=0xF3;
			// base_status.uint|=0x04;
      // base_return_status.uint|=0x04;
			send_FlC200_base_set_cmd(0x01,0,0);
		}
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if((base_return_status.uint&0x0C)==0x00)
		{ // F
			base_status.uint&=0xF3;
			base_return_status.uint&=0xF3;
			base_status.uint|=0x04;
			base_return_status.uint|=0x04;
			send_FlC200_base_set_cmd(0x01,1,0);
		}
		else
		{
			//C
			now_page = 0x0000;
			base_status.uint&=0xF3;
			base_return_status.uint&=0xF3;
			// base_status.uint|=0x04;
			// base_return_status.uint|=0x04;
			send_FlC200_base_set_cmd(0x01,0,0);
		}
		f_display_set_info = TRUE;
	}
}
void func_sys_setting_brightness(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	
	if(deal_type==TO_INIT)
	{
		if(base_return_status.light<=110)
			sprintf(display_buf,"Low");
			// Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"Low",(ARGB_mydarkcyan),0,1,1);
		else if(base_return_status.light<=160)
			sprintf(display_buf,"Mid");
			// Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(system_item[sn].x_val+X_set_mid_offset,system_item[sn].y_val+Y_system_system_offset,"Mid",(ARGB_mydarkcyan),0,1,1);
	  else //if(base_return_status.light<=200)
			sprintf(display_buf,"Hi");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(base_return_status.light<=110)
		{
			base_status.light = 160;//mid
			base_return_status.light = 160;
		  send_FlC200_base_set_cmd(0x08,base_status.light,0);
			f_display_set_info = TRUE;
		}
		else if(base_return_status.light<=170)
		{
			base_status.light = 180;//hi
      base_return_status.light = 180;
			send_FlC200_base_set_cmd(0x08,base_status.light,0);
			f_display_set_info = TRUE;
		}
		else
		{
		
		}
	}
	else if(deal_type==TO_DOWN)
	{
	  if(base_return_status.light<=110)
		{
			 // base_status.light = 255;
     //base_return_status.light = 255;
			 //send_FlC200_base_set_cmd(0x08,base_status.light,0);
			// f_display_set_info = TRUE;
		}
		else if(base_return_status.light<=160)
		{
			base_status.light = 110;
			base_return_status.light = 110;
			send_FlC200_base_set_cmd(0x08,base_status.light,0);
			f_display_set_info = TRUE;
		}
		else
		{
			base_status.light = 160;
			base_return_status.light = 160;
			send_FlC200_base_set_cmd(0x08,base_status.light,0);
			f_display_set_info = TRUE;
		}
	}
}
void func_sys_setting_sleep_time(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
  if(deal_type==TO_INIT)
	{
		if(base_return_status.sleep_time==0)
			sprintf(display_buf,"Off");
		else if(base_return_status.sleep_time<=60)
			sprintf(display_buf,"%02d Min",base_return_status.sleep_time);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		base_return_status.sleep_time++;
		if(base_return_status.sleep_time>60)
			base_return_status.sleep_time = 60;
		send_FlC200_base_set_cmd(0x10,base_return_status.sleep_time,0);
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
	  if(base_return_status.sleep_time)
			base_return_status.sleep_time--;
		send_FlC200_base_set_cmd(0x10,base_return_status.sleep_time,0);
		f_display_set_info = TRUE;
	}
}
void func_sys_setting_touch_tone(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if((base_return_status.touch_tone&0x01)==0x00)
			sprintf(display_buf,"Off");
		else  
			sprintf(display_buf,"On");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if((base_return_status.touch_tone&0x01)==0x00)
			base_return_status.touch_tone |= 0x01;
		else  
			base_return_status.touch_tone &= 0xFE;
		send_FlC200_base_set_cmd(0x11,(base_return_status.touch_tone&0x01),0);
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if((base_return_status.touch_tone&0x01)==0x00)
			base_return_status.touch_tone |= 0x01;
		else  
			base_return_status.touch_tone &= 0xFE;
		send_FlC200_base_set_cmd(0x11,(base_return_status.touch_tone&0x01),0);
		f_display_set_info = TRUE;
	}
}
void func_sys_setting_light_up_screen_when_alarm_occurs(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if((base_return_status.touch_tone&0x04)==0x00)
			sprintf(display_buf,"Off");
		else  
			sprintf(display_buf,"On");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if((base_return_status.touch_tone&0x04)==0x00)
		{
			base_return_status.touch_tone |= 0x04;
			send_FlC200_base_set_cmd(0x11,0x21,0);
		}
		else  
		{
			base_return_status.touch_tone &= 0xFB;
			send_FlC200_base_set_cmd(0x11,0x20,0);
		}
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if((base_return_status.touch_tone&0x04)==0x00)
		{
			base_return_status.touch_tone |= 0x04;
			send_FlC200_base_set_cmd(0x11,0x21,0);
		}
		else  
		{
			base_return_status.touch_tone &= 0xFB;
			send_FlC200_base_set_cmd(0x11,0x20,0);
		}
		f_display_set_info = TRUE;
	}
}
void func_sys_setting_Code_Enter(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		
	}
	else if(deal_type==TO_UP)
	{
			
	}
	else if(deal_type==TO_DOWN)
	{
		
	}
	else if(deal_type==TO_DEAL)
	{
		keyboard_ui_step=KEYBOARD_PAGE_NOR;
		f_ui_new_input_code_enter = TRUE;
		f_need_ui_disply_keyboard = TRUE;
	}
}
void func_sys_setting_restore_defualt(void* p,u8 sn,DEAl_TYPE deal_type)
{
	setup_item_info_t *setup_p;
	if(deal_type==TO_INIT)
	{
		
	}
	else if(deal_type==TO_UP)
	{
		
	}
	else if(deal_type==TO_DOWN)
	{
	
	}
	else if(deal_type==TO_DEAL)
	{
		//send_FlC200_base_set_cmd(0x88,0x01,0);
		send_FlC200_base_set_cmd(0x81,0xFF,0);
		setup_p = &setup_page_sta.now_p[0];
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_SETUP2)
		{    
			if(setup_p->father_p!=empty_father_p)	
			{  
				//setup_page.now_page_num = 0;
				if(last_show_page_level>0)
				 	last_show_page_level--;
				setup_page_sta.now_page_num = last_show_page_num[last_show_page_level] ;
				//sysprintf("setup_page_sta.now_page_num = %d \r\n",setup_page_sta.now_page_num);
				f_system_Date_Time_set = FALSE;
				//setup_page_sta.now_page_num=last_now_page_num;
				if(setup_page_sta.now_p == Data_Time)
				{
				 	memcpy(&time_return_status,&time_status,sizeof(TIME_STATUS));
				  send_FlC200_time_set_cmd();
				}
   				if(setup_page_sta.now_p == new_Data_Time)
				{
				 	memcpy(&time_return_status,&time_status,sizeof(TIME_STATUS));
				  send_FlC200_time_set_cmd();
				}             
                
				setup_page_sta.now_p = setup_p->father_p;
		    page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
		    f_display_set_info = TRUE;
			}
		}
	}
}
void func_sys_setting_system_reset(void* p,u8 sn,DEAl_TYPE deal_type)
{
	if(deal_type==TO_INIT)
	{
		
	}
	else if(deal_type==TO_UP)
	{
	
	}
	else if(deal_type==TO_DOWN)
	{
	
	}
	else if(deal_type==TO_DEAL)
	{
		//send_FlC200_base_set_cmd(0x88,0x01,0);
		send_FlC200_base_set_cmd(0x81,0xFE,0);
	}
}
void func_power_system_setting_batt_capacity(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	
	if(deal_type==TO_INIT)
	{
		sprintf(display_buf,"%dAH",parts_set_return_status.Capacity/10);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		parts_set_return_status.Capacity+=200;
		if(parts_set_return_status.Capacity>=10000)
			parts_set_return_status.Capacity = 10000;
		send_FlC200_set_cmd(0x40,parts_set_return_status.Capacity);
	}
	else if(deal_type==TO_DOWN)
	{
		if(parts_set_return_status.Capacity>10000)
			parts_set_return_status.Capacity = 0;
		else if(parts_set_return_status.Capacity>0 && parts_set_return_status.Capacity<10000)
			parts_set_return_status.Capacity -= 200;
		send_FlC200_set_cmd(0x40,parts_set_return_status.Capacity);
	}
	else if(deal_type==TO_DEAL)
	{
		char_input_target_type = 2;
		f_ui_new_input_bat_capacity = TRUE;
		f_ui_new_input_bat_percenage = FALSE;
		f_ui_new_input_inv_limit_cur= FALSE;
	}
}
void func_power_ststem_setting_batt_soc(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		sprintf(display_buf,"%d%%",parts_set_return_status.Percentage);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{
		parts_set_return_status.Percentage+=1;
		if(parts_set_return_status.Percentage>=100)
			parts_set_return_status.Percentage = 100;
		send_FlC200_set_cmd(0x41,parts_set_return_status.Percentage);
	}
	else if(deal_type==TO_DOWN)
	{
		if(parts_set_return_status.Percentage>0)
			parts_set_return_status.Percentage -= 1;
		else
			parts_set_return_status.Percentage = 0;
		send_FlC200_set_cmd(0x41,parts_set_return_status.Percentage);
	}
	else if(deal_type==TO_DEAL)
	{
		char_input_target_type = 3;
		f_ui_new_input_bat_capacity = FALSE;
		f_ui_new_input_bat_percenage = TRUE;
		f_ui_new_input_inv_limit_cur= FALSE;
	}
}
void func_power_system_setting_victron_multiplus_inv(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		sprintf(display_buf,"%d.%dA",parts_set_return_status.Inverter_Input_Current_Limit/10,parts_set_return_status.Inverter_Input_Current_Limit%10);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{
		//send_FlC200_set_cmd(0x4A,parts_set_return_status.Inverter_Input_Current_Limit);
	}
	else if(deal_type==TO_DOWN)
	{
		//send_FlC200_set_cmd(0x4A,parts_set_return_status.Inverter_Input_Current_Limit);
	}
	else if(deal_type==TO_DEAL)
	{
		char_input_target_type = 1;
		f_ui_new_input_bat_capacity = FALSE;
		f_ui_new_input_bat_percenage = FALSE;
		f_ui_new_input_inv_limit_cur = TRUE;
	}
}
void func_power_setting_output_source_priority(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{	
		if(acopower_inv.output_source_priority==0x00)
			sprintf(display_buf,"SUB");
		else  
			sprintf(display_buf,"SBU");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		f_display_set_info = TRUE;
		if(acopower_inv.output_source_priority==0x00)
			acopower_inv.output_source_priority = 0x01;
		else if(acopower_inv.output_source_priority==0x01)
			acopower_inv.output_source_priority = 0x00;
	}
	else if(deal_type==TO_DOWN)
	{
		f_display_set_info = TRUE;
		if(acopower_inv.output_source_priority==0x00)
			acopower_inv.output_source_priority = 0x01;
		else if(acopower_inv.output_source_priority==0x01)
			acopower_inv.output_source_priority = 0x00;
	}
}
void func_power_setting_setting_vol_point_back_to_utility_source(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	static u8 temp_vol = 105;
	if(deal_type==TO_INIT)
	{
		acopower_inv.vol_point_back_to_utility_source = temp_vol;
		sprintf(display_buf,"%d.%dV",temp_vol/10,temp_vol%10);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		f_display_set_info = TRUE;
		if(temp_vol<140)
			temp_vol +=5;
		else
			temp_vol = 105;
		acopower_inv.vol_point_back_to_utility_source = temp_vol;
	}
	else if(deal_type==TO_DOWN)
	{
		f_display_set_info = TRUE;
		if(temp_vol>105)
			temp_vol-=5;
		else
			temp_vol = 140;
		acopower_inv.vol_point_back_to_utility_source = temp_vol;
	}
}
void func_power_setting_power_saving_mode(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if(acopower_inv.power_saving_mode == 0x01)
			sprintf(display_buf,"Enable");
		else  if(acopower_inv.power_saving_mode == 0x00)
			sprintf(display_buf,"Disable");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(acopower_inv.power_saving_mode == 0x01)
			acopower_inv.power_saving_mode = 0x00;
		else  if(acopower_inv.power_saving_mode == 0x00)
			acopower_inv.power_saving_mode = 0x01;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		f_display_set_info = TRUE;
		if(acopower_inv.power_saving_mode == 0x01)
			acopower_inv.power_saving_mode = 0x00;
		else  if(acopower_inv.power_saving_mode == 0x00)
			acopower_inv.power_saving_mode = 0x01;
	}
}
void func_power_setting_charger_source_priority(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if(acopower_inv.charger_source_priority == 0x01)
			sprintf(display_buf,"Solar Utility");
		else if(acopower_inv.charger_source_priority == 0x00)
			sprintf(display_buf,"Solar first");
		else if(acopower_inv.charger_source_priority == 0x02)
			sprintf(display_buf,"Only solar");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(acopower_inv.charger_source_priority==0x02)
			acopower_inv.charger_source_priority = 0x00;
		else
			acopower_inv.charger_source_priority++;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(acopower_inv.charger_source_priority==0x00)
			acopower_inv.charger_source_priority = 0x02;
		else
			acopower_inv.charger_source_priority--;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_ac_input_voltage_range(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		sprintf(display_buf,"UPS");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		//f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		//f_display_set_info = TRUE;
	}
}
void func_power_setting_maximum_charging_current(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	static u8 max_charging_cur = 10;
	if(deal_type==TO_INIT)
	{
		acopower_inv.max_charging_cur = max_charging_cur;
		sprintf(display_buf,"%dA",max_charging_cur);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(max_charging_cur==150)
			max_charging_cur=10;
		else
			max_charging_cur+=10;
		acopower_inv.max_charging_cur = max_charging_cur;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(max_charging_cur==10)
			max_charging_cur=150;
		else
			max_charging_cur-=10;
		acopower_inv.max_charging_cur = max_charging_cur;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_max_utility_charging_current(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	static u8 max_utility_charge_cur = 30;
	if(deal_type==TO_INIT)
	{
		acopower_inv.max_utility_charging_cur = max_utility_charge_cur;
		sprintf(display_buf,"%dA",max_utility_charge_cur);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(max_utility_charge_cur==150)
			max_utility_charge_cur = 10;
		else if(max_utility_charge_cur==80)
			max_utility_charge_cur = 150;
		else
			max_utility_charge_cur+= 10;
		acopower_inv.max_utility_charging_cur = max_utility_charge_cur;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(max_utility_charge_cur==150)
			max_utility_charge_cur = 80;
		else if(max_utility_charge_cur==10)
			max_utility_charge_cur = 150;
		else
			max_utility_charge_cur-= 10;
		acopower_inv.max_utility_charging_cur = max_utility_charge_cur;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_output_voltage(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	static u8 temp_output_vol = 120;
	if(deal_type==TO_INIT)
	{
		acopower_inv.output_vol = temp_output_vol;
		sprintf(display_buf,"%dV",temp_output_vol);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(temp_output_vol==130)
			temp_output_vol = 110;
		else
			temp_output_vol+= 10;
		acopower_inv.output_vol = temp_output_vol;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(temp_output_vol==110)
			temp_output_vol = 130;
		else
			temp_output_vol-= 10;
		acopower_inv.output_vol = temp_output_vol;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_output_fre(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	static u8 output_fre=60;
	if(deal_type==TO_INIT)
	{
		acopower_inv.output_fre = output_fre;
		sprintf(display_buf,"%dHz",output_fre);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(output_fre==60)
			output_fre = 50;
		else
			output_fre = 60;
		acopower_inv.output_fre = output_fre;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(output_fre==60)
			output_fre = 50;
		else
			output_fre = 60;
		acopower_inv.output_fre = output_fre;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_alarm_ctrl(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if(acopower_inv.alarm_ctrl==0x00)
			sprintf(display_buf,"On");
		else  
			sprintf(display_buf,"Off");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(acopower_inv.alarm_ctrl==0x01)
			acopower_inv.alarm_ctrl = 0x00;
		else
			acopower_inv.alarm_ctrl = 0x01;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(acopower_inv.alarm_ctrl==0x01)
			acopower_inv.alarm_ctrl = 0x00;
		else
			acopower_inv.alarm_ctrl = 0x01;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_beeps(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if(acopower_inv.beeps==0x00)
			sprintf(display_buf,"On");
		else  
			sprintf(display_buf,"Off");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(acopower_inv.beeps==0x01)
			acopower_inv.beeps = 0x00;
		else
			acopower_inv.beeps = 0x01;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(acopower_inv.beeps==0x01)
			acopower_inv.beeps = 0x00;
		else
			acopower_inv.beeps = 0x01;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_battery_type(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if(acopower_inv.battery_type==0x00)
			sprintf(display_buf,"AGM");
		else if(acopower_inv.battery_type==0x01)
			sprintf(display_buf,"Flooded");
		else if(acopower_inv.battery_type==0x02)
			sprintf(display_buf,"Lithium");
		else if(acopower_inv.battery_type==0x03)
			sprintf(display_buf,"Use-Defined");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(acopower_inv.battery_type==0x03)
			acopower_inv.battery_type = 0;
		else
			acopower_inv.battery_type++;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(acopower_inv.battery_type==0x00)
			acopower_inv.battery_type = 3;
		else
			acopower_inv.battery_type--;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_bulk_charging_vol(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	static u8 temp_bulk_charge_vol = 146;
	if(deal_type==TO_INIT)
	{
		acopower_inv.bulk_charging_vol = temp_bulk_charge_vol;
		sprintf(display_buf,"%d.%dV",temp_bulk_charge_vol/10,temp_bulk_charge_vol%10);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(temp_bulk_charge_vol==146)
			temp_bulk_charge_vol=120;
		else
			temp_bulk_charge_vol++;
		f_display_set_info = TRUE;
		acopower_inv.bulk_charging_vol = temp_bulk_charge_vol;
	}
	else if(deal_type==TO_DOWN)
	{
		if(temp_bulk_charge_vol==120)
			temp_bulk_charge_vol=146;
		else
			temp_bulk_charge_vol--;
		f_display_set_info = TRUE;
		acopower_inv.bulk_charging_vol = temp_bulk_charge_vol;
	}
}
void func_power_setting_floating_charging_vol(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	static u8 temp_float_charge_vol = 146;
	if(deal_type==TO_INIT)
	{
		acopower_inv.float_charging_vol = temp_float_charge_vol;
		sprintf(display_buf,"%d.%dV",temp_float_charge_vol/10,temp_float_charge_vol%10);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(temp_float_charge_vol==146)
			temp_float_charge_vol=120;
		else
			temp_float_charge_vol++;
		f_display_set_info = TRUE;
		acopower_inv.float_charging_vol = temp_float_charge_vol;
	}
	else if(deal_type==TO_DOWN)
	{
		if(temp_float_charge_vol==120)
			temp_float_charge_vol=146;
		else
			temp_float_charge_vol--;
		f_display_set_info = TRUE;
		acopower_inv.float_charging_vol = temp_float_charge_vol;
	}
}
void func_power_setting_low_dc_cut_off_vol(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	static u8 temp_low_dc_cut_off_vol = 105;
	if(deal_type==TO_INIT)
	{
		acopower_inv.low_dc_cut_off_vol = temp_low_dc_cut_off_vol;
		sprintf(display_buf,"%d.%dV",temp_low_dc_cut_off_vol/10,temp_low_dc_cut_off_vol%10);
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(temp_low_dc_cut_off_vol==120)
			temp_low_dc_cut_off_vol=100;
		else
			temp_low_dc_cut_off_vol++;
		f_display_set_info = TRUE;
		acopower_inv.low_dc_cut_off_vol = temp_low_dc_cut_off_vol;
	}
	else if(deal_type==TO_DOWN)
	{
		if(temp_low_dc_cut_off_vol==100)
			temp_low_dc_cut_off_vol=120;
		else
			temp_low_dc_cut_off_vol--;
		f_display_set_info = TRUE;
		acopower_inv.low_dc_cut_off_vol = temp_low_dc_cut_off_vol;
	}
}
void func_power_setting_auto_restart_when_overload_occurs(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if(acopower_inv.restart_overload_occurs==0x00)
			sprintf(display_buf,"Disable");
		else
			sprintf(display_buf,"Enable");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(acopower_inv.restart_overload_occurs==0x00)
			acopower_inv.restart_overload_occurs = 0x01;
		else
			acopower_inv.restart_overload_occurs = 0x00;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(acopower_inv.restart_overload_occurs==0x00)
			acopower_inv.restart_overload_occurs = 0x01;
		else
			acopower_inv.restart_overload_occurs = 0x00;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_auto_restart_when_temp_occurs(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if(acopower_inv.restart_temp_occurs==0x00)
			sprintf(display_buf,"Enable");
		else
			sprintf(display_buf,"Disable");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(acopower_inv.restart_temp_occurs==0x00)
			acopower_inv.restart_temp_occurs = 0x01;
		else
			acopower_inv.restart_temp_occurs = 0x00;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(acopower_inv.restart_temp_occurs==0x00)
			acopower_inv.restart_temp_occurs = 0x01;
		else
			acopower_inv.restart_temp_occurs = 0x00;
		f_display_set_info = TRUE;
	}
}
void func_power_setting_record_fault_code(void* p,u8 sn,DEAl_TYPE deal_type)
{
	char display_buf[32];
	if(deal_type==TO_INIT)
	{
		if(acopower_inv.record_fault_code==0x00)
			sprintf(display_buf,"Enable");
		else
			sprintf(display_buf,"Disable");
		Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_5_chun_item[sn].x_val+SETUP_X_set_mid_offset,setup_5_chun_item[sn].y_val+SETUP_Y_set_mid_offset,display_buf,(ARGB_mydarkcyan),0,1,1);
	}
	else if(deal_type==TO_UP)
	{  
		if(acopower_inv.record_fault_code==0x00)
			acopower_inv.record_fault_code = 0x01;
		else
			acopower_inv.record_fault_code = 0x00;
		f_display_set_info = TRUE;
	}
	else if(deal_type==TO_DOWN)
	{
		if(acopower_inv.record_fault_code==0x00)
			acopower_inv.record_fault_code = 0x01;
		else
			acopower_inv.record_fault_code = 0x00;
		f_display_set_info = TRUE;
	}
}
void func_batt_type(void* p,u8 sn,DEAl_TYPE deal_type,u8 type)
{
	setup_item_info_t *setup_p;
	if(deal_type==TO_INIT)
	{
		
	}
	else if(deal_type==TO_UP)
	{
	
	}
	else if(deal_type==TO_DOWN)
	{
	
	}
	else if(deal_type==TO_DEAL)
	{
		type_sel.Battery_SmartShun_Type = type;
		send_FlC200_set_cmd(0x85,1*256+type);
		
		setup_p = &setup_page_sta.now_p[0];
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_SETUP2)
		{
				//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			if(setup_p->father_p!=empty_father_p)	
			{
					//setup_page.now_page_num = 0;
					//f_system_Date_Time_set = FALSE;
				if(last_show_page_level>0)
					last_show_page_level--;
				setup_page_sta.now_page_num = last_show_page_num[last_show_page_level] ;
				setup_page_sta.now_p = setup_p->father_p;
				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
				f_display_set_info = TRUE;
				if(type_sel.Battery_SmartShun_Type == BATTERY_LINKS2_KL500A)
					Power_System_Setting[5].setup_menu_touch_type = TOUCH_TYPE_ENTER;
				else
					Power_System_Setting[5].setup_menu_touch_type = TOUCH_TYPE_NONE_DIS_DIM;
			}
		}
	}
}
void func_power_system_info_Batt_Type_0(void* p,u8 sn,DEAl_TYPE deal_type){func_batt_type(p,sn,deal_type,0);}
void func_power_system_info_Batt_Type_1(void* p,u8 sn,DEAl_TYPE deal_type){func_batt_type(p,sn,deal_type,1);}
void func_power_system_info_Batt_Type_2(void* p,u8 sn,DEAl_TYPE deal_type){func_batt_type(p,sn,deal_type,2);}
void func_power_system_info_Batt_Type_3(void* p,u8 sn,DEAl_TYPE deal_type){func_batt_type(p,sn,deal_type,3);}
void func_power_system_info_Batt_Type_4(void* p,u8 sn,DEAl_TYPE deal_type){func_batt_type(p,sn,deal_type,4);}
void func_Inverter_type(void* p,u8 sn,DEAl_TYPE deal_type,u8 type)
{
//do nothing
//		char display_buf[32];
	setup_item_info_t *setup_p;
	if(deal_type==TO_INIT)
	{
		
	}
	else if(deal_type==TO_UP)
	{
	
	}
	else if(deal_type==TO_DOWN)
	{
	
	}
	else if(deal_type==TO_DEAL)
	{
		type_sel.Inverter_Type = type;
		
		send_FlC200_set_cmd(0x85,2*256+type);
		
		setup_p = &setup_page_sta.now_p[0];
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_SETUP2)
		{
			//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			if(setup_p->father_p!=empty_father_p)	
			{
				if(last_show_page_level>0)
					last_show_page_level--;
				setup_page_sta.now_page_num = last_show_page_num[last_show_page_level] ;
				setup_page_sta.now_p = setup_p->father_p;
				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
				f_display_set_info = TRUE;
				if((parts_set_return_status.Inverter_Mode<=3)&&(type_sel.Inverter_Type == 1))
					Power_System_Setting[7].setup_menu_touch_type = TOUCH_TYPE_ENTER;
				else
					Power_System_Setting[7].setup_menu_touch_type = TOUCH_TYPE_NONE_DIS_DIM;
			}
		}
	}
	
}
void func_power_system_info_Inverter_Type_0(void* p,u8 sn,DEAl_TYPE deal_type){func_Inverter_type(p,sn,deal_type,0);}
void func_power_system_info_Inverter_Type_1(void* p,u8 sn,DEAl_TYPE deal_type){func_Inverter_type(p,sn,deal_type,1);}
void func_power_system_info_Inverter_Type_2(void* p,u8 sn,DEAl_TYPE deal_type){func_Inverter_type(p,sn,deal_type,2);}
void func_power_system_info_Inverter_Type_3(void* p,u8 sn,DEAl_TYPE deal_type){func_Inverter_type(p,sn,deal_type,3);}
void func_mppt_type(void* p,u8 sn,DEAl_TYPE deal_type,u8 type)
{
//do nothing
//		char display_buf[32];
	setup_item_info_t *setup_p;
	if(deal_type==TO_INIT)
	{
		
	}
	else if(deal_type==TO_UP)
	{
	
	}
	else if(deal_type==TO_DOWN)
	{
	
	}
	else if(deal_type==TO_DEAL)
	{
		type_sel.Mppt_Type = type;
		send_FlC200_set_cmd(0x85,3*256+type);
		
		setup_p = &setup_page_sta.now_p[0];
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_SETUP2)
		{
			//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			if(setup_p->father_p!=empty_father_p)	
			{
				if(last_show_page_level>0)
					last_show_page_level--;
				setup_page_sta.now_page_num = last_show_page_num[last_show_page_level] ;
				setup_page_sta.now_p = setup_p->father_p;
				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
				f_display_set_info = TRUE;
			}
		}
	}
	
}
void func_power_system_info_Mppt_Type_0(void* p,u8 sn,DEAl_TYPE deal_type){func_mppt_type(p,sn,deal_type,0);}
void func_power_system_info_Mppt_Type_1(void* p,u8 sn,DEAl_TYPE deal_type){func_mppt_type(p,sn,deal_type,1);}
void func_power_system_info_Mppt_Type_2(void* p,u8 sn,DEAl_TYPE deal_type){func_mppt_type(p,sn,deal_type,2);}
void func_power_system_info_Mppt_Type_3(void* p,u8 sn,DEAl_TYPE deal_type){func_mppt_type(p,sn,deal_type,3);}
void func_power_system_info_Mppt_Type_4(void* p,u8 sn,DEAl_TYPE deal_type){func_mppt_type(p,sn,deal_type,4);}
void func_DC_Changer_type(void* p,u8 sn,DEAl_TYPE deal_type,u8 type)
{
//do nothing
//		char display_buf[32];
	setup_item_info_t *setup_p;
	if(deal_type==TO_INIT)
	{
		
	}
	else if(deal_type==TO_UP)
	{
		
	}
	else if(deal_type==TO_DOWN)
	{
		
	}
	else if(deal_type==TO_DEAL)
	{
		type_sel.DC_Changer_Type = type;
		send_FlC200_set_cmd(0x85,4*256+type);
		setup_p = &setup_page_sta.now_p[0];
		if(page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item==TOP_SIDE_PAGE_HOME_SETUP2)
		{
			//if((setup_page.now_page_num+1)*PAGE_DISPLAY_ITEM_NUM<setup_page.max_page_num)
			if(setup_p->father_p!=empty_father_p)	
			{
				if(last_show_page_level>0)
					last_show_page_level--;
				setup_page_sta.now_page_num = last_show_page_num[last_show_page_level] ;
				setup_page_sta.now_p = setup_p->father_p;
				page_home.page_top_side[LEFT_SIDE_PAGE_HOME].last_item=TOP_SIDE_ICO_NUM_5;//更新
				f_display_set_info = TRUE;
			}
		}
	}
}
void func_power_system_info_DcDc_Type_0(void* p,u8 sn,DEAl_TYPE deal_type){func_DC_Changer_type(p,sn,deal_type,0);}
void func_power_system_info_DcDc_Type_1(void* p,u8 sn,DEAl_TYPE deal_type){func_DC_Changer_type(p,sn,deal_type,1);}
void func_power_system_info_DcDc_Type_2(void* p,u8 sn,DEAl_TYPE deal_type){func_DC_Changer_type(p,sn,deal_type,2);}
void ui_column_setup_power_system_info_str(bool upgrade)
{
	char display_buf[64];
	setup_page_t *setup_page_p;
	u8 temp = 0;
	
	setup_page_p = &setup_page_sta;
	if(upgrade)
	{
		if(setup_page_p->now_p == Power_System_Setting)
		{
			Virtual_LCD_Draw_Rectangle_ARGB32(360,137,690-360,385-137,Virtual_LCDbuff2,ARGB_clear);
			switch(setup_page_p->now_page_num)//页面文字设置
			{
				case 0x00:
					if(type_sel.Battery_SmartShun_Type<5)
						temp = type_sel.Battery_SmartShun_Type+1;
					else 
						temp = type_sel.Battery_SmartShun_Type+2;
					Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,176,Battery_info_select[temp].display_str,(ARGB_mydarkcyan),0,1,1);
					if(type_sel.Inverter_Type<5)
						temp = type_sel.Inverter_Type+1;
					else
						temp = type_sel.Inverter_Type+2;
					Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,254,Inverter_info_select[temp].display_str,(ARGB_mydarkcyan),0,1,1);
					if(type_sel.Mppt_Type<5)
						temp = type_sel.Mppt_Type+1;
					else
						temp = type_sel.Mppt_Type+2;
					Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,332,Mppt_info_select[temp].display_str,(ARGB_mydarkcyan),0,1,1);
					//if(type_sel.DC_Changer_Type<3)
						temp = type_sel.DC_Changer_Type+1;
					//else
						//temp = type_sel.DC_Changer_Type+2;
				break;
                    case 0x01:
                  Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,176,DcDc_info_select[temp].display_str,(ARGB_mydarkcyan),0,1,1);
				break;

			}
		}
		else if(setup_page_p->now_p == System_info)
		{
			Virtual_LCD_Draw_Rectangle_ARGB32(350,137,690-350,385-137,Virtual_LCDbuff2,ARGB_clear);
			switch(setup_page_p->now_page_num)//页数
			{
				case 0:

//                sprintf(display_buf," %04X ",code_connect);//蓝牙配对码
//					Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,176+10,display_buf,(ARGB_mydarkcyan),0,1,1);
//					
//                //BLE Name
//                sprintf(display_buf,"LINKS2-%c%c%c%c%c%c%c%c%c%c%c%c",BT_MAC_STR[0],BT_MAC_STR[1],BT_MAC_STR[2],BT_MAC_STR[3],BT_MAC_STR[4],BT_MAC_STR[5],BT_MAC_STR[6],BT_MAC_STR[7],BT_MAC_STR[8],BT_MAC_STR[9],BT_MAC_STR[10],BT_MAC_STR[11]);
//					Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,254+10 ,display_buf,(ARGB_mydarkcyan),0,1,1);
//					
//                Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,332+10,MCU_VERSION_STR,(ARGB_mydarkcyan),0,1,1);//MCU software
//					
                
                //176+10  1
                //254+10  2
                //332+10  3
                
                
//                sprintf(display_buf," %04X ",code_connect);//蓝牙配对码
//					Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,176+10,display_buf,(ARGB_mydarkcyan),0,1,1);
//					
                //BLE Name
//                sprintf(display_buf,"LINKS2-%c%c%c%c%c%c%c%c%c%c%c%c",BT_MAC_STR[0],BT_MAC_STR[1],BT_MAC_STR[2],BT_MAC_STR[3],BT_MAC_STR[4],BT_MAC_STR[5],BT_MAC_STR[6],BT_MAC_STR[7],BT_MAC_STR[8],BT_MAC_STR[9],BT_MAC_STR[10],BT_MAC_STR[11]);
//					Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,176+10 ,display_buf,(ARGB_mydarkcyan),0,1,1);
					
                Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,176+10,MCU_VERSION_STR,(ARGB_mydarkcyan),0,1,1);//MCU software
			
                 Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,254+10,VERSION_STR,(ARGB_mydarkcyan),0,1,1);        //UI software        
       
       					if(CONTROL_MCU_VERSION_STR[18] == '\0')
						Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,332+10,"Device not connected",(ARGB_mydarkcyan),0,1,1);
					else
						Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,332+10,&CONTROL_MCU_VERSION_STR[18],(ARGB_mydarkcyan),0,1,1);//Control Unit SlaveMCU  

       
//                    
                    break;
				case 1:
                    


					if(CONTROL_SECOND_MCU_VERSION_STR[23] == '\0')
						Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,176+10,"Device not connected",(ARGB_mydarkcyan),0,1,1);
					else
						Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,176+10,&CONTROL_SECOND_MCU_VERSION_STR[23],(ARGB_mydarkcyan),0,1,1);
					
                    if(External_protocol_MCU_VERSION_STR[23] == '\0')//External_protocol MCU
						Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,254+10,"Device not connected",(ARGB_mydarkcyan),0,1,1);
					else
						Virtual_LCD_Draw_String_ARGB_align_right_4bit(16,630,254+10,&External_protocol_MCU_VERSION_STR[23],(ARGB_mydarkcyan),0,1,1);
       
                    
                    
                   break;
                    
//                    case 2:
//                     break;
                    
                    
			}
		}
		else if(setup_page_p->now_p == System_setting)//信息显示界面
		{
			Virtual_LCD_Draw_Rectangle_ARGB32(30,130,690-30,385-130,Virtual_LCDbuff2,ARGB_clear);
			Virtual_LCD_Draw_String_ARGB_24_4bit(52,130+50,"Battery_info:",(ARGB_white),0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(65,163+50,Extra_device_battery_ver,(ARGB_mydarkcyan),0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(52,195+50,"Inveter info :",(ARGB_white),0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(65,228+50,Extra_device_inverter_ver,(ARGB_mydarkcyan),0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(52,260+50,"Mppt_info :",(ARGB_white),0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(65,293+50,Extra_device_mppt_ver,(ARGB_mydarkcyan),0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(52,325+50,"DcDc_info :",(ARGB_white),0,1,1);
			Virtual_LCD_Draw_String_ARGB_24_4bit(65,358+50,Extra_device_Dc_Dc_ver,(ARGB_mydarkcyan),0,1,1);
		}
        
        else if(setup_page_p->now_p == setup_setting)//初始显示界面
		{
            
            switch(setup_page_p->now_page_num)//页数
			{
				case 1://页显示温度单位
			///Virtual_LCD_Draw_Rectangle_ARGB32(30,130,690-30,385-130,Virtual_LCDbuff2,ARGB_clear);
		///	Virtual_LCD_Draw_String_ARGB_24_4bit(553+50,96+5,"C",(ARGB_white),0,1,1);
            break;
            }
		}
        
        
	}
	if(upgrade==FALSE)
	{
		Virtual_LCD_Upgrate_formx1y1(30,130,690-30,385-130);
	}
}


extern lcd_dis_item_t *p_home_top_item_5_test_u[6];
extern lcd_dis_item_t *p_home_top_item_5_test_d[6];
extern lcd_dis_item_t test_home_top_item[6];


//void ui_column_setup_system_upgrade_info_str(bool upgrade)//升级进度
//{
//	static u8 old_upgrade_info1[48];
//	static u8 old_upgrade_info2[48];
//	static u8 old_upgrade_info3[48];
//	setup_page_t *setup_page_p;
//	lcd_dis_item_t *p;
//	
//	setup_page_p = &setup_page_sta;
//	p = &t_Setup_info_column_upgrade_page;//升级页背景
//	if(setup_page_p->now_p == System_Upgrade_page)//设置页字体
//	{

//        
//		if((memcmp(&upgrade_info1,&old_upgrade_info1,36)||upgrade))
//		{
//			memcpy(&old_upgrade_info1,&upgrade_info1,36);
//			Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,185,p->x_end_val-p->x_val,40,Virtual_LCDbuff2,ARGB_clear);
//			upgrade_info1[47]='\0';
//			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(103,190,(char*)upgrade_info1,ARGB_yellow,0,1,1);
//			//if(upgrade==FALSE)
//			{
//				Virtual_LCD_Upgrate_formx1y1(p->x_val,185,p->x_end_val-p->x_val,40);
//			}
//		}
//		if((memcmp(&upgrade_info2,&old_upgrade_info2,36)||upgrade))
//		{
//			memcpy(&old_upgrade_info2,&upgrade_info2,36);
//			Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,235-20,p->x_end_val-p->x_val,40,Virtual_LCDbuff2,ARGB_clear);
//			upgrade_info2[47]='\0';
//			sysprintf("\r\n %d  %d\r\n,",upgrade_info2[7],upgrade_info2[8]);
//			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(103,240-20,(char*)upgrade_info2,ARGB_yellow,0,1,1);
//			//if(upgrade==FALSE)
//			{
//				Virtual_LCD_Upgrate_formx1y1(p->x_val,235,p->x_end_val-p->x_val,40);
//			}
//		}
//		if((memcmp(&upgrade_info3,&old_upgrade_info3,36)||upgrade))
//		{
//			memcpy(&old_upgrade_info3,&upgrade_info3,36);
//			Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,285-40,p->x_end_val-p->x_val,40,Virtual_LCDbuff2,ARGB_clear);
//			upgrade_info3[47]='\0';
//			sysprintf("\r\n %d  %d\r\n,",upgrade_info2[7],upgrade_info2[8]);
//			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(103,290-40,(char*)upgrade_info3,ARGB_yellow,0,1,1);
//			//if(upgrade==FALSE)
//			{
//				Virtual_LCD_Upgrate_formx1y1(p->x_val,285,p->x_end_val-p->x_val,40);
//			}
//		}

//    
//	}
//  
//}

void ui_column_setup_system_upgrade_info_str(bool upgrade)//升级信息
{
	static u8 old_upgrade_info1[48];
	static u8 old_upgrade_info2[48];
	static u8 old_upgrade_info3[48];
	setup_page_t *setup_page_p;
	lcd_dis_item_t *p;
	
	setup_page_p = &setup_page_sta;
	p = &t_Setup_info_column_upgrade_page;
	if(setup_page_p->now_p == System_Upgrade_page)
	{
		if((memcmp(&upgrade_info1,&old_upgrade_info1,36)||upgrade))
		{
			memcpy(&old_upgrade_info1,&upgrade_info1,36);
			Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,185,p->x_end_val-p->x_val,40,Virtual_LCDbuff2,ARGB_clear);
			upgrade_info1[47]='\0';
			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(103,190,(char*)upgrade_info1,ARGB_yellow,0,1,1);
			//if(upgrade==FALSE)
			{
				Virtual_LCD_Upgrate_formx1y1(p->x_val,185,p->x_end_val-p->x_val,40);
			}
		}
		if((memcmp(&upgrade_info2,&old_upgrade_info2,36)||upgrade))
		{
			memcpy(&old_upgrade_info2,&upgrade_info2,36);
			Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,235,p->x_end_val-p->x_val,40,Virtual_LCDbuff2,ARGB_clear);
			upgrade_info2[47]='\0';
			sysprintf("\r\n %d  %d\r\n,",upgrade_info2[7],upgrade_info2[8]);
			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(103,240,(char*)upgrade_info2,ARGB_yellow,0,1,1);
			//if(upgrade==FALSE)
			{
				Virtual_LCD_Upgrate_formx1y1(p->x_val,235,p->x_end_val-p->x_val,40);
			} 
		}
		if((memcmp(&upgrade_info3,&old_upgrade_info3,36)||upgrade))
		{
			memcpy(&old_upgrade_info3,&upgrade_info3,36);
			Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val,285,p->x_end_val-p->x_val,40,Virtual_LCDbuff2,ARGB_clear);
			upgrade_info3[47]='\0';
			sysprintf("\r\n %d  %d\r\n,",upgrade_info2[7],upgrade_info2[8]);
			Virtual_LCD_Draw_String_ARGB_24_4bit_bold(103,290,(char*)upgrade_info3,ARGB_yellow,0,1,1);
			//if(upgrade==FALSE)
			{
				Virtual_LCD_Upgrate_formx1y1(p->x_val,285,p->x_end_val-p->x_val,40);
			}
		}
	}
}


void func_set_upgrade_open_key_type(KEY_TYPE key_type)
{
   setup_5_chun_item[28].key_type = key_type;
}
void func_set_upgrade_close_key_type(KEY_TYPE key_type)
{
   setup_5_chun_item[29].key_type = key_type;
}

//typedef struct _setup_page_t
//{	
//	u8 now_page_deep;//0=首层，1=第2层 ，2=第3层
//	u8 now_page_num;//这一层的多少页 4项1页
//	u8 max_page_num;//这一层最多有多少页
//	setup_item_info_t* now_p;//当前指向数组	
//} setup_page_t;


//根据当前“设置页面结构”刷新整个 Setup 界面的所有可视项、按键状态、上下页逻辑、Back、Upgrade 显示、左/右按钮、滑动条等，
void display_column_setup_page(bool upgrage_dispaly,bool upgrage,setup_page_t *setup_page_p,lcd_dis_item_t *setup_item_p,char* display_buf)
{
	setup_item_info_t *setup_p; 
	u8 i;
		
	if(setup_page_p->now_p==empty_son_p)//当前指向数组	
	{
		setup_page_p->max_page_num = 0;//这一层最多有多少页
		return;
	}
	else
	{
		for(i=0;1;i++)
		{
			if(setup_page_p->now_p[i].setup_menu_touch_type == END_OF_THE_LIST)//当前指向数组	.按键状态==//结束
			{
				 setup_page_p->max_page_num = i;//这一层最多有多少页=i
				 break;
			}
		}
	}
	//PAGE_DISPLAY_ITEM_NUM
	if(setup_page_p->now_page_num==0)//首页
		setup_item_p[6].key_type = KEY_TYPE_TOUCH_NONE;//prepage  
	else
		setup_item_p[6].key_type = KEY_TYPE_ONCE;//prepage
	 
	if((setup_page_p->now_page_num+1)*setup_page_display_num<setup_page_p->max_page_num)//
		setup_item_p[7].key_type = KEY_TYPE_ONCE;//prepage
	else
		setup_item_p[7].key_type = KEY_TYPE_TOUCH_NONE;//prepage
	
	if(setup_page_p->now_p[0].father_p!=empty_father_p)	  //back
	{
		setup_item_p[26].key_type = KEY_TYPE_ONCE;// 
	}
	else 
	{
		setup_item_p[26].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
		setup_item_p[26].last_status = STATUS_IDLE;
		setup_item_p[26].now_status = STATUS_IDLE;
	}
	
	if(upgrage)
  {
		Virtual_LCD_Draw_Rectangle_ARGB32(25,50,690,400,Virtual_LCDbuff2,ARGB_clear);
		Virtual_LCD_Draw_String_ARGB_24_4bit(297,80,display_buf,(0xFF78baf7),0,1,1);
      
		//setup_5_chun_item[6].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
		//setup_5_chun_item[15].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
		//setup_5_chun_item[22].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
		//setup_5_chun_item[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
		//if(setup_page_p->now_p[0].father_p!=empty_father_p)
			//Virtual_LCD_Draw_String_ARGB_24_4bit(82,85,"Save and Back",(0xFFe2e2e4),0,1,1);
		    /*if(setup_page_p->now_p->father_p!=empty_father_p)
				{
					x_addr_offset = 0;
					i = 0;
					while(display_buf[i]!='\0')
					{						
						  x_addr_offset+=(glyph_dsc_24_4bit_bold[display_buf[i]-0x20].adv_w);
							i++;
					}
					Virtual_LCD_Draw_String_ARGB_24_4bit(142+x_addr_offset,90," -> ",(0xFF78baf7),0,1,1);
					x_addr_offset += 30;
					father_setup_page_p->now_p = setup_page_p->now_p->father_p;
				  Virtual_LCD_Draw_String_ARGB_24_4bit(142+x_addr_offset,90,father_setup_page_p->now_p->display_str,(0xFF78baf7),0,1,1);
				
				}*/
	}
	 
	 
	for(i=0;i<setup_page_display_num;i++)//页面选项数
	{
		setup_p = &setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i];
		if((setup_page_p->now_page_num*setup_page_display_num+i)<setup_page_p->max_page_num)
		{
			if(upgrage)
	    {
				//Virtual_LCD_Draw_Rectangle_ARGB32(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
//		    if(setup_p->setup_menu_touch_type==TOUCH_TYPE_NONE_DIS_DIM)
//				{
//					if((setup_p->father_p!=empty_father_p)&&(i==0))
//					//if((setup_page_p->now_p == Power_System_Setting)&&((setup_page_p->now_page_num!=1)||(i<2)))
//						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+330,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i].display_str,(ARGB_gray),0,1,1);
//					else
//						Virtual_LCD_Draw_String_ARGB_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i].display_str,(ARGB_gray),0,1,1);
//				}
//				else
//				{
//					if((setup_p->father_p!=empty_father_p)&&(i==0))
//					//if((setup_page_p->now_p == Power_System_Setting)&&((setup_page_p->now_page_num!=1)||(i<2)))
//						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+330,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i].display_str,(0xFFe2e2e4),0,1,1);
//					else
//						Virtual_LCD_Draw_String_ARGB_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i].display_str,(0xFFe2e2e4),0,1,1);
//				}
//			}
        
		    if(setup_p->setup_menu_touch_type==TOUCH_TYPE_NONE_DIS_DIM)
				{
					if((setup_p->father_p!=empty_father_p)&&(i==0))
					//if((setup_page_p->now_p == Power_System_Setting)&&((setup_page_p->now_page_num!=1)||(i<2)))
						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+330,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15+10,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i].display_str,(ARGB_gray),0,1,1);
					else
						Virtual_LCD_Draw_String_ARGB_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15+10,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i].display_str,(ARGB_gray),0,1,1);
				}
				else
				{
					if((setup_p->father_p!=empty_father_p)&&(i==0))
					//if((setup_page_p->now_p == Power_System_Setting)&&((setup_page_p->now_page_num!=1)||(i<2)))
						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+330,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15+10,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i].display_str,(0xFFe2e2e4),0,1,1);
					else
						Virtual_LCD_Draw_String_ARGB_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15+10,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num+i].display_str,(0xFFe2e2e4),0,1,1);
				}
			}            
            
            
            
			switch(setup_p->setup_menu_touch_type)
			{
				case TOUCH_TYPE_NORMAL://正常  
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//左按键 不显示
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//右按键 不显示
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_ONCE;//按键点击：单位次按键 按下一次自己弹起，
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//进入，不显示
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
                
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item 
				  //setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				  //setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
				break;
                
    				case TOUCH_TYPE_Temperature://温度

					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_ONCE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_ONCE;//单位次按键 按下一次自己弹起，         
					//setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
                    
                    setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;//不进行触摸 弹起图标当背景显示//

					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
           

                    
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
                    
                     setup_item_p[30].key_type = KEY_TYPE_TOUCH_NONE;//温度图标
                    disply_Setup_val(TRUE);

				break;            
                    
                    
               	case TOUCH_TYPE_ENTER_Upgrade://正常  点一下进入下一级
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;  //不进行触摸 也不显示
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_ONCE;//单位次按键 按下一次自己弹起，
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
                
				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item 
				  //setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				  //setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
				break; 
                
				case TOUCH_TYPE_ENTER://正常  点一下进入下一级
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;  //不进行触摸 也不显示
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_ONCE;//单位次按键 按下一次自己弹起，
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item 
				  //setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
				  //setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
                
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;
                
                
				case TOUCH_TYPE_LEFT_RIGHT://显示左右选择按键 可以左右选择
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_ONCE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_ONCE;//单位次按键 按下一次自己弹起，
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;//不进行触摸 弹起图标当背景显示 
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
				  //setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_ONCE;//left
				  //setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_ONCE;//right				   
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;
				case TOUCH_TYPE_UP_DOWN://显示上下选择按键 可以上下选择
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;//不进行触摸 弹起图标当背景显示 
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
					//setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
					//setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;
				case TOUCH_TYPE_SLIDE://显示滑动按键 可以滑动选择
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
					//setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
					//setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right			
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;				
				case TOUCH_TYPE_KEYBOARD://进入键盘显示，输入值
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item   
					//setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
					//setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right				
				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示
                
				break;
				case TOUCH_TYPE_NONE://显示没有触摸
				case TOUCH_TYPE_NONE_DIS_DIM:
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
					//setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
					//setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right				
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;
				case TOUCH_TYPE_SPECIAL://特殊情况处理 在程序外处理
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_ONCE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_ONCE;//item 
					//setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
					//setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;
				case END_OF_THE_LIST://结束
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
					//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
					//setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
					//setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;
				case TOUCH_TYPE_UPGRADE:
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[29].key_type = KEY_TYPE_ONCE;//升级startt
					setup_item_p[28].key_type = KEY_TYPE_ONCE;//升级返回
				  setup_item_p[27].key_type = KEY_TYPE_TOUCH_NONE;
					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;
				case TOUCH_TYPE_BACKGROUND:
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
				  setup_item_p[27].key_type = KEY_TYPE_TOUCH_NONE;
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

					//setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//
				break;
				case TOUCH_TYPE_SAVE_AND_BACK:
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
				  setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[26].key_type = KEY_TYPE_ONCE;//
                				   setup_item_p[30].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//温度图标不显示

				break;
				default:
					
				break;
			}
			if(upgrage)
			{
			  if(*setup_p->f!=empty_fun)
					(*setup_p->f)(setup_p,i+SYSTEM_ITEM_1_OFFSET,TO_INIT);	
				//sysprintf("\r\n======================%d",i);
		  }
			else
			{
			   if(*setup_p->f!=empty_fun)
			    (*setup_p->f)(setup_p,i+SYSTEM_ITEM_1_OFFSET,TO_DO_NOTHING);	
			}
		}
		else
		{
			setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;
			setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			
			//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
			//setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
			//setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
			//if(upgrage)
			//	Virtual_LCD_Draw_Rectangle_ARGB32(setup_item_p[1+i].x_val+32,setup_item_p[1+i].y_val+26,690,24,Virtual_LCDbuff2,ARGB_clear);
    }
  }
	if(upgrage_dispaly)
	{
		//f_need_LCD_Upgrate = TRUE;
		Virtual_LCD_Upgrate();	
	}
}

void ui_column_setup_set_info(bool upgrage)
{
	setup_page_t *setup_page_p;
	lcd_dis_item_t *setup_item_p;
	static u8 last_now_item = TOP_SIDE_ICO_NUM_5;
	
	setup_page_p = &setup_page_sta;
	setup_item_p = setup_5_chun_item;
	
	if(last_now_item!=page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item)
	{
		last_now_item=page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item;
		setup_page_p->now_p = setup_setting;
		setup_page_p->now_page_deep = 0;
		setup_page_p->now_page_num = 0;
		//last_now_page_num = 0;
		last_show_page_level = 0;
		last_show_page_num[0] = 0;
		last_show_page_num[1] = 0;
		
		if(type_sel.Battery_SmartShun_Type == BATTERY_LINKS2_KL500A)
		{
			Power_System_Setting[5].setup_menu_touch_type = TOUCH_TYPE_ENTER;
		}
		else
		{
			Power_System_Setting[5].setup_menu_touch_type = TOUCH_TYPE_NONE_DIS_DIM;
		}
		if((parts_set_return_status.Inverter_Mode<=3)&&(type_sel.Inverter_Type == 1))
		{
			Power_System_Setting[7].setup_menu_touch_type = TOUCH_TYPE_ENTER;
		}
		else
		{
			Power_System_Setting[7].setup_menu_touch_type = TOUCH_TYPE_NONE_DIS_DIM;
		}
	}
	f_display_set_info = FALSE;
	display_column_setup_page(FALSE,upgrage,setup_page_p,setup_item_p,"");
}



void ui_column_setup_init_5(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][TOP_SIDE_PAGE_HOME_SETUP2]; //父页面（绑定底栏）5
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_bg_5_cun_new.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_bg_5_cun_new.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
	p->item_num=SETUP_5_CHUN_ITME_NUM;// how many item
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
	
	for(i=0;i<SETUP_5_CHUN_ITME_NUM;i++)//背景？？意义不明
	{
		p_setup_item_main_d[i]->key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//不进行触摸 也不显示
	}
	//
    
    
    
	f_ui_disply_dialog_info_5 = FALSE;
	p->item = setup_5_chun_item;
	for(i=0;i<SETUP_5_CHUN_ITME_NUM;i++)///触控？？？
	{
		memcpy(&(p->item[i]),p_setup_item_main_d[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_setup_item_main_u[i]->pic_item;//
		p->item[i].size_of_pic_item = p_setup_item_main_u[i]->size_of_pic_item ;
	}
	p->sub_page_count = 0x00; //定义好子页面数目
	p->sub_page = NULL;//= (lcd_dis_page_t **)malloc(p->sub_page_count * sizeof(lcd_dis_page_t *));  //开辟子页面数组内存
	
	t_Setup_info_column_enter_down_new.key_type = KEY_TYPE_ONCE;//选项进入
	t_Setup_info_column_enter_down_new_1.key_type = KEY_TYPE_ONCE;
	t_Setup_info_column_enter_down_new_2.key_type = KEY_TYPE_ONCE;
	t_Setup_info_column_enter_down_new_3.key_type = KEY_TYPE_ONCE;
	//t_Setup_info_coulumn_new_3.key_type = KEY_TYPE_TOUCH_NONE;
	//t_Setup_page_pre_down_new.key_type = KEY_TYPE_ONCE;
	//t_Setup_page_next_down_new.key_type = KEY_TYPE_ONCE;
	
	
	ui_column_setup_set_info(FALSE);//首页
}




void disply_Setup_val(bool upgrade)
{
    
	static SetupSystem old_Setup_status;   
	char display_buf[32];
	lcd_dis_item_t *p;
    
    
	if((memcmp(&now_Setup_status,&old_Setup_status,sizeof(SetupSystem)))||upgrade)//判断是否状态更新
	{
    memcpy(&old_Setup_status,&now_Setup_status,sizeof(SetupSystem));//更新状态
        
//        p=&t_page6_no_select;//清除的区域
//		//清空字符
//		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_val+500,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);//防止刷掉选项文本
//                              
          p=&t_page6_left_up;
		//清空字符
		Virtual_LCD_Draw_Rectangle_ARGB32(p->x_end_val+60,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val,Virtual_LCDbuff2,ARGB_clear);

        
        
        if(now_Setup_status.icon==0){

        sprintf(display_buf, "C");
        Virtual_LCD_Draw_String_ARGB_32_4bit_bold(611+2,102+5,display_buf,(0xFF18ACFC),0,1,1);//
		Virtual_LCD_Draw_String_o(611-2,102,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(0xFF18ACFC),0,1,1);
        }
        
        else if(now_Setup_status.icon==1){
        sprintf(display_buf, "F");
        Virtual_LCD_Draw_String_ARGB_32_4bit_bold(611+3,102+5,display_buf,(0xFF18ACFC),0,1,1);//
		Virtual_LCD_Draw_String_o(611-3,102,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(0xFF18ACFC),0,1,1);
        }        
        else if(now_Setup_status.icon==2){
        sprintf(display_buf, "K");
        Virtual_LCD_Draw_String_ARGB_32_4bit_bold(611+2,102+5,display_buf,(0xFF18ACFC),0,1,1);//
	//	Virtual_LCD_Draw_String_o(132+10+10-5,168+10+5,display_buf,(lv_font_fmt_txt_glyph_dsc_t*)glyph_dsc_24_4bit,(0xFFFC532E),0,1,1);
        }
        
        		if(upgrade==FALSE)
			Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val);

    }
}