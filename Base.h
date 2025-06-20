#include<iostream>
#include<string>
using namespace std;
class User {
public:
	string name;
	string ID;
	int age;
	string loginPwd;
	//构造函数
	User(){}
	User(string name,
		string ID,
		int age,
		string loginPwd) 
		: name(name), 
		ID(ID), 
		age(age), 
		loginPwd(loginPwd) {}
	//析构函数
	~User() {};
};
class Student :public User {
	string entryYear;
	string major;
	string grade;
public:
	//构造函数
    Student(){}
	Student(string name,
		string ID,
		int age,
		string entryYear,
		string loginPwd,
		string major,
		string grade)
		: User(name, ID, age, loginPwd),
		entryYear(entryYear),
		major(major),
		grade(grade) {}
	//成员函数
	//get方法
	string getName() {
		return name;
	}
    string getID() {
		return ID;
	}
    int getAge() {
		return age;
	}
	string getEntryYear() {
		return entryYear;
	}
    string getLoginPwd() {
		return loginPwd;
	}
    string getMajor() {
		return major;
	}
    string getGrade() {
		return grade;
	}
	//set方法
    void setName(string name) {
		this->name = name;
	}
    void setID(string ID) {
		this->ID = ID;
	}
    void setAge(int age) {
		this->age = age;
	}
	void setEntryYear(string entryYear) {
		this->entryYear = entryYear;
	}
	void setMajor(string major) {
		this->major = major;
	}
	void setLoginPwd(string loginPwd) {
		this->loginPwd = loginPwd;
	}
    void setGrade(string grade) {
		this->grade = grade;
	}
	//析构函数
	~Student() {}
};

class Teacher :public User {
	string title;
	string majorField;
public:
	//构造函数
	Teacher(){}
	Teacher(string name, 
		string ID, 
		int age, 
		string title, 
		string loginPwd,
	    string majorField) 
		: User(name, ID, age, loginPwd), 
		title(title),
	    majorField(majorField){}
	//成员函数
	//get方法
	string getName() {
		return name;
	}
    string getID() {
		return ID;
	}
    int getAge() {
		return age;
	}
	string getTitle() {
		return title;
	}
    string getLoginPwd() {
		return loginPwd;
	}
	string getMajorField() {
		return majorField;
	}
	//set方法
    void setName(string name) {
		this->name = name;
	}
    void setID(string ID) {
		this->ID = ID;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setTitle(string title) {
		this->title = title;
	}
	void setLoginPwd(string loginPwd) {
		this->loginPwd = loginPwd;
	}
    void setMajorField(string majorField) {
		this->majorField = majorField;
	}
	//析构函数
	~Teacher() {}
};
class Course {
	string className;
	int stuNumber;
	int credit;
	string teacherName;
	string assessmentMethod;
public:
	//构造函数
	Course() {}
	Course(string className, 
		int stuNumber, 
		int credit, 
		string teacherName, 
		string assessmentMethod) 
		: className(className), 
		stuNumber(stuNumber), 
		credit(credit), 
		teacherName(teacherName), 
		assessmentMethod(assessmentMethod) {}
	//成员函数
	//get方法
	string getClassName() {
		return className;
	}
	int getStuNumber() {
		return stuNumber;
	}
	int getCredit() {
		return credit;
	}
	string getTeacherName() {
		return teacherName;
	}
	string getAssessmentMethod() {
		return assessmentMethod;
	}
	//set方法
	void setClassName(string className) {
		this->className = className;
	}
    void setStuNumber(int stuNumber) {
		this->stuNumber = stuNumber;
	}
    void setCredit(int credit) {
		this->credit = credit;
	}
    void setTeacherName(string teacherName) {
		this->teacherName = teacherName;
	}
    void setAssessmentMethod(string assessmentMethod) {
		this->assessmentMethod = assessmentMethod;
	}
	//析构函数
	~Course() {}
};
