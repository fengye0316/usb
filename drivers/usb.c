#include "printf.h"

int usb_init(void)
{
	unsigned short chip_id;
	
	chip_id = d12_read_id();
	if (chip_id != D12_CHIP_ID) {
		printf("d12 is not working!\r\n");
		return -1;
	}
	
	return 0;
}
