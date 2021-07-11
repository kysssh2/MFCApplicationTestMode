
// MFCApplicationTestModeDlg.h: 헤더 파일
//

#pragma once
#include "BtnST.h"
#include "Label.h"
#include "ini.h"
#include "CDlgImage.h"
#include "CDlgParameter.h"





// CMFCApplicationTestModeDlg 대화 상자
class CMFCApplicationTestModeDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplicationTestModeDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATIONTESTMODE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonNew();

	int nThreshold = 128;

	CButtonST m_btnNew;
	void InitButtons(CButtonST * pButton);
	double m_dNum;
	CLabel m_ldNum;
	void InitLabel(CLabel* pLabel);

	void UpdateIni(BOOL bLoad);
	afx_msg void OnBnClickedOk();

	CDlgImage* m_pDlgImage; 
	CDlgParameter* m_pDlgParameter;

	void InitDialog();
	void setDlgView(int nMode);



	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonImage();
	afx_msg void OnBnClickedButtonParameter();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonBinary();
	afx_msg void OnBnClickedButtonCentroid();
	afx_msg void OnBnClickedButtonGray();
};
