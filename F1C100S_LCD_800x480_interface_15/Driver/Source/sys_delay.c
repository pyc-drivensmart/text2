#include "sys_delay.h"

/*
408M 延时1ms
0极优化
*/
void delay_ms(int ms)
{
 volatile unsigned int cnt,i,s;
// s=ms*66; //不开cache
 s=ms*1851; //开cache	
	for(cnt=0;cnt<s;cnt++)
	{
		for(i=0;i<20;i++);
	}
}
/*
408M 延时1us
0极优化
*/
void delay_us(int us)
{
 volatile unsigned int cnt,i,s;
  s=(unsigned int)((float)us*3); //开cache	//13.6351
//	s=us;
	for(cnt=0;cnt<s;cnt++)
	{
		for(i=0;i<1;i++);
	}

}
