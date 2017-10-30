// c_rotation.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "c_rotation.h"
#include "afxdialogex.h"


// c_rotation 대화 상자입니다.

IMPLEMENT_DYNAMIC(c_rotation, CDialogEx)

c_rotation::c_rotation(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG7, pParent)
    , c_rotation_dgree(0)
{

}

c_rotation::~c_rotation()
{
}

void c_rotation::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, c_rotation_dgree);
	DDV_MinMaxInt(pDX, c_rotation_dgree, 0, 360);
}


BEGIN_MESSAGE_MAP(c_rotation, CDialogEx)
END_MESSAGE_MAP()


// c_rotation 메시지 처리기입니다.
