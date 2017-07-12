#ifndef __pxRcordServerDef_H__
#define __pxRcordServerDef_H__
#include <vector>
using namespace std;

const int g_nMaxRecordTaskCount = 128;
const int g_nMaxDeviceClientCount = 8;
const int g_nMaxRecordCount = 8;
const int g_nMaxDeviceCount = 128;
const int g_nMaxBufferSize = 1*1024*1024;
const int g_nMaxVideoSize = 512*1024;

const int g_nMaxAdtsSamplingRates =	16;
const int g_nMetaData = 1024 * 320;
enum EPxRecordErrorType
{
	keRecordErrorType_Invliad = -1,
	keRecordErrorType_DeviceLost = 0,
	keRecordErrorType_DeviceTimeError = 1,
	keRecordErrorType_DeviceConnectError = 2,
	keRecordErrorType_DeviceHeadError = 3,
	keRecordErrorType_DeviceReadError = 4,	
	keRecordErrorType_Count
};

#define DEVICE_MPEG4	1
#define DEVICE_WMV9		2
#define DEVICE_MPEG2	3

#define VIEW_RECORD     1 //0Ԥ�� 1¼�񣨲�������������


enum EPxRecordAudioVideoType
{
	keRecordAudioVideoType_Invalid = 0,
	keRecordAudioVideoType_AudioOnly = 1,
	keRecordAudioVideoType_VideoOnly = 2,
	keRecordAudioVideoType_AVBoth = 3,
	keRecordAudioVideoType_Count
};

enum EPxRecordDeviceType
{
	keRecordDeviceType_Invliad = -1,
	keRecordDeviceType_WMV = 0,//wmv
	keRecordDeviceType_MPEG264,//MPEG264
	keRecordDeviceType_HK,//HK
	keRecordDeviceType_Last
};

enum EPxRecordDeviceClientType
{
	keRecordDeviceClientType_Invliad = 0,
	keRecordDeviceClientType_WMV9 = 1,//wmv����
	keRecordDeviceClientType_MPEG4_9601 = 2,//DVSС�׺�
	keRecordDeviceClientType_MPEG4_ENC = 3,//VGA
	keRecordDeviceClientType_MPEG4_NEWD = 4,//�п�ԭ��wmv���룬�ȱ��mpeg4����
	keRecordDeviceClientType_H264 = 7,//H.264
	keRecordDeviceClientType_HKMPEG4 = 12,//�����ķ�����MPEG��DVS
	keRecordDeviceClientType_HKH264 = 13,//�����������264����
	keRecordDeviceClientType_HKHIGH_264 = 14,//��������264������
	keRecordDeviceClientType_RTP_264 = 15,//�����ı�׼RTP��ʽ������ԭ����DEV_HKHIGH_264����
	keRecordDeviceClientType_HKHIGH_MPEG = 16,//��������Mepg4������ //lhj@2013.3.14 add
	keRecordDeviceClientType_Last
};

struct SPxRecordDeviceClientMPEG264
{
	HWND hDisplayWnd;
	char chConnetString[100];
	char chDeviceIP[20];
	int  nFormat;
};

struct SPxRecordDeviceClientWMV
{
	HWND hDisplayWnd;
	char chConnetString[100];
	char chDeviceIP[20];
	int  nFormat;
};

struct SPxRecordDeviceClientHK
{
	char chDeviceIP[20];                            //�豸IP
	int  nChannelsNum;                              //�豸
	int  nRecordTaskNum;                            //�豸�����
	char chDeviceLoginAcc[100];                     //�豸��½�û���	
	char chDeviceLoginPsd[100];                     //�豸��½����
};

struct SPxRecordDeviceClient
{
	EPxRecordDeviceType eDeviceType;
	EPxRecordDeviceClientType eRecordDeviceClientType;          //�豸����
	bool bRecordVideo;
	bool bRecordAudio;
	union UPxDeviceClient
	{
		SPxRecordDeviceClientMPEG264 sClientMPEG264;
		SPxRecordDeviceClientWMV sClientWMV;
		SPxRecordDeviceClientHK sClientHK;
	}uDeviceClient;
};

enum EPxRecordFileType
{
	keRecordFileType_Invliad = -1,
	keRecordFileType_WMV = 0,
	keRecordFileType_ASF,
	keRecordFileType_FLV,
	keRecordFileType_MP4,
	keRecordFileType_M3U8,
	keRecordFileType_Count
};

enum EPxRecordVideoType
{
	keRecordVideoType_Invliad = -1,
	keRecordVideoType_WMV = 0,
	keRecordVideoType_MPEG4,
	keRecordVideoType_MPEG2,
	keRecordVideoType_H264,
	keRecordVideoType_MPEG2_HIGH,
	keRecordVideoType_H264_HIGH,
	keRecordVideoType_Count
};

enum EPxRecordAudioType
{
	keRecordAudioType_Invliad = -1,
	keRecordAudioType_AAC = 0,
	keRecordAudioType_MP2L2,
	keRecordAudioType_MP3,
	keRecordAudioType_Count
};

enum EPxRecordAudioSamples
{
	keRecordAudioSamples_Invliad = -1,//5500,16000,22050,32000,44100
	keRecordAudioSamples_5500 = 5500,
	keRecordAudioSamples_16000 = 16000,
	keRecordAudioSamples_22050 = 22050,
	keRecordAudioSamples_32000 = 32000,
	keRecordAudioSamples_44100 = 44100,
	keRecordAudioSamples_48000 = 48000,
	keRecordAudioSamples_Count
};

enum  EPxRecordAudioBits
{
	keRecordAudioBits_Invliad = -1,//16384��mp2l2Ϊ32768
	keRecordAudioBits_MP3 = 16384,
	keRecordAudioBits_MP2L2 = 32768,
	keRecordAudioBits_Count
};

struct SPxRecordDeviceClientPara
{
	int nWidth;
	int nHeight;
	int nBitrate;
	EPxRecordVideoType eVideoEncType;//for HK: ��Ƶ�����ʽ//��Ƶ�������� 0 ˽��h264;1��׼h264; 2��׼mpeg4; 3-M-JPEG
	EPxRecordAudioType eAudioEncType;//for HK: ��Ƶ�����ʽ ��Ƶ�������� 0-OggVorbis;1-G711_U;2-G711_A
	EPxRecordAudioSamples eAudioSampleRate;
	float fFrameRate;
	int nAudioChannels;
	int nAudioBitsPerSampleint;
	EPxRecordAudioBits eAvgBitsPerSec;
	char szWMVMediaType[72*8];

	SPxRecordDeviceClientPara()
	{
		nWidth = 0;
		nHeight = 0;
		nBitrate = 0;
		eVideoEncType = keRecordVideoType_Invliad;//for HK: ��Ƶ�����ʽ//��Ƶ�������� 0 ˽��h264;1��׼h264; 2��׼mpeg4; 3-M-JPEG
		eAudioEncType = keRecordAudioType_Invliad;//for HK: ��Ƶ�����ʽ ��Ƶ�������� 0-OggVorbis;1-G711_U;2-G711_A
		eAudioSampleRate = keRecordAudioSamples_Invliad;
		fFrameRate = 0.0f;
		nAudioChannels = 0;
		nAudioBitsPerSampleint = 0;
		eAvgBitsPerSec = keRecordAudioBits_Invliad;

	}

	~SPxRecordDeviceClientPara()
	{
		nWidth = 0;
		nHeight = 0;
		nBitrate = 0;
		eVideoEncType = keRecordVideoType_Invliad;//for HK: ��Ƶ�����ʽ//��Ƶ�������� 0 ˽��h264;1��׼h264; 2��׼mpeg4; 3-M-JPEG
		eAudioEncType = keRecordAudioType_Invliad;//for HK: ��Ƶ�����ʽ ��Ƶ�������� 0-OggVorbis;1-G711_U;2-G711_A
		eAudioSampleRate = keRecordAudioSamples_Invliad;
		fFrameRate = 0.0f;
		nAudioChannels = 0;
		nAudioBitsPerSampleint = 0;
		eAvgBitsPerSec = keRecordAudioBits_Invliad;
	}
};

struct SPxRecordFilePropertyASF
{
	size_t size;
};

struct SPxRecordFilePropertyFLV
{
	size_t size;
};

struct SPxRecordFilePropertyMP4
{
	size_t size;
};

struct SPxRecordStreamProperty
{
	bool bHasVideo;
	bool bHasAudio;

	EPxRecordVideoType eVideoType;//��Ƶ����������(TYPE_H264)
	EPxRecordAudioType eAudioType;//��Ƶ����������(TYPE_AAC)

	int nVideoWidth;//��Ƶ��
	int nVideoHeight;//��Ƶ��
	int nVideoBitrate;//��Ƶ����
	float fVideoFrameRate;//��Ƶ֡��

	int nAudioChannels;//��Ƶ������(1,2)
	EPxRecordAudioSamples eAudioSamplesPerSecond;//��Ƶ������(16000,22050,32000,44100)
	int nAudioBitsPerSampleint;//��Ƶ��������(8,16)
	//EPxRecordAudioBits eAvgBitsPerSec;//(asf�ļ���Mp3Ϊ16384��mp2l2Ϊ32768)

	//char szVideoIP[50];//��ƵIP
	//char szAudioIP[50];//��ƵIP
	//char szWMVMediaType[72*8];

	SPxRecordStreamProperty()
	{
		bHasVideo = false;
		bHasAudio = false;

		eVideoType      = keRecordVideoType_H264;
		eAudioType      = keRecordAudioType_AAC;
		nVideoWidth     = 1366;
		nVideoHeight    = 768;
		nVideoBitrate   = 1024*1024;
		fVideoFrameRate = 25;

		nAudioChannels         = 2;
		eAudioSamplesPerSecond = keRecordAudioSamples_32000;
		nAudioBitsPerSampleint = 16;
	}

	~SPxRecordStreamProperty()
	{
		bHasVideo = false;
		bHasAudio = false;

		eVideoType      = keRecordVideoType_H264;
		eAudioType      = keRecordAudioType_AAC;
		nVideoWidth     = 1366;
		nVideoHeight    = 768;
		nVideoBitrate   = 1024*1024;
		fVideoFrameRate = 25;

		nAudioChannels         = 2;
		eAudioSamplesPerSecond = keRecordAudioSamples_32000;
		nAudioBitsPerSampleint = 16;
	}
};

struct SPxRecordFileProperty
{
	EPxRecordFileType eFileType;

	vector<SPxRecordStreamProperty> aStreamProperty;

	//union UPxFileProperty
	//{
	//	SPxRecordFilePropertyASF sASFProperty;
	//	SPxRecordFilePropertyFLV sFLVProperty;
	//	SPxRecordFilePropertyMP4 sMP4Property;
	//}uFileProperty;
};

//#define TCP_UNI			1 //TCP����
//#define UDP_UNI			2 //UDP����
//#define UDP_MULTI		3 //UDP�鲥

enum EPxConnectType
{
	keConnectType_Invalid = 0,
	keConnectType_TCP_UNI = 1,
	keConnectType_UDP_UNI = 2,
	keConnectType_UDP_MULTI = 3,
	keConnectType_Last
};
#endif //__pxRcordServerDef_H__