#include "ui_def.h"
#include "ui_data.h"


typedef struct
{
    u8 icon;  // 
} SetupSystem;

///SetupSystem now_Setup_status;   //现在状态
void disply_Setup_val(bool upgrade);

#define X_setup_column_1_5  40
#define Y_setup_column_1_5  75

/////////new_5_cun//////////////////////////////////////////////////////////////

#define X_Setup_info_coulumn_new  28
#define Y_Setup_info_coulumn_new  56 
                                   
#define X_Setup_info_coulumn_new_1  X_Setup_info_coulumn_new
#define Y_Setup_info_coulumn_new_1  112

#define X_Setup_info_coulumn_new_2  X_Setup_info_coulumn_new
#define Y_Setup_info_coulumn_new_2  168

#define X_Setup_info_coulumn_new_3  X_Setup_info_coulumn_new
#define Y_Setup_info_coulumn_new_3  224

#define X_Setup_info_coulumn_new_4  X_Setup_info_coulumn_new
#define Y_Setup_info_coulumn_new_4  280

#define X_Setup_info_coulumn_new_5  X_Setup_info_coulumn_new
#define Y_Setup_info_coulumn_new_5  336

#define X_Setup_info_coulumn_new_6  X_Setup_info_coulumn_new
#define Y_Setup_info_coulumn_new_6  392

#define X_Setup_info_coulumn_d_new   X_Setup_info_coulumn_new  
#define Y_Setup_info_coulumn_d_new   Y_Setup_info_coulumn_new  
                                                               
#define X_Setup_info_coulumn_d_new_1 X_Setup_info_coulumn_new_1
#define Y_Setup_info_coulumn_d_new_1 Y_Setup_info_coulumn_new_1
                                     
#define X_Setup_info_coulumn_d_new_2 X_Setup_info_coulumn_new_2
#define Y_Setup_info_coulumn_d_new_2 Y_Setup_info_coulumn_new_2
                                     
#define X_Setup_info_coulumn_d_new_3 X_Setup_info_coulumn_new_3
#define Y_Setup_info_coulumn_d_new_3 Y_Setup_info_coulumn_new_3

#define X_Setup_info_coulumn_d_new_4 X_Setup_info_coulumn_new_4
#define Y_Setup_info_coulumn_d_new_4 Y_Setup_info_coulumn_new_4
                                                              
#define X_Setup_info_coulumn_d_new_5 X_Setup_info_coulumn_new_5
#define Y_Setup_info_coulumn_d_new_5 Y_Setup_info_coulumn_new_5

#define X_Setup_info_coulumn_d_new_6 X_Setup_info_coulumn_new_6
#define Y_Setup_info_coulumn_d_new_6 Y_Setup_info_coulumn_new_6

//#define X_Setup_left_icon_down_new  461
//#define Y_Setup_left_icon_down_new  66

//#define X_Setup_left_icon_down_new_1  461
//#define Y_Setup_left_icon_down_new_1  122

//#define X_Setup_left_icon_down_new_2  461
//#define Y_Setup_left_icon_down_new_2  178

//左按下
#define X_Setup_left_icon_down_new  461
#define Y_Setup_left_icon_down_new 96

#define X_Setup_left_icon_down_new_1  461
#define Y_Setup_left_icon_down_new_1  174

#define X_Setup_left_icon_down_new_2  461
#define Y_Setup_left_icon_down_new_2  252


#define X_Setup_left_icon_down_new_3  461
#define Y_Setup_left_icon_down_new_3   330

#define X_Setup_left_icon_down_new_4  461
#define Y_Setup_left_icon_down_new_4   0

#define X_Setup_left_icon_down_new_5  461
#define Y_Setup_left_icon_down_new_5  0

#define X_Setup_left_icon_down_new_6  461
#define Y_Setup_left_icon_down_new_6  0

#define X_Setup_left_icon_up_new   X_Setup_left_icon_down_new  
#define Y_Setup_left_icon_up_new   Y_Setup_left_icon_down_new 

#define X_Setup_left_icon_up_new_1 X_Setup_left_icon_down_new_1
#define Y_Setup_left_icon_up_new_1 Y_Setup_left_icon_down_new_1

#define X_Setup_left_icon_up_new_2 X_Setup_left_icon_down_new_2
#define Y_Setup_left_icon_up_new_2 Y_Setup_left_icon_down_new_2

#define X_Setup_left_icon_up_new_3 X_Setup_left_icon_down_new_3
#define Y_Setup_left_icon_up_new_3 Y_Setup_left_icon_down_new_3

#define X_Setup_left_icon_up_new_4 X_Setup_left_icon_down_new_4
#define Y_Setup_left_icon_up_new_4 Y_Setup_left_icon_down_new_4
                                                              
#define X_Setup_left_icon_up_new_5 X_Setup_left_icon_down_new_5
#define Y_Setup_left_icon_up_new_5 Y_Setup_left_icon_down_new_5

#define X_Setup_left_icon_up_new_6 X_Setup_left_icon_down_new_6
#define Y_Setup_left_icon_up_new_6 Y_Setup_left_icon_down_new_6

#define X_Setup_right_icon_down_new  602
#define Y_Setup_right_icon_down_new  96

#define X_Setup_right_icon_down_new_1  X_Setup_right_icon_down_new
#define Y_Setup_right_icon_down_new_1  174

#define X_Setup_right_icon_down_new_2  X_Setup_right_icon_down_new
#define Y_Setup_right_icon_down_new_2  252

#define X_Setup_right_icon_down_new_3  X_Setup_right_icon_down_new
#define Y_Setup_right_icon_down_new_3  330

#define X_Setup_right_icon_down_new_4  X_Setup_right_icon_down_new
#define Y_Setup_right_icon_down_new_4  0
                                     
#define X_Setup_right_icon_down_new_5  X_Setup_right_icon_down_new
#define Y_Setup_right_icon_down_new_5  0

#define X_Setup_right_icon_down_new_6  X_Setup_right_icon_down_new
#define Y_Setup_right_icon_down_new_6  0

#define X_Setup_right_icon_up_new    X_Setup_right_icon_down_new  
#define Y_Setup_right_icon_up_new    Y_Setup_right_icon_down_new  
                                     
#define X_Setup_right_icon_up_new_1  X_Setup_right_icon_down_new_1
#define Y_Setup_right_icon_up_new_1  Y_Setup_right_icon_down_new_1
                                     
#define X_Setup_right_icon_up_new_2  X_Setup_right_icon_down_new_2
#define Y_Setup_right_icon_up_new_2  Y_Setup_right_icon_down_new_2

#define X_Setup_right_icon_up_new_3  X_Setup_right_icon_down_new_3
#define Y_Setup_right_icon_up_new_3  Y_Setup_right_icon_down_new_3
                                     
#define X_Setup_right_icon_up_new_4  X_Setup_right_icon_down_new_4
#define Y_Setup_right_icon_up_new_4  Y_Setup_right_icon_down_new_4
                                                                  
#define X_Setup_right_icon_up_new_5  X_Setup_right_icon_down_new_5
#define Y_Setup_right_icon_up_new_5  Y_Setup_right_icon_down_new_5

#define X_Setup_right_icon_up_new_6  X_Setup_right_icon_down_new_6
#define Y_Setup_right_icon_up_new_6  Y_Setup_right_icon_down_new_6
																		 
#define X_Setup_page_next_down_new  696
#define Y_Setup_page_next_down_new  249

#define X_Setup_page_next_up_new  X_Setup_page_next_down_new
#define Y_Setup_page_next_up_new  Y_Setup_page_next_down_new

#define X_Setup_page_pre_down_new  696
#define Y_Setup_page_pre_down_new  80

#define X_Setup_page_pre_up_new  X_Setup_page_pre_down_new
#define Y_Setup_page_pre_up_new  Y_Setup_page_pre_down_new

#define X_Setup_info_column_enter_down_new    X_Setup_info_coulumn_new
#define Y_Setup_info_column_enter_down_new    Y_Setup_info_coulumn_new

#define X_Setup_info_column_enter_down_new_1  X_Setup_info_coulumn_new_1
#define Y_Setup_info_column_enter_down_new_1  Y_Setup_info_coulumn_new_1
                                              
#define X_Setup_info_column_enter_down_new_2  X_Setup_info_coulumn_new_2
#define Y_Setup_info_column_enter_down_new_2  Y_Setup_info_coulumn_new_2
                                              
#define X_Setup_info_column_enter_down_new_3  X_Setup_info_coulumn_new_3
#define Y_Setup_info_column_enter_down_new_3  Y_Setup_info_coulumn_new_3
                                              
#define X_Setup_info_column_enter_down_new_4  X_Setup_info_coulumn_new_4
#define Y_Setup_info_column_enter_down_new_4  Y_Setup_info_coulumn_new_4
                                              
#define X_Setup_info_column_enter_down_new_5  X_Setup_info_coulumn_new_5
#define Y_Setup_info_column_enter_down_new_5  Y_Setup_info_coulumn_new_5

#define X_Setup_info_column_enter_down_new_6  X_Setup_info_coulumn_new_6
#define Y_Setup_info_column_enter_down_new_6  Y_Setup_info_coulumn_new_6

#define X_Setup_info_column_enter_up_new   X_Setup_info_column_enter_down_new  
#define Y_Setup_info_column_enter_up_new   Y_Setup_info_column_enter_down_new  
                                           
#define X_Setup_info_column_enter_up_new_1 X_Setup_info_column_enter_down_new_1
#define Y_Setup_info_column_enter_up_new_1 Y_Setup_info_column_enter_down_new_1
                                           
#define X_Setup_info_column_enter_up_new_2 X_Setup_info_column_enter_down_new_2
#define Y_Setup_info_column_enter_up_new_2 Y_Setup_info_column_enter_down_new_2
                                           
#define X_Setup_info_column_enter_up_new_3 X_Setup_info_column_enter_down_new_3
#define Y_Setup_info_column_enter_up_new_3 Y_Setup_info_column_enter_down_new_3

#define X_Setup_info_column_enter_up_new_4 X_Setup_info_column_enter_down_new_4
#define Y_Setup_info_column_enter_up_new_4 Y_Setup_info_column_enter_down_new_4
                                                                               
#define X_Setup_info_column_enter_up_new_5 X_Setup_info_column_enter_down_new_5
#define Y_Setup_info_column_enter_up_new_5 Y_Setup_info_column_enter_down_new_5
                                                                               
#define X_Setup_info_column_enter_up_new_6 X_Setup_info_column_enter_down_new_6
#define Y_Setup_info_column_enter_up_new_6 Y_Setup_info_column_enter_down_new_6

#define X_Setup_save_and_back_new  28
#define Y_Setup_save_and_back_new  56

#define X_Setup_save_and_back_new_down  X_Setup_save_and_back_new
#define Y_Setup_save_and_back_new_down  Y_Setup_save_and_back_new

#define X_Setup_info_column_upgrade_page  30
//#define Y_Setup_info_column_upgrade_page  112
#define Y_Setup_info_column_upgrade_page  155//升级背景

#define X_Setup_info_column_upgrade_button  206
#define Y_Setup_info_column_upgrade_button  334

#define X_Setup_info_column_upgrade_button_d  X_Setup_info_column_upgrade_button
#define Y_Setup_info_column_upgrade_button_d  Y_Setup_info_column_upgrade_button

#define X_Setup_info_column_upgrade_close  404
#define Y_Setup_info_column_upgrade_close  334




#define X_Alarm_bk_close  343
#define Y_Alarm_bk_close  334



#define X_Setup_info_column_upgrade_close_d  X_Setup_info_column_upgrade_close
#define Y_Setup_info_column_upgrade_close_d  Y_Setup_info_column_upgrade_close
///////////////////////////////////////////////////////////////////////
#define empty_father_p 0 
#define empty_fon_p 0 
#define empty_fun 0 

#define SETUP_OFFSET_LEFT 14
#define SETUP_OFFSET_RIGHT 20
#define SETUP_OFFSET_BTN 8
#define SETUP_OFFSET_ENTER_BTN 0

#define SETUP_X_set_mid_offset 527
#define SETUP_Y_set_mid_offset 15+10 //设置页蓝色字体y偏移

typedef struct
{
	u8 output_source_priority;
	u8 ac_input_vol_range;
	u8 max_charging_cur;
	u8 max_utility_charging_cur;
	u8 vol_point_back_to_utility_source;
	u8 power_saving_mode;
	u8 charger_source_priority;
	u8 output_vol;
	u8 output_fre;
	u8 alarm_ctrl;
	u8 beeps;
	u8 battery_type;
	u8 bulk_charging_vol;
	u8 float_charging_vol;
	u8 low_dc_cut_off_vol;
	u8 restart_overload_occurs;
	u8 restart_temp_occurs;
	u8 record_fault_code;
}ACOPWER_INV;


typedef enum
{
  BATTERY_NC=0,
  BATTERY_LINKS2_KL500A,
  BATTERY_VICTRON_SMART_SHUNT,
  BATTERY_LINKS2_RV_BAT12_400,
  BATTERY_RV_C,
  BATTERY_LIST_END,
 
}BATTERY_SMART_SHUNT_TYPE;

typedef enum
{
  INVERTER_NC=0,
  INVERTER_VICTRON_MULTIPLUS,
  INVERTER_LINKS2_12V_3000W,
  INVERTER_RV_C, 
  INVERTER_LIST_END, 
}INVERTER_TYPE;

typedef enum
{
  MPPT_NC=0,
  MPPT_SRNE_MA4830N15,
  MPPT_VICTRON_SMARTSOLAR_CHG,
  MPPT_LINKS2_12V50A_DC_MPPT,
  MPPT_RV_C, 
  MPPT_LIST_END, 
}MPPT_TYPE;

typedef enum
{
  DCDC_NC=0,
  DCDC_LINKS2_12V50A_DC_MPPT,
  DCDC_RV_C, 
  DCDC_LIST_END,
}DCDC_TYPE;

typedef struct
{   
  BATTERY_SMART_SHUNT_TYPE Battery_SmartShun_Type;
  INVERTER_TYPE Inverter_Type;
  MPPT_TYPE Mppt_Type;
  DCDC_TYPE DC_Changer_Type;
	u8 Battery_SmartShun_Type_change_cnt;//S
  u8 Inverter_Type_change_cnt;//S
  u8 Mppt_Type_change_cnt;//S
  u8 DC_Changer_Type_change_cnt;//S
}TYPE_SEL;
extern TYPE_SEL type_sel;
///
extern u8 setup_page_display_num;
extern u8 last_show_page_num[3] ;
extern u8 last_show_page_level  ;
extern ACOPWER_INV acopower_inv;


extern lcd_dis_item_t setup_5_chun_item[31];
////////////
extern void ui_column_setup_init_5(void);
extern void ui_column_setup_set_info(bool upgrage);
extern void ui_column_setup_power_system_info_str(bool upgrade);
extern void ui_column_setup_system_upgrade_info_str(bool upgrade);
extern void func_set_upgrade_close_key_type(KEY_TYPE key_type);
extern void func_set_upgrade_open_key_type(KEY_TYPE key_type);
//extern void ui_column_power_system_setting_info(bool upgrage);
















