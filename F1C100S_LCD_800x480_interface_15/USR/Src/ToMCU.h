
#define CONTROL_MCU_VER_LEN 16
#define EXTRA_DEVICE_VER_LEN 50
extern char MCU_VERSION_STR[40];
extern char BT_MAC_STR[12];
extern char CONTROL_MCU_VERSION_STR[50];
extern char CONTROL_SECOND_MCU_VERSION_STR[50];
extern char External_key_MCU_VERSION_STR[50];
extern char External_protocol_MCU_VERSION_STR[50];

extern u8 External_key_mcu_ver_len;
extern u8 External_key_mcu_ver[20];
extern u8 External_protocol_mcu_ver_len ;
extern u8 External_protocol_mcu_ver[20];

extern char Extra_device_mppt_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_Dc_Dc_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_inverter_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_battery_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_battery2_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_battery3_ver[EXTRA_DEVICE_VER_LEN];
extern u16 Control_Unit_product_id;
#define NEW_CONTROL_UNIT_PRODUCT_ID 0x00E1

//0x81
#define HC_MASTER_CMD_START_END 0x81
#define HC_MASTER_CMD_QUERY_STATE 0x90
#define HC_SLAVE_CMD_VERSION 0x30
#define HC_SLAVE_CMD_CODE_RETURN 0x31
#define HC_SLAVE_CMD_MAC 0x32
#define HC_SLAVE_CMD_OTHER_INFO_CONNECT 0x33
#define HC_SLAVE_CMD_EXT_MCU_PRINTF 0x34
#define HC_SLAVE_CMD_PRODUCT_ID 0x35

#define HC_SLAVE_CMD_BASE_STATUS 0x24

#define HC_SLAVE_CMD_RGB_STATUS 0x5B //RGB

#define HC_SLAVE_CMD_DIESEL_HEATERS_STATUS 0x5C //柴暖


#define HC_SLAVE_CMD_SWITCH_STATUS 0x60
#define HC_SLAVE_CMD_SWITCH_NAME 0x61
#define HC_SLAVE_CMD_INTERVER_STATUS 0x62
#define HC_SLAVE_CMD_BATTERY_STATUS 0x63
#define HC_SLAVE_CMD_CHANGE_STATUS 0x64
#define HC_SLAVE_CMD_SOLAR_STATUS 0x65
#define HC_SLAVE_CMD_VAL_STATUS 0x66
#define HC_SLAVE_CMD_TEMP_STATUS 0x67
#define HC_SLAVE_CMD_SWITCH_CH 0x68
#define HC_SLAVE_CMD_EXT_KRY_TYPE 0x69 //旧手刹
#define HC_SLAVE_CMD_WARNING_CODE_LIST 0x6A

#define HC_SLAVE_CMD_BATTERY_SET_STATUS 0x70
#define HC_SLAVE_CMD_FRESH_SET_STATUS 0x71
#define HC_SLAVE_CMD_BLACK_SET_STATUS 0x72
#define HC_SLAVE_CMD_GREY_SET_STATUS 0x73
#define HC_SLAVE_CMD_LPG_SET_STATUS 0x74
#define HC_SLAVE_CMD_TIME_STATUS 0x75
#define HC_SLAVE_CMD_BASE_SET_STATUS 0x76
#define HC_SLAVE_CMD_PARTS_SET_STATUS 0x77
#define HC_SLAVE_CMD_CH_CURRENT_STATUS 0x78


#define HC_SLAVE_CMD_HVAC_SET_STATUS 0x7C//空调


#define HC_SLAVE_CMD_INFO_STATUS 0x88

#define HC_SLAVE_CMD_CODE_CONNECT 0x31


#define HC_MASTER_CMD_SWITCH_CTR 0xC0
#define HC_MASTER_CMD_SWITCH_NAME 0xC1
#define HC_MASTER_CMD_SET_CMD 0xC2
#define HC_MASTER_CMD_TIME_SET 0xC3
#define HC_MASTER_CMD_BASE_SET 0xC4



typedef struct
{
   u16 val_max;
   u16 val_warning_H_or_Low_Alarm;
   u16 val_alarm_H;
	 u16 val_protect_L;
	 u8 Tank_type;
	 u8 Tank_sensor_type;
   u16 temp_auto_heat_begin;
   u16 temp_auto_heat_stop;

}TANK_SET_STATUS;

typedef struct
{
   u16 V_warning_L;
   u16 V_warning_H;
   u16 V_SOC_warning_L;
   
}BATTERY_SET_STATUS;
extern BATTERY_SET_STATUS main_battery_set_status,assi1_battery_set_status,assi2_battery_set_status;

typedef struct
{
   u16 val_max;
   u16 val_warning_L;
   u16 val_warning_H;
   u16 val_protect;

}FRESH_SET_STATUS;
extern FRESH_SET_STATUS fresh_set_status;



typedef struct
{
   u16 val_max;
   u16 val_warning_H;
   u16 val_alarm_H;
   u16 temp_auto_heat_begin;
   u16 temp_auto_heat_stop;

}BACK_SET_STATUS;
extern BACK_SET_STATUS back_set_status;

typedef struct
{
   u16 val_max;
   u16 val_warning_H;
   u16 val_alarm_H;
}GREY_SET_STATUS;
extern GREY_SET_STATUS grey_set_status;
typedef struct
{
   u16 val_max;
   u16 val_warning_L;
   u16 val_warning_H;
   //u16 val_protect;

}LPG_SET_STATUS;
extern LPG_SET_STATUS LPG_set_status;


typedef struct
{
   u16 Capacity;
   u8 Percentage;
	 u8 temp_sensor_type;
	 u8 tanks_sensor_type;
	 u8 Inverter_Mode;
	 u16 Inverter_Input_Current_Limit;
	 u16 Inverter_Alarm_setup1;
	 u16 Inverter_Alarm_setup2;
}PARTS_SET_STATUS;//coulombmeter
extern PARTS_SET_STATUS  parts_set_return_status,parts_set_status;

typedef struct
{
   u8 year;
   u8 mon;
   u8 day;
   u8 hour;
   u8 min;
   u8 sec;
	 u8 format;//bit7 1:12h 0:24h
}TIME_STATUS;
extern TIME_STATUS time_status;


typedef struct
{
   u8 uint;
   u8 language;
   u8 light;
   u8 R;
   u8 G;
   u8 B;
   u8 sleep_time;
	 u8 touch_tone;
}BASE_STATUS;
extern BASE_STATUS base_status;
extern u16 code_connect; //??????
extern bool f_sleep_now;
extern u8 f_fault_on;
extern bool f_fault_flash;
extern bool f_override_key;
extern bool f_handbreak;
extern bool f_ignore_handbreak;



#define NAME_TXT_MAX_LEN 16
#define SWITCH_NAME_CH_NUM 30
typedef struct
{   
   u8 txt[NAME_TXT_MAX_LEN];
	 u8 txt_len;
	 u8 icon_select;

}SWITCH_NAME_LIST;
extern SWITCH_NAME_LIST switch_name_list[SWITCH_NAME_CH_NUM];



extern BATTERY_SET_STATUS main_battery_set_status,assi1_battery_set_status,assi2_battery_set_status;
extern FRESH_SET_STATUS fresh_set_status;
extern BACK_SET_STATUS back_set_status;
extern GREY_SET_STATUS grey_set_status;
extern LPG_SET_STATUS LPG_set_status;
extern TIME_STATUS time_status;
extern SWITCH_NAME_LIST switch_name_list[SWITCH_NAME_CH_NUM]; //1-20
extern u16 current_val[SWITCH_NAME_CH_NUM];
extern bool f_disply_current_val;
extern bool f_disply_debug_val;
extern u32 External_key_type;//2bit一个按键，从高2位表示ch1  0:表示触摸，1表示自锁，2，3未知

//返回
extern BATTERY_SET_STATUS main_battery_set_return_status,assi1_battery_set_return_status,assi2_battery_set_return_status;
extern FRESH_SET_STATUS fresh_set_return_status;
extern BACK_SET_STATUS back_set_return_status;
extern GREY_SET_STATUS grey_set_return_status;
extern LPG_SET_STATUS LPG_set_return_status;
extern TANK_SET_STATUS Tank1_set_return_status;
extern TANK_SET_STATUS Tank2_set_return_status;
extern TANK_SET_STATUS Tank3_set_return_status;
extern TANK_SET_STATUS Tank4_set_return_status;

extern PARTS_SET_STATUS parts_set_return_status;
extern TIME_STATUS time_return_status;
extern SWITCH_NAME_LIST switch_name_list_return[SWITCH_NAME_CH_NUM]; //1-switch_ch_select_num_max
extern u8 switch_ch_list_return[SWITCH_NAME_CH_NUM]; //switch1-switch_ch_select_num_max  switch 选择通道
extern u32 External_key_type_return;//2bit一个按键，从高2位表示ch1   0:表示触摸，1表示自锁，2，3未知

typedef struct
{
   u16 V_220;
   u16 V_dc;
   u16 V_o;
   u16 I_220;
   u16 I_dc;
   u16 I_o;
	 u16 P_220;
   u16 P_dc;
   u16 P_o;
	 u8 F_220;
	 u8 F_o;
   u8 MAX_temp;
   u8 mode;
}INVERTER_STATUS;
extern INVERTER_STATUS Inverter_status;
typedef struct
{
   u16 V;
   u16 I;
   u8 Q;
   u8 MAX_temp;
	 bool f_time_changer;
   u16 time;
}BATTERY_STATUS;
extern BATTERY_STATUS main_battery_status,assi1_battery_status,assi2_battery_status;
typedef struct
{
   u16 V_in;
   u16 I_in;
   u16 Power;
   u16 time;
	 u16 V_batt;
   u16 I_batt;
   u16 P_batt;
}CHARGER_STATUS;

extern CHARGER_STATUS Fully_Charger,Booster_Charger,Solar_Charger,Combi_CHG,ACin_charger,ACout_charger;
typedef struct
{
   u16 Temp_in;
   u16 Humidness_in;
   u16 Temp_out;
   u16 Humidness_out;
   
   
}TEMP_STATUS;
extern TEMP_STATUS temp_status;


typedef struct
{
   u16 V_in;
   u16 I_in;
   u16 V_batt;
   u16 I_batt;   
   u16 V_load;
   u16 I_load;
	 u16 Power;
}SOLAR_STATUS;
extern SOLAR_STATUS solar_status;

typedef struct
{
   u8 val_tank1;
   u8 val_tank2;
   u8 val_tank3;
   u8 val_tank4;

}VAL_STATUS;
extern VAL_STATUS val_status;


#define TXT_MAX_LEN 120
#define WAINING_CODE_MAX_LEN 48

typedef struct
{
   TIME_STATUS time_happen;
	 u8 err_code_from;//来源分类(8bit)=0：常规 =80：电力系统（最高位是1，后面还要进行详细分类，如MPPT等）
   u8 err_code_type;//警告类型(8bit)=1：警告  =2：故障/错误   =3：保护   =4：没连接
	 u8 time_cnt;//最大显示99 超过10次不再弹警告
   u8 txt_len;
   u8 txt[TXT_MAX_LEN];

}WARNING_CODE_LIST;
extern WARNING_CODE_LIST waining_code_list[WAINING_CODE_MAX_LEN+1];//从[1]算起
extern u8 last_waining_code_list_num;
extern u8 waining_code_list_num;
extern WARNING_CODE_LIST power_waining_code_list[WAINING_CODE_MAX_LEN+1];//从[1]算起
extern u8 power_waining_code_list_num;

extern u16 X_offset_test;
extern u16 Y_offset_test;//这两个值用来微调 测试 找准座标  通过0xFE发送


#define PWM_CTRL_CH  10
#define PWM_CTRL_MIN_VAL 5
#define PWM_CTRL_MAX_VAL 100
extern u8 switch_ctrl_byte[5];
extern u8 pwm_ctrl_byte[PWM_CTRL_CH];//??????1-4,

extern u8 pwm_rgb_ctrl_byte;//??????1-4,

//extern bool f_load9_on;
//extern bool f_load10_on;
//extern bool f_black_heart_auto_on;
extern bool f_ble_have;
extern bool f_ble_connect_on;
extern u8 old_switch_ctrl_byte[5];
extern u8 old_pwm_ctrl_byte[PWM_CTRL_CH];//??????1-4,
//extern bool old_f_load9_on;
//extern bool old_f_load10_on;
extern u8 switch_ch_select_num_max;
extern BASE_STATUS base_status;
extern BASE_STATUS base_return_status;

extern bool f_FlC200_send_Heartbeat;
extern u8 upgrade_info_len1;
extern u8 upgrade_info_len2;
extern u8 upgrade_info_len3;
extern char upgrade_info1[48];
extern char upgrade_info2[48];
extern char upgrade_info3[48];
extern void FlC200_init(void);
extern bool FlC200_hc_cmd_proc(u8 * buf);//所有通过CRC的指令都会在这里解释
extern void F1C200_rx_pro(void);
extern void FlC200_hc_ready_time_send_proc(void);

extern void send_FlC200_connect_req_cmd(void);//
extern bool set_switch_icon_status(void);
extern void send_FlC200_swtich_cmd(u8 type,u8 cmd);//

extern void send_FlC200_swtich2B_cmd(u8 type,u8 cmd1,u8 cmd2);//c0


extern void send_FlC200_swtich_name_cmd(u8 type);//

extern void send_FlC200_set_cmd(u8 type,u16 para);//

extern void send_FlC200_set_cmd_new(u8 type,u16 para,u8 ch);//


extern void send_FlC200_time_set_cmd(void);//
extern void send_FlC200_base_set_cmd(u8 type,u8 para,u8 para2);//
extern void send_FlC200_test_cmd(u8 mode);//
extern bool  Is_Inverter_mode_Inverting(void);
extern bool  Is_Inverter_mode_AC_IN(void);
