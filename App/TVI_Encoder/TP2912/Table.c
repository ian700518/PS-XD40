
#include "Config.h"
#include "TP2912_Typedefs.h"

CODE BYTE TVP7002_1080P30_DataSet[] = {

	0xb8, 31,		
	0x01, 0x89,
	0x02, 0x80, 
	0x03, 0xe0,
	0x07, 0x2c,
	0x08, 0x3c,
	0x09, 0x3c,
	0x0a, 0x3c,
	0x0c, 0x90,
	0x0e, 0x36,	//0x3e,
//	0x0f, 0x02,	
	0x11, 0x40,
	0x12, 0x01,
	0x15, 0x47,
	0x1a, 0xca,
	0x21, 0x39,
	0x2a, 0x83,
	0x2f, 0x0c,
	0x34, 0x09,
	0x35, 0x00,
	0x36, 0x02,
	0x3d, 0x06,
	0x3f, 0x0f,
	0x40, 0x07,
	0x41, 0x01,
	0x42, 0x8b,
	0x43, 0x08,
	0x44, 0x03,
	0x45, 0x03,
	0x46, 0x2d,
	0x47, 0x2d,
	0x17, 0x50,

	0xff, 0xff
};

CODE BYTE TVP7002_720P_DataSet[] = {

	0xb8, 18,		
	0x01, 0x67,
	0x02, 0x20, 
	0x03, 0xa0,
	0x05, 0x32,
	0x06, 0x20,
	0x15, 0x47,
	0x3f, 0x0f,
	0x40, 0x47,
	0x41, 0x01,
	0x42, 0x4b,
	0x43, 0x06,
	0x44, 0x05,
	0x45, 0x05,
	0x46, 0x1e,
	0x47, 0x1e,
	0x48, 0x00,
	0x49, 0x00,
	0x17, 0x00,

	0xff, 0xff
};

CODE BYTE TVP7002_480i_DataSet[] = {

	0xb8, 16,		
	0x01, 0x35,
	0x02, 0xa0, 
	0x03, 0x18,
	0x05, 0x06,
	0x06, 0x10,
	0x40, 0x95,
	0x41, 0x00,
	0x42, 0x0f,
	0x43, 0x00,
	0x44, 0x01,
	0x45, 0x01,
	0x46, 0x13,
	0x47, 0x13,
	0x48, 0x02,
	0x49, 0x01,
	0x17, 0x00,

	0xff, 0xff
};

CODE BYTE ADV7611_HDMIMAP_Dataset[] = {	
	0x68, 21,
	0x01, 0x01,
	0x9b, 0x03,
	0x6f, 0x0c,
	0x85, 0x1f,
	0x87, 0x70,
	0x57, 0xda,
	0x58, 0x01,
	0x03, 0x98,
	0x4c, 0x44,
	0xc1, 0x01,
	0xc2, 0x01,
	0xc3, 0x01,
	0xc4, 0x01,
	0xc5, 0x01,
	0xc6, 0x01,
	0xc7, 0x01,
	0xc8, 0x01,
	0xc9, 0x01,
	0xca, 0x01,
	0xcb, 0x01,
	0xcc, 0x01,
	
	0xff, 0xff
};

CODE BYTE ADV7611IO__1080P30_Dataset[] = {	
	0x98, 7,
	0x01, 0x25,
	0x00, 0x1e,
	0x03, 0x80,
	0x04, 0x60,
	0x0c, 0x42,
	0x15, 0xb8,
	0x19, 0x80,
	
	0xff, 0xff
};

CODE BYTE ADV7611IO__720P60_Dataset[] = {	
	0x98, 7,
	0x01, 0x05,
	0x00, 0x13,
	0x03, 0x80,
	0x04, 0x60,
	0x0c, 0x42,
	0x15, 0xb8,
	0x19, 0x80,
	
	0xff, 0xff
};
CODE BYTE ADV7611IO__720P30_Dataset[] = {	
	0x98, 8,
	0x01, 0x25,
	0x00, 0x19,
	0x03, 0x80,
	0x04, 0x60,
	0x0c, 0x42,
	0x15, 0xb8,
	0x19, 0x80,
	0x33, 0x40,
	
	0xff, 0xff
};

CODE BYTE ADV7611IO__720P25_Dataset[] = {	
	0x98, 8,
	0x01, 0x35,
	0x00, 0x19,
	0x03, 0x80,
	0x04, 0x62,
	0x0c, 0x42,
	0x15, 0xb8,
	0x19, 0x80,
	0x33, 0x40,
	
	0xff, 0xff
};


CODE BYTE ADV7611IO__480i_Dataset[] = {	
	0x98, 8,
	0x01, 0x05,
	0x00, 0x00,
	0x03, 0x00,
	0x04, 0x60,
	0x0c, 0x42,
	0x15, 0xb8,
	0x19, 0xc0,
	0x33, 0x40,
	
	0xff, 0xff
};

CODE BYTE PO3100K__720PP30_Dataset[] = {
	0x64, 155,
	0x03, 0x00,
	0x2d, 0x01,
	0x29, 0x9d,
	0x04, 0x00,
	0x05, 0x00,
	0x40, 0x3c,
	0x15, 0x15,
	0x28, 0x22,
	0x33, 0x05,
	0x34, 0x02,		//10
	0x36, 0x80,
	0x38, 0x58,
	0x03, 0x01,
	0x1e, 0x0e,
	0x26, 0x03,
	0xb1, 0x30,
	0x03, 0x04,
	0x06, 0x98,
	0x03, 0x01,
	0xa4, 0x88,		//20
	0xa5, 0x88,
	0xa6, 0x88,
	0xa7, 0x00,
	0xa8, 0x00,
	0xa9, 0x08,
	0x03, 0x04,
	0x06, 0xb8,
	0x75, 0x28,
	0x76, 0x28,
	0x77, 0x78,		//30
	0x78, 0x78,
	0x79, 0x48,
	0x7a, 0x48,
	0x7b, 0xb8,
	0x7c, 0xb8,
	0x73, 0x08,
	0x51, 0x10,
	0x52, 0xe0,
	0x54, 0x02,
	0x55, 0x40,		//40
	0x5b, 0x4b,
	0x5c, 0x64,
	0x5d, 0xa4,
	0x5e, 0x23,
	0x5f, 0x28,
	0x61, 0x73,
	0x62, 0x37,
	0x63, 0x87,
	0x64, 0x2d,
	0x65, 0x2d,		//50
	0x6e, 0x3a,
	0x70, 0x60,
	0x03, 0x03,
	0x18, 0x60,
	0x03, 0x04,
	0x3b, 0x90,
	0x3d, 0x70,
	0x1c, 0xba,
	0x1f, 0xba,
	0x4a, 0x08,		//60
	0x41, 0x04,
	0x42, 0x08,
	0x43, 0x10,
	0x44, 0x20,
	0x2e, 0x04,
	0x03, 0x00,
	0x4f, 0x08,
	0x5a, 0xba,
	0x5b, 0x00,
	0x03, 0x04,		//70
	0xa1, 0x10,
	0x03, 0x02,
	0x34, 0x8a,
	0x35, 0x8d,
	0x36, 0x8b,
	0x37, 0x3e,
	0x38, 0x90,
	0x39, 0x84,
	0x3b, 0x3c,
	0x03, 0x03,		//80
	0x09, 0x86,
	0x0d, 0x88,
	0x03, 0x02,
	0x3e, 0x27,
	0x3f, 0x36,
	0x40, 0x40,
	0x41, 0x49,
	0x42, 0x58,
	0x43, 0x64,
	0x44, 0x78,		//90
	0x45, 0x89,
	0x46, 0xa4,
	0x47, 0xbb,
	0x48, 0xcf,
	0x4a, 0xf1,
	0x6b, 0x0b,
	0x6c, 0x13,
	0x6d, 0x1a,
	0x6e, 0x20,
	0x6f, 0x2b,		//100
	0x70, 0x36,		
	0x71, 0x49,		
	0x72, 0x5a,
	0x73, 0x7b,
	0x74, 0x98,
	0x75, 0xb4,
	0x76, 0xce,
	0x77, 0xe7,
	0x8d, 0x30,
	0x30, 0x40,		//110
	0x31, 0x40,		
	0x03, 0x04,		
	0x09, 0x00,
	0x03, 0x03,
	0x2e, 0x7f,
	0x2f, 0x7f,
	0x30, 0x7f,
	0x32, 0x00,
	0x33, 0x00,
	0x34, 0x00,		//120
	0x78, 0x00,		
	0x79, 0x00,		
	0xa1, 0x30,
	0x03, 0x01,
	0x19, 0xc4,
	0x5f, 0x02,
	0x60, 0xc8,
	0x61, 0x03,
	0x62, 0x66,
	0x67, 0x03,		//130
	0x68, 0x79,		
	0x69, 0x03,		
	0x6a, 0x8c,
	0x53, 0x02,
	0x54, 0xd0,
	0x99, 0x03,
	0x9a, 0x79,
	0x6f, 0x03,
	0x70, 0x00,
	0x73, 0x00,		//140
	0x74, 0x9c,	
	0x7b, 0x03,
	0x7c, 0x9c,
	0x8f, 0x03,		
	0x90, 0x73,
	0x8b, 0x03,
	0x8c, 0x9e,
	0x03, 0x04,
	0x13, 0x70,
	0x15, 0x70,		//150
	0x17, 0x70,
	0x1c, 0x4e,		
	0x1f, 0x4e,
	0x03, 0x00,		
	0x40, 0x2c,		
	
	0xff, 0xff
};

