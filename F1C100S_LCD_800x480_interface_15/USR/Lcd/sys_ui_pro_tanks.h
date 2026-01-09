

#define X_offset1 12
#define Y_offset1 24

#define X_tanks_black_bg  594
#define Y_tanks_black_bg  102

#define X_tanks_black_100  X_offset1+X_tanks_black_bg//-1
#define Y_tanks_black_100  Y_offset1+Y_tanks_black_bg



#define X_tanks_black_wave  X_offset1+X_tanks_black_bg//-1
#define Y_tanks_black_wave  Y_offset1+Y_tanks_black_bg


#define X_tanks_b_tanks_d  140
#define Y_tanks_b_tanks_d  514

#define X_tanks_b_tanks_u  140
#define Y_tanks_b_tanks_u  514

#define X_tanks_fresh_bg  185
#define Y_tanks_fresh_bg  102

#define X_tanks_fresh_100  X_offset1+X_tanks_fresh_bg
#define Y_tanks_fresh_100  Y_offset1+Y_tanks_fresh_bg



#define X_tanks_fresh_wave  X_offset1+X_tanks_fresh_bg
#define Y_tanks_fresh_wave  Y_offset1+Y_tanks_fresh_bg
#define X_tanks_grey_bg  389
#define Y_tanks_grey_bg  102
#define X_tanks_grey_100  X_offset1+X_tanks_grey_bg
#define Y_tanks_grey_100  Y_offset1+Y_tanks_grey_bg



#define X_tanks_grey_wave X_offset1+X_tanks_grey_bg
#define Y_tanks_grey_wave  Y_offset1+Y_tanks_grey_bg



#define X_tanks_LPG_bg  796
#define Y_tanks_LPG_bg  102

#define X_tanks_LPG_100  X_offset1+X_tanks_LPG_bg
#define Y_tanks_LPG_100  Y_offset1+Y_tanks_LPG_bg


#define X_tanks_LPG_wave  X_offset1+X_tanks_LPG_bg
#define Y_tanks_LPG_wave  Y_offset1+Y_tanks_LPG_bg

#define X_tanks_wpOFF_d  206//402
#define Y_tanks_wpOFF_d  406//386

#define X_tanks_wpOFF_u  206
#define Y_tanks_wpOFF_u  406

#define X_tanks_wpON_d  206
#define Y_tanks_wpON_d  406

#define X_tanks_wpON_u  206
#define Y_tanks_wpON_u  406

#define X_tanks_heat_ON  610
#define Y_tanks_heat_ON  406
#define X_tanks_heat_OFF  610
#define Y_tanks_heat_OFF  406

extern u8 ICO_tanks_wp;
extern void disply_big_tanks_status(u8 type,bool upgrage);

extern BOOL page_tanks_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_tanks_init(void);
extern void disply_tanks_tank_ch_name(bool upgrade);
extern void set_tanks_item_key_type(void);
