#pragma once


// CArrangeDlg ��ȭ �����Դϴ�.

class CArrangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CArrangeDlg)

public:
	CArrangeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CArrangeDlg();
    unsigned char **m_tempImage;
    int Height;
    int Width;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ARRANGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
};
