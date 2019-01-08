#include<stdio.h>
#include<math.h>
int isPrime(int i);
int main()
{
	int k;
	for(k=2;k<10000;k++)
	{
		if(isPrime(k))
		{
			printf("%d\t",k);
		}
	}	
	return 0;
}
int isPrime(int k)
{
	int i=(int)sqrt(k);
	int flag=0;
	int j;
	for(j=2;j<=i;j++)
	{
		if(k%j==0)
		{
			break;
		}	
	}
	if(j>i)
	{
		flag=1;
	}
	else
	{
		flag=0;
	}
	return flag;
}