#pragma once
/*
* ·在整个系统中有三种身份，分别是学生、老师、管理员
* ·三种身份有共性也有特性  可以将三种身份的共性抽象出一个身份基类identity
* ·在头文件下创建identity.h文件
* 
* 共性：在登录的时候都要输入各自的用户名和密码
* 多态：因为每个角色在其下边都有一个子菜单 所以用纯虚函数operMenu来实现
*/
#include<iostream>
#include<string>
using namespace std;

//身份抽象类  子类要重新基类中的纯虚函数 不然子类也是抽象类 不能实现
class Identity
{

public:

	//操作菜单
	virtual void operMenu() = 0;

	string m_name; //用户名
	string m_pwd;  //密码
};