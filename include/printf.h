#ifndef __PRINTF_H
#define __PRINTF_H

#include "uart.h"

#define putchar	uart_putc
#define puts	uart_puts

/*
 * 注意在使用printf函数时，需要指定变量的类型，例如：
 * int a = 6;
 * printf("%d\r\n", a);
 * 这样才能正确打印出变量的值，如果直接使用printf("%d\r\n", 6);
 * 则不会正确打印出变量的值，猜测可能是可变参数不是都以int类型来存储数据的，
 * 而该函数实现时都是以int变量类型来获取可变参数的值，所以会输出错误的值，
 * 经测值在PC平台上没有出现此问题，只有在Keil 51上才有此问题。
 */
extern void printf(const char *fmt, ...);

#endif /* __PRINTF_H */
