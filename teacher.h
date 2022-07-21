#pragma once
/*
* 教师类主要功能是查看学生的预约并且进行审核
* 
* 特有属性 职工号
* 教师类的主要功能有：
*	·显示教师操作的菜单
*	·查看所有预约
*	·审核预约
*	·注销登录
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
	//默认构造
	Teacher();

	//有参构造 职工号 用户名 密码
	Teacher(int empid, string name, string pwd);

	//菜单界面 重写基类中的纯虚函数
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//教师特有属性 职工号
	int m_empid;
};