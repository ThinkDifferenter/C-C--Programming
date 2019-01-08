#include<stdio.h>
int main()
{
	int a,b;
	int *p,*q;
	a=100;
	b=300;
	p=&a;
	q=&b;
	printf("a=%d,b=%d\n",a,b);
	printf("a=%d,b=%d\n",*p,*q);
	printf("&a=%p,&b=%p\n",&a,&b);
	printf("&a=%p,&b=%p\n",p,q);
	return 0;
}