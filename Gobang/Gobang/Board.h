#pragma once

#include "pch.h"
#include"background.h"

class CBoard :public CStatic
{
	DECLARE_DYNAMIC(CBoard)
public:
	CBoard();
	virtual ~CBoard();
	void SetBkImage(const wchar_t* str);
	void SetWidth(int width);
	void SetSize(int size);
	void SetGap(int _gap);
	void SetColor(COLORREF color);
	void SetChessImage(const wchar_t* str, int chess);//1Ϊ�ף�2Ϊ��
	int GetDownX();//��ȡ�������ӵĺ�����
	int GetDownY();//��ȡ�������ӵ�������
	void ChangeChess(int _x, int _y, int m);//�ı������ϵ�ĳ����	
	void ChangeChess2(int _x, int _y, int m);
private:
	int board_width;
	int chess_size;
	COLORREF crColor;
	int gap;
	CImage m_bitmap;
	bool bk;//�Ƿ��б���
	CImage white, black;
	int chess[15][15];
	int x, y;
	int down_x, down_y;
	int now_x, now_y;
	bool rem;//���ڼ�¼��ǰ������ɫ(��Ϊ�ף���Ϊ��)
	CDC dc;
	bool dc_create;
protected:
	void DrawIt(CDC* pDC);
	void Draw();
	void DrawChess(int x, int y, int m, CDC* dc);

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};