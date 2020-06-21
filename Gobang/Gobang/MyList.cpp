#include "pch.h"
#include "MyList.h"
#include"background.h"

IMPLEMENT_DYNAMIC(CMyList, CStatic)

CMyList::CMyList()
{
	m_bkColor = 0xFFFFFF;
	m_textColor = 0x000000;
	bOver = 150, bDown = 100, bDisable = 20;
	choose = -1; Choose = -1;
	height = 60, width = 200;
	page_num = 5;
	page_move = 0;
	create = false;
}
CMyList::~CMyList()
{

}

BEGIN_MESSAGE_MAP(CMyList, CStatic)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
	ON_WM_ENABLE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void CMyList::SetBkColor(COLORREF color)
{
	m_bkColor = color;
}
void CMyList::SetTextColor(COLORREF color)
{
	m_textColor = color;
}
void CMyList::SetDiaphaneity(int Over, int Down, int Disable)
{
	bOver = Over, bDown = Down, bDisable = Disable;
}
void CMyList::SetButtonRect(int Height, int Width)
{
	height = Height; width = Width;
}
void CMyList::SetButtonNum(int num)
{
	page_num = num;
}
void CMyList::SetMove(int move)
{
	page_move = move;
	Draw();
}

BOOL CMyList::OnEraseBkgnd(CDC* pDC)
{
	if (!create)
	{
		this->SetWindowPos(NULL, 0, 0, width, height * page_num, SWP_NOZORDER | SWP_NOMOVE);
		create = !create;
	}
	Draw();
	return true;
}
void CMyList::OnMouseMove(UINT nFlags, CPoint point)
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
	choose = (page_move + point.y) % ((page_num + 1) * height) / height;//最后一个按钮的底边Y
	Choose = (page_move + point.y) / height;
	Draw();
	CStatic::OnMouseMove(nFlags, point);
}
void CMyList::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bDown = true;
	Draw();
	::SendMessage(GetParent()->m_hWnd, 180, Choose, 0);
	CStatic::OnLButtonDown(nFlags, point);
}
void CMyList::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bDown = false; Draw();
	CStatic::OnLButtonUp(nFlags, point);
	/*static int i = 0;
	i++;
	SetMove(i);*/
}
LRESULT CMyList::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	m_bOver = false;
	m_bTracking = false;
	m_bDown = false;
	InvalidateRect(NULL, false);
	Draw();
	return 0;
}
LRESULT CMyList::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	m_bOver = true;
	InvalidateRect(NULL);
	return 0;
}

void CMyList::DrawButton(int num, CDC* pdc)
{
	if (num >= name.GetSize())
	{
		return;
	}
	int y = num * height - page_move;
	//int y = ;
	CDC dc;
	dc.CreateCompatibleDC(pdc);
	CRect rect;
	GetClientRect(&rect);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
	dc.SelectObject(&bmp);



	CRect rc;
	rc.SetRect(0, 0, width, height);
	//-------------------------------------------------------------
	int nAlpha = 100;//0--255
	int nOffset = 0;
	HBRUSH hbr = CreateSolidBrush(m_bkColor);
	FillRect(dc, &rc, hbr);
	DeleteObject(hbr);
	if (num  == Choose)
	{
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
	}
	else
	{
		nAlpha = bDisable;
	}





	BLENDFUNCTION blend;
	memset(&blend, 0, sizeof(blend));
	blend.BlendOp = AC_SRC_OVER;
	blend.SourceConstantAlpha = nAlpha; // 透明度 最大255
	CRgn cRgn;
	cRgn.CreateRoundRectRgn(0, y, width, height + y, 3, 3);
	pdc->SelectClipRgn(&cRgn);
	pdc->AlphaBlend(0, y, width, height, &dc, 0, 0, width, height, blend);

	//按钮文字
	//CString str;
	//str.Format(L"%d", (page_move + height * (page_num + 1 - num)) / ((page_num + 1) * height) * (page_num + 1));
	//MessageBox(str);
	CString strText = name.GetAt(num);
	if (strText != _T(""))
	{
		pdc->SetBkMode(TRANSPARENT);
		rc.SetRect(0, y, width, height + y);
		rc.InflateRect(-2, -2);
		rc.OffsetRect(nOffset, nOffset);
		HFONT hFont = (HFONT)SendMessage(WM_GETFONT);
		//CFont cFont;
		//cFont.Attach(hFont);
		if (!hFont)hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
		HFONT hOldFont = (HFONT)SelectObject(pdc->GetSafeHdc(), hFont);
		::SetTextColor(pdc->GetSafeHdc(), m_textColor);
		::DrawText(pdc->GetSafeHdc(), strText, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_WORD_ELLIPSIS);
		::SelectObject(pdc->GetSafeHdc(), hOldFont);
	}
	SelectClipRgn(pdc->GetSafeHdc(), NULL);
	dc.DeleteDC();
	cRgn.DeleteObject();
}
void CMyList::Draw()
{
	CDC* pdc = this->GetDC();

	//创建缓冲
	CDC dc;
	dc.CreateCompatibleDC(pdc);
	CRect rect;
	GetClientRect(&rect);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pdc, rect.Width(), rect.Height());
	dc.SelectObject(&bmp);

	//复制背景

	CPoint pt(0, 0);
	MapWindowPoints(GetParent(), &pt, 1);
	imgBackground.BitBlt(dc, rect, pt, SRCCOPY);
	for (int i = 0; i <= page_num; i++)
	{
		DrawButton(page_move / height + i, &dc);
	}

	pdc->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
	dc.DeleteDC();
}
void CMyList::OnEnable(BOOL bEnable)
{
	CStatic::OnEnable(bEnable);
	m_bDisable = IsWindowEnabled() ? FALSE : TRUE;
	Draw();
}

void CMyList::Add(CString Name)
{
	name.Add(Name);
	Draw();
}
