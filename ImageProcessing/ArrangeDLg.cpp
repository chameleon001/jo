// ArrangeDLg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ArrangeDLg.h"
#include "afxdialogex.h"


// CArrangeDLg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CArrangeDlg, CDialogEx)

CArrangeDLg::CArrangeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ARRANGE, pParent)
{

}

CArrangeDLg::~CArrangeDlg()
{
}

void CArrangeDLg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CArrangeDlg, CDialogEx)
END_MESSAGE_MAP()


// CArrangeDLg �޽��� ó�����Դϴ�.


BOOL CArrangeDLg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

    return TRUE;  // return TRUE unless you set the focus to a control
                  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
