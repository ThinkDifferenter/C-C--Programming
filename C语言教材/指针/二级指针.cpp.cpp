#include<stdio.h>
int main()
{
	int i=100;
	int *p=&i;
	int **q=&p;
	printf("i=%d\n",i);
	printf("i=%d\n",*p);
	printf("i=%d\n",**q);
	printf("&i=%p\n",&i);
	printf("&i=%p\n",p);
	printf("&i=%p\n",*q);
	printf("&i=%p\n",p);
	return 0;
}