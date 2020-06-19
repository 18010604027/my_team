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


