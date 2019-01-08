#include<stdio.h>
main()
{
	int *p;
	int a=3;
	int *a1=&a;
	int b=5;
	int *b1=&b;
	printf("&a=%p,&b=%p\n",&a,&b);
	printf("*a1=%d,*b1=%d\n",*a1,*b1);
	
	
	p=a1;
	a1=b1;
	b1=p;
	printf("&a=%p,&b=%p\n",&a,&b);
	printf("*a1=%d,*b1=%d\n",*a1,*b1);
	
	printf("a=%d\nb=%d\n",*a1,*b1);
	
	
	return 0;
	
	
}
