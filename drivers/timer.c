#include <reg52.h>
#include "configs.h"
#include "timer.h"

void timer1_init(void)
{
	TMOD &= 0x0F;
	TMOD |= TIMER_MODE2 << 4;				/* 8bit auto-reload mode */
	TH1 = 256 - SYS_CLK_FREQ / (BAUD_RATE * 32 * 12);
	TL1 = 256 - SYS_CLK_FREQ / (BAUD_RATE * 32 * 12);
	TR1 = 1;						/* Turn on timer1 */
}
