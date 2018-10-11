//=============================================================================
//  Header Declaration
//=============================================================================
#include <stdio.h>
#include "common.h"

//=============================================================================
//  Define & MACRO
//=============================================================================

//=============================================================================
//  Static Variable Declaration
//=============================================================================

//=============================================================================
//  Array Declaration (data table)
//=============================================================================

//=============================================================================
//  Function Definition
//=============================================================================
BYTE Get_CurrentDisplayMode(void)
{
	eDisplayMode_t displayMode;

	Read_NvItem_DisplayMode(&displayMode);
	return displayMode;
}

BYTE Get_CurrentDisplayChannel(void)
{
	eChannel_t channel;

	Read_NvItem_DisplayChannel(&channel);
	return (BYTE)channel;
}

void Set_DisplayMode_FullScreen(BYTE ch)
{
	Write_NvItem_DisplayChannel((eChannel_t)ch);
	Write_NvItem_DisplayMode(DISPLAY_MODE_FULL_SCREEN);
	// TO DO : Update displaying Channel here in full screen mode
	//Display_FullScreen(displayChannel);
}

void Set_DisplayMode_Quad(void)
{
	Write_NvItem_DisplayMode(DISPLAY_MODE_QUAD);
	Write_NvItem_DisplayChannel(CHANNEL_QUAD);

}

