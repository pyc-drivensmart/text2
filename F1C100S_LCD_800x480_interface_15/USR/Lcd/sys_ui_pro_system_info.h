
#define X_system_info_ble_code 320
#define Y_system_info_ble_code 170

#define X_system_info_screen_upgrade_d  437
#define Y_system_info_screen_upgrade_d  239

#define X_system_info_screen_upgrade_u  437
#define Y_system_info_screen_upgrade_u  239

#define X_system_info_control_upgrade_d  437
#define Y_system_info_control_upgrade_d  309

#define X_system_info_control_upgrade_u  437
#define Y_system_info_control_upgrade_u  309

#define X_system_info_code_d 358
#define Y_system_info_code_d 193

#define X_system_info_code_u 358
#define Y_system_info_code_u 193
extern BOOL page_system_info_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_system_alarm_init(void);


extern u16 now_page_info;//从高到低 --1级--2级--3级--4级
extern u8 now_page_info_deep;//当前处于哪一层


extern void ui_system_info_init(void);
extern void display_set_info_info(bool upgrade);
