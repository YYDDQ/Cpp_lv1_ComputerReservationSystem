#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"

class Teacher :public Identity
{
public:
	
	//Ĭ�Ϲ���
	Teacher();
	
	//�вι���
	Teacher(int empID, string name, string pwd);
	
	//�˵�����
	virtual void operMenu();
	
	//�鿴����ԤԼ
	void showAllOrder();
	
	//���ԤԼ
	void validOrder();

	//��ʦ�˵�
	void TeacherMenu(Identity*& teacher);
	
	//��ʦ���
	int m_EmID;
};