#pragma once
#include "pxBufferDef.h"
#include <vector>
using namespace std;

#define DEFAULT_BUFFER_LIST_LEN (200)
#define DEFAULT_BUFFER_SIZE     (1024*1024)

class CPxBufferPool
{
public:
	CPxBufferPool(void);
	~CPxBufferPool(void);

public:
	int        Init(int in_nBufferSize, int in_nBufferPoolLen = DEFAULT_BUFFER_LIST_LEN);
	void       Release();

public:
	int        GetEmptyBufferPos();
	void       SetBufferAt(int in_nPos, SPxBuffer *in_psBuffer );
	SPxBuffer *GetBufferAt(int in_nPos);
	int        GetBufferSize();

private:
	vector <SPxBuffer> m_vRingBuffer;
	CRITICAL_SECTION   m_csRingBuffer;

	int m_nBufferListLen;
	int m_nCurPos;// ָ����һ�����е�buffer���±�

	int m_nBufferSize; // �ڴ����ÿ���ڴ�Ĵ�С
};