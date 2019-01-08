#include<stdio.h>
int main()
{
	int i=100;
	int *p=&i;
	int **q=&p;
	printf("----------------------------\n");
	printf("i=%d\n",*p);
	printf("i=%d\n",**q);
	printf("&i=%p\n",&i);
	printf("&i=%p\n",p);
	printf("&i=%p\n",*q);
	printf("&p=%p\n",p);
	printf("&p=%x\n",*q);
	printf("-----------------------------\n");
	printf("sizeof(i)=%d\n",sizeof(i));
	printf("sizeof(p)=%d\n",sizeof(p));
	printf("sizeof(q)=%d\n",sizeof(q));
	//指针同样是变量！ 
	return 0;
}