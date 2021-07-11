// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplicationTestMode.h"
#include "CDlgImage.h"
#include "afxdialogex.h"


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialog)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CDlgImage , pParent)
{

}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	drawImage();
}

void CDlgImage::drawImage() {

	CStatic* staticsize = (CStatic*)GetDlgItem(IDC_STATIC_IMAGE);
	CClientDC dc(staticsize);

	CRect rect;
	staticsize->GetClientRect(rect);

	if (m_imgFile != NULL) {
	

		int w = m_imgFile.GetWidth();
		int h = m_imgFile.GetHeight();
		
		//m_imgFile.BitBlt(dc.m_hDC, 0, 0, w, h, 0, 0);
		m_imgFile.StretchBlt(dc.m_hDC,0,0,rect.Width(), rect.Height());

	}
}

void CDlgImage::binarization(int threshold) {

	if (m_imgFile != NULL) {

		unsigned char* fm = (unsigned char*)m_imgFile.GetPixelAddress(0, m_imgFile.GetHeight() - 1);
		
		int w = m_imgFile.GetWidth();
		int h = m_imgFile.GetHeight();
	

		for (int j = 0; j < h; j++) {
			for (int i = 0;  i < w; i++) {
				unsigned char* fmTmp = fm + j * w + i;

				if (*fmTmp < threshold)
					*fmTmp = 0;
					//m_imgFile.SetPixel(i, j, 0);
				else 
					*fmTmp = 0x0ff;
					//m_imgFile.SetPixel(i, j, 0x0ff);
			}
		}
	}
}


void CDlgImage::centroid() {
	if (m_imgFile != NULL) {

		unsigned char* fm = (unsigned char*)m_imgFile.GetPixelAddress(0, m_imgFile.GetHeight() - 1);

		int w = m_imgFile.GetWidth();
		int h = m_imgFile.GetHeight();
		
		int xsum = 0;
		int ysum = 0;
		int count = 0;

		for (int j = 0; j < h; j++) {

			for (int i = 0; i < w; i++) {
				unsigned char* fmTmp = fm + j * w + i;
				if (*fmTmp == 0) {
					xsum += i; ysum += j; count++;
				}
			}
		}
		//centroid = (xsum/count, ysum/count)


		if (count > 0) {

			for (int i = -15; i < 15; i++) {
				unsigned char* fmTmp = fm + ysum / count * w + xsum / count + i;
				*fmTmp = 0;

			} // x축

			for (int i = -15; i < 15; i++) {
				unsigned char* fmTmp = fm + ysum / count * w + xsum / count + i * w;
				*fmTmp = 0;

			} // y축

		}
	}
}

void CDlgImage::graySclae(){
	if (m_imgFile != NULL) {

		unsigned char* fm = (unsigned char*)m_imgFile.GetPixelAddress(0, m_imgFile.GetHeight() - 1);

		int w = m_imgFile.GetWidth();
		int h = m_imgFile.GetHeight();
		COLORREF rgb;
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				rgb = m_imgFile.GetPixel(x, y);
				RGB2GRAY(rgb);
				//printf("drawing..[%d/%d][%d/%d]\n", y,h,x,w);
				m_imgFile.SetPixel(x, y, rgb);
				//unsigned char* fmTmp = fm + y * w + x;
				//*fmTmp = rgb;
			}
		}
	}
}

void CDlgImage::RGB2GRAY(COLORREF& rgb) {
	COLORREF grayColor = ((GetRValue(rgb) * 0.3) + (GetGValue(rgb) * 0.59) + (GetBValue(rgb) * 0.11));
	rgb = RGB(grayColor, grayColor, grayColor);
}
