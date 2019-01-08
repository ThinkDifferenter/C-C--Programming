#include<stdio.h>
#include<math.h>
int Isprime(int n);
int main()
{
	int i;
	for(i=2;i<=100;i++)
	{
		if(Isprime(i)==1)
		{
			printf("%d\t",i);
		}
	}
	printf("\n");
	return 0;
}
int Isprime(int n)
{
	int m;
	int flag=0;
	m=sqrt(n);
	int i;
	for(i=2;i<=m;i++)
	{
		if(n%i==0)
		{
			break;
		}
	}
	if(i>m)
	{
		flag=1;
	}
	else
	{
		flag=0;
	}
	return flag;
}