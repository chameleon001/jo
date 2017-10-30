#pragma once


// c_rotation 대화 상자입니다.

class c_rotation : public CDialogEx
{
	DECLARE_DYNAMIC(c_rotation)

public:
	c_rotation(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~c_rotation();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
    int c_rotation_dgree;
};
