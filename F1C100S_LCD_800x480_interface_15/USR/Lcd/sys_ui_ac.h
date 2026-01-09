void ui_ac_init(void)   ;
void page5_displlay_val(void);


typedef struct
{
    u8 SetTemp;  //
    u8 nowTemp;
    u8 mode;//0无选中，1cool，2heat
    u8 Fan;//0:low,1:MED,2:Hiight
    
        bool isPowerOn; // 开关状态（true：开，false：关）

} ACSystem;

#define Cool_Mode 1
#define Heat_Mode 2

#define AC_ISPOWER_SN  2//电源

#define AC_MODE_SN  5//COOL 模式起始索引
#define AC_FAN_MODE_SN  7//风扇模式起始索引


#define AC_KEY_SN  2//电源开关起始索引

void disply_AC_val(bool upgrade);
void Fan_b(void);

void Fan_r(void);


typedef enum {
  MODE_OFF = 1,
  MODE_COOL,
  MODE_HEAT_FURNACE,//
  MODE_HEAT_PUMP,//制
  MODE_AIR, //送风模块
  MODE_DRY, //抽湿模式
  MODE_AUTO,
}ModeSwitch;

typedef enum {
  OFF,
  COOL,
  HEAT_FURNACE,//制
}Mode;

typedef struct 
{
  u16 Now_temp;           // 当前温度
  u8 Cool_set_temp;       // 用户设定制冷温度
  u8 Furnace_set_temp;    // 用户设定制暧温度
  u8 Auto_set_temp;       // 用户设定AUTO温度
  u16 Now_temp_f;           // 当前温度
  u8 Cool_set_temp_f;       // 用户设定制冷温度
  u8 Furnace_set_temp_f;    // 用户设定制暧温度
  u8 Auto_set_temp_f;      // 用户设定AUTO温度
  ModeSwitch sw_mode;     // 模式开关：冷 / 热 / 关闭
    u8 fan_speed;           // Bit7-4:开关模式0x00：OFF  0x01：AUTO  0x02：ON  Bit3-0:风速  0x01：HIGH  0x02: MID  0x03：LOW
    u8 fan_speed_heat;
}P6_HVAC_CTRL_STATUS;

//HVAC_CTRL_STATUS Hvac_ctrl_statu;
void FlC200_hc_comm_AC_SW(u8* para); //获取同步数据 para[0]: ID, para[1]: LEN, para[2]: DATA 0
void FlC200_hc_comm_Hvac_pro(u8* para);//获取同步输数据
