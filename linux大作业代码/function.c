#include "include/User.h"
#include "include/function.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void Menu() {
	printf("\n\n");
	printf("\t\t\t===================BMI����ϵͳ=======================\n");
	printf("\t\t\t*                                                   *\n");
	printf("\t\t\t*          1>. ��¼                                 *\n");
	printf("\t\t\t*          2>. ע��                                 *\n");
	printf("\t\t\t*          0>. �˳�����ϵͳ                         *\n");
	printf("\t\t\t*                                    ��ӭʹ�ñ�ϵͳ!*\n");
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t����ѡ����س�����ѡ��:                             \n");
}



void page2(struct user User[100], int currentN) {
	printf("\n\n");
	printf("\t\t\t=======================���ܹ���=======================\n");
	printf("\t\t\t*                                                   *\n");
	printf("\t\t\t*         ��ǰ�û�Ϊ��%s                           *\n", User[currentN].username);
	printf("\t\t\t*          1>. �Ǽ�BMI                    	    *\n");
	printf("\t\t\t*          2>. �鿴��ʷBMI                          *\n");
	printf("\t\t\t*          3>. �л��û�                             *\n");
	printf("\t\t\t*          0>. �˳�ϵͳ                             *\n");
	printf("\t\t\t*                                    ��ӭʹ�ñ�ϵͳ!*\n");
	printf("\t\t\t=====================================================\n");
	printf("\t\t\t����ѡ����س�����ѡ��:                             \n");
}
void drawHistogram(Record F[100], int k) {
	float maxBmi = 0.0;
	//�������BMI
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
// ��ȡ��ǰʱ�䲢�洢Ϊ�ַ���
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
	printf("���������(m)������(kg)\n");
	scanf("%f%f", &height, &weight);
	User[currentN].height=height;
	}else{
		height=User[currentN].height;
		printf("����������(kg)\n");
		scanf("%f", &weight);
	}
	User[currentN].F[User[currentN].k].weight = weight;
	User[currentN].F[User[currentN].k].BMI = BMIcalculator(height, weight);
	getCurrentTime(User[currentN].F[User[currentN].k].Time);
	printf("%s��%f����(BMI:%f)\n", User[currentN].F[User[currentN].k].Time, User[currentN].F[User[currentN].k].weight, User[currentN].F[User[currentN].k].BMI);
	User[currentN].k++;
	save(n, User);
}
void healthy(float BMI){
	if(BMI<15){
		printf("  ��������\n");
	}else if(BMI>=15&&BMI<16){
		printf("  �ж�����\n");
	}else if(BMI>=16&&BMI<18.5){
		printf("  �������\n");
	}else if(BMI>=18.5&&BMI<25){
		printf("  ��������\n");
	}else if(BMI>=25&&BMI<30){
		printf("  ����ǰ��\n");
	}else if(BMI>=30 &&BMI<35){
		printf("  ��ȷ���\n");
	}else if(BMI>=35&&BMI<40){
		printf("  �жȷ���\n");
	}else if(BMI>=40){
		printf("  ���ط���\n");
	}
}
void BMIList(int begin, int end, struct user User[100], int currentN) {
	for (int i = (begin > 0) ? begin : 0; i < end && i < User[currentN].k; i++) {
		printf("%d. %s��%f����(%f)", i + 1,  User[currentN].F[i].Time, User[currentN].F[i].weight, User[currentN].F[i].BMI);
		healthy(User[currentN].F[i].BMI);
	}
}


// �ȽϺ�������������
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
//BMI��¼����ģ��
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
	printf("\t\t\t*  n����һҳ p����һҳ h���鿴ͼ�� a���鿴������ʷ����   q��ȡ��  *\n");
	//���ջ��з�
	getchar();


	int pagesize = 4;
	int k = 0;
	BMIRecordList L ;
	//����ʾ��һҳ
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
					printf("%d. %s��%f����(%f)\n", i + 1,  L.G[i].Time, L.G[i].weight, L.G[i].BMI);
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
				recordBMI(n, User, *currentN); //��¼BMI
				page2(User, *currentN);
				break;
			case 2:
				showBMIList(User, *currentN); //�鿴��ʷ��¼

				page2(User, *currentN);
				break;
			case 3:
				switchUser(n, User, currentN); //�л��û�
				page2(User, *currentN);
				break;
			default:
				//TODO
				break;
		}
	}
}
