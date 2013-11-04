#ifndef __D12_H
#define __D12_H

/* From internet */
#define D12_CHIP_ID			0x1012

/* Endpoint index */
#define D12_EP0_OUT			0
#define D12_EP0_IN			1
#define D12_EP1_OUT			2
#define D12_EP1_IN			3
#define D12_EP2_OUT			4
#define D12_EP2_IN			5

/* Interrupt register bits */
#define D12_INT_EP0_OUT			(1 << 0)
#define D12_INT_EP0_IN			(1 << 1)
#define D12_INT_EP1_OUT			(1 << 2)
#define D12_INT_EP1_IN			(1 << 3)
#define D12_INT_EP2_OUT			(1 << 4)
#define D12_INT_EP2_IN			(1 << 5)
#define D12_INT_BUS_REST		(1 << 6)
#define D12_INT_SPD_CHG			(1 << 7)
#define D12_INT_DMA_EOT			(1 << 8)

/* Endpoint status bits */
#define D12_EP_STAT_SETUP_PAKCET	(1 << 2)
#define D12_EP_STAT_BUF0_FULL		(1 << 5)
#define D12_EP_STAT_BUF1_FULL		(1 << 6)
#define D12_EP_STAT_STALL		(1 << 7)

/* Last transaction status register bits */
#define D12_TRANS_STAT_SUCCESS		(1 << 0)
#define D12_TRANS_STAT_SETUP_PACKET	(1 << 5)
#define D12_TRANS_STAT_DATA1_PACKET	(1 << 6)
#define D12_TRANS_STAT_NOT_READ		(1 << 7)


extern unsigned short d12_read_id(void);

extern void d12_init(void);
extern void d12_disconnect(void);
extern unsigned short d12_read_interrupt_status(void);
extern void d12_set_address(unsigned char idx);
extern void d12_endpoint_enable(unsigned char cmd);
extern void d12_select_endpoint(unsigned char idx);
extern unsigned char d12_read_endpoint_status(unsigned char idx);
extern unsigned char d12_read_last_trans_status(unsigned char idx);
extern void d12_ack_setup(void);
extern unsigned char d12_read_buffer(unsigned char idx, unsigned char *buf, unsigned char size);
extern void d12_clear_buffer(void);
extern void d12_validate_buffer(void);
extern void d12_write_buffer(unsigned char idx, unsigned char *buf, unsigned char size);

#endif /* __D12_H */
