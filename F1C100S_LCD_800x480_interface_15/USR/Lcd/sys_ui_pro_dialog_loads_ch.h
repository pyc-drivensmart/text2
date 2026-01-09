
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


#define X_loads_setup_ch_d_char0  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*0
#define Y_loads_setup_ch_d_char0  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
#define X_loads_setup_ch_d_char1  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*1
#define Y_loads_setup_ch_d_char1  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
#define X_loads_setup_ch_d_char2  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*2
#define Y_loads_setup_ch_d_char2  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
#define X_loads_setup_ch_d_char3  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*3
#define Y_loads_setup_ch_d_char3  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
#define X_loads_setup_ch_d_char4  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*4
#define Y_loads_setup_ch_d_char4  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0

#define X_loads_setup_ch_d_char5  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*5
#define Y_loads_setup_ch_d_char5  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
#define X_loads_setup_ch_d_char6  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*6
#define Y_loads_setup_ch_d_char6  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
#define X_loads_setup_ch_d_char7  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*7
#define Y_loads_setup_ch_d_char7  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0

#define X_loads_setup_ch_d_char8  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*8
#define Y_loads_setup_ch_d_char8  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
#define X_loads_setup_ch_d_char9  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*9
#define Y_loads_setup_ch_d_char9  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0


#define X_loads_setup_ch_d_char10  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*10
#define Y_loads_setup_ch_d_char10  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
#define X_loads_setup_ch_d_char11  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*11
#define Y_loads_setup_ch_d_char11  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*0
//以下为扩展通道 还没有改变坐标

#define X_loads_setup_ch_d_char12  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*2
#define Y_loads_setup_ch_d_char12  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*2
#define X_loads_setup_ch_d_char13  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*3
#define Y_loads_setup_ch_d_char13  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*2
#define X_loads_setup_ch_d_char14  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*4
#define Y_loads_setup_ch_d_char14  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*2

#define X_loads_setup_ch_d_char15  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*0
#define Y_loads_setup_ch_d_char15  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*3
#define X_loads_setup_ch_d_char16  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*1
#define Y_loads_setup_ch_d_char16  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*3
#define X_loads_setup_ch_d_char17  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*2
#define Y_loads_setup_ch_d_char17  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*3
#define X_loads_setup_ch_d_char18  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*3
#define Y_loads_setup_ch_d_char18  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*3
#define X_loads_setup_ch_d_char19  X_dialog_bg+X_INTER_OFFET+X_INTER_SPACE*4
#define Y_loads_setup_ch_d_char19  Y_dialog_bg+Y_INTER_OFFET+Y_INTER_SPACE*3


#define DIALOG_LOADS_CH_MAX 20
extern u8 now_dialog_loads_ch_select_ch;
extern u8 now_dialog_loads_ch_select_num;
extern bool f_ui_disply_dialog_loads_ch;
extern bool f_need_ui_disply_dialog_loads;
extern void ui_disply_dialog_loads_ch(void);
extern BOOL page_dialog_loads_ch_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_dialog_loads_ch_init(void);
extern void ui_out_dialog_loads_ch(void);
extern void disply_loads_ch_name(bool upgrade);
