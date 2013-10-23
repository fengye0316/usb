#ifndef __UART_H
#define __UART_H

#define UART_MODE0	(0x00 << 6)
#define UART_MODE1	(0x01 << 6)
#define UART_MODE2	(0x02 << 6)
#define UART_MODE3	(0x03 << 6)

extern void uart_init(void);
extern void uart_putc(const char c);
extern void uart_puts(const char *s);

#endif /* __UART_H */
