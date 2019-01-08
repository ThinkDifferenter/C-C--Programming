#include<stdio.h>
#define f(x) (2*x*x*x-4*x*x+3*x-6)
#define f1(x) (6*x*x-8*x+3)
int main()
{
	double x1,x2,y1,y2;
	x1=-10;
	x2=10;
	do
	{
		y1=f(x1);
		x1=x1-y1/f1(x1);
	}while(y1!=0);
	
	do
	{
		y2=f(x2);
		x2=x2-y2/f1(x2);
	}while(y2!=0);
	printf("x1=%f\tx2=%f\n",x1,x2);
	return 0;
} 