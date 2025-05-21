#pragma once
#include <iostream>
#include <string>
using namespace std;
class worker {
public:
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;
	int m_ID;
	string m_name;
	int m_DeptID;
};