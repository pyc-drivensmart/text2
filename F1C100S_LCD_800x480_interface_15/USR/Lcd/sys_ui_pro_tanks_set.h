






extern u8 tanks_now_set_send_id;
extern bool f_display_tanks_setup_info;


extern void display_tanks_setup_info(bool upgrage);
extern setup_page_t tanks_setup_page;
extern setup_item_info_t tanks_settings[];
extern BOOL page_tanks_setup_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_tanks_setup_init(void);




extern void func_Tank_Type(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd);
extern void func_Tank1_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank2_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank3_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank4_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank_Capacity(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd);
extern void func_Tank1_Capacity(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank2_Capacity(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank3_Capacity(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank4_Capacity(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd);
extern void func_Tank1_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank2_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank3_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank4_High_Warning_or_Low_Alarm(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type,TANK_SET_STATUS* Tank_status,u8 set_cmd);
extern void func_Tank1_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank2_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank3_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank4_High_Alarm(void* p,u8 sn,DEAl_TYPE deal_type);
extern void check_tanks_setup_status(bool upgrage);
extern void func_Water_Pump_Channel(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Water_Heater_Channel(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Save_And_Back(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_get_Channel(void* p,u8 sn,DEAl_TYPE deal_type);

extern void func_Tank1_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank2_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank3_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Tank4_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type);

