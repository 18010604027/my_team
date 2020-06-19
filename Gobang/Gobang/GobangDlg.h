
// GobangDlg.h: 头文件
//

#pragma once
#include"background.h"
#include "MyButton.h"

// CGobangDlg 对话框
class CGobangDlg : public CDialogEx
{
// 构造
public:
	CGobangDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GOBANG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMyButton button1;
	afx_msg void OnBnClickedButton1();
	CMyButton button2;
	afx_msg void OnBnClickedButton2();
	CMyButton button5;
	afx_msg void OnBnClickedButton5();
	CMyButton button3;
	afx_msg void OnBnClickedButton3();
	CMyButton button4;
	afx_msg void OnBnClickedButton4();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg LRESULT MyBoardDown(WPARAM x, LPARAM y);
};
