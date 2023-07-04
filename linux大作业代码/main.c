#include "include/File.h"
#include "include/User.h"
#include "include/function.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>


int main() {
	struct user User[100];
	int n = 0; //当前注册的人数
	int currentN;//当前访问的用户角标
	int choice;
	Menu();
	scanf("%d", &choice);
	n = load(User); //从txt文件读取
	switch (choice) {
		case 0:
			break;
		case 1://登录
			loginUser(n, User, &currentN);
			nextpage(n, User, &currentN);
			save(n, User); //存入txt
			break;
		case 2://注册

			registerUser(n, User, &currentN);
			nextpage(n, User, &currentN);
			save(n, User);
			break;
		default:
			break;
	}

}
