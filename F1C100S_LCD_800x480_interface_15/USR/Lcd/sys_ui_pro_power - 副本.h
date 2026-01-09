#define X_indicatorlamp_d  206
#define Y_indicatorlamp_d  255

#define X_indicatorlamp_u  206
#define Y_indicatorlamp_u  255

#define X_power_ac_bg  140
#define Y_power_ac_bg  68

#define X_power_battery_bg  140
#define Y_power_battery_bg  366

#define X_power_battery_ico  165
#define Y_power_battery_ico  401

#define X_power_bc_bg  581
#define Y_power_bc_bg  366

#define X_power_b_alarm_d  388
#define Y_power_b_alarm_d  514

#define X_power_b_alarm_u  388
#define Y_power_b_alarm_u  514

#define X_power_b_btn2  265
#define Y_power_b_btn2  514

#define X_power_b_btn3  389
#define Y_power_b_btn3  514

#define X_power_b_btn4  512
#define Y_power_b_btn4  514

#define X_power_b_btn5  635
#define Y_power_b_btn5  514

#define X_power_b_btn6  758
#define Y_power_b_btn6  514

#define X_power_b_chart_d  512
#define Y_power_b_chart_d  514

#define X_power_b_chart_u  512
#define Y_power_b_chart_u  514

#define X_power_b_power_d  140
#define Y_power_b_power_d  514

#define X_power_b_power_u  140
#define Y_power_b_power_u  514

#define X_power_b_setup_d  881
#define Y_power_b_setup_d  514

#define X_power_b_setup_u  881
#define Y_power_b_setup_u  514


#define X_power_b_system_d  265
#define Y_power_b_system_d  514

#define X_power_b_system_u  265
#define Y_power_b_system_u  514

#define X_power_cc_bg  581
#define Y_power_cc_bg  68

#define X_power_inverterOFF_d  308
#define Y_power_inverterOFF_d  278

#define X_power_inverterOFF_u  308
#define Y_power_inverterOFF_u   278

#define X_power_inverterON_d  308
#define Y_power_inverterON_d   278

#define X_power_inverterON_u  308
#define Y_power_inverterON_u   278

#define X_power_sc_bg  581
#define Y_power_sc_bg  217


#define X_power_battery_offset 8
#define Y_power_battery_offset 14

#define X_power_battery_0  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_0  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_1  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_1  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_2  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_2  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_3  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_3  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_4  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_4  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_5  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_5  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_changer_0  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_changer_0  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_changer_1  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_changer_1  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_changer_2  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_changer_2  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_changer_3  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_changer_3  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_changer_4  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_changer_4  Y_power_battery_ico+Y_power_battery_offset

#define X_power_battery_changer_5  X_power_battery_ico+X_power_battery_offset
#define Y_power_battery_changer_5  Y_power_battery_ico+Y_power_battery_offset

extern BOOL page_power_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_power_init(void);
extern void disply_solar_val(bool upgrade);
extern void disply_AC_in_out_val(bool upgrade);
extern void disply_combi_CHG_val(bool upgrade);
extern void disply_booster_val(bool upgrade);
