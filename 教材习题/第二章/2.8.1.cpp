#include<stdio.h>
int isleapyear(int i)
{
	int flag=0;
	if(i%4==0&&i%100==0)
	{
		if(i%100!=0&&i%400==0)
		{
			flag=1;
		}
	}
	else
	{
		flag=0;
	}
	return flag;
}
int main()
{
	int i;
	printf("input year:");
	scanf("%d",&i);
	if(isleapyear(i)==1)
	{
		printf("year %d is leap year!\n",i);
	}
	else
	{
		printf("year %d is not leap year!\n",i);	
	}
	return 0;
}