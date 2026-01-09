void ui_Dise_Heater_init(void)   ;


// 定义警告状态的位域结构
typedef struct {
    
//    bool FLAME_EXTINGUISHED;  // Bit0 火焰熄灭警告
//    bool BREAK_LINE_FAULT;  // Bit1 断路故障警告
    bool flameExtinguished;  // Bit0 火焰熄灭警告
    bool breaklineFault;  // Bit1 断路故障警告

    bool motorFault;  // Bit2 电机故障警告
    bool overHeating;  // Bit3 超温警告
    bool oilPumpFaul;  // Bit4 油泵故障警告
    bool ignitionPlugOut;  // Bit5 点火插头断开警告
    bool overVoltage;  // Bit6 超压警告
    bool underVoltage;  // Bit7 欠压警告
    
} WarningStatus;



typedef struct
{
    u8 icon_num;    // 加热挡位（0-10）
    bool isPowerOn; // 开关状态（true：开，false：关）
    bool manualOilPump;  // Bit5 手动泵油
    bool heatDissipation;  // Bit6 散热
    WarningStatus warn;//警告状态
} DiseHeaterSystem;
                    











void disply_DiseHeater_pic(bool upgrade);
void FlC200_hc_comm_diese_heater_SW(u8* para) ;//获取同步数据 ,同步互动条
