#include<stdio.h>
int jiecheng(int i);
int main()
{
	int i;
	int (*p)(int);
	p=jiecheng;
	printf("the sizeof(long long) is %d\n",sizeof(long long));
	printf("Please input number for jiecheng:");
	scanf("%d",&i);
	printf("the result is %ld\n",(*p)(i));
	return 0;
}
int jiecheng(int i)
{
	long long result=1;
	for(int j=1;j<=i;j++)
	{
		result*=j;
	}
	return result;
}