#include "Head.h"

int main(int argc, char *argv[])
{
	//��ʼ��ʱ
	int begintime;
	int endtime;
	begintime = clock();

	//��Ŀ���ļ�����
	//Reader_base();

	//��ȷ�ϼ�����
	//Reader_verify();

	//��ʼƥ��
	Match();

	//������ʱ�����
	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);
	system("pause");

	return 0;
}