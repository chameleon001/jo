// ArrangeDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ArrangeDlg.h"
#include "afxdialogex.h"


// CArrangeDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CArrangeDlg, CDialogEx)

CArrangeDlg::CArrangeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ARRANGE, pParent)
{

}

CArrangeDlg::~CArrangeDlg()
{
}

void CArrangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CArrangeDlg, CDialogEx)
    ON_WM_PAINT()
END_MESSAGE_MAP()


// CArrangeDlg 메시지 처리기입니다.


BOOL CArrangeDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    CRect rect, rectC;
    GetWindowRect(&rect);
    GetClientRect(&rectC);

    int cx, cy;

    CSize sizeImg;
    sizeImg.cx = Width;
    sizeImg.cy = Height;

    cx = sizeImg.cx + rect.Width() - rectC.Width() + 4;
    // 정렬 영상 출력을 위한 대화상자 크기 조절
    cy = sizeImg.cy + rect.Height() - rectC.Height() + 4;

    SetWindowPos(this, 0, 0, cx, cy, SWP_NOZORDER);


    return TRUE;  // return TRUE unless you set the focus to a control
                  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CArrangeDlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
                       // TODO: 여기에 메시지 처리기 코드를 추가합니다.
                       // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

    int i, j;
    unsigned char R, G, B;

    for (i = 0; i<Height; i++) {
        for (j = 0; j<Width; j++) {
            R = m_tempImage[i][j];

            G = B = R;
            dc.SetPixel(j, i, RGB(R, G, B));
            // 정규화된 정렬 영상을 화면에 출력
        }
    }

}
