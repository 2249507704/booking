#pragma once
/*
* ��������ϵͳ����������ݣ��ֱ���ѧ������ʦ������Ա
* ����������й���Ҳ������  ���Խ�������ݵĹ��Գ����һ����ݻ���identity
* ����ͷ�ļ��´���identity.h�ļ�
* 
* ���ԣ��ڵ�¼��ʱ��Ҫ������Ե��û���������
* ��̬����Ϊÿ����ɫ�����±߶���һ���Ӳ˵� �����ô��麯��operMenu��ʵ��
*/
#include<iostream>
#include<string>
using namespace std;

//��ݳ�����  ����Ҫ���»����еĴ��麯�� ��Ȼ����Ҳ�ǳ����� ����ʵ��
class Identity
{

public:

	//�����˵�
	virtual void operMenu() = 0;

	string m_name; //�û���
	string m_pwd;  //����
};