#include<stdio.h>
//��������������
static int i=1000;
int main()
{
	int i=100;
	printf("for����ľֲ�����:\n");
	for(int i=1;i<4;i++)//for������ľֲ����� 
	{
		printf("%d\t",i);
	}
	printf("\n����������ľֲ�����:\n");
	{
		int i=10;
		printf("%d\n",i);
	}
	printf("main��������ľֲ�����:\n"); 
	printf("%d\n\n",i);
	printf("ȫ�ֱ���i=%d\n",i);
	return 0;
}