
// ImageProcessingDoc.h : CImageProcessingDoc 클래스의 인터페이스
//

// ImageProcessingmDoc.h : interface of the CWaveletTransformDoc class
//////////////////////////////////////////////////////////////
#if !defined (AFX_WAVELETTRANSFORMDOC_H__4A38BAEB_E3CB_44C9_B2CB_057CD4D9FF0A__INCLUDED_)
#endif
#define AFX_WAVELETTRANSFORMDOC_H__4A38BAEB_E3CB_44C9_B2CB_057CD4D9FF0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma once

#include "WaveletTransformDlg.h" // 대화상자 헤더 선언


////////////////////////
class CWaveletTransformDoc : public CDocument
{
protected: // create from serialization only
    CWaveletTransformDoc();
    DECLARE_DYNCREATE(CWaveletTransformDoc)
    // Attributes

public:
    // Operations
public:
    CWaveletTransformDlg *pDlg;

};
/////////////////////

class CImageProcessingDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageProcessingDoc();
    DECLARE_DYNCREATE(CImageProcessingDoc)
   
   

// 특성입니다.
public:
	unsigned char* m_InputImage; //Input이미지
	int m_width, m_height, m_size;

	unsigned char* m_OutputImage; //Output이미지 추가
	int m_Re_width, m_Re_height, m_Re_size;
    unsigned char **m_ArrangeImage;
    unsigned char *m_InputImage2, *m_OutputImage2;
    double m_HIST[256];
    double m_Sum_Of_HIST[256];
    unsigned char m_Scale_HIST[256];
    double** m_tempImage;
    CPoint EG[2000]; //경계선상의 점들
    int n_eg; //경계선상 점의 수
    int BP[500], n_bp; //코너점의 index, 코너점의 개수
    
    double *m_Recon;
    double *m_FilterH0, *m_FilterH1, *m_FilterG0, *m_FilterG1;
    int m_FilterTap;
    double **m_tempInput, **m_tempOutput;
    int m_Level;

    struct Complex {
        double Re; // 실수를 위한 변수
        double Im; // 허수를 위한 변수
    };
    Complex **m_FFT;
    Complex **m_IFFT;
    CWaveletTransformDlg *pDlg;

// 작업입니다.
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

    void OnSNR();
    double* OnUpWSampling(double* m_Target, int size);
    void OnWaveletDecode();
    double** OnWScale(double** m_Target, int height, int width);
    double* OnConvolution(double* m_Target, double* m_Filter, int size, int  mode);
    double* OnDownWSampling(double* m_Target, int size);
    void OnFilterGen(double* m_H0, double* m_H1, double* m_G0, double* m_G1);
    void OnFilterTapGen();
    double** OnMem2DAllocDouble(int height, int width);
    unsigned char ** OnMem2DAllocUnsigned(int height, int width);
    void OnWaveletEncode();
   
// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImageProcessingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
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
       afx_msg void OnWaveletTransform();
};
