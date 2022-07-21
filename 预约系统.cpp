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
* 架构：
*	基类：Identity.h
*	派生类： manager.h  student.h  teacher.h 在cpp中实现
*	登录模块: globalFile.h
*	入口: 预约系统
*/

//进入管理员子菜单  用父类指针传入一个管理员  管理员子菜单功能实现
void managerMenu(Identity *&manager)
{
	while (true)  //因为菜单要一直出现 所以while
	{
		//调用管理员子菜单   多态 父类指针调用子类对象  公共的部分
		manager->operMenu();

		//将父类指针转为子类指针 就可以调用子类中的特有接口了
		Manager* man = (Manager*)manager;  //把父类指针强行转换为Manager指针

		int select = 0;

		//接收用户选项
		cin >> select;

		if (select == 1)  //添加账号
		{
			man->addPerson();
		}
		else if (select == 2)  // 查看账号
		{
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			man->clearFile();
		}
		else
		{
			//注销账号 直接把申请的new对象销毁就行
			delete manager; //销毁堆区对象
			system("pause");
			system("cls");
			return;
		}

	}
}

//进入学生子菜单    用父类指针传入一个学生     学生子菜单功能实现
void studentMenu(Identity*& student)
{
	while (true)
	{
		//用多态 进入子菜单
		student->operMenu(); //这个还属于父类范围 在父类成员内的属性  然后把指针转回去 控制其他接口

		//强转为子类 可以用一些子类特有的成员函数 把父类强转为Student类
		Student* stu = (Student*)student;

		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMeOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)  //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete  student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//进入教师子菜单     用父类指针传入一个教师		教师子菜单功能实现
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//教师菜单
		teacher->operMenu();  //利用多态实现出来的

		Teacher* tea = (Teacher*)teacher;  //把这个父类的老师 转换为Teacher*类型 用tea接收 这样就可以调用特有的函数了
		
		int select = 0;

		cin >> select;

		if (select == 1)  //查看所以预约
		{
			tea->showAllOrder();  
		}
		else if (select == 2) //审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher; //释放堆区内存
			cout << "注销预约" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录功能  参数分别是：操作文件名  操作身份类型  1 -> student  2 -> teacher  3 -> manager
//函数功能：用不同的身份登录进该系统  身份信息要从对应的文件里读取 再核实
void LoginIn(string filename, int type)
{
	//利用多态的思想 创建一个身份的父类指针 这个指针待会指向要用到的子类
	Identity* person = NULL;  //用它去指向不同的子类对象   多态

	//对文件进行操作 读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		//关闭文件
		ifs.close();
		return;
	}

	//准备接收用户信息  以下就是用户信息
	//学生和老师比较特殊 要有id号
	int id = 0;
	string name;
	string pwd;

	//再来判断是学生还是老师
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	//验证
	if (type == 1)
	{
		//学生身份验证
		int fId = 0; //从文件中读取的id
		string fName;//从文件中读取的姓名
		string fPwd;//从文件中读取的密码
		//ifs一行一行的读取文件中的信息
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{ //ifs读取到文件中的信息和我们输入的信息对比 如果都对 则登录成功
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				//new出来一个具体的学生 用来当形参传入函数
				person = new Student(id, name, pwd);

				//进入学生的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId = 0;
		string fName;
		string fPwd;

		//读文件
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//读的和输入的一样 就验证通过
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				//new出来一个具体的老师
				person = new Teacher(id, name, pwd);

				//进入教师的子菜单
				teacherMenu(person);
				return;

			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取的密码

		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//进入管理员子菜单界面
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	int select = 0;
	

	while (1)
	{
		cout << "================ 欢迎来到该系统 ===================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t----------------------\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    1、学生代表     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    2、老    师     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    3、管 理 员     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    0、退    出     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t----------------------\n";
		cout << "请输入您的选择：" << endl;
		cin >> select;

		switch (select)
		{
		case 1: //学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}