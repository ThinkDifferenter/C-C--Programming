#include "Head.h"

int main(int argc, char *argv[])
{
	//��ʼ��ʱ
	int begintime;
	int endtime;
	begintime = clock();

	//��ʼƥ��
	Match_test2();
	//Match_test();

	//������ʱ�����
	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);
	system("pause");

	return 0;
}