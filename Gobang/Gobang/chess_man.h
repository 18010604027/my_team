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
class chess_man
{
private:
	chess_node* head, * now, * last;
	string file;
	int length;
public:
	chess_man();							//���캯����ʼ����Ϸ��ʱ���õ�
	chess_man(string file1, int i);					//�������ع��캯����������Ȼ��߸��̵�ʱ���õ�
	void change_file(string file2);			//���ʵ���ǲ�֪��������ʲô�õ�
//ע�⣬���ﺯ��������creat_chess,creat����û��e��
	void creat_chess(chess chess2);		   //�������½�һ����㣬��һ�����õ�
	void delete_chess();					//����ɾ��һ����㣬�����ʱ���õ�
	void save(int x);//��1��������, 2�����̣���;//���Ǳ�����ȣ�ע��Ϊ�˶�����Ϊ�˸����������ֲ�ͬ�ı��棬Ҫ�ò�ͬ���ļ���׺
	void jumpup();							//����������һ��
	void jumpdown();						//����������һ�������̵�ʱ���õ�
	chess get_chess();						//���ǵõ���ǰ��һ�����Ǹ����ӵ�ָ��
	~chess_man();
};

