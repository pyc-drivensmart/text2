
#define X_system_btn1_d  140
#define Y_system_btn1_d  142

#define X_system_btn1_u  140
#define Y_system_btn1_u  142

#define X_system_btn2_d  140
#define Y_system_btn2_d  233

#define X_system_btn2_u  140
#define Y_system_btn2_u  233

#define X_system_btn3_d  140
#define Y_system_btn3_d  324

#define X_system_btn3_u  140
#define Y_system_btn3_u  324

#define X_system_btn4_d  140
#define Y_system_btn4_d  415

#define X_system_btn4_u  140
#define Y_system_btn4_u  415


#define X_system_b_alarm_d  388
#define Y_system_b_alarm_d  514

#define X_system_b_alarm_u  388
#define Y_system_b_alarm_u  514


#define X_system_b_acc_d  512
#define Y_system_b_acc_d  514

#define X_system_b_acc_u  512
#define Y_system_b_acc_u  514

#define X_system_b_info_d  265
#define Y_system_b_info_d  514

#define X_system_b_info_u  265
#define Y_system_b_info_u  514




#define X_test_1_d  265
#define Y_test_1_d  514

#define X_test_1_u  265
#define Y_test_1_u  514

#define X_test_2_d  388
#define Y_test_2_d  514

#define X_test_2_u  388
#define Y_test_2_u  514

#define X_test_3_d  511
#define Y_test_3_d  514

#define X_test_3_u  511
#define Y_test_3_u  514

#define X_test_4_d  635
#define Y_test_4_d  514

#define X_test_4_u  635
#define Y_test_4_u  514

#define X_test_5_d  758
#define Y_test_5_d  514

#define X_test_5_u  758
#define Y_test_5_u  514

#define X_system_b_system_d  140
#define Y_system_b_system_d  514

#define X_system_b_system_u  140
#define Y_system_b_system_u  514

#define X_system_headline  142
#define Y_system_headline  128

#define X_system_nextpage_d  887
#define Y_system_nextpage_d  415

#define X_system_nextpage_o  887
#define Y_system_nextpage_o  415

#define X_system_nextpage_u  887
#define Y_system_nextpage_u  415

#define X_system_prepage_d  887
#define Y_system_prepage_d  142

#define X_system_prepage_o  887
#define Y_system_prepage_o  142

#define X_system_prepage_u  887
#define Y_system_prepage_u  142




#define X_set_down_d  630
#define Y_set_down_d  158

#define X_set_down_u  X_set_down_d
#define Y_set_down_u  Y_set_down_d



#define X_set_up_d  795
#define Y_set_up_d  158

#define X_set_up_u  X_set_up_d
#define Y_set_up_u  Y_set_up_d

#define X_set_left_d 630
#define Y_set_left_d 158

#define X_set_left_u  X_set_left_d
#define Y_set_left_u  Y_set_left_d

#define X_set_right_d  797//图片有偏移
#define Y_set_right_d  158

#define X_set_right_u  X_set_right_d
#define Y_set_right_u  Y_set_right_d


#define X_set_left1_d 630
#define Y_set_left1_d 158

#define X_set_left1_u  X_set_left_d
#define Y_set_left1_u  Y_set_left_d

#define X_set_right1_d  795
#define Y_set_right1_d  158

#define X_set_right1_u  X_set_right_d
#define Y_set_right1_u  Y_set_right_d


#define X_set_left2_d 630
#define Y_set_left2_d 248

#define X_set_left2_u  X_set_left2_d
#define Y_set_left2_u  Y_set_left2_d

#define X_set_right2_d  797//图片有偏移
#define Y_set_right2_d  248

#define X_set_right2_u  X_set_right2_d
#define Y_set_right2_u  Y_set_right2_d


#define X_set_left3_d 630
#define Y_set_left3_d 338

#define X_set_left3_u  X_set_left3_d
#define Y_set_left3_u  Y_set_left3_d

#define X_set_right3_d  795
#define Y_set_right3_d  338

#define X_set_right3_u  X_set_right3_d
#define Y_set_right3_u  Y_set_right3_d


#define X_set_left4_d 630
#define Y_set_left4_d 427

#define X_set_left4_u  X_set_left4_d
#define Y_set_left4_u  Y_set_left4_d

#define X_set_right4_d  795
#define Y_set_right4_d  427

#define X_set_right4_u  X_set_right4_d
#define Y_set_right4_u  Y_set_right4_d




#define X_system_b_back_d  881
#define Y_system_b_back_d  514



#define X_system_b_back_u  881
#define Y_system_b_back_u  514

#define X_system_b_btn2  265
#define Y_system_b_btn2  514

#define X_system_b_btn3  388
#define Y_system_b_btn3  514







typedef enum
{  
  TOUCH_TYPE_ENTER = 1,//正常  点一下进入下一级
	TOUCH_TYPE_NORMAL,      //正常  
	TOUCH_TYPE_LEFT_RIGHT,//显示左右选择按键 可以左右选择
	TOUCH_TYPE_UP_DOWN,   //显示上下选择按键 可以上下选择
	TOUCH_TYPE_SLIDE,     //显示滑动按键 可以滑动选择
	TOUCH_TYPE_KEYBOARD,  //进入键盘显示，输入值
	TOUCH_TYPE_NONE,      //显示没有触摸
	TOUCH_TYPE_NONE_DIS_DIM,      //显示没有触摸 浅色显示
	TOUCH_TYPE_SPECIAL,   //特殊情况处理 在程序外处理
	TOUCH_TYPE_UPGRADE,   //升级页面
	TOUCH_TYPE_BACKGROUND,
	TOUCH_TYPE_SAVE_AND_BACK,
    
    TOUCH_TYPE_Temperature,   //温度 
	END_OF_THE_LIST,   //结束
    
    TOUCH_TYPE_ENTER_Upgrade,//升级图标
}SETUP_MENU_TOUCH_TYPE;
#define SETUP_MENU_MAX_STR_LEN 36


typedef enum
{  
	V_1BIT,
 	V_8BIT,
	V_16BIT,
	V_32BIT,
}V_TYPE;


typedef enum
{  
	TO_INIT=0,
 	TO_UP,
	TO_DOWN,
	TO_DEAL,
	TO_DO_NOTHING,
}DEAl_TYPE;

typedef enum
{  
  MENU_DEEP_1TH=1,
	MENU_DEEP_2TH=2,
	MENU_DEEP_3TH=3,
	MENU_DEEP_4TH=4,
}MENU_DEEP;


#define SYSTEM_ITEM_1_OFFSET 0
#define SYSTEM_LEFT_1_OFFSET 6
#define SYSTEM_RIGHT_1_OFFSET 10
#define SYSTEM_BACK_OFFSET 14


#define PAGE_DISPLAY_ITEM_NUM 6

#define empty_father_p 0
#define empty_son_p 0
#define empty_fun 0

#define X_system_system_offset 52
#define Y_system_system_offset 18

#define X_set_mid_offset 593
typedef struct _setup_item_info_t
{	
	char display_str[SETUP_MENU_MAX_STR_LEN];//'\0'结束
	SETUP_MENU_TOUCH_TYPE setup_menu_touch_type;	  
	/*u32* setup_variable_p;//指向设置的变量
	V_TYPE variable_type;//变量是多少位的 
	u32  setup_variable_min_val;//最小值
	u32  setup_variable_max_val;//最大值*/
	void* father_p;//父数组
	void *son_p;//指向子数组
	//指向显示的数组变量
	void (*f)(void*,u8 sn,DEAl_TYPE deal_type);
	 
} setup_item_info_t;
extern setup_item_info_t System_Upgrade_page[];
extern setup_item_info_t System_Reset_5[];
extern setup_item_info_t Restore_Default_Settings_5[];
extern setup_item_info_t setup_setting[] ;
extern setup_item_info_t Data_Time[];
extern setup_item_info_t System_setting[];
extern setup_item_info_t Power_System_Setting[];
extern setup_item_info_t setup_setting[];
extern setup_item_info_t system_settings[];
extern setup_item_info_t Battery_info_select[];
extern setup_item_info_t Inverter_info_select[];
extern setup_item_info_t Mppt_info_select[];
extern setup_item_info_t DcDc_info_select[];
extern setup_item_info_t Batt_settings[];
extern setup_item_info_t Inv_settings[];
extern setup_item_info_t Power_setting[];
//home//
extern setup_item_info_t home_main_page[];
extern setup_item_info_t home_dcdc_page_info[];
extern setup_item_info_t home_solar_page_info[];
extern setup_item_info_t home_inv_page_info[];
extern setup_item_info_t home_batt_page_info[];
////power////
extern setup_item_info_t power_main_page[];
extern setup_item_info_t dcdc_page_info[];
extern setup_item_info_t solar_page_info[];
extern setup_item_info_t inv_page_info[];
extern setup_item_info_t batt_page_info[];

typedef struct _setup_page_info_t
{	
	setup_item_info_t item_info1;
	setup_item_info_t item_info2;
	setup_item_info_t item_info3;
	setup_item_info_t item_info4;	 
} setup_page_info_t;


typedef struct _setup_page_t
{	
	u8 now_page_deep;//0=首层，1=第2层 ，2=第3层
	u8 now_page_num;//这一层的多少页 4项1页
	u8 max_page_num;//这一层最多有多少页
	setup_item_info_t* now_p;//当前指向数组	
} setup_page_t;

extern setup_page_t home_page_sta;
extern setup_page_t power_page_sta;
extern setup_page_t setup_page_sta;
extern setup_page_t setup_page;
extern u8 last_now_page_num;
extern bool f_system_Date_Time_set;
extern bool f_system_accessories_External_Key_Type;



extern u8 Is_Leap_Year(u16 year);
extern void dispay_hour(void);
extern void time_touch_pro(u16 x_val,u16 y_val);
extern void func_Date_Time_Save_And_Back(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Date_Time(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Language(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Temperature_uint(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Volume_uint(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Brightness(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Sleep_Time(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Touch_Tone(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Upgrade(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Restore_Default_Settings(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_System_Reset(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_Code_Enter(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Warning_Tone(void* p,u8 sn,DEAl_TYPE deal_type);
extern void func_system_Light_Up_The_Screen(void* p,u8 sn,DEAl_TYPE deal_type);




extern void display_setup_page(bool upgrage_dispaly,bool upgrage,setup_page_t *setup_page_p,lcd_dis_item_t *setup_item_p,char* display_buf);


extern void display_set_info(bool upgrage);
extern BOOL page_system_deel_with_i(lcd_dis_page_t *p2,u8* i);
extern void ui_system_init(void);

extern bool f_display_set_info;
extern u16 now_page;//从高到低 --1级--2级--3级--4级
extern u8 now_page_deep;//当前处于哪一层
extern void time_touch_pro(u16 x_val,u16 y_val);
extern void disply_assi1_battery_val(bool upgrade);
