#include<stdio.h>
#define N 38
#define M 3.1415926 
int i=12;
int main()
{
	printf("sizeof (i)=%d\n",sizeof(i));
	printf("sizeof (N)=%d\n",sizeof(N));
	printf("sizeof (M)=%d\n",sizeof(M));
//	printf("the location of M is %d\n",&M);
//	printf("the location of N is %d\n",&N);
	printf("the location of i is %d\n",&i);
	//��ʦ���Ҷ�����޲��������ڴ�����Ӧ��С�Ĵ洢�����洢��
	// �����ҶԶ���ĺ����ȡָ���㣬��������error˵ no-lvalue in unary '&' 
	return 0;
}