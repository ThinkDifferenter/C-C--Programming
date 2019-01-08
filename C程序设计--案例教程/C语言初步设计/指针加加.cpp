#include<stdio.h>
main()
{
	char a[]={0,1,2,3,4,5,6,7,8,9};
	char *p=a;
	printf("p =%d\n",p);
	printf("*p=%p\n",p);
	printf("*p+1=%p\n",(p+1));
 
 	int a1[]={0,1,2,3,4,5,6,7,8,9};
 	int *q=a1;
 	printf("q =%d\n",q);
	printf("*q=%p\n",q);
	printf("*q+1=%p\n",(q+1));
	
	return 0;
	
}
