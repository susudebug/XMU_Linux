#include "include/User.h"
#include "include/function.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void Menu() {
	printf("\n\n");
	printf("\t\t\t===================BMI管理系统=======================\n");
	printf("\t\t\t*                                                   *\n");
	printf("\t\t\t*          1>. 登录                                 *\n");
	printf("\t\t\t*          2>. 注册                                 *\n");
	printf("\t\t\t*          0>. 退出管理系统                         *\n");
	printf("\t\t\t*                                    欢迎使用本系统!*\n");
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t输入选项，按回车进入选项:                             \n");
}



void page2(struct user User[100], int currentN) {
	printf("\n\n");
	printf("\t\t\t=======================功能管理=======================\n");
	printf("\t\t\t*                                                   *\n");
	printf("\t\t\t*         当前用户为：%s                           *\n", User[currentN].username);
	printf("\t\t\t*          1>. 登记BMI                    	    *\n");
	printf("\t\t\t*          2>. 查看历史BMI                          *\n");
	printf("\t\t\t*          3>. 切换用户                             *\n");
	printf("\t\t\t*          0>. 退出系统                             *\n");
	printf("\t\t\t*                                    欢迎使用本系统!*\n");
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t输入选项，按回车进入选项:                             \n");
}
void drawHistogram(Record F[100], int k) {
	float maxBmi = 0.0;
	//计算最大BMI
	for (int i = 0; i < k; ++i) {
		if (F[i].BMI > maxBmi) {
			maxBmi = F[i].BMI;
		}
	}

	for (int i = (int)(maxBmi); i >= 0; --i) {
		if (i <= 9)
			printf("%d  | ", i);

		else
			printf("%d | ", i);

		for (int j = 0; j < k; ++j) {
			if ((int)(F[j].BMI)>=i) {
				printf("  ******   ");
			} else {
				printf("           ");
			}
		}
		printf("\n");
	}
	printf("   ");
	for (int i = 0; i < k; ++i) {
		printf("%s ", F[i].Time);
	}
	printf("\n");
}

float BMIcalculator(float height, float weight) {
	return weight / (height * height);
}
// 获取当前时间并存储为字符串
void getCurrentTime(char* currentTime) {
	time_t rawTime;
	struct tm* timeInfo;

	time(&rawTime);
	timeInfo = localtime(&rawTime);

	strftime(currentTime, 11, "%Y-%m-%d", timeInfo);
}
void recordBMI(int n, struct user User[100], int currentN) {
	float height = 0;
	float weight = 0;
	if(User[currentN].k==0){
	printf("请输入身高(m)、体重(kg)\n");
	scanf("%f%f", &height, &weight);
	User[currentN].height=height;
	}else{
		height=User[currentN].height;
		printf("请输入体重(kg)\n");
		scanf("%f", &weight);
	}
	User[currentN].F[User[currentN].k].weight = weight;
	User[currentN].F[User[currentN].k].BMI = BMIcalculator(height, weight);
	getCurrentTime(User[currentN].F[User[currentN].k].Time);
	printf("%s：%f公斤(BMI:%f)\n", User[currentN].F[User[currentN].k].Time, User[currentN].F[User[currentN].k].weight, User[currentN].F[User[currentN].k].BMI);
	User[currentN].k++;
	save(n, User);
}
void healthy(float BMI){
	if(BMI<15){
		printf("  严重消瘦\n");
	}else if(BMI>=15&&BMI<16){
		printf("  中度消瘦\n");
	}else if(BMI>=16&&BMI<18.5){
		printf("  轻度消瘦\n");
	}else if(BMI>=18.5&&BMI<25){
		printf("  体重正常\n");
	}else if(BMI>=25&&BMI<30){
		printf("  肥胖前期\n");
	}else if(BMI>=30 &&BMI<35){
		printf("  轻度肥胖\n");
	}else if(BMI>=35&&BMI<40){
		printf("  中度肥胖\n");
	}else if(BMI>=40){
		printf("  严重肥胖\n");
	}
}
void BMIList(int begin, int end, struct user User[100], int currentN) {
	for (int i = (begin > 0) ? begin : 0; i < end && i < User[currentN].k; i++) {
		printf("%d. %s：%f公斤(%f)", i + 1,  User[currentN].F[i].Time, User[currentN].F[i].weight, User[currentN].F[i].BMI);
		healthy(User[currentN].F[i].BMI);
	}
}


// 比较函数，用于排序
int compareUsers(const void* a, const void* b) {
	const Record* userA = (const Record*)a;
	const Record* userB = (const Record*)b;

	if (userA->BMI < userB->BMI) {
		return -1;
	} else if (userA->BMI > userB->BMI) {
		return 1;
	} else {
		return 0;
	}
}
//BMI记录排序模块
BMIRecordList sortBMIRecords(struct user User[100], int currentN) {
	BMIRecordList L;
	for (int i = 0; i < User[currentN].k; i++) {
		L.G[i].BMI = User[currentN].F[i].BMI;
		L.G[i].weight = User[currentN].F[i].weight;
		strcpy(L.G[i].Time, User[currentN].F[i].Time);
	}
	L.size = User[currentN].k;
	qsort(L.G, L.size, sizeof(Record), compareUsers);
	return L;
}
void showBMIList(struct user User[100], int currentN) {
	char choice;
	printf("\t\t\t*  n：下一页 p：上一页 h：查看图表 a：查看个人历史排名   q：取消  *\n");
	//吸收换行符
	getchar();


	int pagesize = 4;
	int k = 0;
	BMIRecordList L ;
	//先显示第一页
	BMIList(k, k + pagesize, User, currentN);
	k += pagesize;


	scanf("%c", &choice);

	while (choice != 'q') {

		switch (choice) {
			case 'q':
				break;
			case 'n':
				BMIList(k, k + pagesize, User, currentN);
				k += pagesize;
				break;
			case 'p':
				BMIList(k - pagesize, k, User, currentN);
				k -= pagesize;
				break;
			case 'h':
//				plot();
				drawHistogram(User[currentN].F, User[currentN].k);
				break;
			case 'a':
				L = sortBMIRecords(User, currentN);
				for (int i = 0; i < L.size; i++) {
					printf("%d. %s：%f公斤(%f)\n", i + 1,  L.G[i].Time, L.G[i].weight, L.G[i].BMI);
				}
				break;
		}

		getchar();
		scanf("%c", &choice);
	}

}



void nextpage(int n, struct user User[100], int* currentN) {
	page2(User, *currentN);
	int choice = 1;
	while (choice != 0) {
		scanf("%d", &choice);
		switch (choice) {
			case 0:
				break;
			case 1:
				recordBMI(n, User, *currentN); //记录BMI
				page2(User, *currentN);
				break;
			case 2:
				showBMIList(User, *currentN); //查看历史记录

				page2(User, *currentN);
				break;
			case 3:
				switchUser(n, User, currentN); //切换用户
				page2(User, *currentN);
				break;
			default:
				//TODO
				break;
		}
	}
}
