#include "include/File.h"
#include "include/User.h"
#include "include/function.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>


int main() {
	struct user User[100];
	int n = 0; //��ǰע�������
	int currentN;//��ǰ���ʵ��û��Ǳ�
	int choice;
	Menu();
	scanf("%d", &choice);
	n = load(User); //��txt�ļ���ȡ
	switch (choice) {
		case 0:
			break;
		case 1://��¼
			loginUser(n, User, &currentN);
			nextpage(n, User, &currentN);
			save(n, User); //����txt
			break;
		case 2://ע��

			registerUser(n, User, &currentN);
			nextpage(n, User, &currentN);
			save(n, User);
			break;
		default:
			break;
	}

}
