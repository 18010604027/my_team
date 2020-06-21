#pragma once
#include "MyButton.h"

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
	CString edit;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
