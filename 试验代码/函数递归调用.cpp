#include<stdio.h>
int jiecheng(int i);
int main()
{
	int n;
	printf("input n:");
	scanf("%d",&n);
	printf("%d\n",jiecheng(n));
	return 0;	
}
int jiecheng(int i)
{
	int result=1;
	if(i<0)
	{
		printf("input error!\n");
	}
	else if(i==1)
	{
		result=1;	
	}
	else
	{
		result=i*jiecheng(i-1);
	}
	return result;
}