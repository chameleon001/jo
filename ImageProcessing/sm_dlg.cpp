// sm_dlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "sm_dlg.h"
#include "afxdialogex.h"


// sm_dlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(sm_dlg, CDialogEx)

sm_dlg::sm_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG8, pParent)
    , n_input(0)
{

}

sm_dlg::~sm_dlg()
{
}

void sm_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(sm_dlg, CDialogEx)
END_MESSAGE_MAP()


// sm_dlg 메시지 처리기입니다.
