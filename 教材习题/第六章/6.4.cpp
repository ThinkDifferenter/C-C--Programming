#include<stdio.h>
int jiecheng(int n);
int main()
{
	int n,i;
	long result=0;
	printf("Please input n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		result+=jiecheng(i);
	}
	printf("the resule is %ld\n",result);
	return 0;
}
int  jiecheng(int n)
{
	int i;
	long t=1;
	for(i=1;i<=n;i++)
	{
		t*=i;
	}
	return t;	
}