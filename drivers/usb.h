#ifndef __USB_H
#define __USB_H

extern code unsigned char device_descriptor[];
extern code unsigned char config_descriptor[];
extern code unsigned char report_descriptor[];

extern code unsigned char support_language[];
extern code unsigned char manufacturer_string[];
extern code unsigned char product_string[];


extern void ep0out_event_handler(void);
extern void ep0in_event_handler(void);

extern int usb_init(void);

#endif /* __USB_H */
