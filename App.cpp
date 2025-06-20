#include<iostream>
#include<string>
#include"Functions.h"
using namespace std;
//主函数
int main() {
	cout << "--------------------xx大学学生选课系统--------------------" << endl;
	//数据库初始化
	dbInit();
	//主界面
	Login();
	return 0;
}