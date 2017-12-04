#pragma once


// CArrangeDlg 대화 상자입니다.

class CArrangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CArrangeDlg)

public:
	CArrangeDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CArrangeDlg();
    unsigned char **m_tempImage;
    int Height;
    int Width;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ARRANGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
};
