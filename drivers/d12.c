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
	unsigned char tmp;
	
	D12_A0 = 0;
	D12_RD_N = 0;
	tmp = D12_DATA_PORT;
	D12_RD_N = 1;
	
	return tmp;
}

static void d12_write_data(unsigned char tmp)
{
	D12_A0 = 0;
	D12_WR_N = 0;
	D12_DATA_PORT = tmp;
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
