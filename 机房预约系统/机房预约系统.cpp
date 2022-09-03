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

	//读取文件
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//判断文件是否存在
	if(!ifs.is_open())//文件不存在
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id;
	string name;
	string pwd;

	
		if (type == 1)
		{
			cout << "请输入学号" << endl;
			while (!(cin >> id))//限制只能输入数字
			{
				cin.clear(); //将流中的所有状态都重设为有效值
				cin.sync();//清空流
				while (cin.get() != '\n')
					continue;           //摆脱错误的输入	
				cout << "输入的不是数字 请重新输入:" << endl;;
			}
			
		}
		else if (type == 2)
		{
			cout << "请输入教师编号" << endl;
			while (!(cin >> id))//限制只能输入数字
			{
				cin.clear(); //将流中的所有状态都重设为有效值
				cin.sync();//清空流
				while (cin.get() != '\n')
					continue;           //摆脱错误的输入	
				cout << "输入的不是数字 请重新输入:" << endl;;
			}
			
		}
		
	

	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)//学生登录验证
	{
		int fID;//从文件中读取的ID
		string fName;//从文件中读取的Name
		string fPwd;//从文件中读取的Pwd

		//待修改模块 尝试精简
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{

			if (fID == id && fName == name && fPwd == pwd)
			{
				cout << "学生登录验证成功" << endl;
				
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				Student s;
				s.studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)//教师身份验证
	{
		int fID;//从文件中读取的ID
		string fName;//从文件中读取的Name
		string fPwd;//从文件中读取的Pwd


		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{

			if (fID == id && fName == name && fPwd == pwd)
			{
				cout << "教师登录验证成功" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				Teacher t;
				t.TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)//管理员身份验证
	{
		int fID;//从文件中读取的ID
		string fName;//从文件中读取的Name
		string fPwd;//从文件中读取的Pwd


		while (ifs >> fName && ifs >> fPwd)
		{

			if (fName == name && fPwd == pwd)
			{
				cout << "管理员登录验证成功" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				Manager m;
				m.managerMenu(person);
				return;
			}
		}
	}
	cout << "登录验证失败" << endl;
	
	system("pause");
	system("cls");
}



int main() {

	int select = -1;

	while (true) 
	{
		cout << "======================  欢迎来到机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

	
		while (!(cin >> select))//限制只能输入数字
		{
			cin.clear(); //将流中的所有状态都重设为有效值
			cin.sync();//清空流
			while (cin.get() != '\n')
				continue;           //摆脱错误的输入
			cout << "输入的不是数字 请重新输入:" << endl;;
		}

		
		switch(select)
		{
		case 1://学生
			loginIn(STUDENT_FILE,1);
			break;
		case 2://老师
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			loginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
		

	}
	system("pause");
	return 0;
}