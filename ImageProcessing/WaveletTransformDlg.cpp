// WaveletTransformDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "WaveletTransformDlg.h"
#include "afxdialogex.h"
#include ��ImageProcessingDoc.h"


// CWaveletTransformDlg ��ȭ �����Դϴ�.

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
    m_pDoc = pDoc; // Doc Ŭ���� ����
    m_Level = 1; // Wavelet ���� ���� �ʱ�ȭ
    m_Error = 0.0f; // MSE �ʱ�ȭ
    m_SNR = 0.0f; // SNR �ʱ�ȭ
    m_FilterCheck = 0; // Filter Check �ʱ�ȭ
}


BEGIN_MESSAGE_MAP(CWaveletTransformDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_ARRANGE, &CWaveletTransformDlg::OnButtonArrange)
    ON_BN_CLICKED(IDC_BUTTON_END, &CWaveletTransformDlg::OnButtonEnd)
    ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CWaveletTransformDlg::OnButtonUpdate)
END_MESSAGE_MAP()


// CWaveletTransformDlg �޽��� ó�����Դϴ�.


void CWaveletTransformDlg::OnButtonArrange()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CWaveletTransformDlg::OnButtonEnd()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CWaveletTransformDlg::OnButtonUpdate()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
