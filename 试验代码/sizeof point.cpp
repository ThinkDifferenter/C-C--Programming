#include<stdio.h>
int main()
{
	int i=100;
	int *p=&i;
	char *q;
	double *d;
	printf("sizeof (i)=%d\n",sizeof(i));
	printf("sizeof (P)=%d\n",sizeof(p));
	printf("sizeof (q)=%d\n",sizeof(q));
	printf("sizeof (d)=%d\n",sizeof(d));
	//不管我定义指向什么类型的指针变量，它的大小都是4个字节
	//老师，是不是存储指针的内存都是4个字节啊？ 
	return 0;
}