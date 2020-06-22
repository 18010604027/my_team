// Dudang.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"											//////////////////////////这是添加的
#include "Gobang.h"
#include "Dudang.h"
#include "afxdialogex.h"
#include<fstream>
#include"chess_man.h"
#include"file_name.h"
#include"Game.h"
#include"MyButton.h"
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
	DDX_Control(pDX, IDC_SCROLLBAR1, mylist);
	DDX_Control(pDX, IDC_S, scrbar);
	DDX_Control(pDX, IDC_BUTTON2, button2);
	DDX_Control(pDX, IDC_BUTTON3, button3);
	DDX_Control(pDX, IDC_BUTTON1, button1);
}

BEGIN_MESSAGE_MAP(Dudang, CDialogEx)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &Dudang::OnNMThemeChangedScrollbar1)
	ON_BN_CLICKED(IDC_BUTTON1, &Dudang::OnBnClickedButton1)
	ON_MESSAGE(180, MyMsgHandler)
	ON_WM_CTLCOLOR()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDC_BUTTON2, &Dudang::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Dudang::OnBnClickedButton3)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// Dudang 消息处理程序
LRESULT Dudang::MyMsgHandler(WPARAM w, LPARAM l)
{
	int i = 0;
	name* temp;
	head_name = _name1.get_name1();//这里改为了get_name1()
	temp = head_name;
	for (i = 0; i <= w; i++)
	{
		temp = temp->next;
	}
	ShowWindow(SW_HIDE);
	Game game;
	game.azbycx = 1;
	string str_1;
	str_1 = temp->na;
	game.str1 = str_1.c_str();
	game.DoModal();


	CDialogEx::OnOK();
	
	
	/*
	这里需要和谷朋朋商量一下怎么返回给她
	*/
	/*
	CString str;
	str.Format(L"%d",w);
	MessageBox(str);
	*/
	return 0;
}
void Dudang::OnNMThemeChangedScrollbar1(NMHDR* pNMHDR, LRESULT* pResult)
{

	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
void Dudang::OnBnClickedButton1()
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
	std::string str_2(CW2A(strPath.GetString()));//这句话好像没啥用

	CString FilePathName;
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("读档 (*.ld)|*.ld||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = strPath;
	if (dlg.DoModal() == IDOK)
	{
		FilePathName = dlg.GetPathName(); //路径+文件名保存在了FilePathName里

		CString FilePathName2 = FilePathName;//FilePathName2将会保存文件名
		CString FilePathName3 = FilePathName;//FilePathName3与FilePathName一样
		nTemp = FilePathName2.GetAllocLength() - FilePathName2.ReverseFind('\\');//这四行是用来得到文件名的
		FilePathName2 = FilePathName2.Right(nTemp - 1);//这四行是用来得到文件名的
		nTemp = FilePathName2.ReverseFind('.');//这四行是用来得到文件名的
		FilePathName2 = FilePathName2.Left(nTemp);//这四行是用来得到文件名的
		//MessageBox(FilePathName);


		//这里还没有写完
		CString str_temp2 = FilePathName3;//获取文件所在的上一个文件夹
		nTemp = str_temp2.ReverseFind('\\');//获取文件所在的上一个文件夹
		str_temp2 = str_temp2.Left(nTemp);//获取文件所在的上一个文件夹
		nTemp = str_temp2.GetAllocLength() - str_temp2.ReverseFind('\\');//获取文件所在的上一个文件夹
		str_temp2 = str_temp2.Right(nTemp - 1);//获取文件所在的上一个文件夹
		if (str_temp2 == "date1")//复盘的时候，别写成date1，别直接复制粘贴
		{

		}
		else
		{
			int i = 0;
			name name_1;
			name* name_2;
			name_2 = name_1.get_name1();//注意，在复盘界面要调用的是get_name2，不是get_name1，别直接复制粘贴
			name_2 = name_2->next;
			std::string str_temp3(CW2A(FilePathName2.GetString()));//str_temp3储存的是文件名与FilePathName2一样
			while (name_2 != nullptr)
			{
				if (name_2->na == str_temp3)
				{
					name_2 = name_2->next;
					i++;
				}

				else
				{
					name_2 = name_2->next;
				}
			}
			if (i == 0)
			{
				//说明在allname1文件里面，没有和它重名的
			}
			else
			{
				str_temp3 = str_temp3 + "(copy)";//这里会报错
			}
			fstream file_temp("allname1.txt", ios::out | ios::app);//注意这里不能忘了app//还有一件事在复盘那里是allname2,别直接复制粘贴
			file_temp << str_temp3;
			file_temp.close();
			FilePathName2 = str_temp3.c_str();

		}



		ShowWindow(SW_HIDE);
		Game game;
		game.azbycx = 1;
		game.str1 = FilePathName2;
		game.DoModal();
		CDialogEx::OnOK();


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
BOOL Dudang::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	{
		CRect rect;
		GetWindowRect(rect);
		MoveWindow(rect.left, rect.top, 270, 325, TRUE);
		button1.GetWindowRect(rect);
		button1.MoveWindow(220, 25, 48, 300, TRUE);
		button2.GetWindowRect(rect);
		button2.MoveWindow(127, 0, rect.Width(), rect.Height(), TRUE);
		button3.GetWindowRect(rect);
		button3.MoveWindow(200, 0, rect.Width(), rect.Height(), TRUE);
		scrbar.GetWindowRect(rect);
		scrbar.MoveWindow(0, 25, rect.Width(), rect.Height(), TRUE);
		mylist.GetWindowRect(rect);
		mylist.MoveWindow(200, 25, rect.Width(), 300, TRUE);
	}
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	reset_bk(IDB_BITMAP2);
	button2.SetTextColor(RGB(255, 255, 255));
	button2.SetBkColor(RGB(0, 0, 0));
	button2.SetDiaphaneity(100, 180, 10);
	button3.SetTextColor(RGB(255, 255, 255));
	button3.SetBkColor(RGB(0, 0, 0));
	button3.SetDiaphaneity(100, 180, 10);
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
void Dudang::OnPaint()
{
	draw_bk(1);// 不为绘图消息调用 CDialogEx::OnPaint()
}
HBRUSH Dudang::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	int ID = pWnd->GetDlgCtrlID();
	//判断控件ID为需要设置的标签时
	if (ID == IDC_S)
	{
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
void Dudang::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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
BOOL Dudang::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
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
void Dudang::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//最小化—
	PostMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
void Dudang::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//退出×
	CDialogEx::OnOK();
}
LRESULT Dudang::OnNcHitTest(CPoint point)
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



