#include "include/File.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void save(int n, struct user User[100]) {
	FILE* fp;
	if ((fp = fopen("1.txt", "a+")) == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		if (fwrite(&User[i], sizeof(struct user), 1, fp) != 1)
			printf("�ļ���ʧ��\n");
	}
	fclose(fp);
	printf("��Ϣ¼��ɹ���\n");
}


int load(struct user User[100]) { //���ļ�,��ȡ���������
	FILE*fp;
	int i = 0;
	if ((fp = fopen("1.txt", "r+")) == NULL) {
		printf ("�ļ���ʧ��\n");
		exit(0);
	} else {
		do {
			fread(&User[i], sizeof(struct user), 1, fp);
			i++;
		} while (feof(fp) == 0);
	}
	printf("BMI��Ϣ������ɣ�\n");
	fclose(fp);
	return (i - 1);

}
