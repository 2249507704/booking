#pragma once
/*
* ����Ա��Ҫ�����ǶԽ�ʦ��ѧ�����й��� �鿴������Ϣ�Լ����ԤԼ��¼
* 
* ����Ա���е���Ҫ�����ǣ�
*	����ʾ����Ա�����Ĳ˵�����
*	������˺�   ����ӵ�ʱ��Ҫ��ֹѧ�� ���� ְ���ų����ظ������  ����Ҫ��һ��ȥ�ع���
*	���鿴�˺�
*	���鿴������Ϣ
*	�����ԤԼ��¼
*	��ע����¼
*/
#include"Identity.h"
#include<iostream>
#include<string>
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
using namespace std;
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���  �û���  ����
	Manager(string name, string pwd);

	//��д�����еĴ��麯�� �˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void clearFile();

	//ȥ�ز��� �ظ���ѧ�ź�ְ���ž���ʾ����  ���õ�������
	//ȥ�غ��� ����ظ� ����������id  ��������  ����ֵ��true�������ظ� false����û���ظ�
	//��������ô����id  ��  �����������id  �Ƿ�����ͬ��  ����оͷ���true
	bool checkRepeat(int id, int type);



	//��ʼ������
	void initVector();

	//����ѧ������
	vector<Student>vStu;

	//������ʦ����
	vector<Teacher>vTea;

	//������������
	vector<ComputerRoom>vCom;

	//��ʼ����������
	void initComputerRoom();
};