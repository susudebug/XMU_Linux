#ifndef FUNC
#define FUNC



void Menu();
void healthy(float BMI);
void save(int n, struct user User[100]);

int load(struct user User[100]);

void page2(struct user User[100], int currentN);

float BMIcalculator(float height, float weight);
// ��ȡ��ǰʱ�䲢�洢Ϊ�ַ���
void getCurrentTime(char* currentTime);
void recordBMI(int n,struct user User[100], int currentN);
void BMIList(int begin, int end, struct user User[100], int currentN);

// �ȽϺ�������������
int compareUsers(const void* a, const void* b);
//BMI��¼����ģ��
BMIRecordList sortBMIRecords(struct user User[100], int currentN);
void showBMIList(struct user User[100], int currentN);

// �û�ע��ģ��
void registerUser(int n, struct user User[100], int *currentN);
//�û���½ģ��
void loginUser(int n, struct user User[100], int* currentN);
//�л��û�
void switchUser(int n, struct user User[100], int* currentN);
void nextpage(int n, struct user User[100], int* currentN);

#endif 
