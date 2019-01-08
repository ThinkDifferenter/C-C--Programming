#include<stdio.h>
void f1(int i);
void f2(double i);
int main()
{
	int i=1;
	double j=1.0;
	f1(i);
	f2(j);
	f1(j);
	f2(i);
	return 0;	
}
void f1(int i)
{
	printf("the int number is %d\n",i);
} 
void f2(double i)
{
	printf("the double number is %f\n",i);
}