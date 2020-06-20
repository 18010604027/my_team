// Fupan.cpp: 实现文件
//

#include "pch.h"
#include "Gobang.h"
#include "Fupan.h"
#include "afxdialogex.h"


// Fupan 对话框

IMPLEMENT_DYNAMIC(Fupan, CDialogEx)

Fupan::Fupan(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Fupan::~Fupan()
{
}

void Fupan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Fupan, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Fupan::OnBnClickedButton1)
END_MESSAGE_MAP()


// Fupan 消息处理程序


void Fupan::OnBnClickedButton1()
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
