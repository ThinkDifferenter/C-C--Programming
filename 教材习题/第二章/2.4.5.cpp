#include<stdio.h>
int main()
{
	int n;
	printf("inter a number n:");
	scanf("%d",&n);
	if(n%5==0&&n%3==0)
	{
		printf("%d��ʱ��3��5����\n",n);
	}
	else
	{
		printf("%d����ͬʱ��3��5����\n",n);
	}
	return 0;
}