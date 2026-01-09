#include "ui_def.h"
#include "ui_data.h"

#define X_bottombtn_ac_d  391
#define Y_bottombtn_ac_d  490

#define X_bottombtn_ac_u  391
#define Y_bottombtn_ac_u  490

#define X_bottombtn_auto_d  139
#define Y_bottombtn_auto_d  490

#define X_bottombtn_auto_u  139
#define Y_bottombtn_auto_u  490

#define X_bottombtn_frontwindow_d  645
#define Y_bottombtn_frontwindow_d  490

#define X_bottombtn_frontwindow_u  645
#define Y_bottombtn_frontwindow_u  490

#define X_bottombtn_innerloop_d  898
#define Y_bottombtn_innerloop_d  490

#define X_bottombtn_innerloop_u  898
#define Y_bottombtn_innerloop_u  490

#define X_bottombtn_maxac_d  518
#define Y_bottombtn_maxac_d  490

#define X_bottombtn_maxac_u  518
#define Y_bottombtn_maxac_u  490

#define X_bottombtn_outerloop_d  898
#define Y_bottombtn_outerloop_d  490

#define X_bottombtn_outerloop_u  898
#define Y_bottombtn_outerloop_u  490

#define X_bottombtn_rearwindow_d  772
#define Y_bottombtn_rearwindow_d  490

#define X_bottombtn_rearwindow_u  772
#define Y_bottombtn_rearwindow_u  490

#define X_bottombtn_sync_d  265
#define Y_bottombtn_sync_d  490

#define X_bottombtn_sync_u  265
#define Y_bottombtn_sync_u  490

#define X_climatebtn_body_d  432
#define Y_climatebtn_body_d  191

#define X_climatebtn_body_u  432
#define Y_climatebtn_body_u  191

#define X_climatebtn_down_d  172//859
#define Y_climatebtn_down_d  294

#define X_climatebtn_down_u  172//859
#define Y_climatebtn_down_u  294

#define X_climatebtn_feet_d  432
#define Y_climatebtn_feet_d  285

#define X_climatebtn_feet_u  432
#define Y_climatebtn_feet_u  285

#define X_climatebtn_head_d  432
#define Y_climatebtn_head_d  98

#define X_climatebtn_head_u  432
#define Y_climatebtn_head_u  98

#define X_climatebtn_off_d  172
#define Y_climatebtn_off_d  393

#define X_climatebtn_off_u  172
#define Y_climatebtn_off_u 393

#define X_climatebtn_rearclimate_d  859
#define Y_climatebtn_rearclimate_d  393

#define X_climatebtn_rearclimate_u  859
#define Y_climatebtn_rearclimate_u  393

#define X_climatebtn_up_d  172//859
#define Y_climatebtn_up_d  98

#define X_climatebtn_up_u  172//859
#define Y_climatebtn_up_u  98

#define X_climate_fan_big  742
#define Y_climate_fan_big  393

#define X_climate_fan_small  348
#define Y_climate_fan_small  393

#define X_climate_fan_big_d  742
#define Y_climate_fan_big_d  393

#define X_climate_fan_small_d  348
#define Y_climate_fan_small_d  393

#define X_climate_fan_0  429
#define Y_climate_fan_0  431

#define X_climate_fan_1  429
#define Y_climate_fan_1  431

#define X_climate_fan_2  429
#define Y_climate_fan_2  431

#define X_climate_fan_3  429
#define Y_climate_fan_3  431

#define X_climate_fan_4  429
#define Y_climate_fan_4  431

#define X_climate_fan_5  429
#define Y_climate_fan_5  431

#define X_climate_fan_6  429
#define Y_climate_fan_6  431

#define X_climate_fan_7  429
#define Y_climate_fan_7  431

#define X_climate_fan_rear  879+10
#define Y_climate_fan_rear  519

#define X_climate_scrollbar_box  429
#define Y_climate_scrollbar_box  431

#define X_climate_scrollbar_slider  429
#define Y_climate_scrollbar_slider  431

#define X_climate_scrollbar_value  429
#define Y_climate_scrollbar_value  431
/////////////////////////////////////////
#define X_climatebtn_right_up_d  859
#define Y_climatebtn_right_up_d  98

#define X_climatebtn_right_up_u  859
#define Y_climatebtn_right_up_u  98


#define X_climatebtn_right_down_d  859
#define Y_climatebtn_right_down_d  294

#define X_climatebtn_right_down_u  859
#define Y_climatebtn_right_down_u  294


#define X_climatebtn_left_val  172+15
#define Y_climatebtn_left_val  208+10

#define X_climatebtn_right_val  859+15
#define Y_climatebtn_right_val  208+10

#define X_climatebtn_rear_val  199+25
#define Y_climatebtn_rear_val  524
////////////////////////////////////
#define X_rearctrl_lock_d  576
#define Y_rearctrl_lock_d  490

#define X_rearctrl_lock_u  576
#define Y_rearctrl_lock_u  490

#define X_rearctrl_minusB_d  139
#define Y_rearctrl_minusB_d  490

#define X_rearctrl_minusB_u  139
#define Y_rearctrl_minusB_u  490

#define X_rearctrl_minus_d  732
#define Y_rearctrl_minus_d  490

#define X_rearctrl_minus_u  732
#define Y_rearctrl_minus_u  490

#define X_rearctrl_plusR_d  357
#define Y_rearctrl_plusR_d  490

#define X_rearctrl_plusR_u  357
#define Y_rearctrl_plusR_u  490

#define X_rearctrl_plus_d  964
#define Y_rearctrl_plus_d  490

#define X_rearctrl_plus_u  964
#define Y_rearctrl_plus_u  490

#define X_rearctrl_power_d  419
#define Y_rearctrl_power_d  490

#define X_rearctrl_power_u  419
#define Y_rearctrl_power_u  490

#define X_rearctrl_windowbg1  199
#define Y_rearctrl_windowbg1  490

#define X_rearctrl_windowbg2  794
#define Y_rearctrl_windowbg2  490



typedef enum
{  
	AC_PAGE_NOR = 0,
	AC_PAGE_REAR = 1,
}AC_PAGE;
extern AC_PAGE ac_ui_step;
extern AC_PAGE last_ac_ui_step;
extern u16 tempt_l;//22.5
extern u16 tempt_r;
extern u16 tempt_b;
extern u8 fan;
extern u8 fan_b;

//空调界面按键列表 按下
extern lcd_dis_item_t *p_climate_item_d[AC_ICO_NUM];
//空调界面按键列表 弹起
extern lcd_dis_item_t *p_climate_item_u[AC_ICO_NUM];
extern void tempt_display(void);
extern void fan_display(void);
extern BOOL page_ac_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_AC_init(void);
