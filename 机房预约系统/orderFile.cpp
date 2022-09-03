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

	string date;      //����
	string interval;  //ʱ���
	string stuId;     //ѧ�����
	string stuName;   //ѧ������
	string roomId;    //�������
	string status;    //ԤԼ״̬


	this->m_Size = 0; //ԤԼ��¼����

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