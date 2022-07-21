#pragma once
#include<iostream>
using namespace std;

//因为机房的信息也要输出  所以要创建一个机房类
class ComputerRoom
{
public:

	int m_Comid;  //机房号
	int m_MixNum;  //机房最大容量
};