
#include "includes.h"

#define SHOW_MCU_MSG_DATA  //显示F1C发送到MCU

NEW_FIFO(McuUart2_TxFifo,256,u8,u16);
NEW_FIFO(McuUart2_RxFifo,256,u8,u16);
NEW_FIFO(McuUart0_TxFifo,256,u8,u16);
NEW_FIFO(McuUart0_RxFifo,1024,u8,u16);

#define uart4_RX_LEN 256 
#define uart4_TX_LEN 256
char MCU_VERSION_STR[40]="MCU: ";//RPK-RV-001 V1.xx.xxxBYPM
char BT_MAC_STR[12]={'0','0','0','0','0','0','0','0','0','0','0','0'};
char CONTROL_MCU_VERSION_STR[50]="Control Unit MCU: "; 
char CONTROL_SECOND_MCU_VERSION_STR[50]="Control Unit SlaveMCU: "; 
char External_key_MCU_VERSION_STR[50]="External_key MCU: "; 
char External_protocol_MCU_VERSION_STR[50]="External_protocol MCU: "; 

char Extra_device_mppt_ver[EXTRA_DEVICE_VER_LEN];
char Extra_device_Dc_Dc_ver[EXTRA_DEVICE_VER_LEN];
char Extra_device_inverter_ver[EXTRA_DEVICE_VER_LEN];
char Extra_device_battery_ver[EXTRA_DEVICE_VER_LEN];
char Extra_device_battery2_ver[EXTRA_DEVICE_VER_LEN];
char Extra_device_battery3_ver[EXTRA_DEVICE_VER_LEN];
u16 Control_Unit_product_id = 0x0000;

u32 uart4_Rx_all_cnt=0;
u32 uart4_Rx_crcerr_cnt=0;

typedef struct
{
   u8 data[uart4_RX_LEN];// 
   u16 read_p;//读指针
   u16 write_p;//写指针
   u16 over_cnt;
} UART4_FIFO_BUF;
UART4_FIFO_BUF uart4_fifo_tx_buf;
UART4_FIFO_BUF uart4_fifo_rx_buf;


//设置
BATTERY_SET_STATUS main_battery_set_status,assi1_battery_set_status,assi2_battery_set_status;
FRESH_SET_STATUS fresh_set_status;
BACK_SET_STATUS back_set_status;
GREY_SET_STATUS grey_set_status;
LPG_SET_STATUS LPG_set_status;
PARTS_SET_STATUS parts_set_status;
TIME_STATUS time_status;
SWITCH_NAME_LIST switch_name_list[SWITCH_NAME_CH_NUM]; //1-20
u32 External_key_type = 0;//2bit一个按键，从高2位表示ch1  0:表示触摸，1表示自锁，2，3未知
//返回
BATTERY_SET_STATUS main_battery_set_return_status,assi1_battery_set_return_status,assi2_battery_set_return_status;
FRESH_SET_STATUS fresh_set_return_status;
BACK_SET_STATUS back_set_return_status;
GREY_SET_STATUS grey_set_return_status;
LPG_SET_STATUS LPG_set_return_status;

TANK_SET_STATUS Tank1_set_return_status;
TANK_SET_STATUS Tank2_set_return_status;
TANK_SET_STATUS Tank3_set_return_status;
TANK_SET_STATUS Tank4_set_return_status;



PARTS_SET_STATUS parts_set_return_status;
TIME_STATUS time_return_status;
SWITCH_NAME_LIST switch_name_list_return[SWITCH_NAME_CH_NUM]; //1-20

u8 switch_ch_list_return[SWITCH_NAME_CH_NUM]; //switch1-switch_ch_select_num_max  switch 选择通道
u8 switch_ch_select_num_max = 12;

u32 External_key_type_return = 0;//2bit一个按键，从高2位表示ch1  0:表示触摸，1表示自锁，2，3未知

u16 code_connect = 0x8888; //??????
bool f_code_connect_done = FALSE;

typedef struct
{
   u8 uint;
   u8 language;
   u8 light;
   u8 R;
   u8 G;
   u8 B;
   u8 sleep_time;
	 u8 touch_tone;
}BASE__STATUS;
BASE_STATUS base_status;
BASE_STATUS base_return_status;

//??









//??
u8 switch_ctrl_byte[5]={0,0,0,0,0};//对应串口协议开关状态反馈信息 【0x60】
u8 pwm_ctrl_byte[PWM_CTRL_CH]={PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL};//??????1-4,
//bool f_load9_on = FALSE;//switch_ctrl_byte已经有
//bool f_load10_on = FALSE;//switch_ctrl_byte已经有
//bool f_black_heart_auto_on = FALSE;//switch_ctrl_byte已经有

u8 old_switch_ctrl_byte[5]={0,0,0,0,0};
u8 old_pwm_ctrl_byte[PWM_CTRL_CH]={PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL,PWM_CTRL_MAX_VAL};//??????1-100,
//bool old_f_load9_on = FALSE;
//bool old_f_load10_on = FALSE;
INVERTER_STATUS Inverter_status;
BATTERY_STATUS main_battery_status,assi1_battery_status,assi2_battery_status;
CHARGER_STATUS Fully_Charger,Booster_Charger,Solar_Charger,Combi_CHG,ACin_charger,ACout_charger;
TEMP_STATUS temp_status;
SOLAR_STATUS solar_status;
VAL_STATUS val_status;
WARNING_CODE_LIST waining_code_list[WAINING_CODE_MAX_LEN+1];//从[1]算起
u8 last_waining_code_list_num = 0;
u8 waining_code_list_num=0;
WARNING_CODE_LIST power_waining_code_list[WAINING_CODE_MAX_LEN+1];//从[1]算起
u8 power_waining_code_list_num=0;
bool f_ble_have = FALSE;
bool f_ble_connect_on = FALSE;
u8 f_fault_on = FALSE;//0 gray 1 yellow 2 red
bool f_fault_flash = FALSE;
bool f_override_key= FALSE;
bool f_handbreak=FALSE;
bool f_ignore_handbreak=FALSE;

u8 mcu_version_len = 0;
u8 mcu_version[30];

u8 control_mcu_ver_len = 0;
u8 control_mcu_ver[20];
u8 control_second_mcu_ver_len = 0;
u8 control_second_mcu_ver[20];

u8 External_key_mcu_ver_len = 0;
u8 External_key_mcu_ver[20]={0};
u8 External_protocol_mcu_ver_len = 0;
u8 External_protocol_mcu_ver[20]={0};

u8 upgrade_info_len1 = 0;
u8 upgrade_info_len2 = 0;
u8 upgrade_info_len3 = 0;
char upgrade_info1[48];
char upgrade_info2[48];
char upgrade_info3[48];


u16 current_val[SWITCH_NAME_CH_NUM]={0};
bool f_disply_current_val=TRUE;
bool f_disply_debug_val=FALSE;



u16 X_offset_test = 0;
u16 Y_offset_test = 0;//这两个值用来微调 测试 找准座标  通过0xFE发送
#if 0
void UART4_IRQHandler(void)
{
  u8  rx_data,tx_data;
  
  u8 rdata[251];
  u8 i=0;
    if (USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)
    {
        rx_data = (USART_ReceiveData(UART4) & 0xFF);              /* Read one byte from the receive data register         */
        
        uart4_fifo_rx_buf.data[uart4_fifo_rx_buf.write_p] = rx_data;        
        uart4_fifo_rx_buf.write_p++;
        if(uart4_fifo_rx_buf.write_p>=uart4_RX_LEN)
        uart4_fifo_rx_buf.write_p = 0;
        
        if(uart4_fifo_rx_buf.write_p == uart4_fifo_rx_buf.read_p)
         uart4_fifo_rx_buf.over_cnt++;
        USART_ClearITPendingBit(UART4, USART_IT_RXNE);          /* Clear the USART1 Receive interrupt */                         
    }

    if (USART_GetITStatus(UART4, USART_IT_TXE) != RESET)
    {
      USART_ClearITPendingBit(UART4, USART_IT_TXE);           /* Clear the USART1 transmit interrupt                  */
      if(uart4_fifo_tx_buf.read_p!=uart4_fifo_tx_buf.write_p)
			{
				tx_data = uart4_fifo_tx_buf.data[uart4_fifo_tx_buf.read_p];
				uart4_fifo_tx_buf.read_p++;
				if(uart4_fifo_tx_buf.read_p>=uart4_RX_LEN)
				uart4_fifo_tx_buf.read_p=0;
				USART_SendData(UART4,tx_data);
			}                  
			else
			{
				USART_ITConfig(UART4, USART_IT_TXE, DISABLE);
			}
     

        
    }

}

void FlC200_init(void)
{

    
    GPIO_InitTypeDef GPIO_InitStrue;     //在GPIO_Init函数调用时需定义一个GPIO_InitTypeDef结构体类型变量
    USART_InitTypeDef USART_InitStrue;    //USART_Init函数调用时需定义一个USART_InitTypeDef结构体类型变量
    NVIC_InitTypeDef NVIC_InitStrue;    //USART_Init函数调用时需定义一个NVIC_InitTypeDef结构体类型变量
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);//使能GPIOA时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);//使能USART2时钟

    
    GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;    //复用功能推挽输出模式
    GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10;    //PA9
    GPIO_InitStrue.GPIO_Speed=GPIO_Speed_50MHz;    //设置输出速度
    GPIO_Init(GPIOC,&GPIO_InitStrue);
    
    GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;    //浮空输入模式
    GPIO_InitStrue.GPIO_Pin=GPIO_Pin_11;    //PA10
    GPIO_Init(GPIOC,&GPIO_InitStrue);
    
    
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART4,ENABLE);//复位串口2
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART4,DISABLE);//停止复位
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);    //设置NVIC中断分组2:2位抢占优先级，2位响应优先级   0-3;
    NVIC_InitStrue.NVIC_IRQChannel=UART4_IRQn; //串口2对应的中断名称
    NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;    //使能该中断通道
    NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级为2，因为此程序只有一个中断，故可任意设置
    NVIC_InitStrue.NVIC_IRQChannelSubPriority=3;//响应优先级为1，因为此程序只有一个中断，故可任意设置
    NVIC_Init(&NVIC_InitStrue);    //中断初始化

    
    USART_InitStrue.USART_BaudRate=115200;//设置波特率9600
    USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//无硬件数据流控制，相关寄存器为CR3
    USART_InitStrue.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//模式为接收和发送
    USART_InitStrue.USART_Parity=USART_Parity_No;//无奇偶校验位0x0000，相关寄存器为SR1的PS位
    USART_InitStrue.USART_StopBits=USART_StopBits_1;    //1个停止位
    USART_InitStrue.USART_WordLength=USART_WordLength_8b;    //数据长度为8位
    USART_Init(UART4,&USART_InitStrue);    //串口初始化
    
    
    USART_ITConfig(UART4,USART_IT_RXNE,ENABLE);//使能串口中断，也叫开启串口中断，第二个参数是设置具体开启哪种中断，具体为寄存器SR
    USART_Cmd(UART4,ENABLE); //串口使能  就是将寄存器CR1中的UE位置1
    
    //fifo
   uart4_fifo_tx_buf.read_p=0;//读指针
   uart4_fifo_tx_buf.write_p=0;//写指针
   
   uart4_fifo_rx_buf.read_p=0;//读指针
   uart4_fifo_rx_buf.write_p=0;//写指针
   
}
#endif


void F1C200_rx_pro(void) //接受函数入口
{
	u8 data/*,temp*/,cnt=0;   
       // u16 i,j,addr_temp = 0;
        //u32 temp_u32=0;
        //static u8 qick_step = 0;//快速翻页指数
	static u16 MagLen,MagLenMax;	
        static u8 ComMagStatus,checksum;
        
	static u8 MsgPackage[256];
        
  while(1)	
	{
		cnt++;
         if(cnt>=100)//???20?
           break;
  if(FIFO_GET_ONE(McuUart0_RxFifo,&data)) 
  {        
		#ifdef SHOW_MCU_MSG_DATA
         sysprintf("-%X",data); 
		#endif

        // printf("%c",data);
        //  PrintfString(" ++");PrintfHex(data);
       //2E E1 01 00 1D 
        switch (ComMagStatus)
	{
		case 0:
			if (data == 0x2E) ComMagStatus = 1;
                        MsgPackage[0] = data;
			break;
		case 1:
			if ((data&0xF0)) {ComMagStatus = 2;}
			else ComMagStatus = 0;
                        checksum  = data;
                        MsgPackage[1] = data;//ID
			break;
		case 2:
			{
				ComMagStatus = 3;
				checksum  += data;
                                MagLenMax = data;//
                                MsgPackage[2] = data;
				MagLen = 0;
			}
			break;
                case 3:
			if(MagLen < (MagLenMax))
			{
				MsgPackage[MagLen+3] = data;
				checksum += data;
				MagLen ++;
                                //printf("checksum:0x%02X ",checksum);
			}
			else if(MagLen == (MagLenMax))
			{
                               // checksum2 = 0;
                                //checksum2 = CRC_GetModbus16(&(MsgPackage[3]),(MagLenMax-2));
                               MsgPackage[MagLen+3] = data;
                                uart4_Rx_all_cnt++;
                                checksum = 0xFF - checksum;
                                //printf("checksum:0x%02X ,0x%02X",checksum,data);
				if(MsgPackage[MagLenMax+3] == checksum)
				{
                                 // 	sysprintf("\r\n In FlC200_hc_cmd_proc \r\n  "); 

                                    FlC200_hc_cmd_proc(&MsgPackage[1]);//所有通过CRC的指令都会在这里解释
				}
				else
				{
                                  //PrintfString("\r\nc100  EEEEEEEEEEEEEEEEEE  MCU ERR %%%:");
				//	for(i=0;i<MagLen;i++) PrintfHex(MsgPackage[i]);
                                  //      PrintfString(" ");
                                        
                                 uart4_Rx_crcerr_cnt ++;
					
				}
				ComMagStatus = 0;
			}
			break;
		default:
			ComMagStatus = 0;
			break;
	}
        
    }
	else
		break;
}
}
   
/*
void Write_uart4_Tx_Fifo(u8 data)
{
   uart4_fifo_tx_buf.data[uart4_fifo_tx_buf.write_p] = data;        
   uart4_fifo_tx_buf.write_p++;
   if(uart4_fifo_tx_buf.write_p>=uart4_TX_LEN)
   uart4_fifo_tx_buf.write_p = 0;
        
   if(uart4_fifo_tx_buf.write_p == uart4_fifo_tx_buf.read_p)
   uart4_fifo_tx_buf.over_cnt++;


}*/

extern void Enable_Tx_IE(enum eUart uart,BOOL cmd);
/*EXPORT_FIFO_API(McuUart2_TxFifo,256,u8,u16);
EXPORT_FIFO_API(McuUart2_RxFifo,256,u8,u16);
EXPORT_FIFO_API(McuUart0_TxFifo,256,u8,u16);
EXPORT_FIFO_API(McuUart0_RxFifo,1024,u8,u16);*/

u8 FlC200_last_send_data[64];
void FlC200_send_all_new_hechi_packet(u8* buf) 
{

  //char print_buf[32];
  u16 checksum;
  u8 i;
  FlC200_last_send_data[0]=0x2E;
  
  checksum=0;
  for(i=0;i<(buf[2]+2);i++)
  {
     FlC200_last_send_data[i+1]=buf[1+i];
     checksum+=buf[1+i];
  }
  checksum = 0xFF - checksum;
  FlC200_last_send_data[buf[2]+3] = checksum;
/*
  for(i=0;i<(buf[2]+4);i++)
        Write_uart4_Tx_Fifo(FlC200_last_send_data[i]);
  USART_ITConfig(UART4, USART_IT_TXE, ENABLE);//启动发送
  //RS485_status.after_rec_data_cnt = 0;
  */
	#ifdef SHOW_MCU_MSG_DATA
	sysprintf("\r\n-->mcu"); 
	#endif
	for(i=0;i<(buf[2]+4);i++)
	{
	   FIFO_PUT_ONE(McuUart0_TxFifo,FlC200_last_send_data[i]);  
		#ifdef SHOW_MCU_MSG_DATA
		 sysprintf("+%X",FlC200_last_send_data[i]); 
		#endif
	}
	FIFO_PUT_ONE(McuUart0_TxFifo,(u8)(code_connect>>8));  
	FIFO_PUT_ONE(McuUart0_TxFifo,(u8)code_connect);  
	Enable_Tx_IE(UART0,TRUE);
}
 
void F1C200_send_hc_ack(void)
{



}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool f_FlC200_all_data_req=TRUE;
bool f_FlC200_send_Heartbeat=FALSE;
void send_FlC200_hc_req_cmd(u8 req_id)//
{
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_QUERY_STATE;
  buf[2]=0x02;
  buf[3]=req_id;
  buf[4]=0;
  FlC200_send_all_new_hechi_packet(buf);  
}

bool f_FlC200_connect_req=FALSE;//TRUE;
void send_FlC200_connect_req_cmd(void)//
{
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_START_END;
  buf[2]=0x01;
  buf[3]=01;
  FlC200_send_all_new_hechi_packet(buf);  
}

///////////////////switch cmd////////////////////////////
/*Lights:
0x00: Lights可调开关1:Overbed
0x01: Lights可调开关2:Hall
0x02: Lights可调开关3:Parlour
0x03: Lights可调开关4:备用开关

0x04-0x07: 预留
0x08: Lights开关1：Underbed
0x09: Lights开关2：Kitchen
0x0A: Lights开关3：Awning
0x0B: Lights开关4：Outdoor
0x0C: Lights开关5：Bath
0x0D: Lights开关6：Light(备用)
0x0E: Lights开关7：Light(备用)
0x0F: 所有Lights开关

Loads:
0x10: Loads开关1: Ventilator
0x11: Loads开关2: Water Pump
0x12: Loads开关3: TV
0x13: Loads开关4: Fridge
0x14: Loads开关5: Air Conditioner
0x15: Loads开关6: Microwave
0x16: Loads开关7: Washing Michine
0x17: Loads开关8: Kitchen Ventilator
0x18: Loads开关9: Load(备用)
0x19: Loads开关10: Load(备用)
0x1A-0x1E: 预留
0x1F: 所有Loads开关

其他开关
0x20: 总开关（12V开关）
0x21: 污水箱手动/自动加热控制（manual/auto）
0x22: 空水箱保护开关
0x23: 双电池隔离器
0x24: 逆变器开关
0x25-0x27: 预留
0x2F: 所有pumps开关

可调开关等级
0X30: 可调开关1 等级
0X31: 可调开关2 等级
0X32: 可调开关3 等级
0X33: 可调开关4 等级
*/
void pre_updata_swtich_status(u8 type,u8 cmd)
{
	 switch(type)
	 {
		 case 0x00:
			 if(cmd)
			 {
			    switch_ctrl_byte[0]|=0x80;
				  old_switch_ctrl_byte[0]|=0x80;
			 }
			 else
			 {
			    switch_ctrl_byte[0]&=~0x80;
				  old_switch_ctrl_byte[0]&=~0x80;
			 }
			 break;
			 case 0x01:
			 if(cmd)
			 {
			    switch_ctrl_byte[0]|=0x40;
				  old_switch_ctrl_byte[0]|=0x40;
			 }
			 else
			 {
			    switch_ctrl_byte[0]&=~0x40;
				  old_switch_ctrl_byte[0]&=~0x40;
			 }
			 break;
			 case 0x02:
			 if(cmd)
			 {
			    switch_ctrl_byte[0]|=0x20;
				  old_switch_ctrl_byte[0]|=0x20;
			 }
			 else
			 {
			    switch_ctrl_byte[0]&=~0x20;
				  old_switch_ctrl_byte[0]&=~0x20;
			 }
			 break;
			 case 0x03:
			 if(cmd)
			 {
			    switch_ctrl_byte[0]|=0x10;
				  old_switch_ctrl_byte[0]|=0x10;
			 }
			 else
			 {
			    switch_ctrl_byte[0]&=~0x10;
				  old_switch_ctrl_byte[0]&=~0x10;
			 }
			 break;
			 case 0x08:
			 if(cmd)
			 {
			    switch_ctrl_byte[1]|=0x80;
				  old_switch_ctrl_byte[1]|=0x80;
			 }
			 else
			 {
			    switch_ctrl_byte[1]&=~0x80;
				  old_switch_ctrl_byte[1]&=~0x80;
			 }
			 break;
			 case 0x09:
			 if(cmd)
			 {
			    switch_ctrl_byte[1]|=0x40;
				  old_switch_ctrl_byte[1]|=0x40;
			 }
			 else
			 {
			    switch_ctrl_byte[1]&=~0x40;
				  old_switch_ctrl_byte[1]&=~0x40;
			 }
			 break;
			 case 0x0A:
			 if(cmd)
			 {
			    switch_ctrl_byte[1]|=0x20;
				  old_switch_ctrl_byte[1]|=0x20;
			 }
			 else
			 {
			    switch_ctrl_byte[1]&=~0x20;
				  old_switch_ctrl_byte[1]&=~0x20;
			 }
			 break;
			 case 0x0B:
			 if(cmd)
			 {
			    switch_ctrl_byte[1]|=0x10;
				  old_switch_ctrl_byte[1]|=0x10;
			 }
			 else
			 {
			    switch_ctrl_byte[1]&=~0x10;
				  old_switch_ctrl_byte[1]&=~0x10;
			 }
			 break;
			 case 0x0C:
			 if(cmd)
			 {
			    switch_ctrl_byte[1]|=0x08;
				  old_switch_ctrl_byte[1]|=0x08;
			 }
			 else
			 {
			    switch_ctrl_byte[1]&=~0x08;
				  old_switch_ctrl_byte[1]&=~0x08;
			 }
			 break;
			 case 0x0D:
			 if(cmd)
			 {
			    switch_ctrl_byte[1]|=0x04;
				  old_switch_ctrl_byte[1]|=0x04;
			 }
			 else
			 {
			    switch_ctrl_byte[1]&=~0x04;
				  old_switch_ctrl_byte[1]&=~0x04;
			 }
			 break;
			 case 0x0E:
			 if(cmd)
			 {
			    switch_ctrl_byte[1]|=0x02;
				  old_switch_ctrl_byte[1]|=0x02;
			 }
			 else
			 {
			    switch_ctrl_byte[1]&=~0x02;
				  old_switch_ctrl_byte[1]&=~0x02;
			 }
			 break;
			 case 0x0F:
			 if(cmd)
			 {
			   // switch_ctrl_byte[]|=0x00;
				  //old_switch_ctrl_byte[]|=0x00;
			 }
			 else
			 {
			    //switch_ctrl_byte[]&~0x00;
				  //old_switch_ctrl_byte[]&~0x00;
			 }
			 break;
			 case 0x10:
			 if(cmd)
			 {
			    switch_ctrl_byte[2]|=0x80;
				  old_switch_ctrl_byte[2]|=0x80;
			 }
			 else
			 {
			    switch_ctrl_byte[2]&=~0x80;
				  old_switch_ctrl_byte[2]&=~0x80;
			 }
			 break;
			 case 0x11:
			 if(cmd)
			 {
			    switch_ctrl_byte[2]|=0x40;
				  old_switch_ctrl_byte[2]|=0x40;
			 }
			 else
			 {
			    switch_ctrl_byte[2]&=~0x40;
				  old_switch_ctrl_byte[2]&=~0x40;
			 }
			 break;
			 case 0x12:
			 if(cmd)
			 {
			    switch_ctrl_byte[2]|=0x20;
				  old_switch_ctrl_byte[2]|=0x20;
			 }
			 else
			 {
			    switch_ctrl_byte[2]&=~0x20;
				  old_switch_ctrl_byte[2]&=~0x20;
			 }
			 break;
			 case 0x13:
			 if(cmd)
			 {
			    switch_ctrl_byte[2]|=0x10;
				  old_switch_ctrl_byte[2]|=0x10;
			 }
			 else
			 {
			    switch_ctrl_byte[2]&=~0x10;
				  old_switch_ctrl_byte[2]&=~0x10;
			 }
			 break;
			 case 0x14:
			 if(cmd)
			 {
			    switch_ctrl_byte[2]|=0x08;
				  old_switch_ctrl_byte[2]|=0x08;
			 }
			 else
			 {
			    switch_ctrl_byte[2]&=~0x08;
				  old_switch_ctrl_byte[2]&=~0x08;
			 }
			 break;
			 case 0x15:
			 if(cmd)
			 {
			    switch_ctrl_byte[2]|=0x04;
				  old_switch_ctrl_byte[2]|=0x04;
			 }
			 else
			 {
			    switch_ctrl_byte[2]&=~0x04;
				  old_switch_ctrl_byte[2]&=~0x04;
			 }
			 break;
			 case 0x16:
			 if(cmd)
			 {
			    switch_ctrl_byte[2]|=0x02;
				  old_switch_ctrl_byte[2]|=0x02;
			 }
			 else
			 {
			    switch_ctrl_byte[2]&=~0x02;
				  old_switch_ctrl_byte[2]&=~0x02;
			 }
			 break;
			 case 0x17:
			 if(cmd)
			 {
			    switch_ctrl_byte[2]|=0x01;
				  old_switch_ctrl_byte[2]|=0x01;
			 }
			 else
			 {
			    switch_ctrl_byte[2]&=~0x001;
				  old_switch_ctrl_byte[2]&=~0x01;
			 }
			 break;
			 case 0x18:
			 if(cmd)
			 {
			    switch_ctrl_byte[3]|=0x80;
				  old_switch_ctrl_byte[3]|=0x80;
			 }
			 else
			 {
			    switch_ctrl_byte[3]&=~0x80;
				  old_switch_ctrl_byte[3]&=~0x80;
			 }
			 break;
			 case 0x19:
			 if(cmd)
			 {
			    switch_ctrl_byte[3]|=0x40;
				  old_switch_ctrl_byte[3]|=0x40;
			 }
			 else
			 {
			    switch_ctrl_byte[3]&=~0x40;
				  old_switch_ctrl_byte[3]&=~0x40;
			 }
			 break;
			 case 0x1F:
			 if(cmd)
			 {
			    //switch_ctrl_byte[]|=0x00;
				  //old_switch_ctrl_byte[]|=0x00;
			 }
			 else
			 {
			    //switch_ctrl_byte[]&~0x00;
				  //old_switch_ctrl_byte[]&~0x00;
			 }
			 break;
			 case 0x20:
			 if(cmd)
			 {
			    switch_ctrl_byte[4]|=0x80;
				  old_switch_ctrl_byte[4]|=0x80;
			 }
			 else
			 {
			    switch_ctrl_byte[4]&=~0x80;
				  old_switch_ctrl_byte[4]&=~0x80;
			 }
			 break;
			 case 0x21:
			 if(cmd)
			 {
			    switch_ctrl_byte[4]|=0x40;
				  old_switch_ctrl_byte[4]|=0x40;
			 }
			 else
			 {
			    switch_ctrl_byte[4]&=~0x40;
				  old_switch_ctrl_byte[4]&=~0x40;
			 }
			 break;
			 case 0x22:
			 if(cmd)
			 {
			    //switch_ctrl_byte[4]|=0x00;
				  //old_switch_ctrl_byte[4]|=0x00;
			 }
			 else
			 {
			    //switch_ctrl_byte[4]&=~0x00;
				  //old_switch_ctrl_byte[4]&=~0x00;
			 }
			 break;
			 case 0x23:
			 if(cmd)
			 {
			    //switch_ctrl_byte[]|=0x00;
				  //old_switch_ctrl_byte[]|=0x00;
			 }
			 else
			 {
			    //switch_ctrl_byte[]&~0x00;
				  //old_switch_ctrl_byte[]&~0x00;
			 }
			 break;
			 case 0x24:
			 if(cmd)
			 {
			    switch_ctrl_byte[4]|=0x08;
				  old_switch_ctrl_byte[4]|=0x08;
			 }
			 else
			 {
			    switch_ctrl_byte[4]&=~0x08;
				  old_switch_ctrl_byte[4]&=~0x08;
			 }
			 break;
			 
			 case 0x30:
			 if(cmd)
			 {
			    //switch_ctrl_byte[]|=0x00;
				 // old_switch_ctrl_byte[]|=0x00;
			 }
			 else
			 {
			    //switch_ctrl_byte[]&~0x00;
				  //old_switch_ctrl_byte[]&~0x00;
			 }
			 break;
			 
			 case 0x31:
			 if(cmd)
			 {
			    //switch_ctrl_byte[]|=0x00;
				 // old_switch_ctrl_byte[]|=0x00;
			 }
			 else
			 {
			    //switch_ctrl_byte[]&~0x00;
				  //old_switch_ctrl_byte[]&~0x00;
			 }
			 break;
			 
			 case 0x32:
			 if(cmd)
			 {
			   // switch_ctrl_byte[]|=0x00;
				 // old_switch_ctrl_byte[]|=0x00;
			 }
			 else
			 {
			   // switch_ctrl_byte[]&~0x00;
				 // old_switch_ctrl_byte[]&~0x00;
			 }
			 break;
			 
			 case 0x33:
			 if(cmd)
			 {
			    //switch_ctrl_byte[]|=0x00;
				  //old_switch_ctrl_byte[]|=0x00;
			 }
			 else
			 {
			    //switch_ctrl_byte[]&~0x00;
				  //old_switch_ctrl_byte[]&~0x00;
			 }
			 break;
		 
	 
	 
	 }



}
	bool Is_uint_Fahrenheit(void)
{
   if((base_return_status.uint&0x0C)==0x04)
     return TRUE;
   else
     return FALSE;
}
#define HC_MASTER_CMD_HVAC_SET 0xC8

void send_FlC200_Hvac_cmd(u8 ch,P6_HVAC_CTRL_STATUS* P6_Hvac_ctrl_status_p)//
{
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_HVAC_SET;//0xC8
  buf[2]=0x06;
  buf[3]=ch;
	buf[4]=P6_Hvac_ctrl_status_p->sw_mode;
    if(P6_Hvac_ctrl_status_p->sw_mode == MODE_COOL)
        buf[5]=P6_Hvac_ctrl_status_p->fan_speed;
    else if(P6_Hvac_ctrl_status_p->sw_mode == MODE_HEAT_PUMP)
        buf[5]=P6_Hvac_ctrl_status_p->fan_speed_heat;
	if(Is_uint_Fahrenheit())//F
	{ 
	   buf[6]=P6_Hvac_ctrl_status_p->Furnace_set_temp_f;
		 buf[7]=P6_Hvac_ctrl_status_p->Cool_set_temp_f;
		 buf[8]=P6_Hvac_ctrl_status_p->Auto_set_temp_f;
	}
	else
	{
	   buf[6]=P6_Hvac_ctrl_status_p->Furnace_set_temp;//制暖温度
		 buf[7]=P6_Hvac_ctrl_status_p->Cool_set_temp;
		 buf[8]=P6_Hvac_ctrl_status_p->Auto_set_temp;
	
	}

	
  FlC200_send_all_new_hechi_packet(buf);  
}



void send_FlC200_swtich_cmd(u8 type,u8 cmd)//c0
{
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_SWITCH_CTR;//0xC0
  buf[2]=0x02;
  buf[3]=type;
	buf[4]=cmd;
	pre_updata_swtich_status(type,cmd);//先更新状态，不用等下面返回，如果返回不一样再处理
  FlC200_send_all_new_hechi_packet(buf);  
}

void send_FlC200_swtich2B_cmd(u8 type,u8 cmd1,u8 cmd2)//c0
{
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_SWITCH_CTR;//0xC0
  buf[2]=0x04;
  buf[3]=type;
	buf[4]=cmd1;
    buf[5]=cmd2;
    buf[6]=0x01;

	//pre_updata_swtich_status(type,cmd);//先更新状态，不用等下面返回，如果返回不一样再处理
  FlC200_send_all_new_hechi_packet(buf);  
}


///////////////////switch rename////////////////////////////
void send_FlC200_swtich_name_cmd(u8 type)//
{
  u8 buf[32];//[12]???????????????
	u8 i;
  buf[1]=HC_MASTER_CMD_SWITCH_NAME;
  //buf[2]=0x02;
  buf[3]=type;
	buf[4]=switch_name_list[type].icon_select;
	buf[5]=switch_name_list[type].txt_len;
	//sysprintf("\r\nrrrrrrrrrrrrrrrrrrrrr%d",buf[4]);
	if(buf[5]!=0)
  {
     for(i=0;i<buf[5];i++)
       buf[6+i]=switch_name_list[type].txt[i];
  }
	buf[2]=buf[5]+3;
  FlC200_send_all_new_hechi_packet(buf);  
}

/////////////////////CMD_SET_CMD//////////////////////////
void send_FlC200_set_cmd(u8 type,u16 para)//
{
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_SET_CMD;//0xC2
  buf[2]=0x03;
  buf[3]=type;
	buf[4]=(u8)(para>>8);
	buf[5]=(u8)(para);
    
    
  FlC200_send_all_new_hechi_packet(buf);  
}
  
/////////////////////CMD_SET_CMD//////////////////////////
//void send_FlC200_set_cmd(u8 type,u32 para)//
//{
//  u8 buf[12];
//  buf[1]=HC_MASTER_CMD_SET_CMD;
//  buf[2]=0x03;
//  buf[3]=type;
//	buf[4]=(u8)(para>>16)&0xff;
//	buf[5]=(u8)(para>>8)&0xff;
//    buf[6]=(u8)(para)&0xff;

//    
//  FlC200_send_all_new_hechi_packet(buf);  
//}
  
/////////////////////CMD_SET_CMD//////////////////////////
void send_FlC200_set_cmd_new(u8 type,u16 para,u8 ch)//
{
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_SET_CMD;//c2、控制器设定控制指令【0xC2】
  buf[2]=0x04;//数据长度
  buf[3]=type;//指令
	buf[4]=(u8)(para>>8);//D1
	buf[5]=(u8)(para);
	buf[6]=(u8)(ch);//D3
  FlC200_send_all_new_hechi_packet(buf);  
}



/////////////////////_TIME_SET//////////////////////////
void send_FlC200_time_set_cmd(void)//
{
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_TIME_SET;
  buf[2]=0x07;
  buf[3]=time_status.year;
	buf[4]=time_status.mon;
	buf[5]=time_status.day;
	buf[6]=time_status.hour;
	buf[7]=time_status.min;
	buf[8]=time_status.sec;
	buf[9]=time_status.format;
  FlC200_send_all_new_hechi_packet(buf);  
}
  
/////////////////////BASE_SET_CMD//////////////////////////
void send_FlC200_base_set_cmd(u8 type,u8 para,u8 para2)//
{   
  u8 buf[12];
  buf[1]=HC_MASTER_CMD_BASE_SET;
  buf[2]=0x03;
  buf[3]=type;
	buf[4]=(u8)(para);
	buf[5]=(u8)(para2);
  FlC200_send_all_new_hechi_packet(buf);  
}

/////////////////////////////////////////////
bool f_FlC200_send_hc_version_req=FALSE;
void send_FlC200_hc_version(void)//
{
  u8 buf[22];
  buf[1]=HC_SLAVE_CMD_VERSION;
  buf[2]=0x11;
//  sprintf((char*)(buf+3),"Focus%s",__DATE__);  
  memset(buf+3,0,17);//先清零
  u8 len=strlen(VERSION_STR);
  if(len<=17)
  {
    memcpy(buf+3,VERSION_STR,len);
  }
  else
    sprintf((char*)(buf+3),"Build%s",__DATE__);  
//  sprintf(VERSION_STR);
  FlC200_send_all_new_hechi_packet(buf);  
 /* #ifdef  USE_USB_HID
    Usb_Packet_Tx_Rroc(buf);
  #endif*/
}

/////////////////////TEST_CMD//////////////////////////
void send_FlC200_test_cmd(u8 mode)//
{
  u8 buf[12];
  buf[1]=0xFE;
  buf[2]=0x01;
  buf[3]=mode;
  FlC200_send_all_new_hechi_packet(buf);  
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


void FlC200_hc_ready_time_send_proc(void)//串口处于空闲，可发送数据的状态下。由于本处理在最高优先级的任务中执行，所以XX_IS_CHANGE中先判断，
{                              //然后再由发送函数发送出去也不会出现IS_CHANGE检测到的数据与实际发出的数据不相符的情况！！！   
  
  //static u8 key_repeat_count=0;
  

//  if (!hc_comm_started)
//    return;
#ifndef DEBUG_MODE//2012-10-23
//if (!FLASH_GetReadOutProtectionStatus())//如果已经加密
 // return;
#endif

  // f_FlC200_send_hc_version_req = TRUE;
  
 //if(f_send_hc_car_type ==TRUE)
    //send_hc_cartype_packet();
	if(f_FlC200_connect_req)//请求连接
	{
		f_FlC200_connect_req=FALSE;
    send_FlC200_connect_req_cmd();
  }
	else if(f_FlC200_all_data_req)//请求所有数据
	{
	   f_FlC200_all_data_req = FALSE;
		 send_FlC200_hc_req_cmd(0xFF);
	}
  else if(f_FlC200_send_Heartbeat)//f_FlC200_send_Heartbeat
	{
	   f_FlC200_send_Heartbeat = FALSE;
		 send_FlC200_hc_req_cmd(0x00);
	}
  else //！！！！这个处理必需放在最后来做，否则按下按键后别的变化状态就不能实时传送出去了
  {

  }

  
}


//////////  请求ID  //////////////////////////////////////////////////

void F1C200_query_state_proc(u8 val,u8 para)
{
  switch (val)
  {
  case HC_SLAVE_CMD_SWITCH_STATUS:
   //f_FlC200_send_switch_status_req=TRUE;
    break;

    
  default:
    break;
  }
}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void FlC200_hc_comm_base_status_pro(u8* para)//新手刹（刹车信号）
{
	 u8 i;
	if(para[1]&0x08)
		 f_handbreak = TRUE;//手刹
	else
	   f_handbreak = FALSE;
    
    if(1)sysprintf(" f_handbreak=%d\r\n",f_handbreak);

}
    



void FlC200_hc_comm_product_id_pro(u8* para)
{
	 u8 i;
	if(para[0]==2)
	{
		 Control_Unit_product_id = para[1]*256+para[2];
  }
}

void FlC200_hc_comm_version_pro(u8* para)
{
	 u8 i;
   mcu_version_len = para[0];
    
//   sysprintf(" ----------mcu_version_len=%d\r\n",mcu_version_len);

	for(i=0;i<mcu_version_len;i++)
	{
        mcu_version[i] = para[1+i];
		MCU_VERSION_STR[5+i] = para[1+i];
	}
	MCU_VERSION_STR[5+i+1] = '\0';
}

//char CONTROL_MCU_VERSION_STR[32]="Control Unit MCU: "; 
//char CONTROL_SECOND_MCU_VERSION_STR[32]="Control Unit SlaveMCU: "; 
/*u8 control_mcu_ver_len = 0;
u8 control_mcu_ver[20];
u8 control_second_mcu_ver_len = 0;
u8 control_second_mcu_ver[20];*/
void FlC200_hc_comm_ctr_mcu_version_pro(u8* para)
{
	 u8 i;
	if(para[1]==1)
	{
		 control_mcu_ver_len = para[0]-1;
		for(i=0;i<control_mcu_ver_len;i++)
		{
			control_mcu_ver[i] = para[2+i];
			CONTROL_MCU_VERSION_STR[18+i] = para[2+i];
		}
		CONTROL_MCU_VERSION_STR[18+i+1] = '\0';
  }
	else if(para[1]==2)
	{
		control_second_mcu_ver_len = para[0]-1;
		for(i=0;i<control_second_mcu_ver_len;i++)
		{
			control_second_mcu_ver[i] = para[2+i];
			CONTROL_SECOND_MCU_VERSION_STR[23+i] = para[2+i];
		}
		CONTROL_SECOND_MCU_VERSION_STR[23+i+1] = '\0';
                sysprintf(" ----------control_second_mcu_ver_len=%d\r\n",control_second_mcu_ver_len);

  }
//	else if(para[1]==3)
//	{
//		 External_key_mcu_ver_len = para[0]-1;
//		for(i=0;i<External_key_mcu_ver_len;i++)
//		{
//			External_key_mcu_ver[i] = para[2+i];
//			External_key_MCU_VERSION_STR[18+i] = para[2+i];
//		}
//		External_key_MCU_VERSION_STR[18+i+1] = '\0';
//  }
    
  
//	else if(para[1]==4)
//	{
//		 External_protocol_mcu_ver_len = para[0]-1;
//		for(i=0;i<External_protocol_mcu_ver_len;i++)
//		{
//			External_protocol_mcu_ver[i] = para[2+i];
//			External_protocol_MCU_VERSION_STR[23+i] = para[2+i];
//		}                                                              
//		External_protocol_MCU_VERSION_STR[23+i+1] = '\0';
//        
//  }
    
  	else if(para[1]==3)
	{
		 External_protocol_mcu_ver_len = para[0]-1;
		for(i=0;i<External_protocol_mcu_ver_len;i++)
		{
			External_protocol_mcu_ver[i] = para[2+i];
			External_protocol_MCU_VERSION_STR[23+i] = para[2+i];
		}
		External_protocol_MCU_VERSION_STR[23+i+1] = '\0';
        sysprintf(" ----------External_protocol_mcu_ver_len=%d\r\n",External_protocol_mcu_ver_len);

  }
	/*
	=0x20:MPPT描述符
=0x30:DC-DC描述符
=0x40:逆变器描述符
=0x50:电池1(库仑计)描述符
=0x51:电池2描述符
=0x52:电池3描述符
	extern char Extra_device_mppt_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_Dc_Dc_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_inverter_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_battery_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_battery2_ver[EXTRA_DEVICE_VER_LEN];
extern char Extra_device_battery3_ver[EXTRA_DEVICE_VER_LEN];*/
	else if(para[1]==0x20)
	{		
		for(i=0;i<(para[0]-1);i++)
		{
			Extra_device_mppt_ver[i] = para[2+i];
			if(i==(EXTRA_DEVICE_VER_LEN-1))
			{
			   Extra_device_mppt_ver[i] = 0;
				break;
			}
		}
  }
	else if(para[1]==0x30)
	{		
		for(i=0;i<(para[0]-1);i++)
		{
			Extra_device_Dc_Dc_ver[i] = para[2+i];
			if(i==(EXTRA_DEVICE_VER_LEN-1))
			{
			   Extra_device_Dc_Dc_ver[i] = 0;
				break;
			}
		}
  }
	else if(para[1]==0x40)
	{		
		for(i=0;i<(para[0]-1);i++)
		{
			Extra_device_inverter_ver[i] = para[2+i];
			if(i==(EXTRA_DEVICE_VER_LEN-1))
			{
			   Extra_device_inverter_ver[i] = 0;
				break;
			}
		}
  }
	else if(para[1]==0x50)
	{		
		for(i=0;i<(para[0]-1);i++)
		{
			Extra_device_battery_ver[i] = para[2+i];
			if(i==(EXTRA_DEVICE_VER_LEN-1))
			{
			   Extra_device_battery_ver[i] = 0;
				break;
			}
		}
  }
	else if(para[1]==0x51)
	{		
		for(i=0;i<(para[0]-1);i++)
		{
			Extra_device_battery2_ver[i] = para[2+i];
			if(i==(EXTRA_DEVICE_VER_LEN-1))
			{
			   Extra_device_battery2_ver[i] = 0;
				break;
			}
		}
  }
	else if(para[1]==0x52)
	{		
		for(i=0;i<(para[0]-1);i++)
		{
			Extra_device_battery3_ver[i] = para[2+i];
			if(i==(EXTRA_DEVICE_VER_LEN-1))
			{
			   Extra_device_battery3_ver[i] = 0;
				break;
			}
		}
  }
	
	
}



void FlC200_hc_comm_External_mcu_printf_pro(u8* para)
{
	 //u8 i;
   char print_buf[100];
   static u8 k = 0;

		sprintf(print_buf,"\r\nExt_mcu sn%d:%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X",\
		k,para[1],para[2],para[3],para[4],para[5],para[6],para[7],para[8],para[9],para[10],\
		para[11],para[12],para[13],para[14],para[15],para[16],para[17],para[18],para[19],para[20]); 
	  fill_DisplayBuf(print_buf);
	  k++;

}



void FlC200_hc_comm_mac_pro(u8* para)
{
	 u8 i,len;
   len = para[0];
	 if(len>12) 
		 len=12;
	for(i=0;i<len;i++)
	{
    //mcu_version[i] = para[1+i];
		BT_MAC_STR[i] = para[1+i];
	}

}


void init_FlC200_hc_comm_req(void)
{ 
  u8 buf[20];
  buf[1]=HC_SLAVE_CMD_CODE_CONNECT;
  buf[2]=2;
  
  buf[3]=(u8)(code_connect>>8);
  buf[4]=(u8)code_connect;

  FlC200_send_all_new_hechi_packet(buf); 

}


extern lcd_dis_item_t *p_lights_lights_item_d[MAX_LIGHTS_DIAPLAY_NUM];
extern lcd_dis_item_t *p_home_lights_item_d[MAX_DIAPLAY_NUM];

extern lcd_dis_item_t *p_loads_loads_item_d[MAX_LOADS_DIAPLAY_NUM];
extern lcd_dis_item_t *p_home_loads_item_d[MAX_DIAPLAY_NUM];

extern lcd_dis_item_t tanks_item[TANKS_ICO_NUM];
extern lcd_dis_item_t home_item[HOME_ICO_NUM];
extern lcd_dis_item_t power_item[POWER_ICO_NUM];
extern lcd_dis_item_t tanks_set_item[TANKS_SET_ICO_NUM];

extern u8 dis_page_item;




#define HOME_UPDATA_NUM 4
lcd_dis_item_t *p_home_updata_item[HOME_UPDATA_NUM]=
{
//&home_item[0],//
&home_item[2],//
&home_item[4],//
&home_item[8],//
&home_item[11],//
};

void set_home_off_item_key_type(void)
{
	lcd_dis_page_t *p1= &page_home.page_left_side;
	if(f_override_key==FALSE)
	{
		//lights_off
			if(((switch_ctrl_byte[0]&0xF0)||(switch_ctrl_byte[1]&0x7E)))//所有灯灭时，不执行
			{
				
				 home_item[2].key_type = KEY_TYPE_NORMAL;
				/* home_item[2].now_status=STATUS_SELECT;
				 if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
					home_item[2].last_status=STATUS_SELECT;*/

			}
			else 
			{
				 if(home_item[2].now_status==STATUS_SELECT)
				 {
					home_item[2].key_type = KEY_TYPE_TOUCH_NONE;
					home_item[2].now_status=STATUS_IDLE;
					if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
					 home_item[2].last_status=STATUS_IDLE;

				 }
				 else
				 {
					//home_item[2].key_type = KEY_TYPE_NORMAL; 
					// home_item[2].pic_item_select =t_home_lightsoff_d.pic_item;//
				 // home_item[2].size_of_pic_item_select= t_home_lightsoff_d.size_of_pic_item ;
				 }
			}
			//loads_off
			if(((switch_ctrl_byte[2]&0xFF)||(switch_ctrl_byte[3]&0xC0)))//所有load关时，不执行
			{
				home_item[4].key_type = KEY_TYPE_NORMAL;
				home_item[4].now_status=STATUS_SELECT;
				if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
					home_item[4].last_status=STATUS_SELECT;
			}
			else 
			{
				 if(home_item[4].now_status==STATUS_SELECT)
				 {
						home_item[4].key_type = KEY_TYPE_TOUCH_NONE;
						home_item[4].now_status=STATUS_IDLE;
						if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
							home_item[4].last_status=STATUS_IDLE;
				 }
				 //if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
				//	home_item[4].last_status=STATUS_SELECT;
			}	
   }
	else
	{

				//home_item[2].key_type = KEY_TYPE_TOUCH_NONE;

				//home_item[4].key_type = KEY_TYPE_TOUCH_NONE;
		
		if(((switch_ctrl_byte[0]&0xF0)||(switch_ctrl_byte[1]&0x7E)))//所有灯灭时，不执行
			{
				
				 home_item[2].key_type = KEY_TYPE_TOUCH_NONE;
				/* home_item[2].now_status=STATUS_SELECT;
				 if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
					home_item[2].last_status=STATUS_SELECT;*/

			}
			else 
			{
				 if(home_item[2].now_status==STATUS_SELECT)
				 {
					home_item[2].key_type = KEY_TYPE_TOUCH_NONE;
					home_item[2].now_status=STATUS_IDLE;
					if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
					 home_item[2].last_status=STATUS_IDLE;

				 }
				 else
				 {
					//home_item[2].key_type = KEY_TYPE_NORMAL; 
					// home_item[2].pic_item_select =t_home_lightsoff_d.pic_item;//
				 // home_item[2].size_of_pic_item_select= t_home_lightsoff_d.size_of_pic_item ;
				 }
			}
			//loads_off
			if(((switch_ctrl_byte[2]&0xFF)||(switch_ctrl_byte[3]&0xC0)))//所有load关时，不执行
			{
				home_item[4].key_type = KEY_TYPE_TOUCH_NONE;
				home_item[4].now_status=STATUS_SELECT;
				if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
					home_item[4].last_status=STATUS_SELECT;
			}
			else 
			{
				 if(home_item[4].now_status==STATUS_SELECT)
				 {
						home_item[4].key_type = KEY_TYPE_TOUCH_NONE;
						home_item[4].now_status=STATUS_IDLE;
						if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
							home_item[4].last_status=STATUS_IDLE;
				 }
				 //if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
				//	home_item[4].last_status=STATUS_SELECT;
			}	
	
	}

}



bool set_switch_icon_status(void)
{
	 u8 i,temp;
//	u16 temp2 = 0;
	 bool f_upgrate = FALSE;
	lcd_dis_page_t *p1,*p2;
	lcd_dis_item_t *p;
	p1 = &page_home.page_left_side;
	p2 = &page_home.page_top_side[page_home.page_left_side.now_item];

	
	///////////////////////////////frist updata button status////////////////////////////////////////////
	//可调开关	4个
	for(i=0;i<4;i++)
	{
		if(switch_ctrl_byte[0]&(0x80>>i))
		{					 
			p_home_lights_item_d[i]->now_status=STATUS_SELECT;
			//p_home_lights_item_d[i]->last_status=STATUS_SELECT;//home页在本函数直接更新
			
			p_lights_lights_item_d[i]->now_status=STATUS_SELECT;
			p_lights_lights_item_d[i]->last_status=STATUS_SELECT;	
			
		}
		else
		{

			 p_home_lights_item_d[i]->now_status=STATUS_IDLE;
			// p_home_lights_item_d[i]->last_status=STATUS_IDLE;//home页在本函数直接更新
			
			 p_lights_lights_item_d[i]->now_status=STATUS_IDLE;
			 p_lights_lights_item_d[i]->last_status=STATUS_IDLE;			

		}
	}
	
	//灯 7个
	temp = switch_ctrl_byte[1];
	for(i=0;i<6;i++)
	{
		if(temp&0x40)
		{
			 p_lights_lights_item_d[4+i]->now_status=STATUS_SELECT;
			 p_lights_lights_item_d[4+i]->last_status=STATUS_SELECT;
			 if(i<2)
			 {
			   p_home_lights_item_d[4+i]->now_status=STATUS_SELECT;
			  // p_home_lights_item_d[3+i]->last_status=STATUS_SELECT;//home页在本函数直接更新
			 }
		}
		else
		{
			 p_lights_lights_item_d[4+i]->now_status=STATUS_IDLE;
			 p_lights_lights_item_d[4+i]->last_status=STATUS_IDLE;
			 if(i<2)
			 {
			   p_home_lights_item_d[4+i]->now_status=STATUS_IDLE;
			  // p_home_lights_item_d[4+i]->last_status=STATUS_IDLE;//home页在本函数直接更新
			 }
		}

		temp<<=1;
  }
	

	
	
	
	
	
	//load 8个 
	temp = switch_ctrl_byte[2];
	for(i=0;i<8;i++)
	{
		if(temp&0x80)
		{
			 p_loads_loads_item_d[i]->now_status=STATUS_SELECT;
			 p_loads_loads_item_d[i]->last_status=STATUS_SELECT;
			 if(i<6)
			 {
				 //if(p_home_loads_item_d[i]->now_status!=STATUS_SELECT)
			  // f_upgrate = TRUE;
			   p_home_loads_item_d[i]->now_status=STATUS_SELECT;
			   //p_home_loads_item_d[i]->last_status=STATUS_SELECT;
			 }
			 /*if(i==1)
			 { 
			    tanks_item[ICO_tanks_wp].now_status=STATUS_SELECT;
			    tanks_item[ICO_tanks_wp].last_status=STATUS_SELECT;
				 
				  //if(home_item[11].now_status!=STATUS_SELECT)
			   // f_upgrate = TRUE;
				  home_item[11].now_status=STATUS_SELECT;
			    //home_item[11].last_status=STATUS_SELECT;
			 }*/
		}
		else
		{
			 p_loads_loads_item_d[i]->now_status=STATUS_IDLE;
			 p_loads_loads_item_d[i]->last_status=STATUS_IDLE;
			 if(i<6)
			 {
				// if(p_home_loads_item_d[i]->now_status!=STATUS_IDLE)
			 //f_upgrate = TRUE;
			   p_home_loads_item_d[i]->now_status=STATUS_IDLE;
			   //p_home_loads_item_d[i]->last_status=STATUS_IDLE;
			 }
			 /* if(i==1)
			 { 
				 
				 //if(home_item[i].now_status!=STATUS_IDLE)
			// f_upgrate = TRUE;
			    tanks_item[ICO_tanks_wp].now_status=STATUS_IDLE;
			    tanks_item[ICO_tanks_wp].last_status=STATUS_IDLE;
				  home_item[11].now_status=STATUS_IDLE;
			    //home_item[11].last_status=STATUS_IDLE;
				 //
			 }*/
		}

		temp<<=1;
  }
	
	
	//附加load 2个
	if(switch_ctrl_byte[3]&0x80)
	{
			 p_loads_loads_item_d[8]->now_status=STATUS_SELECT;
			 p_loads_loads_item_d[8]->last_status=STATUS_SELECT;
	}
	else
	{
			 p_loads_loads_item_d[8]->now_status=STATUS_IDLE;
			 p_loads_loads_item_d[8]->last_status=STATUS_IDLE;
	}
	if(switch_ctrl_byte[3]&0x40)
	{
			 p_loads_loads_item_d[9]->now_status=STATUS_SELECT;
			 p_loads_loads_item_d[9]->last_status=STATUS_SELECT;
	}
	else
	{
			 p_loads_loads_item_d[9]->now_status=STATUS_IDLE;
			 p_loads_loads_item_d[9]->last_status=STATUS_IDLE;
	}
	
	//pump 2个
	if(switch_ctrl_byte[0]&0x02)
	{
	   home_item[11].now_status=STATUS_SELECT;
	   if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
		   home_item[11].last_status=STATUS_SELECT;
		 
		 tanks_item[ICO_tanks_wp].now_status=STATUS_SELECT;
		 if(p1->now_item!=LEFT_SIDE_PAGE_TANKS)
		   tanks_item[ICO_tanks_wp].last_status=STATUS_SELECT;
	}
	else
	{
	  home_item[11].now_status=STATUS_IDLE;
		 if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
		   home_item[11].last_status=STATUS_IDLE; 
		 
		tanks_item[ICO_tanks_wp].now_status=STATUS_IDLE;
		if(p1->now_item!=LEFT_SIDE_PAGE_TANKS)
		   tanks_item[ICO_tanks_wp].last_status=STATUS_IDLE;
		
	}
	if(switch_ctrl_byte[0]&0x01)
	{

		 tanks_item[ICO_tanks_wp+1].now_status=STATUS_SELECT;
		 if(p1->now_item!=LEFT_SIDE_PAGE_TANKS)
		   tanks_item[ICO_tanks_wp+1].last_status=STATUS_SELECT;
	}
	else
	{

		 
		tanks_item[ICO_tanks_wp+1].now_status=STATUS_IDLE;
		if(p1->now_item!=LEFT_SIDE_PAGE_TANKS)
		   tanks_item[ICO_tanks_wp+1].last_status=STATUS_IDLE;
		
	}
	
	
	//lights off	
	if(switch_ctrl_byte[1]&0x01)
	{
		 //if(home_item[0].now_status!=STATUS_SELECT)
			//   f_upgrate = TRUE;
		 home_item[2].now_status=STATUS_SELECT;
		 //home_item[2].last_status=STATUS_SELECT;		
		 //home_item[2].key_type = KEY_TYPE_NORMAL;


	}
	else
	{
		//if(home_item[i].now_status!=STATUS_IDLE)
		//	 f_upgrate = TRUE;
	   home_item[2].now_status=STATUS_IDLE;
		 //home_item[2].pic_item_select =t_home_lightsoff_d.pic_item;//
     //home_item[2].size_of_pic_item_select= t_home_lightsoff_d.size_of_pic_item ;
		 //home_item[2].last_status=STATUS_IDLE;
     //home_item[2].key_type = KEY_TYPE_TOUCH_NONE;
	}
	
	//loadss off	
	if(switch_ctrl_byte[3]&0x01)
	{
		 //if(home_item[0].now_status!=STATUS_SELECT)
			//   f_upgrate = TRUE;
		 home_item[4].now_status=STATUS_SELECT;
		 //home_item[4].last_status=STATUS_SELECT;
		home_item[4].key_type = KEY_TYPE_NORMAL;

	}
	else
	{
		//if(home_item[i].now_status!=STATUS_IDLE)
		//	 f_upgrate = TRUE;
	   home_item[4].now_status=STATUS_IDLE;
		 //home_item[4].last_status=STATUS_IDLE;
		home_item[4].key_type = KEY_TYPE_TOUCH_NONE;

	}
	
	//pumps off	
	/*if(switch_ctrl_byte[3]&0x02)
	{
		 //if(home_item[0].now_status!=STATUS_SELECT)
			//   f_upgrate = TRUE;
		 home_item[11].now_status=STATUS_SELECT;
	   if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
		   home_item[11].last_status=STATUS_SELECT;
	
		 home_item[11].key_type = KEY_TYPE_NORMAL;
		 
		 tanks_item[ICO_tanks_wp].now_status=STATUS_SELECT;
		 if(p1->now_item!=LEFT_SIDE_PAGE_TANKS)
		   tanks_item[ICO_tanks_wp].last_status=STATUS_SELECT;
		 
		 tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_NORMAL;

	}
	else
	{
		//if(home_item[i].now_status!=STATUS_IDLE)
		//	 f_upgrate = TRUE;
	   home_item[11].now_status=STATUS_IDLE;
		 if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
		   home_item[11].last_status=STATUS_IDLE; 
		 home_item[11].key_type = KEY_TYPE_TOUCH_NONE;
		 
		tanks_item[ICO_tanks_wp].now_status=STATUS_IDLE;
		if(p1->now_item!=LEFT_SIDE_PAGE_TANKS)
		   tanks_item[ICO_tanks_wp].last_status=STATUS_IDLE;
		
		if(switch_ctrl_byte[3]&0x04)
		 tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_NORMAL;
		 else
			 tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_TOUCH_NONE;

	}*/

	//inverver	
	if(switch_ctrl_byte[4]&0x08)
	{
		 //if(home_item[0].now_status!=STATUS_SELECT)
			//   f_upgrate = TRUE;
		// home_item[0].now_status=STATUS_SELECT;
		 //home_item[0].last_status=STATUS_SELECT;
		 //power_item[5].now_status=STATUS_SELECT;
		 //power_item[5].last_status=STATUS_SELECT;
	}
	else
	{
		//if(home_item[i].now_status!=STATUS_IDLE)
		//	 f_upgrate = TRUE;
	  // home_item[0].now_status=STATUS_IDLE;
		 //home_item[0].last_status=STATUS_IDLE;
		 //power_item[5].now_status=STATUS_IDLE;
		 //power_item[5].last_status=STATUS_IDLE;
	}
	//12V
	if(switch_ctrl_byte[4]&0x80)
	{

		 home_item[8].now_status=STATUS_SELECT;
		 //home_item[8].last_status=STATUS_SELECT;
		// power_item[5].now_status=STATUS_SELECT;
		// power_item[5].last_status=STATUS_SELECT;
	}
	else
	{

	   home_item[8].now_status=STATUS_IDLE;
		 //home_item[8].last_status=STATUS_IDLE;
		// power_item[5].now_status=STATUS_IDLE;
		// power_item[5].last_status=STATUS_IDLE;
	}
	
	//auto heart
	if(switch_ctrl_byte[4]&0x40)
	{

		 //tanks_set_item[5].now_status=STATUS_SELECT;
		 //tanks_set_item[5].last_status=STATUS_SELECT;

	}
	else
	{

	   //tanks_set_item[5].now_status=STATUS_IDLE;
		 //tanks_set_item[5].last_status=STATUS_IDLE;

	}
	
	
	
	
	
 	if(p1->now_item==LEFT_SIDE_PAGE_HOME)
  {

		for(i=0;i<HOME_UPDATA_NUM;i++)
		{
			p = p_home_updata_item[i];
			 if(p->now_status!=p->last_status)
			 {
				 f_upgrate = TRUE;
				 p->last_status=p->now_status;
				 
				 
				 if((dis_page_item!=PAGE_INIT)&&(now_in_dialog_or_keyboard_window()==FALSE))
				 {

				 if(p->now_status==STATUS_SELECT)
				 png_dis_xy(p->x_val,p->y_val,p->pic_item_select,p->size_of_pic_item_select,Virtual_LCDbuff1);
				 else	if(p->now_status==STATUS_IDLE)	
					png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);	
				 }			 
				 
			 } 
	  }

			for(i=0;i<6;i++)
			{
					p = p_home_lights_item_d[i];
					
				 if(p->now_status!=p->last_status)
				 {
					 f_upgrate = TRUE;
					 p->last_status=p->now_status;
					 
					 if((dis_page_item!=PAGE_INIT)&&(now_in_dialog_or_keyboard_window()==FALSE))
					 {
					 if(p->now_status==STATUS_SELECT)
					 png_dis_xy(p->x_val,p->y_val,p->pic_item_select,p->size_of_pic_item_select,Virtual_LCDbuff1);
					 else	if(p->now_status==STATUS_IDLE)	
						png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);			
					 }			 
					 
				 }
			 }

			for(i=0;i<6;i++)
			{
					p = p_home_loads_item_d[i];
					
				 if(p->now_status!=p->last_status)
				 {
					 f_upgrate = TRUE;
					 p->last_status=p->now_status;
					 
					 if((dis_page_item!=PAGE_INIT)&&(now_in_dialog_or_keyboard_window()==FALSE))
					 {
					 if(p->now_status==STATUS_SELECT)
					 png_dis_xy(p->x_val,p->y_val,p->pic_item_select,p->size_of_pic_item_select,Virtual_LCDbuff1);
					 else	if(p->now_status==STATUS_IDLE)	
						png_dis_xy(p->x_val,p->y_val,p->pic_item,p->size_of_pic_item,Virtual_LCDbuff1);			
					 }			 
					 
				 }
			 }
			 

    //f_upgrate = FALSE;
	  }
		
		if(switch_ctrl_byte[4]&0x40)
	 {

		 //tanks_set_item[5].now_status=STATUS_SELECT;
		 //tanks_set_item[5].last_status=STATUS_SELECT;

	 }
	 else
	 {

	   //tanks_set_item[5].now_status=STATUS_IDLE;
		 //tanks_set_item[5].last_status=STATUS_IDLE;

	 }
		

		
	
	
	
	//那些需要刷新页面////////////////////////////////////////////
	if(now_in_dialog_or_keyboard_window()==FALSE)
	{
		//sysprintf("\r\n888888888888888old_switch_ctrl_byte:,%X,%X,%X,%X",old_switch_ctrl_byte[2],switch_ctrl_byte[2],old_switch_ctrl_byte[3],switch_ctrl_byte[3]);
  if((old_switch_ctrl_byte[2]!=switch_ctrl_byte[2])||((old_switch_ctrl_byte[3]&0xC0)!=(switch_ctrl_byte[3]&0xC0))/*||(old_f_load9_on!=f_load9_on)||(old_f_load10_on!=f_load10_on)*/)
	{
	
	     if((p1->now_item==LEFT_SIDE_PAGE_LOADS)&&(now_in_dialog_or_keyboard_window()==FALSE))
			 {
				 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
				// sysprintf("\r\n888888888888888");
			 
			 }
	
	
	
	}
	
	if((old_switch_ctrl_byte[0]!=switch_ctrl_byte[0])||(old_switch_ctrl_byte[1]!=switch_ctrl_byte[1])/*||(old_f_load9_on!=f_load9_on)||(old_f_load10_on!=f_load10_on)*/)
	{
	
	     if((p1->now_item==LEFT_SIDE_PAGE_LIGHTS)&&(now_in_dialog_or_keyboard_window()==FALSE))
			 {
				 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
				 //sysprintf("\r\n888888888888881");
			 
			 }
	
	
	
	}
	
	//loads off  lights_off
	//if(((old_switch_ctrl_byte[4]&0x88)!=(switch_ctrl_byte[4]&0x88))||\
	//	((old_switch_ctrl_byte[1]&0x01)!=(switch_ctrl_byte[1]&0x01))||\
	//  ((old_switch_ctrl_byte[3]&0x01)!=(switch_ctrl_byte[3]&0x01)))
	if(f_upgrate)
	{
	   if(dis_page_item!=PAGE_INIT)
		{
	     if(p1->now_item==LEFT_SIDE_PAGE_HOME)
			 {
				 if(now_in_dialog_or_keyboard_window()==FALSE)
				 {
					 f_upgrate = TRUE;
						//Virtual_LCD_Upgrate();
					 //全部更新速度太慢
					 //p1->last_item=LEFT_SIDE_PAGE_UPDATA;
					 
					 
					 disply_light_name(TRUE);
			     disply_load_name(TRUE);
					 
					 p = &t_home_inverter_d;
					 Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
					 
					 p = &t_home_lightsoff_d;
					 Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
					 
					 p = &t_home_loadoff_d;
					 Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
					 
					 p = &t_home_powerS_d;
					 Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
					 
					 p = &t_home_wpON_d;
					 Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
					 
					 p = &t_home_loadlights_bg;
					 Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
					 
					 p = &t_home_loads_bg;
					 Virtual_LCD_Upgrate_formx1y1(p->x_val,p->y_val,p->x_end_val-p->x_val,p->y_end_val-p->y_val);
					 
					 

				 }
			 
			 }
		 }
	
	
	
	}
	if((old_switch_ctrl_byte[4]&0x08)!=(switch_ctrl_byte[4]&0x08))
	{
	
	     if(p1->now_item==LEFT_SIDE_PAGE_POWER)
			 {
			    //Virtual_LCD_Upgrate();
				 if(now_in_dialog_or_keyboard_window()==FALSE)
				 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
			 
			 }
	
	}
	if((old_switch_ctrl_byte[2]&0x40)!=(switch_ctrl_byte[2]&0x40))
	{
	
	     if((p1->now_item==LEFT_SIDE_PAGE_TANKS)&&((p2->now_item == TOP_SIDE_PAGE_TANKS_TANKS)))
			 {
			    //Virtual_LCD_Upgrate();
				 if(now_in_dialog_or_keyboard_window()==FALSE)
				 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
			 
			 }
	
	}
	if((old_switch_ctrl_byte[4]&0x40)!=(switch_ctrl_byte[4]&0x40))
	{
	
	     if((p1->now_item==LEFT_SIDE_PAGE_TANKS)&&((p2->now_item == TOP_SIDE_PAGE_TANKS_SETUP)))
			 {
			    //Virtual_LCD_Upgrate();
				 if(now_in_dialog_or_keyboard_window()==FALSE)
				 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
			 
			 }
	
	
	
	}
	
	#if 0
	//lights_off
	if(((switch_ctrl_byte[0]&0xF0)||(switch_ctrl_byte[1]&0x7E)))//所有灯灭时，不执行
	{
		
		 home_item[2].key_type = KEY_TYPE_NORMAL;
		/* home_item[2].now_status=STATUS_SELECT;
		 if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
			home_item[2].last_status=STATUS_SELECT;*/

	}
	else 
	{
	   if(home_item[2].now_status==STATUS_SELECT)
		 {
		   home_item[2].key_type = KEY_TYPE_TOUCH_NONE;
			 home_item[2].now_status = STATUS_IDLE;
		   if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
		    home_item[2].last_status=STATUS_IDLE;

		 }
		 else
		 {
			//home_item[2].key_type = KEY_TYPE_NORMAL; 
			// home_item[2].pic_item_select =t_home_lightsoff_d.pic_item;//
     // home_item[2].size_of_pic_item_select= t_home_lightsoff_d.size_of_pic_item ;
		 }
	}
	//loads_off
	if(((switch_ctrl_byte[2]&0xFF)||(switch_ctrl_byte[3]&0xC0)))//所有load关时，不执行
	{
		home_item[4].key_type = KEY_TYPE_NORMAL;
		home_item[4].now_status=STATUS_SELECT;
		if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
			home_item[4].last_status=STATUS_SELECT;
	}
	else 
	{
	   if(home_item[4].now_status==STATUS_SELECT)
		 {
		    home_item[4].key_type = KEY_TYPE_TOUCH_NONE;
				home_item[4].now_status=STATUS_IDLE;
				if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
				  home_item[4].last_status=STATUS_IDLE;
		 }
		 //if(p1->now_item!=LEFT_SIDE_PAGE_HOME)
		//	home_item[4].last_status=STATUS_SELECT;
	}	
		#endif
	set_home_off_item_key_type();
	//pumps_off
	/*temp2 = 0;

	for(i=0;i<MAX_LOADS_DIAPLAY_NUM;i++)
	{
	  if(switch_name_list_return[loads_display_loads_ch[i]].icon_select==7)
			temp2|=((u16)1)<<(15-i);
			
	}
	if((switch_ctrl_byte[2]&((u8)(temp2>>8)))||(switch_ctrl_byte[3]&((u8)(temp2))))//所有pumps关时，不执行
	{
		//home_item[11].key_type = KEY_TYPE_NORMAL;
		tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_NORMAL;
	}
	else 
	{
	   //if(home_item[11].now_status==STATUS_SELECT)
		  if(tanks_item[ICO_tanks_wp].now_status==STATUS_IDLE)
		 {
		  // home_item[11].key_type = KEY_TYPE_TOUCH_NONE;
			 tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_TOUCH_NONE;
		 }
	}	
	*/
}
  //copy to old data
 
 old_switch_ctrl_byte[0]=switch_ctrl_byte[0];
 old_switch_ctrl_byte[1]=switch_ctrl_byte[1];
 old_switch_ctrl_byte[2]=switch_ctrl_byte[2];
 old_switch_ctrl_byte[3]=switch_ctrl_byte[3];
 old_switch_ctrl_byte[4]=switch_ctrl_byte[4];
 
 
 old_pwm_ctrl_byte[0]=pwm_ctrl_byte[0];
 old_pwm_ctrl_byte[1]=pwm_ctrl_byte[1];
 old_pwm_ctrl_byte[2]=pwm_ctrl_byte[2];
 old_pwm_ctrl_byte[3]=pwm_ctrl_byte[3];

 
// old_f_load9_on = f_load9_on;
// old_f_load10_on = f_load10_on;

	return f_upgrate;
}










void FlC200_hc_comm_switch_pro(u8* para)
{
	//lcd_dis_page_t *p;
	//bool f_upgrate = FALSE;
	static bool old_f_override_key = FALSE;
	switch_ctrl_byte[0] = para[0];
	switch_ctrl_byte[1] = para[1];
	switch_ctrl_byte[2] = para[2];
	switch_ctrl_byte[3] = para[3];
	switch_ctrl_byte[4] = para[4];
	pwm_ctrl_byte[0] = para[5];
	pwm_ctrl_byte[1] = para[6];
	pwm_ctrl_byte[2] = para[7];
	pwm_ctrl_byte[3] = para[8];
	pwm_ctrl_byte[4] = para[9];
	pwm_ctrl_byte[5] = para[10];
	pwm_ctrl_byte[6] = para[11];
	pwm_ctrl_byte[7] = para[12];
	pwm_ctrl_byte[8] = para[13];
	pwm_ctrl_byte[9] = para[14];

	
	if(switch_ctrl_byte[4]&0x01)
		f_ble_connect_on = TRUE;
	else
		f_ble_connect_on = FALSE;
	if(switch_ctrl_byte[4]&0x02)
		f_ble_have = TRUE;
	else
		f_ble_have = FALSE;
	if(switch_ctrl_byte[4]&0x20)
		f_override_key = TRUE;
	else
		f_override_key = FALSE;
	if(old_f_override_key!=f_override_key)
	{
	   old_f_override_key=f_override_key;
		 if(f_override_key)
		 {
		   f_ui_need_disply_dialog_msg= TRUE;
			 v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_OVERRIDE_KEY;
		 }
		 else
		 {
		   f_ui_need_disply_dialog_msg= TRUE;
			 v_ui_disply_dialog_msg_type = DIALOG_MSG_TYPE_OVERRIDE_KEY;
		 }
		 //2025-01-18
    //set_home_loads_item_key_type();
	  //set_lights_item_key_type(KEY_TYPE_NORMAL);	
	  //set_home_lights_item_key_type();	
	  //set_loads_item_key_type(KEY_TYPE_NORMAL);	
	  //set_loads_motors_item_key_type(KEY_TYPE_NORMAL);	
		//set_tanks_item_key_type();
		//set_home_off_item_key_type();
	
	}
		
	
	
	//f_upgrate = 
	//set_switch_icon_status(); 2025-01-18
	/*p = &page_home.page_left_side;
	if(p->now_item==LEFT_SIDE_PAGE_HOME)
	{
		if((f_ui_disply_dialog_code==FALSE)&&(f_ui_disply_dialog_info==FALSE))
		{
			disply_light_name(TRUE);
			disply_load_name(TRUE);
			if(f_upgrate)
			{
			 //page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;//目的是刷新页面
				Virtual_LCD_Upgrate();
			}
	 }
	}*/
	

}
void FlC200_hc_comm_switch_ch_pro(u8* para)
{
	 u8 i;
	 switch_ch_select_num_max = para[0];
	 for(i=0;i<SWITCH_NAME_CH_NUM;i++)
	{
	   switch_ch_list_return[i] = para[i+1];
	
	
	}
	if(f_lights_b_setup_d==FALSE)
	 set_lights_item_key_type(KEY_TYPE_NORMAL);
	
	set_home_lights_item_key_type();
	
	if(f_loads_b_setup_d==FALSE)
	 set_loads_item_key_type(KEY_TYPE_NORMAL);
	
	set_loads_motors_item_key_type(KEY_TYPE_NORMAL);
	
	set_home_loads_item_key_type();
	set_tanks_item_key_type();
	
	if((page_home.page_left_side.now_item==LEFT_SIDE_PAGE_LIGHTS)&&(page_home.page_left_side.last_item != LEFT_SIDE_PAGE_UPDATA))
	{
					 
			if(now_in_dialog_or_keyboard_window()==FALSE)
			{

				//disply_lights_light_ch_name(FALSE);
				page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;
			}
	}
	if((page_home.page_left_side.now_item==LEFT_SIDE_PAGE_LOADS)&&(page_home.page_left_side.last_item != LEFT_SIDE_PAGE_UPDATA))
	{
					 
			if(now_in_dialog_or_keyboard_window()==FALSE)
			{

				//disply_loads_load_ch_name(FALSE);
				page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;
			}
	}
	if((page_home.page_left_side.now_item==LEFT_SIDE_PAGE_HOME)&&(page_home.page_left_side.last_item != LEFT_SIDE_PAGE_UPDATA))
	{
					 
			if(now_in_dialog_or_keyboard_window()==FALSE)
			{

				//disply_loads_load_ch_name(FALSE);
				page_home.page_left_side.last_item = LEFT_SIDE_PAGE_UPDATA;
			}
	}
	/*
	if((switch_ch_list_return[6]==0)||(switch_ch_list_return[6]>24))
	{
		tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_TOUCH_NONE;
		t_tanks_wpON_d.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
		home_item[11].key_type = KEY_TYPE_TOUCH_NONE;
		t_home_wpON_d.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
	}
	else
	{
		 tanks_item[ICO_tanks_wp].key_type = KEY_TYPE_NORMAL;
		 t_tanks_wpON_d.key_type = KEY_TYPE_NORMAL;//防止初始化前收到了这个指令
		 home_item[11].key_type = KEY_TYPE_NORMAL;
		 t_home_wpON_d.key_type = KEY_TYPE_NORMAL;//防止初始化前收到了这个指令
	}
  if((switch_ch_list_return[7]==0)||(switch_ch_list_return[7]>24))
	{
		tanks_item[ICO_tanks_wp+1].key_type = KEY_TYPE_TOUCH_NONE;
		t_tanks_heat_ON.key_type = KEY_TYPE_TOUCH_NONE;//防止初始化前收到了这个指令
	}
	else
	{
		 tanks_item[ICO_tanks_wp+1].key_type = KEY_TYPE_NORMAL;
		 t_tanks_heat_ON.key_type = KEY_TYPE_NORMAL;//防止初始化前收到了这个指令
	}
			 
	*/
}
void FlC200_hc_comm_External_key_type_pro(u8* para)  
{
	 External_key_type_return = 	(((u32)para[0])<<24)+(((u32)para[1])<<16)+(((u32)para[2])<<8)+(((u32)para[3])<<0);
	 External_key_type = External_key_type_return;
		if(para[4]&0x01)  //旧手刹D4 b0
		 f_ignore_handbreak = TRUE;
	else
	   f_ignore_handbreak = FALSE;
    
	 
}
void FlC200_hc_comm_ch_current_pro(u8* para)
{
	 u8 i;
	 for(i=0;i<SWITCH_NAME_CH_NUM;i++)
	{
	   current_val[i] = para[2*i]*256+para[2*i+1];
	}	
}

void FlC200_hc_comm_switch_name(u8 *pbuf)
{
   u8 ch,len,i;
	lcd_dis_page_t *p1;
     ch = pbuf[0]; 
		if(switch_name_list_return[ch].icon_select!=pbuf[1])  //是否需要更新 2023-04-26
		{
			 switch_name_list_return[ch].icon_select = pbuf[1];
			
			
			 p1 = &page_home.page_left_side;
			 if(ch<=0x0F)
			{
				 get_lights_item_now_status();
		     get_home_lights_item_now_status();
			   ui_lights_init();
				 Upgrade_home_item();
				 set_lights_item_now_status(); 
				 set_home_lights_item_now_status();		

				 if((p1->now_item==LEFT_SIDE_PAGE_LIGHTS)&&(now_in_dialog_or_keyboard_window()==FALSE))
				 {
						//Virtual_LCD_Upgrate();
					 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
				 
				 }
				 else if(p1->now_item==LEFT_SIDE_PAGE_HOME)
				 {
						//Virtual_LCD_Upgrate();
					 if(ch<=0x0A)
					 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
				 
				 }				
					
			}
			else if((ch>=0x10)&&(ch<=0x19))
			{
				 get_loads_item_now_status();
		     get_home_loads_item_now_status();
			   ui_loads_init();
				 Upgrade_load_item();
				 set_loads_item_now_status(); 
				 set_home_loads_item_now_status();		
					  if((p1->now_item==LEFT_SIDE_PAGE_LOADS)&&(now_in_dialog_or_keyboard_window()==FALSE))
					 {
							//Virtual_LCD_Upgrate();
						 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
					 
					 }
					 else if(p1->now_item==LEFT_SIDE_PAGE_HOME)
					 {
							//Virtual_LCD_Upgrate();
						 if((ch>=0x10)&&(ch<=0x15))
						 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
					 
					 }
				
			}
			else if((ch>=0x1A)&&(ch<=0x1E))
			{
				 //get_loads_item_now_status();
		     //get_home_loads_item_now_status();
			   ui_loads_motors_init();
				 //Upgrade_load_item();
				 //set_loads_item_now_status(); 
				 //set_home_loads_item_now_status();		
					  if((p1->now_item==LEFT_SIDE_PAGE_LOADS)&&(now_in_dialog_or_keyboard_window()==FALSE))
					 {
							//Virtual_LCD_Upgrate();
						 p1->last_item=LEFT_SIDE_PAGE_UPDATA;
					 
					 }

				
			}
			
			  
		
			 
		}
	
   len = pbuf[2];
   
   if(len!=0)
   {
		 if(len>16)
			 len=16;
		 
     switch_name_list_return[ch].txt_len = len;
     for(i=0;i<len;i++)
     {   
       switch_name_list_return[ch].txt[i]=pbuf[3+i];
     }
		 if(len == 16)
		 switch_name_list_return[ch].txt[len-1] = '\0';
   }
}





bool  Is_Inverter_mode_Inverting(void)
{ 
   	switch(Inverter_status.mode)
		{
			case 4:
				//sprintf(display_buf,"Inverting");
			case 7:
			case 0x11:
        //sprintf(display_buf,"Inverting");
			case 0x13:
      case 0x24:
				//sprintf(display_buf,"Invert Full");
      case 0x25:
				//sprintf(display_buf,"Invert Half");
      case 0x26:
				//sprintf(display_buf,"Invert AES");
			return TRUE;
				//break;
      
			default:
				return FALSE;
				//break;
		}
 
}
bool  Is_Inverter_mode_AC_IN(void)
{ 
   		switch(Inverter_status.mode)
		{

			case 0x10:
				//sprintf(display_buf,"Bypass");
			case 0x12:
				//sprintf(display_buf,"Charging");
      case 0x28:
				//sprintf(display_buf,"Bypass");
      case 0x29:
				//sprintf(display_buf,"Charge");
			case 0x30:
				//sprintf(display_buf,"Initializing");
			case 0x31:
				//sprintf(display_buf,"Bulk");
			case 0x32:
				//sprintf(display_buf,"Absorption");
			case 0x33:
				//sprintf(display_buf,"Float");
			case 0x34:
				//sprintf(display_buf,"Storage");
			case 0x35:
				//sprintf(display_buf,"Repeated Absorption");
			case 0x36:
				//sprintf(display_buf,"Forced Absorption");
			case 0x37:
				//sprintf(display_buf,"Equalise");
			case 0x38:
				//sprintf(display_buf,"Bulk stopped");
			  return TRUE;
				//break;
			default:
				return FALSE;
				//break;
		}
 
}	

void FlC200_hc_comm_inverter_pro(u8* para)
{	
  Inverter_status.V_dc = para[0]*256+para[1];   
	Inverter_status.V_220 = para[2]*256+para[3];  
  Inverter_status.V_o = para[4]*256+para[5];    //输出电压
  Inverter_status.I_dc = para[6]*256+para[7];   //直流电流
  Inverter_status.I_220 = para[8]*256+para[9];  //市电电流
  Inverter_status.I_o = para[10]*256+para[11];  //
	Inverter_status.MAX_temp = para[12];          //
	Inverter_status.mode = para[13];              //
  Inverter_status.P_dc = para[14]*256+para[15]; //
	Inverter_status.P_220 = para[16]*256+para[17];//
  Inverter_status.P_o = para[18]*256+para[19];  //
	Inverter_status.F_220 = para[20];             //
	Inverter_status.F_o	  = para[21];             //
}

void FlC200_hc_comm_battery_pro(u8* para)
{	
	if(para[0]==0)
	{
	  main_battery_status.V = para[1]*256+para[2];
		main_battery_status.I = para[3]*256+para[4];
		main_battery_status.Q = para[5];
		main_battery_status.MAX_temp = para[6];
	}
	else if(para[0]==1)
	{
	  assi1_battery_status.V = para[1]*256+para[2];
		assi1_battery_status.I = para[3]*256+para[4];
		assi1_battery_status.Q = para[5];
		assi1_battery_status.MAX_temp = para[6];
		if(para[7]&0x02)			
		assi1_battery_status.f_time_changer = TRUE;
		else
		assi1_battery_status.f_time_changer = FALSE;
		
		assi1_battery_status.time = para[8]*256+para[9];
	}
	else if(para[0]==2)
	{
	  assi2_battery_status.V = para[1]*256+para[2];
		assi2_battery_status.I = para[3]*256+para[4];
		assi2_battery_status.Q = para[5];
		assi2_battery_status.MAX_temp = para[6];
	}

}

void FlC200_hc_comm_charger_pro(u8* para)
{	
	if(para[0]==0)
	{
	  Fully_Charger.V_in = para[1]*256+para[2];
		Fully_Charger.I_in = para[3]*256+para[4];
		Fully_Charger.Power = para[5]*256+para[6];
		Fully_Charger.time = para[7]*256+para[8];
	}
	else if(para[0]==1)
	{
	  Booster_Charger.V_in = para[1]*256+para[2];
		Booster_Charger.I_in = para[3]*256+para[4];
		Booster_Charger.Power = para[5]*256+para[6];
		Booster_Charger.time = para[7]*256+para[8];
	}
	else if(para[0]==2)
	{
	  Solar_Charger.V_in = para[1]*256+para[2];
		Solar_Charger.I_in = para[3]*256+para[4];
		Solar_Charger.Power = para[5]*256+para[6];
		Solar_Charger.time = para[7]*256+para[8];
	}
	else if(para[0]==3)
	{
	  Combi_CHG.V_in = para[1]*256+para[2];
		Combi_CHG.I_in = para[3]*256+para[4];
		Combi_CHG.Power = para[5]*256+para[6];
		Combi_CHG.time = para[7]*256+para[8];
	}
	else if(para[0]==4)
	{
	  ACin_charger.V_in = para[1]*256+para[2];
		ACin_charger.I_in = para[3]*256+para[4];
		ACin_charger.Power = para[5]*256+para[6];
		ACin_charger.time = para[7]*256+para[8];
	}
	else if(para[0]==5)
	{
	  ACout_charger.V_in = para[1]*256+para[2];
		ACout_charger.I_in = para[3]*256+para[4];
		ACout_charger.Power = para[5]*256+para[6];
		ACout_charger.time = para[7]*256+para[8];
	}

}
void FlC200_hc_comm_solar_pro(u8* para)
{	
	solar_status.V_in = para[0]*256+para[1];
  solar_status.I_in = para[2]*256+para[3];
  solar_status.V_batt = para[4]*256+para[5];
  solar_status.I_batt = para[6]*256+para[7];
  solar_status.V_load = para[8]*256+para[9];
  solar_status.I_load = para[10]*256+para[11];
	solar_status.Power = para[12]*256+para[13];
}

void FlC200_hc_comm_val_pro(u8* para)
{	
	val_status.val_tank1 = para[0];
  val_status.val_tank2 = para[1];
  val_status.val_tank3 = para[2];
  val_status.val_tank4 = para[3];
}

void FlC200_hc_comm_temp_pro(u8* para)
{	
	u16 temp;
	temp = para[0]*256+para[1];
	if(temp<65530)
	{
		if((temp%10)>=5)
			temp = (temp/10)*10 +10;
		else
			temp = (temp/10)*10;
  }
	temp_status.Temp_in= temp;
	
	temp = para[2]*256+para[3];
	if(temp<65530)
	{
		if((temp%10)>=5)
			temp = (temp/10)*10 +10;
		else
			temp = (temp/10)*10;
 }
  temp_status.Humidness_in= temp;
	
	temp = para[4]*256+para[5];
 if(temp<65530)
 {
	if((temp%10)>=5)
		temp = (temp/10)*10 +10;
	else
		temp = (temp/10)*10;
 }
  temp_status.Temp_out = temp;
	
	temp = para[6]*256+para[7];
 if(temp<65530)
	{
	if((temp%10)>=5)
		temp = (temp/10)*10 +10;
	else
		temp = (temp/10)*10;
 }
  temp_status.Humidness_out= temp;
}


void FlC200_hc_comm_warning_code_pro(u8* para)
{	

	//static u8 last_power_waining_code_list_num = 0;
	u8 waining_code_now_num = 0;
	//u8 power_waining_code_now_num = 0;
	u8 i;
	waining_code_list_num= para[0];
  waining_code_now_num= para[1];
  waining_code_list[waining_code_now_num].time_happen.year= para[2];
  waining_code_list[waining_code_now_num].time_happen.mon= para[3];
  waining_code_list[waining_code_now_num].time_happen.day= para[4];
  waining_code_list[waining_code_now_num].time_happen.hour= para[5];
  waining_code_list[waining_code_now_num].time_happen.min= para[6];
  waining_code_list[waining_code_now_num].time_happen.sec= para[7];
  waining_code_list[waining_code_now_num].err_code_from= para[8];
  waining_code_list[waining_code_now_num].err_code_type= para[9];
	waining_code_list[waining_code_now_num].time_cnt= para[10];
  waining_code_list[waining_code_now_num].txt_len = para[11];
	
  
	
  if(para[11]!=0)
  {
     for(i=0;i<para[11];i++)
       waining_code_list[waining_code_now_num].txt[i] = para[12+i];
  }
	sysprintf("\r\n last_waining_code_list_num %d,waining_code_list_num %d,waining_code_now_num%d",last_waining_code_list_num,waining_code_list_num,waining_code_now_num);
	if(last_waining_code_list_num!=waining_code_list_num)
	{
		if(waining_code_now_num == (waining_code_list_num))
		{
			if(waining_code_list_num>last_waining_code_list_num)
			{
				if(waining_code_list[waining_code_now_num].time_cnt<=10)
			  {
					if(f_ui_disply_dialog_info==FALSE)	
					{
						if(f_ui_init_finsh)
						{
							 ui_disply_dialog_code();
							//sysprintf("\r\n000000000000000000000000000");
						}
						else
						{
							f_ui_need_disply_dialog_code=TRUE;
						}
					}
				}
				else
				{
					 f_fault_flash = TRUE;
				}
		  }
			
		last_waining_code_list_num = waining_code_list_num;	
		}
		
	}
}


void FlC200_hc_comm_battery_set_return_pro(u8* para)
{	
	if(para[0]==0)
	{
	  main_battery_set_return_status.V_warning_L = para[1]*256+para[2];
		main_battery_set_return_status.V_warning_H = para[3]*256+para[4];
		main_battery_set_return_status.V_SOC_warning_L= para[5]*256+para[6];
	}
	else if(para[0]==1)
	{
	  assi1_battery_set_return_status.V_warning_L = para[1]*256+para[2];
		assi1_battery_set_return_status.V_warning_H = para[3]*256+para[4];
		assi1_battery_set_return_status.V_SOC_warning_L= para[5]*256+para[6];
	}
	else if(para[0]==2)
	{
	  assi2_battery_set_return_status.V_warning_L = para[1]*256+para[2];
		assi2_battery_set_return_status.V_warning_H = para[3]*256+para[4];
		assi2_battery_set_return_status.V_SOC_warning_L= para[5]*256+para[6];
	}

}


void FlC200_hc_comm_tank_set_return_pro(u8* para)
{	
  TANK_SET_STATUS* Tank_set_return_status_p;
	switch(para[0])
	{
			  case 1:
					Tank_set_return_status_p = &Tank1_set_return_status;
					break;
				case 2:
					Tank_set_return_status_p = &Tank2_set_return_status;
					break;
				case 3:
					Tank_set_return_status_p = &Tank3_set_return_status;
					break;
				case 4:
					Tank_set_return_status_p = &Tank4_set_return_status;
					break;
				default:
					return;	
	}

		
	Tank_set_return_status_p->Tank_type =para[1];
	Tank_set_return_status_p->Tank_sensor_type =para[2];
	Tank_set_return_status_p->val_max =para[3]*256+para[4];
	Tank_set_return_status_p->val_warning_H_or_Low_Alarm =para[5]*256+para[6];
	Tank_set_return_status_p->val_alarm_H =para[7]*256+para[8];
	Tank_set_return_status_p->val_protect_L =para[9]*256+para[10];
	Tank_set_return_status_p->temp_auto_heat_begin =para[11];
	Tank_set_return_status_p->temp_auto_heat_stop =para[12];

}
void FlC200_hc_comm_fresh_set_return_pro(u8* para)
{	
  
	fresh_set_return_status.val_max= para[0]*256+para[1];
	fresh_set_return_status.val_warning_L= para[2]*256+para[3];
	fresh_set_return_status.val_warning_H= para[4]*256+para[5];
	fresh_set_return_status.val_protect= para[6]*256+para[7];
}


void FlC200_hc_comm_black_set_return_pro(u8* para)
{	
  
	back_set_return_status.val_max= para[0]*256+para[1];
	back_set_return_status.val_warning_H= para[2]*256+para[3];
	back_set_return_status.val_alarm_H= para[4]*256+para[5];
	back_set_return_status.temp_auto_heat_begin= para[6];
	back_set_return_status.temp_auto_heat_stop= para[7];
}




void FlC200_hc_comm_grey_set_return_pro(u8* para)
{	
  
	grey_set_return_status.val_max= para[0]*256+para[1];
	grey_set_return_status.val_warning_H= para[2]*256+para[3];
	grey_set_return_status.val_alarm_H= para[4]*256+para[5];

}
void FlC200_hc_comm_LPG_set_return_pro(u8* para)
{	
  
	LPG_set_return_status.val_max= para[0]*256+para[1];
	LPG_set_return_status.val_warning_L= para[2]*256+para[3];
	LPG_set_return_status.val_warning_H= para[4]*256+para[5];
	//fresh_set_return_status.val_protect= para[6]*256+para[7];
}

void FlC200_hc_comm_bat_set_return_pro(u8* para)
{	
  
	parts_set_return_status.Capacity= para[0]*256+para[1];
	parts_set_return_status.Percentage= para[2];
	parts_set_return_status.temp_sensor_type = para[3]&0x0F;
	parts_set_return_status.tanks_sensor_type = (para[3]>>4)&0x0F;
	/*if(parts_set_return_status.tanks_sensor_type==1)
	{
	  Tank1_set_return_status.Tank_sensor_type = 1;
		Tank2_set_return_status.Tank_sensor_type = 1;
		Tank3_set_return_status.Tank_sensor_type = 1;
		Tank4_set_return_status.Tank_sensor_type = 1;
		
	}
	else
	{
	  Tank1_set_return_status.Tank_sensor_type = 0;
		Tank2_set_return_status.Tank_sensor_type = 0;
		Tank3_set_return_status.Tank_sensor_type = 0;
		Tank4_set_return_status.Tank_sensor_type = 0;
	}*/
	parts_set_return_status.Inverter_Mode = para[4]&0x0F;
	if(parts_set_return_status.Inverter_Mode>=4)
	{
		parts_set_return_status.Inverter_Mode = 0x0F;
	}
	parts_set_status.Inverter_Mode = parts_set_return_status.Inverter_Mode;
  parts_set_return_status.Inverter_Input_Current_Limit = para[5]*256+para[6];
	parts_set_return_status.Inverter_Alarm_setup1 = para[7]*256+para[8];
	parts_set_return_status.Inverter_Alarm_setup2 = para[9]*256+para[10];
	type_sel.Battery_SmartShun_Type=para[11];
	type_sel.Inverter_Type=para[12];
	type_sel.Mppt_Type=para[13];
	type_sel.DC_Changer_Type=para[14];
	
}
void FlC200_hc_comm_time_set_return(u8 *para)//反馈设置时间
{   
  time_return_status.year = para[0];
  time_return_status.mon = para[1];
  time_return_status.day = para[2];
  time_return_status.hour = para[3];
  time_return_status.min = para[4];
  time_return_status.sec = para[5];
	time_return_status.format = para[6];
    
    if(0)
    {
        sysprintf("Time Return:\r\n");
        sysprintf("  year   = %d\r\n", time_return_status.year);
        sysprintf("  mon    = %d\r\n", time_return_status.mon);
        sysprintf("  day    = %d\r\n", time_return_status.day);
        sysprintf("  hour   = %d\r\n", time_return_status.hour);
        sysprintf("  min    = %d\r\n", time_return_status.min);
        sysprintf("  sec    = %d\r\n", time_return_status.sec);
        sysprintf("  format = %d\r\n", time_return_status.format&0x80);
    }
}
void FlC200_hc_comm_base_set_return(u8 *para)
{   
  base_return_status.uint = para[0];//温度单位
  base_return_status.language = para[1];
	base_return_status.light = para[2];
	base_return_status.R = para[3];
	base_return_status.G = para[4];
	base_return_status.B = para[5];
	base_return_status.sleep_time = para[6];
	base_return_status.touch_tone = para[7];
    
    if (0)
    {
        sysprintf("Base Return:\r\n");
        sysprintf("  uint        = %d\r\n", base_return_status.uint);        // 温度单位
        sysprintf("  language    = %d\r\n", base_return_status.language);    // 语言
        sysprintf("  light       = %d\r\n", base_return_status.light);       // 亮度
        sysprintf("  R           = %d\r\n", base_return_status.R);           // 红
        sysprintf("  G           = %d\r\n", base_return_status.G);           // 绿
        sysprintf("  B           = %d\r\n", base_return_status.B);           // 蓝
        sysprintf("  sleep_time  = %d\r\n", base_return_status.sleep_time);  // 休眠时间
        sysprintf("  touch_tone  = %d\r\n", base_return_status.touch_tone);  // 触摸音
    }

}

//应答集
#define  ACKOK 0x00
#define  ACKNext 0x81
#define  ACKLDErr 0x3
#define  ACKLDOver 0xa
#define  ACKBaudOK 0x8
#define  ACKIAP 0xe

#define ACKERR_OBER 0xf0 //OB擦除失败
#define ACKERR_INFOER 0xf1 //信息区擦除失败
#define  ACKERR_PW 0x0D //口令出错
#define  ACKERR_LOAD 0x3 //烧录出错
#define  ACKERR_CRC 0x0C //CRC出错
#define  ACKERR_OVVOL 0x02 //超出容量
#define  ACKERR_KEY 0x0F //私钥错误
#define  ACKERR_SHIFT 0x0B //无法切换 固定码错误或波特率错误

#define  ACKERR_NOSPIFLASH 0x05 //无spi flash
#define  ACK_SPIFLASH 0x04 //切换至spi flash
void FlC200_hc_comm_info_return(u8 *para)
{   
	u8 i;//,temp;
	if(para[0]==1)
	{
     switch(para[1])
		 {
		   case 0:
				 sprintf(upgrade_info1,"BOOT: Please Input USB Disk.");
				 break;
			 case 2:
				 sprintf(upgrade_info1,"BOOT: No Boot File Found.");
				 func_set_upgrade_close_key_type(KEY_TYPE_TOUCH_NONE);
			   set_dialog_info_close_key_type(KEY_TYPE_TOUCH_NONE);
				 break;
		  case 7:
				 sprintf(upgrade_info1,"BOOT: Now Status:%d%%.",para[5]);			
         set_dialog_info_close_key_type(KEY_TYPE_TOUCH_NONE);
				 func_set_upgrade_close_key_type(KEY_TYPE_TOUCH_NONE);
				 break;
		  case 8:
				 sprintf(upgrade_info1,"BOOT: Timeout Waiting for Flash.");
				 break;
			case 9:
				 sprintf(upgrade_info1,"BOOT: Checking data...");
				 break;
			case 0x10:
				 sprintf(upgrade_info1,"BOOT: CRC Err.");
				 break;
		  case 0x12:
				 sprintf(upgrade_info1,"BOOT: Update Successfully.");
				 break;
		 }
	}
	else if(para[0]==2)
	{
     switch(para[1])
		 {
		   case 1:
				 sprintf(upgrade_info2,"UI:Waiting For Upgrade.");
				 break;
			 case 2:
				 sprintf(upgrade_info2,"UI: No Boot File Found.");
				 break;
			 case 3:
				 sprintf(upgrade_info2,"UI: Reading File...");
				 break;
		  case 7:
				sprintf(upgrade_info2,"UI: Now Status:%d%%.",para[5]);
				 break;
		  case 8:
				 sprintf(upgrade_info2,"UI:Timeout Waiting for Flash.");
				 break;
			case 9:
				 sprintf(upgrade_info2,"UI: Checking data...");
				 break;
			case 0x10:
				 sprintf(upgrade_info2,"UI: CRC Err.");
				 break;
		  case 0x12:
				 sprintf(upgrade_info2,"UI: Update Successfully.");
				 break;
		 }
	}
	else if(para[0]==3)
	{
     switch(para[1])
		 {
		   case 1:
				 sprintf(upgrade_info3,"MCU: Waiting For Upgrade.");
				 break;
			 case 2:
				 sprintf(upgrade_info3,"MCU:No MCU File,Close This Window To Restart");
			   set_dialog_info_close_key_type(KEY_TYPE_ONCE);
			  func_set_upgrade_close_key_type(KEY_TYPE_ONCE);
				 break;
		  case 7:
				 sprintf(upgrade_info3,"MCU:Now Status:%d%%.",para[5]);
				 break;
			case 0x11:
				 if(para[5]==ACKERR_PW) //口令出错
						sprintf((char*)&upgrade_info3[0],"MCU:err:Password,Close This Window To Restart");  
					else if(para[5]==ACKERR_LOAD)//烧录出错
						sprintf((char*)&upgrade_info3[0],"MCU:err:FlashLoad,Close This Window To Restart");  
					else if(para[5]==ACKERR_CRC)//CRC出错
						sprintf((char*)&upgrade_info3[0],"MCU:err:CRC,Close This Window To Restart");  
					else if(para[5]==ACKERR_OVVOL)//超出容量
						sprintf((char*)&upgrade_info3[0],"MCU:err:OverSize,Close This Window To Restart");  
					else if(para[5]==ACKERR_KEY)//私钥错误
						sprintf((char*)&upgrade_info3[0],"MCU:err:Key,Close This Window To Restart");  
					else if(para[5]==ACKERR_SHIFT)//无法切换 固定码错误或波特率错误
						sprintf((char*)&upgrade_info3[0],"MCU:err:Shift Close This Window To Restart");  
					else if(para[5]==ACKERR_NOSPIFLASH)//无spi flash
						sprintf((char*)&upgrade_info3[0],"MCU:err:NoSpiFlash Close This Window To Restart");  					
					else  
					sprintf((char*)&upgrade_info3[0],"MCU:err0X%02X,Close This Window To Restart",para[5]);  
					set_dialog_info_close_key_type(KEY_TYPE_ONCE);
					func_set_upgrade_close_key_type(KEY_TYPE_ONCE);
				 break;
		  case 0x12:
				 sprintf(upgrade_info3,"MCU: Update Successfully,Close To Restart.");
			   set_dialog_info_close_key_type(KEY_TYPE_ONCE);
			   func_set_upgrade_close_key_type(KEY_TYPE_ONCE);
				 break;
		 }
	}
	if(f_ui_disply_dialog_info_5 == FALSE)
	{
		f_ui_disply_dialog_info_5 = TRUE;
		ui_column_setup_system_upgrade_info_str(TRUE);
	}
	//if(f_ui_disply_dialog_info==FALSE)
	//{
	//	f_ui_disply_dialog_info = TRUE;
	//	ui_column_setup_system_upgrade_info_str(TRUE);
	//	//ui_disply_dialog_info();
	//}
	
}

void FlC200_hc_comm_set_pro(u8 cmd,u8 para1,u8 para2)
{
  switch (cmd)
  {
    case 0x01://0x01：主电池低压报警点
       main_battery_set_status.V_warning_L   = para1*256+para2;
    break;
    case 0x02://0x02：主电池高压报警点
       main_battery_set_status.V_warning_H   = para1*256+para2;
    break;
    case 0x03://0x03：主电池SOC低报警点
       main_battery_set_status.V_SOC_warning_L   = para1*256+para2;
    break;
    
    case 0x06://0x：副电池1低压报警点
       assi1_battery_set_status.V_warning_L   = para1*256+para2;
    break;
    case 0x07://0x：副电池1高压报警点
       assi1_battery_set_status.V_warning_H   = para1*256+para2;
    break;
    case 0x08://0x：副电池1SOC低报警点
       assi1_battery_set_status.V_SOC_warning_L   = para1*256+para2;
    break;
    
     case 0x0A://0x：副电池2低压报警点
       assi2_battery_set_status.V_warning_L   = para1*256+para2;
    break;
    case 0x0B://0x：副电池2高压报警点
       assi2_battery_set_status.V_warning_H   = para1*256+para2;
    break;
    case 0x0C://0x：副电池2SOC低报警点
       assi2_battery_set_status.V_SOC_warning_L   = para1*256+para2;
    break;
    
    
    case 0x10://0x10：清水箱最大容量
       fresh_set_status.val_max  = para1*256+para2;
    break;
    case 0x11://0x11：清水箱水位报警下限
       fresh_set_status.val_warning_L  = para1*256+para2;
    break;
    case 0x12://0x12：清水箱水位报警上限
       fresh_set_status.val_warning_H = para1*256+para2;
    break;
    case 0x13://0x13：清水箱空水保护点
       fresh_set_status.val_protect = para1*256+para2;
    break;
    
    case 0x16://0x16：污水箱最大容量
       back_set_status.val_max = para1*256+para2;
    break;
    case 0x17://0x17：污水箱水位报警下限(高量警示)
       back_set_status.val_warning_H = para1*256+para2;
    break;
    case 0x18://0x18：污水箱水位报警上限(高量报警)
       back_set_status.val_alarm_H = para1*256+para2;
    break;
    case 0x19://0x19：污水箱自动加热启动温度
       back_set_status.temp_auto_heat_begin = para1;
    break;
    case 0x1a://0x1a：污水箱自动加热停止温度
       back_set_status.temp_auto_heat_stop = para1;
    break;
    
    
    case 0x20://0x20：灰水箱最大容量
       grey_set_status.val_max = para1*256+para2;
    break;
     case 0x21://0x21：灰水箱水位报警下限(高量警示)
       grey_set_status.val_warning_H= para1*256+para2;
    break;
     case 0x22://0x22：灰水箱水位报警上限(高量报警)
       grey_set_status.val_alarm_H= para1*256+para2;
    break;
    
  }
}





void FlC200_hc_comm_base_set_pro(u8 cmd,u8 para1,u8 para2)
{
  switch (cmd)
  {
    case 0x01://0x01：温度单位
       if(para1==0x00)
       {
         base_status.uint&=~0x0C;
       }
       if(para1==0x01)
       {
         base_status.uint&=~0x0C;
         base_status.uint|= 0x04;
         
       }
    break;
    case 0x02://0x02：容量单位
       if(para1==0x00)
       {
         base_status.uint&=~0x03;
       }
       if(para1==0x01)
       {
         base_status.uint&=~0x03;
         base_status.uint|= 0x01;
         
       }
    break;
    case 0x06://0x06：语言设置
      if(para1<2)
       base_status.language = para1;
    break;
    
    case 0x08://0x08：亮度调节
      if(para1<2)
       base_status.light = para1;
    break;
    
    case 0x09://0x09：色相调节R
      if(para1<2)
       base_status.R = para1;
    break;
    
    case 0x0A://0x0A：G
      if(para1<2)
       base_status.G = para1;
    break;
    
    case 0x0B://0x0B：B
      if(para1<2)
       base_status.B = para1;
    break;

     case 0x10://0x10：屏幕休眠时间
      if(para1<2)
       base_status.sleep_time = para1;
    break;
  }
}

bool f_sleep_now = FALSE;
void FlC200_hc_comm_test_pro(u8 cmd)
{
  //u32 temp_pow;
  switch (cmd)
  {
    case 0x00://touch up
      f_sleep_now=TRUE;
     break;
	}
}



bool FlC200_hc_cmd_proc(u8 * buf)//所有通过CRC的指令都会在这里解释
{
   // sysprintf("\r\n In FlC200_hc_cmd_proc \r\n  "); 
  switch (buf[0])//buf[0]:ID buf[1]:LEN buf[2]:DATA
  {
		   // sysprintf("\r\n In 1111---------- \r\n  "); 
 

      
        case HC_SLAVE_CMD_RGB_STATUS://page3 RGB 0x5B
		   F1C200_send_hc_ack();//先发ACK,再处理
            FlC200_hc_comm_RGB_SW(&buf[0]);//打印同步数据
        		break;

      	case HC_SLAVE_CMD_HVAC_SET_STATUS://page5  HVAC
		   F1C200_send_hc_ack();//先发ACK,再处理
            FlC200_hc_comm_AC_SW(&buf[0]);//打印同步数据 
      		break;

        case HC_SLAVE_CMD_DIESEL_HEATERS_STATUS:
             F1C200_send_hc_ack();//先发ACK,再处理
             FlC200_hc_comm_diese_heater_SW(&buf[0]);

        
		case HC_SLAVE_CMD_BASE_STATUS://新手刹24(刹车信号)，旧69
			F1C200_send_hc_ack();//先发ACK,再处理
		  FlC200_hc_comm_base_status_pro(&buf[2]);
		break;
        

        
		case HC_SLAVE_CMD_PRODUCT_ID:
			F1C200_send_hc_ack();//先发ACK,再处理
		  FlC200_hc_comm_product_id_pro(&buf[2]);
		break;
		case HC_SLAVE_CMD_VERSION:
			F1C200_send_hc_ack();//先发ACK,再处理
		  FlC200_hc_comm_version_pro(&buf[1]);
		break;
		case HC_SLAVE_CMD_OTHER_INFO_CONNECT:
			F1C200_send_hc_ack();//先发ACK,再处理
		  FlC200_hc_comm_ctr_mcu_version_pro(&buf[1]);
		break;
		case HC_SLAVE_CMD_EXT_MCU_PRINTF:
			F1C200_send_hc_ack();//先发ACK,再处理
		  FlC200_hc_comm_External_mcu_printf_pro(&buf[1]);
		break;
		case HC_SLAVE_CMD_MAC:
			F1C200_send_hc_ack();//先发ACK,再处理
		  FlC200_hc_comm_mac_pro(&buf[1]);
		break;
		case HC_SLAVE_CMD_CODE_RETURN://蓝牙配对信息
			F1C200_send_hc_ack();//先发ACK,再处理
		  //if (buf[2]==0x01)
      {
		 code_connect = buf[2]*256+buf[3];
         f_code_connect_done = TRUE;
        if(1) {
            sysprintf("code_connect = %02X\r\n", code_connect);
            sysprintf("code_connect = %d\r\n", code_connect);

        
        }
          
      }
		break;
		
		case HC_SLAVE_CMD_SWITCH_STATUS://开关状态返回，处理灯0x60
			 F1C200_send_hc_ack();//先发ACK,再处理
            FlC200_hc_comm_light_SW(&buf[0]);   //light SW         //buf[0]:ID buf[1]:LEN buf[2]:DATA
        
        
        
		   //FlC200_hc_comm_switch_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_SWITCH_CH:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   //FlC200_hc_comm_switch_ch_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_EXT_KRY_TYPE://旧手刹0x69
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_External_key_type_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_INTERVER_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_inverter_pro(&buf[2]);
			break;
		
		case HC_SLAVE_CMD_BATTERY_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_battery_pro(&buf[2]);
			break;
		
		case HC_SLAVE_CMD_CHANGE_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_charger_pro(&buf[2]);
			break;
		
		case HC_SLAVE_CMD_SOLAR_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_solar_pro(&buf[2]);
			break;
		
		case HC_SLAVE_CMD_VAL_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_val_pro(&buf[2]);
			break;
		
		case HC_SLAVE_CMD_TEMP_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_temp_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_WARNING_CODE_LIST:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_warning_code_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_BATTERY_SET_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_battery_set_return_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_FRESH_SET_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_tank_set_return_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_BLACK_SET_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_black_set_return_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_GREY_SET_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_grey_set_return_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_LPG_SET_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_LPG_set_return_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_PARTS_SET_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_bat_set_return_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_CH_CURRENT_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   //FlC200_hc_comm_ch_current_pro(&buf[2]);
			break;
		case HC_SLAVE_CMD_TIME_STATUS://时间
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_time_set_return(&buf[2]);
			break;
        
		case HC_SLAVE_CMD_BASE_SET_STATUS:///系统设置状态反馈信息 0x76
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_base_set_return(&buf[2]);
			break;
        
        
		case HC_SLAVE_CMD_INFO_STATUS:
		   F1C200_send_hc_ack();//先发ACK,再处理
		   FlC200_hc_comm_info_return(&buf[2]);
			break;
	  case HC_SLAVE_CMD_SWITCH_NAME:
		F1C200_send_hc_ack();//先发ACK,再处理
	  //FlC200_hc_comm_switch_name(&buf[2]);
		break;
		
		case 0xFD://TEST
    F1C200_send_hc_ack();//先发ACK,再处理
		X_offset_test = buf[2]*256+buf[3];
		Y_offset_test = buf[4]*256+buf[5];
    break;
		case 0xFE://TEST
    F1C200_send_hc_ack();//先发ACK,再处理
    FlC200_hc_comm_test_pro(buf[2]);
    break;
		
		
		
		
		
		
		
		
		
		/*
		
		
  case HC_MASTER_CMD_START_END://响应主机启动与关闭通讯的请求
    F1C200_send_hc_ack();//先发ACK,再处理
    if (buf[2]==0x01)
    {
      init_FlC200_hc_comm_req();   //返回密码      
    }
    break;
		

    
  case HC_MASTER_CMD_QUERY_STATE:
    F1C200_send_hc_ack();//先发ACK,再处理
    F1C200_query_state_proc(buf[2],buf[3]);

  break;
  
  
  case HC_MASTER_CMD_SWITCH_NAME:
    F1C200_send_hc_ack();//先发ACK,再处理
    FlC200_hc_comm_switch_name(&buf[2]);
  break;
  
  case HC_MASTER_CMD_SET_CMD:
    F1C200_send_hc_ack();//先发ACK,再处理
    FlC200_hc_comm_set_pro(buf[2],buf[3],buf[4]);
  break;
  

  
  case HC_MASTER_CMD_BASE_SET:
    F1C200_send_hc_ack();//先发ACK,再处理
    FlC200_hc_comm_base_set_pro(buf[2],buf[3],buf[4]);
  break;
  

*/

    
  default:
    return FALSE;
    
  }
  return TRUE;
}








