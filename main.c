#include <reg52.h>

sbit led1 = P2^0;

void delayms(unsigned int ms)
{
	unsigned int x;
	unsigned int y;
	
	for (y = ms; y > 0; y--) {
		for (x = 227; x > 0; x--);
	}
}

void main(void)
{
	while (1) {
		led1 = 0;
		delayms(1000);
		led1 = 1;
		delayms(1000);
	}
}
