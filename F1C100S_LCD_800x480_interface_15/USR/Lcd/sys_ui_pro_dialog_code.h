
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





extern u8 now_dialog_code_select_ch;
extern u8 now_dialog_code_select_num;
extern bool f_ui_disply_dialog_code;
extern bool f_ui_init_finsh;
extern bool f_ui_need_disply_dialog_code;
extern void ui_disply_dialog_code(void);
extern BOOL page_dialog_code_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_dialog_code_init(void);
extern void ui_out_dialog_code(void);
extern void disply_code_name(bool upgrade);
