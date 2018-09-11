//=============================================================================
//  Header Declaration
//=============================================================================
#include <stdio.h>
#include "common.h"

//=============================================================================
//  Global Variable Declaration
//=============================================================================
BOOL bScreenFreeze = CLEAR;
u8 pre_special_mode = LEFT_TOP;

//=============================================================================
//  Static Variable Declaration
//=============================================================================
static keycode_t current_keycode = KEYCODE_NONE;
static keycode_t led_keycode = KEYCODE_NONE;
static key_mode_e key_mode = KEY_MODE_LONG;
static key_mode_e saved_key_mode = KEY_MODE_LONG;
static keystatus_e key_status = KEY_STATUS_RELEASED;
static BOOL bKeyReady = CLEAR;
static keydata_e current_keydata = KEY_NONE;
static u8 pre_split_mode = 0;

//=============================================================================
//  Constant Array Declaration (data table)
//=============================================================================
const static keycode_t keycode_table[] =
{
	KEYCODE_CH1, 		//0xFE	1111 1110	254
 	KEYCODE_CH2, 		//0xFD 	1111 1101	253
	KEYCODE_CH3, 		//0xFB 	1111 1011 	251
	KEYCODE_CH4, 		//0xF7 	1111 0111 	247

	KEYCODE_SPLIT, 		//0xEF 	1110 1111 	239
	KEYCODE_FREEZE, 	//0xDF 	1101 1111 	223
	KEYCODE_SEQUENCE, 	//0xBF 	1011 1111 	191
	KEYCODE_NONE		//0x7f	0111 1111	127
};

const static keydata_e key_table[] =
{
	KEY_FULL_CH1,
	KEY_FULL_CH2,
	KEY_FULL_CH3,
	KEY_FULL_CH4,
//-------------------------
	KEY_4SPLIT,
	KEY_FREEZE,
	KEY_AUTO_SEQ,
};

#define NUM_OF_KEYS				sizeof(key_table) //7

#define KEYCOUNT_SHORT			4
#define KEYCOUNT_REPEAT			40	//400ms
#define KEYCOUNT_LONG			80	//800ms

#define VALID_LONG_KEY(key)		(key == KEY_FREEZE)?TRUE:FALSE

#define VALID_REPEAT_KEY(key)	\
	((key == KEY_FULL_CH1) || (key == KEY_FULL_CH2) || \
	 (key == KEY_FULL_CH3) || (key == KEY_FULL_CH4))?TRUE:FALSE
//=============================================================================
//  Function Definition
//=============================================================================

//-----------------------------------------------------------------------------
// Interface
//-----------------------------------------------------------------------------
void SetKeyMode(key_mode_e mode)
{
	saved_key_mode = mode;
	if(GetKeyStatus() == KEY_STATUS_RELEASED)
	{
		key_mode = mode;
	}
}

key_mode_e GetKeyMode(void)
{
	return key_mode;
}
//-----------------------------------------------------------------------------
keycode_t GetKeyCode(keydata_e key)
{
	keycode_t code = KEYCODE_NONE;
	u8 i;

	for(i=0; i<NUM_OF_KEYS; i++)
	{
		if(key == key_table[i])
		{
			break;
		}
	}

	if(i < NUM_OF_KEYS)
	{
		code = keycode_table[i];
	}

	return code;
}
//-----------------------------------------------------------------------------
void UpdateKeyStatus(keystatus_e status)
{
	key_status = status; 
}
keystatus_e GetKeyStatus(void)
{
	return key_status;
}
//-----------------------------------------------------------------------------
void SetKeyReady(void)
{
	bKeyReady = SET;
}
void ClearKeyReady(void)
{
	bKeyReady = CLEAR;
}
BOOL IsKeyReady(void)
{
	return bKeyReady;
}
//-----------------------------------------------------------------------------
void UpdateKeyData(keydata_e key)
{
	current_keydata = key;
}
keydata_e GetCurrentKey(void)
{
	return current_keydata;
}
//-----------------------------------------------------------------------------
BOOL IsScreenFreeze(void)
{
	return bScreenFreeze;
}

//-----------------------------------------------------------------------------
//  Key Functions
//-----------------------------------------------------------------------------

void Key_Scan(void)
{
	keycode_t key_code = KEYCODE_NONE;

	// All key columns are HIGH and LED rows are LOW
	KEY_LED1_5_HIGH;
	KEY_LED2_6_HIGH;
	KEY_LED3_7_HIGH;
	KEY_LED4_HIGH;

	KEY_LED0_LOW;
	KEY_LED1_LOW;

	KEY_DATA_INPUT_MODE;
       
	//Scan KROW0
	KEY_ROW1_HIGH;
	KEY_ROW0_LOW;
	
	Delay_us(10);

	if(LOW == KEY_DATA1_5_INPUT)
		key_code = KEYCODE_CH1;
	else if(LOW== KEY_DATA2_6_INPUT)
		key_code = KEYCODE_CH2;
	else if(LOW == KEY_DATA3_7_INPUT)
		key_code = KEYCODE_CH3;
	else if(LOW == KEY_DATA4_INPUT)
		key_code = KEYCODE_CH4;

	//Scan KROW1
	KEY_ROW0_HIGH;
	KEY_ROW1_LOW;

	Delay_us(10);

	if(LOW == KEY_DATA1_5_INPUT)
		key_code = KEYCODE_SPLIT;
	else if(LOW== KEY_DATA2_6_INPUT)
		key_code = KEYCODE_FREEZE;
	else if(LOW == KEY_DATA3_7_INPUT)
		key_code = KEYCODE_SEQUENCE;

	KEY_ROW1_HIGH;

	// Update current_keycode
	current_keycode = key_code;
	if(key_code != KEYCODE_NONE)
	{
		led_keycode = key_code;
		UpdateKeyStatus(KEY_STATUS_PRESSED);
	}
	else
	{
		UpdateKeyStatus(KEY_STATUS_RELEASED);
	}
}

void Key_Led_Ctrl(void)
{
	static u8 stage = KEYLED_STAGE_LEFT;
	keycode_t leds;

	if(GetKeyStatus() == KEY_STATUS_RELEASED)
	{
		leds = GetKeyCode(GetCurrentKey());
	}
	else
	{
		leds = led_keycode;
	}

	if(leds != KEYCODE_NONE)
	{
		KEY_DATA_OUTPUT_MODE;

		if(stage == KEYLED_STAGE_LEFT)
		{
			KEY_LED0_LOW;
			if((leds & 0x0F) != 0x0F)
			{
				KEY_LED_ON(leds);
			}
			KEY_LED1_HIGH;
		}
		else if(stage == KEYLED_STAGE_RIGHT)
		{
			KEY_LED1_LOW;
			if((leds & 0xF0) != 0xF0)
			{
				KEY_LED_ON((u32)((leds>>4)|0xFFFFFFF0));
			}
			KEY_LED0_HIGH;
		}
	}
	// Change stage for the next time
	stage = (++stage) % KEYLED_STAGE_MAX;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void Key_Check(void)	
{
	const keycode_t *pKeyCode;

	static u8 debounce_cnt = KEYCOUNT_SHORT;
	static u8 key_cnt = 0;
	static keydata_e processing_key_data = KEY_NONE;
	static BOOL bLongKey = CLEAR;
	static BOOL bRepeatKey = CLEAR;

	u8 i;

	if(current_keycode != KEYCODE_NONE)
	{
		pKeyCode = keycode_table;
		UpdateKeyStatus(KEY_STATUS_PRESSED);

		// Find index of key code table
		for(i=0; i< NUM_OF_KEYS; i++)
		{
			if(*(pKeyCode+i) == current_keycode)
			{
				break;
			}
		}

		if(i < NUM_OF_KEYS)
		{
			if(key_table[i] != processing_key_data)
			{
				processing_key_data = key_table[i];
				key_cnt = 0;
			}
			else
			{
				key_cnt++;
			}

			if(key_cnt >= debounce_cnt)
			{
				switch (GetKeyMode())
				{
				case KEY_MODE_SHORT:
					if(CLEAR == bRepeatKey)
					{
						bRepeatKey = SET;
						bLongKey = CLEAR;
						UpdateKeyData(processing_key_data);
						SetKeyReady();
					}
					break;

				case KEY_MODE_REPEAT:
					UpdateKeyData(processing_key_data);//current_keydata = processing_key_data;
					debounce_cnt = KEYCOUNT_REPEAT;
					if(SET == bRepeatKey)
					{
						if(FALSE == VALID_REPEAT_KEY(processing_key_data))
						{
							bRepeatKey = SET;
							key_cnt = 0;
							return;
						}
						debounce_cnt = KEYCOUNT_SHORT;
					}
					SetKeyReady();
					bRepeatKey = SET;
					key_cnt = 0;
					break;

				case KEY_MODE_LONG:
					bLongKey = SET;
					if((VALID_LONG_KEY(processing_key_data)) && (key_cnt > KEYCOUNT_LONG))
					{
				  		bRepeatKey = SET;
				  		UpdateKeyData(processing_key_data | (keydata_e)KEY_LONG);
						SetKeyReady();
					}
					else
					{
						UpdateKeyData(processing_key_data);
					}
					break;

				case KEY_MODE_MAX:
				default:
					// Do nothing
					break;
				}
			}
		}
		else //reset all flags and count.
		{
			bLongKey = CLEAR;
			bRepeatKey = CLEAR;
			debounce_cnt = KEYCOUNT_SHORT;
			key_cnt = 0;
			UpdateKeyStatus(KEY_STATUS_RELEASED);
		}
	}
	else
	{
		if(SET == bLongKey)
		{
			bLongKey = CLEAR;
			SetKeyReady();
		}
		bRepeatKey = CLEAR;
		debounce_cnt = KEYCOUNT_SHORT;
		key_cnt = 0;
		UpdateKeyStatus(KEY_STATUS_RELEASED);
		if(GetKeyMode() != saved_key_mode)
		{
			SetKeyMode(saved_key_mode);
		}
	}
}

void Key_Proc(void)
{
	static keydata_e previous_keydata = KEY_NONE;
	keydata_e key = GetCurrentKey();
	BOOL autoSeq_skipNoVideoChannel;


	if(IsKeyReady()==TRUE)
	{
		ClearKeyReady();

		switch(key)
		{
			case KEY_FULL_CH1 : 
			case KEY_FULL_CH2 : 
			case KEY_FULL_CH3 : 
			case KEY_FULL_CH4 : 
				// If key is changed...
				if(previous_keydata != key /*|| SDIRX_change_flag	Louis block*/)
				{
					Erase_OSD();
					bScreenFreeze = CLEAR;
					bAuto_Seq_Flag = CLEAR;
					bMode_change_flag = SET;
					//InputSelect = VIDEO_SDI_2HD_POP;
					pre_split_mode = sys_status.current_split_mode = key-1;
					Set_border_line();
				}
				break;
				
			case KEY_4SPLIT : 
				if(previous_keydata != key /*|| SDIRX_change_flag	Louis block*/)
				{
					if(pre_split_mode != SPLITMODE_SPLIT4 || bAuto_Seq_Flag || bScreenFreeze)
					{
						Erase_OSD();
					}
					bScreenFreeze = CLEAR;
					bAuto_Seq_Flag = CLEAR;
					bMode_change_flag = SET;
					//InputSelect = VIDEO_SDI_2HD_POP;
					pre_split_mode = sys_status.current_split_mode = SPLITMODE_SPLIT4;
#if 0 //Louis
				    SGQ_4CH_INIT(change_mode[cmode]);
#endif
					Set_border_line();
				}
				break;
			case KEY_FREEZE :
				bAuto_Seq_Flag = CLEAR;
				if(bScreenFreeze == CLEAR)
				{
					bScreenFreeze = SET;
					MDINHIF_RegField(MDIN_LOCAL_ID, 0x040, 1, 1, 1);	//main freeze On
				}
				else
				{
					bScreenFreeze = CLEAR;
					MDINHIF_RegField(MDIN_LOCAL_ID, 0x040, 1, 1, 0);	//main freeze Off
				}
				break;

			case KEY_AUTO_SEQ :
				Read_NvItem_AutoSeqLossSkip(&autoSeq_skipNoVideoChannel);
				if((OFF == autoSeq_skipNoVideoChannel) || ((vVideo_Loss&0x0000000f) != 0x0000000f))
				{
					if(bAuto_Seq_Flag == CLEAR)
					{
						Erase_OSD();
					}
					//bMode_change_flag = SET;
					bScreenFreeze = CLEAR;
					MDINHIF_RegField(MDIN_LOCAL_ID, 0x040, 1, 1, 0);	//main freeze Off
					Auto_Seq_Init();
				}
				break;

			case KEY_MENU :
				bAuto_Seq_Flag = CLEAR;
				bScreenFreeze = SET;
				MDINHIF_RegField(MDIN_LOCAL_ID, 0x040, 1, 1, 0);	//main freeze Off
				Enter_SetUP();
				break;

		}
		previous_keydata = key & (~KEY_LONG);
	}
}


