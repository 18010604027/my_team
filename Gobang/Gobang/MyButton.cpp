#include "pch.h"
#include "MyButton.h"
#include"background.h"

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
{
	m_bkColor = 0xFFFFFF;
	m_textColor = 0x000000;
	bOver = 150, bDown = 180, bDisable = 90;
}
CMyButton::~CMyButton()
{

}

BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
	ON_WM_ENABLE()
END_MESSAGE_MAP()

void CMyButton::SetBkColor(COLORREF color)
{
	m_bkColor = color;
}

void CMyButton::SetTextColor(COLORREF color)
{
	m_textColor = color;
}

void CMyButton::SetDiaphaneity(int Over, int Down, int Disable)
{
	bOver = Over, bDown = Down, bDisable = Disable;
}

BOOL CMyButton::PreCreateWindow(CREATESTRUCT& cs)
{
	BOOL bRet = CButton::PreCreateWindow(cs);
	ButtonInit();
	return bRet;
}

void CMyButton::PreSubclassWindow()
{
	CButton::PreSubclassWindow();
	ButtonInit();
}

void CMyButton::ButtonInit()
{
	m_bTracking = false;
	m_bOver = m_bDown = m_bDisable = false;
	m_bDisable = IsWindowEnabled() ? false : true;
	ModifyStyle(NULL, BS_OWNERDRAW);
}

void CMyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	DrawButton(lpDrawItemStruct->hDC);
}

void CMyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	if (!m_bTracking)
	{
		m_bOver = true;
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 13;//HOVER_DEFAULT
		m_bTracking = (bool)_TrackMouseEvent(&tme);
	}
	CButton::OnMouseMove(nFlags, point);
}

void CMyButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bDown = true;
	CButton::OnLButtonDown(nFlags, point);
}

void CMyButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bDown = false;
	CButton::OnLButtonUp(nFlags, point);
}

LRESULT CMyButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	m_bOver = false;
	m_bTracking = false;
	m_bDown = false;
	InvalidateRect(NULL, false);
	return 0;
}
LRESULT CMyButton::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	m_bOver = true;
	InvalidateRect(NULL);
	return 0;
}
void CMyButton::DrawButton()
{
	HDC hDC = ::GetDC(m_hWnd);
	DrawButton(hDC);
	::ReleaseDC(m_hWnd, hDC);
}
void CMyButton::DrawButton(HDC hDestDC)
{
	CRect rc;
	GetClientRect(rc);
	int nWindth = rc.Width();
	int nHeight = rc.Height();
	HDC hDC = CreateCompatibleDC(hDestDC);
	HDC hMaskDC = CreateCompatibleDC(hDestDC);
	HBITMAP hBitmap = CreateCompatibleBitmap(hDestDC, nWindth, nHeight);
	HBITMAP hMaskBitmap = CreateCompatibleBitmap(hDestDC, nWindth, nHeight);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hDC, hBitmap);
	HBITMAP hOldMaskBitmap = (HBITMAP)SelectObject(hMaskDC, hMaskBitmap);
	SetBkMode(hDC, TRANSPARENT);
	//�Ѹ����ڵı���ͼ���Ƶ���ť��DC��,ʵ���Ӿ�͸��----------------
	CPaintDC dc(this);
	CRect Rect;
	GetClientRect(&Rect);
	int Width = Rect.Width();
	int Height = Rect.Height();
	CBitmap MemBmp;
	MemBmp.CreateCompatibleBitmap(&dc, Width, Height);
	CPoint pt(0, 0);
	MapWindowPoints(GetParent(), &pt, 1);
	imgBackground.BitBlt(hDC, rc, pt, SRCCOPY);
	//-------------------------------------------------------------
	int nAlpha = 100;//0--255
	int nOffset = 0;
	HBRUSH hbr = CreateSolidBrush(m_bkColor);
	FillRect(hMaskDC, &rc, hbr);
	DeleteObject(hbr);
	if (m_bDisable) 
	{
		nAlpha = bDisable;
	}
	else if (m_bDown) 
	{
		nAlpha = bDown;
		nOffset = 1;
	}
	else if (m_bOver) 
	{
		nAlpha = bOver;
	}
	else 
	{
		nAlpha = bDisable;
	}
	BLENDFUNCTION blend;
	memset(&blend, 0, sizeof(blend));
	blend.BlendOp = AC_SRC_OVER;
	blend.SourceConstantAlpha = nAlpha; // ͸���� ���255
	HRGN hRgn = CreateRoundRectRgn(0, 0, nWindth, nHeight, 3, 3);
	SelectClipRgn(hDC, hRgn);
	AlphaBlend(hDC, 0, 0, nWindth, nHeight, hMaskDC, 0, 0, nWindth, nHeight, blend);
	CString strText;
	GetWindowText(strText);
	if (strText != _T("")) 
	{
		rc.InflateRect(-2, -2);
		rc.OffsetRect(nOffset, nOffset);
		HFONT hFont = (HFONT)SendMessage(WM_GETFONT);
		if (!hFont)hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
		HFONT hOldFont = (HFONT)SelectObject(hDC, hFont);
		::SetTextColor(hDC, m_textColor);
		::DrawText(hDC, strText, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_WORD_ELLIPSIS);
		::SelectObject(hDC, hOldFont);
	}
	SelectClipRgn(hDC, NULL);
	DeleteObject(hRgn);
	//���Ƶ��ؼ���DC��------------------------
	BitBlt(hDestDC, 0, 0, nWindth, nHeight, hDC, 0, 0, SRCCOPY);
	//ɾ����Դ,�ͷ��ڴ�-----------------------
	SelectObject(hDC, hOldBitmap);
	DeleteObject(hBitmap);
	DeleteDC(hDC);
	SelectObject(hMaskDC, hOldMaskBitmap);
	DeleteObject(hMaskBitmap);
	DeleteDC(hMaskDC);
}
void CMyButton::OnEnable(BOOL bEnable)
{
	CButton::OnEnable(bEnable);
	m_bDisable = IsWindowEnabled() ? FALSE : TRUE;
	DrawButton();
}
