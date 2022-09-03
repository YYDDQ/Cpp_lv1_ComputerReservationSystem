#include"Manager.h"
#include<fstream>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include<algorithm>


//默认构造
Manager::Manager()
{
}
//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_pwd = pwd;
	
	initVector();

}
//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;//操作的文件名称
	string tip;
	string errorTip;//错误提示
	ofstream ofs;
	int select;

	cin >> select;

	switch (select)
	{
	case 1:
		fileName = STUDENT_FILE;
		tip = "请输入学号" ;
		errorTip = "学号输入错误，请重新输入";
		break;
	case 2:
		fileName = TEACHER_FILE;
		tip = "请输入职工编号" ;
		errorTip = "教师职工号输入错误,请重新输入";
		break;
	}

	//利用追加的方式写文件
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

	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	ofs << id << " "
		<< name << " "
		<< pwd << endl;

	ofs.close();
	
	//初始化容器 避免因为新添加的成员未加入容器而出现无法判断是否重复的情况
	initVector();
	
	system("pause");
	system("cls");


}
//显示学生信息
void printStudent(Student &s)
{
	cout << s.m_id << " "
		<< s.m_Name << " "
		<< s.m_pwd << endl;
}
//显示教师信息
void printTeacher(Teacher &t)
{
	cout << t.m_EmID << " "
		<< t.m_Name << " "
		<< t.m_pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select;
	cin >> select;
	
	
	if (select == 1)
	{
		cout << "学生信息如下" << endl;
		for_each(vStu.begin(),vStu.end(),printStudent);
		
	}
	else
	{
		cout << "教师信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
		
	}
	system("pause");
	system("cls");
}
//查看机房信息
void Manager::showComputer()
{
	
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号： " << it->m_ComID << " 机房最大容量： " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);//ios::trunc 如果文件存在将文件长度设置为0
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}


//判断重复函数
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

//管理员菜单
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
		case 1://添加账号
			cout << "添加账号" << endl;
			mg->addPerson();
			break;
		case 2://查看账号
			cout << "查看账号" << endl;
			mg->showPerson();
			break;
		case 3://查看机房
			cout << "查看机房" << endl;
			mg->showComputer();
			break;
		case 4://清空预约
			cout << "清空预约" << endl;
			mg->cleanFile();
			break;
		default://注销
			delete manager;
			cout << "注销登录" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
void Manager:: initVector()
{
	ifstream ifs;

	//初始化学生
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		ifs.close();
		return;
	}
	vStu.clear();

	Student s;

	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生人数为" << vStu.size() << endl;
	ifs.close();


	//初始化老师
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		ifs.close();
		return;
	}
	vTea.clear();

	Teacher t;

	if (ifs >> t.m_EmID && ifs >> t.m_Name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师人数为" << vTea.size() << endl;
	ifs.close();

	//初始化机房
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		ifs.close();
		return;
	}
	vCom.clear();
	ComputerRoom c;
	while (ifs >> c.m_ComID && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为： " << vCom.size() << endl;
	ifs.close();
}