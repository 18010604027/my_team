﻿#pragma once
#include"background.h"
#include "MyButton.h"
#include "Board.h"
#include"chess_man.h"
#include "Rule.h"
// Game 对话框

class Game : public CDialogEx
{
	DECLARE_DYNAMIC(Game)

public:

	Game(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Game();
	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString str1;
	int azbycx;//0开始 1读档 2复盘
	bool ch;
	bool AI;
	Rule rule;
	bool win;
	chess_man Chess_man;
	bool change;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT MyBoardDown(WPARAM x, LPARAM y);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CMyButton gbutton1;
	CMyButton gbutton2;
	CMyButton gbutton3;
	CMyButton gbutton4;
	CMyButton gbutton5;
	CMyButton gbutton6;
	CMyButton gbutton7;
	CMyButton gbutton8;
	CMyButton gbutton9;
	CMyButton gbutton10;
	CBoard board;
};