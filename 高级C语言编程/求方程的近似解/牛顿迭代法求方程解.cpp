#include<stdio.h>
#include<math.h>
#define f(x)  (x*x*x-7.7*x*x+19.2*x-15.3)
#define f_(x) (3*x*x-15.4*x+19.2)

int main()
{
	double x0,x1;
	x0=1;
	x1=x0-f(x0)/f_(x0);
	
	while(fabs(x0-x1)>=1e-5)
	{
		x0=x1;
		x1=x0-f(x0)/f_(x0);
	}	
	printf("½â:%2f\n",x1);
	return 0;
} 