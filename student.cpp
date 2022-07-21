#include "student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	//��ʼ������  id  ���� ����
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//�ڹ��캯���г�ʼ������
	this->initComputerRoom();

}

void Student::operMenu()
{ 
	//�ڹ��캯����֪�����Լ���ʲô
	cout << "================ ��ӭѧ������" << this->m_name << " " << "��¼��================== = " << endl;
	cout << "\t\t -------------------- \n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    1������ԤԼ     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    2���鿴�ҵ�ԤԼ |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    3���鿴����ԤԼ |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    4��ȡ��ԤԼ     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    0��ע����¼     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t -------------------- \n";
	cout << "����������ѡ��" << endl;
}

void Student::applyOrder()
{

	//����ԤԼ  ���������� Ȼ��ʱ��� Ȼ���Ǹ�����
	//����
	cout << "����������ʱ������һ�����壡" << endl;
	cout << "�����������ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	//Ҫ���յĶ���
	int date = 0;   //��������
	int interval;   //ʱ��� ���� ���� ����
	int room = 0;   //�������

	//��������ж� ���������1��5
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			//������������  break
			break;
		}
		cout << "�����������������룡" << endl;
	}

	//ʱ���  ������� ����
	cout << "��������ҪԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}

	//����
	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_Comid << "�Ż���������Ϊ��" << vCom[i].m_MixNum << endl;
	}

	while (true)
	{
		cin >> room;

		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "ԤԼ�ɹ��������..." << endl;

	//�������Ϣд�뵽�ļ���
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app); //��׷�ӵķ�ʽ��
	//Ҫд�������
	ofs << "date:" << date << "  ";
	ofs << "interval:" << interval << "  ";
	ofs << "roomid:" << room << "  ";
	ofs << "stuid:" << this->m_id << "  ";
	ofs << "stuname:" << this->m_name << "  ";
	ofs << "status:" << 1 << endl;


	//�ر��ļ�
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMeOrder()
{
	//����һ��OrderFile��
	OrderFile of; //�����������Ϳ��Ե������Ĺ��캯�� �Ϳ��Բ��Դ�����  ����������е�ԤԼ��¼

	//���û��ԤԼ��¼ �򷵻�
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//atoi ���԰� char��ת��Ϊint  ��Ϊm_id������ 
		//�������ĺͱ�������һ�� ���ӡ���
		if (atoi(of.m_orderData[i]["stuid"].c_str()) == this->m_id)
		{
			cout << "ԤԼ����:��" << of.m_orderData[i]["date"] << " ";
			cout << "ԤԼʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "����:" << of.m_orderData[i]["roomid"] << " ";
			string status = "״̬:";//0 ȡ��ԤԼ  1�����  2��ԤԼ  -1ԤԼʧ��

			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ȡ��ԤԼ";
			}
			//���ԤԼ״̬
			cout << status << endl;

		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ����:��" << of.m_orderData[i]["date"] << " ";
		cout << "ԤԼʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ��:" << of.m_orderData[i]["stuid"] << " ";
		cout << "����:" << of.m_orderData[i]["stuname"] << " ";
		cout << "�������:" << of.m_orderData[i]["roomid"] << " ";

		//ƴ��״̬
		string status = "״̬:"; //0ȡ��ԤԼ  1 �����  2ԤԼ�ɹ� -1ԤԼʧ��

		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if(of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ȡ��ԤԼ";
		}

		//���ԤԼ״̬
		cout << status << endl;
	}
	system("pause");
	system("cls");

}

void Student::cancelOrder()
{
	//�Ȳ鿴�Ƿ���ԤԼ��¼
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "û��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����е�ԤԼ���Ѿ�ԤԼ�ɹ���ԤԼ����ȡ����" << endl;
	vector<int>v;  //׼��һ������ȥ��ű��  �������������е��±���
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//�ж�ѧ������ǲ��������  ��Ϊֻ���Լ�����ȡ���Լ���ԤԼ��¼
		if (atoi(of.m_orderData[i]["stuid"].c_str()) == this->m_id)
		{
			//��Ϊֻ����ȡ�������  1   ��  ��  ��˳ɹ��� 2  �ļ�¼  ɸѡ״̬
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				//��Ϊ���i������Ҫ�޸ĵ���Ϣ ����ɸѡ�ü����ų���һ�� ���ɸѡ������i�ŵ�����v��
				v.push_back(i);
				//������  Ҫȡ������ԤԼ��Ϣ  ��index ��1��ʼ  i������������ �������������� ��������������ԤԼ�� ��index�����ҵ�����ԤԼ��¼���±�
				cout << index++ << "��"; //�����Լ�������±�
				cout << "ԤԼ����:��" << of.m_orderData[i]["date"] << " ";
				cout << "ԤԼʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "ѧ��:" << of.m_orderData[i]["stuid"] << " ";
				cout << "����:" << of.m_orderData[i]["stuname"] << " ";
				cout << "�������:" << of.m_orderData[i]["roomid"] << " ";

				//ƴ��״̬ ��Ϊֻ�����޸�������״̬��ԤԼ��Ϣ ����ֻɸѡ��������
				string status = "״̬:"; //0ȡ��ԤԼ  1 �����  2ԤԼ�ɹ� 

				//ֻ�Ҵ�������� �� ԤԼ�ɹ�����Ϣ  ��ΪҪȡ��ԤԼ
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				//���ԤԼ״̬
				cout << status << endl;
			}

			
		}
	}
	cout << "��������Ҫȡ������ԤԼ��¼,0��ʾ���أ�" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())  //����ȡ��������Ҫ���ڵ���0�� С��vector��������������
		{
			//����û�ѡ��0  �ͷ��� break��ȥ
			if (select == 0)
			{
				break;
			}
			else
			{
				//��Щ���޸��ϱ���ʾ��״̬ �Ӷ��ﵽЧ��
				of.m_orderData[v[select - 1]]["status"] = "0";//ȡ��ԤԼ  ���ǰ��ļ��е�״̬��Ϊ0

				//��ʼ���ļ�
				of.updateOrder();

				cout << "�Ѿ�ȡ����ԤԼ" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}

void Student::initComputerRoom()
{
	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	//�������
	vCom.clear();

	ComputerRoom c;

	while (ifs >> c.m_Comid && ifs >> c.m_MixNum)
	{
		//�Ѷ�ȡ�������ݷ���������
		vCom.push_back(c);
	}

	cout << "��ǰ�Ļ�����Ϊ��" << vCom.size() << endl;

	//�ر��ļ�
	ifs.close();

}
