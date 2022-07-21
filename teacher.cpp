#include "teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int empid, string name, string pwd)
{
	//初始化教师属性
	this->m_empid = empid;
	this->m_name = name;
	this->m_pwd = pwd;
}

void Teacher::operMenu()
{
	cout << "================ 欢迎教师：" << this->m_name << " " << "登录！================== = " << endl;
	cout << "\t\t -------------------- \n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    1、查看所有预约 |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    2、审核预约     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    0、注销登录     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t -------------------- \n";
	cout << "请输入您的选择：" << endl;
	
}

void Teacher::showAllOrder()
{
	OrderFile of; //创建一个类
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期:周" << of.m_orderData[i]["date"] << " ";
		cout << "预约时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号:" << of.m_orderData[i]["stuid"] << " ";
		cout << "姓名:" << of.m_orderData[i]["stuname"] << " ";
		cout << "机房编号:" << of.m_orderData[i]["roomid"] << " ";

		//拼接状态
		string status = "状态:"; //0取消预约  1 审核中  2预约成功 -1预约失败

		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "取消预约";
		}

		//输出预约状态
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	OrderFile of; //创建一个类
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约信息如下：" << endl;

	int index = 1;
	//创建一个容器 存我们需要的下标
	vector<int>v;

	for (int i = 0; i < of.m_Size; i++)
	{
		//审核状态为审核中的信息
		if (of.m_orderData[i]["status"] == "1")  //找到了需要审核的信息了
		{
			//把这个编号  也就是第几条信息放入容器中  重新定义下标为1
			v.push_back(i);
			cout << index++ << "、";
			cout << "预约日期:周" << of.m_orderData[i]["date"] << " ";
			cout << "预约时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "学号:" << of.m_orderData[i]["stuid"] << " ";
			cout << "姓名:" << of.m_orderData[i]["stuname"] << " ";
			cout << "机房编号:" << of.m_orderData[i]["roomid"] << " ";

			//只找处于审核中的信息  因为要审核预约
			string status = "状态:"; //1-->审核中  2-->成功 -1-->失败  0-->取消
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
	}
	cout << "请输入您要审核的预约信息,输入0则返回：" << endl;
	int select = 0; //选择审核的信息第几条
	int ret = 0; //是否同意通过审核的选择
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入您的审核结果：" << endl;
				cout << "1-->同意" << endl;
				cout << "2-->拒绝" << endl;
				cin >> ret;

				//切记这里是更改状态 不是判断是否相等
				if (ret == 1)
				{
					//这些是修改上边显示的状态 从而达到效果
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				//更新文件
				of.updateOrder();
				cout << "审核完毕" << endl;
				//跳出循环
				break;
			}

		}
		cout << "输入错误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}
