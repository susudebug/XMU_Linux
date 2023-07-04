#include "include/User.h"
#include "include/File.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
// �û�ע��ģ��
void registerUser(int n, struct user User[100], int *currentN) {
	printf("�����û���: ");
	scanf("%s", User[n].username);
	printf("��������: ");
	scanf("%s", User[n].password);
	printf("��������: ");
	scanf("%d", &User[n].age);
	printf("�����Ա�: ");
	scanf("%s", User[n].gender);
	printf("ע��ɹ�!\n");
	*currentN = n;
	n++;
	save(n, User);

}
//�û���½ģ��
void loginUser(int n, struct user User[100], int* currentN) {
	char username[20];
	char password[20];
	printf("�����û���: ");
	scanf("%s", username);
	printf("��������: ");
	scanf("%s", password);

	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(User[i].username, username) == 0 && strcmp(User[i].password, password) == 0) {
			printf("��¼�ɹ�\n");
			*currentN = i;
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("�Ҳ������û���������ע��\n");
		registerUser(n, User, currentN);
	}
	save(n, User);
}
//�л��û�
void switchUser(int n, struct user User[100], int* currentN) {
	printf("\n\n");
	printf("\t\t\t====================�û�����ҳ��======================\n");
	printf("\t\t\t*                                                   *\n");
	printf("\t\t\t*          1>. �л������û�                   	  *\n");
	printf("\t\t\t*          2>. ע�����˺�                  		  *\n");
	printf("\t\t\t*          0>. ȡ��                                 *\n");
	printf("\t\t\t*                                    ��ӭʹ�ñ�ϵͳ!*\n");
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t����ѡ����س�����ѡ��:                             \n");

	int choice;
	scanf("%d", &choice);
	switch (choice) {
		case 0:
			nextpage(n, User, currentN);
			break;
		case 1: {
			for (int i = 0; i < n; i++) {
				printf("%d. %s��%d\n", i + 1, User[i].username, User[i].age);
			}
			int newUser;
			char password[20];
			printf("�����л��û�����ţ����س�����ѡ��:\n");
			scanf("%d", &newUser);
			if(newUser==0)
			return ;
			printf("��������: ");
			scanf("%s", password);
			if (strcmp(User[newUser - 1].password, password) == 0) {
				printf("��¼�ɹ�\n");
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
