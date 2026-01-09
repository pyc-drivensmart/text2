

#define DIALOG_MSG_TYPE_OVERRIDE_KEY 0
#define DIALOG_MSG_TYPE_MOTOR_WARNING 1
#define DIALOG_MSG_TYPE_HANDBREAK_WARNING 2
extern bool f_ui_disply_dialog_msg;
extern bool f_ui_need_disply_dialog_msg;
extern u32 v_ui_need_out_dialog_msg_cnt;
extern u8 v_ui_disply_dialog_msg_type;
extern void ui_disply_dialog_msg(void);
extern BOOL page_dialog_msg_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_dialog_msg_init(void);
extern void ui_out_dialog_msg(void);
extern void disply_msg_name(bool upgrade);
extern void set_v_ui_need_out_dialog_msg_cnt(void);
extern void check_ui_out_dialog_msg(void);
