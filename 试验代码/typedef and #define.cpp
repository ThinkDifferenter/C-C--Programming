#include<stdio.h>
#define integer int
typedef int Integer;
typedef unsigned int NI;
int main()
{
	unsigned integer n =100;
	NI i=300;
//	unsigned Integer m =200;//typedef ���Ǽ򵥵��滻������ 
	printf("%d\n",n);
//	printf("%d\n",m);
	printf("%d\n",i);//typedef��Ϊһ�����������������һ�����������ͣ����� 
	return 0; 
}