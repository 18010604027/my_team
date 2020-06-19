
// MFCApplication2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include<string>
#include"chess_man.h"
//#include"file_name.h"//用来获取文件名的东西
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_S, my_list);
	DDX_Control(pDX, IDC_SCROLLBAR1, scr_bar);
	DDX_Control(pDX, IDC_BUTTON1, mybutton1);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_VSCROLL()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_MESSAGE(180,MyMsgHandler)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()

LRESULT CMFCApplication2Dlg::MyMsgHandler(WPARAM w, LPARAM l)
{
	int i = 0;
	name* temp;
	head_name = _name1.get_name1();//这里改为了get_name1()
	temp = head_name;
	for (i = 0; i <= w; i++)
	{
		temp = temp->next;
	}

	//Game g1;//这是游戏窗口的变量，str1是这个对象的一个变量用这个变量来储存文件名然后传递给她
	//g1.str1 = temp->na;

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
// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	set_bk(IDB_BITMAP2);
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
	name* p1=head_name;
	for (i = 0; i < _name1.length; i++)//不能写i <= _name1.length
	{
		p1 = p1->next;
		string temp;
		temp = p1->na;
		CString temp2;
		temp2 = temp.c_str();
		my_list.Add(temp2);
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

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		draw_bk(1);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int pos = scr_bar.GetScrollPos();
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
	my_list.SetMove(10 * p);

	scr_bar.SetScrollPos(pos); //设置滚动条的位置
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);


}


HBRUSH CMFCApplication2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL CMFCApplication2Dlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	CRect rc;
	scr_bar.GetWindowRect(rc);
	if (pt.x >= rc.left && pt.x <= rc.right)
	{
		if (pt.y >= rc.top && pt.y <= rc.bottom)
		{
			int pos = scr_bar.GetScrollPos() - zDelta / 20;
			scr_bar.SetScrollPos(pos);
			pos = scr_bar.GetScrollPos();
			my_list.SetMove(10 * pos);
		}
	}
	my_list.GetWindowRect(rc);
	if (pt.x >= rc.left && pt.x <= rc.right)
	{
		if (pt.y >= rc.top && pt.y <= rc.bottom)
		{
			int pos = scr_bar.GetScrollPos() - zDelta / 20;
			scr_bar.SetScrollPos(pos);
			pos = scr_bar.GetScrollPos();;
			my_list.SetMove(10 * pos);
		}
	}
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CMFCApplication2Dlg::OnBnClickedButton1()
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
		chess_man c1(str,1);//这就读取了一个文件里的数据
	}
	else
	{
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
}
/*
	CString FilePathName;
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("复盘 (*.rp)|*.rp|All Files (*.*)|*.*||"),
		NULL);



	dlg.m_ofn.lpstrInitialDir = L"c:\\users\\30464\\source\\repos\\MFCApplication14\\";
	if (dlg.DoModal() == IDOK)
	{
		FilePathName = dlg.GetPathName(); //文件名保存在了FilePathName里
		//CString cstr;
		//std::string str(CW2A(FilePathName.GetString()));
		//chess_man c1(str);//这就读取了一个文件里的数据

	}
	else
	{
		return;
	}
	/*
	CString gReadFilePathName;
	CFileDialog fileDlg(true, _T("mp3"), _T("*.mp3"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("mp3 Files (*.mp3)|*.mp3|wav File(*.wav)|*.wav|All File (*.*)|*.*||"), NULL);
	if (fileDlg.DoModal() == IDOK)    //弹出对话框
	{
		gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名
		//GetDlgItem(IDC_EDIT1)->SetWindowText(gReadFilePathName);//将路径显示
		CString filename = fileDlg.GetFileName();
	}

	*/
	// TODO: 在此添加控件通知处理程序代码
