#pragma once


// c_rotation ��ȭ �����Դϴ�.

class c_rotation : public CDialogEx
{
	DECLARE_DYNAMIC(c_rotation)

public:
	c_rotation(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~c_rotation();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    int c_rotation_dgree;
};
