#pragma once
/*
* ��ʦ����Ҫ�����ǲ鿴ѧ����ԤԼ���ҽ������
* 
* �������� ְ����
* ��ʦ�����Ҫ�����У�
*	����ʾ��ʦ�����Ĳ˵�
*	���鿴����ԤԼ
*	�����ԤԼ
*	��ע����¼
*/
#include"Identity.h"
#include<iostream>
#include<string>
#include"orderFile.h"
#include<vector>
using namespace std;
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��� ְ���� �û��� ����
	Teacher(int empid, string name, string pwd);

	//�˵����� ��д�����еĴ��麯��
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ�������� ְ����
	int m_empid;
};