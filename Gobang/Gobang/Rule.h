#pragma once
#include"pch.h"
#include<ctime>
#include"chess_man.h"
using namespace std;
class Rule
{
private:
	const int me[10] = { 1,5,25,125,625,3125,15625,100000,1000000,10000000 };
	int two[15][15];
	int x, y;
	bool win;
public:
	Rule();
	void change(chess c);
	bool judge(chess);
	int get_chess(int x,int y);
	int getmax(const  int score[][15]);
	long long search(int dep, int c);
	long long getscore(const int board[][15], int c);
	bool four(const  int board[][15], int c, int x, int y);
	chess AI(int c);
};