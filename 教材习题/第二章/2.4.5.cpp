#include<stdio.h>
int main()
{
	int n;
	printf("inter a number n:");
	scanf("%d",&n);
	if(n%5==0&&n%3==0)
	{
		printf("%d能时被3和5整除\n",n);
	}
	else
	{
		printf("%d不能同时被3和5整除\n",n);
	}
	return 0;
}