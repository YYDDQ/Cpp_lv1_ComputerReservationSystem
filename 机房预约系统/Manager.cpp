#include"Manager.h"
#include<fstream>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include<algorithm>


//Ĭ�Ϲ���
Manager::Manager()
{
}
//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_pwd = pwd;
	
	initVector();

}
//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;//�������ļ�����
	string tip;
	string errorTip;//������ʾ
	ofstream ofs;
	int select;

	cin >> select;

	switch (select)
	{
	case 1:
		fileName = STUDENT_FILE;
		tip = "������ѧ��" ;
		errorTip = "ѧ�������������������";
		break;
	case 2:
		fileName = TEACHER_FILE;
		tip = "������ְ�����" ;
		errorTip = "��ʦְ�����������,����������";
		break;
	}

	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;
	
	cout << tip << endl;
	
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id,select);
		if (ret)
			cout << errorTip << endl;
		else
			break;
	}

	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	ofs << id << " "
		<< name << " "
		<< pwd << endl;

	ofs.close();
	
	//��ʼ������ ������Ϊ����ӵĳ�Աδ���������������޷��ж��Ƿ��ظ������
	initVector();
	
	system("pause");
	system("cls");


}
//��ʾѧ����Ϣ
void printStudent(Student &s)
{
	cout << s.m_id << " "
		<< s.m_Name << " "
		<< s.m_pwd << endl;
}
//��ʾ��ʦ��Ϣ
void printTeacher(Teacher &t)
{
	cout << t.m_EmID << " "
		<< t.m_Name << " "
		<< t.m_pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select;
	cin >> select;
	
	
	if (select == 1)
	{
		cout << "ѧ����Ϣ����" << endl;
		for_each(vStu.begin(),vStu.end(),printStudent);
		
	}
	else
	{
		cout << "��ʦ��Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
		
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::showComputer()
{
	
	cout << "������Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ� " << it->m_ComID << " ������������� " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);//ios::trunc ����ļ����ڽ��ļ���������Ϊ0
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}


//�ж��ظ�����
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); ++it)	
		{
			if (id == it->m_id)
				return true;
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); ++it)
		{
			if (id == it->m_EmID)
				return true;
		}
	}
	return false;
}

//����Ա�˵�
void Manager::managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();

		Manager* mg = (Manager*)manager;

		int select = 0;

		cin >> select;

		switch (select)
		{
		case 1://����˺�
			cout << "����˺�" << endl;
			mg->addPerson();
			break;
		case 2://�鿴�˺�
			cout << "�鿴�˺�" << endl;
			mg->showPerson();
			break;
		case 3://�鿴����
			cout << "�鿴����" << endl;
			mg->showComputer();
			break;
		case 4://���ԤԼ
			cout << "���ԤԼ" << endl;
			mg->cleanFile();
			break;
		default://ע��
			delete manager;
			cout << "ע����¼" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
void Manager:: initVector()
{
	ifstream ifs;

	//��ʼ��ѧ��
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		ifs.close();
		return;
	}
	vStu.clear();

	Student s;

	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ" << vStu.size() << endl;
	ifs.close();


	//��ʼ����ʦ
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		ifs.close();
		return;
	}
	vTea.clear();

	Teacher t;

	if (ifs >> t.m_EmID && ifs >> t.m_Name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ" << vTea.size() << endl;
	ifs.close();

	//��ʼ������
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		ifs.close();
		return;
	}
	vCom.clear();
	ComputerRoom c;
	while (ifs >> c.m_ComID && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ�� " << vCom.size() << endl;
	ifs.close();
}