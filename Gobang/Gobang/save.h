#pragma once
#include "MyButton.h"
#include "chess_man.h"

// save 对话框

class save : public CDialogEx
{
	DECLARE_DYNAMIC(save)

public:
	save(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~save();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyButton yes;
	CMyButton no;
	CEdit edit;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	chess_man Chess_man;
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnPaint();
	CMyButton button1;
	CMyButton button2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
