#include<iostream>
#include<string>
using namespace std;
class User {
public:
	string name;
	string ID;
	int age;
	string loginPwd;
	//���캯��
	User(){}
	User(string name,
		string ID,
		int age,
		string loginPwd) 
		: name(name), 
		ID(ID), 
		age(age), 
		loginPwd(loginPwd) {}
	//��������
	~User() {};
};
class Student :public User {
	string entryYear;
	string major;
	string grade;
public:
	//���캯��
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
	//��Ա����
	//get����
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
	//set����
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
	//��������
	~Student() {}
};

class Teacher :public User {
	string title;
	string majorField;
public:
	//���캯��
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
	//��Ա����
	//get����
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
	//set����
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
	//��������
	~Teacher() {}
};
class Course {
	string className;
	int stuNumber;
	int credit;
	string teacherName;
	string assessmentMethod;
public:
	//���캯��
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
	//��Ա����
	//get����
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
	//set����
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
	//��������
	~Course() {}
};
