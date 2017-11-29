// ArrangeDLg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ArrangeDLg.h"
#include "afxdialogex.h"


// CArrangeDLg 대화 상자입니다.

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


// CArrangeDLg 메시지 처리기입니다.


BOOL CArrangeDLg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  여기에 추가 초기화 작업을 추가합니다.

    return TRUE;  // return TRUE unless you set the focus to a control
                  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
