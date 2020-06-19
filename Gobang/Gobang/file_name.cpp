#include"pch.h"
#include"file_name.h"
name::name()
{
	length = 0;//得初始化
	na = { 0 };//注意这里也改了，把“0”改为了{0}
	next = nullptr;
}
//注意,这里get_name函数不是name类的成员函数。因为name的数据都为公有，所以虽然不是成员函数，但是也可以访问其数据
name* name::get_name1()//注意这里把     "get_name"改为了get_name1
{
	int i = 0;
	fstream f;
	f.open("allname1.txt", ios::in);
	name* head = nullptr; name* p1 = nullptr; name* p2 = nullptr;
	head = new name;
	head->next = nullptr;
	p1 = nullptr;
	p2 = head;
	while (1)
	{
		string temp2;
		f >> temp2;
		if (f.eof())
		{
			break;
		}
		else
		{
			length++;
			i++;
			p1 = new name;
			p1->next = nullptr;
			p1->na = temp2;
			p2->next = p1;
			p2 = p1;
		}
	}
	f.close();
	return head;
}

name* name::get_name2()//注意这里把     "get_name"改为了get_name1
{
	int i = 0;
	fstream f;
	f.open("allname2.txt", ios::in);
	name* head = nullptr; name* p1 = nullptr; name* p2 = nullptr;
	head = new name;
	head->next = nullptr;
	p1 = nullptr;
	p2 = head;
	while (1)
	{
		string temp2;
		f >> temp2;
		if (f.eof())
		{
			break;
		}
		else
		{
			length++;
			i++;
			p1 = new name;
			p1->next = nullptr;
			p1->na = temp2;
			p2->next = p1;
			p2 = p1;
		}
	}
	f.close();
	return head;
}