
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

    unsigned char *m_InputImage2, *m_OutputImage2;
    double m_HIST[256];
    double m_Sum_Of_HIST[256];
    unsigned char m_Scale_HIST[256];
    double** m_tempImage;
    CPoint EG[2000]; //��輱���� ����
    int n_eg; //��輱�� ���� ��
    int BP[500], n_bp; //�ڳ����� index, �ڳ����� ����
    
    struct Complex {
        double Re; // �Ǽ��� ���� ����
        double Im; // ����� ���� ����
    };
    Complex **m_FFT;
    Complex **m_IFFT;


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
       void OnWMap();
     
       void WMap(int x, int y, int * wx, int * wy);
      
       afx_msg void OnFrameSum();
       afx_msg void OnFrameSub();
       afx_msg void OnFrameMul();
       afx_msg void OnFrameDiv();
       afx_msg void OnFrameAnd();
       afx_msg void OnFrameOr();
       afx_msg void OnFrameComb();
       afx_msg void OnBinaryErosion();
       afx_msg void OnBinaryDilation();
       afx_msg void OnGrayErosion();
       afx_msg void OnLowPassFilter();
       afx_msg void OnHighPassFilter();
       afx_msg void OnMedianFilter();
       afx_msg void OnWeightmedianfilter();
       afx_msg void OnMaxFilter();
       afx_msg void OnMinFilter();
       afx_msg void OnChaincodes();
       void GetCorners(CPoint * EG, int st, int en);
       void OnCorners();
      
       afx_msg void OnLinesmoothing();
       afx_msg void OnFft2d();
       void OnFft1d(Complex * X, int N, int Log2N);
       void OnShuffle(Complex * X, int N, int Log2N);
       void OnButterfly(Complex * X, int N, int Log2N, int mode);
       int OnReverseBitOrder(int index, int Log2N);
       afx_msg void OnIfft2d();
       void OnIfft1d(Complex * X, int N, int Log2N);
};
