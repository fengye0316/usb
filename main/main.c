#include "printf.h"
#include "uart.h"
#include "usb.h"

void board_init(void)
{
	uart_init();
	usb_init();
}

void main(void)
{
	board_init();
	
	printf("/****************Welcome to the usb world!****************/\r\n");
	
	while (1);
}
