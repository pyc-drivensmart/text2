#include "sys_clock.h"
#include "sys_types.h"
#include "sys_io.h"
#include "reg_ccu.h"

#define GPIOG_BASE (CPU_PORT_BASE + 0xD8)
#define GPIOE_BASE (CPU_PORT_BASE + 0x90)
#define GPIOG_INTERRUPT_BASE (GPIO_CPU_INTERRUPT_BASE + 0x20)
/*
等待系统时钟成功
*/
static void wait_pll_stable(u32_t base)
{
	u32_t rval = 0;
	u32_t time = 0xfff;

	do {
		rval = read32(base);
		time--;
	} while(time && !(rval & (1 << 28)));
}

static void clock_set_pll_cpu(u32_t clk)
{
	u32_t n, k, m, p;
	u32_t rval = 0;
	u32_t div = 0;

	if(clk > 720000000)
		clk = 720000000;

	if((clk % 24000000) == 0)
	{
		div = clk / 24000000;
		n = div - 1;
		k = 0;
		m = 0;
		p = 0;
	}
	else if((clk % 12000000) == 0)
	{
		m = 1;
		div = clk / 12000000;
		if((div % 3) == 0)
			k = 2;
		else if((div % 4) == 0)
			k = 3;
		else
			k = 1;
		n = (div / (k + 1)) - 1;
		p = 0;
	}
	else
	{
		div = clk / 24000000;
		n = div - 1;
		k = 0;
		m = 0;
		p = 0;
	}

	rval = read32(F1C100S_CCU_BASE + CCU_PLL_CPU_CTRL);
	rval &= ~((0x3 << 16) | (0x1f << 8) | (0x3 << 4) | (0x3 << 0));
	rval |= (1U << 31) | (p << 16) | (n << 8) | (k << 4) | m;
	write32(F1C100S_CCU_BASE + CCU_PLL_CPU_CTRL, rval);
	wait_pll_stable(F1C100S_CCU_BASE + CCU_PLL_CPU_CTRL);
}
/*
系统时钟
*/
void Sys_Clock_Init(int Hz)
{
	write32(F1C100S_CCU_BASE + CCU_PLL_STABLE_TIME0, 0x1ff);
	write32(F1C100S_CCU_BASE + CCU_PLL_STABLE_TIME1, 0x1ff);
	write32(F1C100S_CCU_BASE + CCU_CPU_CFG, 0x00020000);
	write32(F1C100S_CCU_BASE + CCU_AHB_APB_CFG, 0x00012110);

	clock_set_pll_cpu(Hz);
}

