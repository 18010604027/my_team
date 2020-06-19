#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class name
{
public:
	name();
	name* get_name1();//获取读档文件的文件名
	name* get_name2();//获取复盘文件的文件名
	string na;
	int length;//注意，这个length是没有写在文件里的，是根据这个链表里有几个文件名字数出来的
	name* next;
};
