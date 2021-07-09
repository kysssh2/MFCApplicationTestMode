// CDlgNew.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplicationTestMode.h"
#include "CDlgNew.h"
#include "afxdialogex.h"


// CDlgNew 대화 상자

IMPLEMENT_DYNAMIC(CDlgNew, CDialogEx)

CDlgNew::CDlgNew(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NEW, pParent)
{

}

CDlgNew::~CDlgNew()
{
}

void CDlgNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgNew, CDialogEx)
END_MESSAGE_MAP()


// CDlgNew 메시지 처리기
