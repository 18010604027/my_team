#pragma once
#include"MyList.h"
#include"background.h"
#include"file_name.h"
#include"MyButton.h"
// Dudang 对话框

class Dudang : public CDialogEx
{
	DECLARE_DYNAMIC(Dudang)

public:
	Dudang(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dudang();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	name  _name1;//定义一个name的对象
	name* head_name;
	afx_msg LRESULT MyMsgHandler(WPARAM, LPARAM);
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar mylist;
	CMyList scrbar;
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	CMyButton button2;
	CMyButton button3;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnStnClickedS();
};
