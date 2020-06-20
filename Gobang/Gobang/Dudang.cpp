// Dudang.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"											//////////////////////////这是添加的
#include "Gobang.h"
#include "Dudang.h"
#include "afxdialogex.h"
#include<fstream>
#include"chess_man.h"
#ifdef _DEBUG												//////////////////////
#define new DEBUG_NEW										//////////////////////
#endif														//////////////////////
// Dudang 对话框

IMPLEMENT_DYNAMIC(Dudang, CDialogEx)

Dudang::Dudang(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Dudang::~Dudang()
{
}

void Dudang::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dudang, CDialogEx)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &Dudang::OnNMThemeChangedScrollbar1)
	ON_BN_CLICKED(IDC_BUTTON1, &Dudang::OnBnClickedButton1)
	ON_STN_CLICKED(IDC_S, &Dudang::OnStnClickedS)
END_MESSAGE_MAP()


// Dudang 消息处理程序


void Dudang::OnNMThemeChangedScrollbar1(NMHDR* pNMHDR, LRESULT* pResult)
{

	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Dudang::OnBnClickedButton1()
{

	CString FilePathName;
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("复盘 (*.rp)|*.rp|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L"c:\\users\\";
	if (dlg.DoModal() == IDOK)
	{
		FilePathName = dlg.GetPathName(); //文件名保存在了FilePathName里
		//CString cstr;
		std::string str(CW2A(FilePathName.GetString()));
		chess_man c1(str, 1);//这就读取了一个文件里的数据
	}
	else
	{
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
}
