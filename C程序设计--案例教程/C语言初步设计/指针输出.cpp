#include<stdio.h>
main()
{
	int i;
	int *p=&i;
	*p=100;
	
	printf("&i=%p\n",&i);
	printf("*p=%p\n",p);
	printf("i=%d\n",i);
	printf("p=%d\n",*p);
	printf("*(p+1)=%p\n",p+1);
	printf("&i+1=%p\n",&i+1);
	
	return 0;
	
}
