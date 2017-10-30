#pragma once


// CMove 대화 상자입니다.

class CMove : public CDialogEx
{
	DECLARE_DYNAMIC(CMove)

public:
	CMove(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMove();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
    int m_move_x;
    int m_move_y;
};
