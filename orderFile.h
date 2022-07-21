#pragma once
//预约类
#include<iostream>
#include"globalFile.h"
#include<map>
#include<string>
#include<fstream>
using namespace std;

class OrderFile
{
public:

	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//因为日期 和 内容 都是成对出现  使用map key --- 记录的条数   value---  具体记录的键值对信息

	/*******************************************************************
	* 
	* ·map容器的目的是用来存放txt文件里的数据的
	* ·又因为order.txt文件里的数据都是以键值对的形式存放 map<key,value>
	* ·因为预约会有好多条 则用map嵌套
	*			map<int, map<string, string>>   key---预约条数  value---预约信息
	*			·int 表示第几条信息
	*			·map<string,string> 表示每条信息的内容
	********************************************************************/
	map<int, map<string, string>> m_orderData;

	//预约记录条数
	int m_Size;

};