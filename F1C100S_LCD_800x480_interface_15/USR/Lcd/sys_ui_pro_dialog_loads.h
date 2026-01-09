

#define X_loads_AC_sel_c  762
#define Y_loads_AC_sel_c  149

#define X_loads_AC_sel_u  762
#define Y_loads_AC_sel_u  149

#define X_loads_fridge_sel_c  432
#define Y_loads_fridge_sel_c  149

#define X_loads_fridge_sel_u  432
#define Y_loads_fridge_sel_u  149

#define X_loads_KV_sel_c  598
#define Y_loads_KV_sel_c  149

#define X_loads_KV_sel_u  598
#define Y_loads_KV_sel_u  149

#define X_loads_load_sel_c  267
#define Y_loads_load_sel_c  149

#define X_loads_load_sel_u  267
#define Y_loads_load_sel_u  149

#define X_loads_MW_sel_c  267
#define Y_loads_MW_sel_c  284

#define X_loads_MW_sel_u  267
#define Y_loads_MW_sel_u  284

#define X_loads_TV_sel_c  432
#define Y_loads_TV_sel_c  284

#define X_loads_TV_sel_u  432
#define Y_loads_TV_sel_u  284

#define X_loads_ventilator_sel_c  267
#define Y_loads_ventilator_sel_c  149

#define X_loads_ventilator_sel_u  267
#define Y_loads_ventilator_sel_u  149

#define X_loads_WM_sel_c  598
#define Y_loads_WM_sel_c  284

#define X_loads_WM_sel_u  598
#define Y_loads_WM_sel_u  284

#define X_loads_wp_sel_c  762
#define Y_loads_wp_sel_c  284

#define X_loads_wp_sel_u  762
#define Y_loads_wp_sel_u  284


extern lcd_dis_item_t dialog_loads_item[DIALOG_LOADS_ICO_NUM];
extern u8 now_dialog_loads_icon_select_ch;
extern bool f_ui_disply_dialog_loads;
extern void ui_disply_dialog_loads(void);
extern BOOL page_dialog_loads_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_dialog_loads_init(void);
extern void ui_out_dialog_loads(void);
