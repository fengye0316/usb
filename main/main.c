#include <reg52.h>
#include "delay.h"

sbit led1 = P2^0;

void main(void)
{
	while (1) {
		led1 = 0;
		delayms(1000);
		led1 = 1;
		delayms(1000);
	}
}
