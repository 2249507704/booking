#include<iostream>
#include"Identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include<string>
#include"manager.h"
#include"teacher.h"
using namespace std;

/*
* �ܹ���
*	���ࣺIdentity.h
*	�����ࣺ manager.h  student.h  teacher.h ��cpp��ʵ��
*	��¼ģ��: globalFile.h
*	���: ԤԼϵͳ
*/

//�������Ա�Ӳ˵�  �ø���ָ�봫��һ������Ա  ����Ա�Ӳ˵�����ʵ��
void managerMenu(Identity *&manager)
{
	while (true)  //��Ϊ�˵�Ҫһֱ���� ����while
	{
		//���ù���Ա�Ӳ˵�   ��̬ ����ָ������������  �����Ĳ���
		manager->operMenu();

		//������ָ��תΪ����ָ�� �Ϳ��Ե��������е����нӿ���
		Manager* man = (Manager*)manager;  //�Ѹ���ָ��ǿ��ת��ΪManagerָ��

		int select = 0;

		//�����û�ѡ��
		cin >> select;

		if (select == 1)  //����˺�
		{
			man->addPerson();
		}
		else if (select == 2)  // �鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			man->clearFile();
		}
		else
		{
			//ע���˺� ֱ�Ӱ������new�������پ���
			delete manager; //���ٶ�������
			system("pause");
			system("cls");
			return;
		}

	}
}

//����ѧ���Ӳ˵�    �ø���ָ�봫��һ��ѧ��     ѧ���Ӳ˵�����ʵ��
void studentMenu(Identity*& student)
{
	while (true)
	{
		//�ö�̬ �����Ӳ˵�
		student->operMenu(); //��������ڸ��෶Χ �ڸ����Ա�ڵ�����  Ȼ���ָ��ת��ȥ ���������ӿ�

		//ǿתΪ���� ������һЩ�������еĳ�Ա���� �Ѹ���ǿתΪStudent��
		Student* stu = (Student*)student;

		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMeOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)  //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete  student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//�����ʦ�Ӳ˵�     �ø���ָ�봫��һ����ʦ		��ʦ�Ӳ˵�����ʵ��
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//��ʦ�˵�
		teacher->operMenu();  //���ö�̬ʵ�ֳ�����

		Teacher* tea = (Teacher*)teacher;  //������������ʦ ת��ΪTeacher*���� ��tea���� �����Ϳ��Ե������еĺ�����
		
		int select = 0;

		cin >> select;

		if (select == 1)  //�鿴����ԤԼ
		{
			tea->showAllOrder();  
		}
		else if (select == 2) //���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			delete teacher; //�ͷŶ����ڴ�
			cout << "ע��ԤԼ" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��¼����  �����ֱ��ǣ������ļ���  �����������  1 -> student  2 -> teacher  3 -> manager
//�������ܣ��ò�ͬ����ݵ�¼����ϵͳ  �����ϢҪ�Ӷ�Ӧ���ļ����ȡ �ٺ�ʵ
void LoginIn(string filename, int type)
{
	//���ö�̬��˼�� ����һ����ݵĸ���ָ�� ���ָ�����ָ��Ҫ�õ�������
	Identity* person = NULL;  //����ȥָ��ͬ���������   ��̬

	//���ļ����в��� ���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		//�ر��ļ�
		ifs.close();
		return;
	}

	//׼�������û���Ϣ  ���¾����û���Ϣ
	//ѧ������ʦ�Ƚ����� Ҫ��id��
	int id = 0;
	string name;
	string pwd;

	//�����ж���ѧ��������ʦ
	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	//��֤
	if (type == 1)
	{
		//ѧ�������֤
		int fId = 0; //���ļ��ж�ȡ��id
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		//ifsһ��һ�еĶ�ȡ�ļ��е���Ϣ
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{ //ifs��ȡ���ļ��е���Ϣ�������������Ϣ�Ա� ������� ���¼�ɹ�
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//new����һ�������ѧ�� �������βδ��뺯��
				person = new Student(id, name, pwd);

				//����ѧ�����Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId = 0;
		string fName;
		string fPwd;

		//���ļ�
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���ĺ������һ�� ����֤ͨ��
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//new����һ���������ʦ
				person = new Teacher(id, name, pwd);

				//�����ʦ���Ӳ˵�
				teacherMenu(person);
				return;

			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ������

		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//�������Ա�Ӳ˵�����
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	int select = 0;
	

	while (1)
	{
		cout << "================ ��ӭ������ϵͳ ===================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t----------------------\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    1��ѧ������     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    2����    ʦ     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    3���� �� Ա     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    0����    ��     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t----------------------\n";
		cout << "����������ѡ��" << endl;
		cin >> select;

		switch (select)
		{
		case 1: //ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //�˳�
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}