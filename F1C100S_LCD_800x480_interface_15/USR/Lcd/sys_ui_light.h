
// 灯光系统（包含6个灯，每个灯直接包含亮度和开关状态）
typedef struct
{
    struct
    {
        u8 brightness;  // 亮度百分比（0-100）
        bool isPowerOn; // 开关状态（true：开，false：关）
    } lights[6];  // 6个灯，下标0-5对应具体的灯序号
} LightSystem;



void ui_light_init(void)   ;
void disply_ligght_val(bool upgrade);
void disply_ligght_val2(bool upgrade);
void disply_page1_light_pwm_status(u8 type,bool upgrage);//显示,type:通道
void FlC200_hc_comm_light_SW(u8* para);//同步灯状态
void Light_Status_synchronization_SW(bool upgrade);//同步状态
//void disply_Light_Status_synchronization_pwm_status(bool upgrage);//状态同步显示滑动条（未完）
void disply_Light_Status_synchronization_pwm_status(u8 type,bool upgrage);//显示,type:通道
#define P1_Light_PWM_CTRL_CH  6
#define Page1_LIGHT_PWM0 0
#define Page1_LIGHT_PWM1 1
#define Page1_LIGHT_PWM2 2
#define Page1_LIGHT_PWM3 3
#define Page1_LIGHT_PWM4 4
#define Page1_LIGHT_PWM5 5

#define P1_PWM_CTRL_MIN_VAL 5//最小亮度
#define P1_Light_PWM_CTRL_MAX_VAL 100

#define Light_Pic_SN 6 //灯序号