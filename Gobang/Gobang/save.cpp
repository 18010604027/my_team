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
	DDX_Control(pDX, IDC_BUTTON1, button1);
	DDX_Control(pDX, IDC_BUTTON2, button2);
}


BEGIN_MESSAGE_MAP(save, CDialogEx)
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_EDIT1, &save::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &save::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &save::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &save::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &save::OnBnClickedButton2)
	ON_WM_CTLCOLOR()
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
	{
		CRect rect;
		GetWindowRect(rect);
		MoveWindow(rect.left, rect.top, 300, 120, TRUE);
		edit.GetWindowRect(rect);
		edit.MoveWindow(40, 60, rect.Width(), 20, TRUE);
		
		GetDlgItem(IDC_STATIC)->GetWindowRect(rect);
		GetDlgItem(IDC_STATIC)->MoveWindow(20, 30, 100, rect.Height(), TRUE);

		yes.GetWindowRect(rect);
		yes.MoveWindow(145, 97, rect.Width(), rect.Height(), TRUE);
		no.GetWindowRect(rect);
		no.MoveWindow(225, 97, rect.Width(), rect.Height(), TRUE);

		button1.GetWindowRect(rect);
		button1.MoveWindow(157, 0, rect.Width(), rect.Height(), TRUE);
		button2.GetWindowRect(rect);
		button2.MoveWindow(230, 0, rect.Width(), rect.Height(), TRUE);

	}
	reset_bk(IDB_BITMAP2);
	button1.SetTextColor(RGB(255, 255, 255));
	button1.SetBkColor(RGB(0, 0, 0));
	button1.SetDiaphaneity(100, 180, 10);
	button2.SetTextColor(RGB(255, 255, 255));
	button2.SetBkColor(RGB(0, 0, 0));
	button2.SetDiaphaneity(100, 180, 10);
	yes.SetTextColor(RGB(255, 255, 255));
	yes.SetBkColor(RGB(0, 0, 0));
	yes.SetDiaphaneity(100, 180, 10);
	no.SetTextColor(RGB(255, 255, 255));
	no.SetBkColor(RGB(0, 0, 0));
	no.SetDiaphaneity(100, 180, 10);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
void save::OnPaint()
{
	draw_bk(1);// 不为绘图消息调用 CDialogEx::OnPaint()
}
LRESULT save::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ScreenToClient(&point);
	CRect rc;
	GetClientRect(&rc);
	if (rc.PtInRect(point))
	{
		return HTCAPTION;
	}
	else
	{
		return CDialog::OnNcHitTest(point);
	}
	return CDialogEx::OnNcHitTest(point);
}

void save::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//—
}


void save::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//×
}


HBRUSH save::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	int ID = pWnd->GetDlgCtrlID();
	if (ID == IDC_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
