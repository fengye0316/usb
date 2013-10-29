#include "printf.h"
#include "uart.h""

void board_init(void)
{
	uart_init();
}

void main(void)
{
	board_init();
	
	printf("/***************Welcome to the usb world!****************/");
	
	while (1);
}
