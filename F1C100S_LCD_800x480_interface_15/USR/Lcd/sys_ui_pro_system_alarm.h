
/*
#define X_system_b_alarm_d  265
#define Y_system_b_alarm_d  514

#define X_system_b_alarm_u  265
#define Y_system_b_alarm_u  514

*/

#define X_system_alarm_btn1_d  140
#define Y_system_alarm_btn1_d  142

#define X_system_alarm_btn1_u  140
#define Y_system_alarm_btn1_u  142

#define X_system_alarm_btn2_d  140
#define Y_system_alarm_btn2_d  233

#define X_system_alarm_btn2_u  140
#define Y_system_alarm_btn2_u  233

#define X_system_alarm_btn3_d  140
#define Y_system_alarm_btn3_d  324

#define X_system_alarm_btn3_u  140
#define Y_system_alarm_btn3_u  324

#define X_system_alarm_btn4_d  140
#define Y_system_alarm_btn4_d  415

#define X_system_alarm_btn4_u  140
#define Y_system_alarm_btn4_u  415


#define X_set_err_r_1  X_system_btn1_d+22
#define X_set_err_r_2  X_system_btn2_d+22
#define X_set_err_r_3  X_system_btn3_d+22
#define X_set_err_r_4  X_system_btn4_d+22

#define Y_set_err_r_1  Y_system_btn1_d+22 
#define Y_set_err_r_2  Y_system_btn2_d+22
#define Y_set_err_r_3  Y_system_btn3_d+22
#define Y_set_err_r_4  Y_system_btn4_d+22

#define X_set_err_y_1  X_system_btn1_d+22
#define X_set_err_y_2  X_system_btn2_d+22
#define X_set_err_y_3  X_system_btn3_d+22
#define X_set_err_y_4  X_system_btn4_d+22

#define Y_set_err_y_1  Y_system_btn1_d+22
#define Y_set_err_y_2  Y_system_btn2_d+22
#define Y_set_err_y_3  Y_system_btn3_d+22
#define Y_set_err_y_4  Y_system_btn4_d+22




#define X_system_alarm_b_system_alarm_d  140
#define Y_system_alarm_b_system_alarm_d  514

#define X_system_alarm_b_system_alarm_u  140
#define Y_system_alarm_b_system_alarm_u  514

#define X_system_alarm_headline  142
#define Y_system_alarm_headline  128

#define X_system_alarm_nextpage_d  887
#define Y_system_alarm_nextpage_d  415

#define X_system_alarm_nextpage_o  887
#define Y_system_alarm_nextpage_o  415

#define X_system_alarm_nextpage_u  887
#define Y_system_alarm_nextpage_u  415

#define X_system_alarm_prepage_d  887
#define Y_system_alarm_prepage_d  142

#define X_system_alarm_prepage_o  887
#define Y_system_alarm_prepage_o  142

#define X_system_alarm_prepage_u  887
#define Y_system_alarm_prepage_u  142

extern BOOL page_system_alarm_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_system_alarm_init(void);

extern void reset_page_alarm(void);
extern u16 now_page_alarm;//从高到低 --1级--2级--3级--4级
extern u8 now_page_alarm_deep;//当前处于哪一层
extern void display_set_alarm_info(void);
extern void alarm_info_printf(u8 num,lcd_dis_item_t* p,WARNING_CODE_LIST* p_list,u8 list_num);

