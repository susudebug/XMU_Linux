#ifndef FUNC
#define FUNC



void Menu();
void healthy(float BMI);
void save(int n, struct user User[100]);

int load(struct user User[100]);

void page2(struct user User[100], int currentN);

float BMIcalculator(float height, float weight);
// 获取当前时间并存储为字符串
void getCurrentTime(char* currentTime);
void recordBMI(int n,struct user User[100], int currentN);
void BMIList(int begin, int end, struct user User[100], int currentN);

// 比较函数，用于排序
int compareUsers(const void* a, const void* b);
//BMI记录排序模块
BMIRecordList sortBMIRecords(struct user User[100], int currentN);
void showBMIList(struct user User[100], int currentN);

// 用户注册模块
void registerUser(int n, struct user User[100], int *currentN);
//用户登陆模块
void loginUser(int n, struct user User[100], int* currentN);
//切换用户
void switchUser(int n, struct user User[100], int* currentN);
void nextpage(int n, struct user User[100], int* currentN);

#endif 
