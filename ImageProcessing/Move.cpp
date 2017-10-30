// Move.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "Move.h"
#include "afxdialogex.h"


// CMove ��ȭ �����Դϴ�.

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


// CMove �޽��� ó�����Դϴ�.
