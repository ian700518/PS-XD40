#ifndef __NVP6168_H__
#define __NVP6168_H__


#define PLATFORM_LINUX					0
#define NVP6168_I2C_ADDR				0x60
#define NVP_MULTI_CHIP					0
#define COAXIAL_PROTOCOL				0

#define TOTAL_CHIP_CNT					1
#define TOTAL_CHANNEL_CNT				4 * TOTAL_CHIP_CNT


typedef enum  
{
	VPORT_MAP0,		// 1, 2, 3, 4	// full ch1, 2 split 1&2 , all 4 split, PIP with ch2
	VPORT_MAP1,		// 1, 3, 2, 4	// PIP with ch3
	VPORT_MAP2,		// 1, 4, 2, 3	// PIP with ch4
	VPORT_MAP_MAX
} NC_VPORT_MAP;


void NVP6168_AutoDetection_Proc(void);
void NVP6168_VO_Port_Set(NC_VPORT_MAP vo_port);

#endif
