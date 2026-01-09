void ui_RGB_init(void)   ;
//==============================================================
// 结构体名称：RGBSystem
// 功能：表示一个多灯RGB灯组系统，用于管理每个灯的亮度与模式状态
// 说明：通过 RGB_select 选择当前操作的灯（0 → RGB1, 1 → RGB2）
//==============================================================
typedef struct
{
    // ----------------------------------------------------------
    // 每个灯的独立参数
    // ----------------------------------------------------------
    struct
    {
        u8 brightness;     // 亮度百分比（0~100）
        bool isPowerOn;    // 开关状态（true：开，false：关）

        // 特效状态标志
        bool FLASH_Flag;   // 闪烁模式标志
        bool SMOOT_Flag;  // 平滑渐变模式标志
        bool FADE_Flag;    // 渐隐模式标志
        bool STROBE_Flag;  // 频闪模式标志
        u8 r;
        u8 g;
        u8 b;
        bool change;  
    } RGB[2];  // 系统包含2个RGB灯

    bool RGB_select;       // 当前选择灯编号（0：RGB1，1：RGB2）
} RGBSystem;




void disply_RGB_val(bool upgrade);
void HandleColorTouch(void);
#define PAGE_RGB_NUM  13

#define RGB_MODE_SN  3
#define RGB_POWER_SN  8
#define RGB_SEL_SN  11

void disply_pwm_RGB_status(u8 type,bool upgrage);//显示,type:通道
void FlC200_hc_comm_RGB_SW(u8* para); //打印同步数据 para[0]: ID, para[1]: LEN, para[2]: DATA 0


