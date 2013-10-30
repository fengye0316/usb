#ifndef __D12_H
#define __D12_H

/* From internet */
#define D12_CHIP_ID			0x1012

#define D12_CMD_READ_ID			0xFD


#define D12_EP0_OUT			0
#define D12_EP0_IN			1
#define D12_EP1_OUT			2
#define D12_EP1_IN			3
#define D12_EP2_OUT			4
#define D12_EP2_IN			5

extern unsigned short d12_read_id(void);

#endif /* __D12_H */
