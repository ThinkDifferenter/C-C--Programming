#include<stdio.h>
int add(int i,int j);
int subtract(int i,int j);
double multiply(double i,double j);
double divide(double i,double j);
int process1(int i,int j,int (*p)(int i,int j));
double process2(double i,double j,double (*q)(double i,double j));
int main()
{
	int a,b;
	printf("inter integer a,b:");
	scanf("%d %d",&a,&b);
	printf("the sun of i,j is %d\n",process1(a,b,add));
	printf("the reduce of i,j is %d\n",process1(a,b,subtract));
	
	double i,j;	
	printf("inter decimal i,j:");
	scanf("%lf %lf",&i,&j);
	printf("the result of a*b is %f\n",process2(i,j,multiply));
	printf("the result of a/b is %f\n",process2(i,j,divide));
	return 0;
}
int add(int i,int j)
{
	return i+j;
}
int subtract(int i,int j)
{
	return i-j;
}
double multiply(double i,double j)
{
	return i*j;
}
double divide(double i,double j)
{
	return i/j;
}
int process1(int i,int j,int (*p)(int i,int j))
{
	return (*p)(i,j);
}
double process2(double i,double j,double (*q)(double i,double j))
{
	return (*q)(i,j);
}