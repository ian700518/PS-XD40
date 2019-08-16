/********************************************************************************
 *
 *  Copyright (C) 2017 	NEXTCHIP Inc. All rights reserved.
 *  Module		: The decoder's video format module
 *  Description	: ACP-F/W information
 *  Author		:
 *  Date         :
 *  Version		: Version 1.0
 *
 ********************************************************************************
 *  History      :
 *
 *
 ********************************************************************************/
#ifndef _RAPTOR4_COAX_FIRMUP_
#define _RAPTOR4_COAX_FIRMUP_

#include "../raptor4_fmt.h"

/********************************************************************************
 *                              ENUMERATION
 *********************************************************************************/
typedef enum
{
	ACP_FIRMUP_READY,				// not ready
	ACP_FIRMUP_POSSIBLE,			// possible updating firmware
	ACP_FIRMUP_TIMEOUT,				// time out to update fw
	ACP_FIRMUP_NOTSUPPORT,			// camera don't support to update fw

	ACP_FIRMUP_READY_ISP_STATUS_OK,
	ACP_FIRMUP_READY_ISP_STATUS_NG,

	ACP_FIRMUP_FAILED_MAKE_DIR,		// failed to mount usb
	ACP_FIRMUP_REQUEST_SINGE_DISP,	// Request Single display
	ACP_FIRMUP_THERE_IS_NOFILE,		// there is no F/W file
	ACP_FIRMUP_FWFILE_IS_ZERO,		// F/W file size is 0
	ACP_FIRMUP_EXIST_FW_FILE,		// There is F/W file
	ACP_FIRMUP_FAILE_OPEN_FILE,		// failed to open file

	ACP_FIRMUP_FWUP_START,			// start to update F/W
	ACP_FIRMUP_TIMEOUT_PATTERN,		// timeout to change test pattern(1080p25p)
	ACP_FIRMUP_TIMEOUT_FW_START,	// failed to start F/W(ready)
	ACP_FIRMUP_FAILED_SEND_DATA,	// failed to send F/W data
	ACP_FIRMUP_SUCCESS_SEND_DATA,	// success to send F/W data

	ACP_FIRMUP_READY_PATTERN,		// ready to change test pattern
	ACP_FIRMUP_CHANGED_PATTERN,		// checked test pattern
	ACP_FIRMUP_READY_FW_START,		// ready to update F/W start
	ACP_FIRMUP_CHECKED_FW_START,	// checked FW start

	ACP_FIRMUP_MAX

} ACP_FIRMUP_MODE;


typedef struct _nc_coax_firmup_s
{
	NC_U8 Chn;

	unsigned int	channel;                // FirmUP Channel
	unsigned int	cp_mode;                // Channel Format
	char 	filename[64];          		    //
	char 	filePullname[64+32];   			// FirmUP FileNmae
	unsigned int	filesize;
	unsigned int	filechecksum;			// (sum of file&0x0000FFFFF)
	unsigned int	currentpacketnum;		// current packet sequnce number(0,1,2........)
	unsigned int	filepacketnum;			// file packet number = (total size/128bytes), if remain exist, file packet number++
	NC_U8 	onepacketbuf[128+32];

	unsigned int	currentFileOffset;		// Current file offset
	unsigned int	readsize;				// currnet read size

	unsigned int 	receive_addr;

	unsigned int	ispossiblefirmup[16]; 	// is it possible to update firmware?
	int 			result;

	int				appstatus[16];			// Application status

} nc_coax_firmup_s, *pnc_coax_firmup_s;

typedef struct FIRMWARE_FILE_DEC_INFO
{
	char firmup_fileName[1024];             // FirmUP file name
	int strlen;                             // FirmUP file name length

} FIRMWARE_FILE_DEC_INFO;

typedef struct FIRMWARE_START_INFO          // FirmUP thread argument
{
	int ch;                                 // FirmUP Channel
	int fileNo;                             // Allocation file number

} FIRMWARE_START_INFO;


/*
 * void NC_APP_VD_COAX_FirmUP_FW_File_Size_Set(int size)
 * int  NC_APP_VD_COAX_FirmUP_FW_File_Size_Get(void)
 * void NC_APP_VD_COAX_FirmUP_FW_Packet_Size_Set(int size)
 * int  NC_APP_VD_COAX_FirmUP_FW_Packet_Size_Get(int size)
 * void __NC_APP_VD_COAX_FirmUP_UI_Status_Set(char *pString)
 * int  NC_APP_VD_COAX_FirmUP_Status_Get(char *pString)
 * void NC_APP_VD_COAX_FirmUP_ProgressBar_Status_Set(int percentage)
 * int  NC_APP_VD_COAX_FirmUP_ProgressBar_Status_Get(void)
 * int  NC_APP_VD_USB_Mount( void )
 * int  NC_APP_VD_USB_Umount( void )
 * int  __NC_APP_VD_COAX_FirmUP_USB_Mount( void )
 * void __NC_APP_VD_COAX_FirmUP_USB_Umount( void )
 * int  __NC_APP_VD_COAX_FirmUP_File_Memory_Alloc( char *path, int file_cnt )
 * void __NC_APP_VD_COAX_FirmUP_File_Memory_Alloc_Free( void )
 * int  NC_APP_VD_COAX_FirmUP_File_Count_Get( char *Path )
 * void NC_APP_VD_COAX_FirmUP_File_Select_Get( char *pfileName, int fileNo )
 * int  __NC_APP_VD_COAX_FirmUP_File_information_Get( FILE *pFile, unsigned char *firmware_name, void *p_param )
 * void __NC_APP_VD_COAX_FirmUP_Fail(FILE *pFile)
 * void __NC_APP_VD_COAX_FirmUP_Logical_Flag_Init( void )
 * int  __NC_APP_VD_COAX_FirmUP_ACP_Header_Check(void *p_param)
 * int  __NC_APP_VD_COAX_FirmUP_Ready_Check(void *p_param)
 * int  __NC_APP_VD_COAX_FirmUP_Start_Check(void *p_param)
 * int  __NC_VD_COAX_Firmware_Update_Data_Send( FILE *pFile, void *p_param )
 * int __NC_APP_VD_COAX_FirmUP_End_Check(void *p_param)
 * void *t_NC_APP_VD_COAX_FirmUP_CoaxFWUpdate_Start( void *arg )
 * void NC_APP_VD_COAX_FirmUP_CoaxFWUpdate_Start( int Ch, int fileNum, NC_FORMAT_STANDARD format_standard  )
 * int NC_APP_VD_COAX_System_FirmUP_File_Check(void)
 * void NC_APP_VD_COAX_System_FirmUP_Check(void)
 *
 */


// Allocation firmwUP file list, Interworking with GUI
int  NC_APP_VD_COAX_FirmUP_File_Count_Get( char *Path );                     // FirmUP file count, Allocates memory as many as the number of firmware files.
void NC_APP_VD_COAX_FirmUP_File_Select_Get( char *pfileName, int fileNo );   // Returns the file name corresponding to the file number. parameter out *pfileName
int  NC_APP_VD_COAX_FirmUP_Status_Get(char *pString);                        // FirmUP check logical status in GUI
int  NC_APP_VD_COAX_FirmUP_ProgressBar_Status_Get(void);                     // Returns the firmware data transfer rate. 0 ~ 100
void NC_APP_VD_COAX_FirmUP_CoaxFWUpdate_Start( int Ch, int fileNum  );       // FirmUP Start


// Internal use function
int __NC_APP_VD_COAX_FirmUP_USB_Mount( void );
void __NC_APP_VD_COAX_FirmUP_USB_Umount( void );

int __NC_APP_VD_COAX_FirmUP_File_Memory_Alloc( char *path, int file_cnt );
void __NC_APP_VD_COAX_FirmUP_File_Memory_Alloc_Free( void );
void __NC_APP_VD_COAX_FirmUP_UI_Status_Set(char *pString);

void __NC_APP_VD_COAX_FirmUP_Fail(FILE *pFile);
void __NC_APP_VD_COAX_FirmUP_Logical_Flag_Init( void );

int __NC_APP_VD_COAX_FirmUP_ACP_Header_Check(void *p_param);
int __NC_APP_VD_COAX_FirmUP_Ready_Check(void *p_param);
int __NC_APP_VD_COAX_FirmUP_Start_Check(void *p_param);
int __NC_VD_COAX_Firmware_Update_Data_Send( FILE *pFile, void *p_param );
int __NC_APP_VD_COAX_FirmUP_End_Check(void *p_param);
void NC_APP_VD_COAX_System_FirmUP_Check(void);

int NC_APP_VD_USB_Umount( void );
int NC_APP_VD_USB_Mount( void );

#endif
