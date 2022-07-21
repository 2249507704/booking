#include "orderFile.h"

OrderFile::OrderFile()
{
	//��ʼ���ļ�
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	//׼�����ļ��л�ȡ������
	string date;     //����
	string interval; //ʱ���
	string stuid;	 //ѧ��id
	string stuname;	 //ѧ������
	string roomid;	 //�������
	string status;	 //ԤԼ״̬

	//��ʼ��ԤԼ��¼������
	this->m_Size = 0;

	//��ȡԤԼ��Ϣ
	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status)
	{
		////�����Ƿ��ܶ���
		//cout << date << endl;				//��������date�� date:1  ��һ����ֵ�� ����Ҫ�������в��
		//cout << interval << endl;
		//cout << stuid << endl;
		//cout << stuname << endl;
		//cout << roomid << endl;
		//cout << status << endl;
		//cout << endl;

		//���ڳ��ֵĶ��Ǽ�ֵ��  ���ڣ�1  ������Ҫ�Ѽ�ֵ�Էָ�  �ҵ���
		string key;
		string value;
		//��key��value�ŵ�һ��С������
		map<string, string>m;

		//�ָ�����
		int pos = date.find(":"); //date��1   ���ص�λ��pos = 4  d a t e ��1
									//							 0 1 2 3 4	
		if (pos != -1) //˵���ҵ�����λ����
		{
			//�ý�ȡ��key��ȡ����  substr()  �����￪ʼ��ȡ ��ȡ����
			key = date.substr(0, pos);  //��0�Ž�ȡ��4��  d a t e ��0λ�ÿ�ʼ��ȡ 4��
			value = date.substr(pos + 1, date.size() - pos - 1);

			//�ѷָ�Ķ����ŵ�������  ��Ϊÿһ�����Ƕ��� ��Ҫ����һ������ make_pair(key,value)
			m.insert(make_pair(key, value));

		}

		//�ָ�ʱ���
		pos = interval.find(":"); //interval��1   ���ص�λ��pos = 8  
													
		if (pos != -1) //˵���ҵ�����λ����
		{
			//�ý�ȡ��key��ȡ����  substr()  �����￪ʼ��ȡ ��ȡ����
			key = interval.substr(0, pos); 
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			//�ѷָ�Ķ����ŵ�������  ��Ϊÿһ�����Ƕ��� ��Ҫ����һ������ make_pair(key,value)
			m.insert(make_pair(key, value));

		}

		//�ָ�ѧ��id
		pos = stuid.find(":"); 

		if (pos != -1) //˵���ҵ�����λ����
		{
			//�ý�ȡ��key��ȡ����  substr()  �����￪ʼ��ȡ ��ȡ����
			key = stuid.substr(0, pos);  
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);

			//�ѷָ�Ķ����ŵ�������  ��Ϊÿһ�����Ƕ��� ��Ҫ����һ������ make_pair(key,value)
			m.insert(make_pair(key, value));

		}
		

		//�ָ�ѧ������
		pos = stuname.find(":");

		if (pos != -1) //˵���ҵ�����λ����
		{
			//�ý�ȡ��key��ȡ����  substr()  �����￪ʼ��ȡ ��ȡ����
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);

			//�ѷָ�Ķ����ŵ�������  ��Ϊÿһ�����Ƕ��� ��Ҫ����һ������ make_pair(key,value)
			m.insert(make_pair(key, value));

		}


		//�ָ�������
		pos = roomid.find(":");

		if (pos != -1) //˵���ҵ�����λ����
		{
			//�ý�ȡ��key��ȡ����  substr()  �����￪ʼ��ȡ ��ȡ����
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);

			//�ѷָ�Ķ����ŵ�������  ��Ϊÿһ�����Ƕ��� ��Ҫ����һ������ make_pair(key,value)
			m.insert(make_pair(key, value));

		}

		//�ָ�ԤԼ״̬
		pos = status.find(":");

		if (pos != -1) //˵���ҵ�����λ����
		{
			//�ý�ȡ��key��ȡ����  substr()  �����￪ʼ��ȡ ��ȡ����
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			//�ѷָ�Ķ����ŵ�������  ��Ϊÿһ�����Ƕ��� ��Ҫ����һ������ make_pair(key,value)
			m.insert(make_pair(key, value));

		}
		////��֤
		//cout << "key =" << key << endl;
		//cout << "value=" << value << endl;

		//���м�¼��Сmap�����ŵ���map������   �ѵ�ǰ�ж�������¼ �� Сmap����������� ���뵽��map������
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++; //���¼�¼����
	}
	ifs.close();

}

void OrderFile::updateOrder()
{
	//���ж���û�м�¼  ���û�м�¼ ��return
	if (this->m_Size == 0)
	{
		return;
	}

	//��out|trunc����д
	ofstream ofs;

	//�������˶�ɾ�� ����д��
	ofs.open(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < m_Size; i++)
	{
		//�����Ƕ�׵�map���� i�ǵڼ���ԤԼ��Ϣ  ���߲���Ҫ�Ķ���
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuid:" << this->m_orderData[i]["stuid"] << " ";
		ofs << "stuname:" << this->m_orderData[i]["stuname"] << " ";
		ofs << "roomid:" << this->m_orderData[i]["roomid"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}

	ofs.close();
}
