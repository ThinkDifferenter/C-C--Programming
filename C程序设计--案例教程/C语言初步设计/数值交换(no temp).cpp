#include<stdio.h>
int main()
{
	int a=4,b=5;
	printf("a=%d,b=%d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("----------------------------\n");
	printf("a=%d,b=%d\n",a,b);
	return 0;
}