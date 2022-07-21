#include "manager.h"
#include<fstream>
#include"globalFile.h"
#include<algorithm>
Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	//初始化信息
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化容器  在这里调用初始化容器的函数 可以显示出学生、教师文件中的信息
	this->initVector();

	this->initComputerRoom();
}

void Manager::operMenu()
{
	cout << "================ 欢迎管理员"<<this->m_name<<"登录！================== = " << endl;
	cout << "\t\t -------------------- \n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    1、添加账号     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    2、查看账号     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    3、查看机房     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    4、清空预约     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    0、注销登录     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t -------------------- \n";
	cout << "请输入您的选择：" << endl;
}

void Manager::addPerson()
{
	cout << "请输入您要添加用户的类型：" << endl;
	cout << "1---添加学生" << endl;
	cout << "2---添加老师" << endl;
	
	string filename; //创建对应的文件
	string tip;
	ofstream ofs; //对文件进行写入的对象 文件输出流对象

	int select = 0;
	cin >> select;

	//重复错误提示
	string errorTop;

	if (select == 1)  //选择1  有以下定义
	{
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errorTop = "学号重复，请重新输入！";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入职工号：";
		errorTop = "职工号重复，请重新输入！";
	}

	//写文件
	ofs.open(filename, ios::out | ios::app);  //写 并且要 追加着写
	//写入的信息
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	
	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTop << endl;
		}
		else
			break;
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//用ofs对象往对应的filename里边写东西
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;


	system("pause");
	system("cls");
	
	//关闭ofs函数
	ofs.close();

	/*************************************************************
	* bug：在同一时间添加多个人的情况下会出现学号或者职工号
	* 重复的情况
	*
	* 解决方法： 在每次添加过后都初始化容器一次 重新获取数据
	**************************************************************/
	this->initVector();
	return;
}

void PrintStudent(Student& s)
{
	cout << "学生学号为：" << s.m_id << " " << "学生姓名为：" << s.m_name << " " << "学生密码为：" << s.m_pwd << endl;
}
 

void PrintTeacher(Teacher& t)
{
	cout << "教师职工号为：" << t.m_empid << " " << "教师姓名为：" << t.m_name << " " << "教师密码为：" << t.m_pwd << endl;
}

void Manager::showPerson()
{
	//先提示查看什么
	cout << "请选择要查看的内容：" << endl;
	cout << "1、查看所有的学生" << endl;
	cout << "2、查看所有的老师" << endl;

	//定义一个选项
	int select = 0;
	//开始接收
	cin >> select;
	
	if (select == 1)
	{
		//查看学生
		cout << "所有的学生信息为：" << endl;
		//STL中的遍历算法 for_each  和 vector<...>::it...一样
		//用STL算法要包含头文件algorithm
		for_each(vStu.begin(), vStu.end(),PrintStudent); //参数是容器的开头和结尾 和一个函数
	}
	else
	{
		//查看老师
		cout << "所有的老师信息为：" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	//遍历容器内的数据 并且输出
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_Comid << " " << "机房最大容量" << it->m_MixNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearFile()
{
	//用ofstream文件的输出流对象来打开文件 用trunc--->如果文件存在 删干净 再创建
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//在添加id号的时候需要用到这个函数
bool Manager::checkRepeat(int id, int type)
{
	//先来查找学生的是否有重复
	if (type == 1)
	{
		//遍历容器里的元素
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}
//初始化容器
void Manager::initVector()
{
	//首先肯定是要获取打开学生文件 来获取学生文件里的信息  读文件
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}

	//把两个容器进行清空
	vStu.clear();
	vTea.clear();

	//获取学生信息  这个是已经有的  所以不需要new一个出来了
	Student s;
	//一行一行的来读取
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		//把读取到的信息放到vector容器内
		vStu.push_back(s);
	}

	//用容器特有的函数输出一些读取到的信息
	cout << "当前学生数量为：" << vStu.size() << endl;
	//关闭文件读取
	ifs.close();

	//开始读取老师文件的信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_empid && ifs >>t.m_name && ifs >> t.m_pwd)
	{
		//把读取到的信息放到容器里
		vTea.push_back(t);
	}

	cout << "当前教师数量为：" << vTea.size() << endl;

	ifs.close();
}

void Manager::initComputerRoom()
{
	//首先要读取文件  读文件用ifs  打开文件ofs 写文件
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}
	//清空初始容器
	vCom.clear();

	ComputerRoom c;
	//检查现在有的数据
	while (ifs >> c.m_Comid && ifs >> c.m_MixNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;

	//关闭文件
	ifs.close();
}

