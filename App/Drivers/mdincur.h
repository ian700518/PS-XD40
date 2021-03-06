//----------------------------------------------------------------------------------------------------------------------
// (C) Copyright 2010  Macro Image Technology Co., LTd. , All rights reserved
// 
// This source code is the property of Macro Image Technology and is provided
// pursuant to a Software License Agreement. This code's reuse and distribution
// without Macro Image Technology's permission is strictly limited by the confidential
// information provisions of the Software License Agreement.
//-----------------------------------------------------------------------------------------------------------------------
//
// File Name   		:  MDINCUR.H
// Description 		:  This file contains typedefine for the driver files	
// Ref. Docment		: 
// Revision History 	:

#ifndef		__MDINCUR_H__
#define		__MDINCUR_H__

// -----------------------------------------------------------------------------
// Include files
// -----------------------------------------------------------------------------
#ifndef		__MDINTYPE_H__
#include	 "mdintype.h"
#endif

// -----------------------------------------------------------------------------
// Struct/Union Types and define
// -----------------------------------------------------------------------------

typedef struct {
	WORD	w;			// the width of cursor bitmap, in pixels
	WORD	h;			// the height of cursor bitmap, in pixels
	DWORD	addr;		// the start address of cursor bitmap in MDIN-sdram

	WORD	r;			// the row+bank of cursor bitmap, is used only internal operation
	WORD	c;			// the column of cursor bitmap, is used only internal operation

}	stPACKED CURSOR_BMP_INFO, *PCURSOR_BMP_INFO;

typedef struct {
	PBYTE	pBuff;		// the pointer to palette of cursor bitmap
	DWORD	size;		// the size of palette of cursor bitmap, in bytes

}	stPACKED CURSOR_PAL_INFO, *PCURSOR_PAL_INFO;

typedef struct {
	WORD	ctrl;		// the display control of cursor bitmap
	WORD	x;			// the left corner of cursor display position
	WORD	y;			// the top corner of cursor display position
	BYTE	alpha;		// the alpha-blending of cursor layer
	BYTE	cycle;		// the period of blinking, in vsync

	CURSOR_BMP_INFO stBMP;
	CURSOR_PAL_INFO stPAL;

}	stPACKED CURSOR_CTL_INFO, *PCURSOR_CTL_INFO;

#define		CURSOR_DISPLAY_ON		0x0001
#define		CURSOR_DISPLAY_OFF		0x0000

#define		CURSOR_16BIT_16COLOR	0x0000
#define		CURSOR_32BIT_8COLOR		0x0100
#define		CURSOR_32BIT_4COLOR		0x0200
#define		CURSOR_COLORMODE_MASK	0x0300

#define		CURSOR_REPEAT_H_ON		0x0004
#define		CURSOR_REPEAT_H_OFF		0x0000
#define		CURSOR_REPEAT_V_ON		0x0008
#define		CURSOR_REPEAT_V_OFF		0x0000

#define		CURSOR_COLORKEY_ON		0x0010
#define		CURSOR_COLORKEY_OFF		0x0000

#define		CURSOR_BLINK_ON			0x0020
#define		CURSOR_BLINK_OFF		0x0000

#define		CURSOR_BLINK_INVERSE	0x0040
#define		CURSOR_BLINK_BLACK		0x0000

#define		CURSOR_OPAQUE			31
#define		CURSOR_TRANSPARENT		0

// -----------------------------------------------------------------------------
// Exported function Prototype
// -----------------------------------------------------------------------------

MDIN_ERROR_t MDINCUR_SetCursorConfig(PCURSOR_CTL_INFO pINFO);
MDIN_ERROR_t MDINCUR_EnableCursor(PCURSOR_CTL_INFO pINFO, BOOL OnOff);
MDIN_ERROR_t MDINCUR_SetCursorPosition(PCURSOR_CTL_INFO pINFO, WORD x, WORD y);
MDIN_ERROR_t MDINCUR_EnableCursorRepeat(PCURSOR_CTL_INFO pINFO, BOOL h_rpt, BOOL v_rpt);
MDIN_ERROR_t MDINCUR_SetCursorAlpha(PCURSOR_CTL_INFO pINFO, BYTE alpha);
MDIN_ERROR_t MDINCUR_EnableCursorBlink(PCURSOR_CTL_INFO pINFO, BOOL OnOff);
MDIN_ERROR_t MDINCUR_SetCursorBlinkInverse(PCURSOR_CTL_INFO pINFO, BOOL OnOff);
MDIN_ERROR_t MDINCUR_SetCursorBlinkCycle(PCURSOR_CTL_INFO pINFO, BYTE cycle);
MDIN_ERROR_t MDINCUR_EnableCursorColorKey(PCURSOR_CTL_INFO pINFO, BOOL OnOff);
MDIN_ERROR_t MDINCUR_SetCursorBMPInfo(PCURSOR_CTL_INFO pINFO, BYTE w, BYTE h, DWORD addr);
MDIN_ERROR_t MDINCUR_SetCursorPalette(PCURSOR_CTL_INFO pINFO, BYTE size, PBYTE pBuff);


#endif	/* __MDINCUR_H__ */
