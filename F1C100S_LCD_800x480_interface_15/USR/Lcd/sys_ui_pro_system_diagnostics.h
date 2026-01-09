
#define X_diagnostics_clear_d  760
#define Y_diagnostics_clear_d  444

#define X_diagnostics_clear_u  760
#define Y_diagnostics_clear_u  444

#define X_diagnostics_gray  0
#define Y_diagnostics_gray  0

#define X_diagnostics_green  0
#define Y_diagnostics_green  0

#define X_diagnostics_network_bg  143
#define Y_diagnostics_network_bg  74

#define X_diagnostics_output_bg  526
#define Y_diagnostics_output_bg  74

#define X_diagnostics_red  0
#define Y_diagnostics_red  0

#define X_diagnostics_idle  0
#define Y_diagnostics_idle  0

#define X_diagnostics_yellow  0
#define Y_diagnostics_yellow  0

#define X_diagnostics_sensor_bg  760
#define Y_diagnostics_sensor_bg  74

#define X_diagnostics_start_d  526
#define Y_diagnostics_start_d  444

#define X_diagnostics_start_u  526
#define Y_diagnostics_start_u  444

#define X_system_b_diagnostics_d  635
#define Y_system_b_diagnostics_d  514

#define X_system_b_diagnostics_u  635
#define Y_system_b_diagnostics_u  514



extern bool f_diagnostics_on;

extern BOOL page_system_diagnostics_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_system_diagnostics_init(void);


extern void display_diagnostics_info(bool upgrade);
extern void diagnostics_pro(void);
