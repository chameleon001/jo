// sm_dlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "sm_dlg.h"
#include "afxdialogex.h"


// sm_dlg ��ȭ �����Դϴ�.

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


// sm_dlg �޽��� ó�����Դϴ�.
