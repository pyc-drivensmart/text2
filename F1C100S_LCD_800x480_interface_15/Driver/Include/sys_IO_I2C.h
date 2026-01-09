#include "sys_types.h"
void IO_AT24C256_Demo(void);
void IO_I2C_Init(void);
void IO_read_byte(u16 addr,u8 addr_len,u8* buf,u16 buf_len);
void IO_write_byte(u16 addr,u8 addr_len,u8* buf,u16 buf_len);
void IO_set_slave_addr(u8 addr);

