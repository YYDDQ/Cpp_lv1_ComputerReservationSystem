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

	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);
	
	//�˵�����
	virtual void operMenu();//��д���ി�麯��
	
	//����ԤԼ
	void applyOrder();
	
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	
	//�鿴����ԤԼ
	void showAllOrder();
	
	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ���˵�
	void studentMenu(Identity*& manager);
	
	//ѧ��ѧ��
	int m_id;

	//��������
	vector<ComputerRoom> vCom;
};