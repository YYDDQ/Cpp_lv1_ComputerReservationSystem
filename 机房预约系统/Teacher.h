#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"

class Teacher :public Identity
{
public:
	
	//默认构造
	Teacher();
	
	//有参构造
	Teacher(int empID, string name, string pwd);
	
	//菜单界面
	virtual void operMenu();
	
	//查看所有预约
	void showAllOrder();
	
	//审核预约
	void validOrder();

	//教师菜单
	void TeacherMenu(Identity*& teacher);
	
	//教师编号
	int m_EmID;
};