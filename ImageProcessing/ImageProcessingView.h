
// ImageProcessingView.h : CImageProcessingView Ŭ������ �������̽�
//

#pragma once


class CImageProcessingView : public CView
{
protected: // serialization������ ��������ϴ�.
	CImageProcessingView();
	DECLARE_DYNCREATE(CImageProcessingView)

// Ư���Դϴ�.
public:
	CImageProcessingDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CImageProcessingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDownSampling();
	afx_msg void OnUpSampling();
    afx_msg void OnQuantization();
    afx_msg void OnSumConstant();
    afx_msg void OnSubConstant();
    afx_msg void OnMulConstant();
    afx_msg void OnDivConstant();
    afx_msg void OnAndOperate();
    afx_msg void OnOrOperate();
    afx_msg void OnXorOperate();
    afx_msg void OnNegaTransform();
    afx_msg void OnGammaCorrection();
    afx_msg void OnBinarization();
    afx_msg void OnHistoStretch();
    afx_msg void OnEndInSearch();
    afx_msg void OnHistogram();
    afx_msg void OnHistoEqual();
    afx_msg void OnHistoSpec();
    afx_msg void OnEmbossing();
    afx_msg void OnBlurr();
    afx_msg void OnGaussianFilter();
    afx_msg void OnSharpening();
    void OnDiffOperatorHor();
     void OnLaplacian();
     afx_msg void OnLog();
     afx_msg void OnNearest();
     afx_msg void OnBilinear();
     afx_msg void OnMedianSub();
     afx_msg void OnMeanSub();
     afx_msg void OnTranslation();
     afx_msg void OnMirrorHor();
     afx_msg void OnMirrorVer();
     afx_msg void OnRotation();
     afx_msg void OnMorphing();
     void OnWMap();
    
 
     afx_msg void OnFrameSum();
     afx_msg void OnFrameSub();
     afx_msg void OnFrameMul();
     afx_msg void OnFrameDiv();
     afx_msg void OnFrameAnd();
     afx_msg void OnFrameOr();
};

#ifndef _DEBUG  // ImageProcessingView.cpp�� ����� ����
inline CImageProcessingDoc* CImageProcessingView::GetDocument() const
   { return reinterpret_cast<CImageProcessingDoc*>(m_pDocument); }
#endif

