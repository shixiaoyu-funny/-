#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Base.h"
#include"Functions.h"
#include<mysql.h>
using namespace std;
const char* host = "127.0.0.1";
const char* user = "root";
string password;//159357
const char* database_name = "project1";
const int port = 3306;
int operation;
int identify;
extern map<string, map<string, vector<Course>>> course;
//��ȡ���ݿ����Ӿ��
MYSQL* con = mysql_init(NULL);
void dbInit() {
	cout << "���������ݿ����룺";
	cin>>password;
	if (!mysql_real_connect(con, host, user, password.c_str(), database_name, port, NULL, 0)) {
		cerr << "���������Ȩ���ʣ�" << endl;
		system("pause");
		exit(1);
		return;
	}
	else {
		cout << "���ݿ����ӳɹ�" << endl;
	}
	mysql_set_character_set(con, "gbk");
}
//�ر����ݿ�
void dbClose() {
	if (con != NULL) {
		mysql_close(con);
		cout << "���ݿ������Ѱ�ȫ�ر�" << endl;
	}
}
//�洢ѧ��ѡ����Ϣ
map<int, Course> selectedCourses = {};
//�洢�����û���Ϣ
vector<Student> stuUser = {};
vector<Teacher> teaUser = {};
//��¼&ע��
void Login() {
	bool flag1 = true;
	while (flag1) {
		cout << "��ѡ��������ݣ�1.ѧ�� 2.��ʦ����" << endl;
		cin >> identify;
		if (identify == 1) {
			if (studentLogin()) {
				cout << "��¼�ɹ���" << endl;
				studentFunction();
			}
			else {
				cout << "��¼ʧ�ܣ���Ҫע����(y/n)" << endl;
				char choice;
				cin >> choice;
				if (choice == 'y') {
					stuRegister();
					cout << "ע��ɹ��������µ�½" << endl;
				}
				else {
					cout << "�����µ�½��" << endl;
				}
			}
		}
		if (identify == 2) {

			if (teacherLogin()) {
				cout << "��¼�ɹ���" << endl;
				teacherFunction();
			}
			else {
				cout << "��¼ʧ�ܣ���Ҫע����(y/n)" << endl;
				char choice;
				cin >> choice;
				if (choice == 'y') {
					teaRegister();
				}
				else {
					cout << "�����µ�½��" << endl;
				}
			}
		}
		if (identify != 1 && identify != 2) {
			cout << "����������������룡" << endl;
		}
	}
}

void stuRegister() {
	cout << "�����������Ϣ��" << endl;
	Student* stu = new Student();
	cout << "������������";
	cin >> stu->name;
	cout << "������ѧ�ţ�";
	cin >> stu->ID;
	cout << "���������䣺";
	cin >> stu->age;
	cout << "�������꼶��";
	string grade;
	cin >> grade;
	stu->setGrade(grade);
	cout << "��������ѧ��ݣ�";
	string entryYear;
	cin >> entryYear;
	stu->setEntryYear(entryYear);
	cout << "������רҵ��";
	string major;
	cin >> major;
	stu->setMajor(major);
	cout << "���������룺";
	string pwd;
	cin >> pwd;
	stu->setLoginPwd(pwd);
	string queryInsert = "insert into student values('" +
		stu->getName() + "','" +
		stu->getID() + "','" +
		to_string(stu->getAge()) + "','" +
		stu->getEntryYear() + "','" +
		stu->getLoginPwd() + "','" +
		stu->getMajor() + "','" +
		stu->getGrade() + "')";
	if (mysql_query(con, queryInsert.c_str()) == 0) {
		cout << "ע��ɹ���" << endl;
	}
	else {
		cout << "ע��ʧ�ܣ�" << endl;
	}
}
void teaRegister() {
	cout << "�����������Ϣ��" << endl;
	Teacher* tea = new Teacher();
	cout << "������������";
	cin >> tea->name;
	cout << "�����빤�ţ�";
	cin >> tea->ID;
	cout << "���������䣺";
	cin >> tea->age;
	cout << "������ְ�ƣ�";
	string title;
	cin >> title;
	tea->setTitle(title);
	cout << "�������¼���룺";
	string pwd;
	cin >> pwd;
	tea->setLoginPwd(pwd);
	cout << "������רҵ��";
	string majorField;
	cin >> majorField;
	tea->setMajorField(majorField);
	string queryInsert = "insert into teacher values('" +
		tea->getName() + "','" +
		tea->getID() + "','" +
		to_string(tea->getAge()) + "','" +
		tea->getTitle() + "','" +
		tea->getLoginPwd() + "','" +
		tea->getMajorField() + "')";
	if (mysql_query(con, queryInsert.c_str()) == 0) {
		cout << "ע��ɹ���" << endl;
	}
	else {
		cout << "ע��ʧ�ܣ�" << endl;
	}
}
// ѧ������ʵ��
void selectCourse() {
	//�洢��ѡ�γ������Ϣ
	map<int, Course> optionalCourses = {};
	int index = 0;
	// ����רҵ
	auto c = course.find(stuUser[0].getMajor());
	if (c != course.end()) {
		// �����꼶
		auto& ptr = c->second;
		if (stuUser[0].getGrade() == "����") {
			cout << "δ�ҵ�����ѧ�����ؿγ�" << endl;
			studentFunction();
		}
		auto cl = ptr.find(stuUser[0].getGrade());
		if (cl != ptr.end()) {
			cout << "����ѧ��Ӧ��ѡ�Ŀγ�Ϊ��" << endl;
			for (auto& i : cl->second) {
				index++;
				optionalCourses.insert({ index,i });
				cout << "�γ���ţ�" << index
					<< " �γ����ƣ�" << i.getClassName()
					<< " ѧ��������" << i.getStuNumber()
					<< " �γ�ѧ�֣�" << i.getCredit()
					<< " �ڿ���ʦ��" << i.getTeacherName()
					<< " �Ͽν��ң�" << i.getAssessmentMethod()
					<< endl;
			}
			char choice = 'y';
			do {
				cout << "��ѡ��������ţ���" << endl;
				cin >> index;
				if (optionalCourses.find(index) == optionalCourses.end()) {
					cout << "δ�ҵ��ÿγ̡�" << endl;
					continue;
				}
				if (selectedCourses.find(index) != selectedCourses.end()) {
					cout << "�ÿγ��ѱ�ѡ��" << endl;
					continue;
				}
				selectedCourses.insert({ index,optionalCourses.find(index)->second });
				cout << "�Ƿ����ѡ��(y/n)��";
				cin >> choice;
			} while (choice == 'y');
			cout << "ѡ�γɹ���" << endl;
		}
		else {
			cout << "δ�ҵ����꼶�Ŀγ���Ϣ��" << endl;
		}
	}
	else {
		cout << "δ�ҵ���רҵ�Ŀγ���Ϣ��" << endl;
	}
	studentFunction();
}

void lookSelectedCourse() {
	cout << "����ѡ��Ŀγ����£�" << endl;
	for (auto selected : selectedCourses) {
		cout << "�γ���ţ�" << selected.first
			<< "�γ����ƣ�" << selected.second.getClassName()
			<< " ѧ��������" << selected.second.getStuNumber()
			<< " �γ�ѧ�֣�" << selected.second.getCredit()
			<< " �ڿ���ʦ��" << selected.second.getTeacherName()
			<< " �Ͽν��ң�" << selected.second.getAssessmentMethod() << endl;
	}
	studentFunction();
}

void cancelCourse() {
	cout << "��������Ҫɾ���Ŀγ̵ı�ţ�";
	int index = 0;
	cin >> index;
	auto findIndex = selectedCourses.find(index);
	if (findIndex != selectedCourses.end()) {
		selectedCourses.erase(findIndex);
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "δ�ҵ���ؿγ�" << endl;
	}
	char choice;
	cout << "�Ƿ�Ҫ����ɾ����(y/n)";
	cin >> choice;
	if (choice == 'y') {
		cancelCourse();
	}
	else {
		studentFunction();
	}
}

void studentInfo() {
	cout << "���ĸ�����Ϣ��" << endl;
	Student student = stuUser[0];
	cout << "������" << student.getName() << endl;
	cout << "�꼶��" << student.getGrade() << endl;
	cout << "ѧ�ţ�" << student.getID() << endl;
	cout << "���䣺" << student.getAge() << endl;
	cout << "��ѧ��ݣ�" << student.getEntryYear() << endl;
	cout << "רҵ��" << student.getMajor() << endl;
	cout << "���룺" << student.getLoginPwd() << endl;
	studentFunction();
}

void changePwd(vector<Student>& stuUser) {
	cout << "��������ԭ�������룺";
	string originPwd;
	cin >> originPwd;
	if (originPwd == stuUser[0].getLoginPwd()) {
		cout << "���������µ����룺";
		string newPwd;
		cin >> newPwd;
		stuUser[0].setLoginPwd(newPwd);
		cout << "���óɹ�" << endl;
		string updatequery = "update student set pwd = '" + newPwd + "' where id = '" + stuUser[0].getID() + "'";
		mysql_query(con, updatequery.c_str());
		studentFunction();
	}
	else {
		cout << "�������" << endl;
		changePwd(stuUser);
	}
}

//��ʦ����ʵ��
void lookStudentInfo() {
	if (teaUser[0].getName() == "Root") {
		cout << "������ʹ�ô˹��ܣ���ѡ��������1����" << endl;
		teacherFunction();
	}
	string majorField = teaUser[0].getMajorField();
	string selectquery = "select name,id,grade,age,entryDate,major from student where major = '" + majorField + "'";
	if (mysql_query(con, selectquery.c_str()) == 0) {
		MYSQL_RES* res = mysql_store_result(con);
		if (res) {
			MYSQL_ROW row;
			while (row = mysql_fetch_row(res)) {
				cout << "ѧ�ţ�" << row[1] << " ������" << row[0] << " ���䣺" << row[2] << "�꼶" << row[6] << " ��ѧ��ݣ�" << row[3] << " רҵ��" << row[5] << endl;
			}
		}
	}
	teacherFunction();

}

void teacherInfo() {
	cout << "���ĸ�����Ϣ��" << endl;
	Teacher teacher = teaUser[0];
	cout << "������" << teacher.getName() << endl;
	cout << "���ţ�" << teacher.getID() << endl;
	cout << "���䣺" << teacher.getAge() << endl;
	cout << "ְ�ƣ�" << teacher.getTitle() << endl;
	cout << "���룺" << teacher.getLoginPwd() << endl;
	teacherFunction();
}

void lookAllStudentInfo() {
	if (teaUser[0].getName() == "Root") {
		cout << "����ѧ����Ϣ��" << endl;
		string selectquery = "select name,id,grade,age,entryDate,major from student";
		if (mysql_query(con, selectquery.c_str()) == 0) {
			MYSQL_RES* res = mysql_store_result(con);
			if (res) {
				MYSQL_ROW row;
				while (row = mysql_fetch_row(res)) {
					cout << "ѧ�ţ�" << row[1] << " ������" << row[0] << " ���䣺" << row[2] << "�꼶" << row[6] << " ��ѧ��ݣ�" << row[3] << " רҵ��" << row[5] << endl;
				}
			}
		}
		teacherFunction();
	}
	else {
		cout << "����Ȩ�޲��㣬�޷��鿴����ѧ����Ϣ��" << endl;
		teacherFunction();
	}

}

void changePwd(vector<Teacher>& teaUser) {
	cout << "��������ԭ�������룺";
	string originPwd;
	cin >> originPwd;
	if (originPwd == teaUser[0].getLoginPwd()) {
		cout << "���������µ����룺";
		string newPwd;
		cin >> newPwd;
		teaUser[0].setLoginPwd(newPwd);
		cout << "���óɹ�" << endl;
		string updatequery = "update teacher set pwd = '" + newPwd + "' where id = '" + teaUser[0].getID() + "'";
		mysql_query(con, updatequery.c_str());
		teacherFunction();
	}
	else {
		cout << "�������" << endl;
		changePwd(teaUser);
	}
}

//ѧ����¼&����չʾ
bool studentLogin() {
	cout << "������ѧ�ţ�" << endl;
	string id;
	cin >> id;
	cout << "���������룺" << endl;
	string password;
	cin >> password;

	// ������Ч����֤
	if (id.empty() || password.empty()) {
		cout << "ѧ�ź����벻��Ϊ�գ�" << endl;
		return false;
	}

	string selectquery = "select * from student where id = '" + id + "' and pwd = '" + password + "'";
	if (mysql_query(con, selectquery.c_str())) {
		cout << "���ݿ��ѯ����" << mysql_error(con) << endl;
		return false;
	}

	MYSQL_RES* res = mysql_store_result(con);
	if (!res) {
		cout << "�������ȡʧ�ܣ�" << mysql_error(con) << endl;
		return false;
	}

	// �Ȼ�ȡ��¼�������ж��Ƿ��н��
	int rowCount = mysql_num_rows(res);
	if (rowCount <= 0) {
		mysql_free_result(res);
		cout << "ѧ�Ż��������" << endl;
		return false;
	}

	// ��ȡ��һ������
	MYSQL_ROW row = mysql_fetch_row(res);
	if (!row) {
		mysql_free_result(res);
		cout << "�����л�ȡʧ�ܣ�" << endl;
		return false;
	}

	// ��ȡ�ֶ�����ȷ��������������Ч��Χ��
	int fieldCount = mysql_num_fields(res);
	if (fieldCount < 7) {
		mysql_free_result(res);
		cout << "���ݿ��ṹ�쳣��" << endl;
		return false;
	}

	// ����ѧ��������ӵ��û��б�
	stuUser.push_back(Student(
		row[0] ? row[0] : "",
		row[1] ? row[1] : "",
		row[2] ? atoi(row[2]) : 0,
		row[3] ? row[3] : "",
		row[4] ? row[4] : "",
		row[5] ? row[5] : "",
		row[6] ? row[6] : ""
	));

	mysql_free_result(res);
	return true;
}

void studentFunction() {
	cout << "--------------------ѧ������--------------------" << endl;
	cout << "1.�鿴��ѡ�Ŀγ�" << endl;
	cout << "2.ѡ��" << endl;
	cout << "3.�˿�" << endl;
	cout << "4.�鿴������Ϣ" << endl;
	cout << "5.�޸�����" << endl;
	cout << "6.�˳���¼" << endl;
	cout << "7.�˳�ϵͳ" << endl;
	cout << "�����������������빦��ǰ�����֣���";
	cin >> operation;
	switch (operation) {
	case 1:
		lookSelectedCourse();
		break;
	case 2:
		selectCourse();
		break;
	case 3:
		cancelCourse();
		break;
	case 4:
		studentInfo();
		break;
	case 5:
		changePwd(stuUser);
		break;
	case 6:
		cout << "�˳���¼�ɹ���" << endl;
		selectedCourses.clear();
		stuUser.clear();
		Login();
		break;
	case 7:
		cout << "�˳�ϵͳ�ɹ�����л����ʹ��" << endl;
		//�ر����ݿ�
		dbClose();
		exit(0);
	default:
		cout << "����������������룡" << endl;
		studentFunction();
	}
}

//��ʦ��¼&����չʾ
bool teacherLogin() {
	cout << "�����빤�ţ�" << endl;
	string id;
	cin >> id;
	cout << "���������룺" << endl;
	string password;
	cin >> password;

	// ������Ч����֤
	if (id.empty() || password.empty()) {
		cout << "���ź����벻��Ϊ�գ�" << endl;
		return false;
	}

	string selectquery = "select * from teacher where id = '" + id + "' and pwd = '" + password + "'";
	if (mysql_query(con, selectquery.c_str())) {
		cout << "���ݿ��ѯ����" << mysql_error(con) << endl;
		return false;
	}

	MYSQL_RES* res = mysql_store_result(con);
	if (!res) {
		cout << "�������ȡʧ�ܣ�" << mysql_error(con) << endl;
		return false;
	}

	// �Ȼ�ȡ��¼�������ж��Ƿ��н��
	int rowCount = mysql_num_rows(res);
	if (rowCount <= 0) {
		mysql_free_result(res);
		cout << "���Ż��������" << endl;
		return false;
	}

	// ��ȡ��һ������
	MYSQL_ROW row = mysql_fetch_row(res);
	if (!row) {
		mysql_free_result(res);
		cout << "�����л�ȡʧ�ܣ�" << endl;
		return false;
	}

	// ��ȡ�ֶ�����ȷ��������������Ч��Χ��
	int fieldCount = mysql_num_fields(res);
	if (fieldCount < 6) {
		mysql_free_result(res);
		cout << "���ݿ��ṹ�쳣��" << endl;
		return false;
	}

	// ������ʦ������ӵ��û��б�����ָ�뱣����
	teaUser.push_back(Teacher(
		row[0] ? row[0] : "",
		row[1] ? row[1] : "",
		row[2] ? atoi(row[2]) : 0,
		row[3] ? row[3] : "",
		row[4] ? row[4] : "",
		row[5] ? row[5] : ""
	));

	mysql_free_result(res);
	return true;
}

void teacherFunction() {
	cout << "--------------------��ʦ����--------------------" << endl;
	cout << "1.�鿴����ѧ����Ϣ" << endl;
	cout << "2.�鿴��רҵѧ����Ϣ" << endl;
	cout << "3.�鿴������Ϣ" << endl;
	cout << "4.�޸�����" << endl;
	cout << "5.�˳���¼" << endl;
	cout << "6.�˳�ϵͳ" << endl;
	cout << "��������������";
	cin >> operation;
	switch (operation) {
	case 1:
		lookAllStudentInfo();
		break;
	case 2:
		lookStudentInfo();
	case 3:
		teacherInfo();
		break;
	case 4:
		changePwd(teaUser);
		break;
	case 5:
		cout << "�˳���¼�ɹ���" << endl;
		teaUser.clear();
		Login();
		break;
	case 6:
		cout << "�˳�ϵͳ�ɹ�����л����ʹ��" << endl;
		//�ر����ݿ�
		dbClose();
		exit(0);
	default:
		cout << "����������������룡" << endl;
		teacherFunction();
	}
}