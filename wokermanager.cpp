#include "workermanager.h"

EmployeeManagement::EmployeeManagement() {
    //文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        this->m_empNum = 0;
        this->m_empArray = NULL;
        this->m_Fileisempty = true; 
        ifs.close();
        return;
    }
    //文件存在但为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this->m_empNum = 0;
        this->m_empArray = NULL;
        this->m_Fileisempty = true;
        ifs.close();
        return;
    }
   //文件存在不为空
    int num = this->get_EmpNum();
    this->m_empNum = num;
    this->m_empArray = new worker * [this->m_empNum];
    this->init_Emp();
}

void EmployeeManagement::showMenu() {
    cout << "=====================================" << endl;
    cout << "Welcome to Employee Management System" << endl;
    cout << "==========0. Exist===================" << endl;
    cout << "==========1. Add Employee============" << endl;
    cout << "==========2. View Employee==========" << endl;
    cout << "==========3. Delete Employee=========" << endl;
    cout << "==========4. Update Employee=========" << endl;
    cout << "==========5. Find====================" << endl;
    cout << "==========6. Sort====================" << endl;
    cout << "==========7. Clean===================" << endl;
    cout << "Please select an option: " << endl;
}

void EmployeeManagement::ExistSystem() {
    cout << "Welcome to use it next time." << endl;
    exit(0);//退出程序
}

void EmployeeManagement::add_emp() {
    cout << "plesae enter num:" << endl;
    int addnum = 0;//保存用户的输入数量
    cin >> addnum;
    if (addnum > 0) {
        //添加
        //计算新添加空间大小
        int newSize = this->m_empNum + addnum;

        //开辟新空间
        worker** newSpace = new worker * [newSize];
        //拷贝原来数据
        if (this->m_empArray != NULL) {
            for (int i = 0; i < this->m_empNum; i++) {
                newSpace[i] = this->m_empArray[i];
            }
        }

        //添加新数据
        for (int i = 0; i < addnum; i++) {
            int id;
            string name;
            int dselect;
            cout << "please enter the" << i + 1 << " new worker num" << endl;
            cin >> id;
            cout << "please enter the" << i + 1 << " name" << endl;
            cin >> name;
            cout << "please select site" << endl<<
                "1. worker" << endl <<
                "2. manager" << endl <<
                "3. boss" << endl;
            cin >> dselect;
            worker* worker = NULL;
            switch (dselect) {
            case 1:
                worker = new employee(id, name, 1);
                break;
            case 2:
                worker = new manager(id, name, 2);
                break;
            case 3:
                worker = new boss(id, name, 3);
                break;
            default:
                break;
            }
            //将创建的职工指针保存到数组中
            newSpace[this->m_empNum + i] = worker;
        }

        //释放空间
        delete[]this->m_empArray;
        //更改新空间指向
        this->m_empArray = newSpace;
        //更新职工人数
        this->m_empNum = newSize;
        this->m_Fileisempty = false;
        //提示添加成功
        cout << "success enter " << addnum << "new worker" << endl;
        //添加成功后保存到文件中
        this->save();
    }
    else {
        cout << "error!" << endl;
    }
    system("pause");
    system("cls");
}

void EmployeeManagement::save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    //将数据写入到文件
    for (int i = 0; i < this->m_empNum; i++) {
        ofs << this->m_empArray[i]->m_ID << " "
            << this->m_empArray[i]->m_name << " "
            << this->m_empArray[i]->m_DeptID << endl;
    }
    ofs.close();
}

int EmployeeManagement::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did){
        num++;
    }
    return num;
}

void EmployeeManagement::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did) {
        worker* worker = NULL;
        if (did == 1) {
            worker = new employee(id, name, did);
        }
        else if (did == 2) {
            worker = new manager(id, name, did);
        }
        else {
            worker = new boss(id, name, did);
        }
        this->m_empArray[index] = worker;
        index++;
    }
    ifs.close();
}

void EmployeeManagement::show_Emp() {
    //判断文件是否为空
    if (this->m_Fileisempty) {
        cout << "can not find file or no word in file" << endl;
    }
    else {
        for (int i = 0; i < m_empNum; i++) {
            this->m_empArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

int EmployeeManagement::IsExist(int id) {
    int index = -1;
    for (int i = 0; i < this->m_empNum; i++) {
        if (this->m_empArray[i]->m_ID == id) {
            index = i;
            break;
        }
    }
    return index;
}

void EmployeeManagement::del_Emp() {
    if (this->m_Fileisempty) {
        cout << "can not find file or no wore in file" << endl;
    }
    else {
        cout << "please enter the num that you want delete" << endl;
        int id = 0;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_empNum; i++) {
                this->m_empArray[i] = this->m_empArray[i + 1];
            }
            this->m_empNum--;
            this->save();
            cout << "success!" << endl;
        }
        else {
            cout << "filed!can not find this" << endl;
        }
    }
    system("pause");
    system("cls");
}

void EmployeeManagement::Mod_Emp() {
    if (this->m_Fileisempty) {
        cout << "can not find file" << endl;
    }
    else {
        cout << "please enter num that you want to modify" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1) {
            delete this->m_empArray[ret];
            int newID = 0;
            string newName = " ";
            int newS = 0;
            cout << "please enter new id" << endl;
            cin >> newID;
            cout << "please enter new name" << endl;
            cin >> newName;
            cout << "please enter new slect" << endl;
            cout << "please select site" << endl <<
                "1. worker" << endl <<
                "2. manager" << endl <<
                "3. boss" << endl;
            cin >> newS;
            worker* worker = NULL;
            switch (newS) {
            case 1:
                worker = new employee(newID, newName, newS);
                break;
            case 2 :
                worker = new manager(newID, newName, newS);
                break;
            case 3 :
                worker = new boss(newID, newName, newS);
                break;
            default:
                break;
            }
            //更新到数组中
            this->m_empArray[ret] = worker;
            cout << "success!" << endl;
            this->save();
        }
        else {
            cout << "filed! can not find this people" << endl;
        }
    }
    system("pause");
    system("cls");
}

void EmployeeManagement::Find_Emp() {
    if (this->m_Fileisempty) {
        cout << "can not find file" << endl;
    }
    else {
        cout << "please enter way that you want to find" << endl;
        cout << "1 .id" << endl << "2 .name" << endl;
        int select;
        cin >> select;
        if (select == 1) {
            int id;
            cout << "please enter the id that you want to find" << endl;
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1) {
                cout << "information is" << endl;
                this->m_empArray[ret]->showInfo();
            }
            else {
                cout << "can not find this people " << endl;
            }
        }
        else if (select == 2) {
            string name;
            cout << "please enter the name that you want to find" << endl;
            cin >> name;
            bool flag = false;
            for (int i = 0; i < m_empNum; i++) {
                if (this->m_empArray[i]->m_name == name) {
                    cout << "success,id is " << this->m_empArray[i]->m_ID << "information is" << endl;
                    this->m_empArray[i]->showInfo();
                    flag = true;
                }
            }
            if (flag == false) {
                cout << "filed ! can not find this people" << endl;
            }
        }
        else {
            cout << "error" << endl;
        }
    }
    system("pause");
    system("cls");
}

void EmployeeManagement::Sort_Emp() {
    if (this->m_Fileisempty) {
        cout << "can not find file" << endl;
        system("pause");
        system("cls");
    }
    else {
        cout << "please choice way that you want to sort" << endl << "1.in ascending order" << endl << "2.ascending sequence" << endl;
        int select;
        cin >> select;
        for (int i = 0; i < this->m_empNum; i++) {
            int minormax = i;
            for (int j = i + 1; j < this->m_empNum; j++) {
                if (select == 1) {
                    if (this->m_empArray[minormax]->m_ID > this->m_empArray[j]->m_ID) {
                        minormax = j;
                    }
                }
                else {
                    if (this->m_empArray[minormax]->m_ID < this->m_empArray[j]->m_ID) {
                        minormax = j;
                    }
                }
            }
            if (i != minormax) {
                worker* temp = this->m_empArray[i];
                this->m_empArray[i] = this->m_empArray[minormax];
                this->m_empArray[minormax] = temp;
            }
        }
        cout << "success,the resule is" << endl;
        this->save();
        this->show_Emp();
    }
}

void EmployeeManagement::Clean_File() {
    cout << "are you sure(1.Y  2.N)" << endl;
    int select;
    cin >> select;
    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->m_empArray != NULL) {
            //删除堆区每个职工对象
            for (int i = 0; i < this->m_empNum; i++) {
                delete this->m_empArray[i];
                this->m_empArray[i] = NULL;
            }

            //删除堆区数组指针
            delete[]this->m_empArray;
            this->m_empArray = NULL;
            this->m_empNum = 0;
            this->m_Fileisempty = true;
        }
        cout << "success" << endl;
    }
    system("pause");
    system("cls");
}

EmployeeManagement::~EmployeeManagement() {
    if (this->m_empArray != NULL) {
        for (int i = 0; i < this->m_empNum; i++) {
            if (this->m_empArray[i] != NULL) {
                delete this->m_empArray[i];
            }
        }
        delete[]this->m_empArray;
        this->m_empArray = NULL;
    }
}