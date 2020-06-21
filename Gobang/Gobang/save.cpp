// save.cpp: 实现文件
//

#include "pch.h"
#include "Gobang.h"
#include "save.h"
#include "afxdialogex.h"
#include "MyButton.h"
#include "background.h"
#include "Game.h"


// save 对话框

IMPLEMENT_DYNAMIC(save, CDialogEx)

save::save(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

save::~save()
{
}

void save::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, yes);
	DDX_Control(pDX, IDCANCEL, no);
	DDX_Control(pDX, IDC_EDIT1, edit);
}


BEGIN_MESSAGE_MAP(save, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &save::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &save::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &save::OnBnClickedCancel)
END_MESSAGE_MAP()


// save 消息处理程序


void save::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}


void save::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Game* game = (Game*)GetParent();
	CString str;
	edit.GetWindowText(str);//获取当前子窗口编辑框中的值
	std::string str1(CW2A(str.GetString()));
	game->Chess_man.change_file(str1);
	CDialogEx::OnOK();
}


void save::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

BOOL save::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	yes.SetTextColor(RGB(255, 255, 255));
	yes.SetBkColor(RGB(0, 0, 0));
	yes.SetDiaphaneity(100, 180, 10);
	no.SetTextColor(RGB(255, 255, 255));
	no.SetBkColor(RGB(0, 0, 0));
	no.SetDiaphaneity(100, 180, 10);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}