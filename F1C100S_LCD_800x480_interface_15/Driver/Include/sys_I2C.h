#include "sys_types.h"

#define  TWI0  0  //0x01C2 7000---0x01C2 73FF  1K
#define  TWI1  1  //0x01C2 7400---0x01C2 77FF  1K
#define  TWI2  2  //0x01C2 7800---0x01C2 7BFF  1K

//ËÙÂÊ
#define  Rate400K 400000
#define  Rate100K 100000

void AT24C256_Demo(void);
void I2C_Init(int TWIx);	
void set_slave_addr(u8 addr);
int write_byte(int TWIx,u16 addr,u8 addr_len,u8* buff,u16 len);
u8 read_byte(int TWIx,u16 addr,u8 addr_len,u8* buff,u16 len);
