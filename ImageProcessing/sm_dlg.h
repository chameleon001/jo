#pragma once


// sm_dlg ��ȭ �����Դϴ�.

class sm_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(sm_dlg)

public:
	sm_dlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~sm_dlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    int n_input;
};
