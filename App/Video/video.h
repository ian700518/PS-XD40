//----------------------------------------------------------------------------------------------------------------------
// (C) Copyright 2008  Macro Image Technology Co., LTd. , All rights reserved
// 
// This source code is the property of Macro Image Technology and is provided
// pursuant to a Software License Agreement. This code's reuse and distribution
// without Macro Image Technology's permission is strictly limited by the confidential
// information provisions of the Software License Agreement.
//-----------------------------------------------------------------------------------------------------------------------
//
// File Name   		:  VIDEO.H
// Description 		:  This file contains typedefine for the driver files	
// Ref. Docment		: 
// Revision History 	:

#ifndef		__VIDEO_H__
#define		__VIDEO_H__

// -----------------------------------------------------------------------------
// Include files
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Struct/Union Types and define
// -----------------------------------------------------------------------------
#define MDIN_MULTI_DEVICE

#ifdef MDIN_MULTI_DEVICE		// added by kukuri

typedef enum {
	VIDEO_INPUT_NONE = 0,
	VIDEO_DIGITAL_NVP6158_A,
//	VIDEO_DIGITAL_NVP6158_B,
	VIDEO_DIGITAL_NVP6158_AB,
	VIDEO_DIGITAL_NVP6158_C,
//	VIDEO_DIGITAL_NVP6158_D,
	VIDEO_DIGITAL_NVP6158_CD,
	VIDEO_DIGITAL_NVP6158_AC,
	VIDEO_DIGITAL_NVP6158_AD,
	VIDEO_DIGITAL_NVP6158_ABCD
//	VIDEO_DIGITAL_NVP6158_MAX
} MDIN_VIDEO_INPUT_t;

//#define		VIDEO_DIGITAL_NVP6158_A		0
//#define		VIDEO_DIGITAL_NVP6158_B		1
//#define		VIDEO_DIGITAL_NVP6158_AB	2
//#define		VIDEO_DIGITAL_NVP6158_C		3
//#define		VIDEO_DIGITAL_NVP6158_D		4
//#define		VIDEO_DIGITAL_NVP6158_CD	5

typedef enum
{
	MDIN_ID_A = 0,
	MDIN_ID_B,
	MDIN_ID_C,
//	MDIN_ID_D,
	MDIN_ID_MAX
} MDIN_CHIP_ID_t;

#define 		MDIN_A				0
#define 		MDIN_B				1
#define 		SELECT_MDIN(x)			selectedMDIN = x		

#else

#if defined(SYSTEM_USE_MDIN340)
#define		VIDEO_VDCNV_TVP5160			0
#define		VIDEO_VDCNV_TW9910			1
#define		VIDEO_DIGITAL_HDMI			2
//#define		VIDEO_EXTERNAL_IN				3		   //by hungry 2012.02.15
#define		VIDEO_DIGITAL_SDI			3				   //by hungry 2012.02.15
#define		VIDEO_EXTERNAL_IN			4				   //by hungry 2012.02.15
#endif

#if defined(SYSTEM_USE_MDIN325)||defined(SYSTEM_USE_MDIN325A)
#define		VIDEO_VDCNV_TVP5160			0
#define		VIDEO_VDCNV_TW2866			1
#define		VIDEO_ADCNV_COMPONENT		2
#define		VIDEO_ADCNV_PC_RGB			3
#define		VIDEO_DIGITAL_HDMI			4
#define		VIDEO_DIGITAL_SDI			5				   	//by hungry 2012.02.15
#define		VIDEO_EXTERNAL_IN			6		   			//by hungry 2012.02.15
#define		VIDEO_VDCNV_4CH_IN			7					//by hungry 2012.02.15
#endif

#if defined(SYSTEM_USE_MDIN380)
#define		VIDEO_VDCNV_TVP5160			0
#define		VIDEO_VDCNV_TW2866			1
#define		VIDEO_ADCNV_COMPONENT		2
#define		VIDEO_ADCNV_PC_RGB			3
#define		VIDEO_DIGITAL_HDMI			4
#define		VIDEO_DIGITAL_SDI			5				   //by hungry 2012.02.15
#define		VIDEO_VDCNV_4CH_IN			6
#define		VIDEO_ADCNV_2HD_IN			7
#define		VIDEO_DIGITAL_SDI2			8				   //by flcl 2013.04.23
#define		VIDEO_SDI_2HD_POP			9
#endif

#endif	//MDIN_MULTI_DEVICE kukuri

//#define VIDEO_CORP_NONE				0x00
//#define VIDEO_CROP_H				0x01
//#define VIDEO_CROP_V				0x02
//
//#define VIDEO_CORP_HALF				0x01
//#define VIDEO_CORP_QUAD				0x02

// ----------------------------------------------------------------------
// Exported Variables
// ----------------------------------------------------------------------
extern MDIN_VIDEO_INFO	 stVideo_A, stVideo_B, stVideo_C;
//extern MDIN_VIDEO_INFO stVideo;


//extern BYTE AdjInterWND,  InputSelect, InputSelOld,  SrcSyncInfo;
//extern BYTE SrcMainFrmt, PrevSrcMainFrmt, SrcMainMode, PrevSrcMainMode;
//extern BYTE OutMainFrmt, PrevOutMainFrmt, OutMainMode, PrevOutMainMode;
//extern BYTE SrcAuxFrmt, PrevSrcAuxFrmt, SrcAuxMode, PrevSrcAuxMode;
//extern BYTE OutAuxFrmt, PrevOutAuxFrmt, OutAuxMode, PrevOutAuxMode;
//extern BYTE AdcVideoFrmt, PrevAdcFrmt, EncVideoFrmt, PrevEncFrmt;

// -----------------------------------------------------------------------------
// Exported function Prototype
// -----------------------------------------------------------------------------
void CreateVideoInstance(void);
//void InitInputSource(void);
void SetInputSource(BYTE input);
void VideoProcessHandler(void);
void VideoHTXCtrlHandler(void);
//void Request2VideoProcess(void);
void Set_DisplayWindow(eDisplayMode_t displayMode);

#endif	/* __VIDEO_H__ */
