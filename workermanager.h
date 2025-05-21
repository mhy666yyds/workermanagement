#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#define FILENAME "empFile.txt"
using namespace std;

class EmployeeManagement {
public:
    EmployeeManagement();
    //展示菜单
    void showMenu();
    //退出系统
    void ExistSystem();
    //记录人数
    int m_empNum;
    //职工数组指针
    worker** m_empArray;
    //添加职工
    void add_emp();
    //保存文件
    void save();
    //判断文件是否为空
    bool m_Fileisempty;
    //统计文件中人数
    int get_EmpNum();
    //初始化员工
    void init_Emp();
    //显示职工
    void show_Emp();
    //删除职工
    void del_Emp();
    //判断职工是否存在(存在返回位置，不存在返回-1)
    int IsExist(int id);
    //修改职工
    void Mod_Emp();
    //查找职工
    void Find_Emp();
    //排序
    void Sort_Emp();
    //清空    
    void Clean_File();
    ~EmployeeManagement();
};
