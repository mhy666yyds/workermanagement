#include "boss.h"
boss::boss(int id, string name, int did) {
	this->m_ID = id;
	this->m_name = name;
	this->m_DeptID = did;
}
void boss::showInfo() {
	cout << "worker id is :" << this->m_ID
		<< "\tworker name is :" << this->m_name
		<< "\tworker department is:" << this->getDeptName() << endl;
}
string boss::getDeptName() {
	return string("boss");
}