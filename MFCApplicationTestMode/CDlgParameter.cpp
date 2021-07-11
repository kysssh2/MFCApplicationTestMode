// CDlgParameter.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplicationTestMode.h"
#include "CDlgParameter.h"
#include "afxdialogex.h"
#include "MFCApplicationTestModeDlg.h"


// CDlgParameter 대화 상자

IMPLEMENT_DYNAMIC(CDlgParameter, CDialog)

CDlgParameter::CDlgParameter(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CDlgParameter, pParent)
	, m_nThreshold(0)
{
	m_pParent = pParent; 
}

CDlgParameter::~CDlgParameter()
{
}

void CDlgParameter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_THR, m_nThreshold);
}


BEGIN_MESSAGE_MAP(CDlgParameter, CDialog)
END_MESSAGE_MAP()


// CDlgParameter 메시지 처리기


BOOL CDlgParameter::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (pMsg->message == WM_KEYDOWN && pMsg->hwnd == GetDlgItem(IDC_EDIT_THR)->m_hWnd) {
		// 키가 눌렸는지 , edit에서 눌렸는지 확인
		if (pMsg->wParam == VK_RETURN) {
			//엔터키인지 확인
			UpdateData(true);
			CMFCApplicationTestModeDlg* pDlg = (CMFCApplicationTestModeDlg*)m_pParent;

			pDlg->nThreshold = m_nThreshold;

			pDlg->m_pDlgParameter->ShowWindow(SW_HIDE);
			pDlg->m_pDlgImage->ShowWindow(SW_SHOW);

			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
