#ifndef F1
#define F1

typedef struct record {
	char Time[20];
	float weight;
	float BMI;
} Record;

// 支撑记录排序管理的数据结构模块
typedef struct BMIL{
	Record G[100];
	int size;
} BMIRecordList;

// 用户结构体
struct user {
	char username[20];
	char password[20];
	Record F[100];//存储BMI、weight、时间
	int age;
	char gender[20];
	int k;//当前用户的BMI记录条数
};
void save(int n, struct user User[100]);

int load(struct user User[100]);
#endif 
