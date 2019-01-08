#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	double k;
	printf("请输入一个数:");
	scanf("%d",&n);
	k=sqrt(i);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
		{
			break;
		}
	}
	if(i>k)
	{
		printf("%d是素数\n",n);
	}
	else
	{
		printf("%d不是素数\n",n);
	}
	return 0;
}