#include "teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int empid, string name, string pwd)
{
	//��ʼ����ʦ����
	this->m_empid = empid;
	this->m_name = name;
	this->m_pwd = pwd;
}

void Teacher::operMenu()
{
	cout << "================ ��ӭ��ʦ��" << this->m_name << " " << "��¼��================== = " << endl;
	cout << "\t\t -------------------- \n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    1���鿴����ԤԼ |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    2�����ԤԼ     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    0��ע����¼     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t -------------------- \n";
	cout << "����������ѡ��" << endl;
	
}

void Teacher::showAllOrder()
{
	OrderFile of; //����һ����
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
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
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	OrderFile of; //����һ����
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��Ϣ���£�" << endl;

	int index = 1;
	//����һ������ ��������Ҫ���±�
	vector<int>v;

	for (int i = 0; i < of.m_Size; i++)
	{
		//���״̬Ϊ����е���Ϣ
		if (of.m_orderData[i]["status"] == "1")  //�ҵ�����Ҫ��˵���Ϣ��
		{
			//��������  Ҳ���ǵڼ�����Ϣ����������  ���¶����±�Ϊ1
			v.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼ����:��" << of.m_orderData[i]["date"] << " ";
			cout << "ԤԼʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ѧ��:" << of.m_orderData[i]["stuid"] << " ";
			cout << "����:" << of.m_orderData[i]["stuname"] << " ";
			cout << "�������:" << of.m_orderData[i]["roomid"] << " ";

			//ֻ�Ҵ�������е���Ϣ  ��ΪҪ���ԤԼ
			string status = "״̬:"; //1-->�����  2-->�ɹ� -1-->ʧ��  0-->ȡ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}
	cout << "��������Ҫ��˵�ԤԼ��Ϣ,����0�򷵻أ�" << endl;
	int select = 0; //ѡ����˵���Ϣ�ڼ���
	int ret = 0; //�Ƿ�ͬ��ͨ����˵�ѡ��
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "������������˽����" << endl;
				cout << "1-->ͬ��" << endl;
				cout << "2-->�ܾ�" << endl;
				cin >> ret;

				//�м������Ǹ���״̬ �����ж��Ƿ����
				if (ret == 1)
				{
					//��Щ���޸��ϱ���ʾ��״̬ �Ӷ��ﵽЧ��
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				//�����ļ�
				of.updateOrder();
				cout << "������" << endl;
				//����ѭ��
				break;
			}

		}
		cout << "����������������룡" << endl;
	}
	system("pause");
	system("cls");
}
