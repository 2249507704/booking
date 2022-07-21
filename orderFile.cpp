#include "orderFile.h"

OrderFile::OrderFile()
{
	//开始读文件
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	//准备从文件中获取的数据
	string date;     //日期
	string interval; //时间段
	string stuid;	 //学生id
	string stuname;	 //学生姓名
	string roomid;	 //机房编号
	string status;	 //预约状态

	//初始化预约记录的条数
	this->m_Size = 0;

	//读取预约信息
	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status)
	{
		////测试是否能读出
		//cout << date << endl;				//读出来的date是 date:1  是一个键值对 我们要把他进行拆分
		//cout << interval << endl;
		//cout << stuid << endl;
		//cout << stuname << endl;
		//cout << roomid << endl;
		//cout << status << endl;
		//cout << endl;

		//现在出现的都是键值对  日期：1  接下来要把键值对分割  找到：
		string key;
		string value;
		//把key和value放到一个小容器里
		map<string, string>m;

		//分割日期
		int pos = date.find(":"); //date：1   返回的位置pos = 4  d a t e ：1
									//							 0 1 2 3 4	
		if (pos != -1) //说明找到：的位置了
		{
			//用截取把key截取出来  substr()  从那里开始截取 截取几个
			key = date.substr(0, pos);  //从0号截取到4号  d a t e 从0位置开始截取 4个
			value = date.substr(pos + 1, date.size() - pos - 1);

			//把分割的东西放到容器里  因为每一个都是队组 则要创建一个队组 make_pair(key,value)
			m.insert(make_pair(key, value));

		}

		//分割时间段
		pos = interval.find(":"); //interval：1   返回的位置pos = 8  
													
		if (pos != -1) //说明找到：的位置了
		{
			//用截取把key截取出来  substr()  从那里开始截取 截取几个
			key = interval.substr(0, pos); 
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			//把分割的东西放到容器里  因为每一个都是队组 则要创建一个队组 make_pair(key,value)
			m.insert(make_pair(key, value));

		}

		//分割学生id
		pos = stuid.find(":"); 

		if (pos != -1) //说明找到：的位置了
		{
			//用截取把key截取出来  substr()  从那里开始截取 截取几个
			key = stuid.substr(0, pos);  
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);

			//把分割的东西放到容器里  因为每一个都是队组 则要创建一个队组 make_pair(key,value)
			m.insert(make_pair(key, value));

		}
		

		//分割学生姓名
		pos = stuname.find(":");

		if (pos != -1) //说明找到：的位置了
		{
			//用截取把key截取出来  substr()  从那里开始截取 截取几个
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);

			//把分割的东西放到容器里  因为每一个都是队组 则要创建一个队组 make_pair(key,value)
			m.insert(make_pair(key, value));

		}


		//分割机房编号
		pos = roomid.find(":");

		if (pos != -1) //说明找到：的位置了
		{
			//用截取把key截取出来  substr()  从那里开始截取 截取几个
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);

			//把分割的东西放到容器里  因为每一个都是队组 则要创建一个队组 make_pair(key,value)
			m.insert(make_pair(key, value));

		}

		//分割预约状态
		pos = status.find(":");

		if (pos != -1) //说明找到：的位置了
		{
			//用截取把key截取出来  substr()  从那里开始截取 截取几个
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			//把分割的东西放到容器里  因为每一个都是队组 则要创建一个队组 make_pair(key,value)
			m.insert(make_pair(key, value));

		}
		////验证
		//cout << "key =" << key << endl;
		//cout << "value=" << value << endl;

		//将有记录的小map容器放到大map容器里   把当前有多少条记录 和 小map容器里的数据 插入到大map容器中
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++; //更新记录数量
	}
	ifs.close();

}

void OrderFile::updateOrder()
{
	//先判断有没有记录  如果没有记录 则return
	if (this->m_Size == 0)
	{
		return;
	}

	//用out|trunc重新写
	ofstream ofs;

	//更新完了都删掉 重新写入
	ofs.open(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < m_Size; i++)
	{
		//这个是嵌套的map容器 i是第几条预约信息  后者才是要的东西
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuid:" << this->m_orderData[i]["stuid"] << " ";
		ofs << "stuname:" << this->m_orderData[i]["stuname"] << " ";
		ofs << "roomid:" << this->m_orderData[i]["roomid"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}

	ofs.close();
}
