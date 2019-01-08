#include<stdio.h>
int f();
int f(int i);
//void f();
//void f(int i);
int main()
{
	int i=2;
	f();
	f(i);
	return 0;
}
int f()
{
	int i=1;
	return i;
}
int f(int i)
{
	return i;
}
//void f()
//{
//	int i=3;
//	printf("the i is %d\n",i);
//}
//void f(int i)
//{
//	printf("the i is %d\n",i);
//}