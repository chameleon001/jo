#pragma once


// CMove ��ȭ �����Դϴ�.

class CMove : public CDialogEx
{
	DECLARE_DYNAMIC(CMove)

public:
	CMove(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMove();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    int m_move_x;
    int m_move_y;
};
