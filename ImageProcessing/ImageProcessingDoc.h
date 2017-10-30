
// ImageProcessingDoc.h : CImageProcessingDoc Ŭ������ �������̽�
//


#pragma once


class CImageProcessingDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CImageProcessingDoc();
	DECLARE_DYNCREATE(CImageProcessingDoc)

// Ư���Դϴ�.
public:
	unsigned char* m_InputImage; //Input�̹���
	int m_width, m_height, m_size;

	unsigned char* m_OutputImage; //Output�̹��� �߰�
	int m_Re_width, m_Re_height, m_Re_size;

    double m_HIST[256];
    double m_Sum_Of_HIST[256];
    unsigned char m_Scale_HIST[256];
    double** m_tempImage;

// �۾��Դϴ�.
public:
	void OnDownSampling();
	void OnUpSampling();
    void OnQuantization();
    void OnSumConstant();
    void OnSubConstant();
    void OnMulConstant();
    void OnDivConstant();
    void OnAndOperate();
    void OnOrOperate();
    void OnXorOperate();
    void OnNegaTransform();
    void OnGammaCorrection();
    void OnBinarization();
    void OnHistoStretch();
    void OnHistoSpec();
    void OnBlurr();
    double ** OnMaskProcess55(unsigned char * Target, double Mask[5][5]);
    double ** OnMaskProcess(unsigned char * Target, double Mask[3][3]);
    double ** OnScale(double ** Target, int height, int width);
    double ** Image2DMem(int height, int width);

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CImageProcessingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
 //   afx_msg void OnSumConstant();
 //   afx_msg void OnSubConstant();
 //   afx_msg void OnMulConstant();
 //   afx_msg void OnDivConstant();
 //   afx_msg void OnAndOperate();
  //  afx_msg void OnOrOperate();
  //  afx_msg void OnXorOperate();
  /*  afx_msg void OnNegaTransform();
    afx_msg void OnGammaCorrection();
    afx_msg void OnBinarization();
    */
    //afx_msg void OnHistoStretch();
    afx_msg void OnEndInSearch();
    afx_msg void OnHistogram();
    afx_msg void OnHistoEqual();
//    afx_msg void OnHistoSpec();
    afx_msg void OnEmbossing();

    
     void OnGaussianFilter();
      void OnSharpening();
      void OnDiffOperatorHor();
       void OnLaplacian();
     //  double ** OnMaskProcess55(unsigned char * Target, double Mask[3][3]);
       afx_msg void OnLog();
       afx_msg void OnNearest();
       afx_msg void OnBilinear();
       afx_msg void OnMedianSub();
       void OnBubleSort(double * A, int MAX);
       void OnSwap(double * a, double * b);
       afx_msg void OnMeanSub();
       afx_msg void OnTranslation();
       afx_msg void OnMirrorHor();
       afx_msg void OnMirrorVer();
       afx_msg void OnRotation();
       afx_msg void OnMorphing();
};