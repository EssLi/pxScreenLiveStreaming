
// pxScreenLiveStreamingDlg.h : ͷ�ļ�
//

#pragma once

extern "C" 
{
	void _cdecl rgb32_to_yv12_mmx(unsigned char *y_out, unsigned char *u_out, unsigned char *v_out,
		unsigned char *src, int width, int height, int stride);

	void _cdecl rgb24_to_yv12_mmx(unsigned char *y_out, unsigned char *u_out, unsigned char *v_out,
		unsigned char *src, int width, int height, int stride);
}

#define AVC_SEQUENCE_HEADER_LEN (1024)
#define AAC_SEQUENCE_HEADER_LEN (512)


// CpxScreenLiveStreamingDlg �Ի���
class CPxScreenLiveStreamingDlg : public CDialogEx
{
// ����
public:
	CPxScreenLiveStreamingDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CPxScreenLiveStreamingDlg();

// �Ի�������
	enum { IDD = IDD_PXSCREENLIVESTREAMING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	bool Init();

// video
public:
	int									m_nScreenWidth;
	int									m_nScreenHeight;


	/*HDC									m_hScreenDC;
	HDC									m_hMemDC;
	HWND								m_hDesktopWnd;
	HBITMAP								m_hCompatibleBitmap;*/

	CDC *pDC;
	CDC memDC; 
	CBitmap memBitmap;                // ��������Ļ���ݵ�bitmap
	CBitmap m_hCompatibleBitmap;

	//BITMAPINFO							m_BitmapInfo;

	BITMAPFILEHEADER					m_BitmapFileHeader;
	BITMAPINFOHEADER                    m_BitmapInfoHeader;

	BYTE							*	m_pBitmapBuffer;
	int									m_nBitmapBufferLen;

	int m_nFps;
	double m_fPeriod;
	int m_nTimetoSleep;
	LARGE_INTEGER m_liPerfFreq;
	LARGE_INTEGER m_liBeginTime;
	LARGE_INTEGER m_liEndTime;

// YUV
public:
	BYTE							*	m_pYUVBuffer;	//YUV����
	int									m_nUOffset;
	int									m_nVOffset;
	int                                 m_nYUVBufferSize;

public:
	/*static*//* DWORD WINAPI ThreadStart(LPVOID lp);*/
};
