#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include"computerRoom.h"
#include<vector>
#include<fstream>
#include"globalFile.h"

class Student:public Identity
{
public:

	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);
	
	//菜单界面
	virtual void operMenu();//重写父类纯虚函数
	
	//申请预约
	void applyOrder();
	
	//查看我的预约
	void showMyOrder();
	
	//查看所有预约
	void showAllOrder();
	
	//取消预约
	void cancelOrder();

	//学生菜单
	void studentMenu(Identity*& manager);
	
	//学生学号
	int m_id;

	//机房容器
	vector<ComputerRoom> vCom;
};