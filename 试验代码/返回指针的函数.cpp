#include<stdio.h>
int *max(int a,int b);
int main()
{
	int a=3;
	int b=4;
	printf("the max of a,b is %d\n",*(max(a,b)));
	return 0;
}
int*max(int a,int b)
{
	if(a>b)
	{
		return &a;
	}
	else
	{
		return &b;
	}
}