#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"globalFile.h"
#include<string>
#include"Student.h"
#include"Manager.h"
#include"Teacher.h"


void loginIn(string fileName, int type)
{
	Identity * person = NULL;

	//��ȡ�ļ�
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//�ж��ļ��Ƿ����
	if(!ifs.is_open())//�ļ�������
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id;
	string name;
	string pwd;

	
		if (type == 1)
		{
			cout << "������ѧ��" << endl;
			while (!(cin >> id))//����ֻ����������
			{
				cin.clear(); //�����е�����״̬������Ϊ��Чֵ
				cin.sync();//�����
				while (cin.get() != '\n')
					continue;           //���Ѵ��������	
				cout << "����Ĳ������� ����������:" << endl;;
			}
			
		}
		else if (type == 2)
		{
			cout << "�������ʦ���" << endl;
			while (!(cin >> id))//����ֻ����������
			{
				cin.clear(); //�����е�����״̬������Ϊ��Чֵ
				cin.sync();//�����
				while (cin.get() != '\n')
					continue;           //���Ѵ��������	
				cout << "����Ĳ������� ����������:" << endl;;
			}
			
		}
		
	

	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)//ѧ����¼��֤
	{
		int fID;//���ļ��ж�ȡ��ID
		string fName;//���ļ��ж�ȡ��Name
		string fPwd;//���ļ��ж�ȡ��Pwd

		//���޸�ģ�� ���Ծ���
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{

			if (fID == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����¼��֤�ɹ�" << endl;
				
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				Student s;
				s.studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)//��ʦ�����֤
	{
		int fID;//���ļ��ж�ȡ��ID
		string fName;//���ļ��ж�ȡ��Name
		string fPwd;//���ļ��ж�ȡ��Pwd


		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{

			if (fID == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				Teacher t;
				t.TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)//����Ա�����֤
	{
		int fID;//���ļ��ж�ȡ��ID
		string fName;//���ļ��ж�ȡ��Name
		string fPwd;//���ļ��ж�ȡ��Pwd


		while (ifs >> fName && ifs >> fPwd)
		{

			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				Manager m;
				m.managerMenu(person);
				return;
			}
		}
	}
	cout << "��¼��֤ʧ��" << endl;
	
	system("pause");
	system("cls");
}



int main() {

	int select = -1;

	while (true) 
	{
		cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

	
		while (!(cin >> select))//����ֻ����������
		{
			cin.clear(); //�����е�����״̬������Ϊ��Чֵ
			cin.sync();//�����
			while (cin.get() != '\n')
				continue;           //���Ѵ��������
			cout << "����Ĳ������� ����������:" << endl;;
		}

		
		switch(select)
		{
		case 1://ѧ��
			loginIn(STUDENT_FILE,1);
			break;
		case 2://��ʦ
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			loginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		

	}
	system("pause");
	return 0;
}