#include<stdio.h>
int prime(int i)
{
	int j,flag=0;
	for(j=0;j<i;j++)
	{
		if(i%j==0)
		{
			flag=0;
		}
	}
	flag=1;
	return flag;
}
int main()
{
	int i;
	for(i=100;i<=200;i++)
	{
		if (prime(i)==1)
		{
			printf("%d\t",i);
		}
	}	
	return 0;
} 