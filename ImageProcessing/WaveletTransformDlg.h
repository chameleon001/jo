#pragma once

//////////////////////////////////////////////////////////
//    CWaveletTransformDlg dialog
class CImageProcessingDoc;


// CWaveletTransformDlg ��ȭ �����Դϴ�.

class CWaveletTransformDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWaveletTransformDlg)

public:
	CWaveletTransformDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
    CWaveletTransformDlg(CImageProcessingDoc *pDoc, CWnd* pParent = NULL);

	virtual ~CWaveletTransformDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WAVELET_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
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
