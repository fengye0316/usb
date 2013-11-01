#include <reg52.h>
#include "d12.h"

#define D12_DATA_PORT		P0

sbit	D12_INT_N =		P3^2;
sbit	D12_RD_N =		P3^7;
sbit	D12_WR_N =		P3^6;
sbit	D12_A0 =		P3^5;

static void d12_write_command(unsigned char cmd)
{
	D12_A0 = 1;
	D12_WR_N = 0;
	D12_DATA_PORT = cmd;
	D12_WR_N = 1;
}

static unsigned char d12_read_data(void)
{
	unsigned char val;
	
	D12_A0 = 0;
	D12_RD_N = 0;
	val = D12_DATA_PORT;
	D12_RD_N = 1;
	
	return val;
}

static void d12_write_data(unsigned char val)
{
	D12_A0 = 0;
	D12_WR_N = 0;
	D12_DATA_PORT = val;
	D12_WR_N = 1;
}

unsigned short d12_read_id(void)
{
	unsigned short id;
	
	d12_write_command(0xFD);	/* 0xFD: D12 read ID command */
	id = d12_read_data();
	id |= (unsigned short)d12_read_data() << 8;
	
	return id;
}

void d12_init(void)
{
	EX0 = 1;
	IT0 = 0;
	
	d12_write_command(0xF3);	/* 0xF3: D12 set mode command */
	d12_write_data(0x16);
	d12_write_data(0x47);
}

void d12_disconnect(void)
{
	d12_write_command(0xF3);
	d12_write_data(0x06);
	d12_write_data(0x47);
}

unsigned short d12_read_interrupt_status(void)
{
	unsigned short status;
	
	d12_write_command(0xF4);	/* 0xF4: D12 read interrupt register command */
	status = d12_read_data();
	status |= (unsigned short)d12_read_data() << 8;
	
	return status;
}

void d12_set_address(unsigned char addr)
{
	d12_write_command(0xD0);	/* 0xD0: D12 set address and enable the function command */
	d12_write_data(addr | 0x80);
}

void d12_endpoint_enable(unsigned char cmd)
{
	d12_write_command(0xD8);	/* 0xD8: D12 set endpoint enable command */
	d12_write_data(cmd);
}

void d12_select_endpoint(unsigned char idx)
{
	d12_write_command(0x00 + idx)	/* 0x00+x: D12 select endpoint command */
}

unsigned char d12_read_endpoint_status(unsigned char idx)
{
	unsigned char status;
	
	d12_select_endpoint(idx);
	d12_write_command(0x80 + idx);	/* 0x80+x: D12 read endpoint status command */
	status = d12_read_data();
	
	return status;
}

unsigned char d12_read_last_trans_status(unsigned char idx)
{
	unsigned char status;
	
	d12_select_endpoint(idx);
	d12_write_command(0x40 + idx);	/* 0x40+x: D12 read last transaction status command */
	status = d12_read_data();
	
	return status;
}

void d12_ack_setup(void)
{
	d12_select_endpoint(D12_EP0_IN);
	d12_write_command(0xF1);	/* 0xF1: D12 acknowledge setup command */
	d12_select_endpoint(D12_EP0_OUT);
	d12_write_command(0xF1);
}

unsigned char d12_read_buffer(unsigned char idx, unsigned char *buf, unsigned char size)
{
	unsigned char i, len;
	
	d12_select_endpoint(idx);
	d12_write_command(0xF0);	/* 0xF0: D12 read buffer command */
	d12_read_data();
	len = d12_read_data();
	
	if (len > size) {
		len = size;
	}
	
	for (i = 0; i < len; i++) {
		*buf++ = d12_read_data();
	}
	
	return len;
}

void d12_clear_buffer(void)
{
	d12_write_command(0xF2);	/* 0xF2: D12 clear buffer command */
}

void d12_validate_buffer(void)
{
	d12_write_command(0xFA);	/* 0xFA: D12 validate buffer command */
}

void d12_write_buffer(unsigned char idx, unsigned char *buf, unsigned char size)
{
	unsigned char i;
	
	d12_select_endpoint(idx);
	d12_write_command(0xF0);	/* 0xF0: D12 write buffer command */
	d12_write_data(0x00);
	d12_write_data(size);
	
	for (i = 0; i < size; i++) {
		d12_write_data(*buf++);
	}
	
	d12_validate_buffer();
}
