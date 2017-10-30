// Move.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "Move.h"
#include "afxdialogex.h"


// CMove 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMove, CDialogEx)

CMove::CMove(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
    , m_move_x(0)
    , m_move_y(0)
{

}

CMove::~CMove()
{
}

void CMove::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_move_x);
    DDV_MinMaxInt(pDX, m_move_x, 0, 255);
    DDX_Text(pDX, IDC_EDIT2, m_move_y);
	DDV_MinMaxInt(pDX, m_move_y, 1, 300);
}


BEGIN_MESSAGE_MAP(CMove, CDialogEx)
END_MESSAGE_MAP()


// CMove 메시지 처리기입니다.
