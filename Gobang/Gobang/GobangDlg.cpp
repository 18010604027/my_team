
// GobangDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Gobang.h"
#include "GobangDlg.h"
#include "afxdialogex.h"
#include "Game.h"
#include "chess_man.h"
#include "Fupan.h"
#include "Dudang.h"


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
//protected:
	//DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton6();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


// CGobangDlg 对话框



CGobangDlg::CGobangDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GOBANG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGobangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, button1);
	DDX_Control(pDX, IDC_BUTTON2, button2);
	DDX_Control(pDX, IDC_BUTTON5, button5);
	DDX_Control(pDX, IDC_BUTTON3, button3);
	DDX_Control(pDX, IDC_BUTTON4, button4);
	DDX_Control(pDX, IDC_BUTTON6, button6);
	DDX_Control(pDX, IDC_BUTTON7, button7);
}

BEGIN_MESSAGE_MAP(CGobangDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGobangDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CGobangDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CGobangDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CGobangDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGobangDlg::OnBnClickedButton4)
	ON_WM_NCHITTEST()
	ON_MESSAGE(190, MyBoardDown)
	ON_BN_CLICKED(IDC_BUTTON6, &CGobangDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CGobangDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CGobangDlg 消息处理程序
LRESULT CGobangDlg::MyBoardDown(WPARAM x, LPARAM y)
{
	static bool i = 0;
	i = !i;
	//board.ChangeChess(x, y, i + 1);
	return 0;
}

BOOL CGobangDlg::OnInitDialog()
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
	{
		CRect rect;
		GetWindowRect(rect);
		MoveWindow(rect.left, rect.top, 780, 500, TRUE);
		button1.GetWindowRect(rect);
		button1.MoveWindow(190, 220, rect.Width(), rect.Height(), TRUE);
		button2.GetWindowRect(rect);
		button2.MoveWindow(500, 220, rect.Width(), rect.Height(), TRUE);
		button3.GetWindowRect(rect);
		button3.MoveWindow(190, 310, rect.Width(), rect.Height(), TRUE);
		button4.GetWindowRect(rect);
		button4.MoveWindow(500, 310, rect.Width(), rect.Height(), TRUE);
		button5.GetWindowRect(rect);
		button5.MoveWindow(350, 380, rect.Width(), rect.Height(), TRUE);
		button6.GetWindowRect(rect);
		button6.MoveWindow(614, 0, rect.Width(), rect.Height(), TRUE);
		button7.GetWindowRect(rect);
		button7.MoveWindow(700, 0, rect.Width(), rect.Height(), TRUE);
	}
	set_bk(IDB_BITMAP1);
	button1.SetTextColor(RGB(255, 255, 255));
	button1.SetBkColor(RGB(0, 0, 0));
	button1.SetDiaphaneity(100, 180, 10);
	button2.SetTextColor(RGB(255, 255, 255));
	button2.SetBkColor(RGB(0, 0, 0));
	button2.SetDiaphaneity(100, 180, 10);
	button3.SetTextColor(RGB(255, 255, 255));
	button3.SetBkColor(RGB(0, 0, 0));
	button3.SetDiaphaneity(100, 180, 10);
	button4.SetTextColor(RGB(255, 255, 255));
	button4.SetBkColor(RGB(0, 0, 0));
	button4.SetDiaphaneity(100, 180, 10);
	button5.SetTextColor(RGB(255, 255, 255));
	button5.SetBkColor(RGB(0, 0, 0));
	button5.SetDiaphaneity(100, 180, 10);
	button6.SetTextColor(RGB(255, 255, 255));
	button6.SetBkColor(RGB(0, 0, 0));
	button6.SetDiaphaneity(100, 180, 10);
	button7.SetTextColor(RGB(255, 255, 255));
	button7.SetBkColor(RGB(0, 0, 0));
	button7.SetDiaphaneity(100, 180, 10);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGobangDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGobangDlg::OnPaint()
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
		draw_bk(1);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGobangDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGobangDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//开始游戏
	ShowWindow(SW_HIDE);
	Game game;
	game.azbycx = 0;
	game.DoModal();
	reset_bk(IDB_BITMAP1);
	ShowWindow(SW_SHOW);
}


void CGobangDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//载入进度
	ShowWindow(SW_HIDE);
	Dudang select;
	select.DoModal();
	reset_bk(IDB_BITMAP1);
	ShowWindow(SW_SHOW);
}

void CGobangDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CGobangDlg::OnOK();
}
void CGobangDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
	Fupan back;
	back.DoModal();
	reset_bk(IDB_BITMAP1);
	ShowWindow(SW_SHOW);
}
void CGobangDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"\
中 文 名      五子棋\n\n\
英 文 名      Gobang\n\n\
棋      盘      15道盘\n\n\
棋      子      黑白棋子\n\n\
规      则      对局双方各执一色棋子，黑先、白后，交替下子，每次只能下一子，\n\
                   且下在棋盘的无子交叉点。五子连珠则获胜，一方获胜，游戏结束。\n\n\
功能说明   保存进度：保存该盘对局的游戏状态，留供以后查考。\n\n\
                 载入进度：重新读取原来的游戏状态，继续该盘对局。\n\n\
                 复       盘：对局双方将本盘对局全过程的再现。\n\n\
                 悔       棋：棋子下定后收回重下。\
", L"游戏说明");
	//WinExec("notepad.exe 游戏说明.txt ", SW_SHOWNORMAL);
}
LRESULT CGobangDlg::OnNcHitTest(CPoint point)
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


void CGobangDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	//—
}


void CGobangDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	//×
}
