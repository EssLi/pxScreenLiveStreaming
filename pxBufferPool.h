#pragma once

#define DEFAULT_BUFFER_LIST_LEN (200)
#define DEFAULT_BUFFER_SIZE  (1024*1024)

typedef enum EPxMediaType
{
	kePxMediaType_Invalid = -1,
	kePxMediaType_Video,
	kePxMediaType_Audio,
	kePxMediaType_Cnt
}EPxMediaType;

typedef unsigned char * LPBYTE;
typedef unsigned char uint8_t;

struct SPxBuffer
{
	EPxMediaType eMediaType;
	LPBYTE       lpBuffer;
	int          nDataLength;
	unsigned int uiTimestamp;

	SPxBuffer()
	{
		eMediaType  = kePxMediaType_Invalid;
		lpBuffer    = NULL;
		nDataLength = 0;
		uiTimestamp = 0;
	}

	~SPxBuffer()
	{
		eMediaType  = kePxMediaType_Invalid;
		lpBuffer    = NULL;
		nDataLength = 0;
		uiTimestamp = 0;
	}
};

class SPxBufferPool
{
public:
	SPxBufferPool(void);
	~SPxBufferPool(void);

public:
	int InitBufferPool(int in_nBufferSize,  
		               int in_nBufferPoolLen = DEFAULT_BUFFER_LIST_LEN);

	void ReleaseBufferPool();

	int GetEmptyBufferPos();
	void SetBufferAt(int in_nPos, 
		             EPxMediaType in_keMediaType, 
					 uint8_t *in_ui8Data, 
					 int in_nDataLength, 
					 unsigned int uiTimestamp);

public:
	int m_nBufferListLen;
	int m_nCurPos;// ָ����һ�����е�buffer���±�
	CRITICAL_SECTION g_csBufferPool;
};