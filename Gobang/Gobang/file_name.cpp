#include"pch.h"
#include"file_name.h"
name::name()
{
	length = 0;//�ó�ʼ��
	na = { 0 };//ע������Ҳ���ˣ��ѡ�0����Ϊ��{0}
	next = nullptr;
}
//ע��,����get_name��������name��ĳ�Ա��������Ϊname�����ݶ�Ϊ���У�������Ȼ���ǳ�Ա����������Ҳ���Է���������
name* name::get_name1()//ע�������     "get_name"��Ϊ��get_name1
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

name* name::get_name2()//ע�������     "get_name"��Ϊ��get_name1
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