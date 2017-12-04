
// ImageProcessingDoc.cpp : CImageProcessingDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImageProcessing.h"
#endif

#include "ImageProcessingDoc.h"
#include "DownSampleDlg.h"
#include "Move.h"
#include "c_rotation.h"
#include "UpSampleDlg.h"
#include "QuantizationDlg.h"
#include "math.h"
#include "ConstantDlg.h"
#include "sm_dlg.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImageProcessingDoc

IMPLEMENT_DYNCREATE(CImageProcessingDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageProcessingDoc, CDocument)
    ON_COMMAND(ID_SUM_CONSTANT, &CImageProcessingDoc::OnSumConstant)
    ON_COMMAND(ID_SUB_CONSTANT, &CImageProcessingDoc::OnSubConstant)
    ON_COMMAND(ID_MUL_CONSTANT, &CImageProcessingDoc::OnMulConstant)
    ON_COMMAND(ID_DIV_CONSTANT, &CImageProcessingDoc::OnDivConstant)
    ON_COMMAND(ID_AND_OPERATE, &CImageProcessingDoc::OnAndOperate)
    ON_COMMAND(ID_OR_OPERATE, &CImageProcessingDoc::OnOrOperate)
    ON_COMMAND(ID_XOR_OPERATE, &CImageProcessingDoc::OnXorOperate)
    ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessingDoc::OnNegaTransform)
    ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessingDoc::OnGammaCorrection)
    ON_COMMAND(ID_BINARIZATION, &CImageProcessingDoc::OnBinarization)
    ON_COMMAND(ID_HISTO_STRETCH, &CImageProcessingDoc::OnHistoStretch)
    ON_COMMAND(ID_END_IN_SEARCH, &CImageProcessingDoc::OnEndInSearch)
    ON_COMMAND(ID_HISTOGRAM, &CImageProcessingDoc::OnHistogram)
    ON_COMMAND(ID_HISTO_EQUAL, &CImageProcessingDoc::OnHistoEqual)
    ON_COMMAND(ID_HISTO_SPEC, &CImageProcessingDoc::OnHistoSpec)
    ON_COMMAND(ID_EMBOSSING, &CImageProcessingDoc::OnEmbossing)
    ON_COMMAND(ID_BLURR, &CImageProcessingDoc::OnBlurr)
    ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessingDoc::OnGaussianFilter)
    ON_COMMAND(ID_SHARPENING, &CImageProcessingDoc::OnSharpening)
    ON_COMMAND(ID_LAPLACIAN, &CImageProcessingDoc::OnLaplacian)
    ON_COMMAND(ID_LoG, &CImageProcessingDoc::OnLog)
    ON_COMMAND(ID_NEAREST, &CImageProcessingDoc::OnNearest)
    ON_COMMAND(ID_BILINEAR, &CImageProcessingDoc::OnBilinear)
    ON_COMMAND(ID_MEDIAN_SUB, &CImageProcessingDoc::OnMedianSub)

    ON_COMMAND(ID_MEAN_SUB, &CImageProcessingDoc::OnMeanSub)
    ON_COMMAND(ID_TRANSLATION, &CImageProcessingDoc::OnTranslation)
    ON_COMMAND(ID_MIRROR_HOR, &CImageProcessingDoc::OnMirrorHor)
    ON_COMMAND(ID_MIRROR_VER, &CImageProcessingDoc::OnMirrorVer)
    ON_COMMAND(ID_ROTATION, &CImageProcessingDoc::OnRotation)
    ON_COMMAND(ID_MORPHING, &CImageProcessingDoc::OnMorphing)
    //ON_COMMAND(ID_WMap, &CImageProcessingDoc::OnWmap)
    ON_COMMAND(ID_FRAME_SUM, &CImageProcessingDoc::OnFrameSum)

    ON_COMMAND(ID_FRAME_SUB, &CImageProcessingDoc::OnFrameSub)
    ON_COMMAND(ID_FRAME_MUL, &CImageProcessingDoc::OnFrameMul)
    ON_COMMAND(ID_FRAME_DIV, &CImageProcessingDoc::OnFrameDiv)
    ON_COMMAND(ID_FRAME_AND, &CImageProcessingDoc::OnFrameAnd)
    ON_COMMAND(ID_FRAME_OR, &CImageProcessingDoc::OnFrameOr)
    ON_COMMAND(ID_FRAME_COMB, &CImageProcessingDoc::OnFrameComb)
    ON_COMMAND(ID_BINARY_EROSION, &CImageProcessingDoc::OnBinaryErosion)
    ON_COMMAND(ID_BINARY_DILATION, &CImageProcessingDoc::OnBinaryDilation)
    ON_COMMAND(ID_GRAY_EROSION, &CImageProcessingDoc::OnGrayErosion)
    ON_COMMAND(ID_LOW_PASS_FILTER, &CImageProcessingDoc::OnLowPassFilter)
    ON_COMMAND(ID_HIGH_PASS_FILTER, &CImageProcessingDoc::OnHighPassFilter)
    ON_COMMAND(ID_MEDIAN_FILTER, &CImageProcessingDoc::OnMedianFilter)
    ON_COMMAND(ID_WeightMedianFilter, &CImageProcessingDoc::OnWeightmedianfilter)
    ON_COMMAND(ID_MAX_FILTER, &CImageProcessingDoc::OnMaxFilter)
    ON_COMMAND(ID_MIN_FILTER, &CImageProcessingDoc::OnMinFilter)
    ON_COMMAND(ID_Chaincodes, &CImageProcessingDoc::OnChaincodes)
    ON_COMMAND(ID_Corners, &CImageProcessingDoc::OnCorners)
    
    
    ON_COMMAND(ID_LINESMOOTHING, &CImageProcessingDoc::OnLinesmoothing)
    ON_COMMAND(ID_FFT_2D, &CImageProcessingDoc::OnFft2d)
    ON_COMMAND(ID_IFFT_2D, &CImageProcessingDoc::OnIfft2d)
    ON_COMMAND(ID_WAVELET_TRANSFORM, &CImageProcessingDoc::OnWaveletTransform)
END_MESSAGE_MAP()


// CImageProcessingDoc ����/�Ҹ�

CImageProcessingDoc::CImageProcessingDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CImageProcessingDoc::~CImageProcessingDoc()
{
}

BOOL CImageProcessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CImageProcessingDoc serialization

void CImageProcessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CImageProcessingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CImageProcessingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImageProcessingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImageProcessingDoc ����

#ifdef _DEBUG
void CImageProcessingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageProcessingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageProcessingDoc ���


BOOL CImageProcessingDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	CFile File; // ���� ��ü ����

	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
	// ���� ���� ��ȭ���ڿ��� ������ ������ �����ϰ� �б� ��� ����

	// �� å������ ������ ũ�� 256*256, 512*512, 640*480���� ����Ѵ�.
	if (File.GetLength() == 256 * 256) { // RAW ������ ũ�� ����
		m_height = 256;
		m_width = 256;
	}
	else if (File.GetLength() == 512 * 512) { // RAW ������ ũ�� ����
		m_height = 512;
		m_width = 512;
	}
	else if (File.GetLength() == 640 * 480) { // RAW ������ ũ�� ����
		m_height = 480;
		m_width = 640;
	}
	else {
		AfxMessageBox((CString)("Not Support Image Size")); // �ش� ũ�Ⱑ ���� ���
			return 0;
	}
	m_size = m_width * m_height; // ������ ũ�� ���

	m_InputImage = new unsigned char[m_size];
	// �Է� ������ ũ�⿡ �´� �޸� �Ҵ�

	for (int i = 0; i<m_size; i++)
		m_InputImage[i] = 255; // �ʱ�ȭ
	File.Read(m_InputImage, m_size); // �Է� ���� ���� �б�
	File.Close(); // ���� �ݱ�
				  

	return TRUE;
}


BOOL CImageProcessingDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CFile File; // ���� ��ü ����
	CFileDialog SaveDlg((bool)false, (LPCTSTR)"raw", NULL, OFN_HIDEREADONLY);
	// raw ������ �ٸ� �̸����� �����ϱ⸦ ���� ��ȭ���� ��ü ����

	if (SaveDlg.DoModal() == IDOK) {
		// DoModal ��� �Լ����� �����ϱ� ����
		File.Open(SaveDlg.GetPathName(), CFile::modeCreate |
			CFile::modeWrite);
		// ���� ����
		File.Write(m_OutputImage, m_size); // ���� ����
		File.Close(); // ���� �ݱ�
	}

	return CDocument::OnSaveDocument(lpszPathName);
}


void CImageProcessingDoc::OnDownSampling()
{
	int i, j;
	CDownSampleDlg dlg;
	if (dlg.DoModal() == IDOK) // ��ȭ������ Ȱ��ȭ ����
	{
		m_Re_height = m_height / dlg.m_DownSampleRate;
		// ��� ������ ���� ���̸� ���
		m_Re_width = m_width / dlg.m_DownSampleRate;
		// ��� ������ ���� ���̸� ���
		m_Re_size = m_Re_height * m_Re_width;
		// ��� ������ ũ�⸦ ���

		m_OutputImage = new unsigned char[m_Re_size];
		// ��� ������ ���� �޸� �Ҵ�

		for (i = 0; i<m_Re_height; i++) {
			for (j = 0; j<m_Re_width; j++) {
				m_OutputImage[i*m_Re_width + j]
					= m_InputImage[(i*dlg.m_DownSampleRate*m_width) + dlg.m_DownSampleRate*j];
				// ��� ������ ����
			}
		}
	}
}


void CImageProcessingDoc::OnUpSampling()
{
	int i, j;

	CUpSampleDlg dlg;
	if (dlg.DoModal() == IDOK) { // DoModal ��ȭ������ Ȱ��ȭ ����
		m_Re_height = m_height * dlg.m_UpSampleRate;
		// Ȯ�� ������ ���� ���� ���
		m_Re_width = m_width * dlg.m_UpSampleRate;
		// Ȯ�� ������ ���� ���� ���
		m_Re_size = m_Re_height * m_Re_width;
		// Ȯ�� ������ ũ�� ���
		m_OutputImage = new unsigned char[m_Re_size];
		// Ȯ�� ������ ���� �޸� �Ҵ�

		for (i = 0; i<m_Re_size; i++)
			m_OutputImage[i] = 0; // �ʱ�ȭ

		for (i = 0; i<m_height; i++) {
			for (j = 0; j<m_width; j++) {
				m_OutputImage[i*dlg.m_UpSampleRate*m_Re_width +
					dlg.m_UpSampleRate*j] = m_InputImage[i*m_width + j];
			} // ���ġ�Ͽ� ���� Ȯ��
		}
	}
}

void CImageProcessingDoc::OnQuantization()
{
    CQuantizationDlg dlg;
    if (dlg.DoModal() == IDOK)
        // ����ȭ ��Ʈ ���� �����ϴ� ��ȭ������ Ȱ��ȭ ����
    {
        int i, j, value, LEVEL;
        double HIGH, *TEMP;

        m_Re_height = m_height;
        m_Re_width = m_width;
        m_Re_size = m_Re_height * m_Re_width;

        m_OutputImage = new unsigned char[m_Re_size];
        // ����ȭ ó���� ������ ����ϱ� ���� �޸� �Ҵ�

        TEMP = new double[m_size];
        // �Է� ���� ũ��(m_size)�� ������ �޸� �Ҵ�

        LEVEL = 256; // �Է� ������ ����ȭ �ܰ�(28=256)
        HIGH = 256.;

        value = (int)pow(2.0, dlg.m_QuantBit);
        // ����ȭ �ܰ� ����(�� : 24=16)

        for (i = 0; i<m_size; i++) {
            for (j = 0; j<value; j++) {
                if (m_InputImage[i] >= (LEVEL / value)*j &&
                    m_InputImage[i]<(LEVEL / value)*(j + 1)) {
                    TEMP[i] = (double)(HIGH / value)*j; // ����ȭ ����
                }
            }
        }
        for (i = 0; i<m_size; i++) {
            m_OutputImage[i] = (unsigned char)TEMP[i];
            // ��� ���� ����
        }
    }
}


void CImageProcessingDoc::OnSumConstant()
{
    CConstantDlg dlg; // ��� ���� �Է¹޴� ��ȭ����

    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            if (m_InputImage[i] + dlg.m_Constant >= 255)
                m_OutputImage[i] = 255;
            // ��� ���� 255���� ũ�� 255 ���
            else
                m_OutputImage[i] = (unsigned char)(m_InputImage[i] + dlg.m_Constant);
            // ��� ���� ȭ�� ������ ����
        }
    }

}


void CImageProcessingDoc::OnSubConstant()
{
    CConstantDlg dlg;

    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            if (m_InputImage[i] - dlg.m_Constant < 0)
                m_OutputImage[i] = 0; // ��� ���� 255���� ũ�� 255�� ���
            else
                m_OutputImage[i] = (unsigned char)(m_InputImage[i] - dlg.m_Constant);
            // ��� ���� ȭ�� ������ ����
        }
    }

}


void CImageProcessingDoc::OnMulConstant()
{
    CConstantDlg dlg;

    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            if (m_InputImage[i] * dlg.m_Constant > 255)
                m_OutputImage[i] = 255;
            // ���� ���� 255���� ũ�� 255�� ���
            else if (m_InputImage[i] * dlg.m_Constant < 0)
                m_OutputImage[i] = 0;
            // ���� ���� 0���� ������ 0�� ���
            else
                m_OutputImage[i]
                = (unsigned char)(m_InputImage[i] * dlg.m_Constant);
            // ��� ���� ȭ�� �� ����
        }
    }

}


void CImageProcessingDoc::OnDivConstant()
{
    CConstantDlg dlg;

    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            if (m_InputImage[i] / dlg.m_Constant > 255)
                m_OutputImage[i] = 255;
            // �������� ���� 255���� ũ�� 255�� ���
            else if (m_InputImage[i] / dlg.m_Constant < 0)
                m_OutputImage[i] = 0;
            // �������� ���� 0���� ������ 0�� ���
            else
                m_OutputImage[i]
                = (unsigned char)(m_InputImage[i] / dlg.m_Constant);
            // ��� ���� ȭ�� �� ������
        }
    }

}


void CImageProcessingDoc::OnAndOperate()
{
    CConstantDlg dlg;
    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            // ��Ʈ ���� AND ����
            if ((m_InputImage[i] & (unsigned char)dlg.m_Constant) >= 255)
            {
                m_OutputImage[i] = 255;
            }
            else if ((m_InputImage[i] & (unsigned char)dlg.m_Constant)< 0)
            {
                m_OutputImage[i] = 0;
            }
            else {
                m_OutputImage[i] = (m_InputImage[i]
                    & (unsigned char)dlg.m_Constant);
            }
        }
    }

}


void CImageProcessingDoc::OnOrOperate()
{
    CConstantDlg dlg;
    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            // ��Ʈ ���� OR ����
            if ((m_InputImage[i] | (unsigned char)dlg.m_Constant) >= 255) {
                m_OutputImage[i] = 255;
            }
            else if ((m_InputImage[i] | (unsigned char)dlg.m_Constant) < 0) {
                m_OutputImage[i] = 0;
            }
            else {
                m_OutputImage[i] = (m_InputImage[i] |
                    (unsigned char)dlg.m_Constant);
            }
        }
    }

}


void CImageProcessingDoc::OnXorOperate()
{
    CConstantDlg dlg;
    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            // ��Ʈ ���� XOR ����
            if ((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) >= 255) {
                m_OutputImage[i] = 255;
            }
            else if ((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) < 0) {
                m_OutputImage[i] = 0;
            }
            else {
                m_OutputImage[i] = (m_InputImage[i]
                    ^ (unsigned char)dlg.m_Constant);
            }
        }
    }

}


void CImageProcessingDoc::OnNegaTransform()
{
    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    for (i = 0; i<m_size; i++)
        m_OutputImage[i] = 255 - m_InputImage[i]; // ���� ������ ����

}


void CImageProcessingDoc::OnGammaCorrection()
{
    CConstantDlg dlg;

    int i;
    double temp;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            temp = pow(m_InputImage[i], 1 / dlg.m_Constant);
            // ���� �� ���
            if (temp < 0)
                m_OutputImage[i] = 0;
            else if (temp > 255)
                m_OutputImage[i] = 255;
            else
                m_OutputImage[i] = (unsigned char)temp;
        }
    }
}


void CImageProcessingDoc::OnBinarization()
{
    CConstantDlg dlg;

    int i;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (dlg.DoModal() == IDOK) {
        for (i = 0; i<m_size; i++) {
            if (m_InputImage[i] >= dlg.m_Constant)
                m_OutputImage[i] = 255; // �Ӱ� ������ ũ�� 255 ���
            else
                m_OutputImage[i] = 0; // �Ӱ� ������ ������ 0 ���
        }
    }

}


void CImageProcessingDoc::OnHistoStretch()
{
    int i;
    unsigned char LOW, HIGH, MAX, MIN;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    LOW = 0;
    HIGH = 255;

    MIN = m_InputImage[0]; // �ּҰ��� ã�� ���� �ʱⰪ
    MAX = m_InputImage[0]; // �ִ밪�� ã�� ���� �ʱⰪ

                           // �Է� ������ �ּҰ� ã��
    for (i = 0; i<m_size; i++) {
        if (m_InputImage[i] < MIN)
            MIN = m_InputImage[i];
    }

    // �Է� ������ �ִ밪 ã��
    for (i = 0; i<m_size; i++) {
        if (m_InputImage[i] > MAX)
            MAX = m_InputImage[i];
    }

    m_OutputImage = new unsigned char[m_Re_size];

    // ������׷� stretch
    for (i = 0; i<m_size; i++)
        m_OutputImage[i] = (unsigned char)((m_InputImage[i] -
            MIN)*HIGH / (MAX - MIN));
}


void CImageProcessingDoc::OnEndInSearch()
{
    int i;
    unsigned char LOW, HIGH, MAX, MIN;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    LOW = 0;
    HIGH = 255;

    MIN = m_InputImage[0];
    MAX = m_InputImage[0];

    for (i = 0; i<m_size; i++) {
        if (m_InputImage[i] < MIN)
            MIN = m_InputImage[i];
    }

    for (i = 0; i<m_size; i++) {
        if (m_InputImage[i] > MAX)
            MAX = m_InputImage[i];
    }

    m_OutputImage = new unsigned char[m_Re_size];
   
    for (i = 0; i<m_size; i++) {
        // ���� ������ �ּҰ����� ���� ���� 0
        if (m_InputImage[i] <= MIN) {
            m_OutputImage[i] = 0;
        }

        // ���� ������ �ִ밪���� ū ���� 255
        else if (m_InputImage[i] >= MAX) {
            m_OutputImage[i] = 255;
        }
        else
            m_OutputImage[i] = (unsigned char)((m_InputImage[i] -
                MIN)*HIGH / (MAX - MIN));
    }

}


void CImageProcessingDoc::OnHistogram()
{
    // ������׷��� ���� 0~255
    // ������׷��� ũ�� ���� MAX=255�� ����ȭ�Ͽ� ���
    // ����Ʈ�׷��� ũ�� : 256*256 ����

    int i, j, value;
    unsigned char LOW, HIGH;
    double MAX, MIN, DIF;

    m_Re_height = 256;
    m_Re_width = 256;
    m_Re_size = m_Re_height * m_Re_width;

    LOW = 0;
    HIGH = 255;

    // �ʱ�ȭ
    for (i = 0; i<256; i++)
        m_HIST[i] = LOW;

    // �� �� ����
    for (i = 0; i<m_size; i++) {
        value = (int)m_InputImage[i];
        m_HIST[value]++;
    }

    // ����ȭ
    MAX = m_HIST[0];
    MIN = m_HIST[0];

    for (i = 0; i<256; i++) {
        if (m_HIST[i] > MAX)
            MAX = m_HIST[i];
    }

    for (i = 0; i<256; i++) {
        if (m_HIST[i] < MIN)
            MIN = m_HIST[i];
    }
    DIF = MAX - MIN;

    // ����ȭ�� ������׷�
    for (i = 0; i<256; i++)
        m_Scale_HIST[i] = (unsigned char)((m_HIST[i] - MIN) * HIGH / DIF);

    // ����ȭ�� ������׷� ���
    m_OutputImage = new unsigned char[m_Re_size + (256 * 20)];

    for (i = 0; i<m_Re_size; i++)
        m_OutputImage[i] = 255;

    // ����ȭ�� ������׷��� ���� ��� �迭�� ���� ��(0)���� ǥ��
    for (i = 0; i<256; i++) {
        for (j = 0; j<m_Scale_HIST[i]; j++) {
            m_OutputImage[m_Re_width*(m_Re_height - j - 1) + i] = 0;
        }
    }

    // ������׷��� ����ϰ� �� �Ʒ� �κп� ������׷��� ���� ǥ��
    for (i = m_Re_height; i<m_Re_height + 5; i++) {
        for (j = 0; j<256; j++) {
            m_OutputImage[m_Re_height * i + j] = 255;
        }
    }

    for (i = m_Re_height + 5; i<m_Re_height + 20; i++) {
        for (j = 0; j<256; j++) {
            m_OutputImage[m_Re_height * i + j] = j;
        }
    }

    m_Re_height = m_Re_height + 20;
    m_Re_size = m_Re_height * m_Re_width;

}


void CImageProcessingDoc::OnHistoEqual()
{
    int i, value;
    unsigned char LOW, HIGH, Temp;
    double SUM = 0.0;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    LOW = 0;
    HIGH = 255;

    // �ʱ�ȭ
    for (i = 0; i<256; i++)
        m_HIST[i] = LOW;

    // �� �� ����
    for (i = 0; i<m_size; i++) {
        value = (int)m_InputImage[i];
        m_HIST[value]++;
    }

    // ���� ������׷� ����
    for (i = 0; i<256; i++) {
        SUM += m_HIST[i];
        m_Sum_Of_HIST[i] = SUM;
    }

    m_OutputImage = new unsigned char[m_Re_size];

    // �Է� ������ ��Ȱȭ�� �������� ���
    for (i = 0; i<m_size; i++) {
        Temp = m_InputImage[i];
        m_OutputImage[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
    }
}

void CImageProcessingDoc::OnHistoSpec()
{
    int i, value, Dvalue, top, bottom, DADD;
    unsigned char *m_DTEMP, m_Sum_Of_ScHIST[256], m_TABLE[256];
    unsigned char LOW, HIGH, Temp, *m_Org_Temp;
    double m_DHIST[256], m_Sum_Of_DHIST[256], SUM = 0.0, DSUM = 0.0;
    double DMAX, DMIN;

    top = 255;
    bottom = top - 1;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];
    m_Org_Temp = new unsigned char[m_size];

    CFile File;
    CFileDialog OpenDlg(TRUE);

    // ���ϴ� ������׷��� �ִ� ������ �Է¹���
    if (OpenDlg.DoModal() == IDOK) {
        File.Open(OpenDlg.GetFileName(), CFile::modeRead);

        if (File.GetLength() == (unsigned)m_size) {
            m_DTEMP = new unsigned char[m_size];
            File.Read(m_DTEMP, m_size);
            File.Close();
        }
        else {
            AfxMessageBox((CString)("Image size not matched"));
           
            // ���� ũ���� ������ ������� ��
            return;
        }
    }

    LOW = 0;
    HIGH = 255;

    // �ʱ�ȭ
    for (i = 0; i<256; i++) {
        m_HIST[i] = LOW;
        m_DHIST[i] = LOW;
        m_TABLE[i] = LOW;
    }

    // �� �� ����
    for (i = 0; i<m_size; i++) {
        value = (int)m_InputImage[i];
        m_HIST[value]++;
        Dvalue = (int)m_DTEMP[i];
        m_DHIST[Dvalue]++;
    }

    // ���� ������׷� ����
    for (i = 0; i<256; i++) {
        SUM += m_HIST[i];
        m_Sum_Of_HIST[i] = SUM;
        DSUM += m_DHIST[i];
        m_Sum_Of_DHIST[i] = DSUM;
    }
    // ���� ������ ��Ȱȭ
    for (i = 0; i<m_size; i++) {
        Temp = m_InputImage[i];
        m_Org_Temp[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
    }

    // ���� ������׷����� �ּҰ��� �ִ밪 ����
    DMIN = m_Sum_Of_DHIST[0];
    DMAX = m_Sum_Of_DHIST[255];

    // ���ϴ� ������ ��Ȱȭ
    for (i = 0; i<256; i++) {
        m_Sum_Of_ScHIST[i] = (unsigned char)((m_Sum_Of_DHIST[i]
            - DMIN)*HIGH / (DMAX - DMIN));
    }


    // ������̺��� �̿��� ��ȭ
    for (; ; ) {
        for (i = m_Sum_Of_ScHIST[bottom];
            i <= m_Sum_Of_ScHIST[top]; i++) {
            m_TABLE[i] = top;
        }
        top = bottom;
        bottom = bottom - 1;

        if (bottom < -1)
            break;
    }

    for (i = 0; i<m_size; i++) {
        DADD = (int)m_Org_Temp[i];
        m_OutputImage[i] = m_TABLE[DADD];
    }

}


void CImageProcessingDoc::OnEmbossing()
{
    int i, j;
    double EmboMask[3][3] = { { -1., 0., 0. },{ 0., 0., 0. },{ 0., 0., 1. } };
    // ����ũ ����
    // double EmboMask[3][3] = {{0., 0., 0.}, {0., 1., 0.}, {0., 0., 0.}};
    // double EmboMask[3][3] = {{1., 1., 1.}, {1., -8.,1.}, {1., 1., 1.}};

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;
    m_OutputImage = new unsigned char[m_Re_size];
    m_tempImage = OnMaskProcess(m_InputImage, EmboMask);
    // OnMaskProcess �Լ��� ȣ���Ͽ� ȸ�� ó���� �Ѵ�.

    for (i = 0; i<m_Re_height; i++) {
        for (j = 0; j<m_Re_width; j++) {
            if (m_tempImage[i][j] > 255.)
                m_tempImage[i][j] = 255.;
            if (m_tempImage[i][j] < 0.)
                m_tempImage[i][j] = 0.;
        }
    } // ȸ�� ó�� ����� 0~255 ���� ���� �ǵ��� �Ѵ�.

      // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);
      // ����ȭ �Լ��� ����� ��

      // ȸ�� ó�� ����� ����ȭ ó�� ����� 2���� �迭 ���� �ǹǷ�
      // 2���� �迭�� 1���� �迭�� �ٲپ� ����ϵ��� �Ѵ�.
    for (i = 0; i<m_Re_height; i++) {
        for (j = 0; j<m_Re_width; j++) {
            m_OutputImage[i*m_Re_width + j]
                = (unsigned char)m_tempImage[i][j];
        }
    }

}

double** CImageProcessingDoc::OnMaskProcess(unsigned char *Target, double Mask[3][3])
{ // ȸ�� ó���� �Ͼ�� �Լ�
    int i, j, n, m;
    double **tempInputImage, **tempOutputImage, S = 0.0;

    tempInputImage = Image2DMem(m_height + 2, m_width + 2);
    // �Է� ���� ���� �޸� �Ҵ�
    tempOutputImage = Image2DMem(m_height, m_width);
    // ��� ���� ���� �޸� �Ҵ�

    // 1���� �Է� ������ ���� 2���� �迭�� �Ҵ��Ѵ�.
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInputImage[i + 1][j + 1]
                = (double)Target[i * m_width + j];
        }
    }

    // ȸ������
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            for (n = 0; n<3; n++) {
                for (m = 0; m<3; m++) {
                    S += Mask[n][m] * tempInputImage[i + n][j + m];
                }
            } // ȸ�� ����ũ�� ũ�� ��ŭ �̵��ϸ鼭 ���� ����
            tempOutputImage[i][j] = S; // ������ ���� ��� �޸𸮿� ����
            S = 0.0; // ���� ������� �̵��ϸ� ���� ���� �ʱ�ȭ
        }
    }
    return tempOutputImage; // ��� �� ��ȯ
}

double** CImageProcessingDoc::OnScale(double **Target, int height, int width)
{ // ����ȭ�� ���� �Լ�
    int i, j;
    double min, max;

    min = max = Target[0][0];

    for (i = 0; i<height; i++) {
        for (j = 0; j<width; j++) {
            if (Target[i][j] <= min)
                min = Target[i][j];
        }
    }

    for (i = 0; i<height; i++) {
        for (j = 0; j<width; j++) {
            if (Target[i][j] >= max)
                max = Target[i][j];
        }
    }

    max = max - min;

    for (i = 0; i<height; i++) {
        for (j = 0; j<width; j++) {
            Target[i][j] = (Target[i][j] - min) * (255. / max);
        }
    }

    return Target;
}
double** CImageProcessingDoc::Image2DMem(int height, int width)
{ // 2���� �޸� �Ҵ��� ���� �Լ�
    double** temp;
    int i, j;
    temp = new double *[height];
    for (i = 0; i<height; i++) {
        temp[i] = new double[width];
    }
    for (i = 0; i<height; i++) {
        for (j = 0; j<width; j++) {
            temp[i][j] = 0.0;
        }
    } // �Ҵ�� 2���� �޸𸮸� �ʱ�ȭ
    return temp;
}



void CImageProcessingDoc::OnBlurr()
{
    int i, j;
    double BlurrMask[3][3] = { { 1. / 9., 1. / 9., 1. / 9. },
    { 1. / 9., 1. / 9., 1. / 9. },{ 1. / 9., 1. / 9., 1. / 9. } };

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    m_tempImage = OnMaskProcess(m_InputImage, BlurrMask);
    // ���� ó��
    // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

    // ����ȭ
    for (i = 0; i<m_Re_height; i++) {
        for (j = 0; j<m_Re_width; j++) {
            if (m_tempImage[i][j] > 255.)
                m_tempImage[i][j] = 255.;
            if (m_tempImage[i][j] < 0.)
                m_tempImage[i][j] = 0.;
        }
    }
    for (i = 0; i<m_Re_height; i++) {
        for (j = 0; j<m_Re_width; j++) {
            m_OutputImage[i*m_Re_width + j]
                = (unsigned char)m_tempImage[i][j];
        }
    }

}


void CImageProcessingDoc::OnGaussianFilter()
{
    int i, j;
    double GaussianMask[3][3] = { { 1. / 16., 1. / 8., 1. / 16. },
    { 1. / 8., 1. / 4., 1. / 8. },{ 1. / 16., 1. / 8., 1. / 16. } };

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    m_tempImage = OnMaskProcess(m_InputImage, GaussianMask);
    // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

    for (i = 0; i<m_Re_height; i++) {
        for (j = 0; j<m_Re_width; j++) {
            if (m_tempImage[i][j] > 255.)
                m_tempImage[i][j] = 255.;
            if (m_tempImage[i][j] < 0.)
                m_tempImage[i][j] = 0.;
        }
    }

    for (i = 0; i<m_Re_height; i++) {
        for (j = 0; j<m_Re_width; j++) {
            m_OutputImage[i*m_Re_width + j]
                = (unsigned char)m_tempImage[i][j];
        }
    }

}


void CImageProcessingDoc::OnSharpening()
{
    int i, j;
    //double SharpeningMask[3][3] = {{-1., -1., -1.}, {-1., 9., -1.}, { -1., -1., -1. }};
    double SharpeningMask[3][3] = { { 0., -1., 0. },{ -1., 5.,-1. },{ 0., -1., 0. } };

m_Re_height = m_height;
m_Re_width = m_width;
m_Re_size = m_Re_height * m_Re_width;

m_OutputImage = new unsigned char[m_Re_size];

m_tempImage = OnMaskProcess(m_InputImage, SharpeningMask);
// m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

for (i = 0; i<m_Re_height; i++) {
    for (j = 0; j<m_Re_width; j++) {
        if (m_tempImage[i][j] > 255.)
            m_tempImage[i][j] = 255.;
        if (m_tempImage[i][j] < 0.)
            m_tempImage[i][j] = 0.;
    }
}

for (i = 0; i<m_Re_height; i++) {
    for (j = 0; j<m_Re_width; j++) {
        m_OutputImage[i*m_Re_width + j]
            = (unsigned char)m_tempImage[i][j];
    }
}


}

void CImageProcessingDoc::OnDiffOperatorHor()
{
    int i, j;
    double DiffHorMask[3][3]
        = { { 0., -1., 0. },{ 0., 1., 0. },{ 0., 0., 0. } };
    // ���� ���� ����

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;
    m_OutputImage = new unsigned char[m_Re_size];

    m_tempImage = OnMaskProcess(m_InputImage, DiffHorMask);
    // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            if (m_tempImage[i][j] > 255.)
                m_tempImage[i][j] = 255.;
            if (m_tempImage[i][j] < 0.)
                m_tempImage[i][j] = 0.;
        }
    }

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            m_OutputImage[i* m_Re_width + j]
                = (unsigned char)m_tempImage[i][j];
        }
    }
}



void CImageProcessingDoc::OnLaplacian()
{
    int i, j;
    double LaplacianMask[3][3] = { { 0., 1., 0. },{ 1., -4., 1. },{ 0., 1., 0. } };

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;
    m_OutputImage = new unsigned char[m_Re_size];

    m_tempImage = OnMaskProcess(m_InputImage, LaplacianMask);

    // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            if (m_tempImage[i][j] > 255.)
                m_tempImage[i][j] = 255.;
            if (m_tempImage[i][j] < 0.)
                m_tempImage[i][j] = 0.;
        }
    }

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            m_OutputImage[i* m_Re_width + j]
                = (unsigned char)m_tempImage[i][j];
        }
    }
}

double** CImageProcessingDoc::OnMaskProcess55(unsigned char *Target, double Mask[5][5])
{ // ȸ�� ó���� �Ͼ�� �Լ�
    int i, j, n, m; 
    double **tempInputImage, **tempOutputImage, S = 0.0;

    tempInputImage = Image2DMem(m_height + 4, m_width + 4);
    // �Է� ���� ���� �޸� �Ҵ�
    tempOutputImage = Image2DMem(m_height, m_width);
    // ��� ���� ���� �޸� �Ҵ�

    // 1���� �Է� ������ ���� 2���� �迭�� �Ҵ��Ѵ�.
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInputImage[i + 1][j + 1]
                = (double)Target[i * m_width + j];
        }
    }

    // ȸ������
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            for (n = 0; n<5; n++) {
                for (m = 0; m<5; m++) {
                    S += Mask[n][m] * tempInputImage[i + n][j + m];
                }
            } // ȸ�� ����ũ�� ũ�� ��ŭ �̵��ϸ鼭 ���� ����
            tempOutputImage[i][j] = S; // ������ ���� ��� �޸𸮿� ����
            S = 0.0; // ���� ������� �̵��ϸ� ���� ���� �ʱ�ȭ
        }
    }
    return tempOutputImage; // ��� �� ��ȯ
}

void CImageProcessingDoc::OnLog()
{
    // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

    int i, j;
    double LaplacianMask[5][5] = { { 0.,0., -1., 0.,0. },{ 0., -1., -2., -1., 0. },{ -1., -2., 16. , -2. , -1. },{0. , -1. , -2. , -1. , 0.}, { 0. , 0. , -1. , 0. , 0. } };

    m_Re_height = m_height;
    m_Re_width = m_width; 
    m_Re_size = m_Re_height * m_Re_width;
    m_OutputImage = new unsigned char[m_Re_size];

    m_tempImage = OnMaskProcess55(m_InputImage, LaplacianMask);

    // m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            if (m_tempImage[i][j] > 255.)
                m_tempImage[i][j] = 255.;
            if (m_tempImage[i][j] < 0.)
                m_tempImage[i][j] = 0.;
        }
    }

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            m_OutputImage[i* m_Re_width + j]
                = (unsigned char)m_tempImage[i][j];
        }
    }
}


void CImageProcessingDoc::OnNearest()
{
    // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
    int i, j;
    int ZoomRate = 2; // ���� Ȯ�� ����
    double **tempArray;

    m_Re_height = int(ZoomRate*m_height); // Ȯ��� ������ ����
    m_Re_width = int(ZoomRate*m_width); // Ȯ��� ������ �ʺ�
    m_Re_size = m_Re_height * m_Re_width;

    m_tempImage = Image2DMem(m_height, m_width);
    tempArray = Image2DMem(m_Re_height, m_Re_width);

    m_OutputImage = new unsigned char[m_Re_size];

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
        }
    }

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            tempArray[i][j] = m_tempImage[i / ZoomRate][j / ZoomRate];
            // �̿��� ȭ�Ҹ� �̿��� ����
        }
    }

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            m_OutputImage[i* m_Re_width + j] = (unsigned char)tempArray[i][j];
        }
    }
}



void CImageProcessingDoc::OnBilinear()
{
    int i, j, point, i_H, i_W;
    unsigned char newValue;
    double ZoomRate = 2.0, r_H, r_W, s_H, s_W;
    double C1, C2, C3, C4;

    m_Re_height = (int)(m_height * ZoomRate); // Ȯ��� ������ ����
    m_Re_width = (int)(m_width * ZoomRate); // Ȯ��� ������ �ʺ�
    m_Re_size = m_Re_height * m_Re_width;

    m_tempImage = Image2DMem(m_height, m_width);
    m_OutputImage = new unsigned char[m_Re_size];

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
        }
    }
    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            r_H = i / ZoomRate;
            r_W = j / ZoomRate;

            i_H = (int)floor(r_H);
            i_W = (int)floor(r_W);

            s_H = r_H - i_H;
            s_W = r_W - i_W;

            if (i_H < 0 || i_H >= (m_height - 1) || i_W < 0
                || i_W >= (m_width - 1))
            {
                point = i* m_Re_width + j;
                m_OutputImage[point] = 255;
            }

            else
            {
                C1 = (double)m_tempImage[i_H][i_W];
                C2 = (double)m_tempImage[i_H][i_W + 1];
                C3 = (double)m_tempImage[i_H + 1][i_W + 1];
                C4 = (double)m_tempImage[i_H + 1][i_W];

                newValue = (unsigned char)(C1*(1 - s_H)*(1 - s_W)
                    + C2*s_W*(1 - s_H) + C3*s_W*s_H + C4*(1 - s_W)*s_H);
                point = i* m_Re_width + j;
                m_OutputImage[point] = newValue;
            }
        }
    }



}


void CImageProcessingDoc::OnMedianSub()
{
    int i, j, n, m, M = 2, index = 0; // M = ���� ���ø� ����
    double *Mask, Value;

    Mask = new    double[M*M]; // ����ũ�� ũ�� ����

    m_Re_height = (m_height + 1) / M;
    m_Re_width = (m_width + 1) / M;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];
    m_tempImage = Image2DMem(m_height + 1, m_width + 1);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
        }
    }

    for (i = 0; i<m_height - 1; i = i + M) {
        for (j = 0; j<m_width - 1; j = j + M) {
            for (n = 0; n<M; n++) {
                for (m = 0; m<M; m++) {
                    Mask[n*M + m] = m_tempImage[i + n][j + m];
                    // �Է� ������ ������� �߶� ����ũ �迭�� ����
                }
            }
            OnBubleSort(Mask, M*M); // ����ũ�� ����� ���� ����
            Value = Mask[(int)(M*M / 2)]; // ���ĵ� �� �� ��� ���� ����
            m_OutputImage[index] = (unsigned char)Value;
            // ��� ���� ���
            index++;
        }
    }


}


void CImageProcessingDoc::OnBubleSort(double * A, int MAX)
{ // �������� ������ ó���ϴ� �Լ�
    int i, j;
    for (i = 0; i<MAX; i++) {
        for (j = 0; j<MAX - 1; j++) {
            if (A[j] > A[j + 1]) {
                OnSwap(&A[j], &A[j + 1]);
            }
        }
    }
}

void CImageProcessingDoc::OnSwap(double *a, double *b)
{ // ������ ��ȯ �Լ�
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void CImageProcessingDoc::OnMeanSub()
{
    int i, j, n, m, M = 3, index = 0, k; // M = ���� ���ø� ����
    double *Mask, Value, Sum = 0.0;

    Mask = new    double[M*M];

    m_Re_height = (m_height + 1) / M;
    m_Re_width = (m_width + 1) / M;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];
    m_tempImage = Image2DMem(m_height + 1, m_width + 1);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
        }
    }

    for (i = 0; i<m_height - 1; i = i + M) {
        for (j = 0; j<m_width - 1; j = j + M) {
            for (n = 0; n<M; n++) {
                for (m = 0; m<M; m++) {
                    Mask[n*M + m] = m_tempImage[i + n][j + m];
                }
            }
            for (k = 0; k<M*M; k++)
                Sum = Sum + Mask[k];
            // ����ũ�� ����� ���� ����
            Value = (Sum / (M*M)); // ����� ���
            m_OutputImage[index] = (unsigned char)Value;
            // ��հ��� ���
            index++;
            Sum = 0.0;
        }
    }
}


/*
CConstantDlg dlg;
int i;

m_Re_height = m_height;
m_Re_width = m_width;
m_Re_size = m_Re_height * m_Re_width;

m_OutputImage = new unsigned char[m_Re_size];

if (dlg.DoModal() == IDOK) {

}



m_OutputImage = new unsigned char[m_Re_size];

if (dlg.DoModal() == IDOK) {
for (i = 0; i<m_size; i++) {
// ��Ʈ ���� AND ����
if ((m_InputImage[i] & (unsigned char)dlg.m_Constant) >= 255)
{
m_OutputImage[i] = 255;
}
else if ((m_InputImage[i] & (unsigned char)dlg.m_Constant)< 0)
{
m_OutputImage[i] = 0;
}
else {
m_OutputImage[i] = (m_InputImage[i]
& (unsigned char)dlg.m_Constant);
}
}
}

*/

void CImageProcessingDoc::OnTranslation()
{
    CMove dlg;
    // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
    int i, j;
    int h_pos = 30, w_pos = 130;
    //���߿� ����ڰ� ���� �Է��ϵ��� �����ϱ�
    double **tempArray;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    m_tempImage = Image2DMem(m_height, m_width);
    tempArray = Image2DMem(m_Re_height, m_Re_width);


    if (dlg.DoModal() == IDOK) {

        h_pos = dlg.m_move_y;
        w_pos = dlg.m_move_y;
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
        }
    }
    for (i = 0; i<m_height - h_pos; i++) {
        for (j = 0; j<m_width - w_pos; j++) {
            tempArray[i + h_pos][j + w_pos] = m_tempImage[i][j];
            // �Է� ������ h_pos, w_pos��ŭ �̵�
        }
    }

    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            m_OutputImage[i* m_Re_width + j]
                = (unsigned char)tempArray[i][j];
        }
    }
    }
    delete[] m_tempImage;
    delete[] tempArray;


}


void CImageProcessingDoc::OnMirrorHor()
{
    int i, j;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_OutputImage[i*m_width + m_width - j - 1] =
                m_InputImage[i*m_width + j];
            // �Է� ������ �迭 ���� ��� ������ ���� 
            // �迭�� ������ ���ڸ����� ����
        }
    }

}


void CImageProcessingDoc::OnMirrorVer()
{
    int i, j;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_OutputImage[(m_height - i - 1)*m_width + j]
                = m_InputImage[i*m_width + j];
            // �Է� ������ ���� ��� ������ ���� �迭�� ������ ���ڸ����� ����
        }
    }

}


void CImageProcessingDoc::OnRotation()
{
    c_rotation dlg;

    int i, j, CenterH, CenterW, newH, newW, degree = 45;
    // degree = ȸ���� ����

    double Radian, PI, **tempArray, Value;



    if (dlg.DoModal() == IDOK) {
        i, j, CenterH, CenterW, newH, newW, degree = dlg.c_rotation_dgree;

        m_Re_height = m_height; // ȸ���� ������ ����
        m_Re_width = m_width; // ȸ���� ������ �ʺ�
        m_Re_size = m_Re_height * m_Re_width;

        m_OutputImage = new unsigned char[m_Re_size];
        PI = 3.14159265358979; // ȸ������ ���� PI ��

        Radian = (double)degree*PI / 180.0;
        // degree ���� radian���� ����
        CenterH = m_height / 2; // ������ �߽� ��ǥ
        CenterW = m_width / 2; // ������ �߽� ��ǥ

        m_tempImage = Image2DMem(m_height, m_width);
        tempArray = Image2DMem(m_Re_height, m_Re_width);

        for (i = 0; i < m_height; i++) {
            for (j = 0; j < m_width; j++) {
                m_tempImage[i][j] = (double)m_InputImage[i*m_width + j];
            }
        }
        for (i = 0; i < m_height; i++) {
            for (j = 0; j < m_width; j++) {
                // ȸ�� ��ȯ ����� �̿��Ͽ� ȸ���ϰ� �� ��ǥ �� ���
                newH = (int)((i - CenterH)*cos(Radian)
                    - (j - CenterW)*sin(Radian) + CenterH);
                newW = (int)((i - CenterH)*sin(Radian)
                    + (j - CenterW)*sin(Radian) + CenterW);

                if (newH < 0 || newH >= m_height) {
                    // ȸ���� ��ǥ�� ��� ������ ���� �迭 ���� �Ѿ ��
                    Value = 0;
                }
                else if (newW < 0 || newW >= m_width) {
                    // ȸ���� ��ǥ�� ��� ������ ���� �迭 ���� �Ѿ ��
                    Value = 0;
                }
                else {
                    Value = m_tempImage[newH][newW];
                }
                tempArray[i][j] = Value;
            }
        }

        for (i = 0; i < m_Re_height; i++) {
            for (j = 0; j < m_Re_width; j++) {
                m_OutputImage[i* m_Re_width + j]
                    = (unsigned char)tempArray[i][j];
            }
        }
    }

    delete[] m_tempImage;
    //delete[] tempArray;
    //�̹��� ���߿� �ذ��ϱ�
}



void CImageProcessingDoc::OnMorphing()
{
    // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

    CFile File;
    CFileDialog OpenDlg(TRUE);

    int i;
    unsigned char *temp;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (OpenDlg.DoModal() == IDOK) {
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);
        // ���������� ������ ���ο� ������ ��� ���� 
        // ���� ��ȭ���ڸ� �̿��� ������ �Է�

        if (File.GetLength() == (unsigned)m_width * m_height) {
            temp = new unsigned char[m_size];
            m_InputImage2 = temp;
            // �Է� �� ������ ���� �迭 ����

            File.Read(temp, m_size); // ���õ� ������ �о� �迭�� ����
            File.Close();
        }
        else {
            AfxMessageBox(CString("Image size not matched"));
            //������ ũ�Ⱑ �ٸ� ���� ó������ ����
            return;
        }
    }

}

void CImageProcessingDoc::OnWMap()
{
    // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
    int i, j, x, y;
    bool flag;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    WMap(100, 20, &x, &y);
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            WMap(j, i, &x, &y);
            flag = true;
            if ((x>m_width - 1) || (x<0) || (y>m_height - 1) || (y<0)) flag = false;
            if (flag) m_OutputImage[i* m_Re_width + j] = (unsigned char)m_InputImage[y* m_width + x];
            else m_OutputImage[i* m_Re_width + j] = 255;
        }
    }
}

void CImageProcessingDoc::WMap(int x, int y, int *wx, int *wy)
{
    //���簢���� (x0,y0), (x1,y1), (x2,y2), (x3,y3) 4���� �����������ϴ� �簢������
    int x1 = m_width + 20, y1 = 10, x2 = m_width + 10, y2 = m_height + 30, x3 = 0, y3 = m_height + 10;
    //	int x1=m_width, y1=0, x2=m_width, y2=m_height, x3=0, y3=m_height;
    float sx, sy, tx, ty;
    float k1, k2, k3, t1;

    if (x*y2 - y*x2>0) {
        k1 = x1*y2 - y1*x2;
        k2 = x1*y - y1*x;
        k3 = x*y2 - y*x2;
        if (k2 != 0) {
            t1 = k2 / k1;
            sx = x - t1*x2;
            sy = y - t1*y2;
        }
        else {
            sx = x; sy = y;
        }
        if (k3 != 0) {
            t1 = k3 / k1;
            tx = x - t1*x1;
            ty = y - t1*y1;
        }
        else {
            tx = x; ty = y;
        }
        *wx = (int)((sx / x1 + tx / x2)*m_width);
        *wy = (int)(ty*m_height / y2);
    }
    else {
        k1 = x2*y3 - y2*x3;
        k2 = x2*y - y2*x;
        k3 = x*y3 - y*x3;
        if (k2 != 0) {
            t1 = k2 / k1;
            sx = x - t1*x3;
            sy = y - t1*y3;
        }
        else {
            sx = x; sy = y;
        }
        if (k3 != 0) {
            t1 = k3 / k1;
            tx = x - t1*x2;
            ty = y - t1*y2;
        }
        else {
            tx = x; ty = y;
        }
        *wx = (int)(sx*m_width / x2);
        *wy = (int)((sy / y2 + ty / y3)*m_height);
    }
}



void CImageProcessingDoc::OnFrameSum()
{
    CFile File;
    CFileDialog OpenDlg(TRUE);

    int i, k;
    float t =1.2; // 0.5;
    unsigned char *temp;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (OpenDlg.DoModal() == IDOK) {
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);
        // ���������� ������ ���ο� ������ ��� ���� 
        // ���� ��ȭ���ڸ� �̿��� ������ �Է�

        if (File.GetLength() == (unsigned)m_width * m_height) {
            temp = new unsigned char[m_size];
            // �Է� �� ������ ���� �迭 ����

            File.Read(temp, m_size); // ���õ� ������ �о� �迭�� ����
            File.Close();

            // ������ ���� �ȼ� �� �ȼ��� �������� ����
            for (i = 0; i<m_size; i++) {
                k = (int)((1 - t)*m_InputImage[i] + t*temp[i]);
                if (k> 255)
                    m_OutputImage[i] = 255;
                else
                    m_OutputImage[i] = k;
            }
        }
        else {
            AfxMessageBox(CString("Image size not matched"));
            //������ ũ�Ⱑ �ٸ� ���� ó������ ����
            return;
        }
    }
}


void CImageProcessingDoc::OnFrameSub()
{
    CFile File;
    CFileDialog OpenDlg(TRUE);

    int i;
    unsigned char *temp;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (OpenDlg.DoModal() == IDOK) {
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);

        if (File.GetLength() == (unsigned)m_width * m_height) {
            temp = new unsigned char[m_size];

            File.Read(temp, m_size);
            File.Close();

            // ������ ���� �ȼ� �� �ȼ��� �������� ����
            for (i = 0; i<m_size; i++) {
                if (m_InputImage[i] - temp[i] < 0)
                    m_OutputImage[i] = 0;
                else
                    m_OutputImage[i] = m_InputImage[i] - temp[i];
            }
        }
        else {
            AfxMessageBox(CString("Image size not matched"));
            return;
        }
    }



}


void CImageProcessingDoc::OnFrameMul()
{
    CFile File;
    CFileDialog OpenDlg(TRUE);

    int i;
    unsigned char *temp;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];
    if (OpenDlg.DoModal() == IDOK) {
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);
        if (File.GetLength() == (unsigned)m_width * m_height) {
            temp = new unsigned char[m_size];
            File.Read(temp, m_size);
            File.Close();

            // ������ ���� �ȼ� �� �ȼ��� �������� ����
            for (i = 0; i<m_size; i++) {
                if (m_InputImage[i] * temp[i] > 255)
                    m_OutputImage[i] = 255;
                else
                    m_OutputImage[i] = m_InputImage[i] * temp[i];
            }
        }
        else {
            AfxMessageBox(CString("Image size not matched"));
            return;
        }
    }

}


void CImageProcessingDoc::OnFrameDiv()
{
    CFile File;
    CFileDialog OpenDlg(TRUE);

    int i;
    unsigned char *temp;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (OpenDlg.DoModal() == IDOK) {
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);

        if (File.GetLength() == (unsigned)m_width * m_height) {
            temp = new unsigned char[m_size];

            File.Read(temp, m_size);
            File.Close();
            // ������ ���� �ȼ� �� �ȼ��� �������� ����
            for (i = 0; i<m_size; i++) {
                if (m_InputImage[i] == 0)
                    // ������ ���̡�0���̸� ����� ���󿡼��� �ּҰ�
                    m_OutputImage[i] = 0;
                else if (temp[i] == 0)
                    // ������ ���̡�0���̸� ����� ���󿡼��� �ִ밪
                    m_OutputImage[i] = 255;
                else
                    m_OutputImage[i]
                    = (unsigned char)(m_InputImage[i] / temp[i]);
            }
        }
        else {
            AfxMessageBox((CString)"Image size not matched");
            return;
        }
    }

}


void CImageProcessingDoc::OnFrameAnd()
{
    CFile File;
    CFileDialog OpenDlg(TRUE);
    int i;
    unsigned char *temp;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (OpenDlg.DoModal() == IDOK) {
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);

        if (File.GetLength() == (unsigned)m_width * m_height) {
            temp = new unsigned char[m_size];
            File.Read(temp, m_size);
            File.Close();

            // ������ ���� �ȼ� �� �ȼ��� AND ���� ����
            for (i = 0; i<m_size; i++) {
                m_OutputImage[i]
                    = (unsigned char)(m_InputImage[i] & temp[i]);
            }
        }
        else {
            AfxMessageBox((CString)"Image size not matched");
            return;
        }
    }
}



void CImageProcessingDoc::OnFrameOr()
{
    CFile File;
    CFileDialog OpenDlg(TRUE);
    int i;
    unsigned char *temp;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    if (OpenDlg.DoModal() == IDOK) {
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);
        if (File.GetLength() == (unsigned)m_width * m_height) {
            temp = new unsigned char[m_size];

            File.Read(temp, m_size);
            File.Close();

            // ������ ���� �ȼ� �� �ȼ��� OR ���� ����
            for (i = 0; i<m_size; i++) {
                m_OutputImage[i]
                    = (unsigned char)(m_InputImage[i] | temp[i]);
            }
        }
        else {
            AfxMessageBox((CString)"Image size not matched");
            return;
        }
    }

}


void CImageProcessingDoc::OnFrameComb()
{
    CFile File;
    CFileDialog OpenDlg(TRUE);
    int i;
    unsigned char *temp = NULL, *masktemp = NULL, maskvalue;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    AfxMessageBox((CString)"�ռ��� ������ �Է��Ͻÿ�");

    if (OpenDlg.DoModal() == IDOK) { // �ռ��� ������ �Է�
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);
        temp = new unsigned char[m_size];
        File.Read(temp, m_size);

        if ((unsigned)m_width * m_height != File.GetLength()) {
            AfxMessageBox(CString("Image size not matched"));
            // ������ ũ�Ⱑ ���� ��
            return;
        }
        File.Close();
    }
    // �Է� ����, �ռ��� ����, ����ũ ������ ũ�Ⱑ ���ƾ� �Ѵ�.
    AfxMessageBox(CString("�Է� ������ ����ũ ������ �Է��Ͻÿ�"));
    if (OpenDlg.DoModal() == IDOK) { // �Է� ������ ����ũ ����
        File.Open(OpenDlg.GetPathName(), CFile::modeRead);
        masktemp = new unsigned char[m_size];
        File.Read(masktemp, m_size);
        File.Close();
    }

    for (i = 0; i<m_size; i++) {
        maskvalue = 255 - masktemp[i];
        // ������ �ִ밪���� ����ũ ������ ���� ����.
        m_OutputImage[i]
            = (m_InputImage[i] & masktemp[i]) | (temp[i] & maskvalue);
        // �Է� ����� ����ũ ������ AND ������ �ϰ�, �ռ��� ������
        // (255-����ũ ����) ���� AND ������ ������ �� �� ���� ���Ѵ�.
    }

}


void CImageProcessingDoc::OnBinaryErosion()
{
    int i, j, n, m;
    double Mask[3][3] = { { 255.,255.,255. },
    { 255.,255.,255. },
    { 255.,255.,255. } };
    // ħ�Ŀ����� ���� ����ũ
    double **tempInput, S = 0.0;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;
    m_OutputImage = new unsigned char[m_Re_size];

    tempInput = Image2DMem(m_height + 2, m_width + 2);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInput[i + 1][j + 1]
                = (double)m_InputImage[i * m_width + j];
        }
    }
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            for (n = 0; n<3; n++) {
                for (m = 0; m<3; m++) {
                    if (Mask[n][m] == tempInput[i + n][j + m]) {
                        // ����ũ�� ���� ���� �ִ��� ����
                        S += 1.0;
                    }
                }
            }
            if (S == 9.0)
                m_OutputImage[i * m_Re_width + j] = (unsigned char)255.0;
            // ���� ��� ��ġ�ϸ� ��� ���� 255
            else
                m_OutputImage[i * m_Re_width + j] = (unsigned char)0.0;
            // ��� ��ġ���� ������ ��� ���� 0
            S = 0.0; // reset
        }
    }
    delete[] tempInput;


}


void CImageProcessingDoc::OnBinaryDilation()
{
    int i, j, n, m;
    double Mask[3][3] = { { 0., 0., 0. },{ 0., 0., 0. },{ 0., 0., 0. } };
    // ��â ó���� ���� ����ũ
    double **tempInput, S = 0.0;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    tempInput = Image2DMem(m_height + 2, m_width + 2);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInput[i + 1][j + 1]
                = (double)m_InputImage[i * m_width + j];
        }
    }

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            for (n = 0; n<3; n++) {
                for (m = 0; m<3; m++) {
                    if (Mask[n][m] == tempInput[i + n][j + m]) {
                        // ����ũ�� ���� ���� �ִ��� ����
                        S += 1.0;
                    }
                }
            }
            if (S == 9.0)
                m_OutputImage[i * m_Re_width + j]
                = (unsigned char)0.0;
            // ��� ��ġ�ϸ� ��� ���� 0
            else
                m_OutputImage[i * m_Re_width + j]
                = (unsigned char)255.0;
            // ��� ��ġ���� ������ ��� ���� 255
            S = 0.0;
        }
    }
    delete[] tempInput;

}


void CImageProcessingDoc::OnGrayErosion()
{
    int i, j, n, m, h;
    double Mask[9], MIN = 10000.0; // MIN = �ּҰ�
    double **tempInput, S = 0.0;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    tempInput = Image2DMem(m_height + 2, m_width + 2);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInput[i + 1][j + 1]
                = (double)m_InputImage[i * m_width + j];
        }
    }
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            MIN = 10000.0; // reset
            for (n = 0; n<3; n++) {
                for (m = 0; m<3; m++) {
                    Mask[n * 3 + m] = tempInput[i + n][j + m];
                    // 3*3 ũ���� �Է� ���� ����ũ �迭�� ����
                }
            }
            for (h = 0; h<9; h++) {
                if (Mask[h] < MIN) // ����ũ���� �ּҰ��� ���Ѵ�.
                    MIN = Mask[h];
            }
            m_OutputImage[i * m_Re_width + j]
                = (unsigned char)MIN; // �ּҰ� ���
        }
    }
}


void CImageProcessingDoc::OnLowPassFilter()
{
    int i, j;
    double LPF[3][3] = { { 1. / 9., 1. / 9., 1. / 9. },
    { 1. / 9., 1. / 9., 1. / 9. },
    { 1. / 9., 1. / 9., 1. / 9. } };
    //double LPF[3][3] = {{1./12.,1./12.,1./12.},  {1. / 12., 4. / 12., 1. / 12.},    { 1. / 12.,1. / 12.,1. / 12. }

//double LPF[3][3] = {{1./18.,1./18.,1./18.},{1. / 18., 10. / 18., 1. / 18.},{ 1. / 18.,1. / 18.,1. / 18. }};
// ������ ���� ����ũ
    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    m_tempImage = OnMaskProcess(m_InputImage, LPF);
// �Է� ����� ����ũ�� �̿��� ȸ�� ó��

    for (i = 0; i < m_Re_height; i++) {
        for (j = 0; j < m_Re_width; j++) {
            if (m_tempImage[i][j] > 255)
                // ȸ�� ó�� ��� ���� 0~255 ������ ���� �ƴ� �� 
                // 0���� ������ 0��,
                // 255���� ũ�� 255�� ���
                m_OutputImage[i*   m_Re_width + j] = 255;
            else if (m_tempImage[i][j] < 0)
                m_OutputImage[i*   m_Re_width + j] = 0;
            else
                m_OutputImage[i*   m_Re_width + j]
                = (unsigned char)m_tempImage[i][j];
         }
    }
}


void CImageProcessingDoc::OnHighPassFilter()
{
    int i, j;
    double HPF[3][3] = { { -1. / 9., -1. / 9., -1. / 9. },
    { -1. / 9., 8 / 9., -1. / 9. },
    { -1. / 9., -1. / 9., -1. / 9. } };
    //double HPF[3][3] = {{-1., -1., -1.},    {-1., 9., -1.},    { -1., -1., -1. }};
// ������ ���� ����ũ
    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    m_tempImage = OnMaskProcess(m_InputImage, HPF);
    for (i = 0; i< m_Re_height; i++) {
        for (j = 0; j< m_Re_width; j++) {
            // ȸ�� ó�� ��� ���� 0~255 ������ ���� �ƴ� �� 
            // 0���� ������ 0��,
            // 255���� ũ�� 255�� ���
            if (m_tempImage[i][j] > 255)
                m_OutputImage[i*   m_Re_width + j] = 255;
            else if (m_tempImage[i][j] < 0)
                m_OutputImage[i*   m_Re_width + j] = 0;
            else
                m_OutputImage[i*   m_Re_width + j]
                = (unsigned char)m_tempImage[i][j];
        }
    }
}


void CImageProcessingDoc::OnMedianFilter()
{
    int i, j, n, m, index = 0;
    double **tempInputImage, Mask[9];

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    tempInputImage = Image2DMem(m_height + 2, m_width + 2);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInputImage[i + 1][j + 1]
                = (double)m_InputImage[i * m_width + j];
        }
    }
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            for (n = 0; n<3; n++) {
                for (m = 0; m<3; m++) {
                    Mask[n * 3 + m] = tempInputImage[i + n][j + m];
                    // 3*3 ũ�� �迭 ���� ����ũ �迭�� �Ҵ�
                }
            }
           ///����
//            Mask[9] = Mask[10] = Mask[4];
        //    OnBubleSort(Mask, 11); // ����ũ ���� ũ������� ����
           
             OnBubleSort(Mask, 9); // ����ũ ���� ũ������� ����
          
            m_OutputImage[index] = (unsigned char)Mask[4];
            // �߰� �� ���
            index++; // ��� �迭�� ��ǥ
        }
    }
}


void CImageProcessingDoc::OnWeightmedianfilter()
{
    int i, j, n, m, index = 0;
    double **tempInputImage, Mask[11];

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    tempInputImage = Image2DMem(m_height + 2, m_width + 2);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInputImage[i + 1][j + 1]
                = (double)m_InputImage[i * m_width + j];
        }
    }
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            for (n = 0; n<3; n++) {
                for (m = 0; m<3; m++) {
                    Mask[n * 3 + m] = tempInputImage[i + n][j + m];
                    // 3*3 ũ�� �迭 ���� ����ũ �迭�� �Ҵ�
                }
            }
            ///����
            Mask[9] = Mask[10] = Mask[4];
            //Mask[9] = Mask[10]= tempInputImage[i + 1][j + 1]; ���� ����.
            OnBubleSort(Mask, 11); // ����ũ ���� ũ������� ����

            m_OutputImage[index] = (unsigned char)Mask[5];
            // �߰� �� ���
            index++; // ��� �迭�� ��ǥ
        }
    }
}


void CImageProcessingDoc::OnMaxFilter()
{
    int i, j, n, m, index = 0;
    double **tempInputImage, Mask[9];

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    tempInputImage = Image2DMem(m_height + 2, m_width + 2);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInputImage[i + 1][j + 1]
                = (double)m_InputImage[i * m_width + j];
        }
    }
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            for (n = 0; n<3; n++) {
                for (m = 0; m<3; m++) {
                    Mask[n * 3 + m] = tempInputImage[i + n][j + m];
                    // 3*3 ũ�� �迭 ���� ����ũ �迭�� �Ҵ�
                }
            }
            OnBubleSort(Mask, 9); // ����ũ �迭 ���� ũ������� ����
            m_OutputImage[index] = (unsigned char)Mask[8];
            // �ִ밪 ���
            index++; // ��� �迭�� ��ǥ
        }
    }


}


void CImageProcessingDoc::OnMinFilter()
{
    int i, j, n, m, index = 0;
    double **tempInputImage, Mask[9];

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    tempInputImage = Image2DMem(m_height + 2, m_width + 2);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInputImage[i + 1][j + 1]
                = (double)m_InputImage[i * m_width + j];
        }
    }
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            for (n = 0; n<3; n++) {
                for (m = 0; m<3; m++) {
                    Mask[n * 3 + m] = tempInputImage[i + n][j + m];
                    // 3*3 ũ�� �迭 ���� ����ũ �迭�� �Ҵ�
                }
            }
            OnBubleSort(Mask, 9); // ����ũ ���� ũ������� ����
            m_OutputImage[index] = (unsigned char)Mask[0];
            // �ּҰ� ����
            index++; // ��� �迭�� ��ǥ
        }
    }
}


void CImageProcessingDoc::OnChaincodes()
{
    int i, j;
    const POINT nei[8] = { { -1,0 },{ -1,-1 },{ 0,-1 },{ 1,-1 },{ 1,0 },{ 1,1 },{ 0,1 },{ -1,1 } };
    int x0, y0, x, y, k, n, u, v;
    int sh;
    double **tempInput;

    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;

    m_OutputImage = new unsigned char[m_Re_size];

    tempInput = Image2DMem(m_height, m_width);

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            tempInput[j][i]
                = (double)m_InputImage[i * m_width + j];
        }
    }

    for (x = 1; x<m_width; x++) { //ù��° �� ã��
        for (y = 1; y<m_height; y++) {
            if (tempInput[x][y]>128) break;
        }
        if (y<m_height && tempInput[x][y]>128) break;
    }

    n_eg = 0;		// ������� ������ ���� ���� ī����
    x0 = x;	y0 = y;
    n = 1;				// ������ �������� ���� �÷��� ���� ������� ã�� ����
    do {
        EG[n_eg].x = x;
        EG[n_eg++].y = y;
        for (k = 0; k<8; k++, n = ((n + 1) & 7)) {
            u = x + nei[n].x;
            v = y + nei[n].y;
            if (u<0 || u >= m_width || v<0 || v >= m_height) continue;
            if (tempInput[u][v]>128) break;
        }
        if (k == 8) break;
        x = x + nei[n].x;
        y = y + nei[n].y;
        n = (n + 5) & 7;
    } while (!(x == x0 && y == y0));	// ������ ���� ������� ������ ��������

    for (i = 0; i<m_size; i++) m_OutputImage[i] = 0;

    for (i = 0; i<n_eg; i++) {
        m_OutputImage[EG[i].y* m_width + EG[i].x] = 255; //��輱���
    }
}

void CImageProcessingDoc::GetCorners(CPoint* EG, int st, int en)
{
    float err = 20, min_d = 5;
    //err : ������ ���� �����ټ��� �� ���̻���
    float t, p, t1, l, d;
    float Tx, Ty;
    int brkp = -1;
    CPoint P, T, T1, B(EG[st].x, EG[st].y), E(EG[en].x, EG[en].y);
    float max_d = err;
    T = E - B;

    t = sqrt((float)(T.x*T.x + T.y*T.y)); //T�� scalar ��=����
                                          //���̰� sampling �Ÿ����� �۰ų� ���̿� ���� ������ ������ ���� Ư¡��(breakpoint)����
    if ((t<min_d && en - st<min_d) || (en - st<2)) {
        BP[n_bp++] = en;
    }
    else { //�ƴϸ� 
        Tx = T.x / t;  // ���� ������ ��������
        Ty = T.y / t;
        //���� ������ ���ͷ� ���� �ִ� ��Ŭ����� �Ÿ� �˻��Ͽ� breakpoint ã��
        for (int j = st + 1; j<en; j++) {
            P = EG[j] - B; //ù�����κ��� �������� �̸��� ����
            T = EG[j] - E;
            p = sqrt((float)(P.x*P.x + P.y*P.y));
            t = sqrt((float)(T.x*T.x + T.y*T.y));
            if (p>min_d && t>min_d) {
                d = Tx*P.y - Ty*P.x; if (d<0) d = -d;
                if (d>max_d) {
                    max_d = d;
                    brkp = j;
                }
            }
        }
        if ((brkp != -1)) {
            GetCorners(EG, st, brkp); //breakpoint �������� �ٽ� ������
            GetCorners(EG, brkp, en);
        }
        else {
            BP[n_bp++] = en;
        }
    }
}

void CImageProcessingDoc::OnCorners() {
    
}


void CImageProcessingDoc::OnLinesmoothing()
{
    struct Edge {
        float x, y;
    } E1[2000], E2[2000];
    int i, j, n = 300;
    int x1, y1;


    sm_dlg dlg;
    if (dlg.DoModal() == IDOK) {
        n = dlg.n_input;
        m_Re_height = m_height;
        m_Re_width = m_width;
        m_Re_size = m_Re_height * m_Re_width;

        m_OutputImage = new unsigned char[m_Re_size];

        OnChaincodes();

        for (i = 0; i < n_eg; i++) { E1[i].x = EG[i].x; E1[i].y = EG[i].y; }
        E1[n_eg].x = E1[0].x; E1[n_eg].y = E1[0].y;
        E1[n_eg + 1].x = E1[1].x; E1[n_eg + 1].y = E1[1].y;

        for (j = 0; j < n; j++) {
            for (i = 1; i <= n_eg; i++) {
                E2[i].x = (E1[i - 1].x + E1[i].x + E1[i + 1].x) / 3;
                E2[i].y = (E1[i - 1].y + E1[i].y + E1[i + 1].y) / 3;
            }
            for (i = 1; i <= n_eg; i++) { E1[i].x = E2[i].x; E1[i].y = E2[i].y; }
            E1[0].x = E1[n_eg].x; E1[0].y = E1[n_eg].y;
            E1[n_eg + 1].x = E1[1].x; E1[n_eg + 1].y = E1[1].y;
        }

        for (i = 0; i < m_Re_size; i++) m_OutputImage[i] = 0;

        for (i = 0; i < n_eg; i++) {
            x1 = (int)E1[i].x; y1 = (int)E1[i].y;
            m_OutputImage[y1* m_width + x1] = 255; //��輱���
        }

    }
}


void CImageProcessingDoc::OnFft2d()
{
    int i, j, row, col, Log2N, Num;
    Complex *Data;
    unsigned char **temp;
    double Value, Absol;

    Num = m_width;
    Log2N = 0;

    while (Num >= 2) // ������ �ʺ� ���
    {
        Num >>= 1;
        Log2N++;
    }
    m_Re_height = m_height;
    m_Re_width = m_width;
    m_Re_size = m_Re_height * m_Re_width;
    m_OutputImage = new unsigned char[m_Re_size];
    m_tempImage = Image2DMem(m_height, m_width); // ��� ��� �Ҵ�

    Data = new Complex[m_width];
    m_FFT = new Complex *[m_height];
    // ���ļ� ���� ��ȯ ������ �����ϱ� ���� �迭
    temp = new unsigned char *[m_height];

    for (i = 0; i<m_height; i++) {
        m_FFT[i] = new Complex[m_width];
        temp[i] = new unsigned char[m_width];
    }
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            Data[j].Re = (double)m_InputImage[i*m_width + j];
            // �Է��� �� ���� ����, �Ǽ� ���� ���� ������ ��
            Data[j].Im = 0.0; // ���� ���� ���� 0
        }
        OnFft1d(Data, m_width, Log2N); // 1���� FFT
        for (j = 0; j<m_width; j++) { // ��� ����
            m_FFT[i][j].Re = Data[j].Re;
            m_FFT[i][j].Im = Data[j].Im;
        }
    }

    Num = m_height;
    Log2N = 0;

    while (Num >= 2) // ������ ���� ���
    {
        Num >>= 1;
        Log2N++;
    }

    Data = new Complex[m_height];

    for (i = 0; i<m_width; i++) {
        for (j = 0; j<m_height; j++) {
            Data[j].Re = m_FFT[j][i].Re; // ������ �� ���� ����
            Data[j].Im = m_FFT[j][i].Im;
        }

        OnFft1d(Data, m_height, Log2N); // 1���� FFT

        for (j = 0; j<m_height; j++) { // ��� ����
            m_FFT[j][i].Re = Data[j].Re;
            m_FFT[j][i].Im = Data[j].Im;
        }
    }
    // FFT ���� ����� �������� ����ϱ� ���� ����
    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            Value = sqrt((m_FFT[i][j].Re * m_FFT[i][j].Re) +
                (m_FFT[i][j].Im * m_FFT[i][j].Im));
            Absol = 20 * log(Value);

            if (Absol > 255.0)
                Absol = 255.0;
            if (Absol < 0.0)
                Absol = 0.0;
            m_tempImage[i][j] = Absol;
        }
    }

    // ���ø� ���� : ������ 4����ϰ� ���ҵ� ������ ���� ��Ī �� �¿� ��Ī
    for (i = 0; i<m_height; i += m_height / 2) {
        for (int j = 0; j<m_width; j += m_width / 2) {
            for (row = 0; row<m_height / 2; row++) {
                for (col = 0; col<m_width / 2; col++) {
                    temp[(m_height / 2 - 1) - row + i][(m_width / 2 - 1) - col + j]
                        = (unsigned char)m_tempImage[i + row][j + col];
                }
            }
        }
    }

    for (i = 0; i < m_height; i++) {
        for (j = 0; j < m_width; j++) {
            m_OutputImage[i*m_width + j] = temp[i][j];
        }
    }

    delete[] Data, **temp;


}

void CImageProcessingDoc::OnFft1d(Complex *X, int N, int Log2N)
{
    // 1���� fft�� ���� �Լ�
    OnShuffle(X, N, Log2N); // �Լ� ȣ��
    OnButterfly(X, N, Log2N, 1); // �Լ� ȣ��
}


void CImageProcessingDoc::OnShuffle(Complex *X, int N, int Log2N)
{
    // �Է� �������� ������ �ٱ��� ���� �Լ�
    int i;
    Complex *temp;

    temp = new Complex[N];

    for (i = 0; i<N; i++) {
        temp[i].Re = X[OnReverseBitOrder(i, Log2N)].Re;
        temp[i].Im = X[OnReverseBitOrder(i, Log2N)].Im;
    }

    for (i = 0; i<N; i++) {
        X[i].Re = temp[i].Re;
        X[i].Im = temp[i].Im;
    }
    delete[] temp;
}


void CImageProcessingDoc::OnButterfly(Complex *X, int N,
    int Log2N, int mode)
{
    // ����(Butterfly) ������ ���� �Լ�
    int i, j, k, m;

    int start;
    double Value;
    double PI = 3.14159265358979;

    Complex *Y, temp;

    Y = new Complex[N / 2];

    for (i = 0; i<Log2N; i++) {
        Value = pow(2.0, i + 1);

        if (mode == 1) {
            for (j = 0; j<(int)(Value / 2); j++) {
                Y[j].Re = cos(j*2.0*PI / Value);
                Y[j].Im = -sin(j*2.0*PI / Value);
            }
        }

        if (mode == 2) {
            for (j = 0; j<(int)(Value / 2); j++) {
                Y[j].Re = cos(j*2.0*PI / Value);
                Y[j].Im = sin(j*2.0*PI / Value);
            }
        }

        start = 0;

        for(k = 0; k < N/(int)Value; k++) {
            for (j = start; j<start + (int)(Value / 2); j++) {
                m = j + (int)(Value / 2);
                temp.Re = Y[j - start].Re * X[m].Re - Y[j - start].Im * X[m].Im;
                temp.Im = Y[j - start].Im * X[m].Re + Y[j - start].Re * X[m].Im;

                X[m].Re = X[j].Re - temp.Re;
                X[m].Im = X[j].Im - temp.Im;

                X[j].Re = X[j].Re + temp.Re;
                X[j].Im = X[j].Im + temp.Im;
            }
            start = start + (int)Value;
        }
    }

    if (mode == 2) {
        for (i = 0; i<N; i++) {
            X[i].Re = X[i].Re / N;
            X[i].Im = X[i].Im / N;
        }
    }
    delete[] Y;
}

int CImageProcessingDoc::OnReverseBitOrder(int index, int Log2N)
{
    int i, X, Y;
    Y = 0;
    for (i = 0; i<Log2N; i++) {
        X = (index & (1 << i)) >> i;
        Y = (Y << 1) | X;
    }
    return Y;
}




void CImageProcessingDoc::OnIfft2d()
{
    int i, j, Num, Log2N;
    Complex *Data;

    Num = m_width;
    Log2N = 0;
    while (Num >= 2) // ���ļ� ��ȯ�� ������ �ʺ� ���
    {
        Num >>= 1;
        Log2N++;
    }

    Data = new Complex[m_height];
    m_IFFT = new Complex *[m_height]; // ����ȯ�� ������ ���� �迭

    for (i = 0; i<m_height; i++) {
        m_IFFT[i] = new Complex[m_width];
    }

    for (i = 0; i< m_height; i++) {
        for (j = 0; j<m_width; j++) { // �� ���� ����
            Data[j].Re = m_FFT[i][j].Re;
            Data[j].Im = m_FFT[i][j].Im;
        }

        OnIfft1d(Data, m_width, Log2N); // 1���� IFFT
        for (j = 0; j<m_width; j++) {
            m_IFFT[i][j].Re = Data[j].Re; // ��� ����
            m_IFFT[i][j].Im = Data[j].Im;
        }
    }

    Num = m_height;
    Log2N = 0;
    while (Num >= 2) // ���ļ� ��ȯ�� ������ ���� ���
    {
        Num >>= 1;
        Log2N++;
    }

    Data = new Complex[m_height];

    for (i = 0; i<m_width; i++) {
        for (j = 0; j<m_height; j++) {
            Data[j].Re = m_IFFT[j][i].Re; // �� ���� ����
            Data[j].Im = m_IFFT[j][i].Im;
        }

        OnIfft1d(Data, m_height, Log2N); // 1���� IFFT

        for (j = 0; j<m_height; j++) {
            m_IFFT[j][i].Re = Data[j].Re; // ��� ����
            m_IFFT[j][i].Im = Data[j].Im;
        }
    }

    for (i = 0; i<m_width; i++) {
        for (j = 0; j<m_height; j++) {
            m_OutputImage[i*m_width + j]
                = (unsigned char)m_IFFT[i][j].Re;
            // ��� ���
        }
    }
    delete[] Data;
}

void CImageProcessingDoc::OnIfft1d(Complex *X, int N, int Log2N)
{
    OnShuffle(X, N, Log2N);
    OnButterfly(X, N, Log2N, 2);
}



void CImageProcessingDoc::OnWaveletTransform()
{
    m_OutputImage = new unsigned char[m_size];
    pDlg = new CWaveletTransformDlg(this);
    if (pDlg->GetSafeHwnd() == NULL) pDlg->Create(IDD_WAVELET_DLG);
    pDlg->ShowWindow(SW_SHOW);

}



void CImageProcessingDoc::OnWaveletEncode()
{
    // �ִ� ���� ���� 512*512 ��� 6������ ����
    if (m_Level <= 0 || (pow(2.0, m_Level + 3) > (double)m_width) || (pow(2.0, m_Level + 3) > (double)m_height)) {
        AfxMessageBox((CString)"Not support decomposition level");
        return;
    }

    int i, j, k, width, height;
    double *m_Conv1, *m_Conv2, *m_Conv3, *m_Conv4; // Convolution�� ���� ����
    double *m_Down1, *m_Down2, *m_Down3, *m_Down4; // �ٿ� ���ø��� ���� ����
    double *m_Hor, *m_Ver1, *m_Ver2;
    double **m_L, **m_H, **m_LL, **m_LH, **m_HL, **m_HH, **m_SLL, **m_SLH, **m_SHL, **m_SHH;

    m_Conv1 = m_Conv2 = m_Conv3 = m_Conv4 = NULL;
    m_Down1 = m_Down2 = m_Down3 = m_Down4 = NULL;
    m_Hor = m_Ver1 = m_Ver2 = NULL;
    m_L = m_H = m_LL = m_LH = m_HL = m_HH = m_SLL = m_SLH = m_SHL = m_SHH = NULL;



    m_tempInput = OnMem2DAllocDouble(m_height, m_width);
    m_tempOutput = OnMem2DAllocDouble(m_height, m_width);
    m_ArrangeImage = OnMem2DAllocUnsigned(m_height, m_width);


    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_tempInput[i][j] = (double)m_InputImage[i*m_width + j];
            // 1���� �Է��� 2���� �迭�� ��ȯ
        }
    }

    OnFilterTapGen();

    m_FilterH0 = new double[m_FilterTap]; // ���� ����� ���� �迭
    m_FilterH1 = new double[m_FilterTap]; // ���� ����� ���� �迭
    m_FilterG0 = new double[m_FilterTap]; // ���� ����� ���� �迭
    m_FilterG1 = new double[m_FilterTap]; // ���� ����� ���� �迭

    OnFilterGen(m_FilterH0, m_FilterH1, m_FilterG0, m_FilterG1); // ���� ��� ����

    width = m_width;
    height = m_height;

    for (k = 0; k<m_Level; k++) {
        m_L = OnMem2DAllocDouble(height, width / 2);
        m_H = OnMem2DAllocDouble(height, width / 2);
        m_LL = OnMem2DAllocDouble(height / 2, width / 2); // LL ������ ���� �迭
        m_LH = OnMem2DAllocDouble(height / 2, width / 2); // LH ������ ���� �迭
        m_HL = OnMem2DAllocDouble(height / 2, width / 2); // HL ������ ���� �迭
        m_HH = OnMem2DAllocDouble(height / 2, width / 2); // HH ������ ���� �迭

        m_Hor = new double[width]; // Ⱦ �Է��� ���� �迭

        for (i = 0; i<height; i++) {
            for (j = 0; j<width; j++) {
                m_Hor[j] = m_tempInput[i][j]; // �Է� �迭�� 1���� �迭�� �Ҵ�
            }

            m_Conv1 = OnConvolution(m_Hor, m_FilterH0, width, 1); // Convolution ó��
            m_Conv2 = OnConvolution(m_Hor, m_FilterH1, width, 1); // Convolution ó��
            m_Down1 = OnDownWSampling(m_Conv1, width); // �ٿ� ���ø�
            m_Down2 = OnDownWSampling(m_Conv2, width); // �ٿ� ���ø�

            for (j = 0; j<width / 2; j++) { // �ٿ� ���ø� ����� ����
                m_L[i][j] = m_Down1[j];
                m_H[i][j] = m_Down2[j];
            }
        }

        m_Ver1 = new double[height];
        m_Ver2 = new double[height];

        for (i = 0; i<width / 2; i++) {
            for (j = 0; j<height; j++) {
                m_Ver1[j] = m_L[j][i]; // �� �������� 1���� �迭�� �Ҵ�
                m_Ver2[j] = m_H[j][i];
            }

            m_Conv1 = OnConvolution(m_Ver1, m_FilterH0, height, 1); // Convolution ó��
            m_Conv2 = OnConvolution(m_Ver1, m_FilterH1, height, 1);
            m_Conv3 = OnConvolution(m_Ver2, m_FilterH0, height, 1);
            m_Conv4 = OnConvolution(m_Ver2, m_FilterH1, height, 1);

            m_Down1 = OnDownWSampling(m_Conv1, height); // �ٿ� ���ø�
            m_Down2 = OnDownWSampling(m_Conv2, height);
            m_Down3 = OnDownWSampling(m_Conv3, height);
            m_Down4 = OnDownWSampling(m_Conv4, height);

            for (j = 0; j<height / 2; j++) {
                m_LL[j][i] = m_Down1[j]; // ��� ����
                m_LH[j][i] = m_Down2[j];
                m_HL[j][i] = m_Down3[j];
                m_HH[j][i] = m_Down4[j];
            }
        }

        m_SLL = OnWScale(m_LL, height / 2, width / 2); // ó�� ����� ����ȭ
        m_SLH = OnWScale(m_LH, height / 2, width / 2); // ó�� ����� ����ȭ
        m_SHL = OnWScale(m_HL, height / 2, width / 2); // ó�� ����� ����ȭ
        m_SHH = OnWScale(m_HH, height / 2, width / 2); // ó�� ����� ����ȭ

        for (i = 0; i<height / 2; i++) {
            for (j = 0; j<width / 2; j++) {
                m_tempOutput[i][j] = m_LL[i][j];
                m_tempOutput[i][j + (width / 2)] = m_HL[i][j];
                m_tempOutput[i + (height / 2)][j] = m_LH[i][j];
                m_tempOutput[i + (height / 2)][j + (width / 2)] = m_HH[i][j];
                // ó�� ����� ����

                m_ArrangeImage[i][j] = (unsigned char)m_SLL[i][j];
                m_ArrangeImage[i][j + (width / 2)] = (unsigned char)m_SHL[i][j];
                m_ArrangeImage[i + (height / 2)][j] = (unsigned char)m_SLH[i][j];
                m_ArrangeImage[i + (height / 2)][j + (width / 2)] = (unsigned char)m_SHH[i][j];
                // �ð������� ���� ���ϰ� �ϱ� ���� ���� ������ 
                // ����ȭ ������ ��ģ��

            }
        }

        width = width / 2; // ���ظ� ����ϱ� ���� ������ ������ ũ�⸦ ������ ����
        height = height / 2; // ���ظ� ����ϱ� ���� ������ ������ ũ�⸦ ������ ����	 

        m_tempInput = OnMem2DAllocDouble(height, width);

        for (i = 0; i<height; i++) {
            for (j = 0; j<width; j++) {
                m_tempInput[i][j] = m_LL[i][j]; // LL ���� ���ο� �Է����� �Ҵ�
            }
        }
    }

    // �޸� ����
    delete[] m_Conv1, m_Conv2, m_Conv3, m_Conv4;
    delete[] m_Down1, m_Down2, m_Down3, m_Down4;
    delete[] m_Hor, m_Ver1, m_Ver2;

    for (i = 0; i<height; i++) {
        delete[] m_LL[i]; delete[] m_LH[i]; delete[] m_HL[i]; delete[] m_HH[i];
        delete[] m_SLL[i];	delete[] m_SLH[i];	delete[] m_SHL[i];	delete[] m_SHH[i];
        delete[] m_L[i];  delete[] m_H[i];
    }
    delete m_L, m_H, m_LL, m_LH, m_HL, m_HH, m_SLL, m_SLH, m_SHL, m_SHH;

    UpdateAllViews(NULL);

}



unsigned char** CImageProcessingDoc::OnMem2DAllocUnsigned(int height, int width)
{
    // unsigned char ������ 2���� �迭 �Ҵ�
    int i, j;
    unsigned char** temp;

    temp = new unsigned char *[height];

    for (i = 0; i<height; i++) // 2���� �迭 �Ҵ�
        temp[i] = new unsigned char[width];

    for (i = 0; i<height; i++) {
        for (j = 0; j<width; j++) {
            temp[i][j] = 0; // 2���� �迭 �ʱ�ȭ
        }
    }
    return temp;


}

double** CImageProcessingDoc::OnMem2DAllocDouble(int height, int width)
{
    // double ������ 2���� �迭 �Ҵ�
    int i, j;
    double** temp;

    temp = new double *[height];

    for (i = 0; i<height; i++)
        temp[i] = new double[width];

    for (i = 0; i<height; i++) {
        for (j = 0; j<width; j++) {
            temp[i][j] = 0;
        }
    }
    return temp;



}

void CImageProcessingDoc::OnFilterTapGen()
{
    // Filter Tap ����
    switch (pDlg->m_FilterCheck)
    {
    case 0: m_FilterTap = 2;
        break;
    case 1: m_FilterTap = 4;
        break;
    case 2: m_FilterTap = 6;
        break;
    case 3: m_FilterTap = 8;
        break;
    default: AfxMessageBox((CString)"Wrong Filter Tap");
        return;
    }

}

void CImageProcessingDoc::OnFilterGen(double *m_H0, double *m_H1, double *m_G0, double *m_G1)
{
    // ���� �����
    int i;
    switch (m_FilterTap)
    {
    case 2:
        m_H0[0] = 0.70710678118655;
        m_H0[1] = 0.70710678118655;
        break;
    case 4:
        m_H0[0] = -0.12940952255092;
        m_H0[1] = 0.22414386804186;
        m_H0[2] = 0.83651630373747;
        m_H0[3] = 0.48296291314469;
        break;
    case 6:
        m_H0[0] = 0.03522629188210;
        m_H0[1] = -0.08544127388224;
        m_H0[2] = -0.13501102001039;
        m_H0[3] = 0.45987750211933;
        m_H0[4] = 0.80689150931334;
        m_H0[5] = 0.33267055295096;
        break;
    case 8:
        m_H0[0] = -0.01059740178500;
        m_H0[1] = 0.03288301166698;
        m_H0[2] = 0.03084138183599;
        m_H0[3] = -0.18703481171888;
        m_H0[4] = -0.02798376941698;
        m_H0[5] = 0.63088076792959;
        m_H0[6] = 0.71484657055254;
        m_H0[7] = 0.23037781330886;
        break;
    default:
        AfxMessageBox((CString)"Wrong Filter");
        return;
    }

    // H0 ���� ����� �̿���, H1, G0, G1 ���� ��� ����
    for (i = 0; i<m_FilterTap; i++)
        m_H1[i] = pow(-1.0, i + 1) * m_H0[m_FilterTap - i - 1];

    for (i = 0; i<m_FilterTap; i++)
        m_G0[i] = m_H0[m_FilterTap - i - 1];

    for (i = 0; i<m_FilterTap; i++)
        m_G1[i] = pow(-1.0, i) * m_H0[i];


}

double* CImageProcessingDoc::OnDownWSampling(double *m_Target, int size)
{
    // �ٿ���ø� �Լ�
    int i;
    double* m_temp;

    m_temp = new double[size / 2];

    for (i = 0; i<size / 2; i++)
        m_temp[i] = m_Target[2 * i]; // �ٿ���ø� ó��

    return m_temp;

}

double* CImageProcessingDoc::OnConvolution(double *m_Target, double *m_Filter, int size, int mode)
{
    // Circular convolution�� ���� �Լ�
    int i, j;
    double *m_temp, *m_tempConv;
    double m_sum = 0.0;

    m_temp = new double[size + m_FilterTap - 1];
    m_tempConv = new double[size];// Convolution ��� ��� �迭

    switch (mode) {
    case 1: // Circular Convolution�� ���� �ʱ�ȭ
        for (i = 0; i<size; i++)
            m_temp[i] = m_Target[i];

        for (i = 0; i<m_FilterTap - 1; i++)
            m_temp[size + i] = m_Target[i];

        break;

    case 2:
        for (i = 0; i<m_FilterTap - 1; i++)
            m_temp[i] = m_Target[size - m_FilterTap + i + 1];

        for (i = m_FilterTap - 1; i<size + m_FilterTap - 1; i++)
            m_temp[i] = m_Target[i - m_FilterTap + 1];

        break;
    }

    for (i = 0; i<size; i++) {
        for (j = 0; j<m_FilterTap; j++) {
            // Convolution ����
            m_sum += (m_temp[j + i] * m_Filter[m_FilterTap - j - 1]);
        }

        m_tempConv[i] = m_sum;
        m_sum = 0.0;
    }

    return m_tempConv; // ���� ����� return

}

double** CImageProcessingDoc::OnWScale(double **m_Target, int height, int width)
{
    // ����ȭ �Լ� : ���͸� �� ���� 0~ 255 ������ ������ ����ȭ
    int i, j;
    double min, max;
    double **temp;

    temp = OnMem2DAllocDouble(height, width);

    min = max = m_Target[0][0];

    for (i = 0; i<height; i++) {
        for (j = 0; j<width; j++) {
            if (m_Target[i][j] <= min) { // �ּҰ�
                min = m_Target[i][j];
            }

            if (m_Target[i][j] >= max) { // �ִ밪
                max = m_Target[i][j];
            }
        }
    }

    max = max - min;

    for (i = 0; i<height; i++) {
        for (j = 0; j<width; j++) {
            temp[i][j] = (m_Target[i][j] - min) * (255. / max); // ����ȭ ó��
        }
    }
    return temp;

}

void CImageProcessingDoc::OnWaveletDecode()
{
    int i, j, k;
    int width, height;
    double *tempLL, *tempLH, *tempHL, *tempHH, *tempL, *tempH;
    double **L, **H;
    double *Up1, *Up2, *Up3, *Up4;
    double *Conv1, *Conv2, *Conv3, *Conv4;
    double **R;

    tempLL = tempLH = tempHL = tempHH = tempL = tempH = NULL;
    L = H = NULL;
    Up1 = Up2 = Up3 = Up4 = NULL;
    Conv1 = Conv2 = Conv3 = Conv4 = NULL;
    R = NULL;

    width = m_width / (int)(pow(2.0, m_Level));
    height = m_height / (int)(pow(2.0, m_Level));

    m_Recon = new double[m_width * m_height];

    for (k = m_Level; k>0; k--) {
        if (width > m_width || height > m_height) { // ���� ����
            return;
        }

        tempLL = new double[height];
        tempLH = new double[height];
        tempHL = new double[height];
        tempHH = new double[height];

        L = OnMem2DAllocDouble(height * 2, width);
        H = OnMem2DAllocDouble(height * 2, width);

        tempL = new double[width];
        tempH = new double[width];

        R = OnMem2DAllocDouble(height * 2, width * 2);

        for (i = 0; i<width; i++) {
            for (j = 0; j<height; j++) { // ���Ŀ��󿡼� ó���ϰ��� �ϴ� ���� �и�
                tempLL[j] = m_tempOutput[j][i];
                tempLH[j] = m_tempOutput[j + height][i];
                tempHL[j] = m_tempOutput[j][i + width];
                tempHH[j] = m_tempOutput[j + height][i + width];
            }

            Up1 = OnUpWSampling(tempLL, height); // �� ���ø�
            Up2 = OnUpWSampling(tempLH, height);
            Up3 = OnUpWSampling(tempHL, height);
            Up4 = OnUpWSampling(tempHH, height);

            Conv1 = OnConvolution(Up1, m_FilterG0, height * 2, 2); // Convolution ����
            Conv2 = OnConvolution(Up2, m_FilterG1, height * 2, 2);
            Conv3 = OnConvolution(Up3, m_FilterG0, height * 2, 2);
            Conv4 = OnConvolution(Up4, m_FilterG1, height * 2, 2);

            for (j = 0; j<height * 2; j++) {
                L[j][i] = Conv1[j] + Conv2[j];
                H[j][i] = Conv3[j] + Conv4[j];
            }
        }

        for (i = 0; i<height * 2; i++) {
            for (j = 0; j<width; j++) {
                tempL[j] = L[i][j]; // Ⱦ ������ �и�
                tempH[j] = H[i][j];
            }


            Up1 = OnUpWSampling(tempL, width); // �� ���ø�
            Up2 = OnUpWSampling(tempH, width);

            Conv1 = OnConvolution(Up1, m_FilterG0, width * 2, 2); //Convolution ����
            Conv2 = OnConvolution(Up2, m_FilterG1, width * 2, 2);

            for (j = 0; j<width * 2; j++) {
                R[i][j] = Conv1[j] + Conv2[j];
            }
        }

        for (i = 0; i<height * 2; i++) {
            for (j = 0; j<width * 2; j++) {
                m_tempOutput[i][j] = R[i][j]; // ���� �����͸� �ٽ� ����
            }
        }
        height = height * 2; // ������ ũ�⸦ �ι� Ȯ��
        width = width * 2;

    }

    for (i = 0; i<m_height; i++) {
        for (j = 0; j<m_width; j++) {
            m_Recon[i*m_width + j] = R[i][j];
            m_OutputImage[i*m_width + j] = (unsigned char)R[i][j]; // ���� ������ ����� ���
        }
    }

    UpdateAllViews(NULL);

    // �޸� ����
    delete[] tempLL, tempLH, tempHL, tempHH, tempL, tempH;
    delete[] Up1, Up2, Up3, Up4;
    delete[] Conv1, Conv2, Conv3, Conv4;


    for (i = 0; i<m_height; i++) {
        delete[] L[i];
        delete[] H[i];
        delete[] R[i];
    }

    delete L, H, R;
}

double* CImageProcessingDoc::OnUpWSampling(double *m_Target, int size)
{
    // �� ���ø��� ���� �Լ�
    int i;
    double* m_temp;

    m_temp = new double[size * 2];

    for (i = 0; i<size * 2; i++)
        m_temp[i] = 0.0; //�ʱ�ȭ

    for (i = 0; i<size; i++)
        m_temp[2 * i] = m_Target[i]; // �����ø� ó��

    return m_temp;

}

void CImageProcessingDoc::OnSNR()
{
    double OrgSum, ErrSum, MeanErr, MeanOrg;
    int i;

    OrgSum = 0.0;
    ErrSum = 0.0;

    // calculate mean squared error
    for (i = 0; i<m_size; i++) {
        // ������ ������ ���
        ErrSum += ((double)m_InputImage[i] - m_Recon[i]) * ((double)m_InputImage[i] - m_Recon[i]);
    }
    MeanErr = ErrSum / m_size; // ���� ������ ���


    for (i = 0; i<m_size; i++) {
        // ��ȣ�� ������ ���
        OrgSum += ((double)m_InputImage[i]) * ((double)m_InputImage[i]);
    }
    MeanOrg = OrgSum / m_size; // ��ȣ ������ ���

    pDlg->m_Error = (float)MeanErr; // ���� ���
    pDlg->m_SNR = (float)(10 * (double)log10(MeanOrg / MeanErr)); // ��ȣ�� ������ ���
}
