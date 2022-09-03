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
	
	//Ĭ�Ϲ���
	Manager();
	
	//�вι���
	Manager(string name,string pwd);
	
	//ѡ��˵�
	virtual void operMenu();
	
	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();
	
	//�鿴������Ϣ
	void showComputer();
	
	//���ԤԼ��¼
	void cleanFile();

	//�ж��ظ�����
	bool checkRepeat(int id, int type);

	//����Ա�˵�
	void managerMenu(Identity*& manager);
	
	

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;
};