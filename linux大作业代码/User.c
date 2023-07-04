#include "include/User.h"
#include "include/File.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
// 用户注册模块
void registerUser(int n, struct user User[100], int *currentN) {
	printf("输入用户名: ");
	scanf("%s", User[n].username);
	printf("输入密码: ");
	scanf("%s", User[n].password);
	printf("输入年龄: ");
	scanf("%d", &User[n].age);
	printf("输入性别: ");
	scanf("%s", User[n].gender);
	printf("注册成功!\n");
	*currentN = n;
	n++;
	save(n, User);

}
//用户登陆模块
void loginUser(int n, struct user User[100], int* currentN) {
	char username[20];
	char password[20];
	printf("输入用户名: ");
	scanf("%s", username);
	printf("输入密码: ");
	scanf("%s", password);

	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(User[i].username, username) == 0 && strcmp(User[i].password, password) == 0) {
			printf("登录成功\n");
			*currentN = i;
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("找不到该用户！请重新注册\n");
		registerUser(n, User, currentN);
	}
	save(n, User);
}
//切换用户
void switchUser(int n, struct user User[100], int* currentN) {
	printf("\n\n");
	printf("\t\t\t====================用户管理页面======================\n");
	printf("\t\t\t*                                                   *\n");
	printf("\t\t\t*          1>. 切换已有用户                   	  *\n");
	printf("\t\t\t*          2>. 注册新账号                  		  *\n");
	printf("\t\t\t*          0>. 取消                                 *\n");
	printf("\t\t\t*                                    欢迎使用本系统!*\n");
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t输入选项，按回车进入选项:                             \n");

	int choice;
	scanf("%d", &choice);
	switch (choice) {
		case 0:
			nextpage(n, User, currentN);
			break;
		case 1: {
			for (int i = 0; i < n; i++) {
				printf("%d. %s，%d\n", i + 1, User[i].username, User[i].age);
			}
			int newUser;
			char password[20];
			printf("输入切换用户的序号，按回车进入选项:\n");
			scanf("%d", &newUser);
			if(newUser==0)
			return ;
			printf("输入密码: ");
			scanf("%s", password);
			if (strcmp(User[newUser - 1].password, password) == 0) {
				printf("登录成功\n");
				*currentN = newUser - 1;
				nextpage(n, User, currentN);
			}
			break;
		}
		case 2: {
			registerUser(n, User, currentN);
			nextpage(n, User, currentN);
			break;
		}
		default:
			break;
	}

	save(n, User);
}
