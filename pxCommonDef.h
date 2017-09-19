#ifndef _PX_COMMON_DEF_H
#define _PX_COMMON_DEF_H

#include <queue>
#include <vector>
using namespace std;

#include "Windows.h"
#include "pxBufferPool.h"
#include "pxQueueBuffer.h"
#include "pxErrorDef.h"
#include "pxBufferDef.h"


// ��Ƶ�ɼ�
#include <mmsystem.h>

// �����ڴ��

// YUV
extern CPxBufferPool      g_oYUVBufferPool;      // YUV�ڴ��
extern CPxQueueBuffer     g_oYUVQueueBuffer; // �洢�ɼ���YUV����

// PCM
extern CPxBufferPool      g_oPCMBufferPool;      // PCM�ڴ��
extern CPxQueueBuffer     g_oPCMQueueBuffer; // �洢�ɼ���PCM����

// H.264/AAC
extern CPxBufferPool      g_oCodedBufferPool;    // �洢��������ݵ��ڴ��(H.264/AAC)
extern CPxQueueBuffer     g_oCodedQueueBuffer;   // �洢��������ݵĶ���

extern int gettimeofday(struct timeval*, int*);

extern UINT64 GetCurrentTimestamp();

#define VIDEO_SAVE_BMP  0
#define VIDEO_SAVE_YUV  0
#define VIDEO_SAVE_H264 0
#define VIDEO_SAVE_H264_FROM_BUFFERLIST 1
#define DEBUG_VIDEO_TIME_ANALYZE 0

#define DEBUG_AUDIO_CAPTURE_PCM 1
#define AUDIO_SAVE_PCM 1
#define AUDIO_SAVE_PCM_FROM_BUFFERLIST 1
#define AUDIO_SAVE_AAC 0
#define AUDIO_SAVE_AAC_FROM_BUFFERLIST 0

#define AV_RB24(x)  ((((uint8_t*)(x))[0] << 16) | \
	(((uint8_t*)(x))[1] <<  8) | \
	((uint8_t*)(x))[2])
#define AV_RB32(x)  ((((uint8_t*)(x))[0] << 24) | \
	(((uint8_t*)(x))[1] << 16) | \
	(((uint8_t*)(x))[2] <<  8) | \
	((uint8_t*)(x))[3])

#endif