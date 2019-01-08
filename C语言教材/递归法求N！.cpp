#include<stdio.h>
double fac(int n);
int main()
{
	int n;
	double y;
	printf("Input an integer number :");
	scanf("%d",&n);
	y=fac(n);
	printf("%d!=%.0f\n",n,y);
	return 0;
} 
double fac(int n)
{
	double f;
	if(n<0)
	{
		printf("Input error!\n");
	}
	else if(n==0||n==1)
	{
		f=1;
	}
	else
	{
		f=fac(n-1)*n;
	}
	return f;
}