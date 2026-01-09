#include "sys_types.h"

#include "ui_def.h"
#include "ui_data.h"

#define PAGE_INIT  0
#define PAGE_INFO  1
#define PAGE_LEFT_SIDE  2
#define PAGE_LEFT_SIDE_UPDATA 3
#define PAGE_TOP_SIDE  4
#define PAGE_TOP_SIDE_UPDATA  5
#define PAGE_MAIN_ITEM  6
#define PAGE_MAIN_ITEM_DISALL 7
#define PAGE_5  8

#define TEST_PAGE_LEFT_SIDE  1
#define TEST_PAGE_INFO 2
#define TEST_PAGE_LEFT_SIDE_UPDATA 3
#define TEST_PAGE_TOP_SIDE  4
#define TEST_PAGE_TOP_SIDE_UPDATA  5
#define TEST_PAGE_MAIN_ITEM_DISALL 6

#define SELECT_1  1
#define SELECT_2  2
#define SELECT_3  3
#define SELECT_4  4
#define SELECT_5  5




#define MAIN_AREA_X  120
#define MAIN_AREA_Y  5
#define MAIN_AREA_X_END  800
#define MAIN_AREA_Y_END  420


extern u16 slide_x;
extern u16 slide_y;
extern u16 X_touch_now;
extern u16 Y_touch_now;
extern bool f_force_to_target_top_page;
extern void page_printf_info(char c,bool Upgrape);
extern void fill_DisplayBuf(char* buf);
extern void page_printf_DisplayBuf(bool Upgrape);
extern void page_init(void);
extern void page_dis_pro(void);
extern void page_dis_test_pro(void);
extern void page_touch_pro(u16 x,u16 y);
extern void out_from_long_touch_status(void);


