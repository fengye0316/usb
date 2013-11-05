code unsigned char device_descriptor[] = {
	0x12,		/* bLength */
	0x01,		/* bDescriptorType */
	0x10, 0x01,	/* bcdUSB */
	0x00,		/* bDeviceClass */
	0x00,		/* bDeviceSubClass */
	0x00,		/* bDeviceProtocol */
	0x10,		/* bMaxPacketSize */
	0x00, 0x80,	/* idVendor */
	0x01, 0x00,	/* idProduct */
	0x00, 0x01,	/* bcdDevice */
	0x01,		/* iManufacturer */
	0x02,		/* iProduct */
	0x00,		/* iSerialNumber */
	0x01		/* bNumConfigurations */
};

code unsigned char config_descriptor[] = {
	/* configuration descriptor */
	0x09,		/* bLength */
	0x02,		/* bDescriptorType */
	0x22, 0x00,	/* wTotalLength */
	0x01,		/* bNumInterfaces */
	0x01,		/* bConfigurationValue */
	0x00,		/* iConfiguration */
	0x80,		/* bmAttributes */
	0x32,		/* bMaxPower */
	
	/* interface descriptor */
	0x09,		/* bLength */
	0x04,		/* bDescriptorType */
	0x00,		/* bInterfaceNumber */
	0x00,		/* bAlternateSetting */
	0x01,		/* bNumEndpoints */
	0x03,		/* bInterfaceClass */
	0x01,		/* bInterfaceSubClass */
	0x01,		/* bInterfaceProtocol */
	0x00,		/* iInterface */
	
	/* hid descriptor */
	0x09,		/* bLength */
	0x21,		/* bDescriptorType */
	0x01, 0x01,	/* bcdHID */
	0x00,		/* bCountryCode */
	0x01,		/* bNumDescriptor */
	0x22,		/* bDescriptorType */
	0x2d, 0x00,	/* wDescriptorLength */
	
	/* endpoint descriptor */
	0x07,		/* bLength */
	0x05,		/* bDescriptorType */
	0x81,		/* bEndpointAddress */
	0x03,		/* bmAttributes */
	0x08, 0x00,	/* wMaxPacketsize */
	0x0a		/* bInterval */
};

code unsigned char support_language[] = {
	0x04,		/* bLength */
	0x03,		/* bDescriptorType */
	0x09, 0x04	/* English (United States ) */
};

code unsigned char manufacturer_string[] = {
	0x14,		/* bLength */
	0x03,		/* bDescriptorType */
	0x55, 0x00,	/* U */
	0x53, 0x00,	/* S */
	0x42, 0x00,	/* B */
	0x20, 0x00,
	0x57, 0x00,	/* W */
	0x6f, 0x00,	/* o */
	0x72, 0x00,	/* r */
	0x6c, 0x00,	/* l */
	0x64, 0x00	/* d */
};

code unsigned char product_string[] = {
	0x1a,		/* bLength */
	0x03,		/* bDescriptorType */
	0x55, 0x00,	/* U */
	0x53, 0x00,	/* S */
	0x42, 0x00,	/* B */
	0x20, 0x00,
	0x4b, 0x00,	/* K */
	0x65, 0x00,	/* e */
	0x79, 0x00,	/* y */
	0x62, 0x00,	/* b */
	0x6f, 0x00,	/* o */
	0x61, 0x00,	/* a */
	0x72, 0x00,	/* r */
	0x64, 0x00,	/* d */
};

code unsigned char report_descriptor[] = {
	0x05, 0x01,	/* Usage Page(Generic Desktop) */
	0x09, 0x06,	/* Usage(Keyboard) */
	0xa1, 0x01,	/* Collection(Application) */
	
	/* Function key, such as Ctrl, Shift... */
	0x05, 0x07,	/* Usage Page(Keyboard) */
	0x19, 0xe0,	/* Usage Minimum(Keyboard LeftControl) */
	0x29, 0xe7,	/* Usage Maximum(Keyboard RightGUI) */
	0x15, 0x00,	/* Logical Minimum(0) */
	0x25, 0x01,	/* Logical Maximum(1) */
	0x75, 0x01,	/* Report Size(1) */
	0x95, 0x08,	/* Report Count(8) */
	0x81, 0x02,	/* Input(Data, Variable, Absolute) */
	
	/* For reserved */
	0x75, 0x08,	/* Report Size(8) */
	0x95, 0x01,	/* Report Count(1) */
	0x81, 0x01,	/* Input(Constant) */
	
#if 0
	/* For LED */
	0x05, 0x08,	/* Usage Page(for LEDs )*/
	0x19, 0x01,	/* Usage Minimum(Num Lock) */
	0x29, 0x05,	/* Usage Maximum(Kana) */
	0x75, 0x01,	/* Report Size(1) */
	0x95, 0x05,	/* Report Count(5) */
	0x91, 0x02,	/* Output(Data, Variable, Absolute) */
	0x75, 0x03,	/* Report Size(3) */
	0x95, 0x01,	/* Report Count(1) */
	0x91, 0x01,	/* Output(Constant) */
#endif
	/* generic key */
	0x05, 0x07,	/* Usage Page(Key Codes) */
	0x19, 0x00,	/* Usage Minimum(0) */
	0x29, 0x65,	/* Usage Maximum(101) */
	0x15, 0x00,	/* Logical Minimum(0) */
	0x25, 0x65,	/* Logical Maximum(101) */
	0x75, 0x08,	/* Report Size(8) */
	0x95, 0x06,	/* Report Count(6) */
	0x81, 0x00,	/* Input(Data Array) */
	
	0xc0		/* End Collection */
};
