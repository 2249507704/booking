#pragma once
/*
* ѧ�������Ҫ������ͨ�����еĳ�Ա������ʵ��ԤԼ����
* 
* ѧ�����е�   ѧ��ѧ��
* ѧ�������Ҫ������
*	����ʾѧ�������Ĳ˵�����
*	������ԤԼ
*	���鿴����ԤԼ
*	���鿴����ԤԼ
*	��ȡ��ԤԼ
*	��ע����¼
*/
#include"Identity.h"
#include<iostream>
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
using namespace std;

class Student :public Identity
{
public:

	//Ĭ�Ϲ���
	Student();

	//�вι���(ѧ�� ���� ����)
	Student(int id, string name, string pwd);

	//�Ӳ˵����� ��д�����еĴ��麯��
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMeOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ  ȡ��ԤԼ�ɹ���ԤԼ  ������ ����е�ԤԼ
	void cancelOrder();

	//ѧ��ѧ�� ѧ������������
	int m_id;

	//��������  Ҫ��ʾ������Ϣ
	vector<ComputerRoom>vCom;

	//��ʼ�����������ĺ���
	void initComputerRoom();
};