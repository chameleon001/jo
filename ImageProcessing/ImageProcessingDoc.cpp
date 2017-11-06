
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
