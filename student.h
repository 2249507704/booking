#pragma once
/*
* 学生类的主要功能是通过类中的成员函数，实现预约操作
* 
* 学生特有的   学生学号
* 学生类的主要功能有
*	·显示学生操作的菜单界面
*	·申请预约
*	·查看自身预约
*	·查看所有预约
*	·取消预约
*	·注销登录
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

	//默认构造
	Student();

	//有参构造(学号 姓名 密码)
	Student(int id, string name, string pwd);

	//子菜单界面 重写基类中的纯虚函数
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMeOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约  取消预约成功的预约  或者是 审核中的预约
	void cancelOrder();

	//学生学号 学生的特有属性
	int m_id;

	//机房容器  要显示机房信息
	vector<ComputerRoom>vCom;

	//初始化机房容器的函数
	void initComputerRoom();
};