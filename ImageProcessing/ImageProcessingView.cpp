
// ImageProcessingView.cpp : CImageProcessingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImageProcessing.h"
#endif

#include "ImageProcessingDoc.h"
#include "ImageProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessingView

IMPLEMENT_DYNCREATE(CImageProcessingView, CView)

BEGIN_MESSAGE_MAP(CImageProcessingView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWN_SAMPLING, &CImageProcessingView::OnDownSampling)
	ON_COMMAND(ID_UP_SAMPLING, &CImageProcessingView::OnUpSampling)
    ON_COMMAND(ID_QUANTIZATION, &CImageProcessingView::OnQuantization)
    ON_COMMAND(ID_SUM_CONSTANT, &CImageProcessingView::OnSumConstant)
    ON_COMMAND(ID_SUB_CONSTANT, &CImageProcessingView::OnSubConstant)
    ON_COMMAND(ID_MUL_CONSTANT, &CImageProcessingView::OnMulConstant)
    ON_COMMAND(ID_DIV_CONSTANT, &CImageProcessingView::OnDivConstant)
    ON_COMMAND(ID_AND_OPERATE, &CImageProcessingView::OnAndOperate)
    ON_COMMAND(ID_OR_OPERATE, &CImageProcessingView::OnOrOperate)
    ON_COMMAND(ID_XOR_OPERATE, &CImageProcessingView::OnXorOperate)
    ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessingView::OnNegaTransform)
    ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessingView::OnGammaCorrection)
    ON_COMMAND(ID_BINARIZATION, &CImageProcessingView::OnBinarization)
    ON_COMMAND(ID_HISTO_STRETCH, &CImageProcessingView::OnHistoStretch)
    ON_COMMAND(ID_END_IN_SEARCH, &CImageProcessingView::OnEndInSearch)
    ON_COMMAND(ID_HISTOGRAM, &CImageProcessingView::OnHistogram)
    ON_COMMAND(ID_HISTO_EQUAL, &CImageProcessingView::OnHistoEqual)
    ON_COMMAND(ID_HISTO_SPEC, &CImageProcessingView::OnHistoSpec)
    ON_COMMAND(ID_EMBOSSING, &CImageProcessingView::OnEmbossing)
    ON_COMMAND(ID_BLURR, &CImageProcessingView::OnBlurr)
    ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessingView::OnGaussianFilter)
    ON_COMMAND(ID_SHARPENING, &CImageProcessingView::OnSharpening)
    ON_COMMAND(ID_LAPLACIAN, &CImageProcessingView::OnLaplacian)
    ON_COMMAND(ID_LoG, &CImageProcessingView::OnLog)
    ON_COMMAND(ID_NEAREST, &CImageProcessingView::OnNearest)
    ON_COMMAND(ID_BILINEAR, &CImageProcessingView::OnBilinear)

    ON_COMMAND(ID_MEDIAN_SUB, &CImageProcessingView::OnMedianSub)
    ON_COMMAND(ID_MEAN_SUB, &CImageProcessingView::OnMeanSub)
    ON_COMMAND(ID_TRANSLATION, &CImageProcessingView::OnTranslation)

    ON_COMMAND(ID_MIRROR_HOR, &CImageProcessingView::OnMirrorHor)
    ON_COMMAND(ID_MIRROR_VER, &CImageProcessingView::OnMirrorVer)
    ON_COMMAND(ID_ROTATION, &CImageProcessingView::OnRotation)
    ON_COMMAND(ID_MORPHING, &CImageProcessingView::OnMorphing)

    ON_COMMAND(ID_WMap, &CImageProcessingView::OnWMap)
  //  ON_UPDATE_COMMAND_UI(ID_WMap, &CImageProcessingView::OnUpdateWmap)
    ON_COMMAND(ID_FRAME_SUM, &CImageProcessingView::OnFrameSum)
    ON_COMMAND(ID_FRAME_SUB, &CImageProcessingView::OnFrameSub)
    ON_COMMAND(ID_FRAME_MUL, &CImageProcessingView::OnFrameMul)
    ON_COMMAND(ID_FRAME_DIV, &CImageProcessingView::OnFrameDiv)
    ON_COMMAND(ID_FRAME_AND, &CImageProcessingView::OnFrameAnd)
    ON_COMMAND(ID_FRAME_OR, &CImageProcessingView::OnFrameOr)
    ON_COMMAND(ID_FRAME_COMB, &CImageProcessingView::OnFrameComb)
END_MESSAGE_MAP()

// CImageProcessingView ����/�Ҹ� 

CImageProcessingView::CImageProcessingView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CImageProcessingView::~CImageProcessingView()
{
}

BOOL CImageProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CImageProcessingView �׸���

void CImageProcessingView::OnDraw(CDC* pDC)
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	
	int i, j;
	unsigned char R, G, B;

	for (i = 0; i<pDoc->m_height; i++) {
		for (j = 0; j<pDoc->m_width; j++) {
			R = G = B = pDoc->m_InputImage[i*pDoc->m_width + j];
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}

	//��� ppt���� 26 ��ҵ� ������� ���α׷� �߰�
	for (i = 0; i<pDoc->m_Re_height; i++) {
		for (j = 0; j<pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i*pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}

}


// CImageProcessingView �μ�


void CImageProcessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CImageProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CImageProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CImageProcessingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessingView ����

#ifdef _DEBUG
void CImageProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessingDoc* CImageProcessingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessingDoc)));
	return (CImageProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessingView �޽��� ó����


void CImageProcessingView::OnDownSampling()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//ppt���� �߰���
	CImageProcessingDoc* pDoc = GetDocument(); // Doc Ŭ���� ����
	pDoc->OnDownSampling(); // Doc Ŭ������ OnUpSampling �Լ� ȣ��
	Invalidate(TRUE); // ȭ�� ����

}


void CImageProcessingView::OnUpSampling()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CImageProcessingDoc* pDoc = GetDocument(); // Doc Ŭ���� ����
	pDoc->OnUpSampling(); // Doc Ŭ������ OnUpSampling �Լ� ȣ��
	Invalidate(TRUE); // ȭ�� ����

}


void CImageProcessingView::OnQuantization()
{
    // TODO: Add your command handler code here
    CImageProcessingDoc* pDoc = GetDocument(); // Doc Ŭ���� ����
    ASSERT_VALID(pDoc);

    pDoc->OnQuantization(); // Doc Ŭ������ OnQuantization �Լ� ȣ��

    Invalidate(TRUE); // ȭ�� ����
    // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CImageProcessingView::OnSumConstant()
{
    // TODO: Add your command handler code here
    CImageProcessingDoc* pDoc = GetDocument();
    // ��ť��Ʈ Ŭ���� ����
    ASSERT_VALID(pDoc); // �ν��Ͻ� �ּҸ� ������

    pDoc->OnSumConstant();

    Invalidate(TRUE);

}


void CImageProcessingView::OnSubConstant()
{
    // TODO: Add your command handler code here
    CImageProcessingDoc* pDoc = GetDocument();// ��ť��Ʈ Ŭ���� ����
    ASSERT_VALID(pDoc); // �ν��Ͻ� �ּҸ� ������

    pDoc->OnSubConstant();

    Invalidate(TRUE);

}


void CImageProcessingView::OnMulConstant()
{
    // TODO: Add your command handler code here
    CImageProcessingDoc* pDoc = GetDocument(); // ��ť��Ʈ Ŭ���� ����
    ASSERT_VALID(pDoc); // �ν��Ͻ� �ּҸ� ������

    pDoc->OnMulConstant();

    Invalidate(TRUE);

}


void CImageProcessingView::OnDivConstant()
{
    // TODO: Add your command handler code here
    CImageProcessingDoc* pDoc = GetDocument(); // ��ť��Ʈ Ŭ���� ����
    ASSERT_VALID(pDoc); // �ν��Ͻ� �ּҸ� ������

    pDoc->OnDivConstant();

    Invalidate(TRUE);
}


    void CImageProcessingView::OnAndOperate()
    {
        // TODO: Add your command handler code here
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnAndOperate();

        Invalidate(TRUE);
    }


    void CImageProcessingView::OnOrOperate()
    {
        // TODO: Add your command handler code here
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnOrOperate();

        Invalidate(TRUE);
    }


    void CImageProcessingView::OnXorOperate()
    {
        // TODO: Add your command handler code here
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);
        pDoc->OnXorOperate();
        Invalidate(TRUE);

    }


    void CImageProcessingView::OnNegaTransform()
    {
        // TODO: Add your command handler code here
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnNegaTransform();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnGammaCorrection()
    {
        // TODO: Add your command handler code here
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnGammaCorrection();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnBinarization()
    {
        // TODO: Add your command handler code here
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnBinarization();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnHistoStretch()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnHistoStretch();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnEndInSearch()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnEndInSearch();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnHistogram()
    {
        CImageProcessingDoc*pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnHistogram();
        Invalidate(TRUE);
    }


    void CImageProcessingView::OnHistoEqual()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnHistoEqual();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnHistoSpec()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnHistoSpec();

            Invalidate(TRUE);

    }


    void CImageProcessingView::OnEmbossing()
    {

        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnEmbossing();

        Invalidate(TRUE);
    }


    void CImageProcessingView::OnBlurr()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnBlurr();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnGaussianFilter()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnGaussianFilter();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnSharpening()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnSharpening();

        Invalidate(TRUE);

    }
    void CImageProcessingView::OnDiffOperatorHor()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnDiffOperatorHor();

        Invalidate(TRUE);
    }



    void CImageProcessingView::OnLaplacian()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnLaplacian();

        Invalidate(TRUE);
    }


    void CImageProcessingView::OnLog()
    {
        // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnLog();

        Invalidate(TRUE);
    }


    void CImageProcessingView::OnNearest()
    {
        // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnNearest();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnBilinear()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnBilinear();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnMedianSub()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnMedianSub();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnMeanSub()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnMeanSub();

        Invalidate(TRUE);

      

    }


    void CImageProcessingView::OnTranslation()
    {
        // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnTranslation();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnMirrorHor()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnMirrorHor();

        Invalidate(TRUE);
    }


    void CImageProcessingView::OnMirrorVer()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnMirrorVer();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnRotation()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnRotation();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnMorphing()
    {
        // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
        // TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
        float al;
        int i, j, k;
        unsigned char R;
        CImageProcessingDoc* pDoc = GetDocument();
        CClientDC dc(this);
        pDoc->OnMorphing(); // Doc Ŭ�������� �����ؾ� �� �Լ� �̸�
        al = 0;
        for (k = 0; k < 5; k++) {
            al += 0.2;
            for (i = 0; i < pDoc->m_size; i++) {
                pDoc->m_OutputImage[i] = (1 - al)*pDoc->m_InputImage[i] + al*pDoc->m_InputImage2[i];
            }
            for (i = 0; i < pDoc->m_height; i++) {
                for (j = 0; j < pDoc->m_width; j++) {
                    R = pDoc->m_OutputImage[i*pDoc->m_width + j];
                    dc.SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, R, R));
                }
            }
            Sleep(500);
        }
    }

    void CImageProcessingView::OnWMap()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnWMap();

        Invalidate(TRUE);

    }

    void CImageProcessingView::OnFrameSum()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnFrameSum();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnFrameSub()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnFrameSub();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnFrameMul()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnFrameMul();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnFrameDiv()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnFrameDiv();

        Invalidate(TRUE);
    }


    void CImageProcessingView::OnFrameAnd()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnFrameAnd();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnFrameOr()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnFrameOr();

        Invalidate(TRUE);

    }


    void CImageProcessingView::OnFrameComb()
    {
        CImageProcessingDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->OnFrameComb();

        Invalidate(TRUE);

    }
