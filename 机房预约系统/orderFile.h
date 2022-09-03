#pragma once
#include<iostream>
using namespace std;
#include <map>
#include"globalFile.h"
#include<fstream>

class OrderFile
{
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();
	
	//记录的容器 key--记录条数 value--具体记录的键值对应的信息
	map<int, map<string, string>>m_orderData;
	
	//分割字符串
	void cutString(string date, map <string, string>& m);

	//预约记录条数
	int m_Size;
};