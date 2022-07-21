#include "student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	//初始化属性  id  姓名 密码
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//在构造函数中初始化容器
	this->initComputerRoom();

}

void Student::operMenu()
{ 
	//在构造函数中知道了自己叫什么
	cout << "================ 欢迎学生代表：" << this->m_name << " " << "登录！================== = " << endl;
	cout << "\t\t -------------------- \n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    1、申请预约     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    2、查看我的预约 |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    3、查看所有预约 |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    4、取消预约     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t|    0、注销登录     |\n";
	cout << "\t\t|                    |\n";
	cout << "\t\t -------------------- \n";
	cout << "请输入您的选择：" << endl;
}

void Student::applyOrder()
{

	//申请预约  先申请日期 然后时间段 然后那个机房
	//日期
	cout << "机房开启的时间是周一到周五！" << endl;
	cout << "请输入申请的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	//要接收的定义
	int date = 0;   //输入日期
	int interval;   //时间段 上午 或者 下午
	int room = 0;   //机房编号

	//对输入的判断 输入必须是1到5
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			//满足日期区间  break
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	//时间段  上午或是 下午
	cout << "请输入你要预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	//机房
	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_Comid << "号机房的容量为：" << vCom[i].m_MixNum << endl;
	}

	while (true)
	{
		cin >> room;

		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	cout << "预约成功！审核中..." << endl;

	//把审核信息写入到文件中
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app); //用追加的方式打开
	//要写入的内容
	ofs << "date:" << date << "  ";
	ofs << "interval:" << interval << "  ";
	ofs << "roomid:" << room << "  ";
	ofs << "stuid:" << this->m_id << "  ";
	ofs << "stuname:" << this->m_name << "  ";
	ofs << "status:" << 1 << endl;


	//关闭文件
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMeOrder()
{
	//创建一个OrderFile类
	OrderFile of; //创建这个对象就可以调用他的构造函数 就可以测试代码了  这里边有所有的预约记录

	//如果没有预约记录 则返回
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//atoi 可以把 char型转变为int  因为m_id是整型 
		//如果输入的和遍历到的一样 则打印输出
		if (atoi(of.m_orderData[i]["stuid"].c_str()) == this->m_id)
		{
			cout << "预约日期:周" << of.m_orderData[i]["date"] << " ";
			cout << "预约时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房:" << of.m_orderData[i]["roomid"] << " ";
			string status = "状态:";//0 取消预约  1审核中  2已预约  -1预约失败

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
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
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
		else if(of.m_orderData[i]["status"] == "2")
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

void Student::cancelOrder()
{
	//先查看是否有预约记录
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中的预约和已经预约成功的预约可以取消！" << endl;
	vector<int>v;  //准备一个容器去存放编号  存放在最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//判断学生编号是不是自身的  因为只有自己可以取消自己的预约记录
		if (atoi(of.m_orderData[i]["stuid"].c_str()) == this->m_id)
		{
			//因为只可以取消审核中  1   的  和  审核成功的 2  的记录  筛选状态
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				//因为这个i是我们要修改的信息 可能筛选好几条才出现一条 则把筛选出来的i放到容器v里
				v.push_back(i);
				//输出编号  要取消哪条预约信息  用index 从1开始  i是用来遍历的 例如现在有五条 但是有两条是我预约的 则index来给我的两条预约记录做下标
				cout << index++ << "、"; //定义自己结果的下标
				cout << "预约日期:周" << of.m_orderData[i]["date"] << " ";
				cout << "预约时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "学号:" << of.m_orderData[i]["stuid"] << " ";
				cout << "姓名:" << of.m_orderData[i]["stuname"] << " ";
				cout << "机房编号:" << of.m_orderData[i]["roomid"] << " ";

				//拼接状态 因为只可以修改这两种状态的预约信息 所以只筛选出这两种
				string status = "状态:"; //0取消预约  1 审核中  2预约成功 

				//只找处于审核中 和 预约成功的信息  因为要取消预约
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				//输出预约状态
				cout << status << endl;
			}

			
		}
	}
	cout << "请输入你要取消哪条预约记录,0表示返回：" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())  //输入取消的条数要大于等于0条 小于vector容器里的最大条数
		{
			//如果用户选择0  就返回 break出去
			if (select == 0)
			{
				break;
			}
			else
			{
				//这些是修改上边显示的状态 从而达到效果
				of.m_orderData[v[select - 1]]["status"] = "0";//取消预约  这是把文件中的状态改为0

				//初始化文件
				of.updateOrder();

				cout << "已经取消了预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}

void Student::initComputerRoom()
{
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	//清空容器
	vCom.clear();

	ComputerRoom c;

	while (ifs >> c.m_Comid && ifs >> c.m_MixNum)
	{
		//把读取到的数据放入容器里
		vCom.push_back(c);
	}

	cout << "当前的机房数为：" << vCom.size() << endl;

	//关闭文件
	ifs.close();

}
