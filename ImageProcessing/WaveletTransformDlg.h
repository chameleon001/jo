#pragma once

//////////////////////////////////////////////////////////
//    CWaveletTransformDlg dialog
class CImageProcessingDoc;


// CWaveletTransformDlg 대화 상자입니다.

class CWaveletTransformDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWaveletTransformDlg)

public:
	CWaveletTransformDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
    CWaveletTransformDlg(CImageProcessingDoc *pDoc, CWnd* pParent = NULL);

	virtual ~CWaveletTransformDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WAVELET_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
    CImageProcessingDoc *m_pDoc;

	DECLARE_MESSAGE_MAP()
public:
    int m_Level;
    float m_Error;
    float m_SNR;
    int m_FilterCheck;
    afx_msg void OnButtonArrange();
    afx_msg void OnButtonEnd();
    afx_msg void OnButtonUpdate();
};
