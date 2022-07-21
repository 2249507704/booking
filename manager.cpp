#include "manager.h"
#include<fstream>
#include"globalFile.h"
#include<algorithm>
Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	//��ʼ����Ϣ
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ������  ��������ó�ʼ�������ĺ��� ������ʾ��ѧ������ʦ�ļ��е���Ϣ
	this->initVector();

	this->initComputerRoom();
}

void Manager::operMenu()
{
	cout << "================ ��ӭ����Ա"<<this->m_name<<"��¼��================== = " << endl;
	cout << "\t\t -------------------- \n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    1������˺�     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    2���鿴�˺�     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    3���鿴����     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    4�����ԤԼ     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    0��ע����¼     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t -------------------- \n";
	cout << "����������ѡ��" << endl;
}

void Manager::addPerson()
{
	cout << "��������Ҫ����û������ͣ�" << endl;
	cout << "1---���ѧ��" << endl;
	cout << "2---�����ʦ" << endl;
	
	string filename; //������Ӧ���ļ�
	string tip;
	ofstream ofs; //���ļ�����д��Ķ��� �ļ����������

	int select = 0;
	cin >> select;

	//�ظ�������ʾ
	string errorTop;

	if (select == 1)  //ѡ��1  �����¶���
	{
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTop = "ѧ���ظ������������룡";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "������ְ���ţ�";
		errorTop = "ְ�����ظ������������룡";
	}

	//д�ļ�
	ofs.open(filename, ios::out | ios::app);  //д ����Ҫ ׷����д
	//д�����Ϣ
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	
	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTop << endl;
		}
		else
			break;
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//��ofs��������Ӧ��filename���д����
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;


	system("pause");
	system("cls");
	
	//�ر�ofs����
	ofs.close();

	/*************************************************************
	* bug����ͬһʱ����Ӷ���˵�����»����ѧ�Ż���ְ����
	* �ظ������
	*
	* ��������� ��ÿ����ӹ��󶼳�ʼ������һ�� ���»�ȡ����
	**************************************************************/
	this->initVector();
	return;
}

void PrintStudent(Student& s)
{
	cout << "ѧ��ѧ��Ϊ��" << s.m_id << " " << "ѧ������Ϊ��" << s.m_name << " " << "ѧ������Ϊ��" << s.m_pwd << endl;
}
 

void PrintTeacher(Teacher& t)
{
	cout << "��ʦְ����Ϊ��" << t.m_empid << " " << "��ʦ����Ϊ��" << t.m_name << " " << "��ʦ����Ϊ��" << t.m_pwd << endl;
}

void Manager::showPerson()
{
	//����ʾ�鿴ʲô
	cout << "��ѡ��Ҫ�鿴�����ݣ�" << endl;
	cout << "1���鿴���е�ѧ��" << endl;
	cout << "2���鿴���е���ʦ" << endl;

	//����һ��ѡ��
	int select = 0;
	//��ʼ����
	cin >> select;
	
	if (select == 1)
	{
		//�鿴ѧ��
		cout << "���е�ѧ����ϢΪ��" << endl;
		//STL�еı����㷨 for_each  �� vector<...>::it...һ��
		//��STL�㷨Ҫ����ͷ�ļ�algorithm
		for_each(vStu.begin(), vStu.end(),PrintStudent); //�����������Ŀ�ͷ�ͽ�β ��һ������
	}
	else
	{
		//�鿴��ʦ
		cout << "���е���ʦ��ϢΪ��" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	//���������ڵ����� �������
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_Comid << " " << "�����������" << it->m_MixNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearFile()
{
	//��ofstream�ļ�����������������ļ� ��trunc--->����ļ����� ɾ�ɾ� �ٴ���
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//�����id�ŵ�ʱ����Ҫ�õ��������
bool Manager::checkRepeat(int id, int type)
{
	//��������ѧ�����Ƿ����ظ�
	if (type == 1)
	{
		//�����������Ԫ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}
//��ʼ������
void Manager::initVector()
{
	//���ȿ϶���Ҫ��ȡ��ѧ���ļ� ����ȡѧ���ļ������Ϣ  ���ļ�
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	//�����������������
	vStu.clear();
	vTea.clear();

	//��ȡѧ����Ϣ  ������Ѿ��е�  ���Բ���Ҫnewһ��������
	Student s;
	//һ��һ�е�����ȡ
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		//�Ѷ�ȡ������Ϣ�ŵ�vector������
		vStu.push_back(s);
	}

	//���������еĺ������һЩ��ȡ������Ϣ
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	//�ر��ļ���ȡ
	ifs.close();

	//��ʼ��ȡ��ʦ�ļ�����Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_empid && ifs >>t.m_name && ifs >> t.m_pwd)
	{
		//�Ѷ�ȡ������Ϣ�ŵ�������
		vTea.push_back(t);
	}

	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;

	ifs.close();
}

void Manager::initComputerRoom()
{
	//����Ҫ��ȡ�ļ�  ���ļ���ifs  ���ļ�ofs д�ļ�
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	//��ճ�ʼ����
	vCom.clear();

	ComputerRoom c;
	//��������е�����
	while (ifs >> c.m_Comid && ifs >> c.m_MixNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;

	//�ر��ļ�
	ifs.close();
}

