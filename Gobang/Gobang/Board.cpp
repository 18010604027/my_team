#include "pch.h"
#include "Board.h"

IMPLEMENT_DYNAMIC(CBoard, CStatic)

CBoard::CBoard()
{
	now_x = -1, now_y = -1;
	dc_create = false;
	rem = false;
	down_x = -1;
	down_y = -1;
	bk = false;
	board_width = 15;
	chess_size = 30;
	crColor = RGB(0, 0, 0);
	gap = 6;
	x = chess_size / 2;
	y = chess_size / 2;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			chess[i][j] = 0;
		}
	}
}
CBoard::~CBoard()
{
	dc.DeleteDC();
	white.Destroy();
	black.Destroy();
}
BEGIN_MESSAGE_MAP(CBoard, CStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

BOOL CBoard::OnEraseBkgnd(CDC* pDC)
{
	DrawIt(pDC);
	return true;
}
void CBoard::DrawIt(CDC* pDC)
{
	pDC->SetBkMode(TRANSPARENT);
	if (!dc_create)
	{
		dc.CreateCompatibleDC(pDC);
		dc_create = !dc_create;
		this->SetWindowPos(NULL, 0, 0, 2 * x + (chess_size + gap) * (board_width - 1) + 1, 2 * y + (chess_size + gap) * (board_width - 1) + 1, SWP_NOZORDER | SWP_NOMOVE);
		Draw();
	}
	CRect rect;
	GetClientRect(&rect);
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
}
void CBoard::OnLButtonDown(UINT nFlags, CPoint point)
{
	down_x = (point.x) / (gap + chess_size);
	down_y = (point.y) / (gap + chess_size);
	if (down_x >= 0 && down_x < board_width && down_y >= 0 && down_y < board_width)
	{
		::SendMessage(GetParent()->m_hWnd , 190, down_x, down_y);
	}
	else
	{
		down_x = -1;
		down_y = -1;
	}
}
void CBoard::SetBkImage(const wchar_t* str)
{
	bk = true;
	m_bitmap.Load(str);
	if (m_bitmap.GetBPP() == 32) //确认该图像包含Alpha通道
	{
		int i;
		int j;
		for (i = 0; i < m_bitmap.GetWidth(); i++)
		{
			for (j = 0; j < m_bitmap.GetHeight(); j++)
			{
				byte* pByte = (byte*)m_bitmap.GetPixelAddress(i, j);
				pByte[0] = pByte[0] * pByte[3] / 255;
				pByte[1] = pByte[1] * pByte[3] / 255;
				pByte[2] = pByte[2] * pByte[3] / 255;
			}
		}
	}
}
void CBoard::SetWidth(int width)
{
	board_width = width;
	this->SetWindowPos(NULL, 0, 0, 2 * x + (chess_size + gap) * (board_width - 1) + 1, 2 * y + (chess_size + gap) * (board_width - 1) + 1, SWP_NOZORDER | SWP_NOMOVE);
}
void CBoard::SetSize(int size)
{
	chess_size = size;
	this->SetWindowPos(NULL, 0, 0, 2 * x + (chess_size + gap) * (board_width - 1) + 1, 2 * y + (chess_size + gap) * (board_width - 1) + 1, SWP_NOZORDER | SWP_NOMOVE);
}
void CBoard::SetGap(int _gap)
{
	gap = _gap;
	this->SetWindowPos(NULL, 0, 0, 2 * x + (chess_size + gap) * (board_width - 1) + 1, 2 * y + (chess_size + gap) * (board_width - 1) + 1, SWP_NOZORDER | SWP_NOMOVE);
}
void CBoard::SetColor(COLORREF color)
{
	crColor = color;
}
void CBoard::SetChessImage(const wchar_t* str, int chess)
{
	if (chess == 1)
	{
		white.Load(str);
		if (white.GetBPP() == 32) //确认该图像包含Alpha通道
		{
			int i;
			int j;
			for (i = 0; i < white.GetWidth(); i++)
			{
				for (j = 0; j < white.GetHeight(); j++)
				{
					byte* pByte = (byte*)white.GetPixelAddress(i, j);
					pByte[0] = pByte[0] * pByte[3] / 255;
					pByte[1] = pByte[1] * pByte[3] / 255;
					pByte[2] = pByte[2] * pByte[3] / 255;
				}
			}
		}
	}
	else if (chess == 2)
	{
		black.Load(str);
		if (black.GetBPP() == 32) //确认该图像包含Alpha通道
		{
			int i;
			int j;
			for (i = 0; i < black.GetWidth(); i++)
			{
				for (j = 0; j < black.GetHeight(); j++)
				{
					byte* pByte = (byte*)black.GetPixelAddress(i, j);
					pByte[0] = pByte[0] * pByte[3] / 255;
					pByte[1] = pByte[1] * pByte[3] / 255;
					pByte[2] = pByte[2] * pByte[3] / 255;
				}
			}
		}
	}
}

void CBoard::Draw()
{
	CDC* pdc = this->GetDC();

	//创建缓冲
	CRect rect;
	GetClientRect(&rect);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pdc, 2 * x + (chess_size + gap) * (board_width - 1) + 1, 2 * y + (chess_size + gap) * (board_width - 1) + 1);
	dc.SelectObject(&bmp);
	
	//复制背景
	if (!bk)
	{
		CPoint pt(0, 0);
		MapWindowPoints(GetParent(), &pt, 1);
		imgBackground.BitBlt(dc, rect, pt, SRCCOPY);
	}
	else
	{
		CPoint pt(0, 0);
		//MapWindowPoints(GetParent(), &pt, 1);
		m_bitmap.BitBlt(dc, rect, pt, SRCCOPY);
	}

	//创建刷子
	CPen ppenRed;
	ppenRed.CreatePen(PS_SOLID, 2, crColor);
	CBrush fillbrush;
	fillbrush.CreateSolidBrush(crColor);
	dc.SelectObject(ppenRed);
	dc.SelectObject(&fillbrush);

	//画线

	for (int i = 0; i < board_width; i++)
	{
		dc.MoveTo(x + (chess_size + gap) * i, y);
		dc.LineTo(x + (chess_size + gap) * i, y + (chess_size + gap) * (board_width - 1));
	}
	for (int i = 0; i < board_width; i++)
	{
		dc.MoveTo(x, y + (chess_size + gap) * i);
		dc.LineTo(x + (chess_size + gap) * (board_width - 1), y + (chess_size + gap) * i);
	}
	dc.Ellipse(x + (chess_size + gap) * 3 - 4, y + (chess_size + gap) * 3 - 4, x + (chess_size + gap) * 3 + 4, y + (chess_size + gap) * 3 + 4);
	dc.Ellipse(x + (chess_size + gap) * 11 - 4, y + (chess_size + gap) * 3 - 4, x + (chess_size + gap) * 11 + 4, y + (chess_size + gap) * 3 + 4);
	dc.Ellipse(x + (chess_size + gap) * 3 - 4, y + (chess_size + gap) * 11 - 4, x + (chess_size + gap) * 3 + 4, y + (chess_size + gap) * 11 + 4);
	dc.Ellipse(x + (chess_size + gap) * 11 - 4, y + (chess_size + gap) * 11 - 4, x + (chess_size + gap) * 11 + 4, y + (chess_size + gap) * 11 + 4);
	dc.Ellipse(x + (chess_size + gap) * 7 - 4, y + (chess_size + gap) * 7 - 4, x + (chess_size + gap) * 7 + 4, y + (chess_size + gap) * 7 + 4);

	//画棋子
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (chess[i][j])
			{
				DrawChess(i, j, chess[i][j], &dc);
			}

		}
	}
	//now_x = -1, now_y = -1;
	if (now_x != -1)
	{
		int len = 2;
		CPen ppen;
		ppen.CreatePen(PS_SOLID, 2, RGB(0, 128, 255));
		CBrush fillbrush2;
		fillbrush2.CreateSolidBrush(RGB(0, 128, 255));
		dc.SelectObject(ppen);
		dc.SelectObject(&fillbrush2);
		dc.Rectangle(x + now_x * (chess_size + gap) - len, y + now_y * (chess_size + gap)-len, x + now_x * (chess_size + gap) + len, y + now_y * (chess_size + gap)+len);
		/*dc.MoveTo(x + now_x * (chess_size + gap) - len, y + now_y * (chess_size + gap));
		dc.LineTo(x + now_x * (chess_size + gap) + len, y + now_y * (chess_size + gap));
		dc.MoveTo(x + now_x * (chess_size + gap) , y + now_y * (chess_size + gap) - len);
		dc.LineTo(x + now_x * (chess_size + gap) , y + now_y * (chess_size + gap) + len);*/
	}
	//pdc->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);

	//dc.DeleteDC();
	bmp.DeleteObject();
}
void CBoard::DrawChess(int _x, int _y, int m, CDC* dc)
{
	if (m == 1)
	{
		white.Draw(*dc, x + (chess_size + gap) * _x - chess_size / 2, y + (chess_size + gap) * _y - chess_size / 2);
	}
	else if (m == 2)
	{
		black.Draw(*dc, x + (chess_size + gap) * _x - chess_size / 2, y + (chess_size + gap) * _y - chess_size / 2);
	}
}

int CBoard::GetDownX()
{
	return down_x;
}
int CBoard::GetDownY()
{
	return down_y;
}
void CBoard::ChangeChess(int _x, int _y, int m)
{
	chess[_x][_y] = m;
	if (m != 0)
	{
		now_x = _x, now_y = _y;
	}
	else
	{
		now_x = -1, now_y = -1;
	}
	Draw();
	DrawIt(this->GetDC());
}

void CBoard::ChangeChess2(int _x, int _y, int m)
{
	chess[_x][_y] = m;
	if (m != 0)
	{
		now_x = _x, now_y = _y;
	}
	else
	{
		now_x = -1, now_y = -1;
	}
}