#include<stdio.h>
#include<math.h>
int prime(int m)
{
	int k=sqrt(m),i,flag=0;
	for(i=0;i<=k;i++)
	{
		if(m%i==0)
		{
			flag=0;
			break;
		}
	}	
	if(i>k)
	{
		flag=1;
	}
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