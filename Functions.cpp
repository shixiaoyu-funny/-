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
//获取数据库链接句柄
MYSQL* con = mysql_init(NULL);
void dbInit() {
	cout << "请输入数据库密码：";
	cin>>password;
	if (!mysql_real_connect(con, host, user, password.c_str(), database_name, port, NULL, 0)) {
		cerr << "密码错误，无权访问！" << endl;
		system("pause");
		exit(1);
		return;
	}
	else {
		cout << "数据库连接成功" << endl;
	}
	mysql_set_character_set(con, "gbk");
}
//关闭数据库
void dbClose() {
	if (con != NULL) {
		mysql_close(con);
		cout << "数据库连接已安全关闭" << endl;
	}
}
//存储学生选课信息
map<int, Course> selectedCourses = {};
//存储在线用户信息
vector<Student> stuUser = {};
vector<Teacher> teaUser = {};
//登录&注册
void Login() {
	bool flag1 = true;
	while (flag1) {
		cout << "请选择您的身份（1.学生 2.老师）：" << endl;
		cin >> identify;
		if (identify == 1) {
			if (studentLogin()) {
				cout << "登录成功！" << endl;
				studentFunction();
			}
			else {
				cout << "登录失败，需要注册吗？(y/n)" << endl;
				char choice;
				cin >> choice;
				if (choice == 'y') {
					stuRegister();
					cout << "注册成功！请重新登陆" << endl;
				}
				else {
					cout << "请重新登陆：" << endl;
				}
			}
		}
		if (identify == 2) {

			if (teacherLogin()) {
				cout << "登录成功！" << endl;
				teacherFunction();
			}
			else {
				cout << "登录失败，需要注册吗？(y/n)" << endl;
				char choice;
				cin >> choice;
				if (choice == 'y') {
					teaRegister();
				}
				else {
					cout << "请重新登陆：" << endl;
				}
			}
		}
		if (identify != 1 && identify != 2) {
			cout << "输入错误，请重新输入！" << endl;
		}
	}
}

void stuRegister() {
	cout << "请输入各项信息：" << endl;
	Student* stu = new Student();
	cout << "请输入姓名：";
	cin >> stu->name;
	cout << "请输入学号：";
	cin >> stu->ID;
	cout << "请输入年龄：";
	cin >> stu->age;
	cout << "请输入年级：";
	string grade;
	cin >> grade;
	stu->setGrade(grade);
	cout << "请输入入学年份：";
	string entryYear;
	cin >> entryYear;
	stu->setEntryYear(entryYear);
	cout << "请输入专业：";
	string major;
	cin >> major;
	stu->setMajor(major);
	cout << "请输入密码：";
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
		cout << "注册成功！" << endl;
	}
	else {
		cout << "注册失败！" << endl;
	}
}
void teaRegister() {
	cout << "请输入各项信息：" << endl;
	Teacher* tea = new Teacher();
	cout << "请输入姓名：";
	cin >> tea->name;
	cout << "请输入工号：";
	cin >> tea->ID;
	cout << "请输入年龄：";
	cin >> tea->age;
	cout << "请输入职称：";
	string title;
	cin >> title;
	tea->setTitle(title);
	cout << "请输入登录密码：";
	string pwd;
	cin >> pwd;
	tea->setLoginPwd(pwd);
	cout << "请输入专业：";
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
		cout << "注册成功！" << endl;
	}
	else {
		cout << "注册失败！" << endl;
	}
}
// 学生功能实现
void selectCourse() {
	//存储可选课程序号信息
	map<int, Course> optionalCourses = {};
	int index = 0;
	// 查找专业
	auto c = course.find(stuUser[0].getMajor());
	if (c != course.end()) {
		// 查找年级
		auto& ptr = c->second;
		if (stuUser[0].getGrade() == "大四") {
			cout << "未找到您本学年的相关课程" << endl;
			studentFunction();
		}
		auto cl = ptr.find(stuUser[0].getGrade());
		if (cl != ptr.end()) {
			cout << "您本学期应该选的课程为：" << endl;
			for (auto& i : cl->second) {
				index++;
				optionalCourses.insert({ index,i });
				cout << "课程序号：" << index
					<< " 课程名称：" << i.getClassName()
					<< " 学生数量：" << i.getStuNumber()
					<< " 课程学分：" << i.getCredit()
					<< " 授课老师：" << i.getTeacherName()
					<< " 上课教室：" << i.getAssessmentMethod()
					<< endl;
			}
			char choice = 'y';
			do {
				cout << "请选择（输入序号）：" << endl;
				cin >> index;
				if (optionalCourses.find(index) == optionalCourses.end()) {
					cout << "未找到该课程。" << endl;
					continue;
				}
				if (selectedCourses.find(index) != selectedCourses.end()) {
					cout << "该课程已被选择。" << endl;
					continue;
				}
				selectedCourses.insert({ index,optionalCourses.find(index)->second });
				cout << "是否继续选课(y/n)：";
				cin >> choice;
			} while (choice == 'y');
			cout << "选课成功！" << endl;
		}
		else {
			cout << "未找到该年级的课程信息。" << endl;
		}
	}
	else {
		cout << "未找到该专业的课程信息。" << endl;
	}
	studentFunction();
}

void lookSelectedCourse() {
	cout << "您已选择的课程如下：" << endl;
	for (auto selected : selectedCourses) {
		cout << "课程序号：" << selected.first
			<< "课程名称：" << selected.second.getClassName()
			<< " 学生数量：" << selected.second.getStuNumber()
			<< " 课程学分：" << selected.second.getCredit()
			<< " 授课老师：" << selected.second.getTeacherName()
			<< " 上课教室：" << selected.second.getAssessmentMethod() << endl;
	}
	studentFunction();
}

void cancelCourse() {
	cout << "请输入您要删除的课程的编号：";
	int index = 0;
	cin >> index;
	auto findIndex = selectedCourses.find(index);
	if (findIndex != selectedCourses.end()) {
		selectedCourses.erase(findIndex);
		cout << "删除成功" << endl;
	}
	else {
		cout << "未找到相关课程" << endl;
	}
	char choice;
	cout << "是否要继续删除？(y/n)";
	cin >> choice;
	if (choice == 'y') {
		cancelCourse();
	}
	else {
		studentFunction();
	}
}

void studentInfo() {
	cout << "您的个人信息：" << endl;
	Student student = stuUser[0];
	cout << "姓名：" << student.getName() << endl;
	cout << "年级：" << student.getGrade() << endl;
	cout << "学号：" << student.getID() << endl;
	cout << "年龄：" << student.getAge() << endl;
	cout << "入学年份：" << student.getEntryYear() << endl;
	cout << "专业：" << student.getMajor() << endl;
	cout << "密码：" << student.getLoginPwd() << endl;
	studentFunction();
}

void changePwd(vector<Student>& stuUser) {
	cout << "请输入您原来的密码：";
	string originPwd;
	cin >> originPwd;
	if (originPwd == stuUser[0].getLoginPwd()) {
		cout << "请输入您新的密码：";
		string newPwd;
		cin >> newPwd;
		stuUser[0].setLoginPwd(newPwd);
		cout << "设置成功" << endl;
		string updatequery = "update student set pwd = '" + newPwd + "' where id = '" + stuUser[0].getID() + "'";
		mysql_query(con, updatequery.c_str());
		studentFunction();
	}
	else {
		cout << "密码错误！" << endl;
		changePwd(stuUser);
	}
}

//老师功能实现
void lookStudentInfo() {
	if (teaUser[0].getName() == "Root") {
		cout << "您无需使用此功能，请选择完整的1功能" << endl;
		teacherFunction();
	}
	string majorField = teaUser[0].getMajorField();
	string selectquery = "select name,id,grade,age,entryDate,major from student where major = '" + majorField + "'";
	if (mysql_query(con, selectquery.c_str()) == 0) {
		MYSQL_RES* res = mysql_store_result(con);
		if (res) {
			MYSQL_ROW row;
			while (row = mysql_fetch_row(res)) {
				cout << "学号：" << row[1] << " 姓名：" << row[0] << " 年龄：" << row[2] << "年级" << row[6] << " 入学年份：" << row[3] << " 专业：" << row[5] << endl;
			}
		}
	}
	teacherFunction();

}

void teacherInfo() {
	cout << "您的个人信息：" << endl;
	Teacher teacher = teaUser[0];
	cout << "姓名：" << teacher.getName() << endl;
	cout << "工号：" << teacher.getID() << endl;
	cout << "年龄：" << teacher.getAge() << endl;
	cout << "职称：" << teacher.getTitle() << endl;
	cout << "密码：" << teacher.getLoginPwd() << endl;
	teacherFunction();
}

void lookAllStudentInfo() {
	if (teaUser[0].getName() == "Root") {
		cout << "所有学生信息：" << endl;
		string selectquery = "select name,id,grade,age,entryDate,major from student";
		if (mysql_query(con, selectquery.c_str()) == 0) {
			MYSQL_RES* res = mysql_store_result(con);
			if (res) {
				MYSQL_ROW row;
				while (row = mysql_fetch_row(res)) {
					cout << "学号：" << row[1] << " 姓名：" << row[0] << " 年龄：" << row[2] << "年级" << row[6] << " 入学年份：" << row[3] << " 专业：" << row[5] << endl;
				}
			}
		}
		teacherFunction();
	}
	else {
		cout << "您的权限不足，无法查看所有学生信息！" << endl;
		teacherFunction();
	}

}

void changePwd(vector<Teacher>& teaUser) {
	cout << "请输入您原来的密码：";
	string originPwd;
	cin >> originPwd;
	if (originPwd == teaUser[0].getLoginPwd()) {
		cout << "请输入您新的密码：";
		string newPwd;
		cin >> newPwd;
		teaUser[0].setLoginPwd(newPwd);
		cout << "设置成功" << endl;
		string updatequery = "update teacher set pwd = '" + newPwd + "' where id = '" + teaUser[0].getID() + "'";
		mysql_query(con, updatequery.c_str());
		teacherFunction();
	}
	else {
		cout << "密码错误！" << endl;
		changePwd(teaUser);
	}
}

//学生登录&功能展示
bool studentLogin() {
	cout << "请输入学号：" << endl;
	string id;
	cin >> id;
	cout << "请输入密码：" << endl;
	string password;
	cin >> password;

	// 输入有效性验证
	if (id.empty() || password.empty()) {
		cout << "学号和密码不能为空！" << endl;
		return false;
	}

	string selectquery = "select * from student where id = '" + id + "' and pwd = '" + password + "'";
	if (mysql_query(con, selectquery.c_str())) {
		cout << "数据库查询错误：" << mysql_error(con) << endl;
		return false;
	}

	MYSQL_RES* res = mysql_store_result(con);
	if (!res) {
		cout << "结果集获取失败：" << mysql_error(con) << endl;
		return false;
	}

	// 先获取记录数，再判断是否有结果
	int rowCount = mysql_num_rows(res);
	if (rowCount <= 0) {
		mysql_free_result(res);
		cout << "学号或密码错误！" << endl;
		return false;
	}

	// 获取第一行数据
	MYSQL_ROW row = mysql_fetch_row(res);
	if (!row) {
		mysql_free_result(res);
		cout << "数据行获取失败！" << endl;
		return false;
	}

	// 获取字段数，确保访问索引在有效范围内
	int fieldCount = mysql_num_fields(res);
	if (fieldCount < 7) {
		mysql_free_result(res);
		cout << "数据库表结构异常！" << endl;
		return false;
	}

	// 创建学生对象并添加到用户列表
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
	cout << "--------------------学生功能--------------------" << endl;
	cout << "1.查看已选的课程" << endl;
	cout << "2.选课" << endl;
	cout << "3.退课" << endl;
	cout << "4.查看个人信息" << endl;
	cout << "5.修改密码" << endl;
	cout << "6.退出登录" << endl;
	cout << "7.退出系统" << endl;
	cout << "请输入您的需求（输入功能前的数字）：";
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
		cout << "退出登录成功！" << endl;
		selectedCourses.clear();
		stuUser.clear();
		Login();
		break;
	case 7:
		cout << "退出系统成功！感谢您的使用" << endl;
		//关闭数据库
		dbClose();
		exit(0);
	default:
		cout << "输入错误，请重新输入！" << endl;
		studentFunction();
	}
}

//老师登录&功能展示
bool teacherLogin() {
	cout << "请输入工号：" << endl;
	string id;
	cin >> id;
	cout << "请输入密码：" << endl;
	string password;
	cin >> password;

	// 输入有效性验证
	if (id.empty() || password.empty()) {
		cout << "工号和密码不能为空！" << endl;
		return false;
	}

	string selectquery = "select * from teacher where id = '" + id + "' and pwd = '" + password + "'";
	if (mysql_query(con, selectquery.c_str())) {
		cout << "数据库查询错误：" << mysql_error(con) << endl;
		return false;
	}

	MYSQL_RES* res = mysql_store_result(con);
	if (!res) {
		cout << "结果集获取失败：" << mysql_error(con) << endl;
		return false;
	}

	// 先获取记录数，再判断是否有结果
	int rowCount = mysql_num_rows(res);
	if (rowCount <= 0) {
		mysql_free_result(res);
		cout << "工号或密码错误！" << endl;
		return false;
	}

	// 获取第一行数据
	MYSQL_ROW row = mysql_fetch_row(res);
	if (!row) {
		mysql_free_result(res);
		cout << "数据行获取失败！" << endl;
		return false;
	}

	// 获取字段数，确保访问索引在有效范围内
	int fieldCount = mysql_num_fields(res);
	if (fieldCount < 6) {
		mysql_free_result(res);
		cout << "数据库表结构异常！" << endl;
		return false;
	}

	// 创建教师对象并添加到用户列表（含空指针保护）
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
	cout << "--------------------老师功能--------------------" << endl;
	cout << "1.查看所有学生信息" << endl;
	cout << "2.查看本专业学生信息" << endl;
	cout << "3.查看个人信息" << endl;
	cout << "4.修改密码" << endl;
	cout << "5.退出登录" << endl;
	cout << "6.退出系统" << endl;
	cout << "请输入您的需求：";
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
		cout << "退出登录成功！" << endl;
		teaUser.clear();
		Login();
		break;
	case 6:
		cout << "退出系统成功！感谢您的使用" << endl;
		//关闭数据库
		dbClose();
		exit(0);
	default:
		cout << "输入错误，请重新输入！" << endl;
		teacherFunction();
	}
}