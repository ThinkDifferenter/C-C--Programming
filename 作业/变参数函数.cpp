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
	printf("�������%d������������Ϊ:%d\n",cnt,max);
	return 0;
}