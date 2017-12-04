// ArrangeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ArrangeDlg.h"
#include "afxdialogex.h"


// CArrangeDlg ��ȭ �����Դϴ�.

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


// CArrangeDlg �޽��� ó�����Դϴ�.


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
    // ���� ���� ����� ���� ��ȭ���� ũ�� ����
    cy = sizeImg.cy + rect.Height() - rectC.Height() + 4;

    SetWindowPos(this, 0, 0, cx, cy, SWP_NOZORDER);


    return TRUE;  // return TRUE unless you set the focus to a control
                  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CArrangeDlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
                       // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
                       // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.

    int i, j;
    unsigned char R, G, B;

    for (i = 0; i<Height; i++) {
        for (j = 0; j<Width; j++) {
            R = m_tempImage[i][j];

            G = B = R;
            dc.SetPixel(j, i, RGB(R, G, B));
            // ����ȭ�� ���� ������ ȭ�鿡 ���
        }
    }

}
