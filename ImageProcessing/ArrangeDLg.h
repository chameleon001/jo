#pragma once


// CArrangeDLg ��ȭ �����Դϴ�.

class CArrangeDLg : public CDialogEx
{
	DECLARE_DYNAMIC(CArrangeDLg)

public:
	CArrangeDLg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CArrangeDLg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ARRANGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
};
