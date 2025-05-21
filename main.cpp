#include <iostream>
#include "workermanager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main() {
    EmployeeManagement em;
    while (true) {
        em.showMenu();
        int choice = 0;
        cin >> choice;
        switch (choice)
        {
        case 0://退出
            em.ExistSystem();
            break;
        case 1://添加
            em.add_emp();
            break;
        case 2://显示
            em.show_Emp();
            break;
        case 3://删除
            em.del_Emp();
            break;
        case 4://修改
            em.Mod_Emp();
            break;
        case 5://查找
            em.Find_Emp();
            break;
        case 6://排序
            em.Sort_Emp();
            break;
        case 7://清空
            em.Clean_File();
            break;
        default:
            system("cls");
            break;
        }
    }
    return 0;
}