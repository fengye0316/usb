#include "printf.h"
#include "d12.h"
#include "delay.h"

void usb_interrupt_handler(void) interrupt 0
{
	unsigned short status;
	
	status = d12_read_interrupt_status();
	switch (status) {
	case D12_EP0_OUT:
		ep0out_event_handler();
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
	case D12_BUS_RST:
		break;
	case D12_SPD_CHG:
		break;
	case D12_DMA_EOT:
		break;
	default:
		break;
	}
}

void ep0out_event_handler(void)
{
	unsigned char buf[8], status;
	
	status = d12_read_last_trans_status(D12_EP0_OUT);
	
	if (status & D12_TRANS_STAT_SETUP_PACKET) {
		d12_read_buffer(D12_EP0_OUT, buf, 8);
		
		d12_ack_setup();
		d12_clear_buffer();
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
