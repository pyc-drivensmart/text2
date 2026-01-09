
/*
#define X_dialog_bg  201//194
#define Y_dialog_bg  57//76

#define X_dialog_close_d  336
#define Y_dialog_close_d  449

#define X_dialog_close_u  336
#define Y_dialog_close_u  449

#define X_dialog_save_d  581
#define Y_dialog_save_d  449

#define X_dialog_save_u  581
#define Y_dialog_save_u  449
*/



extern u8 now_dialog_info_select_ch;
extern u8 now_dialog_info_select_num;
extern bool f_ui_disply_dialog_info;
extern bool f_ui_disply_dialog_info_5;
extern bool f_ui_init_finsh;
extern bool f_ui_need_disply_dialog_info;
extern void ui_disply_dialog_info(void);
extern BOOL page_dialog_info_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_dialog_info_init(void);
extern void ui_out_dialog_info(void);
extern void disply_info_name(bool upgrade);
extern void disply_info(bool upgrade);
extern void set_dialog_info_start_key_type(KEY_TYPE key_type);
extern void set_dialog_info_close_key_type(KEY_TYPE key_type);

