#include<stdio.h>
#include<math.h>
int sushu(int n);
int main()
{
	int i;
	for(i=100;i<=200;i++)
	{
		sushu(i);
	}
	return 0;	
}
int sushu(int n)
{
	int i;
	double k;
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
		printf("%dÊÇËØÊı\n",n);
	}
	return 0;
}