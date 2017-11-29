// WaveletTransformDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "WaveletTransformDlg.h"
#include "afxdialogex.h"
#include “ImageProcessingDoc.h"


// CWaveletTransformDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CWaveletTransformDlg, CDialogEx)

CWaveletTransformDlg::CWaveletTransformDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WAVELET_DLG, pParent)
    , m_Level(0)
    , m_Error(0)
    , m_SNR(0)
    , m_FilterCheck(0)
{
    m_pDoc = NULL;

    m_Level = 0;
    m_Error = 0.0f;
    m_SNR = 0.0f;
    m_FilterCheck = 0;


}

CWaveletTransformDlg::~CWaveletTransformDlg()
{
}

void CWaveletTransformDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_Level);
    DDX_Text(pDX, IDC_EDIT2, m_Error);
    DDX_Text(pDX, IDC_EDIT3, m_SNR);
    DDX_Radio(pDX, IDC_RADIO1, m_FilterCheck);
}


CWaveletTransformDlg::CWaveletTransformDlg(CImageProcessingDoc *pDoc, CWnd* pParent /*=NULL*/)
    : CDialogEx(CWaveletTransformDlg::IDD, pParent)
{
    m_pDoc = pDoc; // Doc 클래스 참조
    m_Level = 1; // Wavelet 분해 레벨 초기화
    m_Error = 0.0f; // MSE 초기화
    m_SNR = 0.0f; // SNR 초기화
    m_FilterCheck = 0; // Filter Check 초기화
}


BEGIN_MESSAGE_MAP(CWaveletTransformDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_ARRANGE, &CWaveletTransformDlg::OnButtonArrange)
    ON_BN_CLICKED(IDC_BUTTON_END, &CWaveletTransformDlg::OnButtonEnd)
    ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CWaveletTransformDlg::OnButtonUpdate)
END_MESSAGE_MAP()


// CWaveletTransformDlg 메시지 처리기입니다.


void CWaveletTransformDlg::OnButtonArrange()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CWaveletTransformDlg::OnButtonEnd()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CWaveletTransformDlg::OnButtonUpdate()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
