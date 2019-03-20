﻿#ifndef __RAPTOR3_AUDIO_H_
#define __RAPTOR3_AUDIO_H_

typedef enum NC_AUDIO_MASTER_SLAVE
{
	AudioMaster = 0,
	AudioSlave,

}NC_AUDIO_MASTER_SLAVE;

typedef enum NC_AUDIO_INTERFACE
{
	I2S = 0,
	DSP,
	SSP,
}NC_AUDIO_INTERFACE;

typedef enum NC_AUDIO_SAMPLING_RATE
{
	SampleRate_8K = 0,
	SampleRate_16K,
	SampleRate_32K,
	SampleRate_44_1K,

}NC_AUDIO_SAMPLING_RATE;

typedef enum NC_AUDIO_VOL
{
	MUTE = 0,
	Vol0 = 0,
	Vol1 = 1,
	Vol2,
	Vol3,
	Vol4,
	Vol5,
	Vol6,
	Vol7,
	Vol8,
	Vol9,
	Vol10,
	Vol11,
	Vol12,
	Vol13,
	Vol14,
	Vol15,
	Vol16,
	Vol17,
	Vol18,
	Vol19,
	Vol20,
	Vol21,
	Vol22,
	Vol23,
	Vol24,
	Vol25,
	Vol26,
	Vol27,
	Vol28,
	Vol29,
	Vol30,
	Vol31,
	Vol32,
	Vol33,
	Vol34,
	Vol35,
	Vol36,
	Vol37,
	Vol38,
	Vol39,
	Vol40,
	Vol41,
	Vol42,
	Vol43,
	Vol44,
	Vol45,
	Vol46,
	Vol47,
	Vol48,
	Vol49,
	Vol50,
	Vol51,
	Vol52,
	Vol53,
	Vol54,
	Vol55,
	Vol56,
	Vol57,
	Vol58,
	Vol59,
	Vol60,
	Vol61,
	Vol62,
	Vol63,
	Vol64,
	Vol65,
	Vol66,
	Vol67,
	Vol68,
	Vol69,
	Vol70,
	Vol71,
	Vol72,
	Vol73,
	Vol74,
	Vol75,
	Vol76,
	Vol77,
	Vol78,
	Vol79,
	Vol80,
	Vol81,
	Vol82,
	Vol83,
	Vol84,
	Vol85,
	Vol86,
	Vol87,
	Vol88,
	Vol89,
	Vol90,
	Vol91,
	Vol92,
	Vol93,
	Vol94,
	Vol95,
	Vol96,
	Vol97,
	Vol98,
	Vol99,
	Vol100,
	MAX = 100,
}NC_AUDIO_VOL;

typedef enum NC_AUDIO_CH
{
	LIVE_CH = 0,
	HDMI_CH,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
	CH_8,
	CH_9,
	CH_10,
	CH_11,
	CH_12,
	CH_13,
	CH_14,
	CH_15,
	CH_16,
	MIC_1,
	MIC_2,

}NC_AUDIO_CH;

#endif

