#include"orderFile.h"

void OrderFile::cutString(string date,map <string,string> &m)
{
	string key;
	string value;


	int pos = date.find(":");
	if (pos = date.find(":"))
	{
		key = date.substr(0, pos);
		value = date.substr(pos + 1, date.size() - pos - 1);
		m.insert(make_pair(key, value));
	}

}

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //机房编号
	string status;    //预约状态


	this->m_Size = 0; //预约记录个数

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
	
		map<string, string > m;
		this->cutString(date,m);
		this->cutString(interval, m);
		this->cutString(stuId, m);
		this->cutString(stuName, m);
		this->cutString(roomId, m);
		this->cutString(status, m);

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}
	ifs.close();
}
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}