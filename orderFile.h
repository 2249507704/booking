#pragma once
//ԤԼ��
#include<iostream>
#include"globalFile.h"
#include<map>
#include<string>
#include<fstream>
using namespace std;

class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��Ϊ���� �� ���� ���ǳɶԳ���  ʹ��map key --- ��¼������   value---  �����¼�ļ�ֵ����Ϣ

	/*******************************************************************
	* 
	* ��map������Ŀ�����������txt�ļ�������ݵ�
	* ������Ϊorder.txt�ļ�������ݶ����Լ�ֵ�Ե���ʽ��� map<key,value>
	* ����ΪԤԼ���кö��� ����mapǶ��
	*			map<int, map<string, string>>   key---ԤԼ����  value---ԤԼ��Ϣ
	*			��int ��ʾ�ڼ�����Ϣ
	*			��map<string,string> ��ʾÿ����Ϣ������
	********************************************************************/
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int m_Size;

};