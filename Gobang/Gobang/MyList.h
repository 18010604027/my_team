#pragma once

#include "pch.h"



class CMyList :public CStatic
{
	DECLARE_DYNAMIC(CMyList)
public:
	CMyList();
	virtual ~CMyList();
	void SetBkColor(COLORREF color);
	void SetTextColor(COLORREF color);
	void SetDiaphaneity(int Over, int Down, int Disable);
	void SetMove(int move);

	void Add(CString name);

	void SetButtonRect(int Height, int Width);
	void SetButtonNum(int num);

	//virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	

private:
	bool m_bOver;
	bool m_bDown;
	bool m_bDisable;
	bool m_bTracking;
	COLORREF m_bkColor;
	COLORREF m_textColor;
	int choose;
	int Choose;//实际选项

	int page_move;

	int bOver;
	int bDown;
	int bDisable;

	CStringArray name;
	//CRect rc;
	int height, width;
	int page_num;
	bool create;
	//void ButtonInit();
	void DrawButton(int y, CDC* pdc);
	void Draw();

protected:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};