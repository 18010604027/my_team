#include"pch.h"
#include"chess_man.h" 
chess_man::chess_man()						//������캯��Ӧ��Ҫ���ļ��Ŷ�
{
	head = new chess_node;
	last = new chess_node;
	head->next = last;
	head->prev = nullptr;
	last->next = nullptr;
	last->prev = head;
	//iofile = nullptr;						//���������ˣ�
	length = 0;
	file = { 0 };
	now = head->next;						//һ��ʼnowָ����ָ��head����һ���Ŀռ�
}
//������ƹ��캯����������Ȼ��߸��̵�ʱ���õģ�����Ҫ���ļ�
chess_man::chess_man(string file1, int i)			//Ϊʲô����Ҫ��һ��������
{
	if (i == 1)
	{
		head = new chess_node;
		last = new chess_node;
		head->next = last;
		head->prev = nullptr;
		last->next = nullptr;
		last->prev = head;
		file = file1;
		fstream iofile;
		iofile.open("date1\\" + file, ios::in);//ע������date�ļ��е�λ�ÿ��ܷŴ���

		iofile >> length;
		int i = 0;//�������ƴ��ļ������ȡ����
		for (i = 0; i < length; i++)//֮���Բ��� <= ����Ϊi�Ǵ�0��ʼ��
		{
			chess_node* temp1 = new chess_node;
			chess_node* temp2 = new chess_node;
			/*��ʵ����ֱ��дtemp2=last->prev;
			*/
			temp2 = head->next;				//������ܻ��д���Ϊû��дtemp2->prev=head;
			while (temp2 != last)
			{
				temp2 = temp2->next;
			}
			temp2 = temp2->prev;
			temp2->next = temp1;
			temp1->prev = temp2;
			temp1->next = last;
			last->prev = temp1;
			iofile >> temp1->chess1.x >> temp1->chess1.y >> temp1->chess1.z;//������ܻ��д���Ϊ��̫��"->"��
			//������ܻ����Ϊendl�������ļ��������ݵ�ʱ�����л��з��ģ�Ȼ���ڶ�ȡ���ݵ�ʱ��ȴû�У����ܻ��
		}
		now = head->next;//Ҫע�������ǹ��캯����Ҫ�����е����ݶ���ʼ��//nowһ��ʼ��ָ��head����һ��������һ���������ݵĿռ�
		iofile.close();
	}
	if (i == 2)
	{
		head = new chess_node;
		last = new chess_node;
		head->next = last;
		head->prev = nullptr;
		last->next = nullptr;
		last->prev = head;
		file = file1;
		fstream iofile;
		iofile.open("date2\\" + file, ios::in);//ע������date�ļ��е�λ�ÿ��ܷŴ���

		iofile >> length;
		int i = 0;//�������ƴ��ļ������ȡ����
		for (i = 0; i < length; i++)//֮���Բ��� <= ����Ϊi�Ǵ�0��ʼ��
		{
			chess_node* temp1 = new chess_node;
			chess_node* temp2 = new chess_node;
			/*��ʵ����ֱ��дtemp2=last->prev;
			*/
			temp2 = head->next;				//������ܻ��д���Ϊû��дtemp2->prev=head;
			while (temp2 != last)
			{
				temp2 = temp2->next;
			}
			temp2 = temp2->prev;
			temp2->next = temp1;
			temp1->prev = temp2;
			temp1->next = last;
			last->prev = temp1;
			iofile >> temp1->chess1.x >> temp1->chess1.y >> temp1->chess1.z;//������ܻ��д���Ϊ��̫��"->"��
			//������ܻ����Ϊendl�������ļ��������ݵ�ʱ�����л��з��ģ�Ȼ���ڶ�ȡ���ݵ�ʱ��ȴû�У����ܻ��
		}
		now = head->next;//Ҫע�������ǹ��캯����Ҫ�����е����ݶ���ʼ��//nowһ��ʼ��ָ��head����һ��������һ���������ݵĿռ�
		iofile.close();
	}
}
void chess_man::change_file(string file2)
{
	file = file2;							//������ܲ�������������Ҫ����

}
//ע�⣬���ﺯ��������creat_chess,creat����û��e��
void chess_man::creat_chess(chess chess2)
{
	chess_node* temp = last;			//�����temp�Ǹ�ʲô�õģ�//��֪��
	last->chess1 = chess2;
	last->next = new chess_node;
	chess_node* p; p = last;
	last = last->next;
	last->prev = p;
	last->next = nullptr;
	length++;
	now = last->prev;//��������nowָ�����ڶ����������һ���������ݵĿռ�
	//������ܻ������Ϊֻд��now=last->prev;
}
void chess_man::delete_chess()//����ɾ�����ǵ����ڶ������
{
	if (length == 0)
	{
		//cout << "����Ϊ��";
		return;
	}
	else {
		//����Ҳ����ֱ����last�����ô�ͷָ�뿪ʼ��
		chess_node* temp1, * temp2;
		temp1 = last->prev;
		temp2 = temp1->prev;
		temp2->next = last;
		last->prev = temp2;
		delete temp1;
		now = temp2;
		length--;
		return;
	}
}
void chess_man::save(int x)
{
	if (x == 1)
	{
		int i = 1;		//��������whileѭ����
		chess_node* temp; temp = head->next;
		string  filename;
		filename = file;
		//cin >> filename;
		fstream iofile;
		iofile.open("date1\\" + filename + ".ld", ios::out);
		iofile << length << endl;								//�����ǰ�ͷ�ռ��length���浽�ļ�����
		if (length > 0)
		{
			while (i <= length)
			{

				iofile << temp->chess1.x << endl << temp->chess1.y << endl << temp->chess1.z << endl;//ע��temp->chess1->x�Ǵ���ģ����Ի���ʾ"���ʽ�������ָ������"
				i++;
				temp = temp->next;
			}
		}
		iofile.close();
		fstream file_out("allname1.txt", ios::out | ios::app);//ע�⣬��������׷�����һ��Ҫ���ļ�β������ݣ�������ֱ��д���ݣ���Ϊֱ��д���ݻ��ԭ�ȵ����ݸ�ɾ��
		file_out << filename + ".ld" << endl;//������ܻᱨ��//ע��һ��Ҫ�л��з�
		file_out.close();
	}
	if (x == 2)
	{
		int i = 1;		//��������whileѭ����
		chess_node* temp; temp = head->next;
		string  filename;
		filename = file;
		//cin >> filename;
		fstream iofile;
		iofile.open("date2\\" + filename + ".rp", ios::out);
		iofile << length << endl;								//�����ǰ�ͷ�ռ��length���浽�ļ�����
		if (length > 0)
		{
			while (i <= length)
			{
				iofile << temp->chess1.x << endl << temp->chess1.y << endl << temp->chess1.z << endl;//ע��temp->chess1->x�Ǵ���ģ����Ի���ʾ"���ʽ�������ָ������"
				i++;
				temp = temp->next;
			}
		}
		iofile.close();
		iofile.close();
		fstream file_out("allname2.txt", ios::out | ios::app);
		file_out << filename + ".rp" << endl;//ע��һ��Ҫ�л��з�
		file_out.close();
	}
}
bool chess_man::jumpup()//���Ӧ���Ǹı�ָ��now��ֵ��ʹָ֮����һ��
{
	if (now->prev != head)
	{
		now = now->prev;
		return true;
	}
	else
	{
		return false;
	}
}
bool chess_man::jumpdown()
{
	if (now->next != last)
	{
		now = now->next;
	}
	else
	{
		return false;
	}
}
chess chess_man::get_chess()
{
	chess temp;
	temp.x = now->chess1.x;
	temp.y = now->chess1.y;
	temp.z = now->chess1.z;
	return temp;
}
chess_man::~chess_man()
{
	if (length == 0)
	{
		delete head;
		delete last;
		head = nullptr;
		last = nullptr;
		return;
	}
	else
	{
		while (head->next != nullptr)
		{
			chess_node* temp = head;
			head = head->next;
			delete temp;
		}
		delete head;
		head = nullptr;
	}
}