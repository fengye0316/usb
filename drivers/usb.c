#include "printf.h"
#include "d12.h"
#include "delay.h"

void usb_interrupt_handler(void) interrupt 0
{
	unsigned short status;
	
	status = d12_read_interrupt_status();
	switch (status) {
	case D12_EP0_OUT:
		break;
	case D12_EP0_IN:
		break;
	case D12_EP1_OUT:
		break;
	case D12_EP1_IN:
		break;
	case D12_EP2_OUT:
		break;
	case D12_EP2_IN:
		break;
	case D12_BUS_RESET:
		break;
	case D12_SPD_CHG:
		break;
	case D12_DMA_EOT:
		break;
	default:
		break;
	}
}

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
