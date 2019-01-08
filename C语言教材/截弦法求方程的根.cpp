#include<stdio.h>
#include<math.h>
//y=x*x*x-5*x*x+16*x-80
double f(double x)
{
	double y;
	y=x*x*x-5*x*x+16*x-80;
	return y;
}
double xpoint(double x1,double x2)
{
	double y;
	y=(x1*f(x2)-x2*f(x1)/(f(x2)-f(x1)));
	return y;
}
double root(double x1,double x2)
{
	double x,y,y1;
	y1=f(x1);
	do
	{
		x=xpoint(x1,x2);
		y=f(x);
		if(y*y1>0)
		{
			y1=y;
			x1=x;
		}
		else
		{
			x2=x;
		}
	}while(fabs(y)>=1e-6);
	return x;
}
int main()
{
	double x1,x2,f1,f2,x;
	do
	{
		printf("Input x1,x2:\n");
		scanf("%lf %lf",&x1,&x2);
		f1=f(x1);
		f2=f(x2);
	}while(f1*f2<=0);
	x=root(x1,x2);
	printf("A root of equation is %8.4f\n",x);
	return 0; 
} 