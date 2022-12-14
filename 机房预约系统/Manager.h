#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"computerRoom.h"
#include<algorithm>


class Manager :public Identity
{
public:
	
	//默认构造
	Manager();
	
	//有参构造
	Manager(string name,string pwd);
	
	//选择菜单
	virtual void operMenu();
	
	//添加账号
	void addPerson();

	//查看账号
	void showPerson();
	
	//查看机房信息
	void showComputer();
	
	//清空预约记录
	void cleanFile();

	//判断重复函数
	bool checkRepeat(int id, int type);

	//管理员菜单
	void managerMenu(Identity*& manager);
	
	

	//初始化容器
	void initVector();

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vCom;
};