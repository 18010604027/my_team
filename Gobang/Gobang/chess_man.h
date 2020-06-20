#pragma once
#include<iostream>
#include<fstream>
using namespace std;
typedef struct point
{
	unsigned int x;
	unsigned int y;
}point;
typedef struct chess
{
	unsigned int x; unsigned int y; unsigned int z;//(0为空，1为白，2为黑)
}chess;
typedef class chess_node
{
public:
	chess_node* prev;//指向上一个结点的指针
	chess_node* next;//指向下一个结点的指针
	chess chess1;
}chess_node;
class chess_man
{
private:
	chess_node* head, * now, * last;
	string file;
	int length;
public:
	chess_man();							//构造函数开始新游戏的时候用的
	chess_man(string file1, int i);					//这是重载构造函数，载入进度或者复盘的时候用的
	void change_file(string file2);			//这个实在是不知道用来干什么用的
//注意，这里函数名字是creat_chess,creat后面没有e。
	void creat_chess(chess chess2);		   //这里是新建一个结点，下一步棋用的
	void delete_chess();					//这是删除一个结点，悔棋的时候用的
	void save(int x);//（1（读档）, 2（复盘））;//这是保存进度，注意为了读档和为了复盘这是两种不同的保存，要用不同的文件后缀
	void jumpup();							//这是跳到上一步
	void jumpdown();						//这是跳到下一步，复盘的时候用的
	chess get_chess();						//这是得到当前那一步的那个棋子的指针
	~chess_man();
};

