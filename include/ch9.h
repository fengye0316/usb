#ifndef __CH9_H
#define __CH9_H

enum usb_device_state {
	USB_STATE_NOTATTACHED = 0,
	USB_STATE_ATTACHED,
	USB_STATE_POWERED,
	USB_STATE_DEFAULT,
	USB_STATE_ADDRESS,
	USB_STATE_CONFIGURED,
	USB_STATE_SUSPEND
};

struct usb_setup_request {
	unsigned char	bmRequestType;
	unsigned char	bRequest;
	unsigned short	wValue;
	unsigned short	wIndex;
	unsigned short	wLength;
};

#define USB_DIR_OUT			0x00 /* host to device */
#define USB_DIR_IN			0x80 /* device to host */

#define USB_TYPE_MASK			(0x03 << 5)
#define USB_TYPE_STANDARD		(0x00 << 5)
#define USB_TYPE_CLASS			(0x01 << 5)
#define USB_TYPE_VENDOR			(0x02 << 5)
#define USB_TYPE_RESERVED		(0x03 << 5)

#define USB_RECIP_MASK			0x1F
#define USB_RECIP_DEVICE		0x00
#define USB_RECIP_INTERFACE		0x01
#define USB_RECIP_ENDPOINT		0x02
#define USB_RECIP_OTHER			0x03

/* usb standard request codes */
#define USB_REQ_GET_STATUS		0x00
#define USB_REQ_CLEAR_FEATURE		0x01
#define USB_REQ_SET_FEATURE		0x03
#define USB_REQ_SET_ADDRESS		0x05
#define USB_REQ_GET_DESCRIPTOR		0x06
#define USB_REQ_SET_DESCRIPTOR		0x07
#define USB_REQ_GET_CONFIGURATION	0x08
#define USB_REQ_SET_CONFIGURATION	0x09
#define USB_REQ_GET_INTERFACE		0x0A
#define USB_REQ_SET_INTERFACE		0x0B
#define USB_REQ_SYNCH_FRAME		0x0C

/* usb descriptor types */
#define USB_DT_DEVICE			0x01
#define USB_DT_CONFIG			0x02
#define USB_DT_STRING			0x03
#define USB_DT_INTERFACE		0x04
#define USB_DT_ENDPOINT			0x05
#define USB_DT_DEVICE_QUALIFIER		0x06
#define USB_DT_OTHER_SPEED_CONFIG	0x07
#define USB_DT_INTERFACE_POWER		0x08
#define USB_DT_REPORT			0x22 /* for hid */

#endif /* __CH9_H */
