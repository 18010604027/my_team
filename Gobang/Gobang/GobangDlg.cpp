
// GobangDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Gobang.h"
#include "GobangDlg.h"
#include "afxdialogex.h"
#include "Game.h"

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
	Game game;
	game.DoModal();
}


void CGobangDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CGobangDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CGobangDlg::OnOK();
}
void CGobangDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}
void CGobangDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	WinExec("notepad.exe 游戏说明.txt ", SW_SHOWNORMAL);
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
