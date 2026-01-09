


//SPI_FLASH HK25Q64 Ultra Low Power, 64M-bit Serial Multi I/O Flash Memory Datasheet
//F1C100 32MB DDR1  F1C200 64MB DDR1

#define VERSION_STR "UI: CS05_UI_V1.00.017 2025-12-16"  //UI版本
//V1.00.017 2025-12-13 增加日期设置，删除蓝牙名称项
//V1.00.015 2025-12-9 增加两条柴暖警告，RGB控制逻辑优化
//V1.00.013 2025-12-4 修改触控框架，单点触控
//V1.00.012 2025-12-3 修正柴暖同步逻辑，增加手刹检测 mcu： CS05_UI_V1.00.007 2025-12-1
//V1.00.011 2025-12-2 完善灯管光全开全全关逻辑，更换设置页升级背景图片
//V1.00.008 2025-04-25 更换Y轴触摸 适配最新硬件-航触触摸
//V1.00.008 2025-04-24 完善UI显示
//V1.00.006 2025-03-14 完善power页面详情页，添加test页面
//V1.01.003 2024-06-19 修改容量的输入范围和UI更新问题
//V1.01.002 2024-06-18 修改测试中出现的问题
//V1.01.001 2024-06-12 增加兼容B型房车多路控制盒.
//V1.00.029 2024-05-17 lights和loads编辑逻辑 增加水泵和加热按键.
//V1.00.028 2024-05-06 修改UI窜页面，逆变器按键无效时灰掉
//V1.00.027 2024-04-30 大量ui优化及布局调整  
//V1.00.026 2024-04-08 修改部分UI遗留问题
//V1.00.025 2024-03-08 增加温度符号小圆圈，公开检测电流显示，并调整位置颜色,增加打印通道示(第一个名字写入“95279527激活”)
//V1.00.024 2024-01-08 修改water pump off和loads Off的状态返回
//V1.00.023 2023-12-28 修改water pump off和loads Off功能 增加扩展IO自锁轻触选择 显示扩展盒的版本
//V1.00.022 2023-12-08 修改部分显示问题，增加检测电流显示(第一个名字写入“95279527激活”)
//V1.00.021 2023-11-15 修改部分显示问题，增加控制盒版本显示
//V1.00.020 2023-10-18 修改部分与APP显示相关问题 MPPT_RVC显示 24-12小时选择
//V1.00.019 2023-09-14 增加库仑计设置项
//V1.00.018 2023-08-22 修改版本号？












//配置LCD




//#define LCD_SIZE_10CH_TOUCH
//#define LCD_TYPE_RGB43_480_272 
#define LCD_TYPE_RGB_1024_600 
//#define LCD_TYPE_Vga_1024_768 
//#define LCD_TYPE_Vga_640_480_60HZ
//#define  LCD_TYPE_Vga_640_480_75HZ
//#define  LCD_TYPE_TV_PAL_720_576
//#define LDC_TYPE_Vga_480_480
//-------------------------------------------
#ifdef	LCD_TYPE_TV_PAL_720_576
	#define XSIZE_PHYS (unsigned int)720 
	#define YSIZE_PHYS (unsigned int)576
#endif

//-------------------------------------------
#ifdef	LCD_TYPE_RGB43_480_272
	#define XSIZE_PHYS (unsigned int)480  
	#define YSIZE_PHYS (unsigned int)272 
#endif	
	
#ifdef	LCD_TYPE_RGB_1024_600
	#define XSIZE_PHYS (unsigned int)800 
	#define YSIZE_PHYS (unsigned int)480
#endif	
//-------------------------------------------
#ifdef LCD_TYPE_Vga_1024_768
	#define XSIZE_PHYS (unsigned int)480  
	#define YSIZE_PHYS (unsigned int)480 
#endif
//-------------------------------------------	
#ifdef LCD_TYPE_Vga_640_480_75HZ
	#define XSIZE_PHYS (unsigned int)640  
	#define YSIZE_PHYS (unsigned int)480
#endif
//-------------------------------------------
#ifdef LCD_TYPE_Vga_640_480_60HZ
	#define XSIZE_PHYS (unsigned int)640  
	#define YSIZE_PHYS (unsigned int)480
#endif
//-------------------------------------------
#ifdef LDC_TYPE_Vga_480_480
	#define XSIZE_PHYS (unsigned int)480  
  #define YSIZE_PHYS (unsigned int)480
#endif
	
//#define ARGB_black	0xFF000000
//#define ARGB_darkGray	0xFF555555
//#define ARGB_lightGray	0xFFAAAAAA
//#define ARGB_white	0xFFFFFFFF
//#define ARGB_gray	0xFF7F7F7F
//#define ARGB_red	0xFFFF0000
//#define ARGB_green	0xFF00FF00
//#define ARGB_blue	0xFF0000FF
//#define ARGB_cyan	0xFF00FFFF
//#define ARGB_yellow	0xFFFFFF00
//#define ARGB_magenta	0xFFFF00FF
//#define ARGB_orange	0xFFFF7F00
//#define ARGB_purple	0xFF7F007F
//#define ARGB_brown	0xFF996633
//#define ARGB_clear	0x00000000
//	#FC532E
#define ARGB_black        0xFF000000
#define ARGB_darkGray     0xFF555555  // 深灰
#define ARGB_lightGray    0xFFAAAAAA  // 浅灰
#define ARGB_white        0xFFFFFFFF
#define ARGB_gray         0xFF7F7F7F  // 中灰
#define ARGB_red          0xFFFF0000
#define ARGB_green        0xFF00FF00
#define ARGB_blue         0xFF0000FF
#define ARGB_cyan         0xFF00FFFF  // 青蓝（绿+蓝）
#define ARGB_yellow       0xFFFFFF00  // 黄（红+绿）
#define ARGB_magenta      0xFFFF00FF  // 品红（红+蓝）
#define ARGB_orange       0xFFFF7F00  // 橙（红+浅黄）
#define ARGB_purple       0xFF7F007F  // 紫（深红+深蓝）
#define ARGB_brown        0xFF996633  // 棕（红+黄+灰）
#define ARGB_clear        0x00000000  // 全透明


/////////////////////////////////////
#define ARGB_mygreen 0xFF52FF77
#define ARGB_myorange 0xFFecc15b
#define ARGB_mygray 0xFF464655
#define ARGB_mydarkcyan 0xFF06e1db
#define ARGB_myblue  0xFF1170B2

#define TIME_ONE_MS         1
#define TIME_ONE_S          (TIME_ONE_MS*1000)
#define TIME_ONE_MIN          (TIME_ONE_S*60)	
	

extern __align(4) unsigned int Virtual_LCDbuff0[XSIZE_PHYS*YSIZE_PHYS];  
extern __align(4) unsigned int Virtual_LCDbuff1[XSIZE_PHYS*YSIZE_PHYS];  
extern __align(4) unsigned int Virtual_LCDbuff2[XSIZE_PHYS*YSIZE_PHYS];
extern __align(4) unsigned int Virtual_LCDbuff3[XSIZE_PHYS*YSIZE_PHYS];  //???

