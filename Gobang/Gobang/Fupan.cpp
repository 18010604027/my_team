// Fupan.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Gobang.h"
#include "Fupan.h"
#include "afxdialogex.h"
#include<fstream>
#include"chess_man.h"
#include"file_name.h"
#include"Game.h"
// Fupan 对话框

IMPLEMENT_DYNAMIC(Fupan, CDialogEx)

Fupan::Fupan(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Fupan::~Fupan()
{
}

void Fupan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, mylist);
	DDX_Control(pDX, IDC_S, scrbar);
}


BEGIN_MESSAGE_MAP(Fupan, CDialogEx)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &Fupan::OnNMThemeChangedScrollbar1)
	ON_BN_CLICKED(IDC_BUTTON1, &Fupan::OnBnClickedButton1)
	ON_MESSAGE(180, MyMsgHandler)
	ON_WM_CTLCOLOR()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()



// Fupan 消息处理程序
LRESULT Fupan::MyMsgHandler(WPARAM w, LPARAM l)
{
	int i = 0;
	name* temp;
	head_name = _name1.get_name1();//这里改为了get_name1()
	temp = head_name;
	for (i = 0; i <= w; i++)
	{
		temp = temp->next;
	}
	Game g1;//这是游戏窗口的变量，str1是这个对象的一个变量用这个变量来储存文件名然后传递给她
	string str_1;
	str_1 = temp->na;
	g1.str1 = str_1.c_str();
	g1.DoModal();
	/*
	CString str;
	str.Format(L"%d",w);
	MessageBox(str);
	*/
	return 0;
}


void Fupan::OnNMThemeChangedScrollbar1(NMHDR* pNMHDR, LRESULT* pResult)
{

	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Fupan::OnBnClickedButton1()
{
	CString strPath;
	wchar_t cCurrentFilePath[255];
	int nTemp;
	GetModuleFileName(NULL, cCurrentFilePath, 255);
	strPath = cCurrentFilePath;
	nTemp = strPath.ReverseFind('\\');
	strPath = strPath.Left(nTemp);
	nTemp = strPath.ReverseFind('\\');
	strPath = strPath.Left(nTemp + 1);
	std::string str_2(CW2A(strPath.GetString()));
	CString FilePathName;
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("复盘 (*.rp)|*.rp|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = strPath;
	if (dlg.DoModal() == IDOK)
	{
		FilePathName = dlg.GetPathName(); //文件名保存在了FilePathName里
		nTemp = FilePathName.GetAllocLength() - FilePathName.ReverseFind('\\');
		FilePathName = FilePathName.Right(nTemp - 1);
		nTemp = FilePathName.ReverseFind('.');
		FilePathName = FilePathName.Left(nTemp);
		Game game;
		game.str1 = FilePathName;
		game.DoModal();
		//CString cstr;
		//std::string str(CW2A(FilePathName.GetString()));
		//chess_man c1(str,1);//这就读取了一个文件里的数据
		//MessageBox(FilePathName);
	}
	else
	{
		return;
	}
}


BOOL Fupan::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	reset_bk(IDB_BITMAP2);
	/*
	for (int i = 0; i < 30; i++)
	{

		CString str;
		str.Format(L"%d",i);
		my_list.Add(str);
	}
	*/
	int i = 0;
	head_name = _name1.get_name1();
	name* p1 = head_name;
	for (i = 0; i < _name1.length; i++)//不能写i <= _name1.length
	{
		p1 = p1->next;
		string temp;
		temp = p1->na;
		CString temp2;
		temp2 = temp.c_str();
		scrbar.Add(temp2);
	}
	//name  _name1;//定义一个name的对象
	if (_name1.length <= 5)
	{
		CScrollBar* pScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLLBAR1);
		pScrollBar->SetScrollRange(0, 0);
		SCROLLINFO si;
		ZeroMemory(&si, sizeof(si));
		pScrollBar->GetScrollInfo(&si);
		si.nPage = 1;
		pScrollBar->SetScrollInfo(&si);

		return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
	}
	else
	{
		CScrollBar* pScrollBar = (CScrollBar*)GetDlgItem(IDC_SCROLLBAR1);
		pScrollBar->SetScrollRange(0, (_name1.length - 5) * 6);
		SCROLLINFO si;
		ZeroMemory(&si, sizeof(si));
		pScrollBar->GetScrollInfo(&si);
		si.nPage = 1;
		pScrollBar->SetScrollInfo(&si);

		return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
	}
}


HBRUSH Fupan::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	int ID = pWnd->GetDlgCtrlID();
	//判断控件ID为需要设置的标签时
	if (ID == IDC_SCROLLBAR1)
	{
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void Fupan::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		// TODO: 在此添加消息处理程序代码和/或调用默认值
	int pos = mylist.GetScrollPos();
	switch (nSBCode)
	{
	case SB_LINEUP:   //向左滚动一行
		pos -= 1;
		break;
	case SB_LINEDOWN: //向下滚动一行
		pos += 1;
		break;
	case SB_PAGEUP:  //向上滚动一页
		pos -= 10;
		break;
	case SB_PAGEDOWN:  //向下滚动一页
		pos += 10;
		break;
	case SB_THUMBPOSITION: //滑块当前位置
		pos = nPos;
		break;
	}
	int m2 = 10;
	int p;
	if (nPos == 0)
	{
		p = pos;
	}
	else
	{
		p = nPos;
	}
	scrbar.SetMove(10 * p);

	mylist.SetScrollPos(pos); //设置滚动条的位置

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL Fupan::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	CRect rc;
	mylist.GetWindowRect(rc);
	if (pt.x >= rc.left && pt.x <= rc.right)
	{
		if (pt.y >= rc.top && pt.y <= rc.bottom)
		{
			int pos = mylist.GetScrollPos() - zDelta / 20;
			mylist.SetScrollPos(pos);
			pos = mylist.GetScrollPos();
			scrbar.SetMove(10 * pos);
		}
	}
	scrbar.GetWindowRect(rc);
	if (pt.x >= rc.left && pt.x <= rc.right)
	{
		if (pt.y >= rc.top && pt.y <= rc.bottom)
		{
			int pos = mylist.GetScrollPos() - zDelta / 20;
			mylist.SetScrollPos(pos);
			pos = mylist.GetScrollPos();;
			scrbar.SetMove(10 * pos);
		}
	}
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}