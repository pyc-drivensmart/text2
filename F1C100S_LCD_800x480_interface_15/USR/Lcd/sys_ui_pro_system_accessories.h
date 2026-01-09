

#define X_system_accessories_btn1_d  140
#define Y_system_accessories_btn1_d  142

#define X_system_accessories_btn1_u  140
#define Y_system_accessories_btn1_u  142

#define X_system_accessories_btn2_d  140
#define Y_system_accessories_btn2_d  233

#define X_system_accessories_btn2_u  140
#define Y_system_accessories_btn2_u  233

#define X_system_accessories_btn3_d  140
#define Y_system_accessories_btn3_d  324

#define X_system_accessories_btn3_u  140
#define Y_system_accessories_btn3_u  324

#define X_system_accessories_btn4_d  140
#define Y_system_accessories_btn4_d  415

#define X_system_accessories_btn4_u  140
#define Y_system_accessories_btn4_u  415






#define X_system_accessories_b_system_accessories_d  140
#define Y_system_accessories_b_system_accessories_d  514

#define X_system_accessories_b_system_accessories_u  140
#define Y_system_accessories_b_system_accessories_u  514

#define X_system_accessories_headline  142
#define Y_system_accessories_headline  128

#define X_system_accessories_nextpage_d  887
#define Y_system_accessories_nextpage_d  415

#define X_system_accessories_nextpage_o  887
#define Y_system_accessories_nextpage_o  415

#define X_system_accessories_nextpage_u  887
#define Y_system_accessories_nextpage_u  415

#define X_system_accessories_prepage_d  887
#define Y_system_accessories_prepage_d  142

#define X_system_accessories_prepage_o  887
#define Y_system_accessories_prepage_o  142

#define X_system_accessories_prepage_u  887
#define Y_system_accessories_prepage_u  142



extern bool f_display_set_accessories_info;
extern setup_page_t accessories_page;


extern setup_item_info_t accessory_settings[];
extern void func_Temperature_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type);
//extern void func_Tanks_Sensor_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_External_Key_Type(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Battery_Capacity(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Percentage_of_Battery_Capacity(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Ignore_Handbreak(void* p,u8 sn,DEAl_TYPE deal_type);


extern BOOL page_system_accessories_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_system_accessories_init(void);


extern u16 now_page_accessories;//从高到低 --1级--2级--3级--4级
extern u8 now_page_accessories_deep;//当前处于哪一层
extern void display_set_accessories_info(bool upgrage);
extern void check_parts_set_status(bool upgrage);
