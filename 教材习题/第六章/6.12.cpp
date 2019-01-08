#include<stdio.h>
#define f(x) (2*x*x*x-4*x*x+3*x-6)
#define f1(x) (6*x*x-8*x+3)
int main()
{
	double x,y;
	x=1.5;
	do
	{
		y=f(x);
		x=x-y/f1(x);
	}while(y>=1e-6);
	printf("x=%f\n",x);
	return 0;
}