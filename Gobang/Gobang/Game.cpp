// Game.cpp: 实现文件
//

#include "pch.h"
#include "Gobang.h"
#include "Game.h"
#include "afxdialogex.h"
#include "Rule.h"
#include "chess_man.h"


// Game 对话框

IMPLEMENT_DYNAMIC(Game, CDialogEx)

Game::Game(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Game::~Game()
{
}

void Game::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, gbutton1);
	DDX_Control(pDX, IDC_BUTTON2, gbutton2);
	DDX_Control(pDX, IDC_BUTTON3, gbutton3);
	DDX_Control(pDX, IDC_BUTTON4, gbutton4);
	DDX_Control(pDX, IDC_BOARD, board);
	DDX_Control(pDX, IDC_BUTTON5, gbutton5);
	DDX_Control(pDX, IDC_BUTTON6, gbutton6);
	DDX_Control(pDX, IDC_BUTTON7, gbutton7);
}

BEGIN_MESSAGE_MAP(Game, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Game::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Game::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Game::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Game::OnBnClickedButton4)
	ON_WM_NCHITTEST()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//ON_BN_CLICKED(IDC_BUTTON5, &Game::OnBnClickedButton5)
	//ON_STN_CLICKED(IDC_BOARD, &Game::OnStnClickedBoard)
	ON_MESSAGE(190, MyBoardDown)
	ON_BN_CLICKED(IDC_BUTTON7, &Game::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &Game::OnBnClickedButton6)
END_MESSAGE_MAP()


// Game 消息处理程序
LRESULT Game::MyBoardDown(WPARAM x, LPARAM y)
{
	if (azbycx != 2)
	{
		if (win)
		{
			return 0;
		}
		ch = !ch;
		board.ChangeChess(x, y, ch + 1);
		chess chess;
		chess.x = x, chess.y = y, chess.z = ch + 1;
		rule.change(chess);
		chess_man->creat_chess(chess);
		if (rule.judge(chess))
		{
			win = true;
			if (ch)
			{
				MessageBox(L"黑棋胜", L"温馨提示");
			}
			else
			{
				MessageBox(L"白棋胜", L"温馨提示");
			}
		}
		if (AI)
		{
			ch = !ch;;
			chess = rule.AI(ch + 1);
			board.ChangeChess(chess.x, chess.y, ch + 1);
			rule.change(chess);
			chess_man->creat_chess(chess);
			if (rule.judge(chess))
			{
				win = true;
				if (ch)
				{
					MessageBox(L"黑棋胜", L"温馨提示");
				}
				else
				{
					MessageBox(L"白棋胜", L"温馨提示");
				}
			}
		}
		return 0;
	}
}

void Game::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	chess c1;
	c1=Chess_man.get_chess();
	int _x = c1.x, _y = c1.y, _m = 0;
	board.ChangeChess(_x, _y, _m);
	rule.change(c1);
	Chess_man.delete_chess();
} 

void Game::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Game::OnOK();
}


void Game::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//保存进度
	int x = 1;
	Chess_man.save(x);
}

void Game::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//重新开始
	if (MessageBox(_T("是否保存进度？"), _T("提醒："), MB_YESNO) == IDNO)
	{
		rule;
		board;
	}
}

void Game::OnBnClickedButton5()
{
	AI = !AI;
	if (AI)
	{
		chess chess;
		ch = !ch;;
		chess = rule.AI(ch + 1);
		board.ChangeChess(chess.x, chess.y, ch + 1);
		rule.change(chess);
		chess_man->creat_chess(chess);
		if (rule.judge(chess))
		{
			win = true;
			if (ch)
			{
				MessageBox(L"黑棋胜", L"温馨提示");
			}
			else
			{
				MessageBox(L"白棋胜", L"温馨提示");
			}
		}
	}
	// TODO: 在此添加控件通知处理程序代码
}

LRESULT Game::OnNcHitTest(CPoint point)
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

BOOL Game::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON7)->ShowWindow(SW_HIDE);
	if (azbycx == 1)
	{
		int i = 1;
		std::string strStr;
		strStr=str1.GetBuffer(0);
		Chess_man.initial(str1,i);
		do
		{
			chess c;
			c = Chess_man.get_chess();
			int x = c.x, y = c.y, z = c.z;
			board.ChangeChess2(x, y, z);
			rule.change(c);
		} while (Chess_man.jumpdown());
	}
	else if (azbycx == 2)
	{
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON7)->ShowWindow(SW_SHOW);
		int i = 2;
		Chess_man.initial(str1, 1);
		chess c;
		c = Chess_man.get_chess();
		int x = c.x, y = c.y, z = c.z;
		board.ChangeChess2(x, y, z);
		rule.change(c);
	}
	win = false;
	AI = false;
	ch = false;
	// TODO: 在此处添加消息处理程序代码
	reset_bk(IDB_BITMAP2);
	gbutton1.SetTextColor(RGB(255, 255, 255));
	gbutton1.SetBkColor(RGB(0, 0, 0));
	gbutton1.SetDiaphaneity(100, 180, 10);
	gbutton2.SetTextColor(RGB(255, 255, 255));
	gbutton2.SetBkColor(RGB(0, 0, 0));
	gbutton2.SetDiaphaneity(100, 180, 10);
	gbutton3.SetTextColor(RGB(255, 255, 255));
	gbutton3.SetBkColor(RGB(0, 0, 0));
	gbutton3.SetDiaphaneity(100, 180, 10);
	gbutton4.SetTextColor(RGB(255, 255, 255));
	gbutton4.SetBkColor(RGB(0, 0, 0));
	gbutton4.SetDiaphaneity(100, 180, 10);
	gbutton5.SetTextColor(RGB(255, 255, 255));
	gbutton5.SetBkColor(RGB(0, 0, 0));
	gbutton5.SetDiaphaneity(100, 180, 10);
	gbutton6.SetTextColor(RGB(255, 255, 255));
	gbutton6.SetBkColor(RGB(0, 0, 0));
	gbutton6.SetDiaphaneity(100, 180, 10);
	gbutton7.SetTextColor(RGB(255, 255, 255));
	gbutton7.SetBkColor(RGB(0, 0, 0));
	gbutton7.SetDiaphaneity(100, 180, 10);
	board.SetChessImage(L"png\\黑棋.png", 2);
	board.SetChessImage(L"png\\白棋.png", 1);
	board.SetBkImage(L"bmp\\木制棋盘.bmp");//这里输入实际地址
	return TRUE;  // return TRUE unless you set the focus to a control
			  // 异常: OCX 属性页应返回 FALSE
		
}
void Game::OnPaint()
{

	draw_bk(1);// 不为绘图消息调用 CDialogEx::OnPaint()
}


HBRUSH Game::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	int ID = pWnd->GetDlgCtrlID();
	if (ID == IDC_BOARD)
	{
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}




void Game::OnStnClickedBoard()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Game::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	Chess_man.jumpdown();
}


void Game::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	Chess_man.jumpup();
}
