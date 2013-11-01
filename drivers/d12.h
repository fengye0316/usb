#ifndef __D12_H
#define __D12_H

/* From internet */
#define D12_CHIP_ID			0x1012


#define D12_EP0_OUT			0
#define D12_EP0_IN			1
#define D12_EP1_OUT			2
#define D12_EP1_IN			3
#define D12_EP2_OUT			4
#define D12_EP2_IN			5


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
