#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class name
{
public:
	name();
	name* get_name1();//��ȡ�����ļ����ļ���
	name* get_name2();//��ȡ�����ļ����ļ���
	string na;
	int length;//ע�⣬���length��û��д���ļ���ģ��Ǹ�������������м����ļ�������������
	name* next;
};
