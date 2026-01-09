#include "ui_def.h"
#include "ui_data.h"

#define Y_tank_wave_offest_5 8

#define X_tank_balck_val_5  425
#define Y_tank_balck_val_5  67

#define X_tank_black_bg_5  421
#define Y_tank_black_bg_5  53

#define X_tank_fresh_bg_5  45
#define Y_tank_fresh_bg_5  53

#define X_tank_fresh_val_5  49
#define Y_tank_fresh_val_5  67

#define X_tank_gray_bg_5  233
#define Y_tank_gray_bg_5  53

#define X_tank_gray_val_5  237
#define Y_tank_gray_val_5  67

#define X_tank_lpg_bg_5  611
#define Y_tank_lpg_bg_5  53

#define X_tank_lpg_val_5  615
#define Y_tank_lpg_val_5  67

#define X_tank_water_heater_down_5  57
#define Y_tank_water_heater_down_5  329

#define X_tank_water_heater_up_5  X_tank_water_heater_down_5
#define Y_tank_water_heater_up_5  Y_tank_water_heater_down_5

#define X_tank_water_pump_down_5  431
#define Y_tank_water_pump_down_5  329

#define X_tank_water_pump_up_5  X_tank_water_pump_down_5
#define Y_tank_water_pump_up_5  Y_tank_water_pump_down_5

#define X_tank_black_wave_5  425
#define Y_tank_black_wave_5  67-Y_tank_wave_offest_5

#define X_tank_fresh_wave_5  49
#define Y_tank_fresh_wave_5  67-Y_tank_wave_offest_5

#define X_tank_gray_wave_5  237
#define Y_tank_gray_wave_5  67-Y_tank_wave_offest_5

#define X_tank_lpg_wave_5  615
#define Y_tank_lpg_wave_5  67-Y_tank_wave_offest_5

#define X_tank_column_1_5		40
#define Y_tank_column_1_5		75

#define X_tank_column_2_5		X_tank_column_1_5
#define Y_tank_column_2_5   Y_tank_column_1_5+50

#define X_tank_column_3_5		X_tank_column_1_5
#define Y_tank_column_3_5   Y_tank_column_1_5+100

#define X_tank_column_4_5		X_tank_column_1_5
#define Y_tank_column_4_5   Y_tank_column_1_5+150

#define X_tank_column_5_5		X_tank_column_1_5
#define Y_tank_column_5_5   Y_tank_column_1_5+200

#define X_tank_column_6_5		X_tank_column_1_5
#define Y_tank_column_6_5   Y_tank_column_1_5+250

#define X_tank_column_7_5		X_tank_column_1_5
#define Y_tank_column_7_5   Y_tank_column_1_5+300

#define X_tank_column_right_add_1_5		692
#define Y_tank_column_right_add_1_5		88
         
#define X_tank_column_left_sub_1_5		547
#define Y_tank_column_left_sub_1_5		88

#define X_tank_column_return_1_5		45
#define Y_tank_column_return_1_5		44

extern void ui_column_tank_init_5(void);
extern void disply_column_tanks_state(u8 tank_type,bool upgrade);
extern void ui_column_tank_subpage_1_display(bool upgrade);
