






#define X_load_motobtn0_u 304
#define Y_load_motobtn0_u 117

#define X_load_motobtn1_u 574
#define Y_load_motobtn1_u 117


#define X_loads_b_Motors_d 265
#define Y_loads_b_Motors_d 514

#define X_loads_b_Motors_u 265
#define Y_loads_b_Motors_u 514

#define X_loads_b_Motors_f 265
#define Y_loads_b_Motors_f 514

#define X_load_motoctl_btn_d 330
#define Y_load_motoctl_btn_d 304

#define X_load_motoctl_btn_u 330
#define Y_load_motoctl_btn_u 304



#define X_load_motoctl_btn_down_d 330
#define Y_load_motoctl_btn_down_d 365

#define X_load_motoctl_btn_down_u 330
#define Y_load_motoctl_btn_down_u 365


#define X_load_motoctl_btn1_d 601
#define Y_load_motoctl_btn1_d 304

#define X_load_motoctl_btn1_u 601
#define Y_load_motoctl_btn1_u 304


#define X_load_motoctl_btn1_down_d 601
#define Y_load_motoctl_btn1_down_d 365

#define X_load_motoctl_btn1_down_u 601
#define Y_load_motoctl_btn1_down_u 365




#define X_Motors_Awning_ico_u  26//340
#define Y_Motors_Awning_ico_u  41//158

#define X_Motors_Curtain_ico_u 26//340
#define Y_Motors_Curtain_ico_u  41//158

#define X_Motors_Expansion_ico_u 26//340
#define Y_Motors_Expansion_ico_u 41//158





#define MAX_LOADS_MOTORS_DIAPLAY_NUM 2

extern u8 loads_display_motors_ch[MAX_LOADS_MOTORS_DIAPLAY_NUM];
extern u8 loads_motor_u_ico_select_p[MAX_LOADS_MOTORS_DIAPLAY_NUM];
extern u8 loads_motor_u_ico_select_ch;
extern BOOL page_loads_deel_with_i(lcd_dis_page_t *p2,u8* i);

///////////////////////////////////////////////////
extern void ui_loads_motors_init(void);
extern void disply_loads_motor_ch_name(bool upgrade);
extern void disply_loads_motor_name(bool upgrade);
extern void disply_motors_current_val(bool upgrade);
extern void set_loads_motors_item_key_type(KEY_TYPE type);

