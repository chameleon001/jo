// DownSampleDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "DownSampleDlg.h"
#include "afxdialogex.h"


// CDownSampleDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDownSampleDlg, CDialogEx)

CDownSampleDlg::CDownSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_DownSampleRate(0)
{

}

CDownSampleDlg::~CDownSampleDlg()
{
}

void CDownSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_DownSampleRate);
}


BEGIN_MESSAGE_MAP(CDownSampleDlg, CDialogEx)
END_MESSAGE_MAP()


// CDownSampleDlg �޽��� ó�����Դϴ�.
