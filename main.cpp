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
        case 0://�˳�
            em.ExistSystem();
            break;
        case 1://���
            em.add_emp();
            break;
        case 2://��ʾ
            em.show_Emp();
            break;
        case 3://ɾ��
            em.del_Emp();
            break;
        case 4://�޸�
            em.Mod_Emp();
            break;
        case 5://����
            em.Find_Emp();
            break;
        case 6://����
            em.Sort_Emp();
            break;
        case 7://���
            em.Clean_File();
            break;
        default:
            system("cls");
            break;
        }
    }
    return 0;
}