#include "Head.h"

int main(int argc, char *argv[])
{
	//��ʼ��ʱ
	int begintime;
	int endtime;
	begintime = clock();

	//��ʼƥ��
	Match();

	//������ʱ�����
	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);
	system("pause");

	return 0;
}