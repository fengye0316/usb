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
	
	d12_write_command(D12_CMD_READ_ID);
	id = d12_read_data();
	id |= (unsigned short)d12_read_data() << 8;
	
	return id;
}

void d12_init(void)
{
	EX0 = 1;
	IT0 = 0;
	
	d12_write_command(D12_CMD_SET_MODE);
	d12_write_data(0x16);
	d12_write_data(0x47);
}

void d12_disconnect(void)
{
	d12_write_command(D12_CMD_SET_MODE);
	d12_write_data(0x06);
	d12_write_data(0x47);
}
