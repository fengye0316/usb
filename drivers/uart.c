#include <reg52.h>
#include "timer.h"
#include "uart.h"

void uart_interrupt_handler(void) interrupt 4
{
	char tmp;
	
	if (RI) {
		RI = 0;
		tmp = SBUF;
		SBUF = tmp;
	}
}

void uart_init(void)
{
	timer1_init();
	SCON = UART_MODE1;
	REN = 1;			/* Enable reception */		
	ES = 1;				/* Enable the serial port interrupt */
	EA = 1;				/* Enable global interrupt */
}

void uart_putc(const char c)
{
	SBUF = c;
	while (!TI);
	TI = 0;
}

void uart_puts(const char *s)
{
	while (*s != '\0') {
		uart_putc(*s++);
	}
}
