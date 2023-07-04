#include "include/File.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void save(int n, struct user User[100]) {
	FILE* fp;
	if ((fp = fopen("1.txt", "a+")) == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		if (fwrite(&User[i], sizeof(struct user), 1, fp) != 1)
			printf("文件打开失败\n");
	}
	fclose(fp);
	printf("信息录入成功！\n");
}


int load(struct user User[100]) { //打开文件,读取里面的数据
	FILE*fp;
	int i = 0;
	if ((fp = fopen("1.txt", "r+")) == NULL) {
		printf ("文件打开失败\n");
		exit(0);
	} else {
		do {
			fread(&User[i], sizeof(struct user), 1, fp);
			i++;
		} while (feof(fp) == 0);
	}
	printf("BMI信息加载完成！\n");
	fclose(fp);
	return (i - 1);

}
