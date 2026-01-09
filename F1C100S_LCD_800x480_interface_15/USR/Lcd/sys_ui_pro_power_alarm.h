
extern BOOL page_power_alarm_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_power_alarm_init(void);

extern void reset_page_power_alarm(void);
extern u16 now_page_power_alarm;//从高到低 --1级--2级--3级--4级
extern u8 now_page_power_alarm_deep;//当前处于哪一层
extern void display_power_alarm_info(void);

