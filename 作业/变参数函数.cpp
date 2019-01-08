#include<stdio.h>
int main()
{
	int a[100];
	int cnt,i=0,max;
	printf("Please inter date:\n");
	while(1)
	{
		scanf("%d",&a[i]);
		if(a[i]!=-1)
		{ 
			i++;
		}
		else
		{
			break;
		}
	}
	cnt=i;
	max=a[0];
	for(i=0;i<=cnt;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	printf("你输入的%d个数中最大的数为:%d\n",cnt,max);
	return 0;
}