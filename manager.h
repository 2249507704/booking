#pragma once
/*
* 管理员主要功能是对教师和学生进行管理 查看机房信息以及清空预约记录
* 
* 管理员类中的主要功能是：
*	·显示管理员操作的菜单界面
*	·添加账号   在添加的时候要防止学号 或者 职工号出现重复的情况  所以要有一个去重过程
*	·查看账号
*	·查看机房信息
*	·清空预约记录
*	·注销登录
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
	//默认构造
	Manager();

	//有参构造  用户名  密码
	Manager(string name, string pwd);

	//重写基类中的纯虚函数 菜单函数
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void clearFile();

	//去重操作 重复的学号和职工号就显示错误  利用到了容器
	//去重函数 检测重复 参数：传入id  传入类型  返回值：true代表有重复 false代表没有重复
	//检验就是用传入的id  和  遍历容器里的id  是否有相同的  如果有就返回true
	bool checkRepeat(int id, int type);



	//初始化容器
	void initVector();

	//创建学生容器
	vector<Student>vStu;

	//创建教师容器
	vector<Teacher>vTea;

	//创建机房容器
	vector<ComputerRoom>vCom;

	//初始化机房容器
	void initComputerRoom();
};