#include<stdio.h>
#include<math.h>
int shuixianhuashu(int n);
int main()
{
	int n;
	printf("Please input n:");
	scanf("%d",&n);
	if(shuixianhuashu(n)==1)
	{
		printf("yes!\n");
	}
	else
	{
		printf("no!\n");
	}
	return 0;
}
int shuixianhuashu(int n)
{
	int a[6]={0,0,0,0,0,0},i,j=n;
	int flag=0;
	int t=0;
	for(i=0;i<6;i++)
	{
		a[i]=n%10;
		n=n/10;
	}
	for(i=0;i<6;i++)
	{
		t+=pow(a[i],3);
	}
	if(j==t)
	{
		flag=1;
	}
	return flag;
}