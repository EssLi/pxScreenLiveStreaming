#ifndef _PX_COMMON_DEF_H
#define _PX_COMMON_DEF_H

#include <queue>
#include <vector>
using namespace std;

#include "Windows.h"
#include "pxBufferPool.h"

// �����ڴ��
extern struct SPxBuffer;
extern vector <SPxBuffer> g_vlpBufferPool;
extern SPxBufferPool g_oPxBufferPool;

// �����������ݵĶ���
extern queue <SPxBuffer> g_qCodedBufferList;

extern int gettimeofday(struct timeval*, int*);

#define SAVE_BMP  0
#define SAVE_YUV  0
#define SAVE_H264 1

#endif