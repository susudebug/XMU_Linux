#ifndef F1
#define F1

typedef struct record {
	char Time[20];
	float weight;
	float BMI;
} Record;

// ֧�ż�¼�����������ݽṹģ��
typedef struct BMIL{
	Record G[100];
	int size;
} BMIRecordList;

// �û��ṹ��
struct user {
	char username[20];
	char password[20];
	Record F[100];//�洢BMI��weight��ʱ��
	int age;
	char gender[20];
	int k;//��ǰ�û���BMI��¼����
};
void save(int n, struct user User[100]);

int load(struct user User[100]);
#endif 
