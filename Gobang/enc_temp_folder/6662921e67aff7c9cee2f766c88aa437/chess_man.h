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
	unsigned int x; unsigned int y; unsigned int z;//(0Ϊ�գ�1Ϊ�ף�2Ϊ��)
}chess;
typedef class chess_node
{
public:
	chess_node* prev;//ָ����һ������ָ��
	chess_node* next;//ָ����һ������ָ��
	chess chess1;
}chess_node;


