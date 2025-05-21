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
    //չʾ�˵�
    void showMenu();
    //�˳�ϵͳ
    void ExistSystem();
    //��¼����
    int m_empNum;
    //ְ������ָ��
    worker** m_empArray;
    //���ְ��
    void add_emp();
    //�����ļ�
    void save();
    //�ж��ļ��Ƿ�Ϊ��
    bool m_Fileisempty;
    //ͳ���ļ�������
    int get_EmpNum();
    //��ʼ��Ա��
    void init_Emp();
    //��ʾְ��
    void show_Emp();
    //ɾ��ְ��
    void del_Emp();
    //�ж�ְ���Ƿ����(���ڷ���λ�ã������ڷ���-1)
    int IsExist(int id);
    //�޸�ְ��
    void Mod_Emp();
    //����ְ��
    void Find_Emp();
    //����
    void Sort_Emp();
    //���    
    void Clean_File();
    ~EmployeeManagement();
};
