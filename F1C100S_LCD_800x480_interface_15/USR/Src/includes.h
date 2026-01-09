
//sys
#include "stdio.h"
#include "sys_types.h"
#include "sys_uart.h"
#include "sys_clock.h"
#include "sys_dram.h"
//#include "sys_gpio.h"
#include "sys_delay.h"
#include "sys_lcd.h"
#include "sys_cache.h"
#include "sys_interrupt.h"
#include "sys_timer.h"
#include "sys_I2C.h"

//c lab
#include <string.h>
#include <stdio.h>
#include <sys_mmu.h>
#include "stdlib.h"

//user
#include "main.h"
#include "fifo.h"
#include "font.h"
#include "sys_IO_I2C.h"
#include "GT911.h"
#include "ToMCU.h"

#include "myFont.h"
#include "ui_def.h"
#include "ui_data.h"
#include "sys_LCD_gui_argb32.h"
#include "sys_virtual_gui_argb32.h"
#include "sys_ui_pro_home.h"
#include "sys_ui_pro_auxilary_keyboard.h"
#include "sys_ui_pro.h"
#include "sys_ui_pro_system.h"
#include "sys_ui_pro_power.h"
#include "sys_ui_pro_power_system.h"
#include "sys_ui_pro_lights.h"
#include "sys_ui_pro_loads.h"
#include "sys_ui_pro_tanks.h"
#include "sys_ui_pro_tanks_set.h"
#include "sys_ui_pro_system_alarm.h"
#include "sys_ui_pro_system_accessories.h"
#include "sys_ui_pro_system_info.h"
#include "sys_ui_pro_keyboard.h"
#include "sys_ui_pro_dialog_lights.h"
#include "sys_ui_pro_dialog_loads.h"
#include "sys_ui_pro_dialog_lights_ch.h"
#include "sys_ui_pro_dialog_loads_ch.h"
#include "sys_ui_pro_dialog_code.h"
#include "sys_ui_pro_dialog_msg.h"
#include "sys_ui_pro_dialog_info.h"
#include "sys_ui_pro_loads_motors.h"
#include "sys_ui_pro_dialog_motors.h"
#include "sys_ui_pro_dialog_test.h"
#include "ctrl_status.h"
#include "sys_ui_pro_power_set.h"
#include "sys_ui_pro_power_alarm.h"

#include "sys_ui_pro_column_home_5.h"
#include "sys_ui_pro_column_power_5.h"
#include "sys_ui_pro_column_tank_5.h"
#include "sys_ui_pro_column_alarm_5.h"
#include "sys_ui_pro_column_setup_5.h"
#include "Test_png.h"

#include "sys_ui_elevator.h"
#include "sys_ui_light.h"
#include "sys_ui_rgb.h"
#include "sys_ui_ac.h"
#include "sys_ui_setup.h"
#include "sys_ui_diese_heater.h"





extern void ResetDelayTime(u32 *time);
extern void SetDelayTime(u32 *time,u32 t);
extern u8 CntDelayTime(u32 *time,u32 t);
