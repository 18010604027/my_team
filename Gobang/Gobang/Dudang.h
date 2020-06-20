#pragma once


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
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnStnClickedS();
};
