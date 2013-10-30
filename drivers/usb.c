#include "printf.h"
#include "d12.h"
#include "delay.h"

int usb_init(void)
{
	unsigned short chip_id;
	
	chip_id = d12_read_id();
	if (chip_id != D12_CHIP_ID) {
		printf("d12 is not working!\r\n");
		return -1;
	}
	
	d12_disconnect();
	delayms(100);
	d12_init();
	
	return 0;
}
