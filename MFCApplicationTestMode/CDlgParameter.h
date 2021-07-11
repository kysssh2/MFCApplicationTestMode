#pragma once


// CDlgParameter 대화 상자

class CDlgParameter : public CDialog
{
	DECLARE_DYNAMIC(CDlgParameter)

public:
	CDlgParameter(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgParameter();
	CWnd* m_pParent = NULL;


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgParameter };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nThreshold;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
