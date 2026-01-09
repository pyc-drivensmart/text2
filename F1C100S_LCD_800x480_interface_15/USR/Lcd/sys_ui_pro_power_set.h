



#define X_power_set_block1  134
#define Y_power_set_block1  65

#define X_power_set_block2  429
#define Y_power_set_block2  65

#define X_power_set_block3  724
#define Y_power_set_block3  65

#define X_power_set_block4  134
#define Y_power_set_block4  288

#define X_power_set_block5  429
#define Y_power_set_block5  288

#define X_power_set_choose_auto  558
#define Y_power_set_choose_auto  315

#define X_power_set_choose_manual  558
#define Y_power_set_choose_manual  315

#define X_power_ico_char_offset 209
#define Y_power_ico_char_offset 45

#define X_power_ico_char_offset1 209
#define Y_power_ico_char_offset1 106

#define X_power_ico_char_offset2 209
#define Y_power_ico_char_offset2 164


#define X_power_d_ico_char0  X_power_ico_char_offset+X_power_set_block1
#define Y_power_d_ico_char0  Y_power_ico_char_offset+Y_power_set_block1
#define X_power_d_ico_char1  X_power_ico_char_offset1+X_power_set_block1
#define Y_power_d_ico_char1  Y_power_ico_char_offset1+Y_power_set_block1
#define X_power_d_ico_char2  X_power_ico_char_offset2+X_power_set_block1
#define Y_power_d_ico_char2  Y_power_ico_char_offset2+Y_power_set_block1

#define X_power_d_ico_char3  X_power_ico_char_offset+X_power_set_block2
#define Y_power_d_ico_char3  Y_power_ico_char_offset+Y_power_set_block2
#define X_power_d_ico_char4  X_power_ico_char_offset1+X_power_set_block2
#define Y_power_d_ico_char4  Y_power_ico_char_offset1+Y_power_set_block2
#define X_power_d_ico_char5  X_power_ico_char_offset2+X_power_set_block2
#define Y_power_d_ico_char5  Y_power_ico_char_offset2+Y_power_set_block2

#define X_power_d_ico_char6  X_power_ico_char_offset+X_power_set_block3
#define Y_power_d_ico_char6  Y_power_ico_char_offset+Y_power_set_block3
#define X_power_d_ico_char7  X_power_ico_char_offset1+X_power_set_block3
#define Y_power_d_ico_char7  Y_power_ico_char_offset1+Y_power_set_block3
#define X_power_d_ico_char8  X_power_ico_char_offset2+X_power_set_block3
#define Y_power_d_ico_char8  Y_power_ico_char_offset2+Y_power_set_block3

#define X_power_d_ico_char9  X_power_ico_char_offset+X_power_set_block4
#define Y_power_d_ico_char9  Y_power_ico_char_offset+Y_power_set_block4
#define X_power_d_ico_char10  X_power_ico_char_offset1+X_power_set_block4
#define Y_power_d_ico_char10  Y_power_ico_char_offset1+Y_power_set_block4
#define X_power_d_ico_char11  X_power_ico_char_offset2+X_power_set_block4
#define Y_power_d_ico_char11  Y_power_ico_char_offset2+Y_power_set_block4

#define X_power_d_ico_char12  X_power_ico_char_offset1+X_power_set_block5
#define Y_power_d_ico_char12  Y_power_ico_char_offset1+Y_power_set_block5
#define X_power_d_ico_char13  X_power_ico_char_offset2+X_power_set_block5
#define Y_power_d_ico_char13  Y_power_ico_char_offset2+Y_power_set_block5


extern u8 power_set_send_id[9];
extern u16 *power_display_set_ch[9];
extern u16 *power_display_set_return_ch[9];
extern void disply_power_set_name_bg(u8 ich,bool upgrade);
extern void disply_power_set_info(bool upgrage);
extern BOOL page_power_set_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_power_set_init(void);
extern void disply_power_set_name(bool upgrade);
extern void disply_power_status(u8 type,bool upgrage);



extern  u8 power_now_set_send_id;


extern bool f_display_power_setup_info;


extern void display_power_setup_info(bool upgrage);
extern setup_page_t power_setup_page;
extern setup_item_info_t power_settings[];
extern BOOL page_power_setup_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_power_setup_init(void);
extern void check_power_setup_status(bool upgrage);
